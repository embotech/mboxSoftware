/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 10 Jun 2021
/// @brief Implementation of the OptimalTrajectoryPlanner class, implementing the interface to the Optimal Trajectory planner running asynchronously.

#include <iostream>
#include <chrono>
#include <fstream>

#include "otp_interface.hpp"
#include "optimal_trajectory_planner.hpp"
#include "log_optimal_trajectory_planner_message.hpp"


obrttg::OptimalTrajectoryPlanner::OptimalTrajectoryPlanner()
    : m_init(false), m_started(false), m_threadReady(false), m_shutDown(false), m_computing(false), m_thread(),
    m_threadCfg(obrttg::ThreadConfiguration({0}, 99, SCHED_FIFO)), m_otp(OtpInterface()), m_result(),
    m_logMsgThread(nullptr)
{}

obrttg::OptimalTrajectoryPlanner::~OptimalTrajectoryPlanner()
{
    if (!m_shutDown)
    {
        terminate();
    }
}

int obrttg::OptimalTrajectoryPlanner::initialize()
{
    std::lock_guard<std::mutex> lk{m_initMtx};
    if (!m_init)
    {
        if (m_otp.initialize())
        {
            return ERROR_OTP_INIT_OTP;
        }
        setResult(m_otp.output());

        if (!checkLicense())
        {
            return ERROR_OTP_INIT_LICENSE;
        }
        m_init = true;
        return OTP_SUCCESS;
    }

    return ERROR_OTP_INIT_REPEATED;
}

int obrttg::OptimalTrajectoryPlanner::start()
{
    std::lock_guard<std::mutex> lk(m_startMutex);
    if (!m_init)
    {
        return ERROR_OTP_START_NOT_INIT;
    }
    if (!m_started)
    {
        m_started = true;

        // Launch and configrue trajectory computation thread
        m_thread = std::thread(&OptimalTrajectoryPlanner::run, this);
        int rc;
        {
            std::lock_guard<std::mutex> lk2{m_runMtx};
            rc = m_threadCfg.apply(m_thread.native_handle());

            // Start OTP logging
            startLogging();
            m_threadReady = true; 
        }
        m_runCondition.notify_one();

        if (rc == ERROR_THREAD_CONFIG_APPLY_AFFINITY)
        {
            return ERROR_OTP_START_THREAD_AFFINITY;
        }
        else if (rc == ERROR_THREAD_CONFIG_APPLY_SCHED_PARAMS)
        {
            return ERROR_OTP_START_THREAD_SCHEDULING;
        }

        return OTP_SUCCESS;
    }
    return ERROR_OTP_START_REPEATED;
}

void obrttg::OptimalTrajectoryPlanner::terminate()
{
    if (m_init && !m_shutDown)
    {
        std::cout << "OptimalTrajectoryPlanner: Terminating" << std::endl;
        m_shutDown = true;
        m_otp.terminate();

        // If OTP thread is running
        if (m_started && m_thread.joinable())
        {
            // Submit empty request to trigger queue
            step({});
            // Trigger condition in case the thread is blocked waiting 
            m_runCondition.notify_one();
            // Wait until the OTP thread is finished
            m_thread.join();
            // Stop logging
            stopLogging();
        }
        std::cout << "OptimalTrajectoryPlanner: Terminating ... [OK]" << std::endl;
    }
}

void obrttg::OptimalTrajectoryPlanner::step(std::unique_ptr<const ComputationRequest> request)
{
    m_queue.enqueue(std::move(request));
}

int obrttg::OptimalTrajectoryPlanner::setThreadConfig(ThreadConfiguration &cfg)
{
    if (m_started)
    {
        return ERROR_OTP_SET_THREAD_CFG;
    }
    m_threadCfg = cfg;
    return OTP_SUCCESS;
}

busGncOtp obrttg::OptimalTrajectoryPlanner::getResult()
{
    m_resultMutex.lock();
    busGncOtp result(m_result);
    m_resultMutex.unlock();

    return result;
}

bool obrttg::OptimalTrajectoryPlanner::isResultReady()
{
    return !m_computing;
}

void obrttg::OptimalTrajectoryPlanner::setResult(busGncOtp result)
{
    m_resultMutex.lock();
    memcpy(&m_result, &result, sizeof(busGncOtp));
    m_resultMutex.unlock();
}

void obrttg::OptimalTrajectoryPlanner::run()
{
    // Wait until the thread scheduling attributes are configured
    std::unique_lock<std::mutex> lk{m_runMtx};
    m_runCondition.wait(lk, [&]{return (m_threadReady || m_shutDown);});
    std::cout << "OptimalTrajectoryPlanner: Starting computation thread (cpu " << sched_getcpu() << ") ... [OK]" << std::endl;

    while (!m_shutDown || !m_queue.empty())
    {
        auto request = m_queue.getFront();
        if (request != nullptr)
        {
            m_computing = true;
            ExtU_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T input;
            memcpy(&(input.gnc_parameters), &(request->m_parameters), sizeof(busGncParameters));
            memcpy(&(input.comm_in), &(request->m_commIn), sizeof(busGncCommIn));
            memcpy(&(input.mvm_output), &(request->m_mvm), sizeof(busGncMvm));
            memcpy(&(input.guidance_in), &(request->m_guidance), sizeof(busGncGuidance));

            m_otp.step(input);

            auto output = m_otp.output();

            if (request->m_mvm.recompute_flag)
            {
                m_logMsgThread->postMessage(std::make_unique<LogOptimalTrajectoryPlannerMessage>(output));
            }
            setResult(output);
            m_computing = false;
        }
    }

    std::cout << "OptimalTrajectoryPlanner: Killing thread ... [OK]" << std::endl;
}

void obrttg::OptimalTrajectoryPlanner::startLogging()
{
    // Set up logging file
    std::string nameLogFile = obrttg::LogProcessor::getLogFileName("otp");
    std::unique_ptr<std::ostream> logFile = std::make_unique<std::ofstream>(nameLogFile,
                                                                            std::ios::binary | std::ios::app);

    // Create logging thread
    m_logMsgThread = std::make_unique<embo::MessageThread<obrttg::LogProcessor>>(
        std::make_unique<LogProcessor>(std::move(logFile)));

    // Start logging thread
    m_logMsgThread->start();
}

void obrttg::OptimalTrajectoryPlanner::stopLogging()
{
    // Delete logging thread
    m_logMsgThread.reset();
    m_logMsgThread.reset();
}

bool obrttg::OptimalTrajectoryPlanner::checkLicense()
{
    ExtU_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T input;
    input.mvm_output.recompute_flag = true;
    m_otp.step(input);
    auto output = m_otp.output();

    return ((int)(output.exit_flag) != -100);

}
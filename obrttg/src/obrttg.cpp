/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 9 Jun 2021
/// @brief Implementation of the Obrttg class, implementing the highest interface to the mBox software.

#include <iostream>
#include <memory>
#include <future>

#include "obrttg.hpp"
#include "obrttg_periodic.hpp"
#include "optimal_trajectory_planner.hpp"
#include "mavlink_interface.hpp"
#include "message_thread.hpp"
#include "log_processor.hpp"
#include "log_obrttg_message.hpp"

obrttg::Obrttg::Obrttg()
    : m_otp(std::make_shared<OptimalTrajectoryPlanner>()), m_periodic(std::make_shared<ObrttgPeriodic>()),
      m_comm(std::make_shared<MavlinkInterface>()), m_init(false), m_started(false), m_shutDown(false), m_ready(false),
      m_thread(), m_commInCallback(NULL), m_commOutCallback(NULL), m_status(SUCCESS), m_rxFaultTol(5), m_nRxFaults(0)
{}

obrttg::Obrttg::~Obrttg()
{
    if (!m_shutDown)
    {
        terminate();
    }
}

int obrttg::Obrttg::initialize()
{
    std::lock_guard<std::mutex> lk(m_initMtx);
    if (!m_init)
    {
        if (m_comm->setThreadConfig(m_threadCfg.comm))
        {
            setStatus(ERROR_OBRTTG_COM_INIT_THREAD_CFG);
            return 1;
        }
        auto rc = m_comm->initialize();
        if (rc)
        {
            if (rc == ERROR_COM_INIT_REPEATED)
            {
                setStatus(ERROR_OBRTTG_COM_INIT_REPEATED);
                return 1;
            }
            else if (rc == ERROR_COM_INIT_LOW_LEVEL) 
            {
                setStatus(ERROR_OBRTTG_COM_INIT_LOW_LEVEL);
                return 1;
            }
            else
            {
                setStatus(ERROR_OBRTTG_COM_INIT_UNKNOWN);
                return 1;
            }
        }

        rc = m_periodic->initialize();
        if (rc)
        {
            if (rc == ERROR_PERIODIC_INIT_REPEATED)
            {
                setStatus(ERROR_OBRTTG_PER_INIT_REPEATED);
                return 1;
            }
            else if (rc == ERROR_PERIODIC_INIT_PARAMETERS)
            {
                setStatus(ERROR_OBRTTG_PER_INIT_PARAMETERS);
                return 1;
            }
            else if (rc == ERROR_PERIODIC_INIT_NAVIGATION)
            {
                setStatus(ERROR_OBRTTG_PER_INIT_NAVIGATION);
                return 1;
            }
            else if (rc == ERROR_PERIODIC_INIT_MVM)
            {
                setStatus(ERROR_OBRTTG_PER_INIT_MVM);
                return 1;
            }
            else if (rc == ERROR_PERIODIC_INIT_GUIDANCE)
            {
                setStatus(ERROR_OBRTTG_PER_INIT_GUIDANCE);
                return 1;
            }
            else 
            {
                setStatus(ERROR_OBRTTG_PER_INIT_UNKNOWN);
                return 1;
            }
        }

        if (m_otp->setThreadConfig(m_threadCfg.otp))
        {
            setStatus(ERROR_OBRTTG_OTP_INIT_THREAD_CFG);
            return 1;
        }
        rc = m_otp->initialize();
        if (rc)
        {
            if (rc == ERROR_OTP_INIT_REPEATED)
            {
                setStatus(ERROR_OBRTTG_OTP_INIT_REPEATED);
                return 1;
            }
            else if (rc == ERROR_OTP_INIT_OTP)
            {
                setStatus(ERROR_OBRTTG_OTP_INIT_OTP);
                return 1;
            }
            else 
            {
                setStatus(ERROR_OBRTTG_OTP_INIT_UNKNOWN);
                return 1;
            }
        }
        m_init = true;
        return 0;
    }

    setStatus(ERROR_INIT_REPEATED);
    return 1;
}

int obrttg::Obrttg::start()
{
    std::lock_guard<std::mutex> lk(m_startMtx);
    if (!m_init)
    {
        setStatus(ERROR_START_NOT_INIT);
        return 1;
    }
    if (!m_started)
    {
        m_started = true;
        auto rc = m_comm->start();
        if (rc)
        {
            if (rc == ERROR_COM_START_NOT_INIT) 
            {
                setStatus(ERROR_OBRTTG_COM_START_NOT_INIT);
                return 1;
            }
            else if (rc == ERROR_COM_START_REPEATED)
            {
                setStatus(ERROR_OBRTTG_COM_START_REPEATED);
                return 1;
            }
            else if (rc == ERROR_COM_START_THREAD_AFFINITY)
            {
                setStatus(ERROR_OBRTTG_COM_START_THREAD_AFFINITY);
                return 1;
            }
            else if (rc == ERROR_COM_START_THREAD_SCHEDULING)
            {
                setStatus(ERROR_OBRTTG_COM_START_THREAD_SCHEDULING);
                return 1;
            }
            else
            {
                setStatus(ERROR_OBRTTG_COM_START_UNKNOWN);
                return 1;
            }
        }

        rc = m_periodic->start();
        if (rc)
        {
            if (rc == ERROR_PERIODIC_START_NOT_INIT)
            {
                setStatus(ERROR_OBRTTG_PER_START_NOT_INIT);
                return 1;
            }
            else if (rc == ERROR_PERIODIC_START_REPEATED)
            {
                setStatus(ERROR_OBRTTG_PER_START_REPEATED);
                return 1;
            }
            else
            {
                setStatus(ERROR_OBRTTG_PER_START_UNKNOWN);
                return 1;
            }
        }

        rc = m_otp->start();
        if (rc)
        {
            if (rc == ERROR_OTP_START_NOT_INIT)
            {
                setStatus(ERROR_OBRTTG_OTP_START_NOT_INIT);
                return 1;
            }
            else if (rc == ERROR_OTP_START_REPEATED)
            {
                setStatus(ERROR_OBRTTG_OTP_START_REPEATED);
                return 1;
            }
            else if (rc == ERROR_OTP_START_THREAD_AFFINITY)
            {
                setStatus(ERROR_OBRTTG_OTP_START_THREAD_AFFINITY);
                return 1;
            }
            else if (rc == ERROR_OTP_START_THREAD_SCHEDULING)
            {
                setStatus(ERROR_OBRTTG_OTP_START_THREAD_SCHEDULING);
                return 1;
            }
            else
            {
                setStatus(ERROR_OBRTTG_OTP_START_UNKNOWN);
                return 1;
            }
        }

        // Create Obrttg thread
        m_thread = std::thread(&Obrttg::run, this);
        {
            std::lock_guard<std::mutex> lk2{m_runMtx};
            rc = m_threadCfg.main.apply(m_thread.native_handle());
            m_ready = true;
        }
        m_runCondition.notify_one();
        if (rc)
        {
            if (rc == ERROR_THREAD_CONFIG_APPLY_AFFINITY)
            {
                setStatus(ERROR_START_THREAD_AFFINITY);
            }
            if (rc == ERROR_THREAD_CONFIG_APPLY_SCHED_PARAMS)
            {
                setStatus(ERROR_START_THREAD_SCHEDULING);
            }
            return 1;
        }
        

        // Wait 2 second for the thread to run
        msleep(2000);
        if (status())
        {
            m_ready = false;
            return 1;
        }

        return 0;
    }

    setStatus(ERROR_START_REPEATED);
    return 1;
}

int obrttg::Obrttg::join()
{
    if (m_started && (status() == obrttg::SUCCESS) && m_thread.joinable())
    {
        m_thread.join();
        return (status() == obrttg::SUCCESS);
    }
    return 1;
}

void obrttg::Obrttg::terminate()
{
    if (m_init && !m_shutDown)
    {
        std::cout << "Obrttg: Terminating" << std::endl;
        m_shutDown = true;
        msleep(m_ts);
        m_periodic->terminate();
        m_otp->terminate();
        m_comm->terminate();
        if (m_started)
        {
            if (m_thread.joinable())
            {
                m_thread.join();
            }
        }
        std::cout << "Obrttg: Terminating ... [OK]" << std::endl;
    }
}

int obrttg::Obrttg::step()
{
    PeriodicInput perIn;
    PeriodicOutput perOut;
    busGncCommOut commOut;

    int rc;
    if (rc = m_comm->receive(perIn.inComm))
    {
        if ((m_nRxFaults < m_rxFaultTol) && (perIn.inComm.timestamp_obc > 1))
        {
            m_nRxFaults++;
        }
        else
        {
            if (rc == ERROR_COM_LINK_ACTIVE)
            {
                setStatus(ERROR_OBRTTG_COM_STEP_RX_ACTIVE);
                return 1;
            }
            else if (rc == ERROR_COM_RX_EMPTY)
            {
                setStatus(ERROR_OBRTTG_COM_STEP_RX_EMPTY);
                return 1;
            }
            else
            {
                setStatus(ERROR_OBRTTG_COM_RX_UNKNOWN);
                return 1;
            }
        }
    }
    else
    {
        m_nRxFaults = 0;
    }


    perIn.otp = m_otp->getResult();

    rc = m_periodic->step(perIn, perOut);
    //if (perOut.mvm.recompute_flag)
    //{
    //    auto rx  = perIn.inComm;
    //    std::cout << "[ " << rx.timestamp_obc << " ] Position: [ " << rx.vehicle_state[0] << ", " << rx.vehicle_state[1] << ", " << rx.vehicle_state[2] << " ] [m]" << std::endl;
    //    std::cout << "               Velocity: " << rx.vehicle_state[3] << ", " << rx.vehicle_state[4] << ", " << rx.vehicle_state[5] << " ] [m/s]" << std::endl;
    //    std::cout << "               Mass: " << rx.vehicle_state[13] << " [kg]" << std::endl;
    //    std::cout << "               Mission status: " << rx.mission_status << std::endl; 

    //    std::cout << "Submitted OTP request " << std::endl;
    //    std::cout << "    x = [" << perOut.mvm.next_start[0] << ", " << perOut.mvm.next_start[1] << ", " << perOut.mvm.next_start[2] << ", " << perOut.mvm.next_start[3] << ", " << perOut.mvm.next_start[4] << ", " << perOut.mvm.next_start[5] << "]" << std::endl; 
    //}
    m_otp->step(std::make_unique<ComputationRequest>(perOut.par, perIn.inComm, perOut.mvm, perOut.gui));

    rc  = m_comm->transmit(perOut.outComm);
    if (rc)
    {
        if (rc == ERROR_COM_LINK_ACTIVE)
        {
            setStatus(ERROR_OBRTTG_COM_STEP_TX_ACTIVE);
            return 1;
        }
        else
        {
            setStatus(ERROR_OBRTTG_COM_TX_UNKNOWN);
            return 1;
        }
    }
    
    return SUCCESS;
}

int obrttg::Obrttg::run()
{
    std::unique_lock<std::mutex> lk{m_runMtx};
    m_runCondition.wait(lk, [&]{return (m_ready || m_shutDown);});

    const auto ts = std::chrono::milliseconds(m_ts);
    auto t = std::chrono::steady_clock::now();
    while (!(m_shutDown || isDone()))
    {
        // Run obrttg step
        if (step())
        {
            return 1;
        }

        // Update next execution time
        t += ts;

        // Sleep until the next execution
        std::this_thread::sleep_until(t);
    }
    //if (!isDone())
    //{
    //    std::cout << "I'm still not done :(" << std::endl;
    //}
    return SUCCESS;
}

bool obrttg::Obrttg::isDone()
{
    return (m_periodic->isDone());
}

obrttg::ThreadConfigurations obrttg::Obrttg::getThreadConfig() const
{
    return m_threadCfg;
}

void obrttg::Obrttg::setThreadConfig(obrttg::ThreadConfigurations &threadCfg)
{
    m_threadCfg = threadCfg;
}

bool obrttg::Obrttg::setPeriodicObrttg(std::shared_ptr<ObrttgPeriodic> periodic)
{
    m_periodic = periodic; 
    return false;
}

bool obrttg::Obrttg::setOptimalTrajectoryPlanner(std::shared_ptr<OptimalTrajectoryPlanner> otp)
{
    m_otp = otp; 
    return false;
}

bool obrttg::Obrttg::setCommunicationInterface(std::shared_ptr<CommunicationInterface> comm)
{
    m_comm = comm; 
    return false;
}
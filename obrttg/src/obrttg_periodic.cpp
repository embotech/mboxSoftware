/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Jun 2021
/// @brief Implementation of the ObrttgPeriodic class, implementing the interface to the periodic segment of the mBox software.

#include <fstream>
#include <iostream>

#include "obrttg_periodic.hpp"

#include "parameters_interface.hpp"
#include "navigation_interface.hpp"
#include "guidance_interface.hpp"
#include "mvm_interface.hpp"

#include "log_obrttg_message.hpp"

obrttg::ObrttgPeriodic::ObrttgPeriodic()
    : m_init(false), m_started(false), m_shutDown(false), m_par(ParametersInterface()), m_nav(NavigationInterface()),
    m_mvm(MvmInterface()), m_gui(GuidanceInterface()), m_logMsgThread(nullptr)
{
}

obrttg::ObrttgPeriodic::~ObrttgPeriodic()
{
    if (!m_shutDown)
    {
        terminate();
    }
}

int obrttg::ObrttgPeriodic::initialize()
{
    std::lock_guard<std::mutex> lk(m_initMtx);

    if (!m_init)
    {
        m_init = true;

        if (m_par.initialize())
        {
            return ERROR_PERIODIC_INIT_PARAMETERS;
        }
        m_state.par = m_par.output();

        if (m_nav.initialize())
        {
            return ERROR_PERIODIC_INIT_NAVIGATION;
        }
        m_state.nav = m_nav.output();

        if (m_mvm.initialize())
        {
            return ERROR_PERIODIC_INIT_MVM;
        }
        m_state.mvm = m_mvm.output();

        if (m_gui.initialize())
        {
            return ERROR_PERIODIC_INIT_GUIDANCE;
        }
        m_state.gui = m_gui.output();

        return PERIODIC_SUCCESS;
    }
    return ERROR_PERIODIC_INIT_REPEATED;
}

int obrttg::ObrttgPeriodic::start()
{
    std::lock_guard<std::mutex> lk(m_startMtx);
    if (!m_init)
    {
        return ERROR_PERIODIC_START_NOT_INIT;
    }
    if (!m_started)
    {
        m_started = true;
        startLogging();
        return PERIODIC_SUCCESS;
    }
    return ERROR_PERIODIC_START_REPEATED;
}

int obrttg::ObrttgPeriodic::step(const PeriodicInput &in, PeriodicOutput &out)
{
    std::lock_guard<std::mutex> lk(m_stepMtx);

    m_state.comm = in.inComm;
    m_state.otp = in.otp;

    void* parInput;
    if (m_par.step(parInput))
    {
        return ERROR_PERIODIC_STEP_PARAMETERS;
    }
    m_state.par = m_par.output();

    ExtU_obrttg_navigation_mBox_T navInput;
    navInput.comm_in = m_state.comm;
    navInput.gnc_parameters = m_state.par;
    navInput.guidance_output = m_state.gui;
    navInput.mvm_output = m_state.mvm;

    if (m_nav.step(navInput))
    {
        return ERROR_PERIODIC_STEP_MVM;
    }
    m_state.nav = m_nav.output();

    ExtU_obrttg_mvm_mBox_T mvmInput;
    mvmInput.comm_in = m_state.comm;
    mvmInput.gnc_parameters = m_state.par;
    mvmInput.navigation_output = m_state.nav;
    mvmInput.guidance_output = m_state.gui;
    mvmInput.otp_output = m_state.otp;

    if (m_mvm.step(mvmInput))
    {
        return ERROR_PERIODIC_STEP_MVM;
    }
    m_state.mvm = m_mvm.output();

    ExtU_obrttg_guidance_mBox_T guiInput;
    guiInput.comm_in = m_state.comm;
    guiInput.gnc_parameters = m_state.par;
    guiInput.navigation_output = m_state.nav;
    guiInput.mvm_output = m_state.mvm;
    guiInput.otp_output = m_state.otp;

    if (m_gui.step(guiInput))
    {
        return ERROR_PERIODIC_STEP_GUIDANCE;
    }
    m_state.gui = m_gui.output();
    
    m_logMsgThread->postMessage(std::make_unique<obrttg::LogObrttgMessage>(m_state.nav, m_state.gui, m_state.mvm));

    memcpy(&(out.par), &(m_state.par), sizeof(busGncParameters)); 
    memcpy(&(out.nav), &(m_state.nav), sizeof(busGncNavigation)); 
    memcpy(&(out.mvm), &(m_state.mvm), sizeof(busGncMvm)); 
    memcpy(&(out.gui), &(m_state.gui), sizeof(busGncGuidance)); 

    // Generate communication output
    // Timestamp of the reference equal to the timestamp of the received state
    out.outComm.timestamp = in.inComm.timestamp_obc;                                                
    // Kind of dirty trick to do the mission phase ID to PAC status conversion
    std::vector<int> pacStatusTable = {1, 5, 2, 3, 4};
    auto phaseId = (int)(out.mvm.mission_phase_id[0]);
    out.outComm.pac_status = (real_T)(pacStatusTable.at(phaseId+1));
    // Position and velocity reference
    memcpy(&(out.outComm.position_reference), &(out.gui.guidance_reference[4]), 3*sizeof(real_T));
    memcpy(&(out.outComm.velocity_reference), &(out.gui.guidance_reference[7]), 3*sizeof(real_T));

    return PERIODIC_SUCCESS;
}

bool obrttg::ObrttgPeriodic::isDone()
{
    std::lock_guard<std::mutex> lk(m_stepMtx);
    // Check if flight mode is equal to -1 (idle mode) 
    return (m_state.mvm.mission_phase_id[0] == -1.0);
}

void obrttg::ObrttgPeriodic::terminate()
{
    if (m_init && !m_shutDown)
    {
        std::cout << "ObrttgPeriodic: Terminating" << std::endl;
        m_shutDown = true;

        m_par.terminate();
        m_nav.terminate();
        m_mvm.terminate();
        m_gui.terminate();

        if (m_started)
        {
            stopLogging();
        }
    }
}

void obrttg::ObrttgPeriodic::startLogging()
{
    // Set up logging file
    std::string nameLogFile = LogProcessor::getLogFileName("obrttg");
    std::unique_ptr<std::ostream> logFile = std::make_unique<std::ofstream>(nameLogFile,
                                                                            std::ios::binary | std::ios::app);

    m_logMsgThread = std::make_unique<embo::MessageThread<LogProcessor>>(
        std::make_unique<LogProcessor>(std::move(logFile)));
    
    m_logMsgThread->start();
}

void obrttg::ObrttgPeriodic::stopLogging()
{
    m_logMsgThread.reset();
}
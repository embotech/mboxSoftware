/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 15 Jun 2020
/// @brief Declaration of the MavlinkInterface class derived from the CommunicationInterface. This class wraps the incaslib and provides some advanced functionalities.

#include <iostream>
#include <chrono>
#include <cstring>
#include <fstream>

#ifdef __cplusplus
extern "C"
{
#endif
#include "incaslib.h"
#ifdef __cplusplus
}
#endif

#include "mavlink_interface.hpp"
#include "time_utils.hpp"
#include "callback.hpp"
#include "log_communication_in_message.hpp"
#include "log_communication_out_message.hpp"


obrttg::MavlinkInterface::MavlinkInterface()
    : m_init(false), m_started(false), m_threadReady(false), m_shutDown(false), m_status(Status::IDLE), m_channel(-1),
    m_timeout(1000000), m_lastRxPkg({0}), m_txThread(), m_threadCfg(obrttg::ThreadConfiguration({1}, 99, SCHED_FIFO)),
    m_logRxMsgThread(nullptr), m_logTxMsgThread(nullptr)
{}

obrttg::MavlinkInterface::~MavlinkInterface()
{
    if (!m_shutDown)
    {
        terminate();
    }
}

int obrttg::MavlinkInterface::initialize()
{
    std::lock_guard<std::mutex> lk{m_initMtx};
    if (!m_init)
    {
        m_channel = incasLibInit();
        if (m_channel < 0)
        {
            return ERROR_COM_INIT_LOW_LEVEL;
        }

        // Configure watchdog timer
        m_watchdog.setCallback([this](){setStatus(MavlinkInterface::Status::TIMEOUT);});
        m_watchdog.setDuration(m_timeout);

        // Set up callback for signal processing
        Callback<void(const signal_t*), 0>::func = std::bind(&MavlinkInterface::signalCallback,
                                                   this,
                                                   std::placeholders::_1);
        attachOnSignal(Callback<void(const signal_t*), 0>::callback, m_channel);

        // Set up callback for event processing
        Callback<void(const uint32_t, const uint32_t), 1>::func = std::bind(&MavlinkInterface::eventCallback,
                                                                            this,
                                                                            std::placeholders::_1,
                                                                            std::placeholders::_2);
        attachOnEvent(Callback<void(const uint32_t, const uint32_t), 1>::callback, m_channel);

        m_init = true;
        return COM_SUCCESS;
    }
    return ERROR_COM_INIT_REPEATED;
}

int obrttg::MavlinkInterface::start()
{
    std::lock_guard<std::mutex> lk{m_startMtx};
    if (!m_init)
    {
        return ERROR_COM_START_NOT_INIT;
    }
    if (!m_started)
    {
        m_started = true;

        // Wait for DTV communication to be ready
        while (!isActive() && !m_shutDown)
        {
            msleep(100);
        }

        // Launch background thread taking care of the outbound communication
        m_txThread = std::thread(&MavlinkInterface::run, this);
        int rc;
        {
            std::lock_guard<std::mutex> lk2{m_runMtx};
            rc = m_threadCfg.apply(m_txThread.native_handle());

            // Start communication logging
            startLogging();
            m_threadReady = true;
        }
        m_runCondition.notify_one();

        if (rc == ERROR_THREAD_CONFIG_APPLY_AFFINITY)
        {
            return ERROR_COM_START_THREAD_AFFINITY;
        }
        else if (rc ==  ERROR_THREAD_CONFIG_APPLY_SCHED_PARAMS)
        {
            return ERROR_COM_START_THREAD_SCHEDULING;
        }

        return COM_SUCCESS;
    }
    return ERROR_COM_START_REPEATED;
}

void obrttg::MavlinkInterface::terminate()
{
    if (m_init && !m_shutDown)
    {
        std::cout << "MavlinkInterface: Terminating" << std::endl;
        m_shutDown = true;
        incasLibClose(m_channel);
        if (m_started) 
        {
            send({});
            // Trigger condition in case the thread is blocked waiting 
            m_runCondition.notify_one();
            // Wait until communication thread is finished
            m_txThread.join();
            // Stop logging
            stopLogging();
        }
        std::cout << "MavlinkInterface: Terminating ... [OK]" << std::endl;
    }
}

int obrttg::MavlinkInterface::setThreadConfig(ThreadConfiguration &cfg)
{
    if (m_started)
    {
        return ERROR_COM_SET_THREAD_CFG;
    }
    m_threadCfg = cfg;
    return COM_SUCCESS;
}

bool obrttg::MavlinkInterface::isActive()
{
    return (getStatus() == MavlinkInterface::Status::ACTIVE);
}

obrttg::MavlinkInterface::Status obrttg::MavlinkInterface::getStatus()
{
    std::lock_guard<std::mutex> lk{m_statusMtx};
    return m_status;
}

void obrttg::MavlinkInterface::setStatus(MavlinkInterface::Status status)
{
    std::lock_guard<std::mutex> lk{m_statusMtx};
    m_status = status;
}

int obrttg::MavlinkInterface::transmit(const busGncCommOut &reference)
{
    if (!m_init)
    {
        return ERROR_COM_NOT_INIT;
    }
    if (!m_started)
    {
        return ERROR_COM_NOT_START;
    }
    if (!isActive())
    {
        return ERROR_COM_LINK_ACTIVE;
    }

    mavlink::DTVReference ref;
    ref.position[0] = reference.position_reference[0];
    ref.position[1] = reference.position_reference[1];
    ref.position[2] = reference.position_reference[2];
    ref.velocity[0] = reference.velocity_reference[0];
    ref.velocity[1] = reference.velocity_reference[1];
    ref.velocity[2] = reference.velocity_reference[2];
    ref.timestamp = reference.timestamp;
    ref.pacStatus = (int)(reference.pac_status);

    // Log message to be transmitted
    m_logTxMsgThread->postMessage(std::make_unique<LogCommOutMessage>(reference));

    return send(std::make_unique<const mavlink::DTVReference>(ref));
}

int obrttg::MavlinkInterface::send(std::unique_ptr<const mavlink::DTVReference> reference)
{
    m_txQueue.enqueue(std::move(reference));
    return COM_SUCCESS;
}

int obrttg::MavlinkInterface::receive(busGncCommIn &state)
{
    state = m_lastRxPkg;

    if (!m_init)
    {
        return ERROR_COM_NOT_INIT;
    }
    if (!m_started)
    {
        return ERROR_COM_NOT_START;
    }
    if (!isActive())
    {
        return ERROR_COM_LINK_ACTIVE;
    }

    if (m_rxQueue.empty())
    {
        return ERROR_COM_RX_EMPTY;
    }

    std::unique_ptr<const mavlink::DTVState> elem;
    while (!m_rxQueue.empty())
    {
        elem = m_rxQueue.getFront();
    }

    m_lastRxPkg = static_cast<busGncCommIn>(*elem.get());
    state = m_lastRxPkg;

    // Log received messaged
    m_logRxMsgThread->postMessage(std::make_unique<LogCommInMessage>(state));

    return COM_SUCCESS;
}

void obrttg::MavlinkInterface::run()
{
    // Wait until the thread scheduling attributes are configured
    std::unique_lock<std::mutex> lk{m_runMtx};
    m_runCondition.wait(lk, [&]{return (m_threadReady || m_shutDown);});

    while (!m_shutDown || !m_txQueue.empty())
    {
        if (isActive())
        {
            auto reference = m_txQueue.getFront();
            if (reference != nullptr)
            {
                // Cast to list of signals
                auto txPkg = static_cast<mavlink::TxPackage>(*reference.get());
                if (!m_shutDown)
                {
                    for (auto &s : txPkg)
                    {
                        signal_t sig({
                            .sig_id = s->sig_id,
                            .timestamp = s->timestamp,
                            .signal_value = s->signal_value
                        });
                        auto rc = sendSignals(&sig, 1, m_channel);
                    }
                }
            }
        }
    }
}

void obrttg::MavlinkInterface::startLogging()
{
    // Set up logging file
    std::string nameRxLogFile = obrttg::LogProcessor::getLogFileName("commIn");
    std::string nameTxLogFile = obrttg::LogProcessor::getLogFileName("commOut");

    std::unique_ptr<std::ostream> rxLogFile = std::make_unique<std::ofstream>(nameRxLogFile,
                                                                              std::ios::binary | std::ios::app);
    std::unique_ptr<std::ostream> txLogFile = std::make_unique<std::ofstream>(nameTxLogFile,
                                                                              std::ios::binary | std::ios::app);
    // Create logging thread
    m_logRxMsgThread = std::make_unique<embo::MessageThread<obrttg::LogProcessor>>(
        std::make_unique<obrttg::LogProcessor>(std::move(rxLogFile)));
    m_logTxMsgThread = std::make_unique<embo::MessageThread<obrttg::LogProcessor>>(
        std::make_unique<obrttg::LogProcessor>(std::move(txLogFile)));

    // Start logging thread
    m_logRxMsgThread->start();
    m_logTxMsgThread->start();
}

void obrttg::MavlinkInterface::stopLogging()
{
    // Delete logging threads
    m_logRxMsgThread.reset();
    m_logTxMsgThread.reset();
}

void obrttg::MavlinkInterface::signalCallback(const signal_t* signal)
{
    if (!signal)
    {
        // Empty signal
        return;
    }

    std::lock_guard<std::mutex> lk(m_rxMtx);
    while (auto rc = m_rxPkg.insert(std::make_unique<const signal_t>(*signal)))
    {
        // - 0 the signal was successfully added
        // - 1 the signal does not belong to the data package
        // - 2 the signal was already added to the data package
        // - 3 the signal is too old
        // - 4 the signal is too new
        if (rc == 4)
        {
            // The incoming signal is too new -> belongs to next data package -> reset contents of m_rxPkg
            m_rxPkg.reset();
        }
        else
        {
            break;
        }
    }
    //std::cout << " --> Received signal " << signal->sig_id << std::endl;

    if (m_rxPkg.full())
    {
        // If Rx Data package is completed, insert it in the Rx queue
        m_rxQueue.enqueue(std::make_unique<mavlink::DTVState>(m_rxPkg));
        m_rxPkg.reset();
    }

}

void obrttg::MavlinkInterface::eventCallback(const uint32_t event, const uint32_t eventData)
{
    if (event == RTE_EVENT_GNC_IDLE)
    {
        if (getStatus() == MavlinkInterface::Status::IDLE)
        {
            // The MavlinkInterface was not yet running, initialize watchdog
            if (m_watchdog.start())
            {
                std::cout << "Watchdog failed to start" << std::endl;
                setStatus(MavlinkInterface::Status::ERROR);
            }
            else
            {
                setStatus(MavlinkInterface::Status::ACTIVE);
            }

        }
        else if (getStatus() == MavlinkInterface::Status::ACTIVE)
        {
            // If the MavlinkInterface is already running, just reset the watchdog
            m_watchdog.pet();
        }
    }
}
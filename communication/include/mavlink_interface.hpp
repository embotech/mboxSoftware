/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 15 Jun 2021
/// @brief Declaration of the MavlinkInterface class derived from the CommunicationInterface. This class wraps the incaslib and provides some advanced functionalities.

#ifndef _MBOX_COMMUNICATION_INCLUDE_MAVLINK_INTERFACE_HPP_
#define _MBOX_COMMUNICATION_INCLUDE_MAVLINK_INTERFACE_HPP_

#include <thread>
#include <mutex>

#include "sync_queue.hpp"
#include "message_thread.hpp"

#include "communication_interface.hpp"
#include "mavlink_tools.hpp"
#include "obrttg_types.hpp"
#include "log_processor.hpp"
#include "watchdog.hpp"

namespace obrttg
{
class MavlinkInterface : public CommunicationInterface
{
public:
    MavlinkInterface();
    ~MavlinkInterface();

    // Delete copy and assignment constructors (rule of 5)
    MavlinkInterface(const MavlinkInterface &) = delete;
    MavlinkInterface &operator=(const MavlinkInterface &) = delete;
    MavlinkInterface(MavlinkInterface &&other) = delete;
    MavlinkInterface &operator=(MavlinkInterface &&other) = delete;

    int initialize() override;
    int start() override;
    void terminate() override;

    bool isActive() override;

    int transmit(const busGncCommOut &reference) override;
    int receive(busGncCommIn &state) override;

    int setThreadConfig(ThreadConfiguration &cfg);

    ///< Communication interface status flags
    enum class Status {
        IDLE,       ///< not established
        ACTIVE,     ///< established and running
        TIMEOUT,    ///< watchdog timeout
        ERROR       ///< error
    };
private:
    void run();

    Status getStatus();
    void setStatus(Status status);

    int send(std::unique_ptr<const mavlink::DTVReference> reference);
    //void receiveCallback(signal_t* signal, const service_t service);
    void signalCallback(const signal_t* signal);
    void eventCallback(const uint32_t event, const uint32_t eventData);

    /// @brief Initializes and triggers the logging threads.
    void startLogging();
    /// @brief Stops the logging threads.
    void stopLogging();

    int m_channel;                                  ///< Incaslib socket channel

    busGncCommIn m_lastRxPkg;                       ///< Stores the last received data package

    uint64_t m_timeout;                             ///< Timeout of the watchdog monitoring the incaslib communication (in us)
    mavlink::RxPackage m_rxPkg;

    embo::SyncQueue<std::unique_ptr<const mavlink::DTVReference>> m_txQueue;
    embo::SyncQueue<std::unique_ptr<const mavlink::DTVState>> m_rxQueue;

    std::mutex m_initMtx;
    std::mutex m_startMtx;
    std::condition_variable m_runCondition;
    std::mutex m_runMtx;
    std::mutex m_statusMtx;
    std::mutex m_rxMtx;

    bool m_init;                            ///< Boolean flag monitoring the successful call to the initialize method
    bool m_started;                         ///< Boolean flag monitoring the successful call to the start method
    bool m_threadReady;                     ///< Prevents run() from starting before the thread is configured
    bool m_shutDown;                        ///< Boolean flag monitoring the call to the shutdown method
    Status m_status;                        ///< Flag monitoring the status of the communication interface

    Watchdog m_watchdog;                    ///< Watchdog timer monitoring communication with OBC

    std::thread m_txThread;                 ///< Thread transmitting guidance references
    ThreadConfiguration m_threadCfg;        ///< Communication thread configuration

    std::unique_ptr<embo::MessageThread<LogProcessor>> m_logRxMsgThread;
    std::unique_ptr<embo::MessageThread<LogProcessor>> m_logTxMsgThread;
};
} // namespace obrttg

#endif // _MBOX_COMMUNICATION_INCLUDE_MAVLINK_INTERFACE_HPP_
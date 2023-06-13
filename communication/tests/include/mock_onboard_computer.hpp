/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file mock_onboard_computer.hpp
/// @author embotech AG
/// @date 1 Jul 2021
/// @brief Declaration of MockOnboardComputer class for testing purposes.

#ifndef _MBOX_COMMUNICATION_TEST_INCLUDE_MOCK_ONBOARD_COMPUTER_HPP_
#define _MBOX_COMMUNICATION_TEST_INCLUDE_MOCK_ONBOARD_COMPUTER_HPP_

#include <mutex>
#include <netinet/in.h>
#include <sys/socket.h>

#include "lib/incas/mavlink.h"

#include "sync_queue.hpp"
#include "message_thread.hpp"

#include "mavlink_tools.hpp"

namespace obrttg::test
{
static constexpr uint32_t MOCK_OBC_TERMINATE = 999999;

class MockOnboardComputer
{
public:
    MockOnboardComputer();
    ~MockOnboardComputer();

    // Delete copy and assignment constructors (rule of 5)
    MockOnboardComputer(const MockOnboardComputer &) = delete;
    MockOnboardComputer &operator=(const MockOnboardComputer &) = delete;
    MockOnboardComputer(MockOnboardComputer &&other) = delete;
    MockOnboardComputer &operator=(MockOnboardComputer &&other) = delete;

    int start();
    int launch();
    void terminate();

    int pushMessage(const busPACinput &msg);
    int pullMessage(busGncCommOut &msg);

    int event(const uint32_t eventId, double value);

private:
    void run();

    int getLastMessage(obrttg::mavlink::DTVReference &msg);
    obrttg::mavlink::DTVState getDtvState(const obrttg::mavlink::DTVReference &ref);

    void receive(uint64_t timeout);
    void parseRxMessage(const uint8_t *buffer, int len);
    void send(const obrttg::mavlink::DTVState &dtvState);

    void sendSignal(const mavlink_signal_t &signal);
    void sendEvent(const uint32_t event, double value);

    channel_t m_channel;
    int m_socket;
    sockaddr_in m_address;

    uint64_t m_rxTimeout;
    uint64_t m_cycleTime;

    mavlink::TxPackage m_rxPkg;

    embo::SyncQueue<std::unique_ptr<const mavlink::DTVReference>> m_rxQueue;
    embo::SyncQueue<std::unique_ptr<const mavlink::DTVState>> m_txQueue;

    std::mutex m_startMtx;
    std::mutex m_activeMtx;
    std::mutex m_txMtx;
    std::condition_variable m_startCondition;

    bool m_started;
    bool m_launched;
    bool m_shutDown;

    std::thread m_txThread;               ///< Thread transmitting guidance references
};
}

#endif
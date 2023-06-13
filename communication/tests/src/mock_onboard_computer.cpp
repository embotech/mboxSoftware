/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file mock_onboard_computer.hpp
/// @author embotech AG
/// @date 1 Jul 2021
/// @brief Implementation of MockOnboardComputer class for testing purposes.

#include <unistd.h>
#include <iostream>

#ifdef __cplusplus
extern "C"
{
#endif
#include "incaslib.h"
#ifdef __cplusplus
}
#endif

#include "communication_interface.hpp"
#include "mock_onboard_computer.hpp"
#include "time_utils.hpp"

obrttg::test::MockOnboardComputer::MockOnboardComputer()
    : m_started{false}, m_shutDown{false}, m_launched(false), m_rxTimeout{20000}, m_cycleTime{40000}
{}

obrttg::test::MockOnboardComputer::~MockOnboardComputer()
{
    if (!m_shutDown)
    {
        terminate();
    }
}

int obrttg::test::MockOnboardComputer::start()
{
    std::lock_guard<std::mutex> lk(m_startMtx);
    if (!m_started)
    {
        memset(&m_address, 0, sizeof(m_address));
        m_address.sin_family = AF_INET;
        m_address.sin_port = htons(7878);
        m_address.sin_addr.s_addr = INADDR_ANY;

        if ((m_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        {
            return obrttg::ERROR_COM_INIT_LOW_LEVEL;
        }

        m_started = true;
        return obrttg::COM_SUCCESS;

    }
    return obrttg::ERROR_COM_START_REPEATED;
}

int obrttg::test::MockOnboardComputer::launch()
{
    if (!m_launched)
    {
        m_txThread = std::thread(&MockOnboardComputer::run, this);
        m_launched = true;
        return obrttg::COM_SUCCESS;
    }
    return obrttg::ERROR_COM_START_REPEATED;
}

void obrttg::test::MockOnboardComputer::terminate()
{
    if (m_started && !m_shutDown)
    {
        m_shutDown = true;
        shutdown(m_socket, SHUT_RDWR);
        if (m_launched)
        {
            m_txThread.join();
        }
        close(m_socket);
    }
}

int obrttg::test::MockOnboardComputer::pushMessage(const busPACinput &msg)
{
    mavlink::DTVState mmsg;
    mmsg.timestamp = ((double)(obrttg::mnow()))/1000.0;
    memcpy(&mmsg.data, &msg, sizeof(busPACinput));
    //mmsg.timestamp = msg.timestamp_obc;
    //memcpy(&mmsg.data.positionVectorLP[0], &msg.vehicle_state[0], 3*sizeof(double));
    //memcpy(&mmsg.data.velocityVectorLP[0], &msg.vehicle_state[3], 3*sizeof(double));
    //memcpy(&mmsg.data.eulerAnglesLP[0], &msg.vehicle_state[6], 3*sizeof(double));
    //memcpy(&mmsg.data.angularVelocityB[0], &msg.vehicle_state[10], 3*sizeof(double));
    //mmsg.data.mass = msg.vehicle_state[13];
    //memcpy(&mmsg.data.cogPositionS[0], &msg.vehicle_state[14], 3*sizeof(double));

    m_txQueue.enqueue(std::make_unique<mavlink::DTVState>(mmsg));

    usleep(2*m_cycleTime);

    return (m_txQueue.empty()) ? obrttg::COM_SUCCESS : obrttg::ERROR_COM_RX_EMPTY;
}

int obrttg::test::MockOnboardComputer::pullMessage(busGncCommOut &msg)
{
    if (m_rxQueue.empty())
    {
        return obrttg::ERROR_COM_RX_EMPTY;
    }

    auto mmsg = m_rxQueue.getFront();
    msg.timestamp = mmsg->timestamp;
    msg.pac_status = (real_T)(mmsg->pacStatus);
    memcpy(&msg.position_reference[0], &mmsg->position[0], 3*sizeof(double));
    memcpy(&msg.velocity_reference[0], &mmsg->velocity[0], 3*sizeof(double));

    return COM_SUCCESS;
}

int obrttg::test::MockOnboardComputer::event(const uint32_t eventId, double value)
{
    sendEvent(eventId, value);
    return COM_SUCCESS;
}

void obrttg::test::MockOnboardComputer::run()
{
    while (!m_shutDown)
    {
        // Set state to busy
        sendEvent(RTE_EVENT_GNC_BUSY, 0);

        auto t0 = tic();

        // Check if there is something to receive 
        receive(m_rxTimeout);

        if (!m_txQueue.empty())
        {
            // If there is something to send, send it
            auto state = m_txQueue.getFront();
            send(*state);
        }

        // Stay idle until the end of the cycle
        auto idleTime = (m_cycleTime - utoc(t0));
        sendEvent(RTE_EVENT_GNC_IDLE, (double)(idleTime));
        usleep(idleTime);
    }
}

int obrttg::test::MockOnboardComputer::getLastMessage(obrttg::mavlink::DTVReference &msg)
{
    if (m_rxQueue.empty())
    {
        return 1;
    }
    while (!m_rxQueue.empty())
    {
        msg = *m_rxQueue.getFront().get();
    }

    return 0;
}

obrttg::mavlink::DTVState obrttg::test::MockOnboardComputer::getDtvState(const obrttg::mavlink::DTVReference &ref)
{
    obrttg::mavlink::DTVState state{};
    state.timestamp = ref.timestamp;
    state.data.positionVectorLP[0] = ref.position[0];
    state.data.positionVectorLP[1] = ref.position[1];
    state.data.positionVectorLP[2] = ref.position[2];
    state.data.velocityVectorLP[0] = ref.velocity[0];
    state.data.velocityVectorLP[1] = ref.velocity[1];
    state.data.velocityVectorLP[2] = ref.velocity[2];

    return state;
}

void obrttg::test::MockOnboardComputer::receive(uint64_t timeout)
{
    auto t0 = tic();
    while (utoc(t0) < timeout)
    {
        // Set Rx timeout for the socket
        uint64_t trem = (timeout - utoc(t0));
        auto us = (suseconds_t)(trem % (uint64_t)(1E6));
        auto s = (time_t)((trem - us)/(1E6));
        struct timeval tv = {.tv_sec=s, .tv_usec = us};
        setsockopt(m_socket, SOL_SOCKET, SO_RCVTIMEO, (struct timeval *)&tv, sizeof(tv));

        uint8_t buffer[sizeof(mavlink_message_t)];
        socklen_t slen;
        auto len = recvfrom(m_socket, &buffer[0], sizeof(mavlink_message_t), 0, (struct sockaddr *)&m_address, &slen);
        if (len > 0)
        {
            parseRxMessage(buffer, len);
        }
    }
}

void obrttg::test::MockOnboardComputer::send(const obrttg::mavlink::DTVState &dtvState)
{
    auto txPkg = static_cast<mavlink::RxPackage>(dtvState);

    for (auto &s : txPkg)
    {
        mavlink_signal_t msignal;

        msignal.signal_id = s->sig_id;
        msignal.timestamp = s->timestamp;
        memcpy((uint8_t*)&msignal.data, (uint8_t*)&s->signal_value, sizeof(double));
        sendSignal(msignal);
    }

}


void obrttg::test::MockOnboardComputer::sendEvent(const uint32_t event, double value)
{
    // Create Mavlink signal
    mavlink_signal_t evt;
    evt.signal_id = event;
    evt.timestamp = mnow();
    memcpy((uint8_t *)&evt.data, (uint8_t*)&value, sizeof(double));
    //std::cout << "Sending event " << evt.signal_id << " with value " << value << " (" << evt.data << ")" << std::endl;

    // Send it out
    sendSignal(evt);
}

void obrttg::test::MockOnboardComputer::sendSignal(const mavlink_signal_t &signal)
{
    // Create Mavlink message
    uint8_t buffer[sizeof(mavlink_message_t)];
    mavlink_message_t msg;

    // Block other calls to this method  
    std::lock_guard<std::mutex> lk(m_txMtx);

    // Send signal via the UDP socket
    mavlink_msg_signal_encode_chan(0, 0, 0, &msg, &signal);
    auto len = mavlink_msg_to_send_buffer(&buffer[0], &msg);
    sendto(m_socket, &buffer[0], len, 0, (struct sockaddr*)&m_address, sizeof(m_address));
}

void obrttg::test::MockOnboardComputer::parseRxMessage(const uint8_t *buffer, int len)
{
    mavlink_message_t msg;
    mavlink_status_t sts;
    signal_t signal;
    uint64_t rawvalue;

    for (uint32_t i = 0; i < len; i++)
    {
        mavlink_parse_char(0, buffer[i], &msg, &sts);
        if (msg.msgid == MAVLINK_MSG_ID_SIGNAL)
        {
            // Make sure this frame came from Embotech PAC
            if (msg.compid == (uint8_t)(EMBOTECH_PAC) && (msg.sysid == (uint8_t)(EMBOTECH_PAC >> 8)))
            {
                signal.sig_id = mavlink_msg_signal_get_signal_id(&msg);
                signal.timestamp = mavlink_msg_signal_get_timestamp(&msg);
                rawvalue = mavlink_msg_signal_get_data(&msg);
                memcpy((uint8_t*)&signal.signal_value, (uint8_t*)&rawvalue, sizeof(double));

                while (auto rc = m_rxPkg.insert(std::make_unique<signal_t>(signal)))
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
                if (m_rxPkg.full())
                {
                    // If Rx Data package is completed, insert it in the Rx queue
                    m_rxQueue.enqueue(std::make_unique<obrttg::mavlink::DTVReference>(m_rxPkg));
                    m_rxPkg.reset();
                }
            }
        }
        memset((uint8_t*)&signal, 0, sizeof(signal_t));
        memset((uint8_t*)&msg, 0, sizeof(mavlink_message_t));
        memset((uint8_t*)&sts, 0, sizeof(mavlink_status_t));
    }
}


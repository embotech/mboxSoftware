/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 01 Jul 2021
/// @brief Unit tests for the MavlinkInterface class.

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

#include "mock_onboard_computer.hpp"

#include "struct_comparator.hpp"
#include "gtest/gtest.h"

class MavlinkInterfaceTestFixture : public ::testing::Test
{
public:
    MavlinkInterfaceTestFixture() {}

    int launch()
    {
        if (auto rc = launchOBC())
        {
            return rc;
        }
        return launchPAC();
    }

    int launchPAC()
    {
        if (auto rc = m_pac.initialize())
        {
            return rc;
        }
        return m_pac.start();
    }

    int startOBC()
    {
        return m_obc.start();
    }

    int launchOBC()
    {
        if (auto rc = m_obc.start())
        {
            return rc;
        }
        return m_obc.launch();
    }

    void TearDown()
    {
        m_obc.terminate();
        m_pac.terminate();
    }

protected:
    obrttg::MavlinkInterface m_pac;
    obrttg::test::MockOnboardComputer m_obc;
};

TEST_F(MavlinkInterfaceTestFixture, start_success)
{
    // Successful start of the communication framework:
    // - OBC started the communication channel
    // - OBC is sending messages though the communication channel
    ASSERT_EQ(launchOBC(), obrttg::COM_SUCCESS);
    ASSERT_EQ(launchPAC(), obrttg::COM_SUCCESS);
}

//TEST_F(MavlinkInterfaceTestFixture, start_PAC_timeout)
//{
//    // OBC communication is not yet running -> timeout
//    ASSERT_EQ(launchPAC(), obrttg::ERROR_COM_START_TIMEOUT);
//
//    // OBC communication started but is not sending anything yet -> timeout
//    ASSERT_EQ(startOBC(), obrttg::COM_SUCCESS);
//    ASSERT_EQ(launchPAC(), obrttg::ERROR_COM_START_TIMEOUT);
//}

TEST_F(MavlinkInterfaceTestFixture, comm_interrupted)
{
    // Successful launch of the communication channel
    ASSERT_EQ(launch(), obrttg::COM_SUCCESS);
    ASSERT_TRUE(m_pac.isActive());
    obrttg::ssleep(1);
    ASSERT_TRUE(m_pac.isActive());

    // OBC stops
    m_obc.terminate();

    // The mavlink interface remains active even after 0.5 seconds 
    ASSERT_TRUE(m_pac.isActive());
    obrttg::msleep(500);
    ASSERT_TRUE(m_pac.isActive());

    // When the watchdog timer expires (1 second), the mavlink interface should become inactive
    obrttg::msleep(1000);
    ASSERT_FALSE(m_pac.isActive());
}

TEST_F(MavlinkInterfaceTestFixture, transmit)
{
    // Test communication PAC -> OBC

    // Successful launch of the communication channel
    ASSERT_EQ(launch(), obrttg::COM_SUCCESS);

    // Define message
    busGncCommOut rxRef = {0};      // Received message (actual result)
    busGncCommOut txRef = {
        .timestamp = 10.0,
        .pac_status = 1.0,
        .position_reference = {1.0, 2.0, 3.0},
        .velocity_reference = {4.0, 5.0, 6.0}
    };                              // Sent message (expected result)

    // PAC sends message to OBC
    ASSERT_EQ(m_pac.transmit(txRef), obrttg::COM_SUCCESS);
    obrttg::msleep(100);
    // Check that the message was successfully received on the OBC side
    ASSERT_EQ(m_obc.pullMessage(rxRef), obrttg::COM_SUCCESS);

    // Compare sent and received messages
    obrttg::compareBusGncCommOut(txRef, rxRef);
}

TEST_F(MavlinkInterfaceTestFixture, transmit_not_active)
{
    busGncCommOut ref = {0};      
    // PAC was not initialized so transmit should fail
    ASSERT_EQ(m_pac.transmit(ref), obrttg::ERROR_COM_NOT_INIT);
    ASSERT_EQ(m_pac.initialize(), obrttg::COM_SUCCESS);
    ASSERT_EQ(m_pac.transmit(ref), obrttg::ERROR_COM_NOT_START);
}

TEST_F(MavlinkInterfaceTestFixture, receive)
{
    // Test communication OBC -> PAC

    // Successful launch of the communication channel
    ASSERT_EQ(launch(), obrttg::COM_SUCCESS);

    // Define message
    busGncCommIn rxState = {0};     // Received message (actual result)
    busPACinput txState = {
        .missionStatus = 2,
        .positionVectorLP = {1.0, 2.0, 3.0},
        .velocityVectorLP = {4.0, 4.0, 6.0},
        .eulerAnglesLP = {7.0, 8.0, 9.0},
        .angularVelocityB = {10.0, 11.0, 12.0},
        .cogPositionS = {13.0, 14.0, 15.0},
        .mass = 16.0
    };

    // OBC triggers event
    m_obc.event(RTE_EVENT_VEHICLE_MODE_CHANGED, RTE_VEHICLE_LAUNCHPAD_MODE);
    // OBC sends message to PAC
    double ts = ((double)(obrttg::mnow()))/1000.0;
    ASSERT_EQ(m_obc.pushMessage(txState), obrttg::COM_SUCCESS);
    obrttg::msleep(100);

    // Check that the message was successfully received on the PAC side
    ASSERT_EQ(m_pac.receive(rxState), obrttg::COM_SUCCESS);
    double ts_obc = ((double)(obrttg::mnow()))/1000.0; 

    // Get expected result
    busGncCommIn rxState_exp = {0};
    obrttg::input_parser::parse(txState, ts, ts_obc, rxState_exp);

    // Ensure there is nothing else to receive
    ASSERT_EQ(m_pac.receive(rxState), obrttg::ERROR_COM_RX_EMPTY);
    
    obrttg::compareBusGncCommIn(rxState, rxState_exp);
}

TEST_F(MavlinkInterfaceTestFixture, receive_not_active)
{
    busGncCommIn state = {0};      
    // PAC was not initialized so receive should fail
    ASSERT_EQ(m_pac.receive(state), obrttg::ERROR_COM_NOT_INIT);

    ASSERT_EQ(m_pac.initialize(), obrttg::COM_SUCCESS);
    ASSERT_EQ(m_pac.receive(state), obrttg::ERROR_COM_NOT_START);
}
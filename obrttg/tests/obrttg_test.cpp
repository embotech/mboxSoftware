/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 28 Jun 2021
/// @brief Unit tests for Obrttg class.

#include "obrttg.hpp"
#include "obrttg_periodic.hpp"
#include "optimal_trajectory_planner.hpp"
#include "communication_interface.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::AtLeast;

class MockObrttgPeriodic
    : public obrttg::ObrttgPeriodic
{
public:
    MOCK_METHOD(int, initialize, (), (override));
    MOCK_METHOD(int, start, (), (override));
};

class MockOptimalTrajectoryPlanner
    : public obrttg::OptimalTrajectoryPlanner
{
public:
    MOCK_METHOD(int, initialize, (), (override));
    MOCK_METHOD(int, start, (), (override));
};

class MockCommInterface
    : public obrttg::CommunicationInterface
{
public:
    MOCK_METHOD(int, initialize, (), (override));
    MOCK_METHOD(int, start, (), (override));
};

class ObrttgFixture : public ::testing::Test
{
public:
    ObrttgFixture()
        : m_periodic(std::make_shared<MockObrttgPeriodic>()),
          m_otp(std::make_shared<MockOptimalTrajectoryPlanner>()),
          m_comm(std::make_shared<MockCommInterface>())
    {}

protected:
    virtual void SetUp()
    {
        m_obrttg.setPeriodicObrttg(m_periodic);
        m_obrttg.setOptimalTrajectoryPlanner(m_otp);
        m_obrttg.setCommunicationInterface(m_comm);
        std::filesystem::copy_file("test_params.json", "params.json");
    }
    virtual void TearDown() {
       m_obrttg.terminate();
       std::filesystem::remove("params.json");
    }
    obrttg::Obrttg m_obrttg;
    std::shared_ptr<MockObrttgPeriodic> m_periodic;
    std::shared_ptr<MockOptimalTrajectoryPlanner> m_otp;
    std::shared_ptr<MockCommInterface> m_comm;
};

TEST_F(ObrttgFixture, initSuccess)
{
    EXPECT_CALL(*m_periodic, initialize()).WillOnce(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, initialize()).WillOnce(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillOnce(::testing::Return(obrttg::COM_SUCCESS));

    auto rc = m_obrttg.initialize();
    ASSERT_EQ(rc, 0);
}

TEST_F(ObrttgFixture, initializeFailure_repeated)
{
    EXPECT_CALL(*m_periodic, initialize()).WillRepeatedly(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, initialize()).WillRepeatedly(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.initialize(), obrttg::SUCCESS);
    ASSERT_EQ(m_obrttg.initialize(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_INIT_REPEATED);
}

TEST_F(ObrttgFixture, initializeFailure_comm_repeated)
{
    EXPECT_CALL(*m_periodic, initialize()).WillRepeatedly(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, initialize()).WillRepeatedly(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillRepeatedly(::testing::Return(obrttg::ERROR_COM_INIT_REPEATED));

    ASSERT_EQ(m_obrttg.initialize(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_COM_INIT_REPEATED);
}

TEST_F(ObrttgFixture, initFailure_comm_lowlevel)
{
    EXPECT_CALL(*m_periodic, initialize()).WillRepeatedly(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, initialize()).WillRepeatedly(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillRepeatedly(::testing::Return(obrttg::ERROR_COM_INIT_LOW_LEVEL));

    ASSERT_EQ(m_obrttg.initialize(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_COM_INIT_LOW_LEVEL);
}

TEST_F(ObrttgFixture, initFailure_periodic_repeated)
{
    EXPECT_CALL(*m_periodic, initialize()).WillRepeatedly(::testing::Return(obrttg::ERROR_PERIODIC_INIT_REPEATED));
    EXPECT_CALL(*m_otp, initialize()).WillRepeatedly(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.initialize(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_PER_INIT_REPEATED);
}

TEST_F(ObrttgFixture, initFailure_periodic_parameters)
{
    EXPECT_CALL(*m_periodic, initialize()).WillRepeatedly(::testing::Return(obrttg::ERROR_PERIODIC_INIT_PARAMETERS));
    EXPECT_CALL(*m_otp, initialize()).WillRepeatedly(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.initialize(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_PER_INIT_PARAMETERS);
}

TEST_F(ObrttgFixture, initFailure_periodic_navigation)
{
    EXPECT_CALL(*m_periodic, initialize()).WillRepeatedly(::testing::Return(obrttg::ERROR_PERIODIC_INIT_NAVIGATION));
    EXPECT_CALL(*m_otp, initialize()).WillRepeatedly(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.initialize(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_PER_INIT_NAVIGATION);
}

TEST_F(ObrttgFixture, initiFailure_periodic_mvm)
{
    EXPECT_CALL(*m_periodic, initialize()).WillRepeatedly(::testing::Return(obrttg::ERROR_PERIODIC_INIT_MVM));
    EXPECT_CALL(*m_otp, initialize()).WillRepeatedly(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.initialize(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_PER_INIT_MVM);
}

TEST_F(ObrttgFixture, initFailure_periodic_guidance)
{
    EXPECT_CALL(*m_periodic, initialize()).WillRepeatedly(::testing::Return(obrttg::ERROR_PERIODIC_INIT_GUIDANCE));
    EXPECT_CALL(*m_otp, initialize()).WillRepeatedly(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.initialize(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_PER_INIT_GUIDANCE);
}

TEST_F(ObrttgFixture, initFailure_otp_otpInterfaceFailed)
{
    EXPECT_CALL(*m_periodic, initialize()).WillRepeatedly(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, initialize()).WillRepeatedly(::testing::Return(obrttg::ERROR_OTP_INIT_OTP));
    EXPECT_CALL(*m_comm, initialize()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.initialize(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_OTP_INIT_OTP);
}

TEST_F(ObrttgFixture, startSuccess)
{
    // Configure real ObrttgPeriodic and OptimalTrajectoryPlanner objects
    m_obrttg.setPeriodicObrttg(std::make_shared<obrttg::ObrttgPeriodic>());
    m_obrttg.setOptimalTrajectoryPlanner(std::make_shared<obrttg::OptimalTrajectoryPlanner>());

    EXPECT_CALL(*m_comm, initialize()).WillOnce(::testing::Return(obrttg::COM_SUCCESS));
    ASSERT_EQ(m_obrttg.initialize(), obrttg::SUCCESS);

    EXPECT_CALL(*m_comm, start()).WillOnce(::testing::Return(obrttg::COM_SUCCESS));
    EXPECT_EQ(m_obrttg.start(), obrttg::SUCCESS) << "start() failed with error code " << m_obrttg.status();
}

TEST_F(ObrttgFixture, startFailure_repeated)
{
    // Configure real ObrttgPeriodic and OptimalTrajectoryPlanner objects
    m_obrttg.setPeriodicObrttg(std::make_shared<obrttg::ObrttgPeriodic>());
    m_obrttg.setOptimalTrajectoryPlanner(std::make_shared<obrttg::OptimalTrajectoryPlanner>());

    EXPECT_CALL(*m_comm, initialize()).WillOnce(::testing::Return(obrttg::COM_SUCCESS));
    ASSERT_EQ(m_obrttg.initialize(), obrttg::SUCCESS);

    EXPECT_CALL(*m_otp, start()).WillRepeatedly(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, start()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.start(), obrttg::SUCCESS);
    ASSERT_EQ(m_obrttg.start(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_START_REPEATED);
}

TEST_F(ObrttgFixture, startFailure_comm_repeated)
{
    EXPECT_CALL(*m_periodic, initialize()).WillOnce(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, initialize()).WillOnce(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillOnce(::testing::Return(obrttg::COM_SUCCESS));
    ASSERT_EQ(m_obrttg.initialize(), obrttg::SUCCESS);

    EXPECT_CALL(*m_periodic, start()).WillRepeatedly(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, start()).WillRepeatedly(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, start()).WillRepeatedly(::testing::Return(obrttg::ERROR_COM_START_REPEATED));

    ASSERT_EQ(m_obrttg.start(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_COM_START_REPEATED);
}

TEST_F(ObrttgFixture, startFailure_comm_not_init)
{
    EXPECT_CALL(*m_periodic, initialize()).WillOnce(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, initialize()).WillOnce(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillOnce(::testing::Return(obrttg::COM_SUCCESS));
    ASSERT_EQ(m_obrttg.initialize(), obrttg::SUCCESS);

    EXPECT_CALL(*m_periodic, start()).WillRepeatedly(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, start()).WillRepeatedly(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, start()).WillRepeatedly(::testing::Return(obrttg::ERROR_COM_START_NOT_INIT));

    ASSERT_EQ(m_obrttg.start(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_COM_START_NOT_INIT);
}

TEST_F(ObrttgFixture, startFailure_periodic_repeated)
{
    EXPECT_CALL(*m_periodic, initialize()).WillOnce(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, initialize()).WillOnce(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillOnce(::testing::Return(obrttg::COM_SUCCESS));
    ASSERT_EQ(m_obrttg.initialize(), obrttg::SUCCESS);

    EXPECT_CALL(*m_periodic, start()).WillRepeatedly(::testing::Return(obrttg::ERROR_PERIODIC_START_REPEATED));
    EXPECT_CALL(*m_otp, start()).WillRepeatedly(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, start()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.start(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_PER_START_REPEATED);
}

TEST_F(ObrttgFixture, startFailure_periodic_not_init)
{
    EXPECT_CALL(*m_periodic, initialize()).WillOnce(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, initialize()).WillOnce(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillOnce(::testing::Return(obrttg::COM_SUCCESS));
    ASSERT_EQ(m_obrttg.initialize(), obrttg::SUCCESS);

    EXPECT_CALL(*m_periodic, start()).WillRepeatedly(::testing::Return(obrttg::ERROR_PERIODIC_START_NOT_INIT));
    EXPECT_CALL(*m_otp, start()).WillRepeatedly(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, start()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.start(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_PER_START_NOT_INIT);
}

TEST_F(ObrttgFixture, startFailure_otp_repeated)
{
    EXPECT_CALL(*m_periodic, initialize()).WillOnce(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, initialize()).WillOnce(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillOnce(::testing::Return(obrttg::COM_SUCCESS));
    ASSERT_EQ(m_obrttg.initialize(), obrttg::SUCCESS);

    EXPECT_CALL(*m_periodic, start()).WillRepeatedly(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, start()).WillRepeatedly(::testing::Return(obrttg::ERROR_OTP_START_REPEATED));
    EXPECT_CALL(*m_comm, start()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.start(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_OTP_START_REPEATED);
}

TEST_F(ObrttgFixture, startFailure_otp_not_init)
{
    EXPECT_CALL(*m_periodic, initialize()).WillOnce(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, initialize()).WillOnce(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillOnce(::testing::Return(obrttg::COM_SUCCESS));
    ASSERT_EQ(m_obrttg.initialize(), obrttg::SUCCESS);

    EXPECT_CALL(*m_periodic, start()).WillRepeatedly(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, start()).WillRepeatedly(::testing::Return(obrttg::ERROR_OTP_START_NOT_INIT));
    EXPECT_CALL(*m_comm, start()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.start(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_OTP_START_NOT_INIT);
}

TEST_F(ObrttgFixture, startFailure_otp_affinity)
{
    EXPECT_CALL(*m_periodic, initialize()).WillOnce(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, initialize()).WillOnce(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillOnce(::testing::Return(obrttg::COM_SUCCESS));
    ASSERT_EQ(m_obrttg.initialize(), obrttg::SUCCESS);

    EXPECT_CALL(*m_periodic, start()).WillRepeatedly(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, start()).WillRepeatedly(::testing::Return(obrttg::ERROR_OTP_START_THREAD_AFFINITY));
    EXPECT_CALL(*m_comm, start()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.start(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_OTP_START_THREAD_AFFINITY);
}

TEST_F(ObrttgFixture, startFailure_otp_scheduling)
{
    EXPECT_CALL(*m_periodic, initialize()).WillOnce(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, initialize()).WillOnce(::testing::Return(obrttg::OTP_SUCCESS));
    EXPECT_CALL(*m_comm, initialize()).WillOnce(::testing::Return(obrttg::COM_SUCCESS));
    ASSERT_EQ(m_obrttg.initialize(), obrttg::SUCCESS);

    EXPECT_CALL(*m_periodic, start()).WillRepeatedly(::testing::Return(obrttg::PERIODIC_SUCCESS));
    EXPECT_CALL(*m_otp, start()).WillRepeatedly(::testing::Return(obrttg::ERROR_OTP_START_THREAD_SCHEDULING));
    EXPECT_CALL(*m_comm, start()).WillRepeatedly(::testing::Return(obrttg::COM_SUCCESS));

    ASSERT_EQ(m_obrttg.start(), 1);
    ASSERT_EQ(m_obrttg.status(), obrttg::ERROR_OBRTTG_OTP_START_THREAD_SCHEDULING);
}
/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 18 Jun 2021
/// @brief Unit tests for the LogProcessor class.

#include "log_processor.hpp"

#include <chrono>
#include <memory> // unique_ptr
#include <sstream>
#include <thread>

#include "gtest/gtest.h"

#include "message_thread.hpp"
#include "obrttg_types.hpp"
#include "msgpack_parse_utils.hpp"
#include "struct_comparator.hpp"
#include "obrttg_types_utils.hpp"

#include "log_obrttg_message.hpp"
#include "log_optimal_trajectory_planner_message.hpp"
#include "log_communication_in_message.hpp"
#include "log_communication_out_message.hpp"

class LogProcessorFixture : public ::testing::Test
{
public:
    LogProcessorFixture()
        : logStringStream(new std::stringstream()),
          logMessageThread(
              std::make_unique<obrttg::LogProcessor>(std::unique_ptr<std::ostream>(logStringStream)))
    {
    }

protected:
    void SetUp() override
    {
        logStringStream->clear();
        logMessageThread.start();
    }
    void wait4log()
    {
        // Wait a bit to allow log to be written
        // This function waits until:
        //  - the log stream is not empty AND
        //  - the log stream length stops growing
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        size_t sslength = 0;
        do
        {   sslength = logStringStream->str().empty() ? 0 : logStringStream->str().size();
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        } while (logStringStream->str().empty() || (logStringStream->str().length() > sslength));
    }

    const uint16_t nLogs = 2000;
    std::stringstream *logStringStream; // we need to keep a reference to the stream to extract the string
    embo::MessageThread<obrttg::LogProcessor> logMessageThread;
};

TEST_F(LogProcessorFixture, logObrttgTest)
{
    std::vector<busGncMvm> mvm;
    std::vector<busGncGuidance> guidance;
    std::vector<busGncNavigation> navigation;

    for (uint16_t i = 0; i < nLogs; i++)
    {
        mvm.push_back(obrttg::randomBusGncMvm());
        guidance.push_back(obrttg::randomBusGncGuidance());
        navigation.push_back(obrttg::randomBusGncNavigation());

        logMessageThread.postMessage(std::make_unique<obrttg::LogObrttgMessage>(navigation[i], guidance[i], mvm[i]));
    }

    wait4log();

    // Obtain log string and parse it.
    std::string logFileBuffer = logStringStream->str();
    obrttg::ParsedMBoxLog parsedMBoxLog = {};
    uint16_t result = obrttg::parseMBoxLog(logFileBuffer, &parsedMBoxLog);


    ASSERT_EQ(result, 0);

    std::vector<obrttg::ObrttgLog> obrttgLogs = parsedMBoxLog.obrttgLogs;

    ASSERT_EQ(obrttgLogs.size(), nLogs);

    for (uint16_t i = 0; i < nLogs; i++)
    {
        obrttg::compareBusGncNavigation(obrttgLogs[i].navigation, navigation[i]);
        obrttg::compareBusGncGuidance(obrttgLogs[i].guidance, guidance[i]);
        obrttg::compareBusGncMvm(obrttgLogs[i].mvm, mvm[i]);
    }
}

TEST_F(LogProcessorFixture, logOptimalTrajectoryPlannerTest)
{
    std::vector<busGncOtp> otp; 
    for (uint16_t i = 0; i < nLogs; i++)
    {
        otp.push_back(obrttg::randomBusGncOtp());
        // Send log to logging thread.
        logMessageThread.postMessage(std::make_unique<obrttg::LogOptimalTrajectoryPlannerMessage>(otp[i]));
    }

    wait4log();

    // Obtain log string and parse it.
    std::string logFileBuffer = logStringStream->str();
    obrttg::ParsedMBoxLog parsedMBoxLog = {};
    uint16_t result = obrttg::parseMBoxLog(logFileBuffer, &parsedMBoxLog);

    ASSERT_EQ(result, 0);

    std::vector<obrttg::OptimalTrajectoryPlannerLog> otpLogs = parsedMBoxLog.otpLogs;

    ASSERT_EQ(otpLogs.size(), nLogs);

    for (uint16_t i = 0; i < nLogs; i++)
    {
        obrttg::compareBusGncOtp(otpLogs[i].otp, otp[i]);
    }
}

TEST_F(LogProcessorFixture, logCommunicationInTest)
{
    std::vector<busGncCommIn> commIn;

    for (uint16_t i = 0; i < nLogs; i++)
    {
        commIn.push_back(obrttg::randomBusGncCommIn());
        // Send log to logging thread.
        logMessageThread.postMessage(std::make_unique<obrttg::LogCommInMessage>(commIn[i]));
    }

    wait4log();

    // Obtain log string and parse it.
    std::string logFileBuffer = logStringStream->str();
    obrttg::ParsedMBoxLog parsedMBoxLog = {};
    uint16_t result = obrttg::parseMBoxLog(logFileBuffer, &parsedMBoxLog);

    ASSERT_EQ(result, 0);

    std::vector<obrttg::CommInLog> commInLogs = parsedMBoxLog.commInLogs;

    ASSERT_EQ(commInLogs.size(), nLogs);

    for (uint16_t i = 0; i < nLogs; i++)
    {
        obrttg::compareBusGncCommIn(commInLogs[i].commIn, commIn[i]);
    }
}

TEST_F(LogProcessorFixture, logCommunicationOutTest)
{
    std::vector<busGncCommOut> commOut;
    
    for (uint16_t i = 0; i < nLogs; i++)
    {
        commOut.push_back(obrttg::randomBusGncCommOut());
        // Send log to logging thread.
        logMessageThread.postMessage(std::make_unique<obrttg::LogCommOutMessage>(commOut[i]));
    }

    wait4log();

    // Obtain log string and parse it.
    std::string logFileBuffer = logStringStream->str();
    obrttg::ParsedMBoxLog parsedMBoxLog = {};
    uint16_t result = obrttg::parseMBoxLog(logFileBuffer, &parsedMBoxLog);

    ASSERT_EQ(result, 0);

    std::vector<obrttg::CommOutLog> commOutLogs = parsedMBoxLog.commOutLogs;

    ASSERT_EQ(commOutLogs.size(), nLogs);

    for (uint16_t i = 0; i < nLogs; i++)
    {
        obrttg::compareBusGncCommOut(commOutLogs[i].commOut, commOut[i]);
    }
}
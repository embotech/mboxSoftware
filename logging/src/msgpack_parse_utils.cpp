/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 21 Jun 2021
/// @brief Implementation of structures defining the contents of the different log types.

#include <fstream>
#include <stdexcept>

#include "msgpack_wrapper_obrttg_types.hpp"
#include "msgpack_wrapper_log_types.hpp"
#include "msgpack_parse_utils.hpp"



void obrttg::processObrttgLog(const StringKeyMsgpackMap &msgpackMap, ObrttgLog *obrttgLog)
{
    msgpackMap.at("timestamp").convert(obrttgLog->timestamp);
    msgpackMap.at("navigation").convert(obrttgLog->navigation);
    msgpackMap.at("guidance").convert(obrttgLog->guidance);
    msgpackMap.at("mvm").convert(obrttgLog->mvm);
}

void obrttg::processOptimalTrajectoryPlannerLog(const StringKeyMsgpackMap &msgpackMap, OptimalTrajectoryPlannerLog *otpLog)
{
    msgpackMap.at("timestamp").convert(otpLog->timestamp);
    msgpackMap.at("otp").convert(otpLog->otp);
}

void obrttg::processCommInLog(const StringKeyMsgpackMap &msgpackMap, CommInLog *commInLog)
{
    msgpackMap.at("timestamp").convert(commInLog->timestamp);
    msgpackMap.at("commIn").convert(commInLog->commIn);
}

void obrttg::processCommOutLog(const StringKeyMsgpackMap &msgpackMap, CommOutLog *commOutLog)
{
    msgpackMap.at("timestamp").convert(commOutLog->timestamp);
    msgpackMap.at("commOut").convert(commOutLog->commOut);
}

uint16_t obrttg::readStringKeyMsgpackMap(const obrttg::StringKeyMsgpackMap &msgpackMap,
                                         const std::string &logType,
                                         obrttg::ParsedMBoxLog *parsedMBoxLog)
{
    uint16_t result = 0u;

    if (logType == "obrttg")
    {
        obrttg::ObrttgLog obrttgLog = {};
        obrttg::processObrttgLog(msgpackMap, &obrttgLog);
        parsedMBoxLog->obrttgLogs.push_back(obrttgLog);
    }
    else if (logType == "otp")
    {
        obrttg::OptimalTrajectoryPlannerLog otpLog = {};
        obrttg::processOptimalTrajectoryPlannerLog(msgpackMap, &otpLog);
        parsedMBoxLog->otpLogs.push_back(otpLog);
    }
    else if (logType == "commIn")
    {
        obrttg::CommInLog commInLog = {};
        obrttg::processCommInLog(msgpackMap, &commInLog);
        parsedMBoxLog->commInLogs.push_back(commInLog);
    }
    else if (logType == "commOut")
    {
        obrttg::CommOutLog commOutLog = {};
        obrttg::processCommOutLog(msgpackMap, &commOutLog);
        parsedMBoxLog->commOutLogs.push_back(commOutLog);
    }
    else
    {
        // logType cannot be processed.
        result = 1u;
    }

    return result;
}

std::string obrttg::readMBoxLogIntoString(const std::string &fileName)
{
    std::ifstream ifs(fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

    std::ifstream::pos_type fileSize = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    std::vector<char> bytes(fileSize);
    ifs.read(bytes.data(), fileSize);

    return std::string(bytes.data(), fileSize);
}

uint16_t obrttg::parseMBoxLog(const std::string &buffer,
                              obrttg::ParsedMBoxLog *parsedMBoxLog)
{
    uint16_t resultFlag = 0u;

    std::size_t offset = 0u;
    msgpack::object_handle msgpackObjectHandle = {};
    std::string logType = {};

    try
    {
        // Each toplevel msgpack object needs to be a map with a key "type".
        while (offset < buffer.size() && resultFlag == 0u)
        {
            msgpack::unpack(msgpackObjectHandle, buffer.data(), buffer.size(), offset);
            msgpack::object msgpackObject = msgpackObjectHandle.get();
            obrttg::StringKeyMsgpackMap stringKeyMsgpackMap =
                msgpackObject.as<obrttg::StringKeyMsgpackMap>();
            stringKeyMsgpackMap.at("type").convert(logType);

            resultFlag = obrttg::readStringKeyMsgpackMap(stringKeyMsgpackMap, logType, parsedMBoxLog);
        }
    }
    catch (const std::out_of_range &exception)
    {
        (void) exception;
        resultFlag = 2u;
    }

    return resultFlag;
}
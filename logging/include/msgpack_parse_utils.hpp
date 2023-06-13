/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 18 Jun 2021
/// @brief Declaration of structures defining the contents of the different log types.

#ifndef _MBOX_LOGGING_INCLUDE_MSGPACK_PARSE_UTILS_HPP_
#define _MBOX_LOGGING_INCLUDE_MSGPACK_PARSE_UTILS_HPP_

#include <cstdint>
#include <map>
#include <vector>
#include <string>

#include "msgpack.hpp"

#include "obrttg_types.hpp"

namespace obrttg
{

// Generic container. Each msgpack map will first be parsed into it.
typedef std::map<std::string, msgpack::object> StringKeyMsgpackMap;

typedef struct {
    int64_t timestamp;
    busGncNavigation navigation;
    busGncGuidance guidance;
    busGncMvm mvm;
} ObrttgLog;

typedef struct {
    int64_t timestamp;
    busGncOtp otp;
} OptimalTrajectoryPlannerLog;

typedef struct {
    int64_t timestamp;
    busGncCommIn commIn;
} CommInLog;

typedef struct {
    int64_t timestamp;
    busGncCommOut commOut;
} CommOutLog;

struct ParsedMBoxLog
{
    std::vector<ObrttgLog> obrttgLogs;
    std::vector<OptimalTrajectoryPlannerLog> otpLogs;
    std::vector<CommInLog> commInLogs;
    std::vector<CommOutLog> commOutLogs;
};

/// @brief Reads Obrttg log msgpackMap into C++ data structure. Can throw an exception.
///
/// @param[in] msgpackMap msgpack object
/// @param[out] obrttgLog C++ data structure
void processObrttgLog(const StringKeyMsgpackMap &msgpackMap, ObrttgLog *obrttgLog);

/// @brief Reads Optimal Trajectory Planner log msgpackMap into C++ data structure. Can throw an exception.
///
/// @param[in] msgpackMap msgpack object
/// @param[out] otpLog C++ data structure
void processOptimalTrajectoryPlannerLog(const StringKeyMsgpackMap &msgpackMap, OptimalTrajectoryPlannerLog *otpLog);

/// @brief Reads communication input log msgpackMap into C++ data structure. Can throw an exception.
///
/// @param[in] msgpackMap msgpack object
/// @param[out] commInLog C++ data structure
void processCommInLog(const StringKeyMsgpackMap &msgpackMap, CommInLog *commInLog);

/// @brief Reads communication output log msgpackMap into C++ data structure. Can throw an exception.
///
/// @param[in] msgpackMap msgpack object
/// @param[out] commOutLog C++ data structure
void processCommOutLog(const StringKeyMsgpackMap &msgpackMap, CommOutLog *commOutLog);

/// @brief Reads specified msgpackMap according to the specified log type into parsedLog. Can throw an
/// exception.
///
/// @param[in] msgpackMap msgpack object
/// @param[in] logType Type of log that is represented in msgpackMap (e.g. "init").
/// @param[out] parsedLog The respective field of the main container will be pushed back accordingly.
///
/// @return 1u when logType does not match a known logType, 0u otherwise.
uint16_t readStringKeyMsgpackMap(const obrttg::StringKeyMsgpackMap &msgpackMap,
                                 const std::string &logType,
                                 obrttg::ParsedMBoxLog *parsedMBoxLog);

/// @brief Reads the specified mbox log file in to a string.
///
/// @param[in] fileName Name of the file.
///
/// @return String containing the whole log file.
std::string readMBoxLogIntoString(const std::string &fileName);

/// @brief Main function to be used when parsing a proparker log file in C++. Catches possible exceptions
/// during parse process. Obtain the string containing the log using the function
/// readMBoxLogIntoString().
///
/// @param[in] buffer String containing the to be parsed log.
/// @param[out] parsedMBoxLog Data structure into which log is read.
///
/// @return 0u when parsing is successful, 1u when unknown logtypes have occurred, 2u when struct field was
/// not present.
uint16_t parseMBoxLog(const std::string &buffer, obrttg::ParsedMBoxLog *parsedMBoxLog);

} // namespace obrttg

#endif // #ifndef _MBOX_LOGGING_INCLUDE_MSGPACK_PARSE_UTILS_HPP_
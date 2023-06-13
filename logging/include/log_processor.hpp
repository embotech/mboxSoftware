/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 18 Jun 2021
/// @brief Declaration of LogProcessor base class. It takes care of serializing log messages and writing them to the corresponding log file.

#ifndef _MBOX_LOGGING_INCLUDE_LOG_PROCESSOR_HPP_
#define _MBOX_LOGGING_INCLUDE_LOG_PROCESSOR_HPP_

#include <memory>
#include <ostream>

#include <msgpack.hpp>

#include "msgpack_wrapper_log_types.hpp"

namespace obrttg 
{
/// @brief The core class of the log message thread. Processes all incoming messgages accordingly.
class LogProcessor
{
public:
    /// @brief Constructs LogProcessor object.
    /// @param[in] logFile Reference to ostream where log is written. Processor takes ownership of stream.
    explicit LogProcessor(std::unique_ptr<std::ostream> logFile);

    /// @brief Processes calls to obrttg::Obrttg::step().
    ///
    /// @param[in] message Message containing data to be logged.
    template <typename LogMessage>
    void process(const LogMessage *message)
    {
        packer << message->log;

        logFile->flush();
    }

    //void process(const LogOptimalTrajectoryPlannerMessage *message);

    /// @return Current system timestamp
    static int64_t getCurrentTimestamp();

    /// @brief Returns a string that can be used as a log file name.
    ///
    /// The name includes a timestamp to avoid name collisions.
    ///
    /// @param[in] prefix Prefix set in front of number:
    ///                     - obrttg
    ///                     - otp
    ///                     - commIn
    ///                     - commOut
    ///
    /// @return String with file name.
    static std::string getLogFileName(const std::string &prefix);

private:
    std::unique_ptr<std::ostream> logFile;
    msgpack::packer<std::ostream> packer;
};

} // namespace obrttg
#endif //  _MBOX_LOGGING_INCLUDE_LOG_PROCESSOR_HPP_
/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 18 Jun 2021
/// @brief Declaration of the LogCommInMessage class, implementing the processing of inbound communication log messages.

#ifndef _MBOX_LOGGING_INCLUDE_LOG_COMMUNICATION_IN_MESSAGE_HPP_
#define _MBOX_LOGGING_INCLUDE_LOG_COMMUNICATION_IN_MESSAGE_HPP_

#include <utility>

#include "message.hpp"

#include "msgpack_parse_utils.hpp"
#include "log_processor.hpp"

namespace obrttg 
{
struct LogCommInMessage : public embo::Message<LogProcessor>
{
    LogCommInMessage(const busGncCommIn &commIn)
        : log({LogProcessor::getCurrentTimestamp(), commIn})
    {
    }

    void process(LogProcessor *processor) const override
    {
        processor->process(this);
    }

    const CommInLog log;
};
} // namespace obrttg 

#endif // #ifndef _MBOX_LOGGING_INCLUDE_LOG_COMMUNICATION_IN_MESSAGE_HPP_
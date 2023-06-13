/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 18 Jun 2021
/// @brief Declaration of the LogObrttgMessage class, implementing the processing of Obrttg log messages.

#ifndef _MBOX_LOGGING_INCLUDE_LOG_OBRTTG_MESSAGE_HPP_
#define _MBOX_LOGGING_INCLUDE_LOG_OBRTTG_MESSAGE_HPP_

#include <utility>

#include "message.hpp"

#include "msgpack_parse_utils.hpp"
#include "log_processor.hpp"

namespace obrttg 
{
struct LogObrttgMessage : public embo::Message<LogProcessor>
{
    LogObrttgMessage(const busGncNavigation &navigation, 
                     const busGncGuidance &guidance,
                     const busGncMvm &mvm)
        : log({LogProcessor::getCurrentTimestamp(), navigation, guidance, mvm})
    {
    }

    void process(LogProcessor *processor) const override
    {
        processor->process(this);
    }

    const ObrttgLog log;
};
} // namespace obrttg 

#endif // #ifndef _MBOX_LOGGING_INCLUDE_LOG_OBRTTG_MESSAGE_HPP_
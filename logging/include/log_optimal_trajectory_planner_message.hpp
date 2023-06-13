/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 18 Jun 2021
/// @brief Declaration of the LogOptimalTrajectoryPlannerMessage class, implementing the processing of optimal trajectory planner log messages.

#ifndef _MBOX_LOGGING_INCLUDE_LOG_OPTIMAL_TRAJECTORY_PLANNER_MESSAGE_HPP_
#define _MBOX_LOGGING_INCLUDE_LOG_OPTIMAL_TRAJECTORY_PLANNER_MESSAGE_HPP_

#include <utility>

#include "message.hpp"

#include "msgpack_parse_utils.hpp"
#include "log_processor.hpp"

namespace obrttg 
{
struct LogOptimalTrajectoryPlannerMessage : public embo::Message<LogProcessor>
{
    LogOptimalTrajectoryPlannerMessage(const busGncOtp &otp)
        : log({LogProcessor::getCurrentTimestamp(), otp})
    {
    }

    void process(LogProcessor *processor) const override
    {
        processor->process(this);
    }

    const OptimalTrajectoryPlannerLog log;
};
} // namespace obrttg 

#endif // #ifndef _MBOX_LOGGING_INCLUDE_LOG_OPTIMAL_TRAJECTORY_PLANNER_MESSAGE_HPP_
/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file message.hpp
/// @author embotech AG
/// @date 23 Jul 2020
/// @brief Contains base class for messages.

#ifndef UTILS_MESSAGE_THREAD_INCLUDE_MESSAGE_HPP_
#define UTILS_MESSAGE_THREAD_INCLUDE_MESSAGE_HPP_

namespace embo
{
/// @brief Derive from this class to define your custom message payloads.
///
/// @tparam MessageProcessor Message processor that can process the derived message type. Should provide a
///                          method
///                             void process(const MessageType *msg)
///                          for the derived message type.
template<typename MessageProcessor>
struct Message
{
    Message() = default;
    virtual ~Message() = default;

    // Copying and moving is not possible
    Message(const Message &) = delete;
    Message &operator=(const Message &) = delete;
    Message(Message &&other) noexcept = delete;
    Message &operator=(Message &&other) noexcept = delete;

    /// Dispatches call to message processor. Implement with
    ///     processor->process(this);
    virtual void process(MessageProcessor *processor) const = 0;
};
} // namespace embo
#endif // UTILS_MESSAGE_THREAD_INCLUDE_MESSAGE_HPP_

/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file request_reply_message.hpp
/// @author embotech AG
/// @date 29 Jul 2020
/// @brief Contains base class for messages sent to request/reply threads.

#ifndef UTILS_MESSAGE_THREAD_INCLUDE_REQUEST_REPLY_MESSAGE_HPP_
#define UTILS_MESSAGE_THREAD_INCLUDE_REQUEST_REPLY_MESSAGE_HPP_

#include <memory>
#include <utility>

#include "message.hpp"
#include "sync_queue.hpp"

namespace embo
{
/// @brief Message containing a pointer to queue to transfer a reply.
///
/// @tparam MessageProcessor Message processor that can process the derived message type. Should provide a
///                          method
///                             std::unique_ptr<ReplyType> processRequest(const MessageType *msg)
///                          for the derived message type.
/// @tparam Reply Datatype of reply expected by callback.
template<typename MessageProcessor, typename Reply>
struct RequestReplyMessage : public Message<MessageProcessor>
{
    RequestReplyMessage() : Message<MessageProcessor>(), m_replyQueuePtr({})
    {
    }

    /// Dispatches call to message processor. Implement with
    ///     return processor->processRequest(this);
    virtual std::unique_ptr<Reply> processRequest(MessageProcessor *processor) const = 0;

    std::weak_ptr<SyncQueue<std::unique_ptr<Reply>>> m_replyQueuePtr;

private:
    void process(MessageProcessor *processor) const override
    {
        std::unique_ptr<Reply> reply = this->processRequest(processor);
        if (auto replyQueue = m_replyQueuePtr.lock())
        {
            replyQueue->enqueue(std::move(reply));
        }
    }
};
} // namespace embo

#endif // UTILS_MESSAGE_THREAD_INCLUDE_REQUEST_REPLY_MESSAGE_HPP_

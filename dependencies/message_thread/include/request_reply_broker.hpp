/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file request_reply_broker.hpp
/// @author embotech AG
/// @date 27 Jul 2020
/// @brief Contains broker to communicate with request/reply thread.

#ifndef UTILS_MESSAGE_THREAD_INCLUDE_REQUEST_REPLY_BROKER_HPP_
#define UTILS_MESSAGE_THREAD_INCLUDE_REQUEST_REPLY_BROKER_HPP_

#include <memory>
#include <utility>

#include "message_thread.hpp"
#include "request_reply_message.hpp"
#include "sync_queue.hpp"

namespace embo
{
/// @brief Message thread broker for specific requests.
///
/// The broker takes messages and sends them to a message threads. It fills the messages with a callback
/// that allows is to receive replies. Replies are stored in a FIFO queue.
///
/// @tparam MessageProcessor Message processor class used by message thread.
/// @tparam Reply Datatype of reply received in callback.
template<typename MessageProcessor, typename Reply>
class RequestReplyBroker
{
public:
    /// @brief Construct a new Request Reply Broker object
    ///
    /// @param[in] messageThread Non-owning pointer to the message thread.
    explicit RequestReplyBroker(std::weak_ptr<MessageThread<MessageProcessor>> messageThread)
        : m_messageThread(std::move(messageThread)),
          m_replyQueue(std::make_shared<SyncQueue<std::unique_ptr<Reply>>>())
    {
    }

    ~RequestReplyBroker() = default;

    // Copying is not possible, moving not implemented
    RequestReplyBroker(const RequestReplyBroker &) = delete;
    RequestReplyBroker &operator=(const RequestReplyBroker &) = delete;
    RequestReplyBroker(RequestReplyBroker &&other) noexcept = delete;
    RequestReplyBroker &operator=(RequestReplyBroker &&other) noexcept = delete;

    /// @brief Sends message to the message thread. Can fail if message thread has been destructed.
    ///
    /// @param[in] msg Message to be sent to the message thread. replyQueuePtr is modified!
    /// @return true if message is sent, false if thread is dead
    bool postMessage(std::unique_ptr<RequestReplyMessage<MessageProcessor, Reply>> msg)
    {
        // Weak pointer to be copied into a shared_ptr before usage
        auto messageThread = m_messageThread.lock();
        if (messageThread)
        {
            // Add pointer back to this broker's reply queue to the message
            msg->m_replyQueuePtr = m_replyQueue;
            messageThread->postMessage(std::move(msg));
        }
        return static_cast<bool>(messageThread); // true if shared_ptr holds pointer
    }

    /// @brief Checks if there are any replies in queue.
    bool isReplyReady()
    {
        return !m_replyQueue->empty();
    }

    /// @brief Returns reply from message thread. Blocking function, i.e. waits for reply to arrive if it
    ///        hasn't.
    std::unique_ptr<Reply> getReply()
    {
        return m_replyQueue->getFront();
    }

private:
    std::weak_ptr<MessageThread<MessageProcessor>> m_messageThread;
    std::shared_ptr<SyncQueue<std::unique_ptr<Reply>>> m_replyQueue;
};
} // namespace embo
#endif // UTILS_MESSAGE_THREAD_INCLUDE_REQUEST_REPLY_BROKER_HPP_

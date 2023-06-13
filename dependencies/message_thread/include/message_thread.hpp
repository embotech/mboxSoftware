/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file msg_thread.hpp
/// @author embotech AG
/// @date 14 Jul 2020
/// @brief Message thread implementation.

#ifndef UTILS_MESSAGE_THREAD_INCLUDE_MESSAGE_THREAD_HPP_
#define UTILS_MESSAGE_THREAD_INCLUDE_MESSAGE_THREAD_HPP_

#include <memory>
#include <mutex>
#include <thread>
#include <utility>

#include "message.hpp"
#include "sync_queue.hpp"

namespace embo
{
/// @brief Generic message thread. The key object is the MessageProcessor object that is used proccess all
///        received messages.
/// @tparam MessageProcessor Message processor that can process the all message types sent to this thread.
template<typename MessageProcessor>
class MessageThread
{
public:
    /// @brief Message thread constructor.
    ///
    /// @param[in] processor Message processor
    explicit MessageThread(std::unique_ptr<MessageProcessor> processor)
        : m_started(false), m_shutDown(false), m_thread(), m_queue(), m_processor(std::move(processor))
    {
    }

    // Delete copy and assignment constructors (rule of 5)
    MessageThread(const MessageThread &) = delete;
    MessageThread &operator=(const MessageThread &) = delete;
    MessageThread(MessageThread &&other) = delete;
    MessageThread &operator=(MessageThread &&other) = delete;

    virtual ~MessageThread()
    {
        if (m_started)
        {
            // This will first empty the queue and then shut down the thread.
            m_shutDown = true;
            postMessage({}); // Post empty message to trigger queue
            m_thread.join();
        }
    }

    /// @brief Launches the internal message processing thread.
    ///
    void start()
    {
        std::lock_guard<std::mutex> lk(m_startMutex);
        if (!m_started)
        {
            // Thread cannot be started in constructor because we need to await full construction of derived
            // objects to have the virtual function ready.
            m_thread = std::thread(&MessageThread::run, this);
            m_started = true;
        }
    }

    /// @brief Posts a new message that will be processed in the internal message thread.
    ///
    /// @param[in] msg Message
    void postMessage(std::unique_ptr<const Message<MessageProcessor>> msg)
    {
        m_queue.enqueue(std::move(msg));
    }

private:
    /// @brief Function that is executed in the internal thread. Processes messages that are pushed onto the
    /// message queue. Function terminates when shutdown flag is set and queue is empty.
    ///
    void run()
    {
        while (!m_shutDown || !m_queue.empty())
        {
            auto msg = m_queue.getFront();
            if (msg != nullptr)
            {
                msg->process(m_processor.get());
            }
        }
    }

    std::mutex m_startMutex; ///< Protects start() method
    bool m_started;          ///< Protects against multiple calls of start()
    bool m_shutDown;         ///< Set to true in destructor
    std::thread m_thread;    ///< Thread handle

    // Queue stores base class pointers to allow for polymorphism.
    SyncQueue<std::unique_ptr<const Message<MessageProcessor>>> m_queue;
    std::unique_ptr<MessageProcessor> m_processor;
};
} // namespace embo
#endif // UTILS_MESSAGE_THREAD_INCLUDE_MESSAGE_THREAD_HPP_

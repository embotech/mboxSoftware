/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file sync_queue.hpp
/// @author embotech AG
/// @date 14 Jul 2020
/// @brief SyncQueue implementation.

#ifndef UTILS_MESSAGE_THREAD_INCLUDE_SYNC_QUEUE_HPP_
#define UTILS_MESSAGE_THREAD_INCLUDE_SYNC_QUEUE_HPP_

#include <condition_variable>
#include <mutex>
#include <queue>
#include <utility>

namespace embo
{
/// @brief Wraps a std::queue where elements can be pushed onto in a threadsafe way. Uses a condition_variable
/// to notify about newly pushed elements, which are then returned in the getFront() method. Used in the
/// MessageThread template.
///
/// @tparam T Any type.
template<typename T>
class SyncQueue
{
public:
    /// @brief Check whether the queue is empty.
    ///
    /// @return True when empty.
    bool empty()
    {
        std::lock_guard<std::mutex> lk{queueMutex};

        return queue.empty();
    }

    /// @brief Pushes a new element into the queue.
    ///
    /// @param element Element to be pushed into queue.
    void enqueue(T element)
    {
        {
            std::lock_guard<std::mutex> lk{queueMutex};
            queue.push(std::move(element));
        }
        conditionVariable.notify_one();
    }

    /// @brief Waits until the queue is non empty and then returns the front element.
    ///
    /// @return Front element of queue.
    T getFront()
    {
        // Wait for an element to be added to the queue
        std::unique_lock<std::mutex> lk{queueMutex};
        conditionVariable.wait(lk, [&] { return !queue.empty(); });
        auto element = std::move(queue.front());
        queue.pop();

        return element;
    }

private:
    std::condition_variable conditionVariable;
    std::mutex queueMutex;
    std::queue<T> queue;
};
} // namespace embo
#endif // UTILS_MESSAGE_THREAD_INCLUDE_SYNC_QUEUE_HPP_

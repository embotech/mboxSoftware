/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file 
/// @author embotech AG
/// @date 03 Nov 2021
/// @brief Declaration of Watchdog class implementing a watchdog timer.

#ifndef _UTILS_INCLUDE_WATCHDOG_HPP_
#define _UTILS_INCLUDE_WATCHDOG_HPP_

#include <thread>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <functional>

#include <signal.h>
#include <time.h>
#include <pthread.h>

namespace obrttg 
{
class Watchdog
{
public:
    Watchdog();
    Watchdog(uint64_t timer);
    Watchdog(uint64_t timer, std::function<void()> callback);

    ~Watchdog();

    ///@brief Sets the value of the watchdog timer interval in microseconds
    ///
    ///@param[in] duration Wathdog timer interval in microseconds
    ///@return 0 if success, 1 otherwise
    int setDuration(uint64_t duration);

    ///@brief Sets the callback function to be called when the watchdog timer expires.
    /// The callback function can be set only while the watchdog timer is not running.
    ///
    ///@param[in] callback Void function taking no arguments
    ///@return 0 if success, 1 otherwise
    int setCallback(std::function<void()> callback);

    ///@brief Starts watchdog timer
    ///
    ///@return 0 if success, 1 otherwise
    int start();

    ///@brief Stops watchdog timer
    void stop();

    ///@brief Resets watchdog timer
    void pet();

    ///@brief Method to check if the watchdog timer is running
    ///
    ///@return true if it is running, false otherwise
    bool isRunning();

    ///@brief Static method handling the timeout callback
    ///@param[in] sigval 
    static void handler(sigval_t sigval);

private:
    uint64_t m_duration;                        ///< Watchdog timer interval duration in midroseconds
    std::atomic<bool> m_init;                   ///< Boolean flag defining whether the watchdog timer is initialized
    std::atomic<bool> m_running;                ///< Boolean flag defining whether the watchdog timer is running
    std::function<void()> m_callback;           ///< Callback function
    std::mutex m_mtx;                           ///< Watchdog timer mutex
    timer_t m_timerid;                          ///< POSIX timer structure

    ///@brief Configures and creates a POSIX per-process timer.
    /// The timer uses the CLOCK_MONOTONIC clock to measure time. 
    /// Upon expiration of the timer, the callback function (provided via setCallback) is invoked.
    ///
    ///@return 0 if success, 1 otherwise
    int initialize();

    ///@brief Starts the timer
    ///
    ///@return 0 if success, -1 otherwise
    int arm();

    ///@brief Stops the timer
    ///
    ///@return 0 if success, -1 otherwise
    int disarm();
}; 
}   // namespace obrttg

#endif // _UTILS_INCLUDE_WATCHDOG_HPP_
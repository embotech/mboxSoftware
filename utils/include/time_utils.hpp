/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 29 Jun 2021
/// @brief Declaration of time helper functions.

#ifndef _UTILS_CONTAINERS_INCLUDE_TIME_UTILS_HPP_
#define _UTILS_CONTAINERS_INCLUDE_TIME_UTILS_HPP_

#include <chrono>
#include <thread>

namespace obrttg 
{
using namespace std::chrono;
inline uint64_t unow()
{
    return duration_cast<microseconds>(steady_clock::now().time_since_epoch()).count();
}

inline uint64_t mnow()
{
    return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

inline steady_clock::time_point tic()
{
    return steady_clock::now();
}

inline uint64_t utoc(const steady_clock::time_point &t0)
{
    return duration_cast<microseconds>(steady_clock::now().time_since_epoch()).count() -
           duration_cast<microseconds>(t0.time_since_epoch()).count();
}

/// @brief  Blocks the execution of the current thread for at least the specified amount of nanoseconds
inline void nsleep(uint64_t ns)
{
    std::this_thread::sleep_for(nanoseconds(ns));
}

/// @brief  Blocks the execution of the current thread for at least the specified amount of microseconds
inline void usleep(uint64_t us)
{
    std::this_thread::sleep_for(microseconds(us));
}

/// @brief  Blocks the execution of the current thread for at least the specified amount of milliseconds
inline void msleep(uint64_t ms)
{
    std::this_thread::sleep_for(milliseconds(ms));
}

/// @brief  Blocks the execution of the current thread for at least the specified amount of seconds
inline void ssleep(uint64_t s)
{
    std::this_thread::sleep_for(seconds(s));
}
} // namespace obrttg

#endif // _UTILS_CONTAINERS_INCLUDE_TIME_UTILS_HPP_
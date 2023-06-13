/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Mar 2022
/// @brief Declaration of thread configuration helper class for Obrttg.

#ifndef _UTILS_INCLUDE_THREAD_CONFIGURATION_HPP_
#define _UTILS_INCLUDE_THREAD_CONFIGURATION_HPP_

#include <thread>
#include <vector>
#include <sys/sysinfo.h>

namespace obrttg
{
// Return codes
//
// ThreadConfiguration success
static constexpr uint16_t THREAD_CONFIG_SUCCESS = 0u;

// Apply configuration errors
static constexpr uint16_t ERROR_THREAD_CONFIG_APPLY_AFFINITY = 1u;
static constexpr uint16_t ERROR_THREAD_CONFIG_APPLY_SCHED_PARAMS = 2u;

typedef struct ThreadConfiguration
{
    ThreadConfiguration() : priority(0), policy(SCHED_OTHER)
    {
        int ncpus = get_nprocs();
        cpuSet.clear();
        for (int i = 0; i < ncpus; i++)
        {
            cpuSet.push_back(i);
        }
    }

    ThreadConfiguration(std::vector<int> _cpuSet, int _priority, int _policy)
        : priority(_priority), policy(_policy), cpuSet(_cpuSet) {}
    
    /// @brief Applies thread configuration to the given thread
    ///
    /// @param[in] thr Native handle to thread
    ///
    /// @return 0 success, otherwise error code
    int apply(std::thread::native_handle_type thr)
    {
        cpu_set_t set;
        sched_param schedParams; 
        schedParams.sched_priority = priority;
        CPU_ZERO(&set);
        for (auto i = 0; i < cpuSet.size(); i++)
        {
            CPU_SET(cpuSet[i], &set);
        }
        if (pthread_setaffinity_np(thr, sizeof(cpu_set_t), &set))
        {
            return ERROR_THREAD_CONFIG_APPLY_AFFINITY;
        }
        if (pthread_setschedparam(thr, policy, &schedParams))
        {
            return ERROR_THREAD_CONFIG_APPLY_SCHED_PARAMS;
        }

        return THREAD_CONFIG_SUCCESS;
    }

    ///< Value in the range (0 - 99) defining the thread priority
    int priority;
    ///< Value defining the thread scheduling policy
    ///     https://man7.org/linux/man-pages/man7/sched.7.html
    ///         - SCHED_FIFO (real-time policy)
    ///         - SCHED_RR (real-time policy)
    int policy;
    ///< Vector of cpu IDs defining the thread affinity
    std::vector<int> cpuSet;
} ThreadConfiguration;

}

#endif // #ifndef _UTILS_INCLUDE_THREAD_CONFIGURATION_HPP_

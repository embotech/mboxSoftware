/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 10 Jun 2021
/// @brief Declaration of the OptimalTrajectoryPlanner class, implementing the interface to the Optimal Trajectory planner running asynchronously.

#ifndef _MBOX_OBRTTG_INCLUDE_OPTIMAL_TRAJECTORY_PLANNER_HPP_
#define _MBOX_OBRTTG_INCLUDE_OPTIMAL_TRAJECTORY_PLANNER_HPP_

#include <thread>
#include <pthread.h>
#include <mutex>

// libembotech
#include "sync_queue.hpp"
#include "message_thread.hpp"

// obrttg
#include "log_processor.hpp"
#include "otp_interface.hpp"
#include "obrttg.hpp"
#include "thread_configuration.hpp"

// codegen
#ifdef __cplusplus
extern "C"
{
#endif
#include "obrttg_otp_sfcn_nlp3_DTVsingle_96d7.h"
#ifdef __cplusplus
}
#endif

namespace obrttg
{
// Return codes
//
// OTP success
static constexpr uint16_t OTP_SUCCESS = 0u;

// Init errors (1 - 99)
static constexpr uint16_t ERROR_OTP_INIT_REPEATED = 1u;             ///< Start method was already called
static constexpr uint16_t ERROR_OTP_INIT_OTP = 2u;                  ///< Error initializing OTP component
static constexpr uint16_t ERROR_OTP_INIT_LICENSE = 3u;              ///< FORCES License error when initializing OTP

// Start errors (100 - 199)
static constexpr uint16_t ERROR_OTP_START_NOT_INIT = 100u;
static constexpr uint16_t ERROR_OTP_START_REPEATED = 101u;              ///< Start method was already called
static constexpr uint16_t ERROR_OTP_START_THREAD_AFFINITY = 102u;       ///< Error configuring OTP thread affinity
static constexpr uint16_t ERROR_OTP_START_THREAD_SCHEDULING = 103u;     ///< Error configuring OTP thread scheduling params

// Thread configuration
static constexpr uint16_t ERROR_OTP_SET_THREAD_CFG = 300u;              ///< Error setting the thread configuration

typedef struct ComputationRequest
{
    ComputationRequest() = default;
    ComputationRequest(const busGncParameters &parameters, const busGncCommIn &commIn, const busGncMvm &mvm, const busGncGuidance &guidance) :
        m_parameters(parameters), m_commIn(commIn), m_mvm(mvm), m_guidance(guidance)
    {}

    // Copying and moving is not possible
    ComputationRequest(const ComputationRequest &) = delete;
    ComputationRequest &operator=(const ComputationRequest &) = delete;
    ComputationRequest(ComputationRequest &&other) noexcept = delete;
    ComputationRequest &operator=(ComputationRequest &&other) noexcept = delete;

    busGncParameters m_parameters;
    busGncCommIn m_commIn;
    busGncMvm m_mvm;
    busGncGuidance m_guidance;
} ComputationRequest;

class OptimalTrajectoryPlanner
{
public:
    OptimalTrajectoryPlanner();
    ~OptimalTrajectoryPlanner();

    // Delete copy and assignment constructors (rule of 5)
    OptimalTrajectoryPlanner(const OptimalTrajectoryPlanner &) = delete;
    OptimalTrajectoryPlanner &operator=(const OptimalTrajectoryPlanner &) = delete;
    OptimalTrajectoryPlanner(OptimalTrajectoryPlanner &&other) = delete;
    OptimalTrajectoryPlanner &operator=(OptimalTrajectoryPlanner &&other) = delete;

    virtual int initialize();
    virtual int start();
    virtual void terminate();
    virtual void step(std::unique_ptr<const ComputationRequest> request);

    virtual busGncOtp getResult();
    virtual bool isResultReady();

    int setThreadConfig(ThreadConfiguration &cfg);

private:
    void run();

    void setResult(busGncOtp result);

    void startLogging();
    void stopLogging();

    /// @brief Checks the FORCES solver license
    ///
    /// @return true if license check is ok, false otherwise
    bool checkLicense();

    std::mutex m_initMtx;                           ///< Protects initialize() method from being called simultaneously
    std::mutex m_startMutex;                        ///< Protects start() method from being called simultaneously
    std::condition_variable m_runCondition;
    std::mutex m_runMtx;                            ///< Prevents run() from starting before being ready
    std::mutex m_resultMutex;                       ///< Protects 

    bool m_init;                                    ///< Protects against multiple calls of initialize()
    bool m_started;                                 ///< Protects against multiple calls of start()
    bool m_threadReady;                             ///< Prevents run() from starting before the thread is configured
    bool m_shutDown;
    bool m_computing;                               ///< Protects against multiple calls of step()

    std::thread m_thread;                           ///< OTP thread handle 
    ThreadConfiguration m_threadCfg;                ///< OTP thread configuration

    OtpInterface m_otp;
    busGncOtp m_result;

    embo::SyncQueue<std::unique_ptr<const ComputationRequest>> m_queue;
    std::unique_ptr<embo::MessageThread<LogProcessor>> m_logMsgThread;  ///< Logging thread

};
} // namespace obrttg
#endif // _MBOX_OBRTTG_INCLUDE_OPTIMAL_TRAJECTORY_PLANNER_HPP_
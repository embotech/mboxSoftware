/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Jun 2021
/// @brief Declaration of the ObrttgPeriodic class, implementing the interface to the periodic segment of the mBox software.

#ifndef _MBOX_OBRTTG_INCLUDE_OBRTTG_PERIODIC_HPP_
#define _MBOX_OBRTTG_INCLUDE_OBRTTG_PERIODIC_HPP_

#include <mutex>
#include <memory>

#include "message_thread.hpp"

#include "log_processor.hpp"
#include "parameters_interface.hpp"
#include "navigation_interface.hpp"
#include "mvm_interface.hpp"
#include "guidance_interface.hpp"

#ifdef __cplusplus
extern "C"
{
#endif
#include "obrttg_navigation_mBox.h"
#include "obrttg_mvm_mBox.h"
#include "obrttg_guidance_mBox.h"
#ifdef __cplusplus
}
#endif

//#include "mbox_parameters.hpp"

namespace obrttg
{
// Return codes
//
// Obrttg periodic success
static constexpr uint16_t PERIODIC_SUCCESS = 0u;

// Obrttg periodic initialize errors (1 - 99)
static constexpr uint16_t ERROR_PERIODIC_INIT_REPEATED = 1u;
static constexpr uint16_t ERROR_PERIODIC_INIT_PARAMETERS = 2u;
static constexpr uint16_t ERROR_PERIODIC_INIT_NAVIGATION = 3u;
static constexpr uint16_t ERROR_PERIODIC_INIT_MVM = 4u;
static constexpr uint16_t ERROR_PERIODIC_INIT_GUIDANCE = 5u;

// Obrttg periodic start errors (100 - 199)
static constexpr uint16_t ERROR_PERIODIC_START_NOT_INIT = 100u;
static constexpr uint16_t ERROR_PERIODIC_START_REPEATED = 101u;

// Obrttg periodic step errors (100 - 199)
static constexpr uint16_t ERROR_PERIODIC_STEP_PARAMETERS = 100u;
static constexpr uint16_t ERROR_PERIODIC_STEP_NAVIGATION = 101u;
static constexpr uint16_t ERROR_PERIODIC_STEP_MVM = 102u;
static constexpr uint16_t ERROR_PERIODIC_STEP_GUIDANCE = 103u;

typedef struct PeriodicInput
{
    busGncCommIn inComm;
    busGncOtp otp;
} PeriodicInput;

typedef struct PeriodicOutput
{
    busGncParameters par;
    busGncNavigation nav;
    busGncMvm mvm;
    busGncGuidance gui;
    busGncCommOut outComm;
} PeriodicOutput;

typedef struct PeriodicState
{
    busGncParameters par;
    busGncCommIn comm;
    busGncNavigation nav;
    busGncMvm mvm;
    busGncOtp otp;
    busGncGuidance gui;
} PeriodicState;

class ObrttgPeriodic
{
public:
    ObrttgPeriodic();
    ~ObrttgPeriodic();

    // Delete copy and assignment constructors (rule of 5)
    ObrttgPeriodic(const ObrttgPeriodic &) = delete;
    ObrttgPeriodic &operator=(const ObrttgPeriodic &) = delete;
    ObrttgPeriodic(ObrttgPeriodic &&other) = delete;
    ObrttgPeriodic &operator=(ObrttgPeriodic &&other) = delete;

    virtual int initialize();
    virtual int start();
    virtual void terminate();
    virtual int step(const PeriodicInput &in, PeriodicOutput &out);
    virtual bool isDone();

    void setAffinity(std::vector<int> cpuSet);
    void setPriority(int priority);
    void setPolicy(int policy);

    
private:
    void startLogging();
    void stopLogging();

    std::mutex m_initMtx;                           ///< Protects initialize() method
    std::mutex m_startMtx;                          ///< Protects start() method 
    std::mutex m_stepMtx;                           ///< Protects step() method
    bool m_init;                                    ///< Protects against multiple calls of initialize()
    bool m_started;                                 ///< Protects against multiple calls of start()
    bool m_shutDown;

    ParametersInterface m_par;
    NavigationInterface m_nav;
    MvmInterface m_mvm;
    GuidanceInterface m_gui;

    PeriodicState m_state;

    std::unique_ptr<embo::MessageThread<LogProcessor>> m_logMsgThread;  ///< Logging thread
};
}
#endif // _MBOX_OBRTTG_INCLUDE_OBRTTG_INTERNAL_HPP_

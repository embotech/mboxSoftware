/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 9 Jun 2021
/// @brief Declaration of the Obrttg class, implementing the highest interface to the mBox software.

#ifndef _MBOX_OBRTTG_INCLUDE_OBRTTG_HPP_
#define _MBOX_OBRTTG_INCLUDE_OBRTTG_HPP_

#include <vector>
#include <memory>
#include <mutex>
#include <functional>
#include <system_error>
#include <condition_variable>

#include "obrttg_types.hpp"
#include "thread_configuration.hpp"

namespace obrttg
{
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Return codes
//
// DO NOT CHANGE ANY OF THE RETURN CODES BELOW - UNEXPECTED BEHAVIOR MAY OCCUR !!!
// Success (0)
static constexpr uint16_t SUCCESS = 0u; ///< The function call returned successfully.

// General Errors (1 - 99)
static constexpr uint16_t ERROR_INIT_REPEATED = 1u;             ///< Initialize method was called more than once
static constexpr uint16_t ERROR_START_REPEATED = 2u;            ///< Start method was called more than once
static constexpr uint16_t ERROR_START_NOT_INIT = 3u;            ///< Start method was called before initializing components
static constexpr uint16_t ERROR_START_THREAD_AFFINITY = 4u;     ///< Error configuring Obrttg main thread affinity
static constexpr uint16_t ERROR_START_THREAD_SCHEDULING = 5u;   ///< Error configuring Obrttg main thread scheduling parameters
static constexpr uint16_t ERROR_UNKNOWN = 99u;                  ///< Unknown error occured

// Obrttg Periodic Obrttg errors (100 - 199)
static constexpr uint16_t ERROR_OBRTTG_PER_INIT_REPEATED = 100u;            ///< Periodic initialize method called more than once
static constexpr uint16_t ERROR_OBRTTG_PER_INIT_PARAMETERS = 101u;          ///< Failed to initialize parameters module
static constexpr uint16_t ERROR_OBRTTG_PER_INIT_NAVIGATION = 102u;          ///< Failed to initialize navigation module
static constexpr uint16_t ERROR_OBRTTG_PER_INIT_MVM = 103u;                 ///< Falied to initialize MVM module
static constexpr uint16_t ERROR_OBRTTG_PER_INIT_GUIDANCE = 106u;            ///< Failed to initialize guidance module
static constexpr uint16_t ERROR_OBRTTG_PER_START_NOT_INIT = 120u;           ///< Periodic start method called before initialize() 
static constexpr uint16_t ERROR_OBRTTG_PER_START_REPEATED = 121u;           ///< Periodic start method called more than once 
static constexpr uint16_t ERROR_OBRTTG_PER_START_THREAD_AFFINITY = 122u;    ///< Failed to set periodic thread affinity
static constexpr uint16_t ERROR_OBRTTG_PER_START_THREAD_SCHEDULING = 123u;  ///< Failed to set periodic thread scheduling params
static constexpr uint16_t ERROR_OBRTTG_PER_INIT_UNKNOWN = 190u;             ///< Periodic Obrttg unknown error when calling initialize()
static constexpr uint16_t ERROR_OBRTTG_PER_START_UNKNOWN = 191u;            ///< Periodic Obrttg unknown error when calling start() 


// Obrttg Optimal Trajectory Planner errors (200 - 299)
static constexpr uint16_t ERROR_OBRTTG_OTP_INIT_REPEATED = 200u;            ///< OTP initialize method called more than once
static constexpr uint16_t ERROR_OBRTTG_OTP_INIT_THREAD_CFG = 201u;          ///< Error setting communication thread configuration
static constexpr uint16_t ERROR_OBRTTG_OTP_INIT_OTP = 202u;                 ///< Failed to initialize OTP module
static constexpr uint16_t ERROR_OBRTTG_OTP_INIT_LICENSE = 203u;             ///< Failed FORCES license check
static constexpr uint16_t ERROR_OBRTTG_OTP_START_NOT_INIT = 210u;           ///< Otp start method called more than once 
static constexpr uint16_t ERROR_OBRTTG_OTP_START_REPEATED = 211u;           ///< Otp start method called more than once 
static constexpr uint16_t ERROR_OBRTTG_OTP_START_THREAD_AFFINITY = 212u;    ///< Failed to set OTP thread affinity
static constexpr uint16_t ERROR_OBRTTG_OTP_START_THREAD_SCHEDULING = 213u;  ///< Failed to set OTP thread scheduling parameters
static constexpr uint16_t ERROR_OBRTTG_OTP_INIT_UNKNOWN = 290u;             ///< OTP unknown error when calling initialize()
static constexpr uint16_t ERROR_OBRTTG_OTP_START_UNKNOWN = 291u;            ///< OTP unknown error when calling start()


// Obrttg Communication errors (300 - 399)
static constexpr uint16_t ERROR_OBRTTG_COM_INIT_REPEATED = 300u;            ///< OTP initialize method called more than once
static constexpr uint16_t ERROR_OBRTTG_COM_INIT_THREAD_CFG = 301u;          ///< Error setting communication thread configuration
static constexpr uint16_t ERROR_OBRTTG_COM_INIT_LOW_LEVEL = 302u;           ///< Error initializing the low-level interface
static constexpr uint16_t ERROR_OBRTTG_COM_START_NOT_INIT = 310u;           ///< Comm start method called before initializing
static constexpr uint16_t ERROR_OBRTTG_COM_START_REPEATED = 311u;           ///< Comm start method called more than once
static constexpr uint16_t ERROR_OBRTTG_COM_START_TIMEOUT = 312u;            ///< Timeout while initializing obrttg communication
static constexpr uint16_t ERROR_OBRTTG_COM_START_THREAD_AFFINITY = 313u;    ///< Failed to set communication thread affinity
static constexpr uint16_t ERROR_OBRTTG_COM_START_THREAD_SCHEDULING = 314u;  ///< Failed to set communication thread scheduling parameters
static constexpr uint16_t ERROR_OBRTTG_COM_STEP_RX_EMPTY = 320u;            ///< No input messages when calling receive()
static constexpr uint16_t ERROR_OBRTTG_COM_STEP_RX_ACTIVE = 321u;           ///< Comm link not active when calling receive() 
static constexpr uint16_t ERROR_OBRTTG_COM_STEP_TX_ACTIVE = 322u;           ///< Comm link not active when calling transmit() 
static constexpr uint16_t ERROR_OBRTTG_COM_INIT_UNKNOWN = 390u;             ///< Comm unknown error when calling initialize()
static constexpr uint16_t ERROR_OBRTTG_COM_START_UNKNOWN = 391u;            ///< Comm unknown error when calling start()
static constexpr uint16_t ERROR_OBRTTG_COM_RX_UNKNOWN = 392u;               ///< Comm unknown error when calling receive()
static constexpr uint16_t ERROR_OBRTTG_COM_TX_UNKNOWN = 393u;               ///< Comm unknown error when calling transmit()

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class 
//
// DO NOT CHANGE ANY OF THE CLASSES BELOW - UNEXPECTED BEHAVIOR MAY OCCUR !!!

/// @brief Class containing implementation details of obrttg::OptimalTrajectoryPlanner
class OptimalTrajectoryPlanner;

/// @brief Class containing implementation details of obrttg::ObrttgPeriodic
class ObrttgPeriodic;

/// @brief Class containing implementation details of obrttg::CommunicationInterface
class CommunicationInterface;


typedef int (commInFcn)(busGncCommIn &); 
typedef int (commOutFcn)(const busGncCommOut &); 

typedef struct ThreadConfigurations {
    ThreadConfigurations() :
        main(ThreadConfiguration({0}, 99, SCHED_FIFO)), 
        otp(ThreadConfiguration({1}, 99, SCHED_FIFO)),
        comm(ThreadConfiguration({2}, 99, SCHED_FIFO))
        {}

    obrttg::ThreadConfiguration main;
    obrttg::ThreadConfiguration otp;
    obrttg::ThreadConfiguration comm;

} ThreadConfigurations;

/// @brief Class defining the main interface to configure and launch the Obrttg Software
class Obrttg
{
public:
    /// @brief Constructor for Obrttg object
    Obrttg(); 
    /// @brief Destructor for Obrttg object
    ~Obrttg();
        
    // Delete copy and move constructors/assignments (rule of 5)
    // Delete copy constructor
    Obrttg(const Obrttg &) = delete;
    // Delete copy assignment
    Obrttg &operator=(const Obrttg &) = delete;
    // Delete move constructor
    Obrttg(Obrttg &&other) = delete;
    // Delete move assignment
    Obrttg &operator=(Obrttg &&other) = delete;

    /// @brief Configure an alternative Optimal Trajectory Planner
    ///
    /// @param[in] otp Shared pointer to OptimalTrajectoryPlanner object
    ///
    /// @return Returns false if assignment was successful, false otherwise
    bool setOptimalTrajectoryPlanner(std::shared_ptr<OptimalTrajectoryPlanner> otp);

    /// @brief Configure an alternative ObrttgPeriodic. The ObrttgPeriodic class manages:
    ///             - Parameters
    ///             - Navigation
    ///             - Mission and Vehicle Management
    ///             - Guidance
    ///
    /// @param[in] periodic Shared pointer to ObrttgPeriodic object
    ///
    /// @return false if assignment was successful, true otherwise
    bool setPeriodicObrttg(std::shared_ptr<ObrttgPeriodic> periodic);

    /// @brief Configure an alternative CommunicationInterface.
    ///
    /// @param[in] comm Shared pointer to CommunicationInterface object
    ///
    /// @return false if assignment was successful, true otherwise
    bool setCommunicationInterface(std::shared_ptr<CommunicationInterface> comm);

    /// @brief Initializes the different modules in the Obrttg software
    ///
    /// @return 0 if the initialization was successful, 1 otherwise
    int initialize();

    /// @brief Initializes the different modules in Obrttg software.
    ///
    /// @return 0 if the start was successful, error code otherwise 
    int start();

    /// @brief Waits for the current mission to be done
    ///
    /// @return 0 if the mission run successfully, 1 otherwise
    int join();

    /// @brief Terminates the different modules in Obrttg software.
    void terminate();

    /// @brief Runs an individual step of the Obrttg sofware.
    ///
    /// @return 0 if the Obrttg software step runs successfully, error code otherwise
    int step();
    
    /// @brief Checks if the Obrttg software has completed its execution.
    ///
    /// @return false if the Obrttg software is still running, true otherwise
    bool isDone();

    /// @brief Return the configuration of the different Obrttg threads
    ///
    /// @return Current Obrttg ThreadConfigurations object
    ThreadConfigurations getThreadConfig() const; 

    /// @brief Set new ThreadConfiguration object for the Obrttg
    ///
    /// @param[in] threadConfig ThreadConfigurations object
    void setThreadConfig(ThreadConfigurations &threadConfig);

    /// @brief Configures input communication callback
    ///
    /// @param[in] callback Callback function to receive input messages
    void setCommInCallback(std::function<commInFcn> callback);

    /// @brief Configures output communication callback
    ///
    /// @param[in] callback Callback function to transmit output messages
    void setCommOutCallback(std::function<commOutFcn> callback);

    uint16_t status() const { return m_status; }

    /// @brief Defines the number of cycles the Obrttg software can run without an updated state. Afterwards, an 
    /// ERROR_OBRTTG_COM_STEP_RX_EMPTY error is triggered.
    ///
    /// @param[in] nCycles Number of cycles the Obrttg can run without a state update.
    void setRxFaultTolerance(uint16_t nCycles);

    static const uint16_t m_ts = 40;    // Obrttg cycle time in milliseconds

private:
    /// @brief Runs the Obrttg sofware until the mission is completed.
    ///
    /// @return 0 if the Obrttg software runs successfully, error code otherwise
    int run();

    /// @brief Sets the current status
    ///
    /// @param[in] status New Obrttg software status
    void setStatus(uint16_t status) { m_status = status; }

    std::mutex m_initMtx;                               ///< Protects initialize() method
    std::mutex m_startMtx;                              ///< Protects start() method
    std::mutex m_runMtx;                                ///< Prevents run method from running before being ready
    std::condition_variable m_runCondition;             ///< Prevents run method from running before being ready

    bool m_init;                                        ///< Protects against multiple calls of initialize()
    bool m_started;                                     ///< Protects against multiple calls of start()
    bool m_shutDown;                                    ///< Protects against multiple calls of terminate()
    bool m_ready;                                       ///< Prevents run thread from running before being configured

    std::thread m_thread;                               ///< Obrttg thread handle 
    ThreadConfigurations m_threadCfg;                   ///< Configurations of the different Obrttg threads

    std::shared_ptr<OptimalTrajectoryPlanner> m_otp;    ///< Pointer to implementation OptimalTrajectoryPlanner class
    std::shared_ptr<ObrttgPeriodic> m_periodic;         ///< Pointer to implementation ObrttgPeriodic class
    std::shared_ptr<CommunicationInterface> m_comm;     ///< Pointer to implementation CommunicationInterface class

    std::function<commInFcn> m_commInCallback;          ///< Inbound communication callback
    std::function<commOutFcn> m_commOutCallback;        ///< Outbound communication callback

    uint16_t m_status;                                  ///< Stores the current error status

    uint16_t m_rxFaultTol;                              ///< Number of cycles Obrttg is allowed to run without an state update.
    uint16_t m_nRxFaults;                               ///< Number of cycles without a state update.
};
} // namespace obrttg

#endif // _MBOX_OBRTTG_INCLUDE_OBRTTG_HPP_
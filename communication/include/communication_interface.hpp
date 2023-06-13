/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 15 Jun 2020
/// @brief Declaration of the CommunicationInterface virtual class defining the communication interface of Obrttg.

#ifndef _MBOX_COMMUNICATION_INCLUDE_COMMUNICATION_INTERFACE_HPP_
#define _MBOX_COMMUNICATION_INCLUDE_COMMUNICATION_INTERFACE_HPP_

#include <mutex>

#include "obrttg_types.hpp"
#include "thread_configuration.hpp"

namespace obrttg
{

// Return codes
//
// Communication success
static constexpr uint16_t COM_SUCCESS = 0u;

// Initialize errors (1 - 99)
static constexpr uint16_t ERROR_COM_INIT_REPEATED = 1u;
static constexpr uint16_t ERROR_COM_INIT_LOW_LEVEL = 2u;

// Start errors (100 - 199)
static constexpr uint16_t ERROR_COM_START_NOT_INIT = 100u;
static constexpr uint16_t ERROR_COM_START_REPEATED = 101u;
static constexpr uint16_t ERROR_COM_START_TIMEOUT = 103u;
static constexpr uint16_t ERROR_COM_START_THREAD_AFFINITY = 104u;
static constexpr uint16_t ERROR_COM_START_THREAD_SCHEDULING = 105u;

// Run errors (200 - 299)
static constexpr uint16_t ERROR_COM_LINK_ACTIVE = 200u;         ///< Communication link not active when receive / transmit was called
static constexpr uint16_t ERROR_COM_RX_EMPTY = 201u;            ///< Rx queue was empty when receive() was called
static constexpr uint16_t ERROR_COM_NOT_INIT = 203u;            ///< transmit()/receive() method called before calling initialize()
static constexpr uint16_t ERROR_COM_NOT_START = 204u;           ///< transmit()/receive() method called before calling start()

// Thread configuration
static constexpr uint16_t ERROR_COM_SET_THREAD_CFG = 300u;

class CommunicationInterface
{
public:
    CommunicationInterface() {}

    virtual ~CommunicationInterface() {}

    // Delete copy and move constructors/assignments (rule of 5)
    // Delete copy constructor
    CommunicationInterface(const CommunicationInterface &) = delete;
    // Delete copy assignment
    CommunicationInterface &operator=(const CommunicationInterface &) = delete;
    // Delete move constructor
    CommunicationInterface(CommunicationInterface &&other) = delete;
    // Delete move assignment
    CommunicationInterface &operator=(CommunicationInterface &&other) = delete;

    virtual int initialize() { return 0; }
    virtual int start() { return 0; }
    virtual void terminate() {}

    virtual bool isActive() { return true; }

    virtual int transmit(const busGncCommOut &reference) { return 0; }
    virtual int receive(busGncCommIn &state){ return 0; }

    virtual int setThreadConfig(ThreadConfiguration &cfg) { return 0; };
};
} // namespace obrttg

#endif // _MBOX_COMMUNICATION_INCLUDE_COMMUNICATION_INTERFACE_HPP_
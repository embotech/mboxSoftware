/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 21 Jun 2021
/// @brief Declaration of utility functions to generate random Obrttg bus structures.

#ifndef _MBOX_UTILS_INCLUDE_OBRTTG_TYPES_UTILS_HPP_
#define _MBOX_UTILS_INCLUDE_OBRTTG_TYPES_UTILS_HPP_

#include "obrttg_types.hpp"

namespace obrttg
{
/// @brief Generates busGncNavigation structure filled with random values
///
/// @return busGncNavigation structure filled with random values
busGncNavigation randomBusGncNavigation();

/// @brief Generates busGncGuidance structure filled with random values
///
/// @return busGncGuidance structure filled with random values
busGncGuidance randomBusGncGuidance();

/// @brief Generates busGncMvm structure filled with random values
///
/// @return busGncMvm structure filled with random values
busGncMvm randomBusGncMvm();

/// @brief Generates busGncOtp structure filled with random values
///
/// @return busGncOtp structure filled with random values
busGncOtp randomBusGncOtp();

/// @brief Generates busGncCommIn structure filled with random values
///
/// @return busGncCommIn structure filled with random values
busGncCommIn randomBusGncCommIn();

/// @brief Generates busGncCommOut structure filled with random values
///
/// @return busGncCommOut structure filled with random values
busGncCommOut randomBusGncCommOut();

} // namespace obrttg

#endif // _MBOX_UTILS_INCLUDE_OBRTTG_TYPES_UTILS_HPP_
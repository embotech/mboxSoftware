/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 21 Jun 2021
/// @brief Declaration of test helper functions to compare Obrttg bus structs using Google Test assertions.

#ifndef _MBOX_UTILS_INCLUDE_STRUCT_COMPARATOR_HPP_
#define _MBOX_UTILS_INCLUDE_STRUCT_COMPARATOR_HPP_

#include "obrttg_types.hpp"

namespace obrttg
{
/// @brief Compares all fields of two busGncNavigation structs.
///
/// @param[in] actual
/// @param[in] expected
void compareBusGncNavigation(const busGncNavigation &actual, const busGncNavigation &expected);

/// @brief Compares all fields of two busGncGuidance structs.
///
/// @param[in] actual
/// @param[in] expected
void compareBusGncGuidance(const busGncGuidance &actual, const busGncGuidance &expected);

/// @brief Compares all fields of two busGncMvm structs.
///
/// @param[in] actual
/// @param[in] expected
void compareBusGncMvm(const busGncMvm &actual, const busGncMvm &expected);

/// @brief Compares all fields of two busGncOtp structs.
///
/// @param[in] actual
/// @param[in] expected
void compareBusGncOtp(const busGncOtp &actual, const busGncOtp &expected);

/// @brief Compares all fields of two busCommIn structs.
///
/// @param[in] actual
/// @param[in] expected
void compareBusGncCommIn(const busGncCommIn &actual, const busGncCommIn &expected);

/// @brief Compares all fields of two busCommOut structs.
///
/// @param[in] actual
/// @param[in] expected
void compareBusGncCommOut(const busGncCommOut &actual, const busGncCommOut &expected);

}   // namespace obrttg

#endif // _MBOX_UTILS_INCLUDE_STRUCT_COMPARATOR_HPP
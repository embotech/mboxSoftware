/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Jun 2021
/// @brief Declaration of NavigationInterface class derived from CodegenInterface. It provides an interface to the Navigation module.

#ifndef _MBOX_OBRTTG_INCLUDE_NAVIGATION_INTERFACE_HPP_
#define _MBOX_OBRTTG_INCLUDE_NAVIGATION_INTERFACE_HPP_

#include <mutex>

#ifdef __cplusplus
extern "C"
{
#endif
#include "obrttg_navigation_mBox.h"
#ifdef __cplusplus
}
#endif

#include "codegen_interface.hpp"

namespace obrttg
{
class NavigationInterface : public CodegenInterface<busGncNavigation, const ExtU_obrttg_navigation_mBox_T &>
{
public:
    NavigationInterface();

    bool initialize() override; 
    bool step(const ExtU_obrttg_navigation_mBox_T &input) override;
    void terminate() override;

    busGncNavigation output() const;

private:
    busGncNavigation m_output;
    std::mutex m_busyMtx;
};
}   // namespace obrttg
#endif // _MBOX_OBRTTG_INCLUDE_NAVIGATION_INTERFACE_HPP_
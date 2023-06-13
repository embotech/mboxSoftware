/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Jun 2021
/// @brief Declaration of GuidanceInterface class derived from CodegenInterface. It provides an interface to the Guidance module.

#ifndef _MBOX_OBRTTG_INCLUDE_GUIDANCE_INTERFACE_HPP_
#define _MBOX_OBRTTG_INCLUDE_GUIDANCE_INTERFACE_HPP_

#include <mutex>

#ifdef __cplusplus
extern "C"
{
#endif
#include "obrttg_guidance_mBox.h"
#ifdef __cplusplus
}
#endif

#include "codegen_interface.hpp"

namespace obrttg
{
class GuidanceInterface : public CodegenInterface<busGncGuidance, const ExtU_obrttg_guidance_mBox_T &>
{
public:
    GuidanceInterface();

    bool initialize() override; 
    bool step(const ExtU_obrttg_guidance_mBox_T &input) override;
    void terminate() override;

    busGncGuidance output() const;

private:
    busGncGuidance m_output;
    std::mutex m_busyMtx;
};
}
#endif
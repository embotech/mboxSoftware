/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Jun 2021
/// @brief Implementation of GuidanceInterface class derived from CodegenInterface. It provides an interface to the Guidance module.

#include "guidance_interface.hpp"

obrttg::GuidanceInterface::GuidanceInterface()
    : m_output{0}
{}

bool obrttg::GuidanceInterface::initialize()
{
    std::lock_guard<std::mutex> lk(m_busyMtx);

    obrttg_guidance_mBox_initialize();
    
    return (rtmGetErrorStatus(obrttg_guidance_mBox_M) != NULL);
}

bool obrttg::GuidanceInterface::step(const ExtU_obrttg_guidance_mBox_T &input)
{
    std::lock_guard<std::mutex> lk(m_busyMtx);

    memcpy(&obrttg_guidance_mBox_U, &input, sizeof(ExtU_obrttg_guidance_mBox_T));
    obrttg_guidance_mBox_step();
    if (rtmGetErrorStatus(obrttg_guidance_mBox_M) != NULL)
    {
        return true;
    }
    memcpy(&m_output, &(obrttg_guidance_mBox_Y.guidance_output), sizeof(busGncMvm));
    return false;
}

void obrttg::GuidanceInterface::terminate()
{
    std::lock_guard<std::mutex> lk{m_busyMtx};
    obrttg_guidance_mBox_terminate();
}

busGncGuidance obrttg::GuidanceInterface::output() const
{
    return m_output;
}
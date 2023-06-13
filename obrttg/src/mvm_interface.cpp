/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Jun 2021
/// @brief Implementation of MvmInterface class derived from CodegenInterface. It provides an interface to the MVM module.

#include <mutex>

#include "mvm_interface.hpp"

obrttg::MvmInterface::MvmInterface()
    : m_output{0}
{}

bool obrttg::MvmInterface::initialize()
{
    std::lock_guard<std::mutex> lk(m_busyMtx);

    obrttg_mvm_mBox_initialize();

    return (rtmGetErrorStatus(obrttg_mvm_mBox_M) != NULL);
}

bool obrttg::MvmInterface::step(const ExtU_obrttg_mvm_mBox_T &input)
{
    std::lock_guard<std::mutex> lk(m_busyMtx);

    memcpy(&obrttg_mvm_mBox_U, &input, sizeof(ExtU_obrttg_mvm_mBox_T));
    obrttg_mvm_mBox_step();
    if (rtmGetErrorStatus(obrttg_mvm_mBox_M) != NULL)
    {
        return true;
    }
    memcpy(&m_output, &(obrttg_mvm_mBox_Y.mvm_output), sizeof(busGncMvm));
    return false;
}

void obrttg::MvmInterface::terminate()
{
    std::lock_guard<std::mutex> lk(m_busyMtx);
    obrttg_mvm_mBox_terminate();
}

busGncMvm obrttg::MvmInterface::output() const
{
    return m_output;
}
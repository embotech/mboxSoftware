/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Jun 2021
/// @brief Implementation of NavigationInterface class derived from CodegenInterface. It provides an interface to the Navigation module.

#include "navigation_interface.hpp"

obrttg::NavigationInterface::NavigationInterface()
    : m_output{0}
{}

bool obrttg::NavigationInterface::initialize()
{
    std::lock_guard<std::mutex> lk(m_busyMtx);

    obrttg_navigation_mBox_initialize();

    return (rtmGetErrorStatus(obrttg_navigation_mBox_M) != NULL);

}

bool obrttg::NavigationInterface::step(const ExtU_obrttg_navigation_mBox_T &input)
{
    std::lock_guard<std::mutex> lk(m_busyMtx);

    memcpy(&obrttg_navigation_mBox_U, &input, sizeof(ExtU_obrttg_navigation_mBox_T));
    obrttg_navigation_mBox_step();
    if (rtmGetErrorStatus(obrttg_navigation_mBox_M) != NULL)
    {
        return true;
    }
    memcpy(&m_output, &(obrttg_navigation_mBox_Y.navigation_output), sizeof(busGncNavigation));
    return false;
}

void obrttg::NavigationInterface::terminate()
{
    std::lock_guard<std::mutex> lk(m_busyMtx);
    obrttg_navigation_mBox_terminate();
}

busGncNavigation obrttg::NavigationInterface::output() const
{
    return m_output;
}
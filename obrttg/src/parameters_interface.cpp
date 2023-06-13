/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Jun 2021
/// @brief Implementation of ParametersInterface class derived from CodegenInterface. It provides an interface to the Parameters module.

#include "parameters_interface.hpp"
#include <iostream>

obrttg::ParametersInterface::ParametersInterface()
    : m_output{0}, m_ready(false)
{}

bool obrttg::ParametersInterface::initialize()
{
    std::lock_guard<std::mutex> lk(m_busyMtx);

    // Hardcoded mission parameters file name
    std::string fname = "params.json";

    // Create parameters loader object
    obrttg::parameters::Loader loader(
        obrttg::parameters::Loader::Config(fname, MBOX_PARAMS_N_WAYPOINTS, MBOX_PARAMS_DIM_WAYPOINTS));

    // Check if the parameters file was loaded correctly    
    if (!loader.ready())
    {
        return true;
    }
    m_ready = true;
    m_output = loader.get();
    return false;
}

bool obrttg::ParametersInterface::step(void*)
{
    std::lock_guard<std::mutex> lk(m_busyMtx);
    if (m_ready)
    {
        return false;
    }
    return true;
}

void obrttg::ParametersInterface::terminate()
{
    std::lock_guard<std::mutex> lk{m_busyMtx};
}

busGncParameters obrttg::ParametersInterface::output() const
{
    return m_output;
}
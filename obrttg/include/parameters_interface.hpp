/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Jun 2021
/// @brief Declaration of ParametersInterface class derived from CodegenInterface. It provides an interface to the Parameters module.

#ifndef _MBOX_OBRTTG_INCLUDE_PARAMETERS_INTERFACE_HPP_
#define _MBOX_OBRTTG_INCLUDE_PARAMETERS_INTERFACE_HPP_

#include <mutex>
#include <string>

#include "obrttg_parameters_loader.hpp"
#include "codegen_interface.hpp"

namespace obrttg
{
class ParametersInterface : public CodegenInterface<busGncParameters, void*>
{
public:
    ParametersInterface();

    bool initialize() override; 
    bool step(void*) override;
    void terminate() override;

    busGncParameters output() const;

private:
    bool m_ready;
    busGncParameters m_output;
    std::mutex m_busyMtx;
};
} // namespace obrttg
#endif // _MBOX_OBRTTG_INCLUDE_PARAMETERS_INTERFACE_HPP_ 
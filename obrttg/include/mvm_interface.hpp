/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Jun 2021
/// @brief Declaration of MvmInterface class derived from CodegenInterface. It provides an interface to the MVM module.

#ifndef _MBOX_OBRTTG_INCLUDE_MVM_INTERFACE_HPP_
#define _MBOX_OBRTTG_INCLUDE_MVM_INTERFACE_HPP_

#include <mutex>

#ifdef __cplusplus
extern "C"
{
#endif
#include "obrttg_mvm_mBox.h"
#ifdef __cplusplus
}
#endif

#include "codegen_interface.hpp"

namespace obrttg
{
class MvmInterface : public CodegenInterface<busGncMvm, const ExtU_obrttg_mvm_mBox_T &>
{
public:
    MvmInterface();

    bool initialize(); 
    bool step(const ExtU_obrttg_mvm_mBox_T &input);
    void terminate();

    busGncMvm output() const;

private:
    busGncMvm m_output;
    std::mutex m_busyMtx;
};
}
#endif
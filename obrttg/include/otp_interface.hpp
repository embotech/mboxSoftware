/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Jun 2021
/// @brief Declaration of OtpInterface class derived from CodegenInterface. It provides an interface to the OTP module.

#ifndef _MBOX_OBRTTG_INCLUDE_OTP_INTERFACE_HPP_
#define _MBOX_OBRTTG_INCLUDE_OTP_INTERFACE_HPP_

#include <mutex>

#ifdef __cplusplus
extern "C"
{
#endif
#include "obrttg_otp_sfcn_nlp3_DTVsingle_96d7.h"
#ifdef __cplusplus
}
#endif

#include "codegen_interface.hpp"

namespace obrttg
{
class OtpInterface : public CodegenInterface<busGncOtp, const ExtU_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T &>
{
public:
    OtpInterface();

    bool initialize() override; 
    bool step(const ExtU_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T &input) override;
    void terminate() override;

    busGncOtp output() const;

private:
    busGncOtp m_output;
    std::mutex m_busyMtx;
};
}
#endif
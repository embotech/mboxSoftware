/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Jun 2021
/// @brief Implementation of OtpInterface class derived from CodegenInterface. It provides an interface to the OTP module.

#include <mutex>

#include "otp_interface.hpp"

obrttg::OtpInterface::OtpInterface()
    : m_output{0}
{}

bool obrttg::OtpInterface::initialize()
{
    std::lock_guard<std::mutex> lk(m_busyMtx);

    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_initialize();

    return (rtmGetErrorStatus(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M) != NULL);
}

bool obrttg::OtpInterface::step(const ExtU_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T &input)
{
    std::lock_guard<std::mutex> lk(m_busyMtx);

    memcpy(&obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U, &input, sizeof(ExtU_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T));
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_step();
    if (rtmGetErrorStatus(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M) != NULL)
    {
        return true;
    }
    memcpy(&m_output, &(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output), sizeof(busGncOtp));
    return false;
}

void obrttg::OtpInterface::terminate()
{
    std::lock_guard<std::mutex> lk(m_busyMtx);
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_terminate();
}

busGncOtp obrttg::OtpInterface::output() const
{
    return m_output;
}
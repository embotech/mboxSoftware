/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 *
 * obrttg_otp_sfcn_nlp3_DTVsingle_96d7_private.h
 *
 * Code generation for model "obrttg_otp_sfcn_nlp3_DTVsingle_96d7".
 *
 * Model version              : 1.571
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Mar 30 19:37:53 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_private_h_
#define RTW_HEADER_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void nlp3_DTVsingle_96d7_x0_generator_Start_wrapper(void);
  extern void nlp3_DTVsingle_96d7_x0_generator_Outputs_wrapper(const real_T
    *x_initial,
    const real_T *x_target,
    const real_T *thrust_limits,
    real_T *initial_guess);
  extern void nlp3_DTVsingle_96d7_x0_generator_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void nlp3_DTVsingle_96d7_parser_Start_wrapper(void);
  extern void nlp3_DTVsingle_96d7_parser_Outputs_wrapper(
    const real_T *x_initial,
    const real_T *x_target,
    const real_T *initial_guess,
    const real_T *thrust_limits,
    const real_T *vane_limits,
    const real_T *vel_norm_limit,
    const real_T *max_tilt_angle,
    const real_T *glideslope_angle,
    const real_T *current_thrust_cmd,
    real_T *lb01,
    real_T *lb02,
    real_T *lb03,
    real_T *lb04,
    real_T *lb05,
    real_T *lb06,
    real_T *lb07,
    real_T *lb08,
    real_T *lb09,
    real_T *lb10,
    real_T *lb11,
    real_T *lb12,
    real_T *lb13,
    real_T *lb14,
    real_T *lb15,
    real_T *lb16,
    real_T *lb17,
    real_T *lb18,
    real_T *lb19,
    real_T *lb20,
    real_T *lb21,
    real_T *lb22,
    real_T *lb23,
    real_T *lb24,
    real_T *lb25,
    real_T *lb26,
    real_T *lb27,
    real_T *lb28,
    real_T *lb29,
    real_T *lb30,
    real_T *ub01,
    real_T *ub02,
    real_T *ub03,
    real_T *ub04,
    real_T *ub05,
    real_T *ub06,
    real_T *ub07,
    real_T *ub08,
    real_T *ub09,
    real_T *ub10,
    real_T *ub11,
    real_T *ub12,
    real_T *ub13,
    real_T *ub14,
    real_T *ub15,
    real_T *ub16,
    real_T *ub17,
    real_T *ub18,
    real_T *ub19,
    real_T *ub20,
    real_T *ub21,
    real_T *ub22,
    real_T *ub23,
    real_T *ub24,
    real_T *ub25,
    real_T *ub26,
    real_T *ub27,
    real_T *ub28,
    real_T *ub29,
    real_T *ub30,
    real_T *hu02,
    real_T *hu03,
    real_T *hu04,
    real_T *hu05,
    real_T *hu06,
    real_T *hu07,
    real_T *hu08,
    real_T *hu09,
    real_T *hu10,
    real_T *hu11,
    real_T *hu12,
    real_T *hu13,
    real_T *hu14,
    real_T *hu15,
    real_T *hu16,
    real_T *hu17,
    real_T *hu18,
    real_T *hu19,
    real_T *hu20,
    real_T *hu21,
    real_T *hu22,
    real_T *hu23,
    real_T *hu24,
    real_T *hu25,
    real_T *hu26,
    real_T *hu27,
    real_T *hu28,
    real_T *hu29,
    real_T *x0,
    real_T *xinit,
    real_T *all_parameters,
    real_T *NumberIneqVec);
  extern void nlp3_DTVsingle_96d7_parser_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void nlp3_DTVsingle_96d7_Start_wrapper(void);
  extern void nlp3_DTVsingle_96d7_Outputs_wrapper(
    const real_T *lb01,
    const real_T *lb02,
    const real_T *lb03,
    const real_T *lb04,
    const real_T *lb05,
    const real_T *lb06,
    const real_T *lb07,
    const real_T *lb08,
    const real_T *lb09,
    const real_T *lb10,
    const real_T *lb11,
    const real_T *lb12,
    const real_T *lb13,
    const real_T *lb14,
    const real_T *lb15,
    const real_T *lb16,
    const real_T *lb17,
    const real_T *lb18,
    const real_T *lb19,
    const real_T *lb20,
    const real_T *lb21,
    const real_T *lb22,
    const real_T *lb23,
    const real_T *lb24,
    const real_T *lb25,
    const real_T *lb26,
    const real_T *lb27,
    const real_T *lb28,
    const real_T *lb29,
    const real_T *lb30,
    const real_T *ub01,
    const real_T *ub02,
    const real_T *ub03,
    const real_T *ub04,
    const real_T *ub05,
    const real_T *ub06,
    const real_T *ub07,
    const real_T *ub08,
    const real_T *ub09,
    const real_T *ub10,
    const real_T *ub11,
    const real_T *ub12,
    const real_T *ub13,
    const real_T *ub14,
    const real_T *ub15,
    const real_T *ub16,
    const real_T *ub17,
    const real_T *ub18,
    const real_T *ub19,
    const real_T *ub20,
    const real_T *ub21,
    const real_T *ub22,
    const real_T *ub23,
    const real_T *ub24,
    const real_T *ub25,
    const real_T *ub26,
    const real_T *ub27,
    const real_T *ub28,
    const real_T *ub29,
    const real_T *ub30,
    const real_T *hu02,
    const real_T *hu03,
    const real_T *hu04,
    const real_T *hu05,
    const real_T *hu06,
    const real_T *hu07,
    const real_T *hu08,
    const real_T *hu09,
    const real_T *hu10,
    const real_T *hu11,
    const real_T *hu12,
    const real_T *hu13,
    const real_T *hu14,
    const real_T *hu15,
    const real_T *hu16,
    const real_T *hu17,
    const real_T *hu18,
    const real_T *hu19,
    const real_T *hu20,
    const real_T *hu21,
    const real_T *hu22,
    const real_T *hu23,
    const real_T *hu24,
    const real_T *hu25,
    const real_T *hu26,
    const real_T *hu27,
    const real_T *hu28,
    const real_T *hu29,
    const real_T *x0,
    const real_T *xinit,
    const real_T *all_parameters,
    const real_T *NumberIneqVec,
    real_T *outputs,
    real_T *solver_exitflag,
    real_T *iterations,
    real_T *solve_time,
    real_T *min_fuel_formulation_flag,
    real_T *primal_obj);
  extern void nlp3_DTVsingle_96d7_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void nlp3_DTVsingle_96d7_postprocessor_Start_wrapper(void);
  extern void nlp3_DTVsingle_96d7_postprocessor_Outputs_wrapper(
    const real_T *outputs,
    real_T *trajectory);
  extern void nlp3_DTVsingle_96d7_postprocessor_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif
#endif           /* RTW_HEADER_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_private_h_ */

/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 *
 * obrttg_otp_sfcn_nlp3_DTVsingle_96d7.c
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

#include "obrttg_otp_sfcn_nlp3_DTVsingle_96d7.h"
#include "obrttg_otp_sfcn_nlp3_DTVsingle_96d7_private.h"

const busGncOtp obrttg_otp_sfcn_nlp3_DTVsingle_96d7_rtZbusGncOtp = {
  0.0,                                 /* timestamp */

  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
  ,                                    /* optimal_trajectory */
  0.0,                                 /* trajectory_id */
  0.0,                                 /* exit_flag */
  0.0,                                 /* n_iter */
  0.0,                                 /* solve_time */
  0.0,                                 /* min_fuel_formulation_flag */

  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
  ,                                    /* x_target */

  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 }
  ,                                    /* x_start */

  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 }
  ,                                    /* health_status */

  {
    0.0, 0.0, 0.0 }
  /* trajectory_params */
} ;                                    /* busGncOtp ground */

/* Block signals (default storage) */
B_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B;

/* Block states (default storage) */
DW_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T obrttg_otp_sfcn_nlp3_DTVsingle_96d7_DW;

/* External inputs (root inport signals with default storage) */
ExtU_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y;

/* Real-time model */
RT_MODEL_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T
  obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M_;
RT_MODEL_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T *const
  obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M =
  &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M_;

/* Model step function */
void obrttg_otp_sfcn_nlp3_DTVsingle_96d7_step(void)
{
  /* Outputs for Enabled SubSystem: '<Root>/triggered_otp' incorporates:
   *  EnablePort: '<S1>/recompute_flag'
   */
  /* Inport: '<Root>/mvm_output' */
  if (obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.mvm_output.recompute_flag) {
    /* SignalConversion generated from: '<S3>/nlp3_DTVsingle_96d7_parser' incorporates:
     *  Inport: '<Root>/comm_in'
     *  Product: '<S5>/Multiply'
     *  Product: '<S5>/Multiply1'
     */
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.TmpSignalConversionAtnlp3_DTVsingle_96d7_parserInport4
      [0] = obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.comm_in.engine_status[7] *
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.comm_in.engine_status[6];
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.TmpSignalConversionAtnlp3_DTVsingle_96d7_parserInport4
      [1] = obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.comm_in.engine_status[8] *
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.comm_in.engine_status[6];

    /* SignalConversion generated from: '<S3>/nlp3_DTVsingle_96d7_parser' incorporates:
     *  Inport: '<Root>/comm_in'
     *  Product: '<S5>/Multiply2'
     *  Product: '<S5>/Multiply3'
     */
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.TmpSignalConversionAtnlp3_DTVsingle_96d7_parserInport5
      [0] = obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.comm_in.engine_status[9] *
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.comm_in.engine_status[6];
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.TmpSignalConversionAtnlp3_DTVsingle_96d7_parserInport5
      [1] = obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.comm_in.engine_status[10] *
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.comm_in.engine_status[6];

    /* S-Function (nlp3_DTVsingle_96d7_x0_generator): '<S3>/nlp3_DTVsingle_96d7_x0_generator' */
    nlp3_DTVsingle_96d7_x0_generator_Outputs_wrapper
      (&obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.mvm_output.next_start[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.mvm_output.next_target[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.TmpSignalConversionAtnlp3_DTVsingle_96d7_parserInport4
       [0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_x0_generator[0]);

    /* S-Function (nlp3_DTVsingle_96d7_parser): '<S3>/nlp3_DTVsingle_96d7_parser' incorporates:
     *  Inport: '<Root>/gnc_parameters'
     */
    nlp3_DTVsingle_96d7_parser_Outputs_wrapper
      (&obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.mvm_output.next_start[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.mvm_output.next_target[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_x0_generator[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.TmpSignalConversionAtnlp3_DTVsingle_96d7_parserInport4
       [0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.TmpSignalConversionAtnlp3_DTVsingle_96d7_parserInport5
       [0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.gnc_parameters.gncParameters.maxSpeedConstraint,
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.gnc_parameters.gncParameters.tiltAngleConstraint,
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.gnc_parameters.gncParameters.glideSlopeAngleConstraint,
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.mvm_output.next_start[14],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o1[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o2[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o3[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o4[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o5[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o6[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o7[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o8[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o9[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o10[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o11[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o12[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o13[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o14[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o15[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o16[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o17[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o18[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o19[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o20[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o21[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o22[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o23[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o24[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o25[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o26[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o27[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o28[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o29[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o30[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o31[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o32[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o33[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o34[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o35[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o36[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o37[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o38[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o39[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o40[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o41[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o42[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o43[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o44[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o45[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o46[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o47[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o48[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o49[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o50[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o51[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o52[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o53[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o54[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o55[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o56[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o57[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o58[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o59[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o60[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o61[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o62[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o63[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o64[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o65[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o66[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o67[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o68[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o69[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o70[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o71[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o72[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o73[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o74[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o75[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o76[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o77[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o78[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o79[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o80[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o81[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o82[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o83[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o84[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o85[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o86[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o87[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o88[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o89[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o90[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o91[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o92[0]);

    /* S-Function (nlp3_DTVsingle_96d7_solver): '<S3>/nlp3_DTVsingle_96d7_solver' */
    nlp3_DTVsingle_96d7_Outputs_wrapper
      (&obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o1[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o2[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o3[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o4[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o5[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o6[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o7[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o8[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o9[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o10[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o11[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o12[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o13[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o14[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o15[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o16[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o17[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o18[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o19[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o20[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o21[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o22[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o23[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o24[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o25[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o26[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o27[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o28[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o29[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o30[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o31[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o32[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o33[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o34[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o35[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o36[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o37[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o38[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o39[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o40[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o41[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o42[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o43[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o44[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o45[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o46[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o47[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o48[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o49[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o50[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o51[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o52[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o53[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o54[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o55[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o56[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o57[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o58[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o59[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o60[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o61[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o62[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o63[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o64[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o65[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o66[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o67[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o68[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o69[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o70[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o71[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o72[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o73[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o74[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o75[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o76[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o77[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o78[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o79[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o80[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o81[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o82[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o83[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o84[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o85[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o86[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o87[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o88[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o89[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o90[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o91[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_parser_o92[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_solver_o1[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_solver_o2,
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_solver_o3,
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_solver_o4,
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_solver_o5,
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_solver_o6);

    /* S-Function (nlp3_DTVsingle_96d7_postprocessor): '<S3>/nlp3_DTVsingle_96d7_postprocessor' */
    nlp3_DTVsingle_96d7_postprocessor_Outputs_wrapper
      (&obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_solver_o1[0],
       &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.optimal_trajectory[0]);

    /* BusCreator: '<S2>/Bus Creator' incorporates:
     *  Constant: '<S3>/Constant3'
     *  DigitalClock: '<S2>/Digital Clock'
     *  Inport: '<Root>/comm_in'
     *  Inport: '<Root>/gnc_parameters'
     *  Memory: '<S3>/Memory'
     *  Outport: '<Root>/otp_output'
     *  SignalConversion generated from: '<S2>/Bus Creator'
     *  Sum: '<S3>/Sum'
     * */
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.timestamp =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->Timing.taskTime0;
    memcpy(&obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.optimal_trajectory
           [0], &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.optimal_trajectory[0],
           540U * sizeof(real_T));
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.trajectory_id =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_DW.Memory_PreviousInput + 1.0;
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.exit_flag =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_solver_o2;
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.n_iter =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_solver_o3;
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.solve_time =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_solver_o4;
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.min_fuel_formulation_flag =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B.nlp3_DTVsingle_96d7_solver_o5;
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.x_start[0] =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.mvm_output.next_start[13];
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.x_start[1] =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.mvm_output.next_start[14];
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.x_start[2] =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.mvm_output.next_start[15];
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.x_start[3] =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.mvm_output.next_start[16];
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.health_status[0] =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.gnc_parameters.gncParameters.maxSpeedConstraint;
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.health_status[1] =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.gnc_parameters.gncParameters.tiltAngleConstraint;
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.health_status[2] =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.gnc_parameters.gncParameters.glideSlopeAngleConstraint;
    memcpy(&obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.x_target[0],
           &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.mvm_output.next_start[0], 13U *
           sizeof(real_T));
    memcpy(&obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.x_start[4],
           &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.mvm_output.next_target[0], 13U
           * sizeof(real_T));
    memcpy(&obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.health_status[3],
           &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.comm_in.engine_status[0], 13U *
           sizeof(real_T));
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.trajectory_params[0] =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.comm_in.engine_status[13];
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.trajectory_params[1] =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.comm_in.engine_status[14];
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output.trajectory_params[2] =
      obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U.comm_in.engine_status[15];

    /* Update for Memory: '<S3>/Memory' incorporates:
     *  Constant: '<S3>/Constant3'
     *  Sum: '<S3>/Sum'
     */
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_DW.Memory_PreviousInput++;
  }

  /* End of Inport: '<Root>/mvm_output' */
  /* End of Outputs for SubSystem: '<Root>/triggered_otp' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo,
                      (&obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.04s, 0.0s] */
    if ((rtmGetTFinal(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M)!=-1) &&
        !((rtmGetTFinal(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M)-
           obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->Timing.taskTime0) >
          obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->Timing.taskTime0 * (DBL_EPSILON)))
    {
      rtmSetErrorStatus(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M,
                        "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->Timing.clockTick0)) {
    ++obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->Timing.clockTickH0;
  }

  obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->Timing.taskTime0 =
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->Timing.clockTick0 *
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->Timing.stepSize0 +
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->Timing.clockTickH0 *
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void obrttg_otp_sfcn_nlp3_DTVsingle_96d7_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M, 0,
                sizeof(RT_MODEL_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T));
  rtmSetTFinal(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M, -1);
  obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->Timing.stepSize0 = 0.04;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo,
                          (NULL));
    rtliSetLogXSignalPtrs(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo,
                          (NULL));
    rtliSetLogT(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo, "");
    rtliSetLogX(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo, "");
    rtliSetLogXFinal(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo,
      "rt_");
    rtliSetLogFormat(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo, 0);
    rtliSetLogDecimation(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo, 1);
    rtliSetLogY(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo,
                          (NULL));
    rtliSetLogYSignalPtrs(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo,
                          (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B), 0,
                sizeof(B_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T));

  /* states (dwork) */
  (void) memset((void *)&obrttg_otp_sfcn_nlp3_DTVsingle_96d7_DW, 0,
                sizeof(DW_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T));

  /* external inputs */
  (void)memset(&obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U, 0, sizeof
               (ExtU_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T));

  /* external outputs */
  obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output =
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_rtZbusGncOtp;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime
    (obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->rtwLogInfo, 0.0, rtmGetTFinal
     (obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M),
     obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M->Timing.stepSize0,
     (&rtmGetErrorStatus(obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M)));

  /* SystemInitialize for Enabled SubSystem: '<Root>/triggered_otp' */
  /* InitializeConditions for Memory: '<S3>/Memory' */
  obrttg_otp_sfcn_nlp3_DTVsingle_96d7_DW.Memory_PreviousInput = 0.0;

  /* SystemInitialize for Outport: '<Root>/otp_output' incorporates:
   *  Outport: '<S1>/otp_output'
   */
  obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y.otp_output =
    obrttg_otp_sfcn_nlp3_DTVsingle_96d7_rtZbusGncOtp;

  /* End of SystemInitialize for SubSystem: '<Root>/triggered_otp' */
}

/* Model terminate function */
void obrttg_otp_sfcn_nlp3_DTVsingle_96d7_terminate(void)
{
  /* (no terminate code required) */
}

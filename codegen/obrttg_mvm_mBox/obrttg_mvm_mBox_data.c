/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/*
 * obrttg_mvm_mBox_data.c
 *
 * Code generation for model "obrttg_mvm_mBox".
 *
 * Model version              : 1.589
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Mar 30 19:37:43 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "obrttg_mvm_mBox.h"
#include "obrttg_mvm_mBox_private.h"

/* Invariant block signals (default storage) */
const ConstB_obrttg_mvm_mBox_T obrttg_mvm_mBox_ConstB = {
  /* Start of '<S1>/mission_and_vehicle_management_mbox' */
  {
    /* Start of '<S4>/target_manager_mbox' */
    {
      /* Start of '<S44>/manage_optimal_guidance_mbox' */
      {
        { 1.0, 0.0, 0.0, 0.0 },        /* '<S59>/target_attitude' */

        { 0.0, 0.0, 0.0 },             /* '<S59>/target_rates' */
        30.0,                          /* '<S71>/Width' */
        30.0,                          /* '<S72>/Width' */
        30.0,                          /* '<S73>/Width' */
        30.0                           /* '<S81>/Width' */
      }
      /* End of '<S44>/manage_optimal_guidance_mbox' */
    }
    /* End of '<S4>/target_manager_mbox' */
  }
  /* End of '<S1>/mission_and_vehicle_management_mbox' */
};

/* Constant parameters (default storage) */
const ConstP_obrttg_mvm_mBox_T obrttg_mvm_mBox_ConstP = {
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S11>/Logic'
   *   '<S16>/Logic'
   *   '<S17>/Logic'
   *   '<S34>/Logic'
   *   '<S8>/Logic'
   *   '<S9>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 }
};

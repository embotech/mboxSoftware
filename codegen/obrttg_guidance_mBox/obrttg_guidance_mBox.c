/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/*
 * obrttg_guidance_mBox.c
 *
 * Code generation for model "obrttg_guidance_mBox".
 *
 * Model version              : 1.561
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Mar 30 19:37:28 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "obrttg_guidance_mBox.h"
#include "obrttg_guidance_mBox_private.h"

const busGncGuidance obrttg_guidance_mBox_rtZbusGncGuidance = {
  0.0,                                 /* timestamp */
  0.0,                                 /* time_to_go */

  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
  ,                                    /* state_error */

  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 }
  ,                                    /* guidance_reference */

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
  /* current_optimal_trajectory */
} ;                                    /* busGncGuidance ground */

/* Block signals (default storage) */
B_obrttg_guidance_mBox_T obrttg_guidance_mBox_B;

/* Block states (default storage) */
DW_obrttg_guidance_mBox_T obrttg_guidance_mBox_DW;

/* External inputs (root inport signals with default storage) */
ExtU_obrttg_guidance_mBox_T obrttg_guidance_mBox_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_obrttg_guidance_mBox_T obrttg_guidance_mBox_Y;

/* Real-time model */
RT_MODEL_obrttg_guidance_mBox_T obrttg_guidance_mBox_M_;
RT_MODEL_obrttg_guidance_mBox_T *const obrttg_guidance_mBox_M =
  &obrttg_guidance_mBox_M_;

/* Lookup Binary Search Utility BINARYSEARCH_real_T */
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

/* Lookup Utility LookUp_real_T_real_T */
void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const
  real_T *pUData, uint32_T iHi)
{
  uint32_T iLeft;
  uint32_T iRght;
  BINARYSEARCH_real_T( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      real_T num;
      real_T den;
      den = pUData[iRght];
      den -= pUData[iLeft];
      num = u;
      num -= pUData[iLeft];
      lambda = num / den;
    } else {
      lambda = 0.0;
    }

    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = pYData[iLeft];
      yRghtCast = pYData[iRght];
      yLeftCast += lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }
  }
}

/* Model step function */
void obrttg_guidance_mBox_step(void)
{
  /* local block i/o variables */
  real_T rtb_interp_qw;
  real_T rtb_select_time14[30];
  real_T rtb_select_Fx[30];
  real_T rtb_select_time15[30];
  real_T rtb_select_Fy[30];
  real_T rtb_select_time16[30];
  real_T rtb_select_Fz[30];
  real_T rtb_select_time13[30];
  real_T rtb_select_m[30];
  real_T rtb_select_time[30];
  real_T rtb_select_x[30];
  real_T rtb_select_time1[30];
  real_T rtb_select_y[30];
  real_T rtb_select_time2[30];
  real_T rtb_select_z[30];
  real_T rtb_select_time6[30];
  real_T rtb_select_qw[30];
  real_T rtb_select_time7[30];
  real_T rtb_select_qx[30];
  real_T rtb_select_time8[30];
  real_T rtb_select_qy[30];
  real_T rtb_select_time9[30];
  real_T rtb_select_qz[30];
  real_T rtb_select_time3[30];
  real_T rtb_select_vel_x[30];
  real_T rtb_select_time4[30];
  real_T rtb_select_vel_y[30];
  real_T rtb_select_time5[30];
  real_T rtb_select_vel_z[30];
  real_T rtb_select_time10[30];
  real_T rtb_select_wx[30];
  real_T rtb_select_time11[30];
  real_T rtb_select_wy[30];
  real_T rtb_select_time12[30];
  real_T rtb_select_wz[30];
  real_T rtb_interp_Fx;
  real_T rtb_interp_Fy;
  real_T rtb_interp_Fz;
  real_T rtb_interp_mass;
  real_T rtb_interp_pos_x;
  real_T rtb_interp_pos_y;
  real_T rtb_interp_pos_z;
  real_T rtb_interp_qx;
  real_T rtb_interp_qy;
  real_T rtb_interp_qz;
  real_T rtb_interp_vel_x;
  real_T rtb_interp_vel_y;
  real_T rtb_interp_vel_z;
  real_T rtb_interp_wx;
  real_T rtb_interp_wy;
  real_T rtb_interp_wz;
  boolean_T y[30];
  boolean_T b_y;
  int32_T i2;
  int32_T iy;
  int32_T i;
  int32_T ix;
  int32_T k;
  real_T qN;
  boolean_T rtb_push_logical_operator;
  int8_T rtPrevAction;
  real_T rtb_t_idx_0;
  real_T rtb_t_idx_1;
  real_T rtb_t_idx_2;
  real_T rtb_t_idx_3;
  boolean_T exitg1;

  /* Logic: '<S4>/push_logical_operator' incorporates:
   *  Constant: '<S15>/Constant'
   *  Inport: '<Root>/mvm_output'
   *  Inport: '<Root>/otp_output'
   *  RelationalOperator: '<S15>/Compare'
   */
  rtb_push_logical_operator =
    ((obrttg_guidance_mBox_U.mvm_output.computation_done != 0.0) &&
     (obrttg_guidance_mBox_U.otp_output.exit_flag == 1.0));

  /* MATLAB Function: '<S14>/MATLAB Function' incorporates:
   *  Inport: '<Root>/mvm_output'
   *  Inport: '<Root>/otp_output'
   *  RelationalOperator: '<S16>/FixPt Relational Operator'
   *  RelationalOperator: '<S17>/FixPt Relational Operator'
   *  UnitDelay: '<S16>/Delay Input1'
   *  UnitDelay: '<S17>/Delay Input1'
   */
  if ((int32_T)rtb_push_logical_operator > (int32_T)
      obrttg_guidance_mBox_DW.DelayInput1_DSTATE) {
    for (k = 0; k < 30; k++) {
      memcpy(&obrttg_guidance_mBox_DW.Memory_PreviousInput[k * 18 + 540],
             &obrttg_guidance_mBox_U.otp_output.optimal_trajectory[k * 18], 18U *
             sizeof(real_T));
    }
  }

  if ((int32_T)obrttg_guidance_mBox_U.mvm_output.change_trajectory > (int32_T)
      obrttg_guidance_mBox_DW.DelayInput1_DSTATE_h) {
    for (k = 0; k < 30; k++) {
      y[k] = false;
    }

    i2 = 1;
    iy = -1;
    for (i = 0; i < 30; i++) {
      ix = i2 - 1;
      i2 += 18;
      iy++;
      exitg1 = false;
      while ((!exitg1) && (ix + 1 <= i2 - 1)) {
        k = (ix / 18 * 18 + ix % 18) + 540;
        if ((obrttg_guidance_mBox_DW.Memory_PreviousInput[k] == 0.0) || rtIsNaN
            (obrttg_guidance_mBox_DW.Memory_PreviousInput[k])) {
          ix++;
        } else {
          y[iy] = true;
          exitg1 = true;
        }
      }
    }

    b_y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 30)) {
      if (!y[k]) {
        k++;
      } else {
        b_y = true;
        exitg1 = true;
      }
    }

    if (b_y) {
      for (k = 0; k < 30; k++) {
        for (i2 = 0; i2 < 18; i2++) {
          iy = 18 * k + i2;
          i = iy + 540;
          obrttg_guidance_mBox_DW.Memory_PreviousInput[iy] =
            obrttg_guidance_mBox_DW.Memory_PreviousInput[i];
          obrttg_guidance_mBox_DW.Memory_PreviousInput[i] = 0.0;
        }
      }
    }
  }

  for (k = 0; k < 30; k++) {
    memcpy(&obrttg_guidance_mBox_B.output_trajectory[k * 18],
           &obrttg_guidance_mBox_DW.Memory_PreviousInput[k * 18], 18U * sizeof
           (real_T));
  }

  /* End of MATLAB Function: '<S14>/MATLAB Function' */

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Constant: '<S3>/F_ref_inertial'
   *  Constant: '<S3>/mass_ref'
   *  Constant: '<S3>/zero_error'
   *  Inport: '<Root>/mvm_output'
   *  Inport: '<Root>/navigation_output'
   *  Inport: '<S3>/state_inertial'
   *  SignalConversion generated from: '<Root>/navigation_output'
   */
  rtPrevAction = obrttg_guidance_mBox_DW.SwitchCase_ActiveSubsystem;
  rtb_t_idx_0 = trunc(obrttg_guidance_mBox_U.mvm_output.mission_phase_id[0]);
  if (rtIsNaN(rtb_t_idx_0) || rtIsInf(rtb_t_idx_0)) {
    rtb_t_idx_0 = 0.0;
  } else {
    rtb_t_idx_0 = fmod(rtb_t_idx_0, 4.294967296E+9);
  }

  if ((rtb_t_idx_0 < 0.0 ? -(int32_T)(uint32_T)-rtb_t_idx_0 : (int32_T)(uint32_T)
       rtb_t_idx_0) == 2) {
    obrttg_guidance_mBox_DW.SwitchCase_ActiveSubsystem = 0;
  } else {
    obrttg_guidance_mBox_DW.SwitchCase_ActiveSubsystem = 1;
  }

  if ((rtPrevAction != obrttg_guidance_mBox_DW.SwitchCase_ActiveSubsystem) &&
      (rtPrevAction == 0)) {
    /* Disable for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    obrttg_guidance_mBox_DW.DiscreteTimeIntegrator_DSTATE =
      obrttg_guidance_mBox_B.DiscreteTimeIntegrator;
  }

  if (obrttg_guidance_mBox_DW.SwitchCase_ActiveSubsystem == 0) {
    if (obrttg_guidance_mBox_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/embotech guidance' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
       */
      obrttg_guidance_mBox_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
      obrttg_guidance_mBox_DW.DiscreteTimeIntegrator_PrevResetState = 2;

      /* End of InitializeConditions for SubSystem: '<S1>/embotech guidance' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/embotech guidance' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    for (k = 0; k < 30; k++) {
      /* Selector: '<S5>/select_time14' incorporates:
       *  Selector: '<S5>/select_time'
       *  Selector: '<S5>/select_time1'
       *  Selector: '<S5>/select_time10'
       *  Selector: '<S5>/select_time11'
       *  Selector: '<S5>/select_time12'
       *  Selector: '<S5>/select_time13'
       *  Selector: '<S5>/select_time15'
       *  Selector: '<S5>/select_time16'
       *  Selector: '<S5>/select_time2'
       *  Selector: '<S5>/select_time3'
       *  Selector: '<S5>/select_time4'
       *  Selector: '<S5>/select_time5'
       *  Selector: '<S5>/select_time6'
       *  Selector: '<S5>/select_time7'
       *  Selector: '<S5>/select_time8'
       *  Selector: '<S5>/select_time9'
       */
      rtb_t_idx_0 = obrttg_guidance_mBox_B.output_trajectory[18 * k];
      rtb_select_time14[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_Fx' */
      rtb_select_Fx[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 1];

      /* Selector: '<S5>/select_time15' */
      rtb_select_time15[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_Fy' */
      rtb_select_Fy[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 2];

      /* Selector: '<S5>/select_time16' */
      rtb_select_time16[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_Fz' */
      rtb_select_Fz[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 3];

      /* Selector: '<S5>/select_time13' */
      rtb_select_time13[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_m' */
      rtb_select_m[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 4];

      /* Selector: '<S5>/select_time' */
      rtb_select_time[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_x' */
      rtb_select_x[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 5];

      /* Selector: '<S5>/select_time1' */
      rtb_select_time1[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_y' */
      rtb_select_y[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 6];

      /* Selector: '<S5>/select_time2' */
      rtb_select_time2[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_z' */
      rtb_select_z[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 7];

      /* Selector: '<S5>/select_time6' */
      rtb_select_time6[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_qw' */
      rtb_select_qw[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 11];

      /* Selector: '<S5>/select_time7' */
      rtb_select_time7[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_qx' */
      rtb_select_qx[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 12];

      /* Selector: '<S5>/select_time8' */
      rtb_select_time8[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_qy' */
      rtb_select_qy[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 13];

      /* Selector: '<S5>/select_time9' */
      rtb_select_time9[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_qz' */
      rtb_select_qz[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 14];

      /* Selector: '<S5>/select_time3' */
      rtb_select_time3[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_vel_x' */
      rtb_select_vel_x[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 8];

      /* Selector: '<S5>/select_time4' */
      rtb_select_time4[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_vel_y' */
      rtb_select_vel_y[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 9];

      /* Selector: '<S5>/select_time5' */
      rtb_select_time5[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_vel_z' */
      rtb_select_vel_z[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 10];

      /* Selector: '<S5>/select_time10' */
      rtb_select_time10[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_wx' */
      rtb_select_wx[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 15];

      /* Selector: '<S5>/select_time11' */
      rtb_select_time11[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_wy' */
      rtb_select_wy[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 16];

      /* Selector: '<S5>/select_time12' */
      rtb_select_time12[k] = rtb_t_idx_0;

      /* Selector: '<S5>/select_wz' */
      rtb_select_wz[k] = obrttg_guidance_mBox_B.output_trajectory[18 * k + 17];
    }

    /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    if (obrttg_guidance_mBox_U.mvm_output.change_trajectory &&
        (obrttg_guidance_mBox_DW.DiscreteTimeIntegrator_PrevResetState <= 0)) {
      obrttg_guidance_mBox_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
    }

    obrttg_guidance_mBox_B.DiscreteTimeIntegrator =
      obrttg_guidance_mBox_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */

    /* S-Function (sfix_look1_dyn): '<S5>/interp_Fx' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_Fx'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_Fx), &rtb_select_Fx[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time14[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_Fy' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_Fy'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_Fy), &rtb_select_Fy[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time15[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_Fz' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_Fz'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_Fz), &rtb_select_Fz[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time16[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_mass' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_mass'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_mass), &rtb_select_m[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time13[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_pos_x' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_pos_x'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_pos_x), &rtb_select_x[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_pos_y' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_pos_y'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_pos_y), &rtb_select_y[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time1[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_pos_z' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_pos_z'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_pos_z), &rtb_select_z[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time2[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_qw' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_qw'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_qw), &rtb_select_qw[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time6[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_qx' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_qx'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_qx), &rtb_select_qx[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time7[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_qy' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_qy'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_qy), &rtb_select_qy[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time8[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_qz' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_qz'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_qz), &rtb_select_qz[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time9[0], 29U);

    /* MATLAB Function: '<S10>/multiply_quaternions' incorporates:
     *  Gain: '<S9>/Gain'
     *  Inport: '<Root>/navigation_output'
     *  SignalConversion generated from: '<Root>/navigation_output'
     *  SignalConversion generated from: '<S12>/ SFunction '
     */
    rtb_t_idx_0 = ((rtb_interp_qw *
                    obrttg_guidance_mBox_U.navigation_output.attitude[0] -
                    -rtb_interp_qx *
                    obrttg_guidance_mBox_U.navigation_output.attitude[1]) -
                   -rtb_interp_qy *
                   obrttg_guidance_mBox_U.navigation_output.attitude[2]) -
      -rtb_interp_qz * obrttg_guidance_mBox_U.navigation_output.attitude[3];
    rtb_t_idx_1 = ((rtb_interp_qw *
                    obrttg_guidance_mBox_U.navigation_output.attitude[1] +
                    -rtb_interp_qx *
                    obrttg_guidance_mBox_U.navigation_output.attitude[0]) -
                   -rtb_interp_qy *
                   obrttg_guidance_mBox_U.navigation_output.attitude[3]) +
      -rtb_interp_qz * obrttg_guidance_mBox_U.navigation_output.attitude[2];
    rtb_t_idx_2 = ((rtb_interp_qw *
                    obrttg_guidance_mBox_U.navigation_output.attitude[2] +
                    -rtb_interp_qx *
                    obrttg_guidance_mBox_U.navigation_output.attitude[3]) +
                   -rtb_interp_qy *
                   obrttg_guidance_mBox_U.navigation_output.attitude[0]) -
      -rtb_interp_qz * obrttg_guidance_mBox_U.navigation_output.attitude[1];
    rtb_t_idx_3 = ((rtb_interp_qw *
                    obrttg_guidance_mBox_U.navigation_output.attitude[3] -
                    -rtb_interp_qx *
                    obrttg_guidance_mBox_U.navigation_output.attitude[2]) +
                   -rtb_interp_qy *
                   obrttg_guidance_mBox_U.navigation_output.attitude[1]) +
      -rtb_interp_qz * obrttg_guidance_mBox_U.navigation_output.attitude[0];
    if (rtb_t_idx_0 < 0.0) {
      rtb_t_idx_0 = -rtb_t_idx_0;
      rtb_t_idx_1 = -rtb_t_idx_1;
      rtb_t_idx_2 = -rtb_t_idx_2;
      rtb_t_idx_3 = -rtb_t_idx_3;
    }

    /* End of MATLAB Function: '<S10>/multiply_quaternions' */

    /* MATLAB Function: '<S11>/normalize_quaternion' */
    qN = sqrt(((rtb_t_idx_0 * rtb_t_idx_0 + rtb_t_idx_1 * rtb_t_idx_1) +
               rtb_t_idx_2 * rtb_t_idx_2) + rtb_t_idx_3 * rtb_t_idx_3);

    /* Reshape: '<S8>/Reshape' incorporates:
     *  MATLAB Function: '<S11>/normalize_quaternion'
     */
    obrttg_guidance_mBox_B.state_error[6] = rtb_t_idx_0 / qN;
    obrttg_guidance_mBox_B.state_error[7] = rtb_t_idx_1 / qN;
    obrttg_guidance_mBox_B.state_error[8] = rtb_t_idx_2 / qN;
    obrttg_guidance_mBox_B.state_error[9] = rtb_t_idx_3 / qN;

    /* S-Function (sfix_look1_dyn): '<S5>/interp_vel_x' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_vel_x'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_vel_x), &rtb_select_vel_x[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time3[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_vel_y' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_vel_y'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_vel_y), &rtb_select_vel_y[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time4[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_vel_z' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_vel_z'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_vel_z), &rtb_select_vel_z[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time5[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_wx' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_wx'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_wx), &rtb_select_wx[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time10[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_wy' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_wy'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_wy), &rtb_select_wy[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time11[0], 29U);

    /* S-Function (sfix_look1_dyn): '<S5>/interp_wz' */
    /* Dynamic Look-Up Table Block: '<S5>/interp_wz'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_interp_wz), &rtb_select_wz[0],
                         obrttg_guidance_mBox_B.DiscreteTimeIntegrator,
                         &rtb_select_time12[0], 29U);

    /* SignalConversion generated from: '<S2>/guidance_reference' */
    obrttg_guidance_mBox_B.guidance_reference[0] = rtb_interp_Fx;
    obrttg_guidance_mBox_B.guidance_reference[1] = rtb_interp_Fy;
    obrttg_guidance_mBox_B.guidance_reference[2] = rtb_interp_Fz;
    obrttg_guidance_mBox_B.guidance_reference[3] = rtb_interp_mass;
    obrttg_guidance_mBox_B.guidance_reference[4] = rtb_interp_pos_x;
    obrttg_guidance_mBox_B.guidance_reference[5] = rtb_interp_pos_y;
    obrttg_guidance_mBox_B.guidance_reference[6] = rtb_interp_pos_z;
    obrttg_guidance_mBox_B.guidance_reference[7] = rtb_interp_vel_x;
    obrttg_guidance_mBox_B.guidance_reference[8] = rtb_interp_vel_y;
    obrttg_guidance_mBox_B.guidance_reference[9] = rtb_interp_vel_z;
    obrttg_guidance_mBox_B.guidance_reference[10] = rtb_interp_qw;
    obrttg_guidance_mBox_B.guidance_reference[11] = rtb_interp_qx;
    obrttg_guidance_mBox_B.guidance_reference[12] = rtb_interp_qy;
    obrttg_guidance_mBox_B.guidance_reference[13] = rtb_interp_qz;
    obrttg_guidance_mBox_B.guidance_reference[14] = rtb_interp_wx;
    obrttg_guidance_mBox_B.guidance_reference[15] = rtb_interp_wy;
    obrttg_guidance_mBox_B.guidance_reference[16] = rtb_interp_wz;

    /* Sum: '<S6>/Sum2' incorporates:
     *  Inport: '<Root>/navigation_output'
     *  SignalConversion generated from: '<Root>/navigation_output'
     */
    obrttg_guidance_mBox_B.state_error[10] =
      obrttg_guidance_mBox_U.navigation_output.rates[0] - rtb_interp_wx;
    obrttg_guidance_mBox_B.state_error[11] =
      obrttg_guidance_mBox_U.navigation_output.rates[1] - rtb_interp_wy;
    obrttg_guidance_mBox_B.state_error[12] =
      obrttg_guidance_mBox_U.navigation_output.rates[2] - rtb_interp_wz;

    /* Sum: '<S6>/Sum1' incorporates:
     *  Inport: '<Root>/navigation_output'
     *  SignalConversion generated from: '<Root>/navigation_output'
     */
    obrttg_guidance_mBox_B.state_error[3] =
      obrttg_guidance_mBox_U.navigation_output.velocity[0] - rtb_interp_vel_x;
    obrttg_guidance_mBox_B.state_error[4] =
      obrttg_guidance_mBox_U.navigation_output.velocity[1] - rtb_interp_vel_y;
    obrttg_guidance_mBox_B.state_error[5] =
      obrttg_guidance_mBox_U.navigation_output.velocity[2] - rtb_interp_vel_z;

    /* Sum: '<S6>/Sum8' incorporates:
     *  Inport: '<Root>/navigation_output'
     *  SignalConversion generated from: '<Root>/navigation_output'
     */
    obrttg_guidance_mBox_B.state_error[0] =
      obrttg_guidance_mBox_U.navigation_output.position[0] - rtb_interp_pos_x;
    obrttg_guidance_mBox_B.state_error[1] =
      obrttg_guidance_mBox_U.navigation_output.position[1] - rtb_interp_pos_y;
    obrttg_guidance_mBox_B.state_error[2] =
      obrttg_guidance_mBox_U.navigation_output.position[2] - rtb_interp_pos_z;

    /* SignalConversion generated from: '<S2>/time_to_go' incorporates:
     *  MATLAB Function: '<S5>/calculate_remaining_trajectory_time'
     */
    obrttg_guidance_mBox_B.time_to_go =
      obrttg_guidance_mBox_B.output_trajectory[522] -
      obrttg_guidance_mBox_B.DiscreteTimeIntegrator;

    /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    obrttg_guidance_mBox_DW.DiscreteTimeIntegrator_DSTATE += 0.04;
    obrttg_guidance_mBox_DW.DiscreteTimeIntegrator_PrevResetState = (int8_T)
      obrttg_guidance_mBox_U.mvm_output.change_trajectory;

    /* End of Outputs for SubSystem: '<S1>/embotech guidance' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/enabled_idle_mode' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* SignalConversion generated from: '<S3>/time_to_go' incorporates:
     *  Constant: '<S3>/time_to_go_constant'
     */
    obrttg_guidance_mBox_B.time_to_go = -1.0;
    memset(&obrttg_guidance_mBox_B.state_error[0], 0, 13U * sizeof(real_T));
    obrttg_guidance_mBox_B.guidance_reference[3] = 0.0;
    obrttg_guidance_mBox_B.guidance_reference[0] = 0.0;
    obrttg_guidance_mBox_B.guidance_reference[4] =
      obrttg_guidance_mBox_U.navigation_output.position[0];
    obrttg_guidance_mBox_B.guidance_reference[7] =
      obrttg_guidance_mBox_U.navigation_output.velocity[0];
    obrttg_guidance_mBox_B.guidance_reference[1] = 0.0;
    obrttg_guidance_mBox_B.guidance_reference[5] =
      obrttg_guidance_mBox_U.navigation_output.position[1];
    obrttg_guidance_mBox_B.guidance_reference[8] =
      obrttg_guidance_mBox_U.navigation_output.velocity[1];
    obrttg_guidance_mBox_B.guidance_reference[2] = 0.0;
    obrttg_guidance_mBox_B.guidance_reference[6] =
      obrttg_guidance_mBox_U.navigation_output.position[2];
    obrttg_guidance_mBox_B.guidance_reference[9] =
      obrttg_guidance_mBox_U.navigation_output.velocity[2];
    obrttg_guidance_mBox_B.guidance_reference[10] =
      obrttg_guidance_mBox_U.navigation_output.attitude[0];
    obrttg_guidance_mBox_B.guidance_reference[11] =
      obrttg_guidance_mBox_U.navigation_output.attitude[1];
    obrttg_guidance_mBox_B.guidance_reference[12] =
      obrttg_guidance_mBox_U.navigation_output.attitude[2];
    obrttg_guidance_mBox_B.guidance_reference[13] =
      obrttg_guidance_mBox_U.navigation_output.attitude[3];
    obrttg_guidance_mBox_B.guidance_reference[14] =
      obrttg_guidance_mBox_U.navigation_output.rates[0];
    obrttg_guidance_mBox_B.guidance_reference[15] =
      obrttg_guidance_mBox_U.navigation_output.rates[1];
    obrttg_guidance_mBox_B.guidance_reference[16] =
      obrttg_guidance_mBox_U.navigation_output.rates[2];

    /* End of Outputs for SubSystem: '<S1>/enabled_idle_mode' */
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* BusCreator: '<Root>/Bus Creator4' incorporates:
   *  Inport: '<Root>/comm_in'
   *  Outport: '<Root>/guidance_output'
   */
  obrttg_guidance_mBox_Y.guidance_output.timestamp =
    obrttg_guidance_mBox_U.comm_in.timestamp;
  obrttg_guidance_mBox_Y.guidance_output.time_to_go =
    obrttg_guidance_mBox_B.time_to_go;
  memcpy(&obrttg_guidance_mBox_Y.guidance_output.state_error[0],
         &obrttg_guidance_mBox_B.state_error[0], 13U * sizeof(real_T));
  memcpy(&obrttg_guidance_mBox_Y.guidance_output.guidance_reference[0],
         &obrttg_guidance_mBox_B.guidance_reference[0], 17U * sizeof(real_T));
  memcpy(&obrttg_guidance_mBox_Y.guidance_output.current_optimal_trajectory[0],
         &obrttg_guidance_mBox_B.output_trajectory[0], 540U * sizeof(real_T));

  /* Update for UnitDelay: '<S17>/Delay Input1' */
  obrttg_guidance_mBox_DW.DelayInput1_DSTATE = rtb_push_logical_operator;

  /* Update for UnitDelay: '<S16>/Delay Input1' incorporates:
   *  Inport: '<Root>/mvm_output'
   */
  obrttg_guidance_mBox_DW.DelayInput1_DSTATE_h =
    obrttg_guidance_mBox_U.mvm_output.change_trajectory;

  /* Matfile logging */
  rt_UpdateTXYLogVars(obrttg_guidance_mBox_M->rtwLogInfo,
                      (&obrttg_guidance_mBox_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.04s, 0.0s] */
    if ((rtmGetTFinal(obrttg_guidance_mBox_M)!=-1) &&
        !((rtmGetTFinal(obrttg_guidance_mBox_M)-
           obrttg_guidance_mBox_M->Timing.taskTime0) >
          obrttg_guidance_mBox_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(obrttg_guidance_mBox_M, "Simulation finished");
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
  if (!(++obrttg_guidance_mBox_M->Timing.clockTick0)) {
    ++obrttg_guidance_mBox_M->Timing.clockTickH0;
  }

  obrttg_guidance_mBox_M->Timing.taskTime0 =
    obrttg_guidance_mBox_M->Timing.clockTick0 *
    obrttg_guidance_mBox_M->Timing.stepSize0 +
    obrttg_guidance_mBox_M->Timing.clockTickH0 *
    obrttg_guidance_mBox_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void obrttg_guidance_mBox_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)obrttg_guidance_mBox_M, 0,
                sizeof(RT_MODEL_obrttg_guidance_mBox_T));
  rtmSetTFinal(obrttg_guidance_mBox_M, -1);
  obrttg_guidance_mBox_M->Timing.stepSize0 = 0.04;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    obrttg_guidance_mBox_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(obrttg_guidance_mBox_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(obrttg_guidance_mBox_M->rtwLogInfo, (NULL));
    rtliSetLogT(obrttg_guidance_mBox_M->rtwLogInfo, "");
    rtliSetLogX(obrttg_guidance_mBox_M->rtwLogInfo, "");
    rtliSetLogXFinal(obrttg_guidance_mBox_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(obrttg_guidance_mBox_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(obrttg_guidance_mBox_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(obrttg_guidance_mBox_M->rtwLogInfo, 0);
    rtliSetLogDecimation(obrttg_guidance_mBox_M->rtwLogInfo, 1);
    rtliSetLogY(obrttg_guidance_mBox_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(obrttg_guidance_mBox_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(obrttg_guidance_mBox_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &obrttg_guidance_mBox_B), 0,
                sizeof(B_obrttg_guidance_mBox_T));

  /* states (dwork) */
  (void) memset((void *)&obrttg_guidance_mBox_DW, 0,
                sizeof(DW_obrttg_guidance_mBox_T));

  /* external inputs */
  (void)memset(&obrttg_guidance_mBox_U, 0, sizeof(ExtU_obrttg_guidance_mBox_T));

  /* external outputs */
  obrttg_guidance_mBox_Y.guidance_output =
    obrttg_guidance_mBox_rtZbusGncGuidance;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(obrttg_guidance_mBox_M->rtwLogInfo, 0.0,
    rtmGetTFinal(obrttg_guidance_mBox_M),
    obrttg_guidance_mBox_M->Timing.stepSize0, (&rtmGetErrorStatus
    (obrttg_guidance_mBox_M)));

  /* Start for SwitchCase: '<S1>/Switch Case' */
  obrttg_guidance_mBox_DW.SwitchCase_ActiveSubsystem = -1;

  /* InitializeConditions for Memory: '<S14>/Memory' */
  memset(&obrttg_guidance_mBox_DW.Memory_PreviousInput[0], 0, 1080U * sizeof
         (real_T));

  /* InitializeConditions for UnitDelay: '<S17>/Delay Input1' */
  obrttg_guidance_mBox_DW.DelayInput1_DSTATE = false;

  /* InitializeConditions for UnitDelay: '<S16>/Delay Input1' */
  obrttg_guidance_mBox_DW.DelayInput1_DSTATE_h = false;

  /* SystemInitialize for IfAction SubSystem: '<S1>/embotech guidance' */
  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  obrttg_guidance_mBox_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  obrttg_guidance_mBox_DW.DiscreteTimeIntegrator_PrevResetState = 2;

  /* End of SystemInitialize for SubSystem: '<S1>/embotech guidance' */

  /* SystemInitialize for Merge generated from: '<S1>/Merge' */
  obrttg_guidance_mBox_B.time_to_go = 0.0;

  /* SystemInitialize for Merge generated from: '<S1>/Merge' */
  memset(&obrttg_guidance_mBox_B.state_error[0], 0, 13U * sizeof(real_T));

  /* SystemInitialize for Merge generated from: '<S1>/Merge' */
  memset(&obrttg_guidance_mBox_B.guidance_reference[0], 0, 17U * sizeof(real_T));
}

/* Model terminate function */
void obrttg_guidance_mBox_terminate(void)
{
  /* (no terminate code required) */
}

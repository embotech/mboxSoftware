/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/*
 * obrttg_mvm_mBox.c
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

const busGncMvm obrttg_mvm_mBox_rtZbusGncMvm = {
  0.0,                                 /* timestamp */
  0.0,                                 /* computation_done */
  false,                               /* recompute_flag */

  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
  ,                                    /* next_target */

  {
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 }
  ,                                    /* next_start */

  {
    0.0, 0.0 }
  ,                                    /* mission_phase_id */
  false,                               /* change_trajectory */

  {
    0.0, 0.0, 0.0 }
  ,                                    /* mvm_flags */
  false                                /* retargetOk */
} ;                                    /* busGncMvm ground */

/* Block signals (default storage) */
B_obrttg_mvm_mBox_T obrttg_mvm_mBox_B;

/* Block states (default storage) */
DW_obrttg_mvm_mBox_T obrttg_mvm_mBox_DW;

/* External inputs (root inport signals with default storage) */
ExtU_obrttg_mvm_mBox_T obrttg_mvm_mBox_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_obrttg_mvm_mBox_T obrttg_mvm_mBox_Y;

/* Real-time model */
RT_MODEL_obrttg_mvm_mBox_T obrttg_mvm_mBox_M_;
RT_MODEL_obrttg_mvm_mBox_T *const obrttg_mvm_mBox_M = &obrttg_mvm_mBox_M_;

/* Forward declaration for local functions */
static int32_T obrttg_mvm_mBox_bsearch(const real_T x[30], real_T xi);
static void obrttg_mvm_mBox_getStatePrediction(const real_T referenceTrajectory
  [540], real_T predictionTime, real_T statePrediction[17]);

/* System initialize for atomic system: '<S2>/check_computation_completion_svf' */
void obrttg_mvm_mBox_check_computation_completion_svf_Init
  (DW_check_computation_completion_svf_obrttg_mvm_mBox_T *localDW)
{
  /* InitializeConditions for Memory: '<S8>/Memory' */
  localDW->Memory_PreviousInput = true;

  /* InitializeConditions for Delay: '<S6>/Delay' */
  localDW->Delay_DSTATE = 0.0;

  /* InitializeConditions for Memory: '<S9>/Memory' */
  localDW->Memory_PreviousInput_f = false;
}

/* Output and update for atomic system: '<S2>/check_computation_completion_svf' */
void obrttg_mvm_mBox_check_computation_completion_svf(boolean_T
  rtu_recompute_flag, real_T rtu_trajectory_id,
  B_check_computation_completion_svf_obrttg_mvm_mBox_T *localB,
  DW_check_computation_completion_svf_obrttg_mvm_mBox_T *localDW)
{
  int32_T rowIdx;
  int32_T rowIdx_0;

  /* CombinatorialLogic: '<S8>/Logic' incorporates:
   *  Memory: '<S8>/Memory'
   */
  rowIdx = (int32_T)(((uint32_T)rtu_recompute_flag << 1) +
                     localDW->Memory_PreviousInput);

  /* CombinatorialLogic: '<S9>/Logic' incorporates:
   *  Delay: '<S6>/Delay'
   *  Memory: '<S9>/Memory'
   *  RelationalOperator: '<S6>/Equal'
   */
  rowIdx_0 = (int32_T)(((((uint32_T)(rtu_trajectory_id != localDW->Delay_DSTATE)
    << 1) + rtu_recompute_flag) << 1) + localDW->Memory_PreviousInput_f);

  /* Sum: '<S7>/Sum' incorporates:
   *  CombinatorialLogic: '<S8>/Logic'
   *  CombinatorialLogic: '<S9>/Logic'
   */
  localB->computation_done = (real_T)obrttg_mvm_mBox_ConstP.pooled9[(uint32_T)
    rowIdx_0] - (real_T)obrttg_mvm_mBox_ConstP.pooled9[(uint32_T)rowIdx];

  /* Update for Memory: '<S8>/Memory' incorporates:
   *  CombinatorialLogic: '<S8>/Logic'
   */
  localDW->Memory_PreviousInput = obrttg_mvm_mBox_ConstP.pooled9[(uint32_T)
    rowIdx];

  /* Update for Delay: '<S6>/Delay' */
  localDW->Delay_DSTATE = rtu_trajectory_id;

  /* Update for Memory: '<S9>/Memory' incorporates:
   *  CombinatorialLogic: '<S9>/Logic'
   */
  localDW->Memory_PreviousInput_f = obrttg_mvm_mBox_ConstP.pooled9[(uint32_T)
    rowIdx_0];
}

/* Output and update for atomic system: '<S45>/manage_startup_mbox' */
void obrttg_mvm_mBox_manage_startup_mbox(const real_T rtu_vehicle_state[14],
  real_T rtu_computation_done, real_T rtu_solver_exit_flag, const real_T
  rtu_target_list[18], const real_T rtu_takeoff_target_position[3], const real_T
  rtu_takeoff_velocity[3], B_manage_startup_mbox_obrttg_mvm_mBox_T *localB)
{
  int32_T i;
  real_T nextStart_tmp;

  /* MATLAB Function: '<S89>/manage_startup' */
  localB->recomputeFlag = 0.0;
  localB->switchTrajectory = 0.0;
  localB->nextStart[0] = rtu_vehicle_state[0] - 0.73;
  localB->nextStart[1] = rtu_takeoff_target_position[0];
  localB->nextStart[4] = rtu_takeoff_velocity[0];
  localB->nextStart[2] = rtu_takeoff_target_position[1];
  localB->nextStart[5] = rtu_takeoff_velocity[1];
  localB->nextStart[3] = rtu_takeoff_target_position[2];
  localB->nextStart[6] = rtu_takeoff_velocity[2];
  localB->nextStart[7] = 1.0;
  localB->nextStart[8] = 0.0;
  localB->nextStart[9] = 0.0;
  localB->nextStart[10] = 0.0;
  localB->nextStart[11] = 0.0;
  localB->nextStart[14] = -rtu_vehicle_state[0] * -9.80665;
  localB->nextStart[12] = 0.0;
  nextStart_tmp = -rtu_vehicle_state[0] * 0.0;
  localB->nextStart[15] = nextStart_tmp;
  localB->nextStart[13] = 0.0;
  localB->nextStart[16] = nextStart_tmp;
  localB->nextTarget[6] = 1.0;
  for (i = 0; i < 6; i++) {
    localB->nextTarget[i] = rtu_target_list[i];
    localB->nextTarget[i + 7] = 0.0;
  }

  if (rtu_computation_done == -1.0) {
    localB->recomputeFlag = 1.0;
  } else {
    if (rtu_computation_done == 1.0) {
      if (rtu_solver_exit_flag != 1.0) {
        localB->recomputeFlag = 1.0;
      } else {
        localB->switchTrajectory = 1.0;
      }
    }
  }

  /* End of MATLAB Function: '<S89>/manage_startup' */
}

/* Function for MATLAB Function: '<S54>/get_next_start' */
static int32_T obrttg_mvm_mBox_bsearch(const real_T x[30], real_T xi)
{
  int32_T n;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  n = 1;
  low_ip1 = 2;
  high_i = 30;
  while (high_i > low_ip1) {
    mid_i = (n + high_i) >> 1;
    if (xi >= x[mid_i - 1]) {
      n = mid_i;
      low_ip1 = mid_i + 1;
    } else {
      high_i = mid_i;
    }
  }

  return n;
}

/* Function for MATLAB Function: '<S54>/get_next_start' */
static void obrttg_mvm_mBox_getStatePrediction(const real_T referenceTrajectory
  [540], real_T predictionTime, real_T statePrediction[17])
{
  real_T b_statePrediction[17];
  real_T varargin_2[510];
  real_T x[30];
  real_T xtmp;
  int32_T offset;
  int32_T b_k;
  int32_T n;
  real_T b_y1;
  int32_T tmp_tmp;
  int32_T varargin_2_tmp;
  static const int8_T b[7] = { 1, 0, 0, 0, 0, 0, 0 };

  int32_T exitg1;
  for (n = 0; n < 17; n++) {
    for (offset = 0; offset < 30; offset++) {
      varargin_2[offset + 30 * n] = referenceTrajectory[(18 * offset + n) + 1];
    }
  }

  for (n = 0; n < 30; n++) {
    x[n] = referenceTrajectory[18 * n];
  }

  for (n = 0; n < 17; n++) {
    b_statePrediction[n] = (rtNaN);
  }

  n = 0;
  do {
    exitg1 = 0;
    if (n < 30) {
      if (rtIsNaN(referenceTrajectory[18 * n])) {
        exitg1 = 1;
      } else {
        n++;
      }
    } else {
      if (referenceTrajectory[18] < referenceTrajectory[0]) {
        for (n = 0; n < 15; n++) {
          xtmp = x[n];
          x[n] = x[29 - n];
          x[29 - n] = xtmp;
        }

        for (n = 0; n < 17; n++) {
          offset = n * 30;
          for (b_k = 0; b_k < 15; b_k++) {
            tmp_tmp = offset + b_k;
            xtmp = varargin_2[tmp_tmp];
            varargin_2_tmp = (offset - b_k) + 29;
            varargin_2[tmp_tmp] = varargin_2[varargin_2_tmp];
            varargin_2[varargin_2_tmp] = xtmp;
          }
        }
      }

      if (rtIsNaN(predictionTime)) {
        for (n = 0; n < 17; n++) {
          b_statePrediction[n] = (rtNaN);
        }
      } else {
        if ((!(predictionTime > x[29])) && (!(predictionTime < x[0]))) {
          n = obrttg_mvm_mBox_bsearch(x, predictionTime);
          xtmp = x[n - 1];
          xtmp = (predictionTime - xtmp) / (x[n] - xtmp);
          if (xtmp == 0.0) {
            for (offset = 0; offset < 17; offset++) {
              b_statePrediction[offset] = varargin_2[(offset * 30 + n) - 1];
            }
          } else if (xtmp == 1.0) {
            for (offset = 0; offset < 17; offset++) {
              b_statePrediction[offset] = varargin_2[offset * 30 + n];
            }
          } else {
            for (offset = 0; offset < 17; offset++) {
              b_k = offset * 30 + n;
              b_y1 = varargin_2[b_k - 1];
              if (b_y1 == varargin_2[b_k]) {
                b_statePrediction[offset] = b_y1;
              } else {
                b_statePrediction[offset] = (1.0 - xtmp) * b_y1 + xtmp *
                  varargin_2[b_k];
              }
            }
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  for (n = 0; n < 7; n++) {
    statePrediction[n] = b_statePrediction[n + 3];
    statePrediction[n + 7] = b[n];
  }

  statePrediction[14] = b_statePrediction[0];
  statePrediction[15] = b_statePrediction[1];
  statePrediction[16] = b_statePrediction[2];
}

/* Output and update for atomic system: '<S49>/get_next_start' */
void obrttg_mvm_mBox_get_next_start(const real_T rtu_trajectory[540], const
  real_T rtu_vehicle_state[14], real_T rtu_n_attempts, real_T rtu_propagate_flag,
  real_T rtu_request_id, real_T rtu_time_to_go, real_T rtu_prediction_time,
  B_get_next_start_obrttg_mvm_mBox_T *localB)
{
  real_T predictionAbsoluteTime;
  real_T propagatedState[17];
  boolean_T timeWithinRange;
  real_T vehicleState[17];
  real_T varargin_2[90];
  real_T y;
  real_T x[30];
  real_T xtmp;
  int32_T offset;
  int32_T c_k;
  real_T t;
  int32_T n;
  real_T b_y1;
  real_T y2;
  real_T Vq_idx_0;
  real_T Vq_idx_1;
  int32_T tmp_tmp;
  int32_T varargin_2_tmp;
  int32_T exitg1;

  /* MATLAB Function: '<S54>/get_next_start' */
  predictionAbsoluteTime = rtu_trajectory[522] - rtu_time_to_go;
  if (predictionAbsoluteTime <= rtu_trajectory[522]) {
    for (n = 0; n < 3; n++) {
      for (c_k = 0; c_k < 30; c_k++) {
        varargin_2[c_k + 30 * n] = rtu_trajectory[(18 * c_k + n) + 1];
      }
    }

    for (n = 0; n < 30; n++) {
      x[n] = rtu_trajectory[18 * n];
    }

    Vq_idx_0 = (rtNaN);
    Vq_idx_1 = (rtNaN);
    b_y1 = (rtNaN);
    n = 0;
    do {
      exitg1 = 0;
      if (n < 30) {
        if (rtIsNaN(rtu_trajectory[18 * n])) {
          exitg1 = 1;
        } else {
          n++;
        }
      } else {
        if (rtu_trajectory[18] < rtu_trajectory[0]) {
          for (n = 0; n < 15; n++) {
            xtmp = x[n];
            x[n] = x[29 - n];
            x[29 - n] = xtmp;
          }

          for (n = 0; n < 3; n++) {
            offset = n * 30;
            for (c_k = 0; c_k < 15; c_k++) {
              tmp_tmp = offset + c_k;
              xtmp = varargin_2[tmp_tmp];
              varargin_2_tmp = (offset - c_k) + 29;
              varargin_2[tmp_tmp] = varargin_2[varargin_2_tmp];
              varargin_2[varargin_2_tmp] = xtmp;
            }
          }
        }

        if ((!(predictionAbsoluteTime > x[29])) && (!(predictionAbsoluteTime <
              x[0]))) {
          n = obrttg_mvm_mBox_bsearch(x, predictionAbsoluteTime);
          Vq_idx_0 = x[n - 1];
          xtmp = (predictionAbsoluteTime - Vq_idx_0) / (x[n] - Vq_idx_0);
          if (xtmp == 0.0) {
            Vq_idx_0 = varargin_2[n - 1];
            Vq_idx_1 = varargin_2[n + 29];
            b_y1 = varargin_2[n + 59];
          } else if (xtmp == 1.0) {
            Vq_idx_0 = varargin_2[n];
            Vq_idx_1 = varargin_2[n + 30];
            b_y1 = varargin_2[n + 60];
          } else {
            b_y1 = varargin_2[n - 1];
            if (b_y1 == varargin_2[n]) {
              Vq_idx_0 = b_y1;
            } else {
              Vq_idx_0 = (1.0 - xtmp) * b_y1 + xtmp * varargin_2[n];
            }

            b_y1 = varargin_2[n + 29];
            y2 = varargin_2[n + 30];
            if (b_y1 == y2) {
              Vq_idx_1 = b_y1;
            } else {
              Vq_idx_1 = (1.0 - xtmp) * b_y1 + xtmp * y2;
            }

            b_y1 = varargin_2[n + 59];
            y2 = varargin_2[n + 60];
            if (!(b_y1 == y2)) {
              b_y1 = (1.0 - xtmp) * b_y1 + xtmp * y2;
            }
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    Vq_idx_0 = rtu_trajectory[523];
    Vq_idx_1 = rtu_trajectory[524];
    b_y1 = rtu_trajectory[525];
  }

  memcpy(&vehicleState[0], &rtu_vehicle_state[0], 14U * sizeof(real_T));
  vehicleState[14] = Vq_idx_0;
  vehicleState[15] = Vq_idx_1;
  vehicleState[16] = b_y1;
  predictionAbsoluteTime += rtu_prediction_time;
  if ((predictionAbsoluteTime >= 0.0) && (predictionAbsoluteTime <=
       rtu_trajectory[522])) {
    timeWithinRange = true;
  } else {
    timeWithinRange = false;
  }

  memcpy(&propagatedState[0], &vehicleState[0], 17U * sizeof(real_T));
  xtmp = 3.3121686421112381E-170;
  y2 = fabs(Vq_idx_0);
  if (y2 > 3.3121686421112381E-170) {
    y = 1.0;
    xtmp = y2;
  } else {
    t = y2 / 3.3121686421112381E-170;
    y = t * t;
  }

  y2 = fabs(Vq_idx_1);
  if (y2 > xtmp) {
    t = xtmp / y2;
    y = y * t * t + 1.0;
    xtmp = y2;
  } else {
    t = y2 / xtmp;
    y += t * t;
  }

  y2 = fabs(b_y1);
  if (y2 > xtmp) {
    t = xtmp / y2;
    y = y * t * t + 1.0;
    xtmp = y2;
  } else {
    t = y2 / xtmp;
    y += t * t;
  }

  y = xtmp * sqrt(y);
  propagatedState[0] = vehicleState[0] - y * 3.4166666666666666E-5 *
    rtu_prediction_time;
  xtmp = (vehicleState[0] + propagatedState[0]) / 2.0;
  propagatedState[4] = (Vq_idx_0 / xtmp + -9.80665) * rtu_prediction_time +
    vehicleState[4];
  propagatedState[1] = (vehicleState[4] + propagatedState[4]) / 2.0 *
    rtu_prediction_time + vehicleState[1];
  propagatedState[5] = Vq_idx_1 / xtmp * rtu_prediction_time + vehicleState[5];
  propagatedState[2] = (vehicleState[5] + propagatedState[5]) / 2.0 *
    rtu_prediction_time + vehicleState[2];
  propagatedState[6] = b_y1 / xtmp * rtu_prediction_time + vehicleState[6];
  propagatedState[3] = (vehicleState[6] + propagatedState[6]) / 2.0 *
    rtu_prediction_time + vehicleState[3];
  if (timeWithinRange) {
    obrttg_mvm_mBox_getStatePrediction(rtu_trajectory, predictionAbsoluteTime,
      vehicleState);
  } else {
    obrttg_mvm_mBox_getStatePrediction(rtu_trajectory, rtu_trajectory[522],
      vehicleState);
    propagatedState[4] = vehicleState[4];
    propagatedState[5] = vehicleState[5];
    propagatedState[6] = vehicleState[6];
  }

  if (!(rtu_propagate_flag != 0.0)) {
    memcpy(&propagatedState[0], &vehicleState[0], 17U * sizeof(real_T));
  }

  for (n = 0; n < 17; n++) {
    localB->nextStart[n] = (4.0 * propagatedState[n] + vehicleState[n]) / 5.0;
    if (rtu_request_id == 4.0) {
      localB->nextStart[n] = (3.0 * propagatedState[n] + vehicleState[n]) / 4.0;
    }
  }

  if (rtu_request_id == 6.0) {
    Vq_idx_0 = (rtu_n_attempts - 1.0) * 0.01;
    localB->nextStart[1] += Vq_idx_0;
    localB->nextStart[2] += Vq_idx_0;
    localB->nextStart[3] += Vq_idx_0;
    if (localB->nextStart[4] < 0.0) {
      Vq_idx_0 = -1.0;
    } else if (localB->nextStart[4] > 0.0) {
      Vq_idx_0 = 1.0;
    } else if (localB->nextStart[4] == 0.0) {
      Vq_idx_0 = 0.0;
    } else {
      Vq_idx_0 = (rtNaN);
    }

    localB->nextStart[4] -= Vq_idx_0 * 0.1 * (rtu_n_attempts - 1.0);
    if (localB->nextStart[5] < 0.0) {
      Vq_idx_0 = -1.0;
    } else if (localB->nextStart[5] > 0.0) {
      Vq_idx_0 = 1.0;
    } else if (localB->nextStart[5] == 0.0) {
      Vq_idx_0 = 0.0;
    } else {
      Vq_idx_0 = (rtNaN);
    }

    localB->nextStart[5] -= Vq_idx_0 * 0.1 * (rtu_n_attempts - 1.0);
    if (localB->nextStart[6] < 0.0) {
      Vq_idx_0 = -1.0;
    } else if (localB->nextStart[6] > 0.0) {
      Vq_idx_0 = 1.0;
    } else if (localB->nextStart[6] == 0.0) {
      Vq_idx_0 = 0.0;
    } else {
      Vq_idx_0 = (rtNaN);
    }

    localB->nextStart[6] -= Vq_idx_0 * 0.1 * (rtu_n_attempts - 1.0);
  }

  /* End of MATLAB Function: '<S54>/get_next_start' */
}

/* Output and update for atomic system: '<S49>/get_prediction_time' */
void obrttg_mvm_mBox_get_prediction_time(real_T rtu_time_to_go, real_T
  rtu_request_id, B_get_prediction_time_obrttg_mvm_mBox_T *localB)
{
  real_T rtu_time_to_go_0[6];

  /* SignalConversion generated from: '<S55>/sel_prediction_time' incorporates:
   *  Constant: '<S55>/max_computation_time'
   *  Constant: '<S55>/max_computation_time1'
   *  Constant: '<S55>/max_computation_time2'
   *  Constant: '<S55>/max_computation_time3'
   *  Constant: '<S55>/max_computation_time4'
   */
  rtu_time_to_go_0[0] = rtu_time_to_go;
  rtu_time_to_go_0[1] = 0.2;
  rtu_time_to_go_0[2] = 0.2;
  rtu_time_to_go_0[3] = 0.2;
  rtu_time_to_go_0[4] = 0.2;
  rtu_time_to_go_0[5] = 0.2;

  /* Selector: '<S55>/sel_prediction_time' */
  localB->sel_prediction_time = rtu_time_to_go_0[(int32_T)rtu_request_id - 1];
}

/* Output and update for atomic system: '<S49>/get_propagate_flag' */
void obrttg_mvm_mBox_get_propagate_flag(B_get_propagate_flag_obrttg_mvm_mBox_T
  *localB)
{
  /* Selector: '<S56>/Selector' */
  localB->Selector = 1.0;
}

/* System initialize for atomic system: '<S50>/get_next_target_idx' */
void obrttg_mvm_mBox_get_next_target_idx_Init
  (DW_get_next_target_idx_obrttg_mvm_mBox_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S60>/Delay Input1' */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S61>/Delay Input1' */
  localDW->DelayInput1_DSTATE_n = 0.0;
}

/* System reset for atomic system: '<S50>/get_next_target_idx' */
void obrttg_mvm_mBox_get_next_target_idx_Reset
  (DW_get_next_target_idx_obrttg_mvm_mBox_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S60>/Delay Input1' */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S61>/Delay Input1' */
  localDW->DelayInput1_DSTATE_n = 0.0;
}

/* Output and update for atomic system: '<S50>/get_next_target_idx' */
void obrttg_mvm_mBox_get_next_target_idx(real_T rtu_nominal_request, real_T
  rtu_retarget_request, real_T rtu_current_target_idx,
  B_get_next_target_idx_obrttg_mvm_mBox_T *localB,
  DW_get_next_target_idx_obrttg_mvm_mBox_T *localDW)
{
  /* Sum: '<S58>/Sum1' incorporates:
   *  RelationalOperator: '<S60>/FixPt Relational Operator'
   *  RelationalOperator: '<S61>/FixPt Relational Operator'
   *  UnitDelay: '<S60>/Delay Input1'
   *  UnitDelay: '<S61>/Delay Input1'
   */
  localB->nextTargetIdx = (real_T)((rtu_nominal_request >
    localDW->DelayInput1_DSTATE) + (rtu_retarget_request >
    localDW->DelayInput1_DSTATE_n)) + rtu_current_target_idx;

  /* Update for UnitDelay: '<S60>/Delay Input1' */
  localDW->DelayInput1_DSTATE = rtu_nominal_request;

  /* Update for UnitDelay: '<S61>/Delay Input1' */
  localDW->DelayInput1_DSTATE_n = rtu_retarget_request;
}

/* Output and update for atomic system: '<S51>/manage_computations' */
void obrttg_mvm_mBox_manage_computations(const real_T rtu_request_flags[5],
  real_T rtu_computation_done, real_T rtu_solver_exitflag, real_T
  rtu_n_attempts_in, B_manage_computations_obrttg_mvm_mBox_T *localB)
{
  int32_T requestID;
  int8_T activeRequests_data[5];
  int8_T ii_data[5];
  boolean_T x_data[5];
  int32_T idx;
  int32_T b_ii;
  int32_T b_idx;
  int32_T c_ii;
  boolean_T exitg1;

  /* MATLAB Function: '<S63>/manage_computations' */
  requestID = 0;
  localB->nAttemptsOut = rtu_n_attempts_in;
  if (rtu_computation_done == 1.0) {
    if ((rtu_n_attempts_in > 0.0) && (rtu_solver_exitflag != 1.0)) {
      if (rtu_n_attempts_in < 3.0) {
        requestID = 6;
      }

      localB->nAttemptsOut = rtu_n_attempts_in + 1.0;
    }

    idx = 0;
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii < 5)) {
      if (rtu_request_flags[b_ii] != 0.0) {
        idx++;
        ii_data[idx - 1] = (int8_T)(b_ii + 1);
        if (idx >= 5) {
          exitg1 = true;
        } else {
          b_ii++;
        }
      } else {
        b_ii++;
      }
    }

    if (1 > idx) {
      idx = 0;
    }

    b_ii = idx;
    for (b_idx = 0; b_idx < idx; b_idx++) {
      activeRequests_data[b_idx] = ii_data[b_idx];
      x_data[b_idx] = ((ii_data[b_idx] == 1) || (ii_data[b_idx] == 2) ||
                       (ii_data[b_idx] == 5));
    }

    b_idx = 0;
    c_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (c_ii <= idx - 1)) {
      if (x_data[c_ii]) {
        b_idx++;
        ii_data[b_idx - 1] = (int8_T)(c_ii + 1);
        if (b_idx >= idx) {
          exitg1 = true;
        } else {
          c_ii++;
        }
      } else {
        c_ii++;
      }
    }

    if (idx == 1) {
      if (b_idx == 0) {
        idx = 0;
      }
    } else if (1 > b_idx) {
      idx = 0;
    } else {
      idx = b_idx;
    }

    if (idx != 0) {
      requestID = activeRequests_data[ii_data[0] - 1];
      localB->nAttemptsOut = 1.0;
    } else {
      if ((b_ii != 0) && (localB->nAttemptsOut == 0.0)) {
        requestID = activeRequests_data[0];
        localB->nAttemptsOut = 1.0;
      }
    }
  }

  localB->requestID = requestID;

  /* End of MATLAB Function: '<S63>/manage_computations' */
}

/* Output and update for atomic system: '<S51>/merge_request_flags' */
void obrttg_mvm_mBox_merge_request_flags(const real_T rtu_request_flags_new[5],
  const real_T rtu_request_flags_old[5], B_merge_request_flags_obrttg_mvm_mBox_T
  *localB)
{
  boolean_T rtb_request_flags_cast1[5];
  boolean_T rtb_request_flags_cast2[5];
  int32_T i;
  for (i = 0; i < 5; i++) {
    /* DataTypeConversion: '<S64>/request_flags_cast1' */
    rtb_request_flags_cast1[i] = (rtu_request_flags_new[i] != 0.0);

    /* DataTypeConversion: '<S64>/request_flags_cast2' */
    rtb_request_flags_cast2[i] = (rtu_request_flags_old[i] != 0.0);
  }

  /* DataTypeConversion: '<S64>/request_flags_cast' incorporates:
   *  Logic: '<S64>/compute_flag_or'
   */
  localB->request_flags_cast[0] = (rtb_request_flags_cast1[0] ||
    rtb_request_flags_cast2[0]);
  localB->request_flags_cast[2] = rtb_request_flags_cast1[2];
  localB->request_flags_cast[1] = (rtb_request_flags_cast1[1] ||
    rtb_request_flags_cast2[1]);
  localB->request_flags_cast[3] = rtb_request_flags_cast1[3];
  localB->request_flags_cast[4] = (rtb_request_flags_cast1[4] ||
    rtb_request_flags_cast2[4]);
}

/* Output and update for atomic system: '<S51>/update_request_flag' */
void obrttg_mvm_mBox_update_request_flag(real_T rtu_compute_flag, const real_T
  rtu_request_flags_in[5], B_update_request_flag_obrttg_mvm_mBox_T *localB)
{
  boolean_T rtb_computation_not;
  int32_T i;

  /* Logic: '<S66>/computation_not' incorporates:
   *  DataTypeConversion: '<S66>/compute_flag_cast'
   */
  rtb_computation_not = !(rtu_compute_flag != 0.0);

  /* Product: '<S66>/Multiply' incorporates:
   *  DataTypeConversion: '<S66>/compute_flag_cast1'
   */
  for (i = 0; i < 5; i++) {
    localB->Multiply[i] = (real_T)rtb_computation_not * rtu_request_flags_in[i];
  }

  /* End of Product: '<S66>/Multiply' */
}

/* System initialize for atomic system: '<S48>/manage_trajectory_switch' */
void obrttg_mvm_mBox_manage_trajectory_switch_Init
  (DW_manage_trajectory_switch_obrttg_mvm_mBox_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S70>/Delay Input1' */
  localDW->DelayInput1_DSTATE = 0.0;
}

/* System reset for atomic system: '<S48>/manage_trajectory_switch' */
void obrttg_mvm_mBox_manage_trajectory_switch_Reset
  (DW_manage_trajectory_switch_obrttg_mvm_mBox_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S70>/Delay Input1' */
  localDW->DelayInput1_DSTATE = 0.0;
}

/* Output and update for atomic system: '<S48>/manage_trajectory_switch' */
void obrttg_mvm_mBox_manage_trajectory_switch(real_T rtu_time_trajectory_switch,
  real_T rtu_time, real_T rtu_n_attempts, real_T rtu_computation_done,
  B_manage_trajectory_switch_obrttg_mvm_mBox_T *localB,
  DW_manage_trajectory_switch_obrttg_mvm_mBox_T *localDW)
{
  int32_T rtb_switchFlag;

  /* MATLAB Function: '<S52>/manage_trajectory_switch' */
  localB->emergencyFlag = 0.0;
  rtb_switchFlag = 0;
  if ((rtu_computation_done == 0.0) && (rtu_n_attempts > 0.0) && (rtu_time >=
       rtu_time_trajectory_switch + 0.18000000000000002)) {
    localB->emergencyFlag = 1.0;
  } else if (rtu_n_attempts > 3.0) {
    localB->emergencyFlag = 1.0;
  } else {
    if ((rtu_computation_done == 1.0) && (rtu_n_attempts > 0.0) && (rtu_time >=
         rtu_time_trajectory_switch)) {
      rtb_switchFlag = 1;
    }
  }

  /* End of MATLAB Function: '<S52>/manage_trajectory_switch' */

  /* DataTypeConversion: '<S52>/switchFlag_cast' incorporates:
   *  RelationalOperator: '<S70>/FixPt Relational Operator'
   *  UnitDelay: '<S70>/Delay Input1'
   */
  localB->switchFlag_cast = (rtb_switchFlag > localDW->DelayInput1_DSTATE);

  /* Update for UnitDelay: '<S70>/Delay Input1' */
  localDW->DelayInput1_DSTATE = rtb_switchFlag;
}

/* Output and update for atomic system: '<S53>/manage_failure_request' */
void obrttg_mvm_mBox_manage_failure_request(real_T rtu_failure_flag, real_T
  rtu_time_to_go, real_T rtu_n_targets, real_T rtu_current_target_idx,
  B_manage_failure_request_obrttg_mvm_mBox_T *localB)
{
  /* MATLAB Function: '<S76>/manage_failure_request' */
  localB->requestFlag = 0.0;
  localB->emergencyFlag = 0.0;
  if (rtu_failure_flag != 0.0) {
    if (rtu_time_to_go > 2.0) {
      localB->requestFlag = 1.0;
    } else {
      if (rtu_current_target_idx >= rtu_n_targets) {
        localB->emergencyFlag = 1.0;
      }
    }
  }

  /* End of MATLAB Function: '<S76>/manage_failure_request' */
}

/* Output and update for atomic system: '<S53>/manage_long_trajectory_request' */
void obrttg_mvm_mBox_manage_long_trajectory_request(real_T rtu_time_to_go,
  real_T rtu_trajectory_time_step, real_T rtu_trajectory_time, real_T
  rtu_offline_otp, B_manage_long_trajectory_request_obrttg_mvm_mBox_T *localB)
{
  /* MATLAB Function: '<S77>/manage_long_trajectory_request' */
  localB->requestFlag = 0.0;
  if ((rtu_trajectory_time_step > 0.5) && (rtu_time_to_go < rtu_trajectory_time /
       2.0 + 0.04) && ((rtu_time_to_go > 0.0) && (!(rtu_offline_otp != 0.0)))) {
    localB->requestFlag = 1.0;
  }

  /* End of MATLAB Function: '<S77>/manage_long_trajectory_request' */
}

/* Output and update for atomic system: '<S53>/manage_nominal_request' */
void obrttg_mvm_mBox_manage_nominal_request(real_T rtu_time_to_go, real_T
  rtu_n_targets, real_T rtu_current_target_idx,
  B_manage_nominal_request_obrttg_mvm_mBox_T *localB)
{
  /* MATLAB Function: '<S78>/manage_nominal_request' */
  localB->requestFlag = 0.0;
  if ((rtu_time_to_go <= 0.2) && (rtu_time_to_go > 0.0) &&
      (rtu_current_target_idx < rtu_n_targets)) {
    localB->requestFlag = 1.0;
  }

  /* End of MATLAB Function: '<S78>/manage_nominal_request' */
}

/* Output and update for atomic system: '<S53>/manage_retargeting_request' */
void obrttg_mvm_mBox_manage_retargeting_request(real_T rtu_retargeting_flag,
  real_T rtu_time_to_go, real_T rtu_current_target_idx,
  B_manage_retargeting_request_obrttg_mvm_mBox_T *localB)
{
  /* MATLAB Function: '<S79>/manage_retargeting_request' */
  localB->requestFlag = 0.0;
  if ((rtu_retargeting_flag != 0.0) && (rtu_time_to_go > 2.0) &&
      (rtu_current_target_idx == 2.0)) {
    localB->requestFlag = 1.0;
  }

  /* End of MATLAB Function: '<S79>/manage_retargeting_request' */
}

/* Output and update for atomic system: '<S53>/manage_tracking_error_request' */
void obrttg_mvm_mBox_manage_tracking_error_request(real_T
  rtu_tracking_error_flag, real_T rtu_trajectory_time, real_T rtu_time_to_go,
  B_manage_tracking_error_request_obrttg_mvm_mBox_T *localB)
{
  /* MATLAB Function: '<S80>/manage_tracking_error_request' */
  localB->requestFlag = 0.0;
  if ((rtu_tracking_error_flag != 0.0) && (rtu_trajectory_time - rtu_time_to_go >
       4.0) && (rtu_time_to_go > 2.0) && (rtu_time_to_go > 0.0)) {
    localB->requestFlag = 1.0;
  }

  /* End of MATLAB Function: '<S80>/manage_tracking_error_request' */
}

/* System initialize for atomic system: '<S44>/manage_optimal_guidance_mbox' */
void obrttg_mvm_mBox_manage_optimal_guidance_mbox_Init
  (B_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localB,
   DW_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localDW)
{
  int32_T i;

  /* Start for Probe: '<S82>/Probe Dimension' */
  localB->ProbeDimension[0] = 6.0;
  localB->ProbeDimension[1] = 3.0;

  /* Start for Probe: '<S83>/Probe Dimension' */
  localB->ProbeDimension_k[0] = 6.0;
  localB->ProbeDimension_k[1] = 3.0;

  /* InitializeConditions for Memory: '<S51>/compute_flag_memory' */
  localDW->compute_flag_memory_PreviousInput = 0.0;

  /* InitializeConditions for Memory: '<S51>/request_flags_memory' */
  for (i = 0; i < 5; i++) {
    localDW->request_flags_memory_PreviousInput[i] = 0.0;
  }

  /* End of InitializeConditions for Memory: '<S51>/request_flags_memory' */

  /* InitializeConditions for Memory: '<S48>/switch_flag_memory' */
  localDW->switch_flag_memory_PreviousInput = 0.0;

  /* InitializeConditions for Switch: '<S65>/reset_n_attempts' incorporates:
   *  Memory: '<S51>/n_attempts_memory'
   */
  localDW->n_attempts_memory_PreviousInput = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S48>/get_next_start_point' */
  /* SystemInitialize for Outport: '<S49>/next_start' */
  memset(&localB->get_next_start.nextStart[0], 0, 17U * sizeof(real_T));

  /* SystemInitialize for Outport: '<S49>/time_trajectory_switch' */
  localB->Sum1 = 0.0;

  /* End of SystemInitialize for SubSystem: '<S48>/get_next_start_point' */

  /* SystemInitialize for Atomic SubSystem: '<S50>/get_next_target_idx' */
  obrttg_mvm_mBox_get_next_target_idx_Init(&localDW->get_next_target_idx);

  /* End of SystemInitialize for SubSystem: '<S50>/get_next_target_idx' */

  /* SystemInitialize for Atomic SubSystem: '<S48>/manage_trajectory_switch' */
  obrttg_mvm_mBox_manage_trajectory_switch_Init
    (&localDW->manage_trajectory_switch);

  /* End of SystemInitialize for SubSystem: '<S48>/manage_trajectory_switch' */
}

/* System reset for atomic system: '<S44>/manage_optimal_guidance_mbox' */
void obrttg_mvm_mBox_manage_optimal_guidance_mbox_Reset
  (DW_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localDW)
{
  int32_T i;

  /* InitializeConditions for Memory: '<S51>/compute_flag_memory' */
  localDW->compute_flag_memory_PreviousInput = 0.0;

  /* InitializeConditions for Memory: '<S51>/request_flags_memory' */
  for (i = 0; i < 5; i++) {
    localDW->request_flags_memory_PreviousInput[i] = 0.0;
  }

  /* End of InitializeConditions for Memory: '<S51>/request_flags_memory' */

  /* InitializeConditions for Memory: '<S48>/switch_flag_memory' */
  localDW->switch_flag_memory_PreviousInput = 0.0;

  /* InitializeConditions for Switch: '<S65>/reset_n_attempts' incorporates:
   *  Memory: '<S51>/n_attempts_memory'
   */
  localDW->n_attempts_memory_PreviousInput = 0.0;

  /* SystemReset for Atomic SubSystem: '<S50>/get_next_target_idx' */
  obrttg_mvm_mBox_get_next_target_idx_Reset(&localDW->get_next_target_idx);

  /* End of SystemReset for SubSystem: '<S50>/get_next_target_idx' */

  /* SystemReset for Atomic SubSystem: '<S48>/manage_trajectory_switch' */
  obrttg_mvm_mBox_manage_trajectory_switch_Reset
    (&localDW->manage_trajectory_switch);

  /* End of SystemReset for SubSystem: '<S48>/manage_trajectory_switch' */
}

/* Disable for atomic system: '<S44>/manage_optimal_guidance_mbox' */
void obrttg_mvm_mBox_manage_optimal_guidance_mbox_Disable
  (B_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localB,
   DW_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localDW)
{
  /* Disable for Enabled SubSystem: '<S48>/get_next_start_point' */
  if (localDW->get_next_start_point_MODE) {
    /* Disable for Outport: '<S49>/next_start' */
    memset(&localB->get_next_start.nextStart[0], 0, 17U * sizeof(real_T));
    localDW->get_next_start_point_MODE = false;
  }

  /* End of Disable for SubSystem: '<S48>/get_next_start_point' */
}

/* Output and update for atomic system: '<S44>/manage_optimal_guidance_mbox' */
void obrttg_mvm_mBox_manage_optimal_guidance_mbox(real_T rtu_time, const real_T
  rtu_vehicle_state[14], const real_T rtu_optimal_trajectory[540], real_T
  rtu_computation_done, real_T rtu_solver_exitflag, real_T rtu_time_to_go,
  real_T rtu_retargeting_flag, real_T rtu_tracking_error_flag, real_T
  rtu_failure_flag, const real_T rtu_WP_list[18], real_T rtu_offline_otp, real_T
  rtu_current_target_idx, B_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T
  *localB, const ConstB_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localC,
  DW_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localDW)
{
  real_T rtb_TmpSignalConversionAtmerge_request_flagsInport1[5];
  int32_T i;
  int32_T tmp;
  real_T tmp_0;

  /* Switch: '<S74>/Switch' incorporates:
   *  Constant: '<S74>/constant_one'
   *  Sum: '<S74>/Sum'
   */
  if (localB->ProbeDimension[1] > 2.0) {
    tmp_0 = localB->ProbeDimension[1] - 1.0;
  } else {
    tmp_0 = localB->ProbeDimension[1];
  }

  /* End of Switch: '<S74>/Switch' */

  /* Outputs for Atomic SubSystem: '<S53>/manage_nominal_request' */
  obrttg_mvm_mBox_manage_nominal_request(rtu_time_to_go, tmp_0,
    rtu_current_target_idx, &localB->manage_nominal_request);

  /* End of Outputs for SubSystem: '<S53>/manage_nominal_request' */

  /* Outputs for Atomic SubSystem: '<S53>/manage_retargeting_request' */
  obrttg_mvm_mBox_manage_retargeting_request(rtu_retargeting_flag,
    rtu_time_to_go, rtu_current_target_idx, &localB->manage_retargeting_request);

  /* End of Outputs for SubSystem: '<S53>/manage_retargeting_request' */

  /* Outputs for Atomic SubSystem: '<S53>/manage_long_trajectory_request' */
  /* Product: '<S73>/Divide' incorporates:
   *  Selector: '<S71>/sel_last_time'
   *  Selector: '<S81>/sel_last_time'
   */
  obrttg_mvm_mBox_manage_long_trajectory_request(rtu_time_to_go,
    rtu_optimal_trajectory[18 * ((int32_T)localC->Width_b - 1)] /
    localC->Width_l, rtu_optimal_trajectory[18 * ((int32_T)localC->Width - 1)],
    rtu_offline_otp, &localB->manage_long_trajectory_request);

  /* End of Outputs for SubSystem: '<S53>/manage_long_trajectory_request' */

  /* Outputs for Atomic SubSystem: '<S53>/manage_tracking_error_request' */
  /* Selector: '<S72>/sel_last_time' */
  obrttg_mvm_mBox_manage_tracking_error_request(rtu_tracking_error_flag,
    rtu_optimal_trajectory[18 * ((int32_T)localC->Width_k - 1)], rtu_time_to_go,
    &localB->manage_tracking_error_request);

  /* End of Outputs for SubSystem: '<S53>/manage_tracking_error_request' */

  /* Switch: '<S75>/Switch' incorporates:
   *  Constant: '<S75>/constant_one'
   *  Sum: '<S75>/Sum'
   */
  if (localB->ProbeDimension_k[1] > 2.0) {
    tmp_0 = localB->ProbeDimension_k[1] - 1.0;
  } else {
    tmp_0 = localB->ProbeDimension_k[1];
  }

  /* End of Switch: '<S75>/Switch' */

  /* Outputs for Atomic SubSystem: '<S53>/manage_failure_request' */
  obrttg_mvm_mBox_manage_failure_request(rtu_failure_flag, rtu_time_to_go, tmp_0,
    rtu_current_target_idx, &localB->manage_failure_request);

  /* End of Outputs for SubSystem: '<S53>/manage_failure_request' */

  /* SignalConversion generated from: '<S51>/merge_request_flags' */
  rtb_TmpSignalConversionAtmerge_request_flagsInport1[0] =
    localB->manage_nominal_request.requestFlag;
  rtb_TmpSignalConversionAtmerge_request_flagsInport1[1] =
    localB->manage_retargeting_request.requestFlag;
  rtb_TmpSignalConversionAtmerge_request_flagsInport1[2] =
    localB->manage_long_trajectory_request.requestFlag;
  rtb_TmpSignalConversionAtmerge_request_flagsInport1[3] =
    localB->manage_tracking_error_request.requestFlag;
  rtb_TmpSignalConversionAtmerge_request_flagsInport1[4] =
    localB->manage_failure_request.requestFlag;

  /* Outputs for Atomic SubSystem: '<S51>/update_request_flag' */
  /* Memory: '<S51>/compute_flag_memory' */
  obrttg_mvm_mBox_update_request_flag(localDW->compute_flag_memory_PreviousInput,
    localDW->request_flags_memory_PreviousInput, &localB->update_request_flag);

  /* End of Outputs for SubSystem: '<S51>/update_request_flag' */

  /* Outputs for Atomic SubSystem: '<S51>/merge_request_flags' */
  obrttg_mvm_mBox_merge_request_flags
    (rtb_TmpSignalConversionAtmerge_request_flagsInport1,
     localB->update_request_flag.Multiply, &localB->merge_request_flags);

  /* End of Outputs for SubSystem: '<S51>/merge_request_flags' */

  /* Switch: '<S65>/reset_n_attempts' incorporates:
   *  Constant: '<S65>/n_attempts_0'
   *  Memory: '<S48>/switch_flag_memory'
   */
  if (localDW->switch_flag_memory_PreviousInput > 0.0) {
    localDW->n_attempts_memory_PreviousInput = 0.0;
  }

  /* End of Switch: '<S65>/reset_n_attempts' */

  /* Outputs for Atomic SubSystem: '<S51>/manage_computations' */
  obrttg_mvm_mBox_manage_computations
    (localB->merge_request_flags.request_flags_cast, rtu_computation_done,
     rtu_solver_exitflag, localDW->n_attempts_memory_PreviousInput,
     &localB->manage_computations);

  /* End of Outputs for SubSystem: '<S51>/manage_computations' */

  /* Outputs for Enabled SubSystem: '<S48>/get_next_start_point' incorporates:
   *  EnablePort: '<S49>/Enable'
   */
  if (localB->manage_computations.requestID > 0.0) {
    localDW->get_next_start_point_MODE = true;

    /* Outputs for Atomic SubSystem: '<S49>/get_prediction_time' */
    obrttg_mvm_mBox_get_prediction_time(rtu_time_to_go,
      localB->manage_computations.requestID, &localB->get_prediction_time);

    /* End of Outputs for SubSystem: '<S49>/get_prediction_time' */

    /* Outputs for Atomic SubSystem: '<S49>/get_propagate_flag' */
    obrttg_mvm_mBox_get_propagate_flag(&localB->get_propagate_flag);

    /* End of Outputs for SubSystem: '<S49>/get_propagate_flag' */

    /* Outputs for Atomic SubSystem: '<S49>/get_next_start' */
    obrttg_mvm_mBox_get_next_start(rtu_optimal_trajectory, rtu_vehicle_state,
      localB->manage_computations.nAttemptsOut,
      localB->get_propagate_flag.Selector, localB->manage_computations.requestID,
      rtu_time_to_go, localB->get_prediction_time.sel_prediction_time,
      &localB->get_next_start);

    /* End of Outputs for SubSystem: '<S49>/get_next_start' */

    /* Sum: '<S49>/Sum1' */
    localB->Sum1 = localB->get_prediction_time.sel_prediction_time + rtu_time;
  } else {
    if (localDW->get_next_start_point_MODE) {
      /* Disable for Outport: '<S49>/next_start' */
      memset(&localB->get_next_start.nextStart[0], 0, 17U * sizeof(real_T));
      localDW->get_next_start_point_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S48>/get_next_start_point' */

  /* Outputs for Atomic SubSystem: '<S50>/get_next_target_idx' */
  obrttg_mvm_mBox_get_next_target_idx(localB->manage_nominal_request.requestFlag,
    localB->manage_retargeting_request.requestFlag, rtu_current_target_idx,
    &localB->get_next_target_idx, &localDW->get_next_target_idx);

  /* End of Outputs for SubSystem: '<S50>/get_next_target_idx' */

  /* Selector: '<S59>/sel_WP' */
  tmp = (int32_T)localB->get_next_target_idx.nextTargetIdx;
  for (i = 0; i < 6; i++) {
    localB->sel_WP[i] = rtu_WP_list[(tmp - 1) * 6 + i];
  }

  /* End of Selector: '<S59>/sel_WP' */

  /* Outputs for Atomic SubSystem: '<S48>/manage_trajectory_switch' */
  obrttg_mvm_mBox_manage_trajectory_switch(localB->Sum1, rtu_time,
    localB->manage_computations.nAttemptsOut, rtu_computation_done,
    &localB->manage_trajectory_switch, &localDW->manage_trajectory_switch);

  /* End of Outputs for SubSystem: '<S48>/manage_trajectory_switch' */

  /* DataTypeConversion: '<S48>/emergencyFlag_cast' incorporates:
   *  Logic: '<S48>/emergency_or'
   */
  localB->emergencyFlag_cast = ((localB->manage_trajectory_switch.emergencyFlag
    != 0.0) || (localB->manage_failure_request.emergencyFlag != 0.0));

  /* DataTypeConversion: '<S62>/compute_flag_cast' incorporates:
   *  Constant: '<S67>/Constant'
   *  RelationalOperator: '<S67>/Compare'
   */
  localB->compute_flag_cast = (localB->manage_computations.requestID > 0.0);

  /* Update for Memory: '<S51>/compute_flag_memory' */
  localDW->compute_flag_memory_PreviousInput = localB->compute_flag_cast;

  /* Update for Memory: '<S51>/request_flags_memory' */
  for (i = 0; i < 5; i++) {
    localDW->request_flags_memory_PreviousInput[i] =
      localB->merge_request_flags.request_flags_cast[i];
  }

  /* End of Update for Memory: '<S51>/request_flags_memory' */

  /* Update for Memory: '<S48>/switch_flag_memory' */
  localDW->switch_flag_memory_PreviousInput =
    localB->manage_trajectory_switch.switchFlag_cast;

  /* Update for Switch: '<S65>/reset_n_attempts' incorporates:
   *  Memory: '<S51>/n_attempts_memory'
   */
  localDW->n_attempts_memory_PreviousInput =
    localB->manage_computations.nAttemptsOut;
}

/* System initialize for atomic system: '<S4>/target_manager_mbox' */
void obrttg_mvm_mBox_target_manager_mbox_Init
  (B_target_manager_mbox_obrttg_mvm_mBox_T *localB,
   DW_target_manager_mbox_obrttg_mvm_mBox_T *localDW)
{
  /* Start for SwitchCase: '<S21>/Switch Case' */
  localDW->SwitchCase_ActiveSubsystem = -1;

  /* InitializeConditions for Memory: '<S21>/Memory' */
  memset(&localDW->Memory_PreviousInput[0], 0, 13U * sizeof(real_T));

  /* SystemInitialize for IfAction SubSystem: '<S21>/optimal_guidance_manager' */
  /* InitializeConditions for Memory: '<S44>/target_idx_memory' */
  localDW->target_idx_memory_PreviousInput = 1.0;

  /* SystemInitialize for Atomic SubSystem: '<S44>/manage_optimal_guidance_mbox' */
  obrttg_mvm_mBox_manage_optimal_guidance_mbox_Init
    (&localB->manage_optimal_guidance_mbox,
     &localDW->manage_optimal_guidance_mbox);

  /* End of SystemInitialize for SubSystem: '<S44>/manage_optimal_guidance_mbox' */
  /* End of SystemInitialize for SubSystem: '<S21>/optimal_guidance_manager' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/manage_guidance_ready_mbox' */
  /* InitializeConditions for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0;

  /* End of SystemInitialize for SubSystem: '<S21>/manage_guidance_ready_mbox' */
}

/* Output and update for atomic system: '<S4>/target_manager_mbox' */
void obrttg_mvm_mBox_target_manager_mbox(RT_MODEL_obrttg_mvm_mBox_T * const
  obrttg_mvm_mBox_M, const real_T rtu_WPs_list[18], const real_T
  rtu_takeoff_target_position[3], const real_T rtu_velocity_toff[3], real_T
  rtu_offline_otp, const busMissionState *rtu_mission_state, const real_T
  rtu_vehicle_state[14], real_T rtu_solver_exitflag, real_T rtu_computation_done,
  const real_T rtu_optimal_trajectory[540], real_T rtu_flight_mode,
  B_target_manager_mbox_obrttg_mvm_mBox_T *localB, const
  ConstB_target_manager_mbox_obrttg_mvm_mBox_T *localC,
  DW_target_manager_mbox_obrttg_mvm_mBox_T *localDW)
{
  int8_T rtPrevAction;
  int32_T i;
  real_T tmp;

  /* SwitchCase: '<S21>/Switch Case' incorporates:
   *  DataTypeConversion: '<S44>/Cast To Double'
   *  DataTypeConversion: '<S44>/Cast To Double1'
   *  DataTypeConversion: '<S44>/Cast To Double2'
   *  DigitalClock: '<S21>/current_time1'
   *  Memory: '<S44>/target_idx_memory'
   */
  rtPrevAction = localDW->SwitchCase_ActiveSubsystem;
  tmp = trunc(rtu_flight_mode);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 0:
    localDW->SwitchCase_ActiveSubsystem = 0;
    break;

   case 2:
    localDW->SwitchCase_ActiveSubsystem = 1;
    break;

   case 1:
    localDW->SwitchCase_ActiveSubsystem = 2;
    break;

   default:
    localDW->SwitchCase_ActiveSubsystem = 3;
    break;
  }

  if (rtPrevAction != localDW->SwitchCase_ActiveSubsystem) {
    switch (rtPrevAction) {
     case 0:
     case 3:
      break;

     case 1:
      /* Disable for Atomic SubSystem: '<S44>/manage_optimal_guidance_mbox' */
      obrttg_mvm_mBox_manage_optimal_guidance_mbox_Disable
        (&localB->manage_optimal_guidance_mbox,
         &localDW->manage_optimal_guidance_mbox);

      /* End of Disable for SubSystem: '<S44>/manage_optimal_guidance_mbox' */
      break;

     case 2:
      /* Disable for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' */
      localDW->DiscreteTimeIntegrator_DSTATE = localB->DiscreteTimeIntegrator;
      break;
    }
  }

  switch (localDW->SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S21>/startup_manager' incorporates:
     *  ActionPort: '<S45>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S45>/manage_startup_mbox' */
    obrttg_mvm_mBox_manage_startup_mbox(rtu_vehicle_state, rtu_computation_done,
      rtu_solver_exitflag, rtu_WPs_list, rtu_takeoff_target_position,
      rtu_velocity_toff, &localB->manage_startup_mbox);

    /* End of Outputs for SubSystem: '<S45>/manage_startup_mbox' */

    /* SignalConversion generated from: '<S45>/manage_startup_out' incorporates:
     *  Constant: '<S45>/false_emergency_flag'
     */
    memcpy(&localB->Merge[0], &localB->manage_startup_mbox.nextTarget[0], 13U *
           sizeof(real_T));
    memcpy(&localB->Merge[13], &localB->manage_startup_mbox.nextStart[0], 17U *
           sizeof(real_T));
    localB->Merge[30] = localB->manage_startup_mbox.recomputeFlag;
    localB->Merge[31] = localB->manage_startup_mbox.switchTrajectory;
    localB->Merge[32] = 0.0;

    /* End of Outputs for SubSystem: '<S21>/startup_manager' */
    break;

   case 1:
    if (localDW->SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S21>/optimal_guidance_manager' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S21>/Switch Case' incorporates:
       *  Memory: '<S44>/target_idx_memory'
       */
      localDW->target_idx_memory_PreviousInput = 1.0;

      /* End of InitializeConditions for SubSystem: '<S21>/optimal_guidance_manager' */

      /* SystemReset for IfAction SubSystem: '<S21>/optimal_guidance_manager' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      /* SystemReset for Atomic SubSystem: '<S44>/manage_optimal_guidance_mbox' */
      /* SystemReset for SwitchCase: '<S21>/Switch Case' */
      obrttg_mvm_mBox_manage_optimal_guidance_mbox_Reset
        (&localDW->manage_optimal_guidance_mbox);

      /* End of SystemReset for SubSystem: '<S44>/manage_optimal_guidance_mbox' */
      /* End of SystemReset for SubSystem: '<S21>/optimal_guidance_manager' */
    }

    /* Outputs for IfAction SubSystem: '<S21>/optimal_guidance_manager' incorporates:
     *  ActionPort: '<S44>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S44>/manage_optimal_guidance_mbox' */
    obrttg_mvm_mBox_manage_optimal_guidance_mbox
      (obrttg_mvm_mBox_M->Timing.taskTime0, rtu_vehicle_state,
       rtu_optimal_trajectory, rtu_computation_done, rtu_solver_exitflag,
       rtu_mission_state->time_to_go, (real_T)
       rtu_mission_state->retargeting_flag, (real_T)
       rtu_mission_state->tracking_error_flag, (real_T)
       rtu_mission_state->failure_detection, rtu_WPs_list, rtu_offline_otp,
       localDW->target_idx_memory_PreviousInput,
       &localB->manage_optimal_guidance_mbox,
       &localC->manage_optimal_guidance_mbox,
       &localDW->manage_optimal_guidance_mbox);

    /* End of Outputs for SubSystem: '<S44>/manage_optimal_guidance_mbox' */

    /* SignalConversion generated from: '<S44>/manage_optimal_out' incorporates:
     *  DataTypeConversion: '<S44>/Cast To Double'
     *  DataTypeConversion: '<S44>/Cast To Double1'
     *  DataTypeConversion: '<S44>/Cast To Double2'
     *  DigitalClock: '<S21>/current_time1'
     *  Memory: '<S44>/target_idx_memory'
     */
    for (i = 0; i < 6; i++) {
      localB->Merge[i] = localB->manage_optimal_guidance_mbox.sel_WP[i];
    }

    localB->Merge[6] = localC->manage_optimal_guidance_mbox.target_attitude[0];
    localB->Merge[7] = localC->manage_optimal_guidance_mbox.target_attitude[1];
    localB->Merge[8] = localC->manage_optimal_guidance_mbox.target_attitude[2];
    localB->Merge[9] = localC->manage_optimal_guidance_mbox.target_attitude[3];
    localB->Merge[10] = localC->manage_optimal_guidance_mbox.target_rates[0];
    localB->Merge[11] = localC->manage_optimal_guidance_mbox.target_rates[1];
    localB->Merge[12] = localC->manage_optimal_guidance_mbox.target_rates[2];
    memcpy(&localB->Merge[13],
           &localB->manage_optimal_guidance_mbox.get_next_start.nextStart[0],
           17U * sizeof(real_T));
    localB->Merge[30] = localB->manage_optimal_guidance_mbox.compute_flag_cast;
    localB->Merge[31] =
      localB->manage_optimal_guidance_mbox.manage_trajectory_switch.switchFlag_cast;
    localB->Merge[32] = localB->manage_optimal_guidance_mbox.emergencyFlag_cast;

    /* Update for Memory: '<S44>/target_idx_memory' */
    localDW->target_idx_memory_PreviousInput =
      localB->manage_optimal_guidance_mbox.get_next_target_idx.nextTargetIdx;

    /* End of Outputs for SubSystem: '<S21>/optimal_guidance_manager' */
    break;

   case 2:
    if (localDW->SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S21>/manage_guidance_ready_mbox' incorporates:
       *  ActionPort: '<S42>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S21>/Switch Case' incorporates:
       *  DiscreteIntegrator: '<S46>/Discrete-Time Integrator'
       */
      localDW->DiscreteTimeIntegrator_DSTATE = 0.0;

      /* End of InitializeConditions for SubSystem: '<S21>/manage_guidance_ready_mbox' */
    }

    /* Outputs for IfAction SubSystem: '<S21>/manage_guidance_ready_mbox' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    /* DiscreteIntegrator: '<S46>/Discrete-Time Integrator' */
    localB->DiscreteTimeIntegrator = localDW->DiscreteTimeIntegrator_DSTATE;

    /* SignalConversion generated from: '<S42>/manage_guidance_ready_out' incorporates:
     *  Constant: '<S42>/false_emergency_flag'
     *  Constant: '<S42>/false_recompute_flag'
     *  Constant: '<S47>/Constant'
     *  DataTypeConversion: '<S46>/Cast To Double'
     *  Inport: '<S42>/next_target'
     *  RelationalOperator: '<S47>/Compare'
     */
    memcpy(&localB->Merge[0], &localDW->Memory_PreviousInput[0], 13U * sizeof
           (real_T));
    memset(&localB->Merge[13], 0, 18U * sizeof(real_T));
    localB->Merge[31] = (localB->DiscreteTimeIntegrator < 1.0);
    localB->Merge[32] = 0.0;

    /* Update for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S46>/constant'
     */
    localDW->DiscreteTimeIntegrator_DSTATE++;

    /* End of Outputs for SubSystem: '<S21>/manage_guidance_ready_mbox' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S21>/manage_phase_default_mbox' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    /* SignalConversion generated from: '<S43>/manage_default_out' incorporates:
     *  Constant: '<S43>/false_emergency_flag'
     *  Constant: '<S43>/false_recompute_flag'
     *  Constant: '<S43>/false_switch_trajectory'
     *  Inport: '<S43>/next_target'
     */
    memcpy(&localB->Merge[0], &localDW->Memory_PreviousInput[0], 13U * sizeof
           (real_T));
    memset(&localB->Merge[13], 0, 20U * sizeof(real_T));

    /* End of Outputs for SubSystem: '<S21>/manage_phase_default_mbox' */
    break;
  }

  /* End of SwitchCase: '<S21>/Switch Case' */

  /* DataTypeConversion: '<S21>/Cast To Boolean' */
  localB->CastToBoolean = (localB->Merge[30] != 0.0);

  /* DataTypeConversion: '<S21>/Cast To Boolean1' */
  localB->CastToBoolean1 = (localB->Merge[31] != 0.0);

  /* DataTypeConversion: '<S21>/Cast To Boolean2' */
  localB->CastToBoolean2 = (localB->Merge[32] != 0.0);

  /* Update for Memory: '<S21>/Memory' */
  memcpy(&localDW->Memory_PreviousInput[0], &localB->Merge[0], 13U * sizeof
         (real_T));
}

/* System initialize for atomic system: '<S1>/mission_and_vehicle_management_mbox' */
void obrttg_mvm_mBox_mission_and_vehicle_management_mbox_Init
  (B_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T *localB,
   DW_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S33>/Delay Input1' */
  localDW->DelayInput1_DSTATE = 0.0;

  /* InitializeConditions for Memory: '<S34>/Memory' */
  localDW->Memory_PreviousInput = false;

  /* InitializeConditions for Memory: '<S4>/Memory1' */
  localDW->Memory1_PreviousInput = false;

  /* InitializeConditions for Memory: '<S4>/next_target_memory' */
  memset(&localDW->next_target_memory_PreviousInput[0], 0, 13U * sizeof(real_T));

  /* SystemInitialize for Merge: '<S19>/Merge' */
  localB->Merge = 0.0;

  /* SystemInitialize for Atomic SubSystem: '<S4>/target_manager_mbox' */
  obrttg_mvm_mBox_target_manager_mbox_Init(&localB->target_manager_mbox,
    &localDW->target_manager_mbox);

  /* End of SystemInitialize for SubSystem: '<S4>/target_manager_mbox' */
}

/* Output and update for atomic system: '<S1>/mission_and_vehicle_management_mbox' */
void obrttg_mvm_mBox_mission_and_vehicle_management_mbox
  (RT_MODEL_obrttg_mvm_mBox_T * const obrttg_mvm_mBox_M, real_T
   rtu_flight_mode_in, const real_T rtu_start_wp_position[3], const real_T
   rtu_final_wp_position[3], const real_T rtu_WPs_list[18], const real_T
   rtu_velocity_toff[3], real_T rtu_offline_otp, const real_T rtu_vehicle_state
   [14], const busMissionState *rtu_mission_state, const real_T
   rtu_previous_trajectory[540], real_T rtu_solver_exitflag, real_T
   rtu_computation_done, real_T rtu_obc_status_flag,
   B_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T *localB, const
   ConstB_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T *localC,
   DW_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T *localDW)
{
  int32_T rowIdx;
  real_T rtb_Sum_ne_0;
  real_T rtb_Sum_ne_1;
  real_T rtb_Sum_gn;
  real_T rtb_Sum_ne_idx_0;
  real_T rtb_Sum_ne_idx_1;
  real_T tmp;

  /* CombinatorialLogic: '<S34>/Logic' incorporates:
   *  Memory: '<S34>/Memory'
   *  RelationalOperator: '<S33>/FixPt Relational Operator'
   *  UnitDelay: '<S33>/Delay Input1'
   */
  rowIdx = (int32_T)(((uint32_T)(rtu_obc_status_flag <
    localDW->DelayInput1_DSTATE) << 2) + localDW->Memory_PreviousInput);

  /* Sum: '<S36>/Sum1' */
  rtb_Sum_gn = rtu_vehicle_state[1] - rtu_final_wp_position[0];

  /* DotProduct: '<S40>/Dot Product' */
  rtb_Sum_ne_0 = rtb_Sum_gn * rtb_Sum_gn;

  /* Sum: '<S36>/Sum2' incorporates:
   *  Memory: '<S4>/next_target_memory'
   */
  rtb_Sum_gn = rtu_final_wp_position[0] -
    localDW->next_target_memory_PreviousInput[0];

  /* DotProduct: '<S41>/Dot Product' */
  rtb_Sum_ne_1 = rtb_Sum_gn * rtb_Sum_gn;

  /* Sum: '<S36>/Sum1' incorporates:
   *  Sum: '<S20>/Sum'
   */
  rtb_Sum_ne_idx_0 = rtu_vehicle_state[1] - rtu_start_wp_position[0];
  rtb_Sum_gn = rtu_vehicle_state[2] - rtu_final_wp_position[1];

  /* DotProduct: '<S40>/Dot Product' */
  rtb_Sum_ne_0 += rtb_Sum_gn * rtb_Sum_gn;

  /* Sum: '<S36>/Sum2' incorporates:
   *  Memory: '<S4>/next_target_memory'
   */
  rtb_Sum_gn = rtu_final_wp_position[1] -
    localDW->next_target_memory_PreviousInput[1];

  /* DotProduct: '<S41>/Dot Product' */
  rtb_Sum_ne_1 += rtb_Sum_gn * rtb_Sum_gn;

  /* Sum: '<S36>/Sum1' incorporates:
   *  Sum: '<S20>/Sum'
   */
  rtb_Sum_ne_idx_1 = rtu_vehicle_state[2] - rtu_start_wp_position[1];
  rtb_Sum_gn = rtu_vehicle_state[3] - rtu_final_wp_position[2];

  /* DotProduct: '<S40>/Dot Product' */
  rtb_Sum_ne_0 += rtb_Sum_gn * rtb_Sum_gn;

  /* Sum: '<S36>/Sum2' incorporates:
   *  Memory: '<S4>/next_target_memory'
   */
  rtb_Sum_gn = rtu_final_wp_position[2] -
    localDW->next_target_memory_PreviousInput[2];

  /* DotProduct: '<S41>/Dot Product' */
  rtb_Sum_ne_1 += rtb_Sum_gn * rtb_Sum_gn;

  /* Sum: '<S20>/Sum' */
  rtb_Sum_gn = rtu_vehicle_state[3] - rtu_start_wp_position[2];

  /* SwitchCase: '<S19>/Switch Case' */
  tmp = trunc(rtu_flight_mode_in);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  switch (tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S19>/mode_0_startup' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* SignalConversion generated from: '<S23>/mode_output' incorporates:
     *  MATLAB Function: '<S23>/handle_startup_mode'
     */
    localB->Merge = 0.0;

    /* MATLAB Function: '<S23>/handle_startup_mode' incorporates:
     *  Constant: '<S31>/Constant'
     *  Constant: '<S38>/Constant'
     *  Constant: '<S39>/Constant'
     *  DigitalClock: '<S4>/current_time'
     *  Logic: '<S35>/Logical Operator'
     *  Memory: '<S4>/Memory1'
     *  RelationalOperator: '<S31>/Compare'
     *  RelationalOperator: '<S38>/Compare'
     *  RelationalOperator: '<S39>/Compare'
     */
    if (obrttg_mvm_mBox_M->Timing.taskTime0 > 10.0) {
      /* SignalConversion generated from: '<S23>/mode_output' */
      localB->Merge = -1.0;
    } else if (localDW->Memory1_PreviousInput) {
      /* SignalConversion generated from: '<S23>/mode_output' */
      localB->Merge = -1.0;
    } else if (!(rtu_obc_status_flag == 1.0)) {
      /* SignalConversion generated from: '<S23>/mode_output' */
      localB->Merge = -1.0;
    } else {
      if ((rtu_computation_done == 1.0) && (rtu_solver_exitflag == 1.0)) {
        /* SignalConversion generated from: '<S23>/mode_output' */
        localB->Merge = 1.0;
      }
    }

    /* End of Outputs for SubSystem: '<S19>/mode_0_startup' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S19>/mode_1_guidance_ready' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* SignalConversion generated from: '<S24>/mode_output' incorporates:
     *  MATLAB Function: '<S24>/handle_guidance_ready_mode'
     */
    localB->Merge = 1.0;

    /* MATLAB Function: '<S24>/handle_guidance_ready_mode' incorporates:
     *  Constant: '<S20>/Constant1'
     *  Constant: '<S32>/Constant'
     *  DotProduct: '<S37>/Dot Product'
     *  Logic: '<S20>/AND'
     *  Memory: '<S4>/Memory1'
     *  RelationalOperator: '<S20>/Less Than'
     *  RelationalOperator: '<S32>/Compare'
     *  Sqrt: '<S37>/Sqrt'
     */
    if (localDW->Memory1_PreviousInput) {
      /* SignalConversion generated from: '<S24>/mode_output' */
      localB->Merge = -1.0;
    } else {
      if ((sqrt((rtb_Sum_ne_idx_0 * rtb_Sum_ne_idx_0 + rtb_Sum_ne_idx_1 *
                 rtb_Sum_ne_idx_1) + rtb_Sum_gn * rtb_Sum_gn) <= 0.5) &&
          (rtu_obc_status_flag == 3.0)) {
        /* SignalConversion generated from: '<S24>/mode_output' */
        localB->Merge = 2.0;
      }
    }

    /* End of Outputs for SubSystem: '<S19>/mode_1_guidance_ready' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S19>/mode_2_optimal_guidance' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* SignalConversion generated from: '<S25>/mode_output' incorporates:
     *  MATLAB Function: '<S25>/handle_optimal_guidance_mode'
     */
    localB->Merge = 2.0;

    /* MATLAB Function: '<S25>/handle_optimal_guidance_mode' incorporates:
     *  CombinatorialLogic: '<S34>/Logic'
     *  Constant: '<S36>/Constant'
     *  Constant: '<S36>/Constant1'
     *  DotProduct: '<S40>/Dot Product'
     *  DotProduct: '<S41>/Dot Product'
     *  Logic: '<S36>/Logical Operator'
     *  Memory: '<S4>/Memory1'
     *  RelationalOperator: '<S36>/Less Than1'
     *  RelationalOperator: '<S36>/Less Than2'
     *  Sqrt: '<S40>/Sqrt'
     *  Sqrt: '<S41>/Sqrt'
     */
    if (localDW->Memory1_PreviousInput) {
      /* SignalConversion generated from: '<S25>/mode_output' */
      localB->Merge = -1.0;
    } else if (obrttg_mvm_mBox_ConstP.pooled9[(uint32_T)rowIdx]) {
      /* SignalConversion generated from: '<S25>/mode_output' */
      localB->Merge = -1.0;
    } else {
      if ((sqrt(rtb_Sum_ne_0) <= 0.5) && (sqrt(rtb_Sum_ne_1) <= 1.0E-6)) {
        /* SignalConversion generated from: '<S25>/mode_output' */
        localB->Merge = 3.0;
      }
    }

    /* End of Outputs for SubSystem: '<S19>/mode_2_optimal_guidance' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S19>/mode_3_guidance_done' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* SignalConversion generated from: '<S26>/mode_output' incorporates:
     *  MATLAB Function: '<S26>/handle_guidance_done_mode'
     */
    localB->Merge = 3.0;

    /* MATLAB Function: '<S26>/handle_guidance_done_mode' incorporates:
     *  CombinatorialLogic: '<S34>/Logic'
     *  Memory: '<S4>/Memory1'
     */
    if (localDW->Memory1_PreviousInput || obrttg_mvm_mBox_ConstP.pooled9
        [(uint32_T)rowIdx]) {
      /* SignalConversion generated from: '<S26>/mode_output' */
      localB->Merge = -1.0;
    }

    /* End of Outputs for SubSystem: '<S19>/mode_3_guidance_done' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S19>/mode_-1_idle' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    /* SignalConversion generated from: '<S22>/mode_output' incorporates:
     *  Constant: '<S22>/idle_mode'
     */
    localB->Merge = -1.0;

    /* End of Outputs for SubSystem: '<S19>/mode_-1_idle' */
    break;
  }

  /* End of SwitchCase: '<S19>/Switch Case' */

  /* Outputs for Atomic SubSystem: '<S4>/target_manager_mbox' */
  obrttg_mvm_mBox_target_manager_mbox(obrttg_mvm_mBox_M, rtu_WPs_list,
    rtu_start_wp_position, rtu_velocity_toff, rtu_offline_otp, rtu_mission_state,
    rtu_vehicle_state, rtu_solver_exitflag, rtu_computation_done,
    rtu_previous_trajectory, localB->Merge, &localB->target_manager_mbox,
    &localC->target_manager_mbox, &localDW->target_manager_mbox);

  /* End of Outputs for SubSystem: '<S4>/target_manager_mbox' */

  /* Update for UnitDelay: '<S33>/Delay Input1' */
  localDW->DelayInput1_DSTATE = rtu_obc_status_flag;

  /* Update for Memory: '<S34>/Memory' incorporates:
   *  CombinatorialLogic: '<S34>/Logic'
   */
  localDW->Memory_PreviousInput = obrttg_mvm_mBox_ConstP.pooled9[(uint32_T)
    rowIdx];

  /* Update for Memory: '<S4>/Memory1' */
  localDW->Memory1_PreviousInput = localB->target_manager_mbox.CastToBoolean2;

  /* Update for Memory: '<S4>/next_target_memory' */
  memcpy(&localDW->next_target_memory_PreviousInput[0],
         &localB->target_manager_mbox.Merge[0], 13U * sizeof(real_T));
}

/* Model step function */
void obrttg_mvm_mBox_step(void)
{
  int32_T rowIdx;
  int32_T rowIdx_0;
  int32_T rowIdx_1;
  real_T rtb_CastToDouble_a;
  busMissionState rtb_BusCreator1;
  boolean_T rtb_Compare;
  real_T rtb_Sum[3];
  real_T rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[14];
  real_T tmp;

  /* Outputs for Atomic SubSystem: '<S2>/check_computation_completion_svf' */
  /* Memory: '<S1>/recompute_flag_memory' incorporates:
   *  Inport: '<Root>/otp_output'
   */
  obrttg_mvm_mBox_check_computation_completion_svf
    (obrttg_mvm_mBox_DW.recompute_flag_memory_PreviousInput,
     obrttg_mvm_mBox_U.otp_output.trajectory_id,
     &obrttg_mvm_mBox_B.check_computation_completion_svf,
     &obrttg_mvm_mBox_DW.check_computation_completion_svf);

  /* End of Outputs for SubSystem: '<S2>/check_computation_completion_svf' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Inport: '<Root>/gnc_parameters'
   */
  rtb_Sum[0] = obrttg_mvm_mBox_U.gnc_parameters.gncParameters.takeOffHeight +
    obrttg_mvm_mBox_U.gnc_parameters.gncParameters.launchPadPosition[0];
  rtb_Sum[1] = obrttg_mvm_mBox_U.gnc_parameters.gncParameters.launchPadPosition
    [1];
  rtb_Sum[2] = obrttg_mvm_mBox_U.gnc_parameters.gncParameters.launchPadPosition
    [2];

  /* CombinatorialLogic: '<S11>/Logic' incorporates:
   *  Constant: '<S10>/Constant'
   *  Inport: '<Root>/navigation_output'
   *  Logic: '<S3>/AND'
   *  Memory: '<S11>/Memory'
   *  Memory: '<S1>/flight_mode_memory'
   *  RelationalOperator: '<S10>/Compare'
   */
  rowIdx = (int32_T)(((uint32_T)
                      ((obrttg_mvm_mBox_DW.flight_mode_memory_PreviousInput ==
                        2.0) &&
                       obrttg_mvm_mBox_U.navigation_output.retargeting_flag) <<
                      2) + obrttg_mvm_mBox_DW.Memory_PreviousInput);

  /* SignalConversion generated from: '<S1>/mission_and_vehicle_management_mbox' incorporates:
   *  Inport: '<Root>/navigation_output'
   */
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[0] =
    obrttg_mvm_mBox_U.navigation_output.mass;
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[1] =
    obrttg_mvm_mBox_U.navigation_output.position[0];
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[4] =
    obrttg_mvm_mBox_U.navigation_output.velocity[0];
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[2] =
    obrttg_mvm_mBox_U.navigation_output.position[1];
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[5] =
    obrttg_mvm_mBox_U.navigation_output.velocity[1];
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[3] =
    obrttg_mvm_mBox_U.navigation_output.position[2];
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[6] =
    obrttg_mvm_mBox_U.navigation_output.velocity[2];
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[7] =
    obrttg_mvm_mBox_U.navigation_output.attitude[0];
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[8] =
    obrttg_mvm_mBox_U.navigation_output.attitude[1];
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[9] =
    obrttg_mvm_mBox_U.navigation_output.attitude[2];
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[10] =
    obrttg_mvm_mBox_U.navigation_output.attitude[3];
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[11] =
    obrttg_mvm_mBox_U.navigation_output.rates[0];
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[12] =
    obrttg_mvm_mBox_U.navigation_output.rates[1];
  rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7[13] =
    obrttg_mvm_mBox_U.navigation_output.rates[2];

  /* Sqrt: '<S91>/Sqrt' incorporates:
   *  DotProduct: '<S91>/Dot Product'
   *  Inport: '<Root>/guidance_output'
   */
  rtb_CastToDouble_a = sqrt((obrttg_mvm_mBox_U.guidance_output.state_error[0] *
    obrttg_mvm_mBox_U.guidance_output.state_error[0] +
    obrttg_mvm_mBox_U.guidance_output.state_error[1] *
    obrttg_mvm_mBox_U.guidance_output.state_error[1]) +
    obrttg_mvm_mBox_U.guidance_output.state_error[2] *
    obrttg_mvm_mBox_U.guidance_output.state_error[2]);

  /* BusCreator: '<S5>/Bus Creator1' incorporates:
   *  Constant: '<S5>/failure_detection'
   *  Inport: '<Root>/gnc_parameters'
   *  Inport: '<Root>/guidance_output'
   *  Inport: '<Root>/navigation_output'
   *  RelationalOperator: '<S5>/greather_than'
   */
  rtb_BusCreator1.time_to_go = obrttg_mvm_mBox_U.guidance_output.time_to_go;
  rtb_BusCreator1.tracking_error_flag = (rtb_CastToDouble_a >=
    obrttg_mvm_mBox_U.gnc_parameters.gncParameters.trackingErrorThreshold);
  rtb_BusCreator1.retargeting_flag =
    obrttg_mvm_mBox_U.navigation_output.retargeting_flag;
  rtb_BusCreator1.failure_detection = false;

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/constant_one'
   *  Sum: '<S13>/Sum'
   */
  if (obrttg_mvm_mBox_B.ProbeDimension[1] > 2.0) {
    tmp = obrttg_mvm_mBox_B.ProbeDimension[1] - 1.0;
  } else {
    tmp = obrttg_mvm_mBox_B.ProbeDimension[1];
  }

  /* End of Switch: '<S13>/Switch' */

  /* Outputs for Atomic SubSystem: '<S1>/mission_and_vehicle_management_mbox' */
  /* Memory: '<S1>/flight_mode_memory' incorporates:
   *  CombinatorialLogic: '<S11>/Logic'
   *  DataTypeConversion: '<Root>/Cast To Double'
   *  DataTypeConversion: '<S3>/Cast To Double'
   *  Inport: '<Root>/comm_in'
   *  Inport: '<Root>/gnc_parameters'
   *  Inport: '<Root>/guidance_output'
   *  Inport: '<Root>/otp_output'
   *  Reshape: '<Root>/Reshape'
   *  Selector: '<S3>/Selector'
   *  Sum: '<S3>/Sum'
   */
  obrttg_mvm_mBox_mission_and_vehicle_management_mbox(obrttg_mvm_mBox_M,
    obrttg_mvm_mBox_DW.flight_mode_memory_PreviousInput, rtb_Sum,
    &obrttg_mvm_mBox_U.gnc_parameters.gncParameters.waypoints[6 * ((int32_T)(tmp
    + (real_T)obrttg_mvm_mBox_ConstP.pooled9[(uint32_T)rowIdx]) - 1)],
    obrttg_mvm_mBox_U.gnc_parameters.gncParameters.waypoints,
    obrttg_mvm_mBox_U.gnc_parameters.gncParameters.verticalTakeOffVelocity,
    (real_T)obrttg_mvm_mBox_U.gnc_parameters.gncParameters.offlineOtpGeneration,
    rtb_TmpSignalConversionAtmission_and_vehicle_management_mboxInport7,
    &rtb_BusCreator1,
    obrttg_mvm_mBox_U.guidance_output.current_optimal_trajectory,
    obrttg_mvm_mBox_U.otp_output.exit_flag,
    obrttg_mvm_mBox_B.check_computation_completion_svf.computation_done,
    obrttg_mvm_mBox_U.comm_in.mission_status,
    &obrttg_mvm_mBox_B.mission_and_vehicle_management_mbox,
    &obrttg_mvm_mBox_ConstB.mission_and_vehicle_management_mbox,
    &obrttg_mvm_mBox_DW.mission_and_vehicle_management_mbox);

  /* End of Outputs for SubSystem: '<S1>/mission_and_vehicle_management_mbox' */

  /* DataTypeConversion: '<Root>/mvm_cast' incorporates:
   *  BusCreator: '<S5>/Bus Creator1'
   *  Constant: '<S5>/failure_detection'
   *  Inport: '<Root>/gnc_parameters'
   *  Inport: '<Root>/navigation_output'
   *  RelationalOperator: '<S5>/greather_than'
   */
  obrttg_mvm_mBox_Y.mvm_output.mvm_flags[0] =
    obrttg_mvm_mBox_U.navigation_output.retargeting_flag;
  obrttg_mvm_mBox_Y.mvm_output.mvm_flags[1] = 0.0;
  obrttg_mvm_mBox_Y.mvm_output.mvm_flags[2] = (rtb_CastToDouble_a >=
    obrttg_mvm_mBox_U.gnc_parameters.gncParameters.trackingErrorThreshold);

  /* CombinatorialLogic: '<S16>/Logic' incorporates:
   *  Inport: '<Root>/navigation_output'
   *  Memory: '<S16>/Memory'
   */
  rowIdx_0 = (int32_T)(((uint32_T)
                        obrttg_mvm_mBox_U.navigation_output.retargeting_flag <<
                        2) + obrttg_mvm_mBox_DW.Memory_PreviousInput_e);

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   *  Memory: '<S1>/flight_mode_memory'
   */
  rtb_Compare = (obrttg_mvm_mBox_DW.flight_mode_memory_PreviousInput == 2.0);

  /* CombinatorialLogic: '<S17>/Logic' incorporates:
   *  CombinatorialLogic: '<S16>/Logic'
   *  Logic: '<S12>/AND2'
   *  Memory: '<S17>/Memory'
   *  RelationalOperator: '<S15>/FixPt Relational Operator'
   *  UnitDelay: '<S15>/Delay Input1'
   */
  rowIdx_1 = (int32_T)(((uint32_T)(((int32_T)rtb_Compare > (int32_T)
    obrttg_mvm_mBox_DW.DelayInput1_DSTATE) && obrttg_mvm_mBox_ConstP.pooled9
    [(uint32_T)rowIdx_0]) << 1) + obrttg_mvm_mBox_DW.Memory_PreviousInput_a);

  /* BusCreator: '<Root>/Bus Creator' incorporates:
   *  CombinatorialLogic: '<S17>/Logic'
   *  DataTypeConversion: '<S1>/Cast To Double'
   *  Inport: '<Root>/comm_in'
   *  Outport: '<Root>/mvm_output'
   *  SignalConversion generated from: '<Root>/Bus Creator'
   */
  obrttg_mvm_mBox_Y.mvm_output.timestamp = obrttg_mvm_mBox_U.comm_in.timestamp;
  obrttg_mvm_mBox_Y.mvm_output.computation_done =
    obrttg_mvm_mBox_B.check_computation_completion_svf.computation_done;
  obrttg_mvm_mBox_Y.mvm_output.recompute_flag =
    obrttg_mvm_mBox_B.mission_and_vehicle_management_mbox.target_manager_mbox.CastToBoolean;
  memcpy(&obrttg_mvm_mBox_Y.mvm_output.next_target[0],
         &obrttg_mvm_mBox_B.mission_and_vehicle_management_mbox.target_manager_mbox.Merge
         [0], 13U * sizeof(real_T));
  memcpy(&obrttg_mvm_mBox_Y.mvm_output.next_start[0],
         &obrttg_mvm_mBox_B.mission_and_vehicle_management_mbox.target_manager_mbox.Merge
         [13], 17U * sizeof(real_T));
  obrttg_mvm_mBox_Y.mvm_output.mission_phase_id[0] =
    obrttg_mvm_mBox_B.mission_and_vehicle_management_mbox.Merge;
  obrttg_mvm_mBox_Y.mvm_output.mission_phase_id[1] =
    obrttg_mvm_mBox_B.mission_and_vehicle_management_mbox.target_manager_mbox.CastToBoolean2;
  obrttg_mvm_mBox_Y.mvm_output.change_trajectory =
    obrttg_mvm_mBox_B.mission_and_vehicle_management_mbox.target_manager_mbox.CastToBoolean1;
  obrttg_mvm_mBox_Y.mvm_output.retargetOk = obrttg_mvm_mBox_ConstP.pooled9
    [(uint32_T)rowIdx_1];

  /* Update for Memory: '<S1>/recompute_flag_memory' */
  obrttg_mvm_mBox_DW.recompute_flag_memory_PreviousInput =
    obrttg_mvm_mBox_B.mission_and_vehicle_management_mbox.target_manager_mbox.CastToBoolean;

  /* Update for Memory: '<S1>/flight_mode_memory' */
  obrttg_mvm_mBox_DW.flight_mode_memory_PreviousInput =
    obrttg_mvm_mBox_B.mission_and_vehicle_management_mbox.Merge;

  /* Update for Memory: '<S11>/Memory' incorporates:
   *  CombinatorialLogic: '<S11>/Logic'
   */
  obrttg_mvm_mBox_DW.Memory_PreviousInput = obrttg_mvm_mBox_ConstP.pooled9
    [(uint32_T)rowIdx];

  /* Update for Memory: '<S16>/Memory' incorporates:
   *  CombinatorialLogic: '<S16>/Logic'
   */
  obrttg_mvm_mBox_DW.Memory_PreviousInput_e = obrttg_mvm_mBox_ConstP.pooled9
    [(uint32_T)rowIdx_0];

  /* Update for UnitDelay: '<S15>/Delay Input1' */
  obrttg_mvm_mBox_DW.DelayInput1_DSTATE = rtb_Compare;

  /* Update for Memory: '<S17>/Memory' incorporates:
   *  CombinatorialLogic: '<S17>/Logic'
   */
  obrttg_mvm_mBox_DW.Memory_PreviousInput_a = obrttg_mvm_mBox_ConstP.pooled9
    [(uint32_T)rowIdx_1];

  /* Matfile logging */
  rt_UpdateTXYLogVars(obrttg_mvm_mBox_M->rtwLogInfo,
                      (&obrttg_mvm_mBox_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.04s, 0.0s] */
    if ((rtmGetTFinal(obrttg_mvm_mBox_M)!=-1) &&
        !((rtmGetTFinal(obrttg_mvm_mBox_M)-obrttg_mvm_mBox_M->Timing.taskTime0) >
          obrttg_mvm_mBox_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(obrttg_mvm_mBox_M, "Simulation finished");
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
  if (!(++obrttg_mvm_mBox_M->Timing.clockTick0)) {
    ++obrttg_mvm_mBox_M->Timing.clockTickH0;
  }

  obrttg_mvm_mBox_M->Timing.taskTime0 = obrttg_mvm_mBox_M->Timing.clockTick0 *
    obrttg_mvm_mBox_M->Timing.stepSize0 + obrttg_mvm_mBox_M->Timing.clockTickH0 *
    obrttg_mvm_mBox_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void obrttg_mvm_mBox_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)obrttg_mvm_mBox_M, 0,
                sizeof(RT_MODEL_obrttg_mvm_mBox_T));
  rtmSetTFinal(obrttg_mvm_mBox_M, -1);
  obrttg_mvm_mBox_M->Timing.stepSize0 = 0.04;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    obrttg_mvm_mBox_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(obrttg_mvm_mBox_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(obrttg_mvm_mBox_M->rtwLogInfo, (NULL));
    rtliSetLogT(obrttg_mvm_mBox_M->rtwLogInfo, "");
    rtliSetLogX(obrttg_mvm_mBox_M->rtwLogInfo, "");
    rtliSetLogXFinal(obrttg_mvm_mBox_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(obrttg_mvm_mBox_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(obrttg_mvm_mBox_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(obrttg_mvm_mBox_M->rtwLogInfo, 0);
    rtliSetLogDecimation(obrttg_mvm_mBox_M->rtwLogInfo, 1);
    rtliSetLogY(obrttg_mvm_mBox_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(obrttg_mvm_mBox_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(obrttg_mvm_mBox_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &obrttg_mvm_mBox_B), 0,
                sizeof(B_obrttg_mvm_mBox_T));

  /* states (dwork) */
  (void) memset((void *)&obrttg_mvm_mBox_DW, 0,
                sizeof(DW_obrttg_mvm_mBox_T));

  /* external inputs */
  (void)memset(&obrttg_mvm_mBox_U, 0, sizeof(ExtU_obrttg_mvm_mBox_T));

  /* external outputs */
  obrttg_mvm_mBox_Y.mvm_output = obrttg_mvm_mBox_rtZbusGncMvm;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(obrttg_mvm_mBox_M->rtwLogInfo, 0.0,
    rtmGetTFinal(obrttg_mvm_mBox_M), obrttg_mvm_mBox_M->Timing.stepSize0,
    (&rtmGetErrorStatus(obrttg_mvm_mBox_M)));

  /* Start for Probe: '<S18>/Probe Dimension' */
  obrttg_mvm_mBox_B.ProbeDimension[0] = 6.0;
  obrttg_mvm_mBox_B.ProbeDimension[1] = 3.0;

  /* InitializeConditions for Memory: '<S1>/recompute_flag_memory' */
  obrttg_mvm_mBox_DW.recompute_flag_memory_PreviousInput = false;

  /* InitializeConditions for Memory: '<S1>/flight_mode_memory' */
  obrttg_mvm_mBox_DW.flight_mode_memory_PreviousInput = 0.0;

  /* InitializeConditions for Memory: '<S11>/Memory' */
  obrttg_mvm_mBox_DW.Memory_PreviousInput = false;

  /* InitializeConditions for Memory: '<S16>/Memory' */
  obrttg_mvm_mBox_DW.Memory_PreviousInput_e = false;

  /* InitializeConditions for UnitDelay: '<S15>/Delay Input1' */
  obrttg_mvm_mBox_DW.DelayInput1_DSTATE = false;

  /* InitializeConditions for Memory: '<S17>/Memory' */
  obrttg_mvm_mBox_DW.Memory_PreviousInput_a = true;

  /* SystemInitialize for Atomic SubSystem: '<S2>/check_computation_completion_svf' */
  obrttg_mvm_mBox_check_computation_completion_svf_Init
    (&obrttg_mvm_mBox_DW.check_computation_completion_svf);

  /* End of SystemInitialize for SubSystem: '<S2>/check_computation_completion_svf' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/mission_and_vehicle_management_mbox' */
  obrttg_mvm_mBox_mission_and_vehicle_management_mbox_Init
    (&obrttg_mvm_mBox_B.mission_and_vehicle_management_mbox,
     &obrttg_mvm_mBox_DW.mission_and_vehicle_management_mbox);

  /* End of SystemInitialize for SubSystem: '<S1>/mission_and_vehicle_management_mbox' */
}

/* Model terminate function */
void obrttg_mvm_mBox_terminate(void)
{
  /* (no terminate code required) */
}

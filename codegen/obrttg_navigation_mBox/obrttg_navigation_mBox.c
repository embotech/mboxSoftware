/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/*
 * obrttg_navigation_mBox.c
 *
 * Code generation for model "obrttg_navigation_mBox".
 *
 * Model version              : 1.540
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Mar 30 19:37:49 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "obrttg_navigation_mBox.h"
#include "obrttg_navigation_mBox_private.h"

const busGncNavigation obrttg_navigation_mBox_rtZbusGncNavigation = {
  0.0,                                 /* timestamp */

  {
    0.0, 0.0, 0.0 }
  ,                                    /* position */

  {
    0.0, 0.0, 0.0 }
  ,                                    /* velocity */

  {
    0.0, 0.0, 0.0, 0.0 }
  ,                                    /* attitude */

  {
    0.0, 0.0, 0.0 }
  ,                                    /* rates */
  0.0,                                 /* mass */

  {
    0.0, 0.0, 0.0 }
  ,                                    /* CoM */
  false                                /* retargeting_flag */
} ;                                    /* busGncNavigation ground */

/* External inputs (root inport signals with default storage) */
ExtU_obrttg_navigation_mBox_T obrttg_navigation_mBox_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_obrttg_navigation_mBox_T obrttg_navigation_mBox_Y;

/* Real-time model */
RT_MODEL_obrttg_navigation_mBox_T obrttg_navigation_mBox_M_;
RT_MODEL_obrttg_navigation_mBox_T *const obrttg_navigation_mBox_M =
  &obrttg_navigation_mBox_M_;

/* Model step function */
void obrttg_navigation_mBox_step(void)
{
  real_T rtb_Sum;

  /* Sum: '<S2>/Sum' incorporates:
   *  DigitalClock: '<S2>/Digital Clock3'
   *  Inport: '<Root>/gnc_parameters'
   */
  rtb_Sum = obrttg_navigation_mBox_M->Timing.taskTime0 -
    obrttg_navigation_mBox_U.gnc_parameters.validOptionParameters.retargetingEventTime;

  /* Outport: '<Root>/navigation_output' incorporates:
   *  BusCreator: '<Root>/Bus Creator'
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/comm_in'
   *  Inport: '<Root>/gnc_parameters'
   *  Logic: '<S2>/Logical Operator'
   *  Logic: '<S4>/FixPt Logical Operator'
   *  RelationalOperator: '<S3>/Compare'
   *  RelationalOperator: '<S4>/Lower Test'
   *  RelationalOperator: '<S4>/Upper Test'
   */
  obrttg_navigation_mBox_Y.navigation_output.timestamp =
    obrttg_navigation_mBox_U.comm_in.timestamp;
  obrttg_navigation_mBox_Y.navigation_output.position[0] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[0];
  obrttg_navigation_mBox_Y.navigation_output.velocity[0] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[3];
  obrttg_navigation_mBox_Y.navigation_output.position[1] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[1];
  obrttg_navigation_mBox_Y.navigation_output.velocity[1] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[4];
  obrttg_navigation_mBox_Y.navigation_output.position[2] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[2];
  obrttg_navigation_mBox_Y.navigation_output.velocity[2] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[5];
  obrttg_navigation_mBox_Y.navigation_output.attitude[0] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[6];
  obrttg_navigation_mBox_Y.navigation_output.attitude[1] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[7];
  obrttg_navigation_mBox_Y.navigation_output.attitude[2] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[8];
  obrttg_navigation_mBox_Y.navigation_output.attitude[3] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[9];
  obrttg_navigation_mBox_Y.navigation_output.mass =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[13];
  obrttg_navigation_mBox_Y.navigation_output.rates[0] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[10];
  obrttg_navigation_mBox_Y.navigation_output.CoM[0] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[14];
  obrttg_navigation_mBox_Y.navigation_output.rates[1] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[11];
  obrttg_navigation_mBox_Y.navigation_output.CoM[1] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[15];
  obrttg_navigation_mBox_Y.navigation_output.rates[2] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[12];
  obrttg_navigation_mBox_Y.navigation_output.CoM[2] =
    obrttg_navigation_mBox_U.comm_in.vehicle_state[16];
  obrttg_navigation_mBox_Y.navigation_output.retargeting_flag =
    ((obrttg_navigation_mBox_ConstB.Gain1 <= rtb_Sum) && (rtb_Sum <=
      obrttg_navigation_mBox_ConstB.Gain) &&
     (obrttg_navigation_mBox_U.gnc_parameters.validOptionParameters.retargetingEventTime
      > 0.0));

  /* Matfile logging */
  rt_UpdateTXYLogVars(obrttg_navigation_mBox_M->rtwLogInfo,
                      (&obrttg_navigation_mBox_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.04s, 0.0s] */
    if ((rtmGetTFinal(obrttg_navigation_mBox_M)!=-1) &&
        !((rtmGetTFinal(obrttg_navigation_mBox_M)-
           obrttg_navigation_mBox_M->Timing.taskTime0) >
          obrttg_navigation_mBox_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(obrttg_navigation_mBox_M, "Simulation finished");
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
  if (!(++obrttg_navigation_mBox_M->Timing.clockTick0)) {
    ++obrttg_navigation_mBox_M->Timing.clockTickH0;
  }

  obrttg_navigation_mBox_M->Timing.taskTime0 =
    obrttg_navigation_mBox_M->Timing.clockTick0 *
    obrttg_navigation_mBox_M->Timing.stepSize0 +
    obrttg_navigation_mBox_M->Timing.clockTickH0 *
    obrttg_navigation_mBox_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void obrttg_navigation_mBox_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)obrttg_navigation_mBox_M, 0,
                sizeof(RT_MODEL_obrttg_navigation_mBox_T));
  rtmSetTFinal(obrttg_navigation_mBox_M, -1);
  obrttg_navigation_mBox_M->Timing.stepSize0 = 0.04;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    obrttg_navigation_mBox_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(obrttg_navigation_mBox_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(obrttg_navigation_mBox_M->rtwLogInfo, (NULL));
    rtliSetLogT(obrttg_navigation_mBox_M->rtwLogInfo, "");
    rtliSetLogX(obrttg_navigation_mBox_M->rtwLogInfo, "");
    rtliSetLogXFinal(obrttg_navigation_mBox_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(obrttg_navigation_mBox_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(obrttg_navigation_mBox_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(obrttg_navigation_mBox_M->rtwLogInfo, 0);
    rtliSetLogDecimation(obrttg_navigation_mBox_M->rtwLogInfo, 1);
    rtliSetLogY(obrttg_navigation_mBox_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(obrttg_navigation_mBox_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(obrttg_navigation_mBox_M->rtwLogInfo, (NULL));
  }

  /* external inputs */
  (void)memset(&obrttg_navigation_mBox_U, 0, sizeof
               (ExtU_obrttg_navigation_mBox_T));

  /* external outputs */
  obrttg_navigation_mBox_Y.navigation_output =
    obrttg_navigation_mBox_rtZbusGncNavigation;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(obrttg_navigation_mBox_M->rtwLogInfo, 0.0,
    rtmGetTFinal(obrttg_navigation_mBox_M),
    obrttg_navigation_mBox_M->Timing.stepSize0, (&rtmGetErrorStatus
    (obrttg_navigation_mBox_M)));
}

/* Model terminate function */
void obrttg_navigation_mBox_terminate(void)
{
  /* (no terminate code required) */
}

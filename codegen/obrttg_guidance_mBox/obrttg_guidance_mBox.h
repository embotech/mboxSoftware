/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/*
 * obrttg_guidance_mBox.h
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

#ifndef RTW_HEADER_obrttg_guidance_mBox_h_
#define RTW_HEADER_obrttg_guidance_mBox_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef obrttg_guidance_mBox_COMMON_INCLUDES_
# define obrttg_guidance_mBox_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                               /* obrttg_guidance_mBox_COMMON_INCLUDES_ */

#include "obrttg_guidance_mBox_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T output_trajectory[540];       /* '<S14>/MATLAB Function' */
  real_T time_to_go;                   /* '<S1>/Merge' */
  real_T state_error[13];              /* '<S1>/Merge' */
  real_T guidance_reference[17];       /* '<S1>/Merge' */
  real_T DiscreteTimeIntegrator;       /* '<S5>/Discrete-Time Integrator' */
} B_obrttg_guidance_mBox_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S5>/Discrete-Time Integrator' */
  real_T Memory_PreviousInput[1080];   /* '<S14>/Memory' */
  boolean_T DelayInput1_DSTATE;        /* '<S17>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_h;      /* '<S16>/Delay Input1' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S5>/Discrete-Time Integrator' */
} DW_obrttg_guidance_mBox_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  busGncParameters gnc_parameters;     /* '<Root>/gnc_parameters' */
  busGncCommIn comm_in;                /* '<Root>/comm_in' */
  busGncNavigation navigation_output;  /* '<Root>/navigation_output' */
  busGncMvm mvm_output;                /* '<Root>/mvm_output' */
  busGncController controller_output;  /* '<Root>/controller_output' */
  busGncOtp otp_output;                /* '<Root>/otp_output' */
} ExtU_obrttg_guidance_mBox_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  busGncGuidance guidance_output;      /* '<Root>/guidance_output' */
} ExtY_obrttg_guidance_mBox_T;

/* Real-time Model Data Structure */
struct tag_RTM_obrttg_guidance_mBox_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_obrttg_guidance_mBox_T obrttg_guidance_mBox_B;

/* Block states (default storage) */
extern DW_obrttg_guidance_mBox_T obrttg_guidance_mBox_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_obrttg_guidance_mBox_T obrttg_guidance_mBox_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_obrttg_guidance_mBox_T obrttg_guidance_mBox_Y;

/* External data declarations for dependent source files */
extern const busGncGuidance obrttg_guidance_mBox_rtZbusGncGuidance;/* busGncGuidance ground */

/* Model entry point functions */
extern void obrttg_guidance_mBox_initialize(void);
extern void obrttg_guidance_mBox_step(void);
extern void obrttg_guidance_mBox_terminate(void);

/* Real-time Model object */
extern RT_MODEL_obrttg_guidance_mBox_T *const obrttg_guidance_mBox_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'obrttg_guidance_mBox'
 * '<S1>'   : 'obrttg_guidance_mBox/3dof_guidance'
 * '<S2>'   : 'obrttg_guidance_mBox/3dof_guidance/embotech guidance'
 * '<S3>'   : 'obrttg_guidance_mBox/3dof_guidance/enabled_idle_mode'
 * '<S4>'   : 'obrttg_guidance_mBox/3dof_guidance/trajectory_queuing'
 * '<S5>'   : 'obrttg_guidance_mBox/3dof_guidance/embotech guidance/Interpolation'
 * '<S6>'   : 'obrttg_guidance_mBox/3dof_guidance/embotech guidance/compute_state_error'
 * '<S7>'   : 'obrttg_guidance_mBox/3dof_guidance/embotech guidance/Interpolation/calculate_remaining_trajectory_time'
 * '<S8>'   : 'obrttg_guidance_mBox/3dof_guidance/embotech guidance/compute_state_error/quaternion_error'
 * '<S9>'   : 'obrttg_guidance_mBox/3dof_guidance/embotech guidance/compute_state_error/quaternion_error/conjugate_quaternion'
 * '<S10>'  : 'obrttg_guidance_mBox/3dof_guidance/embotech guidance/compute_state_error/quaternion_error/multiply_quaternions'
 * '<S11>'  : 'obrttg_guidance_mBox/3dof_guidance/embotech guidance/compute_state_error/quaternion_error/normalize_quaternion'
 * '<S12>'  : 'obrttg_guidance_mBox/3dof_guidance/embotech guidance/compute_state_error/quaternion_error/multiply_quaternions/multiply_quaternions'
 * '<S13>'  : 'obrttg_guidance_mBox/3dof_guidance/embotech guidance/compute_state_error/quaternion_error/normalize_quaternion/normalize_quaternion'
 * '<S14>'  : 'obrttg_guidance_mBox/3dof_guidance/trajectory_queuing/trajectory_fifo'
 * '<S15>'  : 'obrttg_guidance_mBox/3dof_guidance/trajectory_queuing/write if ok'
 * '<S16>'  : 'obrttg_guidance_mBox/3dof_guidance/trajectory_queuing/trajectory_fifo/Detect pop increase'
 * '<S17>'  : 'obrttg_guidance_mBox/3dof_guidance/trajectory_queuing/trajectory_fifo/Detect push increase'
 * '<S18>'  : 'obrttg_guidance_mBox/3dof_guidance/trajectory_queuing/trajectory_fifo/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_obrttg_guidance_mBox_h_ */

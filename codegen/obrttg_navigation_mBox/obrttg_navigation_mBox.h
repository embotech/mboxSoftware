/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/*
 * obrttg_navigation_mBox.h
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

#ifndef RTW_HEADER_obrttg_navigation_mBox_h_
#define RTW_HEADER_obrttg_navigation_mBox_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef obrttg_navigation_mBox_COMMON_INCLUDES_
# define obrttg_navigation_mBox_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                             /* obrttg_navigation_mBox_COMMON_INCLUDES_ */

#include "obrttg_navigation_mBox_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

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

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Gain;                   /* '<S2>/Gain' */
  const real_T Gain1;                  /* '<S2>/Gain1' */
} ConstB_obrttg_navigation_mBox_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  busGncParameters gnc_parameters;     /* '<Root>/gnc_parameters' */
  busGncCommIn comm_in;                /* '<Root>/comm_in' */
  busGncMvm mvm_output;                /* '<Root>/mvm_output' */
  busGncGuidance guidance_output;      /* '<Root>/guidance_output' */
  busGncController controller_output;  /* '<Root>/controller_output' */
} ExtU_obrttg_navigation_mBox_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  busGncNavigation navigation_output;  /* '<Root>/navigation_output' */
} ExtY_obrttg_navigation_mBox_T;

/* Real-time Model Data Structure */
struct tag_RTM_obrttg_navigation_mBox_T {
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

/* External inputs (root inport signals with default storage) */
extern ExtU_obrttg_navigation_mBox_T obrttg_navigation_mBox_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_obrttg_navigation_mBox_T obrttg_navigation_mBox_Y;

/* External data declarations for dependent source files */
extern const busGncNavigation obrttg_navigation_mBox_rtZbusGncNavigation;/* busGncNavigation ground */
extern const ConstB_obrttg_navigation_mBox_T obrttg_navigation_mBox_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void obrttg_navigation_mBox_initialize(void);
extern void obrttg_navigation_mBox_step(void);
extern void obrttg_navigation_mBox_terminate(void);

/* Real-time Model object */
extern RT_MODEL_obrttg_navigation_mBox_T *const obrttg_navigation_mBox_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/FixPt Data Type Duplicate' : Unused code path elimination
 */

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
 * '<Root>' : 'obrttg_navigation_mBox'
 * '<S1>'   : 'obrttg_navigation_mBox/generate_retargeting_cmd'
 * '<S2>'   : 'obrttg_navigation_mBox/generate_retargeting_cmd/time_instant_detector_software'
 * '<S3>'   : 'obrttg_navigation_mBox/generate_retargeting_cmd/time_instant_detector_software/Compare To Zero'
 * '<S4>'   : 'obrttg_navigation_mBox/generate_retargeting_cmd/time_instant_detector_software/Interval Test Dynamic'
 */
#endif                                /* RTW_HEADER_obrttg_navigation_mBox_h_ */

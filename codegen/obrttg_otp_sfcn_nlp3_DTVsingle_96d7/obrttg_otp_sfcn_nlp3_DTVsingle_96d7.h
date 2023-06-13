/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 *
 * obrttg_otp_sfcn_nlp3_DTVsingle_96d7.h
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

#ifndef RTW_HEADER_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_h_
#define RTW_HEADER_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef obrttg_otp_sfcn_nlp3_DTVsingle_96d7_COMMON_INCLUDES_
# define obrttg_otp_sfcn_nlp3_DTVsingle_96d7_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                /* obrttg_otp_sfcn_nlp3_DTVsingle_96d7_COMMON_INCLUDES_ */

#include "obrttg_otp_sfcn_nlp3_DTVsingle_96d7_types.h"

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

/* Block signals (default storage) */
typedef struct {
  real_T TmpSignalConversionAtnlp3_DTVsingle_96d7_parserInport4[2];/* '<S3>/compute_control_limits' */
  real_T TmpSignalConversionAtnlp3_DTVsingle_96d7_parserInport5[2];/* '<S3>/compute_control_limits' */
  real_T nlp3_DTVsingle_96d7_x0_generator[446];
                                   /* '<S3>/nlp3_DTVsingle_96d7_x0_generator' */
  real_T nlp3_DTVsingle_96d7_parser_o1[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o2[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o3[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o4[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o5[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o6[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o7[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o8[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o9[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o10[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o11[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o12[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o13[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o14[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o15[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o16[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o17[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o18[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o19[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o20[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o21[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o22[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o23[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o24[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o25[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o26[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o27[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o28[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o29[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o30[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o31[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o32[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o33[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o34[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o35[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o36[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o37[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o38[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o39[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o40[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o41[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o42[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o43[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o44[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o45[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o46[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o47[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o48[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o49[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o50[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o51[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o52[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o53[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o54[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o55[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o56[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o57[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o58[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o59[6];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o60[3];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o61[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o62[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o63[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o64[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o65[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o66[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o67[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o68[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o69[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o70[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o71[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o72[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o73[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o74[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o75[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o76[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o77[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o78[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o79[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o80[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o81[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o82[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o83[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o84[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o85[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o86[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o87[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o88[4];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o89[446];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o90[7];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o91[180];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_parser_o92[30];/* '<S3>/nlp3_DTVsingle_96d7_parser' */
  real_T nlp3_DTVsingle_96d7_solver_o1[446];/* '<S3>/nlp3_DTVsingle_96d7_solver' */
  real_T nlp3_DTVsingle_96d7_solver_o2;/* '<S3>/nlp3_DTVsingle_96d7_solver' */
  real_T nlp3_DTVsingle_96d7_solver_o3;/* '<S3>/nlp3_DTVsingle_96d7_solver' */
  real_T nlp3_DTVsingle_96d7_solver_o4;/* '<S3>/nlp3_DTVsingle_96d7_solver' */
  real_T nlp3_DTVsingle_96d7_solver_o5;/* '<S3>/nlp3_DTVsingle_96d7_solver' */
  real_T nlp3_DTVsingle_96d7_solver_o6;/* '<S3>/nlp3_DTVsingle_96d7_solver' */
  real_T optimal_trajectory[540]; /* '<S3>/nlp3_DTVsingle_96d7_postprocessor' */
} B_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S3>/Memory' */
} DW_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  busGncParameters gnc_parameters;     /* '<Root>/gnc_parameters' */
  busGncCommIn comm_in;                /* '<Root>/comm_in' */
  busGncMvm mvm_output;                /* '<Root>/mvm_output' */
  busGncGuidance guidance_in;          /* '<Root>/guidance_in' */
} ExtU_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  busGncOtp otp_output;                /* '<Root>/otp_output' */
} ExtY_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T;

/* Real-time Model Data Structure */
struct tag_RTM_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T {
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
extern B_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T
  obrttg_otp_sfcn_nlp3_DTVsingle_96d7_B;

/* Block states (default storage) */
extern DW_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T
  obrttg_otp_sfcn_nlp3_DTVsingle_96d7_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T
  obrttg_otp_sfcn_nlp3_DTVsingle_96d7_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T
  obrttg_otp_sfcn_nlp3_DTVsingle_96d7_Y;

/* External data declarations for dependent source files */
extern const busGncOtp obrttg_otp_sfcn_nlp3_DTVsingle_96d7_rtZbusGncOtp;/* busGncOtp ground */

/* Model entry point functions */
extern void obrttg_otp_sfcn_nlp3_DTVsingle_96d7_initialize(void);
extern void obrttg_otp_sfcn_nlp3_DTVsingle_96d7_step(void);
extern void obrttg_otp_sfcn_nlp3_DTVsingle_96d7_terminate(void);

/* Real-time Model object */
extern RT_MODEL_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T *const
  obrttg_otp_sfcn_nlp3_DTVsingle_96d7_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Signal Conversion' : Eliminate redundant signal conversion block
 * Block '<S3>/Signal Conversion1' : Eliminate redundant signal conversion block
 * Block '<S3>/Signal Conversion2' : Eliminate redundant signal conversion block
 * Block '<S3>/Signal Conversion3' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'obrttg_otp_sfcn_nlp3_DTVsingle_96d7'
 * '<S1>'   : 'obrttg_otp_sfcn_nlp3_DTVsingle_96d7/triggered_otp'
 * '<S2>'   : 'obrttg_otp_sfcn_nlp3_DTVsingle_96d7/triggered_otp/create_otp_info_bus'
 * '<S3>'   : 'obrttg_otp_sfcn_nlp3_DTVsingle_96d7/triggered_otp/otp'
 * '<S4>'   : 'obrttg_otp_sfcn_nlp3_DTVsingle_96d7/triggered_otp/otp/compute_control_limits'
 * '<S5>'   : 'obrttg_otp_sfcn_nlp3_DTVsingle_96d7/triggered_otp/otp/compute_control_limits/compute_control_limits_1_eng'
 */
#endif                   /* RTW_HEADER_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_h_ */

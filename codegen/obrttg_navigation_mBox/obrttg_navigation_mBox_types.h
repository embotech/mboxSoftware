/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/*
 * obrttg_navigation_mBox_types.h
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

#ifndef RTW_HEADER_obrttg_navigation_mBox_types_h_
#define RTW_HEADER_obrttg_navigation_mBox_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_busMboxParameters_
#define DEFINED_TYPEDEF_FOR_busMboxParameters_

typedef struct {
  real_T trackingErrorThreshold;
  real_T waypoints[18];
  real_T takeOffHeight;
  real_T verticalTakeOffVelocity[3];
  boolean_T offlineOtpGeneration;
  real_T launchPadPosition[3];
  real_T maxSpeedConstraint;
  real_T tiltAngleConstraint;
  real_T glideSlopeAngleConstraint;
} busMboxParameters;

#endif

#ifndef DEFINED_TYPEDEF_FOR_busValidationOptions_
#define DEFINED_TYPEDEF_FOR_busValidationOptions_

typedef struct {
  real_T retargetingEventTime;
} busValidationOptions;

#endif

#ifndef DEFINED_TYPEDEF_FOR_busGncParameters_
#define DEFINED_TYPEDEF_FOR_busGncParameters_

typedef struct {
  busMboxParameters gncParameters;
  busValidationOptions validOptionParameters;
} busGncParameters;

#endif

#ifndef DEFINED_TYPEDEF_FOR_busGncCommIn_
#define DEFINED_TYPEDEF_FOR_busGncCommIn_

typedef struct {
  real_T timestamp_obc;
  real_T timestamp;
  real_T mission_status;
  real_T vehicle_state[17];
  real_T engine_status[16];
} busGncCommIn;

#endif

#ifndef DEFINED_TYPEDEF_FOR_busGncMvm_
#define DEFINED_TYPEDEF_FOR_busGncMvm_

typedef struct {
  real_T timestamp;
  real_T computation_done;
  boolean_T recompute_flag;
  real_T next_target[13];
  real_T next_start[17];
  real_T mission_phase_id[2];
  boolean_T change_trajectory;
  real_T mvm_flags[3];
  boolean_T retargetOk;
} busGncMvm;

#endif

#ifndef DEFINED_TYPEDEF_FOR_busGncGuidance_
#define DEFINED_TYPEDEF_FOR_busGncGuidance_

typedef struct {
  real_T timestamp;
  real_T time_to_go;
  real_T state_error[13];
  real_T guidance_reference[17];
  real_T current_optimal_trajectory[540];
} busGncGuidance;

#endif

#ifndef DEFINED_TYPEDEF_FOR_busGncController_
#define DEFINED_TYPEDEF_FOR_busGncController_

typedef struct {
  real_T timestamp;
  real_T cmd_propulsion[5];
  real_T engine_on;
} busGncController;

#endif

#ifndef DEFINED_TYPEDEF_FOR_busGncNavigation_
#define DEFINED_TYPEDEF_FOR_busGncNavigation_

typedef struct {
  real_T timestamp;
  real_T position[3];
  real_T velocity[3];
  real_T attitude[4];
  real_T rates[3];
  real_T mass;
  real_T CoM[3];
  boolean_T retargeting_flag;
} busGncNavigation;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_obrttg_navigation_mBox_T
  RT_MODEL_obrttg_navigation_mBox_T;

#endif                          /* RTW_HEADER_obrttg_navigation_mBox_types_h_ */

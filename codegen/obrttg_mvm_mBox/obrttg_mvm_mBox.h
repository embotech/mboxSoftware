/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/*
 * obrttg_mvm_mBox.h
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

#ifndef RTW_HEADER_obrttg_mvm_mBox_h_
#define RTW_HEADER_obrttg_mvm_mBox_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef obrttg_mvm_mBox_COMMON_INCLUDES_
# define obrttg_mvm_mBox_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* obrttg_mvm_mBox_COMMON_INCLUDES_ */

#include "obrttg_mvm_mBox_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
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

/* Block signals for system '<S2>/check_computation_completion_svf' */
typedef struct {
  real_T computation_done;             /* '<S7>/Sum' */
} B_check_computation_completion_svf_obrttg_mvm_mBox_T;

/* Block states (default storage) for system '<S2>/check_computation_completion_svf' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S6>/Delay' */
  boolean_T Memory_PreviousInput;      /* '<S8>/Memory' */
  boolean_T Memory_PreviousInput_f;    /* '<S9>/Memory' */
} DW_check_computation_completion_svf_obrttg_mvm_mBox_T;

/* Block signals for system '<S45>/manage_startup_mbox' */
typedef struct {
  real_T nextTarget[13];               /* '<S89>/manage_startup' */
  real_T nextStart[17];                /* '<S89>/manage_startup' */
  real_T recomputeFlag;                /* '<S89>/manage_startup' */
  real_T switchTrajectory;             /* '<S89>/manage_startup' */
} B_manage_startup_mbox_obrttg_mvm_mBox_T;

/* Block signals for system '<S49>/get_next_start' */
typedef struct {
  real_T nextStart[17];                /* '<S54>/get_next_start' */
} B_get_next_start_obrttg_mvm_mBox_T;

/* Block signals for system '<S49>/get_prediction_time' */
typedef struct {
  real_T sel_prediction_time;          /* '<S55>/sel_prediction_time' */
} B_get_prediction_time_obrttg_mvm_mBox_T;

/* Block signals for system '<S49>/get_propagate_flag' */
typedef struct {
  real_T Selector;                     /* '<S56>/Selector' */
} B_get_propagate_flag_obrttg_mvm_mBox_T;

/* Block signals for system '<S50>/get_next_target_idx' */
typedef struct {
  real_T nextTargetIdx;                /* '<S58>/Sum1' */
} B_get_next_target_idx_obrttg_mvm_mBox_T;

/* Block states (default storage) for system '<S50>/get_next_target_idx' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S60>/Delay Input1' */
  real_T DelayInput1_DSTATE_n;         /* '<S61>/Delay Input1' */
} DW_get_next_target_idx_obrttg_mvm_mBox_T;

/* Block signals for system '<S51>/manage_computations' */
typedef struct {
  real_T requestID;                    /* '<S63>/manage_computations' */
  real_T nAttemptsOut;                 /* '<S63>/manage_computations' */
} B_manage_computations_obrttg_mvm_mBox_T;

/* Block signals for system '<S51>/merge_request_flags' */
typedef struct {
  real_T request_flags_cast[5];        /* '<S64>/request_flags_cast' */
} B_merge_request_flags_obrttg_mvm_mBox_T;

/* Block signals for system '<S51>/update_request_flag' */
typedef struct {
  real_T Multiply[5];                  /* '<S66>/Multiply' */
} B_update_request_flag_obrttg_mvm_mBox_T;

/* Block signals for system '<S48>/manage_trajectory_switch' */
typedef struct {
  real_T switchFlag_cast;              /* '<S52>/switchFlag_cast' */
  real_T emergencyFlag;                /* '<S52>/manage_trajectory_switch' */
} B_manage_trajectory_switch_obrttg_mvm_mBox_T;

/* Block states (default storage) for system '<S48>/manage_trajectory_switch' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S70>/Delay Input1' */
} DW_manage_trajectory_switch_obrttg_mvm_mBox_T;

/* Block signals for system '<S53>/manage_failure_request' */
typedef struct {
  real_T requestFlag;                  /* '<S76>/manage_failure_request' */
  real_T emergencyFlag;                /* '<S76>/manage_failure_request' */
} B_manage_failure_request_obrttg_mvm_mBox_T;

/* Block signals for system '<S53>/manage_long_trajectory_request' */
typedef struct {
  real_T requestFlag;               /* '<S77>/manage_long_trajectory_request' */
} B_manage_long_trajectory_request_obrttg_mvm_mBox_T;

/* Block signals for system '<S53>/manage_nominal_request' */
typedef struct {
  real_T requestFlag;                  /* '<S78>/manage_nominal_request' */
} B_manage_nominal_request_obrttg_mvm_mBox_T;

/* Block signals for system '<S53>/manage_retargeting_request' */
typedef struct {
  real_T requestFlag;                  /* '<S79>/manage_retargeting_request' */
} B_manage_retargeting_request_obrttg_mvm_mBox_T;

/* Block signals for system '<S53>/manage_tracking_error_request' */
typedef struct {
  real_T requestFlag;                /* '<S80>/manage_tracking_error_request' */
} B_manage_tracking_error_request_obrttg_mvm_mBox_T;

/* Block signals for system '<S44>/manage_optimal_guidance_mbox' */
typedef struct {
  real_T ProbeDimension[2];            /* '<S82>/Probe Dimension' */
  real_T ProbeDimension_k[2];          /* '<S83>/Probe Dimension' */
  real_T sel_WP[6];                    /* '<S59>/sel_WP' */
  real_T emergencyFlag_cast;           /* '<S48>/emergencyFlag_cast' */
  real_T compute_flag_cast;            /* '<S62>/compute_flag_cast' */
  real_T Sum1;                         /* '<S49>/Sum1' */
  B_manage_tracking_error_request_obrttg_mvm_mBox_T
    manage_tracking_error_request;   /* '<S53>/manage_tracking_error_request' */
  B_manage_retargeting_request_obrttg_mvm_mBox_T manage_retargeting_request;/* '<S53>/manage_retargeting_request' */
  B_manage_nominal_request_obrttg_mvm_mBox_T manage_nominal_request;/* '<S53>/manage_nominal_request' */
  B_manage_long_trajectory_request_obrttg_mvm_mBox_T
    manage_long_trajectory_request; /* '<S53>/manage_long_trajectory_request' */
  B_manage_failure_request_obrttg_mvm_mBox_T manage_failure_request;/* '<S53>/manage_failure_request' */
  B_manage_trajectory_switch_obrttg_mvm_mBox_T manage_trajectory_switch;/* '<S48>/manage_trajectory_switch' */
  B_update_request_flag_obrttg_mvm_mBox_T update_request_flag;/* '<S51>/update_request_flag' */
  B_merge_request_flags_obrttg_mvm_mBox_T merge_request_flags;/* '<S51>/merge_request_flags' */
  B_manage_computations_obrttg_mvm_mBox_T manage_computations;/* '<S51>/manage_computations' */
  B_get_next_target_idx_obrttg_mvm_mBox_T get_next_target_idx;/* '<S50>/get_next_target_idx' */
  B_get_propagate_flag_obrttg_mvm_mBox_T get_propagate_flag;/* '<S49>/get_propagate_flag' */
  B_get_prediction_time_obrttg_mvm_mBox_T get_prediction_time;/* '<S49>/get_prediction_time' */
  B_get_next_start_obrttg_mvm_mBox_T get_next_start;/* '<S49>/get_next_start' */
} B_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T;

/* Block states (default storage) for system '<S44>/manage_optimal_guidance_mbox' */
typedef struct {
  real_T compute_flag_memory_PreviousInput;/* '<S51>/compute_flag_memory' */
  real_T request_flags_memory_PreviousInput[5];/* '<S51>/request_flags_memory' */
  real_T switch_flag_memory_PreviousInput;/* '<S48>/switch_flag_memory' */
  real_T n_attempts_memory_PreviousInput;/* '<S51>/n_attempts_memory' */
  boolean_T get_next_start_point_MODE; /* '<S48>/get_next_start_point' */
  DW_manage_trajectory_switch_obrttg_mvm_mBox_T manage_trajectory_switch;/* '<S48>/manage_trajectory_switch' */
  DW_get_next_target_idx_obrttg_mvm_mBox_T get_next_target_idx;/* '<S50>/get_next_target_idx' */
} DW_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T;

/* Block signals for system '<S4>/target_manager_mbox' */
typedef struct {
  real_T Merge[33];                    /* '<S21>/Merge' */
  real_T DiscreteTimeIntegrator;       /* '<S46>/Discrete-Time Integrator' */
  boolean_T CastToBoolean;             /* '<S21>/Cast To Boolean' */
  boolean_T CastToBoolean1;            /* '<S21>/Cast To Boolean1' */
  boolean_T CastToBoolean2;            /* '<S21>/Cast To Boolean2' */
  B_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T manage_optimal_guidance_mbox;
                                      /* '<S44>/manage_optimal_guidance_mbox' */
  B_manage_startup_mbox_obrttg_mvm_mBox_T manage_startup_mbox;/* '<S45>/manage_startup_mbox' */
} B_target_manager_mbox_obrttg_mvm_mBox_T;

/* Block states (default storage) for system '<S4>/target_manager_mbox' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S46>/Discrete-Time Integrator' */
  real_T Memory_PreviousInput[13];     /* '<S21>/Memory' */
  real_T target_idx_memory_PreviousInput;/* '<S44>/target_idx_memory' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S21>/Switch Case' */
  DW_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T manage_optimal_guidance_mbox;
                                      /* '<S44>/manage_optimal_guidance_mbox' */
} DW_target_manager_mbox_obrttg_mvm_mBox_T;

/* Block signals for system '<S1>/mission_and_vehicle_management_mbox' */
typedef struct {
  real_T Merge;                        /* '<S19>/Merge' */
  B_target_manager_mbox_obrttg_mvm_mBox_T target_manager_mbox;/* '<S4>/target_manager_mbox' */
} B_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T;

/* Block states (default storage) for system '<S1>/mission_and_vehicle_management_mbox' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S33>/Delay Input1' */
  real_T next_target_memory_PreviousInput[13];/* '<S4>/next_target_memory' */
  boolean_T Memory_PreviousInput;      /* '<S34>/Memory' */
  boolean_T Memory1_PreviousInput;     /* '<S4>/Memory1' */
  DW_target_manager_mbox_obrttg_mvm_mBox_T target_manager_mbox;/* '<S4>/target_manager_mbox' */
} DW_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T;

/* Block signals (default storage) */
typedef struct {
  real_T ProbeDimension[2];            /* '<S18>/Probe Dimension' */
  B_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T
    mission_and_vehicle_management_mbox;
                                /* '<S1>/mission_and_vehicle_management_mbox' */
  B_check_computation_completion_svf_obrttg_mvm_mBox_T
    check_computation_completion_svf;
                                   /* '<S2>/check_computation_completion_svf' */
} B_obrttg_mvm_mBox_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T flight_mode_memory_PreviousInput;/* '<S1>/flight_mode_memory' */
  boolean_T DelayInput1_DSTATE;        /* '<S15>/Delay Input1' */
  boolean_T recompute_flag_memory_PreviousInput;/* '<S1>/recompute_flag_memory' */
  boolean_T Memory_PreviousInput;      /* '<S11>/Memory' */
  boolean_T Memory_PreviousInput_e;    /* '<S16>/Memory' */
  boolean_T Memory_PreviousInput_a;    /* '<S17>/Memory' */
  DW_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T
    mission_and_vehicle_management_mbox;
                                /* '<S1>/mission_and_vehicle_management_mbox' */
  DW_check_computation_completion_svf_obrttg_mvm_mBox_T
    check_computation_completion_svf;
                                   /* '<S2>/check_computation_completion_svf' */
} DW_obrttg_mvm_mBox_T;

/* Invariant block signals for system '<S44>/manage_optimal_guidance_mbox' */
typedef struct {
  const real_T target_attitude[4];     /* '<S59>/target_attitude' */
  const real_T target_rates[3];        /* '<S59>/target_rates' */
  const real_T Width;                  /* '<S71>/Width' */
  const real_T Width_k;                /* '<S72>/Width' */
  const real_T Width_l;                /* '<S73>/Width' */
  const real_T Width_b;                /* '<S81>/Width' */
} ConstB_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T;

/* Invariant block signals for system '<S4>/target_manager_mbox' */
typedef struct {
  ConstB_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T
    manage_optimal_guidance_mbox;     /* '<S44>/manage_optimal_guidance_mbox' */
} ConstB_target_manager_mbox_obrttg_mvm_mBox_T;

/* Invariant block signals for system '<S1>/mission_and_vehicle_management_mbox' */
typedef struct {
  ConstB_target_manager_mbox_obrttg_mvm_mBox_T target_manager_mbox;/* '<S4>/target_manager_mbox' */
} ConstB_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T;

/* Invariant block signals (default storage) */
typedef struct {
  ConstB_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T
    mission_and_vehicle_management_mbox;
                                /* '<S1>/mission_and_vehicle_management_mbox' */
} ConstB_obrttg_mvm_mBox_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S11>/Logic'
   *   '<S16>/Logic'
   *   '<S17>/Logic'
   *   '<S34>/Logic'
   *   '<S8>/Logic'
   *   '<S9>/Logic'
   */
  boolean_T pooled9[16];
} ConstP_obrttg_mvm_mBox_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  busGncParameters gnc_parameters;     /* '<Root>/gnc_parameters' */
  busGncCommIn comm_in;                /* '<Root>/comm_in' */
  busGncNavigation navigation_output;  /* '<Root>/navigation_output' */
  busGncGuidance guidance_output;      /* '<Root>/guidance_output' */
  busGncController controller_output;  /* '<Root>/controller_output' */
  busGncOtp otp_output;                /* '<Root>/otp_output' */
} ExtU_obrttg_mvm_mBox_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  busGncMvm mvm_output;                /* '<Root>/mvm_output' */
} ExtY_obrttg_mvm_mBox_T;

/* Real-time Model Data Structure */
struct tag_RTM_obrttg_mvm_mBox_T {
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
extern B_obrttg_mvm_mBox_T obrttg_mvm_mBox_B;

/* Block states (default storage) */
extern DW_obrttg_mvm_mBox_T obrttg_mvm_mBox_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_obrttg_mvm_mBox_T obrttg_mvm_mBox_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_obrttg_mvm_mBox_T obrttg_mvm_mBox_Y;

/* External data declarations for dependent source files */
extern const busGncMvm obrttg_mvm_mBox_rtZbusGncMvm;/* busGncMvm ground */
extern const ConstB_obrttg_mvm_mBox_T obrttg_mvm_mBox_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_obrttg_mvm_mBox_T obrttg_mvm_mBox_ConstP;

/* Model entry point functions */
extern void obrttg_mvm_mBox_initialize(void);
extern void obrttg_mvm_mBox_step(void);
extern void obrttg_mvm_mBox_terminate(void);

/* Real-time Model object */
extern RT_MODEL_obrttg_mvm_mBox_T *const obrttg_mvm_mBox_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S12>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S5>/Cast To Double1' : Eliminate redundant data type conversion
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
 * '<Root>' : 'obrttg_mvm_mBox'
 * '<S1>'   : 'obrttg_mvm_mBox/mvm'
 * '<S2>'   : 'obrttg_mvm_mBox/mvm/check_computation_completion'
 * '<S3>'   : 'obrttg_mvm_mBox/mvm/get_final_waypoint'
 * '<S4>'   : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox'
 * '<S5>'   : 'obrttg_mvm_mBox/mvm/update_mission_state'
 * '<S6>'   : 'obrttg_mvm_mBox/mvm/check_computation_completion/check_computation_completion_svf'
 * '<S7>'   : 'obrttg_mvm_mBox/mvm/check_computation_completion/check_computation_completion_svf/check_if_trafjectory_available'
 * '<S8>'   : 'obrttg_mvm_mBox/mvm/check_computation_completion/check_computation_completion_svf/check_if_trafjectory_available/initialize_flag'
 * '<S9>'   : 'obrttg_mvm_mBox/mvm/check_computation_completion/check_computation_completion_svf/check_if_trafjectory_available/last_computation_done'
 * '<S10>'  : 'obrttg_mvm_mBox/mvm/get_final_waypoint/Compare To Constant'
 * '<S11>'  : 'obrttg_mvm_mBox/mvm/get_final_waypoint/S-R Flip-Flop'
 * '<S12>'  : 'obrttg_mvm_mBox/mvm/get_final_waypoint/check_retargeting_ok'
 * '<S13>'  : 'obrttg_mvm_mBox/mvm/get_final_waypoint/get_number_WPs'
 * '<S14>'  : 'obrttg_mvm_mBox/mvm/get_final_waypoint/check_retargeting_ok/Compare To Constant1'
 * '<S15>'  : 'obrttg_mvm_mBox/mvm/get_final_waypoint/check_retargeting_ok/Detect Increase'
 * '<S16>'  : 'obrttg_mvm_mBox/mvm/get_final_waypoint/check_retargeting_ok/S-R Flip-Flop2'
 * '<S17>'  : 'obrttg_mvm_mBox/mvm/get_final_waypoint/check_retargeting_ok/S-R Flip-Flop3'
 * '<S18>'  : 'obrttg_mvm_mBox/mvm/get_final_waypoint/get_number_WPs/probe_2D_matrix_dimension'
 * '<S19>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/flight_mode_selector_mbox'
 * '<S20>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/generate_state_machine_signals'
 * '<S21>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox'
 * '<S22>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/flight_mode_selector_mbox/mode_-1_idle'
 * '<S23>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/flight_mode_selector_mbox/mode_0_startup'
 * '<S24>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/flight_mode_selector_mbox/mode_1_guidance_ready'
 * '<S25>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/flight_mode_selector_mbox/mode_2_optimal_guidance'
 * '<S26>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/flight_mode_selector_mbox/mode_3_guidance_done'
 * '<S27>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/flight_mode_selector_mbox/mode_0_startup/handle_startup_mode'
 * '<S28>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/flight_mode_selector_mbox/mode_1_guidance_ready/handle_guidance_ready_mode'
 * '<S29>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/flight_mode_selector_mbox/mode_2_optimal_guidance/handle_optimal_guidance_mode'
 * '<S30>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/flight_mode_selector_mbox/mode_3_guidance_done/handle_guidance_done_mode'
 * '<S31>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/generate_state_machine_signals/Compare To Constant'
 * '<S32>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/generate_state_machine_signals/Compare To Constant1'
 * '<S33>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/generate_state_machine_signals/Detect Decrease'
 * '<S34>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/generate_state_machine_signals/S-R Flip-Flop'
 * '<S35>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/generate_state_machine_signals/check_ccomputation'
 * '<S36>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/generate_state_machine_signals/check_stop_guidance'
 * '<S37>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/generate_state_machine_signals/vectorN_norm'
 * '<S38>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/generate_state_machine_signals/check_ccomputation/Compare To Constant'
 * '<S39>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/generate_state_machine_signals/check_ccomputation/Compare To Constant1'
 * '<S40>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/generate_state_machine_signals/check_stop_guidance/vectorN_norm1'
 * '<S41>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/generate_state_machine_signals/check_stop_guidance/vectorN_norm2'
 * '<S42>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/manage_guidance_ready_mbox'
 * '<S43>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/manage_phase_default_mbox'
 * '<S44>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager'
 * '<S45>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/startup_manager'
 * '<S46>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/manage_guidance_ready_mbox/change_trajectory'
 * '<S47>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/manage_guidance_ready_mbox/change_trajectory/Compare To Constant'
 * '<S48>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox'
 * '<S49>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/get_next_start_point'
 * '<S50>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/get_next_target'
 * '<S51>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/handle_requests'
 * '<S52>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/manage_trajectory_switch'
 * '<S53>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests'
 * '<S54>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/get_next_start_point/get_next_start'
 * '<S55>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/get_next_start_point/get_prediction_time'
 * '<S56>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/get_next_start_point/get_propagate_flag'
 * '<S57>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/get_next_start_point/get_next_start/get_next_start'
 * '<S58>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/get_next_target/get_next_target_idx'
 * '<S59>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/get_next_target/get_target_from_list'
 * '<S60>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/get_next_target/get_next_target_idx/nominal_rise'
 * '<S61>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/get_next_target/get_next_target_idx/retarget_rise'
 * '<S62>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/handle_requests/get_compute_flag'
 * '<S63>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/handle_requests/manage_computations'
 * '<S64>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/handle_requests/merge_request_flags'
 * '<S65>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/handle_requests/reset_nAttempts'
 * '<S66>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/handle_requests/update_request_flag'
 * '<S67>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/handle_requests/get_compute_flag/requestID_compare'
 * '<S68>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/handle_requests/manage_computations/manage_computations'
 * '<S69>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/manage_trajectory_switch/manage_trajectory_switch'
 * '<S70>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/manage_trajectory_switch/switchFlag_rise'
 * '<S71>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/compute_trajectory_time_length'
 * '<S72>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/compute_trajectory_time_length1'
 * '<S73>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/compute_trajectory_time_step'
 * '<S74>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/get_number_WPs'
 * '<S75>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/get_number_WPs1'
 * '<S76>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/manage_failure_request'
 * '<S77>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/manage_long_trajectory_request'
 * '<S78>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/manage_nominal_request'
 * '<S79>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/manage_retargeting_request'
 * '<S80>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/manage_tracking_error_request'
 * '<S81>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/compute_trajectory_time_step/compute_trajectory_time_length'
 * '<S82>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/get_number_WPs/probe_2D_matrix_dimension'
 * '<S83>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/get_number_WPs1/probe_2D_matrix_dimension'
 * '<S84>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/manage_failure_request/manage_failure_request'
 * '<S85>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/manage_long_trajectory_request/manage_long_trajectory_request'
 * '<S86>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/manage_nominal_request/manage_nominal_request'
 * '<S87>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/manage_retargeting_request/manage_retargeting_request'
 * '<S88>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/optimal_guidance_manager/manage_optimal_guidance_mbox/obtain_requests/manage_tracking_error_request/manage_tracking_error_request'
 * '<S89>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/startup_manager/manage_startup_mbox'
 * '<S90>'  : 'obrttg_mvm_mBox/mvm/mission_and_vehicle_management_mbox/target_manager_mbox/startup_manager/manage_startup_mbox/manage_startup'
 * '<S91>'  : 'obrttg_mvm_mBox/mvm/update_mission_state/vectorN_norm'
 */
#endif                                 /* RTW_HEADER_obrttg_mvm_mBox_h_ */

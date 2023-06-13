/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/*
 * obrttg_mvm_mBox_private.h
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

#ifndef RTW_HEADER_obrttg_mvm_mBox_private_h_
#define RTW_HEADER_obrttg_mvm_mBox_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "obrttg_mvm_mBox.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

extern void obrttg_mvm_mBox_check_computation_completion_svf_Init
  (DW_check_computation_completion_svf_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_check_computation_completion_svf(boolean_T
  rtu_recompute_flag, real_T rtu_trajectory_id,
  B_check_computation_completion_svf_obrttg_mvm_mBox_T *localB,
  DW_check_computation_completion_svf_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_manage_startup_mbox(const real_T rtu_vehicle_state
  [14], real_T rtu_computation_done, real_T rtu_solver_exit_flag, const real_T
  rtu_target_list[18], const real_T rtu_takeoff_target_position[3], const real_T
  rtu_takeoff_velocity[3], B_manage_startup_mbox_obrttg_mvm_mBox_T *localB);
extern void obrttg_mvm_mBox_get_next_start(const real_T rtu_trajectory[540],
  const real_T rtu_vehicle_state[14], real_T rtu_n_attempts, real_T
  rtu_propagate_flag, real_T rtu_request_id, real_T rtu_time_to_go, real_T
  rtu_prediction_time, B_get_next_start_obrttg_mvm_mBox_T *localB);
extern void obrttg_mvm_mBox_get_prediction_time(real_T rtu_time_to_go, real_T
  rtu_request_id, B_get_prediction_time_obrttg_mvm_mBox_T *localB);
extern void obrttg_mvm_mBox_get_propagate_flag
  (B_get_propagate_flag_obrttg_mvm_mBox_T *localB);
extern void obrttg_mvm_mBox_get_next_target_idx_Init
  (DW_get_next_target_idx_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_get_next_target_idx_Reset
  (DW_get_next_target_idx_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_get_next_target_idx(real_T rtu_nominal_request,
  real_T rtu_retarget_request, real_T rtu_current_target_idx,
  B_get_next_target_idx_obrttg_mvm_mBox_T *localB,
  DW_get_next_target_idx_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_manage_computations(const real_T rtu_request_flags[5],
  real_T rtu_computation_done, real_T rtu_solver_exitflag, real_T
  rtu_n_attempts_in, B_manage_computations_obrttg_mvm_mBox_T *localB);
extern void obrttg_mvm_mBox_merge_request_flags(const real_T
  rtu_request_flags_new[5], const real_T rtu_request_flags_old[5],
  B_merge_request_flags_obrttg_mvm_mBox_T *localB);
extern void obrttg_mvm_mBox_update_request_flag(real_T rtu_compute_flag, const
  real_T rtu_request_flags_in[5], B_update_request_flag_obrttg_mvm_mBox_T
  *localB);
extern void obrttg_mvm_mBox_manage_trajectory_switch_Init
  (DW_manage_trajectory_switch_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_manage_trajectory_switch_Reset
  (DW_manage_trajectory_switch_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_manage_trajectory_switch(real_T
  rtu_time_trajectory_switch, real_T rtu_time, real_T rtu_n_attempts, real_T
  rtu_computation_done, B_manage_trajectory_switch_obrttg_mvm_mBox_T *localB,
  DW_manage_trajectory_switch_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_manage_failure_request(real_T rtu_failure_flag,
  real_T rtu_time_to_go, real_T rtu_n_targets, real_T rtu_current_target_idx,
  B_manage_failure_request_obrttg_mvm_mBox_T *localB);
extern void obrttg_mvm_mBox_manage_long_trajectory_request(real_T rtu_time_to_go,
  real_T rtu_trajectory_time_step, real_T rtu_trajectory_time, real_T
  rtu_offline_otp, B_manage_long_trajectory_request_obrttg_mvm_mBox_T *localB);
extern void obrttg_mvm_mBox_manage_nominal_request(real_T rtu_time_to_go, real_T
  rtu_n_targets, real_T rtu_current_target_idx,
  B_manage_nominal_request_obrttg_mvm_mBox_T *localB);
extern void obrttg_mvm_mBox_manage_retargeting_request(real_T
  rtu_retargeting_flag, real_T rtu_time_to_go, real_T rtu_current_target_idx,
  B_manage_retargeting_request_obrttg_mvm_mBox_T *localB);
extern void obrttg_mvm_mBox_manage_tracking_error_request(real_T
  rtu_tracking_error_flag, real_T rtu_trajectory_time, real_T rtu_time_to_go,
  B_manage_tracking_error_request_obrttg_mvm_mBox_T *localB);
extern void obrttg_mvm_mBox_manage_optimal_guidance_mbox_Init
  (B_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localB,
   DW_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_manage_optimal_guidance_mbox_Reset
  (DW_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_manage_optimal_guidance_mbox_Disable
  (B_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localB,
   DW_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_manage_optimal_guidance_mbox(real_T rtu_time, const
  real_T rtu_vehicle_state[14], const real_T rtu_optimal_trajectory[540], real_T
  rtu_computation_done, real_T rtu_solver_exitflag, real_T rtu_time_to_go,
  real_T rtu_retargeting_flag, real_T rtu_tracking_error_flag, real_T
  rtu_failure_flag, const real_T rtu_WP_list[18], real_T rtu_offline_otp, real_T
  rtu_current_target_idx, B_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T
  *localB, const ConstB_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localC,
  DW_manage_optimal_guidance_mbox_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_target_manager_mbox_Init
  (B_target_manager_mbox_obrttg_mvm_mBox_T *localB,
   DW_target_manager_mbox_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_target_manager_mbox(RT_MODEL_obrttg_mvm_mBox_T *
  const obrttg_mvm_mBox_M, const real_T rtu_WPs_list[18], const real_T
  rtu_takeoff_target_position[3], const real_T rtu_velocity_toff[3], real_T
  rtu_offline_otp, const busMissionState *rtu_mission_state, const real_T
  rtu_vehicle_state[14], real_T rtu_solver_exitflag, real_T rtu_computation_done,
  const real_T rtu_optimal_trajectory[540], real_T rtu_flight_mode,
  B_target_manager_mbox_obrttg_mvm_mBox_T *localB, const
  ConstB_target_manager_mbox_obrttg_mvm_mBox_T *localC,
  DW_target_manager_mbox_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_mission_and_vehicle_management_mbox_Init
  (B_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T *localB,
   DW_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T *localDW);
extern void obrttg_mvm_mBox_mission_and_vehicle_management_mbox
  (RT_MODEL_obrttg_mvm_mBox_T * const obrttg_mvm_mBox_M, real_T
   rtu_flight_mode_in, const real_T rtu_start_wp_position[3], const real_T
   rtu_final_wp_position[3], const real_T rtu_WPs_list[18], const real_T
   rtu_velocity_toff[3], real_T rtu_offline_otp, const real_T rtu_vehicle_state
   [14], const busMissionState *rtu_mission_state, const real_T
   rtu_previous_trajectory[540], real_T rtu_solver_exitflag, real_T
   rtu_computation_done, real_T rtu_obc_status_flag,
   B_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T *localB, const
   ConstB_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T *localC,
   DW_mission_and_vehicle_management_mbox_obrttg_mvm_mBox_T *localDW);

#endif                               /* RTW_HEADER_obrttg_mvm_mBox_private_h_ */

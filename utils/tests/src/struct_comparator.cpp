/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 21 Jun 2021
/// @brief Implementation of test helper functions to compare Obrttg bus structs using Google Test assertions.

#include "struct_comparator.hpp"

#include "gtest/gtest.h"

void obrttg::compareBusGncNavigation(const busGncNavigation &actual, const busGncNavigation &expected)
{
    EXPECT_DOUBLE_EQ(actual.timestamp, expected.timestamp);
    for (uint16_t i = 0u; i < sizeof(actual.position)/sizeof(actual.position[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.position[i], expected.position[i]);
    }
    for (uint16_t i = 0u; i < sizeof(actual.velocity)/sizeof(actual.velocity[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.velocity[i], expected.velocity[i]);
    }
    for (uint16_t i = 0u; i < sizeof(actual.attitude)/sizeof(actual.attitude[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.attitude[i], expected.attitude[i]);
    }
    for (uint16_t i = 0u; i < sizeof(actual.rates)/sizeof(actual.rates[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.rates[i], expected.rates[i]);
    }
    EXPECT_DOUBLE_EQ(actual.mass, expected.mass);
    for (uint16_t i = 0u; i < sizeof(actual.CoM)/sizeof(actual.CoM[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.CoM[i], expected.CoM[i]);
    }
    EXPECT_EQ(actual.retargeting_flag, expected.retargeting_flag);
}

void obrttg::compareBusGncGuidance(const busGncGuidance &actual, const busGncGuidance &expected)
{
    EXPECT_DOUBLE_EQ(actual.timestamp, expected.timestamp);
    EXPECT_DOUBLE_EQ(actual.time_to_go, expected.time_to_go);
    for (uint16_t i = 0u; i < sizeof(actual.state_error)/sizeof(actual.state_error[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.state_error[i], expected.state_error[i]);
    }
    for (uint16_t i = 0u; i < sizeof(actual.guidance_reference)/sizeof(actual.guidance_reference[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.guidance_reference[i], expected.guidance_reference[i]);
    }
    for (uint16_t i = 0u; i < sizeof(actual.current_optimal_trajectory)/sizeof(actual.current_optimal_trajectory[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.current_optimal_trajectory[i], expected.current_optimal_trajectory[i]);
    }
}

void obrttg::compareBusGncMvm(const busGncMvm &actual, const busGncMvm &expected)
{
    EXPECT_DOUBLE_EQ(actual.timestamp, expected.timestamp);
    EXPECT_DOUBLE_EQ(actual.computation_done, expected.computation_done);
    EXPECT_EQ(actual.recompute_flag, expected.recompute_flag);
    for (uint16_t i = 0u; i < sizeof(actual.next_target)/sizeof(actual.next_target[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.next_target[i], expected.next_target[i]);
    }
    for (uint16_t i = 0u; i < sizeof(actual.next_start)/sizeof(actual.next_start[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.next_start[i], expected.next_start[i]);
    }
    for (uint16_t i = 0u; i < sizeof(actual.mission_phase_id)/sizeof(actual.mission_phase_id[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.mission_phase_id[i], expected.mission_phase_id[i]);
    }
    EXPECT_EQ(actual.change_trajectory, expected.change_trajectory);
    for (uint16_t i = 0u; i < sizeof(actual.mvm_flags)/sizeof(actual.mvm_flags[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.mvm_flags[i], expected.mvm_flags[i]);
    }
}

void obrttg::compareBusGncOtp(const busGncOtp &actual, const busGncOtp &expected)
{
    EXPECT_DOUBLE_EQ(actual.timestamp, expected.timestamp);
    for (uint16_t i = 0u; i < sizeof(actual.optimal_trajectory)/sizeof(actual.optimal_trajectory[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.optimal_trajectory[i], expected.optimal_trajectory[i]);
    }
    EXPECT_DOUBLE_EQ(actual.trajectory_id, expected.trajectory_id);
    EXPECT_DOUBLE_EQ(actual.exit_flag, expected.exit_flag);
    EXPECT_DOUBLE_EQ(actual.n_iter, expected.n_iter);
    EXPECT_DOUBLE_EQ(actual.solve_time, expected.solve_time);
    EXPECT_DOUBLE_EQ(actual.min_fuel_formulation_flag, expected.min_fuel_formulation_flag);
    for (uint16_t i = 0u; i < sizeof(actual.x_target)/sizeof(actual.x_target[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.x_target[i], expected.x_target[i]);
    }
    for (uint16_t i = 0u; i < sizeof(actual.x_start)/sizeof(actual.x_start[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.x_start[i], expected.x_start[i]);
    }
    for (uint16_t i = 0u; i < sizeof(actual.health_status)/sizeof(actual.health_status[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.health_status[i], expected.health_status[i]);
    }
    for (uint16_t i = 0u; i < sizeof(actual.trajectory_params)/sizeof(actual.trajectory_params[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.trajectory_params[i], expected.trajectory_params[i]);
    }
}

void obrttg::compareBusGncCommIn(const busGncCommIn &actual, const busGncCommIn &expected)
{
    EXPECT_NEAR(actual.timestamp, expected.timestamp, 0.001);           // Allow an absolute difference of 1ms
    EXPECT_NEAR(actual.timestamp_obc, expected.timestamp_obc, 0.001);   // Allow an absolute difference of 1ms

    EXPECT_DOUBLE_EQ(actual.mission_status, expected.mission_status);
    for (uint16_t i = 0u; i < sizeof(actual.vehicle_state)/sizeof(actual.vehicle_state[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.vehicle_state[i], expected.vehicle_state[i]);
    }
    for (uint16_t i = 0u; i < sizeof(actual.engine_status)/sizeof(actual.engine_status[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.engine_status[i], expected.engine_status[i]);
    }
}

void obrttg::compareBusGncCommOut(const busGncCommOut &actual, const busGncCommOut &expected)
{
    EXPECT_DOUBLE_EQ(actual.timestamp, expected.timestamp);
    EXPECT_DOUBLE_EQ(actual.pac_status, expected.pac_status);
    for (uint16_t i = 0u; i < sizeof(actual.position_reference)/sizeof(actual.position_reference[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.position_reference[i], expected.position_reference[i]);
    }
    for (uint16_t i = 0u; i < sizeof(actual.velocity_reference)/sizeof(actual.velocity_reference[0]); i++)
    {
        EXPECT_DOUBLE_EQ(actual.velocity_reference[i], expected.velocity_reference[i]);
    }
}
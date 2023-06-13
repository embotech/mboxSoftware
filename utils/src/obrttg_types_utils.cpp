/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 21 Jun 2021
/// @brief Implementation of utility functions to generate random Obrttg bus structures.

#include <cstdlib>
#include <cstdint>
#include <math.h>

#include "obrttg_types_utils.hpp"

static double randomDouble(double min, double max)
{
    return min + (max - min)*( (double)rand() / RAND_MAX ); 
}

static int randomIntenger(int min, int max)
{
    return rand() % (max - min) + min;
}

static double randomBoolean()
{
    return (bool)floor((double)rand() / RAND_MAX);
}

busGncNavigation obrttg::randomBusGncNavigation()
{
    busGncNavigation o;
    o.timestamp = randomDouble(0, 1000);
    for (uint16_t i = 0u; i < sizeof(o.position)/sizeof(o.position[0]); i++)
    {
        o.position[i] = randomDouble(-100, 100);
    }
    for (uint16_t i = 0u; i < sizeof(o.velocity)/sizeof(o.velocity[0]); i++)
    {
        o.velocity[i] = randomDouble(-100, 100); 
    }
    for (uint16_t i = 0u; i < sizeof(o.attitude)/sizeof(o.attitude[0]); i++)
    {
        o.attitude[i] = randomDouble(-1, 1);
    }
    for (uint16_t i = 0u; i < sizeof(o.rates)/sizeof(o.rates[0]); i++)
    {
        o.rates[i] = randomDouble(-10, 10); 
    }
    o.mass = randomDouble(30, 65);
    for (uint16_t i = 0u; i < sizeof(o.CoM)/sizeof(o.CoM[0]); i++)
    {
        o.CoM[i] = randomDouble(0.3, 0.7);
    }
    o.retargeting_flag = randomBoolean();

    return o;
}

busGncGuidance obrttg::randomBusGncGuidance()
{
    busGncGuidance o;
    o.timestamp = randomDouble(0, 1000);
    o.time_to_go = randomDouble(0, 30);
    for (uint16_t i = 0u; i < sizeof(o.state_error)/sizeof(o.state_error[0]); i++)
    {
        o.state_error[i] = randomDouble(-10, 10);
    }
    for (uint16_t i = 0u; i < sizeof(o.guidance_reference)/sizeof(o.guidance_reference[0]); i++)
    {
        o.guidance_reference[i] = randomDouble(-50, 50);
    }
    for (uint16_t i = 0u; i < sizeof(o.current_optimal_trajectory)/sizeof(o.current_optimal_trajectory[0]); i++)
    {
        o.current_optimal_trajectory[i] = randomDouble(-50, 50);
    }

    return o;
}

busGncMvm obrttg::randomBusGncMvm()
{
    busGncMvm o;
    o.timestamp = randomDouble(0, 1000);
    o.computation_done = (double)randomIntenger(-1, 1);
    o.recompute_flag = randomBoolean();
    for (uint16_t i = 0u; i < sizeof(o.next_target)/sizeof(o.next_target[0]); i++)
    {
        o.next_target[i] = randomDouble(-50, 50);
    }
    for (uint16_t i = 0u; i < sizeof(o.next_start)/sizeof(o.next_start[0]); i++)
    {
        o.next_start[i] = randomDouble(-50, 50);
    }
    o.mission_phase_id[0] = (double)randomIntenger(-1, 3);
    o.mission_phase_id[1] = (double)randomBoolean();
    o.change_trajectory = randomBoolean();
    for (uint16_t i = 0u; i < sizeof(o.mvm_flags)/sizeof(o.mvm_flags[0]); i++)
    {
        o.mvm_flags[i] = (double)randomBoolean();
    }

    return o;
}

busGncOtp obrttg::randomBusGncOtp()
{
    busGncOtp o;
    o.timestamp = randomDouble(0, 1000);
    for (uint16_t i = 0u; i < sizeof(o.optimal_trajectory)/sizeof(o.optimal_trajectory[0]); i++)
    {
        o.optimal_trajectory[i] = randomDouble(-50, 50);
    }
    o.trajectory_id = (double)randomIntenger(1, 100);
    o.exit_flag = (double)randomIntenger(-7, 1);
    o.n_iter = (double)randomIntenger(0, 150);
    o.solve_time = randomDouble(0, 2);
    o.min_fuel_formulation_flag = (double)randomBoolean();
    for (uint16_t i = 0u; i < sizeof(o.x_target)/sizeof(o.x_target[0]); i++)
    {
        o.x_target[i] = randomDouble(-50, 50);
    }
    for (uint16_t i = 0u; i < sizeof(o.x_start)/sizeof(o.x_start[0]); i++)
    {
        o.x_start[i] = randomDouble(-50, 50);
    }
    for (uint16_t i = 0u; i < sizeof(o.health_status)/sizeof(o.health_status[0]); i++)
    {
        o.health_status[i] = randomDouble(-500, 500);
    }
    for (uint16_t i = 0u; i < sizeof(o.trajectory_params)/sizeof(o.trajectory_params[0]); i++)
    {
        o.trajectory_params[i] = randomDouble(-10, 10);
    }

    return o;
}

busGncCommIn obrttg::randomBusGncCommIn()
{
    busGncCommIn o = {0};
    o.timestamp = randomDouble(0, 1000);
    o.timestamp_obc = randomDouble(0, 1000);
    o.mission_status = (double)randomIntenger(1, 4);
    for (uint16_t i = 0u; i < sizeof(o.vehicle_state)/sizeof(o.vehicle_state[0]); i++)
    {
        o.vehicle_state[i] = randomDouble(-50, 50);
    }
    for (uint16_t i = 0u; i < sizeof(o.engine_status)/sizeof(o.engine_status[0]); i++)
    {
        o.engine_status[i] = randomDouble(-50, 50);
    }
    return o;
}

busGncCommOut obrttg::randomBusGncCommOut()
{
    busGncCommOut o = {0};
    o.timestamp = randomDouble(0, 1000);
    o.pac_status = (double)randomIntenger(1, 3);
    for (uint16_t i = 0u; i < sizeof(o.position_reference)/sizeof(o.position_reference[0]); i++)
    {
        o.position_reference[i] = randomDouble(-100, 100);
    }
    for (uint16_t i = 0u; i < sizeof(o.velocity_reference)/sizeof(o.velocity_reference[0]); i++)
    {
        o.velocity_reference[i] = randomDouble(-20, 20);
    }
    return o;
}
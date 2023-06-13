/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 *
 * ---------------------------------------------------------------------------------------------------------
 * Initial guess generation header file initial_guess.h
 * This file contains the public interface of the initial guess generation functions for the OBRTTG
 * ---------------------------------------------------------------------------------------------------------
 */

#include <stdint.h>
#include "obrttg_solver_defines.h"

/**
 * get_initial_guess_nlp3
 *
 * @brief Function that computes a trajectory initial guess from the initial to the final state (3dof NLP)
 *
 * @param[in] mass_0            Vehicle mass at the beginning of the trajectory
 * @param[in] x_0               Pointer to the 6-element initial state (position + velocity)
 * @param[in] x_N               Pointer to the 6-element final state (position + velocity)
 * @param[in] dt                Time step estimate between trajectory stages
 * @param[out] initial_guess    Pointer to [N_STATES_1 x (N_STAGES - 1) + N_STATES_N] double array in which 
 *                              the trajectory initial guess is saved.
 * @returns                     0 if everything is fine, 1 otherwise
 */
uint32_t get_initial_guess_nlp3(const double mass_0, 
                                const double *x_0, 
                                const double *x_N, 
                                const double dt, 
                                      double *initial_guess);

/**
 * get_flight_time_estimate
 *
 * @brief Function that computes a flight time estimate based on some distance heuristic.
 *
 * @param[in]   x_initial   Pointer to the 3D coordinates of the initial position
 * @param[in]   x_target    Pointer to the 3D coordinates of the target position
 * @returns                 Flight time estimate
 */
double get_flight_time_estimate(const double *x_initial,
                                const double *x_target);

/**
 * get_min_flight_time
 *
 * @brief Function that computes the theoretical minimum time of flight
 * 
 * @param[in] x_initial     [m] Pointer to the 3D coordinates of the initial position
 * @param[in] x_target      [m] Pointer to the 3D coordinates of the target position
 * @param[in] v_initial     [m] Pointer to initial velocity
 * @param[in] max_thrust    [N] Maximum thrust
 * @returns                 Theoretical minimum time of flight
 */
double get_min_flight_time(const double *x_initial, 
                           const double *x_target, 
                           const double *v_initial, 
                           const double max_thrust);

/**
 * get_max_flight_time
 * 
 * @brief Function that computes the theoretical maximum time of flight
 * 
 * @param[in] mass_0        [kg] Vehicle mass at the beginning of the trajectory
 * @param[in] min_thrust    [N] Minimum thrust
 * @returns                 Theoretical maximum time of flight based on available fuel
 */
double get_max_flight_time(const double mass_0, 
                           const double min_thrust);
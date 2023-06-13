/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 *
 * ---------------------------------------------------------------------------------------------------------
 * Initial Guess Generation Source file initial_guess.c
 * This file contains the implementation of the initial guess generation functions for the OBRTTG
 * ---------------------------------------------------------------------------------------------------------
 */

/*
 * Include Files
 *
 */
#include <math.h>
#include <stdint.h>
#include <string.h> /* memcpy */
#include "obrttg_initial_guess.h"

/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */ 

/*
 * get_norm_3d_vector
 *
 * @brief Function that computes the 2-norm of a 3D vector
 *
 * @param[in]   Pointer to the 3D vector
 * @returns     2-Norm of the 3D vector
 */
static double get_norm_3d_vector(const double *x)
{
    return sqrt(x[0] * x[0] + x[1] * x[1] + x[2] * x[2]);
}

/**
 * get_euclidean_distance
 *
 * @brief Function that computes the euclidean distance betweeen 2 3D points
 *
 * @param[in] x0    Pointer to the 3D coordinates of the first point
 * @param[in] x1    Pointer to the 3D coordinates of the second point
 * @returns         the euclidean distance between the two points
 */
static double get_euclidean_distance(const double *x0, 
                                     const double *x1)
{
    double x[3];
    x[0] = x1[0] - x0[0];
    x[1] = x1[1] - x0[1];
    x[2] = x1[2] - x0[2];
    
    return get_norm_3d_vector(x);
}

/**
 * get_position_guess
 *
 * @brief Funtion that computes an initial guess for the position evolution
 *
 * @param[in] x_0               Pointer to the 3D initial position
 * @param[in] x_N               Pointer to the 3D final position
 * @param[in] dt                Time step estimate between trajectory stages
 * @param[out] position_guess   Pointer to [3xN_STAGES] double array in which the position guess is stored.
 * @returns                     0 if everything is fine, 1 otherwise
 */
static uint32_t get_position_guess(const double *x_0, 
                                   const double *x_N, 
                                   const double dt, 
                                         double *position_guess);


/**
 * get_velocity_guess
 *
 * @brief Funtion that computes an initial guess for the velocity evolution
 *
 * @param[in] v_0               Pointer to the initial velocity
 * @param[in] v_N               Pointer to the final velocity
 * @param[in] dt                Time step estimate between trajectory stages
 * @param[in] position_guess    Pointer to [3xN_STAGES] double array with position guess
 * @param[out] velocity_guess   Pointer to [3xN_STAGES] double array in which the velocity guess is stored.
 * @returns                     0 if everything is fine, 1 otherwise
 */
static uint32_t get_velocity_guess(const double *v_0, 
                                   const double *v_N,
                                   const double dt,
                                   const double *position_guess,
                                         double *velocity_guess);


/**
 * get_thrust_and_mass_guess
 *
 * @brief Funtion that computes an initial guess for the thrust and mass evolution
 *
 * @param[in] mass_0                Vehicle mass at the beginning of the trajectory
 * @param[in] velocity_guess        Pointer to the velocity guess
 * @param[in] dt                    Time step estimate between trajectory stages
 * @param[in] position_guess        Pointer to [3xN_STAGES] double array with position guess
 * @param[out] thrust_rate_guess    Pointer to [3xN_STAGES] double array in which thrust rate guess is stored.
 * @param[out] thrust_guess         Pointer to [3xN_STAGES] double array in which the thrust guess is stored.
 * @param[out] mass_guess           Pointer to [N_STAGES] double array in which the mass guess is stored.
 * @returns                         0 if everything is fine, 1 otherwise
 */
static uint32_t get_thrust_and_mass_guess(const double mass_0,
                                          const double *velocity_guess,
                                          const double dt, 
                                                double *thrust_rate_guess,
                                                double *thrust_guess,
                                                double *mass_guess);


double get_flight_time_estimate(const double *x_initial, 
                                       const double *x_target)
{
    return get_euclidean_distance(x_initial, x_target) / 4.0;
}

uint32_t get_initial_guess_nlp3(const double mass_0, 
                                const double *x_0, 
                                const double *x_N, 
                                const double dt, 
                                      double *initial_guess)
{
    /* Initialize variables */
    uint32_t k;
    double position_guess[3 * N_STAGES];
    double velocity_guess[3 * N_STAGES];
    double thrust_guess[3 * N_STAGES];
    double thrust_rate_guess[3 * N_STAGES];
    double mass_guess[N_STAGES];
    double slack_guess = 1.0;           /* Guess for the slack variable is constant */
    double x_0_mod[6] = { 0 };          /* Auxiliary local varriable for modified initial state 
                                           (position + velocity) */

    /* Copy x_0 to auxiliary local variable */
    memcpy(x_0_mod, x_0, 6 * sizeof(double));

    /* Perturb initial velocity slightly to avoid problems with zero velocity */
    for (k=3; k<6; k++)
    {
	    if (x_0_mod[k] == 0)
        {
            x_0_mod[k] = x_0_mod[k] + 0.001;
        }
    }

    /* Compute position guess */
    get_position_guess(x_0_mod, x_N, dt, position_guess);

    /* Compute velocity guess */
    get_velocity_guess(&x_0_mod[3], &x_N[3], dt, position_guess, velocity_guess);

    /* Compute thrust & mass guess */
    get_thrust_and_mass_guess(mass_0, velocity_guess, dt, thrust_rate_guess, thrust_guess, mass_guess);

    /* Transfer the slack, position, velocity, thrust & mass guesses to the initial_guess array */
    for (k = 0; k < (N_STAGES - 1); k++)
    {
        initial_guess[k*N_STATES_1] = slack_guess;
        
		memcpy(&initial_guess[k*N_STATES_1 + 1], &thrust_rate_guess[3 * k], 3 * sizeof(double));

        memcpy( &initial_guess[k*N_STATES_1 + 4], &thrust_guess[3 * k], 3 * sizeof(double) );
        
        initial_guess[k*N_STATES_1 + MASS_IDX_1] = mass_guess[k];

        memcpy( &initial_guess[k*N_STATES_1 + MASS_IDX_1 + 1], &position_guess[3 * k], 3 * sizeof(double) );

        memcpy( &initial_guess[k*N_STATES_1 + MASS_IDX_1 + 4], &velocity_guess[3 * k], 3 * sizeof(double) );

        initial_guess[k*N_STATES_1 + MASS_IDX_1 + 7] = dt;
    }

    /* Transfer last stage initial guess */
    memcpy(&initial_guess[(N_STAGES - 1)*N_STATES_1], &thrust_guess[3*(N_STAGES - 1)], 3 * sizeof(double));
    initial_guess[(N_STAGES - 1)*N_STATES_1 + MASS_IDX_N] = mass_guess[(N_STAGES - 1)];
    memcpy( &initial_guess[(N_STAGES-1)*N_STATES_1 + MASS_IDX_N + 1], &position_guess[3*(N_STAGES-1)], 3 * sizeof(double) );
    memcpy( &initial_guess[(N_STAGES-1)*N_STATES_1 + MASS_IDX_N + 4], &velocity_guess[3*(N_STAGES-1)], 3 * sizeof(double) );
    initial_guess[(N_STAGES - 1)*N_STATES_1 + MASS_IDX_N + 7] = dt;
    
    return 0;
}

static uint32_t get_position_guess(const double *x_0,
                                   const double *x_N,
                                   const double dt,
                                         double *position_guess)
{
    uint32_t k;
    double d_position[3];

    /* Position at first stage is the same as the initial position */
    memcpy(position_guess, x_0, 3 * sizeof(double));
    
    /* Second stage position obtained by propagating the initial speed */
    position_guess[3] = x_0[0] + dt * x_0[3];
    position_guess[4] = x_0[1] + dt * x_0[4];
    position_guess[5] = x_0[2] + dt * x_0[5];

    /* Compute position step vector */
    d_position[0] = (x_N[0] - x_0[0]) / N_STAGES;
    d_position[1] = (x_N[1] - x_0[1]) / N_STAGES;
    d_position[2] = (x_N[2] - x_0[2]) / N_STAGES;
    
    d_position[0] = (x_N[0] - position_guess[3]) / (N_STAGES - 2);
    d_position[1] = (x_N[1] - position_guess[4]) / (N_STAGES - 2);
    d_position[2] = (x_N[2] - position_guess[5]) / (N_STAGES - 2);

    /* Position at stages 3 to N-1 is interpolated linearly */
    for (k = 2; k < (N_STAGES - 1); k++)
    {
        position_guess[3 * k] = position_guess[3 * (k - 1)] + d_position[0];
        position_guess[3 * k + 1] = position_guess[3 * (k - 1) + 1] + d_position[1];
        position_guess[3 * k + 2] = position_guess[3 * (k - 1) + 2] + d_position[2];
    }
    /* Position at final stage is the same as the target position */
    memcpy( &position_guess[3*(N_STAGES - 1)], x_N, 3 * sizeof(double)) ;

    return 0;
}

static uint32_t get_velocity_guess(const double *v_0,
                                   const double *v_N,
                                   const double dt,
                                   const double *position_guess,
                                         double *velocity_guess)
{
    uint32_t k;
    uint32_t j;

    /* Velocity at first stage is the same as the initial velocity */
    memcpy(velocity_guess, v_0, 3 * sizeof(double));

    /* Velocity at stages 2 to N-1 is computed from the position guess steps */
    for (k = 1; k < (N_STAGES - 1); k++)
    {
        for (j = 0; j < 3; j++)
        {
            velocity_guess[3 * k + j] = (position_guess[3 * (k + 1) + j] - 
                                         position_guess[3 * k + j]) / dt;
        }
        
    }
    /* Velocity at final stage is the same as the target velocity */
    memcpy( &velocity_guess[3 * (N_STAGES - 1)], v_N, 3 * sizeof(double));
    return 0;
}

static uint32_t get_thrust_and_mass_guess(const double mass_0,
                                          const double *velocity_guess,
                                          const double dt,
                                                double *thrust_rate_guess,
                                                double *thrust_guess,
                                                double *mass_guess)
{
    uint32_t k;
    uint32_t j;
    double g_inertial[3] = { -G0, 0.0, 0.0 };
    double thrust_norm;
    
    mass_guess[0] = mass_0;

    /* Compute thrust vector from the velocity steps in the velocity guess */
    for (k = 0; k < (N_STAGES - 1); k++)
    {
        thrust_norm = 0.0;
        
        for (j = 0; j < 3; j++)
        {
            thrust_guess[3 * k + j] = mass_guess[k] * ( (velocity_guess[3 * (k + 1) + j] -
                                                         velocity_guess[3 * k + j] )/dt - g_inertial[j] );
            
            thrust_norm += thrust_guess[3 * k + j] * thrust_guess[3 * k + j];
        }
        /* Mass in the next stages is computed from the norm of the thrust vector at the current stage */
        thrust_norm = sqrt(thrust_norm);
        mass_guess[k + 1] = mass_guess[k] - thrust_norm*ENG_ALPHA*dt;
    }

    /* Thrust vector at the last stage is the same as previous */
    thrust_guess[3 * (N_STAGES - 1)]     = thrust_guess[3 * (N_STAGES - 2)];
    thrust_guess[3 * (N_STAGES - 1) + 1] = thrust_guess[3 * (N_STAGES - 2) + 1];
    thrust_guess[3 * (N_STAGES - 1) + 2] = thrust_guess[3 * (N_STAGES - 2) + 2];

	/* Calculate thrust rate */
	for (k = 0; k < (N_STAGES - 2); k++)
	{
		for (j = 0; j < 3; j++)
		{
			thrust_rate_guess[3 * k + j] = (thrust_guess[3 * (k+1) + j] - thrust_guess[3 * k + j]) / dt;
		}
	}

	/* Thrust vector at the last two stages is null */
	thrust_rate_guess[3 * (N_STAGES - 2)] = 0.0;
	thrust_rate_guess[3 * (N_STAGES - 2) + 1] = 0.0;
	thrust_rate_guess[3 * (N_STAGES - 2) + 2] = 0.0;
	thrust_rate_guess[3 * (N_STAGES - 1)] = 0.0;
	thrust_rate_guess[3 * (N_STAGES - 1) + 1] = 0.0;
	thrust_rate_guess[3 * (N_STAGES - 1) + 2] = 0.0;

    return 0;
}

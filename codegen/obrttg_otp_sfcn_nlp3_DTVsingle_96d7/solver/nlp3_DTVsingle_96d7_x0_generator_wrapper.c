/** ---------------------------------------------------------------------------------------------------------
 * x0 Generator S-Function Wrapper
 * This file contains the main guess generation function and the required helper functions for the OBRTTG
-----------------------------------------------------------------------------------------------------------*/


/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */                                       
#include <math.h>
#include <stdint.h>
#include <string.h>
#include "obrttg_initial_guess.h"
#include "obrttg_solver_defines.h"

/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 7
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */


/**
 * Main Wrapper Function
 */
void nlp3_DTVsingle_96d7_x0_generator_Outputs_wrapper(const real_T *x_initial,
			const real_T *x_target,
            const real_T *thrust_limits,
			real_T *initial_guess)
{
    double x_0[6];          /* Initial state (position & velocity) */
    double x_N[6];          /* Target state (position & velocity) */
    double mass_0;          /* Initial mass */
    
    double t_guess;         /* Flight time estimate*/
    double delta_t_guess;   /* Time step estimate based on flight time estimate */
    
    /* Transfer initial & final [position, velocity] to other double arrays */
    memcpy(x_0, &(x_initial[1]), 6 * sizeof(real_T));
    memcpy(x_N, x_target, 6 * sizeof(real_T));
    mass_0 = x_initial[0];
    
    /* Get flight time estimate */
    t_guess = get_flight_time_estimate(x_0, x_N);

    /* Get time step estimate based on total flight time estimate */
    delta_t_guess = t_guess / N_STAGES;

    /* Compute full trajectory initial guess */
    get_initial_guess_nlp3(mass_0, x_0, x_N, delta_t_guess, initial_guess);
}

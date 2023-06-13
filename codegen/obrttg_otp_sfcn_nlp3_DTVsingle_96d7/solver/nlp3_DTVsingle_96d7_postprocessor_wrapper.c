
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



/* %%%%%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <string.h> /* memcpy,  memset */
#include <stdint.h>
#include "obrttg_solver_defines.h"
/* %%%%%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Create external references here.  
 *
 */
/* %%%%%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%%%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void nlp3_DTVsingle_96d7_postprocessor_Outputs_wrapper(
            const real_T *outputs,
                  real_T *trajectory)
{
/* %%%%%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
/* %%%%%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
    
    uint32_t k;
    double trajectory_tmp[OUT_TRAJ_N_STATES*N_STAGES] = {0};
    
    for (k = 0; k < N_STAGES - 1; k++)
    {
        /* Assign trajectory time */
        if (k == 0)
        {
            trajectory_tmp[k*OUT_TRAJ_N_STATES + OUT_TRAJ_T_IDX] = 0;
        }
        else
        {
            trajectory_tmp[k*OUT_TRAJ_N_STATES + OUT_TRAJ_T_IDX] 
                           = trajectory_tmp[(k - 1)*OUT_TRAJ_N_STATES + OUT_TRAJ_T_IDX]
                           + outputs[(k - 1)*N_STATES_1 + MASS_IDX_1 + 7];
        }

        /* Copy thrust vector */
        memcpy( &trajectory_tmp[k*OUT_TRAJ_N_STATES + OUT_TRAJ_F_IDX],
                &outputs[k*N_STATES_1 + 4], 3*sizeof(double));

        /* Copy mass */
        trajectory_tmp[k*OUT_TRAJ_N_STATES + OUT_TRAJ_M_IDX] = outputs[k*N_STATES_1 + MASS_IDX_1];

        /* Copy position */
        memcpy( &trajectory_tmp[k*OUT_TRAJ_N_STATES + OUT_TRAJ_X_IDX],
                &outputs[k*N_STATES_1 + MASS_IDX_1 + 1], 3 * sizeof(double));

        /* Copy velocity */
        memcpy( &trajectory_tmp[k*OUT_TRAJ_N_STATES + OUT_TRAJ_V_IDX],
                &outputs[k*N_STATES_1 + MASS_IDX_1 + 4], 3 * sizeof(double));

        /* Attitude and angular rates are set to zero in 3DoF solvers. Set quaternion qw component to 1.0 */
        trajectory_tmp[k*OUT_TRAJ_N_STATES + OUT_TRAJ_Q_IDX] = 1.0;
        
        
    }
    
    /* Final stage */
    k = (N_STAGES -1);
    
    /* Assign trajectory time */
    trajectory_tmp[k*OUT_TRAJ_N_STATES + OUT_TRAJ_T_IDX] 
                   = trajectory_tmp[(k - 1)*OUT_TRAJ_N_STATES + OUT_TRAJ_T_IDX]
                   + outputs[(k - 1)*N_STATES_1 + MASS_IDX_1 + 7];
    
    /* Copy thrust vector */
    memcpy( &trajectory_tmp[k*OUT_TRAJ_N_STATES + OUT_TRAJ_F_IDX],
            &outputs[k*N_STATES_1], 3*sizeof(double));

    /* Copy mass */
    trajectory_tmp[k*OUT_TRAJ_N_STATES + OUT_TRAJ_M_IDX] = outputs[k*N_STATES_1 + MASS_IDX_N];

    /* Copy position */
    memcpy( &trajectory_tmp[k*OUT_TRAJ_N_STATES + OUT_TRAJ_X_IDX],
            &outputs[k*N_STATES_1 + MASS_IDX_N + 1], 3*sizeof(double));
	
    /* Copy velocity */
    memcpy(&trajectory_tmp[k*OUT_TRAJ_N_STATES + OUT_TRAJ_V_IDX],
        &outputs[k*N_STATES_1 + MASS_IDX_N + 4], 3 * sizeof(double));

    /* Attitude and angular rates (qw set to 1.0) */
    trajectory_tmp[k*OUT_TRAJ_N_STATES + OUT_TRAJ_Q_IDX]  = 1.0;
    
    
     memcpy(trajectory, trajectory_tmp, OUT_TRAJ_N_STATES*N_STAGES*sizeof(double));
    

}



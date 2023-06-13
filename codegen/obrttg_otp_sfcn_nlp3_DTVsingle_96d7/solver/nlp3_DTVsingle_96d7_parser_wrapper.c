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
#include <string.h>
#include "obrttg_solver_defines.h"


/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1


/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void nlp3_DTVsingle_96d7_parser_Outputs_wrapper(const real_T *x_initial,
			const real_T *x_target,
            const real_T *initial_guess,
			const real_T *thrust_limits,
			const real_T *vane_limits,
            const real_T *vel_norm_limit,
            const real_T *max_tilt_angle,
            const real_T *glideslope_angle,
			const real_T *current_thrust_cmd,
			real_T *lb01,
			real_T *lb02,
			real_T *lb03,
			real_T *lb04,
			real_T *lb05,
			real_T *lb06,
			real_T *lb07,
			real_T *lb08,
			real_T *lb09,
			real_T *lb10,
			real_T *lb11,
			real_T *lb12,
			real_T *lb13,
			real_T *lb14,
			real_T *lb15,
			real_T *lb16,
			real_T *lb17,
			real_T *lb18,
			real_T *lb19,
			real_T *lb20,
			real_T *lb21,
			real_T *lb22,
			real_T *lb23,
			real_T *lb24,
			real_T *lb25,
			real_T *lb26,
			real_T *lb27,
			real_T *lb28,
			real_T *lb29,
			real_T *lb30,
			real_T *ub01,
			real_T *ub02,
			real_T *ub03,
			real_T *ub04,
			real_T *ub05,
			real_T *ub06,
			real_T *ub07,
			real_T *ub08,
			real_T *ub09,
			real_T *ub10,
			real_T *ub11,
			real_T *ub12,
			real_T *ub13,
			real_T *ub14,
			real_T *ub15,
			real_T *ub16,
			real_T *ub17,
			real_T *ub18,
			real_T *ub19,
			real_T *ub20,
			real_T *ub21,
			real_T *ub22,
			real_T *ub23,
			real_T *ub24,
			real_T *ub25,
			real_T *ub26,
			real_T *ub27,
			real_T *ub28,
			real_T *ub29,
			real_T *ub30,
			real_T *hu02,
			real_T *hu03,
			real_T *hu04,
			real_T *hu05,
			real_T *hu06,
			real_T *hu07,
			real_T *hu08,
			real_T *hu09,
			real_T *hu10,
			real_T *hu11,
			real_T *hu12,
			real_T *hu13,
			real_T *hu14,
			real_T *hu15,
			real_T *hu16,
			real_T *hu17,
			real_T *hu18,
			real_T *hu19,
			real_T *hu20,
			real_T *hu21,
			real_T *hu22,
			real_T *hu23,
			real_T *hu24,
			real_T *hu25,
			real_T *hu26,
			real_T *hu27,
			real_T *hu28,
			real_T *hu29,
			real_T *x0,
			real_T *xinit,
			real_T *all_parameters,
			real_T *NumberIneqVec)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
    
    double glideslope_origin[3] = {0};
    int k;
    const real_T *current_attitude = x_initial + 7; /* quaternion */
    const real_T current_direction = 1 - 2 * (current_attitude[2] * current_attitude[2] + current_attitude[3] * current_attitude[3]);
    const real_T current_tilt_angle = acos(current_direction);
	const real_T velCurrentNorm = sqrt(x_initial[4] * x_initial[4] + x_initial[5] * x_initial[5] + x_initial[6] * x_initial[6]);
    
    double Ts_nom;
    double Ts_max;
    double lb1[7];
    double ub1[7];
    double lb2[7];
    double ub2[6];
    double lbN[4];
    double ubN[3];
    double hu1[4];
    double hu3[4];
    
    double forceVertMin = thrust_limits[0];
    double forceVertMax = thrust_limits[1] - thrust_limits[1]*VANES_DRAG_FACTOR;
    double forceLatMin = forceVertMax*sin(-TV_ANGLE_ABS_MAX);
    double forceLatMax = forceVertMax*sin(TV_ANGLE_ABS_MAX);
    double forceLatBodyMaxNow = thrust_limits[1]*MAX_NOMINAL_VANE_FORCE;
    double forceLatMinNow = current_tilt_angle*6.333333 - forceLatBodyMaxNow;
    double forceLatMaxNow = current_tilt_angle*6.333333 + forceLatBodyMaxNow;
    
    if (x_target[0] > x_initial[1])
    {
        /* Ascent Trajectory -> Glideslope origin positioned at the inertial reference system origin */
        glideslope_origin[0] = 0.0;
        glideslope_origin[1] = 0.0;
        glideslope_origin[2] = 0.0;
    }
    else
    {
        /* Descent Trajectory -> Glideslope origin positioned under the target position */
        glideslope_origin[0] = x_target[0] - LANDING_SWITCH_HEIGHT;
        glideslope_origin[1] = x_target[1];
        glideslope_origin[2] = x_target[2];
    }

    memcpy(x0, initial_guess, X0_SIZE*sizeof(real_T));        
    memcpy(xinit, x_initial, XINIT_SIZE*sizeof(real_T));
    
    
    for (k = 0; k < (N_STAGES - 1); k++)
    {
        /* Glideslope origin is used in the N-1 first stages */
        memcpy(&all_parameters[N_PARAMS_1*k + 2], 
        glideslope_origin, 3*sizeof(double));
        all_parameters[N_PARAMS_1*k + 0] = cos(max_tilt_angle[0]);
        all_parameters[N_PARAMS_1*k + 5] = tan(glideslope_angle[0]);
        all_parameters[N_PARAMS_1*k + 1] = forceVertMax;
    }
    /* Target position and velocity are used as parameters in the last stage */
    memcpy(&all_parameters[N_PARAMS_1*(N_STAGES - 1) + 0], 
    &x_target[0], 3*sizeof(double));
    memcpy(&all_parameters[N_PARAMS_1*(N_STAGES - 1) + 3], 
    &x_target[3], 3*sizeof(double));
    /* Check if the current state satisfies the glideslope constraint. if so, disable the 
    glideslope constraint (constraint 3) for the first 20 steps of the trajectory */
    double tmp_norm = sqrt( (x_initial[2]-glideslope_origin[1])*(x_initial[2]-glideslope_origin[1])
                          + (x_initial[3]-glideslope_origin[2])*(x_initial[3]-glideslope_origin[2]) );
    if ( tmp_norm > (x_initial[1]-glideslope_origin[0])*tan(glideslope_angle[0]) ) 
    { 
       for (k = 0; k < 15; k++)
       { 
          NumberIneqVec[k] = 3; 
       } 
    }
    else
    {
       for (k = 0; k < 15; k++)
        { 
            NumberIneqVec[k] = 4; 
        } 
    }
    /* Assign rest of the stages */
    for (k = 15; k < (N_STAGES - 1); k++)
    {
        NumberIneqVec[k] = 4;
    }
    NumberIneqVec[N_STAGES - 1] = 2; 
    NumberIneqVec[0] = 2; 

    
    
    Ts_nom = initial_guess[MASS_IDX_1 + 7];
    Ts_max = fmin(fmax(Ts_nom,0.4),MAX_TIME_STEP);
    lb1[0] = -MAX_VERT_THRUST_RATE;
    lb1[1] = -MAX_LAT_THRUST_RATE;
    lb1[2] = -MAX_LAT_THRUST_RATE;
    lb1[3] = forceVertMin;
    lb1[4] = forceLatMinNow;
    lb1[5] = forceLatMinNow;
    lb1[6] = MIN_TIME_STEP;
    ub1[0] = +MAX_VERT_THRUST_RATE;
    ub1[1] = +MAX_LAT_THRUST_RATE;
    ub1[2] = +MAX_LAT_THRUST_RATE;
    ub1[3] = forceVertMax;
    if (lb1[3] >= ub1[3]) ub1[3] = lb1[3] + 0.1;
    ub1[4] = forceLatMaxNow;
    if (lb1[4] >= ub1[4]) ub1[4] = lb1[4] + 0.1;
    ub1[5] = forceLatMaxNow;
    if (lb1[5] >= ub1[5]) ub1[5] = lb1[5] + 0.1;
    ub1[6] = Ts_max;
    lb2[0] = -MAX_VERT_THRUST_RATE;
    lb2[1] = -MAX_LAT_THRUST_RATE;
    lb2[2] = -MAX_LAT_THRUST_RATE;
    lb2[3] = forceVertMin;
    lb2[4] = forceLatMin;
    lb2[5] = forceLatMin;
    lb2[6] = MIN_TIME_STEP;
    ub2[0] = +MAX_VERT_THRUST_RATE;
    ub2[1] = +MAX_LAT_THRUST_RATE;
    ub2[2] = +MAX_LAT_THRUST_RATE;
    ub2[3] = forceLatMax;
    ub2[4] = forceLatMax;
    ub2[5] = Ts_max;
    lbN[0] = forceVertMin;
    lbN[1] = forceLatMin;
    lbN[2] = forceLatMin;
    lbN[3] = MIN_TIME_STEP;
    ubN[0] = forceLatMax;
    ubN[1] = forceLatMax;
    ubN[2] = Ts_max;

    hu1[0] = vel_norm_limit[0];
    hu1[1] = 0.0;
    hu1[2] = 0.0;
    hu1[3] = 0.0;
    hu3[0] = vel_norm_limit[0];
    hu3[1] = 0.0;
    hu3[2] = 0.0;
    hu3[3] = 0.0;
    
    memcpy(lb01, lb1, 7*sizeof(real_T));
    memcpy(ub01, ub1, 7*sizeof(real_T));
    memcpy(lb02, lb2, 7*sizeof(real_T));
    memcpy(ub02, ub2, 6*sizeof(real_T));
    memcpy(hu02, hu1, 4*sizeof(real_T));
    memcpy(lb03, lb2, 7*sizeof(real_T));
    memcpy(ub03, ub2, 6*sizeof(real_T));
    memcpy(hu03, hu3, 4*sizeof(real_T));
    memcpy(lb04, lb2, 7*sizeof(real_T));
    memcpy(ub04, ub2, 6*sizeof(real_T));
    memcpy(hu04, hu3, 4*sizeof(real_T));
    memcpy(lb05, lb2, 7*sizeof(real_T));
    memcpy(ub05, ub2, 6*sizeof(real_T));
    memcpy(hu05, hu3, 4*sizeof(real_T));
    memcpy(lb06, lb2, 7*sizeof(real_T));
    memcpy(ub06, ub2, 6*sizeof(real_T));
    memcpy(hu06, hu3, 4*sizeof(real_T));
    memcpy(lb07, lb2, 7*sizeof(real_T));
    memcpy(ub07, ub2, 6*sizeof(real_T));
    memcpy(hu07, hu3, 4*sizeof(real_T));
    memcpy(lb08, lb2, 7*sizeof(real_T));
    memcpy(ub08, ub2, 6*sizeof(real_T));
    memcpy(hu08, hu3, 4*sizeof(real_T));
    memcpy(lb09, lb2, 7*sizeof(real_T));
    memcpy(ub09, ub2, 6*sizeof(real_T));
    memcpy(hu09, hu3, 4*sizeof(real_T));
    memcpy(lb10, lb2, 7*sizeof(real_T));
    memcpy(ub10, ub2, 6*sizeof(real_T));
    memcpy(hu10, hu3, 4*sizeof(real_T));
    memcpy(lb11, lb2, 7*sizeof(real_T));
    memcpy(ub11, ub2, 6*sizeof(real_T));
    memcpy(hu11, hu3, 4*sizeof(real_T));
    memcpy(lb12, lb2, 7*sizeof(real_T));
    memcpy(ub12, ub2, 6*sizeof(real_T));
    memcpy(hu12, hu3, 4*sizeof(real_T));
    memcpy(lb13, lb2, 7*sizeof(real_T));
    memcpy(ub13, ub2, 6*sizeof(real_T));
    memcpy(hu13, hu3, 4*sizeof(real_T));
    memcpy(lb14, lb2, 7*sizeof(real_T));
    memcpy(ub14, ub2, 6*sizeof(real_T));
    memcpy(hu14, hu3, 4*sizeof(real_T));
    memcpy(lb15, lb2, 7*sizeof(real_T));
    memcpy(ub15, ub2, 6*sizeof(real_T));
    memcpy(hu15, hu3, 4*sizeof(real_T));
    memcpy(lb16, lb2, 7*sizeof(real_T));
    memcpy(ub16, ub2, 6*sizeof(real_T));
    memcpy(hu16, hu3, 4*sizeof(real_T));
    memcpy(lb17, lb2, 7*sizeof(real_T));
    memcpy(ub17, ub2, 6*sizeof(real_T));
    memcpy(hu17, hu3, 4*sizeof(real_T));
    memcpy(lb18, lb2, 7*sizeof(real_T));
    memcpy(ub18, ub2, 6*sizeof(real_T));
    memcpy(hu18, hu3, 4*sizeof(real_T));
    memcpy(lb19, lb2, 7*sizeof(real_T));
    memcpy(ub19, ub2, 6*sizeof(real_T));
    memcpy(hu19, hu3, 4*sizeof(real_T));
    memcpy(lb20, lb2, 7*sizeof(real_T));
    memcpy(ub20, ub2, 6*sizeof(real_T));
    memcpy(hu20, hu3, 4*sizeof(real_T));
    memcpy(lb21, lb2, 7*sizeof(real_T));
    memcpy(ub21, ub2, 6*sizeof(real_T));
    memcpy(hu21, hu3, 4*sizeof(real_T));
    memcpy(lb22, lb2, 7*sizeof(real_T));
    memcpy(ub22, ub2, 6*sizeof(real_T));
    memcpy(hu22, hu3, 4*sizeof(real_T));
    memcpy(lb23, lb2, 7*sizeof(real_T));
    memcpy(ub23, ub2, 6*sizeof(real_T));
    memcpy(hu23, hu3, 4*sizeof(real_T));
    memcpy(lb24, lb2, 7*sizeof(real_T));
    memcpy(ub24, ub2, 6*sizeof(real_T));
    memcpy(hu24, hu3, 4*sizeof(real_T));
    memcpy(lb25, lb2, 7*sizeof(real_T));
    memcpy(ub25, ub2, 6*sizeof(real_T));
    memcpy(hu25, hu3, 4*sizeof(real_T));
    memcpy(lb26, lb2, 7*sizeof(real_T));
    memcpy(ub26, ub2, 6*sizeof(real_T));
    memcpy(hu26, hu3, 4*sizeof(real_T));
    memcpy(lb27, lb2, 7*sizeof(real_T));
    memcpy(ub27, ub2, 6*sizeof(real_T));
    memcpy(hu27, hu3, 4*sizeof(real_T));
    memcpy(lb28, lb2, 7*sizeof(real_T));
    memcpy(ub28, ub2, 6*sizeof(real_T));
    memcpy(hu28, hu3, 4*sizeof(real_T));
    memcpy(lb29, lb2, 7*sizeof(real_T));
    memcpy(ub29, ub2, 6*sizeof(real_T));
    memcpy(hu29, hu3, 4*sizeof(real_T));
    memcpy(lb30, lbN, 4*sizeof(real_T));
    memcpy(ub30, ubN, 3*sizeof(real_T));

}



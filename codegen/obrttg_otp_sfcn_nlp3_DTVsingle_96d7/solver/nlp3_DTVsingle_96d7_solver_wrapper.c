/* include FORCES functions and defs */

#include "nlp3minFuel_DTVs_6515.h"
#include "nlp3minError_DTVs_d42f.h"
#include "obrttg_solver_defines.h"

#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

typedef nlp3minFuel_DTVs_6515interface_float nlp3minFuel_DTVs_6515nmpc_float;


extern void nlp3minFuel_DTVs_6515_casadi2forces(
            double *x, 
            double *y, 
            double *l, 
            double *p, 
            double *f, 
            double *nabla_f, 
            double *c, 
            double *nabla_c, 
            double *h, 
            double *nabla_h, 
            double *hess,
            solver_int32_default stage, 
            solver_int32_default iteration);

nlp3minFuel_DTVs_6515_extfunc pt2function = &nlp3minFuel_DTVs_6515_casadi2forces;

extern void nlp3minError_DTVs_d42f_casadi2forces(
            double *x, 
            double *y, 
            double *l, 
            double *p, 
            double *f, 
            double *nabla_f, 
            double *c, 
            double *nabla_c, 
            double *h, 
            double *nabla_h, 
            double *hess,
            solver_int32_default stage, 
            solver_int32_default iteration);

nlp3minError_DTVs_d42f_extfunc pt2function_min_error = &nlp3minError_DTVs_d42f_casadi2forces;


/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <string.h> /* memcpy */
#include <stdint.h> /* Standard integer library */
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
void nlp3_DTVsingle_96d7_Outputs_wrapper(
     const real_T *lb01,
     const real_T *lb02,
     const real_T *lb03,
     const real_T *lb04,
     const real_T *lb05,
     const real_T *lb06,
     const real_T *lb07,
     const real_T *lb08,
     const real_T *lb09,
     const real_T *lb10,
     const real_T *lb11,
     const real_T *lb12,
     const real_T *lb13,
     const real_T *lb14,
     const real_T *lb15,
     const real_T *lb16,
     const real_T *lb17,
     const real_T *lb18,
     const real_T *lb19,
     const real_T *lb20,
     const real_T *lb21,
     const real_T *lb22,
     const real_T *lb23,
     const real_T *lb24,
     const real_T *lb25,
     const real_T *lb26,
     const real_T *lb27,
     const real_T *lb28,
     const real_T *lb29,
     const real_T *lb30,
     const real_T *ub01,
     const real_T *ub02,
     const real_T *ub03,
     const real_T *ub04,
     const real_T *ub05,
     const real_T *ub06,
     const real_T *ub07,
     const real_T *ub08,
     const real_T *ub09,
     const real_T *ub10,
     const real_T *ub11,
     const real_T *ub12,
     const real_T *ub13,
     const real_T *ub14,
     const real_T *ub15,
     const real_T *ub16,
     const real_T *ub17,
     const real_T *ub18,
     const real_T *ub19,
     const real_T *ub20,
     const real_T *ub21,
     const real_T *ub22,
     const real_T *ub23,
     const real_T *ub24,
     const real_T *ub25,
     const real_T *ub26,
     const real_T *ub27,
     const real_T *ub28,
     const real_T *ub29,
     const real_T *ub30,
     const real_T *hu02,
     const real_T *hu03,
     const real_T *hu04,
     const real_T *hu05,
     const real_T *hu06,
     const real_T *hu07,
     const real_T *hu08,
     const real_T *hu09,
     const real_T *hu10,
     const real_T *hu11,
     const real_T *hu12,
     const real_T *hu13,
     const real_T *hu14,
     const real_T *hu15,
     const real_T *hu16,
     const real_T *hu17,
     const real_T *hu18,
     const real_T *hu19,
     const real_T *hu20,
     const real_T *hu21,
     const real_T *hu22,
     const real_T *hu23,
     const real_T *hu24,
     const real_T *hu25,
     const real_T *hu26,
     const real_T *hu27,
     const real_T *hu28,
     const real_T *hu29,
     const real_T *x0,
     const real_T *xinit,
     const real_T *all_parameters,
     const real_T *NumberIneqVec,
           real_T *outputs,
           real_T *solver_exitflag,
           real_T *iterations,
           real_T *solve_time,
           real_T *min_fuel_formulation_flag,
           real_T *primal_obj)
{
    /* Iterator variables */
    solver_int32_default i, j, k;
	
    /* file pointer for printing */
	FILE *fp = NULL;
    
    /* Solver exitflag */
	solver_int32_default exitflag;
    
    /* Additional variables initialization */
    /* Declare variables that are used by the minimum-fuel problem solver */
	nlp3minFuel_DTVs_6515_params params;
	nlp3minFuel_DTVs_6515_output output;
	nlp3minFuel_DTVs_6515_info info;	    
    
    /*Declare variables that are used by the minimum-landing-error problem solver */
    nlp3minError_DTVs_d42f_params params_min_error;
    nlp3minError_DTVs_d42f_output output_min_error;
    nlp3minError_DTVs_d42f_info info_min_error;
    
    /* hu02[0] corresponds to the maximum velocity norm */
    double hu1_min_error[3] = { hu02[0], 0.0, 0.0};
    double lbN_min_error[5] = { lb02[3], lb02[4], lb02[5], MASS_DRY + LANDING_FUEL, MIN_TIME_STEP};
    double targetAltitude = all_parameters[(N_STAGES-1)*N_PARAMS_1];
    double currentAltitude = xinit[1];

	/* Declare variables used to double check the final position and velocity */
	double temp;
	double final_position_error_norm = 0;
	double final_velocity_error_norm = 0;
	uint16_t iter = 0;


    /* Copy inputs */
    for ( i = 0; i < 7; i++ )
    {
        params.lb01[i] = (double) lb01[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb02[i] = (double) lb02[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb03[i] = (double) lb03[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb04[i] = (double) lb04[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb05[i] = (double) lb05[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb06[i] = (double) lb06[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb07[i] = (double) lb07[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb08[i] = (double) lb08[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb09[i] = (double) lb09[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb10[i] = (double) lb10[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb11[i] = (double) lb11[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb12[i] = (double) lb12[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb13[i] = (double) lb13[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb14[i] = (double) lb14[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb15[i] = (double) lb15[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb16[i] = (double) lb16[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb17[i] = (double) lb17[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb18[i] = (double) lb18[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb19[i] = (double) lb19[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb20[i] = (double) lb20[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb21[i] = (double) lb21[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb22[i] = (double) lb22[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb23[i] = (double) lb23[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb24[i] = (double) lb24[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb25[i] = (double) lb25[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb26[i] = (double) lb26[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb27[i] = (double) lb27[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb28[i] = (double) lb28[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.lb29[i] = (double) lb29[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.lb30[i] = (double) lb30[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.ub01[i] = (double) ub01[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub02[i] = (double) ub02[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub03[i] = (double) ub03[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub04[i] = (double) ub04[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub05[i] = (double) ub05[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub06[i] = (double) ub06[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub07[i] = (double) ub07[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub08[i] = (double) ub08[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub09[i] = (double) ub09[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub10[i] = (double) ub10[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub11[i] = (double) ub11[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub12[i] = (double) ub12[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub13[i] = (double) ub13[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub14[i] = (double) ub14[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub15[i] = (double) ub15[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub16[i] = (double) ub16[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub17[i] = (double) ub17[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub18[i] = (double) ub18[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub19[i] = (double) ub19[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub20[i] = (double) ub20[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub21[i] = (double) ub21[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub22[i] = (double) ub22[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub23[i] = (double) ub23[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub24[i] = (double) ub24[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub25[i] = (double) ub25[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub26[i] = (double) ub26[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub27[i] = (double) ub27[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub28[i] = (double) ub28[i];
    }

    for ( i = 0; i < 6; i++ )
    {
        params.ub29[i] = (double) ub29[i];
    }

    for ( i = 0; i < 3; i++ )
    {
        params.ub30[i] = (double) ub30[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu02[i] = (double) hu02[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu03[i] = (double) hu03[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu04[i] = (double) hu04[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu05[i] = (double) hu05[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu06[i] = (double) hu06[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu07[i] = (double) hu07[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu08[i] = (double) hu08[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu09[i] = (double) hu09[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu10[i] = (double) hu10[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu11[i] = (double) hu11[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu12[i] = (double) hu12[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu13[i] = (double) hu13[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu14[i] = (double) hu14[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu15[i] = (double) hu15[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu16[i] = (double) hu16[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu17[i] = (double) hu17[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu18[i] = (double) hu18[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu19[i] = (double) hu19[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu20[i] = (double) hu20[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu21[i] = (double) hu21[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu22[i] = (double) hu22[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu23[i] = (double) hu23[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu24[i] = (double) hu24[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu25[i] = (double) hu25[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu26[i] = (double) hu26[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu27[i] = (double) hu27[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu28[i] = (double) hu28[i];
    }

    for ( i = 0; i < 4; i++ )
    {
        params.hu29[i] = (double) hu29[i];
    }

    for ( i = 0; i < 446; i++ )
    {
        params.x0[i] = (double) x0[i];
    }

    for ( i = 0; i < 7; i++ )
    {
        params.xinit[i] = (double) xinit[i];
    }

    for ( i = 0; i < 180; i++ )
    {
        params.all_parameters[i] = (double) all_parameters[i];
    }

    for ( i = 0; i < 30; i++ )
    {
        params.NumberIneqVec[i] = (double) NumberIneqVec[i];
    }


    #if nlp3minFuel_DTVs_6515_SET_PRINTLEVEL > 0
		/* Prepare file for printfs */
        fp = fopen("stdout_temp","w+");
		if( fp == NULL ) 
		{
			mexErrMsgTxt("freopen of stdout did not work.");
		}
		rewind(fp);
	#endif
        
    /* Call Solver */
    /* minimum fuel formulation is used by default */
    min_fuel_formulation_flag[0] = 1;
    /* Call minimum-fuel problem solver */
    exitflag = nlp3minFuel_DTVs_6515_solve(&params, &output, &info, fp, pt2function);
    
	/* If the solver has not fully converged but the solution is feasible, accept it */
	if ((exitflag != 1) && (info.res_ineq <= 1E-3) && (info.res_eq <= 1E-3))
	{
		exitflag = 1;
	}

	/* compute error norms for final position and velocity */
	for (iter = 0; iter < 3; iter++)
	{
		temp = output.x30[MASS_IDX_N + 1 + iter] - all_parameters[(N_STAGES - 1)*N_PARAMS_1 + iter];
		temp = temp * temp;
		final_position_error_norm += temp;
		
		temp = output.x30[MASS_IDX_N + 4 + iter] - all_parameters[(N_STAGES - 1)*N_PARAMS_1 + 3 + iter];
		temp = temp * temp;
		final_velocity_error_norm += temp;;
	}
	final_position_error_norm = sqrt(final_position_error_norm);
	final_velocity_error_norm = sqrt(final_velocity_error_norm);

	/* Double check the final position and velocity to make sure they are consistent with what expected */
	if ((exitflag == 1) && ((final_position_error_norm >= POS_TOL) || (final_velocity_error_norm >= VEL_TOL)))
	{
		exitflag = 0;
	}

    /* Check the final mass */
    if ((exitflag==1) && (output.x30[MASS_IDX_N] < MASS_DRY + LANDING_FUEL) && (targetAltitude < currentAltitude))
    {
        /* If the final mass of the minimum fuel problem is greater than the dry mass, 
         * engage the minimum landing error solver. But only if we are going down. */
        
        /* Create the params structure */
        memcpy(params_min_error.lb01, params.lb01, sizeof(params_min_error.lb01));
        memcpy(params_min_error.lb02, params.lb02, sizeof(params_min_error.lb02));
        memcpy(params_min_error.lb03, params.lb03, sizeof(params_min_error.lb03));
        memcpy(params_min_error.lb04, params.lb04, sizeof(params_min_error.lb04));
        memcpy(params_min_error.lb05, params.lb05, sizeof(params_min_error.lb05));
        memcpy(params_min_error.lb06, params.lb06, sizeof(params_min_error.lb06));
        memcpy(params_min_error.lb07, params.lb07, sizeof(params_min_error.lb07));
        memcpy(params_min_error.lb08, params.lb08, sizeof(params_min_error.lb08));
        memcpy(params_min_error.lb09, params.lb09, sizeof(params_min_error.lb09));
        memcpy(params_min_error.lb10, params.lb10, sizeof(params_min_error.lb10));
        memcpy(params_min_error.lb11, params.lb11, sizeof(params_min_error.lb11));
        memcpy(params_min_error.lb12, params.lb12, sizeof(params_min_error.lb12));
        memcpy(params_min_error.lb13, params.lb13, sizeof(params_min_error.lb13));
        memcpy(params_min_error.lb14, params.lb14, sizeof(params_min_error.lb14));
        memcpy(params_min_error.lb15, params.lb15, sizeof(params_min_error.lb15));
        memcpy(params_min_error.lb16, params.lb16, sizeof(params_min_error.lb16));
        memcpy(params_min_error.lb17, params.lb17, sizeof(params_min_error.lb17));
        memcpy(params_min_error.lb18, params.lb18, sizeof(params_min_error.lb18));
        memcpy(params_min_error.lb19, params.lb19, sizeof(params_min_error.lb19));
        memcpy(params_min_error.lb20, params.lb20, sizeof(params_min_error.lb20));
        memcpy(params_min_error.lb21, params.lb21, sizeof(params_min_error.lb21));
        memcpy(params_min_error.lb22, params.lb22, sizeof(params_min_error.lb22));
        memcpy(params_min_error.lb23, params.lb23, sizeof(params_min_error.lb23));
        memcpy(params_min_error.lb24, params.lb24, sizeof(params_min_error.lb24));
        memcpy(params_min_error.lb25, params.lb25, sizeof(params_min_error.lb25));
        memcpy(params_min_error.lb26, params.lb26, sizeof(params_min_error.lb26));
        memcpy(params_min_error.lb27, params.lb27, sizeof(params_min_error.lb27));
        memcpy(params_min_error.lb28, params.lb28, sizeof(params_min_error.lb28));
        memcpy(params_min_error.lb29, params.lb29, sizeof(params_min_error.lb29));
        memcpy(params_min_error.lb30, lbN_min_error, sizeof(params_min_error.lb30));
        memcpy(params_min_error.ub01, params.ub01, sizeof(params_min_error.ub01));
        memcpy(params_min_error.ub02, params.ub02, sizeof(params_min_error.ub02));
        memcpy(params_min_error.ub03, params.ub03, sizeof(params_min_error.ub03));
        memcpy(params_min_error.ub04, params.ub04, sizeof(params_min_error.ub04));
        memcpy(params_min_error.ub05, params.ub05, sizeof(params_min_error.ub05));
        memcpy(params_min_error.ub06, params.ub06, sizeof(params_min_error.ub06));
        memcpy(params_min_error.ub07, params.ub07, sizeof(params_min_error.ub07));
        memcpy(params_min_error.ub08, params.ub08, sizeof(params_min_error.ub08));
        memcpy(params_min_error.ub09, params.ub09, sizeof(params_min_error.ub09));
        memcpy(params_min_error.ub10, params.ub10, sizeof(params_min_error.ub10));
        memcpy(params_min_error.ub11, params.ub11, sizeof(params_min_error.ub11));
        memcpy(params_min_error.ub12, params.ub12, sizeof(params_min_error.ub12));
        memcpy(params_min_error.ub13, params.ub13, sizeof(params_min_error.ub13));
        memcpy(params_min_error.ub14, params.ub14, sizeof(params_min_error.ub14));
        memcpy(params_min_error.ub15, params.ub15, sizeof(params_min_error.ub15));
        memcpy(params_min_error.ub16, params.ub16, sizeof(params_min_error.ub16));
        memcpy(params_min_error.ub17, params.ub17, sizeof(params_min_error.ub17));
        memcpy(params_min_error.ub18, params.ub18, sizeof(params_min_error.ub18));
        memcpy(params_min_error.ub19, params.ub19, sizeof(params_min_error.ub19));
        memcpy(params_min_error.ub20, params.ub20, sizeof(params_min_error.ub20));
        memcpy(params_min_error.ub21, params.ub21, sizeof(params_min_error.ub21));
        memcpy(params_min_error.ub22, params.ub22, sizeof(params_min_error.ub22));
        memcpy(params_min_error.ub23, params.ub23, sizeof(params_min_error.ub23));
        memcpy(params_min_error.ub24, params.ub24, sizeof(params_min_error.ub24));
        memcpy(params_min_error.ub25, params.ub25, sizeof(params_min_error.ub25));
        memcpy(params_min_error.ub26, params.ub26, sizeof(params_min_error.ub26));
        memcpy(params_min_error.ub27, params.ub27, sizeof(params_min_error.ub27));
        memcpy(params_min_error.ub28, params.ub28, sizeof(params_min_error.ub28));
        memcpy(params_min_error.ub29, params.ub29, sizeof(params_min_error.ub29));
        memcpy(params_min_error.ub30, params.ub30, sizeof(params_min_error.ub30));
        memcpy(params_min_error.hu02, hu1_min_error, sizeof(params_min_error.hu02));
        memcpy(params_min_error.hu03, hu1_min_error, sizeof(params_min_error.hu03));
        memcpy(params_min_error.hu04, hu1_min_error, sizeof(params_min_error.hu04));
        memcpy(params_min_error.hu05, hu1_min_error, sizeof(params_min_error.hu05));
        memcpy(params_min_error.hu06, hu1_min_error, sizeof(params_min_error.hu06));
        memcpy(params_min_error.hu07, hu1_min_error, sizeof(params_min_error.hu07));
        memcpy(params_min_error.hu08, hu1_min_error, sizeof(params_min_error.hu08));
        memcpy(params_min_error.hu09, hu1_min_error, sizeof(params_min_error.hu09));
        memcpy(params_min_error.hu10, hu1_min_error, sizeof(params_min_error.hu10));
        memcpy(params_min_error.hu11, hu1_min_error, sizeof(params_min_error.hu11));
        memcpy(params_min_error.hu12, hu1_min_error, sizeof(params_min_error.hu12));
        memcpy(params_min_error.hu13, hu1_min_error, sizeof(params_min_error.hu13));
        memcpy(params_min_error.hu14, hu1_min_error, sizeof(params_min_error.hu14));
        memcpy(params_min_error.hu15, hu1_min_error, sizeof(params_min_error.hu15));
        memcpy(params_min_error.hu16, hu1_min_error, sizeof(params_min_error.hu16));
        memcpy(params_min_error.hu17, hu1_min_error, sizeof(params_min_error.hu17));
        memcpy(params_min_error.hu18, hu1_min_error, sizeof(params_min_error.hu18));
        memcpy(params_min_error.hu19, hu1_min_error, sizeof(params_min_error.hu19));
        memcpy(params_min_error.hu20, hu1_min_error, sizeof(params_min_error.hu20));
        memcpy(params_min_error.hu21, hu1_min_error, sizeof(params_min_error.hu21));
        memcpy(params_min_error.hu22, hu1_min_error, sizeof(params_min_error.hu22));
        memcpy(params_min_error.hu23, hu1_min_error, sizeof(params_min_error.hu23));
        memcpy(params_min_error.hu24, hu1_min_error, sizeof(params_min_error.hu24));
        memcpy(params_min_error.hu25, hu1_min_error, sizeof(params_min_error.hu25));
        memcpy(params_min_error.hu26, hu1_min_error, sizeof(params_min_error.hu26));
        memcpy(params_min_error.hu27, hu1_min_error, sizeof(params_min_error.hu27));
        memcpy(params_min_error.hu28, hu1_min_error, sizeof(params_min_error.hu28));
        memcpy(params_min_error.hu29, hu1_min_error, sizeof(params_min_error.hu29));
        memcpy(params_min_error.x0, params.x0, sizeof(params_min_error.x0));
        memcpy(params_min_error.xinit, params.xinit, sizeof(params_min_error.xinit));
        memcpy(params_min_error.all_parameters, params.all_parameters, sizeof(params_min_error.all_parameters));
                
        /* Call minimum-landing-error problem solver */
        exitflag = nlp3minError_DTVs_d42f_solve(&params_min_error, &output_min_error, 
                                                 &info_min_error, fp, pt2function_min_error);
        /* Set min_fuel_formulation flag to false when using the minimum error forumation */
        min_fuel_formulation_flag[0] = 0;
        /* Sum up min_error and min_fuel solve time and iterations */
        info_min_error.solvetime += info.solvetime;
        info_min_error.it += info.it;
        /* Update output array and info structure */
        memcpy(&output, &output_min_error, sizeof(nlp3minFuel_DTVs_6515_output));
        memcpy(&info, &info_min_error, sizeof(nlp3minFuel_DTVs_6515_info));
    }

    
    #if nlp3minFuel_DTVs_6515_SET_PRINTLEVEL > 0
		/* Read contents of printfs printed to file */
		rewind(fp);
		while( (i = fgetc(fp)) != EOF ) 
		{
			ssPrintf("%c",i);
		}
		fclose(fp);
	#endif
        
    /* Copy outputs */
    k=0;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x01[i];
    }

    k=15;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x02[i];
    }

    k=30;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x03[i];
    }

    k=45;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x04[i];
    }

    k=60;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x05[i];
    }

    k=75;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x06[i];
    }

    k=90;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x07[i];
    }

    k=105;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x08[i];
    }

    k=120;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x09[i];
    }

    k=135;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x10[i];
    }

    k=150;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x11[i];
    }

    k=165;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x12[i];
    }

    k=180;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x13[i];
    }

    k=195;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x14[i];
    }

    k=210;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x15[i];
    }

    k=225;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x16[i];
    }

    k=240;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x17[i];
    }

    k=255;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x18[i];
    }

    k=270;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x19[i];
    }

    k=285;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x20[i];
    }

    k=300;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x21[i];
    }

    k=315;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x22[i];
    }

    k=330;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x23[i];
    }

    k=345;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x24[i];
    }

    k=360;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x25[i];
    }

    k=375;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x26[i];
    }

    k=390;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x27[i];
    }

    k=405;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x28[i];
    }

    k=420;
    for ( i = 0; i < 15; i++ )
    {
        outputs[k+i] = (real_T) output.x29[i];
    }

    k=435;
    for ( i = 0; i < 11; i++ )
    {
        outputs[k+i] = (real_T) output.x30[i];
    }


    
    /* solver statistics */
	iterations[0] = info.it;
	solve_time[0] = info.solvetime;
	primal_obj[0] = info.pobj;
	solver_exitflag[0] = exitflag;
}



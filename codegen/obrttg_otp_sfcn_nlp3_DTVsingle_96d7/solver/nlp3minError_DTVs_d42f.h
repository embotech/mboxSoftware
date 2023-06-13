/*
nlp3minError_DTVs_d42f : A fast customized optimization solver.

Copyright (C) 2013-2021 EMBOTECH AG [info@embotech.com]. All rights reserved.


This program is distributed in the hope that it will be useful.
EMBOTECH makes NO WARRANTIES with respect to the use of the software 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
PARTICULAR PURPOSE. 

EMBOTECH shall not have any liability for any damage arising from the use
of the software.

This Agreement shall exclusively be governed by and interpreted in 
accordance with the laws of Switzerland, excluding its principles
of conflict of laws. The Courts of Zurich-City shall have exclusive 
jurisdiction in case of any dispute.

*/

/* Generated by FORCESPRO v5.1.0 on Wednesday, March 30, 2022 at 4:56:18 PM */
#ifndef nlp3minError_DTVs_d42f_H
#define nlp3minError_DTVs_d42f_H

#ifndef SOLVER_STDIO_H
#define SOLVER_STDIO_H
#include <stdio.h>
#endif


#ifndef SOLVER_STANDARD_TYPES
#define SOLVER_STANDARD_TYPES

typedef signed char solver_int8_signed;
typedef unsigned char solver_int8_unsigned;
typedef char solver_int8_default;
typedef signed short int solver_int16_signed;
typedef unsigned short int solver_int16_unsigned;
typedef short int solver_int16_default;
typedef signed int solver_int32_signed;
typedef unsigned int solver_int32_unsigned;
typedef int solver_int32_default;
typedef signed long long int solver_int64_signed;
typedef unsigned long long int solver_int64_unsigned;
typedef long long int solver_int64_default;

#endif


/* DATA TYPE ------------------------------------------------------------*/
typedef double nlp3minError_DTVs_d42f_float;
typedef double nlp3minError_DTVs_d42f_ldl_s_float;
typedef double nlp3minError_DTVs_d42f_ldl_r_float;
typedef double nlp3minError_DTVs_d42f_callback_float;

typedef double nlp3minError_DTVs_d42finterface_float;

/* SOLVER SETTINGS ------------------------------------------------------*/

/* MISRA-C compliance */
#ifndef MISRA_C_nlp3minError_DTVs_d42f
#define MISRA_C_nlp3minError_DTVs_d42f (0)
#endif

/* restrict code */
#ifndef RESTRICT_CODE_nlp3minError_DTVs_d42f
#define RESTRICT_CODE_nlp3minError_DTVs_d42f (0)
#endif

/* print level */
#ifndef SET_PRINTLEVEL_nlp3minError_DTVs_d42f
#define SET_PRINTLEVEL_nlp3minError_DTVs_d42f    (0)
#endif

/* timing */
#ifndef SET_TIMING_nlp3minError_DTVs_d42f
#define SET_TIMING_nlp3minError_DTVs_d42f    (0)
#endif

/* Numeric Warnings */
/* #define PRINTNUMERICALWARNINGS */

/* maximum number of iterations  */
#define SET_MAXIT_nlp3minError_DTVs_d42f			(250)	

/* scaling factor of line search (FTB rule) */
#define SET_FLS_SCALE_nlp3minError_DTVs_d42f		(nlp3minError_DTVs_d42f_float)(0.99)      

/* maximum number of supported elements in the filter */
#define MAX_FILTER_SIZE_nlp3minError_DTVs_d42f	(250) 

/* maximum number of supported elements in the filter */
#define MAX_SOC_IT_nlp3minError_DTVs_d42f			(4) 

/* desired relative duality gap */
#define SET_ACC_RDGAP_nlp3minError_DTVs_d42f		(nlp3minError_DTVs_d42f_float)(0.0001)

/* desired maximum residual on equality constraints */
#define SET_ACC_RESEQ_nlp3minError_DTVs_d42f		(nlp3minError_DTVs_d42f_float)(1E-06)

/* desired maximum residual on inequality constraints */
#define SET_ACC_RESINEQ_nlp3minError_DTVs_d42f	(nlp3minError_DTVs_d42f_float)(1E-06)

/* desired maximum violation of complementarity */
#define SET_ACC_KKTCOMPL_nlp3minError_DTVs_d42f	(nlp3minError_DTVs_d42f_float)(1E-06)


/* SOLVER RETURN CODES----------------------------------------------------------*/
/* solver has converged within desired accuracy */
#define OPTIMAL_nlp3minError_DTVs_d42f      (1)

/* maximum number of iterations has been reached */
#define MAXITREACHED_nlp3minError_DTVs_d42f (0)

/* solver has stopped due to a timeout */
#define TIMEOUT_nlp3minError_DTVs_d42f   (2)

/* wrong number of inequalities error */
#define INVALID_NUM_INEQ_ERROR_nlp3minError_DTVs_d42f  (-4)

/* factorization error */
#define FACTORIZATION_ERROR_nlp3minError_DTVs_d42f   (-5)

/* NaN encountered in function evaluations */
#define BADFUNCEVAL_nlp3minError_DTVs_d42f  (-6)

/* no progress in method possible */
#define NOPROGRESS_nlp3minError_DTVs_d42f   (-7)

/* regularization error */
#define REGULARIZATION_ERROR_nlp3minError_DTVs_d42f   (-9)

/* invalid values in parameters */
#define PARAM_VALUE_ERROR_nlp3minError_DTVs_d42f   (-11)

/* too small timeout given */
#define INVALID_TIMEOUT_nlp3minError_DTVs_d42f   (-12)

/* thread error */
#define THREAD_FAILURE_nlp3minError_DTVs_d42f  (-98)

/* locking mechanism error */
#define LOCK_FAILURE_nlp3minError_DTVs_d42f  (-99)

/* licensing error - solver not valid on this machine */
#define LICENSE_ERROR_nlp3minError_DTVs_d42f  (-100)

/* INTEGRATORS RETURN CODE ------------*/
/* Integrator ran successfully */
#define INTEGRATOR_SUCCESS (11)
/* Number of steps set by user exceeds maximum number of steps allowed */
#define INTEGRATOR_MAXSTEPS_EXCEEDED (12)





/* PARAMETERS -----------------------------------------------------------*/
/* fill this with data before calling the solver! */
typedef struct
{
    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb01[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb02[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb03[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb04[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb05[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb06[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb07[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb08[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb09[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb10[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb11[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb12[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb13[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb14[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb15[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb16[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb17[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb18[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb19[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb20[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb21[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb22[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb23[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb24[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb25[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb26[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb27[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb28[7];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float lb29[7];

    /* vector of size 5 */
    nlp3minError_DTVs_d42f_float lb30[5];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float ub01[7];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub02[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub03[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub04[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub05[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub06[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub07[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub08[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub09[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub10[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub11[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub12[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub13[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub14[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub15[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub16[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub17[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub18[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub19[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub20[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub21[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub22[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub23[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub24[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub25[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub26[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub27[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub28[6];

    /* vector of size 6 */
    nlp3minError_DTVs_d42f_float ub29[6];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float ub30[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu02[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu03[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu04[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu05[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu06[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu07[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu08[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu09[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu10[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu11[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu12[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu13[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu14[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu15[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu16[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu17[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu18[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu19[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu20[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu21[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu22[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu23[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu24[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu25[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu26[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu27[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu28[3];

    /* vector of size 3 */
    nlp3minError_DTVs_d42f_float hu29[3];

    /* vector of size 446 */
    nlp3minError_DTVs_d42f_float x0[446];

    /* vector of size 7 */
    nlp3minError_DTVs_d42f_float xinit[7];

    /* vector of size 64 */
    nlp3minError_DTVs_d42f_float all_parameters[64];


} nlp3minError_DTVs_d42f_params;


/* OUTPUTS --------------------------------------------------------------*/
/* the desired variables are put here by the solver */
typedef struct
{
    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x01[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x02[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x03[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x04[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x05[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x06[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x07[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x08[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x09[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x10[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x11[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x12[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x13[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x14[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x15[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x16[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x17[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x18[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x19[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x20[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x21[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x22[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x23[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x24[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x25[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x26[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x27[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x28[15];

    /* vector of size 15 */
    nlp3minError_DTVs_d42f_float x29[15];

    /* vector of size 11 */
    nlp3minError_DTVs_d42f_float x30[11];


} nlp3minError_DTVs_d42f_output;


/* SOLVER INFO ----------------------------------------------------------*/
/* diagnostic data from last interior point step */
typedef struct
{
    /* iteration number */
    solver_int32_default it;

	/* number of iterations needed to optimality (branch-and-bound) */
	solver_int32_default it2opt;
	
    /* inf-norm of equality constraint residuals */
    nlp3minError_DTVs_d42f_float res_eq;
	
    /* inf-norm of inequality constraint residuals */
    nlp3minError_DTVs_d42f_float res_ineq;

	/* norm of stationarity condition */
    nlp3minError_DTVs_d42f_float rsnorm;

	/* max of all complementarity violations */
    nlp3minError_DTVs_d42f_float rcompnorm;

    /* primal objective */
    nlp3minError_DTVs_d42f_float pobj;	
	
    /* dual objective */
    nlp3minError_DTVs_d42f_float dobj;	

    /* duality gap := pobj - dobj */
    nlp3minError_DTVs_d42f_float dgap;		
	
    /* relative duality gap := |dgap / pobj | */
    nlp3minError_DTVs_d42f_float rdgap;		

    /* duality measure */
    nlp3minError_DTVs_d42f_float mu;

	/* duality measure (after affine step) */
    nlp3minError_DTVs_d42f_float mu_aff;
	
    /* centering parameter */
    nlp3minError_DTVs_d42f_float sigma;
	
    /* number of backtracking line search steps (affine direction) */
    solver_int32_default lsit_aff;
    
    /* number of backtracking line search steps (combined direction) */
    solver_int32_default lsit_cc;
    
    /* step size (affine direction) */
    nlp3minError_DTVs_d42f_float step_aff;
    
    /* step size (combined direction) */
    nlp3minError_DTVs_d42f_float step_cc;    

	/* solvertime */
	nlp3minError_DTVs_d42f_float solvetime;   

	/* time spent in function evaluations */
	nlp3minError_DTVs_d42f_float fevalstime;  


} nlp3minError_DTVs_d42f_info;









/* SOLVER FUNCTION DEFINITION -------------------------------------------*/
/* Time of Solver Generation: (UTC) Wednesday, March 30, 2022 4:56:24 PM */
/* User License expires on: (UTC) Saturday, September 30, 2023 10:00:00 PM (approx.) (at the time of code generation) */
/* Solver Static License expires on: (UTC) Saturday, September 30, 2023 10:00:00 PM (approx.) */
/* Solver Generation Request Id: 7c6824d5-9d0a-45b6-8535-2deaf9a97f3c */
/* examine exitflag before using the result! */
#ifdef __cplusplus
extern "C" {
#endif		

typedef void (*nlp3minError_DTVs_d42f_extfunc)(nlp3minError_DTVs_d42f_float* x, nlp3minError_DTVs_d42f_float* y, nlp3minError_DTVs_d42f_float* lambda, nlp3minError_DTVs_d42f_float* params, nlp3minError_DTVs_d42f_float* pobj, nlp3minError_DTVs_d42f_float* g, nlp3minError_DTVs_d42f_float* c, nlp3minError_DTVs_d42f_float* Jeq, nlp3minError_DTVs_d42f_float* h, nlp3minError_DTVs_d42f_float* Jineq, nlp3minError_DTVs_d42f_float* H, solver_int32_default stage, solver_int32_default iterations, solver_int32_default threadID);

extern solver_int32_default nlp3minError_DTVs_d42f_solve(nlp3minError_DTVs_d42f_params *params, nlp3minError_DTVs_d42f_output *output, nlp3minError_DTVs_d42f_info *info, FILE *fs, nlp3minError_DTVs_d42f_extfunc evalextfunctions_nlp3minError_DTVs_d42f);	







/*Integrator declarations */
typedef const solver_int32_default* (*cDynJacXsparsity)( solver_int32_default i );
typedef const solver_int32_default* (*cDynJacUsparsity)( solver_int32_default i );
typedef solver_int32_default (*fConDynamics)( const nlp3minError_DTVs_d42f_callback_float** arg, nlp3minError_DTVs_d42f_callback_float** res, solver_int32_default* iw, nlp3minError_DTVs_d42f_callback_float* w, solver_int32_default mem );
typedef solver_int32_default (*fConJacStateDynamics)( const nlp3minError_DTVs_d42f_callback_float** arg, nlp3minError_DTVs_d42f_callback_float** res, solver_int32_default* iw, nlp3minError_DTVs_d42f_callback_float* w, solver_int32_default mem );
typedef solver_int32_default (*fConJacInputDynamics)( const nlp3minError_DTVs_d42f_callback_float** arg, nlp3minError_DTVs_d42f_callback_float** res, solver_int32_default* iw, nlp3minError_DTVs_d42f_callback_float* w, solver_int32_default mem );

void nlp3minError_DTVs_d42f_rkfour_0(const nlp3minError_DTVs_d42f_callback_float * const z, const nlp3minError_DTVs_d42f_callback_float * const p, nlp3minError_DTVs_d42f_float * const c, nlp3minError_DTVs_d42f_float * const jacc,
            fConDynamics cDyn0rd, fConDynamics cDyn, const solver_int32_default threadID);


void nlp3minError_DTVs_d42f_rkfour_1(const nlp3minError_DTVs_d42f_callback_float * const z, const nlp3minError_DTVs_d42f_callback_float * const p, nlp3minError_DTVs_d42f_float * const c, nlp3minError_DTVs_d42f_float * const jacc,
            fConDynamics cDyn0rd, fConDynamics cDyn, const solver_int32_default threadID);







#ifdef __cplusplus
}
#endif

#endif
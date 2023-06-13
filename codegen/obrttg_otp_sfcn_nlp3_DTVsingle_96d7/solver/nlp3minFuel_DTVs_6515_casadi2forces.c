/*
 * CasADi to FORCESPRO Template - missing information to be filled in by createCasadi.m 
 * (C) embotech AG, Zurich, Switzerland, 2013-2021. All rights reserved.
 *
 * This file is part of the FORCESPRO client, and carries the same license.
 */ 

#ifdef __cplusplus
extern "C" {
#endif
    
#include "nlp3minFuel_DTVs_6515.h"

#ifndef NULL
#define NULL ((void *) 0)
#endif


#include "nlp3minFuel_DTVs_6515_casadi.h"



/* copies data from sparse matrix into a dense one */
static void sparse2fullcopy(solver_int32_default nrow, solver_int32_default ncol, const solver_int32_default *colidx, const solver_int32_default *row, nlp3minFuel_DTVs_6515_callback_float *data, nlp3minFuel_DTVs_6515_float *out)
{
    solver_int32_default i, j;
    
    /* copy data into dense matrix */
    for(i=0; i<ncol; i++)
    {
        for(j=colidx[i]; j<colidx[i+1]; j++)
        {
            out[i*nrow + row[j]] = ((nlp3minFuel_DTVs_6515_float) data[j]);
        }
    }
}




/* CasADi to FORCESPRO interface */
extern void nlp3minFuel_DTVs_6515_casadi2forces(nlp3minFuel_DTVs_6515_float *x,        /* primal vars                                         */
                                 nlp3minFuel_DTVs_6515_float *y,        /* eq. constraint multiplers                           */
                                 nlp3minFuel_DTVs_6515_float *l,        /* ineq. constraint multipliers                        */
                                 nlp3minFuel_DTVs_6515_float *p,        /* parameters                                          */
                                 nlp3minFuel_DTVs_6515_float *f,        /* objective function (scalar)                         */
                                 nlp3minFuel_DTVs_6515_float *nabla_f,  /* gradient of objective function                      */
                                 nlp3minFuel_DTVs_6515_float *c,        /* dynamics                                            */
                                 nlp3minFuel_DTVs_6515_float *nabla_c,  /* Jacobian of the dynamics (column major)             */
                                 nlp3minFuel_DTVs_6515_float *h,        /* inequality constraints                              */
                                 nlp3minFuel_DTVs_6515_float *nabla_h,  /* Jacobian of inequality constraints (column major)   */
                                 nlp3minFuel_DTVs_6515_float *hess,     /* Hessian (column major)                              */
                                 solver_int32_default stage,     /* stage number (0 indexed)                           */
								 solver_int32_default iteration, /* iteration number of solver                         */
								 solver_int32_default threadID   /* Id of caller thread                                */)
{
    /* CasADi input and output arrays */
    const nlp3minFuel_DTVs_6515_callback_float *in[4];
    nlp3minFuel_DTVs_6515_callback_float *out[7];
	

	/* Allocate working arrays for CasADi */
	nlp3minFuel_DTVs_6515_callback_float w[20];
	
    /* temporary storage for CasADi sparse output */
    nlp3minFuel_DTVs_6515_callback_float this_f;
    nlp3minFuel_DTVs_6515_callback_float nabla_f_sparse[8];
    nlp3minFuel_DTVs_6515_callback_float h_sparse[4];
    nlp3minFuel_DTVs_6515_callback_float nabla_h_sparse[12];
    nlp3minFuel_DTVs_6515_callback_float c_sparse[1];
    nlp3minFuel_DTVs_6515_callback_float nabla_c_sparse[1];
            
    
    /* pointers to row and column info for 
     * column compressed format used by CasADi */
    solver_int32_default nrow, ncol;
    const solver_int32_default *colind, *row;
    
    /* set inputs for CasADi */
	in[0] = x;
	in[1] = p;
	in[2] = l;
	in[3] = y;

	if ((stage >= 0) && (stage < 1))
	{
		out[0] = &this_f;
		out[1] = nabla_f_sparse;
		nlp3minFuel_DTVs_6515_objective_1(in, out, NULL, w, 0);
		if (nabla_f != NULL)
		{
			nrow = nlp3minFuel_DTVs_6515_objective_1_sparsity_out(1)[0];
			ncol = nlp3minFuel_DTVs_6515_objective_1_sparsity_out(1)[1];
			colind = nlp3minFuel_DTVs_6515_objective_1_sparsity_out(1) + 2;
			row = nlp3minFuel_DTVs_6515_objective_1_sparsity_out(1) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, nabla_f_sparse, nabla_f);
		}

		nlp3minFuel_DTVs_6515_rkfour_0(x, p, c, nabla_c, nlp3minFuel_DTVs_6515_dynamics_0rd_0, nlp3minFuel_DTVs_6515_dynamics_0, threadID);
		out[0] = h_sparse;
		out[1] = nabla_h_sparse;
		nlp3minFuel_DTVs_6515_inequalities_1(in, out, NULL, w, 0);
		if (h != NULL)
		{
			nrow = nlp3minFuel_DTVs_6515_inequalities_1_sparsity_out(0)[0];
			ncol = nlp3minFuel_DTVs_6515_inequalities_1_sparsity_out(0)[1];
			colind = nlp3minFuel_DTVs_6515_inequalities_1_sparsity_out(0) + 2;
			row = nlp3minFuel_DTVs_6515_inequalities_1_sparsity_out(0) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, h_sparse, h);
		}

		if (nabla_h != NULL)
		{
			nrow = nlp3minFuel_DTVs_6515_inequalities_1_sparsity_out(1)[0];
			ncol = nlp3minFuel_DTVs_6515_inequalities_1_sparsity_out(1)[1];
			colind = nlp3minFuel_DTVs_6515_inequalities_1_sparsity_out(1) + 2;
			row = nlp3minFuel_DTVs_6515_inequalities_1_sparsity_out(1) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, nabla_h_sparse, nabla_h);
		}

	}

	if ((stage >= 1) && (stage < 29))
	{
		out[0] = &this_f;
		out[1] = nabla_f_sparse;
		nlp3minFuel_DTVs_6515_objective_2(in, out, NULL, w, 0);
		if (nabla_f != NULL)
		{
			nrow = nlp3minFuel_DTVs_6515_objective_2_sparsity_out(1)[0];
			ncol = nlp3minFuel_DTVs_6515_objective_2_sparsity_out(1)[1];
			colind = nlp3minFuel_DTVs_6515_objective_2_sparsity_out(1) + 2;
			row = nlp3minFuel_DTVs_6515_objective_2_sparsity_out(1) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, nabla_f_sparse, nabla_f);
		}

		nlp3minFuel_DTVs_6515_rkfour_1(x, p, c, nabla_c, nlp3minFuel_DTVs_6515_dynamics_0rd_1, nlp3minFuel_DTVs_6515_dynamics_1, threadID);
		out[0] = h_sparse;
		out[1] = nabla_h_sparse;
		nlp3minFuel_DTVs_6515_inequalities_2(in, out, NULL, w, 0);
		if (h != NULL)
		{
			nrow = nlp3minFuel_DTVs_6515_inequalities_2_sparsity_out(0)[0];
			ncol = nlp3minFuel_DTVs_6515_inequalities_2_sparsity_out(0)[1];
			colind = nlp3minFuel_DTVs_6515_inequalities_2_sparsity_out(0) + 2;
			row = nlp3minFuel_DTVs_6515_inequalities_2_sparsity_out(0) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, h_sparse, h);
		}

		if (nabla_h != NULL)
		{
			nrow = nlp3minFuel_DTVs_6515_inequalities_2_sparsity_out(1)[0];
			ncol = nlp3minFuel_DTVs_6515_inequalities_2_sparsity_out(1)[1];
			colind = nlp3minFuel_DTVs_6515_inequalities_2_sparsity_out(1) + 2;
			row = nlp3minFuel_DTVs_6515_inequalities_2_sparsity_out(1) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, nabla_h_sparse, nabla_h);
		}

	}

	if ((stage >= 29) && (stage < 30))
	{
		out[0] = &this_f;
		out[1] = nabla_f_sparse;
		nlp3minFuel_DTVs_6515_objective_30(in, out, NULL, w, 0);
		if (nabla_f != NULL)
		{
			nrow = nlp3minFuel_DTVs_6515_objective_30_sparsity_out(1)[0];
			ncol = nlp3minFuel_DTVs_6515_objective_30_sparsity_out(1)[1];
			colind = nlp3minFuel_DTVs_6515_objective_30_sparsity_out(1) + 2;
			row = nlp3minFuel_DTVs_6515_objective_30_sparsity_out(1) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, nabla_f_sparse, nabla_f);
		}

		out[0] = h_sparse;
		out[1] = nabla_h_sparse;
		nlp3minFuel_DTVs_6515_inequalities_30(in, out, NULL, w, 0);
		if (h != NULL)
		{
			nrow = nlp3minFuel_DTVs_6515_inequalities_30_sparsity_out(0)[0];
			ncol = nlp3minFuel_DTVs_6515_inequalities_30_sparsity_out(0)[1];
			colind = nlp3minFuel_DTVs_6515_inequalities_30_sparsity_out(0) + 2;
			row = nlp3minFuel_DTVs_6515_inequalities_30_sparsity_out(0) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, h_sparse, h);
		}

		if (nabla_h != NULL)
		{
			nrow = nlp3minFuel_DTVs_6515_inequalities_30_sparsity_out(1)[0];
			ncol = nlp3minFuel_DTVs_6515_inequalities_30_sparsity_out(1)[1];
			colind = nlp3minFuel_DTVs_6515_inequalities_30_sparsity_out(1) + 2;
			row = nlp3minFuel_DTVs_6515_inequalities_30_sparsity_out(1) + 2 + (ncol + 1);
			sparse2fullcopy(nrow, ncol, colind, row, nabla_h_sparse, nabla_h);
		}

	}


    
    /* add to objective */
    if (f != NULL)
    {
        *f += ((nlp3minFuel_DTVs_6515_float) this_f);
    }
}

#ifdef __cplusplus
} /* extern "C" */
#endif

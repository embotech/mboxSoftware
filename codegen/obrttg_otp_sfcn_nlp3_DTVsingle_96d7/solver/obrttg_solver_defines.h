/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 *
 * ---------------------------------------------------------------------------------------------------------
 * nlp3_DTVsingle_96d7 properties definition
 * This header file define the sizes of the solver variables and some variables required by any of the Optimal 
 * Trajectory Planner components.
 * ----------------------------------------------------------------------------------------------------------
 */

/* Macro implementation of minimum of two values */
#define MIN(a,b) (((a)<(b))?(a):(b))

/* Macro implementation of maximum of two values */
#define MAX(a,b) (((a)>(b))?(a):(b))

/* Conversion from degrees to radians */
//#define DEG2RAD                 (3.14159265/180.0)
//#define RAD2DEG                 (180.0/3.14159265)

/* Size of the initial state */
#define XINIT_SIZE              7
/* Size of the initial guess */
#define X0_SIZE                 446
/* Number of problem stages */
#define N_STAGES                30
/* Number of states in stages 1 to N-1 */
#define N_STATES_1              15
/* Number of states in stage N */
#define N_STATES_N              11
/* Number of parameters in stages 1 to N-1 */
#define N_PARAMS_1              6
/* Number of parameters in stages 1 to N-1 */
#define N_PARAMS_N              6
/* Gravity constant [m/s^2]*/
#define G0                      ((double) 9.806649999999999)
/* Engine fuel consumption [kg/N/s]*/
#define ENG_ALPHA               ((double) 0.000034166666667)
/* Vehicle dry mass [kg] */
#define MASS_DRY                ((double) 56.030000000000001)
/* Fuel mass required to land [kg] */
#define LANDING_FUEL            ((double) 0.200000000000000)
/* Mass index within the state vector in the first N-1 stages*/
#define MASS_IDX_1              7
/* Mass index within the state vector in stage N */
#define MASS_IDX_N              3
/* Maximum allowed solver iterations */
#define MAX_SOLVER_ITER         250
/* Maximum number of time of flight searches (CVX solver) */
#define MAX_TOF_SEARCH_ITER     10
/* Minimum iteration margin to try a new solve (CVX solver) */
#define SOLVER_ITER_MARGIN      15
/* Minimum time step between solver stages (NLP solver) */
#define MIN_TIME_STEP           ((double) 0.04)
/* Maximum time step between solver stages (NLP solver) */
#define MAX_TIME_STEP           ((double) 5)
/* Vanes drag factor */
#define VANES_DRAG_FACTOR       0.000000000000000
/* Maximum thrust vector deflection */
#define TV_ANGLE_ABS_MAX        0.261799387799149
/* Output trajectory state size */
#define OUT_TRAJ_N_STATES       18
/* Output trajectory state indices*/
/* Time index */
#define OUT_TRAJ_T_IDX          0
/* Forces index */
#define OUT_TRAJ_F_IDX          1
/* Mass index */
#define OUT_TRAJ_M_IDX          4
/* Position index */
#define OUT_TRAJ_X_IDX          5
/* Velocity index */
#define OUT_TRAJ_V_IDX          8
/* Attitude quaternion index */
#define OUT_TRAJ_Q_IDX          11
/* Angular rates index */
#define OUT_TRAJ_W_IDX          15
/* Maximum vertical thrust rate */
#define MAX_VERT_THRUST_RATE    ((double) 8.000000000000000)
/* Maximum lateral thrust rate */
#define MAX_LAT_THRUST_RATE		((double) 8.000000000000000)
/* Sampling time of synchronous flight software task */
#define TS_GNC					((double) 0.040000000000000)
/* Maximum nominal vane force */
#define MAX_NOMINAL_VANE_FORCE	((double) 0.146800000000000)
/* Height at which the switch from optimal to landing guidance happens */
#define LANDING_SWITCH_HEIGHT   ((double) 2.201200000000000)

/* Tolerance on final position and velocity */
#define POS_TOL    ((double) 0.100000000000000)
#define VEL_TOL    ((double) 0.100000000000000)


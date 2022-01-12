#ifndef __M43_Sim_Forcing_003h_Trajectory_sfun_h__
#define __M43_Sim_Forcing_003h_Trajectory_sfun_h__

/* Include files */
#define S_FUNCTION_NAME                sf_sfun
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "sfcdebug.h"
#define rtInf                          (mxGetInf())
#define rtMinusInf                     (-(mxGetInf()))
#define rtNaN                          (mxGetNaN())
#define rtIsNaN(X)                     ((int)mxIsNaN(X))
#define rtIsInf(X)                     ((int)mxIsInf(X))

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */
extern int32_T _sfEvent_;
extern uint32_T _M43_Sim_Forcing_003h_TrajectoryMachineNumber_;
extern real_T _sfTime_;

/* Variable Definitions */

/* Function Declarations */
extern void M43_Sim_Forcing_003h_Trajectory_initializer(void);
extern void M43_Sim_Forcing_003h_Trajectory_terminator(void);

/* Function Definitions */
#endif

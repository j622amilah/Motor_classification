#ifndef __c27_Sim_Forcing_003h_expe_infra5_full_control5_h__
#define __c27_Sim_Forcing_003h_expe_infra5_full_control5_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  char *context;
  char *name;
  char *dominantType;
  char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c27_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  ChartInfoStruct chartInfo;
} SFc27_Sim_Forcing_003h_expe_infra5_full_control5InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c27_Sim_Forcing_003h_expe_infra5_full_control5_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c27_Sim_Forcing_003h_expe_infra5_full_control5_get_check_sum
  (mxArray *plhs[]);
extern void c27_Sim_Forcing_003h_expe_infra5_full_control5_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif

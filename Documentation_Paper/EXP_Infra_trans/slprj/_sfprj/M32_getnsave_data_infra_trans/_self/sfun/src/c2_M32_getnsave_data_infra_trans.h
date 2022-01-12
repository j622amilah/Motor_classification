#ifndef __c2_M32_getnsave_data_infra_trans_h__
#define __c2_M32_getnsave_data_infra_trans_h__

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
} c2_ResolvedFunctionInfo;

typedef struct {
  real_T c2_B[210];
  real_T c2_n;
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c2_doneDoubleBufferReInit;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_M32_getnsave_data_infra_trans;
  ChartInfoStruct chartInfo;
} SFc2_M32_getnsave_data_infra_transInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_M32_getnsave_data_infra_trans_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_M32_getnsave_data_infra_trans_get_check_sum(mxArray *plhs[]);
extern void c2_M32_getnsave_data_infra_trans_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif

/* Include files */

#include "blascompat32.h"
#include "Sim_Forcing_003h_expe_infra5_full_control5_sfun.h"
#include "c7_Sim_Forcing_003h_expe_infra5_full_control5.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "Sim_Forcing_003h_expe_infra5_full_control5_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c7_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc7_Sim_Forcing_003h_expe_infra5_full_control5InstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c7_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void initialize_params_c7_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void enable_c7_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void disable_c7_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void c7_update_debugger_state_c7_Sim_Forcing_003h_expe_infra5_full_c(void);
static void ext_mode_exec_c7_Sim_Forcing_003h_expe_infra5_full_control5(void);
static const mxArray
  *get_sim_state_c7_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void set_sim_state_c7_Sim_Forcing_003h_expe_infra5_full_control5(const
  mxArray *c7_st);
static void finalize_c7_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void sf_c7_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshall(void *c7_chartInstance, void *c7_u);
static const mxArray *c7_b_sf_marshall(void *c7_chartInstance, void *c7_u);
static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[34]);
static const mxArray *c7_c_sf_marshall(void *c7_chartInstance, void *c7_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c7_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  uint8_T *c7_is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  c7_is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5 = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c7_is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5 = 0U;
}

static void initialize_params_c7_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
}

static void enable_c7_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c7_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c7_update_debugger_state_c7_Sim_Forcing_003h_expe_infra5_full_c(void)
{
}

static void ext_mode_exec_c7_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  c7_update_debugger_state_c7_Sim_Forcing_003h_expe_infra5_full_c();
}

static const mxArray
  *get_sim_state_c7_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  const mxArray *c7_st = NULL;
  const mxArray *c7_y = NULL;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T *c7_max_tilt;
  uint8_T *c7_is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  c7_max_tilt = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c7_is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5 = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(2));
  c7_u = *c7_max_tilt;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_u = *c7_is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y);
  return c7_st;
}

static void set_sim_state_c7_Sim_Forcing_003h_expe_infra5_full_control5(const
  mxArray *c7_st)
{
  const mxArray *c7_u;
  const mxArray *c7_max_tilt;
  real_T c7_d0;
  real_T c7_y;
  const mxArray *c7_is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  uint8_T c7_u0;
  uint8_T c7_b_y;
  boolean_T *c7_doneDoubleBufferReInit;
  real_T *c7_b_max_tilt;
  uint8_T *c7_b_is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  c7_b_max_tilt = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c7_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c7_b_is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5 = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  *c7_doneDoubleBufferReInit = true;
  c7_u = sf_mex_dup(c7_st);
  c7_max_tilt = sf_mex_dup(sf_mex_getcell(c7_u, 0));
  sf_mex_import("max_tilt", sf_mex_dup(c7_max_tilt), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_max_tilt);
  *c7_b_max_tilt = c7_y;
  c7_is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5 = sf_mex_dup
    (sf_mex_getcell(c7_u, 1));
  sf_mex_import("is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5",
                sf_mex_dup(
    c7_is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5), &c7_u0, 1, 3,
                0U, 0, 0U, 0);
  c7_b_y = c7_u0;
  sf_mex_destroy(&c7_is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5);
  *c7_b_is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5 = c7_b_y;
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_Sim_Forcing_003h_expe_infra5_full_c();
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
}

static void sf_c7_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  int32_T c7_i0;
  int32_T c7_previousEvent;
  int32_T c7_i1;
  real_T c7_com_or[4];
  real_T c7_nargout = 1.0;
  real_T c7_nargin = 1.0;
  real_T c7_max_tilt;
  real_T c7_x;
  real_T c7_b_x;
  real_T c7_y;
  real_T c7_c_x;
  real_T c7_d_x;
  real_T c7_b_y;
  real_T c7_e_x;
  real_T c7_f_x;
  real_T c7_c_y;
  real_T c7_g_x;
  real_T c7_h_x;
  real_T c7_d_y;
  real_T c7_varargin_1[4];
  int32_T c7_i2;
  real_T c7_i_x[4];
  int32_T c7_i3;
  real_T c7_j_x[4];
  real_T c7_mtmp;
  int32_T c7_itmp;
  int32_T c7_ix;
  real_T c7_k_x;
  boolean_T c7_b;
  boolean_T c7_searchingForNonNaN;
  int32_T c7_k;
  int32_T c7_b_k;
  int32_T c7_a;
  real_T c7_l_x;
  boolean_T c7_b_b;
  int32_T c7_b_a;
  int32_T c7_i4;
  int32_T c7_c_k;
  int32_T c7_c_a;
  real_T c7_b_mtmp;
  real_T *c7_b_max_tilt;
  real_T (*c7_b_com_or)[4];
  c7_b_max_tilt = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c7_b_com_or = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,5);
  for (c7_i0 = 0; c7_i0 < 4; c7_i0 = c7_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c7_b_com_or)[c7_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c7_b_max_tilt, 1U);
  c7_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,5);
  for (c7_i1 = 0; c7_i1 < 4; c7_i1 = c7_i1 + 1) {
    c7_com_or[c7_i1] = (*c7_b_com_or)[c7_i1];
  }

  sf_debug_symbol_scope_push(4U, 0U);
  sf_debug_symbol_scope_add("nargout", &c7_nargout, c7_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c7_nargin, c7_b_sf_marshall);
  sf_debug_symbol_scope_add("max_tilt", &c7_max_tilt, c7_b_sf_marshall);
  sf_debug_symbol_scope_add("com_or", &c7_com_or, c7_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  c7_x = c7_com_or[3];
  c7_b_x = c7_x;
  c7_y = muDoubleScalarAbs(c7_b_x);
  c7_c_x = c7_com_or[2];
  c7_d_x = c7_c_x;
  c7_b_y = muDoubleScalarAbs(c7_d_x);
  c7_e_x = c7_com_or[1];
  c7_f_x = c7_e_x;
  c7_c_y = muDoubleScalarAbs(c7_f_x);
  c7_g_x = c7_com_or[0];
  c7_h_x = c7_g_x;
  c7_d_y = muDoubleScalarAbs(c7_h_x);
  c7_varargin_1[0] = c7_d_y;
  c7_varargin_1[1] = c7_c_y;
  c7_varargin_1[2] = c7_b_y;
  c7_varargin_1[3] = c7_y;
  for (c7_i2 = 0; c7_i2 < 4; c7_i2 = c7_i2 + 1) {
    c7_i_x[c7_i2] = c7_varargin_1[c7_i2];
  }

  for (c7_i3 = 0; c7_i3 < 4; c7_i3 = c7_i3 + 1) {
    c7_j_x[c7_i3] = c7_i_x[c7_i3];
  }

  c7_mtmp = c7_j_x[0];
  c7_itmp = 1;
  c7_ix = 1;
  c7_k_x = c7_mtmp;
  c7_b = rtIsNaN(c7_k_x);
  if (c7_b) {
    c7_searchingForNonNaN = true;
    c7_k = 2;
   label_1:
    ;
    if (c7_k < 5) {
      c7_b_k = c7_k;
      c7_a = c7_ix;
      c7_ix = c7_a + 1;
      c7_l_x = c7_j_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("ix", (real_T)c7_ix), 1, 4, 1, 0) - 1];
      c7_b_b = rtIsNaN(c7_l_x);
      if (!c7_b_b) {
        c7_mtmp = c7_j_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
          _SFD_INTEGER_CHECK("ix", (real_T)c7_ix), 1, 4, 1, 0) - 1];
        c7_itmp = c7_b_k;
        c7_searchingForNonNaN = false;
      } else {
        c7_k = c7_k + 1;
        goto label_1;
      }
    }

    if (c7_searchingForNonNaN) {
      goto label_2;
    }
  }

  c7_b_a = c7_itmp;
  c7_i4 = c7_b_a + 1;
  for (c7_c_k = c7_i4; c7_c_k < 5; c7_c_k = c7_c_k + 1) {
    c7_c_a = c7_ix;
    c7_ix = c7_c_a + 1;
    if (c7_j_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("ix",
          (real_T)c7_ix), 1, 4, 1, 0) - 1] > c7_mtmp) {
      c7_mtmp = c7_j_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("ix", (real_T)c7_ix), 1, 4, 1, 0) - 1];
    }
  }

 label_2:
  ;
  c7_b_mtmp = c7_mtmp;
  c7_max_tilt = c7_b_mtmp;
  _SFD_EML_CALL(0,-3);
  sf_debug_symbol_scope_pop();
  *c7_b_max_tilt = c7_max_tilt;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
  _sfEvent_ = c7_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_Sim_Forcing_003h_expe_infra5_full_control5MachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  int32_T c7_i5;
  real_T c7_b_u[4];
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  for (c7_i5 = 0; c7_i5 < 4; c7_i5 = c7_i5 + 1) {
    c7_b_u[c7_i5] = (*((real_T (*)[4])c7_u))[c7_i5];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static const mxArray *c7_b_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  real_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  c7_b_u = *((real_T *)c7_u);
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

const mxArray
  *sf_c7_Sim_Forcing_003h_expe_infra5_full_control5_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_ResolvedFunctionInfo c7_info[34];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i6;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_info_helper(c7_info);
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 34));
  for (c7_i6 = 0; c7_i6 < 34; c7_i6 = c7_i6 + 1) {
    c7_r0 = &c7_info[c7_i6];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context",
                    "nameCaptureInfo", c7_i6);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name",
                    "nameCaptureInfo", c7_i6);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c7_i6);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c7_i6);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c7_i6);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c7_i6);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c7_i6);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[34])
{
  c7_info[0].context = "";
  c7_info[0].name = "abs";
  c7_info[0].dominantType = "double";
  c7_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[0].fileLength = 566U;
  c7_info[0].fileTime1 = 1221267134U;
  c7_info[0].fileTime2 = 0U;
  c7_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[1].name = "nargin";
  c7_info[1].dominantType = "";
  c7_info[1].resolved = "[B]nargin";
  c7_info[1].fileLength = 0U;
  c7_info[1].fileTime1 = 0U;
  c7_info[1].fileTime2 = 0U;
  c7_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[2].name = "gt";
  c7_info[2].dominantType = "double";
  c7_info[2].resolved = "[B]gt";
  c7_info[2].fileLength = 0U;
  c7_info[2].fileTime1 = 0U;
  c7_info[2].fileTime2 = 0U;
  c7_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[3].name = "isa";
  c7_info[3].dominantType = "double";
  c7_info[3].resolved = "[B]isa";
  c7_info[3].fileLength = 0U;
  c7_info[3].fileTime1 = 0U;
  c7_info[3].fileTime2 = 0U;
  c7_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[4].name = "ischar";
  c7_info[4].dominantType = "double";
  c7_info[4].resolved = "[B]ischar";
  c7_info[4].fileLength = 0U;
  c7_info[4].fileTime1 = 0U;
  c7_info[4].fileTime2 = 0U;
  c7_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[5].name = "islogical";
  c7_info[5].dominantType = "double";
  c7_info[5].resolved = "[B]islogical";
  c7_info[5].fileLength = 0U;
  c7_info[5].fileTime1 = 0U;
  c7_info[5].fileTime2 = 0U;
  c7_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[6].name = "size";
  c7_info[6].dominantType = "double";
  c7_info[6].resolved = "[B]size";
  c7_info[6].fileLength = 0U;
  c7_info[6].fileTime1 = 0U;
  c7_info[6].fileTime2 = 0U;
  c7_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[7].name = "class";
  c7_info[7].dominantType = "double";
  c7_info[7].resolved = "[B]class";
  c7_info[7].fileLength = 0U;
  c7_info[7].fileTime1 = 0U;
  c7_info[7].fileTime2 = 0U;
  c7_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[8].name = "zeros";
  c7_info[8].dominantType = "double";
  c7_info[8].resolved = "[B]zeros";
  c7_info[8].fileLength = 0U;
  c7_info[8].fileTime1 = 0U;
  c7_info[8].fileTime2 = 0U;
  c7_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[9].name = "eml_scalar_abs";
  c7_info[9].dominantType = "double";
  c7_info[9].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c7_info[9].fileLength = 461U;
  c7_info[9].fileTime1 = 1203447960U;
  c7_info[9].fileTime2 = 0U;
  c7_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c7_info[10].name = "isinteger";
  c7_info[10].dominantType = "double";
  c7_info[10].resolved = "[B]isinteger";
  c7_info[10].fileLength = 0U;
  c7_info[10].fileTime1 = 0U;
  c7_info[10].fileTime2 = 0U;
  c7_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c7_info[11].name = "isreal";
  c7_info[11].dominantType = "double";
  c7_info[11].resolved = "[B]isreal";
  c7_info[11].fileLength = 0U;
  c7_info[11].fileTime1 = 0U;
  c7_info[11].fileTime2 = 0U;
  c7_info[12].context = "";
  c7_info[12].name = "max";
  c7_info[12].dominantType = "double";
  c7_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c7_info[12].fileLength = 308U;
  c7_info[12].fileTime1 = 1192466630U;
  c7_info[12].fileTime2 = 0U;
  c7_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c7_info[13].name = "nargout";
  c7_info[13].dominantType = "";
  c7_info[13].resolved = "[B]nargout";
  c7_info[13].fileLength = 0U;
  c7_info[13].fileTime1 = 0U;
  c7_info[13].fileTime2 = 0U;
  c7_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c7_info[14].name = "le";
  c7_info[14].dominantType = "double";
  c7_info[14].resolved = "[B]le";
  c7_info[14].fileLength = 0U;
  c7_info[14].fileTime1 = 0U;
  c7_info[14].fileTime2 = 0U;
  c7_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c7_info[15].name = "eml_min_or_max";
  c7_info[15].dominantType = "char";
  c7_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c7_info[15].fileLength = 9969U;
  c7_info[15].fileTime1 = 1240262008U;
  c7_info[15].fileTime2 = 0U;
  c7_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c7_info[16].name = "strcmp";
  c7_info[16].dominantType = "char";
  c7_info[16].resolved = "[B]strcmp";
  c7_info[16].fileLength = 0U;
  c7_info[16].fileTime1 = 0U;
  c7_info[16].fileTime2 = 0U;
  c7_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c7_info[17].name = "isnumeric";
  c7_info[17].dominantType = "double";
  c7_info[17].resolved = "[B]isnumeric";
  c7_info[17].fileLength = 0U;
  c7_info[17].fileTime1 = 0U;
  c7_info[17].fileTime2 = 0U;
  c7_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c7_info[18].name = "eq";
  c7_info[18].dominantType = "double";
  c7_info[18].resolved = "[B]eq";
  c7_info[18].fileLength = 0U;
  c7_info[18].fileTime1 = 0U;
  c7_info[18].fileTime2 = 0U;
  c7_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c7_info[19].name = "eml_const_nonsingleton_dim";
  c7_info[19].dominantType = "double";
  c7_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c7_info[19].fileLength = 1473U;
  c7_info[19].fileTime1 = 1240262004U;
  c7_info[19].fileTime2 = 0U;
  c7_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m/local_const_nonsingleton_dim";
  c7_info[20].name = "not";
  c7_info[20].dominantType = "logical";
  c7_info[20].resolved = "[B]not";
  c7_info[20].fileLength = 0U;
  c7_info[20].fileTime1 = 0U;
  c7_info[20].fileTime2 = 0U;
  c7_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m/local_const_nonsingleton_dim";
  c7_info[21].name = "ne";
  c7_info[21].dominantType = "double";
  c7_info[21].resolved = "[B]ne";
  c7_info[21].fileLength = 0U;
  c7_info[21].fileTime1 = 0U;
  c7_info[21].fileTime2 = 0U;
  c7_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c7_info[22].name = "eml_scalar_eg";
  c7_info[22].dominantType = "double";
  c7_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[22].fileLength = 3068U;
  c7_info[22].fileTime1 = 1240262010U;
  c7_info[22].fileTime2 = 0U;
  c7_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c7_info[23].name = "false";
  c7_info[23].dominantType = "";
  c7_info[23].resolved = "[B]false";
  c7_info[23].fileLength = 0U;
  c7_info[23].fileTime1 = 0U;
  c7_info[23].fileTime2 = 0U;
  c7_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[24].name = "isstruct";
  c7_info[24].dominantType = "double";
  c7_info[24].resolved = "[B]isstruct";
  c7_info[24].fileLength = 0U;
  c7_info[24].fileTime1 = 0U;
  c7_info[24].fileTime2 = 0U;
  c7_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c7_info[25].name = "cast";
  c7_info[25].dominantType = "double";
  c7_info[25].resolved = "[B]cast";
  c7_info[25].fileLength = 0U;
  c7_info[25].fileTime1 = 0U;
  c7_info[25].fileTime2 = 0U;
  c7_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c7_info[26].name = "ones";
  c7_info[26].dominantType = "double";
  c7_info[26].resolved = "[B]ones";
  c7_info[26].fileLength = 0U;
  c7_info[26].fileTime1 = 0U;
  c7_info[26].fileTime2 = 0U;
  c7_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c7_info[27].name = "eml_index_class";
  c7_info[27].dominantType = "";
  c7_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[27].fileLength = 909U;
  c7_info[27].fileTime1 = 1192466782U;
  c7_info[27].fileTime2 = 0U;
  c7_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c7_info[28].name = "isempty";
  c7_info[28].dominantType = "double";
  c7_info[28].resolved = "[B]isempty";
  c7_info[28].fileLength = 0U;
  c7_info[28].fileTime1 = 0U;
  c7_info[28].fileTime2 = 0U;
  c7_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c7_info[29].name = "isscalar";
  c7_info[29].dominantType = "double";
  c7_info[29].resolved = "[B]isscalar";
  c7_info[29].fileLength = 0U;
  c7_info[29].fileTime1 = 0U;
  c7_info[29].fileTime2 = 0U;
  c7_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c7_info[30].name = "lt";
  c7_info[30].dominantType = "double";
  c7_info[30].resolved = "[B]lt";
  c7_info[30].fileLength = 0U;
  c7_info[30].fileTime1 = 0U;
  c7_info[30].fileTime2 = 0U;
  c7_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c7_info[31].name = "isnan";
  c7_info[31].dominantType = "double";
  c7_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c7_info[31].fileLength = 506U;
  c7_info[31].fileTime1 = 1228093810U;
  c7_info[31].fileTime2 = 0U;
  c7_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c7_info[32].name = "true";
  c7_info[32].dominantType = "";
  c7_info[32].resolved = "[B]true";
  c7_info[32].fileLength = 0U;
  c7_info[32].fileTime1 = 0U;
  c7_info[32].fileTime2 = 0U;
  c7_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c7_info[33].name = "eml_index_plus";
  c7_info[33].dominantType = "int32";
  c7_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[33].fileLength = 272U;
  c7_info[33].fileTime1 = 1192466786U;
  c7_info[33].fileTime2 = 0U;
}

static const mxArray *c7_c_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  boolean_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  c7_b_u = *((boolean_T *)c7_u);
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c7_Sim_Forcing_003h_expe_infra5_full_control5_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1650549522U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3110636478U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1258990753U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3924251810U);
}

mxArray
  *sf_c7_Sim_Forcing_003h_expe_infra5_full_control5_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4135326549U);
    pr[1] = (double)(3327067466U);
    pr[2] = (double)(1668973489U);
    pr[3] = (double)(2363208027U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray
  *sf_get_sim_state_info_c7_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"max_tilt\",},{M[8],M[0],T\"is_active_c7_Sim_Forcing_003h_expe_infra5_full_control5\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_Sim_Forcing_003h_expe_infra5_full_control5_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Sim_Forcing_003h_expe_infra5_full_control5MachineNumber_,
           7,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance.chartNumber),
           &(chartInstance.instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_Sim_Forcing_003h_expe_infra5_full_control5MachineNumber_,
             chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Sim_Forcing_003h_expe_infra5_full_control5MachineNumber_,
             chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_Sim_Forcing_003h_expe_infra5_full_control5MachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 4;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"com_or",0,(MexFcnForType)c7_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "max_tilt",0,(MexFcnForType)c7_b_sf_marshall);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,133);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c7_com_or)[4];
          real_T *c7_max_tilt;
          c7_max_tilt = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c7_com_or = (real_T (*)[4])ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_com_or);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_max_tilt);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Sim_Forcing_003h_expe_infra5_full_control5MachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c7_Sim_Forcing_003h_expe_infra5_full_control5
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c7_Sim_Forcing_003h_expe_infra5_full_control5();
  initialize_c7_Sim_Forcing_003h_expe_infra5_full_control5();
}

static void sf_opaque_enable_c7_Sim_Forcing_003h_expe_infra5_full_control5(void *
  chartInstanceVar)
{
  enable_c7_Sim_Forcing_003h_expe_infra5_full_control5();
}

static void sf_opaque_disable_c7_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar)
{
  disable_c7_Sim_Forcing_003h_expe_infra5_full_control5();
}

static void sf_opaque_gateway_c7_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar)
{
  sf_c7_Sim_Forcing_003h_expe_infra5_full_control5();
}

static void
  sf_opaque_ext_mode_exec_c7_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar)
{
  ext_mode_exec_c7_Sim_Forcing_003h_expe_infra5_full_control5();
}

static mxArray*
  sf_opaque_get_sim_state_c7_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c7_Sim_Forcing_003h_expe_infra5_full_control5();
  return st;
}

static void
  sf_opaque_set_sim_state_c7_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c7_Sim_Forcing_003h_expe_infra5_full_control5(sf_mex_dup(st));
}

static void sf_opaque_terminate_c7_Sim_Forcing_003h_expe_infra5_full_control5
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c7_Sim_Forcing_003h_expe_infra5_full_control5();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_Sim_Forcing_003h_expe_infra5_full_control5
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_Sim_Forcing_003h_expe_infra5_full_control5();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c7_Sim_Forcing_003h_expe_infra5_full_control5
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Sim_Forcing_003h_expe_infra5_full_control5",
      "Sim_Forcing_003h_expe_infra5_full_control5",7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "Sim_Forcing_003h_expe_infra5_full_control5",
                "Sim_Forcing_003h_expe_infra5_full_control5",7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "Sim_Forcing_003h_expe_infra5_full_control5",
      "Sim_Forcing_003h_expe_infra5_full_control5",7,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "Sim_Forcing_003h_expe_infra5_full_control5",
        "Sim_Forcing_003h_expe_infra5_full_control5",7,1);
      sf_mark_chart_reusable_outputs(S,
        "Sim_Forcing_003h_expe_infra5_full_control5",
        "Sim_Forcing_003h_expe_infra5_full_control5",7,1);
    }

    sf_set_rtw_dwork_info(S,"Sim_Forcing_003h_expe_infra5_full_control5",
                          "Sim_Forcing_003h_expe_infra5_full_control5",7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(3465906247U));
  ssSetChecksum1(S,(3327034416U));
  ssSetChecksum2(S,(130885601U));
  ssSetChecksum3(S,(1350125488U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c7_Sim_Forcing_003h_expe_infra5_full_control5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Sim_Forcing_003h_expe_infra5_full_control5",
      "Sim_Forcing_003h_expe_infra5_full_control5",7);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_Sim_Forcing_003h_expe_infra5_full_control5(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c7_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }

  chart_debug_initialization(S,1);
}

void c7_Sim_Forcing_003h_expe_infra5_full_control5_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_Sim_Forcing_003h_expe_infra5_full_control5(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_Sim_Forcing_003h_expe_infra5_full_control5(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_Sim_Forcing_003h_expe_infra5_full_control5(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_Sim_Forcing_003h_expe_infra5_full_control5_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

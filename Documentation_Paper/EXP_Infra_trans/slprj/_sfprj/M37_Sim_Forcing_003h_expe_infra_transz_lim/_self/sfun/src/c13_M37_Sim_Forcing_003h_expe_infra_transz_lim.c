/* Include files */

#include "blascompat32.h"
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun.h"
#include "c13_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c13_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc13_M37_Sim_Forcing_003h_expe_infra_transz_limInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void initialize_params_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void);
static void enable_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void disable_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c13_update_debugger_state_c13_M37_Sim_Forcing_003h_expe_infra_t(void);
static void ext_mode_exec_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static const mxArray
  *get_sim_state_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void set_sim_state_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c13_st);
static void finalize_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void sf_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber);
static const mxArray *c13_sf_marshall(void *c13_chartInstance, void *c13_u);
static const mxArray *c13_b_sf_marshall(void *c13_chartInstance, void *c13_u);
static void c13_info_helper(c13_ResolvedFunctionInfo c13_info[35]);
static const mxArray *c13_c_sf_marshall(void *c13_chartInstance, void *c13_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  uint8_T *c13_is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c13_is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c13_is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim = 0U;
}

static void initialize_params_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void)
{
}

static void enable_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c13_update_debugger_state_c13_M37_Sim_Forcing_003h_expe_infra_t(void)
{
}

static void ext_mode_exec_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  c13_update_debugger_state_c13_M37_Sim_Forcing_003h_expe_infra_t();
}

static const mxArray
  *get_sim_state_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const mxArray *c13_st = NULL;
  const mxArray *c13_y = NULL;
  real_T c13_u;
  const mxArray *c13_b_y = NULL;
  uint8_T c13_b_u;
  const mxArray *c13_c_y = NULL;
  real_T *c13_status;
  uint8_T *c13_is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c13_is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c13_status = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellarray(2));
  c13_u = *c13_status;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_b_u = *c13_is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c13_y, 1, c13_c_y);
  sf_mex_assign(&c13_st, c13_y);
  return c13_st;
}

static void set_sim_state_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c13_st)
{
  const mxArray *c13_u;
  const mxArray *c13_status;
  real_T c13_d0;
  real_T c13_y;
  const mxArray *c13_is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  uint8_T c13_u0;
  uint8_T c13_b_y;
  boolean_T *c13_doneDoubleBufferReInit;
  real_T *c13_b_status;
  uint8_T *c13_b_is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c13_b_is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c13_b_status = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c13_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  *c13_doneDoubleBufferReInit = true;
  c13_u = sf_mex_dup(c13_st);
  c13_status = sf_mex_dup(sf_mex_getcell(c13_u, 0));
  sf_mex_import("status", sf_mex_dup(c13_status), &c13_d0, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d0;
  sf_mex_destroy(&c13_status);
  *c13_b_status = c13_y;
  c13_is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim = sf_mex_dup
    (sf_mex_getcell(c13_u, 1));
  sf_mex_import("is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim",
                sf_mex_dup(
    c13_is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim), &c13_u0, 1, 3,
                0U, 0, 0U, 0);
  c13_b_y = c13_u0;
  sf_mex_destroy(&c13_is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim);
  *c13_b_is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim = c13_b_y;
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_M37_Sim_Forcing_003h_expe_infra_t();
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void sf_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c13_i0;
  int32_T c13_i1;
  int32_T c13_previousEvent;
  int32_T c13_i2;
  real_T c13_com_offset[2];
  int32_T c13_i3;
  real_T c13_gradual_offset[2];
  real_T c13_threshold;
  real_T c13_nargout = 1.0;
  real_T c13_nargin = 3.0;
  real_T c13_max_error;
  real_T c13_error[2];
  real_T c13_status;
  int32_T c13_i4;
  real_T c13_x;
  real_T c13_b_x;
  real_T c13_y;
  real_T c13_c_x;
  real_T c13_d_x;
  real_T c13_b_y;
  real_T c13_varargin_1[2];
  int32_T c13_i5;
  real_T c13_e_x[2];
  int32_T c13_i6;
  real_T c13_f_x[2];
  real_T c13_mtmp;
  int32_T c13_itmp;
  int32_T c13_ix;
  real_T c13_g_x;
  boolean_T c13_b;
  boolean_T c13_searchingForNonNaN;
  real_T c13_h_x;
  boolean_T c13_b_b;
  int32_T c13_a;
  int32_T c13_i7;
  int32_T c13_k;
  int32_T c13_b_a;
  real_T c13_b_mtmp;
  real_T *c13_b_status;
  real_T *c13_b_threshold;
  real_T (*c13_b_gradual_offset)[2];
  real_T (*c13_b_com_offset)[2];
  c13_b_gradual_offset = (real_T (*)[2])ssGetInputPortSignal(chartInstance.S, 1);
  c13_b_com_offset = (real_T (*)[2])ssGetInputPortSignal(chartInstance.S, 0);
  c13_b_status = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c13_b_threshold = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,12);
  for (c13_i0 = 0; c13_i0 < 2; c13_i0 = c13_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c13_b_com_offset)[c13_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c13_b_status, 1U);
  for (c13_i1 = 0; c13_i1 < 2; c13_i1 = c13_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c13_b_gradual_offset)[c13_i1], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c13_b_threshold, 3U);
  c13_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,12);
  for (c13_i2 = 0; c13_i2 < 2; c13_i2 = c13_i2 + 1) {
    c13_com_offset[c13_i2] = (*c13_b_com_offset)[c13_i2];
  }

  for (c13_i3 = 0; c13_i3 < 2; c13_i3 = c13_i3 + 1) {
    c13_gradual_offset[c13_i3] = (*c13_b_gradual_offset)[c13_i3];
  }

  c13_threshold = *c13_b_threshold;
  sf_debug_symbol_scope_push(8U, 0U);
  sf_debug_symbol_scope_add("nargout", &c13_nargout, c13_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c13_nargin, c13_b_sf_marshall);
  sf_debug_symbol_scope_add("max_error", &c13_max_error, c13_b_sf_marshall);
  sf_debug_symbol_scope_add("error", &c13_error, c13_sf_marshall);
  sf_debug_symbol_scope_add("status", &c13_status, c13_b_sf_marshall);
  sf_debug_symbol_scope_add("threshold", &c13_threshold, c13_b_sf_marshall);
  sf_debug_symbol_scope_add("gradual_offset", &c13_gradual_offset,
    c13_sf_marshall);
  sf_debug_symbol_scope_add("com_offset", &c13_com_offset, c13_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  for (c13_i4 = 0; c13_i4 < 2; c13_i4 = c13_i4 + 1) {
    c13_error[c13_i4] = c13_com_offset[c13_i4] - c13_gradual_offset[c13_i4];
  }

  _SFD_EML_CALL(0,5);
  c13_x = c13_error[1];
  c13_b_x = c13_x;
  c13_y = muDoubleScalarAbs(c13_b_x);
  c13_c_x = c13_error[0];
  c13_d_x = c13_c_x;
  c13_b_y = muDoubleScalarAbs(c13_d_x);
  c13_varargin_1[0] = c13_b_y;
  c13_varargin_1[1] = c13_y;
  for (c13_i5 = 0; c13_i5 < 2; c13_i5 = c13_i5 + 1) {
    c13_e_x[c13_i5] = c13_varargin_1[c13_i5];
  }

  for (c13_i6 = 0; c13_i6 < 2; c13_i6 = c13_i6 + 1) {
    c13_f_x[c13_i6] = c13_e_x[c13_i6];
  }

  c13_mtmp = c13_f_x[0];
  c13_itmp = 1;
  c13_ix = 1;
  c13_g_x = c13_mtmp;
  c13_b = rtIsNaN(c13_g_x);
  if (c13_b) {
    c13_searchingForNonNaN = true;
    c13_ix = 2;
    c13_h_x = c13_f_x[1];
    c13_b_b = rtIsNaN(c13_h_x);
    if (!c13_b_b) {
      c13_mtmp = c13_f_x[1];
      c13_itmp = 2;
      c13_searchingForNonNaN = false;
    }

    if (c13_searchingForNonNaN) {
      goto label_1;
    }
  }

  c13_a = c13_itmp;
  c13_i7 = c13_a + 1;
  for (c13_k = c13_i7; c13_k < 3; c13_k = c13_k + 1) {
    c13_b_a = c13_ix;
    c13_ix = c13_b_a + 1;
    if (c13_f_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK(
          "ix", (real_T)c13_ix), 1, 2, 1, 0) - 1] > c13_mtmp) {
      c13_mtmp = c13_f_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("ix", (real_T)c13_ix), 1, 2, 1, 0) - 1];
    }
  }

 label_1:
  ;
  c13_b_mtmp = c13_mtmp;
  c13_max_error = c13_b_mtmp;
  _SFD_EML_CALL(0,7);
  if (CV_EML_IF(0, 0, c13_max_error > c13_threshold)) {
    _SFD_EML_CALL(0,8);
    c13_status = 0.0;
  } else {
    _SFD_EML_CALL(0,10);
    c13_status = 1.0;
  }

  _SFD_EML_CALL(0,-10);
  sf_debug_symbol_scope_pop();
  *c13_b_status = c13_status;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,12);
  _sfEvent_ = c13_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber)
{
}

static const mxArray *c13_sf_marshall(void *c13_chartInstance, void *c13_u)
{
  const mxArray *c13_y = NULL;
  int32_T c13_i8;
  real_T c13_b_u[2];
  const mxArray *c13_b_y = NULL;
  c13_y = NULL;
  for (c13_i8 = 0; c13_i8 < 2; c13_i8 = c13_i8 + 1) {
    c13_b_u[c13_i8] = (*((real_T (*)[2])c13_u))[c13_i8];
  }

  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 0, 0U, 1U, 0U, 1, 2));
  sf_mex_assign(&c13_y, c13_b_y);
  return c13_y;
}

static const mxArray *c13_b_sf_marshall(void *c13_chartInstance, void *c13_u)
{
  const mxArray *c13_y = NULL;
  real_T c13_b_u;
  const mxArray *c13_b_y = NULL;
  c13_y = NULL;
  c13_b_u = *((real_T *)c13_u);
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c13_y, c13_b_y);
  return c13_y;
}

const mxArray
  *sf_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_ResolvedFunctionInfo c13_info[35];
  const mxArray *c13_m0 = NULL;
  int32_T c13_i9;
  c13_ResolvedFunctionInfo *c13_r0;
  c13_nameCaptureInfo = NULL;
  c13_info_helper(c13_info);
  sf_mex_assign(&c13_m0, sf_mex_createstruct("nameCaptureInfo", 1, 35));
  for (c13_i9 = 0; c13_i9 < 35; c13_i9 = c13_i9 + 1) {
    c13_r0 = &c13_info[c13_i9];
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->context)), "context"
                    , "nameCaptureInfo", c13_i9);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->name)), "name",
                    "nameCaptureInfo", c13_i9);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      c13_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c13_i9);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->resolved)),
                    "resolved", "nameCaptureInfo", c13_i9);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c13_i9);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c13_i9);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c13_i9);
  }

  sf_mex_assign(&c13_nameCaptureInfo, c13_m0);
  return c13_nameCaptureInfo;
}

static void c13_info_helper(c13_ResolvedFunctionInfo c13_info[35])
{
  c13_info[0].context = "";
  c13_info[0].name = "minus";
  c13_info[0].dominantType = "double";
  c13_info[0].resolved = "[B]minus";
  c13_info[0].fileLength = 0U;
  c13_info[0].fileTime1 = 0U;
  c13_info[0].fileTime2 = 0U;
  c13_info[1].context = "";
  c13_info[1].name = "abs";
  c13_info[1].dominantType = "double";
  c13_info[1].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c13_info[1].fileLength = 566U;
  c13_info[1].fileTime1 = 1221267134U;
  c13_info[1].fileTime2 = 0U;
  c13_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c13_info[2].name = "nargin";
  c13_info[2].dominantType = "";
  c13_info[2].resolved = "[B]nargin";
  c13_info[2].fileLength = 0U;
  c13_info[2].fileTime1 = 0U;
  c13_info[2].fileTime2 = 0U;
  c13_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c13_info[3].name = "gt";
  c13_info[3].dominantType = "double";
  c13_info[3].resolved = "[B]gt";
  c13_info[3].fileLength = 0U;
  c13_info[3].fileTime1 = 0U;
  c13_info[3].fileTime2 = 0U;
  c13_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c13_info[4].name = "isa";
  c13_info[4].dominantType = "double";
  c13_info[4].resolved = "[B]isa";
  c13_info[4].fileLength = 0U;
  c13_info[4].fileTime1 = 0U;
  c13_info[4].fileTime2 = 0U;
  c13_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c13_info[5].name = "ischar";
  c13_info[5].dominantType = "double";
  c13_info[5].resolved = "[B]ischar";
  c13_info[5].fileLength = 0U;
  c13_info[5].fileTime1 = 0U;
  c13_info[5].fileTime2 = 0U;
  c13_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c13_info[6].name = "islogical";
  c13_info[6].dominantType = "double";
  c13_info[6].resolved = "[B]islogical";
  c13_info[6].fileLength = 0U;
  c13_info[6].fileTime1 = 0U;
  c13_info[6].fileTime2 = 0U;
  c13_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c13_info[7].name = "size";
  c13_info[7].dominantType = "double";
  c13_info[7].resolved = "[B]size";
  c13_info[7].fileLength = 0U;
  c13_info[7].fileTime1 = 0U;
  c13_info[7].fileTime2 = 0U;
  c13_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c13_info[8].name = "class";
  c13_info[8].dominantType = "double";
  c13_info[8].resolved = "[B]class";
  c13_info[8].fileLength = 0U;
  c13_info[8].fileTime1 = 0U;
  c13_info[8].fileTime2 = 0U;
  c13_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c13_info[9].name = "zeros";
  c13_info[9].dominantType = "double";
  c13_info[9].resolved = "[B]zeros";
  c13_info[9].fileLength = 0U;
  c13_info[9].fileTime1 = 0U;
  c13_info[9].fileTime2 = 0U;
  c13_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c13_info[10].name = "eml_scalar_abs";
  c13_info[10].dominantType = "double";
  c13_info[10].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c13_info[10].fileLength = 461U;
  c13_info[10].fileTime1 = 1203447960U;
  c13_info[10].fileTime2 = 0U;
  c13_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c13_info[11].name = "isinteger";
  c13_info[11].dominantType = "double";
  c13_info[11].resolved = "[B]isinteger";
  c13_info[11].fileLength = 0U;
  c13_info[11].fileTime1 = 0U;
  c13_info[11].fileTime2 = 0U;
  c13_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c13_info[12].name = "isreal";
  c13_info[12].dominantType = "double";
  c13_info[12].resolved = "[B]isreal";
  c13_info[12].fileLength = 0U;
  c13_info[12].fileTime1 = 0U;
  c13_info[12].fileTime2 = 0U;
  c13_info[13].context = "";
  c13_info[13].name = "max";
  c13_info[13].dominantType = "double";
  c13_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c13_info[13].fileLength = 308U;
  c13_info[13].fileTime1 = 1192466630U;
  c13_info[13].fileTime2 = 0U;
  c13_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c13_info[14].name = "nargout";
  c13_info[14].dominantType = "";
  c13_info[14].resolved = "[B]nargout";
  c13_info[14].fileLength = 0U;
  c13_info[14].fileTime1 = 0U;
  c13_info[14].fileTime2 = 0U;
  c13_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c13_info[15].name = "le";
  c13_info[15].dominantType = "double";
  c13_info[15].resolved = "[B]le";
  c13_info[15].fileLength = 0U;
  c13_info[15].fileTime1 = 0U;
  c13_info[15].fileTime2 = 0U;
  c13_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c13_info[16].name = "eml_min_or_max";
  c13_info[16].dominantType = "char";
  c13_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c13_info[16].fileLength = 9969U;
  c13_info[16].fileTime1 = 1240262008U;
  c13_info[16].fileTime2 = 0U;
  c13_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c13_info[17].name = "strcmp";
  c13_info[17].dominantType = "char";
  c13_info[17].resolved = "[B]strcmp";
  c13_info[17].fileLength = 0U;
  c13_info[17].fileTime1 = 0U;
  c13_info[17].fileTime2 = 0U;
  c13_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c13_info[18].name = "isnumeric";
  c13_info[18].dominantType = "double";
  c13_info[18].resolved = "[B]isnumeric";
  c13_info[18].fileLength = 0U;
  c13_info[18].fileTime1 = 0U;
  c13_info[18].fileTime2 = 0U;
  c13_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c13_info[19].name = "eq";
  c13_info[19].dominantType = "double";
  c13_info[19].resolved = "[B]eq";
  c13_info[19].fileLength = 0U;
  c13_info[19].fileTime1 = 0U;
  c13_info[19].fileTime2 = 0U;
  c13_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c13_info[20].name = "eml_const_nonsingleton_dim";
  c13_info[20].dominantType = "double";
  c13_info[20].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c13_info[20].fileLength = 1473U;
  c13_info[20].fileTime1 = 1240262004U;
  c13_info[20].fileTime2 = 0U;
  c13_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m/local_const_nonsingleton_dim";
  c13_info[21].name = "not";
  c13_info[21].dominantType = "logical";
  c13_info[21].resolved = "[B]not";
  c13_info[21].fileLength = 0U;
  c13_info[21].fileTime1 = 0U;
  c13_info[21].fileTime2 = 0U;
  c13_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m/local_const_nonsingleton_dim";
  c13_info[22].name = "ne";
  c13_info[22].dominantType = "double";
  c13_info[22].resolved = "[B]ne";
  c13_info[22].fileLength = 0U;
  c13_info[22].fileTime1 = 0U;
  c13_info[22].fileTime2 = 0U;
  c13_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c13_info[23].name = "eml_scalar_eg";
  c13_info[23].dominantType = "double";
  c13_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c13_info[23].fileLength = 3068U;
  c13_info[23].fileTime1 = 1240262010U;
  c13_info[23].fileTime2 = 0U;
  c13_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c13_info[24].name = "false";
  c13_info[24].dominantType = "";
  c13_info[24].resolved = "[B]false";
  c13_info[24].fileLength = 0U;
  c13_info[24].fileTime1 = 0U;
  c13_info[24].fileTime2 = 0U;
  c13_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c13_info[25].name = "isstruct";
  c13_info[25].dominantType = "double";
  c13_info[25].resolved = "[B]isstruct";
  c13_info[25].fileLength = 0U;
  c13_info[25].fileTime1 = 0U;
  c13_info[25].fileTime2 = 0U;
  c13_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c13_info[26].name = "cast";
  c13_info[26].dominantType = "double";
  c13_info[26].resolved = "[B]cast";
  c13_info[26].fileLength = 0U;
  c13_info[26].fileTime1 = 0U;
  c13_info[26].fileTime2 = 0U;
  c13_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c13_info[27].name = "ones";
  c13_info[27].dominantType = "double";
  c13_info[27].resolved = "[B]ones";
  c13_info[27].fileLength = 0U;
  c13_info[27].fileTime1 = 0U;
  c13_info[27].fileTime2 = 0U;
  c13_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c13_info[28].name = "eml_index_class";
  c13_info[28].dominantType = "";
  c13_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c13_info[28].fileLength = 909U;
  c13_info[28].fileTime1 = 1192466782U;
  c13_info[28].fileTime2 = 0U;
  c13_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c13_info[29].name = "isempty";
  c13_info[29].dominantType = "double";
  c13_info[29].resolved = "[B]isempty";
  c13_info[29].fileLength = 0U;
  c13_info[29].fileTime1 = 0U;
  c13_info[29].fileTime2 = 0U;
  c13_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c13_info[30].name = "isscalar";
  c13_info[30].dominantType = "double";
  c13_info[30].resolved = "[B]isscalar";
  c13_info[30].fileLength = 0U;
  c13_info[30].fileTime1 = 0U;
  c13_info[30].fileTime2 = 0U;
  c13_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c13_info[31].name = "lt";
  c13_info[31].dominantType = "double";
  c13_info[31].resolved = "[B]lt";
  c13_info[31].fileLength = 0U;
  c13_info[31].fileTime1 = 0U;
  c13_info[31].fileTime2 = 0U;
  c13_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c13_info[32].name = "isnan";
  c13_info[32].dominantType = "double";
  c13_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c13_info[32].fileLength = 506U;
  c13_info[32].fileTime1 = 1228093810U;
  c13_info[32].fileTime2 = 0U;
  c13_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c13_info[33].name = "true";
  c13_info[33].dominantType = "";
  c13_info[33].resolved = "[B]true";
  c13_info[33].fileLength = 0U;
  c13_info[33].fileTime1 = 0U;
  c13_info[33].fileTime2 = 0U;
  c13_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c13_info[34].name = "eml_index_plus";
  c13_info[34].dominantType = "int32";
  c13_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c13_info[34].fileLength = 272U;
  c13_info[34].fileTime1 = 1192466786U;
  c13_info[34].fileTime2 = 0U;
}

static const mxArray *c13_c_sf_marshall(void *c13_chartInstance, void *c13_u)
{
  const mxArray *c13_y = NULL;
  boolean_T c13_b_u;
  const mxArray *c13_b_y = NULL;
  c13_y = NULL;
  c13_b_u = *((boolean_T *)c13_u);
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c13_y, c13_b_y);
  return c13_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3819188546U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3982363807U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2665292319U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(934856173U);
}

mxArray
  *sf_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3706514834U);
    pr[1] = (double)(1107167569U);
    pr[2] = (double)(2577816490U);
    pr[3] = (double)(3958480043U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
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
  *sf_get_sim_state_info_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"status\",},{M[8],M[0],T\"is_active_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(&mxChecksum);
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
          (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
           13,
           1,
           1,
           4,
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
            (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
             chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
             chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 2;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"com_offset",0,(MexFcnForType)
                                c13_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"status",
                              0,(MexFcnForType)c13_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 2;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"gradual_offset",0,(MexFcnForType)
                                c13_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "threshold",0,(MexFcnForType)c13_b_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,225);
        _SFD_CV_INIT_EML_IF(0,0,158,181,196,218);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c13_com_offset)[2];
          real_T *c13_status;
          real_T (*c13_gradual_offset)[2];
          real_T *c13_threshold;
          c13_gradual_offset = (real_T (*)[2])ssGetInputPortSignal
            (chartInstance.S, 1);
          c13_com_offset = (real_T (*)[2])ssGetInputPortSignal(chartInstance.S,
            0);
          c13_status = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c13_threshold = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          _SFD_SET_DATA_VALUE_PTR(0U, c13_com_offset);
          _SFD_SET_DATA_VALUE_PTR(1U, c13_status);
          _SFD_SET_DATA_VALUE_PTR(2U, c13_gradual_offset);
          _SFD_SET_DATA_VALUE_PTR(3U, c13_threshold);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  initialize_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_enable_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  enable_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_disable_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  disable_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_gateway_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  sf_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void
  sf_opaque_ext_mode_exec_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  ext_mode_exec_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static mxArray*
  sf_opaque_get_sim_state_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  return st;
}

static void
  sf_opaque_set_sim_state_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(sf_mex_dup(st));
}

static void sf_opaque_terminate_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",13,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",13,3);
      sf_mark_chart_reusable_outputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",13,1);
    }

    sf_set_rtw_dwork_info(S,"M37_Sim_Forcing_003h_expe_infra_transz_lim",
                          "M37_Sim_Forcing_003h_expe_infra_transz_lim",13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(815694050U));
  ssSetChecksum1(S,(1597982071U));
  ssSetChecksum2(S,(2511434578U));
  ssSetChecksum3(S,(1182998582U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",13);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim;
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

void c13_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(SimStruct *
  S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

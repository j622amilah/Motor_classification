/* Include files */

#include "blascompat32.h"
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun.h"
#include "c21_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c21_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc21_M37_Sim_Forcing_003h_expe_infra_transz_limInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void initialize_params_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void);
static void enable_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void disable_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c21_update_debugger_state_c21_M37_Sim_Forcing_003h_expe_infra_t(void);
static void ext_mode_exec_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static const mxArray
  *get_sim_state_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void set_sim_state_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c21_st);
static void finalize_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void sf_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber);
static void c21_eml_warning(void);
static const mxArray *c21_sf_marshall(void *c21_chartInstance, void *c21_u);
static const mxArray *c21_b_sf_marshall(void *c21_chartInstance, void *c21_u);
static void c21_info_helper(c21_ResolvedFunctionInfo c21_info[34]);
static const mxArray *c21_c_sf_marshall(void *c21_chartInstance, void *c21_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  uint8_T *c21_is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c21_is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c21_is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim = 0U;
}

static void initialize_params_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void)
{
}

static void enable_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c21_update_debugger_state_c21_M37_Sim_Forcing_003h_expe_infra_t(void)
{
}

static void ext_mode_exec_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  c21_update_debugger_state_c21_M37_Sim_Forcing_003h_expe_infra_t();
}

static const mxArray
  *get_sim_state_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const mxArray *c21_st = NULL;
  const mxArray *c21_y = NULL;
  int32_T c21_i0;
  real_T c21_u[3];
  const mxArray *c21_b_y = NULL;
  uint8_T c21_b_u;
  const mxArray *c21_c_y = NULL;
  uint8_T *c21_is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  real_T (*c21_stick_out)[3];
  c21_is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c21_stick_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c21_st = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_createcellarray(2));
  for (c21_i0 = 0; c21_i0 < 3; c21_i0 = c21_i0 + 1) {
    c21_u[c21_i0] = (*c21_stick_out)[c21_i0];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c21_y, 0, c21_b_y);
  c21_b_u = *c21_is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c21_c_y = NULL;
  sf_mex_assign(&c21_c_y, sf_mex_create("y", &c21_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c21_y, 1, c21_c_y);
  sf_mex_assign(&c21_st, c21_y);
  return c21_st;
}

static void set_sim_state_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c21_st)
{
  const mxArray *c21_u;
  const mxArray *c21_stick_out;
  real_T c21_dv0[3];
  int32_T c21_i1;
  real_T c21_y[3];
  int32_T c21_i2;
  const mxArray *c21_is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  uint8_T c21_u0;
  uint8_T c21_b_y;
  boolean_T *c21_doneDoubleBufferReInit;
  uint8_T *c21_b_is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  real_T (*c21_b_stick_out)[3];
  c21_b_is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c21_b_stick_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c21_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  *c21_doneDoubleBufferReInit = true;
  c21_u = sf_mex_dup(c21_st);
  c21_stick_out = sf_mex_dup(sf_mex_getcell(c21_u, 0));
  sf_mex_import("stick_out", sf_mex_dup(c21_stick_out), &c21_dv0, 1, 0, 0U, 1,
                0U, 1, 3);
  for (c21_i1 = 0; c21_i1 < 3; c21_i1 = c21_i1 + 1) {
    c21_y[c21_i1] = c21_dv0[c21_i1];
  }

  sf_mex_destroy(&c21_stick_out);
  for (c21_i2 = 0; c21_i2 < 3; c21_i2 = c21_i2 + 1) {
    (*c21_b_stick_out)[c21_i2] = c21_y[c21_i2];
  }

  c21_is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim = sf_mex_dup
    (sf_mex_getcell(c21_u, 1));
  sf_mex_import("is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim",
                sf_mex_dup(
    c21_is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim), &c21_u0, 1, 3,
                0U, 0, 0U, 0);
  c21_b_y = c21_u0;
  sf_mex_destroy(&c21_is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim);
  *c21_b_is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim = c21_b_y;
  sf_mex_destroy(&c21_u);
  c21_update_debugger_state_c21_M37_Sim_Forcing_003h_expe_infra_t();
  sf_mex_destroy(&c21_st);
}

static void finalize_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void sf_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c21_i3;
  int32_T c21_i4;
  int32_T c21_previousEvent;
  real_T c21_threshold;
  real_T c21_enabled;
  int32_T c21_i5;
  real_T c21_stick_in[3];
  real_T c21_nargout = 1.0;
  real_T c21_nargin = 3.0;
  real_T c21_i;
  real_T c21_stick_out[3];
  int32_T c21_i6;
  real_T c21_b_i;
  real_T c21_x;
  real_T c21_b_x;
  real_T c21_y;
  real_T c21_c_x;
  real_T c21_a;
  real_T c21_d_x;
  real_T c21_e_x;
  boolean_T c21_b;
  real_T c21_f_x;
  real_T c21_g_x;
  real_T c21_b_y;
  real_T c21_b_b;
  real_T c21_A;
  real_T c21_B;
  real_T c21_h_x;
  real_T c21_c_y;
  real_T c21_i_x;
  real_T c21_d_y;
  real_T c21_j_x;
  real_T c21_e_y;
  real_T c21_f_y;
  int32_T c21_i7;
  int32_T c21_i8;
  real_T *c21_b_threshold;
  real_T *c21_b_enabled;
  real_T (*c21_b_stick_out)[3];
  real_T (*c21_b_stick_in)[3];
  c21_b_enabled = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c21_b_stick_in = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 2);
  c21_b_stick_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c21_b_threshold = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,15);
  _SFD_DATA_RANGE_CHECK(*c21_b_threshold, 0U);
  for (c21_i3 = 0; c21_i3 < 3; c21_i3 = c21_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c21_b_stick_out)[c21_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c21_b_enabled, 2U);
  for (c21_i4 = 0; c21_i4 < 3; c21_i4 = c21_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c21_b_stick_in)[c21_i4], 3U);
  }

  c21_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,15);
  c21_threshold = *c21_b_threshold;
  c21_enabled = *c21_b_enabled;
  for (c21_i5 = 0; c21_i5 < 3; c21_i5 = c21_i5 + 1) {
    c21_stick_in[c21_i5] = (*c21_b_stick_in)[c21_i5];
  }

  sf_debug_symbol_scope_push(7U, 0U);
  sf_debug_symbol_scope_add("nargout", &c21_nargout, c21_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c21_nargin, c21_sf_marshall);
  sf_debug_symbol_scope_add("i", &c21_i, c21_sf_marshall);
  sf_debug_symbol_scope_add("stick_out", &c21_stick_out, c21_b_sf_marshall);
  sf_debug_symbol_scope_add("stick_in", &c21_stick_in, c21_b_sf_marshall);
  sf_debug_symbol_scope_add("enabled", &c21_enabled, c21_sf_marshall);
  sf_debug_symbol_scope_add("threshold", &c21_threshold, c21_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  for (c21_i6 = 0; c21_i6 < 3; c21_i6 = c21_i6 + 1) {
    c21_stick_out[c21_i6] = 0.0;
  }

  _SFD_EML_CALL(0,4);
  if (CV_EML_IF(0, 0, c21_enabled != 0.0) != 0.0) {
    c21_i = 1.0;
    c21_b_i = 1.0;
    while (c21_b_i <= 3.0) {
      c21_i = c21_b_i;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(0,7);
      c21_x = c21_stick_in[_SFD_EML_ARRAY_BOUNDS_CHECK("stick_in", (int32_T)
        _SFD_INTEGER_CHECK("i", c21_i), 1, 3, 1, 0) - 1];
      c21_b_x = c21_x;
      c21_y = muDoubleScalarAbs(c21_b_x);
      if (CV_EML_IF(0, 1, c21_y < c21_threshold)) {
        _SFD_EML_CALL(0,8);
        c21_stick_out[_SFD_EML_ARRAY_BOUNDS_CHECK("stick_out", (int32_T)
          _SFD_INTEGER_CHECK("i", c21_i), 1, 3, 1, 0) - 1] = 0.0;
      } else {
        _SFD_EML_CALL(0,10);
        c21_c_x = c21_stick_in[_SFD_EML_ARRAY_BOUNDS_CHECK("stick_in", (int32_T)
          _SFD_INTEGER_CHECK("i", c21_i), 1, 3, 1, 0) - 1];
        c21_a = c21_c_x;
        c21_d_x = c21_a;
        c21_a = c21_d_x;
        c21_e_x = c21_a;
        c21_b = rtIsNaN(c21_e_x);
        if (c21_b) {
          c21_a = rtNaN;
        } else if (c21_a > 0.0) {
          c21_a = 1.0;
        } else if (c21_a < 0.0) {
          c21_a = -1.0;
        } else {
          c21_a = 0.0;
        }

        c21_f_x = c21_stick_in[_SFD_EML_ARRAY_BOUNDS_CHECK("stick_in", (int32_T)
          _SFD_INTEGER_CHECK("i", c21_i), 1, 3, 1, 0) - 1];
        c21_g_x = c21_f_x;
        c21_b_y = muDoubleScalarAbs(c21_g_x);
        c21_b_b = c21_b_y - c21_threshold;
        c21_A = c21_a * c21_b_b;
        c21_B = 1.0 - c21_threshold;
        c21_h_x = c21_A;
        c21_c_y = c21_B;
        if (c21_c_y == 0.0) {
          c21_eml_warning();
        }

        c21_i_x = c21_h_x;
        c21_d_y = c21_c_y;
        c21_j_x = c21_i_x;
        c21_e_y = c21_d_y;
        c21_f_y = c21_j_x / c21_e_y;
        c21_stick_out[_SFD_EML_ARRAY_BOUNDS_CHECK("stick_out", (int32_T)
          _SFD_INTEGER_CHECK("i", c21_i), 1, 3, 1, 0) - 1] = c21_f_y;
      }

      c21_b_i = c21_b_i + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance.S);
    }

    CV_EML_FOR(0, 0, 0);
  } else {
    _SFD_EML_CALL(0,14);
    for (c21_i7 = 0; c21_i7 < 3; c21_i7 = c21_i7 + 1) {
      c21_stick_out[c21_i7] = c21_stick_in[c21_i7];
    }
  }

  _SFD_EML_CALL(0,-14);
  sf_debug_symbol_scope_pop();
  for (c21_i8 = 0; c21_i8 < 3; c21_i8 = c21_i8 + 1) {
    (*c21_b_stick_out)[c21_i8] = c21_stick_out[c21_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,15);
  _sfEvent_ = c21_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber)
{
}

static void c21_eml_warning(void)
{
  int32_T c21_i9;
  static char_T c21_cv0[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c21_u[15];
  const mxArray *c21_y = NULL;
  int32_T c21_i10;
  static char_T c21_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c21_b_u[19];
  const mxArray *c21_b_y = NULL;
  for (c21_i9 = 0; c21_i9 < 15; c21_i9 = c21_i9 + 1) {
    c21_u[c21_i9] = c21_cv0[c21_i9];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c21_i10 = 0; c21_i10 < 19; c21_i10 = c21_i10 + 1) {
    c21_b_u[c21_i10] = c21_cv1[c21_i10];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c21_b_y, 14, c21_y);
}

static const mxArray *c21_sf_marshall(void *c21_chartInstance, void *c21_u)
{
  const mxArray *c21_y = NULL;
  real_T c21_b_u;
  const mxArray *c21_b_y = NULL;
  c21_y = NULL;
  c21_b_u = *((real_T *)c21_u);
  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c21_y, c21_b_y);
  return c21_y;
}

static const mxArray *c21_b_sf_marshall(void *c21_chartInstance, void *c21_u)
{
  const mxArray *c21_y = NULL;
  int32_T c21_i11;
  real_T c21_b_u[3];
  const mxArray *c21_b_y = NULL;
  c21_y = NULL;
  for (c21_i11 = 0; c21_i11 < 3; c21_i11 = c21_i11 + 1) {
    c21_b_u[c21_i11] = (*((real_T (*)[3])c21_u))[c21_i11];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c21_y, c21_b_y);
  return c21_y;
}

const mxArray
  *sf_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c21_nameCaptureInfo = NULL;
  c21_ResolvedFunctionInfo c21_info[34];
  const mxArray *c21_m0 = NULL;
  int32_T c21_i12;
  c21_ResolvedFunctionInfo *c21_r0;
  c21_nameCaptureInfo = NULL;
  c21_info_helper(c21_info);
  sf_mex_assign(&c21_m0, sf_mex_createstruct("nameCaptureInfo", 1, 34));
  for (c21_i12 = 0; c21_i12 < 34; c21_i12 = c21_i12 + 1) {
    c21_r0 = &c21_info[c21_i12];
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c21_r0->context)), "context"
                    , "nameCaptureInfo", c21_i12);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c21_r0->name)), "name",
                    "nameCaptureInfo", c21_i12);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo",
      c21_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c21_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c21_i12);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c21_r0->resolved)),
                    "resolved", "nameCaptureInfo", c21_i12);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c21_i12);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c21_i12);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c21_i12);
  }

  sf_mex_assign(&c21_nameCaptureInfo, c21_m0);
  return c21_nameCaptureInfo;
}

static void c21_info_helper(c21_ResolvedFunctionInfo c21_info[34])
{
  c21_info[0].context = "";
  c21_info[0].name = "ctranspose";
  c21_info[0].dominantType = "double";
  c21_info[0].resolved = "[B]ctranspose";
  c21_info[0].fileLength = 0U;
  c21_info[0].fileTime1 = 0U;
  c21_info[0].fileTime2 = 0U;
  c21_info[1].context = "";
  c21_info[1].name = "abs";
  c21_info[1].dominantType = "double";
  c21_info[1].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[1].fileLength = 566U;
  c21_info[1].fileTime1 = 1221267134U;
  c21_info[1].fileTime2 = 0U;
  c21_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[2].name = "nargin";
  c21_info[2].dominantType = "";
  c21_info[2].resolved = "[B]nargin";
  c21_info[2].fileLength = 0U;
  c21_info[2].fileTime1 = 0U;
  c21_info[2].fileTime2 = 0U;
  c21_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[3].name = "gt";
  c21_info[3].dominantType = "double";
  c21_info[3].resolved = "[B]gt";
  c21_info[3].fileLength = 0U;
  c21_info[3].fileTime1 = 0U;
  c21_info[3].fileTime2 = 0U;
  c21_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[4].name = "isa";
  c21_info[4].dominantType = "double";
  c21_info[4].resolved = "[B]isa";
  c21_info[4].fileLength = 0U;
  c21_info[4].fileTime1 = 0U;
  c21_info[4].fileTime2 = 0U;
  c21_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[5].name = "ischar";
  c21_info[5].dominantType = "double";
  c21_info[5].resolved = "[B]ischar";
  c21_info[5].fileLength = 0U;
  c21_info[5].fileTime1 = 0U;
  c21_info[5].fileTime2 = 0U;
  c21_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[6].name = "islogical";
  c21_info[6].dominantType = "double";
  c21_info[6].resolved = "[B]islogical";
  c21_info[6].fileLength = 0U;
  c21_info[6].fileTime1 = 0U;
  c21_info[6].fileTime2 = 0U;
  c21_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[7].name = "size";
  c21_info[7].dominantType = "double";
  c21_info[7].resolved = "[B]size";
  c21_info[7].fileLength = 0U;
  c21_info[7].fileTime1 = 0U;
  c21_info[7].fileTime2 = 0U;
  c21_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[8].name = "class";
  c21_info[8].dominantType = "double";
  c21_info[8].resolved = "[B]class";
  c21_info[8].fileLength = 0U;
  c21_info[8].fileTime1 = 0U;
  c21_info[8].fileTime2 = 0U;
  c21_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[9].name = "zeros";
  c21_info[9].dominantType = "double";
  c21_info[9].resolved = "[B]zeros";
  c21_info[9].fileLength = 0U;
  c21_info[9].fileTime1 = 0U;
  c21_info[9].fileTime2 = 0U;
  c21_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c21_info[10].name = "eml_scalar_abs";
  c21_info[10].dominantType = "double";
  c21_info[10].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c21_info[10].fileLength = 461U;
  c21_info[10].fileTime1 = 1203447960U;
  c21_info[10].fileTime2 = 0U;
  c21_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c21_info[11].name = "isinteger";
  c21_info[11].dominantType = "double";
  c21_info[11].resolved = "[B]isinteger";
  c21_info[11].fileLength = 0U;
  c21_info[11].fileTime1 = 0U;
  c21_info[11].fileTime2 = 0U;
  c21_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c21_info[12].name = "isreal";
  c21_info[12].dominantType = "double";
  c21_info[12].resolved = "[B]isreal";
  c21_info[12].fileLength = 0U;
  c21_info[12].fileTime1 = 0U;
  c21_info[12].fileTime2 = 0U;
  c21_info[13].context = "";
  c21_info[13].name = "lt";
  c21_info[13].dominantType = "double";
  c21_info[13].resolved = "[B]lt";
  c21_info[13].fileLength = 0U;
  c21_info[13].fileTime1 = 0U;
  c21_info[13].fileTime2 = 0U;
  c21_info[14].context = "";
  c21_info[14].name = "sign";
  c21_info[14].dominantType = "double";
  c21_info[14].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c21_info[14].fileLength = 408U;
  c21_info[14].fileTime1 = 1203448042U;
  c21_info[14].fileTime2 = 0U;
  c21_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c21_info[15].name = "eq";
  c21_info[15].dominantType = "double";
  c21_info[15].resolved = "[B]eq";
  c21_info[15].fileLength = 0U;
  c21_info[15].fileTime1 = 0U;
  c21_info[15].fileTime2 = 0U;
  c21_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c21_info[16].name = "eml_scalar_sign";
  c21_info[16].dominantType = "double";
  c21_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c21_info[16].fileLength = 543U;
  c21_info[16].fileTime1 = 1203448012U;
  c21_info[16].fileTime2 = 0U;
  c21_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c21_info[17].name = "isnan";
  c21_info[17].dominantType = "double";
  c21_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c21_info[17].fileLength = 506U;
  c21_info[17].fileTime1 = 1228093810U;
  c21_info[17].fileTime2 = 0U;
  c21_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c21_info[18].name = "eml_guarded_nan";
  c21_info[18].dominantType = "char";
  c21_info[18].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c21_info[18].fileLength = 485U;
  c21_info[18].fileTime1 = 1192466780U;
  c21_info[18].fileTime2 = 0U;
  c21_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c21_info[19].name = "eml_is_float_class";
  c21_info[19].dominantType = "char";
  c21_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c21_info[19].fileLength = 226U;
  c21_info[19].fileTime1 = 1197850442U;
  c21_info[19].fileTime2 = 0U;
  c21_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c21_info[20].name = "strcmp";
  c21_info[20].dominantType = "char";
  c21_info[20].resolved = "[B]strcmp";
  c21_info[20].fileLength = 0U;
  c21_info[20].fileTime1 = 0U;
  c21_info[20].fileTime2 = 0U;
  c21_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c21_info[21].name = "nan";
  c21_info[21].dominantType = "char";
  c21_info[21].resolved = "[B]nan";
  c21_info[21].fileLength = 0U;
  c21_info[21].fileTime1 = 0U;
  c21_info[21].fileTime2 = 0U;
  c21_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c21_info[22].name = "ones";
  c21_info[22].dominantType = "char";
  c21_info[22].resolved = "[B]ones";
  c21_info[22].fileLength = 0U;
  c21_info[22].fileTime1 = 0U;
  c21_info[22].fileTime2 = 0U;
  c21_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c21_info[23].name = "uminus";
  c21_info[23].dominantType = "double";
  c21_info[23].resolved = "[B]uminus";
  c21_info[23].fileLength = 0U;
  c21_info[23].fileTime1 = 0U;
  c21_info[23].fileTime2 = 0U;
  c21_info[24].context = "";
  c21_info[24].name = "minus";
  c21_info[24].dominantType = "double";
  c21_info[24].resolved = "[B]minus";
  c21_info[24].fileLength = 0U;
  c21_info[24].fileTime1 = 0U;
  c21_info[24].fileTime2 = 0U;
  c21_info[25].context = "";
  c21_info[25].name = "mtimes";
  c21_info[25].dominantType = "double";
  c21_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[25].fileLength = 3302U;
  c21_info[25].fileTime1 = 1242750894U;
  c21_info[25].fileTime2 = 0U;
  c21_info[26].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[26].name = "isscalar";
  c21_info[26].dominantType = "double";
  c21_info[26].resolved = "[B]isscalar";
  c21_info[26].fileLength = 0U;
  c21_info[26].fileTime1 = 0U;
  c21_info[26].fileTime2 = 0U;
  c21_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[27].name = "not";
  c21_info[27].dominantType = "logical";
  c21_info[27].resolved = "[B]not";
  c21_info[27].fileLength = 0U;
  c21_info[27].fileTime1 = 0U;
  c21_info[27].fileTime2 = 0U;
  c21_info[28].context = "";
  c21_info[28].name = "mrdivide";
  c21_info[28].dominantType = "double";
  c21_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c21_info[28].fileLength = 800U;
  c21_info[28].fileTime1 = 1238434292U;
  c21_info[28].fileTime2 = 0U;
  c21_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c21_info[29].name = "ge";
  c21_info[29].dominantType = "double";
  c21_info[29].resolved = "[B]ge";
  c21_info[29].fileLength = 0U;
  c21_info[29].fileTime1 = 0U;
  c21_info[29].fileTime2 = 0U;
  c21_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c21_info[30].name = "rdivide";
  c21_info[30].dominantType = "double";
  c21_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c21_info[30].fileLength = 620U;
  c21_info[30].fileTime1 = 1213926766U;
  c21_info[30].fileTime2 = 0U;
  c21_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c21_info[31].name = "isempty";
  c21_info[31].dominantType = "double";
  c21_info[31].resolved = "[B]isempty";
  c21_info[31].fileLength = 0U;
  c21_info[31].fileTime1 = 0U;
  c21_info[31].fileTime2 = 0U;
  c21_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c21_info[32].name = "eml_warning";
  c21_info[32].dominantType = "char";
  c21_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c21_info[32].fileLength = 262U;
  c21_info[32].fileTime1 = 1236257278U;
  c21_info[32].fileTime2 = 0U;
  c21_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c21_info[33].name = "eml_div";
  c21_info[33].dominantType = "double";
  c21_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c21_info[33].fileLength = 4269U;
  c21_info[33].fileTime1 = 1228093826U;
  c21_info[33].fileTime2 = 0U;
}

static const mxArray *c21_c_sf_marshall(void *c21_chartInstance, void *c21_u)
{
  const mxArray *c21_y = NULL;
  boolean_T c21_b_u;
  const mxArray *c21_b_y = NULL;
  c21_y = NULL;
  c21_b_u = *((boolean_T *)c21_u);
  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c21_y, c21_b_y);
  return c21_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(268733470U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2671161671U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2208360170U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3474047278U);
}

mxArray
  *sf_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2771797471U);
    pr[1] = (double)(631501575U);
    pr[2] = (double)(206883667U);
    pr[3] = (double)(2810887691U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
  *sf_get_sim_state_info_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"stick_out\",},{M[8],M[0],T\"is_active_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(&mxChecksum);
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
           21,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "threshold",0,(MexFcnForType)c21_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"stick_out",0,(MexFcnForType)
                                c21_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"enabled",
                              0,(MexFcnForType)c21_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"stick_in",0,(MexFcnForType)
                                c21_b_sf_marshall);
          }

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
        _SFD_CV_INIT_EML(0,1,2,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,303);
        _SFD_CV_INIT_EML_IF(0,0,86,97,272,303);
        _SFD_CV_INIT_EML_IF(0,1,113,143,172,267);
        _SFD_CV_INIT_EML_FOR(0,0,99,109,271);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c21_threshold;
          real_T (*c21_stick_out)[3];
          real_T *c21_enabled;
          real_T (*c21_stick_in)[3];
          c21_enabled = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c21_stick_in = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 2);
          c21_stick_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S,
            1);
          c21_threshold = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c21_threshold);
          _SFD_SET_DATA_VALUE_PTR(1U, c21_stick_out);
          _SFD_SET_DATA_VALUE_PTR(2U, c21_enabled);
          _SFD_SET_DATA_VALUE_PTR(3U, c21_stick_in);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  initialize_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_enable_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  enable_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_disable_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  disable_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_gateway_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  sf_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void
  sf_opaque_ext_mode_exec_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  ext_mode_exec_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static mxArray*
  sf_opaque_get_sim_state_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  return st;
}

static void
  sf_opaque_set_sim_state_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(sf_mex_dup(st));
}

static void sf_opaque_terminate_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",21);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",21,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",21,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",21,3);
      sf_mark_chart_reusable_outputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",21,1);
    }

    sf_set_rtw_dwork_info(S,"M37_Sim_Forcing_003h_expe_infra_transz_lim",
                          "M37_Sim_Forcing_003h_expe_infra_transz_lim",21);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(2476045536U));
  ssSetChecksum1(S,(652052201U));
  ssSetChecksum2(S,(3097872786U));
  ssSetChecksum3(S,(3190791169U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",21);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim;
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

void c21_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(SimStruct *
  S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c21_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

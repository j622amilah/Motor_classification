/* Include files */

#include "blascompat32.h"
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun.h"
#include "c9_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c9_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc9_M37_Sim_Forcing_003h_expe_infra_transz_limInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void initialize_params_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void enable_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void disable_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c9_update_debugger_state_c9_M37_Sim_Forcing_003h_expe_infra_tra(void);
static void ext_mode_exec_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static const mxArray
  *get_sim_state_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void set_sim_state_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c9_st);
static void finalize_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void sf_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshall(void *c9_chartInstance, void *c9_u);
static const mxArray *c9_b_sf_marshall(void *c9_chartInstance, void *c9_u);
static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[39]);
static const mxArray *c9_c_sf_marshall(void *c9_chartInstance, void *c9_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  uint8_T *c9_is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c9_is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c9_is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim = 0U;
}

static void initialize_params_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void enable_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c9_update_debugger_state_c9_M37_Sim_Forcing_003h_expe_infra_tra(void)
{
}

static void ext_mode_exec_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  c9_update_debugger_state_c9_M37_Sim_Forcing_003h_expe_infra_tra();
}

static const mxArray
  *get_sim_state_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const mxArray *c9_st = NULL;
  const mxArray *c9_y = NULL;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  uint8_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T *c9_T;
  uint8_T *c9_is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c9_is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c9_T = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(2));
  c9_u = *c9_T;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_u = *c9_is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c9_y, 1, c9_c_y);
  sf_mex_assign(&c9_st, c9_y);
  return c9_st;
}

static void set_sim_state_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c9_st)
{
  const mxArray *c9_u;
  const mxArray *c9_T;
  real_T c9_d0;
  real_T c9_y;
  const mxArray *c9_is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  uint8_T c9_u0;
  uint8_T c9_b_y;
  boolean_T *c9_doneDoubleBufferReInit;
  real_T *c9_b_T;
  uint8_T *c9_b_is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c9_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c9_b_is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c9_b_T = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  *c9_doneDoubleBufferReInit = true;
  c9_u = sf_mex_dup(c9_st);
  c9_T = sf_mex_dup(sf_mex_getcell(c9_u, 0));
  sf_mex_import("T", sf_mex_dup(c9_T), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_T);
  *c9_b_T = c9_y;
  c9_is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim = sf_mex_dup
    (sf_mex_getcell(c9_u, 1));
  sf_mex_import("is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim",
                sf_mex_dup(
    c9_is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim), &c9_u0, 1, 3,
                0U, 0, 0U, 0);
  c9_b_y = c9_u0;
  sf_mex_destroy(&c9_is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim);
  *c9_b_is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim = c9_b_y;
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_M37_Sim_Forcing_003h_expe_infra_tra();
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void sf_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c9_i0;
  int32_T c9_previousEvent;
  int32_T c9_i1;
  real_T c9_com_pos[3];
  real_T c9_threshold;
  real_T c9_nargout = 1.0;
  real_T c9_nargin = 2.0;
  real_T c9_max_tilt;
  real_T c9_T;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_y;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_b_y;
  real_T c9_e_x;
  real_T c9_f_x;
  real_T c9_c_y;
  real_T c9_varargin_1[3];
  int32_T c9_i2;
  real_T c9_g_x[3];
  int32_T c9_i3;
  real_T c9_h_x[3];
  real_T c9_mtmp;
  int32_T c9_itmp;
  int32_T c9_ix;
  real_T c9_i_x;
  boolean_T c9_b;
  boolean_T c9_searchingForNonNaN;
  int32_T c9_k;
  int32_T c9_b_k;
  int32_T c9_a;
  real_T c9_j_x;
  boolean_T c9_b_b;
  int32_T c9_b_a;
  int32_T c9_i4;
  int32_T c9_c_k;
  int32_T c9_c_a;
  real_T c9_b_mtmp;
  real_T c9_A;
  real_T c9_k_x;
  real_T c9_l_x;
  real_T c9_m_x;
  real_T *c9_b_T;
  real_T *c9_b_threshold;
  real_T (*c9_b_com_pos)[3];
  c9_b_threshold = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c9_b_com_pos = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c9_b_T = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,8);
  for (c9_i0 = 0; c9_i0 < 3; c9_i0 = c9_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c9_b_com_pos)[c9_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c9_b_T, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_b_threshold, 2U);
  c9_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,8);
  for (c9_i1 = 0; c9_i1 < 3; c9_i1 = c9_i1 + 1) {
    c9_com_pos[c9_i1] = (*c9_b_com_pos)[c9_i1];
  }

  c9_threshold = *c9_b_threshold;
  sf_debug_symbol_scope_push(6U, 0U);
  sf_debug_symbol_scope_add("nargout", &c9_nargout, c9_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c9_nargin, c9_b_sf_marshall);
  sf_debug_symbol_scope_add("max_tilt", &c9_max_tilt, c9_b_sf_marshall);
  sf_debug_symbol_scope_add("T", &c9_T, c9_b_sf_marshall);
  sf_debug_symbol_scope_add("threshold", &c9_threshold, c9_b_sf_marshall);
  sf_debug_symbol_scope_add("com_pos", &c9_com_pos, c9_sf_marshall);
  CV_EML_FCN(0, 0);

  /* abs_yaw=abs(com_or(1))+abs(com_or(2))+abs(com_or(3))+abs(com_or(4)); */
  _SFD_EML_CALL(0,4);
  c9_x = c9_com_pos[2];
  c9_b_x = c9_x;
  c9_y = muDoubleScalarAbs(c9_b_x);
  c9_c_x = c9_com_pos[1];
  c9_d_x = c9_c_x;
  c9_b_y = muDoubleScalarAbs(c9_d_x);
  c9_e_x = c9_com_pos[0];
  c9_f_x = c9_e_x;
  c9_c_y = muDoubleScalarAbs(c9_f_x);
  c9_varargin_1[0] = c9_c_y;
  c9_varargin_1[1] = c9_b_y;
  c9_varargin_1[2] = c9_y;
  for (c9_i2 = 0; c9_i2 < 3; c9_i2 = c9_i2 + 1) {
    c9_g_x[c9_i2] = c9_varargin_1[c9_i2];
  }

  for (c9_i3 = 0; c9_i3 < 3; c9_i3 = c9_i3 + 1) {
    c9_h_x[c9_i3] = c9_g_x[c9_i3];
  }

  c9_mtmp = c9_h_x[0];
  c9_itmp = 1;
  c9_ix = 1;
  c9_i_x = c9_mtmp;
  c9_b = rtIsNaN(c9_i_x);
  if (c9_b) {
    c9_searchingForNonNaN = true;
    c9_k = 2;
   label_1:
    ;
    if (c9_k < 4) {
      c9_b_k = c9_k;
      c9_a = c9_ix;
      c9_ix = c9_a + 1;
      c9_j_x = c9_h_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("ix", (real_T)c9_ix), 1, 3, 1, 0) - 1];
      c9_b_b = rtIsNaN(c9_j_x);
      if (!c9_b_b) {
        c9_mtmp = c9_h_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
          _SFD_INTEGER_CHECK("ix", (real_T)c9_ix), 1, 3, 1, 0) - 1];
        c9_itmp = c9_b_k;
        c9_searchingForNonNaN = false;
      } else {
        c9_k = c9_k + 1;
        goto label_1;
      }
    }

    if (c9_searchingForNonNaN) {
      goto label_2;
    }
  }

  c9_b_a = c9_itmp;
  c9_i4 = c9_b_a + 1;
  for (c9_c_k = c9_i4; c9_c_k < 4; c9_c_k = c9_c_k + 1) {
    c9_c_a = c9_ix;
    c9_ix = c9_c_a + 1;
    if (c9_h_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("ix",
          (real_T)c9_ix), 1, 3, 1, 0) - 1] > c9_mtmp) {
      c9_mtmp = c9_h_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("ix", (real_T)c9_ix), 1, 3, 1, 0) - 1];
    }
  }

 label_2:
  ;
  c9_b_mtmp = c9_mtmp;
  c9_max_tilt = c9_b_mtmp;
  _SFD_EML_CALL(0,6);
  if (CV_EML_IF(0, 0, c9_max_tilt > c9_threshold)) {
    /* T=max_tilt/2; */
    _SFD_EML_CALL(0,8);
    c9_A = c9_max_tilt;
    c9_k_x = c9_A;
    c9_l_x = c9_k_x;
    c9_m_x = c9_l_x;
    c9_T = c9_m_x / 3.0;
  } else {
    _SFD_EML_CALL(0,10);
    c9_T = 7.0;

    /* note: threshold should be 21 */
    /* T=10; %note: threshold should be 20 */
  }

  _SFD_EML_CALL(0,-10);
  sf_debug_symbol_scope_pop();
  *c9_b_T = c9_T;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
  _sfEvent_ = c9_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshall(void *c9_chartInstance, void *c9_u)
{
  const mxArray *c9_y = NULL;
  int32_T c9_i5;
  real_T c9_b_u[3];
  const mxArray *c9_b_y = NULL;
  c9_y = NULL;
  for (c9_i5 = 0; c9_i5 < 3; c9_i5 = c9_i5 + 1) {
    c9_b_u[c9_i5] = (*((real_T (*)[3])c9_u))[c9_i5];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static const mxArray *c9_b_sf_marshall(void *c9_chartInstance, void *c9_u)
{
  const mxArray *c9_y = NULL;
  real_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  c9_y = NULL;
  c9_b_u = *((real_T *)c9_u);
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

const mxArray
  *sf_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_ResolvedFunctionInfo c9_info[39];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i6;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_info_helper(c9_info);
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 39));
  for (c9_i6 = 0; c9_i6 < 39; c9_i6 = c9_i6 + 1) {
    c9_r0 = &c9_info[c9_i6];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context",
                    "nameCaptureInfo", c9_i6);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name",
                    "nameCaptureInfo", c9_i6);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c9_i6);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c9_i6);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c9_i6);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c9_i6);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c9_i6);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[39])
{
  c9_info[0].context = "";
  c9_info[0].name = "abs";
  c9_info[0].dominantType = "double";
  c9_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[0].fileLength = 566U;
  c9_info[0].fileTime1 = 1221267134U;
  c9_info[0].fileTime2 = 0U;
  c9_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[1].name = "nargin";
  c9_info[1].dominantType = "";
  c9_info[1].resolved = "[B]nargin";
  c9_info[1].fileLength = 0U;
  c9_info[1].fileTime1 = 0U;
  c9_info[1].fileTime2 = 0U;
  c9_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[2].name = "gt";
  c9_info[2].dominantType = "double";
  c9_info[2].resolved = "[B]gt";
  c9_info[2].fileLength = 0U;
  c9_info[2].fileTime1 = 0U;
  c9_info[2].fileTime2 = 0U;
  c9_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[3].name = "isa";
  c9_info[3].dominantType = "double";
  c9_info[3].resolved = "[B]isa";
  c9_info[3].fileLength = 0U;
  c9_info[3].fileTime1 = 0U;
  c9_info[3].fileTime2 = 0U;
  c9_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[4].name = "ischar";
  c9_info[4].dominantType = "double";
  c9_info[4].resolved = "[B]ischar";
  c9_info[4].fileLength = 0U;
  c9_info[4].fileTime1 = 0U;
  c9_info[4].fileTime2 = 0U;
  c9_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[5].name = "islogical";
  c9_info[5].dominantType = "double";
  c9_info[5].resolved = "[B]islogical";
  c9_info[5].fileLength = 0U;
  c9_info[5].fileTime1 = 0U;
  c9_info[5].fileTime2 = 0U;
  c9_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[6].name = "size";
  c9_info[6].dominantType = "double";
  c9_info[6].resolved = "[B]size";
  c9_info[6].fileLength = 0U;
  c9_info[6].fileTime1 = 0U;
  c9_info[6].fileTime2 = 0U;
  c9_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[7].name = "class";
  c9_info[7].dominantType = "double";
  c9_info[7].resolved = "[B]class";
  c9_info[7].fileLength = 0U;
  c9_info[7].fileTime1 = 0U;
  c9_info[7].fileTime2 = 0U;
  c9_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[8].name = "zeros";
  c9_info[8].dominantType = "double";
  c9_info[8].resolved = "[B]zeros";
  c9_info[8].fileLength = 0U;
  c9_info[8].fileTime1 = 0U;
  c9_info[8].fileTime2 = 0U;
  c9_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[9].name = "eml_scalar_abs";
  c9_info[9].dominantType = "double";
  c9_info[9].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c9_info[9].fileLength = 461U;
  c9_info[9].fileTime1 = 1203447960U;
  c9_info[9].fileTime2 = 0U;
  c9_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c9_info[10].name = "isinteger";
  c9_info[10].dominantType = "double";
  c9_info[10].resolved = "[B]isinteger";
  c9_info[10].fileLength = 0U;
  c9_info[10].fileTime1 = 0U;
  c9_info[10].fileTime2 = 0U;
  c9_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c9_info[11].name = "isreal";
  c9_info[11].dominantType = "double";
  c9_info[11].resolved = "[B]isreal";
  c9_info[11].fileLength = 0U;
  c9_info[11].fileTime1 = 0U;
  c9_info[11].fileTime2 = 0U;
  c9_info[12].context = "";
  c9_info[12].name = "max";
  c9_info[12].dominantType = "double";
  c9_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c9_info[12].fileLength = 308U;
  c9_info[12].fileTime1 = 1192466630U;
  c9_info[12].fileTime2 = 0U;
  c9_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c9_info[13].name = "nargout";
  c9_info[13].dominantType = "";
  c9_info[13].resolved = "[B]nargout";
  c9_info[13].fileLength = 0U;
  c9_info[13].fileTime1 = 0U;
  c9_info[13].fileTime2 = 0U;
  c9_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c9_info[14].name = "le";
  c9_info[14].dominantType = "double";
  c9_info[14].resolved = "[B]le";
  c9_info[14].fileLength = 0U;
  c9_info[14].fileTime1 = 0U;
  c9_info[14].fileTime2 = 0U;
  c9_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c9_info[15].name = "eml_min_or_max";
  c9_info[15].dominantType = "char";
  c9_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[15].fileLength = 9969U;
  c9_info[15].fileTime1 = 1240262008U;
  c9_info[15].fileTime2 = 0U;
  c9_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[16].name = "strcmp";
  c9_info[16].dominantType = "char";
  c9_info[16].resolved = "[B]strcmp";
  c9_info[16].fileLength = 0U;
  c9_info[16].fileTime1 = 0U;
  c9_info[16].fileTime2 = 0U;
  c9_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[17].name = "isnumeric";
  c9_info[17].dominantType = "double";
  c9_info[17].resolved = "[B]isnumeric";
  c9_info[17].fileLength = 0U;
  c9_info[17].fileTime1 = 0U;
  c9_info[17].fileTime2 = 0U;
  c9_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[18].name = "eq";
  c9_info[18].dominantType = "double";
  c9_info[18].resolved = "[B]eq";
  c9_info[18].fileLength = 0U;
  c9_info[18].fileTime1 = 0U;
  c9_info[18].fileTime2 = 0U;
  c9_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[19].name = "eml_const_nonsingleton_dim";
  c9_info[19].dominantType = "double";
  c9_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c9_info[19].fileLength = 1473U;
  c9_info[19].fileTime1 = 1240262004U;
  c9_info[19].fileTime2 = 0U;
  c9_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m/local_const_nonsingleton_dim";
  c9_info[20].name = "not";
  c9_info[20].dominantType = "logical";
  c9_info[20].resolved = "[B]not";
  c9_info[20].fileLength = 0U;
  c9_info[20].fileTime1 = 0U;
  c9_info[20].fileTime2 = 0U;
  c9_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m/local_const_nonsingleton_dim";
  c9_info[21].name = "ne";
  c9_info[21].dominantType = "double";
  c9_info[21].resolved = "[B]ne";
  c9_info[21].fileLength = 0U;
  c9_info[21].fileTime1 = 0U;
  c9_info[21].fileTime2 = 0U;
  c9_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[22].name = "eml_scalar_eg";
  c9_info[22].dominantType = "double";
  c9_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[22].fileLength = 3068U;
  c9_info[22].fileTime1 = 1240262010U;
  c9_info[22].fileTime2 = 0U;
  c9_info[23].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c9_info[23].name = "false";
  c9_info[23].dominantType = "";
  c9_info[23].resolved = "[B]false";
  c9_info[23].fileLength = 0U;
  c9_info[23].fileTime1 = 0U;
  c9_info[23].fileTime2 = 0U;
  c9_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[24].name = "isstruct";
  c9_info[24].dominantType = "double";
  c9_info[24].resolved = "[B]isstruct";
  c9_info[24].fileLength = 0U;
  c9_info[24].fileTime1 = 0U;
  c9_info[24].fileTime2 = 0U;
  c9_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c9_info[25].name = "cast";
  c9_info[25].dominantType = "double";
  c9_info[25].resolved = "[B]cast";
  c9_info[25].fileLength = 0U;
  c9_info[25].fileTime1 = 0U;
  c9_info[25].fileTime2 = 0U;
  c9_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[26].name = "ones";
  c9_info[26].dominantType = "double";
  c9_info[26].resolved = "[B]ones";
  c9_info[26].fileLength = 0U;
  c9_info[26].fileTime1 = 0U;
  c9_info[26].fileTime2 = 0U;
  c9_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[27].name = "eml_index_class";
  c9_info[27].dominantType = "";
  c9_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[27].fileLength = 909U;
  c9_info[27].fileTime1 = 1192466782U;
  c9_info[27].fileTime2 = 0U;
  c9_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[28].name = "isempty";
  c9_info[28].dominantType = "double";
  c9_info[28].resolved = "[B]isempty";
  c9_info[28].fileLength = 0U;
  c9_info[28].fileTime1 = 0U;
  c9_info[28].fileTime2 = 0U;
  c9_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[29].name = "isscalar";
  c9_info[29].dominantType = "double";
  c9_info[29].resolved = "[B]isscalar";
  c9_info[29].fileLength = 0U;
  c9_info[29].fileTime1 = 0U;
  c9_info[29].fileTime2 = 0U;
  c9_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c9_info[30].name = "lt";
  c9_info[30].dominantType = "double";
  c9_info[30].resolved = "[B]lt";
  c9_info[30].fileLength = 0U;
  c9_info[30].fileTime1 = 0U;
  c9_info[30].fileTime2 = 0U;
  c9_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c9_info[31].name = "isnan";
  c9_info[31].dominantType = "double";
  c9_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c9_info[31].fileLength = 506U;
  c9_info[31].fileTime1 = 1228093810U;
  c9_info[31].fileTime2 = 0U;
  c9_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c9_info[32].name = "true";
  c9_info[32].dominantType = "";
  c9_info[32].resolved = "[B]true";
  c9_info[32].fileLength = 0U;
  c9_info[32].fileTime1 = 0U;
  c9_info[32].fileTime2 = 0U;
  c9_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_extremum_sub";
  c9_info[33].name = "eml_index_plus";
  c9_info[33].dominantType = "int32";
  c9_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[33].fileLength = 272U;
  c9_info[33].fileTime1 = 1192466786U;
  c9_info[33].fileTime2 = 0U;
  c9_info[34].context = "";
  c9_info[34].name = "mrdivide";
  c9_info[34].dominantType = "double";
  c9_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c9_info[34].fileLength = 800U;
  c9_info[34].fileTime1 = 1238434292U;
  c9_info[34].fileTime2 = 0U;
  c9_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c9_info[35].name = "ge";
  c9_info[35].dominantType = "double";
  c9_info[35].resolved = "[B]ge";
  c9_info[35].fileLength = 0U;
  c9_info[35].fileTime1 = 0U;
  c9_info[35].fileTime2 = 0U;
  c9_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c9_info[36].name = "rdivide";
  c9_info[36].dominantType = "double";
  c9_info[36].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[36].fileLength = 620U;
  c9_info[36].fileTime1 = 1213926766U;
  c9_info[36].fileTime2 = 0U;
  c9_info[37].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[37].name = "eml_warning";
  c9_info[37].dominantType = "char";
  c9_info[37].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c9_info[37].fileLength = 262U;
  c9_info[37].fileTime1 = 1236257278U;
  c9_info[37].fileTime2 = 0U;
  c9_info[38].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[38].name = "eml_div";
  c9_info[38].dominantType = "double";
  c9_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c9_info[38].fileLength = 4269U;
  c9_info[38].fileTime1 = 1228093826U;
  c9_info[38].fileTime2 = 0U;
}

static const mxArray *c9_c_sf_marshall(void *c9_chartInstance, void *c9_u)
{
  const mxArray *c9_y = NULL;
  boolean_T c9_b_u;
  const mxArray *c9_b_y = NULL;
  c9_y = NULL;
  c9_b_u = *((boolean_T *)c9_u);
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c9_y, c9_b_y);
  return c9_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2180803067U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2879839005U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3195328393U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1793287653U);
}

mxArray
  *sf_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(715880518U);
    pr[1] = (double)(3301127877U);
    pr[2] = (double)(1393429173U);
    pr[3] = (double)(2887684469U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
  *sf_get_sim_state_info_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"T\",},{M[8],M[0],T\"is_active_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(&mxChecksum);
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
           9,
           1,
           1,
           3,
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
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"com_pos",0,(MexFcnForType)c9_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"T",0,
                              (MexFcnForType)c9_b_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "threshold",0,(MexFcnForType)c9_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,346);
        _SFD_CV_INIT_EML_IF(0,0,187,209,247,339);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c9_com_pos)[3];
          real_T *c9_T;
          real_T *c9_threshold;
          c9_threshold = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c9_com_pos = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          c9_T = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_com_pos);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_T);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_threshold);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  initialize_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_enable_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void *
  chartInstanceVar)
{
  enable_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_disable_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  disable_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_gateway_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  sf_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void
  sf_opaque_ext_mode_exec_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  ext_mode_exec_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static mxArray*
  sf_opaque_get_sim_state_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  return st;
}

static void
  sf_opaque_set_sim_state_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(sf_mex_dup(st));
}

static void sf_opaque_terminate_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",9,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",9,2);
      sf_mark_chart_reusable_outputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",9,1);
    }

    sf_set_rtw_dwork_info(S,"M37_Sim_Forcing_003h_expe_infra_transz_lim",
                          "M37_Sim_Forcing_003h_expe_infra_transz_lim",9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(3785703193U));
  ssSetChecksum1(S,(1355812836U));
  ssSetChecksum2(S,(1840531430U));
  ssSetChecksum3(S,(403126221U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",9);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim;
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

void c9_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

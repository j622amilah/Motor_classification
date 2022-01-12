/* Include files */

#include "blascompat32.h"
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun.h"
#include "c19_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c19_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc19_M37_Sim_Forcing_003h_expe_infra_transz_limInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void initialize_params_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void);
static void enable_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void disable_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c19_update_debugger_state_c19_M37_Sim_Forcing_003h_expe_infra_t(void);
static void ext_mode_exec_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static const mxArray
  *get_sim_state_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void set_sim_state_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c19_st);
static void finalize_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void sf_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber);
static const mxArray *c19_sf_marshall(void *c19_chartInstance, void *c19_u);
static const mxArray *c19_b_sf_marshall(void *c19_chartInstance, void *c19_u);
static const mxArray *c19_c_sf_marshall(void *c19_chartInstance, void *c19_u);
static const mxArray *c19_d_sf_marshall(void *c19_chartInstance, void *c19_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  uint8_T *c19_is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c19_is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c19_is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim = 0U;
}

static void initialize_params_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void)
{
  real_T c19_dv0[210];
  int32_T c19_i0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'B' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c19_dv0, 0, 0, 0U, 1, 0U, 2, 42, 5);
  for (c19_i0 = 0; c19_i0 < 210; c19_i0 = c19_i0 + 1) {
    chartInstance.c19_B[c19_i0] = c19_dv0[c19_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c19_update_debugger_state_c19_M37_Sim_Forcing_003h_expe_infra_t(void)
{
}

static void ext_mode_exec_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  c19_update_debugger_state_c19_M37_Sim_Forcing_003h_expe_infra_t();
}

static const mxArray
  *get_sim_state_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const mxArray *c19_st = NULL;
  const mxArray *c19_y = NULL;
  real_T c19_u;
  const mxArray *c19_b_y = NULL;
  real_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  int32_T c19_i1;
  real_T c19_c_u[3];
  const mxArray *c19_d_y = NULL;
  int32_T c19_i2;
  real_T c19_d_u[3];
  const mxArray *c19_e_y = NULL;
  real_T c19_e_u;
  const mxArray *c19_f_y = NULL;
  uint8_T c19_f_u;
  const mxArray *c19_g_y = NULL;
  real_T *c19_endOffile_out;
  real_T *c19_flag_out;
  real_T *c19_vis_cond;
  uint8_T *c19_is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  real_T (*c19_target_ang_speed)[3];
  real_T (*c19_mask)[3];
  c19_mask = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c19_is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c19_vis_cond = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c19_flag_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c19_endOffile_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c19_target_ang_speed = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellarray(6));
  c19_u = *c19_endOffile_out;
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_b_u = *c19_flag_out;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 1, c19_c_y);
  for (c19_i1 = 0; c19_i1 < 3; c19_i1 = c19_i1 + 1) {
    c19_c_u[c19_i1] = (*c19_mask)[c19_i1];
  }

  c19_d_y = NULL;
  sf_mex_assign(&c19_d_y, sf_mex_create("y", &c19_c_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c19_y, 2, c19_d_y);
  for (c19_i2 = 0; c19_i2 < 3; c19_i2 = c19_i2 + 1) {
    c19_d_u[c19_i2] = (*c19_target_ang_speed)[c19_i2];
  }

  c19_e_y = NULL;
  sf_mex_assign(&c19_e_y, sf_mex_create("y", &c19_d_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c19_y, 3, c19_e_y);
  c19_e_u = *c19_vis_cond;
  c19_f_y = NULL;
  sf_mex_assign(&c19_f_y, sf_mex_create("y", &c19_e_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 4, c19_f_y);
  c19_f_u = *c19_is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c19_g_y = NULL;
  sf_mex_assign(&c19_g_y, sf_mex_create("y", &c19_f_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c19_y, 5, c19_g_y);
  sf_mex_assign(&c19_st, c19_y);
  return c19_st;
}

static void set_sim_state_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c19_st)
{
  const mxArray *c19_u;
  const mxArray *c19_endOffile_out;
  real_T c19_d0;
  real_T c19_y;
  const mxArray *c19_b_endOffile_out;
  real_T c19_d1;
  real_T c19_b_y;
  const mxArray *c19_mask;
  real_T c19_dv1[3];
  int32_T c19_i3;
  real_T c19_c_y[3];
  int32_T c19_i4;
  const mxArray *c19_b_mask;
  real_T c19_dv2[3];
  int32_T c19_i5;
  real_T c19_d_y[3];
  int32_T c19_i6;
  const mxArray *c19_c_endOffile_out;
  real_T c19_d2;
  real_T c19_e_y;
  const mxArray *c19_is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  uint8_T c19_u0;
  uint8_T c19_f_y;
  boolean_T *c19_doneDoubleBufferReInit;
  real_T *c19_d_endOffile_out;
  real_T *c19_flag_out;
  real_T *c19_vis_cond;
  uint8_T *c19_b_is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  real_T (*c19_c_mask)[3];
  real_T (*c19_target_ang_speed)[3];
  c19_c_mask = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c19_b_is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c19_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c19_vis_cond = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c19_flag_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c19_d_endOffile_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c19_target_ang_speed = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  *c19_doneDoubleBufferReInit = true;
  c19_u = sf_mex_dup(c19_st);
  c19_endOffile_out = sf_mex_dup(sf_mex_getcell(c19_u, 0));
  sf_mex_import("endOffile_out", sf_mex_dup(c19_endOffile_out), &c19_d0, 1, 0,
                0U, 0, 0U, 0);
  c19_y = c19_d0;
  sf_mex_destroy(&c19_endOffile_out);
  *c19_d_endOffile_out = c19_y;
  c19_b_endOffile_out = sf_mex_dup(sf_mex_getcell(c19_u, 1));
  sf_mex_import("flag_out", sf_mex_dup(c19_b_endOffile_out), &c19_d1, 1, 0, 0U,
                0, 0U, 0);
  c19_b_y = c19_d1;
  sf_mex_destroy(&c19_b_endOffile_out);
  *c19_flag_out = c19_b_y;
  c19_mask = sf_mex_dup(sf_mex_getcell(c19_u, 2));
  sf_mex_import("mask", sf_mex_dup(c19_mask), &c19_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c19_i3 = 0; c19_i3 < 3; c19_i3 = c19_i3 + 1) {
    c19_c_y[c19_i3] = c19_dv1[c19_i3];
  }

  sf_mex_destroy(&c19_mask);
  for (c19_i4 = 0; c19_i4 < 3; c19_i4 = c19_i4 + 1) {
    (*c19_c_mask)[c19_i4] = c19_c_y[c19_i4];
  }

  c19_b_mask = sf_mex_dup(sf_mex_getcell(c19_u, 3));
  sf_mex_import("target_ang_speed", sf_mex_dup(c19_b_mask), &c19_dv2, 1, 0, 0U,
                1, 0U, 1, 3);
  for (c19_i5 = 0; c19_i5 < 3; c19_i5 = c19_i5 + 1) {
    c19_d_y[c19_i5] = c19_dv2[c19_i5];
  }

  sf_mex_destroy(&c19_b_mask);
  for (c19_i6 = 0; c19_i6 < 3; c19_i6 = c19_i6 + 1) {
    (*c19_target_ang_speed)[c19_i6] = c19_d_y[c19_i6];
  }

  c19_c_endOffile_out = sf_mex_dup(sf_mex_getcell(c19_u, 4));
  sf_mex_import("vis_cond", sf_mex_dup(c19_c_endOffile_out), &c19_d2, 1, 0, 0U,
                0, 0U, 0);
  c19_e_y = c19_d2;
  sf_mex_destroy(&c19_c_endOffile_out);
  *c19_vis_cond = c19_e_y;
  c19_is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim = sf_mex_dup
    (sf_mex_getcell(c19_u, 5));
  sf_mex_import("is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim",
                sf_mex_dup(
    c19_is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim), &c19_u0, 1, 3,
                0U, 0, 0U, 0);
  c19_f_y = c19_u0;
  sf_mex_destroy(&c19_is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim);
  *c19_b_is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim = c19_f_y;
  sf_mex_destroy(&c19_u);
  c19_update_debugger_state_c19_M37_Sim_Forcing_003h_expe_infra_t();
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void sf_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c19_i7;
  int32_T c19_i8;
  int32_T c19_i9;
  int32_T c19_previousEvent;
  real_T c19_count;
  int32_T c19_i10;
  real_T c19_b_B[210];
  real_T c19_endOffile_in;
  real_T c19_nargout = 5.0;
  real_T c19_nargin = 3.0;
  real_T c19_endOffile_out;
  real_T c19_flag_out;
  real_T c19_vis_cond;
  real_T c19_mask[3];
  real_T c19_target_ang_speed[3];
  int32_T c19_i11;
  real_T c19_n;
  real_T c19_k;
  real_T c19_b_k;
  int32_T c19_hoistedExpr;
  int32_T c19_b_hoistedExpr;
  int32_T c19_c_hoistedExpr;
  int32_T c19_i12;
  int32_T c19_i13;
  int32_T c19_b_count;
  int32_T c19_i14;
  int32_T c19_i15;
  static real_T c19_dv3[3] = { 1.0, 0.0, 0.0 };

  int32_T c19_i16;
  static real_T c19_dv4[3] = { 0.0, 1.0, 0.0 };

  int32_T c19_i17;
  static real_T c19_dv5[3] = { 0.0, 0.0, 1.0 };

  int32_T c19_i18;
  int32_T c19_i19;
  real_T *c19_c_count;
  real_T *c19_b_endOffile_in;
  real_T *c19_b_vis_cond;
  real_T *c19_b_flag_out;
  real_T *c19_b_endOffile_out;
  real_T (*c19_b_target_ang_speed)[3];
  real_T (*c19_b_mask)[3];
  c19_b_mask = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
  c19_c_count = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c19_b_endOffile_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c19_b_vis_cond = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c19_b_flag_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c19_b_endOffile_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c19_b_target_ang_speed = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S,
    1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,14);
  _SFD_DATA_RANGE_CHECK(*c19_c_count, 0U);
  for (c19_i7 = 0; c19_i7 < 210; c19_i7 = c19_i7 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance.c19_B[c19_i7], 1U);
  }

  for (c19_i8 = 0; c19_i8 < 3; c19_i8 = c19_i8 + 1) {
    _SFD_DATA_RANGE_CHECK((*c19_b_target_ang_speed)[c19_i8], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c19_b_endOffile_in, 3U);
  for (c19_i9 = 0; c19_i9 < 3; c19_i9 = c19_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((*c19_b_mask)[c19_i9], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c19_b_vis_cond, 5U);
  _SFD_DATA_RANGE_CHECK(*c19_b_flag_out, 6U);
  _SFD_DATA_RANGE_CHECK(*c19_b_endOffile_out, 7U);
  c19_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,14);
  c19_count = *c19_c_count;
  for (c19_i10 = 0; c19_i10 < 210; c19_i10 = c19_i10 + 1) {
    c19_b_B[c19_i10] = chartInstance.c19_B[c19_i10];
  }

  c19_endOffile_in = *c19_b_endOffile_in;
  sf_debug_symbol_scope_push(10U, 0U);
  sf_debug_symbol_scope_add("nargout", &c19_nargout, c19_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c19_nargin, c19_sf_marshall);
  sf_debug_symbol_scope_add("endOffile_out", &c19_endOffile_out, c19_sf_marshall);
  sf_debug_symbol_scope_add("flag_out", &c19_flag_out, c19_sf_marshall);
  sf_debug_symbol_scope_add("vis_cond", &c19_vis_cond, c19_sf_marshall);
  sf_debug_symbol_scope_add("mask", &c19_mask, c19_c_sf_marshall);
  sf_debug_symbol_scope_add("target_ang_speed", &c19_target_ang_speed,
    c19_c_sf_marshall);
  sf_debug_symbol_scope_add("endOffile_in", &c19_endOffile_in, c19_sf_marshall);
  sf_debug_symbol_scope_add("B", &c19_b_B, c19_b_sf_marshall);
  sf_debug_symbol_scope_add("count", &c19_count, c19_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,4);
  for (c19_i11 = 0; c19_i11 < 3; c19_i11 = c19_i11 + 1) {
    c19_mask[c19_i11] = 0.0;
  }

  _SFD_EML_CALL(0,5);
  c19_flag_out = 0.0;
  _SFD_EML_CALL(0,7);
  c19_n = 0.0;
  c19_k = 1.0;
 label_1:
  ;
  if (c19_k <= 2.0) {
    c19_b_k = c19_k;
    c19_hoistedExpr = _SFD_EML_ARRAY_BOUNDS_CHECK("s", (int32_T)
      _SFD_INTEGER_CHECK("k", c19_b_k), 1, 2, 1, 0) - 1;
    if (42.0 + -37.0 * (real_T)c19_hoistedExpr == 0.0) {
      c19_n = 0.0;
    } else {
      c19_b_hoistedExpr = _SFD_EML_ARRAY_BOUNDS_CHECK("s", (int32_T)
        _SFD_INTEGER_CHECK("k", c19_b_k), 1, 2, 1, 0) - 1;
      if (42.0 + -37.0 * (real_T)c19_b_hoistedExpr > c19_n) {
        c19_c_hoistedExpr = _SFD_EML_ARRAY_BOUNDS_CHECK("s", (int32_T)
          _SFD_INTEGER_CHECK("k", c19_b_k), 1, 2, 1, 0) - 1;
        c19_n = 42.0 + -37.0 * (real_T)c19_c_hoistedExpr;
      }

      c19_k = c19_k + 1.0;
      goto label_1;
    }
  }

  if (CV_EML_IF(0, 0, c19_count > c19_n)) {
    _SFD_EML_CALL(0,8);
    c19_endOffile_out = -1.0;
  } else {
    _SFD_EML_CALL(0,9);
    c19_endOffile_out = c19_endOffile_in;
  }

  _SFD_EML_CALL(0,12);
  if (CV_EML_IF(0, 1, c19_endOffile_in < 0.0)) {
    _SFD_EML_CALL(0,13);
    for (c19_i12 = 0; c19_i12 < 3; c19_i12 = c19_i12 + 1) {
      c19_target_ang_speed[c19_i12] = 0.0;
    }

    _SFD_EML_CALL(0,14);
    for (c19_i13 = 0; c19_i13 < 3; c19_i13 = c19_i13 + 1) {
      c19_mask[c19_i13] = 0.0;
    }

    _SFD_EML_CALL(0,15);
    c19_vis_cond = 1.0;
  } else {
    _SFD_EML_CALL(0,16);
    c19_b_count = _SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)_SFD_INTEGER_CHECK(
      "count", c19_count), 1, 42, 1, 0) - 1;
    for (c19_i14 = 0; c19_i14 < 3; c19_i14 = c19_i14 + 1) {
      c19_target_ang_speed[c19_i14] = c19_b_B[c19_b_count + 42 * c19_i14];
    }

    _SFD_EML_CALL(0,17);
    c19_vis_cond = c19_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)
      _SFD_INTEGER_CHECK("count", c19_count), 1, 42, 1, 0) + 167];

    /*      if(target_ang_speed(1)~=0)  */
    /*          mask(1)=1; */
    /*      end */
    /*      if(target_ang_speed(2)~=0)  */
    /*          mask(2)=1; */
    /*      end */
    /*      if(target_ang_speed(3)~=0)  */
    /*          mask(3)=1; */
    /*          flag_out=-1; */
    /*      end */
    _SFD_EML_CALL(0,29);
    switch ((int32_T)_SFD_INTEGER_CHECK("", c19_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK(
              "B", (int32_T)_SFD_INTEGER_CHECK("count", c19_count), 1,
              42, 1, 0) + 125])) {
     case 1:
      CV_EML_SWITCH(0, 0, 1);
      _SFD_EML_CALL(0,31);
      for (c19_i15 = 0; c19_i15 < 3; c19_i15 = c19_i15 + 1) {
        c19_mask[c19_i15] = c19_dv3[c19_i15];
      }

      _SFD_EML_CALL(0,32);
      c19_flag_out = 0.0;
      break;

     case 2:
      CV_EML_SWITCH(0, 0, 2);
      _SFD_EML_CALL(0,34);
      for (c19_i16 = 0; c19_i16 < 3; c19_i16 = c19_i16 + 1) {
        c19_mask[c19_i16] = c19_dv4[c19_i16];
      }

      _SFD_EML_CALL(0,35);
      c19_flag_out = 0.0;
      break;

     case 3:
      CV_EML_SWITCH(0, 0, 3);
      _SFD_EML_CALL(0,37);
      for (c19_i17 = 0; c19_i17 < 3; c19_i17 = c19_i17 + 1) {
        c19_mask[c19_i17] = c19_dv5[c19_i17];
      }

      _SFD_EML_CALL(0,38);
      c19_flag_out = -1.0;
      break;

     default:
      CV_EML_SWITCH(0, 0, 0);
      break;
    }
  }

  /* %flag out is to take care that the next trial involves yaw and then a change in the starting position must be handled */
  _SFD_EML_CALL(0,45);
  if (CV_EML_IF(0, 2, c19_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)
        _SFD_INTEGER_CHECK("", c19_count + 1.0), 1, 42, 1, 0) + 125]
                == 3.0)) {
    _SFD_EML_CALL(0,46);
    c19_flag_out = 1.0;
  }

  _SFD_EML_CALL(0,-46);
  sf_debug_symbol_scope_pop();
  for (c19_i18 = 0; c19_i18 < 3; c19_i18 = c19_i18 + 1) {
    (*c19_b_target_ang_speed)[c19_i18] = c19_target_ang_speed[c19_i18];
  }

  for (c19_i19 = 0; c19_i19 < 3; c19_i19 = c19_i19 + 1) {
    (*c19_b_mask)[c19_i19] = c19_mask[c19_i19];
  }

  *c19_b_vis_cond = c19_vis_cond;
  *c19_b_flag_out = c19_flag_out;
  *c19_b_endOffile_out = c19_endOffile_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,14);
  _sfEvent_ = c19_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber)
{
}

static const mxArray *c19_sf_marshall(void *c19_chartInstance, void *c19_u)
{
  const mxArray *c19_y = NULL;
  real_T c19_b_u;
  const mxArray *c19_b_y = NULL;
  c19_y = NULL;
  c19_b_u = *((real_T *)c19_u);
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c19_y, c19_b_y);
  return c19_y;
}

static const mxArray *c19_b_sf_marshall(void *c19_chartInstance, void *c19_u)
{
  const mxArray *c19_y = NULL;
  int32_T c19_i20;
  int32_T c19_i21;
  int32_T c19_i22;
  real_T c19_b_u[210];
  const mxArray *c19_b_y = NULL;
  c19_y = NULL;
  c19_i20 = 0;
  for (c19_i21 = 0; c19_i21 < 5; c19_i21 = c19_i21 + 1) {
    for (c19_i22 = 0; c19_i22 < 42; c19_i22 = c19_i22 + 1) {
      c19_b_u[c19_i22 + c19_i20] = (*((real_T (*)[210])c19_u))[c19_i22 + c19_i20];
    }

    c19_i20 = c19_i20 + 42;
  }

  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_b_u, 0, 0U, 1U, 0U, 2, 42, 5));
  sf_mex_assign(&c19_y, c19_b_y);
  return c19_y;
}

static const mxArray *c19_c_sf_marshall(void *c19_chartInstance, void *c19_u)
{
  const mxArray *c19_y = NULL;
  int32_T c19_i23;
  real_T c19_b_u[3];
  const mxArray *c19_b_y = NULL;
  c19_y = NULL;
  for (c19_i23 = 0; c19_i23 < 3; c19_i23 = c19_i23 + 1) {
    c19_b_u[c19_i23] = (*((real_T (*)[3])c19_u))[c19_i23];
  }

  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c19_y, c19_b_y);
  return c19_y;
}

const mxArray
  *sf_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c19_nameCaptureInfo = NULL;
  c19_ResolvedFunctionInfo c19_info[10];
  c19_ResolvedFunctionInfo (*c19_b_info)[10];
  const mxArray *c19_m0 = NULL;
  int32_T c19_i24;
  c19_ResolvedFunctionInfo *c19_r0;
  c19_nameCaptureInfo = NULL;
  c19_b_info = (c19_ResolvedFunctionInfo (*)[10])c19_info;
  (*c19_b_info)[0].context = "";
  (*c19_b_info)[0].name = "ctranspose";
  (*c19_b_info)[0].dominantType = "double";
  (*c19_b_info)[0].resolved = "[B]ctranspose";
  (*c19_b_info)[0].fileLength = 0U;
  (*c19_b_info)[0].fileTime1 = 0U;
  (*c19_b_info)[0].fileTime2 = 0U;
  (*c19_b_info)[1].context = "";
  (*c19_b_info)[1].name = "length";
  (*c19_b_info)[1].dominantType = "double";
  (*c19_b_info)[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c19_b_info)[1].fileLength = 326U;
  (*c19_b_info)[1].fileTime1 = 1226577276U;
  (*c19_b_info)[1].fileTime2 = 0U;
  (*c19_b_info)[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c19_b_info)[2].name = "nargin";
  (*c19_b_info)[2].dominantType = "";
  (*c19_b_info)[2].resolved = "[B]nargin";
  (*c19_b_info)[2].fileLength = 0U;
  (*c19_b_info)[2].fileTime1 = 0U;
  (*c19_b_info)[2].fileTime2 = 0U;
  (*c19_b_info)[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c19_b_info)[3].name = "eq";
  (*c19_b_info)[3].dominantType = "double";
  (*c19_b_info)[3].resolved = "[B]eq";
  (*c19_b_info)[3].fileLength = 0U;
  (*c19_b_info)[3].fileTime1 = 0U;
  (*c19_b_info)[3].fileTime2 = 0U;
  (*c19_b_info)[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c19_b_info)[4].name = "size";
  (*c19_b_info)[4].dominantType = "double";
  (*c19_b_info)[4].resolved = "[B]size";
  (*c19_b_info)[4].fileLength = 0U;
  (*c19_b_info)[4].fileTime1 = 0U;
  (*c19_b_info)[4].fileTime2 = 0U;
  (*c19_b_info)[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c19_b_info)[5].name = "gt";
  (*c19_b_info)[5].dominantType = "double";
  (*c19_b_info)[5].resolved = "[B]gt";
  (*c19_b_info)[5].fileLength = 0U;
  (*c19_b_info)[5].fileTime1 = 0U;
  (*c19_b_info)[5].fileTime2 = 0U;
  (*c19_b_info)[6].context = "";
  (*c19_b_info)[6].name = "uminus";
  (*c19_b_info)[6].dominantType = "double";
  (*c19_b_info)[6].resolved = "[B]uminus";
  (*c19_b_info)[6].fileLength = 0U;
  (*c19_b_info)[6].fileTime1 = 0U;
  (*c19_b_info)[6].fileTime2 = 0U;
  (*c19_b_info)[7].context = "";
  (*c19_b_info)[7].name = "lt";
  (*c19_b_info)[7].dominantType = "double";
  (*c19_b_info)[7].resolved = "[B]lt";
  (*c19_b_info)[7].fileLength = 0U;
  (*c19_b_info)[7].fileTime1 = 0U;
  (*c19_b_info)[7].fileTime2 = 0U;
  (*c19_b_info)[8].context = "";
  (*c19_b_info)[8].name = "zeros";
  (*c19_b_info)[8].dominantType = "double";
  (*c19_b_info)[8].resolved = "[B]zeros";
  (*c19_b_info)[8].fileLength = 0U;
  (*c19_b_info)[8].fileTime1 = 0U;
  (*c19_b_info)[8].fileTime2 = 0U;
  (*c19_b_info)[9].context = "";
  (*c19_b_info)[9].name = "plus";
  (*c19_b_info)[9].dominantType = "double";
  (*c19_b_info)[9].resolved = "[B]plus";
  (*c19_b_info)[9].fileLength = 0U;
  (*c19_b_info)[9].fileTime1 = 0U;
  (*c19_b_info)[9].fileTime2 = 0U;
  sf_mex_assign(&c19_m0, sf_mex_createstruct("nameCaptureInfo", 1, 10));
  for (c19_i24 = 0; c19_i24 < 10; c19_i24 = c19_i24 + 1) {
    c19_r0 = &c19_info[c19_i24];
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c19_r0->context)), "context"
                    , "nameCaptureInfo", c19_i24);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c19_r0->name)), "name",
                    "nameCaptureInfo", c19_i24);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo",
      c19_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c19_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c19_i24);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c19_r0->resolved)),
                    "resolved", "nameCaptureInfo", c19_i24);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c19_i24);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c19_i24);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c19_i24);
  }

  sf_mex_assign(&c19_nameCaptureInfo, c19_m0);
  return c19_nameCaptureInfo;
}

static const mxArray *c19_d_sf_marshall(void *c19_chartInstance, void *c19_u)
{
  const mxArray *c19_y = NULL;
  boolean_T c19_b_u;
  const mxArray *c19_b_y = NULL;
  c19_y = NULL;
  c19_b_u = *((boolean_T *)c19_u);
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c19_y, c19_b_y);
  return c19_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(149169178U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(649459749U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3678552327U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2000975837U);
}

mxArray
  *sf_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1320987073U);
    pr[1] = (double)(1288349945U);
    pr[2] = (double)(1766712611U);
    pr[3] = (double)(1537661220U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(42);
      pr[1] = (double)(5);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray
  *sf_get_sim_state_info_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[18],T\"endOffile_out\",},{M[1],M[17],T\"flag_out\",},{M[1],M[15],T\"mask\",},{M[1],M[5],T\"target_ang_speed\",},{M[1],M[16],T\"vis_cond\",},{M[8],M[0],T\"is_active_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(&mxChecksum);
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
           19,
           1,
           1,
           8,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"count",0,
                              (MexFcnForType)c19_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 42;
            dimVector[1]= 5;
            _SFD_SET_DATA_PROPS(1,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"B",0,(MexFcnForType)c19_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"target_ang_speed",0,(MexFcnForType)
                                c19_c_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "endOffile_in",0,(MexFcnForType)c19_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"mask",0,(MexFcnForType)c19_c_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "vis_cond",0,(MexFcnForType)c19_sf_marshall);
          _SFD_SET_DATA_PROPS(6,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "flag_out",0,(MexFcnForType)c19_sf_marshall);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "endOffile_out",0,(MexFcnForType)c19_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,3,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,965);
        _SFD_CV_INIT_EML_IF(0,0,133,151,170,206);
        _SFD_CV_INIT_EML_IF(0,1,208,225,295,798);
        _SFD_CV_INIT_EML_IF(0,2,919,938,-1,958);

        {
          static int caseStart[] = { -1, 610, 671, 732 };

          static int caseExprEnd[] = { 8, 616, 677, 738 };

          _SFD_CV_INIT_EML_SWITCH(0,0,584,602,792,4,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c19_count;
          real_T (*c19_target_ang_speed)[3];
          real_T *c19_endOffile_in;
          real_T (*c19_mask)[3];
          real_T *c19_vis_cond;
          real_T *c19_flag_out;
          real_T *c19_endOffile_out;
          c19_mask = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 2);
          c19_count = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c19_endOffile_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c19_vis_cond = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c19_flag_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
          c19_endOffile_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
          c19_target_ang_speed = (real_T (*)[3])ssGetOutputPortSignal
            (chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c19_count);
          _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance.c19_B);
          _SFD_SET_DATA_VALUE_PTR(2U, c19_target_ang_speed);
          _SFD_SET_DATA_VALUE_PTR(3U, c19_endOffile_in);
          _SFD_SET_DATA_VALUE_PTR(4U, c19_mask);
          _SFD_SET_DATA_VALUE_PTR(5U, c19_vis_cond);
          _SFD_SET_DATA_VALUE_PTR(6U, c19_flag_out);
          _SFD_SET_DATA_VALUE_PTR(7U, c19_endOffile_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  initialize_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_enable_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  enable_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_disable_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  disable_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_gateway_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  sf_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void
  sf_opaque_ext_mode_exec_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  ext_mode_exec_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static mxArray*
  sf_opaque_get_sim_state_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  return st;
}

static void
  sf_opaque_set_sim_state_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(sf_mex_dup(st));
}

static void sf_opaque_terminate_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  /* Actual parameters from chart:
     B
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for B*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",19,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",19,2);
      sf_mark_chart_reusable_outputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",19,5);
    }

    sf_set_rtw_dwork_info(S,"M37_Sim_Forcing_003h_expe_infra_transz_lim",
                          "M37_Sim_Forcing_003h_expe_infra_transz_lim",19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(3700035899U));
  ssSetChecksum1(S,(261004233U));
  ssSetChecksum2(S,(1526682888U));
  ssSetChecksum3(S,(1359095402U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",19);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim;
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

void c19_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(SimStruct *
  S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

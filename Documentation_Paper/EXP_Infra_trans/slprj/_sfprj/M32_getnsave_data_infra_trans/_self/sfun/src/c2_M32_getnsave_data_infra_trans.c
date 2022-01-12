/* Include files */

#include "blascompat32.h"
#include "M32_getnsave_data_infra_trans_sfun.h"
#include "c2_M32_getnsave_data_infra_trans.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M32_getnsave_data_infra_trans_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_M32_getnsave_data_infra_transInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_M32_getnsave_data_infra_trans(void);
static void initialize_params_c2_M32_getnsave_data_infra_trans(void);
static void enable_c2_M32_getnsave_data_infra_trans(void);
static void disable_c2_M32_getnsave_data_infra_trans(void);
static void c2_update_debugger_state_c2_M32_getnsave_data_infra_trans(void);
static const mxArray *get_sim_state_c2_M32_getnsave_data_infra_trans(void);
static void set_sim_state_c2_M32_getnsave_data_infra_trans(const mxArray *c2_st);
static void finalize_c2_M32_getnsave_data_infra_trans(void);
static void sf_c2_M32_getnsave_data_infra_trans(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_e_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_f_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_g_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_h_sf_marshall(void *c2_chartInstance, void *c2_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_M32_getnsave_data_infra_trans(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_is_active_c2_M32_getnsave_data_infra_trans = 0U;
}

static void initialize_params_c2_M32_getnsave_data_infra_trans(void)
{
  real_T c2_dv0[210];
  int32_T c2_i0;
  real_T c2_d0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'B' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c2_dv0, 0, 0, 0U, 1, 0U, 2, 42, 5);
  for (c2_i0 = 0; c2_i0 < 210; c2_i0 = c2_i0 + 1) {
    chartInstance.c2_B[c2_i0] = c2_dv0[c2_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'n' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    1, 0), &c2_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance.c2_n = c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_M32_getnsave_data_infra_trans(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c2_M32_getnsave_data_infra_trans(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c2_update_debugger_state_c2_M32_getnsave_data_infra_trans(void)
{
}

static const mxArray *get_sim_state_c2_M32_getnsave_data_infra_trans(void)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_sample_count_out;
  c2_sample_count_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  c2_u = *c2_sample_count_out;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_u = chartInstance.c2_is_active_c2_M32_getnsave_data_infra_trans;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_M32_getnsave_data_infra_trans(const mxArray *c2_st)
{
  const mxArray *c2_u;
  const mxArray *c2_sample_count_out;
  real_T c2_d1;
  real_T c2_y;
  const mxArray *c2_b_is_active_c2_M32_getnsave_data_infra_trans;
  uint8_T c2_u0;
  uint8_T c2_b_y;
  real_T *c2_b_sample_count_out;
  c2_b_sample_count_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  chartInstance.c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_sample_count_out = sf_mex_dup(sf_mex_getcell(c2_u, 0));
  sf_mex_import("sample_count_out", sf_mex_dup(c2_sample_count_out), &c2_d1, 1,
                0, 0U, 0, 0U, 0);
  c2_y = c2_d1;
  sf_mex_destroy(&c2_sample_count_out);
  *c2_b_sample_count_out = c2_y;
  c2_b_is_active_c2_M32_getnsave_data_infra_trans = sf_mex_dup(sf_mex_getcell
    (c2_u, 1));
  sf_mex_import("is_active_c2_M32_getnsave_data_infra_trans", sf_mex_dup
                (c2_b_is_active_c2_M32_getnsave_data_infra_trans), &c2_u0, 1,
                3, 0U, 0, 0U, 0);
  c2_b_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_M32_getnsave_data_infra_trans);
  chartInstance.c2_is_active_c2_M32_getnsave_data_infra_trans = c2_b_y;
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_M32_getnsave_data_infra_trans();
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_M32_getnsave_data_infra_trans(void)
{
}

static void sf_c2_M32_getnsave_data_infra_trans(void)
{
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_previousEvent;
  real32_T c2_time_data;
  int32_T c2_i8;
  real32_T c2_data_com[3];
  int32_T c2_i9;
  real32_T c2_data_act[3];
  real_T c2_sampling;
  real_T c2_sample_count_in;
  real32_T c2_trial_count;
  int32_T c2_i10;
  real32_T c2_target_ang_speed[3];
  real32_T c2_delay;
  real32_T c2_reset;
  real32_T c2_IsinRestPhase;
  real32_T c2_vis_cond;
  int32_T c2_i11;
  real_T c2_b_B[210];
  real_T c2_b_n;
  real32_T c2_Taact;
  int32_T c2_i12;
  real32_T c2_stick[3];
  int32_T c2_i13;
  real32_T c2_gradual_stim[3];
  int32_T c2_i14;
  real32_T c2_noise[3];
  real_T c2_nargout = 1.0;
  real_T c2_nargin = 17.0;
  const mxArray *c2_fileID = NULL;
  real_T c2_index;
  real_T c2_sample_count_out;
  int32_T c2_i15;
  static char_T c2_cv0[2] = { 'a', '+' };

  char_T c2_u[2];
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i16;
  static char_T c2_cv1[13] = { 's', 'u', 'b', 'j', 'e', 'c', 't', '%', 'i', '.',
    't', 'x', 't' };

  char_T c2_c_u[13];
  const mxArray *c2_c_y = NULL;
  real32_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  real32_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  real32_T c2_f_u;
  const mxArray *c2_f_y = NULL;
  real32_T c2_g_u;
  const mxArray *c2_g_y = NULL;
  real32_T c2_h_u;
  const mxArray *c2_h_y = NULL;
  real32_T c2_i_u;
  const mxArray *c2_i_y = NULL;
  real32_T c2_j_u;
  const mxArray *c2_j_y = NULL;
  real32_T c2_k_u;
  const mxArray *c2_k_y = NULL;
  real_T c2_l_u;
  const mxArray *c2_l_y = NULL;
  real32_T c2_m_u;
  const mxArray *c2_m_y = NULL;
  real32_T c2_n_u;
  const mxArray *c2_n_y = NULL;
  real32_T c2_o_u;
  const mxArray *c2_o_y = NULL;
  real32_T c2_p_u;
  const mxArray *c2_p_y = NULL;
  real32_T c2_q_u;
  const mxArray *c2_q_y = NULL;
  real32_T c2_r_u;
  const mxArray *c2_r_y = NULL;
  real32_T c2_s_u;
  const mxArray *c2_s_y = NULL;
  real32_T c2_t_u;
  const mxArray *c2_t_y = NULL;
  real32_T c2_u_u;
  const mxArray *c2_u_y = NULL;
  real32_T c2_v_u;
  const mxArray *c2_v_y = NULL;
  real32_T c2_w_u;
  const mxArray *c2_w_y = NULL;
  real32_T c2_x_u;
  const mxArray *c2_x_y = NULL;
  real32_T c2_y_u;
  const mxArray *c2_y_y = NULL;
  int32_T c2_i17;
  static char_T c2_cv2[90] = { '%', 'f', '\\', 't', '%', 'f', '\\', 't', '%',
    'f', '\\', 't', '%', 'f', '\\', 't', '%', 'f', '\\', 't'
    , '%', 'f', '\\', 't', '%', 'f', '\\', 't', '%', 'f', '\\', 't', '%', 'f',
    '\\', 't', '%', 'f', '\\',
    't', '%', 'f', '\\', 't', '%', 'f', '\\', 't', '%', 'f', '\\', 't', '%', 'f',
    '\\', 't', '%', 'f', '\\'
    , 't', '%', 'f', '\\', 't', '%', 'f', '\\', 't', '%', 'f', '\\', 't', '%',
    'f', '\\', 't', '%', 'f',
    '\\', 't', '%', 'f', '\\', 't', '%', 'f', '\\', 'r', '\\', 'n' };

  char_T c2_ab_u[90];
  const mxArray *c2_ab_y = NULL;
  real32_T *c2_b_time_data;
  real_T *c2_b_sample_count_out;
  real_T *c2_b_sampling;
  real_T *c2_b_sample_count_in;
  real32_T *c2_b_trial_count;
  real32_T *c2_b_delay;
  real32_T *c2_b_reset;
  real32_T *c2_b_IsinRestPhase;
  real32_T *c2_b_vis_cond;
  real32_T *c2_b_Taact;
  real32_T (*c2_b_noise)[3];
  real32_T (*c2_b_gradual_stim)[3];
  real32_T (*c2_b_stick)[3];
  real32_T (*c2_b_target_ang_speed)[3];
  real32_T (*c2_b_data_act)[3];
  real32_T (*c2_b_data_com)[3];
  c2_b_sample_count_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  c2_b_vis_cond = (real32_T *)ssGetInputPortSignal(chartInstance.S, 10);
  c2_b_noise = (real32_T (*)[3])ssGetInputPortSignal(chartInstance.S, 14);
  c2_b_target_ang_speed = (real32_T (*)[3])ssGetInputPortSignal(chartInstance.S,
    6);
  c2_b_data_com = (real32_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  c2_b_IsinRestPhase = (real32_T *)ssGetInputPortSignal(chartInstance.S, 9);
  c2_b_gradual_stim = (real32_T (*)[3])ssGetInputPortSignal(chartInstance.S, 13);
  c2_b_trial_count = (real32_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c2_b_delay = (real32_T *)ssGetInputPortSignal(chartInstance.S, 7);
  c2_b_stick = (real32_T (*)[3])ssGetInputPortSignal(chartInstance.S, 12);
  c2_b_time_data = (real32_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c2_b_sampling = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c2_b_reset = (real32_T *)ssGetInputPortSignal(chartInstance.S, 8);
  c2_b_Taact = (real32_T *)ssGetInputPortSignal(chartInstance.S, 11);
  c2_b_data_act = (real32_T (*)[3])ssGetInputPortSignal(chartInstance.S, 2);
  c2_b_sample_count_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_b_time_data, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_sample_count_out, 1U);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1 = c2_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_data_com)[c2_i1], 2U);
  }

  for (c2_i2 = 0; c2_i2 < 3; c2_i2 = c2_i2 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_data_act)[c2_i2], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_b_sampling, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_sample_count_in, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_b_trial_count, 6U);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3 = c2_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_target_ang_speed)[c2_i3], 7U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c2_b_delay, 8U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_b_reset, 9U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_b_IsinRestPhase, 10U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_b_vis_cond, 11U);
  for (c2_i4 = 0; c2_i4 < 210; c2_i4 = c2_i4 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance.c2_B[c2_i4], 12U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance.c2_n, 13U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_b_Taact, 14U);
  for (c2_i5 = 0; c2_i5 < 3; c2_i5 = c2_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_stick)[c2_i5], 15U);
  }

  for (c2_i6 = 0; c2_i6 < 3; c2_i6 = c2_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_gradual_stim)[c2_i6], 16U);
  }

  for (c2_i7 = 0; c2_i7 < 3; c2_i7 = c2_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_b_noise)[c2_i7], 17U);
  }

  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c2_time_data = *c2_b_time_data;
  for (c2_i8 = 0; c2_i8 < 3; c2_i8 = c2_i8 + 1) {
    c2_data_com[c2_i8] = (*c2_b_data_com)[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 3; c2_i9 = c2_i9 + 1) {
    c2_data_act[c2_i9] = (*c2_b_data_act)[c2_i9];
  }

  c2_sampling = *c2_b_sampling;
  c2_sample_count_in = *c2_b_sample_count_in;
  c2_trial_count = *c2_b_trial_count;
  for (c2_i10 = 0; c2_i10 < 3; c2_i10 = c2_i10 + 1) {
    c2_target_ang_speed[c2_i10] = (*c2_b_target_ang_speed)[c2_i10];
  }

  c2_delay = *c2_b_delay;
  c2_reset = *c2_b_reset;
  c2_IsinRestPhase = *c2_b_IsinRestPhase;
  c2_vis_cond = *c2_b_vis_cond;
  for (c2_i11 = 0; c2_i11 < 210; c2_i11 = c2_i11 + 1) {
    c2_b_B[c2_i11] = chartInstance.c2_B[c2_i11];
  }

  c2_b_n = chartInstance.c2_n;
  c2_Taact = *c2_b_Taact;
  for (c2_i12 = 0; c2_i12 < 3; c2_i12 = c2_i12 + 1) {
    c2_stick[c2_i12] = (*c2_b_stick)[c2_i12];
  }

  for (c2_i13 = 0; c2_i13 < 3; c2_i13 = c2_i13 + 1) {
    c2_gradual_stim[c2_i13] = (*c2_b_gradual_stim)[c2_i13];
  }

  for (c2_i14 = 0; c2_i14 < 3; c2_i14 = c2_i14 + 1) {
    c2_noise[c2_i14] = (*c2_b_noise)[c2_i14];
  }

  sf_debug_symbol_scope_push(22U, 0U);
  sf_debug_symbol_scope_add("nargout", &c2_nargout, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c2_nargin, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("fileID", &c2_fileID, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("index", &c2_index, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("sample_count_out", &c2_sample_count_out,
    c2_c_sf_marshall);
  sf_debug_symbol_scope_add("noise", &c2_noise, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("gradual_stim", &c2_gradual_stim, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("stick", &c2_stick, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("Taact", &c2_Taact, c2_sf_marshall);
  sf_debug_symbol_scope_add("n", &c2_b_n, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("B", &c2_b_B, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("vis_cond", &c2_vis_cond, c2_sf_marshall);
  sf_debug_symbol_scope_add("IsinRestPhase", &c2_IsinRestPhase, c2_sf_marshall);
  sf_debug_symbol_scope_add("reset", &c2_reset, c2_sf_marshall);
  sf_debug_symbol_scope_add("delay", &c2_delay, c2_sf_marshall);
  sf_debug_symbol_scope_add("target_ang_speed", &c2_target_ang_speed,
    c2_b_sf_marshall);
  sf_debug_symbol_scope_add("trial_count", &c2_trial_count, c2_sf_marshall);
  sf_debug_symbol_scope_add("sample_count_in", &c2_sample_count_in,
    c2_c_sf_marshall);
  sf_debug_symbol_scope_add("sampling", &c2_sampling, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("data_act", &c2_data_act, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("data_com", &c2_data_com, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("time_data", &c2_time_data, c2_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  _SFD_EML_CALL(0,4);
  _SFD_EML_CALL(0,5);
  _SFD_EML_CALL(0,6);
  _SFD_EML_CALL(0,8);
  if (CV_EML_IF(0, 0, c2_reset != 0.0F) != 0.0F) {
    _SFD_EML_CALL(0,9);
    c2_sample_count_in = 1.0;
  }

  _SFD_EML_CALL(0,14);
  if (CV_EML_IF(0, 1, c2_IsinRestPhase != 0.0F) != 0.0F) {
    _SFD_EML_CALL(0,15);
    c2_sample_count_out = c2_sample_count_in;
  } else {
    _SFD_EML_CALL(0,17);
    if (CV_EML_IF(0, 2, c2_sample_count_in == c2_sampling)) {
      _SFD_EML_CALL(0,18);
      c2_index = c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)(real32_T)
        _SFD_INTEGER_CHECK("trial_count", (real_T)c2_trial_count), 1,
        42, 1, 0) + 125];

      /* fileID=fopen('subject1.txt','a+'); */
      _SFD_EML_CALL(0,21);
      for (c2_i15 = 0; c2_i15 < 2; c2_i15 = c2_i15 + 1) {
        c2_u[c2_i15] = c2_cv0[c2_i15];
      }

      c2_y = NULL;
      sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 10, 0U, 1U, 0U, 2, 1, 2));
      c2_b_u = c2_b_n;
      c2_b_y = NULL;
      sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
      for (c2_i16 = 0; c2_i16 < 13; c2_i16 = c2_i16 + 1) {
        c2_c_u[c2_i16] = c2_cv1[c2_i16];
      }

      c2_c_y = NULL;
      sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 10, 0U, 1U, 0U, 2, 1,
        13));
      sf_mex_assign(&c2_fileID, sf_mex_call_debug("fopen", 1U, 2U, 14,
        sf_mex_call_debug("sprintf", 1U, 2U, 14, c2_c_y, 14, c2_b_y), 14,
        c2_y));
      _SFD_EML_CALL(0,22);
      c2_d_u = c2_noise[2];
      c2_d_y = NULL;
      sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 1, 0U, 0U, 0U, 0));
      c2_e_u = c2_noise[1];
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 1, 0U, 0U, 0U, 0));
      c2_f_u = c2_noise[0];
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 1, 0U, 0U, 0U, 0));
      c2_g_u = c2_gradual_stim[_SFD_EML_ARRAY_BOUNDS_CHECK("gradual_stim",
        (int32_T)_SFD_INTEGER_CHECK("index", c2_index), 1, 3, 1, 0) - 1
        ];
      c2_g_y = NULL;
      sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_g_u, 1, 0U, 0U, 0U, 0));
      c2_h_u = c2_stick[2];
      c2_h_y = NULL;
      sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_h_u, 1, 0U, 0U, 0U, 0));
      c2_i_u = c2_stick[1];
      c2_i_y = NULL;
      sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_i_u, 1, 0U, 0U, 0U, 0));
      c2_j_u = c2_stick[0];
      c2_j_y = NULL;
      sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_j_u, 1, 0U, 0U, 0U, 0));
      c2_k_u = c2_Taact;
      c2_k_y = NULL;
      sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_k_u, 1, 0U, 0U, 0U, 0));
      c2_l_u = c2_index;
      c2_l_y = NULL;
      sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0));
      c2_m_u = c2_vis_cond;
      c2_m_y = NULL;
      sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_m_u, 1, 0U, 0U, 0U, 0));
      c2_n_u = c2_target_ang_speed[2];
      c2_n_y = NULL;
      sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_n_u, 1, 0U, 0U, 0U, 0));
      c2_o_u = c2_target_ang_speed[1];
      c2_o_y = NULL;
      sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_o_u, 1, 0U, 0U, 0U, 0));
      c2_p_u = c2_target_ang_speed[0];
      c2_p_y = NULL;
      sf_mex_assign(&c2_p_y, sf_mex_create("y", &c2_p_u, 1, 0U, 0U, 0U, 0));
      c2_q_u = c2_delay;
      c2_q_y = NULL;
      sf_mex_assign(&c2_q_y, sf_mex_create("y", &c2_q_u, 1, 0U, 0U, 0U, 0));
      c2_r_u = c2_data_act[2];
      c2_r_y = NULL;
      sf_mex_assign(&c2_r_y, sf_mex_create("y", &c2_r_u, 1, 0U, 0U, 0U, 0));
      c2_s_u = c2_data_act[1];
      c2_s_y = NULL;
      sf_mex_assign(&c2_s_y, sf_mex_create("y", &c2_s_u, 1, 0U, 0U, 0U, 0));
      c2_t_u = c2_data_act[0];
      c2_t_y = NULL;
      sf_mex_assign(&c2_t_y, sf_mex_create("y", &c2_t_u, 1, 0U, 0U, 0U, 0));
      c2_u_u = c2_data_com[2];
      c2_u_y = NULL;
      sf_mex_assign(&c2_u_y, sf_mex_create("y", &c2_u_u, 1, 0U, 0U, 0U, 0));
      c2_v_u = c2_data_com[1];
      c2_v_y = NULL;
      sf_mex_assign(&c2_v_y, sf_mex_create("y", &c2_v_u, 1, 0U, 0U, 0U, 0));
      c2_w_u = c2_data_com[0];
      c2_w_y = NULL;
      sf_mex_assign(&c2_w_y, sf_mex_create("y", &c2_w_u, 1, 0U, 0U, 0U, 0));
      c2_x_u = c2_time_data;
      c2_x_y = NULL;
      sf_mex_assign(&c2_x_y, sf_mex_create("y", &c2_x_u, 1, 0U, 0U, 0U, 0));
      c2_y_u = c2_trial_count;
      c2_y_y = NULL;
      sf_mex_assign(&c2_y_y, sf_mex_create("y", &c2_y_u, 1, 0U, 0U, 0U, 0));
      for (c2_i17 = 0; c2_i17 < 90; c2_i17 = c2_i17 + 1) {
        c2_ab_u[c2_i17] = c2_cv2[c2_i17];
      }

      c2_ab_y = NULL;
      sf_mex_assign(&c2_ab_y, sf_mex_create("y", &c2_ab_u, 10, 0U, 1U, 0U, 2, 1,
        90));
      sf_mex_call_debug("fprintf", 0U, 24U, 14, sf_mex_dup(c2_fileID), 14,
                        c2_ab_y, 14, c2_y_y, 14, c2_x_y, 14, c2_w_y, 14, c2_v_y,
                        14,
                        c2_u_y, 14, c2_t_y, 14, c2_s_y, 14, c2_r_y, 14, c2_q_y,
                        14, c2_p_y, 14, c2_o_y, 14, c2_n_y, 14, c2_m_y, 14,
                        c2_l_y, 14, c2_k_y, 14,
                        c2_j_y, 14, c2_i_y, 14, c2_h_y, 14, c2_g_y, 14, c2_f_y,
                        14, c2_e_y, 14, c2_d_y);

      /* save 3 axes from data_com and data_act */
      /*
         fprintf(fileID,'%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\r\n', trial_count, time_data, data_com(1), data_com(2), data_com(3), delay, target_ang_speed(1), target_ang_speed(2), target_ang_speed(3), vis_cond);%save three axes from data */
      _SFD_EML_CALL(0,24);
      sf_mex_call_debug("fclose", 0U, 1U, 14, sf_mex_dup(c2_fileID));
      _SFD_EML_CALL(0,26);
      c2_sample_count_out = 1.0;
    } else {
      _SFD_EML_CALL(0,28);
      c2_sample_count_out = c2_sample_count_in + 1.0;
    }
  }

  _SFD_EML_CALL(0,-28);
  sf_debug_symbol_scope_pop();
  sf_mex_destroy(&c2_fileID);
  *c2_b_sample_count_out = c2_sample_count_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M32_getnsave_data_infra_transMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real32_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real32_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 1, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i18;
  real32_T c2_b_u[3];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for (c2_i18 = 0; c2_i18 < 3; c2_i18 = c2_i18 + 1) {
    c2_b_u[c2_i18] = (*((real32_T (*)[3])c2_u))[c2_i18];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 1, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  real_T c2_b_u[210];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_i19 = 0;
  for (c2_i20 = 0; c2_i20 < 5; c2_i20 = c2_i20 + 1) {
    for (c2_i21 = 0; c2_i21 < 42; c2_i21 = c2_i21 + 1) {
      c2_b_u[c2_i21 + c2_i19] = (*((real_T (*)[210])c2_u))[c2_i21 + c2_i19];
    }

    c2_i19 = c2_i19 + 42;
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 1U, 0U, 2, 42, 5));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_e_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  const mxArray *c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = sf_mex_dup(*((const mxArray **)c2_u));
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_duplicatearraysafe(&c2_b_u));
  sf_mex_destroy(&c2_b_u);
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray
  *sf_c2_M32_getnsave_data_infra_trans_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[2];
  c2_ResolvedFunctionInfo (*c2_b_info)[2];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i22;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[2])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "eq";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved = "[B]eq";
  (*c2_b_info)[0].fileLength = 0U;
  (*c2_b_info)[0].fileTime1 = 0U;
  (*c2_b_info)[0].fileTime2 = 0U;
  (*c2_b_info)[1].context = "";
  (*c2_b_info)[1].name = "plus";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved = "[B]plus";
  (*c2_b_info)[1].fileLength = 0U;
  (*c2_b_info)[1].fileTime1 = 0U;
  (*c2_b_info)[1].fileTime2 = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2));
  for (c2_i22 = 0; c2_i22 < 2; c2_i22 = c2_i22 + 1) {
    c2_r0 = &c2_info[c2_i22];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i22);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i22);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i22);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i22);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i22);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i22
                    );
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i22
                    );
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_f_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_g_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_h_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real32_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real32_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 1, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_M32_getnsave_data_infra_trans_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(811336415U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2016131234U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(746042928U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4023635559U);
}

mxArray *sf_c2_M32_getnsave_data_infra_trans_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3079968064U);
    pr[1] = (double)(2610232718U);
    pr[2] = (double)(4293129690U);
    pr[3] = (double)(397740625U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,15,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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

static mxArray *sf_get_sim_state_info_c2_M32_getnsave_data_infra_trans(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"sample_count_out\",},{M[8],M[0],T\"is_active_c2_M32_getnsave_data_infra_trans\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_M32_getnsave_data_infra_trans_get_check_sum(&mxChecksum);
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
          (_M32_getnsave_data_infra_transMachineNumber_,
           2,
           1,
           1,
           18,
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
            (_M32_getnsave_data_infra_transMachineNumber_,
             chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_M32_getnsave_data_infra_transMachineNumber_,
             chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_M32_getnsave_data_infra_transMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,
                              "time_data",0,(MexFcnForType)c2_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "sample_count_out",0,(MexFcnForType)
                              c2_g_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"data_com",0,(MexFcnForType)
                                c2_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(3,1,1,0,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"data_act",0,(MexFcnForType)
                                c2_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "sampling",0,(MexFcnForType)c2_c_sf_marshall);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "sample_count_in",0,(MexFcnForType)
                              c2_g_sf_marshall);
          _SFD_SET_DATA_PROPS(6,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,
                              "trial_count",0,(MexFcnForType)c2_h_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(7,1,1,0,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"target_ang_speed",0,(MexFcnForType)
                                c2_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(8,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"delay",0,
                              (MexFcnForType)c2_h_sf_marshall);
          _SFD_SET_DATA_PROPS(9,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"reset",0,
                              (MexFcnForType)c2_h_sf_marshall);
          _SFD_SET_DATA_PROPS(10,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,
                              "IsinRestPhase",0,(MexFcnForType)c2_h_sf_marshall);
          _SFD_SET_DATA_PROPS(11,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,
                              "vis_cond",0,(MexFcnForType)c2_h_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 42;
            dimVector[1]= 5;
            _SFD_SET_DATA_PROPS(12,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"B",0,(MexFcnForType)c2_d_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(13,10,0,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"n",0,
                              (MexFcnForType)c2_g_sf_marshall);
          _SFD_SET_DATA_PROPS(14,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"Taact",
                              0,(MexFcnForType)c2_h_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(15,1,1,0,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"stick",0,(MexFcnForType)c2_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(16,1,1,0,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"gradual_stim",0,(MexFcnForType)
                                c2_b_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(17,1,1,0,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"noise",0,(MexFcnForType)c2_b_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,3,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1366);
        _SFD_CV_INIT_EML_IF(0,0,296,305,-1,332);
        _SFD_CV_INIT_EML_IF(0,1,336,353,392,1361);
        _SFD_CV_INIT_EML_IF(0,2,401,429,1301,1357);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real32_T *c2_time_data;
          real_T *c2_sample_count_out;
          real32_T (*c2_data_com)[3];
          real32_T (*c2_data_act)[3];
          real_T *c2_sampling;
          real_T *c2_sample_count_in;
          real32_T *c2_trial_count;
          real32_T (*c2_target_ang_speed)[3];
          real32_T *c2_delay;
          real32_T *c2_reset;
          real32_T *c2_IsinRestPhase;
          real32_T *c2_vis_cond;
          real32_T *c2_Taact;
          real32_T (*c2_stick)[3];
          real32_T (*c2_gradual_stim)[3];
          real32_T (*c2_noise)[3];
          c2_sample_count_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
          c2_vis_cond = (real32_T *)ssGetInputPortSignal(chartInstance.S, 10);
          c2_noise = (real32_T (*)[3])ssGetInputPortSignal(chartInstance.S, 14);
          c2_target_ang_speed = (real32_T (*)[3])ssGetInputPortSignal
            (chartInstance.S, 6);
          c2_data_com = (real32_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
          c2_IsinRestPhase = (real32_T *)ssGetInputPortSignal(chartInstance.S, 9);
          c2_gradual_stim = (real32_T (*)[3])ssGetInputPortSignal
            (chartInstance.S, 13);
          c2_trial_count = (real32_T *)ssGetInputPortSignal(chartInstance.S, 5);
          c2_delay = (real32_T *)ssGetInputPortSignal(chartInstance.S, 7);
          c2_stick = (real32_T (*)[3])ssGetInputPortSignal(chartInstance.S, 12);
          c2_time_data = (real32_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c2_sampling = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c2_reset = (real32_T *)ssGetInputPortSignal(chartInstance.S, 8);
          c2_Taact = (real32_T *)ssGetInputPortSignal(chartInstance.S, 11);
          c2_data_act = (real32_T (*)[3])ssGetInputPortSignal(chartInstance.S, 2);
          c2_sample_count_out = (real_T *)ssGetOutputPortSignal(chartInstance.S,
            1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_time_data);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_sample_count_out);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_data_com);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_data_act);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_sampling);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_sample_count_in);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_trial_count);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_target_ang_speed);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_delay);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_reset);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_IsinRestPhase);
          _SFD_SET_DATA_VALUE_PTR(11U, c2_vis_cond);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance.c2_B);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance.c2_n);
          _SFD_SET_DATA_VALUE_PTR(14U, c2_Taact);
          _SFD_SET_DATA_VALUE_PTR(15U, c2_stick);
          _SFD_SET_DATA_VALUE_PTR(16U, c2_gradual_stim);
          _SFD_SET_DATA_VALUE_PTR(17U, c2_noise);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M32_getnsave_data_infra_transMachineNumber_,chartInstance.chartNumber,
         chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_M32_getnsave_data_infra_trans(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_M32_getnsave_data_infra_trans();
  initialize_c2_M32_getnsave_data_infra_trans();
}

static void sf_opaque_enable_c2_M32_getnsave_data_infra_trans(void
  *chartInstanceVar)
{
  enable_c2_M32_getnsave_data_infra_trans();
}

static void sf_opaque_disable_c2_M32_getnsave_data_infra_trans(void
  *chartInstanceVar)
{
  disable_c2_M32_getnsave_data_infra_trans();
}

static void sf_opaque_gateway_c2_M32_getnsave_data_infra_trans(void
  *chartInstanceVar)
{
  sf_c2_M32_getnsave_data_infra_trans();
}

static mxArray* sf_opaque_get_sim_state_c2_M32_getnsave_data_infra_trans(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c2_M32_getnsave_data_infra_trans();
  return st;
}

static void sf_opaque_set_sim_state_c2_M32_getnsave_data_infra_trans(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c2_M32_getnsave_data_infra_trans(sf_mex_dup(st));
}

static void sf_opaque_terminate_c2_M32_getnsave_data_infra_trans(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c2_M32_getnsave_data_infra_trans();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_M32_getnsave_data_infra_trans(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_M32_getnsave_data_infra_trans();
  }
}

static void mdlSetWorkWidths_c2_M32_getnsave_data_infra_trans(SimStruct *S)
{
  /* Actual parameters from chart:
     B n
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for B*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for n*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M32_getnsave_data_infra_trans",
      "M32_getnsave_data_infra_trans",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("M32_getnsave_data_infra_trans",
                "M32_getnsave_data_infra_trans",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M32_getnsave_data_infra_trans","M32_getnsave_data_infra_trans",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"M32_getnsave_data_infra_trans",
        "M32_getnsave_data_infra_trans",2,15);
      sf_mark_chart_reusable_outputs(S,"M32_getnsave_data_infra_trans",
        "M32_getnsave_data_infra_trans",2,1);
    }

    sf_set_rtw_dwork_info(S,"M32_getnsave_data_infra_trans",
                          "M32_getnsave_data_infra_trans",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1371519145U));
  ssSetChecksum1(S,(4194640316U));
  ssSetChecksum2(S,(3058662736U));
  ssSetChecksum3(S,(2574201951U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_M32_getnsave_data_infra_trans(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M32_getnsave_data_infra_trans",
      "M32_getnsave_data_infra_trans",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_M32_getnsave_data_infra_trans(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_M32_getnsave_data_infra_trans;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_M32_getnsave_data_infra_trans;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_M32_getnsave_data_infra_trans;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c2_M32_getnsave_data_infra_trans;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c2_M32_getnsave_data_infra_trans;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_M32_getnsave_data_infra_trans;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_M32_getnsave_data_infra_trans;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_M32_getnsave_data_infra_trans;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_M32_getnsave_data_infra_trans;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_M32_getnsave_data_infra_trans;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_M32_getnsave_data_infra_trans;
  chartInstance.chartInfo.extModeExec = NULL;
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

void c2_M32_getnsave_data_infra_trans_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_M32_getnsave_data_infra_trans(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_M32_getnsave_data_infra_trans(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_M32_getnsave_data_infra_trans(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_M32_getnsave_data_infra_trans_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

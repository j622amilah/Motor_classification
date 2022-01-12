/* Include files */

#include "blascompat32.h"
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun.h"
#include "c10_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c10_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc10_M37_Sim_Forcing_003h_expe_infra_transz_limInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void initialize_params_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void);
static void enable_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void disable_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c10_update_debugger_state_c10_M37_Sim_Forcing_003h_expe_infra_t(void);
static void ext_mode_exec_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static const mxArray
  *get_sim_state_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void set_sim_state_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c10_st);
static void finalize_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void sf_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c10_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static const mxArray *c10_sf_marshall(void *c10_chartInstance, void *c10_u);
static const mxArray *c10_b_sf_marshall(void *c10_chartInstance, void *c10_u);
static const mxArray *c10_c_sf_marshall(void *c10_chartInstance, void *c10_u);
static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[27]);
static const mxArray *c10_d_sf_marshall(void *c10_chartInstance, void *c10_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  uint8_T *c10_is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c10_is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c10_is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim = 0U;
}

static void initialize_params_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void)
{
}

static void enable_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c10_update_debugger_state_c10_M37_Sim_Forcing_003h_expe_infra_t(void)
{
}

static void ext_mode_exec_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  c10_update_debugger_state_c10_M37_Sim_Forcing_003h_expe_infra_t();
}

static const mxArray
  *get_sim_state_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const mxArray *c10_st = NULL;
  const mxArray *c10_y = NULL;
  int32_T c10_i0;
  real_T c10_u[6];
  const mxArray *c10_b_y = NULL;
  uint8_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  uint8_T *c10_is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  real_T (*c10_out)[6];
  c10_is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c10_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 1);
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(2));
  for (c10_i0 = 0; c10_i0 < 6; c10_i0 = c10_i0 + 1) {
    c10_u[c10_i0] = (*c10_out)[c10_i0];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_u = *c10_is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y);
  return c10_st;
}

static void set_sim_state_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c10_st)
{
  const mxArray *c10_u;
  const mxArray *c10_out;
  real_T c10_dv0[6];
  int32_T c10_i1;
  real_T c10_y[6];
  int32_T c10_i2;
  const mxArray *c10_is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  uint8_T c10_u0;
  uint8_T c10_b_y;
  boolean_T *c10_doneDoubleBufferReInit;
  uint8_T *c10_b_is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  real_T (*c10_b_out)[6];
  c10_b_is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c10_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c10_b_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 1);
  *c10_doneDoubleBufferReInit = true;
  c10_u = sf_mex_dup(c10_st);
  c10_out = sf_mex_dup(sf_mex_getcell(c10_u, 0));
  sf_mex_import("out", sf_mex_dup(c10_out), &c10_dv0, 1, 0, 0U, 1, 0U, 1, 6);
  for (c10_i1 = 0; c10_i1 < 6; c10_i1 = c10_i1 + 1) {
    c10_y[c10_i1] = c10_dv0[c10_i1];
  }

  sf_mex_destroy(&c10_out);
  for (c10_i2 = 0; c10_i2 < 6; c10_i2 = c10_i2 + 1) {
    (*c10_b_out)[c10_i2] = c10_y[c10_i2];
  }

  c10_is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim = sf_mex_dup
    (sf_mex_getcell(c10_u, 1));
  sf_mex_import("is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim",
                sf_mex_dup(
    c10_is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim), &c10_u0, 1, 3,
                0U, 0, 0U, 0);
  c10_b_y = c10_u0;
  sf_mex_destroy(&c10_is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim);
  *c10_b_is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim = c10_b_y;
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_M37_Sim_Forcing_003h_expe_infra_t();
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void sf_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c10_i3;
  int32_T c10_i4;
  int32_T c10_previousEvent;
  real_T (*c10_out)[6];
  real_T (*c10_vec)[7];
  c10_vec = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
  c10_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,9);
  for (c10_i3 = 0; c10_i3 < 7; c10_i3 = c10_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c10_vec)[c10_i3], 0U);
  }

  for (c10_i4 = 0; c10_i4 < 6; c10_i4 = c10_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c10_out)[c10_i4], 1U);
  }

  c10_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c10_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  _sfEvent_ = c10_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void c10_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c10_i5;
  real_T c10_vec[7];
  real_T c10_nargout = 1.0;
  real_T c10_nargin = 1.0;
  real_T c10_Z;
  real_T c10_X;
  real_T c10_theta;
  real_T c10_sth2;
  real_T c10_cth2;
  real_T c10_sth23;
  real_T c10_cth23;
  real_T c10_L34;
  real_T c10_height_A2;
  real_T c10_offset;
  real_T c10_L5;
  real_T c10_L2;
  real_T c10_L1;
  real_T c10_DTR;
  real_T c10_theta5;
  real_T c10_theta3;
  real_T c10_theta2;
  real_T c10_out[6];
  int32_T c10_i6;
  real_T c10_a;
  real_T c10_y;
  real_T c10_b_a;
  real_T c10_b_y;
  real_T c10_x;
  real_T c10_b_x;
  real_T c10_c_a;
  real_T c10_c_y;
  real_T c10_d_a;
  real_T c10_d_y;
  real_T c10_c_x;
  real_T c10_d_x;
  real_T c10_e_a;
  real_T c10_e_x;
  real_T c10_f_x;
  real_T c10_f_a;
  real_T c10_g_x;
  real_T c10_h_x;
  real_T c10_g_a;
  real_T c10_i_x;
  real_T c10_b;
  real_T c10_j_x;
  real_T c10_e_y;
  real_T c10_b_b;
  real_T c10_f_y;
  real_T c10_c_b;
  real_T c10_g_y;
  real_T c10_d_b;
  real_T c10_h_y;
  real_T c10_e_b;
  real_T c10_h_a;
  real_T c10_k_x;
  real_T c10_f_b;
  real_T c10_l_x;
  real_T c10_i_y;
  real_T c10_g_b;
  real_T c10_j_y;
  real_T c10_h_b;
  real_T c10_k_y;
  real_T c10_i_b;
  real_T c10_l_y;
  real_T c10_j_b;
  int32_T c10_i7;
  real_T (*c10_b_out)[6];
  real_T (*c10_b_vec)[7];
  c10_b_vec = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
  c10_b_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,9);
  for (c10_i5 = 0; c10_i5 < 7; c10_i5 = c10_i5 + 1) {
    c10_vec[c10_i5] = (*c10_b_vec)[c10_i5];
  }

  sf_debug_symbol_scope_push(21U, 0U);
  sf_debug_symbol_scope_add("nargout", &c10_nargout, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c10_nargin, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("Z", &c10_Z, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("X", &c10_X, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("theta", &c10_theta, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("sth2", &c10_sth2, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("cth2", &c10_cth2, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("sth23", &c10_sth23, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("cth23", &c10_cth23, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("L34", &c10_L34, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("height_A2", &c10_height_A2, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("offset", &c10_offset, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("L5", &c10_L5, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("L2", &c10_L2, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("L1", &c10_L1, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("DTR", &c10_DTR, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("theta5", &c10_theta5, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("theta3", &c10_theta3, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("theta2", &c10_theta2, c10_c_sf_marshall);
  sf_debug_symbol_scope_add("out", &c10_out, c10_b_sf_marshall);
  sf_debug_symbol_scope_add("vec", &c10_vec, c10_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,2);
  for (c10_i6 = 0; c10_i6 < 6; c10_i6 = c10_i6 + 1) {
    c10_out[c10_i6] = 0.0;
  }

  _SFD_EML_CALL(0,4);
  c10_theta2 = c10_vec[1];
  _SFD_EML_CALL(0,5);
  c10_theta3 = c10_vec[2];
  _SFD_EML_CALL(0,6);
  c10_theta5 = c10_vec[4];
  _SFD_EML_CALL(0,8);
  c10_DTR = 1.7453292519943295E-002;
  _SFD_EML_CALL(0,9);
  c10_L1 = 0.5;
  _SFD_EML_CALL(0,10);
  c10_L2 = 1.3;

  /*  L3=0.66; */
  /*  L4=0.365; */
  _SFD_EML_CALL(0,13);
  c10_L5 = 0.29;
  _SFD_EML_CALL(0,14);
  c10_offset = 0.055;
  _SFD_EML_CALL(0,15);
  c10_height_A2 = 2.105;
  _SFD_EML_CALL(0,16);
  c10_L34 = 1.025;

  /* L3+L4; */
  _SFD_EML_CALL(0,18);
  c10_a = c10_theta3;
  c10_y = c10_a * 1.7453292519943295E-002;
  c10_b_a = c10_theta2;
  c10_b_y = c10_b_a * 1.7453292519943295E-002;
  c10_x = c10_b_y + c10_y;
  c10_cth23 = c10_x;
  c10_b_x = c10_cth23;
  c10_cth23 = c10_b_x;
  c10_cth23 = muDoubleScalarCos(c10_cth23);
  _SFD_EML_CALL(0,19);
  c10_c_a = c10_theta3;
  c10_c_y = c10_c_a * 1.7453292519943295E-002;
  c10_d_a = c10_theta2;
  c10_d_y = c10_d_a * 1.7453292519943295E-002;
  c10_c_x = c10_d_y + c10_c_y;
  c10_sth23 = c10_c_x;
  c10_d_x = c10_sth23;
  c10_sth23 = c10_d_x;
  c10_sth23 = muDoubleScalarSin(c10_sth23);
  _SFD_EML_CALL(0,20);
  c10_e_a = c10_theta2;
  c10_e_x = c10_e_a * 1.7453292519943295E-002;
  c10_cth2 = c10_e_x;
  c10_f_x = c10_cth2;
  c10_cth2 = c10_f_x;
  c10_cth2 = muDoubleScalarCos(c10_cth2);
  _SFD_EML_CALL(0,21);
  c10_f_a = c10_theta2;
  c10_g_x = c10_f_a * 1.7453292519943295E-002;
  c10_sth2 = c10_g_x;
  c10_h_x = c10_sth2;
  c10_sth2 = c10_h_x;
  c10_sth2 = muDoubleScalarSin(c10_sth2);
  _SFD_EML_CALL(0,23);
  c10_theta = (c10_theta2 + c10_theta3) + c10_theta5;
  _SFD_EML_CALL(0,24);
  c10_g_a = c10_theta;
  c10_i_x = c10_g_a * 1.7453292519943295E-002;
  c10_b = c10_i_x;
  c10_j_x = c10_b;
  c10_b = c10_j_x;
  c10_b = muDoubleScalarCos(c10_b);
  c10_e_y = 0.29 * c10_b;
  c10_b_b = c10_cth23;
  c10_f_y = 1.025 * c10_b_b;
  c10_c_b = c10_sth23;
  c10_g_y = 0.055 * c10_c_b;
  c10_d_b = c10_cth2;
  c10_h_y = 1.3 * c10_d_b;
  c10_e_b = (((c10_h_y + c10_L1) + c10_g_y) + c10_f_y) + c10_e_y;
  c10_X = 100.0 * c10_e_b;
  _SFD_EML_CALL(0,25);
  c10_h_a = c10_theta;
  c10_k_x = c10_h_a * 1.7453292519943295E-002;
  c10_f_b = c10_k_x;
  c10_l_x = c10_f_b;
  c10_f_b = c10_l_x;
  c10_f_b = muDoubleScalarSin(c10_f_b);
  c10_i_y = 0.29 * c10_f_b;
  c10_g_b = c10_sth23;
  c10_j_y = 1.025 * c10_g_b;
  c10_h_b = c10_cth23;
  c10_k_y = 0.055 * c10_h_b;
  c10_i_b = c10_sth2;
  c10_l_y = 1.3 * c10_i_b;
  c10_j_b = (((c10_l_y + c10_height_A2) - c10_k_y) + c10_j_y) + c10_i_y;
  c10_Z = -100.0 * c10_j_b;
  _SFD_EML_CALL(0,27);
  c10_out[0] = c10_X;
  _SFD_EML_CALL(0,28);
  c10_out[2] = c10_Z;
  _SFD_EML_CALL(0,29);
  c10_out[4] = c10_theta;
  _SFD_EML_CALL(0,-29);
  sf_debug_symbol_scope_pop();
  for (c10_i7 = 0; c10_i7 < 6; c10_i7 = c10_i7 + 1) {
    (*c10_b_out)[c10_i7] = c10_out[c10_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,9);
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
}

static const mxArray *c10_sf_marshall(void *c10_chartInstance, void *c10_u)
{
  const mxArray *c10_y = NULL;
  int32_T c10_i8;
  real_T c10_b_u[7];
  const mxArray *c10_b_y = NULL;
  c10_y = NULL;
  for (c10_i8 = 0; c10_i8 < 7; c10_i8 = c10_i8 + 1) {
    c10_b_u[c10_i8] = (*((real_T (*)[7])c10_u))[c10_i8];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static const mxArray *c10_b_sf_marshall(void *c10_chartInstance, void *c10_u)
{
  const mxArray *c10_y = NULL;
  int32_T c10_i9;
  real_T c10_b_u[6];
  const mxArray *c10_b_y = NULL;
  c10_y = NULL;
  for (c10_i9 = 0; c10_i9 < 6; c10_i9 = c10_i9 + 1) {
    c10_b_u[c10_i9] = (*((real_T (*)[6])c10_u))[c10_i9];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static const mxArray *c10_c_sf_marshall(void *c10_chartInstance, void *c10_u)
{
  const mxArray *c10_y = NULL;
  real_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  c10_y = NULL;
  c10_b_u = *((real_T *)c10_u);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

const mxArray
  *sf_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_ResolvedFunctionInfo c10_info[27];
  const mxArray *c10_m0 = NULL;
  int32_T c10_i10;
  c10_ResolvedFunctionInfo *c10_r0;
  c10_nameCaptureInfo = NULL;
  c10_info_helper(c10_info);
  sf_mex_assign(&c10_m0, sf_mex_createstruct("nameCaptureInfo", 1, 27));
  for (c10_i10 = 0; c10_i10 < 27; c10_i10 = c10_i10 + 1) {
    c10_r0 = &c10_info[c10_i10];
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->context)), "context"
                    , "nameCaptureInfo", c10_i10);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->name)), "name",
                    "nameCaptureInfo", c10_i10);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      c10_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c10_i10);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->resolved)),
                    "resolved", "nameCaptureInfo", c10_i10);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c10_i10);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c10_i10);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c10_i10);
  }

  sf_mex_assign(&c10_nameCaptureInfo, c10_m0);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[27])
{
  c10_info[0].context = "";
  c10_info[0].name = "zeros";
  c10_info[0].dominantType = "double";
  c10_info[0].resolved = "[B]zeros";
  c10_info[0].fileLength = 0U;
  c10_info[0].fileTime1 = 0U;
  c10_info[0].fileTime2 = 0U;
  c10_info[1].context = "";
  c10_info[1].name = "pi";
  c10_info[1].dominantType = "";
  c10_info[1].resolved = "[B]pi";
  c10_info[1].fileLength = 0U;
  c10_info[1].fileTime1 = 0U;
  c10_info[1].fileTime2 = 0U;
  c10_info[2].context = "";
  c10_info[2].name = "mrdivide";
  c10_info[2].dominantType = "double";
  c10_info[2].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[2].fileLength = 800U;
  c10_info[2].fileTime1 = 1238434292U;
  c10_info[2].fileTime2 = 0U;
  c10_info[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[3].name = "nargin";
  c10_info[3].dominantType = "";
  c10_info[3].resolved = "[B]nargin";
  c10_info[3].fileLength = 0U;
  c10_info[3].fileTime1 = 0U;
  c10_info[3].fileTime2 = 0U;
  c10_info[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[4].name = "ge";
  c10_info[4].dominantType = "double";
  c10_info[4].resolved = "[B]ge";
  c10_info[4].fileLength = 0U;
  c10_info[4].fileTime1 = 0U;
  c10_info[4].fileTime2 = 0U;
  c10_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[5].name = "isscalar";
  c10_info[5].dominantType = "double";
  c10_info[5].resolved = "[B]isscalar";
  c10_info[5].fileLength = 0U;
  c10_info[5].fileTime1 = 0U;
  c10_info[5].fileTime2 = 0U;
  c10_info[6].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[6].name = "rdivide";
  c10_info[6].dominantType = "double";
  c10_info[6].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[6].fileLength = 620U;
  c10_info[6].fileTime1 = 1213926766U;
  c10_info[6].fileTime2 = 0U;
  c10_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[7].name = "gt";
  c10_info[7].dominantType = "double";
  c10_info[7].resolved = "[B]gt";
  c10_info[7].fileLength = 0U;
  c10_info[7].fileTime1 = 0U;
  c10_info[7].fileTime2 = 0U;
  c10_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[8].name = "isa";
  c10_info[8].dominantType = "double";
  c10_info[8].resolved = "[B]isa";
  c10_info[8].fileLength = 0U;
  c10_info[8].fileTime1 = 0U;
  c10_info[8].fileTime2 = 0U;
  c10_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[9].name = "isempty";
  c10_info[9].dominantType = "double";
  c10_info[9].resolved = "[B]isempty";
  c10_info[9].fileLength = 0U;
  c10_info[9].fileTime1 = 0U;
  c10_info[9].fileTime2 = 0U;
  c10_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[10].name = "not";
  c10_info[10].dominantType = "logical";
  c10_info[10].resolved = "[B]not";
  c10_info[10].fileLength = 0U;
  c10_info[10].fileTime1 = 0U;
  c10_info[10].fileTime2 = 0U;
  c10_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[11].name = "strcmp";
  c10_info[11].dominantType = "char";
  c10_info[11].resolved = "[B]strcmp";
  c10_info[11].fileLength = 0U;
  c10_info[11].fileTime1 = 0U;
  c10_info[11].fileTime2 = 0U;
  c10_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[12].name = "eq";
  c10_info[12].dominantType = "double";
  c10_info[12].resolved = "[B]eq";
  c10_info[12].fileLength = 0U;
  c10_info[12].fileTime1 = 0U;
  c10_info[12].fileTime2 = 0U;
  c10_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[13].name = "eml_warning";
  c10_info[13].dominantType = "char";
  c10_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c10_info[13].fileLength = 262U;
  c10_info[13].fileTime1 = 1236257278U;
  c10_info[13].fileTime2 = 0U;
  c10_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[14].name = "eml_div";
  c10_info[14].dominantType = "double";
  c10_info[14].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c10_info[14].fileLength = 4269U;
  c10_info[14].fileTime1 = 1228093826U;
  c10_info[14].fileTime2 = 0U;
  c10_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c10_info[15].name = "isinteger";
  c10_info[15].dominantType = "double";
  c10_info[15].resolved = "[B]isinteger";
  c10_info[15].fileLength = 0U;
  c10_info[15].fileTime1 = 0U;
  c10_info[15].fileTime2 = 0U;
  c10_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c10_info[16].name = "isreal";
  c10_info[16].dominantType = "double";
  c10_info[16].resolved = "[B]isreal";
  c10_info[16].fileLength = 0U;
  c10_info[16].fileTime1 = 0U;
  c10_info[16].fileTime2 = 0U;
  c10_info[17].context = "";
  c10_info[17].name = "plus";
  c10_info[17].dominantType = "double";
  c10_info[17].resolved = "[B]plus";
  c10_info[17].fileLength = 0U;
  c10_info[17].fileTime1 = 0U;
  c10_info[17].fileTime2 = 0U;
  c10_info[18].context = "";
  c10_info[18].name = "mtimes";
  c10_info[18].dominantType = "double";
  c10_info[18].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[18].fileLength = 3302U;
  c10_info[18].fileTime1 = 1242750894U;
  c10_info[18].fileTime2 = 0U;
  c10_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[19].name = "size";
  c10_info[19].dominantType = "double";
  c10_info[19].resolved = "[B]size";
  c10_info[19].fileLength = 0U;
  c10_info[19].fileTime1 = 0U;
  c10_info[19].fileTime2 = 0U;
  c10_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[20].name = "class";
  c10_info[20].dominantType = "double";
  c10_info[20].resolved = "[B]class";
  c10_info[20].fileLength = 0U;
  c10_info[20].fileTime1 = 0U;
  c10_info[20].fileTime2 = 0U;
  c10_info[21].context = "";
  c10_info[21].name = "cos";
  c10_info[21].dominantType = "double";
  c10_info[21].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c10_info[21].fileLength = 324U;
  c10_info[21].fileTime1 = 1203447952U;
  c10_info[21].fileTime2 = 0U;
  c10_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c10_info[22].name = "eml_scalar_cos";
  c10_info[22].dominantType = "double";
  c10_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c10_info[22].fileLength = 602U;
  c10_info[22].fileTime1 = 1209330788U;
  c10_info[22].fileTime2 = 0U;
  c10_info[23].context = "";
  c10_info[23].name = "sin";
  c10_info[23].dominantType = "double";
  c10_info[23].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c10_info[23].fileLength = 324U;
  c10_info[23].fileTime1 = 1203448042U;
  c10_info[23].fileTime2 = 0U;
  c10_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c10_info[24].name = "eml_scalar_sin";
  c10_info[24].dominantType = "double";
  c10_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c10_info[24].fileLength = 601U;
  c10_info[24].fileTime1 = 1209330792U;
  c10_info[24].fileTime2 = 0U;
  c10_info[25].context = "";
  c10_info[25].name = "uminus";
  c10_info[25].dominantType = "double";
  c10_info[25].resolved = "[B]uminus";
  c10_info[25].fileLength = 0U;
  c10_info[25].fileTime1 = 0U;
  c10_info[25].fileTime2 = 0U;
  c10_info[26].context = "";
  c10_info[26].name = "minus";
  c10_info[26].dominantType = "double";
  c10_info[26].resolved = "[B]minus";
  c10_info[26].fileLength = 0U;
  c10_info[26].fileTime1 = 0U;
  c10_info[26].fileTime2 = 0U;
}

static const mxArray *c10_d_sf_marshall(void *c10_chartInstance, void *c10_u)
{
  const mxArray *c10_y = NULL;
  boolean_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  c10_y = NULL;
  c10_b_u = *((boolean_T *)c10_u);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3952247661U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3926209521U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(554714421U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3675867297U);
}

mxArray
  *sf_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2926941576U);
    pr[1] = (double)(1096874986U);
    pr[2] = (double)(4064530270U);
    pr[3] = (double)(4252582530U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(7);
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
      pr[0] = (double)(6);
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
  *sf_get_sim_state_info_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"out\",},{M[8],M[0],T\"is_active_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(&mxChecksum);
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
           10,
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
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"vec",0,(MexFcnForType)c10_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"out",0,(MexFcnForType)c10_b_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,521);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c10_vec)[7];
          real_T (*c10_out)[6];
          c10_vec = (real_T (*)[7])ssGetInputPortSignal(chartInstance.S, 0);
          c10_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c10_vec);
          _SFD_SET_DATA_VALUE_PTR(1U, c10_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  initialize_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_enable_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  enable_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_disable_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  disable_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_gateway_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  sf_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void
  sf_opaque_ext_mode_exec_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  ext_mode_exec_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static mxArray*
  sf_opaque_get_sim_state_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  return st;
}

static void
  sf_opaque_set_sim_state_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(sf_mex_dup(st));
}

static void sf_opaque_terminate_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",10,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",10,1);
      sf_mark_chart_reusable_outputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",10,1);
    }

    sf_set_rtw_dwork_info(S,"M37_Sim_Forcing_003h_expe_infra_transz_lim",
                          "M37_Sim_Forcing_003h_expe_infra_transz_lim",10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(68265511U));
  ssSetChecksum1(S,(3299182180U));
  ssSetChecksum2(S,(3504596166U));
  ssSetChecksum3(S,(686731007U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",10);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim;
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

void c10_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(SimStruct *
  S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

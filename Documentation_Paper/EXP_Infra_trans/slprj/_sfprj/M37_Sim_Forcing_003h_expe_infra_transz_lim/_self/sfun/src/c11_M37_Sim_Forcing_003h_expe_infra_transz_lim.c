/* Include files */

#include "blascompat32.h"
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun.h"
#include "c11_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c11_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc11_M37_Sim_Forcing_003h_expe_infra_transz_limInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void initialize_params_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void);
static void enable_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void disable_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c11_update_debugger_state_c11_M37_Sim_Forcing_003h_expe_infra_t(void);
static void ext_mode_exec_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static const mxArray
  *get_sim_state_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void set_sim_state_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c11_st);
static void finalize_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void sf_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c11_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static real_T c11_mrdivide(real_T c11_A, real_T c11_B);
static void c11_eml_warning(void);
static const mxArray *c11_sf_marshall(void *c11_chartInstance, void *c11_u);
static const mxArray *c11_b_sf_marshall(void *c11_chartInstance, void *c11_u);
static const mxArray *c11_c_sf_marshall(void *c11_chartInstance, void *c11_u);
static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[39]);
static const mxArray *c11_d_sf_marshall(void *c11_chartInstance, void *c11_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  uint8_T *c11_is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c11_is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c11_is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim = 0U;
}

static void initialize_params_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void)
{
}

static void enable_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c11_update_debugger_state_c11_M37_Sim_Forcing_003h_expe_infra_t(void)
{
}

static void ext_mode_exec_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  c11_update_debugger_state_c11_M37_Sim_Forcing_003h_expe_infra_t();
}

static const mxArray
  *get_sim_state_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const mxArray *c11_st = NULL;
  const mxArray *c11_y = NULL;
  int32_T c11_i0;
  real_T c11_u[7];
  const mxArray *c11_b_y = NULL;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  uint8_T *c11_is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  real_T (*c11_out)[7];
  c11_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  c11_is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(2));
  for (c11_i0 = 0; c11_i0 < 7; c11_i0 = c11_i0 + 1) {
    c11_u[c11_i0] = (*c11_out)[c11_i0];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_u = *c11_is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c11_y, 1, c11_c_y);
  sf_mex_assign(&c11_st, c11_y);
  return c11_st;
}

static void set_sim_state_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c11_st)
{
  const mxArray *c11_u;
  const mxArray *c11_out;
  real_T c11_dv0[7];
  int32_T c11_i1;
  real_T c11_y[7];
  int32_T c11_i2;
  const mxArray *c11_is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  uint8_T c11_u0;
  uint8_T c11_b_y;
  boolean_T *c11_doneDoubleBufferReInit;
  uint8_T *c11_b_is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  real_T (*c11_b_out)[7];
  c11_b_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  c11_b_is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c11_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  *c11_doneDoubleBufferReInit = true;
  c11_u = sf_mex_dup(c11_st);
  c11_out = sf_mex_dup(sf_mex_getcell(c11_u, 0));
  sf_mex_import("out", sf_mex_dup(c11_out), &c11_dv0, 1, 0, 0U, 1, 0U, 1, 7);
  for (c11_i1 = 0; c11_i1 < 7; c11_i1 = c11_i1 + 1) {
    c11_y[c11_i1] = c11_dv0[c11_i1];
  }

  sf_mex_destroy(&c11_out);
  for (c11_i2 = 0; c11_i2 < 7; c11_i2 = c11_i2 + 1) {
    (*c11_b_out)[c11_i2] = c11_y[c11_i2];
  }

  c11_is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim = sf_mex_dup
    (sf_mex_getcell(c11_u, 1));
  sf_mex_import("is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim",
                sf_mex_dup(
    c11_is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim), &c11_u0, 1, 3,
                0U, 0, 0U, 0);
  c11_b_y = c11_u0;
  sf_mex_destroy(&c11_is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim);
  *c11_b_is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim = c11_b_y;
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_M37_Sim_Forcing_003h_expe_infra_t();
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void sf_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c11_i3;
  int32_T c11_i4;
  int32_T c11_previousEvent;
  real_T (*c11_out)[7];
  real_T (*c11_vec)[12];
  c11_vec = (real_T (*)[12])ssGetInputPortSignal(chartInstance.S, 0);
  c11_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,10);
  for (c11_i3 = 0; c11_i3 < 12; c11_i3 = c11_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c11_vec)[c11_i3], 0U);
  }

  for (c11_i4 = 0; c11_i4 < 7; c11_i4 = c11_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c11_out)[c11_i4], 1U);
  }

  c11_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c11_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  _sfEvent_ = c11_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void c11_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c11_i5;
  real_T c11_vec[12];
  real_T c11_nargout = 1.0;
  real_T c11_nargin = 1.0;
  real_T c11_theta2;
  real_T c11_theta5;
  real_T c11_dtheta5;
  real_T c11_left_side_2;
  real_T c11_theta3;
  real_T c11_dtheta3;
  real_T c11_left_side;
  real_T c11_K;
  real_T c11_L34;
  real_T c11_height_A2;
  real_T c11_offset;
  real_T c11_L5;
  real_T c11_L2;
  real_T c11_L1;
  real_T c11_sth;
  real_T c11_cth;
  real_T c11_sth23i;
  real_T c11_cth23i;
  real_T c11_cth2i;
  real_T c11_sth3i;
  real_T c11_cth3i;
  real_T c11_DTR;
  real_T c11_theta5_in;
  real_T c11_theta3_in;
  real_T c11_theta2_in;
  real_T c11_theta;
  real_T c11_Z;
  real_T c11_X;
  real_T c11_out[7];
  int32_T c11_i6;
  real_T c11_a;
  real_T c11_x;
  real_T c11_b_x;
  real_T c11_b_a;
  real_T c11_c_x;
  real_T c11_d_x;
  real_T c11_c_a;
  real_T c11_e_x;
  real_T c11_f_x;
  real_T c11_d_a;
  real_T c11_g_x;
  real_T c11_h_x;
  real_T c11_e_a;
  real_T c11_i_x;
  real_T c11_j_x;
  real_T c11_k_x;
  real_T c11_l_x;
  real_T c11_m_x;
  real_T c11_n_x;
  real_T c11_b;
  real_T c11_y;
  real_T c11_b_b;
  real_T c11_b_y;
  real_T c11_f_a;
  real_T c11_c_b;
  real_T c11_c_y;
  real_T c11_d_b;
  real_T c11_d_y;
  real_T c11_e_b;
  real_T c11_e_y;
  real_T c11_g_a;
  real_T c11_f_b;
  real_T c11_f_y;
  real_T c11_g_b;
  real_T c11_g_y;
  real_T c11_h_a;
  real_T c11_h_b;
  real_T c11_h_y;
  real_T c11_i_b;
  real_T c11_i_y;
  real_T c11_j_b;
  real_T c11_j_y;
  real_T c11_i_a;
  real_T c11_k_b;
  real_T c11_k_y;
  real_T c11_l_b;
  real_T c11_l_y;
  real_T c11_A;
  real_T c11_o_x;
  real_T c11_p_x;
  real_T c11_q_x;
  real_T c11_m_y;
  real_T c11_b_A;
  real_T c11_m_b;
  real_T c11_n_y;
  real_T c11_n_b;
  real_T c11_o_y;
  real_T c11_j_a;
  real_T c11_o_b;
  real_T c11_p_y;
  real_T c11_p_b;
  real_T c11_q_y;
  real_T c11_q_b;
  real_T c11_r_y;
  real_T c11_k_a;
  real_T c11_r_b;
  real_T c11_s_y;
  real_T c11_B;
  real_T c11_r_x;
  real_T c11_t_y;
  real_T c11_s_x;
  real_T c11_u_y;
  real_T c11_t_x;
  real_T c11_v_y;
  real_T c11_u_x;
  real_T c11_v_x;
  real_T c11_w_y;
  real_T c11_w_x;
  real_T c11_l_a;
  real_T c11_x_x;
  real_T c11_y_x;
  boolean_T c11_s_b;
  real_T c11_t_b;
  real_T c11_x_y;
  real_T c11_u_b;
  real_T c11_y_y;
  real_T c11_v_b;
  real_T c11_ab_y;
  real_T c11_w_b;
  real_T c11_bb_y;
  real_T c11_c_A;
  real_T c11_x_b;
  real_T c11_cb_y;
  real_T c11_y_b;
  real_T c11_db_y;
  real_T c11_b_B;
  real_T c11_ab_x;
  real_T c11_eb_y;
  real_T c11_bb_x;
  real_T c11_fb_y;
  real_T c11_cb_x;
  real_T c11_gb_y;
  real_T c11_db_x;
  real_T c11_eb_x;
  real_T c11_hb_y;
  real_T c11_fb_x;
  real_T c11_m_a;
  real_T c11_gb_x;
  real_T c11_hb_x;
  boolean_T c11_ab_b;
  int32_T c11_i7;
  real_T (*c11_b_out)[7];
  real_T (*c11_b_vec)[12];
  c11_b_vec = (real_T (*)[12])ssGetInputPortSignal(chartInstance.S, 0);
  c11_b_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,10);
  for (c11_i5 = 0; c11_i5 < 12; c11_i5 = c11_i5 + 1) {
    c11_vec[c11_i5] = (*c11_b_vec)[c11_i5];
  }

  sf_debug_symbol_scope_push(32U, 0U);
  sf_debug_symbol_scope_add("nargout", &c11_nargout, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c11_nargin, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("theta2", &c11_theta2, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("theta5", &c11_theta5, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("dtheta5", &c11_dtheta5, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("left_side_2", &c11_left_side_2, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("theta3", &c11_theta3, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("dtheta3", &c11_dtheta3, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("left_side", &c11_left_side, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("K", &c11_K, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("L34", &c11_L34, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("height_A2", &c11_height_A2, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("offset", &c11_offset, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("L5", &c11_L5, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("L2", &c11_L2, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("L1", &c11_L1, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("sth", &c11_sth, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("cth", &c11_cth, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("sth23i", &c11_sth23i, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("cth23i", &c11_cth23i, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("cth2i", &c11_cth2i, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("sth3i", &c11_sth3i, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("cth3i", &c11_cth3i, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("DTR", &c11_DTR, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("theta5_in", &c11_theta5_in, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("theta3_in", &c11_theta3_in, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("theta2_in", &c11_theta2_in, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("theta", &c11_theta, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("Z", &c11_Z, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("X", &c11_X, c11_c_sf_marshall);
  sf_debug_symbol_scope_add("out", &c11_out, c11_b_sf_marshall);
  sf_debug_symbol_scope_add("vec", &c11_vec, c11_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,2);
  for (c11_i6 = 0; c11_i6 < 7; c11_i6 = c11_i6 + 1) {
    c11_out[c11_i6] = 0.0;
  }

  _SFD_EML_CALL(0,4);
  c11_X = c11_mrdivide(c11_vec[0], 100.0);
  _SFD_EML_CALL(0,5);
  c11_Z = c11_mrdivide(-c11_vec[2], 100.0);
  _SFD_EML_CALL(0,6);
  c11_theta = c11_vec[4];
  _SFD_EML_CALL(0,8);
  c11_theta2_in = c11_vec[7];
  _SFD_EML_CALL(0,9);
  c11_theta3_in = c11_vec[8];
  _SFD_EML_CALL(0,10);
  c11_theta5_in = c11_vec[10];
  _SFD_EML_CALL(0,12);
  c11_DTR = 1.7453292519943295E-002;

  /*  RTD=180/pi; */
  _SFD_EML_CALL(0,15);
  c11_a = c11_theta3_in;
  c11_x = c11_a * 1.7453292519943295E-002;
  c11_cth3i = c11_x;
  c11_b_x = c11_cth3i;
  c11_cth3i = c11_b_x;
  c11_cth3i = muDoubleScalarCos(c11_cth3i);
  _SFD_EML_CALL(0,16);
  c11_b_a = c11_theta3_in;
  c11_c_x = c11_b_a * 1.7453292519943295E-002;
  c11_sth3i = c11_c_x;
  c11_d_x = c11_sth3i;
  c11_sth3i = c11_d_x;
  c11_sth3i = muDoubleScalarSin(c11_sth3i);
  _SFD_EML_CALL(0,17);
  c11_c_a = c11_theta2_in;
  c11_e_x = c11_c_a * 1.7453292519943295E-002;
  c11_cth2i = c11_e_x;
  c11_f_x = c11_cth2i;
  c11_cth2i = c11_f_x;
  c11_cth2i = muDoubleScalarCos(c11_cth2i);
  _SFD_EML_CALL(0,18);
  c11_d_a = c11_theta2_in + c11_theta3_in;
  c11_g_x = c11_d_a * 1.7453292519943295E-002;
  c11_cth23i = c11_g_x;
  c11_h_x = c11_cth23i;
  c11_cth23i = c11_h_x;
  c11_cth23i = muDoubleScalarCos(c11_cth23i);
  _SFD_EML_CALL(0,19);
  c11_e_a = c11_theta2_in + c11_theta3_in;
  c11_i_x = c11_e_a * 1.7453292519943295E-002;
  c11_sth23i = c11_i_x;
  c11_j_x = c11_sth23i;
  c11_sth23i = c11_j_x;
  c11_sth23i = muDoubleScalarSin(c11_sth23i);

  /*  cth5i=cos(theta5_in*DTR); */
  /*  sth5i=sin(theta5_in*DTR); */
  _SFD_EML_CALL(0,22);
  c11_k_x = c11_theta;
  c11_cth = c11_k_x;
  c11_l_x = c11_cth;
  c11_cth = c11_l_x;
  c11_cth = muDoubleScalarCos(c11_cth);
  _SFD_EML_CALL(0,23);
  c11_m_x = c11_theta;
  c11_sth = c11_m_x;
  c11_n_x = c11_sth;
  c11_sth = c11_n_x;
  c11_sth = muDoubleScalarSin(c11_sth);
  _SFD_EML_CALL(0,25);
  c11_L1 = 0.5;
  _SFD_EML_CALL(0,26);
  c11_L2 = 1.3;

  /*  L3=0.66; */
  /*  L4=0.365; */
  _SFD_EML_CALL(0,29);
  c11_L5 = 0.29;
  _SFD_EML_CALL(0,30);
  c11_offset = 0.055;
  _SFD_EML_CALL(0,31);
  c11_height_A2 = 2.105;
  _SFD_EML_CALL(0,32);
  c11_L34 = 1.025;

  /* L3+L4; */
  /* K=L2*L2+offset*offset+(L34)*(L34); */
  _SFD_EML_CALL(0,35);
  c11_K = 2.7437;
  _SFD_EML_CALL(0,37);
  c11_b = c11_cth;
  c11_y = 1.025 * c11_b;
  c11_b_b = c11_sth;
  c11_b_y = -0.055 * c11_b_b;
  c11_f_a = c11_b_y + c11_y;
  c11_c_b = c11_cth3i;
  c11_c_y = c11_f_a * c11_c_b;
  c11_d_b = c11_sth;
  c11_d_y = 1.025 * c11_d_b;
  c11_e_b = c11_cth;
  c11_e_y = 0.055 * c11_e_b;
  c11_g_a = c11_e_y + c11_d_y;
  c11_f_b = c11_sth3i;
  c11_f_y = c11_g_a * c11_f_b;
  c11_g_b = c11_sth;
  c11_g_y = 0.29 * c11_g_b;
  c11_h_a = (c11_Z - c11_height_A2) - c11_g_y;
  c11_h_b = c11_sth;
  c11_h_y = 0.29 * c11_h_b;
  c11_i_b = (c11_Z - c11_height_A2) - c11_h_y;
  c11_i_y = c11_h_a * c11_i_b;
  c11_j_b = c11_cth;
  c11_j_y = 0.29 * c11_j_b;
  c11_i_a = (c11_X - c11_L1) - c11_j_y;
  c11_k_b = c11_cth;
  c11_k_y = 0.29 * c11_k_b;
  c11_l_b = (c11_X - c11_L1) - c11_k_y;
  c11_l_y = c11_i_a * c11_l_b;
  c11_A = (c11_l_y + c11_i_y) - c11_K;
  c11_o_x = c11_A;
  c11_p_x = c11_o_x;
  c11_q_x = c11_p_x;
  c11_m_y = c11_q_x / 2.6;
  c11_left_side = (c11_m_y - c11_f_y) - c11_c_y;

  /* left_side=0.3325; */
  /* equation to be solved: */
  /*  left_side= offset*sinus(theta3)+(L3+L4)cosinus(theta3) */
  /* we assume theta3 is small */
  /*  syms theta3 */
  /*  eqnth3 = left_side== offset*sin(theta3)+(L34)*cos(theta3); */
  /*  solth3=180*eval(solve(eqnth3,theta3))/pi; */
  /*   */
  /*  for i=1:length(solth3) */
  /*      if(solth3(i)<0) */
  /*          theta3=solth3(i); */
  /*      end */
  /*  end */
  _SFD_EML_CALL(0,54);
  c11_b_A = c11_left_side;
  c11_m_b = c11_cth;
  c11_n_y = 1.025 * c11_m_b;
  c11_n_b = c11_sth;
  c11_o_y = -0.055 * c11_n_b;
  c11_j_a = c11_o_y + c11_n_y;
  c11_o_b = c11_sth3i;
  c11_p_y = c11_j_a * c11_o_b;
  c11_p_b = c11_sth;
  c11_q_y = 1.025 * c11_p_b;
  c11_q_b = c11_cth;
  c11_r_y = 0.055 * c11_q_b;
  c11_k_a = c11_r_y + c11_q_y;
  c11_r_b = c11_cth3i;
  c11_s_y = c11_k_a * c11_r_b;
  c11_B = c11_s_y - c11_p_y;
  c11_r_x = c11_b_A;
  c11_t_y = c11_B;
  if (c11_t_y == 0.0) {
    c11_eml_warning();
  }

  c11_s_x = c11_r_x;
  c11_u_y = c11_t_y;
  c11_t_x = c11_s_x;
  c11_v_y = c11_u_y;
  c11_dtheta3 = c11_t_x / c11_v_y;
  _SFD_EML_CALL(0,55);
  c11_u_x = c11_dtheta3;
  c11_v_x = c11_u_x;
  c11_w_y = muDoubleScalarAbs(c11_v_x);
  if (CV_EML_IF(0, 0, c11_w_y > 0.01)) {
    _SFD_EML_CALL(0,56);
    c11_w_x = c11_dtheta3;
    c11_l_a = c11_w_x;
    c11_x_x = c11_l_a;
    c11_l_a = c11_x_x;
    c11_y_x = c11_l_a;
    c11_s_b = rtIsNaN(c11_y_x);
    if (c11_s_b) {
      c11_l_a = rtNaN;
    } else if (c11_l_a > 0.0) {
      c11_l_a = 1.0;
    } else if (c11_l_a < 0.0) {
      c11_l_a = -1.0;
    } else {
      c11_l_a = 0.0;
    }

    c11_dtheta3 = c11_l_a * 0.01;
  }

  _SFD_EML_CALL(0,58);
  c11_theta3 = c11_theta3_in + c11_dtheta3;

  /*  syms theta5 */
  /*  alpha=L2*cos(theta3*pi/180)+(L34); */
  /*  beta=L2*sin(theta3*pi/180)+offset; */
  /*  eqnth5 = X-L1-L5 == alpha*cos(theta5)-beta*sin(theta5); */
  /*  solth5=180*eval(solve(eqnth5,theta5))/pi; */
  /*   */
  /*  for i=1:length(solth5) */
  /*      if(solth5(i)>0) */
  /*          theta5=solth5(i); */
  /*      end */
  /*  end */
  _SFD_EML_CALL(0,73);
  c11_t_b = c11_cth23i;
  c11_x_y = 1.025 * c11_t_b;
  c11_u_b = c11_sth23i;
  c11_y_y = 0.055 * c11_u_b;
  c11_v_b = c11_cth2i;
  c11_ab_y = 1.3 * c11_v_b;
  c11_w_b = c11_cth;
  c11_bb_y = 0.29 * c11_w_b;
  c11_left_side_2 = ((((c11_X - c11_L1) - c11_bb_y) - c11_ab_y) - c11_y_y) -
    c11_x_y;
  _SFD_EML_CALL(0,75);
  c11_c_A = c11_left_side_2;
  c11_x_b = c11_sth23i;
  c11_cb_y = 1.025 * c11_x_b;
  c11_y_b = c11_cth23i;
  c11_db_y = 0.055 * c11_y_b;
  c11_b_B = c11_db_y - c11_cb_y;
  c11_ab_x = c11_c_A;
  c11_eb_y = c11_b_B;
  if (c11_eb_y == 0.0) {
    c11_eml_warning();
  }

  c11_bb_x = c11_ab_x;
  c11_fb_y = c11_eb_y;
  c11_cb_x = c11_bb_x;
  c11_gb_y = c11_fb_y;
  c11_dtheta5 = c11_cb_x / c11_gb_y;
  _SFD_EML_CALL(0,76);
  c11_db_x = c11_dtheta5;
  c11_eb_x = c11_db_x;
  c11_hb_y = muDoubleScalarAbs(c11_eb_x);
  if (CV_EML_IF(0, 1, c11_hb_y > 0.01)) {
    _SFD_EML_CALL(0,77);
    c11_fb_x = c11_dtheta5;
    c11_m_a = c11_fb_x;
    c11_gb_x = c11_m_a;
    c11_m_a = c11_gb_x;
    c11_hb_x = c11_m_a;
    c11_ab_b = rtIsNaN(c11_hb_x);
    if (c11_ab_b) {
      c11_m_a = rtNaN;
    } else if (c11_m_a > 0.0) {
      c11_m_a = 1.0;
    } else if (c11_m_a < 0.0) {
      c11_m_a = -1.0;
    } else {
      c11_m_a = 0.0;
    }

    c11_dtheta5 = c11_m_a * 0.01;
  }

  _SFD_EML_CALL(0,79);
  c11_theta5 = c11_theta5_in + c11_dtheta5;
  _SFD_EML_CALL(0,81);
  c11_theta2 = (c11_theta - c11_theta3) - c11_theta5;
  _SFD_EML_CALL(0,83);
  c11_out[0] = 0.0;
  _SFD_EML_CALL(0,84);
  c11_out[1] = c11_theta2;
  _SFD_EML_CALL(0,85);
  c11_out[2] = c11_theta3;
  _SFD_EML_CALL(0,86);
  c11_out[3] = 0.0;
  _SFD_EML_CALL(0,87);
  c11_out[4] = c11_theta5;
  _SFD_EML_CALL(0,88);
  c11_out[5] = 0.0;
  _SFD_EML_CALL(0,-88);
  sf_debug_symbol_scope_pop();
  for (c11_i7 = 0; c11_i7 < 7; c11_i7 = c11_i7 + 1) {
    (*c11_b_out)[c11_i7] = c11_out[c11_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,10);
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber)
{
}

static real_T c11_mrdivide(real_T c11_A, real_T c11_B)
{
  real_T c11_x;
  real_T c11_b_y;
  real_T c11_b_x;
  real_T c11_c_y;
  real_T c11_c_x;
  real_T c11_d_y;
  c11_x = c11_A;
  c11_b_y = c11_B;
  if (c11_b_y == 0.0) {
    c11_eml_warning();
  }

  c11_b_x = c11_x;
  c11_c_y = c11_b_y;
  c11_c_x = c11_b_x;
  c11_d_y = c11_c_y;
  return c11_c_x / c11_d_y;
}

static void c11_eml_warning(void)
{
  int32_T c11_i8;
  static char_T c11_cv0[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c11_u[15];
  const mxArray *c11_y = NULL;
  int32_T c11_i9;
  static char_T c11_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c11_b_u[19];
  const mxArray *c11_b_y = NULL;
  for (c11_i8 = 0; c11_i8 < 15; c11_i8 = c11_i8 + 1) {
    c11_u[c11_i8] = c11_cv0[c11_i8];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c11_i9 = 0; c11_i9 < 19; c11_i9 = c11_i9 + 1) {
    c11_b_u[c11_i9] = c11_cv1[c11_i9];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c11_b_y, 14, c11_y);
}

static const mxArray *c11_sf_marshall(void *c11_chartInstance, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i10;
  real_T c11_b_u[12];
  const mxArray *c11_b_y = NULL;
  c11_y = NULL;
  for (c11_i10 = 0; c11_i10 < 12; c11_i10 = c11_i10 + 1) {
    c11_b_u[c11_i10] = (*((real_T (*)[12])c11_u))[c11_i10];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 1U, 0U, 1, 12));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_b_sf_marshall(void *c11_chartInstance, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i11;
  real_T c11_b_u[7];
  const mxArray *c11_b_y = NULL;
  c11_y = NULL;
  for (c11_i11 = 0; c11_i11 < 7; c11_i11 = c11_i11 + 1) {
    c11_b_u[c11_i11] = (*((real_T (*)[7])c11_u))[c11_i11];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_c_sf_marshall(void *c11_chartInstance, void *c11_u)
{
  const mxArray *c11_y = NULL;
  real_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  c11_y = NULL;
  c11_b_u = *((real_T *)c11_u);
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

const mxArray
  *sf_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_ResolvedFunctionInfo c11_info[39];
  const mxArray *c11_m0 = NULL;
  int32_T c11_i12;
  c11_ResolvedFunctionInfo *c11_r0;
  c11_nameCaptureInfo = NULL;
  c11_info_helper(c11_info);
  sf_mex_assign(&c11_m0, sf_mex_createstruct("nameCaptureInfo", 1, 39));
  for (c11_i12 = 0; c11_i12 < 39; c11_i12 = c11_i12 + 1) {
    c11_r0 = &c11_info[c11_i12];
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->context)), "context"
                    , "nameCaptureInfo", c11_i12);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->name)), "name",
                    "nameCaptureInfo", c11_i12);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      c11_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c11_i12);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->resolved)),
                    "resolved", "nameCaptureInfo", c11_i12);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c11_i12);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c11_i12);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c11_i12);
  }

  sf_mex_assign(&c11_nameCaptureInfo, c11_m0);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[39])
{
  c11_info[0].context = "";
  c11_info[0].name = "zeros";
  c11_info[0].dominantType = "double";
  c11_info[0].resolved = "[B]zeros";
  c11_info[0].fileLength = 0U;
  c11_info[0].fileTime1 = 0U;
  c11_info[0].fileTime2 = 0U;
  c11_info[1].context = "";
  c11_info[1].name = "mrdivide";
  c11_info[1].dominantType = "double";
  c11_info[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c11_info[1].fileLength = 800U;
  c11_info[1].fileTime1 = 1238434292U;
  c11_info[1].fileTime2 = 0U;
  c11_info[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c11_info[2].name = "nargin";
  c11_info[2].dominantType = "";
  c11_info[2].resolved = "[B]nargin";
  c11_info[2].fileLength = 0U;
  c11_info[2].fileTime1 = 0U;
  c11_info[2].fileTime2 = 0U;
  c11_info[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c11_info[3].name = "ge";
  c11_info[3].dominantType = "double";
  c11_info[3].resolved = "[B]ge";
  c11_info[3].fileLength = 0U;
  c11_info[3].fileTime1 = 0U;
  c11_info[3].fileTime2 = 0U;
  c11_info[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c11_info[4].name = "isscalar";
  c11_info[4].dominantType = "double";
  c11_info[4].resolved = "[B]isscalar";
  c11_info[4].fileLength = 0U;
  c11_info[4].fileTime1 = 0U;
  c11_info[4].fileTime2 = 0U;
  c11_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c11_info[5].name = "rdivide";
  c11_info[5].dominantType = "double";
  c11_info[5].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[5].fileLength = 620U;
  c11_info[5].fileTime1 = 1213926766U;
  c11_info[5].fileTime2 = 0U;
  c11_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[6].name = "gt";
  c11_info[6].dominantType = "double";
  c11_info[6].resolved = "[B]gt";
  c11_info[6].fileLength = 0U;
  c11_info[6].fileTime1 = 0U;
  c11_info[6].fileTime2 = 0U;
  c11_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[7].name = "isa";
  c11_info[7].dominantType = "double";
  c11_info[7].resolved = "[B]isa";
  c11_info[7].fileLength = 0U;
  c11_info[7].fileTime1 = 0U;
  c11_info[7].fileTime2 = 0U;
  c11_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[8].name = "isempty";
  c11_info[8].dominantType = "double";
  c11_info[8].resolved = "[B]isempty";
  c11_info[8].fileLength = 0U;
  c11_info[8].fileTime1 = 0U;
  c11_info[8].fileTime2 = 0U;
  c11_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[9].name = "not";
  c11_info[9].dominantType = "logical";
  c11_info[9].resolved = "[B]not";
  c11_info[9].fileLength = 0U;
  c11_info[9].fileTime1 = 0U;
  c11_info[9].fileTime2 = 0U;
  c11_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[10].name = "strcmp";
  c11_info[10].dominantType = "char";
  c11_info[10].resolved = "[B]strcmp";
  c11_info[10].fileLength = 0U;
  c11_info[10].fileTime1 = 0U;
  c11_info[10].fileTime2 = 0U;
  c11_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[11].name = "eq";
  c11_info[11].dominantType = "double";
  c11_info[11].resolved = "[B]eq";
  c11_info[11].fileLength = 0U;
  c11_info[11].fileTime1 = 0U;
  c11_info[11].fileTime2 = 0U;
  c11_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[12].name = "eml_warning";
  c11_info[12].dominantType = "char";
  c11_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c11_info[12].fileLength = 262U;
  c11_info[12].fileTime1 = 1236257278U;
  c11_info[12].fileTime2 = 0U;
  c11_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[13].name = "eml_div";
  c11_info[13].dominantType = "double";
  c11_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c11_info[13].fileLength = 4269U;
  c11_info[13].fileTime1 = 1228093826U;
  c11_info[13].fileTime2 = 0U;
  c11_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c11_info[14].name = "isinteger";
  c11_info[14].dominantType = "double";
  c11_info[14].resolved = "[B]isinteger";
  c11_info[14].fileLength = 0U;
  c11_info[14].fileTime1 = 0U;
  c11_info[14].fileTime2 = 0U;
  c11_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c11_info[15].name = "isreal";
  c11_info[15].dominantType = "double";
  c11_info[15].resolved = "[B]isreal";
  c11_info[15].fileLength = 0U;
  c11_info[15].fileTime1 = 0U;
  c11_info[15].fileTime2 = 0U;
  c11_info[16].context = "";
  c11_info[16].name = "uminus";
  c11_info[16].dominantType = "double";
  c11_info[16].resolved = "[B]uminus";
  c11_info[16].fileLength = 0U;
  c11_info[16].fileTime1 = 0U;
  c11_info[16].fileTime2 = 0U;
  c11_info[17].context = "";
  c11_info[17].name = "pi";
  c11_info[17].dominantType = "";
  c11_info[17].resolved = "[B]pi";
  c11_info[17].fileLength = 0U;
  c11_info[17].fileTime1 = 0U;
  c11_info[17].fileTime2 = 0U;
  c11_info[18].context = "";
  c11_info[18].name = "mtimes";
  c11_info[18].dominantType = "double";
  c11_info[18].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[18].fileLength = 3302U;
  c11_info[18].fileTime1 = 1242750894U;
  c11_info[18].fileTime2 = 0U;
  c11_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[19].name = "size";
  c11_info[19].dominantType = "double";
  c11_info[19].resolved = "[B]size";
  c11_info[19].fileLength = 0U;
  c11_info[19].fileTime1 = 0U;
  c11_info[19].fileTime2 = 0U;
  c11_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[20].name = "class";
  c11_info[20].dominantType = "double";
  c11_info[20].resolved = "[B]class";
  c11_info[20].fileLength = 0U;
  c11_info[20].fileTime1 = 0U;
  c11_info[20].fileTime2 = 0U;
  c11_info[21].context = "";
  c11_info[21].name = "cos";
  c11_info[21].dominantType = "double";
  c11_info[21].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c11_info[21].fileLength = 324U;
  c11_info[21].fileTime1 = 1203447952U;
  c11_info[21].fileTime2 = 0U;
  c11_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c11_info[22].name = "eml_scalar_cos";
  c11_info[22].dominantType = "double";
  c11_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c11_info[22].fileLength = 602U;
  c11_info[22].fileTime1 = 1209330788U;
  c11_info[22].fileTime2 = 0U;
  c11_info[23].context = "";
  c11_info[23].name = "sin";
  c11_info[23].dominantType = "double";
  c11_info[23].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c11_info[23].fileLength = 324U;
  c11_info[23].fileTime1 = 1203448042U;
  c11_info[23].fileTime2 = 0U;
  c11_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c11_info[24].name = "eml_scalar_sin";
  c11_info[24].dominantType = "double";
  c11_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c11_info[24].fileLength = 601U;
  c11_info[24].fileTime1 = 1209330792U;
  c11_info[24].fileTime2 = 0U;
  c11_info[25].context = "";
  c11_info[25].name = "plus";
  c11_info[25].dominantType = "double";
  c11_info[25].resolved = "[B]plus";
  c11_info[25].fileLength = 0U;
  c11_info[25].fileTime1 = 0U;
  c11_info[25].fileTime2 = 0U;
  c11_info[26].context = "";
  c11_info[26].name = "minus";
  c11_info[26].dominantType = "double";
  c11_info[26].resolved = "[B]minus";
  c11_info[26].fileLength = 0U;
  c11_info[26].fileTime1 = 0U;
  c11_info[26].fileTime2 = 0U;
  c11_info[27].context = "";
  c11_info[27].name = "abs";
  c11_info[27].dominantType = "double";
  c11_info[27].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c11_info[27].fileLength = 566U;
  c11_info[27].fileTime1 = 1221267134U;
  c11_info[27].fileTime2 = 0U;
  c11_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c11_info[28].name = "ischar";
  c11_info[28].dominantType = "double";
  c11_info[28].resolved = "[B]ischar";
  c11_info[28].fileLength = 0U;
  c11_info[28].fileTime1 = 0U;
  c11_info[28].fileTime2 = 0U;
  c11_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c11_info[29].name = "islogical";
  c11_info[29].dominantType = "double";
  c11_info[29].resolved = "[B]islogical";
  c11_info[29].fileLength = 0U;
  c11_info[29].fileTime1 = 0U;
  c11_info[29].fileTime2 = 0U;
  c11_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c11_info[30].name = "eml_scalar_abs";
  c11_info[30].dominantType = "double";
  c11_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c11_info[30].fileLength = 461U;
  c11_info[30].fileTime1 = 1203447960U;
  c11_info[30].fileTime2 = 0U;
  c11_info[31].context = "";
  c11_info[31].name = "sign";
  c11_info[31].dominantType = "double";
  c11_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c11_info[31].fileLength = 408U;
  c11_info[31].fileTime1 = 1203448042U;
  c11_info[31].fileTime2 = 0U;
  c11_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c11_info[32].name = "eml_scalar_sign";
  c11_info[32].dominantType = "double";
  c11_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c11_info[32].fileLength = 543U;
  c11_info[32].fileTime1 = 1203448012U;
  c11_info[32].fileTime2 = 0U;
  c11_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c11_info[33].name = "isnan";
  c11_info[33].dominantType = "double";
  c11_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c11_info[33].fileLength = 506U;
  c11_info[33].fileTime1 = 1228093810U;
  c11_info[33].fileTime2 = 0U;
  c11_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c11_info[34].name = "eml_guarded_nan";
  c11_info[34].dominantType = "char";
  c11_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c11_info[34].fileLength = 485U;
  c11_info[34].fileTime1 = 1192466780U;
  c11_info[34].fileTime2 = 0U;
  c11_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c11_info[35].name = "eml_is_float_class";
  c11_info[35].dominantType = "char";
  c11_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c11_info[35].fileLength = 226U;
  c11_info[35].fileTime1 = 1197850442U;
  c11_info[35].fileTime2 = 0U;
  c11_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c11_info[36].name = "nan";
  c11_info[36].dominantType = "char";
  c11_info[36].resolved = "[B]nan";
  c11_info[36].fileLength = 0U;
  c11_info[36].fileTime1 = 0U;
  c11_info[36].fileTime2 = 0U;
  c11_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c11_info[37].name = "ones";
  c11_info[37].dominantType = "char";
  c11_info[37].resolved = "[B]ones";
  c11_info[37].fileLength = 0U;
  c11_info[37].fileTime1 = 0U;
  c11_info[37].fileTime2 = 0U;
  c11_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c11_info[38].name = "lt";
  c11_info[38].dominantType = "double";
  c11_info[38].resolved = "[B]lt";
  c11_info[38].fileLength = 0U;
  c11_info[38].fileTime1 = 0U;
  c11_info[38].fileTime2 = 0U;
}

static const mxArray *c11_d_sf_marshall(void *c11_chartInstance, void *c11_u)
{
  const mxArray *c11_y = NULL;
  boolean_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  c11_y = NULL;
  c11_b_u = *((boolean_T *)c11_u);
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3589022600U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2686285279U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3145686616U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1534675130U);
}

mxArray
  *sf_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2994968445U);
    pr[1] = (double)(4240767585U);
    pr[2] = (double)(1114357088U);
    pr[3] = (double)(273018851U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray
  *sf_get_sim_state_info_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"out\",},{M[8],M[0],T\"is_active_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(&mxChecksum);
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
           11,
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
            dimVector[0]= 12;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"vec",0,(MexFcnForType)c11_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"out",0,(MexFcnForType)c11_b_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1813);
        _SFD_CV_INIT_EML_IF(0,0,1145,1166,-1,1202);
        _SFD_CV_INIT_EML_IF(0,1,1625,1646,-1,1682);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c11_vec)[12];
          real_T (*c11_out)[7];
          c11_vec = (real_T (*)[12])ssGetInputPortSignal(chartInstance.S, 0);
          c11_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c11_vec);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  initialize_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_enable_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  enable_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_disable_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  disable_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_gateway_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  sf_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void
  sf_opaque_ext_mode_exec_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  ext_mode_exec_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static mxArray*
  sf_opaque_get_sim_state_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  return st;
}

static void
  sf_opaque_set_sim_state_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(sf_mex_dup(st));
}

static void sf_opaque_terminate_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",11,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",11,1);
      sf_mark_chart_reusable_outputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",11,1);
    }

    sf_set_rtw_dwork_info(S,"M37_Sim_Forcing_003h_expe_infra_transz_lim",
                          "M37_Sim_Forcing_003h_expe_infra_transz_lim",11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(2784526543U));
  ssSetChecksum1(S,(3620225313U));
  ssSetChecksum2(S,(3486860938U));
  ssSetChecksum3(S,(2680768486U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",11);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim;
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

void c11_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(SimStruct *
  S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

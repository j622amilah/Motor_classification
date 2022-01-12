/* Include files */

#include "blascompat32.h"
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun.h"
#include "c6_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c6_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc6_M37_Sim_Forcing_003h_expe_infra_transz_limInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void initialize_params_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void enable_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void disable_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c6_update_debugger_state_c6_M37_Sim_Forcing_003h_expe_infra_tra(void);
static void ext_mode_exec_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static const mxArray
  *get_sim_state_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void set_sim_state_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c6_st);
static void finalize_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void sf_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static void c6_eml_warning(void);
static const mxArray *c6_sf_marshall(void *c6_chartInstance, void *c6_u);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[29]);
static const mxArray *c6_b_sf_marshall(void *c6_chartInstance, void *c6_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  uint8_T *c6_is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c6_is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c6_is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim = 0U;
}

static void initialize_params_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void enable_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c6_update_debugger_state_c6_M37_Sim_Forcing_003h_expe_infra_tra(void)
{
}

static void ext_mode_exec_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  c6_update_debugger_state_c6_M37_Sim_Forcing_003h_expe_infra_tra();
}

static const mxArray
  *get_sim_state_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const mxArray *c6_st = NULL;
  const mxArray *c6_y = NULL;
  real_T c6_u;
  const mxArray *c6_b_y = NULL;
  real_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  uint8_T c6_c_u;
  const mxArray *c6_d_y = NULL;
  real_T *c6_gain;
  real_T *c6_e_y;
  uint8_T *c6_is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c6_e_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c6_gain = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c6_is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(3));
  c6_u = *c6_gain;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_u = *c6_e_y;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_c_u = *c6_is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 2, c6_d_y);
  sf_mex_assign(&c6_st, c6_y);
  return c6_st;
}

static void set_sim_state_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c6_st)
{
  const mxArray *c6_u;
  const mxArray *c6_gain;
  real_T c6_d0;
  real_T c6_y;
  const mxArray *c6_b_gain;
  real_T c6_d1;
  real_T c6_b_y;
  const mxArray *c6_is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  uint8_T c6_u0;
  uint8_T c6_c_y;
  boolean_T *c6_doneDoubleBufferReInit;
  real_T *c6_c_gain;
  real_T *c6_d_y;
  uint8_T *c6_b_is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c6_d_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c6_c_gain = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c6_b_is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c6_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  *c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  c6_gain = sf_mex_dup(sf_mex_getcell(c6_u, 0));
  sf_mex_import("gain", sf_mex_dup(c6_gain), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_gain);
  *c6_c_gain = c6_y;
  c6_b_gain = sf_mex_dup(sf_mex_getcell(c6_u, 1));
  sf_mex_import("y", sf_mex_dup(c6_b_gain), &c6_d1, 1, 0, 0U, 0, 0U, 0);
  c6_b_y = c6_d1;
  sf_mex_destroy(&c6_b_gain);
  *c6_d_y = c6_b_y;
  c6_is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim = sf_mex_dup
    (sf_mex_getcell(c6_u, 2));
  sf_mex_import("is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim",
                sf_mex_dup(
    c6_is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim), &c6_u0, 1, 3,
                0U, 0, 0U, 0);
  c6_c_y = c6_u0;
  sf_mex_destroy(&c6_is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim);
  *c6_b_is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim = c6_c_y;
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_M37_Sim_Forcing_003h_expe_infra_tra();
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void sf_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c6_previousEvent;
  real_T c6_x;
  real_T c6_x_max;
  real_T c6_x_min;
  real_T c6_margin_max;
  real_T c6_margin_min;
  real_T c6_y_in;
  real_T c6_nargout = 2.0;
  real_T c6_nargin = 6.0;
  real_T c6_x1;
  real_T c6_gain;
  real_T c6_y;
  real_T c6_a;
  real_T c6_A;
  real_T c6_B;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_c_x;
  real_T c6_c_y;
  real_T c6_d_x;
  real_T c6_d_y;
  real_T c6_b_a;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_e_y;
  real_T c6_b_A;
  real_T c6_b_B;
  real_T c6_g_x;
  real_T c6_f_y;
  real_T c6_h_x;
  real_T c6_g_y;
  real_T c6_i_x;
  real_T c6_h_y;
  real_T c6_j_x;
  real_T c6_b;
  real_T c6_k_x;
  real_T c6_i_y;
  real_T c6_b_b;
  real_T c6_l_x;
  real_T c6_m_x;
  real_T c6_j_y;
  real_T c6_c_A;
  real_T c6_c_B;
  real_T c6_n_x;
  real_T c6_k_y;
  real_T c6_o_x;
  real_T c6_l_y;
  real_T c6_p_x;
  real_T c6_m_y;
  real_T c6_q_x;
  real_T c6_r_x;
  real_T c6_c_a;
  real_T c6_d_A;
  real_T c6_d_B;
  real_T c6_s_x;
  real_T c6_n_y;
  real_T c6_t_x;
  real_T c6_o_y;
  real_T c6_u_x;
  real_T c6_p_y;
  real_T c6_d_a;
  real_T c6_v_x;
  real_T c6_w_x;
  real_T c6_q_y;
  real_T c6_e_A;
  real_T c6_e_B;
  real_T c6_x_x;
  real_T c6_r_y;
  real_T c6_y_x;
  real_T c6_s_y;
  real_T c6_ab_x;
  real_T c6_t_y;
  real_T c6_bb_x;
  real_T c6_c_b;
  real_T c6_cb_x;
  real_T c6_u_y;
  real_T c6_d_b;
  real_T c6_db_x;
  real_T c6_eb_x;
  real_T c6_v_y;
  real_T c6_f_A;
  real_T c6_f_B;
  real_T c6_fb_x;
  real_T c6_w_y;
  real_T c6_gb_x;
  real_T c6_x_y;
  real_T c6_hb_x;
  real_T c6_y_y;
  real_T c6_ib_x;
  real_T c6_jb_x;
  real_T *c6_kb_x;
  real_T *c6_ab_y;
  real_T *c6_b_x_max;
  real_T *c6_b_x_min;
  real_T *c6_b_margin_max;
  real_T *c6_b_margin_min;
  real_T *c6_b_y_in;
  real_T *c6_b_gain;
  c6_ab_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c6_b_x_max = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c6_b_gain = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c6_b_margin_max = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c6_kb_x = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c6_b_x_min = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c6_b_y_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c6_b_margin_min = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,5);
  _SFD_DATA_RANGE_CHECK(*c6_kb_x, 0U);
  _SFD_DATA_RANGE_CHECK(*c6_ab_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c6_b_x_max, 2U);
  _SFD_DATA_RANGE_CHECK(*c6_b_x_min, 3U);
  _SFD_DATA_RANGE_CHECK(*c6_b_margin_max, 4U);
  _SFD_DATA_RANGE_CHECK(*c6_b_margin_min, 5U);
  _SFD_DATA_RANGE_CHECK(*c6_b_y_in, 6U);
  _SFD_DATA_RANGE_CHECK(*c6_b_gain, 7U);
  c6_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,5);
  c6_x = *c6_kb_x;
  c6_x_max = *c6_b_x_max;
  c6_x_min = *c6_b_x_min;
  c6_margin_max = *c6_b_margin_max;
  c6_margin_min = *c6_b_margin_min;
  c6_y_in = *c6_b_y_in;
  sf_debug_symbol_scope_push(11U, 0U);
  sf_debug_symbol_scope_add("nargout", &c6_nargout, c6_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c6_nargin, c6_sf_marshall);
  sf_debug_symbol_scope_add("x1", &c6_x1, c6_sf_marshall);
  sf_debug_symbol_scope_add("gain", &c6_gain, c6_sf_marshall);
  sf_debug_symbol_scope_add("y", &c6_y, c6_sf_marshall);
  sf_debug_symbol_scope_add("y_in", &c6_y_in, c6_sf_marshall);
  sf_debug_symbol_scope_add("margin_min", &c6_margin_min, c6_sf_marshall);
  sf_debug_symbol_scope_add("margin_max", &c6_margin_max, c6_sf_marshall);
  sf_debug_symbol_scope_add("x_min", &c6_x_min, c6_sf_marshall);
  sf_debug_symbol_scope_add("x_max", &c6_x_max, c6_sf_marshall);
  sf_debug_symbol_scope_add("x", &c6_x, c6_sf_marshall);
  CV_EML_FCN(0, 0);

  /* -------------------------------------------------------------------------- */
  /*  */
  /*    argin_max and margin_min are the margins in which the exponetial */
  /*    saturation takes place */
  /*  */
  /*    x_max, x_min and margin_max and margin_min allow to compute the */
  /*    factor between 0 and 1 of x_max and x_min of the linear range */
  /*  */
  /*    Please note that x_max and x_min, margin_max and margin_min, are */
  /*    all positive values; where the max is for the positive values of x and  */
  /*    the min for the negative values */
  /*  */
  /* -------------------------------------------------------------------------- */
  /*      */
  /*      if x < x_max - margin_max && x >= 0 */
  /*          y = x; */
  /*      elseif x > -x_min + margin_min && x < 0 */
  /*          y = x; */
  /*      elseif x >= x_max - margin_max */
  /*          x1 = (x - x_max + margin_max); */
  /*          y = x_max*(1 -  margin_max/x_max*exp(-abs(x1)/margin_max)); */
  /*      else */
  /*          x1 = (x + x_min - margin_min); */
  /*          y = -x_min*(1 -  margin_min/x_min*exp(-abs(x1)/margin_min)); */
  /*      end */
  _SFD_EML_CALL(0,28);
  if (CV_EML_COND(0, 0, c6_x < c6_x_max - c6_margin_max)) {
    if (CV_EML_COND(0, 1, c6_x >= 0.0)) {
      CV_EML_MCDC(0, 0, true);
      CV_EML_IF(0, 0, true);
      _SFD_EML_CALL(0,29);
      c6_y = c6_x;
      _SFD_EML_CALL(0,30);
      c6_gain = 1.0;
      goto label_1;
    }
  }

  CV_EML_MCDC(0, 0, false);
  CV_EML_IF(0, 0, false);
  _SFD_EML_CALL(0,31);
  if (CV_EML_COND(0, 2, c6_x > (-c6_x_min) + c6_margin_min)) {
    if (CV_EML_COND(0, 3, c6_x < 0.0)) {
      CV_EML_MCDC(0, 1, true);
      CV_EML_IF(0, 1, true);
      _SFD_EML_CALL(0,32);
      c6_y = c6_x;
      _SFD_EML_CALL(0,33);
      c6_gain = 1.0;
      goto label_2;
    }
  }

  CV_EML_MCDC(0, 1, false);
  CV_EML_IF(0, 1, false);
  _SFD_EML_CALL(0,34);
  if (CV_EML_IF(0, 2, c6_x >= c6_x_max - c6_margin_max)) {
    _SFD_EML_CALL(0,35);
    c6_x1 = (c6_x - c6_x_max) + c6_margin_max;
    _SFD_EML_CALL(0,36);
    c6_a = c6_x_max;
    c6_A = c6_margin_max;
    c6_B = c6_x_max;
    c6_b_x = c6_A;
    c6_b_y = c6_B;
    if (c6_b_y == 0.0) {
      c6_eml_warning();
    }

    c6_c_x = c6_b_x;
    c6_c_y = c6_b_y;
    c6_d_x = c6_c_x;
    c6_d_y = c6_c_y;
    c6_b_a = c6_d_x / c6_d_y;
    c6_e_x = c6_x1;
    c6_f_x = c6_e_x;
    c6_e_y = muDoubleScalarAbs(c6_f_x);
    c6_b_A = -c6_e_y;
    c6_b_B = c6_margin_max;
    c6_g_x = c6_b_A;
    c6_f_y = c6_b_B;
    if (c6_f_y == 0.0) {
      c6_eml_warning();
    }

    c6_h_x = c6_g_x;
    c6_g_y = c6_f_y;
    c6_i_x = c6_h_x;
    c6_h_y = c6_g_y;
    c6_j_x = c6_i_x / c6_h_y;
    c6_b = c6_j_x;
    c6_k_x = c6_b;
    c6_b = c6_k_x;
    c6_b = muDoubleScalarExp(c6_b);
    c6_i_y = c6_b_a * c6_b;
    c6_b_b = 1.0 - c6_i_y;
    c6_y = c6_a * c6_b_b;
    _SFD_EML_CALL(0,37);
    c6_l_x = c6_x1;
    c6_m_x = c6_l_x;
    c6_j_y = muDoubleScalarAbs(c6_m_x);
    c6_c_A = -c6_j_y;
    c6_c_B = c6_margin_max;
    c6_n_x = c6_c_A;
    c6_k_y = c6_c_B;
    if (c6_k_y == 0.0) {
      c6_eml_warning();
    }

    c6_o_x = c6_n_x;
    c6_l_y = c6_k_y;
    c6_p_x = c6_o_x;
    c6_m_y = c6_l_y;
    c6_q_x = c6_p_x / c6_m_y;
    c6_gain = c6_q_x;
    c6_r_x = c6_gain;
    c6_gain = c6_r_x;
    c6_gain = muDoubleScalarExp(c6_gain);
  } else {
    _SFD_EML_CALL(0,40);
    c6_x1 = (c6_x + c6_x_min) - c6_margin_min;
    _SFD_EML_CALL(0,41);
    c6_c_a = -c6_x_min;
    c6_d_A = c6_margin_min;
    c6_d_B = c6_x_min;
    c6_s_x = c6_d_A;
    c6_n_y = c6_d_B;
    if (c6_n_y == 0.0) {
      c6_eml_warning();
    }

    c6_t_x = c6_s_x;
    c6_o_y = c6_n_y;
    c6_u_x = c6_t_x;
    c6_p_y = c6_o_y;
    c6_d_a = c6_u_x / c6_p_y;
    c6_v_x = c6_x1;
    c6_w_x = c6_v_x;
    c6_q_y = muDoubleScalarAbs(c6_w_x);
    c6_e_A = -c6_q_y;
    c6_e_B = c6_margin_min;
    c6_x_x = c6_e_A;
    c6_r_y = c6_e_B;
    if (c6_r_y == 0.0) {
      c6_eml_warning();
    }

    c6_y_x = c6_x_x;
    c6_s_y = c6_r_y;
    c6_ab_x = c6_y_x;
    c6_t_y = c6_s_y;
    c6_bb_x = c6_ab_x / c6_t_y;
    c6_c_b = c6_bb_x;
    c6_cb_x = c6_c_b;
    c6_c_b = c6_cb_x;
    c6_c_b = muDoubleScalarExp(c6_c_b);
    c6_u_y = c6_d_a * c6_c_b;
    c6_d_b = 1.0 - c6_u_y;
    c6_y = c6_c_a * c6_d_b;
    _SFD_EML_CALL(0,42);
    c6_db_x = c6_x1;
    c6_eb_x = c6_db_x;
    c6_v_y = muDoubleScalarAbs(c6_eb_x);
    c6_f_A = -c6_v_y;
    c6_f_B = c6_margin_max;
    c6_fb_x = c6_f_A;
    c6_w_y = c6_f_B;
    if (c6_w_y == 0.0) {
      c6_eml_warning();
    }

    c6_gb_x = c6_fb_x;
    c6_x_y = c6_w_y;
    c6_hb_x = c6_gb_x;
    c6_y_y = c6_x_y;
    c6_ib_x = c6_hb_x / c6_y_y;
    c6_gain = c6_ib_x;
    c6_jb_x = c6_gain;
    c6_gain = c6_jb_x;
    c6_gain = muDoubleScalarExp(c6_gain);
  }

 label_2:
  ;
 label_1:
  ;
  _SFD_EML_CALL(0,-42);
  sf_debug_symbol_scope_pop();
  *c6_ab_y = c6_y;
  *c6_b_gain = c6_gain;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
  _sfEvent_ = c6_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static void c6_eml_warning(void)
{
  int32_T c6_i0;
  static char_T c6_cv0[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c6_u[15];
  const mxArray *c6_y = NULL;
  int32_T c6_i1;
  static char_T c6_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c6_b_u[19];
  const mxArray *c6_b_y = NULL;
  for (c6_i0 = 0; c6_i0 < 15; c6_i0 = c6_i0 + 1) {
    c6_u[c6_i0] = c6_cv0[c6_i0];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c6_i1 = 0; c6_i1 < 19; c6_i1 = c6_i1 + 1) {
    c6_b_u[c6_i1] = c6_cv1[c6_i1];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c6_b_y, 14, c6_y);
}

static const mxArray *c6_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  real_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  c6_b_u = *((real_T *)c6_u);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

const mxArray
  *sf_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_ResolvedFunctionInfo c6_info[29];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i2;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 29));
  for (c6_i2 = 0; c6_i2 < 29; c6_i2 = c6_i2 + 1) {
    c6_r0 = &c6_info[c6_i2];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context",
                    "nameCaptureInfo", c6_i2);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name",
                    "nameCaptureInfo", c6_i2);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c6_i2);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c6_i2);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c6_i2);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c6_i2);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c6_i2);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[29])
{
  c6_info[0].context = "";
  c6_info[0].name = "minus";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved = "[B]minus";
  c6_info[0].fileLength = 0U;
  c6_info[0].fileTime1 = 0U;
  c6_info[0].fileTime2 = 0U;
  c6_info[1].context = "";
  c6_info[1].name = "lt";
  c6_info[1].dominantType = "double";
  c6_info[1].resolved = "[B]lt";
  c6_info[1].fileLength = 0U;
  c6_info[1].fileTime1 = 0U;
  c6_info[1].fileTime2 = 0U;
  c6_info[2].context = "";
  c6_info[2].name = "ge";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved = "[B]ge";
  c6_info[2].fileLength = 0U;
  c6_info[2].fileTime1 = 0U;
  c6_info[2].fileTime2 = 0U;
  c6_info[3].context = "";
  c6_info[3].name = "uminus";
  c6_info[3].dominantType = "double";
  c6_info[3].resolved = "[B]uminus";
  c6_info[3].fileLength = 0U;
  c6_info[3].fileTime1 = 0U;
  c6_info[3].fileTime2 = 0U;
  c6_info[4].context = "";
  c6_info[4].name = "plus";
  c6_info[4].dominantType = "double";
  c6_info[4].resolved = "[B]plus";
  c6_info[4].fileLength = 0U;
  c6_info[4].fileTime1 = 0U;
  c6_info[4].fileTime2 = 0U;
  c6_info[5].context = "";
  c6_info[5].name = "gt";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved = "[B]gt";
  c6_info[5].fileLength = 0U;
  c6_info[5].fileTime1 = 0U;
  c6_info[5].fileTime2 = 0U;
  c6_info[6].context = "";
  c6_info[6].name = "mrdivide";
  c6_info[6].dominantType = "double";
  c6_info[6].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[6].fileLength = 800U;
  c6_info[6].fileTime1 = 1238434292U;
  c6_info[6].fileTime2 = 0U;
  c6_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[7].name = "nargin";
  c6_info[7].dominantType = "";
  c6_info[7].resolved = "[B]nargin";
  c6_info[7].fileLength = 0U;
  c6_info[7].fileTime1 = 0U;
  c6_info[7].fileTime2 = 0U;
  c6_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[8].name = "isscalar";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved = "[B]isscalar";
  c6_info[8].fileLength = 0U;
  c6_info[8].fileTime1 = 0U;
  c6_info[8].fileTime2 = 0U;
  c6_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[9].name = "rdivide";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[9].fileLength = 620U;
  c6_info[9].fileTime1 = 1213926766U;
  c6_info[9].fileTime2 = 0U;
  c6_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[10].name = "isa";
  c6_info[10].dominantType = "double";
  c6_info[10].resolved = "[B]isa";
  c6_info[10].fileLength = 0U;
  c6_info[10].fileTime1 = 0U;
  c6_info[10].fileTime2 = 0U;
  c6_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[11].name = "isempty";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved = "[B]isempty";
  c6_info[11].fileLength = 0U;
  c6_info[11].fileTime1 = 0U;
  c6_info[11].fileTime2 = 0U;
  c6_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[12].name = "not";
  c6_info[12].dominantType = "logical";
  c6_info[12].resolved = "[B]not";
  c6_info[12].fileLength = 0U;
  c6_info[12].fileTime1 = 0U;
  c6_info[12].fileTime2 = 0U;
  c6_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[13].name = "strcmp";
  c6_info[13].dominantType = "char";
  c6_info[13].resolved = "[B]strcmp";
  c6_info[13].fileLength = 0U;
  c6_info[13].fileTime1 = 0U;
  c6_info[13].fileTime2 = 0U;
  c6_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[14].name = "eq";
  c6_info[14].dominantType = "double";
  c6_info[14].resolved = "[B]eq";
  c6_info[14].fileLength = 0U;
  c6_info[14].fileTime1 = 0U;
  c6_info[14].fileTime2 = 0U;
  c6_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[15].name = "eml_warning";
  c6_info[15].dominantType = "char";
  c6_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c6_info[15].fileLength = 262U;
  c6_info[15].fileTime1 = 1236257278U;
  c6_info[15].fileTime2 = 0U;
  c6_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[16].name = "eml_div";
  c6_info[16].dominantType = "double";
  c6_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[16].fileLength = 4269U;
  c6_info[16].fileTime1 = 1228093826U;
  c6_info[16].fileTime2 = 0U;
  c6_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[17].name = "isinteger";
  c6_info[17].dominantType = "double";
  c6_info[17].resolved = "[B]isinteger";
  c6_info[17].fileLength = 0U;
  c6_info[17].fileTime1 = 0U;
  c6_info[17].fileTime2 = 0U;
  c6_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c6_info[18].name = "isreal";
  c6_info[18].dominantType = "double";
  c6_info[18].resolved = "[B]isreal";
  c6_info[18].fileLength = 0U;
  c6_info[18].fileTime1 = 0U;
  c6_info[18].fileTime2 = 0U;
  c6_info[19].context = "";
  c6_info[19].name = "abs";
  c6_info[19].dominantType = "double";
  c6_info[19].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[19].fileLength = 566U;
  c6_info[19].fileTime1 = 1221267134U;
  c6_info[19].fileTime2 = 0U;
  c6_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[20].name = "ischar";
  c6_info[20].dominantType = "double";
  c6_info[20].resolved = "[B]ischar";
  c6_info[20].fileLength = 0U;
  c6_info[20].fileTime1 = 0U;
  c6_info[20].fileTime2 = 0U;
  c6_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[21].name = "islogical";
  c6_info[21].dominantType = "double";
  c6_info[21].resolved = "[B]islogical";
  c6_info[21].fileLength = 0U;
  c6_info[21].fileTime1 = 0U;
  c6_info[21].fileTime2 = 0U;
  c6_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[22].name = "size";
  c6_info[22].dominantType = "double";
  c6_info[22].resolved = "[B]size";
  c6_info[22].fileLength = 0U;
  c6_info[22].fileTime1 = 0U;
  c6_info[22].fileTime2 = 0U;
  c6_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[23].name = "class";
  c6_info[23].dominantType = "double";
  c6_info[23].resolved = "[B]class";
  c6_info[23].fileLength = 0U;
  c6_info[23].fileTime1 = 0U;
  c6_info[23].fileTime2 = 0U;
  c6_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[24].name = "zeros";
  c6_info[24].dominantType = "double";
  c6_info[24].resolved = "[B]zeros";
  c6_info[24].fileLength = 0U;
  c6_info[24].fileTime1 = 0U;
  c6_info[24].fileTime2 = 0U;
  c6_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[25].name = "eml_scalar_abs";
  c6_info[25].dominantType = "double";
  c6_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[25].fileLength = 461U;
  c6_info[25].fileTime1 = 1203447960U;
  c6_info[25].fileTime2 = 0U;
  c6_info[26].context = "";
  c6_info[26].name = "exp";
  c6_info[26].dominantType = "double";
  c6_info[26].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c6_info[26].fileLength = 324U;
  c6_info[26].fileTime1 = 1240261974U;
  c6_info[26].fileTime2 = 0U;
  c6_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c6_info[27].name = "eml_scalar_exp";
  c6_info[27].dominantType = "double";
  c6_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c6_info[27].fileLength = 243U;
  c6_info[27].fileTime1 = 1240261972U;
  c6_info[27].fileTime2 = 0U;
  c6_info[28].context = "";
  c6_info[28].name = "mtimes";
  c6_info[28].dominantType = "double";
  c6_info[28].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[28].fileLength = 3302U;
  c6_info[28].fileTime1 = 1242750894U;
  c6_info[28].fileTime2 = 0U;
}

static const mxArray *c6_b_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  boolean_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  c6_b_u = *((boolean_T *)c6_u);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1524788688U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(143319282U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3317827461U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(601035745U);
}

mxArray
  *sf_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2306129500U);
    pr[1] = (double)(2846102984U);
    pr[2] = (double)(2417928835U);
    pr[3] = (double)(1186086770U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray
  *sf_get_sim_state_info_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[11],T\"gain\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(&mxChecksum);
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
           6,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"x",0,
                              (MexFcnForType)c6_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y",0,
                              (MexFcnForType)c6_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"x_max",0,
                              (MexFcnForType)c6_sf_marshall);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"x_min",0,
                              (MexFcnForType)c6_sf_marshall);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "margin_max",0,(MexFcnForType)c6_sf_marshall);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "margin_min",0,(MexFcnForType)c6_sf_marshall);
          _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y_in",0,
                              (MexFcnForType)c6_sf_marshall);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"gain",0,
                              (MexFcnForType)c6_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,3,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1562);
        _SFD_CV_INIT_EML_IF(0,0,1069,1104,1140,1557);
        _SFD_CV_INIT_EML_IF(0,1,1140,1179,1215,1557);
        _SFD_CV_INIT_EML_IF(0,2,1215,1245,1397,1557);

        {
          static int condStart[] = { 1072, 1098 };

          static int condEnd[] = { 1094, 1104 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,1072,1104,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1147, 1174 };

          static int condEnd[] = { 1170, 1179 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1147,1179,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
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
          real_T *c6_x;
          real_T *c6_y;
          real_T *c6_x_max;
          real_T *c6_x_min;
          real_T *c6_margin_max;
          real_T *c6_margin_min;
          real_T *c6_y_in;
          real_T *c6_gain;
          c6_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c6_x_max = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c6_gain = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c6_margin_max = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c6_x = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c6_x_min = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c6_y_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
          c6_margin_min = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_x_max);
          _SFD_SET_DATA_VALUE_PTR(3U, c6_x_min);
          _SFD_SET_DATA_VALUE_PTR(4U, c6_margin_max);
          _SFD_SET_DATA_VALUE_PTR(5U, c6_margin_min);
          _SFD_SET_DATA_VALUE_PTR(6U, c6_y_in);
          _SFD_SET_DATA_VALUE_PTR(7U, c6_gain);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  initialize_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_enable_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void *
  chartInstanceVar)
{
  enable_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_disable_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  disable_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_gateway_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  sf_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void
  sf_opaque_ext_mode_exec_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  ext_mode_exec_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static mxArray*
  sf_opaque_get_sim_state_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  return st;
}

static void
  sf_opaque_set_sim_state_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(sf_mex_dup(st));
}

static void sf_opaque_terminate_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",6,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",6,6);
      sf_mark_chart_reusable_outputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",6,2);
    }

    sf_set_rtw_dwork_info(S,"M37_Sim_Forcing_003h_expe_infra_transz_lim",
                          "M37_Sim_Forcing_003h_expe_infra_transz_lim",6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1344982601U));
  ssSetChecksum1(S,(1764120418U));
  ssSetChecksum2(S,(1004285528U));
  ssSetChecksum3(S,(2327051646U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",6);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim;
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

void c6_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

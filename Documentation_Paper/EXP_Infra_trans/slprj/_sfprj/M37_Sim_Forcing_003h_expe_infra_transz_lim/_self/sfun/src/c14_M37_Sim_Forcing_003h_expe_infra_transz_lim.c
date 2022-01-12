/* Include files */

#include "blascompat32.h"
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun.h"
#include "c14_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c14_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc14_M37_Sim_Forcing_003h_expe_infra_transz_limInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void initialize_params_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void);
static void enable_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void disable_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c14_update_debugger_state_c14_M37_Sim_Forcing_003h_expe_infra_t(void);
static void ext_mode_exec_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static const mxArray
  *get_sim_state_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void set_sim_state_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c14_st);
static void finalize_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void sf_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber);
static void c14_eml_warning(void);
static const mxArray *c14_sf_marshall(void *c14_chartInstance, void *c14_u);
static void c14_info_helper(c14_ResolvedFunctionInfo c14_info[29]);
static const mxArray *c14_b_sf_marshall(void *c14_chartInstance, void *c14_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  uint8_T *c14_is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c14_is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c14_is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim = 0U;
}

static void initialize_params_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void)
{
}

static void enable_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c14_update_debugger_state_c14_M37_Sim_Forcing_003h_expe_infra_t(void)
{
}

static void ext_mode_exec_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  c14_update_debugger_state_c14_M37_Sim_Forcing_003h_expe_infra_t();
}

static const mxArray
  *get_sim_state_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const mxArray *c14_st = NULL;
  const mxArray *c14_y = NULL;
  real_T c14_u;
  const mxArray *c14_b_y = NULL;
  real_T c14_b_u;
  const mxArray *c14_c_y = NULL;
  uint8_T c14_c_u;
  const mxArray *c14_d_y = NULL;
  real_T *c14_gain;
  real_T *c14_e_y;
  uint8_T *c14_is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c14_is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c14_e_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c14_gain = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellarray(3));
  c14_u = *c14_gain;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c14_y, 0, c14_b_y);
  c14_b_u = *c14_e_y;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c14_y, 1, c14_c_y);
  c14_c_u = *c14_is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c14_y, 2, c14_d_y);
  sf_mex_assign(&c14_st, c14_y);
  return c14_st;
}

static void set_sim_state_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c14_st)
{
  const mxArray *c14_u;
  const mxArray *c14_gain;
  real_T c14_d0;
  real_T c14_y;
  const mxArray *c14_b_gain;
  real_T c14_d1;
  real_T c14_b_y;
  const mxArray *c14_is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  uint8_T c14_u0;
  uint8_T c14_c_y;
  boolean_T *c14_doneDoubleBufferReInit;
  real_T *c14_c_gain;
  real_T *c14_d_y;
  uint8_T *c14_b_is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c14_b_is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c14_d_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c14_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c14_c_gain = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  *c14_doneDoubleBufferReInit = true;
  c14_u = sf_mex_dup(c14_st);
  c14_gain = sf_mex_dup(sf_mex_getcell(c14_u, 0));
  sf_mex_import("gain", sf_mex_dup(c14_gain), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d0;
  sf_mex_destroy(&c14_gain);
  *c14_c_gain = c14_y;
  c14_b_gain = sf_mex_dup(sf_mex_getcell(c14_u, 1));
  sf_mex_import("y", sf_mex_dup(c14_b_gain), &c14_d1, 1, 0, 0U, 0, 0U, 0);
  c14_b_y = c14_d1;
  sf_mex_destroy(&c14_b_gain);
  *c14_d_y = c14_b_y;
  c14_is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim = sf_mex_dup
    (sf_mex_getcell(c14_u, 2));
  sf_mex_import("is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim",
                sf_mex_dup(
    c14_is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim), &c14_u0, 1, 3,
                0U, 0, 0U, 0);
  c14_c_y = c14_u0;
  sf_mex_destroy(&c14_is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim);
  *c14_b_is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim = c14_c_y;
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_M37_Sim_Forcing_003h_expe_infra_t();
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void sf_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c14_previousEvent;
  real_T c14_x;
  real_T c14_x_max;
  real_T c14_x_min;
  real_T c14_margin_max;
  real_T c14_margin_min;
  real_T c14_y_in;
  real_T c14_nargout = 2.0;
  real_T c14_nargin = 6.0;
  real_T c14_x1;
  real_T c14_gain;
  real_T c14_y;
  real_T c14_a;
  real_T c14_A;
  real_T c14_B;
  real_T c14_b_x;
  real_T c14_b_y;
  real_T c14_c_x;
  real_T c14_c_y;
  real_T c14_d_x;
  real_T c14_d_y;
  real_T c14_b_a;
  real_T c14_e_x;
  real_T c14_f_x;
  real_T c14_e_y;
  real_T c14_b_A;
  real_T c14_b_B;
  real_T c14_g_x;
  real_T c14_f_y;
  real_T c14_h_x;
  real_T c14_g_y;
  real_T c14_i_x;
  real_T c14_h_y;
  real_T c14_j_x;
  real_T c14_b;
  real_T c14_k_x;
  real_T c14_i_y;
  real_T c14_b_b;
  real_T c14_l_x;
  real_T c14_m_x;
  real_T c14_j_y;
  real_T c14_c_A;
  real_T c14_c_B;
  real_T c14_n_x;
  real_T c14_k_y;
  real_T c14_o_x;
  real_T c14_l_y;
  real_T c14_p_x;
  real_T c14_m_y;
  real_T c14_q_x;
  real_T c14_r_x;
  real_T c14_c_a;
  real_T c14_d_A;
  real_T c14_d_B;
  real_T c14_s_x;
  real_T c14_n_y;
  real_T c14_t_x;
  real_T c14_o_y;
  real_T c14_u_x;
  real_T c14_p_y;
  real_T c14_d_a;
  real_T c14_v_x;
  real_T c14_w_x;
  real_T c14_q_y;
  real_T c14_e_A;
  real_T c14_e_B;
  real_T c14_x_x;
  real_T c14_r_y;
  real_T c14_y_x;
  real_T c14_s_y;
  real_T c14_ab_x;
  real_T c14_t_y;
  real_T c14_bb_x;
  real_T c14_c_b;
  real_T c14_cb_x;
  real_T c14_u_y;
  real_T c14_d_b;
  real_T c14_db_x;
  real_T c14_eb_x;
  real_T c14_v_y;
  real_T c14_f_A;
  real_T c14_f_B;
  real_T c14_fb_x;
  real_T c14_w_y;
  real_T c14_gb_x;
  real_T c14_x_y;
  real_T c14_hb_x;
  real_T c14_y_y;
  real_T c14_ib_x;
  real_T c14_jb_x;
  real_T *c14_kb_x;
  real_T *c14_ab_y;
  real_T *c14_b_x_max;
  real_T *c14_b_x_min;
  real_T *c14_b_margin_max;
  real_T *c14_b_margin_min;
  real_T *c14_b_y_in;
  real_T *c14_b_gain;
  c14_b_y_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c14_ab_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c14_b_margin_min = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  c14_b_gain = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c14_b_x_max = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c14_kb_x = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c14_b_x_min = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c14_b_margin_max = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,13);
  _SFD_DATA_RANGE_CHECK(*c14_kb_x, 0U);
  _SFD_DATA_RANGE_CHECK(*c14_ab_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c14_b_x_max, 2U);
  _SFD_DATA_RANGE_CHECK(*c14_b_x_min, 3U);
  _SFD_DATA_RANGE_CHECK(*c14_b_margin_max, 4U);
  _SFD_DATA_RANGE_CHECK(*c14_b_margin_min, 5U);
  _SFD_DATA_RANGE_CHECK(*c14_b_y_in, 6U);
  _SFD_DATA_RANGE_CHECK(*c14_b_gain, 7U);
  c14_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,13);
  c14_x = *c14_kb_x;
  c14_x_max = *c14_b_x_max;
  c14_x_min = *c14_b_x_min;
  c14_margin_max = *c14_b_margin_max;
  c14_margin_min = *c14_b_margin_min;
  c14_y_in = *c14_b_y_in;
  sf_debug_symbol_scope_push(11U, 0U);
  sf_debug_symbol_scope_add("nargout", &c14_nargout, c14_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c14_nargin, c14_sf_marshall);
  sf_debug_symbol_scope_add("x1", &c14_x1, c14_sf_marshall);
  sf_debug_symbol_scope_add("gain", &c14_gain, c14_sf_marshall);
  sf_debug_symbol_scope_add("y", &c14_y, c14_sf_marshall);
  sf_debug_symbol_scope_add("y_in", &c14_y_in, c14_sf_marshall);
  sf_debug_symbol_scope_add("margin_min", &c14_margin_min, c14_sf_marshall);
  sf_debug_symbol_scope_add("margin_max", &c14_margin_max, c14_sf_marshall);
  sf_debug_symbol_scope_add("x_min", &c14_x_min, c14_sf_marshall);
  sf_debug_symbol_scope_add("x_max", &c14_x_max, c14_sf_marshall);
  sf_debug_symbol_scope_add("x", &c14_x, c14_sf_marshall);
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
  if (CV_EML_COND(0, 0, c14_x < c14_x_max - c14_margin_max)) {
    if (CV_EML_COND(0, 1, c14_x >= 0.0)) {
      CV_EML_MCDC(0, 0, true);
      CV_EML_IF(0, 0, true);
      _SFD_EML_CALL(0,29);
      c14_y = c14_x;
      _SFD_EML_CALL(0,30);
      c14_gain = 1.0;
      goto label_1;
    }
  }

  CV_EML_MCDC(0, 0, false);
  CV_EML_IF(0, 0, false);
  _SFD_EML_CALL(0,31);
  if (CV_EML_COND(0, 2, c14_x > (-c14_x_min) + c14_margin_min)) {
    if (CV_EML_COND(0, 3, c14_x < 0.0)) {
      CV_EML_MCDC(0, 1, true);
      CV_EML_IF(0, 1, true);
      _SFD_EML_CALL(0,32);
      c14_y = c14_x;
      _SFD_EML_CALL(0,33);
      c14_gain = 1.0;
      goto label_2;
    }
  }

  CV_EML_MCDC(0, 1, false);
  CV_EML_IF(0, 1, false);
  _SFD_EML_CALL(0,34);
  if (CV_EML_IF(0, 2, c14_x >= c14_x_max - c14_margin_max)) {
    _SFD_EML_CALL(0,35);
    c14_x1 = (c14_x - c14_x_max) + c14_margin_max;
    _SFD_EML_CALL(0,36);
    c14_a = c14_x_max;
    c14_A = c14_margin_max;
    c14_B = c14_x_max;
    c14_b_x = c14_A;
    c14_b_y = c14_B;
    if (c14_b_y == 0.0) {
      c14_eml_warning();
    }

    c14_c_x = c14_b_x;
    c14_c_y = c14_b_y;
    c14_d_x = c14_c_x;
    c14_d_y = c14_c_y;
    c14_b_a = c14_d_x / c14_d_y;
    c14_e_x = c14_x1;
    c14_f_x = c14_e_x;
    c14_e_y = muDoubleScalarAbs(c14_f_x);
    c14_b_A = -c14_e_y;
    c14_b_B = c14_margin_max;
    c14_g_x = c14_b_A;
    c14_f_y = c14_b_B;
    if (c14_f_y == 0.0) {
      c14_eml_warning();
    }

    c14_h_x = c14_g_x;
    c14_g_y = c14_f_y;
    c14_i_x = c14_h_x;
    c14_h_y = c14_g_y;
    c14_j_x = c14_i_x / c14_h_y;
    c14_b = c14_j_x;
    c14_k_x = c14_b;
    c14_b = c14_k_x;
    c14_b = muDoubleScalarExp(c14_b);
    c14_i_y = c14_b_a * c14_b;
    c14_b_b = 1.0 - c14_i_y;
    c14_y = c14_a * c14_b_b;
    _SFD_EML_CALL(0,37);
    c14_l_x = c14_x1;
    c14_m_x = c14_l_x;
    c14_j_y = muDoubleScalarAbs(c14_m_x);
    c14_c_A = -c14_j_y;
    c14_c_B = c14_margin_max;
    c14_n_x = c14_c_A;
    c14_k_y = c14_c_B;
    if (c14_k_y == 0.0) {
      c14_eml_warning();
    }

    c14_o_x = c14_n_x;
    c14_l_y = c14_k_y;
    c14_p_x = c14_o_x;
    c14_m_y = c14_l_y;
    c14_q_x = c14_p_x / c14_m_y;
    c14_gain = c14_q_x;
    c14_r_x = c14_gain;
    c14_gain = c14_r_x;
    c14_gain = muDoubleScalarExp(c14_gain);
  } else {
    _SFD_EML_CALL(0,40);
    c14_x1 = (c14_x + c14_x_min) - c14_margin_min;
    _SFD_EML_CALL(0,41);
    c14_c_a = -c14_x_min;
    c14_d_A = c14_margin_min;
    c14_d_B = c14_x_min;
    c14_s_x = c14_d_A;
    c14_n_y = c14_d_B;
    if (c14_n_y == 0.0) {
      c14_eml_warning();
    }

    c14_t_x = c14_s_x;
    c14_o_y = c14_n_y;
    c14_u_x = c14_t_x;
    c14_p_y = c14_o_y;
    c14_d_a = c14_u_x / c14_p_y;
    c14_v_x = c14_x1;
    c14_w_x = c14_v_x;
    c14_q_y = muDoubleScalarAbs(c14_w_x);
    c14_e_A = -c14_q_y;
    c14_e_B = c14_margin_min;
    c14_x_x = c14_e_A;
    c14_r_y = c14_e_B;
    if (c14_r_y == 0.0) {
      c14_eml_warning();
    }

    c14_y_x = c14_x_x;
    c14_s_y = c14_r_y;
    c14_ab_x = c14_y_x;
    c14_t_y = c14_s_y;
    c14_bb_x = c14_ab_x / c14_t_y;
    c14_c_b = c14_bb_x;
    c14_cb_x = c14_c_b;
    c14_c_b = c14_cb_x;
    c14_c_b = muDoubleScalarExp(c14_c_b);
    c14_u_y = c14_d_a * c14_c_b;
    c14_d_b = 1.0 - c14_u_y;
    c14_y = c14_c_a * c14_d_b;
    _SFD_EML_CALL(0,42);
    c14_db_x = c14_x1;
    c14_eb_x = c14_db_x;
    c14_v_y = muDoubleScalarAbs(c14_eb_x);
    c14_f_A = -c14_v_y;
    c14_f_B = c14_margin_max;
    c14_fb_x = c14_f_A;
    c14_w_y = c14_f_B;
    if (c14_w_y == 0.0) {
      c14_eml_warning();
    }

    c14_gb_x = c14_fb_x;
    c14_x_y = c14_w_y;
    c14_hb_x = c14_gb_x;
    c14_y_y = c14_x_y;
    c14_ib_x = c14_hb_x / c14_y_y;
    c14_gain = c14_ib_x;
    c14_jb_x = c14_gain;
    c14_gain = c14_jb_x;
    c14_gain = muDoubleScalarExp(c14_gain);
  }

 label_2:
  ;
 label_1:
  ;
  _SFD_EML_CALL(0,-42);
  sf_debug_symbol_scope_pop();
  *c14_ab_y = c14_y;
  *c14_b_gain = c14_gain;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,13);
  _sfEvent_ = c14_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber)
{
}

static void c14_eml_warning(void)
{
  int32_T c14_i0;
  static char_T c14_cv0[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c14_u[15];
  const mxArray *c14_y = NULL;
  int32_T c14_i1;
  static char_T c14_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c14_b_u[19];
  const mxArray *c14_b_y = NULL;
  for (c14_i0 = 0; c14_i0 < 15; c14_i0 = c14_i0 + 1) {
    c14_u[c14_i0] = c14_cv0[c14_i0];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c14_i1 = 0; c14_i1 < 19; c14_i1 = c14_i1 + 1) {
    c14_b_u[c14_i1] = c14_cv1[c14_i1];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c14_b_y, 14, c14_y);
}

static const mxArray *c14_sf_marshall(void *c14_chartInstance, void *c14_u)
{
  const mxArray *c14_y = NULL;
  real_T c14_b_u;
  const mxArray *c14_b_y = NULL;
  c14_y = NULL;
  c14_b_u = *((real_T *)c14_u);
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c14_y, c14_b_y);
  return c14_y;
}

const mxArray
  *sf_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c14_nameCaptureInfo = NULL;
  c14_ResolvedFunctionInfo c14_info[29];
  const mxArray *c14_m0 = NULL;
  int32_T c14_i2;
  c14_ResolvedFunctionInfo *c14_r0;
  c14_nameCaptureInfo = NULL;
  c14_info_helper(c14_info);
  sf_mex_assign(&c14_m0, sf_mex_createstruct("nameCaptureInfo", 1, 29));
  for (c14_i2 = 0; c14_i2 < 29; c14_i2 = c14_i2 + 1) {
    c14_r0 = &c14_info[c14_i2];
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->context)), "context"
                    , "nameCaptureInfo", c14_i2);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->name)), "name",
                    "nameCaptureInfo", c14_i2);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      c14_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c14_i2);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->resolved)),
                    "resolved", "nameCaptureInfo", c14_i2);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c14_i2);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c14_i2);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c14_i2);
  }

  sf_mex_assign(&c14_nameCaptureInfo, c14_m0);
  return c14_nameCaptureInfo;
}

static void c14_info_helper(c14_ResolvedFunctionInfo c14_info[29])
{
  c14_info[0].context = "";
  c14_info[0].name = "minus";
  c14_info[0].dominantType = "double";
  c14_info[0].resolved = "[B]minus";
  c14_info[0].fileLength = 0U;
  c14_info[0].fileTime1 = 0U;
  c14_info[0].fileTime2 = 0U;
  c14_info[1].context = "";
  c14_info[1].name = "lt";
  c14_info[1].dominantType = "double";
  c14_info[1].resolved = "[B]lt";
  c14_info[1].fileLength = 0U;
  c14_info[1].fileTime1 = 0U;
  c14_info[1].fileTime2 = 0U;
  c14_info[2].context = "";
  c14_info[2].name = "ge";
  c14_info[2].dominantType = "double";
  c14_info[2].resolved = "[B]ge";
  c14_info[2].fileLength = 0U;
  c14_info[2].fileTime1 = 0U;
  c14_info[2].fileTime2 = 0U;
  c14_info[3].context = "";
  c14_info[3].name = "uminus";
  c14_info[3].dominantType = "double";
  c14_info[3].resolved = "[B]uminus";
  c14_info[3].fileLength = 0U;
  c14_info[3].fileTime1 = 0U;
  c14_info[3].fileTime2 = 0U;
  c14_info[4].context = "";
  c14_info[4].name = "plus";
  c14_info[4].dominantType = "double";
  c14_info[4].resolved = "[B]plus";
  c14_info[4].fileLength = 0U;
  c14_info[4].fileTime1 = 0U;
  c14_info[4].fileTime2 = 0U;
  c14_info[5].context = "";
  c14_info[5].name = "gt";
  c14_info[5].dominantType = "double";
  c14_info[5].resolved = "[B]gt";
  c14_info[5].fileLength = 0U;
  c14_info[5].fileTime1 = 0U;
  c14_info[5].fileTime2 = 0U;
  c14_info[6].context = "";
  c14_info[6].name = "mrdivide";
  c14_info[6].dominantType = "double";
  c14_info[6].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c14_info[6].fileLength = 800U;
  c14_info[6].fileTime1 = 1238434292U;
  c14_info[6].fileTime2 = 0U;
  c14_info[7].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c14_info[7].name = "nargin";
  c14_info[7].dominantType = "";
  c14_info[7].resolved = "[B]nargin";
  c14_info[7].fileLength = 0U;
  c14_info[7].fileTime1 = 0U;
  c14_info[7].fileTime2 = 0U;
  c14_info[8].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c14_info[8].name = "isscalar";
  c14_info[8].dominantType = "double";
  c14_info[8].resolved = "[B]isscalar";
  c14_info[8].fileLength = 0U;
  c14_info[8].fileTime1 = 0U;
  c14_info[8].fileTime2 = 0U;
  c14_info[9].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c14_info[9].name = "rdivide";
  c14_info[9].dominantType = "double";
  c14_info[9].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[9].fileLength = 620U;
  c14_info[9].fileTime1 = 1213926766U;
  c14_info[9].fileTime2 = 0U;
  c14_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[10].name = "isa";
  c14_info[10].dominantType = "double";
  c14_info[10].resolved = "[B]isa";
  c14_info[10].fileLength = 0U;
  c14_info[10].fileTime1 = 0U;
  c14_info[10].fileTime2 = 0U;
  c14_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[11].name = "isempty";
  c14_info[11].dominantType = "double";
  c14_info[11].resolved = "[B]isempty";
  c14_info[11].fileLength = 0U;
  c14_info[11].fileTime1 = 0U;
  c14_info[11].fileTime2 = 0U;
  c14_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[12].name = "not";
  c14_info[12].dominantType = "logical";
  c14_info[12].resolved = "[B]not";
  c14_info[12].fileLength = 0U;
  c14_info[12].fileTime1 = 0U;
  c14_info[12].fileTime2 = 0U;
  c14_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[13].name = "strcmp";
  c14_info[13].dominantType = "char";
  c14_info[13].resolved = "[B]strcmp";
  c14_info[13].fileLength = 0U;
  c14_info[13].fileTime1 = 0U;
  c14_info[13].fileTime2 = 0U;
  c14_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[14].name = "eq";
  c14_info[14].dominantType = "double";
  c14_info[14].resolved = "[B]eq";
  c14_info[14].fileLength = 0U;
  c14_info[14].fileTime1 = 0U;
  c14_info[14].fileTime2 = 0U;
  c14_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[15].name = "eml_warning";
  c14_info[15].dominantType = "char";
  c14_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c14_info[15].fileLength = 262U;
  c14_info[15].fileTime1 = 1236257278U;
  c14_info[15].fileTime2 = 0U;
  c14_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[16].name = "eml_div";
  c14_info[16].dominantType = "double";
  c14_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c14_info[16].fileLength = 4269U;
  c14_info[16].fileTime1 = 1228093826U;
  c14_info[16].fileTime2 = 0U;
  c14_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c14_info[17].name = "isinteger";
  c14_info[17].dominantType = "double";
  c14_info[17].resolved = "[B]isinteger";
  c14_info[17].fileLength = 0U;
  c14_info[17].fileTime1 = 0U;
  c14_info[17].fileTime2 = 0U;
  c14_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c14_info[18].name = "isreal";
  c14_info[18].dominantType = "double";
  c14_info[18].resolved = "[B]isreal";
  c14_info[18].fileLength = 0U;
  c14_info[18].fileTime1 = 0U;
  c14_info[18].fileTime2 = 0U;
  c14_info[19].context = "";
  c14_info[19].name = "abs";
  c14_info[19].dominantType = "double";
  c14_info[19].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c14_info[19].fileLength = 566U;
  c14_info[19].fileTime1 = 1221267134U;
  c14_info[19].fileTime2 = 0U;
  c14_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c14_info[20].name = "ischar";
  c14_info[20].dominantType = "double";
  c14_info[20].resolved = "[B]ischar";
  c14_info[20].fileLength = 0U;
  c14_info[20].fileTime1 = 0U;
  c14_info[20].fileTime2 = 0U;
  c14_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c14_info[21].name = "islogical";
  c14_info[21].dominantType = "double";
  c14_info[21].resolved = "[B]islogical";
  c14_info[21].fileLength = 0U;
  c14_info[21].fileTime1 = 0U;
  c14_info[21].fileTime2 = 0U;
  c14_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c14_info[22].name = "size";
  c14_info[22].dominantType = "double";
  c14_info[22].resolved = "[B]size";
  c14_info[22].fileLength = 0U;
  c14_info[22].fileTime1 = 0U;
  c14_info[22].fileTime2 = 0U;
  c14_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c14_info[23].name = "class";
  c14_info[23].dominantType = "double";
  c14_info[23].resolved = "[B]class";
  c14_info[23].fileLength = 0U;
  c14_info[23].fileTime1 = 0U;
  c14_info[23].fileTime2 = 0U;
  c14_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c14_info[24].name = "zeros";
  c14_info[24].dominantType = "double";
  c14_info[24].resolved = "[B]zeros";
  c14_info[24].fileLength = 0U;
  c14_info[24].fileTime1 = 0U;
  c14_info[24].fileTime2 = 0U;
  c14_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c14_info[25].name = "eml_scalar_abs";
  c14_info[25].dominantType = "double";
  c14_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c14_info[25].fileLength = 461U;
  c14_info[25].fileTime1 = 1203447960U;
  c14_info[25].fileTime2 = 0U;
  c14_info[26].context = "";
  c14_info[26].name = "exp";
  c14_info[26].dominantType = "double";
  c14_info[26].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c14_info[26].fileLength = 324U;
  c14_info[26].fileTime1 = 1240261974U;
  c14_info[26].fileTime2 = 0U;
  c14_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c14_info[27].name = "eml_scalar_exp";
  c14_info[27].dominantType = "double";
  c14_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c14_info[27].fileLength = 243U;
  c14_info[27].fileTime1 = 1240261972U;
  c14_info[27].fileTime2 = 0U;
  c14_info[28].context = "";
  c14_info[28].name = "mtimes";
  c14_info[28].dominantType = "double";
  c14_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c14_info[28].fileLength = 3302U;
  c14_info[28].fileTime1 = 1242750894U;
  c14_info[28].fileTime2 = 0U;
}

static const mxArray *c14_b_sf_marshall(void *c14_chartInstance, void *c14_u)
{
  const mxArray *c14_y = NULL;
  boolean_T c14_b_u;
  const mxArray *c14_b_y = NULL;
  c14_y = NULL;
  c14_b_u = *((boolean_T *)c14_u);
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c14_y, c14_b_y);
  return c14_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3306474934U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1076240361U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2295224107U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2866759209U);
}

mxArray
  *sf_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
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
  *sf_get_sim_state_info_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[11],T\"gain\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(&mxChecksum);
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
           14,
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
                              (MexFcnForType)c14_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y",0,
                              (MexFcnForType)c14_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"x_max",0,
                              (MexFcnForType)c14_sf_marshall);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"x_min",0,
                              (MexFcnForType)c14_sf_marshall);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "margin_max",0,(MexFcnForType)c14_sf_marshall);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "margin_min",0,(MexFcnForType)c14_sf_marshall);
          _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y_in",0,
                              (MexFcnForType)c14_sf_marshall);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"gain",0,
                              (MexFcnForType)c14_sf_marshall);
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
          real_T *c14_x;
          real_T *c14_y;
          real_T *c14_x_max;
          real_T *c14_x_min;
          real_T *c14_margin_max;
          real_T *c14_margin_min;
          real_T *c14_y_in;
          real_T *c14_gain;
          c14_y_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
          c14_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c14_margin_min = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
          c14_gain = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c14_x_max = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c14_x = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c14_x_min = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c14_margin_max = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          _SFD_SET_DATA_VALUE_PTR(0U, c14_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c14_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c14_x_max);
          _SFD_SET_DATA_VALUE_PTR(3U, c14_x_min);
          _SFD_SET_DATA_VALUE_PTR(4U, c14_margin_max);
          _SFD_SET_DATA_VALUE_PTR(5U, c14_margin_min);
          _SFD_SET_DATA_VALUE_PTR(6U, c14_y_in);
          _SFD_SET_DATA_VALUE_PTR(7U, c14_gain);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  initialize_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_enable_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  enable_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_disable_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  disable_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_gateway_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  sf_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void
  sf_opaque_ext_mode_exec_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  ext_mode_exec_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static mxArray*
  sf_opaque_get_sim_state_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  return st;
}

static void
  sf_opaque_set_sim_state_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(sf_mex_dup(st));
}

static void sf_opaque_terminate_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",14,
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
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",14,6);
      sf_mark_chart_reusable_outputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",14,2);
    }

    sf_set_rtw_dwork_info(S,"M37_Sim_Forcing_003h_expe_infra_transz_lim",
                          "M37_Sim_Forcing_003h_expe_infra_transz_lim",14);
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

static void mdlRTW_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",14);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim;
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

void c14_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(SimStruct *
  S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

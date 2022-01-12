/* Include files */

#include "blascompat32.h"
#include "Sim_Forcing_003h_expe_infra5_full_control5_sfun.h"
#include "c5_Sim_Forcing_003h_expe_infra5_full_control5.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "Sim_Forcing_003h_expe_infra5_full_control5_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c5_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc5_Sim_Forcing_003h_expe_infra5_full_control5InstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c5_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void initialize_params_c5_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void enable_c5_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void disable_c5_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void c5_update_debugger_state_c5_Sim_Forcing_003h_expe_infra5_full_c(void);
static void ext_mode_exec_c5_Sim_Forcing_003h_expe_infra5_full_control5(void);
static const mxArray
  *get_sim_state_c5_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void set_sim_state_c5_Sim_Forcing_003h_expe_infra5_full_control5(const
  mxArray *c5_st);
static void finalize_c5_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void sf_c5_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static void c5_eml_warning(void);
static const mxArray *c5_sf_marshall(void *c5_chartInstance, void *c5_u);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[29]);
static const mxArray *c5_b_sf_marshall(void *c5_chartInstance, void *c5_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c5_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  uint8_T *c5_is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  c5_is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5 = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c5_is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5 = 0U;
}

static void initialize_params_c5_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
}

static void enable_c5_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c5_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c5_update_debugger_state_c5_Sim_Forcing_003h_expe_infra5_full_c(void)
{
}

static void ext_mode_exec_c5_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  c5_update_debugger_state_c5_Sim_Forcing_003h_expe_infra5_full_c();
}

static const mxArray
  *get_sim_state_c5_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  const mxArray *c5_st = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T *c5_d_y;
  uint8_T *c5_is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  c5_is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5 = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c5_d_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2));
  c5_u = *c5_d_y;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_u = *c5_is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y);
  return c5_st;
}

static void set_sim_state_c5_Sim_Forcing_003h_expe_infra5_full_control5(const
  mxArray *c5_st)
{
  const mxArray *c5_u;
  const mxArray *c5_y;
  real_T c5_d0;
  real_T c5_b_y;
  const mxArray *c5_is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  uint8_T c5_u0;
  uint8_T c5_c_y;
  boolean_T *c5_doneDoubleBufferReInit;
  real_T *c5_d_y;
  uint8_T *c5_b_is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  c5_b_is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5 = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c5_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c5_d_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  *c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  c5_y = sf_mex_dup(sf_mex_getcell(c5_u, 0));
  sf_mex_import("y", sf_mex_dup(c5_y), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_b_y = c5_d0;
  sf_mex_destroy(&c5_y);
  *c5_d_y = c5_b_y;
  c5_is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5 = sf_mex_dup
    (sf_mex_getcell(c5_u, 1));
  sf_mex_import("is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5",
                sf_mex_dup(
    c5_is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5), &c5_u0, 1, 3,
                0U, 0, 0U, 0);
  c5_c_y = c5_u0;
  sf_mex_destroy(&c5_is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5);
  *c5_b_is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5 = c5_c_y;
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_Sim_Forcing_003h_expe_infra5_full_c();
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
}

static void sf_c5_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  int32_T c5_previousEvent;
  real_T c5_x;
  real_T c5_x_max;
  real_T c5_x_min;
  real_T c5_margin_max;
  real_T c5_margin_min;
  real_T c5_nargout = 1.0;
  real_T c5_nargin = 5.0;
  real_T c5_x1;
  real_T c5_y;
  real_T c5_a;
  real_T c5_A;
  real_T c5_B;
  real_T c5_b_x;
  real_T c5_b_y;
  real_T c5_c_x;
  real_T c5_c_y;
  real_T c5_d_x;
  real_T c5_d_y;
  real_T c5_b_a;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_e_y;
  real_T c5_b_A;
  real_T c5_b_B;
  real_T c5_g_x;
  real_T c5_f_y;
  real_T c5_h_x;
  real_T c5_g_y;
  real_T c5_i_x;
  real_T c5_h_y;
  real_T c5_j_x;
  real_T c5_b;
  real_T c5_k_x;
  real_T c5_i_y;
  real_T c5_b_b;
  real_T c5_c_a;
  real_T c5_c_A;
  real_T c5_c_B;
  real_T c5_l_x;
  real_T c5_j_y;
  real_T c5_m_x;
  real_T c5_k_y;
  real_T c5_n_x;
  real_T c5_l_y;
  real_T c5_d_a;
  real_T c5_o_x;
  real_T c5_p_x;
  real_T c5_m_y;
  real_T c5_d_A;
  real_T c5_d_B;
  real_T c5_q_x;
  real_T c5_n_y;
  real_T c5_r_x;
  real_T c5_o_y;
  real_T c5_s_x;
  real_T c5_p_y;
  real_T c5_t_x;
  real_T c5_c_b;
  real_T c5_u_x;
  real_T c5_q_y;
  real_T c5_d_b;
  real_T *c5_v_x;
  real_T *c5_r_y;
  real_T *c5_b_x_max;
  real_T *c5_b_x_min;
  real_T *c5_b_margin_max;
  real_T *c5_b_margin_min;
  c5_b_x_min = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c5_b_x_max = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c5_b_margin_min = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  c5_r_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c5_b_margin_max = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c5_v_x = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,3);
  _SFD_DATA_RANGE_CHECK(*c5_v_x, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_r_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_b_x_max, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_b_x_min, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_b_margin_max, 4U);
  _SFD_DATA_RANGE_CHECK(*c5_b_margin_min, 5U);
  c5_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,3);
  c5_x = *c5_v_x;
  c5_x_max = *c5_b_x_max;
  c5_x_min = *c5_b_x_min;
  c5_margin_max = *c5_b_margin_max;
  c5_margin_min = *c5_b_margin_min;
  sf_debug_symbol_scope_push(9U, 0U);
  sf_debug_symbol_scope_add("nargout", &c5_nargout, c5_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c5_nargin, c5_sf_marshall);
  sf_debug_symbol_scope_add("x1", &c5_x1, c5_sf_marshall);
  sf_debug_symbol_scope_add("y", &c5_y, c5_sf_marshall);
  sf_debug_symbol_scope_add("margin_min", &c5_margin_min, c5_sf_marshall);
  sf_debug_symbol_scope_add("margin_max", &c5_margin_max, c5_sf_marshall);
  sf_debug_symbol_scope_add("x_min", &c5_x_min, c5_sf_marshall);
  sf_debug_symbol_scope_add("x_max", &c5_x_max, c5_sf_marshall);
  sf_debug_symbol_scope_add("x", &c5_x, c5_sf_marshall);
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
  _SFD_EML_CALL(0,17);
  if (CV_EML_COND(0, 0, c5_x < c5_x_max - c5_margin_max)) {
    if (CV_EML_COND(0, 1, c5_x >= 0.0)) {
      CV_EML_MCDC(0, 0, true);
      CV_EML_IF(0, 0, true);
      _SFD_EML_CALL(0,18);
      c5_y = c5_x;
      goto label_1;
    }
  }

  CV_EML_MCDC(0, 0, false);
  CV_EML_IF(0, 0, false);
  _SFD_EML_CALL(0,19);
  if (CV_EML_COND(0, 2, c5_x > (-c5_x_min) + c5_margin_min)) {
    if (CV_EML_COND(0, 3, c5_x < 0.0)) {
      CV_EML_MCDC(0, 1, true);
      CV_EML_IF(0, 1, true);
      _SFD_EML_CALL(0,20);
      c5_y = c5_x;
      goto label_2;
    }
  }

  CV_EML_MCDC(0, 1, false);
  CV_EML_IF(0, 1, false);
  _SFD_EML_CALL(0,21);
  if (CV_EML_IF(0, 2, c5_x >= c5_x_max - c5_margin_max)) {
    _SFD_EML_CALL(0,22);
    c5_x1 = (c5_x - c5_x_max) + c5_margin_max;
    _SFD_EML_CALL(0,23);
    c5_a = c5_x_max;
    c5_A = c5_margin_max;
    c5_B = c5_x_max;
    c5_b_x = c5_A;
    c5_b_y = c5_B;
    if (c5_b_y == 0.0) {
      c5_eml_warning();
    }

    c5_c_x = c5_b_x;
    c5_c_y = c5_b_y;
    c5_d_x = c5_c_x;
    c5_d_y = c5_c_y;
    c5_b_a = c5_d_x / c5_d_y;
    c5_e_x = c5_x1;
    c5_f_x = c5_e_x;
    c5_e_y = muDoubleScalarAbs(c5_f_x);
    c5_b_A = -c5_e_y;
    c5_b_B = c5_margin_max;
    c5_g_x = c5_b_A;
    c5_f_y = c5_b_B;
    if (c5_f_y == 0.0) {
      c5_eml_warning();
    }

    c5_h_x = c5_g_x;
    c5_g_y = c5_f_y;
    c5_i_x = c5_h_x;
    c5_h_y = c5_g_y;
    c5_j_x = c5_i_x / c5_h_y;
    c5_b = c5_j_x;
    c5_k_x = c5_b;
    c5_b = c5_k_x;
    c5_b = muDoubleScalarExp(c5_b);
    c5_i_y = c5_b_a * c5_b;
    c5_b_b = 1.0 - c5_i_y;
    c5_y = c5_a * c5_b_b;
  } else {
    _SFD_EML_CALL(0,25);
    c5_x1 = (c5_x + c5_x_min) - c5_margin_min;
    _SFD_EML_CALL(0,26);
    c5_c_a = -c5_x_min;
    c5_c_A = c5_margin_min;
    c5_c_B = c5_x_min;
    c5_l_x = c5_c_A;
    c5_j_y = c5_c_B;
    if (c5_j_y == 0.0) {
      c5_eml_warning();
    }

    c5_m_x = c5_l_x;
    c5_k_y = c5_j_y;
    c5_n_x = c5_m_x;
    c5_l_y = c5_k_y;
    c5_d_a = c5_n_x / c5_l_y;
    c5_o_x = c5_x1;
    c5_p_x = c5_o_x;
    c5_m_y = muDoubleScalarAbs(c5_p_x);
    c5_d_A = -c5_m_y;
    c5_d_B = c5_margin_min;
    c5_q_x = c5_d_A;
    c5_n_y = c5_d_B;
    if (c5_n_y == 0.0) {
      c5_eml_warning();
    }

    c5_r_x = c5_q_x;
    c5_o_y = c5_n_y;
    c5_s_x = c5_r_x;
    c5_p_y = c5_o_y;
    c5_t_x = c5_s_x / c5_p_y;
    c5_c_b = c5_t_x;
    c5_u_x = c5_c_b;
    c5_c_b = c5_u_x;
    c5_c_b = muDoubleScalarExp(c5_c_b);
    c5_q_y = c5_d_a * c5_c_b;
    c5_d_b = 1.0 - c5_q_y;
    c5_y = c5_c_a * c5_d_b;
  }

 label_2:
  ;
 label_1:
  ;
  _SFD_EML_CALL(0,-26);
  sf_debug_symbol_scope_pop();
  *c5_r_y = c5_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
  _sfEvent_ = c5_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_Sim_Forcing_003h_expe_infra5_full_control5MachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static void c5_eml_warning(void)
{
  int32_T c5_i0;
  static char_T c5_cv0[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c5_u[15];
  const mxArray *c5_y = NULL;
  int32_T c5_i1;
  static char_T c5_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c5_b_u[19];
  const mxArray *c5_b_y = NULL;
  for (c5_i0 = 0; c5_i0 < 15; c5_i0 = c5_i0 + 1) {
    c5_u[c5_i0] = c5_cv0[c5_i0];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c5_i1 = 0; c5_i1 < 19; c5_i1 = c5_i1 + 1) {
    c5_b_u[c5_i1] = c5_cv1[c5_i1];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c5_b_y, 14, c5_y);
}

static const mxArray *c5_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

const mxArray
  *sf_c5_Sim_Forcing_003h_expe_infra5_full_control5_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_ResolvedFunctionInfo c5_info[29];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i2;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 29));
  for (c5_i2 = 0; c5_i2 < 29; c5_i2 = c5_i2 + 1) {
    c5_r0 = &c5_info[c5_i2];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context",
                    "nameCaptureInfo", c5_i2);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name",
                    "nameCaptureInfo", c5_i2);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c5_i2);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c5_i2);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c5_i2);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c5_i2);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c5_i2);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[29])
{
  c5_info[0].context = "";
  c5_info[0].name = "minus";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved = "[B]minus";
  c5_info[0].fileLength = 0U;
  c5_info[0].fileTime1 = 0U;
  c5_info[0].fileTime2 = 0U;
  c5_info[1].context = "";
  c5_info[1].name = "lt";
  c5_info[1].dominantType = "double";
  c5_info[1].resolved = "[B]lt";
  c5_info[1].fileLength = 0U;
  c5_info[1].fileTime1 = 0U;
  c5_info[1].fileTime2 = 0U;
  c5_info[2].context = "";
  c5_info[2].name = "ge";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved = "[B]ge";
  c5_info[2].fileLength = 0U;
  c5_info[2].fileTime1 = 0U;
  c5_info[2].fileTime2 = 0U;
  c5_info[3].context = "";
  c5_info[3].name = "uminus";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved = "[B]uminus";
  c5_info[3].fileLength = 0U;
  c5_info[3].fileTime1 = 0U;
  c5_info[3].fileTime2 = 0U;
  c5_info[4].context = "";
  c5_info[4].name = "plus";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved = "[B]plus";
  c5_info[4].fileLength = 0U;
  c5_info[4].fileTime1 = 0U;
  c5_info[4].fileTime2 = 0U;
  c5_info[5].context = "";
  c5_info[5].name = "gt";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved = "[B]gt";
  c5_info[5].fileLength = 0U;
  c5_info[5].fileTime1 = 0U;
  c5_info[5].fileTime2 = 0U;
  c5_info[6].context = "";
  c5_info[6].name = "mrdivide";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[6].fileLength = 800U;
  c5_info[6].fileTime1 = 1238434292U;
  c5_info[6].fileTime2 = 0U;
  c5_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[7].name = "nargin";
  c5_info[7].dominantType = "";
  c5_info[7].resolved = "[B]nargin";
  c5_info[7].fileLength = 0U;
  c5_info[7].fileTime1 = 0U;
  c5_info[7].fileTime2 = 0U;
  c5_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[8].name = "isscalar";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved = "[B]isscalar";
  c5_info[8].fileLength = 0U;
  c5_info[8].fileTime1 = 0U;
  c5_info[8].fileTime2 = 0U;
  c5_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[9].name = "rdivide";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[9].fileLength = 620U;
  c5_info[9].fileTime1 = 1213926766U;
  c5_info[9].fileTime2 = 0U;
  c5_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[10].name = "isa";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved = "[B]isa";
  c5_info[10].fileLength = 0U;
  c5_info[10].fileTime1 = 0U;
  c5_info[10].fileTime2 = 0U;
  c5_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[11].name = "isempty";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved = "[B]isempty";
  c5_info[11].fileLength = 0U;
  c5_info[11].fileTime1 = 0U;
  c5_info[11].fileTime2 = 0U;
  c5_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[12].name = "not";
  c5_info[12].dominantType = "logical";
  c5_info[12].resolved = "[B]not";
  c5_info[12].fileLength = 0U;
  c5_info[12].fileTime1 = 0U;
  c5_info[12].fileTime2 = 0U;
  c5_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[13].name = "strcmp";
  c5_info[13].dominantType = "char";
  c5_info[13].resolved = "[B]strcmp";
  c5_info[13].fileLength = 0U;
  c5_info[13].fileTime1 = 0U;
  c5_info[13].fileTime2 = 0U;
  c5_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[14].name = "eq";
  c5_info[14].dominantType = "double";
  c5_info[14].resolved = "[B]eq";
  c5_info[14].fileLength = 0U;
  c5_info[14].fileTime1 = 0U;
  c5_info[14].fileTime2 = 0U;
  c5_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[15].name = "eml_warning";
  c5_info[15].dominantType = "char";
  c5_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c5_info[15].fileLength = 262U;
  c5_info[15].fileTime1 = 1236257278U;
  c5_info[15].fileTime2 = 0U;
  c5_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[16].name = "eml_div";
  c5_info[16].dominantType = "double";
  c5_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[16].fileLength = 4269U;
  c5_info[16].fileTime1 = 1228093826U;
  c5_info[16].fileTime2 = 0U;
  c5_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[17].name = "isinteger";
  c5_info[17].dominantType = "double";
  c5_info[17].resolved = "[B]isinteger";
  c5_info[17].fileLength = 0U;
  c5_info[17].fileTime1 = 0U;
  c5_info[17].fileTime2 = 0U;
  c5_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c5_info[18].name = "isreal";
  c5_info[18].dominantType = "double";
  c5_info[18].resolved = "[B]isreal";
  c5_info[18].fileLength = 0U;
  c5_info[18].fileTime1 = 0U;
  c5_info[18].fileTime2 = 0U;
  c5_info[19].context = "";
  c5_info[19].name = "abs";
  c5_info[19].dominantType = "double";
  c5_info[19].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[19].fileLength = 566U;
  c5_info[19].fileTime1 = 1221267134U;
  c5_info[19].fileTime2 = 0U;
  c5_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[20].name = "ischar";
  c5_info[20].dominantType = "double";
  c5_info[20].resolved = "[B]ischar";
  c5_info[20].fileLength = 0U;
  c5_info[20].fileTime1 = 0U;
  c5_info[20].fileTime2 = 0U;
  c5_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[21].name = "islogical";
  c5_info[21].dominantType = "double";
  c5_info[21].resolved = "[B]islogical";
  c5_info[21].fileLength = 0U;
  c5_info[21].fileTime1 = 0U;
  c5_info[21].fileTime2 = 0U;
  c5_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[22].name = "size";
  c5_info[22].dominantType = "double";
  c5_info[22].resolved = "[B]size";
  c5_info[22].fileLength = 0U;
  c5_info[22].fileTime1 = 0U;
  c5_info[22].fileTime2 = 0U;
  c5_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[23].name = "class";
  c5_info[23].dominantType = "double";
  c5_info[23].resolved = "[B]class";
  c5_info[23].fileLength = 0U;
  c5_info[23].fileTime1 = 0U;
  c5_info[23].fileTime2 = 0U;
  c5_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[24].name = "zeros";
  c5_info[24].dominantType = "double";
  c5_info[24].resolved = "[B]zeros";
  c5_info[24].fileLength = 0U;
  c5_info[24].fileTime1 = 0U;
  c5_info[24].fileTime2 = 0U;
  c5_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[25].name = "eml_scalar_abs";
  c5_info[25].dominantType = "double";
  c5_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[25].fileLength = 461U;
  c5_info[25].fileTime1 = 1203447960U;
  c5_info[25].fileTime2 = 0U;
  c5_info[26].context = "";
  c5_info[26].name = "exp";
  c5_info[26].dominantType = "double";
  c5_info[26].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c5_info[26].fileLength = 324U;
  c5_info[26].fileTime1 = 1240261974U;
  c5_info[26].fileTime2 = 0U;
  c5_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c5_info[27].name = "eml_scalar_exp";
  c5_info[27].dominantType = "double";
  c5_info[27].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c5_info[27].fileLength = 243U;
  c5_info[27].fileTime1 = 1240261972U;
  c5_info[27].fileTime2 = 0U;
  c5_info[28].context = "";
  c5_info[28].name = "mtimes";
  c5_info[28].dominantType = "double";
  c5_info[28].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[28].fileLength = 3302U;
  c5_info[28].fileTime1 = 1242750894U;
  c5_info[28].fileTime2 = 0U;
}

static const mxArray *c5_b_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  boolean_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  c5_b_u = *((boolean_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c5_Sim_Forcing_003h_expe_infra5_full_control5_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(554741783U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2168199701U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3880468783U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2267666142U);
}

mxArray
  *sf_c5_Sim_Forcing_003h_expe_infra5_full_control5_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(208997172U);
    pr[1] = (double)(1954284068U);
    pr[2] = (double)(1078963805U);
    pr[3] = (double)(120331499U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
  *sf_get_sim_state_info_c5_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c5_Sim_Forcing_003h_expe_infra5_full_control5\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_Sim_Forcing_003h_expe_infra5_full_control5_get_check_sum(&mxChecksum);
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
           5,
           1,
           1,
           6,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"x",0,
                              (MexFcnForType)c5_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y",0,
                              (MexFcnForType)c5_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"x_max",0,
                              (MexFcnForType)c5_sf_marshall);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"x_min",0,
                              (MexFcnForType)c5_sf_marshall);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "margin_max",0,(MexFcnForType)c5_sf_marshall);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "margin_min",0,(MexFcnForType)c5_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1032);
        _SFD_CV_INIT_EML_IF(0,0,652,687,707,1028);
        _SFD_CV_INIT_EML_IF(0,1,707,746,766,1028);
        _SFD_CV_INIT_EML_IF(0,2,766,796,908,1028);

        {
          static int condStart[] = { 655, 681 };

          static int condEnd[] = { 677, 687 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,655,687,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        {
          static int condStart[] = { 714, 741 };

          static int condEnd[] = { 737, 746 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,714,746,2,2,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
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
          real_T *c5_x;
          real_T *c5_y;
          real_T *c5_x_max;
          real_T *c5_x_min;
          real_T *c5_margin_max;
          real_T *c5_margin_min;
          c5_x_min = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c5_x_max = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c5_margin_min = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
          c5_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c5_margin_max = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c5_x = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_x_max);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_x_min);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_margin_max);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_margin_min);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Sim_Forcing_003h_expe_infra5_full_control5MachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c5_Sim_Forcing_003h_expe_infra5_full_control5
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c5_Sim_Forcing_003h_expe_infra5_full_control5();
  initialize_c5_Sim_Forcing_003h_expe_infra5_full_control5();
}

static void sf_opaque_enable_c5_Sim_Forcing_003h_expe_infra5_full_control5(void *
  chartInstanceVar)
{
  enable_c5_Sim_Forcing_003h_expe_infra5_full_control5();
}

static void sf_opaque_disable_c5_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar)
{
  disable_c5_Sim_Forcing_003h_expe_infra5_full_control5();
}

static void sf_opaque_gateway_c5_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar)
{
  sf_c5_Sim_Forcing_003h_expe_infra5_full_control5();
}

static void
  sf_opaque_ext_mode_exec_c5_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar)
{
  ext_mode_exec_c5_Sim_Forcing_003h_expe_infra5_full_control5();
}

static mxArray*
  sf_opaque_get_sim_state_c5_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c5_Sim_Forcing_003h_expe_infra5_full_control5();
  return st;
}

static void
  sf_opaque_set_sim_state_c5_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c5_Sim_Forcing_003h_expe_infra5_full_control5(sf_mex_dup(st));
}

static void sf_opaque_terminate_c5_Sim_Forcing_003h_expe_infra5_full_control5
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c5_Sim_Forcing_003h_expe_infra5_full_control5();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_Sim_Forcing_003h_expe_infra5_full_control5
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_Sim_Forcing_003h_expe_infra5_full_control5();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c5_Sim_Forcing_003h_expe_infra5_full_control5
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Sim_Forcing_003h_expe_infra5_full_control5",
      "Sim_Forcing_003h_expe_infra5_full_control5",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "Sim_Forcing_003h_expe_infra5_full_control5",
                "Sim_Forcing_003h_expe_infra5_full_control5",5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "Sim_Forcing_003h_expe_infra5_full_control5",
      "Sim_Forcing_003h_expe_infra5_full_control5",5,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "Sim_Forcing_003h_expe_infra5_full_control5",
        "Sim_Forcing_003h_expe_infra5_full_control5",5,5);
      sf_mark_chart_reusable_outputs(S,
        "Sim_Forcing_003h_expe_infra5_full_control5",
        "Sim_Forcing_003h_expe_infra5_full_control5",5,1);
    }

    sf_set_rtw_dwork_info(S,"Sim_Forcing_003h_expe_infra5_full_control5",
                          "Sim_Forcing_003h_expe_infra5_full_control5",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(677067393U));
  ssSetChecksum1(S,(322438107U));
  ssSetChecksum2(S,(1935932830U));
  ssSetChecksum3(S,(676536442U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_Sim_Forcing_003h_expe_infra5_full_control5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Sim_Forcing_003h_expe_infra5_full_control5",
      "Sim_Forcing_003h_expe_infra5_full_control5",5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_Sim_Forcing_003h_expe_infra5_full_control5(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c5_Sim_Forcing_003h_expe_infra5_full_control5;
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

void c5_Sim_Forcing_003h_expe_infra5_full_control5_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_Sim_Forcing_003h_expe_infra5_full_control5(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_Sim_Forcing_003h_expe_infra5_full_control5(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_Sim_Forcing_003h_expe_infra5_full_control5(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_Sim_Forcing_003h_expe_infra5_full_control5_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

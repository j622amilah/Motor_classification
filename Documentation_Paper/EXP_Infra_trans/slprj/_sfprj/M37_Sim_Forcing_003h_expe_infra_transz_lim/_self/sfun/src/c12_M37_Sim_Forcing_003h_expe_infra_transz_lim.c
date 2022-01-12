/* Include files */

#include "blascompat32.h"
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun.h"
#include "c12_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c12_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc12_M37_Sim_Forcing_003h_expe_infra_transz_limInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void initialize_params_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void);
static void enable_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void disable_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c12_update_debugger_state_c12_M37_Sim_Forcing_003h_expe_infra_t(void);
static void ext_mode_exec_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static const mxArray
  *get_sim_state_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void set_sim_state_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c12_st);
static void finalize_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void sf_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber);
static const mxArray *c12_sf_marshall(void *c12_chartInstance, void *c12_u);
static const mxArray *c12_b_sf_marshall(void *c12_chartInstance, void *c12_u);
static const mxArray *c12_c_sf_marshall(void *c12_chartInstance, void *c12_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  uint8_T *c12_is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c12_is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c12_is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim = 0U;
}

static void initialize_params_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void)
{
  real_T c12_dv0[210];
  int32_T c12_i0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'B' in the parent workspace.\n");
  sf_mex_import("sf_mex_get_sfun_param", sf_mex_get_sfun_param(chartInstance.S,
    0, 0), &c12_dv0, 0, 0, 0U, 1, 0U, 2, 42, 5);
  for (c12_i0 = 0; c12_i0 < 210; c12_i0 = c12_i0 + 1) {
    chartInstance.c12_B[c12_i0] = c12_dv0[c12_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c12_update_debugger_state_c12_M37_Sim_Forcing_003h_expe_infra_t(void)
{
}

static void ext_mode_exec_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  c12_update_debugger_state_c12_M37_Sim_Forcing_003h_expe_infra_t();
}

static const mxArray
  *get_sim_state_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const mxArray *c12_st = NULL;
  const mxArray *c12_y = NULL;
  real_T c12_u;
  const mxArray *c12_b_y = NULL;
  real_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T c12_c_u;
  const mxArray *c12_d_y = NULL;
  real_T c12_d_u;
  const mxArray *c12_e_y = NULL;
  uint8_T c12_e_u;
  const mxArray *c12_f_y = NULL;
  real_T *c12_current_axis;
  real_T *c12_gradual_state;
  real_T *c12_mod;
  real_T *c12_xytoz;
  uint8_T *c12_is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c12_gradual_state = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c12_current_axis = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c12_xytoz = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c12_mod = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c12_is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellarray(5));
  c12_u = *c12_current_axis;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_b_u = *c12_gradual_state;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c12_y, 1, c12_c_y);
  c12_c_u = *c12_mod;
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c12_y, 2, c12_d_y);
  c12_d_u = *c12_xytoz;
  c12_e_y = NULL;
  sf_mex_assign(&c12_e_y, sf_mex_create("y", &c12_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c12_y, 3, c12_e_y);
  c12_e_u = *c12_is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c12_f_y = NULL;
  sf_mex_assign(&c12_f_y, sf_mex_create("y", &c12_e_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c12_y, 4, c12_f_y);
  sf_mex_assign(&c12_st, c12_y);
  return c12_st;
}

static void set_sim_state_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c12_st)
{
  const mxArray *c12_u;
  const mxArray *c12_current_axis;
  real_T c12_d0;
  real_T c12_y;
  const mxArray *c12_b_current_axis;
  real_T c12_d1;
  real_T c12_b_y;
  const mxArray *c12_c_current_axis;
  real_T c12_d2;
  real_T c12_c_y;
  const mxArray *c12_d_current_axis;
  real_T c12_d3;
  real_T c12_d_y;
  const mxArray *c12_is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  uint8_T c12_u0;
  uint8_T c12_e_y;
  boolean_T *c12_doneDoubleBufferReInit;
  real_T *c12_e_current_axis;
  real_T *c12_gradual_state;
  real_T *c12_mod;
  real_T *c12_xytoz;
  uint8_T *c12_b_is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c12_gradual_state = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c12_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c12_e_current_axis = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c12_xytoz = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c12_mod = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c12_b_is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  *c12_doneDoubleBufferReInit = true;
  c12_u = sf_mex_dup(c12_st);
  c12_current_axis = sf_mex_dup(sf_mex_getcell(c12_u, 0));
  sf_mex_import("current_axis", sf_mex_dup(c12_current_axis), &c12_d0, 1, 0, 0U,
                0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_current_axis);
  *c12_e_current_axis = c12_y;
  c12_b_current_axis = sf_mex_dup(sf_mex_getcell(c12_u, 1));
  sf_mex_import("gradual_state", sf_mex_dup(c12_b_current_axis), &c12_d1, 1, 0,
                0U, 0, 0U, 0);
  c12_b_y = c12_d1;
  sf_mex_destroy(&c12_b_current_axis);
  *c12_gradual_state = c12_b_y;
  c12_c_current_axis = sf_mex_dup(sf_mex_getcell(c12_u, 2));
  sf_mex_import("mod", sf_mex_dup(c12_c_current_axis), &c12_d2, 1, 0, 0U, 0, 0U,
                0);
  c12_c_y = c12_d2;
  sf_mex_destroy(&c12_c_current_axis);
  *c12_mod = c12_c_y;
  c12_d_current_axis = sf_mex_dup(sf_mex_getcell(c12_u, 3));
  sf_mex_import("xytoz", sf_mex_dup(c12_d_current_axis), &c12_d3, 1, 0, 0U, 0,
                0U, 0);
  c12_d_y = c12_d3;
  sf_mex_destroy(&c12_d_current_axis);
  *c12_xytoz = c12_d_y;
  c12_is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim = sf_mex_dup
    (sf_mex_getcell(c12_u, 4));
  sf_mex_import("is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim",
                sf_mex_dup(
    c12_is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim), &c12_u0, 1, 3,
                0U, 0, 0U, 0);
  c12_e_y = c12_u0;
  sf_mex_destroy(&c12_is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim);
  *c12_b_is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim = c12_e_y;
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_M37_Sim_Forcing_003h_expe_infra_t();
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void sf_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c12_i1;
  int32_T c12_previousEvent;
  real_T c12_count;
  int32_T c12_i2;
  real_T c12_b_B[210];
  boolean_T c12_trigger;
  real_T c12_gs_in;
  real_T c12_xytoz_in;
  real_T c12_nargout = 4.0;
  real_T c12_nargin = 5.0;
  real_T c12_next_axis;
  real_T c12_current_axis;
  real_T c12_mod;
  real_T c12_gradual_state;
  real_T c12_xytoz;
  real_T c12_n;
  real_T c12_k;
  real_T c12_b_k;
  int32_T c12_hoistedExpr;
  int32_T c12_b_hoistedExpr;
  int32_T c12_c_hoistedExpr;
  real_T *c12_b_count;
  real_T *c12_b_xytoz;
  boolean_T *c12_b_trigger;
  real_T *c12_b_gradual_state;
  real_T *c12_b_gs_in;
  real_T *c12_b_xytoz_in;
  real_T *c12_b_mod;
  real_T *c12_b_current_axis;
  c12_b_gradual_state = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c12_b_current_axis = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c12_b_xytoz = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c12_b_xytoz_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c12_b_trigger = (boolean_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c12_b_mod = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c12_b_count = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c12_b_gs_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,11);
  _SFD_DATA_RANGE_CHECK(*c12_b_count, 0U);
  for (c12_i1 = 0; c12_i1 < 210; c12_i1 = c12_i1 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance.c12_B[c12_i1], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c12_b_xytoz, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c12_b_trigger, 3U);
  _SFD_DATA_RANGE_CHECK(*c12_b_gradual_state, 4U);
  _SFD_DATA_RANGE_CHECK(*c12_b_gs_in, 5U);
  _SFD_DATA_RANGE_CHECK(*c12_b_xytoz_in, 6U);
  _SFD_DATA_RANGE_CHECK(*c12_b_mod, 7U);
  _SFD_DATA_RANGE_CHECK(*c12_b_current_axis, 8U);
  c12_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,11);
  c12_count = *c12_b_count;
  for (c12_i2 = 0; c12_i2 < 210; c12_i2 = c12_i2 + 1) {
    c12_b_B[c12_i2] = chartInstance.c12_B[c12_i2];
  }

  c12_trigger = *c12_b_trigger;
  c12_gs_in = *c12_b_gs_in;
  c12_xytoz_in = *c12_b_xytoz_in;
  sf_debug_symbol_scope_push(12U, 0U);
  sf_debug_symbol_scope_add("nargout", &c12_nargout, c12_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c12_nargin, c12_sf_marshall);
  sf_debug_symbol_scope_add("next_axis", &c12_next_axis, c12_sf_marshall);
  sf_debug_symbol_scope_add("current_axis", &c12_current_axis, c12_sf_marshall);
  sf_debug_symbol_scope_add("mod", &c12_mod, c12_sf_marshall);
  sf_debug_symbol_scope_add("gradual_state", &c12_gradual_state, c12_sf_marshall);
  sf_debug_symbol_scope_add("xytoz", &c12_xytoz, c12_sf_marshall);
  sf_debug_symbol_scope_add("xytoz_in", &c12_xytoz_in, c12_sf_marshall);
  sf_debug_symbol_scope_add("gs_in", &c12_gs_in, c12_sf_marshall);
  sf_debug_symbol_scope_add("trigger", &c12_trigger, c12_c_sf_marshall);
  sf_debug_symbol_scope_add("B", &c12_b_B, c12_b_sf_marshall);
  sf_debug_symbol_scope_add("count", &c12_count, c12_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  c12_current_axis = c12_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)
    _SFD_INTEGER_CHECK("count", c12_count), 1, 42, 1, 0) + 125];
  _SFD_EML_CALL(0,5);
  if (CV_EML_IF(0, 0, (real_T)c12_trigger == 1.0)) {
    _SFD_EML_CALL(0,6);
    c12_n = 0.0;
    c12_k = 1.0;
   label_1:
    ;
    if (c12_k <= 2.0) {
      c12_b_k = c12_k;
      c12_hoistedExpr = _SFD_EML_ARRAY_BOUNDS_CHECK("s", (int32_T)
        _SFD_INTEGER_CHECK("k", c12_b_k), 1, 2, 1, 0) - 1;
      if (42.0 + -37.0 * (real_T)c12_hoistedExpr == 0.0) {
        c12_n = 0.0;
      } else {
        c12_b_hoistedExpr = _SFD_EML_ARRAY_BOUNDS_CHECK("s", (int32_T)
          _SFD_INTEGER_CHECK("k", c12_b_k), 1, 2, 1, 0) - 1;
        if (42.0 + -37.0 * (real_T)c12_b_hoistedExpr > c12_n) {
          c12_c_hoistedExpr = _SFD_EML_ARRAY_BOUNDS_CHECK("s", (int32_T)
            _SFD_INTEGER_CHECK("k", c12_b_k), 1, 2, 1, 0) - 1;
          c12_n = 42.0 + -37.0 * (real_T)c12_c_hoistedExpr;
        }

        c12_k = c12_k + 1.0;
        goto label_1;
      }
    }

    if (CV_EML_IF(0, 1, c12_count == c12_n)) {
      _SFD_EML_CALL(0,7);
      c12_xytoz = c12_xytoz_in;
      _SFD_EML_CALL(0,8);
      c12_gradual_state = c12_gs_in;
    } else {
      _SFD_EML_CALL(0,12);
      c12_next_axis = c12_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)
        _SFD_INTEGER_CHECK("", c12_count + 1.0), 1, 42, 1, 0) + 125];
      _SFD_EML_CALL(0,14);
      if (CV_EML_COND(0, 0, c12_current_axis == 1.0)) {
      } else if (CV_EML_COND(0, 1, c12_current_axis == 2.0)) {
      } else {
        CV_EML_MCDC(0, 0, false);
        CV_EML_IF(0, 2, false);
        _SFD_EML_CALL(0,23);
        if (CV_EML_IF(0, 4, c12_next_axis == 3.0)) {
          _SFD_EML_CALL(0,24);
          c12_xytoz = 1.0;
          _SFD_EML_CALL(0,25);
          c12_gradual_state = 1.0;
        } else {
          _SFD_EML_CALL(0,27);
          c12_xytoz = 0.0;
          _SFD_EML_CALL(0,28);
          c12_gradual_state = 0.0;
        }

        goto label_2;
      }

      CV_EML_MCDC(0, 0, true);
      CV_EML_IF(0, 2, true);
      _SFD_EML_CALL(0,15);
      if (CV_EML_IF(0, 3, c12_next_axis == 3.0)) {
        _SFD_EML_CALL(0,16);
        c12_xytoz = 1.0;
        _SFD_EML_CALL(0,17);
        c12_gradual_state = 1.0;
      } else {
        _SFD_EML_CALL(0,19);
        c12_xytoz = 0.0;
        _SFD_EML_CALL(0,20);
        c12_gradual_state = 0.0;
      }

     label_2:
      ;
    }

    /* mod=abs(gradual_state-1); */
    /*      if(gradual_state==1) */
    /*          mod=0; */
    /*      else */
    /*          if(current_axis==3) */
    /*              mod=0; */
    /*          else */
    /*              mod=1; */
    /*          end */
    /*      end */
  } else {
    _SFD_EML_CALL(0,43);
    c12_xytoz = c12_xytoz_in;
    _SFD_EML_CALL(0,44);
    c12_gradual_state = c12_gs_in;

    /*      mod=abs(gradual_state-1); */
    /*      if(gs_in==1) */
    /*          mod=0; */
    /*      else */
    /*          mod=1; */
    /*      end */
  }

  _SFD_EML_CALL(0,54);
  if (CV_EML_IF(0, 5, c12_gradual_state == 1.0)) {
    _SFD_EML_CALL(0,55);
    c12_mod = 0.0;
  } else {
    _SFD_EML_CALL(0,57);
    if (CV_EML_IF(0, 6, c12_current_axis == 3.0)) {
      _SFD_EML_CALL(0,58);
      c12_mod = 0.0;
    } else {
      _SFD_EML_CALL(0,60);
      c12_mod = 1.0;
    }
  }

  _SFD_EML_CALL(0,-60);
  sf_debug_symbol_scope_pop();
  *c12_b_xytoz = c12_xytoz;
  *c12_b_gradual_state = c12_gradual_state;
  *c12_b_mod = c12_mod;
  *c12_b_current_axis = c12_current_axis;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,11);
  _sfEvent_ = c12_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber)
{
}

static const mxArray *c12_sf_marshall(void *c12_chartInstance, void *c12_u)
{
  const mxArray *c12_y = NULL;
  real_T c12_b_u;
  const mxArray *c12_b_y = NULL;
  c12_y = NULL;
  c12_b_u = *((real_T *)c12_u);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c12_y, c12_b_y);
  return c12_y;
}

static const mxArray *c12_b_sf_marshall(void *c12_chartInstance, void *c12_u)
{
  const mxArray *c12_y = NULL;
  int32_T c12_i3;
  int32_T c12_i4;
  int32_T c12_i5;
  real_T c12_b_u[210];
  const mxArray *c12_b_y = NULL;
  c12_y = NULL;
  c12_i3 = 0;
  for (c12_i4 = 0; c12_i4 < 5; c12_i4 = c12_i4 + 1) {
    for (c12_i5 = 0; c12_i5 < 42; c12_i5 = c12_i5 + 1) {
      c12_b_u[c12_i5 + c12_i3] = (*((real_T (*)[210])c12_u))[c12_i5 + c12_i3];
    }

    c12_i3 = c12_i3 + 42;
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 0, 0U, 1U, 0U, 2, 42, 5));
  sf_mex_assign(&c12_y, c12_b_y);
  return c12_y;
}

static const mxArray *c12_c_sf_marshall(void *c12_chartInstance, void *c12_u)
{
  const mxArray *c12_y = NULL;
  boolean_T c12_b_u;
  const mxArray *c12_b_y = NULL;
  c12_y = NULL;
  c12_b_u = *((boolean_T *)c12_u);
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c12_y, c12_b_y);
  return c12_y;
}

const mxArray
  *sf_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  c12_ResolvedFunctionInfo c12_info[6];
  c12_ResolvedFunctionInfo (*c12_b_info)[6];
  const mxArray *c12_m0 = NULL;
  int32_T c12_i6;
  c12_ResolvedFunctionInfo *c12_r0;
  c12_nameCaptureInfo = NULL;
  c12_b_info = (c12_ResolvedFunctionInfo (*)[6])c12_info;
  (*c12_b_info)[0].context = "";
  (*c12_b_info)[0].name = "eq";
  (*c12_b_info)[0].dominantType = "double";
  (*c12_b_info)[0].resolved = "[B]eq";
  (*c12_b_info)[0].fileLength = 0U;
  (*c12_b_info)[0].fileTime1 = 0U;
  (*c12_b_info)[0].fileTime2 = 0U;
  (*c12_b_info)[1].context = "";
  (*c12_b_info)[1].name = "length";
  (*c12_b_info)[1].dominantType = "double";
  (*c12_b_info)[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c12_b_info)[1].fileLength = 326U;
  (*c12_b_info)[1].fileTime1 = 1226577276U;
  (*c12_b_info)[1].fileTime2 = 0U;
  (*c12_b_info)[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c12_b_info)[2].name = "nargin";
  (*c12_b_info)[2].dominantType = "";
  (*c12_b_info)[2].resolved = "[B]nargin";
  (*c12_b_info)[2].fileLength = 0U;
  (*c12_b_info)[2].fileTime1 = 0U;
  (*c12_b_info)[2].fileTime2 = 0U;
  (*c12_b_info)[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c12_b_info)[3].name = "size";
  (*c12_b_info)[3].dominantType = "double";
  (*c12_b_info)[3].resolved = "[B]size";
  (*c12_b_info)[3].fileLength = 0U;
  (*c12_b_info)[3].fileTime1 = 0U;
  (*c12_b_info)[3].fileTime2 = 0U;
  (*c12_b_info)[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c12_b_info)[4].name = "gt";
  (*c12_b_info)[4].dominantType = "double";
  (*c12_b_info)[4].resolved = "[B]gt";
  (*c12_b_info)[4].fileLength = 0U;
  (*c12_b_info)[4].fileTime1 = 0U;
  (*c12_b_info)[4].fileTime2 = 0U;
  (*c12_b_info)[5].context = "";
  (*c12_b_info)[5].name = "plus";
  (*c12_b_info)[5].dominantType = "double";
  (*c12_b_info)[5].resolved = "[B]plus";
  (*c12_b_info)[5].fileLength = 0U;
  (*c12_b_info)[5].fileTime1 = 0U;
  (*c12_b_info)[5].fileTime2 = 0U;
  sf_mex_assign(&c12_m0, sf_mex_createstruct("nameCaptureInfo", 1, 6));
  for (c12_i6 = 0; c12_i6 < 6; c12_i6 = c12_i6 + 1) {
    c12_r0 = &c12_info[c12_i6];
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->context)), "context"
                    , "nameCaptureInfo", c12_i6);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->name)), "name",
                    "nameCaptureInfo", c12_i6);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      c12_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c12_i6);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->resolved)),
                    "resolved", "nameCaptureInfo", c12_i6);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c12_i6);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c12_i6);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c12_i6);
  }

  sf_mex_assign(&c12_nameCaptureInfo, c12_m0);
  return c12_nameCaptureInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1504344488U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3440443922U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(493166761U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(786483085U);
}

mxArray
  *sf_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4132558717U);
    pr[1] = (double)(2578696683U);
    pr[2] = (double)(3550300293U);
    pr[3] = (double)(2333184038U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray
  *sf_get_sim_state_info_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[24],T\"current_axis\",},{M[1],M[20],T\"gradual_state\",},{M[1],M[23],T\"mod\",},{M[1],M[5],T\"xytoz\",},{M[8],M[0],T\"is_active_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(&mxChecksum);
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
           12,
           1,
           1,
           9,
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
                              (MexFcnForType)c12_sf_marshall);

          {
            unsigned int dimVector[2];
            dimVector[0]= 42;
            dimVector[1]= 5;
            _SFD_SET_DATA_PROPS(1,10,0,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"B",0,(MexFcnForType)c12_b_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"xytoz",0,
                              (MexFcnForType)c12_sf_marshall);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"trigger",
                              0,(MexFcnForType)c12_c_sf_marshall);
          _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "gradual_state",0,(MexFcnForType)c12_sf_marshall);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"gs_in",0,
                              (MexFcnForType)c12_sf_marshall);
          _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "xytoz_in",0,(MexFcnForType)c12_sf_marshall);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"mod",0,
                              (MexFcnForType)c12_sf_marshall);
          _SFD_SET_DATA_PROPS(8,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "current_axis",0,(MexFcnForType)c12_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,7,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1192);
        _SFD_CV_INIT_EML_IF(0,0,122,135,912,1071);
        _SFD_CV_INIT_EML_IF(0,1,140,159,226,714);
        _SFD_CV_INIT_EML_IF(0,2,289,325,512,706);
        _SFD_CV_INIT_EML_IF(0,3,338,354,425,503);
        _SFD_CV_INIT_EML_IF(0,4,529,545,616,694);
        _SFD_CV_INIT_EML_IF(0,5,1074,1094,1106,1185);
        _SFD_CV_INIT_EML_IF(0,6,1115,1134,1154,1181);

        {
          static int condStart[] = { 292, 309 };

          static int condEnd[] = { 307, 324 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,0,292,324,2,0,&(condStart[0]),&(condEnd[0]),3,
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
          real_T *c12_count;
          real_T *c12_xytoz;
          boolean_T *c12_trigger;
          real_T *c12_gradual_state;
          real_T *c12_gs_in;
          real_T *c12_xytoz_in;
          real_T *c12_mod;
          real_T *c12_current_axis;
          c12_gradual_state = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c12_current_axis = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
          c12_xytoz = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c12_xytoz_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c12_trigger = (boolean_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c12_mod = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c12_count = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c12_gs_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          _SFD_SET_DATA_VALUE_PTR(0U, c12_count);
          _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance.c12_B);
          _SFD_SET_DATA_VALUE_PTR(2U, c12_xytoz);
          _SFD_SET_DATA_VALUE_PTR(3U, c12_trigger);
          _SFD_SET_DATA_VALUE_PTR(4U, c12_gradual_state);
          _SFD_SET_DATA_VALUE_PTR(5U, c12_gs_in);
          _SFD_SET_DATA_VALUE_PTR(6U, c12_xytoz_in);
          _SFD_SET_DATA_VALUE_PTR(7U, c12_mod);
          _SFD_SET_DATA_VALUE_PTR(8U, c12_current_axis);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  initialize_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_enable_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  enable_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_disable_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  disable_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_gateway_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  sf_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void
  sf_opaque_ext_mode_exec_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  ext_mode_exec_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static mxArray*
  sf_opaque_get_sim_state_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  return st;
}

static void
  sf_opaque_set_sim_state_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(sf_mex_dup(st));
}

static void sf_opaque_terminate_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim
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
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",12,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",12,4);
      sf_mark_chart_reusable_outputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",12,4);
    }

    sf_set_rtw_dwork_info(S,"M37_Sim_Forcing_003h_expe_infra_transz_lim",
                          "M37_Sim_Forcing_003h_expe_infra_transz_lim",12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(242540986U));
  ssSetChecksum1(S,(3687824256U));
  ssSetChecksum2(S,(3317444121U));
  ssSetChecksum3(S,(3603997037U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",12);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim;
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

void c12_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(SimStruct *
  S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

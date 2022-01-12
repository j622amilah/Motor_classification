/* Include files */

#include "blascompat32.h"
#include "Sim_Forcing_003h_expe_infra5_full_control5_sfun.h"
#include "c8_Sim_Forcing_003h_expe_infra5_full_control5.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "Sim_Forcing_003h_expe_infra5_full_control5_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c8_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc8_Sim_Forcing_003h_expe_infra5_full_control5InstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c8_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void initialize_params_c8_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void enable_c8_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void disable_c8_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void c8_update_debugger_state_c8_Sim_Forcing_003h_expe_infra5_full_c(void);
static void ext_mode_exec_c8_Sim_Forcing_003h_expe_infra5_full_control5(void);
static const mxArray
  *get_sim_state_c8_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void set_sim_state_c8_Sim_Forcing_003h_expe_infra5_full_control5(const
  mxArray *c8_st);
static void finalize_c8_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void sf_c8_Sim_Forcing_003h_expe_infra5_full_control5(void);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static void c8_mldivide(real_T c8_A[9], real_T c8_B[3], real_T c8_Y[3]);
static void c8_eml_warning(void);
static void c8_eml_scalar_eg(void);
static real_T c8_ceval_xdot(int32_T c8_n, real_T c8_x[3], int32_T c8_ix0,
  int32_T c8_incx, real_T c8_y[3], int32_T c8_iy0, int32_T c8_incy);
static const mxArray *c8_sf_marshall(void *c8_chartInstance, void *c8_u);
static const mxArray *c8_b_sf_marshall(void *c8_chartInstance, void *c8_u);
static const mxArray *c8_c_sf_marshall(void *c8_chartInstance, void *c8_u);
static const mxArray *c8_d_sf_marshall(void *c8_chartInstance, void *c8_u);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[50]);
static const mxArray *c8_e_sf_marshall(void *c8_chartInstance, void *c8_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c8_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  uint8_T *c8_is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  c8_is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5 = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c8_is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5 = 0U;
}

static void initialize_params_c8_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
}

static void enable_c8_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c8_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c8_update_debugger_state_c8_Sim_Forcing_003h_expe_infra5_full_c(void)
{
}

static void ext_mode_exec_c8_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  c8_update_debugger_state_c8_Sim_Forcing_003h_expe_infra5_full_c();
}

static const mxArray
  *get_sim_state_c8_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  const mxArray *c8_st = NULL;
  const mxArray *c8_y = NULL;
  int32_T c8_i0;
  real_T c8_u[3];
  const mxArray *c8_b_y = NULL;
  real_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  real_T c8_d_u;
  const mxArray *c8_e_y = NULL;
  int32_T c8_i1;
  real_T c8_e_u[3];
  const mxArray *c8_f_y = NULL;
  uint8_T c8_f_u;
  const mxArray *c8_g_y = NULL;
  real_T *c8_psi;
  real_T *c8_x;
  real_T *c8_z;
  uint8_T *c8_is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  real_T (*c8_z_p)[3];
  real_T (*c8_c)[3];
  c8_c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 4);
  c8_psi = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c8_z_p = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 5);
  c8_x = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c8_z = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c8_is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5 = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(6));
  for (c8_i0 = 0; c8_i0 < 3; c8_i0 = c8_i0 + 1) {
    c8_u[c8_i0] = (*c8_c)[c8_i0];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_u = *c8_psi;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_u = *c8_x;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_d_u = *c8_z;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 3, c8_e_y);
  for (c8_i1 = 0; c8_i1 < 3; c8_i1 = c8_i1 + 1) {
    c8_e_u[c8_i1] = (*c8_z_p)[c8_i1];
  }

  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", &c8_e_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c8_y, 4, c8_f_y);
  c8_f_u = *c8_is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  c8_g_y = NULL;
  sf_mex_assign(&c8_g_y, sf_mex_create("y", &c8_f_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 5, c8_g_y);
  sf_mex_assign(&c8_st, c8_y);
  return c8_st;
}

static void set_sim_state_c8_Sim_Forcing_003h_expe_infra5_full_control5(const
  mxArray *c8_st)
{
  const mxArray *c8_u;
  const mxArray *c8_c;
  real_T c8_dv0[3];
  int32_T c8_i2;
  real_T c8_y[3];
  int32_T c8_i3;
  const mxArray *c8_psi;
  real_T c8_d0;
  real_T c8_b_y;
  const mxArray *c8_b_psi;
  real_T c8_d1;
  real_T c8_c_y;
  const mxArray *c8_c_psi;
  real_T c8_d2;
  real_T c8_d_y;
  const mxArray *c8_b_c;
  real_T c8_dv1[3];
  int32_T c8_i4;
  real_T c8_e_y[3];
  int32_T c8_i5;
  const mxArray *c8_is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  uint8_T c8_u0;
  uint8_T c8_f_y;
  boolean_T *c8_doneDoubleBufferReInit;
  real_T *c8_d_psi;
  real_T *c8_x;
  real_T *c8_z;
  uint8_T *c8_b_is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  real_T (*c8_c_c)[3];
  real_T (*c8_z_p)[3];
  c8_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c8_c_c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 4);
  c8_d_psi = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c8_z_p = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 5);
  c8_x = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c8_z = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c8_b_is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5 = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  *c8_doneDoubleBufferReInit = true;
  c8_u = sf_mex_dup(c8_st);
  c8_c = sf_mex_dup(sf_mex_getcell(c8_u, 0));
  sf_mex_import("c", sf_mex_dup(c8_c), &c8_dv0, 1, 0, 0U, 1, 0U, 1, 3);
  for (c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
    c8_y[c8_i2] = c8_dv0[c8_i2];
  }

  sf_mex_destroy(&c8_c);
  for (c8_i3 = 0; c8_i3 < 3; c8_i3 = c8_i3 + 1) {
    (*c8_c_c)[c8_i3] = c8_y[c8_i3];
  }

  c8_psi = sf_mex_dup(sf_mex_getcell(c8_u, 1));
  sf_mex_import("psi", sf_mex_dup(c8_psi), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_b_y = c8_d0;
  sf_mex_destroy(&c8_psi);
  *c8_d_psi = c8_b_y;
  c8_b_psi = sf_mex_dup(sf_mex_getcell(c8_u, 2));
  sf_mex_import("x", sf_mex_dup(c8_b_psi), &c8_d1, 1, 0, 0U, 0, 0U, 0);
  c8_c_y = c8_d1;
  sf_mex_destroy(&c8_b_psi);
  *c8_x = c8_c_y;
  c8_c_psi = sf_mex_dup(sf_mex_getcell(c8_u, 3));
  sf_mex_import("z", sf_mex_dup(c8_c_psi), &c8_d2, 1, 0, 0U, 0, 0U, 0);
  c8_d_y = c8_d2;
  sf_mex_destroy(&c8_c_psi);
  *c8_z = c8_d_y;
  c8_b_c = sf_mex_dup(sf_mex_getcell(c8_u, 4));
  sf_mex_import("z_p", sf_mex_dup(c8_b_c), &c8_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c8_i4 = 0; c8_i4 < 3; c8_i4 = c8_i4 + 1) {
    c8_e_y[c8_i4] = c8_dv1[c8_i4];
  }

  sf_mex_destroy(&c8_b_c);
  for (c8_i5 = 0; c8_i5 < 3; c8_i5 = c8_i5 + 1) {
    (*c8_z_p)[c8_i5] = c8_e_y[c8_i5];
  }

  c8_is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5 = sf_mex_dup
    (sf_mex_getcell(c8_u, 5));
  sf_mex_import("is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5",
                sf_mex_dup(
    c8_is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5), &c8_u0, 1, 3,
                0U, 0, 0U, 0);
  c8_f_y = c8_u0;
  sf_mex_destroy(&c8_is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5);
  *c8_b_is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5 = c8_f_y;
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_Sim_Forcing_003h_expe_infra5_full_c();
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
}

static void sf_c8_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  int32_T c8_i6;
  int32_T c8_i7;
  int32_T c8_i8;
  int32_T c8_previousEvent;
  int32_T c8_i9;
  real_T c8_set[6];
  real_T c8_psi_set;
  real_T c8_fraction;
  real_T c8_nargout = 5.0;
  real_T c8_nargin = 3.0;
  real_T c8_A[9];
  real_T c8_x_p[3];
  real_T c8_z_p[3];
  real_T c8_c[3];
  real_T c8_psi;
  real_T c8_z;
  real_T c8_x;
  int32_T c8_i10;
  int32_T c8_i11;
  int32_T c8_i12;
  int32_T c8_i13;
  int32_T c8_i14;
  int32_T c8_i15;
  real_T c8_b_A[9];
  int32_T c8_i16;
  real_T c8_b_x_p[3];
  real_T c8_dv2[3];
  int32_T c8_i17;
  real_T c8_a;
  real_T c8_b;
  real_T c8_y;
  real_T c8_b_a[3];
  int32_T c8_i18;
  real_T c8_b_b[3];
  int32_T c8_i19;
  real_T c8_b_x[3];
  int32_T c8_i20;
  real_T c8_b_y[3];
  int32_T c8_i21;
  real_T c8_c_x[3];
  int32_T c8_i22;
  real_T c8_c_y[3];
  int32_T c8_i23;
  real_T c8_d_x[3];
  int32_T c8_i24;
  real_T c8_d_y[3];
  int32_T c8_i25;
  real_T c8_e_x[3];
  int32_T c8_i26;
  real_T c8_e_y[3];
  real_T c8_c_a;
  real_T c8_c_b;
  int32_T c8_i27;
  int32_T c8_i28;
  real_T *c8_b_psi_set;
  real_T *c8_f_x;
  real_T *c8_b_fraction;
  real_T *c8_b_z;
  real_T *c8_b_psi;
  real_T (*c8_b_c)[3];
  real_T (*c8_b_z_p)[3];
  real_T (*c8_b_set)[6];
  c8_b_c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 4);
  c8_b_psi = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c8_b_z_p = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 5);
  c8_b_set = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 0);
  c8_b_fraction = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c8_f_x = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c8_b_z = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c8_b_psi_set = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,6);
  for (c8_i6 = 0; c8_i6 < 6; c8_i6 = c8_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c8_b_set)[c8_i6], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c8_b_psi_set, 1U);
  _SFD_DATA_RANGE_CHECK(*c8_f_x, 2U);
  _SFD_DATA_RANGE_CHECK(*c8_b_fraction, 3U);
  _SFD_DATA_RANGE_CHECK(*c8_b_z, 4U);
  _SFD_DATA_RANGE_CHECK(*c8_b_psi, 5U);
  for (c8_i7 = 0; c8_i7 < 3; c8_i7 = c8_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c8_b_c)[c8_i7], 6U);
  }

  for (c8_i8 = 0; c8_i8 < 3; c8_i8 = c8_i8 + 1) {
    _SFD_DATA_RANGE_CHECK((*c8_b_z_p)[c8_i8], 7U);
  }

  c8_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,6);
  for (c8_i9 = 0; c8_i9 < 6; c8_i9 = c8_i9 + 1) {
    c8_set[c8_i9] = (*c8_b_set)[c8_i9];
  }

  c8_psi_set = *c8_b_psi_set;
  c8_fraction = *c8_b_fraction;
  sf_debug_symbol_scope_push(12U, 0U);
  sf_debug_symbol_scope_add("nargout", &c8_nargout, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c8_nargin, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("A", &c8_A, c8_d_sf_marshall);
  sf_debug_symbol_scope_add("x_p", &c8_x_p, c8_c_sf_marshall);
  sf_debug_symbol_scope_add("z_p", &c8_z_p, c8_c_sf_marshall);
  sf_debug_symbol_scope_add("c", &c8_c, c8_c_sf_marshall);
  sf_debug_symbol_scope_add("psi", &c8_psi, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("z", &c8_z, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("x", &c8_x, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("fraction", &c8_fraction, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("psi_set", &c8_psi_set, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("set", &c8_set, c8_sf_marshall);
  CV_EML_FCN(0, 0);

  /* ************************************************************************** */
  /*  */
  /*  for fitting a parabolic curve through 3 points */
  /*  */
  /*    set is a 3 x 2 matrix that include: */
  /*        (x1, z1) */
  /*        (x2, z2) */
  /*        (x3, z3) */
  /*  */
  /*    z is the abcis and x the ordinate of the curve */
  /*    fraction runs from 0 to 1 */
  /*  */
  /* ************************************************************************** */
  _SFD_EML_CALL(0,17);
  for (c8_i10 = 0; c8_i10 < 3; c8_i10 = c8_i10 + 1) {
    c8_z_p[c8_i10] = c8_set[c8_i10 + 3];
  }

  _SFD_EML_CALL(0,18);
  for (c8_i11 = 0; c8_i11 < 3; c8_i11 = c8_i11 + 1) {
    c8_x_p[c8_i11] = c8_set[c8_i11];
  }

  _SFD_EML_CALL(0,20);
  for (c8_i12 = 0; c8_i12 < 3; c8_i12 = c8_i12 + 1) {
    c8_A[c8_i12] = c8_z_p[c8_i12] * c8_z_p[c8_i12];
  }

  for (c8_i13 = 0; c8_i13 < 3; c8_i13 = c8_i13 + 1) {
    c8_A[c8_i13 + 3] = c8_z_p[c8_i13];
  }

  for (c8_i14 = 0; c8_i14 < 3; c8_i14 = c8_i14 + 1) {
    c8_A[c8_i14 + 6] = 1.0;
  }

  _SFD_EML_CALL(0,21);
  for (c8_i15 = 0; c8_i15 < 9; c8_i15 = c8_i15 + 1) {
    c8_b_A[c8_i15] = c8_A[c8_i15];
  }

  for (c8_i16 = 0; c8_i16 < 3; c8_i16 = c8_i16 + 1) {
    c8_b_x_p[c8_i16] = c8_x_p[c8_i16];
  }

  c8_mldivide(c8_b_A, c8_b_x_p, c8_dv2);
  for (c8_i17 = 0; c8_i17 < 3; c8_i17 = c8_i17 + 1) {
    c8_c[c8_i17] = c8_dv2[c8_i17];
  }

  _SFD_EML_CALL(0,23);
  c8_a = c8_fraction;
  c8_b = c8_z_p[2] - c8_z_p[0];
  c8_y = c8_a * c8_b;
  c8_z = c8_y + c8_z_p[0];
  _SFD_EML_CALL(0,25);
  c8_b_a[0] = c8_z * c8_z;
  c8_b_a[1] = c8_z;
  c8_b_a[2] = 1.0;
  for (c8_i18 = 0; c8_i18 < 3; c8_i18 = c8_i18 + 1) {
    c8_b_b[c8_i18] = c8_c[c8_i18];
  }

  c8_eml_scalar_eg();
  for (c8_i19 = 0; c8_i19 < 3; c8_i19 = c8_i19 + 1) {
    c8_b_x[c8_i19] = c8_b_a[c8_i19];
  }

  for (c8_i20 = 0; c8_i20 < 3; c8_i20 = c8_i20 + 1) {
    c8_b_y[c8_i20] = c8_b_b[c8_i20];
  }

  for (c8_i21 = 0; c8_i21 < 3; c8_i21 = c8_i21 + 1) {
    c8_c_x[c8_i21] = c8_b_x[c8_i21];
  }

  for (c8_i22 = 0; c8_i22 < 3; c8_i22 = c8_i22 + 1) {
    c8_c_y[c8_i22] = c8_b_y[c8_i22];
  }

  for (c8_i23 = 0; c8_i23 < 3; c8_i23 = c8_i23 + 1) {
    c8_d_x[c8_i23] = c8_c_x[c8_i23];
  }

  for (c8_i24 = 0; c8_i24 < 3; c8_i24 = c8_i24 + 1) {
    c8_d_y[c8_i24] = c8_c_y[c8_i24];
  }

  for (c8_i25 = 0; c8_i25 < 3; c8_i25 = c8_i25 + 1) {
    c8_e_x[c8_i25] = c8_d_x[c8_i25];
  }

  for (c8_i26 = 0; c8_i26 < 3; c8_i26 = c8_i26 + 1) {
    c8_e_y[c8_i26] = c8_d_y[c8_i26];
  }

  c8_x = c8_ceval_xdot(3, c8_e_x, 1, 1, c8_e_y, 1, 1);
  _SFD_EML_CALL(0,27);
  c8_c_a = c8_fraction;
  c8_c_b = c8_psi_set;
  c8_psi = c8_c_a * c8_c_b;
  _SFD_EML_CALL(0,-27);
  sf_debug_symbol_scope_pop();
  *c8_f_x = c8_x;
  *c8_b_z = c8_z;
  *c8_b_psi = c8_psi;
  for (c8_i27 = 0; c8_i27 < 3; c8_i27 = c8_i27 + 1) {
    (*c8_b_c)[c8_i27] = c8_c[c8_i27];
  }

  for (c8_i28 = 0; c8_i28 < 3; c8_i28 = c8_i28 + 1) {
    (*c8_b_z_p)[c8_i28] = c8_z_p[c8_i28];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
  _sfEvent_ = c8_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_Sim_Forcing_003h_expe_infra5_full_control5MachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static void c8_mldivide(real_T c8_A[9], real_T c8_B[3], real_T c8_Y[3])
{
  int32_T c8_i29;
  real_T c8_b_A[9];
  int32_T c8_i30;
  real_T c8_b_B[3];
  int32_T c8_i31;
  real_T c8_c_A[9];
  int32_T c8_i32;
  real_T c8_c_B[3];
  int32_T c8_r1;
  int32_T c8_r2;
  int32_T c8_r3;
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_y;
  real_T c8_d_x;
  real_T c8_e_x;
  real_T c8_b_y;
  real_T c8_maxval;
  real_T c8_f_x;
  real_T c8_g_x;
  real_T c8_h_x;
  real_T c8_c_y;
  real_T c8_i_x;
  real_T c8_j_x;
  real_T c8_d_y;
  real_T c8_a21;
  real_T c8_k_x;
  real_T c8_l_x;
  real_T c8_m_x;
  real_T c8_e_y;
  real_T c8_n_x;
  real_T c8_o_x;
  real_T c8_f_y;
  real_T c8_d;
  real_T c8_p_x;
  real_T c8_g_y;
  real_T c8_q_x;
  real_T c8_h_y;
  real_T c8_z;
  real_T c8_r_x;
  real_T c8_i_y;
  real_T c8_s_x;
  real_T c8_j_y;
  real_T c8_b_z;
  real_T c8_a;
  real_T c8_b;
  real_T c8_k_y;
  real_T c8_b_a;
  real_T c8_b_b;
  real_T c8_l_y;
  real_T c8_c_a;
  real_T c8_c_b;
  real_T c8_m_y;
  real_T c8_d_a;
  real_T c8_d_b;
  real_T c8_n_y;
  real_T c8_t_x;
  real_T c8_u_x;
  real_T c8_v_x;
  real_T c8_o_y;
  real_T c8_w_x;
  real_T c8_x_x;
  real_T c8_p_y;
  real_T c8_b_d;
  real_T c8_y_x;
  real_T c8_ab_x;
  real_T c8_bb_x;
  real_T c8_q_y;
  real_T c8_cb_x;
  real_T c8_db_x;
  real_T c8_r_y;
  real_T c8_c_d;
  int32_T c8_rtemp;
  real_T c8_eb_x;
  real_T c8_s_y;
  real_T c8_fb_x;
  real_T c8_t_y;
  real_T c8_c_z;
  real_T c8_e_a;
  real_T c8_e_b;
  real_T c8_u_y;
  real_T c8_f_a;
  real_T c8_f_b;
  real_T c8_v_y;
  real_T c8_g_a;
  real_T c8_g_b;
  real_T c8_w_y;
  real_T c8_h_a;
  real_T c8_h_b;
  real_T c8_x_y;
  real_T c8_gb_x;
  real_T c8_y_y;
  real_T c8_hb_x;
  real_T c8_ab_y;
  real_T c8_d_z;
  real_T c8_i_a;
  real_T c8_i_b;
  real_T c8_bb_y;
  real_T c8_j_a;
  real_T c8_j_b;
  real_T c8_cb_y;
  real_T c8_ib_x;
  real_T c8_db_y;
  real_T c8_jb_x;
  real_T c8_eb_y;
  real_T c8_e_z;
  real_T c8_k_a;
  real_T c8_k_b;
  real_T c8_fb_y;
  real_T c8_kb_x;
  real_T c8_gb_y;
  real_T c8_lb_x;
  real_T c8_hb_y;
  real_T c8_f_z;
  for (c8_i29 = 0; c8_i29 < 9; c8_i29 = c8_i29 + 1) {
    c8_b_A[c8_i29] = c8_A[c8_i29];
  }

  for (c8_i30 = 0; c8_i30 < 3; c8_i30 = c8_i30 + 1) {
    c8_b_B[c8_i30] = c8_B[c8_i30];
  }

  for (c8_i31 = 0; c8_i31 < 9; c8_i31 = c8_i31 + 1) {
    c8_c_A[c8_i31] = c8_b_A[c8_i31];
  }

  for (c8_i32 = 0; c8_i32 < 3; c8_i32 = c8_i32 + 1) {
    c8_c_B[c8_i32] = c8_b_B[c8_i32];
  }

  c8_r1 = 1;
  c8_r2 = 2;
  c8_r3 = 3;
  c8_x = c8_c_A[0];
  c8_b_x = 0.0;
  c8_c_x = c8_b_x;
  c8_y = muDoubleScalarAbs(c8_c_x);
  c8_d_x = c8_x;
  c8_e_x = c8_d_x;
  c8_b_y = muDoubleScalarAbs(c8_e_x);
  c8_maxval = c8_b_y + c8_y;
  c8_f_x = c8_c_A[1];
  c8_g_x = 0.0;
  c8_h_x = c8_g_x;
  c8_c_y = muDoubleScalarAbs(c8_h_x);
  c8_i_x = c8_f_x;
  c8_j_x = c8_i_x;
  c8_d_y = muDoubleScalarAbs(c8_j_x);
  c8_a21 = c8_d_y + c8_c_y;
  if (c8_a21 > c8_maxval) {
    c8_maxval = c8_a21;
    c8_r1 = 2;
    c8_r2 = 1;
  }

  c8_k_x = c8_c_A[2];
  c8_l_x = 0.0;
  c8_m_x = c8_l_x;
  c8_e_y = muDoubleScalarAbs(c8_m_x);
  c8_n_x = c8_k_x;
  c8_o_x = c8_n_x;
  c8_f_y = muDoubleScalarAbs(c8_o_x);
  c8_d = c8_f_y + c8_e_y;
  if (c8_d > c8_maxval) {
    c8_r1 = 3;
    c8_r2 = 2;
    c8_r3 = 1;
  }

  c8_p_x = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r2", (real_T)c8_r2), 1, 3, 1, 0) - 1];
  c8_g_y = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r1", (real_T)c8_r1), 1, 3, 1, 0) - 1];
  c8_q_x = c8_p_x;
  c8_h_y = c8_g_y;
  c8_z = c8_q_x / c8_h_y;
  c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r2",
    (real_T)c8_r2), 1, 3, 1, 0) - 1] = c8_z;
  c8_r_x = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r3", (real_T)c8_r3), 1, 3, 1, 0) - 1];
  c8_i_y = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r1", (real_T)c8_r1), 1, 3, 1, 0) - 1];
  c8_s_x = c8_r_x;
  c8_j_y = c8_i_y;
  c8_b_z = c8_s_x / c8_j_y;
  c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3",
    (real_T)c8_r3), 1, 3, 1, 0) - 1] = c8_b_z;
  c8_a = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r2", (real_T)c8_r2), 1, 3, 1, 0) - 1];
  c8_b = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r1", (real_T)c8_r1), 1, 3, 1, 0) + 2];
  c8_k_y = c8_a * c8_b;
  c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r2",
    (real_T)c8_r2), 1, 3, 1, 0) + 2] = c8_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r2", (real_T)
    c8_r2), 1, 3, 1, 0) + 2] - c8_k_y;
  c8_b_a = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r3", (real_T)c8_r3), 1, 3, 1, 0) - 1];
  c8_b_b = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r1", (real_T)c8_r1), 1, 3, 1, 0) + 2];
  c8_l_y = c8_b_a * c8_b_b;
  c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3",
    (real_T)c8_r3), 1, 3, 1, 0) + 2] = c8_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3", (real_T)
    c8_r3), 1, 3, 1, 0) + 2] - c8_l_y;
  c8_c_a = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r2", (real_T)c8_r2), 1, 3, 1, 0) - 1];
  c8_c_b = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r1", (real_T)c8_r1), 1, 3, 1, 0) + 5];
  c8_m_y = c8_c_a * c8_c_b;
  c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r2",
    (real_T)c8_r2), 1, 3, 1, 0) + 5] = c8_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r2", (real_T)
    c8_r2), 1, 3, 1, 0) + 5] - c8_m_y;
  c8_d_a = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r3", (real_T)c8_r3), 1, 3, 1, 0) - 1];
  c8_d_b = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r1", (real_T)c8_r1), 1, 3, 1, 0) + 5];
  c8_n_y = c8_d_a * c8_d_b;
  c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3",
    (real_T)c8_r3), 1, 3, 1, 0) + 5] = c8_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3", (real_T)
    c8_r3), 1, 3, 1, 0) + 5] - c8_n_y;
  c8_t_x = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r2", (real_T)c8_r2), 1, 3, 1, 0) + 2];
  c8_u_x = 0.0;
  c8_v_x = c8_u_x;
  c8_o_y = muDoubleScalarAbs(c8_v_x);
  c8_w_x = c8_t_x;
  c8_x_x = c8_w_x;
  c8_p_y = muDoubleScalarAbs(c8_x_x);
  c8_b_d = c8_p_y + c8_o_y;
  c8_y_x = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r3", (real_T)c8_r3), 1, 3, 1, 0) + 2];
  c8_ab_x = 0.0;
  c8_bb_x = c8_ab_x;
  c8_q_y = muDoubleScalarAbs(c8_bb_x);
  c8_cb_x = c8_y_x;
  c8_db_x = c8_cb_x;
  c8_r_y = muDoubleScalarAbs(c8_db_x);
  c8_c_d = c8_r_y + c8_q_y;
  if (c8_c_d > c8_b_d) {
    c8_rtemp = c8_r2;
    c8_r2 = c8_r3;
    c8_r3 = c8_rtemp;
  }

  c8_eb_x = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r3", (real_T)c8_r3), 1, 3, 1, 0) + 2];
  c8_s_y = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r2", (real_T)c8_r2), 1, 3, 1, 0) + 2];
  c8_fb_x = c8_eb_x;
  c8_t_y = c8_s_y;
  c8_c_z = c8_fb_x / c8_t_y;
  c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3",
    (real_T)c8_r3), 1, 3, 1, 0) + 2] = c8_c_z;
  c8_e_a = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r3", (real_T)c8_r3), 1, 3, 1, 0) + 2];
  c8_e_b = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r2", (real_T)c8_r2), 1, 3, 1, 0) + 5];
  c8_u_y = c8_e_a * c8_e_b;
  c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3",
    (real_T)c8_r3), 1, 3, 1, 0) + 5] = c8_c_A[
    _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r3", (real_T)
    c8_r3), 1, 3, 1, 0) + 5] - c8_u_y;
  if (c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("r1",
        (real_T)c8_r1), 1, 3, 1, 0) - 1] == 0.0) {
  } else if (c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
              ("r2", (real_T)c8_r2), 1, 3, 1, 0) + 2] == 0.0) {
  } else if (c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK
              ("r3", (real_T)c8_r3), 1, 3, 1, 0) + 5] == 0.0) {
    goto label_1;
  } else {
    goto label_2;
  }

 label_1:
  ;
  c8_eml_warning();
 label_2:
  ;
  c8_Y[0] = c8_c_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)_SFD_INTEGER_CHECK(
    "r1", (real_T)c8_r1), 1, 3, 1, 0) - 1];
  c8_f_a = c8_Y[0];
  c8_f_b = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r2", (real_T)c8_r2), 1, 3, 1, 0) - 1];
  c8_v_y = c8_f_a * c8_f_b;
  c8_Y[1] = c8_c_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)_SFD_INTEGER_CHECK(
    "r2", (real_T)c8_r2), 1, 3, 1, 0) - 1] - c8_v_y;
  c8_g_a = c8_Y[1];
  c8_g_b = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r3", (real_T)c8_r3), 1, 3, 1, 0) + 2];
  c8_w_y = c8_g_a * c8_g_b;
  c8_h_a = c8_Y[0];
  c8_h_b = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r3", (real_T)c8_r3), 1, 3, 1, 0) - 1];
  c8_x_y = c8_h_a * c8_h_b;
  c8_Y[2] = (c8_c_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)_SFD_INTEGER_CHECK
              ("r3", (real_T)c8_r3), 1, 3, 1, 0) - 1] - c8_x_y) -
    c8_w_y;
  c8_gb_x = c8_Y[2];
  c8_y_y = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r3", (real_T)c8_r3), 1, 3, 1, 0) + 5];
  c8_hb_x = c8_gb_x;
  c8_ab_y = c8_y_y;
  c8_d_z = c8_hb_x / c8_ab_y;
  c8_Y[2] = c8_d_z;
  c8_i_a = c8_Y[2];
  c8_i_b = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r1", (real_T)c8_r1), 1, 3, 1, 0) + 5];
  c8_bb_y = c8_i_a * c8_i_b;
  c8_Y[0] = c8_Y[0] - c8_bb_y;
  c8_j_a = c8_Y[2];
  c8_j_b = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r2", (real_T)c8_r2), 1, 3, 1, 0) + 5];
  c8_cb_y = c8_j_a * c8_j_b;
  c8_Y[1] = c8_Y[1] - c8_cb_y;
  c8_ib_x = c8_Y[1];
  c8_db_y = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r2", (real_T)c8_r2), 1, 3, 1, 0) + 2];
  c8_jb_x = c8_ib_x;
  c8_eb_y = c8_db_y;
  c8_e_z = c8_jb_x / c8_eb_y;
  c8_Y[1] = c8_e_z;
  c8_k_a = c8_Y[1];
  c8_k_b = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r1", (real_T)c8_r1), 1, 3, 1, 0) + 2];
  c8_fb_y = c8_k_a * c8_k_b;
  c8_Y[0] = c8_Y[0] - c8_fb_y;
  c8_kb_x = c8_Y[0];
  c8_gb_y = c8_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
    "r1", (real_T)c8_r1), 1, 3, 1, 0) - 1];
  c8_lb_x = c8_kb_x;
  c8_hb_y = c8_gb_y;
  c8_f_z = c8_lb_x / c8_hb_y;
  c8_Y[0] = c8_f_z;
}

static void c8_eml_warning(void)
{
  int32_T c8_i33;
  static char_T c8_cv0[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't', 'o'
    , ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i', 's',
    'i', 'o', 'n', '.' };

  char_T c8_u[40];
  const mxArray *c8_y = NULL;
  int32_T c8_i34;
  static char_T c8_cv1[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x'
  };

  char_T c8_b_u[21];
  const mxArray *c8_b_y = NULL;
  for (c8_i33 = 0; c8_i33 < 40; c8_i33 = c8_i33 + 1) {
    c8_u[c8_i33] = c8_cv0[c8_i33];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 10, 0U, 1U, 0U, 2, 1, 40));
  for (c8_i34 = 0; c8_i34 < 21; c8_i34 = c8_i34 + 1) {
    c8_b_u[c8_i34] = c8_cv1[c8_i34];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 10, 0U, 1U, 0U, 2, 1, 21));
  sf_mex_call_debug("warning", 0U, 2U, 14, c8_b_y, 14, c8_y);
}

static void c8_eml_scalar_eg(void)
{
}

static real_T c8_ceval_xdot(int32_T c8_n, real_T c8_x[3], int32_T c8_ix0,
  int32_T c8_incx, real_T c8_y[3], int32_T c8_iy0, int32_T
  c8_incy)
{
  real_T c8_d;
  c8_d = 0.0;
  if ((real_T)c8_n > 0.0) {
    return ddot32(&c8_n, &c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
      _SFD_INTEGER_CHECK("ix0", (real_T)c8_ix0), 1, 3, 1, 0) - 1], &
                  c8_incx, &c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
      _SFD_INTEGER_CHECK("iy0", (real_T)c8_iy0), 1, 3, 1, 0) - 1], &c8_incy);
  }

  return c8_d;
}

static const mxArray *c8_sf_marshall(void *c8_chartInstance, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i35;
  int32_T c8_i36;
  int32_T c8_i37;
  real_T c8_b_u[6];
  const mxArray *c8_b_y = NULL;
  c8_y = NULL;
  c8_i35 = 0;
  for (c8_i36 = 0; c8_i36 < 2; c8_i36 = c8_i36 + 1) {
    for (c8_i37 = 0; c8_i37 < 3; c8_i37 = c8_i37 + 1) {
      c8_b_u[c8_i37 + c8_i35] = (*((real_T (*)[6])c8_u))[c8_i37 + c8_i35];
    }

    c8_i35 = c8_i35 + 3;
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 0, 0U, 1U, 0U, 2, 3, 2));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_b_sf_marshall(void *c8_chartInstance, void *c8_u)
{
  const mxArray *c8_y = NULL;
  real_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  c8_y = NULL;
  c8_b_u = *((real_T *)c8_u);
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_c_sf_marshall(void *c8_chartInstance, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i38;
  real_T c8_b_u[3];
  const mxArray *c8_b_y = NULL;
  c8_y = NULL;
  for (c8_i38 = 0; c8_i38 < 3; c8_i38 = c8_i38 + 1) {
    c8_b_u[c8_i38] = (*((real_T (*)[3])c8_u))[c8_i38];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_d_sf_marshall(void *c8_chartInstance, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i39;
  int32_T c8_i40;
  int32_T c8_i41;
  real_T c8_b_u[9];
  const mxArray *c8_b_y = NULL;
  c8_y = NULL;
  c8_i39 = 0;
  for (c8_i40 = 0; c8_i40 < 3; c8_i40 = c8_i40 + 1) {
    for (c8_i41 = 0; c8_i41 < 3; c8_i41 = c8_i41 + 1) {
      c8_b_u[c8_i41 + c8_i39] = (*((real_T (*)[9])c8_u))[c8_i41 + c8_i39];
    }

    c8_i39 = c8_i39 + 3;
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

const mxArray
  *sf_c8_Sim_Forcing_003h_expe_infra5_full_control5_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_ResolvedFunctionInfo c8_info[50];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i42;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 50));
  for (c8_i42 = 0; c8_i42 < 50; c8_i42 = c8_i42 + 1) {
    c8_r0 = &c8_info[c8_i42];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context",
                    "nameCaptureInfo", c8_i42);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name",
                    "nameCaptureInfo", c8_i42);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c8_i42);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c8_i42);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c8_i42);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c8_i42
                    );
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c8_i42
                    );
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[50])
{
  c8_info[0].context = "";
  c8_info[0].name = "times";
  c8_info[0].dominantType = "double";
  c8_info[0].resolved = "[B]times";
  c8_info[0].fileLength = 0U;
  c8_info[0].fileTime1 = 0U;
  c8_info[0].fileTime2 = 0U;
  c8_info[1].context = "";
  c8_info[1].name = "ones";
  c8_info[1].dominantType = "double";
  c8_info[1].resolved = "[B]ones";
  c8_info[1].fileLength = 0U;
  c8_info[1].fileTime1 = 0U;
  c8_info[1].fileTime2 = 0U;
  c8_info[2].context = "";
  c8_info[2].name = "mldivide";
  c8_info[2].dominantType = "double";
  c8_info[2].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c8_info[2].fileLength = 998U;
  c8_info[2].fileTime1 = 1238434288U;
  c8_info[2].fileTime2 = 0U;
  c8_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c8_info[3].name = "nargin";
  c8_info[3].dominantType = "";
  c8_info[3].resolved = "[B]nargin";
  c8_info[3].fileLength = 0U;
  c8_info[3].fileTime1 = 0U;
  c8_info[3].fileTime2 = 0U;
  c8_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c8_info[4].name = "ge";
  c8_info[4].dominantType = "double";
  c8_info[4].resolved = "[B]ge";
  c8_info[4].fileLength = 0U;
  c8_info[4].fileTime1 = 0U;
  c8_info[4].fileTime2 = 0U;
  c8_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c8_info[5].name = "isscalar";
  c8_info[5].dominantType = "double";
  c8_info[5].resolved = "[B]isscalar";
  c8_info[5].fileLength = 0U;
  c8_info[5].fileTime1 = 0U;
  c8_info[5].fileTime2 = 0U;
  c8_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c8_info[6].name = "isa";
  c8_info[6].dominantType = "double";
  c8_info[6].resolved = "[B]isa";
  c8_info[6].fileLength = 0U;
  c8_info[6].fileTime1 = 0U;
  c8_info[6].fileTime2 = 0U;
  c8_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c8_info[7].name = "size";
  c8_info[7].dominantType = "double";
  c8_info[7].resolved = "[B]size";
  c8_info[7].fileLength = 0U;
  c8_info[7].fileTime1 = 0U;
  c8_info[7].fileTime2 = 0U;
  c8_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c8_info[8].name = "eq";
  c8_info[8].dominantType = "double";
  c8_info[8].resolved = "[B]eq";
  c8_info[8].fileLength = 0U;
  c8_info[8].fileTime1 = 0U;
  c8_info[8].fileTime2 = 0U;
  c8_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c8_info[9].name = "ndims";
  c8_info[9].dominantType = "double";
  c8_info[9].resolved = "[B]ndims";
  c8_info[9].fileLength = 0U;
  c8_info[9].fileTime1 = 0U;
  c8_info[9].fileTime2 = 0U;
  c8_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c8_info[10].name = "isempty";
  c8_info[10].dominantType = "double";
  c8_info[10].resolved = "[B]isempty";
  c8_info[10].fileLength = 0U;
  c8_info[10].fileTime1 = 0U;
  c8_info[10].fileTime2 = 0U;
  c8_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.m";
  c8_info[11].name = "eml_lusolve";
  c8_info[11].dominantType = "double";
  c8_info[11].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c8_info[11].fileLength = 4120U;
  c8_info[11].fileTime1 = 1228093832U;
  c8_info[11].fileTime2 = 0U;
  c8_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c8_info[12].name = "eml_index_class";
  c8_info[12].dominantType = "";
  c8_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[12].fileLength = 909U;
  c8_info[12].fileTime1 = 1192466782U;
  c8_info[12].fileTime2 = 0U;
  c8_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c8_info[13].name = "cast";
  c8_info[13].dominantType = "double";
  c8_info[13].resolved = "[B]cast";
  c8_info[13].fileLength = 0U;
  c8_info[13].fileTime1 = 0U;
  c8_info[13].fileTime2 = 0U;
  c8_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c8_info[14].name = "gt";
  c8_info[14].dominantType = "int32";
  c8_info[14].resolved = "[B]gt";
  c8_info[14].fileLength = 0U;
  c8_info[14].fileTime1 = 0U;
  c8_info[14].fileTime2 = 0U;
  c8_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c8_info[15].name = "not";
  c8_info[15].dominantType = "logical";
  c8_info[15].resolved = "[B]not";
  c8_info[15].fileLength = 0U;
  c8_info[15].fileTime1 = 0U;
  c8_info[15].fileTime2 = 0U;
  c8_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/lusolve3x3";
  c8_info[16].name = "eml_xcabs1";
  c8_info[16].dominantType = "double";
  c8_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c8_info[16].fileLength = 419U;
  c8_info[16].fileTime1 = 1209330848U;
  c8_info[16].fileTime2 = 0U;
  c8_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c8_info[17].name = "real";
  c8_info[17].dominantType = "double";
  c8_info[17].resolved = "[B]real";
  c8_info[17].fileLength = 0U;
  c8_info[17].fileTime1 = 0U;
  c8_info[17].fileTime2 = 0U;
  c8_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c8_info[18].name = "abs";
  c8_info[18].dominantType = "double";
  c8_info[18].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[18].fileLength = 566U;
  c8_info[18].fileTime1 = 1221267134U;
  c8_info[18].fileTime2 = 0U;
  c8_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[19].name = "ischar";
  c8_info[19].dominantType = "double";
  c8_info[19].resolved = "[B]ischar";
  c8_info[19].fileLength = 0U;
  c8_info[19].fileTime1 = 0U;
  c8_info[19].fileTime2 = 0U;
  c8_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[20].name = "islogical";
  c8_info[20].dominantType = "double";
  c8_info[20].resolved = "[B]islogical";
  c8_info[20].fileLength = 0U;
  c8_info[20].fileTime1 = 0U;
  c8_info[20].fileTime2 = 0U;
  c8_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[21].name = "class";
  c8_info[21].dominantType = "double";
  c8_info[21].resolved = "[B]class";
  c8_info[21].fileLength = 0U;
  c8_info[21].fileTime1 = 0U;
  c8_info[21].fileTime2 = 0U;
  c8_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[22].name = "zeros";
  c8_info[22].dominantType = "double";
  c8_info[22].resolved = "[B]zeros";
  c8_info[22].fileLength = 0U;
  c8_info[22].fileTime1 = 0U;
  c8_info[22].fileTime2 = 0U;
  c8_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[23].name = "eml_scalar_abs";
  c8_info[23].dominantType = "double";
  c8_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[23].fileLength = 461U;
  c8_info[23].fileTime1 = 1203447960U;
  c8_info[23].fileTime2 = 0U;
  c8_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[24].name = "isinteger";
  c8_info[24].dominantType = "double";
  c8_info[24].resolved = "[B]isinteger";
  c8_info[24].fileLength = 0U;
  c8_info[24].fileTime1 = 0U;
  c8_info[24].fileTime2 = 0U;
  c8_info[25].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[25].name = "isreal";
  c8_info[25].dominantType = "double";
  c8_info[25].resolved = "[B]isreal";
  c8_info[25].fileLength = 0U;
  c8_info[25].fileTime1 = 0U;
  c8_info[25].fileTime2 = 0U;
  c8_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c8_info[26].name = "imag";
  c8_info[26].dominantType = "double";
  c8_info[26].resolved = "[B]imag";
  c8_info[26].fileLength = 0U;
  c8_info[26].fileTime1 = 0U;
  c8_info[26].fileTime2 = 0U;
  c8_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c8_info[27].name = "plus";
  c8_info[27].dominantType = "double";
  c8_info[27].resolved = "[B]plus";
  c8_info[27].fileLength = 0U;
  c8_info[27].fileTime1 = 0U;
  c8_info[27].fileTime2 = 0U;
  c8_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/lusolve3x3";
  c8_info[28].name = "eml_div";
  c8_info[28].dominantType = "double";
  c8_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[28].fileLength = 4269U;
  c8_info[28].fileTime1 = 1228093826U;
  c8_info[28].fileTime2 = 0U;
  c8_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/lusolve3x3";
  c8_info[29].name = "mtimes";
  c8_info[29].dominantType = "double";
  c8_info[29].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[29].fileLength = 3302U;
  c8_info[29].fileTime1 = 1242750894U;
  c8_info[29].fileTime2 = 0U;
  c8_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[30].name = "strcmp";
  c8_info[30].dominantType = "char";
  c8_info[30].resolved = "[B]strcmp";
  c8_info[30].fileLength = 0U;
  c8_info[30].fileTime1 = 0U;
  c8_info[30].fileTime2 = 0U;
  c8_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/lusolve3x3";
  c8_info[31].name = "minus";
  c8_info[31].dominantType = "double";
  c8_info[31].resolved = "[B]minus";
  c8_info[31].fileLength = 0U;
  c8_info[31].fileTime1 = 0U;
  c8_info[31].fileTime2 = 0U;
  c8_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/warn_singular";
  c8_info[32].name = "eml_warning";
  c8_info[32].dominantType = "char";
  c8_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c8_info[32].fileLength = 262U;
  c8_info[32].fileTime1 = 1236257278U;
  c8_info[32].fileTime2 = 0U;
  c8_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m/lusolve3x3";
  c8_info[33].name = "eml_scalar_eg";
  c8_info[33].dominantType = "double";
  c8_info[33].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[33].fileLength = 3068U;
  c8_info[33].fileTime1 = 1240262010U;
  c8_info[33].fileTime2 = 0U;
  c8_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c8_info[34].name = "false";
  c8_info[34].dominantType = "";
  c8_info[34].resolved = "[B]false";
  c8_info[34].fileLength = 0U;
  c8_info[34].fileTime1 = 0U;
  c8_info[34].fileTime2 = 0U;
  c8_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[35].name = "isstruct";
  c8_info[35].dominantType = "double";
  c8_info[35].resolved = "[B]isstruct";
  c8_info[35].fileLength = 0U;
  c8_info[35].fileTime1 = 0U;
  c8_info[35].fileTime2 = 0U;
  c8_info[36].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[36].name = "le";
  c8_info[36].dominantType = "double";
  c8_info[36].resolved = "[B]le";
  c8_info[36].fileLength = 0U;
  c8_info[36].fileTime1 = 0U;
  c8_info[36].fileTime2 = 0U;
  c8_info[37].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[37].name = "ne";
  c8_info[37].dominantType = "logical";
  c8_info[37].resolved = "[B]ne";
  c8_info[37].fileLength = 0U;
  c8_info[37].fileTime1 = 0U;
  c8_info[37].fileTime2 = 0U;
  c8_info[38].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[38].name = "eml_xdotu";
  c8_info[38].dominantType = "int32";
  c8_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c8_info[38].fileLength = 1453U;
  c8_info[38].fileTime1 = 1209330852U;
  c8_info[38].fileTime2 = 0U;
  c8_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c8_info[39].name = "eml_xdot";
  c8_info[39].dominantType = "int32";
  c8_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c8_info[39].fileLength = 1330U;
  c8_info[39].fileTime1 = 1209330850U;
  c8_info[39].fileTime2 = 0U;
  c8_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c8_info[40].name = "eml_refblas_xdot";
  c8_info[40].dominantType = "int32";
  c8_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c8_info[40].fileLength = 343U;
  c8_info[40].fileTime1 = 1211216044U;
  c8_info[40].fileTime2 = 0U;
  c8_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c8_info[41].name = "eml_refblas_xdotx";
  c8_info[41].dominantType = "int32";
  c8_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[41].fileLength = 1605U;
  c8_info[41].fileTime1 = 1236257280U;
  c8_info[41].fileTime2 = 0U;
  c8_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[42].name = "isequal";
  c8_info[42].dominantType = "char";
  c8_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c8_info[42].fileLength = 180U;
  c8_info[42].fileTime1 = 1226577272U;
  c8_info[42].fileTime2 = 0U;
  c8_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c8_info[43].name = "eml_isequal_core";
  c8_info[43].dominantType = "char";
  c8_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c8_info[43].fileLength = 3981U;
  c8_info[43].fileTime1 = 1236257272U;
  c8_info[43].fileTime2 = 0U;
  c8_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c8_info[44].name = "isnumeric";
  c8_info[44].dominantType = "char";
  c8_info[44].resolved = "[B]isnumeric";
  c8_info[44].fileLength = 0U;
  c8_info[44].fileTime1 = 0U;
  c8_info[44].fileTime2 = 0U;
  c8_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m/same_size";
  c8_info[45].name = "true";
  c8_info[45].dominantType = "";
  c8_info[45].resolved = "[B]true";
  c8_info[45].fileLength = 0U;
  c8_info[45].fileTime1 = 0U;
  c8_info[45].fileTime2 = 0U;
  c8_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[46].name = "lt";
  c8_info[46].dominantType = "int32";
  c8_info[46].resolved = "[B]lt";
  c8_info[46].fileLength = 0U;
  c8_info[46].fileTime1 = 0U;
  c8_info[46].fileTime2 = 0U;
  c8_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[47].name = "uminus";
  c8_info[47].dominantType = "int32";
  c8_info[47].resolved = "[B]uminus";
  c8_info[47].fileLength = 0U;
  c8_info[47].fileTime1 = 0U;
  c8_info[47].fileTime2 = 0U;
  c8_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[48].name = "eml_index_minus";
  c8_info[48].dominantType = "int32";
  c8_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[48].fileLength = 277U;
  c8_info[48].fileTime1 = 1192466784U;
  c8_info[48].fileTime2 = 0U;
  c8_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[49].name = "eml_index_plus";
  c8_info[49].dominantType = "int32";
  c8_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[49].fileLength = 272U;
  c8_info[49].fileTime1 = 1192466786U;
  c8_info[49].fileTime2 = 0U;
}

static const mxArray *c8_e_sf_marshall(void *c8_chartInstance, void *c8_u)
{
  const mxArray *c8_y = NULL;
  boolean_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  c8_y = NULL;
  c8_b_u = *((boolean_T *)c8_u);
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c8_Sim_Forcing_003h_expe_infra5_full_control5_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4109338881U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2775499772U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2126060482U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2511823128U);
}

mxArray
  *sf_c8_Sim_Forcing_003h_expe_infra5_full_control5_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(814620563U);
    pr[1] = (double)(2115166045U);
    pr[2] = (double)(3014904924U);
    pr[3] = (double)(4091276798U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
  *sf_get_sim_state_info_c8_Sim_Forcing_003h_expe_infra5_full_control5(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[10],T\"c\",},{M[1],M[8],T\"psi\",},{M[1],M[5],T\"x\",},{M[1],M[7],T\"z\",},{M[1],M[11],T\"z_p\",},{M[8],M[0],T\"is_active_c8_Sim_Forcing_003h_expe_infra5_full_control5\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_Sim_Forcing_003h_expe_infra5_full_control5_get_check_sum(&mxChecksum);
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
           8,
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

          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 2;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"set",0,(MexFcnForType)c8_sf_marshall);
          }

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"psi_set",
                              0,(MexFcnForType)c8_b_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"x",0,
                              (MexFcnForType)c8_b_sf_marshall);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "fraction",0,(MexFcnForType)c8_b_sf_marshall);
          _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"z",0,
                              (MexFcnForType)c8_b_sf_marshall);
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"psi",0,
                              (MexFcnForType)c8_b_sf_marshall);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(6,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"c",0,(MexFcnForType)c8_c_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"z_p",0,(MexFcnForType)c8_c_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,610);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c8_set)[6];
          real_T *c8_psi_set;
          real_T *c8_x;
          real_T *c8_fraction;
          real_T *c8_z;
          real_T *c8_psi;
          real_T (*c8_c)[3];
          real_T (*c8_z_p)[3];
          c8_c = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 4);
          c8_psi = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c8_z_p = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 5);
          c8_set = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 0);
          c8_fraction = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c8_x = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c8_z = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c8_psi_set = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_set);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_psi_set);
          _SFD_SET_DATA_VALUE_PTR(2U, c8_x);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_fraction);
          _SFD_SET_DATA_VALUE_PTR(4U, c8_z);
          _SFD_SET_DATA_VALUE_PTR(5U, c8_psi);
          _SFD_SET_DATA_VALUE_PTR(6U, c8_c);
          _SFD_SET_DATA_VALUE_PTR(7U, c8_z_p);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Sim_Forcing_003h_expe_infra5_full_control5MachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c8_Sim_Forcing_003h_expe_infra5_full_control5
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c8_Sim_Forcing_003h_expe_infra5_full_control5();
  initialize_c8_Sim_Forcing_003h_expe_infra5_full_control5();
}

static void sf_opaque_enable_c8_Sim_Forcing_003h_expe_infra5_full_control5(void *
  chartInstanceVar)
{
  enable_c8_Sim_Forcing_003h_expe_infra5_full_control5();
}

static void sf_opaque_disable_c8_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar)
{
  disable_c8_Sim_Forcing_003h_expe_infra5_full_control5();
}

static void sf_opaque_gateway_c8_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar)
{
  sf_c8_Sim_Forcing_003h_expe_infra5_full_control5();
}

static void
  sf_opaque_ext_mode_exec_c8_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar)
{
  ext_mode_exec_c8_Sim_Forcing_003h_expe_infra5_full_control5();
}

static mxArray*
  sf_opaque_get_sim_state_c8_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c8_Sim_Forcing_003h_expe_infra5_full_control5();
  return st;
}

static void
  sf_opaque_set_sim_state_c8_Sim_Forcing_003h_expe_infra5_full_control5(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c8_Sim_Forcing_003h_expe_infra5_full_control5(sf_mex_dup(st));
}

static void sf_opaque_terminate_c8_Sim_Forcing_003h_expe_infra5_full_control5
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c8_Sim_Forcing_003h_expe_infra5_full_control5();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_Sim_Forcing_003h_expe_infra5_full_control5
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_Sim_Forcing_003h_expe_infra5_full_control5();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c8_Sim_Forcing_003h_expe_infra5_full_control5
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Sim_Forcing_003h_expe_infra5_full_control5",
      "Sim_Forcing_003h_expe_infra5_full_control5",8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "Sim_Forcing_003h_expe_infra5_full_control5",
                "Sim_Forcing_003h_expe_infra5_full_control5",8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "Sim_Forcing_003h_expe_infra5_full_control5",
      "Sim_Forcing_003h_expe_infra5_full_control5",8,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "Sim_Forcing_003h_expe_infra5_full_control5",
        "Sim_Forcing_003h_expe_infra5_full_control5",8,3);
      sf_mark_chart_reusable_outputs(S,
        "Sim_Forcing_003h_expe_infra5_full_control5",
        "Sim_Forcing_003h_expe_infra5_full_control5",8,5);
    }

    sf_set_rtw_dwork_info(S,"Sim_Forcing_003h_expe_infra5_full_control5",
                          "Sim_Forcing_003h_expe_infra5_full_control5",8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(3050771055U));
  ssSetChecksum1(S,(3034209715U));
  ssSetChecksum2(S,(3307489863U));
  ssSetChecksum3(S,(2998801298U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_Sim_Forcing_003h_expe_infra5_full_control5(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Sim_Forcing_003h_expe_infra5_full_control5",
      "Sim_Forcing_003h_expe_infra5_full_control5",8);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_Sim_Forcing_003h_expe_infra5_full_control5(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_Sim_Forcing_003h_expe_infra5_full_control5;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c8_Sim_Forcing_003h_expe_infra5_full_control5;
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

void c8_Sim_Forcing_003h_expe_infra5_full_control5_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_Sim_Forcing_003h_expe_infra5_full_control5(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_Sim_Forcing_003h_expe_infra5_full_control5(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_Sim_Forcing_003h_expe_infra5_full_control5(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_Sim_Forcing_003h_expe_infra5_full_control5_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

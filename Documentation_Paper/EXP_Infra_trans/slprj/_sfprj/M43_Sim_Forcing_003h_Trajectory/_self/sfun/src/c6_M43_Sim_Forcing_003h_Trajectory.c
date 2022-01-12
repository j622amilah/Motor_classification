/* Include files */

#include "blascompat32.h"
#include "M43_Sim_Forcing_003h_Trajectory_sfun.h"
#include "c6_M43_Sim_Forcing_003h_Trajectory.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M43_Sim_Forcing_003h_Trajectory_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c6_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc6_M43_Sim_Forcing_003h_TrajectoryInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c6_M43_Sim_Forcing_003h_Trajectory(void);
static void initialize_params_c6_M43_Sim_Forcing_003h_Trajectory(void);
static void enable_c6_M43_Sim_Forcing_003h_Trajectory(void);
static void disable_c6_M43_Sim_Forcing_003h_Trajectory(void);
static void c6_update_debugger_state_c6_M43_Sim_Forcing_003h_Trajectory(void);
static void ext_mode_exec_c6_M43_Sim_Forcing_003h_Trajectory(void);
static const mxArray *get_sim_state_c6_M43_Sim_Forcing_003h_Trajectory(void);
static void set_sim_state_c6_M43_Sim_Forcing_003h_Trajectory(const mxArray
  *c6_st);
static void finalize_c6_M43_Sim_Forcing_003h_Trajectory(void);
static void sf_c6_M43_Sim_Forcing_003h_Trajectory(void);
static void c6_c6_M43_Sim_Forcing_003h_Trajectory(void);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static real_T c6_mpower(real_T c6_a);
static real_T c6_power(real_T c6_a, real_T c6_b);
static void c6_eml_scalar_eg(void);
static void c6_eml_error(void);
static real_T c6_sqrt(real_T c6_x);
static void c6_b_eml_error(void);
static void c6_adjust_ang(real_T c6_ang[6], real_T c6_b_ang[6]);
static void c6_b_eml_scalar_eg(void);
static void c6_c_eml_scalar_eg(void);
static void c6_d_eml_scalar_eg(void);
static void c6_DCM2Eul(real_T c6_D[9], real_T c6_ang[3]);
static real_T c6_atan2(real_T c6_y, real_T c6_x);
static void c6_c_eml_error(void);
static void c6_e_eml_scalar_eg(void);
static void c6_eml_xgemm(real_T c6_A[9], real_T c6_B[3], real_T c6_C[3], real_T
  c6_b_C[3]);
static void c6_f_eml_scalar_eg(void);
static void c6_inv(real_T c6_x[36], real_T c6_y[36]);
static void c6_eml_xgetrf(real_T c6_A[36], real_T c6_b_A[36], int32_T c6_ipiv[6]);
static int32_T c6_eml_ixamax(int32_T c6_n, real_T c6_x[36], int32_T c6_ix0);
static int32_T c6_ceval_ixamax(int32_T c6_n, real_T c6_x[36], int32_T c6_ix0,
  int32_T c6_incx);
static void c6_ceval_xswap(int32_T c6_n, real_T c6_x[36], int32_T c6_ix0,
  int32_T c6_incx, int32_T c6_iy0, int32_T c6_incy, real_T c6_b_x[36]);
static void c6_ceval_xger(int32_T c6_m, int32_T c6_n, real_T c6_alpha1, int32_T
  c6_ix0, int32_T c6_incx, int32_T c6_iy0, int32_T c6_incy, real_T c6_A[36],
  int32_T c6_ia0, int32_T c6_lda, real_T c6_b_A[36]);
static void c6_eml_blas_xtrsm(int32_T c6_m, int32_T c6_n, real_T c6_alpha1,
  real_T c6_A[36], int32_T c6_ia0, int32_T c6_lda, real_T c6_B[36], int32_T
  c6_ib0, int32_T c6_ldb, real_T c6_b_B[36]);
static void c6_ceval_xtrsm(int32_T c6_m, int32_T c6_n, real_T c6_alpha1, real_T
  c6_A[36], int32_T c6_ia0, int32_T c6_lda, real_T c6_B[36], int32_T c6_ib0,
  int32_T c6_ldb, real_T c6_b_B[36]);
static real_T c6_norm(real_T c6_x[36]);
static void c6_eml_warning(void);
static void c6_b_eml_warning(real_T c6_varargin_3);
static void c6_g_eml_scalar_eg(void);
static real_T c6_b_norm(real_T c6_x[6]);
static real_T c6_genpnorm(real_T c6_x[6], real_T c6_p);
static real_T c6_eml_xnrm2(real_T c6_x[6]);
static real_T c6_ceval_xnrm2(int32_T c6_n, real_T c6_x[6], real_T c6_ix0,
  int32_T c6_incx);
static const mxArray *c6_sf_marshall(void *c6_chartInstance, void *c6_u);
static const mxArray *c6_b_sf_marshall(void *c6_chartInstance, void *c6_u);
static const mxArray *c6_c_sf_marshall(void *c6_chartInstance, void *c6_u);
static const mxArray *c6_d_sf_marshall(void *c6_chartInstance, void *c6_u);
static const mxArray *c6_e_sf_marshall(void *c6_chartInstance, void *c6_u);
static const mxArray *c6_f_sf_marshall(void *c6_chartInstance, void *c6_u);
static const mxArray *c6_g_sf_marshall(void *c6_chartInstance, void *c6_u);
static const mxArray *c6_h_sf_marshall(void *c6_chartInstance, void *c6_u);
static const mxArray *c6_i_sf_marshall(void *c6_chartInstance, void *c6_u);
static const mxArray *c6_j_sf_marshall(void *c6_chartInstance, void *c6_u);
static const mxArray *c6_k_sf_marshall(void *c6_chartInstance, void *c6_u);
static const mxArray *c6_l_sf_marshall(void *c6_chartInstance, void *c6_u);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[107]);
static void c6_b_info_helper(c6_ResolvedFunctionInfo c6_info[107]);
static const mxArray *c6_m_sf_marshall(void *c6_chartInstance, void *c6_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c6_M43_Sim_Forcing_003h_Trajectory(void)
{
  uint8_T *c6_is_active_c6_M43_Sim_Forcing_003h_Trajectory;
  c6_is_active_c6_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c6_is_active_c6_M43_Sim_Forcing_003h_Trajectory = 0U;
}

static void initialize_params_c6_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void enable_c6_M43_Sim_Forcing_003h_Trajectory(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c6_M43_Sim_Forcing_003h_Trajectory(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c6_update_debugger_state_c6_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void ext_mode_exec_c6_M43_Sim_Forcing_003h_Trajectory(void)
{
  c6_update_debugger_state_c6_M43_Sim_Forcing_003h_Trajectory();
}

static const mxArray *get_sim_state_c6_M43_Sim_Forcing_003h_Trajectory(void)
{
  const mxArray *c6_st = NULL;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_u[7];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  uint8_T *c6_is_active_c6_M43_Sim_Forcing_003h_Trajectory;
  real_T (*c6_out)[7];
  c6_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  c6_is_active_c6_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2));
  for (c6_i0 = 0; c6_i0 < 7; c6_i0 = c6_i0 + 1) {
    c6_u[c6_i0] = (*c6_out)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_u = *c6_is_active_c6_M43_Sim_Forcing_003h_Trajectory;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y);
  return c6_st;
}

static void set_sim_state_c6_M43_Sim_Forcing_003h_Trajectory(const mxArray
  *c6_st)
{
  const mxArray *c6_u;
  const mxArray *c6_out;
  real_T c6_dv0[7];
  int32_T c6_i1;
  real_T c6_y[7];
  int32_T c6_i2;
  const mxArray *c6_is_active_c6_M43_Sim_Forcing_003h_Trajectory;
  uint8_T c6_u0;
  uint8_T c6_b_y;
  boolean_T *c6_doneDoubleBufferReInit;
  uint8_T *c6_b_is_active_c6_M43_Sim_Forcing_003h_Trajectory;
  real_T (*c6_b_out)[7];
  c6_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c6_b_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  c6_b_is_active_c6_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  *c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  c6_out = sf_mex_dup(sf_mex_getcell(c6_u, 0));
  sf_mex_import("out", sf_mex_dup(c6_out), &c6_dv0, 1, 0, 0U, 1, 0U, 1, 7);
  for (c6_i1 = 0; c6_i1 < 7; c6_i1 = c6_i1 + 1) {
    c6_y[c6_i1] = c6_dv0[c6_i1];
  }

  sf_mex_destroy(&c6_out);
  for (c6_i2 = 0; c6_i2 < 7; c6_i2 = c6_i2 + 1) {
    (*c6_b_out)[c6_i2] = c6_y[c6_i2];
  }

  c6_is_active_c6_M43_Sim_Forcing_003h_Trajectory = sf_mex_dup(sf_mex_getcell
    (c6_u, 1));
  sf_mex_import("is_active_c6_M43_Sim_Forcing_003h_Trajectory", sf_mex_dup
                (c6_is_active_c6_M43_Sim_Forcing_003h_Trajectory), &c6_u0, 1
                , 3, 0U, 0, 0U, 0);
  c6_b_y = c6_u0;
  sf_mex_destroy(&c6_is_active_c6_M43_Sim_Forcing_003h_Trajectory);
  *c6_b_is_active_c6_M43_Sim_Forcing_003h_Trajectory = c6_b_y;
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_M43_Sim_Forcing_003h_Trajectory();
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void sf_c6_M43_Sim_Forcing_003h_Trajectory(void)
{
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_previousEvent;
  real_T (*c6_out)[7];
  real_T (*c6_vec)[12];
  c6_vec = (real_T (*)[12])ssGetInputPortSignal(chartInstance.S, 0);
  c6_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,5);
  for (c6_i3 = 0; c6_i3 < 12; c6_i3 = c6_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c6_vec)[c6_i3], 0U);
  }

  for (c6_i4 = 0; c6_i4 < 7; c6_i4 = c6_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c6_out)[c6_i4], 1U);
  }

  c6_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c6_c6_M43_Sim_Forcing_003h_Trajectory();
  _sfEvent_ = c6_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void c6_c6_M43_Sim_Forcing_003h_Trajectory(void)
{
  int32_T c6_i5;
  real_T c6_vec[12];
  real_T c6_nargout = 1.0;
  real_T c6_nargin = 1.0;
  real_T c6_i;
  real_T c6_J_ANG[6];
  real_T c6_d_ang[6];
  real_T c6_H[36];
  real_T c6_h[24];
  real_T c6_h6[4];
  real_T c6_h5[4];
  real_T c6_h4[4];
  real_T c6_h3[4];
  real_T c6_h2[4];
  real_T c6_h1[4];
  real_T c6_dD6[16];
  real_T c6_dD5[16];
  real_T c6_dD4[16];
  real_T c6_dD3[16];
  real_T c6_dD2[16];
  real_T c6_dD1[16];
  real_T c6_TET[9];
  real_T c6_PSI[9];
  real_T c6_sn_tet;
  real_T c6_cs_tet;
  real_T c6_sn_psi;
  real_T c6_cs_psi;
  real_T c6_e[18];
  real_T c6_e1[3];
  real_T c6_e2[3];
  real_T c6_e3[3];
  real_T c6_e4[3];
  real_T c6_e5[3];
  real_T c6_e6[3];
  real_T c6_eul_ang[3];
  real_T c6_E[9];
  real_T c6_pos[3];
  real_T c6_p[4];
  real_T c6_x6[4];
  real_T c6_x_cabin[3];
  real_T c6_E6[9];
  real_T c6_E5[9];
  real_T c6_E4[9];
  real_T c6_E3[9];
  real_T c6_E2[9];
  real_T c6_E1[9];
  real_T c6_D6[16];
  real_T c6_D5[16];
  real_T c6_D4[16];
  real_T c6_D3[16];
  real_T c6_D2[16];
  real_T c6_D1[16];
  real_T c6_SA6;
  real_T c6_CA6;
  real_T c6_SA5;
  real_T c6_CA5;
  real_T c6_SA4;
  real_T c6_CA4;
  real_T c6_SA3;
  real_T c6_CA3;
  real_T c6_SA2;
  real_T c6_CA2;
  real_T c6_SA1;
  real_T c6_CA1;
  real_T c6_A6;
  real_T c6_A5;
  real_T c6_A4;
  real_T c6_A3;
  real_T c6_A2;
  real_T c6_A1;
  real_T c6_R1;
  real_T c6_R;
  real_T c6_L;
  real_T c6_ang[6];
  real_T c6_N;
  real_T c6_Height_A2;
  real_T c6_d;
  real_T c6_l5;
  real_T c6_l4;
  real_T c6_l3;
  real_T c6_l2;
  real_T c6_l1;
  real_T c6_SL[12];
  real_T c6_J_ANG_0[6];
  real_T c6_EUL_ANG[3];
  real_T c6_POS[3];
  real_T c6_RTD;
  real_T c6_DTR;
  real_T c6_out[7];
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_i10;
  static real_T c6_dv1[12] = { 159.0, -159.0, 129.0, -19.0, 87.0, -87.0, 349.0,
    -349.0, 60.0, -60.0, 349.0, -349.0 };

  int32_T c6_i11;
  real_T c6_a[6];
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  real_T c6_b_ang[6];
  real_T c6_dv2[6];
  int32_T c6_i15;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_g_x;
  real_T c6_h_x;
  real_T c6_i_x;
  real_T c6_j_x;
  real_T c6_k_x;
  real_T c6_l_x;
  real_T c6_m_x;
  real_T c6_n_x;
  real_T c6_o_x;
  real_T c6_p_x;
  real_T c6_q_x;
  real_T c6_r_x;
  real_T c6_s_x;
  real_T c6_t_x;
  real_T c6_u_x;
  real_T c6_v_x;
  real_T c6_w_x;
  real_T c6_x_x;
  int32_T c6_i16;
  int32_T c6_i17;
  static real_T c6_dv3[4] = { 0.0, 0.0, 1.0, 0.0 };

  int32_T c6_i18;
  int32_T c6_i19;
  static real_T c6_dv4[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c6_i20;
  int32_T c6_i21;
  static real_T c6_dv5[4] = { 0.0, 1.0, 0.0, 0.0 };

  int32_T c6_i22;
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i27;
  int32_T c6_i28;
  int32_T c6_i29;
  int32_T c6_i30;
  int32_T c6_i31;
  int32_T c6_i32;
  int32_T c6_i33;
  int32_T c6_i34;
  int32_T c6_i35;
  int32_T c6_i36;
  int32_T c6_i37;
  int32_T c6_i38;
  int32_T c6_i39;
  int32_T c6_i40;
  int32_T c6_i41;
  int32_T c6_i42;
  int32_T c6_i43;
  int32_T c6_i44;
  int32_T c6_i45;
  int32_T c6_i46;
  int32_T c6_i47;
  int32_T c6_i48;
  int32_T c6_i49;
  int32_T c6_i50;
  int32_T c6_i51;
  int32_T c6_i52;
  int32_T c6_i53;
  int32_T c6_i54;
  int32_T c6_i55;
  int32_T c6_i56;
  int32_T c6_i57;
  int32_T c6_i58;
  int32_T c6_i59;
  int32_T c6_i60;
  int32_T c6_i61;
  int32_T c6_i62;
  real_T c6_b_a[16];
  int32_T c6_i63;
  real_T c6_b[16];
  int32_T c6_i64;
  real_T c6_A[16];
  int32_T c6_i65;
  real_T c6_B[16];
  int32_T c6_i66;
  real_T c6_b_A[16];
  int32_T c6_i67;
  real_T c6_b_B[16];
  int32_T c6_i68;
  real_T c6_c_A[16];
  int32_T c6_i69;
  real_T c6_c_B[16];
  int32_T c6_i70;
  int32_T c6_i71;
  int32_T c6_i72;
  real_T c6_c_a[16];
  int32_T c6_i73;
  int32_T c6_i74;
  int32_T c6_i75;
  real_T c6_b_b[16];
  int32_T c6_i76;
  real_T c6_d_A[16];
  int32_T c6_i77;
  real_T c6_d_B[16];
  int32_T c6_i78;
  real_T c6_e_A[16];
  int32_T c6_i79;
  real_T c6_e_B[16];
  int32_T c6_i80;
  real_T c6_f_A[16];
  int32_T c6_i81;
  real_T c6_f_B[16];
  int32_T c6_i82;
  int32_T c6_i83;
  int32_T c6_i84;
  real_T c6_d_a[16];
  int32_T c6_i85;
  int32_T c6_i86;
  int32_T c6_i87;
  real_T c6_c_b[16];
  int32_T c6_i88;
  real_T c6_g_A[16];
  int32_T c6_i89;
  real_T c6_g_B[16];
  int32_T c6_i90;
  real_T c6_h_A[16];
  int32_T c6_i91;
  real_T c6_h_B[16];
  int32_T c6_i92;
  real_T c6_i_A[16];
  int32_T c6_i93;
  real_T c6_i_B[16];
  int32_T c6_i94;
  int32_T c6_i95;
  int32_T c6_i96;
  real_T c6_e_a[16];
  int32_T c6_i97;
  int32_T c6_i98;
  int32_T c6_i99;
  real_T c6_d_b[16];
  int32_T c6_i100;
  real_T c6_j_A[16];
  int32_T c6_i101;
  real_T c6_j_B[16];
  int32_T c6_i102;
  real_T c6_k_A[16];
  int32_T c6_i103;
  real_T c6_k_B[16];
  int32_T c6_i104;
  real_T c6_l_A[16];
  int32_T c6_i105;
  real_T c6_l_B[16];
  int32_T c6_i106;
  int32_T c6_i107;
  int32_T c6_i108;
  real_T c6_f_a[16];
  int32_T c6_i109;
  int32_T c6_i110;
  int32_T c6_i111;
  real_T c6_e_b[16];
  int32_T c6_i112;
  real_T c6_m_A[16];
  int32_T c6_i113;
  real_T c6_m_B[16];
  int32_T c6_i114;
  real_T c6_n_A[16];
  int32_T c6_i115;
  real_T c6_n_B[16];
  int32_T c6_i116;
  real_T c6_o_A[16];
  int32_T c6_i117;
  real_T c6_o_B[16];
  int32_T c6_i118;
  int32_T c6_i119;
  int32_T c6_i120;
  real_T c6_g_a[16];
  int32_T c6_i121;
  int32_T c6_i122;
  int32_T c6_i123;
  real_T c6_p_A[16];
  int32_T c6_i124;
  int32_T c6_i125;
  real_T c6_q_A[16];
  int32_T c6_i126;
  real_T c6_r_A[16];
  int32_T c6_i127;
  int32_T c6_i128;
  int32_T c6_i129;
  int32_T c6_i130;
  int32_T c6_i131;
  int32_T c6_i132;
  int32_T c6_i133;
  int32_T c6_i134;
  real_T c6_h_a[9];
  int32_T c6_i135;
  int32_T c6_i136;
  int32_T c6_i137;
  int32_T c6_i138;
  real_T c6_f_b[9];
  int32_T c6_i139;
  real_T c6_s_A[9];
  int32_T c6_i140;
  real_T c6_p_B[9];
  int32_T c6_i141;
  real_T c6_t_A[9];
  int32_T c6_i142;
  real_T c6_q_B[9];
  int32_T c6_i143;
  real_T c6_u_A[9];
  int32_T c6_i144;
  real_T c6_r_B[9];
  int32_T c6_i145;
  int32_T c6_i146;
  int32_T c6_i147;
  real_T c6_i_a[9];
  int32_T c6_i148;
  int32_T c6_i149;
  int32_T c6_i150;
  int32_T c6_i151;
  int32_T c6_i152;
  int32_T c6_i153;
  real_T c6_g_b[9];
  int32_T c6_i154;
  real_T c6_v_A[9];
  int32_T c6_i155;
  real_T c6_s_B[9];
  int32_T c6_i156;
  real_T c6_w_A[9];
  int32_T c6_i157;
  real_T c6_t_B[9];
  int32_T c6_i158;
  real_T c6_x_A[9];
  int32_T c6_i159;
  real_T c6_u_B[9];
  int32_T c6_i160;
  int32_T c6_i161;
  int32_T c6_i162;
  real_T c6_j_a[9];
  int32_T c6_i163;
  int32_T c6_i164;
  int32_T c6_i165;
  int32_T c6_i166;
  int32_T c6_i167;
  int32_T c6_i168;
  real_T c6_h_b[9];
  int32_T c6_i169;
  real_T c6_y_A[9];
  int32_T c6_i170;
  real_T c6_v_B[9];
  int32_T c6_i171;
  real_T c6_ab_A[9];
  int32_T c6_i172;
  real_T c6_w_B[9];
  int32_T c6_i173;
  real_T c6_bb_A[9];
  int32_T c6_i174;
  real_T c6_x_B[9];
  int32_T c6_i175;
  int32_T c6_i176;
  int32_T c6_i177;
  real_T c6_k_a[9];
  int32_T c6_i178;
  int32_T c6_i179;
  int32_T c6_i180;
  int32_T c6_i181;
  int32_T c6_i182;
  int32_T c6_i183;
  real_T c6_i_b[9];
  int32_T c6_i184;
  real_T c6_cb_A[9];
  int32_T c6_i185;
  real_T c6_y_B[9];
  int32_T c6_i186;
  real_T c6_db_A[9];
  int32_T c6_i187;
  real_T c6_ab_B[9];
  int32_T c6_i188;
  real_T c6_eb_A[9];
  int32_T c6_i189;
  real_T c6_bb_B[9];
  int32_T c6_i190;
  int32_T c6_i191;
  int32_T c6_i192;
  real_T c6_l_a[9];
  int32_T c6_i193;
  int32_T c6_i194;
  int32_T c6_i195;
  int32_T c6_i196;
  int32_T c6_i197;
  int32_T c6_i198;
  real_T c6_j_b[9];
  int32_T c6_i199;
  real_T c6_fb_A[9];
  int32_T c6_i200;
  real_T c6_cb_B[9];
  int32_T c6_i201;
  int32_T c6_i202;
  real_T c6_gb_A[9];
  int32_T c6_i203;
  real_T c6_db_B[9];
  int32_T c6_i204;
  real_T c6_hb_A[9];
  int32_T c6_i205;
  real_T c6_eb_B[9];
  int32_T c6_i206;
  int32_T c6_i207;
  int32_T c6_i208;
  int32_T c6_i209;
  int32_T c6_i210;
  int32_T c6_i211;
  real_T c6_b_E[9];
  real_T c6_dv6[3];
  int32_T c6_i212;
  int32_T c6_i213;
  real_T c6_m_a[9];
  int32_T c6_i214;
  real_T c6_k_b[9];
  int32_T c6_i215;
  real_T c6_ib_A[9];
  int32_T c6_i216;
  real_T c6_fb_B[9];
  int32_T c6_i217;
  real_T c6_jb_A[9];
  int32_T c6_i218;
  real_T c6_gb_B[9];
  int32_T c6_i219;
  real_T c6_kb_A[9];
  int32_T c6_i220;
  real_T c6_hb_B[9];
  int32_T c6_i221;
  int32_T c6_i222;
  int32_T c6_i223;
  real_T c6_n_a[9];
  int32_T c6_i224;
  int32_T c6_i225;
  int32_T c6_i226;
  real_T c6_l_b[9];
  int32_T c6_i227;
  real_T c6_lb_A[9];
  int32_T c6_i228;
  real_T c6_ib_B[9];
  int32_T c6_i229;
  real_T c6_mb_A[9];
  int32_T c6_i230;
  real_T c6_jb_B[9];
  int32_T c6_i231;
  real_T c6_nb_A[9];
  int32_T c6_i232;
  real_T c6_kb_B[9];
  int32_T c6_i233;
  int32_T c6_i234;
  int32_T c6_i235;
  real_T c6_o_a[9];
  int32_T c6_i236;
  int32_T c6_i237;
  int32_T c6_i238;
  real_T c6_m_b[9];
  int32_T c6_i239;
  real_T c6_ob_A[9];
  int32_T c6_i240;
  real_T c6_lb_B[9];
  int32_T c6_i241;
  real_T c6_pb_A[9];
  int32_T c6_i242;
  real_T c6_mb_B[9];
  int32_T c6_i243;
  real_T c6_qb_A[9];
  int32_T c6_i244;
  real_T c6_nb_B[9];
  int32_T c6_i245;
  int32_T c6_i246;
  int32_T c6_i247;
  real_T c6_p_a[9];
  int32_T c6_i248;
  int32_T c6_i249;
  int32_T c6_i250;
  real_T c6_n_b[9];
  int32_T c6_i251;
  real_T c6_rb_A[9];
  int32_T c6_i252;
  real_T c6_ob_B[9];
  int32_T c6_i253;
  real_T c6_sb_A[9];
  int32_T c6_i254;
  real_T c6_pb_B[9];
  int32_T c6_i255;
  real_T c6_tb_A[9];
  int32_T c6_i256;
  real_T c6_qb_B[9];
  int32_T c6_i257;
  int32_T c6_i258;
  int32_T c6_i259;
  real_T c6_q_a[9];
  int32_T c6_i260;
  int32_T c6_i261;
  int32_T c6_i262;
  real_T c6_r_a[9];
  int32_T c6_i263;
  static real_T c6_dv7[3] = { 1.0, 0.0, 0.0 };

  real_T c6_dv8[3];
  int32_T c6_i264;
  real_T c6_dv9[3];
  real_T c6_dv10[3];
  int32_T c6_i265;
  int32_T c6_i266;
  real_T c6_s_a[9];
  int32_T c6_i267;
  real_T c6_o_b[9];
  int32_T c6_i268;
  real_T c6_ub_A[9];
  int32_T c6_i269;
  real_T c6_rb_B[9];
  int32_T c6_i270;
  real_T c6_vb_A[9];
  int32_T c6_i271;
  real_T c6_sb_B[9];
  int32_T c6_i272;
  real_T c6_wb_A[9];
  int32_T c6_i273;
  real_T c6_tb_B[9];
  int32_T c6_i274;
  int32_T c6_i275;
  int32_T c6_i276;
  real_T c6_t_a[9];
  int32_T c6_i277;
  int32_T c6_i278;
  int32_T c6_i279;
  real_T c6_p_b[9];
  int32_T c6_i280;
  real_T c6_xb_A[9];
  int32_T c6_i281;
  real_T c6_ub_B[9];
  int32_T c6_i282;
  real_T c6_yb_A[9];
  int32_T c6_i283;
  real_T c6_vb_B[9];
  int32_T c6_i284;
  real_T c6_ac_A[9];
  int32_T c6_i285;
  real_T c6_wb_B[9];
  int32_T c6_i286;
  int32_T c6_i287;
  int32_T c6_i288;
  real_T c6_u_a[9];
  int32_T c6_i289;
  int32_T c6_i290;
  int32_T c6_i291;
  real_T c6_q_b[9];
  int32_T c6_i292;
  real_T c6_bc_A[9];
  int32_T c6_i293;
  real_T c6_xb_B[9];
  int32_T c6_i294;
  real_T c6_cc_A[9];
  int32_T c6_i295;
  real_T c6_yb_B[9];
  int32_T c6_i296;
  real_T c6_dc_A[9];
  int32_T c6_i297;
  real_T c6_ac_B[9];
  int32_T c6_i298;
  int32_T c6_i299;
  int32_T c6_i300;
  real_T c6_v_a[9];
  int32_T c6_i301;
  int32_T c6_i302;
  int32_T c6_i303;
  real_T c6_w_a[9];
  int32_T c6_i304;
  static real_T c6_dv11[3] = { 0.0, 1.0, 0.0 };

  real_T c6_dv12[3];
  int32_T c6_i305;
  real_T c6_dv13[3];
  real_T c6_dv14[3];
  int32_T c6_i306;
  int32_T c6_i307;
  real_T c6_x_a[9];
  int32_T c6_i308;
  real_T c6_r_b[9];
  int32_T c6_i309;
  real_T c6_ec_A[9];
  int32_T c6_i310;
  real_T c6_bc_B[9];
  int32_T c6_i311;
  real_T c6_fc_A[9];
  int32_T c6_i312;
  real_T c6_cc_B[9];
  int32_T c6_i313;
  real_T c6_gc_A[9];
  int32_T c6_i314;
  real_T c6_dc_B[9];
  int32_T c6_i315;
  int32_T c6_i316;
  int32_T c6_i317;
  real_T c6_y_a[9];
  int32_T c6_i318;
  int32_T c6_i319;
  int32_T c6_i320;
  real_T c6_s_b[9];
  int32_T c6_i321;
  real_T c6_hc_A[9];
  int32_T c6_i322;
  real_T c6_ec_B[9];
  int32_T c6_i323;
  real_T c6_ic_A[9];
  int32_T c6_i324;
  real_T c6_fc_B[9];
  int32_T c6_i325;
  real_T c6_jc_A[9];
  int32_T c6_i326;
  real_T c6_gc_B[9];
  int32_T c6_i327;
  int32_T c6_i328;
  int32_T c6_i329;
  real_T c6_ab_a[9];
  int32_T c6_i330;
  int32_T c6_i331;
  int32_T c6_i332;
  real_T c6_bb_a[9];
  int32_T c6_i333;
  real_T c6_dv15[3];
  int32_T c6_i334;
  real_T c6_dv16[3];
  real_T c6_dv17[3];
  int32_T c6_i335;
  int32_T c6_i336;
  real_T c6_cb_a[9];
  int32_T c6_i337;
  real_T c6_t_b[9];
  int32_T c6_i338;
  real_T c6_kc_A[9];
  int32_T c6_i339;
  real_T c6_hc_B[9];
  int32_T c6_i340;
  real_T c6_lc_A[9];
  int32_T c6_i341;
  real_T c6_ic_B[9];
  int32_T c6_i342;
  real_T c6_mc_A[9];
  int32_T c6_i343;
  real_T c6_jc_B[9];
  int32_T c6_i344;
  int32_T c6_i345;
  int32_T c6_i346;
  real_T c6_db_a[9];
  int32_T c6_i347;
  int32_T c6_i348;
  int32_T c6_i349;
  real_T c6_eb_a[9];
  int32_T c6_i350;
  real_T c6_dv18[3];
  int32_T c6_i351;
  real_T c6_dv19[3];
  real_T c6_dv20[3];
  int32_T c6_i352;
  int32_T c6_i353;
  real_T c6_fb_a[9];
  int32_T c6_i354;
  real_T c6_gb_a[9];
  int32_T c6_i355;
  real_T c6_dv21[3];
  int32_T c6_i356;
  real_T c6_dv22[3];
  real_T c6_dv23[3];
  int32_T c6_i357;
  int32_T c6_i358;
  static real_T c6_dv24[3] = { 0.0, 0.0, 1.0 };

  int32_T c6_i359;
  int32_T c6_i360;
  int32_T c6_i361;
  int32_T c6_i362;
  int32_T c6_i363;
  int32_T c6_i364;
  real_T c6_y_x;
  real_T c6_ab_x;
  real_T c6_bb_x;
  real_T c6_cb_x;
  real_T c6_db_x;
  real_T c6_eb_x;
  real_T c6_fb_x;
  real_T c6_gb_x;
  int32_T c6_i365;
  int32_T c6_i366;
  int32_T c6_i367;
  int32_T c6_i368;
  int32_T c6_i369;
  real_T c6_hb_a[9];
  int32_T c6_i370;
  real_T c6_u_b[9];
  int32_T c6_i371;
  real_T c6_nc_A[9];
  int32_T c6_i372;
  real_T c6_kc_B[9];
  int32_T c6_i373;
  real_T c6_oc_A[9];
  int32_T c6_i374;
  real_T c6_lc_B[9];
  int32_T c6_i375;
  real_T c6_pc_A[9];
  int32_T c6_i376;
  real_T c6_mc_B[9];
  int32_T c6_i377;
  int32_T c6_i378;
  int32_T c6_i379;
  real_T c6_ib_a[9];
  int32_T c6_i380;
  int32_T c6_i381;
  int32_T c6_i382;
  real_T c6_v_b[18];
  int32_T c6_i383;
  real_T c6_qc_A[9];
  int32_T c6_i384;
  real_T c6_nc_B[18];
  int32_T c6_i385;
  int32_T c6_i386;
  real_T c6_rc_A[9];
  int32_T c6_i387;
  real_T c6_oc_B[18];
  int32_T c6_i388;
  real_T c6_sc_A[9];
  int32_T c6_i389;
  real_T c6_pc_B[18];
  int32_T c6_i390;
  int32_T c6_i391;
  int32_T c6_i392;
  int32_T c6_i393;
  int32_T c6_i394;
  int32_T c6_i395;
  int32_T c6_i396;
  int32_T c6_i397;
  int32_T c6_i398;
  int32_T c6_i399;
  int32_T c6_i400;
  int32_T c6_i401;
  int32_T c6_i402;
  int32_T c6_i403;
  int32_T c6_i404;
  int32_T c6_i405;
  int32_T c6_i406;
  int32_T c6_i407;
  int32_T c6_i408;
  int32_T c6_i409;
  int32_T c6_i410;
  int32_T c6_i411;
  int32_T c6_i412;
  int32_T c6_i413;
  int32_T c6_i414;
  int32_T c6_i415;
  int32_T c6_i416;
  int32_T c6_i417;
  int32_T c6_i418;
  int32_T c6_i419;
  real_T c6_jb_a[16];
  int32_T c6_i420;
  real_T c6_w_b[16];
  int32_T c6_i421;
  real_T c6_tc_A[16];
  int32_T c6_i422;
  real_T c6_qc_B[16];
  int32_T c6_i423;
  real_T c6_uc_A[16];
  int32_T c6_i424;
  real_T c6_rc_B[16];
  int32_T c6_i425;
  real_T c6_vc_A[16];
  int32_T c6_i426;
  real_T c6_sc_B[16];
  int32_T c6_i427;
  int32_T c6_i428;
  int32_T c6_i429;
  real_T c6_kb_a[16];
  int32_T c6_i430;
  int32_T c6_i431;
  int32_T c6_i432;
  real_T c6_x_b[16];
  int32_T c6_i433;
  real_T c6_wc_A[16];
  int32_T c6_i434;
  real_T c6_tc_B[16];
  int32_T c6_i435;
  real_T c6_xc_A[16];
  int32_T c6_i436;
  real_T c6_uc_B[16];
  int32_T c6_i437;
  real_T c6_yc_A[16];
  int32_T c6_i438;
  real_T c6_vc_B[16];
  int32_T c6_i439;
  int32_T c6_i440;
  int32_T c6_i441;
  real_T c6_lb_a[16];
  int32_T c6_i442;
  int32_T c6_i443;
  int32_T c6_i444;
  real_T c6_y_b[16];
  int32_T c6_i445;
  real_T c6_ad_A[16];
  int32_T c6_i446;
  real_T c6_wc_B[16];
  int32_T c6_i447;
  real_T c6_bd_A[16];
  int32_T c6_i448;
  real_T c6_xc_B[16];
  int32_T c6_i449;
  real_T c6_cd_A[16];
  int32_T c6_i450;
  real_T c6_yc_B[16];
  int32_T c6_i451;
  int32_T c6_i452;
  int32_T c6_i453;
  real_T c6_mb_a[16];
  int32_T c6_i454;
  int32_T c6_i455;
  int32_T c6_i456;
  real_T c6_ab_b[16];
  int32_T c6_i457;
  real_T c6_dd_A[16];
  int32_T c6_i458;
  real_T c6_ad_B[16];
  int32_T c6_i459;
  real_T c6_ed_A[16];
  int32_T c6_i460;
  real_T c6_bd_B[16];
  int32_T c6_i461;
  real_T c6_fd_A[16];
  int32_T c6_i462;
  real_T c6_cd_B[16];
  int32_T c6_i463;
  int32_T c6_i464;
  int32_T c6_i465;
  real_T c6_nb_a[16];
  int32_T c6_i466;
  int32_T c6_i467;
  int32_T c6_i468;
  real_T c6_bb_b[16];
  int32_T c6_i469;
  real_T c6_gd_A[16];
  int32_T c6_i470;
  real_T c6_dd_B[16];
  int32_T c6_i471;
  real_T c6_hd_A[16];
  int32_T c6_i472;
  real_T c6_ed_B[16];
  int32_T c6_i473;
  real_T c6_id_A[16];
  int32_T c6_i474;
  real_T c6_fd_B[16];
  int32_T c6_i475;
  int32_T c6_i476;
  int32_T c6_i477;
  real_T c6_ob_a[16];
  int32_T c6_i478;
  int32_T c6_i479;
  int32_T c6_i480;
  real_T c6_jd_A[16];
  int32_T c6_i481;
  int32_T c6_i482;
  real_T c6_kd_A[16];
  int32_T c6_i483;
  real_T c6_ld_A[16];
  int32_T c6_i484;
  int32_T c6_i485;
  int32_T c6_i486;
  int32_T c6_i487;
  real_T c6_pb_a[16];
  int32_T c6_i488;
  real_T c6_cb_b[16];
  int32_T c6_i489;
  real_T c6_md_A[16];
  int32_T c6_i490;
  real_T c6_gd_B[16];
  int32_T c6_i491;
  real_T c6_nd_A[16];
  int32_T c6_i492;
  real_T c6_hd_B[16];
  int32_T c6_i493;
  real_T c6_od_A[16];
  int32_T c6_i494;
  real_T c6_id_B[16];
  int32_T c6_i495;
  int32_T c6_i496;
  int32_T c6_i497;
  real_T c6_qb_a[16];
  int32_T c6_i498;
  int32_T c6_i499;
  int32_T c6_i500;
  real_T c6_db_b[16];
  int32_T c6_i501;
  real_T c6_pd_A[16];
  int32_T c6_i502;
  real_T c6_jd_B[16];
  int32_T c6_i503;
  real_T c6_qd_A[16];
  int32_T c6_i504;
  real_T c6_kd_B[16];
  int32_T c6_i505;
  real_T c6_rd_A[16];
  int32_T c6_i506;
  real_T c6_ld_B[16];
  int32_T c6_i507;
  int32_T c6_i508;
  int32_T c6_i509;
  real_T c6_rb_a[16];
  int32_T c6_i510;
  int32_T c6_i511;
  int32_T c6_i512;
  real_T c6_eb_b[16];
  int32_T c6_i513;
  real_T c6_sd_A[16];
  int32_T c6_i514;
  real_T c6_md_B[16];
  int32_T c6_i515;
  real_T c6_td_A[16];
  int32_T c6_i516;
  real_T c6_nd_B[16];
  int32_T c6_i517;
  real_T c6_ud_A[16];
  int32_T c6_i518;
  real_T c6_od_B[16];
  int32_T c6_i519;
  int32_T c6_i520;
  int32_T c6_i521;
  real_T c6_sb_a[16];
  int32_T c6_i522;
  int32_T c6_i523;
  int32_T c6_i524;
  real_T c6_fb_b[16];
  int32_T c6_i525;
  real_T c6_vd_A[16];
  int32_T c6_i526;
  real_T c6_pd_B[16];
  int32_T c6_i527;
  real_T c6_wd_A[16];
  int32_T c6_i528;
  real_T c6_qd_B[16];
  int32_T c6_i529;
  real_T c6_xd_A[16];
  int32_T c6_i530;
  real_T c6_rd_B[16];
  int32_T c6_i531;
  int32_T c6_i532;
  int32_T c6_i533;
  real_T c6_tb_a[16];
  int32_T c6_i534;
  int32_T c6_i535;
  int32_T c6_i536;
  real_T c6_gb_b[16];
  int32_T c6_i537;
  real_T c6_yd_A[16];
  int32_T c6_i538;
  real_T c6_sd_B[16];
  int32_T c6_i539;
  real_T c6_ae_A[16];
  int32_T c6_i540;
  real_T c6_td_B[16];
  int32_T c6_i541;
  real_T c6_be_A[16];
  int32_T c6_i542;
  real_T c6_ud_B[16];
  int32_T c6_i543;
  int32_T c6_i544;
  int32_T c6_i545;
  real_T c6_ub_a[16];
  int32_T c6_i546;
  int32_T c6_i547;
  int32_T c6_i548;
  real_T c6_ce_A[16];
  int32_T c6_i549;
  int32_T c6_i550;
  real_T c6_de_A[16];
  int32_T c6_i551;
  real_T c6_ee_A[16];
  int32_T c6_i552;
  int32_T c6_i553;
  int32_T c6_i554;
  int32_T c6_i555;
  real_T c6_vb_a[16];
  int32_T c6_i556;
  real_T c6_hb_b[16];
  int32_T c6_i557;
  real_T c6_fe_A[16];
  int32_T c6_i558;
  real_T c6_vd_B[16];
  int32_T c6_i559;
  real_T c6_ge_A[16];
  int32_T c6_i560;
  real_T c6_wd_B[16];
  int32_T c6_i561;
  real_T c6_he_A[16];
  int32_T c6_i562;
  real_T c6_xd_B[16];
  int32_T c6_i563;
  int32_T c6_i564;
  int32_T c6_i565;
  real_T c6_wb_a[16];
  int32_T c6_i566;
  int32_T c6_i567;
  int32_T c6_i568;
  real_T c6_ib_b[16];
  int32_T c6_i569;
  real_T c6_ie_A[16];
  int32_T c6_i570;
  real_T c6_yd_B[16];
  int32_T c6_i571;
  real_T c6_je_A[16];
  int32_T c6_i572;
  real_T c6_ae_B[16];
  int32_T c6_i573;
  real_T c6_ke_A[16];
  int32_T c6_i574;
  real_T c6_be_B[16];
  int32_T c6_i575;
  int32_T c6_i576;
  int32_T c6_i577;
  real_T c6_xb_a[16];
  int32_T c6_i578;
  int32_T c6_i579;
  int32_T c6_i580;
  real_T c6_jb_b[16];
  int32_T c6_i581;
  real_T c6_le_A[16];
  int32_T c6_i582;
  real_T c6_ce_B[16];
  int32_T c6_i583;
  real_T c6_me_A[16];
  int32_T c6_i584;
  real_T c6_de_B[16];
  int32_T c6_i585;
  real_T c6_ne_A[16];
  int32_T c6_i586;
  real_T c6_ee_B[16];
  int32_T c6_i587;
  int32_T c6_i588;
  int32_T c6_i589;
  real_T c6_yb_a[16];
  int32_T c6_i590;
  int32_T c6_i591;
  int32_T c6_i592;
  real_T c6_kb_b[16];
  int32_T c6_i593;
  real_T c6_oe_A[16];
  int32_T c6_i594;
  real_T c6_fe_B[16];
  int32_T c6_i595;
  real_T c6_pe_A[16];
  int32_T c6_i596;
  real_T c6_ge_B[16];
  int32_T c6_i597;
  real_T c6_qe_A[16];
  int32_T c6_i598;
  real_T c6_he_B[16];
  int32_T c6_i599;
  int32_T c6_i600;
  int32_T c6_i601;
  real_T c6_ac_a[16];
  int32_T c6_i602;
  int32_T c6_i603;
  int32_T c6_i604;
  real_T c6_lb_b[16];
  int32_T c6_i605;
  real_T c6_re_A[16];
  int32_T c6_i606;
  real_T c6_ie_B[16];
  int32_T c6_i607;
  real_T c6_se_A[16];
  int32_T c6_i608;
  real_T c6_je_B[16];
  int32_T c6_i609;
  real_T c6_te_A[16];
  int32_T c6_i610;
  real_T c6_ke_B[16];
  int32_T c6_i611;
  int32_T c6_i612;
  int32_T c6_i613;
  real_T c6_bc_a[16];
  int32_T c6_i614;
  int32_T c6_i615;
  int32_T c6_i616;
  real_T c6_ue_A[16];
  int32_T c6_i617;
  int32_T c6_i618;
  real_T c6_ve_A[16];
  int32_T c6_i619;
  real_T c6_we_A[16];
  int32_T c6_i620;
  int32_T c6_i621;
  int32_T c6_i622;
  int32_T c6_i623;
  real_T c6_cc_a[16];
  int32_T c6_i624;
  real_T c6_mb_b[16];
  int32_T c6_i625;
  real_T c6_xe_A[16];
  int32_T c6_i626;
  real_T c6_le_B[16];
  int32_T c6_i627;
  real_T c6_ye_A[16];
  int32_T c6_i628;
  real_T c6_me_B[16];
  int32_T c6_i629;
  real_T c6_af_A[16];
  int32_T c6_i630;
  real_T c6_ne_B[16];
  int32_T c6_i631;
  int32_T c6_i632;
  int32_T c6_i633;
  real_T c6_dc_a[16];
  int32_T c6_i634;
  int32_T c6_i635;
  int32_T c6_i636;
  real_T c6_nb_b[16];
  int32_T c6_i637;
  real_T c6_bf_A[16];
  int32_T c6_i638;
  real_T c6_oe_B[16];
  int32_T c6_i639;
  real_T c6_cf_A[16];
  int32_T c6_i640;
  real_T c6_pe_B[16];
  int32_T c6_i641;
  real_T c6_df_A[16];
  int32_T c6_i642;
  real_T c6_qe_B[16];
  int32_T c6_i643;
  int32_T c6_i644;
  int32_T c6_i645;
  real_T c6_ec_a[16];
  int32_T c6_i646;
  int32_T c6_i647;
  int32_T c6_i648;
  real_T c6_ob_b[16];
  int32_T c6_i649;
  real_T c6_ef_A[16];
  int32_T c6_i650;
  real_T c6_re_B[16];
  int32_T c6_i651;
  real_T c6_ff_A[16];
  int32_T c6_i652;
  real_T c6_se_B[16];
  int32_T c6_i653;
  real_T c6_gf_A[16];
  int32_T c6_i654;
  real_T c6_te_B[16];
  int32_T c6_i655;
  int32_T c6_i656;
  int32_T c6_i657;
  real_T c6_fc_a[16];
  int32_T c6_i658;
  int32_T c6_i659;
  int32_T c6_i660;
  real_T c6_pb_b[16];
  int32_T c6_i661;
  real_T c6_hf_A[16];
  int32_T c6_i662;
  real_T c6_ue_B[16];
  int32_T c6_i663;
  real_T c6_if_A[16];
  int32_T c6_i664;
  real_T c6_ve_B[16];
  int32_T c6_i665;
  real_T c6_jf_A[16];
  int32_T c6_i666;
  real_T c6_we_B[16];
  int32_T c6_i667;
  int32_T c6_i668;
  int32_T c6_i669;
  real_T c6_gc_a[16];
  int32_T c6_i670;
  int32_T c6_i671;
  int32_T c6_i672;
  real_T c6_qb_b[16];
  int32_T c6_i673;
  real_T c6_kf_A[16];
  int32_T c6_i674;
  real_T c6_xe_B[16];
  int32_T c6_i675;
  real_T c6_lf_A[16];
  int32_T c6_i676;
  real_T c6_ye_B[16];
  int32_T c6_i677;
  real_T c6_mf_A[16];
  int32_T c6_i678;
  real_T c6_af_B[16];
  int32_T c6_i679;
  int32_T c6_i680;
  int32_T c6_i681;
  real_T c6_hc_a[16];
  int32_T c6_i682;
  int32_T c6_i683;
  int32_T c6_i684;
  real_T c6_nf_A[16];
  int32_T c6_i685;
  int32_T c6_i686;
  real_T c6_of_A[16];
  int32_T c6_i687;
  real_T c6_pf_A[16];
  int32_T c6_i688;
  int32_T c6_i689;
  int32_T c6_i690;
  int32_T c6_i691;
  real_T c6_ic_a[16];
  int32_T c6_i692;
  real_T c6_rb_b[16];
  int32_T c6_i693;
  real_T c6_qf_A[16];
  int32_T c6_i694;
  real_T c6_bf_B[16];
  int32_T c6_i695;
  real_T c6_rf_A[16];
  int32_T c6_i696;
  real_T c6_cf_B[16];
  int32_T c6_i697;
  real_T c6_sf_A[16];
  int32_T c6_i698;
  real_T c6_df_B[16];
  int32_T c6_i699;
  int32_T c6_i700;
  int32_T c6_i701;
  real_T c6_jc_a[16];
  int32_T c6_i702;
  int32_T c6_i703;
  int32_T c6_i704;
  real_T c6_sb_b[16];
  int32_T c6_i705;
  real_T c6_tf_A[16];
  int32_T c6_i706;
  real_T c6_ef_B[16];
  int32_T c6_i707;
  real_T c6_uf_A[16];
  int32_T c6_i708;
  real_T c6_ff_B[16];
  int32_T c6_i709;
  real_T c6_vf_A[16];
  int32_T c6_i710;
  real_T c6_gf_B[16];
  int32_T c6_i711;
  int32_T c6_i712;
  int32_T c6_i713;
  real_T c6_kc_a[16];
  int32_T c6_i714;
  int32_T c6_i715;
  int32_T c6_i716;
  real_T c6_tb_b[16];
  int32_T c6_i717;
  real_T c6_wf_A[16];
  int32_T c6_i718;
  real_T c6_hf_B[16];
  int32_T c6_i719;
  real_T c6_xf_A[16];
  int32_T c6_i720;
  real_T c6_if_B[16];
  int32_T c6_i721;
  real_T c6_yf_A[16];
  int32_T c6_i722;
  real_T c6_jf_B[16];
  int32_T c6_i723;
  int32_T c6_i724;
  int32_T c6_i725;
  real_T c6_lc_a[16];
  int32_T c6_i726;
  int32_T c6_i727;
  int32_T c6_i728;
  real_T c6_ub_b[16];
  int32_T c6_i729;
  real_T c6_ag_A[16];
  int32_T c6_i730;
  real_T c6_kf_B[16];
  int32_T c6_i731;
  real_T c6_bg_A[16];
  int32_T c6_i732;
  real_T c6_lf_B[16];
  int32_T c6_i733;
  real_T c6_cg_A[16];
  int32_T c6_i734;
  real_T c6_mf_B[16];
  int32_T c6_i735;
  int32_T c6_i736;
  int32_T c6_i737;
  real_T c6_mc_a[16];
  int32_T c6_i738;
  int32_T c6_i739;
  int32_T c6_i740;
  real_T c6_vb_b[16];
  int32_T c6_i741;
  real_T c6_dg_A[16];
  int32_T c6_i742;
  real_T c6_nf_B[16];
  int32_T c6_i743;
  real_T c6_eg_A[16];
  int32_T c6_i744;
  real_T c6_of_B[16];
  int32_T c6_i745;
  real_T c6_fg_A[16];
  int32_T c6_i746;
  real_T c6_pf_B[16];
  int32_T c6_i747;
  int32_T c6_i748;
  int32_T c6_i749;
  real_T c6_nc_a[16];
  int32_T c6_i750;
  int32_T c6_i751;
  int32_T c6_i752;
  real_T c6_gg_A[16];
  int32_T c6_i753;
  int32_T c6_i754;
  real_T c6_hg_A[16];
  int32_T c6_i755;
  real_T c6_ig_A[16];
  int32_T c6_i756;
  int32_T c6_i757;
  int32_T c6_i758;
  int32_T c6_i759;
  real_T c6_oc_a[16];
  int32_T c6_i760;
  real_T c6_wb_b[16];
  int32_T c6_i761;
  real_T c6_jg_A[16];
  int32_T c6_i762;
  real_T c6_qf_B[16];
  int32_T c6_i763;
  real_T c6_kg_A[16];
  int32_T c6_i764;
  real_T c6_rf_B[16];
  int32_T c6_i765;
  real_T c6_lg_A[16];
  int32_T c6_i766;
  real_T c6_sf_B[16];
  int32_T c6_i767;
  int32_T c6_i768;
  int32_T c6_i769;
  real_T c6_pc_a[16];
  int32_T c6_i770;
  int32_T c6_i771;
  int32_T c6_i772;
  real_T c6_xb_b[16];
  int32_T c6_i773;
  real_T c6_mg_A[16];
  int32_T c6_i774;
  real_T c6_tf_B[16];
  int32_T c6_i775;
  real_T c6_ng_A[16];
  int32_T c6_i776;
  real_T c6_uf_B[16];
  int32_T c6_i777;
  real_T c6_og_A[16];
  int32_T c6_i778;
  real_T c6_vf_B[16];
  int32_T c6_i779;
  int32_T c6_i780;
  int32_T c6_i781;
  real_T c6_qc_a[16];
  int32_T c6_i782;
  int32_T c6_i783;
  int32_T c6_i784;
  real_T c6_yb_b[16];
  int32_T c6_i785;
  real_T c6_pg_A[16];
  int32_T c6_i786;
  real_T c6_wf_B[16];
  int32_T c6_i787;
  real_T c6_qg_A[16];
  int32_T c6_i788;
  real_T c6_xf_B[16];
  int32_T c6_i789;
  real_T c6_rg_A[16];
  int32_T c6_i790;
  real_T c6_yf_B[16];
  int32_T c6_i791;
  int32_T c6_i792;
  int32_T c6_i793;
  real_T c6_rc_a[16];
  int32_T c6_i794;
  int32_T c6_i795;
  int32_T c6_i796;
  real_T c6_ac_b[16];
  int32_T c6_i797;
  real_T c6_sg_A[16];
  int32_T c6_i798;
  real_T c6_ag_B[16];
  int32_T c6_i799;
  real_T c6_tg_A[16];
  int32_T c6_i800;
  real_T c6_bg_B[16];
  int32_T c6_i801;
  real_T c6_ug_A[16];
  int32_T c6_i802;
  real_T c6_cg_B[16];
  int32_T c6_i803;
  int32_T c6_i804;
  int32_T c6_i805;
  real_T c6_sc_a[16];
  int32_T c6_i806;
  int32_T c6_i807;
  int32_T c6_i808;
  real_T c6_bc_b[16];
  int32_T c6_i809;
  real_T c6_vg_A[16];
  int32_T c6_i810;
  real_T c6_dg_B[16];
  int32_T c6_i811;
  real_T c6_wg_A[16];
  int32_T c6_i812;
  real_T c6_eg_B[16];
  int32_T c6_i813;
  real_T c6_xg_A[16];
  int32_T c6_i814;
  real_T c6_fg_B[16];
  int32_T c6_i815;
  int32_T c6_i816;
  int32_T c6_i817;
  real_T c6_tc_a[16];
  int32_T c6_i818;
  int32_T c6_i819;
  int32_T c6_i820;
  real_T c6_yg_A[16];
  int32_T c6_i821;
  int32_T c6_i822;
  real_T c6_ah_A[16];
  int32_T c6_i823;
  real_T c6_bh_A[16];
  int32_T c6_i824;
  int32_T c6_i825;
  int32_T c6_i826;
  int32_T c6_i827;
  int32_T c6_i828;
  int32_T c6_i829;
  int32_T c6_i830;
  int32_T c6_i831;
  int32_T c6_i832;
  int32_T c6_i833;
  int32_T c6_i834;
  int32_T c6_i835;
  int32_T c6_i836;
  int32_T c6_i837;
  int32_T c6_i838;
  int32_T c6_i839;
  int32_T c6_i840;
  int32_T c6_i841;
  real_T c6_b_H[36];
  real_T c6_uc_a[36];
  int32_T c6_i842;
  real_T c6_cc_b[3];
  int32_T c6_i843;
  real_T c6_y[3];
  int32_T c6_i844;
  real_T c6_dc_b[6];
  int32_T c6_i845;
  int32_T c6_i846;
  real_T c6_ch_A[36];
  int32_T c6_i847;
  real_T c6_gg_B[6];
  int32_T c6_i848;
  int32_T c6_i849;
  real_T c6_dh_A[36];
  int32_T c6_i850;
  real_T c6_hg_B[6];
  int32_T c6_i851;
  real_T c6_eh_A[36];
  int32_T c6_i852;
  real_T c6_ig_B[6];
  int32_T c6_i853;
  int32_T c6_i854;
  int32_T c6_i855;
  int32_T c6_i856;
  int32_T c6_i857;
  real_T c6_c_ang[6];
  real_T c6_dv25[6];
  int32_T c6_i858;
  int32_T c6_i859;
  real_T c6_b_d_ang[6];
  int32_T c6_i860;
  real_T c6_e_ang[6];
  real_T c6_ec_b[6];
  int32_T c6_i861;
  int32_T c6_i862;
  real_T c6_b_i;
  int32_T c6_i863;
  int32_T c6_i864;
  real_T (*c6_b_out)[7];
  real_T (*c6_b_vec)[12];
  c6_b_vec = (real_T (*)[12])ssGetInputPortSignal(chartInstance.S, 0);
  c6_b_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,5);
  for (c6_i5 = 0; c6_i5 < 12; c6_i5 = c6_i5 + 1) {
    c6_vec[c6_i5] = (*c6_b_vec)[c6_i5];
  }

  sf_debug_symbol_scope_push(88U, 0U);
  sf_debug_symbol_scope_add("nargout", &c6_nargout, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c6_nargin, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("i", &c6_i, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("J_ANG", &c6_J_ANG, c6_e_sf_marshall);
  sf_debug_symbol_scope_add("d_ang", &c6_d_ang, c6_e_sf_marshall);
  sf_debug_symbol_scope_add("H", &c6_H, c6_l_sf_marshall);
  sf_debug_symbol_scope_add("h", &c6_h, c6_k_sf_marshall);
  sf_debug_symbol_scope_add("h6", &c6_h6, c6_i_sf_marshall);
  sf_debug_symbol_scope_add("h5", &c6_h5, c6_i_sf_marshall);
  sf_debug_symbol_scope_add("h4", &c6_h4, c6_i_sf_marshall);
  sf_debug_symbol_scope_add("h3", &c6_h3, c6_i_sf_marshall);
  sf_debug_symbol_scope_add("h2", &c6_h2, c6_i_sf_marshall);
  sf_debug_symbol_scope_add("h1", &c6_h1, c6_i_sf_marshall);
  sf_debug_symbol_scope_add("dD6", &c6_dD6, c6_g_sf_marshall);
  sf_debug_symbol_scope_add("dD5", &c6_dD5, c6_g_sf_marshall);
  sf_debug_symbol_scope_add("dD4", &c6_dD4, c6_g_sf_marshall);
  sf_debug_symbol_scope_add("dD3", &c6_dD3, c6_g_sf_marshall);
  sf_debug_symbol_scope_add("dD2", &c6_dD2, c6_g_sf_marshall);
  sf_debug_symbol_scope_add("dD1", &c6_dD1, c6_g_sf_marshall);
  sf_debug_symbol_scope_add("TET", &c6_TET, c6_h_sf_marshall);
  sf_debug_symbol_scope_add("PSI", &c6_PSI, c6_h_sf_marshall);
  sf_debug_symbol_scope_add("sn_tet", &c6_sn_tet, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("cs_tet", &c6_cs_tet, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("sn_psi", &c6_sn_psi, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("cs_psi", &c6_cs_psi, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("e", &c6_e, c6_j_sf_marshall);
  sf_debug_symbol_scope_add("e1", &c6_e1, c6_d_sf_marshall);
  sf_debug_symbol_scope_add("e2", &c6_e2, c6_d_sf_marshall);
  sf_debug_symbol_scope_add("e3", &c6_e3, c6_d_sf_marshall);
  sf_debug_symbol_scope_add("e4", &c6_e4, c6_d_sf_marshall);
  sf_debug_symbol_scope_add("e5", &c6_e5, c6_d_sf_marshall);
  sf_debug_symbol_scope_add("e6", &c6_e6, c6_d_sf_marshall);
  sf_debug_symbol_scope_add("eul_ang", &c6_eul_ang, c6_d_sf_marshall);
  sf_debug_symbol_scope_add("E", &c6_E, c6_h_sf_marshall);
  sf_debug_symbol_scope_add("pos", &c6_pos, c6_d_sf_marshall);
  sf_debug_symbol_scope_add("p", &c6_p, c6_i_sf_marshall);
  sf_debug_symbol_scope_add("x6", &c6_x6, c6_i_sf_marshall);
  sf_debug_symbol_scope_add("x_cabin", &c6_x_cabin, c6_d_sf_marshall);
  sf_debug_symbol_scope_add("E6", &c6_E6, c6_h_sf_marshall);
  sf_debug_symbol_scope_add("E5", &c6_E5, c6_h_sf_marshall);
  sf_debug_symbol_scope_add("E4", &c6_E4, c6_h_sf_marshall);
  sf_debug_symbol_scope_add("E3", &c6_E3, c6_h_sf_marshall);
  sf_debug_symbol_scope_add("E2", &c6_E2, c6_h_sf_marshall);
  sf_debug_symbol_scope_add("E1", &c6_E1, c6_h_sf_marshall);
  sf_debug_symbol_scope_add("D6", &c6_D6, c6_g_sf_marshall);
  sf_debug_symbol_scope_add("D5", &c6_D5, c6_g_sf_marshall);
  sf_debug_symbol_scope_add("D4", &c6_D4, c6_g_sf_marshall);
  sf_debug_symbol_scope_add("D3", &c6_D3, c6_g_sf_marshall);
  sf_debug_symbol_scope_add("D2", &c6_D2, c6_g_sf_marshall);
  sf_debug_symbol_scope_add("D1", &c6_D1, c6_g_sf_marshall);
  sf_debug_symbol_scope_add("SA6", &c6_SA6, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("CA6", &c6_CA6, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("SA5", &c6_SA5, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("CA5", &c6_CA5, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("SA4", &c6_SA4, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("CA4", &c6_CA4, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("SA3", &c6_SA3, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("CA3", &c6_CA3, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("SA2", &c6_SA2, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("CA2", &c6_CA2, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("SA1", &c6_SA1, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("CA1", &c6_CA1, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("A6", &c6_A6, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("A5", &c6_A5, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("A4", &c6_A4, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("A3", &c6_A3, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("A2", &c6_A2, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("A1", &c6_A1, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("R1", &c6_R1, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("R", &c6_R, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("L", &c6_L, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("ang", &c6_ang, c6_e_sf_marshall);
  sf_debug_symbol_scope_add("N", &c6_N, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("Height_A2", &c6_Height_A2, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("d", &c6_d, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("l5", &c6_l5, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("l4", &c6_l4, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("l3", &c6_l3, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("l2", &c6_l2, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("l1", &c6_l1, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("SL", &c6_SL, c6_f_sf_marshall);
  sf_debug_symbol_scope_add("J_ANG_0", &c6_J_ANG_0, c6_e_sf_marshall);
  sf_debug_symbol_scope_add("EUL_ANG", &c6_EUL_ANG, c6_d_sf_marshall);
  sf_debug_symbol_scope_add("POS", &c6_POS, c6_d_sf_marshall);
  sf_debug_symbol_scope_add("RTD", &c6_RTD, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("DTR", &c6_DTR, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("out", &c6_out, c6_b_sf_marshall);
  sf_debug_symbol_scope_add("vec", &c6_vec, c6_sf_marshall);
  CV_EML_FCN(0, 0);

  /* -------------------------------------------------------------------------- */
  /*  */
  /*    This function solves the inverse kinematics of the 6-DOF KUKA arm and */
  /*    wrist by means of an iterative algorithm. This is the  version, */
  /*    embedded in Simulink. The input and output are vectors that include the */
  /*    list of parameters as defined herafter */
  /*  */
  /*        *** Input variables, vec(1:13) *** */
  /*  */
  /*    vec(1: 3)    POS         Room coordinates of flange, NED in cm */
  /*    vec(4: 6)    EUL_ANG     Euler angles of the flange, phi, theta, psi, in deg */
  /*    vec(7:12)    J_ANG_0     Initial guess of the joint angles, in deg */
  /*  */
  /*        *** Output Variables *** */
  /*  */
  /*    out(1:6)  J_ANG          The six joint angles after convergence */
  /*    out(7)    N, error code  Number of iterations, when negative, it is an */
  /*                             error code: */
  /*                                -1 no convergence */
  /*                                -2 out of reach of joints */
  /*                                -3 joint angles exceeded */
  /*  */
  /*    The North_East_Down convention is used and psi, theta, phi rotation */
  /*    sequence; A2, A3, A5 are up positive and A4, A6 right rotation positive */
  /*    Note that this is different from the KUKA convention */
  /*  */
  /*    Written by Arthur J. Grunwald, Nov. 14, 2014 */
  /*    Re-written for Simulink embedded, Nov. 20, 2014 */
  /*  */
  /* -------------------------------------------------------------------------- */
  _SFD_EML_CALL(0,33);
  c6_DTR = 1.7453292519943295E-002;
  _SFD_EML_CALL(0,34);
  c6_RTD = 5.7295779513082323E+001;

  /*  reload variables */
  _SFD_EML_CALL(0,37);
  for (c6_i6 = 0; c6_i6 < 3; c6_i6 = c6_i6 + 1) {
    c6_POS[c6_i6] = c6_vec[c6_i6];
  }

  /*  Room coordinates of flange, NED in cm */
  _SFD_EML_CALL(0,38);
  for (c6_i7 = 0; c6_i7 < 3; c6_i7 = c6_i7 + 1) {
    c6_EUL_ANG[c6_i7] = c6_vec[c6_i7 + 3];
  }

  /*  Euler angles of the flange, phi, theta, psi, in deg */
  _SFD_EML_CALL(0,39);
  for (c6_i8 = 0; c6_i8 < 6; c6_i8 = c6_i8 + 1) {
    c6_J_ANG_0[c6_i8] = c6_vec[c6_i8 + 6];
  }

  /*  Initial guess of the joint angles, in deg */
  _SFD_EML_CALL(0,40);
  for (c6_i9 = 0; c6_i9 < 7; c6_i9 = c6_i9 + 1) {
    c6_out[c6_i9] = 0.0;
  }

  /*  reserve place for out */
  /*  soft limits on the links (NED convention) */
  /*  SL = [   175    130     88    200    61    200 */
  /*          -175    -20    -88   -200   -61   -200]; */
  /*  Dec. 6, 2014: A2 and A3 limits changed to KUKA hardware */
  /*  May 7,2015 soft limits on the links (NED convention) */
  _SFD_EML_CALL(0,49);
  for (c6_i10 = 0; c6_i10 < 12; c6_i10 = c6_i10 + 1) {
    c6_SL[c6_i10] = c6_dv1[c6_i10];
  }

  /*  define length of arms */
  _SFD_EML_CALL(0,53);
  c6_l1 = 50.0;

  /*  arm length in cm */
  _SFD_EML_CALL(0,54);
  c6_l2 = 130.0;
  _SFD_EML_CALL(0,55);
  c6_l3 = 66.0;
  _SFD_EML_CALL(0,56);
  c6_l4 = 36.5;
  _SFD_EML_CALL(0,57);
  c6_l5 = 29.0;
  _SFD_EML_CALL(0,58);
  c6_d = 5.5;

  /*  vertical offset of the center line of */
  /*  joint 4 from centerline of arm A3 */
  _SFD_EML_CALL(0,60);
  c6_Height_A2 = 210.5;

  /*  height link A2 above the ground */
  /*  offset the height so that level zero is now at the height of the A2 joint */
  _SFD_EML_CALL(0,63);
  c6_POS[2] = c6_POS[2] + c6_Height_A2;

  /*  set initial guess; the algorithm works in rad, so ang is in rad */
  _SFD_EML_CALL(0,66);
  c6_N = 0.0;
  _SFD_EML_CALL(0,67);
  for (c6_i11 = 0; c6_i11 < 6; c6_i11 = c6_i11 + 1) {
    c6_a[c6_i11] = c6_J_ANG_0[c6_i11];
  }

  for (c6_i12 = 0; c6_i12 < 6; c6_i12 = c6_i12 + 1) {
    c6_ang[c6_i12] = c6_a[c6_i12] * 1.7453292519943295E-002;
  }

  /*  check for maximum range of arm links and exit with n = 2 when exceeded */
  _SFD_EML_CALL(0,70);
  c6_L = 261.5;
  _SFD_EML_CALL(0,71);
  c6_R = c6_sqrt(c6_mpower(261.5) - c6_mpower(c6_POS[2])) + c6_l1;
  _SFD_EML_CALL(0,72);
  c6_R1 = c6_sqrt(c6_mpower(c6_POS[0]) + c6_mpower(c6_POS[1]));
  _SFD_EML_CALL(0,73);
  if (CV_EML_IF(0, 0, c6_R1 > c6_R - 5.0)) {
    _SFD_EML_CALL(0,74);
    for (c6_i13 = 0; c6_i13 < 6; c6_i13 = c6_i13 + 1) {
      c6_out[c6_i13] = c6_J_ANG_0[c6_i13];
    }

    /*  return vector as is */
    _SFD_EML_CALL(0,75);
    c6_out[6] = -2.0;
  } else {
    /* -------------------------------- */
    /*  	start of iterative loop */
    /* -------------------------------- */
   label_2:
    ;
    CV_EML_WHILE(0, 0, true);

    /*  4x4 Transfer matrices, include both rotation and translation */
    _SFD_EML_CALL(0,87);
    for (c6_i14 = 0; c6_i14 < 6; c6_i14 = c6_i14 + 1) {
      c6_b_ang[c6_i14] = c6_ang[c6_i14];
    }

    c6_adjust_ang(c6_b_ang, c6_dv2);
    for (c6_i15 = 0; c6_i15 < 6; c6_i15 = c6_i15 + 1) {
      c6_ang[c6_i15] = c6_dv2[c6_i15];
    }

    /*  ang is brought in the range +-pi */
    _SFD_EML_CALL(0,88);
    c6_A1 = c6_ang[0];
    _SFD_EML_CALL(0,89);
    c6_A2 = c6_ang[1];
    _SFD_EML_CALL(0,90);
    c6_A3 = c6_ang[2];
    _SFD_EML_CALL(0,91);
    c6_A4 = c6_ang[3];
    _SFD_EML_CALL(0,92);
    c6_A5 = c6_ang[4];
    _SFD_EML_CALL(0,93);
    c6_A6 = c6_ang[5];
    _SFD_EML_CALL(0,95);
    c6_x = c6_A1;
    c6_CA1 = c6_x;
    c6_b_x = c6_CA1;
    c6_CA1 = c6_b_x;
    c6_CA1 = muDoubleScalarCos(c6_CA1);
    _SFD_EML_CALL(0,96);
    c6_c_x = c6_A1;
    c6_SA1 = c6_c_x;
    c6_d_x = c6_SA1;
    c6_SA1 = c6_d_x;
    c6_SA1 = muDoubleScalarSin(c6_SA1);
    _SFD_EML_CALL(0,97);
    c6_e_x = c6_A2;
    c6_CA2 = c6_e_x;
    c6_f_x = c6_CA2;
    c6_CA2 = c6_f_x;
    c6_CA2 = muDoubleScalarCos(c6_CA2);
    _SFD_EML_CALL(0,98);
    c6_g_x = c6_A2;
    c6_SA2 = c6_g_x;
    c6_h_x = c6_SA2;
    c6_SA2 = c6_h_x;
    c6_SA2 = muDoubleScalarSin(c6_SA2);
    _SFD_EML_CALL(0,99);
    c6_i_x = c6_A3;
    c6_CA3 = c6_i_x;
    c6_j_x = c6_CA3;
    c6_CA3 = c6_j_x;
    c6_CA3 = muDoubleScalarCos(c6_CA3);
    _SFD_EML_CALL(0,100);
    c6_k_x = c6_A3;
    c6_SA3 = c6_k_x;
    c6_l_x = c6_SA3;
    c6_SA3 = c6_l_x;
    c6_SA3 = muDoubleScalarSin(c6_SA3);
    _SFD_EML_CALL(0,101);
    c6_m_x = c6_A4;
    c6_CA4 = c6_m_x;
    c6_n_x = c6_CA4;
    c6_CA4 = c6_n_x;
    c6_CA4 = muDoubleScalarCos(c6_CA4);
    _SFD_EML_CALL(0,102);
    c6_o_x = c6_A4;
    c6_SA4 = c6_o_x;
    c6_p_x = c6_SA4;
    c6_SA4 = c6_p_x;
    c6_SA4 = muDoubleScalarSin(c6_SA4);
    _SFD_EML_CALL(0,103);
    c6_q_x = c6_A5;
    c6_CA5 = c6_q_x;
    c6_r_x = c6_CA5;
    c6_CA5 = c6_r_x;
    c6_CA5 = muDoubleScalarCos(c6_CA5);
    _SFD_EML_CALL(0,104);
    c6_s_x = c6_A5;
    c6_SA5 = c6_s_x;
    c6_t_x = c6_SA5;
    c6_SA5 = c6_t_x;
    c6_SA5 = muDoubleScalarSin(c6_SA5);
    _SFD_EML_CALL(0,105);
    c6_u_x = c6_A6;
    c6_CA6 = c6_u_x;
    c6_v_x = c6_CA6;
    c6_CA6 = c6_v_x;
    c6_CA6 = muDoubleScalarCos(c6_CA6);
    _SFD_EML_CALL(0,106);
    c6_w_x = c6_A6;
    c6_SA6 = c6_w_x;
    c6_x_x = c6_SA6;
    c6_SA6 = c6_x_x;
    c6_SA6 = muDoubleScalarSin(c6_SA6);
    _SFD_EML_CALL(0,108);
    c6_D1[0] = c6_CA1;
    c6_D1[4] = -c6_SA1;
    c6_D1[8] = 0.0;
    c6_D1[12] = 0.0;
    c6_D1[1] = c6_SA1;
    c6_D1[5] = c6_CA1;
    c6_D1[9] = 0.0;
    c6_D1[13] = 0.0;
    c6_i16 = 0;
    for (c6_i17 = 0; c6_i17 < 4; c6_i17 = c6_i17 + 1) {
      c6_D1[c6_i16 + 2] = c6_dv3[c6_i17];
      c6_i16 = c6_i16 + 4;
    }

    c6_i18 = 0;
    for (c6_i19 = 0; c6_i19 < 4; c6_i19 = c6_i19 + 1) {
      c6_D1[c6_i18 + 3] = c6_dv4[c6_i19];
      c6_i18 = c6_i18 + 4;
    }

    _SFD_EML_CALL(0,109);
    c6_D2[0] = c6_CA2;
    c6_D2[4] = 0.0;
    c6_D2[8] = c6_SA2;
    c6_D2[12] = c6_l1;
    c6_i20 = 0;
    for (c6_i21 = 0; c6_i21 < 4; c6_i21 = c6_i21 + 1) {
      c6_D2[c6_i20 + 1] = c6_dv5[c6_i21];
      c6_i20 = c6_i20 + 4;
    }

    c6_D2[2] = -c6_SA2;
    c6_D2[6] = 0.0;
    c6_D2[10] = c6_CA2;
    c6_D2[14] = 0.0;
    c6_i22 = 0;
    for (c6_i23 = 0; c6_i23 < 4; c6_i23 = c6_i23 + 1) {
      c6_D2[c6_i22 + 3] = c6_dv4[c6_i23];
      c6_i22 = c6_i22 + 4;
    }

    _SFD_EML_CALL(0,110);
    c6_D3[0] = c6_CA3;
    c6_D3[4] = 0.0;
    c6_D3[8] = c6_SA3;
    c6_D3[12] = c6_l2;
    c6_i24 = 0;
    for (c6_i25 = 0; c6_i25 < 4; c6_i25 = c6_i25 + 1) {
      c6_D3[c6_i24 + 1] = c6_dv5[c6_i25];
      c6_i24 = c6_i24 + 4;
    }

    c6_D3[2] = -c6_SA3;
    c6_D3[6] = 0.0;
    c6_D3[10] = c6_CA3;
    c6_D3[14] = 0.0;
    c6_i26 = 0;
    for (c6_i27 = 0; c6_i27 < 4; c6_i27 = c6_i27 + 1) {
      c6_D3[c6_i26 + 3] = c6_dv4[c6_i27];
      c6_i26 = c6_i26 + 4;
    }

    _SFD_EML_CALL(0,111);
    c6_D4[0] = 1.0;
    c6_D4[4] = 0.0;
    c6_D4[8] = 0.0;
    c6_D4[12] = c6_l3;
    c6_D4[1] = 0.0;
    c6_D4[5] = c6_CA4;
    c6_D4[9] = -c6_SA4;
    c6_D4[13] = 0.0;
    c6_D4[2] = 0.0;
    c6_D4[6] = c6_SA4;
    c6_D4[10] = c6_CA4;
    c6_D4[14] = c6_d;
    c6_i28 = 0;
    for (c6_i29 = 0; c6_i29 < 4; c6_i29 = c6_i29 + 1) {
      c6_D4[c6_i28 + 3] = c6_dv4[c6_i29];
      c6_i28 = c6_i28 + 4;
    }

    _SFD_EML_CALL(0,112);
    c6_D5[0] = c6_CA5;
    c6_D5[4] = 0.0;
    c6_D5[8] = c6_SA5;
    c6_D5[12] = c6_l4;
    c6_i30 = 0;
    for (c6_i31 = 0; c6_i31 < 4; c6_i31 = c6_i31 + 1) {
      c6_D5[c6_i30 + 1] = c6_dv5[c6_i31];
      c6_i30 = c6_i30 + 4;
    }

    c6_D5[2] = -c6_SA5;
    c6_D5[6] = 0.0;
    c6_D5[10] = c6_CA5;
    c6_D5[14] = 0.0;
    c6_i32 = 0;
    for (c6_i33 = 0; c6_i33 < 4; c6_i33 = c6_i33 + 1) {
      c6_D5[c6_i32 + 3] = c6_dv4[c6_i33];
      c6_i32 = c6_i32 + 4;
    }

    _SFD_EML_CALL(0,113);
    c6_D6[0] = 1.0;
    c6_D6[4] = 0.0;
    c6_D6[8] = 0.0;
    c6_D6[12] = c6_l5;
    c6_D6[1] = 0.0;
    c6_D6[5] = c6_CA6;
    c6_D6[9] = -c6_SA6;
    c6_D6[13] = 0.0;
    c6_D6[2] = 0.0;
    c6_D6[6] = c6_SA6;
    c6_D6[10] = c6_CA6;
    c6_D6[14] = 0.0;
    c6_i34 = 0;
    for (c6_i35 = 0; c6_i35 < 4; c6_i35 = c6_i35 + 1) {
      c6_D6[c6_i34 + 3] = c6_dv4[c6_i35];
      c6_i34 = c6_i34 + 4;
    }

    /*  cut out the 3x3 DCM's for each of the transfer matrices */
    /*  Note that the DCM is for rotation from b->e */
    _SFD_EML_CALL(0,117);
    c6_i36 = 0;
    c6_i37 = 0;
    for (c6_i38 = 0; c6_i38 < 3; c6_i38 = c6_i38 + 1) {
      for (c6_i39 = 0; c6_i39 < 3; c6_i39 = c6_i39 + 1) {
        c6_E1[c6_i39 + c6_i36] = c6_D1[c6_i39 + c6_i37];
      }

      c6_i36 = c6_i36 + 3;
      c6_i37 = c6_i37 + 4;
    }

    _SFD_EML_CALL(0,118);
    c6_i40 = 0;
    c6_i41 = 0;
    for (c6_i42 = 0; c6_i42 < 3; c6_i42 = c6_i42 + 1) {
      for (c6_i43 = 0; c6_i43 < 3; c6_i43 = c6_i43 + 1) {
        c6_E2[c6_i43 + c6_i40] = c6_D2[c6_i43 + c6_i41];
      }

      c6_i40 = c6_i40 + 3;
      c6_i41 = c6_i41 + 4;
    }

    _SFD_EML_CALL(0,119);
    c6_i44 = 0;
    c6_i45 = 0;
    for (c6_i46 = 0; c6_i46 < 3; c6_i46 = c6_i46 + 1) {
      for (c6_i47 = 0; c6_i47 < 3; c6_i47 = c6_i47 + 1) {
        c6_E3[c6_i47 + c6_i44] = c6_D3[c6_i47 + c6_i45];
      }

      c6_i44 = c6_i44 + 3;
      c6_i45 = c6_i45 + 4;
    }

    _SFD_EML_CALL(0,120);
    c6_i48 = 0;
    c6_i49 = 0;
    for (c6_i50 = 0; c6_i50 < 3; c6_i50 = c6_i50 + 1) {
      for (c6_i51 = 0; c6_i51 < 3; c6_i51 = c6_i51 + 1) {
        c6_E4[c6_i51 + c6_i48] = c6_D4[c6_i51 + c6_i49];
      }

      c6_i48 = c6_i48 + 3;
      c6_i49 = c6_i49 + 4;
    }

    _SFD_EML_CALL(0,121);
    c6_i52 = 0;
    c6_i53 = 0;
    for (c6_i54 = 0; c6_i54 < 3; c6_i54 = c6_i54 + 1) {
      for (c6_i55 = 0; c6_i55 < 3; c6_i55 = c6_i55 + 1) {
        c6_E5[c6_i55 + c6_i52] = c6_D5[c6_i55 + c6_i53];
      }

      c6_i52 = c6_i52 + 3;
      c6_i53 = c6_i53 + 4;
    }

    _SFD_EML_CALL(0,122);
    c6_i56 = 0;
    c6_i57 = 0;
    for (c6_i58 = 0; c6_i58 < 3; c6_i58 = c6_i58 + 1) {
      for (c6_i59 = 0; c6_i59 < 3; c6_i59 = c6_i59 + 1) {
        c6_E6[c6_i59 + c6_i56] = c6_D6[c6_i59 + c6_i57];
      }

      c6_i56 = c6_i56 + 3;
      c6_i57 = c6_i57 + 4;
    }

    /*  --- computed position from links A1-A6 --- */
    /* ---------------------------------------------------------------------- */
    /*    In order to move a point in the cabine in 6-DOF rather than the */
    /*    endplate, define the coordinates of that point in x_cabin */
    /* ---------------------------------------------------------------------- */
    _SFD_EML_CALL(0,130);
    for (c6_i60 = 0; c6_i60 < 3; c6_i60 = c6_i60 + 1) {
      c6_x_cabin[c6_i60] = 0.0;
    }

    /*  x,y,z cabin reference point (cm) */
    _SFD_EML_CALL(0,132);
    for (c6_i61 = 0; c6_i61 < 4; c6_i61 = c6_i61 + 1) {
      c6_x6[c6_i61] = c6_dv4[c6_i61];
    }

    _SFD_EML_CALL(0,133);
    for (c6_i62 = 0; c6_i62 < 16; c6_i62 = c6_i62 + 1) {
      c6_b_a[c6_i62] = c6_D1[c6_i62];
    }

    for (c6_i63 = 0; c6_i63 < 16; c6_i63 = c6_i63 + 1) {
      c6_b[c6_i63] = c6_D2[c6_i63];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i64 = 0; c6_i64 < 16; c6_i64 = c6_i64 + 1) {
      c6_A[c6_i64] = c6_b_a[c6_i64];
    }

    for (c6_i65 = 0; c6_i65 < 16; c6_i65 = c6_i65 + 1) {
      c6_B[c6_i65] = c6_b[c6_i65];
    }

    for (c6_i66 = 0; c6_i66 < 16; c6_i66 = c6_i66 + 1) {
      c6_b_A[c6_i66] = c6_A[c6_i66];
    }

    for (c6_i67 = 0; c6_i67 < 16; c6_i67 = c6_i67 + 1) {
      c6_b_B[c6_i67] = c6_B[c6_i67];
    }

    for (c6_i68 = 0; c6_i68 < 16; c6_i68 = c6_i68 + 1) {
      c6_c_A[c6_i68] = c6_b_A[c6_i68];
    }

    for (c6_i69 = 0; c6_i69 < 16; c6_i69 = c6_i69 + 1) {
      c6_c_B[c6_i69] = c6_b_B[c6_i69];
    }

    for (c6_i70 = 0; c6_i70 < 4; c6_i70 = c6_i70 + 1) {
      c6_i71 = 0;
      for (c6_i72 = 0; c6_i72 < 4; c6_i72 = c6_i72 + 1) {
        c6_c_a[c6_i71 + c6_i70] = 0.0;
        c6_i73 = 0;
        for (c6_i74 = 0; c6_i74 < 4; c6_i74 = c6_i74 + 1) {
          c6_c_a[c6_i71 + c6_i70] = c6_c_a[c6_i71 + c6_i70] + c6_c_A[c6_i73 +
            c6_i70] * c6_c_B[c6_i74 + c6_i71];
          c6_i73 = c6_i73 + 4;
        }

        c6_i71 = c6_i71 + 4;
      }
    }

    for (c6_i75 = 0; c6_i75 < 16; c6_i75 = c6_i75 + 1) {
      c6_b_b[c6_i75] = c6_D3[c6_i75];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i76 = 0; c6_i76 < 16; c6_i76 = c6_i76 + 1) {
      c6_d_A[c6_i76] = c6_c_a[c6_i76];
    }

    for (c6_i77 = 0; c6_i77 < 16; c6_i77 = c6_i77 + 1) {
      c6_d_B[c6_i77] = c6_b_b[c6_i77];
    }

    for (c6_i78 = 0; c6_i78 < 16; c6_i78 = c6_i78 + 1) {
      c6_e_A[c6_i78] = c6_d_A[c6_i78];
    }

    for (c6_i79 = 0; c6_i79 < 16; c6_i79 = c6_i79 + 1) {
      c6_e_B[c6_i79] = c6_d_B[c6_i79];
    }

    for (c6_i80 = 0; c6_i80 < 16; c6_i80 = c6_i80 + 1) {
      c6_f_A[c6_i80] = c6_e_A[c6_i80];
    }

    for (c6_i81 = 0; c6_i81 < 16; c6_i81 = c6_i81 + 1) {
      c6_f_B[c6_i81] = c6_e_B[c6_i81];
    }

    for (c6_i82 = 0; c6_i82 < 4; c6_i82 = c6_i82 + 1) {
      c6_i83 = 0;
      for (c6_i84 = 0; c6_i84 < 4; c6_i84 = c6_i84 + 1) {
        c6_d_a[c6_i83 + c6_i82] = 0.0;
        c6_i85 = 0;
        for (c6_i86 = 0; c6_i86 < 4; c6_i86 = c6_i86 + 1) {
          c6_d_a[c6_i83 + c6_i82] = c6_d_a[c6_i83 + c6_i82] + c6_f_A[c6_i85 +
            c6_i82] * c6_f_B[c6_i86 + c6_i83];
          c6_i85 = c6_i85 + 4;
        }

        c6_i83 = c6_i83 + 4;
      }
    }

    for (c6_i87 = 0; c6_i87 < 16; c6_i87 = c6_i87 + 1) {
      c6_c_b[c6_i87] = c6_D4[c6_i87];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i88 = 0; c6_i88 < 16; c6_i88 = c6_i88 + 1) {
      c6_g_A[c6_i88] = c6_d_a[c6_i88];
    }

    for (c6_i89 = 0; c6_i89 < 16; c6_i89 = c6_i89 + 1) {
      c6_g_B[c6_i89] = c6_c_b[c6_i89];
    }

    for (c6_i90 = 0; c6_i90 < 16; c6_i90 = c6_i90 + 1) {
      c6_h_A[c6_i90] = c6_g_A[c6_i90];
    }

    for (c6_i91 = 0; c6_i91 < 16; c6_i91 = c6_i91 + 1) {
      c6_h_B[c6_i91] = c6_g_B[c6_i91];
    }

    for (c6_i92 = 0; c6_i92 < 16; c6_i92 = c6_i92 + 1) {
      c6_i_A[c6_i92] = c6_h_A[c6_i92];
    }

    for (c6_i93 = 0; c6_i93 < 16; c6_i93 = c6_i93 + 1) {
      c6_i_B[c6_i93] = c6_h_B[c6_i93];
    }

    for (c6_i94 = 0; c6_i94 < 4; c6_i94 = c6_i94 + 1) {
      c6_i95 = 0;
      for (c6_i96 = 0; c6_i96 < 4; c6_i96 = c6_i96 + 1) {
        c6_e_a[c6_i95 + c6_i94] = 0.0;
        c6_i97 = 0;
        for (c6_i98 = 0; c6_i98 < 4; c6_i98 = c6_i98 + 1) {
          c6_e_a[c6_i95 + c6_i94] = c6_e_a[c6_i95 + c6_i94] + c6_i_A[c6_i97 +
            c6_i94] * c6_i_B[c6_i98 + c6_i95];
          c6_i97 = c6_i97 + 4;
        }

        c6_i95 = c6_i95 + 4;
      }
    }

    for (c6_i99 = 0; c6_i99 < 16; c6_i99 = c6_i99 + 1) {
      c6_d_b[c6_i99] = c6_D5[c6_i99];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i100 = 0; c6_i100 < 16; c6_i100 = c6_i100 + 1) {
      c6_j_A[c6_i100] = c6_e_a[c6_i100];
    }

    for (c6_i101 = 0; c6_i101 < 16; c6_i101 = c6_i101 + 1) {
      c6_j_B[c6_i101] = c6_d_b[c6_i101];
    }

    for (c6_i102 = 0; c6_i102 < 16; c6_i102 = c6_i102 + 1) {
      c6_k_A[c6_i102] = c6_j_A[c6_i102];
    }

    for (c6_i103 = 0; c6_i103 < 16; c6_i103 = c6_i103 + 1) {
      c6_k_B[c6_i103] = c6_j_B[c6_i103];
    }

    for (c6_i104 = 0; c6_i104 < 16; c6_i104 = c6_i104 + 1) {
      c6_l_A[c6_i104] = c6_k_A[c6_i104];
    }

    for (c6_i105 = 0; c6_i105 < 16; c6_i105 = c6_i105 + 1) {
      c6_l_B[c6_i105] = c6_k_B[c6_i105];
    }

    for (c6_i106 = 0; c6_i106 < 4; c6_i106 = c6_i106 + 1) {
      c6_i107 = 0;
      for (c6_i108 = 0; c6_i108 < 4; c6_i108 = c6_i108 + 1) {
        c6_f_a[c6_i107 + c6_i106] = 0.0;
        c6_i109 = 0;
        for (c6_i110 = 0; c6_i110 < 4; c6_i110 = c6_i110 + 1) {
          c6_f_a[c6_i107 + c6_i106] = c6_f_a[c6_i107 + c6_i106] + c6_l_A[c6_i109
            + c6_i106] * c6_l_B[c6_i110 + c6_i107];
          c6_i109 = c6_i109 + 4;
        }

        c6_i107 = c6_i107 + 4;
      }
    }

    for (c6_i111 = 0; c6_i111 < 16; c6_i111 = c6_i111 + 1) {
      c6_e_b[c6_i111] = c6_D6[c6_i111];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i112 = 0; c6_i112 < 16; c6_i112 = c6_i112 + 1) {
      c6_m_A[c6_i112] = c6_f_a[c6_i112];
    }

    for (c6_i113 = 0; c6_i113 < 16; c6_i113 = c6_i113 + 1) {
      c6_m_B[c6_i113] = c6_e_b[c6_i113];
    }

    for (c6_i114 = 0; c6_i114 < 16; c6_i114 = c6_i114 + 1) {
      c6_n_A[c6_i114] = c6_m_A[c6_i114];
    }

    for (c6_i115 = 0; c6_i115 < 16; c6_i115 = c6_i115 + 1) {
      c6_n_B[c6_i115] = c6_m_B[c6_i115];
    }

    for (c6_i116 = 0; c6_i116 < 16; c6_i116 = c6_i116 + 1) {
      c6_o_A[c6_i116] = c6_n_A[c6_i116];
    }

    for (c6_i117 = 0; c6_i117 < 16; c6_i117 = c6_i117 + 1) {
      c6_o_B[c6_i117] = c6_n_B[c6_i117];
    }

    for (c6_i118 = 0; c6_i118 < 4; c6_i118 = c6_i118 + 1) {
      c6_i119 = 0;
      for (c6_i120 = 0; c6_i120 < 4; c6_i120 = c6_i120 + 1) {
        c6_g_a[c6_i119 + c6_i118] = 0.0;
        c6_i121 = 0;
        for (c6_i122 = 0; c6_i122 < 4; c6_i122 = c6_i122 + 1) {
          c6_g_a[c6_i119 + c6_i118] = c6_g_a[c6_i119 + c6_i118] + c6_o_A[c6_i121
            + c6_i118] * c6_o_B[c6_i122 + c6_i119];
          c6_i121 = c6_i121 + 4;
        }

        c6_i119 = c6_i119 + 4;
      }
    }

    c6_c_eml_scalar_eg();
    c6_c_eml_scalar_eg();
    for (c6_i123 = 0; c6_i123 < 16; c6_i123 = c6_i123 + 1) {
      c6_p_A[c6_i123] = c6_g_a[c6_i123];
    }

    for (c6_i124 = 0; c6_i124 < 4; c6_i124 = c6_i124 + 1) {
      c6_p[c6_i124] = 0.0;
    }

    for (c6_i125 = 0; c6_i125 < 16; c6_i125 = c6_i125 + 1) {
      c6_q_A[c6_i125] = c6_p_A[c6_i125];
    }

    for (c6_i126 = 0; c6_i126 < 16; c6_i126 = c6_i126 + 1) {
      c6_r_A[c6_i126] = c6_q_A[c6_i126];
    }

    for (c6_i127 = 0; c6_i127 < 4; c6_i127 = c6_i127 + 1) {
      c6_p[c6_i127] = 0.0;
      c6_i128 = 0;
      for (c6_i129 = 0; c6_i129 < 4; c6_i129 = c6_i129 + 1) {
        c6_p[c6_i127] = c6_p[c6_i127] + c6_r_A[c6_i128 + c6_i127] *
          c6_dv4[c6_i129];
        c6_i128 = c6_i128 + 4;
      }
    }

    _SFD_EML_CALL(0,134);
    for (c6_i130 = 0; c6_i130 < 3; c6_i130 = c6_i130 + 1) {
      c6_pos[c6_i130] = c6_p[c6_i130];
    }

    /*  position of the cabin reference point in the */
    /*  NED system (cm) */
    /*  computed Euler angles from links A1-A6 */
    /*  Euler matrices for rotation from e->b (note the transpose) */
    _SFD_EML_CALL(0,139);
    c6_i131 = 0;
    for (c6_i132 = 0; c6_i132 < 3; c6_i132 = c6_i132 + 1) {
      c6_i133 = 0;
      for (c6_i134 = 0; c6_i134 < 3; c6_i134 = c6_i134 + 1) {
        c6_h_a[c6_i134 + c6_i131] = c6_E6[c6_i133 + c6_i132];
        c6_i133 = c6_i133 + 3;
      }

      c6_i131 = c6_i131 + 3;
    }

    c6_i135 = 0;
    for (c6_i136 = 0; c6_i136 < 3; c6_i136 = c6_i136 + 1) {
      c6_i137 = 0;
      for (c6_i138 = 0; c6_i138 < 3; c6_i138 = c6_i138 + 1) {
        c6_f_b[c6_i138 + c6_i135] = c6_E5[c6_i137 + c6_i136];
        c6_i137 = c6_i137 + 3;
      }

      c6_i135 = c6_i135 + 3;
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i139 = 0; c6_i139 < 9; c6_i139 = c6_i139 + 1) {
      c6_s_A[c6_i139] = c6_h_a[c6_i139];
    }

    for (c6_i140 = 0; c6_i140 < 9; c6_i140 = c6_i140 + 1) {
      c6_p_B[c6_i140] = c6_f_b[c6_i140];
    }

    for (c6_i141 = 0; c6_i141 < 9; c6_i141 = c6_i141 + 1) {
      c6_t_A[c6_i141] = c6_s_A[c6_i141];
    }

    for (c6_i142 = 0; c6_i142 < 9; c6_i142 = c6_i142 + 1) {
      c6_q_B[c6_i142] = c6_p_B[c6_i142];
    }

    for (c6_i143 = 0; c6_i143 < 9; c6_i143 = c6_i143 + 1) {
      c6_u_A[c6_i143] = c6_t_A[c6_i143];
    }

    for (c6_i144 = 0; c6_i144 < 9; c6_i144 = c6_i144 + 1) {
      c6_r_B[c6_i144] = c6_q_B[c6_i144];
    }

    for (c6_i145 = 0; c6_i145 < 3; c6_i145 = c6_i145 + 1) {
      c6_i146 = 0;
      for (c6_i147 = 0; c6_i147 < 3; c6_i147 = c6_i147 + 1) {
        c6_i_a[c6_i146 + c6_i145] = 0.0;
        c6_i148 = 0;
        for (c6_i149 = 0; c6_i149 < 3; c6_i149 = c6_i149 + 1) {
          c6_i_a[c6_i146 + c6_i145] = c6_i_a[c6_i146 + c6_i145] + c6_u_A[c6_i148
            + c6_i145] * c6_r_B[c6_i149 + c6_i146];
          c6_i148 = c6_i148 + 3;
        }

        c6_i146 = c6_i146 + 3;
      }
    }

    c6_i150 = 0;
    for (c6_i151 = 0; c6_i151 < 3; c6_i151 = c6_i151 + 1) {
      c6_i152 = 0;
      for (c6_i153 = 0; c6_i153 < 3; c6_i153 = c6_i153 + 1) {
        c6_g_b[c6_i153 + c6_i150] = c6_E4[c6_i152 + c6_i151];
        c6_i152 = c6_i152 + 3;
      }

      c6_i150 = c6_i150 + 3;
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i154 = 0; c6_i154 < 9; c6_i154 = c6_i154 + 1) {
      c6_v_A[c6_i154] = c6_i_a[c6_i154];
    }

    for (c6_i155 = 0; c6_i155 < 9; c6_i155 = c6_i155 + 1) {
      c6_s_B[c6_i155] = c6_g_b[c6_i155];
    }

    for (c6_i156 = 0; c6_i156 < 9; c6_i156 = c6_i156 + 1) {
      c6_w_A[c6_i156] = c6_v_A[c6_i156];
    }

    for (c6_i157 = 0; c6_i157 < 9; c6_i157 = c6_i157 + 1) {
      c6_t_B[c6_i157] = c6_s_B[c6_i157];
    }

    for (c6_i158 = 0; c6_i158 < 9; c6_i158 = c6_i158 + 1) {
      c6_x_A[c6_i158] = c6_w_A[c6_i158];
    }

    for (c6_i159 = 0; c6_i159 < 9; c6_i159 = c6_i159 + 1) {
      c6_u_B[c6_i159] = c6_t_B[c6_i159];
    }

    for (c6_i160 = 0; c6_i160 < 3; c6_i160 = c6_i160 + 1) {
      c6_i161 = 0;
      for (c6_i162 = 0; c6_i162 < 3; c6_i162 = c6_i162 + 1) {
        c6_j_a[c6_i161 + c6_i160] = 0.0;
        c6_i163 = 0;
        for (c6_i164 = 0; c6_i164 < 3; c6_i164 = c6_i164 + 1) {
          c6_j_a[c6_i161 + c6_i160] = c6_j_a[c6_i161 + c6_i160] + c6_x_A[c6_i163
            + c6_i160] * c6_u_B[c6_i164 + c6_i161];
          c6_i163 = c6_i163 + 3;
        }

        c6_i161 = c6_i161 + 3;
      }
    }

    c6_i165 = 0;
    for (c6_i166 = 0; c6_i166 < 3; c6_i166 = c6_i166 + 1) {
      c6_i167 = 0;
      for (c6_i168 = 0; c6_i168 < 3; c6_i168 = c6_i168 + 1) {
        c6_h_b[c6_i168 + c6_i165] = c6_E3[c6_i167 + c6_i166];
        c6_i167 = c6_i167 + 3;
      }

      c6_i165 = c6_i165 + 3;
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i169 = 0; c6_i169 < 9; c6_i169 = c6_i169 + 1) {
      c6_y_A[c6_i169] = c6_j_a[c6_i169];
    }

    for (c6_i170 = 0; c6_i170 < 9; c6_i170 = c6_i170 + 1) {
      c6_v_B[c6_i170] = c6_h_b[c6_i170];
    }

    for (c6_i171 = 0; c6_i171 < 9; c6_i171 = c6_i171 + 1) {
      c6_ab_A[c6_i171] = c6_y_A[c6_i171];
    }

    for (c6_i172 = 0; c6_i172 < 9; c6_i172 = c6_i172 + 1) {
      c6_w_B[c6_i172] = c6_v_B[c6_i172];
    }

    for (c6_i173 = 0; c6_i173 < 9; c6_i173 = c6_i173 + 1) {
      c6_bb_A[c6_i173] = c6_ab_A[c6_i173];
    }

    for (c6_i174 = 0; c6_i174 < 9; c6_i174 = c6_i174 + 1) {
      c6_x_B[c6_i174] = c6_w_B[c6_i174];
    }

    for (c6_i175 = 0; c6_i175 < 3; c6_i175 = c6_i175 + 1) {
      c6_i176 = 0;
      for (c6_i177 = 0; c6_i177 < 3; c6_i177 = c6_i177 + 1) {
        c6_k_a[c6_i176 + c6_i175] = 0.0;
        c6_i178 = 0;
        for (c6_i179 = 0; c6_i179 < 3; c6_i179 = c6_i179 + 1) {
          c6_k_a[c6_i176 + c6_i175] = c6_k_a[c6_i176 + c6_i175] +
            c6_bb_A[c6_i178 + c6_i175] * c6_x_B[c6_i179 + c6_i176];
          c6_i178 = c6_i178 + 3;
        }

        c6_i176 = c6_i176 + 3;
      }
    }

    c6_i180 = 0;
    for (c6_i181 = 0; c6_i181 < 3; c6_i181 = c6_i181 + 1) {
      c6_i182 = 0;
      for (c6_i183 = 0; c6_i183 < 3; c6_i183 = c6_i183 + 1) {
        c6_i_b[c6_i183 + c6_i180] = c6_E2[c6_i182 + c6_i181];
        c6_i182 = c6_i182 + 3;
      }

      c6_i180 = c6_i180 + 3;
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i184 = 0; c6_i184 < 9; c6_i184 = c6_i184 + 1) {
      c6_cb_A[c6_i184] = c6_k_a[c6_i184];
    }

    for (c6_i185 = 0; c6_i185 < 9; c6_i185 = c6_i185 + 1) {
      c6_y_B[c6_i185] = c6_i_b[c6_i185];
    }

    for (c6_i186 = 0; c6_i186 < 9; c6_i186 = c6_i186 + 1) {
      c6_db_A[c6_i186] = c6_cb_A[c6_i186];
    }

    for (c6_i187 = 0; c6_i187 < 9; c6_i187 = c6_i187 + 1) {
      c6_ab_B[c6_i187] = c6_y_B[c6_i187];
    }

    for (c6_i188 = 0; c6_i188 < 9; c6_i188 = c6_i188 + 1) {
      c6_eb_A[c6_i188] = c6_db_A[c6_i188];
    }

    for (c6_i189 = 0; c6_i189 < 9; c6_i189 = c6_i189 + 1) {
      c6_bb_B[c6_i189] = c6_ab_B[c6_i189];
    }

    for (c6_i190 = 0; c6_i190 < 3; c6_i190 = c6_i190 + 1) {
      c6_i191 = 0;
      for (c6_i192 = 0; c6_i192 < 3; c6_i192 = c6_i192 + 1) {
        c6_l_a[c6_i191 + c6_i190] = 0.0;
        c6_i193 = 0;
        for (c6_i194 = 0; c6_i194 < 3; c6_i194 = c6_i194 + 1) {
          c6_l_a[c6_i191 + c6_i190] = c6_l_a[c6_i191 + c6_i190] +
            c6_eb_A[c6_i193 + c6_i190] * c6_bb_B[c6_i194 + c6_i191];
          c6_i193 = c6_i193 + 3;
        }

        c6_i191 = c6_i191 + 3;
      }
    }

    c6_i195 = 0;
    for (c6_i196 = 0; c6_i196 < 3; c6_i196 = c6_i196 + 1) {
      c6_i197 = 0;
      for (c6_i198 = 0; c6_i198 < 3; c6_i198 = c6_i198 + 1) {
        c6_j_b[c6_i198 + c6_i195] = c6_E1[c6_i197 + c6_i196];
        c6_i197 = c6_i197 + 3;
      }

      c6_i195 = c6_i195 + 3;
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i199 = 0; c6_i199 < 9; c6_i199 = c6_i199 + 1) {
      c6_fb_A[c6_i199] = c6_l_a[c6_i199];
    }

    for (c6_i200 = 0; c6_i200 < 9; c6_i200 = c6_i200 + 1) {
      c6_cb_B[c6_i200] = c6_j_b[c6_i200];
    }

    for (c6_i201 = 0; c6_i201 < 9; c6_i201 = c6_i201 + 1) {
      c6_E[c6_i201] = 0.0;
    }

    for (c6_i202 = 0; c6_i202 < 9; c6_i202 = c6_i202 + 1) {
      c6_gb_A[c6_i202] = c6_fb_A[c6_i202];
    }

    for (c6_i203 = 0; c6_i203 < 9; c6_i203 = c6_i203 + 1) {
      c6_db_B[c6_i203] = c6_cb_B[c6_i203];
    }

    for (c6_i204 = 0; c6_i204 < 9; c6_i204 = c6_i204 + 1) {
      c6_hb_A[c6_i204] = c6_gb_A[c6_i204];
    }

    for (c6_i205 = 0; c6_i205 < 9; c6_i205 = c6_i205 + 1) {
      c6_eb_B[c6_i205] = c6_db_B[c6_i205];
    }

    for (c6_i206 = 0; c6_i206 < 3; c6_i206 = c6_i206 + 1) {
      c6_i207 = 0;
      for (c6_i208 = 0; c6_i208 < 3; c6_i208 = c6_i208 + 1) {
        c6_E[c6_i207 + c6_i206] = 0.0;
        c6_i209 = 0;
        for (c6_i210 = 0; c6_i210 < 3; c6_i210 = c6_i210 + 1) {
          c6_E[c6_i207 + c6_i206] = c6_E[c6_i207 + c6_i206] + c6_hb_A[c6_i209 +
            c6_i206] * c6_eb_B[c6_i210 + c6_i207];
          c6_i209 = c6_i209 + 3;
        }

        c6_i207 = c6_i207 + 3;
      }
    }

    _SFD_EML_CALL(0,140);
    for (c6_i211 = 0; c6_i211 < 9; c6_i211 = c6_i211 + 1) {
      c6_b_E[c6_i211] = c6_E[c6_i211];
    }

    c6_DCM2Eul(c6_b_E, c6_dv6);
    for (c6_i212 = 0; c6_i212 < 3; c6_i212 = c6_i212 + 1) {
      c6_eul_ang[c6_i212] = c6_dv6[c6_i212];
    }

    /*  determine the vectors of rotation of the endplate in e-system */
    /*  for each one of the links; this is a 3x6 matrix, when multiplied */
    /*  with the vector of the joint angles, it will give the vector */
    /*  of rotation of the endplate (and also of the cabin reference point) */
    /*  in the NED system */
    _SFD_EML_CALL(0,148);
    for (c6_i213 = 0; c6_i213 < 9; c6_i213 = c6_i213 + 1) {
      c6_m_a[c6_i213] = c6_E1[c6_i213];
    }

    for (c6_i214 = 0; c6_i214 < 9; c6_i214 = c6_i214 + 1) {
      c6_k_b[c6_i214] = c6_E2[c6_i214];
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i215 = 0; c6_i215 < 9; c6_i215 = c6_i215 + 1) {
      c6_ib_A[c6_i215] = c6_m_a[c6_i215];
    }

    for (c6_i216 = 0; c6_i216 < 9; c6_i216 = c6_i216 + 1) {
      c6_fb_B[c6_i216] = c6_k_b[c6_i216];
    }

    for (c6_i217 = 0; c6_i217 < 9; c6_i217 = c6_i217 + 1) {
      c6_jb_A[c6_i217] = c6_ib_A[c6_i217];
    }

    for (c6_i218 = 0; c6_i218 < 9; c6_i218 = c6_i218 + 1) {
      c6_gb_B[c6_i218] = c6_fb_B[c6_i218];
    }

    for (c6_i219 = 0; c6_i219 < 9; c6_i219 = c6_i219 + 1) {
      c6_kb_A[c6_i219] = c6_jb_A[c6_i219];
    }

    for (c6_i220 = 0; c6_i220 < 9; c6_i220 = c6_i220 + 1) {
      c6_hb_B[c6_i220] = c6_gb_B[c6_i220];
    }

    for (c6_i221 = 0; c6_i221 < 3; c6_i221 = c6_i221 + 1) {
      c6_i222 = 0;
      for (c6_i223 = 0; c6_i223 < 3; c6_i223 = c6_i223 + 1) {
        c6_n_a[c6_i222 + c6_i221] = 0.0;
        c6_i224 = 0;
        for (c6_i225 = 0; c6_i225 < 3; c6_i225 = c6_i225 + 1) {
          c6_n_a[c6_i222 + c6_i221] = c6_n_a[c6_i222 + c6_i221] +
            c6_kb_A[c6_i224 + c6_i221] * c6_hb_B[c6_i225 + c6_i222];
          c6_i224 = c6_i224 + 3;
        }

        c6_i222 = c6_i222 + 3;
      }
    }

    for (c6_i226 = 0; c6_i226 < 9; c6_i226 = c6_i226 + 1) {
      c6_l_b[c6_i226] = c6_E3[c6_i226];
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i227 = 0; c6_i227 < 9; c6_i227 = c6_i227 + 1) {
      c6_lb_A[c6_i227] = c6_n_a[c6_i227];
    }

    for (c6_i228 = 0; c6_i228 < 9; c6_i228 = c6_i228 + 1) {
      c6_ib_B[c6_i228] = c6_l_b[c6_i228];
    }

    for (c6_i229 = 0; c6_i229 < 9; c6_i229 = c6_i229 + 1) {
      c6_mb_A[c6_i229] = c6_lb_A[c6_i229];
    }

    for (c6_i230 = 0; c6_i230 < 9; c6_i230 = c6_i230 + 1) {
      c6_jb_B[c6_i230] = c6_ib_B[c6_i230];
    }

    for (c6_i231 = 0; c6_i231 < 9; c6_i231 = c6_i231 + 1) {
      c6_nb_A[c6_i231] = c6_mb_A[c6_i231];
    }

    for (c6_i232 = 0; c6_i232 < 9; c6_i232 = c6_i232 + 1) {
      c6_kb_B[c6_i232] = c6_jb_B[c6_i232];
    }

    for (c6_i233 = 0; c6_i233 < 3; c6_i233 = c6_i233 + 1) {
      c6_i234 = 0;
      for (c6_i235 = 0; c6_i235 < 3; c6_i235 = c6_i235 + 1) {
        c6_o_a[c6_i234 + c6_i233] = 0.0;
        c6_i236 = 0;
        for (c6_i237 = 0; c6_i237 < 3; c6_i237 = c6_i237 + 1) {
          c6_o_a[c6_i234 + c6_i233] = c6_o_a[c6_i234 + c6_i233] +
            c6_nb_A[c6_i236 + c6_i233] * c6_kb_B[c6_i237 + c6_i234];
          c6_i236 = c6_i236 + 3;
        }

        c6_i234 = c6_i234 + 3;
      }
    }

    for (c6_i238 = 0; c6_i238 < 9; c6_i238 = c6_i238 + 1) {
      c6_m_b[c6_i238] = c6_E4[c6_i238];
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i239 = 0; c6_i239 < 9; c6_i239 = c6_i239 + 1) {
      c6_ob_A[c6_i239] = c6_o_a[c6_i239];
    }

    for (c6_i240 = 0; c6_i240 < 9; c6_i240 = c6_i240 + 1) {
      c6_lb_B[c6_i240] = c6_m_b[c6_i240];
    }

    for (c6_i241 = 0; c6_i241 < 9; c6_i241 = c6_i241 + 1) {
      c6_pb_A[c6_i241] = c6_ob_A[c6_i241];
    }

    for (c6_i242 = 0; c6_i242 < 9; c6_i242 = c6_i242 + 1) {
      c6_mb_B[c6_i242] = c6_lb_B[c6_i242];
    }

    for (c6_i243 = 0; c6_i243 < 9; c6_i243 = c6_i243 + 1) {
      c6_qb_A[c6_i243] = c6_pb_A[c6_i243];
    }

    for (c6_i244 = 0; c6_i244 < 9; c6_i244 = c6_i244 + 1) {
      c6_nb_B[c6_i244] = c6_mb_B[c6_i244];
    }

    for (c6_i245 = 0; c6_i245 < 3; c6_i245 = c6_i245 + 1) {
      c6_i246 = 0;
      for (c6_i247 = 0; c6_i247 < 3; c6_i247 = c6_i247 + 1) {
        c6_p_a[c6_i246 + c6_i245] = 0.0;
        c6_i248 = 0;
        for (c6_i249 = 0; c6_i249 < 3; c6_i249 = c6_i249 + 1) {
          c6_p_a[c6_i246 + c6_i245] = c6_p_a[c6_i246 + c6_i245] +
            c6_qb_A[c6_i248 + c6_i245] * c6_nb_B[c6_i249 + c6_i246];
          c6_i248 = c6_i248 + 3;
        }

        c6_i246 = c6_i246 + 3;
      }
    }

    for (c6_i250 = 0; c6_i250 < 9; c6_i250 = c6_i250 + 1) {
      c6_n_b[c6_i250] = c6_E5[c6_i250];
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i251 = 0; c6_i251 < 9; c6_i251 = c6_i251 + 1) {
      c6_rb_A[c6_i251] = c6_p_a[c6_i251];
    }

    for (c6_i252 = 0; c6_i252 < 9; c6_i252 = c6_i252 + 1) {
      c6_ob_B[c6_i252] = c6_n_b[c6_i252];
    }

    for (c6_i253 = 0; c6_i253 < 9; c6_i253 = c6_i253 + 1) {
      c6_sb_A[c6_i253] = c6_rb_A[c6_i253];
    }

    for (c6_i254 = 0; c6_i254 < 9; c6_i254 = c6_i254 + 1) {
      c6_pb_B[c6_i254] = c6_ob_B[c6_i254];
    }

    for (c6_i255 = 0; c6_i255 < 9; c6_i255 = c6_i255 + 1) {
      c6_tb_A[c6_i255] = c6_sb_A[c6_i255];
    }

    for (c6_i256 = 0; c6_i256 < 9; c6_i256 = c6_i256 + 1) {
      c6_qb_B[c6_i256] = c6_pb_B[c6_i256];
    }

    for (c6_i257 = 0; c6_i257 < 3; c6_i257 = c6_i257 + 1) {
      c6_i258 = 0;
      for (c6_i259 = 0; c6_i259 < 3; c6_i259 = c6_i259 + 1) {
        c6_q_a[c6_i258 + c6_i257] = 0.0;
        c6_i260 = 0;
        for (c6_i261 = 0; c6_i261 < 3; c6_i261 = c6_i261 + 1) {
          c6_q_a[c6_i258 + c6_i257] = c6_q_a[c6_i258 + c6_i257] +
            c6_tb_A[c6_i260 + c6_i257] * c6_qb_B[c6_i261 + c6_i258];
          c6_i260 = c6_i260 + 3;
        }

        c6_i258 = c6_i258 + 3;
      }
    }

    c6_e_eml_scalar_eg();
    c6_e_eml_scalar_eg();
    for (c6_i262 = 0; c6_i262 < 9; c6_i262 = c6_i262 + 1) {
      c6_r_a[c6_i262] = c6_q_a[c6_i262];
    }

    for (c6_i263 = 0; c6_i263 < 3; c6_i263 = c6_i263 + 1) {
      c6_dv8[c6_i263] = c6_dv7[c6_i263];
    }

    for (c6_i264 = 0; c6_i264 < 3; c6_i264 = c6_i264 + 1) {
      c6_dv9[c6_i264] = 0.0;
    }

    c6_eml_xgemm(c6_r_a, c6_dv8, c6_dv9, c6_dv10);
    for (c6_i265 = 0; c6_i265 < 3; c6_i265 = c6_i265 + 1) {
      c6_e6[c6_i265] = c6_dv10[c6_i265];
    }

    /*  x-axis */
    _SFD_EML_CALL(0,149);
    for (c6_i266 = 0; c6_i266 < 9; c6_i266 = c6_i266 + 1) {
      c6_s_a[c6_i266] = c6_E1[c6_i266];
    }

    for (c6_i267 = 0; c6_i267 < 9; c6_i267 = c6_i267 + 1) {
      c6_o_b[c6_i267] = c6_E2[c6_i267];
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i268 = 0; c6_i268 < 9; c6_i268 = c6_i268 + 1) {
      c6_ub_A[c6_i268] = c6_s_a[c6_i268];
    }

    for (c6_i269 = 0; c6_i269 < 9; c6_i269 = c6_i269 + 1) {
      c6_rb_B[c6_i269] = c6_o_b[c6_i269];
    }

    for (c6_i270 = 0; c6_i270 < 9; c6_i270 = c6_i270 + 1) {
      c6_vb_A[c6_i270] = c6_ub_A[c6_i270];
    }

    for (c6_i271 = 0; c6_i271 < 9; c6_i271 = c6_i271 + 1) {
      c6_sb_B[c6_i271] = c6_rb_B[c6_i271];
    }

    for (c6_i272 = 0; c6_i272 < 9; c6_i272 = c6_i272 + 1) {
      c6_wb_A[c6_i272] = c6_vb_A[c6_i272];
    }

    for (c6_i273 = 0; c6_i273 < 9; c6_i273 = c6_i273 + 1) {
      c6_tb_B[c6_i273] = c6_sb_B[c6_i273];
    }

    for (c6_i274 = 0; c6_i274 < 3; c6_i274 = c6_i274 + 1) {
      c6_i275 = 0;
      for (c6_i276 = 0; c6_i276 < 3; c6_i276 = c6_i276 + 1) {
        c6_t_a[c6_i275 + c6_i274] = 0.0;
        c6_i277 = 0;
        for (c6_i278 = 0; c6_i278 < 3; c6_i278 = c6_i278 + 1) {
          c6_t_a[c6_i275 + c6_i274] = c6_t_a[c6_i275 + c6_i274] +
            c6_wb_A[c6_i277 + c6_i274] * c6_tb_B[c6_i278 + c6_i275];
          c6_i277 = c6_i277 + 3;
        }

        c6_i275 = c6_i275 + 3;
      }
    }

    for (c6_i279 = 0; c6_i279 < 9; c6_i279 = c6_i279 + 1) {
      c6_p_b[c6_i279] = c6_E3[c6_i279];
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i280 = 0; c6_i280 < 9; c6_i280 = c6_i280 + 1) {
      c6_xb_A[c6_i280] = c6_t_a[c6_i280];
    }

    for (c6_i281 = 0; c6_i281 < 9; c6_i281 = c6_i281 + 1) {
      c6_ub_B[c6_i281] = c6_p_b[c6_i281];
    }

    for (c6_i282 = 0; c6_i282 < 9; c6_i282 = c6_i282 + 1) {
      c6_yb_A[c6_i282] = c6_xb_A[c6_i282];
    }

    for (c6_i283 = 0; c6_i283 < 9; c6_i283 = c6_i283 + 1) {
      c6_vb_B[c6_i283] = c6_ub_B[c6_i283];
    }

    for (c6_i284 = 0; c6_i284 < 9; c6_i284 = c6_i284 + 1) {
      c6_ac_A[c6_i284] = c6_yb_A[c6_i284];
    }

    for (c6_i285 = 0; c6_i285 < 9; c6_i285 = c6_i285 + 1) {
      c6_wb_B[c6_i285] = c6_vb_B[c6_i285];
    }

    for (c6_i286 = 0; c6_i286 < 3; c6_i286 = c6_i286 + 1) {
      c6_i287 = 0;
      for (c6_i288 = 0; c6_i288 < 3; c6_i288 = c6_i288 + 1) {
        c6_u_a[c6_i287 + c6_i286] = 0.0;
        c6_i289 = 0;
        for (c6_i290 = 0; c6_i290 < 3; c6_i290 = c6_i290 + 1) {
          c6_u_a[c6_i287 + c6_i286] = c6_u_a[c6_i287 + c6_i286] +
            c6_ac_A[c6_i289 + c6_i286] * c6_wb_B[c6_i290 + c6_i287];
          c6_i289 = c6_i289 + 3;
        }

        c6_i287 = c6_i287 + 3;
      }
    }

    for (c6_i291 = 0; c6_i291 < 9; c6_i291 = c6_i291 + 1) {
      c6_q_b[c6_i291] = c6_E4[c6_i291];
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i292 = 0; c6_i292 < 9; c6_i292 = c6_i292 + 1) {
      c6_bc_A[c6_i292] = c6_u_a[c6_i292];
    }

    for (c6_i293 = 0; c6_i293 < 9; c6_i293 = c6_i293 + 1) {
      c6_xb_B[c6_i293] = c6_q_b[c6_i293];
    }

    for (c6_i294 = 0; c6_i294 < 9; c6_i294 = c6_i294 + 1) {
      c6_cc_A[c6_i294] = c6_bc_A[c6_i294];
    }

    for (c6_i295 = 0; c6_i295 < 9; c6_i295 = c6_i295 + 1) {
      c6_yb_B[c6_i295] = c6_xb_B[c6_i295];
    }

    for (c6_i296 = 0; c6_i296 < 9; c6_i296 = c6_i296 + 1) {
      c6_dc_A[c6_i296] = c6_cc_A[c6_i296];
    }

    for (c6_i297 = 0; c6_i297 < 9; c6_i297 = c6_i297 + 1) {
      c6_ac_B[c6_i297] = c6_yb_B[c6_i297];
    }

    for (c6_i298 = 0; c6_i298 < 3; c6_i298 = c6_i298 + 1) {
      c6_i299 = 0;
      for (c6_i300 = 0; c6_i300 < 3; c6_i300 = c6_i300 + 1) {
        c6_v_a[c6_i299 + c6_i298] = 0.0;
        c6_i301 = 0;
        for (c6_i302 = 0; c6_i302 < 3; c6_i302 = c6_i302 + 1) {
          c6_v_a[c6_i299 + c6_i298] = c6_v_a[c6_i299 + c6_i298] +
            c6_dc_A[c6_i301 + c6_i298] * c6_ac_B[c6_i302 + c6_i299];
          c6_i301 = c6_i301 + 3;
        }

        c6_i299 = c6_i299 + 3;
      }
    }

    c6_e_eml_scalar_eg();
    c6_e_eml_scalar_eg();
    for (c6_i303 = 0; c6_i303 < 9; c6_i303 = c6_i303 + 1) {
      c6_w_a[c6_i303] = c6_v_a[c6_i303];
    }

    for (c6_i304 = 0; c6_i304 < 3; c6_i304 = c6_i304 + 1) {
      c6_dv12[c6_i304] = c6_dv11[c6_i304];
    }

    for (c6_i305 = 0; c6_i305 < 3; c6_i305 = c6_i305 + 1) {
      c6_dv13[c6_i305] = 0.0;
    }

    c6_eml_xgemm(c6_w_a, c6_dv12, c6_dv13, c6_dv14);
    for (c6_i306 = 0; c6_i306 < 3; c6_i306 = c6_i306 + 1) {
      c6_e5[c6_i306] = c6_dv14[c6_i306];
    }

    /*  y-axis */
    _SFD_EML_CALL(0,150);
    for (c6_i307 = 0; c6_i307 < 9; c6_i307 = c6_i307 + 1) {
      c6_x_a[c6_i307] = c6_E1[c6_i307];
    }

    for (c6_i308 = 0; c6_i308 < 9; c6_i308 = c6_i308 + 1) {
      c6_r_b[c6_i308] = c6_E2[c6_i308];
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i309 = 0; c6_i309 < 9; c6_i309 = c6_i309 + 1) {
      c6_ec_A[c6_i309] = c6_x_a[c6_i309];
    }

    for (c6_i310 = 0; c6_i310 < 9; c6_i310 = c6_i310 + 1) {
      c6_bc_B[c6_i310] = c6_r_b[c6_i310];
    }

    for (c6_i311 = 0; c6_i311 < 9; c6_i311 = c6_i311 + 1) {
      c6_fc_A[c6_i311] = c6_ec_A[c6_i311];
    }

    for (c6_i312 = 0; c6_i312 < 9; c6_i312 = c6_i312 + 1) {
      c6_cc_B[c6_i312] = c6_bc_B[c6_i312];
    }

    for (c6_i313 = 0; c6_i313 < 9; c6_i313 = c6_i313 + 1) {
      c6_gc_A[c6_i313] = c6_fc_A[c6_i313];
    }

    for (c6_i314 = 0; c6_i314 < 9; c6_i314 = c6_i314 + 1) {
      c6_dc_B[c6_i314] = c6_cc_B[c6_i314];
    }

    for (c6_i315 = 0; c6_i315 < 3; c6_i315 = c6_i315 + 1) {
      c6_i316 = 0;
      for (c6_i317 = 0; c6_i317 < 3; c6_i317 = c6_i317 + 1) {
        c6_y_a[c6_i316 + c6_i315] = 0.0;
        c6_i318 = 0;
        for (c6_i319 = 0; c6_i319 < 3; c6_i319 = c6_i319 + 1) {
          c6_y_a[c6_i316 + c6_i315] = c6_y_a[c6_i316 + c6_i315] +
            c6_gc_A[c6_i318 + c6_i315] * c6_dc_B[c6_i319 + c6_i316];
          c6_i318 = c6_i318 + 3;
        }

        c6_i316 = c6_i316 + 3;
      }
    }

    for (c6_i320 = 0; c6_i320 < 9; c6_i320 = c6_i320 + 1) {
      c6_s_b[c6_i320] = c6_E3[c6_i320];
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i321 = 0; c6_i321 < 9; c6_i321 = c6_i321 + 1) {
      c6_hc_A[c6_i321] = c6_y_a[c6_i321];
    }

    for (c6_i322 = 0; c6_i322 < 9; c6_i322 = c6_i322 + 1) {
      c6_ec_B[c6_i322] = c6_s_b[c6_i322];
    }

    for (c6_i323 = 0; c6_i323 < 9; c6_i323 = c6_i323 + 1) {
      c6_ic_A[c6_i323] = c6_hc_A[c6_i323];
    }

    for (c6_i324 = 0; c6_i324 < 9; c6_i324 = c6_i324 + 1) {
      c6_fc_B[c6_i324] = c6_ec_B[c6_i324];
    }

    for (c6_i325 = 0; c6_i325 < 9; c6_i325 = c6_i325 + 1) {
      c6_jc_A[c6_i325] = c6_ic_A[c6_i325];
    }

    for (c6_i326 = 0; c6_i326 < 9; c6_i326 = c6_i326 + 1) {
      c6_gc_B[c6_i326] = c6_fc_B[c6_i326];
    }

    for (c6_i327 = 0; c6_i327 < 3; c6_i327 = c6_i327 + 1) {
      c6_i328 = 0;
      for (c6_i329 = 0; c6_i329 < 3; c6_i329 = c6_i329 + 1) {
        c6_ab_a[c6_i328 + c6_i327] = 0.0;
        c6_i330 = 0;
        for (c6_i331 = 0; c6_i331 < 3; c6_i331 = c6_i331 + 1) {
          c6_ab_a[c6_i328 + c6_i327] = c6_ab_a[c6_i328 + c6_i327] +
            c6_jc_A[c6_i330 + c6_i327] * c6_gc_B[c6_i331 + c6_i328];
          c6_i330 = c6_i330 + 3;
        }

        c6_i328 = c6_i328 + 3;
      }
    }

    c6_e_eml_scalar_eg();
    c6_e_eml_scalar_eg();
    for (c6_i332 = 0; c6_i332 < 9; c6_i332 = c6_i332 + 1) {
      c6_bb_a[c6_i332] = c6_ab_a[c6_i332];
    }

    for (c6_i333 = 0; c6_i333 < 3; c6_i333 = c6_i333 + 1) {
      c6_dv15[c6_i333] = c6_dv7[c6_i333];
    }

    for (c6_i334 = 0; c6_i334 < 3; c6_i334 = c6_i334 + 1) {
      c6_dv16[c6_i334] = 0.0;
    }

    c6_eml_xgemm(c6_bb_a, c6_dv15, c6_dv16, c6_dv17);
    for (c6_i335 = 0; c6_i335 < 3; c6_i335 = c6_i335 + 1) {
      c6_e4[c6_i335] = c6_dv17[c6_i335];
    }

    /*  x-axis */
    _SFD_EML_CALL(0,151);
    for (c6_i336 = 0; c6_i336 < 9; c6_i336 = c6_i336 + 1) {
      c6_cb_a[c6_i336] = c6_E1[c6_i336];
    }

    for (c6_i337 = 0; c6_i337 < 9; c6_i337 = c6_i337 + 1) {
      c6_t_b[c6_i337] = c6_E2[c6_i337];
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i338 = 0; c6_i338 < 9; c6_i338 = c6_i338 + 1) {
      c6_kc_A[c6_i338] = c6_cb_a[c6_i338];
    }

    for (c6_i339 = 0; c6_i339 < 9; c6_i339 = c6_i339 + 1) {
      c6_hc_B[c6_i339] = c6_t_b[c6_i339];
    }

    for (c6_i340 = 0; c6_i340 < 9; c6_i340 = c6_i340 + 1) {
      c6_lc_A[c6_i340] = c6_kc_A[c6_i340];
    }

    for (c6_i341 = 0; c6_i341 < 9; c6_i341 = c6_i341 + 1) {
      c6_ic_B[c6_i341] = c6_hc_B[c6_i341];
    }

    for (c6_i342 = 0; c6_i342 < 9; c6_i342 = c6_i342 + 1) {
      c6_mc_A[c6_i342] = c6_lc_A[c6_i342];
    }

    for (c6_i343 = 0; c6_i343 < 9; c6_i343 = c6_i343 + 1) {
      c6_jc_B[c6_i343] = c6_ic_B[c6_i343];
    }

    for (c6_i344 = 0; c6_i344 < 3; c6_i344 = c6_i344 + 1) {
      c6_i345 = 0;
      for (c6_i346 = 0; c6_i346 < 3; c6_i346 = c6_i346 + 1) {
        c6_db_a[c6_i345 + c6_i344] = 0.0;
        c6_i347 = 0;
        for (c6_i348 = 0; c6_i348 < 3; c6_i348 = c6_i348 + 1) {
          c6_db_a[c6_i345 + c6_i344] = c6_db_a[c6_i345 + c6_i344] +
            c6_mc_A[c6_i347 + c6_i344] * c6_jc_B[c6_i348 + c6_i345];
          c6_i347 = c6_i347 + 3;
        }

        c6_i345 = c6_i345 + 3;
      }
    }

    c6_e_eml_scalar_eg();
    c6_e_eml_scalar_eg();
    for (c6_i349 = 0; c6_i349 < 9; c6_i349 = c6_i349 + 1) {
      c6_eb_a[c6_i349] = c6_db_a[c6_i349];
    }

    for (c6_i350 = 0; c6_i350 < 3; c6_i350 = c6_i350 + 1) {
      c6_dv18[c6_i350] = c6_dv11[c6_i350];
    }

    for (c6_i351 = 0; c6_i351 < 3; c6_i351 = c6_i351 + 1) {
      c6_dv19[c6_i351] = 0.0;
    }

    c6_eml_xgemm(c6_eb_a, c6_dv18, c6_dv19, c6_dv20);
    for (c6_i352 = 0; c6_i352 < 3; c6_i352 = c6_i352 + 1) {
      c6_e3[c6_i352] = c6_dv20[c6_i352];
    }

    /*  y-axis */
    _SFD_EML_CALL(0,152);
    for (c6_i353 = 0; c6_i353 < 9; c6_i353 = c6_i353 + 1) {
      c6_fb_a[c6_i353] = c6_E1[c6_i353];
    }

    c6_e_eml_scalar_eg();
    c6_e_eml_scalar_eg();
    for (c6_i354 = 0; c6_i354 < 9; c6_i354 = c6_i354 + 1) {
      c6_gb_a[c6_i354] = c6_fb_a[c6_i354];
    }

    for (c6_i355 = 0; c6_i355 < 3; c6_i355 = c6_i355 + 1) {
      c6_dv21[c6_i355] = c6_dv11[c6_i355];
    }

    for (c6_i356 = 0; c6_i356 < 3; c6_i356 = c6_i356 + 1) {
      c6_dv22[c6_i356] = 0.0;
    }

    c6_eml_xgemm(c6_gb_a, c6_dv21, c6_dv22, c6_dv23);
    for (c6_i357 = 0; c6_i357 < 3; c6_i357 = c6_i357 + 1) {
      c6_e2[c6_i357] = c6_dv23[c6_i357];
    }

    /*  y-axis */
    _SFD_EML_CALL(0,153);
    for (c6_i358 = 0; c6_i358 < 3; c6_i358 = c6_i358 + 1) {
      c6_e1[c6_i358] = c6_dv24[c6_i358];
    }

    /*  z-axis */
    _SFD_EML_CALL(0,155);
    for (c6_i359 = 0; c6_i359 < 3; c6_i359 = c6_i359 + 1) {
      c6_e[c6_i359] = c6_e1[c6_i359];
    }

    for (c6_i360 = 0; c6_i360 < 3; c6_i360 = c6_i360 + 1) {
      c6_e[c6_i360 + 3] = c6_e2[c6_i360];
    }

    for (c6_i361 = 0; c6_i361 < 3; c6_i361 = c6_i361 + 1) {
      c6_e[c6_i361 + 6] = c6_e3[c6_i361];
    }

    for (c6_i362 = 0; c6_i362 < 3; c6_i362 = c6_i362 + 1) {
      c6_e[c6_i362 + 9] = c6_e4[c6_i362];
    }

    for (c6_i363 = 0; c6_i363 < 3; c6_i363 = c6_i363 + 1) {
      c6_e[c6_i363 + 12] = c6_e5[c6_i363];
    }

    for (c6_i364 = 0; c6_i364 < 3; c6_i364 = c6_i364 + 1) {
      c6_e[c6_i364 + 15] = c6_e6[c6_i364];
    }

    /*  in order to see the changes in phi, theta, psi that this rotation */
    /*  vector causes, we have to transform e->b first in yaw and after that */
    /*  in pitch */
    _SFD_EML_CALL(0,160);
    c6_y_x = c6_eul_ang[2];
    c6_cs_psi = c6_y_x;
    c6_ab_x = c6_cs_psi;
    c6_cs_psi = c6_ab_x;
    c6_cs_psi = muDoubleScalarCos(c6_cs_psi);
    _SFD_EML_CALL(0,161);
    c6_bb_x = c6_eul_ang[2];
    c6_sn_psi = c6_bb_x;
    c6_cb_x = c6_sn_psi;
    c6_sn_psi = c6_cb_x;
    c6_sn_psi = muDoubleScalarSin(c6_sn_psi);
    _SFD_EML_CALL(0,162);
    c6_db_x = c6_eul_ang[1];
    c6_cs_tet = c6_db_x;
    c6_eb_x = c6_cs_tet;
    c6_cs_tet = c6_eb_x;
    c6_cs_tet = muDoubleScalarCos(c6_cs_tet);
    _SFD_EML_CALL(0,163);
    c6_fb_x = c6_eul_ang[1];
    c6_sn_tet = c6_fb_x;
    c6_gb_x = c6_sn_tet;
    c6_sn_tet = c6_gb_x;
    c6_sn_tet = muDoubleScalarSin(c6_sn_tet);
    _SFD_EML_CALL(0,165);
    c6_PSI[0] = c6_cs_psi;
    c6_PSI[3] = c6_sn_psi;
    c6_PSI[6] = 0.0;
    c6_PSI[1] = -c6_sn_psi;
    c6_PSI[4] = c6_cs_psi;
    c6_PSI[7] = 0.0;
    c6_i365 = 0;
    for (c6_i366 = 0; c6_i366 < 3; c6_i366 = c6_i366 + 1) {
      c6_PSI[c6_i365 + 2] = c6_dv24[c6_i366];
      c6_i365 = c6_i365 + 3;
    }

    _SFD_EML_CALL(0,166);
    c6_TET[0] = c6_cs_tet;
    c6_TET[3] = 0.0;
    c6_TET[6] = -c6_sn_tet;
    c6_i367 = 0;
    for (c6_i368 = 0; c6_i368 < 3; c6_i368 = c6_i368 + 1) {
      c6_TET[c6_i367 + 1] = c6_dv11[c6_i368];
      c6_i367 = c6_i367 + 3;
    }

    c6_TET[2] = c6_sn_tet;
    c6_TET[5] = 0.0;
    c6_TET[8] = c6_cs_tet;
    _SFD_EML_CALL(0,167);
    for (c6_i369 = 0; c6_i369 < 9; c6_i369 = c6_i369 + 1) {
      c6_hb_a[c6_i369] = c6_TET[c6_i369];
    }

    for (c6_i370 = 0; c6_i370 < 9; c6_i370 = c6_i370 + 1) {
      c6_u_b[c6_i370] = c6_PSI[c6_i370];
    }

    c6_d_eml_scalar_eg();
    c6_d_eml_scalar_eg();
    for (c6_i371 = 0; c6_i371 < 9; c6_i371 = c6_i371 + 1) {
      c6_nc_A[c6_i371] = c6_hb_a[c6_i371];
    }

    for (c6_i372 = 0; c6_i372 < 9; c6_i372 = c6_i372 + 1) {
      c6_kc_B[c6_i372] = c6_u_b[c6_i372];
    }

    for (c6_i373 = 0; c6_i373 < 9; c6_i373 = c6_i373 + 1) {
      c6_oc_A[c6_i373] = c6_nc_A[c6_i373];
    }

    for (c6_i374 = 0; c6_i374 < 9; c6_i374 = c6_i374 + 1) {
      c6_lc_B[c6_i374] = c6_kc_B[c6_i374];
    }

    for (c6_i375 = 0; c6_i375 < 9; c6_i375 = c6_i375 + 1) {
      c6_pc_A[c6_i375] = c6_oc_A[c6_i375];
    }

    for (c6_i376 = 0; c6_i376 < 9; c6_i376 = c6_i376 + 1) {
      c6_mc_B[c6_i376] = c6_lc_B[c6_i376];
    }

    for (c6_i377 = 0; c6_i377 < 3; c6_i377 = c6_i377 + 1) {
      c6_i378 = 0;
      for (c6_i379 = 0; c6_i379 < 3; c6_i379 = c6_i379 + 1) {
        c6_ib_a[c6_i378 + c6_i377] = 0.0;
        c6_i380 = 0;
        for (c6_i381 = 0; c6_i381 < 3; c6_i381 = c6_i381 + 1) {
          c6_ib_a[c6_i378 + c6_i377] = c6_ib_a[c6_i378 + c6_i377] +
            c6_pc_A[c6_i380 + c6_i377] * c6_mc_B[c6_i381 + c6_i378];
          c6_i380 = c6_i380 + 3;
        }

        c6_i378 = c6_i378 + 3;
      }
    }

    for (c6_i382 = 0; c6_i382 < 18; c6_i382 = c6_i382 + 1) {
      c6_v_b[c6_i382] = c6_e[c6_i382];
    }

    c6_f_eml_scalar_eg();
    c6_f_eml_scalar_eg();
    for (c6_i383 = 0; c6_i383 < 9; c6_i383 = c6_i383 + 1) {
      c6_qc_A[c6_i383] = c6_ib_a[c6_i383];
    }

    for (c6_i384 = 0; c6_i384 < 18; c6_i384 = c6_i384 + 1) {
      c6_nc_B[c6_i384] = c6_v_b[c6_i384];
    }

    for (c6_i385 = 0; c6_i385 < 18; c6_i385 = c6_i385 + 1) {
      c6_e[c6_i385] = 0.0;
    }

    for (c6_i386 = 0; c6_i386 < 9; c6_i386 = c6_i386 + 1) {
      c6_rc_A[c6_i386] = c6_qc_A[c6_i386];
    }

    for (c6_i387 = 0; c6_i387 < 18; c6_i387 = c6_i387 + 1) {
      c6_oc_B[c6_i387] = c6_nc_B[c6_i387];
    }

    for (c6_i388 = 0; c6_i388 < 9; c6_i388 = c6_i388 + 1) {
      c6_sc_A[c6_i388] = c6_rc_A[c6_i388];
    }

    for (c6_i389 = 0; c6_i389 < 18; c6_i389 = c6_i389 + 1) {
      c6_pc_B[c6_i389] = c6_oc_B[c6_i389];
    }

    for (c6_i390 = 0; c6_i390 < 3; c6_i390 = c6_i390 + 1) {
      c6_i391 = 0;
      for (c6_i392 = 0; c6_i392 < 6; c6_i392 = c6_i392 + 1) {
        c6_e[c6_i391 + c6_i390] = 0.0;
        c6_i393 = 0;
        for (c6_i394 = 0; c6_i394 < 3; c6_i394 = c6_i394 + 1) {
          c6_e[c6_i391 + c6_i390] = c6_e[c6_i391 + c6_i390] + c6_sc_A[c6_i393 +
            c6_i390] * c6_pc_B[c6_i394 + c6_i391];
          c6_i393 = c6_i393 + 3;
        }

        c6_i391 = c6_i391 + 3;
      }
    }

    /*  the derivatives of D1-D6 for eah one of the link angles */
    _SFD_EML_CALL(0,172);
    c6_dD1[0] = -c6_SA1;
    c6_dD1[4] = -c6_CA1;
    c6_dD1[8] = 0.0;
    c6_dD1[12] = 0.0;
    c6_dD1[1] = c6_CA1;
    c6_dD1[5] = -c6_SA1;
    c6_dD1[9] = 0.0;
    c6_dD1[13] = 0.0;
    c6_i395 = 0;
    for (c6_i396 = 0; c6_i396 < 4; c6_i396 = c6_i396 + 1) {
      c6_dD1[c6_i395 + 2] = 0.0;
      c6_i395 = c6_i395 + 4;
    }

    c6_i397 = 0;
    for (c6_i398 = 0; c6_i398 < 4; c6_i398 = c6_i398 + 1) {
      c6_dD1[c6_i397 + 3] = 0.0;
      c6_i397 = c6_i397 + 4;
    }

    _SFD_EML_CALL(0,173);
    c6_dD2[0] = -c6_SA2;
    c6_dD2[4] = 0.0;
    c6_dD2[8] = c6_CA2;
    c6_dD2[12] = 0.0;
    c6_i399 = 0;
    for (c6_i400 = 0; c6_i400 < 4; c6_i400 = c6_i400 + 1) {
      c6_dD2[c6_i399 + 1] = 0.0;
      c6_i399 = c6_i399 + 4;
    }

    c6_dD2[2] = -c6_CA2;
    c6_dD2[6] = 0.0;
    c6_dD2[10] = -c6_SA2;
    c6_dD2[14] = 0.0;
    c6_i401 = 0;
    for (c6_i402 = 0; c6_i402 < 4; c6_i402 = c6_i402 + 1) {
      c6_dD2[c6_i401 + 3] = 0.0;
      c6_i401 = c6_i401 + 4;
    }

    _SFD_EML_CALL(0,174);
    c6_dD3[0] = -c6_SA3;
    c6_dD3[4] = 0.0;
    c6_dD3[8] = c6_CA3;
    c6_dD3[12] = 0.0;
    c6_i403 = 0;
    for (c6_i404 = 0; c6_i404 < 4; c6_i404 = c6_i404 + 1) {
      c6_dD3[c6_i403 + 1] = 0.0;
      c6_i403 = c6_i403 + 4;
    }

    c6_dD3[2] = -c6_CA3;
    c6_dD3[6] = 0.0;
    c6_dD3[10] = -c6_SA3;
    c6_dD3[14] = 0.0;
    c6_i405 = 0;
    for (c6_i406 = 0; c6_i406 < 4; c6_i406 = c6_i406 + 1) {
      c6_dD3[c6_i405 + 3] = 0.0;
      c6_i405 = c6_i405 + 4;
    }

    _SFD_EML_CALL(0,175);
    c6_i407 = 0;
    for (c6_i408 = 0; c6_i408 < 4; c6_i408 = c6_i408 + 1) {
      c6_dD4[c6_i407] = 0.0;
      c6_i407 = c6_i407 + 4;
    }

    c6_dD4[1] = 0.0;
    c6_dD4[5] = -c6_SA4;
    c6_dD4[9] = -c6_CA4;
    c6_dD4[13] = 0.0;
    c6_dD4[2] = 0.0;
    c6_dD4[6] = c6_CA4;
    c6_dD4[10] = -c6_SA4;
    c6_dD4[14] = 0.0;
    c6_i409 = 0;
    for (c6_i410 = 0; c6_i410 < 4; c6_i410 = c6_i410 + 1) {
      c6_dD4[c6_i409 + 3] = 0.0;
      c6_i409 = c6_i409 + 4;
    }

    _SFD_EML_CALL(0,176);
    c6_dD5[0] = -c6_SA5;
    c6_dD5[4] = 0.0;
    c6_dD5[8] = c6_CA5;
    c6_dD5[12] = 0.0;
    c6_i411 = 0;
    for (c6_i412 = 0; c6_i412 < 4; c6_i412 = c6_i412 + 1) {
      c6_dD5[c6_i411 + 1] = 0.0;
      c6_i411 = c6_i411 + 4;
    }

    c6_dD5[2] = -c6_CA5;
    c6_dD5[6] = 0.0;
    c6_dD5[10] = -c6_SA5;
    c6_dD5[14] = 0.0;
    c6_i413 = 0;
    for (c6_i414 = 0; c6_i414 < 4; c6_i414 = c6_i414 + 1) {
      c6_dD5[c6_i413 + 3] = 0.0;
      c6_i413 = c6_i413 + 4;
    }

    _SFD_EML_CALL(0,177);
    c6_i415 = 0;
    for (c6_i416 = 0; c6_i416 < 4; c6_i416 = c6_i416 + 1) {
      c6_dD6[c6_i415] = 0.0;
      c6_i415 = c6_i415 + 4;
    }

    c6_dD6[1] = 0.0;
    c6_dD6[5] = -c6_SA6;
    c6_dD6[9] = -c6_CA6;
    c6_dD6[13] = 0.0;
    c6_dD6[2] = 0.0;
    c6_dD6[6] = c6_CA6;
    c6_dD6[10] = -c6_SA6;
    c6_dD6[14] = 0.0;
    c6_i417 = 0;
    for (c6_i418 = 0; c6_i418 < 4; c6_i418 = c6_i418 + 1) {
      c6_dD6[c6_i417 + 3] = 0.0;
      c6_i417 = c6_i417 + 4;
    }

    /*  Hessian Matrix H; the inverse of this matrix determines the link */
    /*  angle speed as a function of the speed of x,y,z and the speed of the */
    /*  Euler angles */
    _SFD_EML_CALL(0,183);
    for (c6_i419 = 0; c6_i419 < 16; c6_i419 = c6_i419 + 1) {
      c6_jb_a[c6_i419] = c6_dD1[c6_i419];
    }

    for (c6_i420 = 0; c6_i420 < 16; c6_i420 = c6_i420 + 1) {
      c6_w_b[c6_i420] = c6_D2[c6_i420];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i421 = 0; c6_i421 < 16; c6_i421 = c6_i421 + 1) {
      c6_tc_A[c6_i421] = c6_jb_a[c6_i421];
    }

    for (c6_i422 = 0; c6_i422 < 16; c6_i422 = c6_i422 + 1) {
      c6_qc_B[c6_i422] = c6_w_b[c6_i422];
    }

    for (c6_i423 = 0; c6_i423 < 16; c6_i423 = c6_i423 + 1) {
      c6_uc_A[c6_i423] = c6_tc_A[c6_i423];
    }

    for (c6_i424 = 0; c6_i424 < 16; c6_i424 = c6_i424 + 1) {
      c6_rc_B[c6_i424] = c6_qc_B[c6_i424];
    }

    for (c6_i425 = 0; c6_i425 < 16; c6_i425 = c6_i425 + 1) {
      c6_vc_A[c6_i425] = c6_uc_A[c6_i425];
    }

    for (c6_i426 = 0; c6_i426 < 16; c6_i426 = c6_i426 + 1) {
      c6_sc_B[c6_i426] = c6_rc_B[c6_i426];
    }

    for (c6_i427 = 0; c6_i427 < 4; c6_i427 = c6_i427 + 1) {
      c6_i428 = 0;
      for (c6_i429 = 0; c6_i429 < 4; c6_i429 = c6_i429 + 1) {
        c6_kb_a[c6_i428 + c6_i427] = 0.0;
        c6_i430 = 0;
        for (c6_i431 = 0; c6_i431 < 4; c6_i431 = c6_i431 + 1) {
          c6_kb_a[c6_i428 + c6_i427] = c6_kb_a[c6_i428 + c6_i427] +
            c6_vc_A[c6_i430 + c6_i427] * c6_sc_B[c6_i431 + c6_i428];
          c6_i430 = c6_i430 + 4;
        }

        c6_i428 = c6_i428 + 4;
      }
    }

    for (c6_i432 = 0; c6_i432 < 16; c6_i432 = c6_i432 + 1) {
      c6_x_b[c6_i432] = c6_D3[c6_i432];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i433 = 0; c6_i433 < 16; c6_i433 = c6_i433 + 1) {
      c6_wc_A[c6_i433] = c6_kb_a[c6_i433];
    }

    for (c6_i434 = 0; c6_i434 < 16; c6_i434 = c6_i434 + 1) {
      c6_tc_B[c6_i434] = c6_x_b[c6_i434];
    }

    for (c6_i435 = 0; c6_i435 < 16; c6_i435 = c6_i435 + 1) {
      c6_xc_A[c6_i435] = c6_wc_A[c6_i435];
    }

    for (c6_i436 = 0; c6_i436 < 16; c6_i436 = c6_i436 + 1) {
      c6_uc_B[c6_i436] = c6_tc_B[c6_i436];
    }

    for (c6_i437 = 0; c6_i437 < 16; c6_i437 = c6_i437 + 1) {
      c6_yc_A[c6_i437] = c6_xc_A[c6_i437];
    }

    for (c6_i438 = 0; c6_i438 < 16; c6_i438 = c6_i438 + 1) {
      c6_vc_B[c6_i438] = c6_uc_B[c6_i438];
    }

    for (c6_i439 = 0; c6_i439 < 4; c6_i439 = c6_i439 + 1) {
      c6_i440 = 0;
      for (c6_i441 = 0; c6_i441 < 4; c6_i441 = c6_i441 + 1) {
        c6_lb_a[c6_i440 + c6_i439] = 0.0;
        c6_i442 = 0;
        for (c6_i443 = 0; c6_i443 < 4; c6_i443 = c6_i443 + 1) {
          c6_lb_a[c6_i440 + c6_i439] = c6_lb_a[c6_i440 + c6_i439] +
            c6_yc_A[c6_i442 + c6_i439] * c6_vc_B[c6_i443 + c6_i440];
          c6_i442 = c6_i442 + 4;
        }

        c6_i440 = c6_i440 + 4;
      }
    }

    for (c6_i444 = 0; c6_i444 < 16; c6_i444 = c6_i444 + 1) {
      c6_y_b[c6_i444] = c6_D4[c6_i444];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i445 = 0; c6_i445 < 16; c6_i445 = c6_i445 + 1) {
      c6_ad_A[c6_i445] = c6_lb_a[c6_i445];
    }

    for (c6_i446 = 0; c6_i446 < 16; c6_i446 = c6_i446 + 1) {
      c6_wc_B[c6_i446] = c6_y_b[c6_i446];
    }

    for (c6_i447 = 0; c6_i447 < 16; c6_i447 = c6_i447 + 1) {
      c6_bd_A[c6_i447] = c6_ad_A[c6_i447];
    }

    for (c6_i448 = 0; c6_i448 < 16; c6_i448 = c6_i448 + 1) {
      c6_xc_B[c6_i448] = c6_wc_B[c6_i448];
    }

    for (c6_i449 = 0; c6_i449 < 16; c6_i449 = c6_i449 + 1) {
      c6_cd_A[c6_i449] = c6_bd_A[c6_i449];
    }

    for (c6_i450 = 0; c6_i450 < 16; c6_i450 = c6_i450 + 1) {
      c6_yc_B[c6_i450] = c6_xc_B[c6_i450];
    }

    for (c6_i451 = 0; c6_i451 < 4; c6_i451 = c6_i451 + 1) {
      c6_i452 = 0;
      for (c6_i453 = 0; c6_i453 < 4; c6_i453 = c6_i453 + 1) {
        c6_mb_a[c6_i452 + c6_i451] = 0.0;
        c6_i454 = 0;
        for (c6_i455 = 0; c6_i455 < 4; c6_i455 = c6_i455 + 1) {
          c6_mb_a[c6_i452 + c6_i451] = c6_mb_a[c6_i452 + c6_i451] +
            c6_cd_A[c6_i454 + c6_i451] * c6_yc_B[c6_i455 + c6_i452];
          c6_i454 = c6_i454 + 4;
        }

        c6_i452 = c6_i452 + 4;
      }
    }

    for (c6_i456 = 0; c6_i456 < 16; c6_i456 = c6_i456 + 1) {
      c6_ab_b[c6_i456] = c6_D5[c6_i456];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i457 = 0; c6_i457 < 16; c6_i457 = c6_i457 + 1) {
      c6_dd_A[c6_i457] = c6_mb_a[c6_i457];
    }

    for (c6_i458 = 0; c6_i458 < 16; c6_i458 = c6_i458 + 1) {
      c6_ad_B[c6_i458] = c6_ab_b[c6_i458];
    }

    for (c6_i459 = 0; c6_i459 < 16; c6_i459 = c6_i459 + 1) {
      c6_ed_A[c6_i459] = c6_dd_A[c6_i459];
    }

    for (c6_i460 = 0; c6_i460 < 16; c6_i460 = c6_i460 + 1) {
      c6_bd_B[c6_i460] = c6_ad_B[c6_i460];
    }

    for (c6_i461 = 0; c6_i461 < 16; c6_i461 = c6_i461 + 1) {
      c6_fd_A[c6_i461] = c6_ed_A[c6_i461];
    }

    for (c6_i462 = 0; c6_i462 < 16; c6_i462 = c6_i462 + 1) {
      c6_cd_B[c6_i462] = c6_bd_B[c6_i462];
    }

    for (c6_i463 = 0; c6_i463 < 4; c6_i463 = c6_i463 + 1) {
      c6_i464 = 0;
      for (c6_i465 = 0; c6_i465 < 4; c6_i465 = c6_i465 + 1) {
        c6_nb_a[c6_i464 + c6_i463] = 0.0;
        c6_i466 = 0;
        for (c6_i467 = 0; c6_i467 < 4; c6_i467 = c6_i467 + 1) {
          c6_nb_a[c6_i464 + c6_i463] = c6_nb_a[c6_i464 + c6_i463] +
            c6_fd_A[c6_i466 + c6_i463] * c6_cd_B[c6_i467 + c6_i464];
          c6_i466 = c6_i466 + 4;
        }

        c6_i464 = c6_i464 + 4;
      }
    }

    for (c6_i468 = 0; c6_i468 < 16; c6_i468 = c6_i468 + 1) {
      c6_bb_b[c6_i468] = c6_D6[c6_i468];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i469 = 0; c6_i469 < 16; c6_i469 = c6_i469 + 1) {
      c6_gd_A[c6_i469] = c6_nb_a[c6_i469];
    }

    for (c6_i470 = 0; c6_i470 < 16; c6_i470 = c6_i470 + 1) {
      c6_dd_B[c6_i470] = c6_bb_b[c6_i470];
    }

    for (c6_i471 = 0; c6_i471 < 16; c6_i471 = c6_i471 + 1) {
      c6_hd_A[c6_i471] = c6_gd_A[c6_i471];
    }

    for (c6_i472 = 0; c6_i472 < 16; c6_i472 = c6_i472 + 1) {
      c6_ed_B[c6_i472] = c6_dd_B[c6_i472];
    }

    for (c6_i473 = 0; c6_i473 < 16; c6_i473 = c6_i473 + 1) {
      c6_id_A[c6_i473] = c6_hd_A[c6_i473];
    }

    for (c6_i474 = 0; c6_i474 < 16; c6_i474 = c6_i474 + 1) {
      c6_fd_B[c6_i474] = c6_ed_B[c6_i474];
    }

    for (c6_i475 = 0; c6_i475 < 4; c6_i475 = c6_i475 + 1) {
      c6_i476 = 0;
      for (c6_i477 = 0; c6_i477 < 4; c6_i477 = c6_i477 + 1) {
        c6_ob_a[c6_i476 + c6_i475] = 0.0;
        c6_i478 = 0;
        for (c6_i479 = 0; c6_i479 < 4; c6_i479 = c6_i479 + 1) {
          c6_ob_a[c6_i476 + c6_i475] = c6_ob_a[c6_i476 + c6_i475] +
            c6_id_A[c6_i478 + c6_i475] * c6_fd_B[c6_i479 + c6_i476];
          c6_i478 = c6_i478 + 4;
        }

        c6_i476 = c6_i476 + 4;
      }
    }

    c6_c_eml_scalar_eg();
    c6_c_eml_scalar_eg();
    for (c6_i480 = 0; c6_i480 < 16; c6_i480 = c6_i480 + 1) {
      c6_jd_A[c6_i480] = c6_ob_a[c6_i480];
    }

    for (c6_i481 = 0; c6_i481 < 4; c6_i481 = c6_i481 + 1) {
      c6_h1[c6_i481] = 0.0;
    }

    for (c6_i482 = 0; c6_i482 < 16; c6_i482 = c6_i482 + 1) {
      c6_kd_A[c6_i482] = c6_jd_A[c6_i482];
    }

    for (c6_i483 = 0; c6_i483 < 16; c6_i483 = c6_i483 + 1) {
      c6_ld_A[c6_i483] = c6_kd_A[c6_i483];
    }

    for (c6_i484 = 0; c6_i484 < 4; c6_i484 = c6_i484 + 1) {
      c6_h1[c6_i484] = 0.0;
      c6_i485 = 0;
      for (c6_i486 = 0; c6_i486 < 4; c6_i486 = c6_i486 + 1) {
        c6_h1[c6_i484] = c6_h1[c6_i484] + c6_ld_A[c6_i485 + c6_i484] *
          c6_dv4[c6_i486];
        c6_i485 = c6_i485 + 4;
      }
    }

    _SFD_EML_CALL(0,184);
    for (c6_i487 = 0; c6_i487 < 16; c6_i487 = c6_i487 + 1) {
      c6_pb_a[c6_i487] = c6_D1[c6_i487];
    }

    for (c6_i488 = 0; c6_i488 < 16; c6_i488 = c6_i488 + 1) {
      c6_cb_b[c6_i488] = c6_dD2[c6_i488];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i489 = 0; c6_i489 < 16; c6_i489 = c6_i489 + 1) {
      c6_md_A[c6_i489] = c6_pb_a[c6_i489];
    }

    for (c6_i490 = 0; c6_i490 < 16; c6_i490 = c6_i490 + 1) {
      c6_gd_B[c6_i490] = c6_cb_b[c6_i490];
    }

    for (c6_i491 = 0; c6_i491 < 16; c6_i491 = c6_i491 + 1) {
      c6_nd_A[c6_i491] = c6_md_A[c6_i491];
    }

    for (c6_i492 = 0; c6_i492 < 16; c6_i492 = c6_i492 + 1) {
      c6_hd_B[c6_i492] = c6_gd_B[c6_i492];
    }

    for (c6_i493 = 0; c6_i493 < 16; c6_i493 = c6_i493 + 1) {
      c6_od_A[c6_i493] = c6_nd_A[c6_i493];
    }

    for (c6_i494 = 0; c6_i494 < 16; c6_i494 = c6_i494 + 1) {
      c6_id_B[c6_i494] = c6_hd_B[c6_i494];
    }

    for (c6_i495 = 0; c6_i495 < 4; c6_i495 = c6_i495 + 1) {
      c6_i496 = 0;
      for (c6_i497 = 0; c6_i497 < 4; c6_i497 = c6_i497 + 1) {
        c6_qb_a[c6_i496 + c6_i495] = 0.0;
        c6_i498 = 0;
        for (c6_i499 = 0; c6_i499 < 4; c6_i499 = c6_i499 + 1) {
          c6_qb_a[c6_i496 + c6_i495] = c6_qb_a[c6_i496 + c6_i495] +
            c6_od_A[c6_i498 + c6_i495] * c6_id_B[c6_i499 + c6_i496];
          c6_i498 = c6_i498 + 4;
        }

        c6_i496 = c6_i496 + 4;
      }
    }

    for (c6_i500 = 0; c6_i500 < 16; c6_i500 = c6_i500 + 1) {
      c6_db_b[c6_i500] = c6_D3[c6_i500];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i501 = 0; c6_i501 < 16; c6_i501 = c6_i501 + 1) {
      c6_pd_A[c6_i501] = c6_qb_a[c6_i501];
    }

    for (c6_i502 = 0; c6_i502 < 16; c6_i502 = c6_i502 + 1) {
      c6_jd_B[c6_i502] = c6_db_b[c6_i502];
    }

    for (c6_i503 = 0; c6_i503 < 16; c6_i503 = c6_i503 + 1) {
      c6_qd_A[c6_i503] = c6_pd_A[c6_i503];
    }

    for (c6_i504 = 0; c6_i504 < 16; c6_i504 = c6_i504 + 1) {
      c6_kd_B[c6_i504] = c6_jd_B[c6_i504];
    }

    for (c6_i505 = 0; c6_i505 < 16; c6_i505 = c6_i505 + 1) {
      c6_rd_A[c6_i505] = c6_qd_A[c6_i505];
    }

    for (c6_i506 = 0; c6_i506 < 16; c6_i506 = c6_i506 + 1) {
      c6_ld_B[c6_i506] = c6_kd_B[c6_i506];
    }

    for (c6_i507 = 0; c6_i507 < 4; c6_i507 = c6_i507 + 1) {
      c6_i508 = 0;
      for (c6_i509 = 0; c6_i509 < 4; c6_i509 = c6_i509 + 1) {
        c6_rb_a[c6_i508 + c6_i507] = 0.0;
        c6_i510 = 0;
        for (c6_i511 = 0; c6_i511 < 4; c6_i511 = c6_i511 + 1) {
          c6_rb_a[c6_i508 + c6_i507] = c6_rb_a[c6_i508 + c6_i507] +
            c6_rd_A[c6_i510 + c6_i507] * c6_ld_B[c6_i511 + c6_i508];
          c6_i510 = c6_i510 + 4;
        }

        c6_i508 = c6_i508 + 4;
      }
    }

    for (c6_i512 = 0; c6_i512 < 16; c6_i512 = c6_i512 + 1) {
      c6_eb_b[c6_i512] = c6_D4[c6_i512];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i513 = 0; c6_i513 < 16; c6_i513 = c6_i513 + 1) {
      c6_sd_A[c6_i513] = c6_rb_a[c6_i513];
    }

    for (c6_i514 = 0; c6_i514 < 16; c6_i514 = c6_i514 + 1) {
      c6_md_B[c6_i514] = c6_eb_b[c6_i514];
    }

    for (c6_i515 = 0; c6_i515 < 16; c6_i515 = c6_i515 + 1) {
      c6_td_A[c6_i515] = c6_sd_A[c6_i515];
    }

    for (c6_i516 = 0; c6_i516 < 16; c6_i516 = c6_i516 + 1) {
      c6_nd_B[c6_i516] = c6_md_B[c6_i516];
    }

    for (c6_i517 = 0; c6_i517 < 16; c6_i517 = c6_i517 + 1) {
      c6_ud_A[c6_i517] = c6_td_A[c6_i517];
    }

    for (c6_i518 = 0; c6_i518 < 16; c6_i518 = c6_i518 + 1) {
      c6_od_B[c6_i518] = c6_nd_B[c6_i518];
    }

    for (c6_i519 = 0; c6_i519 < 4; c6_i519 = c6_i519 + 1) {
      c6_i520 = 0;
      for (c6_i521 = 0; c6_i521 < 4; c6_i521 = c6_i521 + 1) {
        c6_sb_a[c6_i520 + c6_i519] = 0.0;
        c6_i522 = 0;
        for (c6_i523 = 0; c6_i523 < 4; c6_i523 = c6_i523 + 1) {
          c6_sb_a[c6_i520 + c6_i519] = c6_sb_a[c6_i520 + c6_i519] +
            c6_ud_A[c6_i522 + c6_i519] * c6_od_B[c6_i523 + c6_i520];
          c6_i522 = c6_i522 + 4;
        }

        c6_i520 = c6_i520 + 4;
      }
    }

    for (c6_i524 = 0; c6_i524 < 16; c6_i524 = c6_i524 + 1) {
      c6_fb_b[c6_i524] = c6_D5[c6_i524];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i525 = 0; c6_i525 < 16; c6_i525 = c6_i525 + 1) {
      c6_vd_A[c6_i525] = c6_sb_a[c6_i525];
    }

    for (c6_i526 = 0; c6_i526 < 16; c6_i526 = c6_i526 + 1) {
      c6_pd_B[c6_i526] = c6_fb_b[c6_i526];
    }

    for (c6_i527 = 0; c6_i527 < 16; c6_i527 = c6_i527 + 1) {
      c6_wd_A[c6_i527] = c6_vd_A[c6_i527];
    }

    for (c6_i528 = 0; c6_i528 < 16; c6_i528 = c6_i528 + 1) {
      c6_qd_B[c6_i528] = c6_pd_B[c6_i528];
    }

    for (c6_i529 = 0; c6_i529 < 16; c6_i529 = c6_i529 + 1) {
      c6_xd_A[c6_i529] = c6_wd_A[c6_i529];
    }

    for (c6_i530 = 0; c6_i530 < 16; c6_i530 = c6_i530 + 1) {
      c6_rd_B[c6_i530] = c6_qd_B[c6_i530];
    }

    for (c6_i531 = 0; c6_i531 < 4; c6_i531 = c6_i531 + 1) {
      c6_i532 = 0;
      for (c6_i533 = 0; c6_i533 < 4; c6_i533 = c6_i533 + 1) {
        c6_tb_a[c6_i532 + c6_i531] = 0.0;
        c6_i534 = 0;
        for (c6_i535 = 0; c6_i535 < 4; c6_i535 = c6_i535 + 1) {
          c6_tb_a[c6_i532 + c6_i531] = c6_tb_a[c6_i532 + c6_i531] +
            c6_xd_A[c6_i534 + c6_i531] * c6_rd_B[c6_i535 + c6_i532];
          c6_i534 = c6_i534 + 4;
        }

        c6_i532 = c6_i532 + 4;
      }
    }

    for (c6_i536 = 0; c6_i536 < 16; c6_i536 = c6_i536 + 1) {
      c6_gb_b[c6_i536] = c6_D6[c6_i536];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i537 = 0; c6_i537 < 16; c6_i537 = c6_i537 + 1) {
      c6_yd_A[c6_i537] = c6_tb_a[c6_i537];
    }

    for (c6_i538 = 0; c6_i538 < 16; c6_i538 = c6_i538 + 1) {
      c6_sd_B[c6_i538] = c6_gb_b[c6_i538];
    }

    for (c6_i539 = 0; c6_i539 < 16; c6_i539 = c6_i539 + 1) {
      c6_ae_A[c6_i539] = c6_yd_A[c6_i539];
    }

    for (c6_i540 = 0; c6_i540 < 16; c6_i540 = c6_i540 + 1) {
      c6_td_B[c6_i540] = c6_sd_B[c6_i540];
    }

    for (c6_i541 = 0; c6_i541 < 16; c6_i541 = c6_i541 + 1) {
      c6_be_A[c6_i541] = c6_ae_A[c6_i541];
    }

    for (c6_i542 = 0; c6_i542 < 16; c6_i542 = c6_i542 + 1) {
      c6_ud_B[c6_i542] = c6_td_B[c6_i542];
    }

    for (c6_i543 = 0; c6_i543 < 4; c6_i543 = c6_i543 + 1) {
      c6_i544 = 0;
      for (c6_i545 = 0; c6_i545 < 4; c6_i545 = c6_i545 + 1) {
        c6_ub_a[c6_i544 + c6_i543] = 0.0;
        c6_i546 = 0;
        for (c6_i547 = 0; c6_i547 < 4; c6_i547 = c6_i547 + 1) {
          c6_ub_a[c6_i544 + c6_i543] = c6_ub_a[c6_i544 + c6_i543] +
            c6_be_A[c6_i546 + c6_i543] * c6_ud_B[c6_i547 + c6_i544];
          c6_i546 = c6_i546 + 4;
        }

        c6_i544 = c6_i544 + 4;
      }
    }

    c6_c_eml_scalar_eg();
    c6_c_eml_scalar_eg();
    for (c6_i548 = 0; c6_i548 < 16; c6_i548 = c6_i548 + 1) {
      c6_ce_A[c6_i548] = c6_ub_a[c6_i548];
    }

    for (c6_i549 = 0; c6_i549 < 4; c6_i549 = c6_i549 + 1) {
      c6_h2[c6_i549] = 0.0;
    }

    for (c6_i550 = 0; c6_i550 < 16; c6_i550 = c6_i550 + 1) {
      c6_de_A[c6_i550] = c6_ce_A[c6_i550];
    }

    for (c6_i551 = 0; c6_i551 < 16; c6_i551 = c6_i551 + 1) {
      c6_ee_A[c6_i551] = c6_de_A[c6_i551];
    }

    for (c6_i552 = 0; c6_i552 < 4; c6_i552 = c6_i552 + 1) {
      c6_h2[c6_i552] = 0.0;
      c6_i553 = 0;
      for (c6_i554 = 0; c6_i554 < 4; c6_i554 = c6_i554 + 1) {
        c6_h2[c6_i552] = c6_h2[c6_i552] + c6_ee_A[c6_i553 + c6_i552] *
          c6_dv4[c6_i554];
        c6_i553 = c6_i553 + 4;
      }
    }

    _SFD_EML_CALL(0,185);
    for (c6_i555 = 0; c6_i555 < 16; c6_i555 = c6_i555 + 1) {
      c6_vb_a[c6_i555] = c6_D1[c6_i555];
    }

    for (c6_i556 = 0; c6_i556 < 16; c6_i556 = c6_i556 + 1) {
      c6_hb_b[c6_i556] = c6_D2[c6_i556];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i557 = 0; c6_i557 < 16; c6_i557 = c6_i557 + 1) {
      c6_fe_A[c6_i557] = c6_vb_a[c6_i557];
    }

    for (c6_i558 = 0; c6_i558 < 16; c6_i558 = c6_i558 + 1) {
      c6_vd_B[c6_i558] = c6_hb_b[c6_i558];
    }

    for (c6_i559 = 0; c6_i559 < 16; c6_i559 = c6_i559 + 1) {
      c6_ge_A[c6_i559] = c6_fe_A[c6_i559];
    }

    for (c6_i560 = 0; c6_i560 < 16; c6_i560 = c6_i560 + 1) {
      c6_wd_B[c6_i560] = c6_vd_B[c6_i560];
    }

    for (c6_i561 = 0; c6_i561 < 16; c6_i561 = c6_i561 + 1) {
      c6_he_A[c6_i561] = c6_ge_A[c6_i561];
    }

    for (c6_i562 = 0; c6_i562 < 16; c6_i562 = c6_i562 + 1) {
      c6_xd_B[c6_i562] = c6_wd_B[c6_i562];
    }

    for (c6_i563 = 0; c6_i563 < 4; c6_i563 = c6_i563 + 1) {
      c6_i564 = 0;
      for (c6_i565 = 0; c6_i565 < 4; c6_i565 = c6_i565 + 1) {
        c6_wb_a[c6_i564 + c6_i563] = 0.0;
        c6_i566 = 0;
        for (c6_i567 = 0; c6_i567 < 4; c6_i567 = c6_i567 + 1) {
          c6_wb_a[c6_i564 + c6_i563] = c6_wb_a[c6_i564 + c6_i563] +
            c6_he_A[c6_i566 + c6_i563] * c6_xd_B[c6_i567 + c6_i564];
          c6_i566 = c6_i566 + 4;
        }

        c6_i564 = c6_i564 + 4;
      }
    }

    for (c6_i568 = 0; c6_i568 < 16; c6_i568 = c6_i568 + 1) {
      c6_ib_b[c6_i568] = c6_dD3[c6_i568];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i569 = 0; c6_i569 < 16; c6_i569 = c6_i569 + 1) {
      c6_ie_A[c6_i569] = c6_wb_a[c6_i569];
    }

    for (c6_i570 = 0; c6_i570 < 16; c6_i570 = c6_i570 + 1) {
      c6_yd_B[c6_i570] = c6_ib_b[c6_i570];
    }

    for (c6_i571 = 0; c6_i571 < 16; c6_i571 = c6_i571 + 1) {
      c6_je_A[c6_i571] = c6_ie_A[c6_i571];
    }

    for (c6_i572 = 0; c6_i572 < 16; c6_i572 = c6_i572 + 1) {
      c6_ae_B[c6_i572] = c6_yd_B[c6_i572];
    }

    for (c6_i573 = 0; c6_i573 < 16; c6_i573 = c6_i573 + 1) {
      c6_ke_A[c6_i573] = c6_je_A[c6_i573];
    }

    for (c6_i574 = 0; c6_i574 < 16; c6_i574 = c6_i574 + 1) {
      c6_be_B[c6_i574] = c6_ae_B[c6_i574];
    }

    for (c6_i575 = 0; c6_i575 < 4; c6_i575 = c6_i575 + 1) {
      c6_i576 = 0;
      for (c6_i577 = 0; c6_i577 < 4; c6_i577 = c6_i577 + 1) {
        c6_xb_a[c6_i576 + c6_i575] = 0.0;
        c6_i578 = 0;
        for (c6_i579 = 0; c6_i579 < 4; c6_i579 = c6_i579 + 1) {
          c6_xb_a[c6_i576 + c6_i575] = c6_xb_a[c6_i576 + c6_i575] +
            c6_ke_A[c6_i578 + c6_i575] * c6_be_B[c6_i579 + c6_i576];
          c6_i578 = c6_i578 + 4;
        }

        c6_i576 = c6_i576 + 4;
      }
    }

    for (c6_i580 = 0; c6_i580 < 16; c6_i580 = c6_i580 + 1) {
      c6_jb_b[c6_i580] = c6_D4[c6_i580];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i581 = 0; c6_i581 < 16; c6_i581 = c6_i581 + 1) {
      c6_le_A[c6_i581] = c6_xb_a[c6_i581];
    }

    for (c6_i582 = 0; c6_i582 < 16; c6_i582 = c6_i582 + 1) {
      c6_ce_B[c6_i582] = c6_jb_b[c6_i582];
    }

    for (c6_i583 = 0; c6_i583 < 16; c6_i583 = c6_i583 + 1) {
      c6_me_A[c6_i583] = c6_le_A[c6_i583];
    }

    for (c6_i584 = 0; c6_i584 < 16; c6_i584 = c6_i584 + 1) {
      c6_de_B[c6_i584] = c6_ce_B[c6_i584];
    }

    for (c6_i585 = 0; c6_i585 < 16; c6_i585 = c6_i585 + 1) {
      c6_ne_A[c6_i585] = c6_me_A[c6_i585];
    }

    for (c6_i586 = 0; c6_i586 < 16; c6_i586 = c6_i586 + 1) {
      c6_ee_B[c6_i586] = c6_de_B[c6_i586];
    }

    for (c6_i587 = 0; c6_i587 < 4; c6_i587 = c6_i587 + 1) {
      c6_i588 = 0;
      for (c6_i589 = 0; c6_i589 < 4; c6_i589 = c6_i589 + 1) {
        c6_yb_a[c6_i588 + c6_i587] = 0.0;
        c6_i590 = 0;
        for (c6_i591 = 0; c6_i591 < 4; c6_i591 = c6_i591 + 1) {
          c6_yb_a[c6_i588 + c6_i587] = c6_yb_a[c6_i588 + c6_i587] +
            c6_ne_A[c6_i590 + c6_i587] * c6_ee_B[c6_i591 + c6_i588];
          c6_i590 = c6_i590 + 4;
        }

        c6_i588 = c6_i588 + 4;
      }
    }

    for (c6_i592 = 0; c6_i592 < 16; c6_i592 = c6_i592 + 1) {
      c6_kb_b[c6_i592] = c6_D5[c6_i592];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i593 = 0; c6_i593 < 16; c6_i593 = c6_i593 + 1) {
      c6_oe_A[c6_i593] = c6_yb_a[c6_i593];
    }

    for (c6_i594 = 0; c6_i594 < 16; c6_i594 = c6_i594 + 1) {
      c6_fe_B[c6_i594] = c6_kb_b[c6_i594];
    }

    for (c6_i595 = 0; c6_i595 < 16; c6_i595 = c6_i595 + 1) {
      c6_pe_A[c6_i595] = c6_oe_A[c6_i595];
    }

    for (c6_i596 = 0; c6_i596 < 16; c6_i596 = c6_i596 + 1) {
      c6_ge_B[c6_i596] = c6_fe_B[c6_i596];
    }

    for (c6_i597 = 0; c6_i597 < 16; c6_i597 = c6_i597 + 1) {
      c6_qe_A[c6_i597] = c6_pe_A[c6_i597];
    }

    for (c6_i598 = 0; c6_i598 < 16; c6_i598 = c6_i598 + 1) {
      c6_he_B[c6_i598] = c6_ge_B[c6_i598];
    }

    for (c6_i599 = 0; c6_i599 < 4; c6_i599 = c6_i599 + 1) {
      c6_i600 = 0;
      for (c6_i601 = 0; c6_i601 < 4; c6_i601 = c6_i601 + 1) {
        c6_ac_a[c6_i600 + c6_i599] = 0.0;
        c6_i602 = 0;
        for (c6_i603 = 0; c6_i603 < 4; c6_i603 = c6_i603 + 1) {
          c6_ac_a[c6_i600 + c6_i599] = c6_ac_a[c6_i600 + c6_i599] +
            c6_qe_A[c6_i602 + c6_i599] * c6_he_B[c6_i603 + c6_i600];
          c6_i602 = c6_i602 + 4;
        }

        c6_i600 = c6_i600 + 4;
      }
    }

    for (c6_i604 = 0; c6_i604 < 16; c6_i604 = c6_i604 + 1) {
      c6_lb_b[c6_i604] = c6_D6[c6_i604];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i605 = 0; c6_i605 < 16; c6_i605 = c6_i605 + 1) {
      c6_re_A[c6_i605] = c6_ac_a[c6_i605];
    }

    for (c6_i606 = 0; c6_i606 < 16; c6_i606 = c6_i606 + 1) {
      c6_ie_B[c6_i606] = c6_lb_b[c6_i606];
    }

    for (c6_i607 = 0; c6_i607 < 16; c6_i607 = c6_i607 + 1) {
      c6_se_A[c6_i607] = c6_re_A[c6_i607];
    }

    for (c6_i608 = 0; c6_i608 < 16; c6_i608 = c6_i608 + 1) {
      c6_je_B[c6_i608] = c6_ie_B[c6_i608];
    }

    for (c6_i609 = 0; c6_i609 < 16; c6_i609 = c6_i609 + 1) {
      c6_te_A[c6_i609] = c6_se_A[c6_i609];
    }

    for (c6_i610 = 0; c6_i610 < 16; c6_i610 = c6_i610 + 1) {
      c6_ke_B[c6_i610] = c6_je_B[c6_i610];
    }

    for (c6_i611 = 0; c6_i611 < 4; c6_i611 = c6_i611 + 1) {
      c6_i612 = 0;
      for (c6_i613 = 0; c6_i613 < 4; c6_i613 = c6_i613 + 1) {
        c6_bc_a[c6_i612 + c6_i611] = 0.0;
        c6_i614 = 0;
        for (c6_i615 = 0; c6_i615 < 4; c6_i615 = c6_i615 + 1) {
          c6_bc_a[c6_i612 + c6_i611] = c6_bc_a[c6_i612 + c6_i611] +
            c6_te_A[c6_i614 + c6_i611] * c6_ke_B[c6_i615 + c6_i612];
          c6_i614 = c6_i614 + 4;
        }

        c6_i612 = c6_i612 + 4;
      }
    }

    c6_c_eml_scalar_eg();
    c6_c_eml_scalar_eg();
    for (c6_i616 = 0; c6_i616 < 16; c6_i616 = c6_i616 + 1) {
      c6_ue_A[c6_i616] = c6_bc_a[c6_i616];
    }

    for (c6_i617 = 0; c6_i617 < 4; c6_i617 = c6_i617 + 1) {
      c6_h3[c6_i617] = 0.0;
    }

    for (c6_i618 = 0; c6_i618 < 16; c6_i618 = c6_i618 + 1) {
      c6_ve_A[c6_i618] = c6_ue_A[c6_i618];
    }

    for (c6_i619 = 0; c6_i619 < 16; c6_i619 = c6_i619 + 1) {
      c6_we_A[c6_i619] = c6_ve_A[c6_i619];
    }

    for (c6_i620 = 0; c6_i620 < 4; c6_i620 = c6_i620 + 1) {
      c6_h3[c6_i620] = 0.0;
      c6_i621 = 0;
      for (c6_i622 = 0; c6_i622 < 4; c6_i622 = c6_i622 + 1) {
        c6_h3[c6_i620] = c6_h3[c6_i620] + c6_we_A[c6_i621 + c6_i620] *
          c6_dv4[c6_i622];
        c6_i621 = c6_i621 + 4;
      }
    }

    _SFD_EML_CALL(0,186);
    for (c6_i623 = 0; c6_i623 < 16; c6_i623 = c6_i623 + 1) {
      c6_cc_a[c6_i623] = c6_D1[c6_i623];
    }

    for (c6_i624 = 0; c6_i624 < 16; c6_i624 = c6_i624 + 1) {
      c6_mb_b[c6_i624] = c6_D2[c6_i624];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i625 = 0; c6_i625 < 16; c6_i625 = c6_i625 + 1) {
      c6_xe_A[c6_i625] = c6_cc_a[c6_i625];
    }

    for (c6_i626 = 0; c6_i626 < 16; c6_i626 = c6_i626 + 1) {
      c6_le_B[c6_i626] = c6_mb_b[c6_i626];
    }

    for (c6_i627 = 0; c6_i627 < 16; c6_i627 = c6_i627 + 1) {
      c6_ye_A[c6_i627] = c6_xe_A[c6_i627];
    }

    for (c6_i628 = 0; c6_i628 < 16; c6_i628 = c6_i628 + 1) {
      c6_me_B[c6_i628] = c6_le_B[c6_i628];
    }

    for (c6_i629 = 0; c6_i629 < 16; c6_i629 = c6_i629 + 1) {
      c6_af_A[c6_i629] = c6_ye_A[c6_i629];
    }

    for (c6_i630 = 0; c6_i630 < 16; c6_i630 = c6_i630 + 1) {
      c6_ne_B[c6_i630] = c6_me_B[c6_i630];
    }

    for (c6_i631 = 0; c6_i631 < 4; c6_i631 = c6_i631 + 1) {
      c6_i632 = 0;
      for (c6_i633 = 0; c6_i633 < 4; c6_i633 = c6_i633 + 1) {
        c6_dc_a[c6_i632 + c6_i631] = 0.0;
        c6_i634 = 0;
        for (c6_i635 = 0; c6_i635 < 4; c6_i635 = c6_i635 + 1) {
          c6_dc_a[c6_i632 + c6_i631] = c6_dc_a[c6_i632 + c6_i631] +
            c6_af_A[c6_i634 + c6_i631] * c6_ne_B[c6_i635 + c6_i632];
          c6_i634 = c6_i634 + 4;
        }

        c6_i632 = c6_i632 + 4;
      }
    }

    for (c6_i636 = 0; c6_i636 < 16; c6_i636 = c6_i636 + 1) {
      c6_nb_b[c6_i636] = c6_D3[c6_i636];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i637 = 0; c6_i637 < 16; c6_i637 = c6_i637 + 1) {
      c6_bf_A[c6_i637] = c6_dc_a[c6_i637];
    }

    for (c6_i638 = 0; c6_i638 < 16; c6_i638 = c6_i638 + 1) {
      c6_oe_B[c6_i638] = c6_nb_b[c6_i638];
    }

    for (c6_i639 = 0; c6_i639 < 16; c6_i639 = c6_i639 + 1) {
      c6_cf_A[c6_i639] = c6_bf_A[c6_i639];
    }

    for (c6_i640 = 0; c6_i640 < 16; c6_i640 = c6_i640 + 1) {
      c6_pe_B[c6_i640] = c6_oe_B[c6_i640];
    }

    for (c6_i641 = 0; c6_i641 < 16; c6_i641 = c6_i641 + 1) {
      c6_df_A[c6_i641] = c6_cf_A[c6_i641];
    }

    for (c6_i642 = 0; c6_i642 < 16; c6_i642 = c6_i642 + 1) {
      c6_qe_B[c6_i642] = c6_pe_B[c6_i642];
    }

    for (c6_i643 = 0; c6_i643 < 4; c6_i643 = c6_i643 + 1) {
      c6_i644 = 0;
      for (c6_i645 = 0; c6_i645 < 4; c6_i645 = c6_i645 + 1) {
        c6_ec_a[c6_i644 + c6_i643] = 0.0;
        c6_i646 = 0;
        for (c6_i647 = 0; c6_i647 < 4; c6_i647 = c6_i647 + 1) {
          c6_ec_a[c6_i644 + c6_i643] = c6_ec_a[c6_i644 + c6_i643] +
            c6_df_A[c6_i646 + c6_i643] * c6_qe_B[c6_i647 + c6_i644];
          c6_i646 = c6_i646 + 4;
        }

        c6_i644 = c6_i644 + 4;
      }
    }

    for (c6_i648 = 0; c6_i648 < 16; c6_i648 = c6_i648 + 1) {
      c6_ob_b[c6_i648] = c6_dD4[c6_i648];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i649 = 0; c6_i649 < 16; c6_i649 = c6_i649 + 1) {
      c6_ef_A[c6_i649] = c6_ec_a[c6_i649];
    }

    for (c6_i650 = 0; c6_i650 < 16; c6_i650 = c6_i650 + 1) {
      c6_re_B[c6_i650] = c6_ob_b[c6_i650];
    }

    for (c6_i651 = 0; c6_i651 < 16; c6_i651 = c6_i651 + 1) {
      c6_ff_A[c6_i651] = c6_ef_A[c6_i651];
    }

    for (c6_i652 = 0; c6_i652 < 16; c6_i652 = c6_i652 + 1) {
      c6_se_B[c6_i652] = c6_re_B[c6_i652];
    }

    for (c6_i653 = 0; c6_i653 < 16; c6_i653 = c6_i653 + 1) {
      c6_gf_A[c6_i653] = c6_ff_A[c6_i653];
    }

    for (c6_i654 = 0; c6_i654 < 16; c6_i654 = c6_i654 + 1) {
      c6_te_B[c6_i654] = c6_se_B[c6_i654];
    }

    for (c6_i655 = 0; c6_i655 < 4; c6_i655 = c6_i655 + 1) {
      c6_i656 = 0;
      for (c6_i657 = 0; c6_i657 < 4; c6_i657 = c6_i657 + 1) {
        c6_fc_a[c6_i656 + c6_i655] = 0.0;
        c6_i658 = 0;
        for (c6_i659 = 0; c6_i659 < 4; c6_i659 = c6_i659 + 1) {
          c6_fc_a[c6_i656 + c6_i655] = c6_fc_a[c6_i656 + c6_i655] +
            c6_gf_A[c6_i658 + c6_i655] * c6_te_B[c6_i659 + c6_i656];
          c6_i658 = c6_i658 + 4;
        }

        c6_i656 = c6_i656 + 4;
      }
    }

    for (c6_i660 = 0; c6_i660 < 16; c6_i660 = c6_i660 + 1) {
      c6_pb_b[c6_i660] = c6_D5[c6_i660];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i661 = 0; c6_i661 < 16; c6_i661 = c6_i661 + 1) {
      c6_hf_A[c6_i661] = c6_fc_a[c6_i661];
    }

    for (c6_i662 = 0; c6_i662 < 16; c6_i662 = c6_i662 + 1) {
      c6_ue_B[c6_i662] = c6_pb_b[c6_i662];
    }

    for (c6_i663 = 0; c6_i663 < 16; c6_i663 = c6_i663 + 1) {
      c6_if_A[c6_i663] = c6_hf_A[c6_i663];
    }

    for (c6_i664 = 0; c6_i664 < 16; c6_i664 = c6_i664 + 1) {
      c6_ve_B[c6_i664] = c6_ue_B[c6_i664];
    }

    for (c6_i665 = 0; c6_i665 < 16; c6_i665 = c6_i665 + 1) {
      c6_jf_A[c6_i665] = c6_if_A[c6_i665];
    }

    for (c6_i666 = 0; c6_i666 < 16; c6_i666 = c6_i666 + 1) {
      c6_we_B[c6_i666] = c6_ve_B[c6_i666];
    }

    for (c6_i667 = 0; c6_i667 < 4; c6_i667 = c6_i667 + 1) {
      c6_i668 = 0;
      for (c6_i669 = 0; c6_i669 < 4; c6_i669 = c6_i669 + 1) {
        c6_gc_a[c6_i668 + c6_i667] = 0.0;
        c6_i670 = 0;
        for (c6_i671 = 0; c6_i671 < 4; c6_i671 = c6_i671 + 1) {
          c6_gc_a[c6_i668 + c6_i667] = c6_gc_a[c6_i668 + c6_i667] +
            c6_jf_A[c6_i670 + c6_i667] * c6_we_B[c6_i671 + c6_i668];
          c6_i670 = c6_i670 + 4;
        }

        c6_i668 = c6_i668 + 4;
      }
    }

    for (c6_i672 = 0; c6_i672 < 16; c6_i672 = c6_i672 + 1) {
      c6_qb_b[c6_i672] = c6_D6[c6_i672];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i673 = 0; c6_i673 < 16; c6_i673 = c6_i673 + 1) {
      c6_kf_A[c6_i673] = c6_gc_a[c6_i673];
    }

    for (c6_i674 = 0; c6_i674 < 16; c6_i674 = c6_i674 + 1) {
      c6_xe_B[c6_i674] = c6_qb_b[c6_i674];
    }

    for (c6_i675 = 0; c6_i675 < 16; c6_i675 = c6_i675 + 1) {
      c6_lf_A[c6_i675] = c6_kf_A[c6_i675];
    }

    for (c6_i676 = 0; c6_i676 < 16; c6_i676 = c6_i676 + 1) {
      c6_ye_B[c6_i676] = c6_xe_B[c6_i676];
    }

    for (c6_i677 = 0; c6_i677 < 16; c6_i677 = c6_i677 + 1) {
      c6_mf_A[c6_i677] = c6_lf_A[c6_i677];
    }

    for (c6_i678 = 0; c6_i678 < 16; c6_i678 = c6_i678 + 1) {
      c6_af_B[c6_i678] = c6_ye_B[c6_i678];
    }

    for (c6_i679 = 0; c6_i679 < 4; c6_i679 = c6_i679 + 1) {
      c6_i680 = 0;
      for (c6_i681 = 0; c6_i681 < 4; c6_i681 = c6_i681 + 1) {
        c6_hc_a[c6_i680 + c6_i679] = 0.0;
        c6_i682 = 0;
        for (c6_i683 = 0; c6_i683 < 4; c6_i683 = c6_i683 + 1) {
          c6_hc_a[c6_i680 + c6_i679] = c6_hc_a[c6_i680 + c6_i679] +
            c6_mf_A[c6_i682 + c6_i679] * c6_af_B[c6_i683 + c6_i680];
          c6_i682 = c6_i682 + 4;
        }

        c6_i680 = c6_i680 + 4;
      }
    }

    c6_c_eml_scalar_eg();
    c6_c_eml_scalar_eg();
    for (c6_i684 = 0; c6_i684 < 16; c6_i684 = c6_i684 + 1) {
      c6_nf_A[c6_i684] = c6_hc_a[c6_i684];
    }

    for (c6_i685 = 0; c6_i685 < 4; c6_i685 = c6_i685 + 1) {
      c6_h4[c6_i685] = 0.0;
    }

    for (c6_i686 = 0; c6_i686 < 16; c6_i686 = c6_i686 + 1) {
      c6_of_A[c6_i686] = c6_nf_A[c6_i686];
    }

    for (c6_i687 = 0; c6_i687 < 16; c6_i687 = c6_i687 + 1) {
      c6_pf_A[c6_i687] = c6_of_A[c6_i687];
    }

    for (c6_i688 = 0; c6_i688 < 4; c6_i688 = c6_i688 + 1) {
      c6_h4[c6_i688] = 0.0;
      c6_i689 = 0;
      for (c6_i690 = 0; c6_i690 < 4; c6_i690 = c6_i690 + 1) {
        c6_h4[c6_i688] = c6_h4[c6_i688] + c6_pf_A[c6_i689 + c6_i688] *
          c6_dv4[c6_i690];
        c6_i689 = c6_i689 + 4;
      }
    }

    _SFD_EML_CALL(0,187);
    for (c6_i691 = 0; c6_i691 < 16; c6_i691 = c6_i691 + 1) {
      c6_ic_a[c6_i691] = c6_D1[c6_i691];
    }

    for (c6_i692 = 0; c6_i692 < 16; c6_i692 = c6_i692 + 1) {
      c6_rb_b[c6_i692] = c6_D2[c6_i692];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i693 = 0; c6_i693 < 16; c6_i693 = c6_i693 + 1) {
      c6_qf_A[c6_i693] = c6_ic_a[c6_i693];
    }

    for (c6_i694 = 0; c6_i694 < 16; c6_i694 = c6_i694 + 1) {
      c6_bf_B[c6_i694] = c6_rb_b[c6_i694];
    }

    for (c6_i695 = 0; c6_i695 < 16; c6_i695 = c6_i695 + 1) {
      c6_rf_A[c6_i695] = c6_qf_A[c6_i695];
    }

    for (c6_i696 = 0; c6_i696 < 16; c6_i696 = c6_i696 + 1) {
      c6_cf_B[c6_i696] = c6_bf_B[c6_i696];
    }

    for (c6_i697 = 0; c6_i697 < 16; c6_i697 = c6_i697 + 1) {
      c6_sf_A[c6_i697] = c6_rf_A[c6_i697];
    }

    for (c6_i698 = 0; c6_i698 < 16; c6_i698 = c6_i698 + 1) {
      c6_df_B[c6_i698] = c6_cf_B[c6_i698];
    }

    for (c6_i699 = 0; c6_i699 < 4; c6_i699 = c6_i699 + 1) {
      c6_i700 = 0;
      for (c6_i701 = 0; c6_i701 < 4; c6_i701 = c6_i701 + 1) {
        c6_jc_a[c6_i700 + c6_i699] = 0.0;
        c6_i702 = 0;
        for (c6_i703 = 0; c6_i703 < 4; c6_i703 = c6_i703 + 1) {
          c6_jc_a[c6_i700 + c6_i699] = c6_jc_a[c6_i700 + c6_i699] +
            c6_sf_A[c6_i702 + c6_i699] * c6_df_B[c6_i703 + c6_i700];
          c6_i702 = c6_i702 + 4;
        }

        c6_i700 = c6_i700 + 4;
      }
    }

    for (c6_i704 = 0; c6_i704 < 16; c6_i704 = c6_i704 + 1) {
      c6_sb_b[c6_i704] = c6_D3[c6_i704];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i705 = 0; c6_i705 < 16; c6_i705 = c6_i705 + 1) {
      c6_tf_A[c6_i705] = c6_jc_a[c6_i705];
    }

    for (c6_i706 = 0; c6_i706 < 16; c6_i706 = c6_i706 + 1) {
      c6_ef_B[c6_i706] = c6_sb_b[c6_i706];
    }

    for (c6_i707 = 0; c6_i707 < 16; c6_i707 = c6_i707 + 1) {
      c6_uf_A[c6_i707] = c6_tf_A[c6_i707];
    }

    for (c6_i708 = 0; c6_i708 < 16; c6_i708 = c6_i708 + 1) {
      c6_ff_B[c6_i708] = c6_ef_B[c6_i708];
    }

    for (c6_i709 = 0; c6_i709 < 16; c6_i709 = c6_i709 + 1) {
      c6_vf_A[c6_i709] = c6_uf_A[c6_i709];
    }

    for (c6_i710 = 0; c6_i710 < 16; c6_i710 = c6_i710 + 1) {
      c6_gf_B[c6_i710] = c6_ff_B[c6_i710];
    }

    for (c6_i711 = 0; c6_i711 < 4; c6_i711 = c6_i711 + 1) {
      c6_i712 = 0;
      for (c6_i713 = 0; c6_i713 < 4; c6_i713 = c6_i713 + 1) {
        c6_kc_a[c6_i712 + c6_i711] = 0.0;
        c6_i714 = 0;
        for (c6_i715 = 0; c6_i715 < 4; c6_i715 = c6_i715 + 1) {
          c6_kc_a[c6_i712 + c6_i711] = c6_kc_a[c6_i712 + c6_i711] +
            c6_vf_A[c6_i714 + c6_i711] * c6_gf_B[c6_i715 + c6_i712];
          c6_i714 = c6_i714 + 4;
        }

        c6_i712 = c6_i712 + 4;
      }
    }

    for (c6_i716 = 0; c6_i716 < 16; c6_i716 = c6_i716 + 1) {
      c6_tb_b[c6_i716] = c6_D4[c6_i716];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i717 = 0; c6_i717 < 16; c6_i717 = c6_i717 + 1) {
      c6_wf_A[c6_i717] = c6_kc_a[c6_i717];
    }

    for (c6_i718 = 0; c6_i718 < 16; c6_i718 = c6_i718 + 1) {
      c6_hf_B[c6_i718] = c6_tb_b[c6_i718];
    }

    for (c6_i719 = 0; c6_i719 < 16; c6_i719 = c6_i719 + 1) {
      c6_xf_A[c6_i719] = c6_wf_A[c6_i719];
    }

    for (c6_i720 = 0; c6_i720 < 16; c6_i720 = c6_i720 + 1) {
      c6_if_B[c6_i720] = c6_hf_B[c6_i720];
    }

    for (c6_i721 = 0; c6_i721 < 16; c6_i721 = c6_i721 + 1) {
      c6_yf_A[c6_i721] = c6_xf_A[c6_i721];
    }

    for (c6_i722 = 0; c6_i722 < 16; c6_i722 = c6_i722 + 1) {
      c6_jf_B[c6_i722] = c6_if_B[c6_i722];
    }

    for (c6_i723 = 0; c6_i723 < 4; c6_i723 = c6_i723 + 1) {
      c6_i724 = 0;
      for (c6_i725 = 0; c6_i725 < 4; c6_i725 = c6_i725 + 1) {
        c6_lc_a[c6_i724 + c6_i723] = 0.0;
        c6_i726 = 0;
        for (c6_i727 = 0; c6_i727 < 4; c6_i727 = c6_i727 + 1) {
          c6_lc_a[c6_i724 + c6_i723] = c6_lc_a[c6_i724 + c6_i723] +
            c6_yf_A[c6_i726 + c6_i723] * c6_jf_B[c6_i727 + c6_i724];
          c6_i726 = c6_i726 + 4;
        }

        c6_i724 = c6_i724 + 4;
      }
    }

    for (c6_i728 = 0; c6_i728 < 16; c6_i728 = c6_i728 + 1) {
      c6_ub_b[c6_i728] = c6_dD5[c6_i728];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i729 = 0; c6_i729 < 16; c6_i729 = c6_i729 + 1) {
      c6_ag_A[c6_i729] = c6_lc_a[c6_i729];
    }

    for (c6_i730 = 0; c6_i730 < 16; c6_i730 = c6_i730 + 1) {
      c6_kf_B[c6_i730] = c6_ub_b[c6_i730];
    }

    for (c6_i731 = 0; c6_i731 < 16; c6_i731 = c6_i731 + 1) {
      c6_bg_A[c6_i731] = c6_ag_A[c6_i731];
    }

    for (c6_i732 = 0; c6_i732 < 16; c6_i732 = c6_i732 + 1) {
      c6_lf_B[c6_i732] = c6_kf_B[c6_i732];
    }

    for (c6_i733 = 0; c6_i733 < 16; c6_i733 = c6_i733 + 1) {
      c6_cg_A[c6_i733] = c6_bg_A[c6_i733];
    }

    for (c6_i734 = 0; c6_i734 < 16; c6_i734 = c6_i734 + 1) {
      c6_mf_B[c6_i734] = c6_lf_B[c6_i734];
    }

    for (c6_i735 = 0; c6_i735 < 4; c6_i735 = c6_i735 + 1) {
      c6_i736 = 0;
      for (c6_i737 = 0; c6_i737 < 4; c6_i737 = c6_i737 + 1) {
        c6_mc_a[c6_i736 + c6_i735] = 0.0;
        c6_i738 = 0;
        for (c6_i739 = 0; c6_i739 < 4; c6_i739 = c6_i739 + 1) {
          c6_mc_a[c6_i736 + c6_i735] = c6_mc_a[c6_i736 + c6_i735] +
            c6_cg_A[c6_i738 + c6_i735] * c6_mf_B[c6_i739 + c6_i736];
          c6_i738 = c6_i738 + 4;
        }

        c6_i736 = c6_i736 + 4;
      }
    }

    for (c6_i740 = 0; c6_i740 < 16; c6_i740 = c6_i740 + 1) {
      c6_vb_b[c6_i740] = c6_D6[c6_i740];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i741 = 0; c6_i741 < 16; c6_i741 = c6_i741 + 1) {
      c6_dg_A[c6_i741] = c6_mc_a[c6_i741];
    }

    for (c6_i742 = 0; c6_i742 < 16; c6_i742 = c6_i742 + 1) {
      c6_nf_B[c6_i742] = c6_vb_b[c6_i742];
    }

    for (c6_i743 = 0; c6_i743 < 16; c6_i743 = c6_i743 + 1) {
      c6_eg_A[c6_i743] = c6_dg_A[c6_i743];
    }

    for (c6_i744 = 0; c6_i744 < 16; c6_i744 = c6_i744 + 1) {
      c6_of_B[c6_i744] = c6_nf_B[c6_i744];
    }

    for (c6_i745 = 0; c6_i745 < 16; c6_i745 = c6_i745 + 1) {
      c6_fg_A[c6_i745] = c6_eg_A[c6_i745];
    }

    for (c6_i746 = 0; c6_i746 < 16; c6_i746 = c6_i746 + 1) {
      c6_pf_B[c6_i746] = c6_of_B[c6_i746];
    }

    for (c6_i747 = 0; c6_i747 < 4; c6_i747 = c6_i747 + 1) {
      c6_i748 = 0;
      for (c6_i749 = 0; c6_i749 < 4; c6_i749 = c6_i749 + 1) {
        c6_nc_a[c6_i748 + c6_i747] = 0.0;
        c6_i750 = 0;
        for (c6_i751 = 0; c6_i751 < 4; c6_i751 = c6_i751 + 1) {
          c6_nc_a[c6_i748 + c6_i747] = c6_nc_a[c6_i748 + c6_i747] +
            c6_fg_A[c6_i750 + c6_i747] * c6_pf_B[c6_i751 + c6_i748];
          c6_i750 = c6_i750 + 4;
        }

        c6_i748 = c6_i748 + 4;
      }
    }

    c6_c_eml_scalar_eg();
    c6_c_eml_scalar_eg();
    for (c6_i752 = 0; c6_i752 < 16; c6_i752 = c6_i752 + 1) {
      c6_gg_A[c6_i752] = c6_nc_a[c6_i752];
    }

    for (c6_i753 = 0; c6_i753 < 4; c6_i753 = c6_i753 + 1) {
      c6_h5[c6_i753] = 0.0;
    }

    for (c6_i754 = 0; c6_i754 < 16; c6_i754 = c6_i754 + 1) {
      c6_hg_A[c6_i754] = c6_gg_A[c6_i754];
    }

    for (c6_i755 = 0; c6_i755 < 16; c6_i755 = c6_i755 + 1) {
      c6_ig_A[c6_i755] = c6_hg_A[c6_i755];
    }

    for (c6_i756 = 0; c6_i756 < 4; c6_i756 = c6_i756 + 1) {
      c6_h5[c6_i756] = 0.0;
      c6_i757 = 0;
      for (c6_i758 = 0; c6_i758 < 4; c6_i758 = c6_i758 + 1) {
        c6_h5[c6_i756] = c6_h5[c6_i756] + c6_ig_A[c6_i757 + c6_i756] *
          c6_dv4[c6_i758];
        c6_i757 = c6_i757 + 4;
      }
    }

    _SFD_EML_CALL(0,188);
    for (c6_i759 = 0; c6_i759 < 16; c6_i759 = c6_i759 + 1) {
      c6_oc_a[c6_i759] = c6_D1[c6_i759];
    }

    for (c6_i760 = 0; c6_i760 < 16; c6_i760 = c6_i760 + 1) {
      c6_wb_b[c6_i760] = c6_D2[c6_i760];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i761 = 0; c6_i761 < 16; c6_i761 = c6_i761 + 1) {
      c6_jg_A[c6_i761] = c6_oc_a[c6_i761];
    }

    for (c6_i762 = 0; c6_i762 < 16; c6_i762 = c6_i762 + 1) {
      c6_qf_B[c6_i762] = c6_wb_b[c6_i762];
    }

    for (c6_i763 = 0; c6_i763 < 16; c6_i763 = c6_i763 + 1) {
      c6_kg_A[c6_i763] = c6_jg_A[c6_i763];
    }

    for (c6_i764 = 0; c6_i764 < 16; c6_i764 = c6_i764 + 1) {
      c6_rf_B[c6_i764] = c6_qf_B[c6_i764];
    }

    for (c6_i765 = 0; c6_i765 < 16; c6_i765 = c6_i765 + 1) {
      c6_lg_A[c6_i765] = c6_kg_A[c6_i765];
    }

    for (c6_i766 = 0; c6_i766 < 16; c6_i766 = c6_i766 + 1) {
      c6_sf_B[c6_i766] = c6_rf_B[c6_i766];
    }

    for (c6_i767 = 0; c6_i767 < 4; c6_i767 = c6_i767 + 1) {
      c6_i768 = 0;
      for (c6_i769 = 0; c6_i769 < 4; c6_i769 = c6_i769 + 1) {
        c6_pc_a[c6_i768 + c6_i767] = 0.0;
        c6_i770 = 0;
        for (c6_i771 = 0; c6_i771 < 4; c6_i771 = c6_i771 + 1) {
          c6_pc_a[c6_i768 + c6_i767] = c6_pc_a[c6_i768 + c6_i767] +
            c6_lg_A[c6_i770 + c6_i767] * c6_sf_B[c6_i771 + c6_i768];
          c6_i770 = c6_i770 + 4;
        }

        c6_i768 = c6_i768 + 4;
      }
    }

    for (c6_i772 = 0; c6_i772 < 16; c6_i772 = c6_i772 + 1) {
      c6_xb_b[c6_i772] = c6_D3[c6_i772];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i773 = 0; c6_i773 < 16; c6_i773 = c6_i773 + 1) {
      c6_mg_A[c6_i773] = c6_pc_a[c6_i773];
    }

    for (c6_i774 = 0; c6_i774 < 16; c6_i774 = c6_i774 + 1) {
      c6_tf_B[c6_i774] = c6_xb_b[c6_i774];
    }

    for (c6_i775 = 0; c6_i775 < 16; c6_i775 = c6_i775 + 1) {
      c6_ng_A[c6_i775] = c6_mg_A[c6_i775];
    }

    for (c6_i776 = 0; c6_i776 < 16; c6_i776 = c6_i776 + 1) {
      c6_uf_B[c6_i776] = c6_tf_B[c6_i776];
    }

    for (c6_i777 = 0; c6_i777 < 16; c6_i777 = c6_i777 + 1) {
      c6_og_A[c6_i777] = c6_ng_A[c6_i777];
    }

    for (c6_i778 = 0; c6_i778 < 16; c6_i778 = c6_i778 + 1) {
      c6_vf_B[c6_i778] = c6_uf_B[c6_i778];
    }

    for (c6_i779 = 0; c6_i779 < 4; c6_i779 = c6_i779 + 1) {
      c6_i780 = 0;
      for (c6_i781 = 0; c6_i781 < 4; c6_i781 = c6_i781 + 1) {
        c6_qc_a[c6_i780 + c6_i779] = 0.0;
        c6_i782 = 0;
        for (c6_i783 = 0; c6_i783 < 4; c6_i783 = c6_i783 + 1) {
          c6_qc_a[c6_i780 + c6_i779] = c6_qc_a[c6_i780 + c6_i779] +
            c6_og_A[c6_i782 + c6_i779] * c6_vf_B[c6_i783 + c6_i780];
          c6_i782 = c6_i782 + 4;
        }

        c6_i780 = c6_i780 + 4;
      }
    }

    for (c6_i784 = 0; c6_i784 < 16; c6_i784 = c6_i784 + 1) {
      c6_yb_b[c6_i784] = c6_D4[c6_i784];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i785 = 0; c6_i785 < 16; c6_i785 = c6_i785 + 1) {
      c6_pg_A[c6_i785] = c6_qc_a[c6_i785];
    }

    for (c6_i786 = 0; c6_i786 < 16; c6_i786 = c6_i786 + 1) {
      c6_wf_B[c6_i786] = c6_yb_b[c6_i786];
    }

    for (c6_i787 = 0; c6_i787 < 16; c6_i787 = c6_i787 + 1) {
      c6_qg_A[c6_i787] = c6_pg_A[c6_i787];
    }

    for (c6_i788 = 0; c6_i788 < 16; c6_i788 = c6_i788 + 1) {
      c6_xf_B[c6_i788] = c6_wf_B[c6_i788];
    }

    for (c6_i789 = 0; c6_i789 < 16; c6_i789 = c6_i789 + 1) {
      c6_rg_A[c6_i789] = c6_qg_A[c6_i789];
    }

    for (c6_i790 = 0; c6_i790 < 16; c6_i790 = c6_i790 + 1) {
      c6_yf_B[c6_i790] = c6_xf_B[c6_i790];
    }

    for (c6_i791 = 0; c6_i791 < 4; c6_i791 = c6_i791 + 1) {
      c6_i792 = 0;
      for (c6_i793 = 0; c6_i793 < 4; c6_i793 = c6_i793 + 1) {
        c6_rc_a[c6_i792 + c6_i791] = 0.0;
        c6_i794 = 0;
        for (c6_i795 = 0; c6_i795 < 4; c6_i795 = c6_i795 + 1) {
          c6_rc_a[c6_i792 + c6_i791] = c6_rc_a[c6_i792 + c6_i791] +
            c6_rg_A[c6_i794 + c6_i791] * c6_yf_B[c6_i795 + c6_i792];
          c6_i794 = c6_i794 + 4;
        }

        c6_i792 = c6_i792 + 4;
      }
    }

    for (c6_i796 = 0; c6_i796 < 16; c6_i796 = c6_i796 + 1) {
      c6_ac_b[c6_i796] = c6_D5[c6_i796];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i797 = 0; c6_i797 < 16; c6_i797 = c6_i797 + 1) {
      c6_sg_A[c6_i797] = c6_rc_a[c6_i797];
    }

    for (c6_i798 = 0; c6_i798 < 16; c6_i798 = c6_i798 + 1) {
      c6_ag_B[c6_i798] = c6_ac_b[c6_i798];
    }

    for (c6_i799 = 0; c6_i799 < 16; c6_i799 = c6_i799 + 1) {
      c6_tg_A[c6_i799] = c6_sg_A[c6_i799];
    }

    for (c6_i800 = 0; c6_i800 < 16; c6_i800 = c6_i800 + 1) {
      c6_bg_B[c6_i800] = c6_ag_B[c6_i800];
    }

    for (c6_i801 = 0; c6_i801 < 16; c6_i801 = c6_i801 + 1) {
      c6_ug_A[c6_i801] = c6_tg_A[c6_i801];
    }

    for (c6_i802 = 0; c6_i802 < 16; c6_i802 = c6_i802 + 1) {
      c6_cg_B[c6_i802] = c6_bg_B[c6_i802];
    }

    for (c6_i803 = 0; c6_i803 < 4; c6_i803 = c6_i803 + 1) {
      c6_i804 = 0;
      for (c6_i805 = 0; c6_i805 < 4; c6_i805 = c6_i805 + 1) {
        c6_sc_a[c6_i804 + c6_i803] = 0.0;
        c6_i806 = 0;
        for (c6_i807 = 0; c6_i807 < 4; c6_i807 = c6_i807 + 1) {
          c6_sc_a[c6_i804 + c6_i803] = c6_sc_a[c6_i804 + c6_i803] +
            c6_ug_A[c6_i806 + c6_i803] * c6_cg_B[c6_i807 + c6_i804];
          c6_i806 = c6_i806 + 4;
        }

        c6_i804 = c6_i804 + 4;
      }
    }

    for (c6_i808 = 0; c6_i808 < 16; c6_i808 = c6_i808 + 1) {
      c6_bc_b[c6_i808] = c6_dD6[c6_i808];
    }

    c6_b_eml_scalar_eg();
    c6_b_eml_scalar_eg();
    for (c6_i809 = 0; c6_i809 < 16; c6_i809 = c6_i809 + 1) {
      c6_vg_A[c6_i809] = c6_sc_a[c6_i809];
    }

    for (c6_i810 = 0; c6_i810 < 16; c6_i810 = c6_i810 + 1) {
      c6_dg_B[c6_i810] = c6_bc_b[c6_i810];
    }

    for (c6_i811 = 0; c6_i811 < 16; c6_i811 = c6_i811 + 1) {
      c6_wg_A[c6_i811] = c6_vg_A[c6_i811];
    }

    for (c6_i812 = 0; c6_i812 < 16; c6_i812 = c6_i812 + 1) {
      c6_eg_B[c6_i812] = c6_dg_B[c6_i812];
    }

    for (c6_i813 = 0; c6_i813 < 16; c6_i813 = c6_i813 + 1) {
      c6_xg_A[c6_i813] = c6_wg_A[c6_i813];
    }

    for (c6_i814 = 0; c6_i814 < 16; c6_i814 = c6_i814 + 1) {
      c6_fg_B[c6_i814] = c6_eg_B[c6_i814];
    }

    for (c6_i815 = 0; c6_i815 < 4; c6_i815 = c6_i815 + 1) {
      c6_i816 = 0;
      for (c6_i817 = 0; c6_i817 < 4; c6_i817 = c6_i817 + 1) {
        c6_tc_a[c6_i816 + c6_i815] = 0.0;
        c6_i818 = 0;
        for (c6_i819 = 0; c6_i819 < 4; c6_i819 = c6_i819 + 1) {
          c6_tc_a[c6_i816 + c6_i815] = c6_tc_a[c6_i816 + c6_i815] +
            c6_xg_A[c6_i818 + c6_i815] * c6_fg_B[c6_i819 + c6_i816];
          c6_i818 = c6_i818 + 4;
        }

        c6_i816 = c6_i816 + 4;
      }
    }

    c6_c_eml_scalar_eg();
    c6_c_eml_scalar_eg();
    for (c6_i820 = 0; c6_i820 < 16; c6_i820 = c6_i820 + 1) {
      c6_yg_A[c6_i820] = c6_tc_a[c6_i820];
    }

    for (c6_i821 = 0; c6_i821 < 4; c6_i821 = c6_i821 + 1) {
      c6_h6[c6_i821] = 0.0;
    }

    for (c6_i822 = 0; c6_i822 < 16; c6_i822 = c6_i822 + 1) {
      c6_ah_A[c6_i822] = c6_yg_A[c6_i822];
    }

    for (c6_i823 = 0; c6_i823 < 16; c6_i823 = c6_i823 + 1) {
      c6_bh_A[c6_i823] = c6_ah_A[c6_i823];
    }

    for (c6_i824 = 0; c6_i824 < 4; c6_i824 = c6_i824 + 1) {
      c6_h6[c6_i824] = 0.0;
      c6_i825 = 0;
      for (c6_i826 = 0; c6_i826 < 4; c6_i826 = c6_i826 + 1) {
        c6_h6[c6_i824] = c6_h6[c6_i824] + c6_bh_A[c6_i825 + c6_i824] *
          c6_dv4[c6_i826];
        c6_i825 = c6_i825 + 4;
      }
    }

    _SFD_EML_CALL(0,190);
    for (c6_i827 = 0; c6_i827 < 4; c6_i827 = c6_i827 + 1) {
      c6_h[c6_i827] = c6_h1[c6_i827];
    }

    for (c6_i828 = 0; c6_i828 < 4; c6_i828 = c6_i828 + 1) {
      c6_h[c6_i828 + 4] = c6_h2[c6_i828];
    }

    for (c6_i829 = 0; c6_i829 < 4; c6_i829 = c6_i829 + 1) {
      c6_h[c6_i829 + 8] = c6_h3[c6_i829];
    }

    for (c6_i830 = 0; c6_i830 < 4; c6_i830 = c6_i830 + 1) {
      c6_h[c6_i830 + 12] = c6_h4[c6_i830];
    }

    for (c6_i831 = 0; c6_i831 < 4; c6_i831 = c6_i831 + 1) {
      c6_h[c6_i831 + 16] = c6_h5[c6_i831];
    }

    for (c6_i832 = 0; c6_i832 < 4; c6_i832 = c6_i832 + 1) {
      c6_h[c6_i832 + 20] = c6_h6[c6_i832];
    }

    /*  this 3x6 is th upper half of H */
    _SFD_EML_CALL(0,191);
    c6_i833 = 0;
    c6_i834 = 0;
    for (c6_i835 = 0; c6_i835 < 6; c6_i835 = c6_i835 + 1) {
      for (c6_i836 = 0; c6_i836 < 3; c6_i836 = c6_i836 + 1) {
        c6_H[c6_i836 + c6_i833] = c6_h[c6_i836 + c6_i834];
      }

      c6_i833 = c6_i833 + 6;
      c6_i834 = c6_i834 + 4;
    }

    c6_i837 = 0;
    c6_i838 = 0;
    for (c6_i839 = 0; c6_i839 < 6; c6_i839 = c6_i839 + 1) {
      for (c6_i840 = 0; c6_i840 < 3; c6_i840 = c6_i840 + 1) {
        c6_H[(c6_i840 + c6_i837) + 3] = c6_e[c6_i840 + c6_i838];
      }

      c6_i837 = c6_i837 + 6;
      c6_i838 = c6_i838 + 3;
    }

    /*  the lower 3x6 half is the matrix e */
    _SFD_EML_CALL(0,193);
    for (c6_i841 = 0; c6_i841 < 36; c6_i841 = c6_i841 + 1) {
      c6_b_H[c6_i841] = c6_H[c6_i841];
    }

    c6_inv(c6_b_H, c6_uc_a);
    for (c6_i842 = 0; c6_i842 < 3; c6_i842 = c6_i842 + 1) {
      c6_cc_b[c6_i842] = c6_EUL_ANG[c6_i842];
    }

    for (c6_i843 = 0; c6_i843 < 3; c6_i843 = c6_i843 + 1) {
      c6_y[c6_i843] = 1.7453292519943295E-002 * c6_cc_b[c6_i843];
    }

    for (c6_i844 = 0; c6_i844 < 3; c6_i844 = c6_i844 + 1) {
      c6_dc_b[c6_i844] = c6_POS[c6_i844] - c6_pos[c6_i844];
    }

    for (c6_i845 = 0; c6_i845 < 3; c6_i845 = c6_i845 + 1) {
      c6_dc_b[c6_i845 + 3] = c6_y[c6_i845] - c6_eul_ang[c6_i845];
    }

    c6_g_eml_scalar_eg();
    c6_g_eml_scalar_eg();
    for (c6_i846 = 0; c6_i846 < 36; c6_i846 = c6_i846 + 1) {
      c6_ch_A[c6_i846] = c6_uc_a[c6_i846];
    }

    for (c6_i847 = 0; c6_i847 < 6; c6_i847 = c6_i847 + 1) {
      c6_gg_B[c6_i847] = c6_dc_b[c6_i847];
    }

    for (c6_i848 = 0; c6_i848 < 6; c6_i848 = c6_i848 + 1) {
      c6_d_ang[c6_i848] = 0.0;
    }

    for (c6_i849 = 0; c6_i849 < 36; c6_i849 = c6_i849 + 1) {
      c6_dh_A[c6_i849] = c6_ch_A[c6_i849];
    }

    for (c6_i850 = 0; c6_i850 < 6; c6_i850 = c6_i850 + 1) {
      c6_hg_B[c6_i850] = c6_gg_B[c6_i850];
    }

    for (c6_i851 = 0; c6_i851 < 36; c6_i851 = c6_i851 + 1) {
      c6_eh_A[c6_i851] = c6_dh_A[c6_i851];
    }

    for (c6_i852 = 0; c6_i852 < 6; c6_i852 = c6_i852 + 1) {
      c6_ig_B[c6_i852] = c6_hg_B[c6_i852];
    }

    for (c6_i853 = 0; c6_i853 < 6; c6_i853 = c6_i853 + 1) {
      c6_d_ang[c6_i853] = 0.0;
      c6_i854 = 0;
      for (c6_i855 = 0; c6_i855 < 6; c6_i855 = c6_i855 + 1) {
        c6_d_ang[c6_i853] = c6_d_ang[c6_i853] + c6_eh_A[c6_i854 + c6_i853] *
          c6_ig_B[c6_i855];
        c6_i854 = c6_i854 + 6;
      }
    }

    _SFD_EML_CALL(0,194);
    for (c6_i856 = 0; c6_i856 < 6; c6_i856 = c6_i856 + 1) {
      c6_ang[c6_i856] = c6_ang[c6_i856] + c6_d_ang[c6_i856];
    }

    _SFD_EML_CALL(0,195);
    for (c6_i857 = 0; c6_i857 < 6; c6_i857 = c6_i857 + 1) {
      c6_c_ang[c6_i857] = c6_ang[c6_i857];
    }

    c6_adjust_ang(c6_c_ang, c6_dv25);
    for (c6_i858 = 0; c6_i858 < 6; c6_i858 = c6_i858 + 1) {
      c6_ang[c6_i858] = c6_dv25[c6_i858];
    }

    _SFD_EML_CALL(0,196);
    for (c6_i859 = 0; c6_i859 < 6; c6_i859 = c6_i859 + 1) {
      c6_b_d_ang[c6_i859] = c6_d_ang[c6_i859];
    }

    if (CV_EML_IF(0, 1, c6_b_norm(c6_b_d_ang) < 1.0E-006)) {
      _SFD_EML_CALL(0,197);
      for (c6_i860 = 0; c6_i860 < 6; c6_i860 = c6_i860 + 1) {
        c6_e_ang[c6_i860] = c6_ang[c6_i860];
      }

      c6_adjust_ang(c6_e_ang, c6_ec_b);
      for (c6_i861 = 0; c6_i861 < 6; c6_i861 = c6_i861 + 1) {
        c6_J_ANG[c6_i861] = 5.7295779513082323E+001 * c6_ec_b[c6_i861];
      }

      _SFD_EML_CALL(0,198);
      for (c6_i862 = 0; c6_i862 < 6; c6_i862 = c6_i862 + 1) {
        c6_out[c6_i862] = c6_J_ANG[c6_i862];
      }

      _SFD_EML_CALL(0,199);
      c6_out[6] = c6_N;

      /*  tests whether the links are within the set soft limits */
      c6_i = 1.0;
      c6_b_i = 1.0;
    } else {
      _SFD_EML_CALL(0,202);
      c6_N = c6_N + 1.0;

      /*  if more than 10 iterations, no convergence */
      _SFD_EML_CALL(0,205);
      sf_mex_listen_for_ctrl_c(chartInstance.S);
      if (CV_EML_IF(0, 2, c6_N > 10.0)) {
        _SFD_EML_CALL(0,206);
        for (c6_i863 = 0; c6_i863 < 6; c6_i863 = c6_i863 + 1) {
          c6_out[c6_i863] = c6_J_ANG_0[c6_i863];
        }

        /*  return vector as is */
        _SFD_EML_CALL(0,207);
        c6_out[6] = -1.0;
        goto label_1;
      } else {
        goto label_2;
      }
    }

   label_3:
    ;
    if (c6_b_i <= 6.0) {
      c6_i = c6_b_i;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(0,214);
      if (CV_EML_IF(0, 3, c6_J_ANG[_SFD_EML_ARRAY_BOUNDS_CHECK("J_ANG", (int32_T)
            _SFD_INTEGER_CHECK("i", c6_i), 1, 6, 1, 0) - 1] >= c6_SL[(
            _SFD_EML_ARRAY_BOUNDS_CHECK("SL", (int32_T)_SFD_INTEGER_CHECK("i",
              c6_i), 1, 6, 2, 0) - 1) << 1])) {
        _SFD_EML_CALL(0,215);
        c6_out[6] = -3.0;
      } else {
        _SFD_EML_CALL(0,217);
        if (CV_EML_IF(0, 4, c6_J_ANG[_SFD_EML_ARRAY_BOUNDS_CHECK("J_ANG",
              (int32_T)_SFD_INTEGER_CHECK("i", c6_i), 1, 6, 1, 0) - 1] <= c6_SL
                      [1
                      + ((_SFD_EML_ARRAY_BOUNDS_CHECK("SL", (int32_T)
                _SFD_INTEGER_CHECK("i", c6_i), 1, 6, 2, 0) - 1) << 1)])) {
          _SFD_EML_CALL(0,218);
          c6_out[6] = -3.0;
        } else {
          c6_b_i = c6_b_i + 1.0;
          sf_mex_listen_for_ctrl_c(chartInstance.S);
          goto label_3;
        }
      }
    } else {
      CV_EML_FOR(0, 0, 0);
    }

   label_1:
    ;
  }

  _SFD_EML_CALL(0,-218);
  sf_debug_symbol_scope_pop();
  for (c6_i864 = 0; c6_i864 < 7; c6_i864 = c6_i864 + 1) {
    (*c6_b_out)[c6_i864] = c6_out[c6_i864];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,5);
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c6_chartNumber, 0U, sf_debug_get_script_id(
    "C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/adjust_ang.m"));
  _SFD_SCRIPT_TRANSLATION(c6_chartNumber, 1U, sf_debug_get_script_id(
    "C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/DCM2Eul.m")
    );
}

static real_T c6_mpower(real_T c6_a)
{
  return c6_power(c6_a, 2.0);
}

static real_T c6_power(real_T c6_a, real_T c6_b)
{
  real_T c6_ak;
  real_T c6_bk;
  real_T c6_x;
  real_T c6_b_x;
  c6_eml_scalar_eg();
  c6_ak = c6_a;
  c6_bk = c6_b;
  if (c6_ak < 0.0) {
    c6_x = c6_bk;
    c6_b_x = c6_x;
    c6_b_x = muDoubleScalarFloor(c6_b_x);
    if (c6_b_x != c6_bk) {
      c6_eml_error();
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c6_ak, c6_bk);
}

static void c6_eml_scalar_eg(void)
{
}

static void c6_eml_error(void)
{
  int32_T c6_i865;
  static char_T c6_cv0[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ',', ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't',
    ' ', 'o', 'n', 'e', ' ',
    'i', 'n', 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ',', ' ',
    'e', '.', 'g', '.', ' ',
    '\'', 'p', 'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'a', ')', ',', 'b', ')',
    '\'', '.' };

  char_T c6_u[102];
  const mxArray *c6_y = NULL;
  int32_T c6_i866;
  static char_T c6_cv1[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':'
    , 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c6_b_u[32];
  const mxArray *c6_b_y = NULL;
  for (c6_i865 = 0; c6_i865 < 102; c6_i865 = c6_i865 + 1) {
    c6_u[c6_i865] = c6_cv0[c6_i865];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 10, 0U, 1U, 0U, 2, 1, 102));
  for (c6_i866 = 0; c6_i866 < 32; c6_i866 = c6_i866 + 1) {
    c6_b_u[c6_i866] = c6_cv1[c6_i866];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 10, 0U, 1U, 0U, 2, 1, 32));
  sf_mex_call_debug("error", 0U, 2U, 14, c6_b_y, 14, c6_y);
}

static real_T c6_sqrt(real_T c6_x)
{
  real_T c6_b_x;
  real_T c6_c_x;
  c6_b_x = c6_x;
  if (c6_b_x < 0.0) {
    c6_b_eml_error();
  }

  c6_c_x = c6_b_x;
  c6_b_x = c6_c_x;
  return muDoubleScalarSqrt(c6_b_x);
}

static void c6_b_eml_error(void)
{
  int32_T c6_i867;
  static char_T c6_cv2[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c6_u[77];
  const mxArray *c6_y = NULL;
  int32_T c6_i868;
  static char_T c6_cv3[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c6_b_u[31];
  const mxArray *c6_b_y = NULL;
  for (c6_i867 = 0; c6_i867 < 77; c6_i867 = c6_i867 + 1) {
    c6_u[c6_i867] = c6_cv2[c6_i867];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c6_i868 = 0; c6_i868 < 31; c6_i868 = c6_i868 + 1) {
    c6_b_u[c6_i868] = c6_cv3[c6_i868];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c6_b_y, 14, c6_y);
}

static void c6_adjust_ang(real_T c6_ang[6], real_T c6_b_ang[6])
{
  real_T c6_nargout = 1.0;
  real_T c6_nargin = 1.0;
  real_T c6_a;
  real_T c6_i;
  int32_T c6_i869;
  real_T c6_b_i;
  sf_debug_symbol_scope_push(6U, 0U);
  sf_debug_symbol_scope_add("nargout", &c6_nargout, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c6_nargin, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("a", &c6_a, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("i", &c6_i, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("ang", c6_b_ang, c6_e_sf_marshall);
  sf_debug_symbol_scope_add("ang", c6_ang, c6_e_sf_marshall);
  for (c6_i869 = 0; c6_i869 < 6; c6_i869 = c6_i869 + 1) {
    c6_b_ang[c6_i869] = c6_ang[c6_i869];
  }

  CV_SCRIPT_FCN(0, 0);
  c6_i = 1.0;
  c6_b_i = 1.0;
  while (c6_b_i <= 6.0) {
    c6_i = c6_b_i;
    CV_SCRIPT_FOR(0, 0, 1);
    _SFD_SCRIPT_CALL(0,4);
    c6_a = c6_b_ang[_SFD_EML_ARRAY_BOUNDS_CHECK("ang", (int32_T)
      _SFD_INTEGER_CHECK("i", c6_i), 1, 6, 1, 0) - 1];
    while (CV_SCRIPT_WHILE(0, 0, c6_a > 3.1415926535897931E+000)) {
      _SFD_SCRIPT_CALL(0,5);
      c6_a = c6_a - 6.2831853071795862E+000;
      sf_mex_listen_for_ctrl_c(chartInstance.S);
    }

    while (CV_SCRIPT_WHILE(0, 1, c6_a < -3.1415926535897931E+000)) {
      _SFD_SCRIPT_CALL(0,6);
      c6_a = c6_a + 6.2831853071795862E+000;
      sf_mex_listen_for_ctrl_c(chartInstance.S);
    }

    _SFD_SCRIPT_CALL(0,7);
    c6_b_ang[_SFD_EML_ARRAY_BOUNDS_CHECK("ang", (int32_T)_SFD_INTEGER_CHECK("i",
      c6_i), 1, 6, 1, 0) - 1] = c6_a;
    c6_b_i = c6_b_i + 1.0;
    sf_mex_listen_for_ctrl_c(chartInstance.S);
  }

  CV_SCRIPT_FOR(0, 0, 0);
  _SFD_SCRIPT_CALL(0,-7);
  sf_debug_symbol_scope_pop();
}

static void c6_b_eml_scalar_eg(void)
{
}

static void c6_c_eml_scalar_eg(void)
{
}

static void c6_d_eml_scalar_eg(void)
{
}

static void c6_DCM2Eul(real_T c6_D[9], real_T c6_ang[3])
{
  real_T c6_nargout = 1.0;
  real_T c6_nargin = 1.0;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_d0;
  real_T c6_d1;
  sf_debug_symbol_scope_push(4U, 0U);
  sf_debug_symbol_scope_add("nargout", &c6_nargout, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c6_nargin, c6_c_sf_marshall);
  sf_debug_symbol_scope_add("ang", c6_ang, c6_d_sf_marshall);
  sf_debug_symbol_scope_add("D", c6_D, c6_h_sf_marshall);
  CV_SCRIPT_FCN(1, 0);

  /*  DCM to Euler angles */
  _SFD_SCRIPT_CALL(1,4);
  c6_x = c6_D[6];
  c6_b_x = c6_x;
  if (c6_b_x < -1.0) {
  } else if (1.0 < c6_b_x) {
  } else {
    goto label_1;
  }

  c6_c_eml_error();
 label_1:
  ;
  c6_c_x = c6_b_x;
  c6_b_x = c6_c_x;
  c6_b_x = muDoubleScalarAsin(c6_b_x);
  c6_d0 = c6_atan2(c6_D[7], c6_D[8]);
  c6_d1 = c6_atan2(c6_D[3], c6_D[0]);
  c6_ang[0] = c6_d0;
  c6_ang[1] = -c6_b_x;
  c6_ang[2] = c6_d1;
  _SFD_SCRIPT_CALL(1,-4);
  sf_debug_symbol_scope_pop();
}

static real_T c6_atan2(real_T c6_y, real_T c6_x)
{
  real_T c6_b_y;
  real_T c6_b_x;
  c6_eml_scalar_eg();
  c6_b_y = c6_y;
  c6_b_x = c6_x;
  return muDoubleScalarAtan2(c6_b_y, c6_b_x);
}

static void c6_c_eml_error(void)
{
  int32_T c6_i870;
  static char_T c6_cv4[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 'a', 's',
    'i', 'n', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c6_u[77];
  const mxArray *c6_y = NULL;
  int32_T c6_i871;
  static char_T c6_cv5[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'a', 's', 'i', 'n', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c6_b_u[31];
  const mxArray *c6_b_y = NULL;
  for (c6_i870 = 0; c6_i870 < 77; c6_i870 = c6_i870 + 1) {
    c6_u[c6_i870] = c6_cv4[c6_i870];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c6_i871 = 0; c6_i871 < 31; c6_i871 = c6_i871 + 1) {
    c6_b_u[c6_i871] = c6_cv5[c6_i871];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c6_b_y, 14, c6_y);
}

static void c6_e_eml_scalar_eg(void)
{
}

static void c6_eml_xgemm(real_T c6_A[9], real_T c6_B[3], real_T c6_C[3], real_T
  c6_b_C[3])
{
  int32_T c6_i872;
  real_T c6_b_A[9];
  int32_T c6_i873;
  real_T c6_b_B[3];
  int32_T c6_i874;
  real_T c6_c_A[9];
  int32_T c6_i875;
  real_T c6_c_B[3];
  int32_T c6_i876;
  int32_T c6_i877;
  int32_T c6_i878;
  for (c6_i872 = 0; c6_i872 < 9; c6_i872 = c6_i872 + 1) {
    c6_b_A[c6_i872] = c6_A[c6_i872];
  }

  for (c6_i873 = 0; c6_i873 < 3; c6_i873 = c6_i873 + 1) {
    c6_b_B[c6_i873] = c6_B[c6_i873];
  }

  for (c6_i874 = 0; c6_i874 < 9; c6_i874 = c6_i874 + 1) {
    c6_c_A[c6_i874] = c6_b_A[c6_i874];
  }

  for (c6_i875 = 0; c6_i875 < 3; c6_i875 = c6_i875 + 1) {
    c6_c_B[c6_i875] = c6_b_B[c6_i875];
  }

  for (c6_i876 = 0; c6_i876 < 3; c6_i876 = c6_i876 + 1) {
    c6_b_C[c6_i876] = 0.0;
    c6_i877 = 0;
    for (c6_i878 = 0; c6_i878 < 3; c6_i878 = c6_i878 + 1) {
      c6_b_C[c6_i876] = c6_b_C[c6_i876] + c6_c_A[c6_i877 + c6_i876] *
        c6_c_B[c6_i878];
      c6_i877 = c6_i877 + 3;
    }
  }
}

static void c6_f_eml_scalar_eg(void)
{
}

static void c6_inv(real_T c6_x[36], real_T c6_y[36])
{
  int32_T c6_i879;
  real_T c6_b_x[36];
  int32_T c6_i880;
  int32_T c6_i881;
  real_T c6_c_x[36];
  int32_T c6_ipiv[6];
  real_T c6_d_x[36];
  int32_T c6_i882;
  int32_T c6_i883;
  int32_T c6_b_ipiv[6];
  int32_T c6_i884;
  int32_T c6_c_ipiv[6];
  int32_T c6_i885;
  int32_T c6_p[6];
  real_T c6_k;
  real_T c6_b_k;
  int32_T c6_ipk;
  int32_T c6_pipk;
  int32_T c6_c_k;
  int32_T c6_d_k;
  int32_T c6_c;
  int32_T c6_e_k;
  int32_T c6_j;
  int32_T c6_b_j;
  int32_T c6_i886;
  int32_T c6_i887;
  int32_T c6_i888;
  int32_T c6_i889;
  int32_T c6_i;
  int32_T c6_b_i;
  real_T c6_a;
  real_T c6_b;
  real_T c6_b_y;
  int32_T c6_i890;
  real_T c6_A[36];
  int32_T c6_i891;
  real_T c6_B[36];
  int32_T c6_i892;
  int32_T c6_i893;
  real_T c6_b_A[36];
  int32_T c6_i894;
  real_T c6_c_y[36];
  int32_T c6_i895;
  real_T c6_e_x[36];
  int32_T c6_i896;
  real_T c6_xinv[36];
  int32_T c6_i897;
  real_T c6_f_x[36];
  real_T c6_n1x;
  int32_T c6_i898;
  real_T c6_b_xinv[36];
  real_T c6_n1xinv;
  real_T c6_b_a;
  real_T c6_b_b;
  real_T c6_d_y;
  real_T c6_rc;
  real_T c6_g_x;
  boolean_T c6_c_b;
  for (c6_i879 = 0; c6_i879 < 36; c6_i879 = c6_i879 + 1) {
    c6_b_x[c6_i879] = c6_x[c6_i879];
  }

  for (c6_i880 = 0; c6_i880 < 36; c6_i880 = c6_i880 + 1) {
    c6_y[c6_i880] = 0.0;
  }

  for (c6_i881 = 0; c6_i881 < 36; c6_i881 = c6_i881 + 1) {
    c6_c_x[c6_i881] = c6_b_x[c6_i881];
  }

  c6_eml_xgetrf(c6_c_x, c6_d_x, c6_ipiv);
  for (c6_i882 = 0; c6_i882 < 36; c6_i882 = c6_i882 + 1) {
    c6_b_x[c6_i882] = c6_d_x[c6_i882];
  }

  for (c6_i883 = 0; c6_i883 < 6; c6_i883 = c6_i883 + 1) {
    c6_b_ipiv[c6_i883] = c6_ipiv[c6_i883];
  }

  for (c6_i884 = 0; c6_i884 < 6; c6_i884 = c6_i884 + 1) {
    c6_c_ipiv[c6_i884] = c6_b_ipiv[c6_i884];
  }

  for (c6_i885 = 0; c6_i885 < 6; c6_i885 = c6_i885 + 1) {
    c6_p[c6_i885] = 1 + c6_i885;
  }

  for (c6_k = 1.0; c6_k <= 6.0; c6_k = c6_k + 1.0) {
    c6_b_k = c6_k;
    c6_ipk = c6_c_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("ipiv", (int32_T)
      _SFD_INTEGER_CHECK("k", c6_b_k), 1, 6, 1, 0) - 1];
    if ((real_T)c6_ipk > c6_b_k) {
      c6_pipk = c6_p[_SFD_EML_ARRAY_BOUNDS_CHECK("perm", (int32_T)
        _SFD_INTEGER_CHECK("ipk", (real_T)c6_ipk), 1, 6, 1, 0) - 1];
      c6_p[_SFD_EML_ARRAY_BOUNDS_CHECK("perm", (int32_T)_SFD_INTEGER_CHECK("ipk",
                                        (real_T)c6_ipk), 1, 6, 1, 0) - 1] =
        c6_p[
        _SFD_EML_ARRAY_BOUNDS_CHECK("perm", (int32_T)_SFD_INTEGER_CHECK("k",
        c6_b_k), 1, 6, 1, 0) - 1];
      c6_p[_SFD_EML_ARRAY_BOUNDS_CHECK("perm", (int32_T)_SFD_INTEGER_CHECK("k",
        c6_b_k), 1, 6, 1, 0) - 1] = c6_pipk;
    }
  }

  for (c6_c_k = 1; c6_c_k < 7; c6_c_k = c6_c_k + 1) {
    c6_d_k = c6_c_k;
    c6_c = c6_p[_SFD_EML_ARRAY_BOUNDS_CHECK("p", (int32_T)_SFD_INTEGER_CHECK("k",
      (real_T)c6_d_k), 1, 6, 1, 0) - 1];
    c6_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("k",
            (real_T)c6_d_k), 1, 6, 1, 0) - 1) + 6 * (
      _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("c", (real_T)
      c6_c), 1, 6, 2, 0) - 1)] = 1.0;
    c6_e_k = c6_d_k;
    for (c6_j = c6_e_k; c6_j < 7; c6_j = c6_j + 1) {
      c6_b_j = c6_j;
      if (c6_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("j",
             (real_T)c6_b_j), 1, 6, 1, 0) - 1) + 6 * (
           _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("c",
             (real_T)c6_c), 1, 6, 2, 0) - 1)] != 0.0) {
        c6_i886 = c6_b_j;
        c6_i887 = 1;
        c6_i888 = c6_i886 + c6_i887;
        if ((c6_i886 < 0) && (c6_i887 < 0) && (c6_i888 >= 0)) {
          c6_i888 = MIN_int32_T;
        } else {
          if ((c6_i886 > 0) && (c6_i887 > 0) && (c6_i888 <= 0)) {
            c6_i888 = MAX_int32_T;
          }
        }

        c6_i889 = c6_i888;
        for (c6_i = c6_i889; c6_i < 7; c6_i = c6_i + 1) {
          c6_b_i = c6_i;
          c6_a = c6_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
            _SFD_INTEGER_CHECK("j", (real_T)c6_b_j), 1, 6, 1, 0) - 1) + 6 * (
            _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("c",
            (real_T)c6_c), 1, 6, 2, 0) - 1)];
          c6_b = c6_b_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
            _SFD_INTEGER_CHECK("i", (real_T)c6_b_i), 1, 6, 1, 0) - 1) + 6 * (
            _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("j",
            (real_T)c6_b_j), 1, 6, 2, 0) - 1)];
          c6_b_y = c6_a * c6_b;
          c6_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("i",
                  (real_T)c6_b_i), 1, 6, 1, 0) - 1) + 6 * (
            _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("c",
            (real_T)c6_c), 1, 6, 2, 0) - 1)] = c6_y[(
            _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("i",
            (real_T)c6_b_i), 1, 6, 1, 0) - 1) + 6 * (
            _SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("c",
            (real_T)c6_c), 1, 6, 2, 0) - 1)] - c6_b_y;
        }
      }
    }
  }

  for (c6_i890 = 0; c6_i890 < 36; c6_i890 = c6_i890 + 1) {
    c6_A[c6_i890] = c6_b_x[c6_i890];
  }

  for (c6_i891 = 0; c6_i891 < 36; c6_i891 = c6_i891 + 1) {
    c6_B[c6_i891] = c6_y[c6_i891];
  }

  for (c6_i892 = 0; c6_i892 < 36; c6_i892 = c6_i892 + 1) {
    c6_y[c6_i892] = c6_B[c6_i892];
  }

  for (c6_i893 = 0; c6_i893 < 36; c6_i893 = c6_i893 + 1) {
    c6_b_A[c6_i893] = c6_A[c6_i893];
  }

  for (c6_i894 = 0; c6_i894 < 36; c6_i894 = c6_i894 + 1) {
    c6_c_y[c6_i894] = c6_y[c6_i894];
  }

  c6_eml_blas_xtrsm(6, 6, 1.0, c6_b_A, 1, 6, c6_c_y, 1, 6, c6_y);
  for (c6_i895 = 0; c6_i895 < 36; c6_i895 = c6_i895 + 1) {
    c6_e_x[c6_i895] = c6_x[c6_i895];
  }

  for (c6_i896 = 0; c6_i896 < 36; c6_i896 = c6_i896 + 1) {
    c6_xinv[c6_i896] = c6_y[c6_i896];
  }

  for (c6_i897 = 0; c6_i897 < 36; c6_i897 = c6_i897 + 1) {
    c6_f_x[c6_i897] = c6_e_x[c6_i897];
  }

  c6_n1x = c6_norm(c6_f_x);
  for (c6_i898 = 0; c6_i898 < 36; c6_i898 = c6_i898 + 1) {
    c6_b_xinv[c6_i898] = c6_xinv[c6_i898];
  }

  c6_n1xinv = c6_norm(c6_b_xinv);
  c6_b_a = c6_n1x;
  c6_b_b = c6_n1xinv;
  c6_d_y = c6_b_a * c6_b_b;
  c6_rc = 1.0 / c6_d_y;
  if (c6_n1x == 0.0) {
  } else if (c6_n1xinv == 0.0) {
  } else if (c6_rc == 0.0) {
    goto label_1;
  } else {
    c6_g_x = c6_rc;
    c6_c_b = rtIsNaN(c6_g_x);
    if (c6_c_b) {
    } else if (c6_rc < 2.2204460492503131E-016) {
    } else {
      return;
    }

    c6_b_eml_warning(c6_rc);
    return;
  }

 label_1:
  ;
  c6_eml_warning();
}

static void c6_eml_xgetrf(real_T c6_A[36], real_T c6_b_A[36], int32_T c6_ipiv[6])
{
  int32_T c6_i899;
  int32_T c6_i900;
  int32_T c6_j;
  int32_T c6_b_j;
  int32_T c6_a;
  int32_T c6_jm1;
  int32_T c6_b;
  int32_T c6_mmj;
  int32_T c6_b_a;
  int32_T c6_b_b;
  int32_T c6_jj;
  int32_T c6_c_a;
  int32_T c6_jp1j;
  int32_T c6_d_a;
  int32_T c6_c;
  int32_T c6_i901;
  real_T c6_c_A[36];
  int32_T c6_e_a;
  int32_T c6_jpiv_offset;
  int32_T c6_f_a;
  int32_T c6_c_b;
  int32_T c6_jpiv;
  int32_T c6_g_a;
  int32_T c6_d_b;
  int32_T c6_b_c;
  int32_T c6_e_b;
  int32_T c6_jrow;
  int32_T c6_h_a;
  int32_T c6_f_b;
  int32_T c6_jprow;
  int32_T c6_i902;
  real_T c6_x[36];
  int32_T c6_ix0;
  int32_T c6_iy0;
  int32_T c6_i903;
  int32_T c6_i904;
  real_T c6_b_x[36];
  int32_T c6_b_ix0;
  int32_T c6_b_iy0;
  int32_T c6_i905;
  real_T c6_c_x[36];
  int32_T c6_i906;
  real_T c6_d_x[36];
  real_T c6_e_x[36];
  int32_T c6_i907;
  int32_T c6_i908;
  int32_T c6_b_jp1j;
  int32_T c6_i_a;
  int32_T c6_j_a;
  int32_T c6_g_b;
  int32_T c6_loop_ub;
  int32_T c6_i;
  int32_T c6_b_i;
  real_T c6_f_x;
  real_T c6_y;
  real_T c6_g_x;
  real_T c6_b_y;
  real_T c6_z;
  int32_T c6_m;
  int32_T c6_h_b;
  int32_T c6_n;
  int32_T c6_c_ix0;
  int32_T c6_k_a;
  int32_T c6_c_iy0;
  int32_T c6_i909;
  real_T c6_d_A[36];
  int32_T c6_l_a;
  int32_T c6_ia0;
  int32_T c6_i910;
  int32_T c6_b_m;
  int32_T c6_b_n;
  int32_T c6_d_ix0;
  int32_T c6_d_iy0;
  int32_T c6_i911;
  real_T c6_e_A[36];
  int32_T c6_b_ia0;
  int32_T c6_i912;
  int32_T c6_c_m;
  int32_T c6_c_n;
  int32_T c6_e_ix0;
  int32_T c6_e_iy0;
  int32_T c6_i913;
  real_T c6_f_A[36];
  int32_T c6_c_ia0;
  int32_T c6_i914;
  int32_T c6_i915;
  real_T c6_g_A[36];
  for (c6_i899 = 0; c6_i899 < 36; c6_i899 = c6_i899 + 1) {
    c6_b_A[c6_i899] = c6_A[c6_i899];
  }

  for (c6_i900 = 0; c6_i900 < 6; c6_i900 = c6_i900 + 1) {
    c6_ipiv[c6_i900] = 1 + c6_i900;
  }

  for (c6_j = 1; c6_j < 6; c6_j = c6_j + 1) {
    c6_b_j = c6_j;
    c6_a = c6_b_j;
    c6_jm1 = c6_a - 1;
    c6_b = c6_b_j;
    c6_mmj = 6 - c6_b;
    c6_b_a = c6_jm1;
    c6_b_b = c6_b_a * 7;
    c6_jj = 1 + c6_b_b;
    c6_c_a = c6_jj;
    c6_jp1j = c6_c_a + 1;
    c6_d_a = c6_mmj;
    c6_c = c6_d_a + 1;
    for (c6_i901 = 0; c6_i901 < 36; c6_i901 = c6_i901 + 1) {
      c6_c_A[c6_i901] = c6_b_A[c6_i901];
    }

    c6_e_a = c6_eml_ixamax(c6_c, c6_c_A, c6_jj);
    c6_jpiv_offset = c6_e_a - 1;
    c6_f_a = c6_jj;
    c6_c_b = c6_jpiv_offset;
    c6_jpiv = c6_f_a + c6_c_b;
    if (c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK(
          "jpiv", (real_T)c6_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if ((real_T)c6_jpiv_offset != 0.0) {
        c6_g_a = c6_b_j;
        c6_d_b = c6_jpiv_offset;
        c6_b_c = c6_g_a + c6_d_b;
        c6_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("ipiv", (int32_T)_SFD_INTEGER_CHECK(
          "j", (real_T)c6_b_j), 1, 6, 1, 0) - 1] = c6_b_c;
        c6_e_b = c6_jm1;
        c6_jrow = 1 + c6_e_b;
        c6_h_a = c6_jrow;
        c6_f_b = c6_jpiv_offset;
        c6_jprow = c6_h_a + c6_f_b;
        for (c6_i902 = 0; c6_i902 < 36; c6_i902 = c6_i902 + 1) {
          c6_x[c6_i902] = c6_b_A[c6_i902];
        }

        c6_ix0 = c6_jrow;
        c6_iy0 = c6_jprow;
        for (c6_i903 = 0; c6_i903 < 36; c6_i903 = c6_i903 + 1) {
          c6_b_A[c6_i903] = c6_x[c6_i903];
        }

        for (c6_i904 = 0; c6_i904 < 36; c6_i904 = c6_i904 + 1) {
          c6_b_x[c6_i904] = c6_b_A[c6_i904];
        }

        c6_b_ix0 = c6_ix0;
        c6_b_iy0 = c6_iy0;
        for (c6_i905 = 0; c6_i905 < 36; c6_i905 = c6_i905 + 1) {
          c6_c_x[c6_i905] = c6_b_x[c6_i905];
        }

        for (c6_i906 = 0; c6_i906 < 36; c6_i906 = c6_i906 + 1) {
          c6_d_x[c6_i906] = c6_c_x[c6_i906];
        }

        /* Empty Loop. */
        c6_ceval_xswap(6, c6_d_x, c6_b_ix0, 6, c6_b_iy0, 6, c6_e_x);
        for (c6_i907 = 0; c6_i907 < 36; c6_i907 = c6_i907 + 1) {
          c6_c_x[c6_i907] = c6_e_x[c6_i907];
        }

        for (c6_i908 = 0; c6_i908 < 36; c6_i908 = c6_i908 + 1) {
          c6_b_A[c6_i908] = c6_c_x[c6_i908];
        }
      }

      c6_b_jp1j = c6_jp1j;
      c6_i_a = c6_jp1j;
      c6_j_a = c6_mmj;
      c6_g_b = c6_j_a - 1;
      c6_loop_ub = c6_i_a + c6_g_b;
      for (c6_i = c6_b_jp1j; c6_i <= c6_loop_ub; c6_i = c6_i + 1) {
        c6_b_i = c6_i;
        c6_f_x = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
          _SFD_INTEGER_CHECK("i", (real_T)c6_b_i), 1, 36, 1, 0) - 1];
        c6_y = c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
          _SFD_INTEGER_CHECK("jj", (real_T)c6_jj), 1, 36, 1, 0) - 1];
        c6_g_x = c6_f_x;
        c6_b_y = c6_y;
        c6_z = c6_g_x / c6_b_y;
        c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("i",
          (real_T)c6_b_i), 1, 36, 1, 0) - 1] = c6_z;
      }
    }

    c6_m = c6_mmj;
    c6_h_b = c6_b_j;
    c6_n = 6 - c6_h_b;
    c6_c_ix0 = c6_jp1j;
    c6_k_a = c6_jj;
    c6_c_iy0 = c6_k_a + 6;
    for (c6_i909 = 0; c6_i909 < 36; c6_i909 = c6_i909 + 1) {
      c6_d_A[c6_i909] = c6_b_A[c6_i909];
    }

    c6_l_a = c6_jj;
    c6_ia0 = c6_l_a + 7;
    for (c6_i910 = 0; c6_i910 < 36; c6_i910 = c6_i910 + 1) {
      c6_b_A[c6_i910] = c6_d_A[c6_i910];
    }

    c6_b_m = c6_m;
    c6_b_n = c6_n;
    c6_d_ix0 = c6_c_ix0;
    c6_d_iy0 = c6_c_iy0;
    for (c6_i911 = 0; c6_i911 < 36; c6_i911 = c6_i911 + 1) {
      c6_e_A[c6_i911] = c6_b_A[c6_i911];
    }

    c6_b_ia0 = c6_ia0;
    for (c6_i912 = 0; c6_i912 < 36; c6_i912 = c6_i912 + 1) {
      c6_b_A[c6_i912] = c6_e_A[c6_i912];
    }

    c6_c_m = c6_b_m;
    c6_c_n = c6_b_n;
    c6_e_ix0 = c6_d_ix0;
    c6_e_iy0 = c6_d_iy0;
    for (c6_i913 = 0; c6_i913 < 36; c6_i913 = c6_i913 + 1) {
      c6_f_A[c6_i913] = c6_b_A[c6_i913];
    }

    c6_c_ia0 = c6_b_ia0;
    for (c6_i914 = 0; c6_i914 < 36; c6_i914 = c6_i914 + 1) {
      c6_b_A[c6_i914] = c6_f_A[c6_i914];
    }

    if ((real_T)c6_c_m < 1.0) {
    } else if ((real_T)c6_c_n < 1.0) {
    } else {
      for (c6_i915 = 0; c6_i915 < 36; c6_i915 = c6_i915 + 1) {
        c6_g_A[c6_i915] = c6_b_A[c6_i915];
      }

      c6_ceval_xger(c6_c_m, c6_c_n, -1.0, c6_e_ix0, 1, c6_e_iy0, 6, c6_g_A,
                    c6_c_ia0, 6, c6_b_A);
      goto label_1;
    }

   label_1:
    ;
  }
}

static int32_T c6_eml_ixamax(int32_T c6_n, real_T c6_x[36], int32_T c6_ix0)
{
  int32_T c6_b_n;
  int32_T c6_i916;
  real_T c6_b_x[36];
  int32_T c6_b_ix0;
  int32_T c6_i917;
  real_T c6_c_x[36];
  c6_b_n = c6_n;
  for (c6_i916 = 0; c6_i916 < 36; c6_i916 = c6_i916 + 1) {
    c6_b_x[c6_i916] = c6_x[c6_i916];
  }

  c6_b_ix0 = c6_ix0;
  for (c6_i917 = 0; c6_i917 < 36; c6_i917 = c6_i917 + 1) {
    c6_c_x[c6_i917] = c6_b_x[c6_i917];
  }

  return c6_ceval_ixamax(c6_b_n, c6_c_x, c6_b_ix0, 1);
}

static int32_T c6_ceval_ixamax(int32_T c6_n, real_T c6_x[36], int32_T c6_ix0,
  int32_T c6_incx)
{
  return idamax32(&c6_n, &c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
    _SFD_INTEGER_CHECK("ix0", (real_T)c6_ix0), 1, 36, 1, 0) - 1]
                  , &c6_incx);
}

static void c6_ceval_xswap(int32_T c6_n, real_T c6_x[36], int32_T c6_ix0,
  int32_T c6_incx, int32_T c6_iy0, int32_T c6_incy, real_T
  c6_b_x[36])
{
  int32_T c6_i918;

  /* Empty Loop. */
  for (c6_i918 = 0; c6_i918 < 36; c6_i918 = c6_i918 + 1) {
    c6_b_x[c6_i918] = c6_x[c6_i918];
  }

  dswap32(&c6_n, &c6_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
           _SFD_INTEGER_CHECK("ix0", (real_T)c6_ix0), 1, 36, 1, 0) - 1], &
          c6_incx, &c6_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
           _SFD_INTEGER_CHECK("iy0", (real_T)c6_iy0), 1, 36, 1, 0) - 1],
          &c6_incy);
}

static void c6_ceval_xger(int32_T c6_m, int32_T c6_n, real_T c6_alpha1, int32_T
  c6_ix0, int32_T c6_incx, int32_T c6_iy0, int32_T
  c6_incy, real_T c6_A[36], int32_T c6_ia0, int32_T c6_lda, real_T c6_b_A[36])
{
  int32_T c6_i919;
  for (c6_i919 = 0; c6_i919 < 36; c6_i919 = c6_i919 + 1) {
    c6_b_A[c6_i919] = c6_A[c6_i919];
  }

  dger32(&c6_m, &c6_n, &c6_alpha1, &c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A",
          (int32_T)_SFD_INTEGER_CHECK("ix0", (real_T)c6_ix0), 1, 36
          , 1, 0) - 1], &c6_incx, &c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A",
          (int32_T)_SFD_INTEGER_CHECK("iy0", (real_T)c6_iy0), 1, 36, 1, 0) -
         1], &c6_incy, &c6_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
          _SFD_INTEGER_CHECK("ia0", (real_T)c6_ia0), 1, 36, 1, 0) - 1], &
         c6_lda);
}

static void c6_eml_blas_xtrsm(int32_T c6_m, int32_T c6_n, real_T c6_alpha1,
  real_T c6_A[36], int32_T c6_ia0, int32_T c6_lda, real_T
  c6_B[36], int32_T c6_ib0, int32_T c6_ldb, real_T c6_b_B[36])
{
  int32_T c6_i920;
  int32_T c6_i921;
  real_T c6_b_A[36];
  int32_T c6_i922;
  real_T c6_c_B[36];
  for (c6_i920 = 0; c6_i920 < 36; c6_i920 = c6_i920 + 1) {
    c6_b_B[c6_i920] = c6_B[c6_i920];
  }

  for (c6_i921 = 0; c6_i921 < 36; c6_i921 = c6_i921 + 1) {
    c6_b_A[c6_i921] = c6_A[c6_i921];
  }

  for (c6_i922 = 0; c6_i922 < 36; c6_i922 = c6_i922 + 1) {
    c6_c_B[c6_i922] = c6_b_B[c6_i922];
  }

  c6_ceval_xtrsm(c6_m, c6_n, c6_alpha1, c6_b_A, c6_ia0, c6_lda, c6_c_B, c6_ib0,
                 c6_ldb, c6_b_B);
}

static void c6_ceval_xtrsm(int32_T c6_m, int32_T c6_n, real_T c6_alpha1, real_T
  c6_A[36], int32_T c6_ia0, int32_T c6_lda, real_T
  c6_B[36], int32_T c6_ib0, int32_T c6_ldb, real_T c6_b_B[36])
{
  char_T c6_SIDE;
  char_T c6_UPLO;
  char_T c6_TRANSA;
  char_T c6_DIAGA;
  int32_T c6_i923;
  c6_SIDE = 'L';
  c6_UPLO = 'U';
  c6_TRANSA = 'N';
  c6_DIAGA = 'N';
  for (c6_i923 = 0; c6_i923 < 36; c6_i923 = c6_i923 + 1) {
    c6_b_B[c6_i923] = c6_B[c6_i923];
  }

  dtrsm32(&c6_SIDE, &c6_UPLO, &c6_TRANSA, &c6_DIAGA, &c6_m, &c6_n, &c6_alpha1,
          &c6_A[_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
           _SFD_INTEGER_CHECK("ia0", (real_T)c6_ia0), 1, 36, 1, 0) - 1], &c6_lda,
          &c6_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)
           _SFD_INTEGER_CHECK("ib0", (real_T)c6_ib0), 1, 36, 1, 0) - 1], &c6_ldb);
}

static real_T c6_norm(real_T c6_x[36])
{
  real_T c6_y;
  int32_T c6_i924;
  real_T c6_b_x[36];
  real_T c6_j;
  real_T c6_b_j;
  real_T c6_s;
  real_T c6_i;
  real_T c6_b_i;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_b_y;
  real_T c6_e_x;
  boolean_T c6_b;
  for (c6_i924 = 0; c6_i924 < 36; c6_i924 = c6_i924 + 1) {
    c6_b_x[c6_i924] = c6_x[c6_i924];
  }

  c6_y = 0.0;
  c6_j = 1.0;
 label_1:
  ;
  if (c6_j <= 6.0) {
    c6_b_j = c6_j;
    c6_s = 0.0;
    for (c6_i = 1.0; c6_i <= 6.0; c6_i = c6_i + 1.0) {
      c6_b_i = c6_i;
      c6_c_x = c6_b_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("i", c6_b_i), 1, 6, 1, 0) - 1) + 6 * (
        _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("j", c6_b_j),
        1, 6, 2, 0) - 1)];
      c6_d_x = c6_c_x;
      c6_b_y = muDoubleScalarAbs(c6_d_x);
      c6_s = c6_s + c6_b_y;
    }

    c6_e_x = c6_s;
    c6_b = rtIsNaN(c6_e_x);
    if (c6_b) {
      return rtNaN;
    } else {
      if (c6_s > c6_y) {
        c6_y = c6_s;
      }

      c6_j = c6_j + 1.0;
      goto label_1;
    }
  }

  return c6_y;
}

static void c6_eml_warning(void)
{
  int32_T c6_i925;
  static char_T c6_cv6[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't', 'o'
    , ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i', 's',
    'i', 'o', 'n', '.' };

  char_T c6_u[40];
  const mxArray *c6_y = NULL;
  int32_T c6_i926;
  static char_T c6_cv7[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x'
  };

  char_T c6_b_u[21];
  const mxArray *c6_b_y = NULL;
  for (c6_i925 = 0; c6_i925 < 40; c6_i925 = c6_i925 + 1) {
    c6_u[c6_i925] = c6_cv6[c6_i925];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 10, 0U, 1U, 0U, 2, 1, 40));
  for (c6_i926 = 0; c6_i926 < 21; c6_i926 = c6_i926 + 1) {
    c6_b_u[c6_i926] = c6_cv7[c6_i926];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 10, 0U, 1U, 0U, 2, 1, 21));
  sf_mex_call_debug("warning", 0U, 2U, 14, c6_b_y, 14, c6_y);
}

static void c6_b_eml_warning(real_T c6_varargin_3)
{
  real_T c6_u;
  const mxArray *c6_y = NULL;
  int32_T c6_i927;
  static char_T c6_cv8[103] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ',', ' ',
    'c', 'l', 'o', 's', 'e', ' ', 't', 'o', ' ', 's', 'i', 'n', 'g', 'u', 'l',
    'a', 'r', ' ', 'o', 'r',
    ' ', 'b', 'a', 'd', 'l', 'y', ' ', 's', 'c', 'a', 'l', 'e', 'd', '.', '\\',
    'n', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', 'R', 'e', 's', 'u', 'l', 't', 's', ' ', 'm', 'a',
    'y', ' ', 'b', 'e', ' ',
    'i', 'n', 'a', 'c', 'c', 'u', 'r', 'a', 't', 'e', '.', ' ', 'R', 'C', 'O',
    'N', 'D', ' ', '=', ' ',
    '%', 'e', '.' };

  char_T c6_b_u[103];
  const mxArray *c6_b_y = NULL;
  int32_T c6_i928;
  static char_T c6_cv9[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'l', 'l',
    'C', 'o', 'n', 'd', 'i', 't', 'i', 'o', 'n', 'e', 'd'
    , 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c6_c_u[27];
  const mxArray *c6_c_y = NULL;
  c6_u = c6_varargin_3;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0));
  for (c6_i927 = 0; c6_i927 < 103; c6_i927 = c6_i927 + 1) {
    c6_b_u[c6_i927] = c6_cv8[c6_i927];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 10, 0U, 1U, 0U, 2, 1, 103));
  for (c6_i928 = 0; c6_i928 < 27; c6_i928 = c6_i928 + 1) {
    c6_c_u[c6_i928] = c6_cv9[c6_i928];
  }

  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_c_u, 10, 0U, 1U, 0U, 2, 1, 27));
  sf_mex_call_debug("warning", 0U, 3U, 14, c6_c_y, 14, c6_b_y, 14, c6_y);
}

static void c6_g_eml_scalar_eg(void)
{
}

static real_T c6_b_norm(real_T c6_x[6])
{
  int32_T c6_i929;
  real_T c6_b_x[6];
  for (c6_i929 = 0; c6_i929 < 6; c6_i929 = c6_i929 + 1) {
    c6_b_x[c6_i929] = c6_x[c6_i929];
  }

  return c6_genpnorm(c6_b_x, 2.0);
}

static real_T c6_genpnorm(real_T c6_x[6], real_T c6_p)
{
  real_T c6_y;
  int32_T c6_i930;
  real_T c6_b_x[6];
  real_T c6_k;
  real_T c6_b_k;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_absx;
  real_T c6_e_x;
  boolean_T c6_b;
  real_T c6_c_k;
  real_T c6_f_x;
  real_T c6_g_x;
  real_T c6_b_y;
  real_T c6_d_k;
  real_T c6_h_x;
  real_T c6_i_x;
  real_T c6_j_x;
  boolean_T c6_b_b;
  int32_T c6_i931;
  real_T c6_k_x[6];
  real_T c6_b_p;
  real_T c6_scale;
  real_T c6_e_k;
  real_T c6_f_k;
  real_T c6_l_x;
  real_T c6_m_x;
  real_T c6_b_absx;
  real_T c6_n_x;
  boolean_T c6_c_b;
  real_T c6_o_x;
  boolean_T c6_d_b;
  real_T c6_d2;
  real_T c6_j;
  real_T c6_b_j;
  real_T c6_p_x;
  boolean_T c6_e_b;
  real_T c6_a;
  real_T c6_f_b;
  real_T c6_c_y;
  real_T c6_q_x;
  boolean_T c6_g_b;
  real_T c6_b_a;
  real_T c6_h_b;
  int32_T c6_i932;
  real_T c6_r_x[6];
  real_T c6_c_p;
  real_T c6_b_scale;
  real_T c6_g_k;
  real_T c6_h_k;
  real_T c6_s_x;
  real_T c6_t_x;
  real_T c6_c_absx;
  real_T c6_u_x;
  boolean_T c6_i_b;
  real_T c6_d3;
  real_T c6_c_j;
  real_T c6_d_j;
  real_T c6_v_x;
  boolean_T c6_j_b;
  real_T c6_c_a;
  real_T c6_k_b;
  real_T c6_d_y;
  real_T c6_w_x;
  boolean_T c6_l_b;
  real_T c6_x_x;
  boolean_T c6_m_b;
  real_T c6_d_a;
  real_T c6_e_a;
  real_T c6_n_b;
  real_T c6_o_b;
  if (c6_p == 2.0) {
    for (c6_i930 = 0; c6_i930 < 6; c6_i930 = c6_i930 + 1) {
      c6_b_x[c6_i930] = c6_x[c6_i930];
    }

    return c6_eml_xnrm2(c6_b_x);
  } else if (c6_p == rtInf) {
    c6_y = 0.0;
    c6_k = 1.0;
   label_1:
    ;
    if (c6_k <= 6.0) {
      c6_b_k = c6_k;
      c6_c_x = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK
        ("k", c6_b_k), 1, 6, 1, 0) - 1];
      c6_d_x = c6_c_x;
      c6_absx = muDoubleScalarAbs(c6_d_x);
      c6_e_x = c6_absx;
      c6_b = rtIsNaN(c6_e_x);
      if (c6_b) {
        return rtNaN;
      } else {
        if (c6_absx > c6_y) {
          c6_y = c6_absx;
        }

        c6_k = c6_k + 1.0;
        goto label_1;
      }
    }
  } else if (c6_p == 1.0) {
    c6_y = 0.0;
    for (c6_c_k = 1.0; c6_c_k <= 6.0; c6_c_k = c6_c_k + 1.0) {
      c6_b_k = c6_c_k;
      c6_f_x = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK
        ("k", c6_b_k), 1, 6, 1, 0) - 1];
      c6_g_x = c6_f_x;
      c6_b_y = muDoubleScalarAbs(c6_g_x);
      c6_y = c6_y + c6_b_y;
    }
  } else if (c6_p == rtMinusInf) {
    c6_y = rtInf;
    c6_d_k = 1.0;
   label_2:
    ;
    if (c6_d_k <= 6.0) {
      c6_b_k = c6_d_k;
      c6_h_x = c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK
        ("k", c6_b_k), 1, 6, 1, 0) - 1];
      c6_i_x = c6_h_x;
      c6_absx = muDoubleScalarAbs(c6_i_x);
      c6_j_x = c6_absx;
      c6_b_b = rtIsNaN(c6_j_x);
      if (c6_b_b) {
        return rtNaN;
      } else {
        if (c6_absx < c6_y) {
          c6_y = c6_absx;
        }

        c6_d_k = c6_d_k + 1.0;
        goto label_2;
      }
    }
  } else if (c6_p > 0.0) {
    for (c6_i931 = 0; c6_i931 < 6; c6_i931 = c6_i931 + 1) {
      c6_k_x[c6_i931] = c6_x[c6_i931];
    }

    c6_b_p = c6_p;
    c6_y = 0.0;
    c6_scale = 0.0;
    c6_e_k = 1.0;
   label_3:
    ;
    if (c6_e_k <= 6.0) {
      c6_f_k = c6_e_k;
      c6_l_x = c6_k_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c6_f_k), 1, 6, 1, 0) - 1];
      c6_m_x = c6_l_x;
      c6_b_absx = muDoubleScalarAbs(c6_m_x);
      c6_n_x = c6_b_absx;
      c6_c_b = rtIsNaN(c6_n_x);
      if (c6_c_b) {
        return rtNaN;
      } else {
        c6_o_x = c6_b_absx;
        c6_d_b = rtIsInf(c6_o_x);
        if (c6_d_b) {
          c6_y = rtInf;
          c6_d2 = c6_f_k + 1.0;
          c6_j = c6_d2;
        } else {
          if (c6_b_absx > 0.0) {
            if (c6_scale < c6_b_absx) {
              c6_a = c6_y;
              c6_f_b = c6_power(c6_scale / c6_b_absx, c6_b_p);
              c6_c_y = c6_a * c6_f_b;
              c6_y = 1.0 + c6_c_y;
              c6_scale = c6_b_absx;
            } else {
              c6_y = c6_y + c6_power(c6_b_absx / c6_scale, c6_b_p);
            }
          }

          c6_e_k = c6_e_k + 1.0;
          goto label_3;
        }
      }
    } else {
      if (c6_y > 0.0) {
        c6_q_x = c6_y;
        c6_g_b = rtIsInf(c6_q_x);
        if (!c6_g_b) {
          c6_b_a = c6_scale;
          c6_h_b = c6_power(c6_y, 1.0 / c6_b_p);
          return c6_b_a * c6_h_b;
        }
      }

      return c6_y;
    }

   label_4:
    ;
    if (c6_j <= 6.0) {
      c6_b_j = c6_j;
      c6_p_x = c6_k_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("j", c6_b_j), 1, 6, 1, 0) - 1];
      c6_e_b = rtIsNaN(c6_p_x);
      if (c6_e_b) {
        return rtNaN;
      } else {
        c6_j = c6_j + 1.0;
        goto label_4;
      }
    }
  } else if (c6_p < 0.0) {
    for (c6_i932 = 0; c6_i932 < 6; c6_i932 = c6_i932 + 1) {
      c6_r_x[c6_i932] = c6_x[c6_i932];
    }

    c6_c_p = c6_p;
    c6_y = 0.0;
    c6_b_scale = rtInf;
    c6_g_k = 1.0;
   label_5:
    ;
    if (c6_g_k <= 6.0) {
      c6_h_k = c6_g_k;
      c6_s_x = c6_r_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("k", c6_h_k), 1, 6, 1, 0) - 1];
      c6_t_x = c6_s_x;
      c6_c_absx = muDoubleScalarAbs(c6_t_x);
      c6_u_x = c6_c_absx;
      c6_i_b = rtIsNaN(c6_u_x);
      if (c6_i_b) {
        return rtNaN;
      } else if (c6_c_absx == 0.0) {
        c6_y = 0.0;
        c6_d3 = c6_h_k + 1.0;
        c6_c_j = c6_d3;
      } else {
        if (c6_c_absx < c6_b_scale) {
          c6_c_a = c6_y;
          c6_k_b = c6_power(c6_b_scale / c6_c_absx, c6_c_p);
          c6_d_y = c6_c_a * c6_k_b;
          c6_y = 1.0 + c6_d_y;
          c6_b_scale = c6_c_absx;
        } else {
          c6_w_x = c6_c_absx;
          c6_l_b = rtIsInf(c6_w_x);
          if (!c6_l_b) {
            c6_y = c6_y + c6_power(c6_c_absx / c6_b_scale, c6_c_p);
          }
        }

        c6_g_k = c6_g_k + 1.0;
        goto label_5;
      }
    } else {
      if (c6_y > 0.0) {
        c6_x_x = c6_y;
        c6_m_b = rtIsInf(c6_x_x);
        if (!c6_m_b) {
          c6_d_a = c6_b_scale;
          c6_e_a = c6_y;
          c6_n_b = 1.0 / c6_c_p;
          c6_o_b = c6_power(c6_e_a, c6_n_b);
          return c6_d_a * c6_o_b;
        }
      }

      return c6_y;
    }

   label_6:
    ;
    if (c6_c_j <= 6.0) {
      c6_d_j = c6_c_j;
      c6_v_x = c6_r_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
        _SFD_INTEGER_CHECK("j", c6_d_j), 1, 6, 1, 0) - 1];
      c6_j_b = rtIsNaN(c6_v_x);
      if (c6_j_b) {
        return rtNaN;
      } else {
        c6_c_j = c6_c_j + 1.0;
        goto label_6;
      }
    }
  } else if (c6_p == 0.0) {
    return rtInf;
  } else {
    return rtNaN;
  }

  return c6_y;
}

static real_T c6_eml_xnrm2(real_T c6_x[6])
{
  int32_T c6_i933;
  real_T c6_b_x[6];
  int32_T c6_i934;
  real_T c6_c_x[6];
  for (c6_i933 = 0; c6_i933 < 6; c6_i933 = c6_i933 + 1) {
    c6_b_x[c6_i933] = c6_x[c6_i933];
  }

  for (c6_i934 = 0; c6_i934 < 6; c6_i934 = c6_i934 + 1) {
    c6_c_x[c6_i934] = c6_b_x[c6_i934];
  }

  return c6_ceval_xnrm2(6, c6_c_x, 1.0, 1);
}

static real_T c6_ceval_xnrm2(int32_T c6_n, real_T c6_x[6], real_T c6_ix0,
  int32_T c6_incx)
{
  return dnrm232(&c6_n, &c6_x[_SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)
    _SFD_INTEGER_CHECK("ix0", c6_ix0), 1, 6, 1, 0) - 1], &c6_incx);
}

static const mxArray *c6_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i935;
  real_T c6_b_u[12];
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  for (c6_i935 = 0; c6_i935 < 12; c6_i935 = c6_i935 + 1) {
    c6_b_u[c6_i935] = (*((real_T (*)[12])c6_u))[c6_i935];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 1, 12));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_b_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i936;
  real_T c6_b_u[7];
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  for (c6_i936 = 0; c6_i936 < 7; c6_i936 = c6_i936 + 1) {
    c6_b_u[c6_i936] = (*((real_T (*)[7])c6_u))[c6_i936];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_c_sf_marshall(void *c6_chartInstance, void *c6_u)
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

static const mxArray *c6_d_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i937;
  real_T c6_b_u[3];
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  for (c6_i937 = 0; c6_i937 < 3; c6_i937 = c6_i937 + 1) {
    c6_b_u[c6_i937] = (*((real_T (*)[3])c6_u))[c6_i937];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_e_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i938;
  real_T c6_b_u[6];
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  for (c6_i938 = 0; c6_i938 < 6; c6_i938 = c6_i938 + 1) {
    c6_b_u[c6_i938] = (*((real_T (*)[6])c6_u))[c6_i938];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_f_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i939;
  int32_T c6_i940;
  int32_T c6_i941;
  real_T c6_b_u[12];
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  c6_i939 = 0;
  for (c6_i940 = 0; c6_i940 < 6; c6_i940 = c6_i940 + 1) {
    for (c6_i941 = 0; c6_i941 < 2; c6_i941 = c6_i941 + 1) {
      c6_b_u[c6_i941 + c6_i939] = (*((real_T (*)[12])c6_u))[c6_i941 + c6_i939];
    }

    c6_i939 = c6_i939 + 2;
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 2, 2, 6));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_g_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i942;
  int32_T c6_i943;
  int32_T c6_i944;
  real_T c6_b_u[16];
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  c6_i942 = 0;
  for (c6_i943 = 0; c6_i943 < 4; c6_i943 = c6_i943 + 1) {
    for (c6_i944 = 0; c6_i944 < 4; c6_i944 = c6_i944 + 1) {
      c6_b_u[c6_i944 + c6_i942] = (*((real_T (*)[16])c6_u))[c6_i944 + c6_i942];
    }

    c6_i942 = c6_i942 + 4;
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_h_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i945;
  int32_T c6_i946;
  int32_T c6_i947;
  real_T c6_b_u[9];
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  c6_i945 = 0;
  for (c6_i946 = 0; c6_i946 < 3; c6_i946 = c6_i946 + 1) {
    for (c6_i947 = 0; c6_i947 < 3; c6_i947 = c6_i947 + 1) {
      c6_b_u[c6_i947 + c6_i945] = (*((real_T (*)[9])c6_u))[c6_i947 + c6_i945];
    }

    c6_i945 = c6_i945 + 3;
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_i_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i948;
  real_T c6_b_u[4];
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  for (c6_i948 = 0; c6_i948 < 4; c6_i948 = c6_i948 + 1) {
    c6_b_u[c6_i948] = (*((real_T (*)[4])c6_u))[c6_i948];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_j_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i949;
  int32_T c6_i950;
  int32_T c6_i951;
  real_T c6_b_u[18];
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  c6_i949 = 0;
  for (c6_i950 = 0; c6_i950 < 6; c6_i950 = c6_i950 + 1) {
    for (c6_i951 = 0; c6_i951 < 3; c6_i951 = c6_i951 + 1) {
      c6_b_u[c6_i951 + c6_i949] = (*((real_T (*)[18])c6_u))[c6_i951 + c6_i949];
    }

    c6_i949 = c6_i949 + 3;
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 2, 3, 6));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_k_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i952;
  int32_T c6_i953;
  int32_T c6_i954;
  real_T c6_b_u[24];
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  c6_i952 = 0;
  for (c6_i953 = 0; c6_i953 < 6; c6_i953 = c6_i953 + 1) {
    for (c6_i954 = 0; c6_i954 < 4; c6_i954 = c6_i954 + 1) {
      c6_b_u[c6_i954 + c6_i952] = (*((real_T (*)[24])c6_u))[c6_i954 + c6_i952];
    }

    c6_i952 = c6_i952 + 4;
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 2, 4, 6));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_l_sf_marshall(void *c6_chartInstance, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i955;
  int32_T c6_i956;
  int32_T c6_i957;
  real_T c6_b_u[36];
  const mxArray *c6_b_y = NULL;
  c6_y = NULL;
  c6_i955 = 0;
  for (c6_i956 = 0; c6_i956 < 6; c6_i956 = c6_i956 + 1) {
    for (c6_i957 = 0; c6_i957 < 6; c6_i957 = c6_i957 + 1) {
      c6_b_u[c6_i957 + c6_i955] = (*((real_T (*)[36])c6_u))[c6_i957 + c6_i955];
    }

    c6_i955 = c6_i955 + 6;
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 1U, 0U, 2, 6, 6));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

const mxArray
  *sf_c6_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_ResolvedFunctionInfo c6_info[107];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i958;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  c6_b_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 107));
  for (c6_i958 = 0; c6_i958 < 107; c6_i958 = c6_i958 + 1) {
    c6_r0 = &c6_info[c6_i958];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context",
                    "nameCaptureInfo", c6_i958);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name",
                    "nameCaptureInfo", c6_i958);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c6_i958);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c6_i958);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c6_i958);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c6_i958);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c6_i958);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[107])
{
  c6_info[0].context = "";
  c6_info[0].name = "pi";
  c6_info[0].dominantType = "";
  c6_info[0].resolved = "[B]pi";
  c6_info[0].fileLength = 0U;
  c6_info[0].fileTime1 = 0U;
  c6_info[0].fileTime2 = 0U;
  c6_info[1].context = "";
  c6_info[1].name = "mrdivide";
  c6_info[1].dominantType = "double";
  c6_info[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[1].fileLength = 800U;
  c6_info[1].fileTime1 = 1238434292U;
  c6_info[1].fileTime2 = 0U;
  c6_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[2].name = "nargin";
  c6_info[2].dominantType = "";
  c6_info[2].resolved = "[B]nargin";
  c6_info[2].fileLength = 0U;
  c6_info[2].fileTime1 = 0U;
  c6_info[2].fileTime2 = 0U;
  c6_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[3].name = "ge";
  c6_info[3].dominantType = "double";
  c6_info[3].resolved = "[B]ge";
  c6_info[3].fileLength = 0U;
  c6_info[3].fileTime1 = 0U;
  c6_info[3].fileTime2 = 0U;
  c6_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[4].name = "isscalar";
  c6_info[4].dominantType = "double";
  c6_info[4].resolved = "[B]isscalar";
  c6_info[4].fileLength = 0U;
  c6_info[4].fileTime1 = 0U;
  c6_info[4].fileTime2 = 0U;
  c6_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c6_info[5].name = "rdivide";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[5].fileLength = 620U;
  c6_info[5].fileTime1 = 1213926766U;
  c6_info[5].fileTime2 = 0U;
  c6_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[6].name = "gt";
  c6_info[6].dominantType = "double";
  c6_info[6].resolved = "[B]gt";
  c6_info[6].fileLength = 0U;
  c6_info[6].fileTime1 = 0U;
  c6_info[6].fileTime2 = 0U;
  c6_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[7].name = "isa";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved = "[B]isa";
  c6_info[7].fileLength = 0U;
  c6_info[7].fileTime1 = 0U;
  c6_info[7].fileTime2 = 0U;
  c6_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[8].name = "isempty";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved = "[B]isempty";
  c6_info[8].fileLength = 0U;
  c6_info[8].fileTime1 = 0U;
  c6_info[8].fileTime2 = 0U;
  c6_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[9].name = "not";
  c6_info[9].dominantType = "logical";
  c6_info[9].resolved = "[B]not";
  c6_info[9].fileLength = 0U;
  c6_info[9].fileTime1 = 0U;
  c6_info[9].fileTime2 = 0U;
  c6_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[10].name = "strcmp";
  c6_info[10].dominantType = "char";
  c6_info[10].resolved = "[B]strcmp";
  c6_info[10].fileLength = 0U;
  c6_info[10].fileTime1 = 0U;
  c6_info[10].fileTime2 = 0U;
  c6_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[11].name = "eq";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved = "[B]eq";
  c6_info[11].fileLength = 0U;
  c6_info[11].fileTime1 = 0U;
  c6_info[11].fileTime2 = 0U;
  c6_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[12].name = "eml_warning";
  c6_info[12].dominantType = "char";
  c6_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c6_info[12].fileLength = 262U;
  c6_info[12].fileTime1 = 1236257278U;
  c6_info[12].fileTime2 = 0U;
  c6_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[13].name = "eml_div";
  c6_info[13].dominantType = "double";
  c6_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[13].fileLength = 4269U;
  c6_info[13].fileTime1 = 1228093826U;
  c6_info[13].fileTime2 = 0U;
  c6_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[14].name = "isinteger";
  c6_info[14].dominantType = "double";
  c6_info[14].resolved = "[B]isinteger";
  c6_info[14].fileLength = 0U;
  c6_info[14].fileTime1 = 0U;
  c6_info[14].fileTime2 = 0U;
  c6_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c6_info[15].name = "isreal";
  c6_info[15].dominantType = "double";
  c6_info[15].resolved = "[B]isreal";
  c6_info[15].fileLength = 0U;
  c6_info[15].fileTime1 = 0U;
  c6_info[15].fileTime2 = 0U;
  c6_info[16].context = "";
  c6_info[16].name = "zeros";
  c6_info[16].dominantType = "double";
  c6_info[16].resolved = "[B]zeros";
  c6_info[16].fileLength = 0U;
  c6_info[16].fileTime1 = 0U;
  c6_info[16].fileTime2 = 0U;
  c6_info[17].context = "";
  c6_info[17].name = "uminus";
  c6_info[17].dominantType = "double";
  c6_info[17].resolved = "[B]uminus";
  c6_info[17].fileLength = 0U;
  c6_info[17].fileTime1 = 0U;
  c6_info[17].fileTime2 = 0U;
  c6_info[18].context = "";
  c6_info[18].name = "plus";
  c6_info[18].dominantType = "double";
  c6_info[18].resolved = "[B]plus";
  c6_info[18].fileLength = 0U;
  c6_info[18].fileTime1 = 0U;
  c6_info[18].fileTime2 = 0U;
  c6_info[19].context = "";
  c6_info[19].name = "mtimes";
  c6_info[19].dominantType = "double";
  c6_info[19].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[19].fileLength = 3302U;
  c6_info[19].fileTime1 = 1242750894U;
  c6_info[19].fileTime2 = 0U;
  c6_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[20].name = "size";
  c6_info[20].dominantType = "double";
  c6_info[20].resolved = "[B]size";
  c6_info[20].fileLength = 0U;
  c6_info[20].fileTime1 = 0U;
  c6_info[20].fileTime2 = 0U;
  c6_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[21].name = "class";
  c6_info[21].dominantType = "double";
  c6_info[21].resolved = "[B]class";
  c6_info[21].fileLength = 0U;
  c6_info[21].fileTime1 = 0U;
  c6_info[21].fileTime2 = 0U;
  c6_info[22].context = "";
  c6_info[22].name = "mpower";
  c6_info[22].dominantType = "double";
  c6_info[22].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[22].fileLength = 3710U;
  c6_info[22].fileTime1 = 1238434290U;
  c6_info[22].fileTime2 = 0U;
  c6_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[23].name = "ndims";
  c6_info[23].dominantType = "double";
  c6_info[23].resolved = "[B]ndims";
  c6_info[23].fileLength = 0U;
  c6_info[23].fileTime1 = 0U;
  c6_info[23].fileTime2 = 0U;
  c6_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[24].name = "power";
  c6_info[24].dominantType = "double";
  c6_info[24].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[24].fileLength = 5380U;
  c6_info[24].fileTime1 = 1228093898U;
  c6_info[24].fileTime2 = 0U;
  c6_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[25].name = "eml_scalar_eg";
  c6_info[25].dominantType = "double";
  c6_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[25].fileLength = 3068U;
  c6_info[25].fileTime1 = 1240262010U;
  c6_info[25].fileTime2 = 0U;
  c6_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c6_info[26].name = "false";
  c6_info[26].dominantType = "";
  c6_info[26].resolved = "[B]false";
  c6_info[26].fileLength = 0U;
  c6_info[26].fileTime1 = 0U;
  c6_info[26].fileTime2 = 0U;
  c6_info[27].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[27].name = "isstruct";
  c6_info[27].dominantType = "double";
  c6_info[27].resolved = "[B]isstruct";
  c6_info[27].fileLength = 0U;
  c6_info[27].fileTime1 = 0U;
  c6_info[27].fileTime2 = 0U;
  c6_info[28].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c6_info[28].name = "cast";
  c6_info[28].dominantType = "double";
  c6_info[28].resolved = "[B]cast";
  c6_info[28].fileLength = 0U;
  c6_info[28].fileTime1 = 0U;
  c6_info[28].fileTime2 = 0U;
  c6_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[29].name = "eml_scalexp_alloc";
  c6_info[29].dominantType = "double";
  c6_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[29].fileLength = 808U;
  c6_info[29].fileTime1 = 1230494700U;
  c6_info[29].fileTime2 = 0U;
  c6_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[30].name = "minus";
  c6_info[30].dominantType = "double";
  c6_info[30].resolved = "[B]minus";
  c6_info[30].fileLength = 0U;
  c6_info[30].fileTime1 = 0U;
  c6_info[30].fileTime2 = 0U;
  c6_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[31].name = "lt";
  c6_info[31].dominantType = "double";
  c6_info[31].resolved = "[B]lt";
  c6_info[31].fileLength = 0U;
  c6_info[31].fileTime1 = 0U;
  c6_info[31].fileTime2 = 0U;
  c6_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[32].name = "eml_scalar_floor";
  c6_info[32].dominantType = "double";
  c6_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c6_info[32].fileLength = 260U;
  c6_info[32].fileTime1 = 1209330790U;
  c6_info[32].fileTime2 = 0U;
  c6_info[33].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[33].name = "ne";
  c6_info[33].dominantType = "double";
  c6_info[33].resolved = "[B]ne";
  c6_info[33].fileLength = 0U;
  c6_info[33].fileTime1 = 0U;
  c6_info[33].fileTime2 = 0U;
  c6_info[34].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[34].name = "eml_error";
  c6_info[34].dominantType = "char";
  c6_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c6_info[34].fileLength = 315U;
  c6_info[34].fileTime1 = 1213926746U;
  c6_info[34].fileTime2 = 0U;
  c6_info[35].context = "";
  c6_info[35].name = "sqrt";
  c6_info[35].dominantType = "double";
  c6_info[35].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[35].fileLength = 572U;
  c6_info[35].fileTime1 = 1203448046U;
  c6_info[35].fileTime2 = 0U;
  c6_info[36].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c6_info[36].name = "eml_scalar_sqrt";
  c6_info[36].dominantType = "double";
  c6_info[36].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c6_info[36].fileLength = 664U;
  c6_info[36].fileTime1 = 1209330794U;
  c6_info[36].fileTime2 = 0U;
  c6_info[37].context = "";
  c6_info[37].name = "adjust_ang";
  c6_info[37].dominantType = "double";
  c6_info[37].resolved =
    "[]C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/adjust_ang.m";
  c6_info[37].fileLength = 171U;
  c6_info[37].fileTime1 = 1416490128U;
  c6_info[37].fileTime2 = 0U;
  c6_info[38].context = "";
  c6_info[38].name = "cos";
  c6_info[38].dominantType = "double";
  c6_info[38].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[38].fileLength = 324U;
  c6_info[38].fileTime1 = 1203447952U;
  c6_info[38].fileTime2 = 0U;
  c6_info[39].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[39].name = "eml_scalar_cos";
  c6_info[39].dominantType = "double";
  c6_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c6_info[39].fileLength = 602U;
  c6_info[39].fileTime1 = 1209330788U;
  c6_info[39].fileTime2 = 0U;
  c6_info[40].context = "";
  c6_info[40].name = "sin";
  c6_info[40].dominantType = "double";
  c6_info[40].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[40].fileLength = 324U;
  c6_info[40].fileTime1 = 1203448042U;
  c6_info[40].fileTime2 = 0U;
  c6_info[41].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[41].name = "eml_scalar_sin";
  c6_info[41].dominantType = "double";
  c6_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c6_info[41].fileLength = 601U;
  c6_info[41].fileTime1 = 1209330792U;
  c6_info[41].fileTime2 = 0U;
  c6_info[42].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[42].name = "le";
  c6_info[42].dominantType = "double";
  c6_info[42].resolved = "[B]le";
  c6_info[42].fileLength = 0U;
  c6_info[42].fileTime1 = 0U;
  c6_info[42].fileTime2 = 0U;
  c6_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[43].name = "eml_index_class";
  c6_info[43].dominantType = "";
  c6_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[43].fileLength = 909U;
  c6_info[43].fileTime1 = 1192466782U;
  c6_info[43].fileTime2 = 0U;
  c6_info[44].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[44].name = "ones";
  c6_info[44].dominantType = "char";
  c6_info[44].resolved = "[B]ones";
  c6_info[44].fileLength = 0U;
  c6_info[44].fileTime1 = 0U;
  c6_info[44].fileTime2 = 0U;
  c6_info[45].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[45].name = "eml_xgemm";
  c6_info[45].dominantType = "int32";
  c6_info[45].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[45].fileLength = 3184U;
  c6_info[45].fileTime1 = 1209330852U;
  c6_info[45].fileTime2 = 0U;
  c6_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c6_info[46].name = "length";
  c6_info[46].dominantType = "double";
  c6_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c6_info[46].fileLength = 326U;
  c6_info[46].fileTime1 = 1226577276U;
  c6_info[46].fileTime2 = 0U;
  c6_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c6_info[47].name = "min";
  c6_info[47].dominantType = "double";
  c6_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[47].fileLength = 308U;
  c6_info[47].fileTime1 = 1192466634U;
  c6_info[47].fileTime2 = 0U;
  c6_info[48].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[48].name = "nargout";
  c6_info[48].dominantType = "";
  c6_info[48].resolved = "[B]nargout";
  c6_info[48].fileLength = 0U;
  c6_info[48].fileTime1 = 0U;
  c6_info[48].fileTime2 = 0U;
  c6_info[49].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[49].name = "eml_min_or_max";
  c6_info[49].dominantType = "char";
  c6_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c6_info[49].fileLength = 9969U;
  c6_info[49].fileTime1 = 1240262008U;
  c6_info[49].fileTime2 = 0U;
  c6_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c6_info[50].name = "ischar";
  c6_info[50].dominantType = "char";
  c6_info[50].resolved = "[B]ischar";
  c6_info[50].fileLength = 0U;
  c6_info[50].fileTime1 = 0U;
  c6_info[50].fileTime2 = 0U;
  c6_info[51].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c6_info[51].name = "isnumeric";
  c6_info[51].dominantType = "double";
  c6_info[51].resolved = "[B]isnumeric";
  c6_info[51].fileLength = 0U;
  c6_info[51].fileTime1 = 0U;
  c6_info[51].fileTime2 = 0U;
  c6_info[52].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c6_info[52].name = "islogical";
  c6_info[52].dominantType = "double";
  c6_info[52].resolved = "[B]islogical";
  c6_info[52].fileLength = 0U;
  c6_info[52].fileTime1 = 0U;
  c6_info[52].fileTime2 = 0U;
  c6_info[53].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[53].name = "eml_refblas_xgemm";
  c6_info[53].dominantType = "int32";
  c6_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[53].fileLength = 5748U;
  c6_info[53].fileTime1 = 1228093874U;
  c6_info[53].fileTime2 = 0U;
  c6_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[54].name = "eml_index_minus";
  c6_info[54].dominantType = "int32";
  c6_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[54].fileLength = 277U;
  c6_info[54].fileTime1 = 1192466784U;
  c6_info[54].fileTime2 = 0U;
  c6_info[55].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[55].name = "eml_index_times";
  c6_info[55].dominantType = "int32";
  c6_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c6_info[55].fileLength = 280U;
  c6_info[55].fileTime1 = 1192466788U;
  c6_info[55].fileTime2 = 0U;
  c6_info[56].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[56].name = "eml_index_plus";
  c6_info[56].dominantType = "int32";
  c6_info[56].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[56].fileLength = 272U;
  c6_info[56].fileTime1 = 1192466786U;
  c6_info[56].fileTime2 = 0U;
  c6_info[57].context = "";
  c6_info[57].name = "ctranspose";
  c6_info[57].dominantType = "double";
  c6_info[57].resolved = "[B]ctranspose";
  c6_info[57].fileLength = 0U;
  c6_info[57].fileTime1 = 0U;
  c6_info[57].fileTime2 = 0U;
  c6_info[58].context = "";
  c6_info[58].name = "DCM2Eul";
  c6_info[58].dominantType = "double";
  c6_info[58].resolved =
    "[]C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/DCM2Eul.m";
  c6_info[58].fileLength = 155U;
  c6_info[58].fileTime1 = 1416490132U;
  c6_info[58].fileTime2 = 0U;
  c6_info[59].context =
    "[]C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/DCM2Eul.m";
  c6_info[59].name = "atan2";
  c6_info[59].dominantType = "double";
  c6_info[59].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c6_info[59].fileLength = 605U;
  c6_info[59].fileTime1 = 1236257254U;
  c6_info[59].fileTime2 = 0U;
  c6_info[60].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c6_info[60].name = "eml_scalar_atan2";
  c6_info[60].dominantType = "double";
  c6_info[60].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c6_info[60].fileLength = 964U;
  c6_info[60].fileTime1 = 1209330786U;
  c6_info[60].fileTime2 = 0U;
  c6_info[61].context =
    "[]C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/DCM2Eul.m";
  c6_info[61].name = "asin";
  c6_info[61].dominantType = "double";
  c6_info[61].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c6_info[61].fileLength = 585U;
  c6_info[61].fileTime1 = 1203447944U;
  c6_info[61].fileTime2 = 0U;
  c6_info[62].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c6_info[62].name = "eml_scalar_asin";
  c6_info[62].dominantType = "double";
  c6_info[62].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asin.m";
  c6_info[62].fileLength = 588U;
  c6_info[62].fileTime1 = 1203447974U;
  c6_info[62].fileTime2 = 0U;
  c6_info[63].context = "";
  c6_info[63].name = "eye";
  c6_info[63].dominantType = "double";
  c6_info[63].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c6_info[63].fileLength = 1765U;
  c6_info[63].fileTime1 = 1219752890U;
  c6_info[63].fileTime2 = 0U;
}

static void c6_b_info_helper(c6_ResolvedFunctionInfo c6_info[107])
{
  c6_info[64].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c6_info[64].name = "eml_assert_valid_size_arg";
  c6_info[64].dominantType = "double";
  c6_info[64].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[64].fileLength = 3237U;
  c6_info[64].fileTime1 = 1228093824U;
  c6_info[64].fileTime2 = 0U;
  c6_info[65].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c6_info[65].name = "isfinite";
  c6_info[65].dominantType = "double";
  c6_info[65].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[65].fileLength = 364U;
  c6_info[65].fileTime1 = 1226577272U;
  c6_info[65].fileTime2 = 0U;
  c6_info[66].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[66].name = "isinf";
  c6_info[66].dominantType = "double";
  c6_info[66].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c6_info[66].fileLength = 506U;
  c6_info[66].fileTime1 = 1228093810U;
  c6_info[66].fileTime2 = 0U;
  c6_info[67].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[67].name = "isnan";
  c6_info[67].dominantType = "double";
  c6_info[67].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c6_info[67].fileLength = 506U;
  c6_info[67].fileTime1 = 1228093810U;
  c6_info[67].fileTime2 = 0U;
  c6_info[68].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c6_info[68].name = "and";
  c6_info[68].dominantType = "logical";
  c6_info[68].resolved = "[B]and";
  c6_info[68].fileLength = 0U;
  c6_info[68].fileTime1 = 0U;
  c6_info[68].fileTime2 = 0U;
  c6_info[69].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/isintegral";
  c6_info[69].name = "true";
  c6_info[69].dominantType = "";
  c6_info[69].resolved = "[B]true";
  c6_info[69].fileLength = 0U;
  c6_info[69].fileTime1 = 0U;
  c6_info[69].fileTime2 = 0U;
  c6_info[70].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/numel_for_size";
  c6_info[70].name = "double";
  c6_info[70].dominantType = "double";
  c6_info[70].resolved = "[B]double";
  c6_info[70].fileLength = 0U;
  c6_info[70].fileTime1 = 0U;
  c6_info[70].fileTime2 = 0U;
  c6_info[71].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[71].name = "intmax";
  c6_info[71].dominantType = "char";
  c6_info[71].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[71].fileLength = 1535U;
  c6_info[71].fileTime1 = 1192466728U;
  c6_info[71].fileTime2 = 0U;
  c6_info[72].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[72].name = "int32";
  c6_info[72].dominantType = "double";
  c6_info[72].resolved = "[B]int32";
  c6_info[72].fileLength = 0U;
  c6_info[72].fileTime1 = 0U;
  c6_info[72].fileTime2 = 0U;
  c6_info[73].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c6_info[73].name = "eml_is_float_class";
  c6_info[73].dominantType = "char";
  c6_info[73].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c6_info[73].fileLength = 226U;
  c6_info[73].fileTime1 = 1197850442U;
  c6_info[73].fileTime2 = 0U;
  c6_info[74].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m/eye_internal";
  c6_info[74].name = "real";
  c6_info[74].dominantType = "double";
  c6_info[74].resolved = "[B]real";
  c6_info[74].fileLength = 0U;
  c6_info[74].fileTime1 = 0U;
  c6_info[74].fileTime2 = 0U;
  c6_info[75].context = "";
  c6_info[75].name = "inv";
  c6_info[75].dominantType = "double";
  c6_info[75].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c6_info[75].fileLength = 4597U;
  c6_info[75].fileTime1 = 1228093880U;
  c6_info[75].fileTime2 = 0U;
  c6_info[76].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c6_info[76].name = "eml_xgetrf";
  c6_info[76].dominantType = "int32";
  c6_info[76].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c6_info[76].fileLength = 2229U;
  c6_info[76].fileTime1 = 1240262014U;
  c6_info[76].fileTime2 = 0U;
  c6_info[77].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c6_info[77].name = "colon";
  c6_info[77].dominantType = "int32";
  c6_info[77].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[77].fileLength = 8271U;
  c6_info[77].fileTime1 = 1228093892U;
  c6_info[77].fileTime2 = 0U;
  c6_info[78].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c6_info[78].name = "floor";
  c6_info[78].dominantType = "double";
  c6_info[78].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[78].fileLength = 332U;
  c6_info[78].fileTime1 = 1203448024U;
  c6_info[78].fileTime2 = 0U;
  c6_info[79].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/checkrange";
  c6_info[79].name = "intmin";
  c6_info[79].dominantType = "char";
  c6_info[79].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c6_info[79].fileLength = 1505U;
  c6_info[79].fileTime1 = 1192466730U;
  c6_info[79].fileTime2 = 0U;
  c6_info[80].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/unrounded_npoints";
  c6_info[80].name = "realmax";
  c6_info[80].dominantType = "";
  c6_info[80].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c6_info[80].fileLength = 771U;
  c6_info[80].fileTime1 = 1226577278U;
  c6_info[80].fileTime2 = 0U;
  c6_info[81].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m/eml_integer_colon";
  c6_info[81].name = "transpose";
  c6_info[81].dominantType = "int32";
  c6_info[81].resolved = "[B]transpose";
  c6_info[81].fileLength = 0U;
  c6_info[81].fileTime1 = 0U;
  c6_info[81].fileTime2 = 0U;
  c6_info[82].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c6_info[82].name = "eml_ixamax";
  c6_info[82].dominantType = "int32";
  c6_info[82].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c6_info[82].fileLength = 731U;
  c6_info[82].fileTime1 = 1209330844U;
  c6_info[82].fileTime2 = 0U;
  c6_info[83].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c6_info[83].name = "eml_refblas_ixamax";
  c6_info[83].dominantType = "int32";
  c6_info[83].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c6_info[83].fileLength = 740U;
  c6_info[83].fileTime1 = 1192466866U;
  c6_info[83].fileTime2 = 0U;
  c6_info[84].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c6_info[84].name = "eml_xcabs1";
  c6_info[84].dominantType = "double";
  c6_info[84].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c6_info[84].fileLength = 419U;
  c6_info[84].fileTime1 = 1209330848U;
  c6_info[84].fileTime2 = 0U;
  c6_info[85].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c6_info[85].name = "abs";
  c6_info[85].dominantType = "double";
  c6_info[85].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[85].fileLength = 566U;
  c6_info[85].fileTime1 = 1221267134U;
  c6_info[85].fileTime2 = 0U;
  c6_info[86].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[86].name = "eml_scalar_abs";
  c6_info[86].dominantType = "double";
  c6_info[86].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[86].fileLength = 461U;
  c6_info[86].fileTime1 = 1203447960U;
  c6_info[86].fileTime2 = 0U;
  c6_info[87].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c6_info[87].name = "imag";
  c6_info[87].dominantType = "double";
  c6_info[87].resolved = "[B]imag";
  c6_info[87].fileLength = 0U;
  c6_info[87].fileTime1 = 0U;
  c6_info[87].fileTime2 = 0U;
  c6_info[88].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c6_info[88].name = "eml_xswap";
  c6_info[88].dominantType = "int32";
  c6_info[88].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c6_info[88].fileLength = 1330U;
  c6_info[88].fileTime1 = 1209330862U;
  c6_info[88].fileTime2 = 0U;
  c6_info[89].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c6_info[89].name = "eml_refblas_xswap";
  c6_info[89].dominantType = "int32";
  c6_info[89].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c6_info[89].fileLength = 905U;
  c6_info[89].fileTime1 = 1238434270U;
  c6_info[89].fileTime2 = 0U;
  c6_info[90].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_xgetrf.m";
  c6_info[90].name = "eml_xgeru";
  c6_info[90].dominantType = "int32";
  c6_info[90].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c6_info[90].fileLength = 2462U;
  c6_info[90].fileTime1 = 1209330856U;
  c6_info[90].fileTime2 = 0U;
  c6_info[91].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c6_info[91].name = "eml_xger";
  c6_info[91].dominantType = "int32";
  c6_info[91].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c6_info[91].fileLength = 2168U;
  c6_info[91].fileTime1 = 1209330854U;
  c6_info[91].fileTime2 = 0U;
  c6_info[92].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c6_info[92].name = "eml_refblas_xger";
  c6_info[92].dominantType = "int32";
  c6_info[92].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c6_info[92].fileLength = 411U;
  c6_info[92].fileTime1 = 1211216050U;
  c6_info[92].fileTime2 = 0U;
  c6_info[93].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c6_info[93].name = "eml_refblas_xgerx";
  c6_info[93].dominantType = "int32";
  c6_info[93].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c6_info[93].fileLength = 2231U;
  c6_info[93].fileTime1 = 1238434268U;
  c6_info[93].fileTime2 = 0U;
  c6_info[94].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c6_info[94].name = "times";
  c6_info[94].dominantType = "double";
  c6_info[94].resolved = "[B]times";
  c6_info[94].fileLength = 0U;
  c6_info[94].fileTime1 = 0U;
  c6_info[94].fileTime2 = 0U;
  c6_info[95].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c6_info[95].name = "eml_ipiv2perm";
  c6_info[95].dominantType = "int32";
  c6_info[95].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c6_info[95].fileLength = 439U;
  c6_info[95].fileTime1 = 1209330832U;
  c6_info[95].fileTime2 = 0U;
  c6_info[96].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/invNxN";
  c6_info[96].name = "eml_xtrsm";
  c6_info[96].dominantType = "int32";
  c6_info[96].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c6_info[96].fileLength = 2383U;
  c6_info[96].fileTime1 = 1209330862U;
  c6_info[96].fileTime2 = 0U;
  c6_info[97].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c6_info[97].name = "eml_refblas_xtrsm";
  c6_info[97].dominantType = "int32";
  c6_info[97].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c6_info[97].fileLength = 8461U;
  c6_info[97].fileTime1 = 1228093876U;
  c6_info[97].fileTime2 = 0U;
  c6_info[98].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/checkcond";
  c6_info[98].name = "norm";
  c6_info[98].dominantType = "double";
  c6_info[98].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c6_info[98].fileLength = 5186U;
  c6_info[98].fileTime1 = 1240262048U;
  c6_info[98].fileTime2 = 0U;
  c6_info[99].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c6_info[99].name = "isvector";
  c6_info[99].dominantType = "double";
  c6_info[99].resolved = "[B]isvector";
  c6_info[99].fileLength = 0U;
  c6_info[99].fileTime1 = 0U;
  c6_info[99].fileTime2 = 0U;
  c6_info[100].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c6_info[100].name = "inf";
  c6_info[100].dominantType = "";
  c6_info[100].resolved = "[B]inf";
  c6_info[100].fileLength = 0U;
  c6_info[100].fileTime1 = 0U;
  c6_info[100].fileTime2 = 0U;
  c6_info[101].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/mat1norm";
  c6_info[101].name = "eml_guarded_nan";
  c6_info[101].dominantType = "char";
  c6_info[101].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c6_info[101].fileLength = 485U;
  c6_info[101].fileTime1 = 1192466780U;
  c6_info[101].fileTime2 = 0U;
  c6_info[102].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c6_info[102].name = "nan";
  c6_info[102].dominantType = "char";
  c6_info[102].resolved = "[B]nan";
  c6_info[102].fileLength = 0U;
  c6_info[102].fileTime1 = 0U;
  c6_info[102].fileTime2 = 0U;
  c6_info[103].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m/checkcond";
  c6_info[103].name = "eps";
  c6_info[103].dominantType = "char";
  c6_info[103].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c6_info[103].fileLength = 1337U;
  c6_info[103].fileTime1 = 1228093800U;
  c6_info[103].fileTime2 = 0U;
  c6_info[104].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c6_info[104].name = "eml_xnrm2";
  c6_info[104].dominantType = "double";
  c6_info[104].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c6_info[104].fileLength = 718U;
  c6_info[104].fileTime1 = 1209330858U;
  c6_info[104].fileTime2 = 0U;
  c6_info[105].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c6_info[105].name = "eml_refblas_xnrm2";
  c6_info[105].dominantType = "int32";
  c6_info[105].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c6_info[105].fileLength = 1433U;
  c6_info[105].fileTime1 = 1240262044U;
  c6_info[105].fileTime2 = 0U;
  c6_info[106].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m/genpnorm";
  c6_info[106].name = "eml_guarded_inf";
  c6_info[106].dominantType = "char";
  c6_info[106].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m";
  c6_info[106].fileLength = 495U;
  c6_info[106].fileTime1 = 1192466778U;
  c6_info[106].fileTime2 = 0U;
}

static const mxArray *c6_m_sf_marshall(void *c6_chartInstance, void *c6_u)
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
void sf_c6_M43_Sim_Forcing_003h_Trajectory_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2198197670U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3073691630U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(381989612U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(823880515U);
}

mxArray *sf_c6_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2258687122U);
    pr[1] = (double)(1014912926U);
    pr[2] = (double)(260770860U);
    pr[3] = (double)(1036905830U);
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

static mxArray *sf_get_sim_state_info_c6_M43_Sim_Forcing_003h_Trajectory(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"out\",},{M[8],M[0],T\"is_active_c6_M43_Sim_Forcing_003h_Trajectory\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_M43_Sim_Forcing_003h_Trajectory_get_check_sum(&mxChecksum);
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
          (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_,
           6,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           2,
           &(chartInstance.chartNumber),
           &(chartInstance.instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_,
             chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_,
             chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_,
             chartInstance.chartNumber,
             0,
             0,
             0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 12;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"vec",0,(MexFcnForType)c6_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"out",0,(MexFcnForType)c6_b_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,5,0,1,1,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,7414);
        _SFD_CV_INIT_EML_IF(0,0,2770,2781,2964,7189);
        _SFD_CV_INIT_EML_IF(0,1,6868,6891,7079,7185);
        _SFD_CV_INIT_EML_IF(0,2,7079,7088,2964,7189);
        _SFD_CV_INIT_EML_IF(0,3,7266,7288,7332,7405);
        _SFD_CV_INIT_EML_IF(0,4,7332,7358,-1,-2);
        _SFD_CV_INIT_EML_FOR(0,0,7248,7262,7409);
        _SFD_CV_INIT_EML_WHILE(0,0,2964,2972,7189);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,1,2,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"adjust_ang",0,-1,162);
        _SFD_CV_INIT_SCRIPT_FOR(0,0,39,53,160);
        _SFD_CV_INIT_SCRIPT_WHILE(0,0,73,87,104);
        _SFD_CV_INIT_SCRIPT_WHILE(0,1,109,123,140);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"DCM2Eul",0,-1,145);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c6_vec)[12];
          real_T (*c6_out)[7];
          c6_vec = (real_T (*)[12])ssGetInputPortSignal(chartInstance.S, 0);
          c6_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_vec);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c6_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c6_M43_Sim_Forcing_003h_Trajectory();
  initialize_c6_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_enable_c6_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  enable_c6_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_disable_c6_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  disable_c6_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_gateway_c6_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  sf_c6_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_ext_mode_exec_c6_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  ext_mode_exec_c6_M43_Sim_Forcing_003h_Trajectory();
}

static mxArray* sf_opaque_get_sim_state_c6_M43_Sim_Forcing_003h_Trajectory(void *
  chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c6_M43_Sim_Forcing_003h_Trajectory();
  return st;
}

static void sf_opaque_set_sim_state_c6_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c6_M43_Sim_Forcing_003h_Trajectory(sf_mex_dup(st));
}

static void sf_opaque_terminate_c6_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c6_M43_Sim_Forcing_003h_Trajectory();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_M43_Sim_Forcing_003h_Trajectory();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c6_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M43_Sim_Forcing_003h_Trajectory",
      "M43_Sim_Forcing_003h_Trajectory",6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("M43_Sim_Forcing_003h_Trajectory",
                "M43_Sim_Forcing_003h_Trajectory",6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M43_Sim_Forcing_003h_Trajectory","M43_Sim_Forcing_003h_Trajectory",6,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"M43_Sim_Forcing_003h_Trajectory",
        "M43_Sim_Forcing_003h_Trajectory",6,1);
      sf_mark_chart_reusable_outputs(S,"M43_Sim_Forcing_003h_Trajectory",
        "M43_Sim_Forcing_003h_Trajectory",6,1);
    }

    sf_set_rtw_dwork_info(S,"M43_Sim_Forcing_003h_Trajectory",
                          "M43_Sim_Forcing_003h_Trajectory",6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(525338945U));
  ssSetChecksum1(S,(4078435017U));
  ssSetChecksum2(S,(3490551446U));
  ssSetChecksum3(S,(507977809U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M43_Sim_Forcing_003h_Trajectory",
      "M43_Sim_Forcing_003h_Trajectory",6);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c6_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c6_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c6_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c6_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c6_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.mdlStart = mdlStart_c6_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c6_M43_Sim_Forcing_003h_Trajectory;
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

void c6_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_M43_Sim_Forcing_003h_Trajectory_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

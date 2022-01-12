/* Include files */

#include "blascompat32.h"
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun.h"
#include "c23_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c23_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc23_M37_Sim_Forcing_003h_expe_infra_transz_limInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void initialize_params_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void);
static void enable_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void disable_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c23_update_debugger_state_c23_M37_Sim_Forcing_003h_expe_infra_t(void);
static void ext_mode_exec_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static const mxArray
  *get_sim_state_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void set_sim_state_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c23_st);
static void finalize_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void sf_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c23_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber);
static void c23_adjust_ang(real_T c23_ang[6], real_T c23_b_ang[6]);
static void c23_eml_scalar_eg(void);
static void c23_b_eml_scalar_eg(void);
static void c23_c_eml_scalar_eg(void);
static void c23_d_eml_scalar_eg(void);
static real_T c23_atan2(real_T c23_y, real_T c23_x);
static void c23_eml_error(void);
static const mxArray *c23_sf_marshall(void *c23_chartInstance, void *c23_u);
static const mxArray *c23_b_sf_marshall(void *c23_chartInstance, void *c23_u);
static const mxArray *c23_c_sf_marshall(void *c23_chartInstance, void *c23_u);
static const mxArray *c23_d_sf_marshall(void *c23_chartInstance, void *c23_u);
static const mxArray *c23_e_sf_marshall(void *c23_chartInstance, void *c23_u);
static const mxArray *c23_f_sf_marshall(void *c23_chartInstance, void *c23_u);
static void c23_info_helper(c23_ResolvedFunctionInfo c23_info[58]);
static const mxArray *c23_g_sf_marshall(void *c23_chartInstance, void *c23_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  uint8_T *c23_is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c23_is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c23_is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim = 0U;
}

static void initialize_params_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void)
{
}

static void enable_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c23_update_debugger_state_c23_M37_Sim_Forcing_003h_expe_infra_t(void)
{
}

static void ext_mode_exec_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  c23_update_debugger_state_c23_M37_Sim_Forcing_003h_expe_infra_t();
}

static const mxArray
  *get_sim_state_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const mxArray *c23_st = NULL;
  const mxArray *c23_y = NULL;
  int32_T c23_i0;
  real_T c23_u[6];
  const mxArray *c23_b_y = NULL;
  uint8_T c23_b_u;
  const mxArray *c23_c_y = NULL;
  uint8_T *c23_is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  real_T (*c23_out)[6];
  c23_is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c23_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 1);
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellarray(2));
  for (c23_i0 = 0; c23_i0 < 6; c23_i0 = c23_i0 + 1) {
    c23_u[c23_i0] = (*c23_out)[c23_i0];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_b_u = *c23_is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c23_y, 1, c23_c_y);
  sf_mex_assign(&c23_st, c23_y);
  return c23_st;
}

static void set_sim_state_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c23_st)
{
  const mxArray *c23_u;
  const mxArray *c23_out;
  real_T c23_dv0[6];
  int32_T c23_i1;
  real_T c23_y[6];
  int32_T c23_i2;
  const mxArray *c23_is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  uint8_T c23_u0;
  uint8_T c23_b_y;
  boolean_T *c23_doneDoubleBufferReInit;
  uint8_T *c23_b_is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  real_T (*c23_b_out)[6];
  c23_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c23_b_is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c23_b_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 1);
  *c23_doneDoubleBufferReInit = true;
  c23_u = sf_mex_dup(c23_st);
  c23_out = sf_mex_dup(sf_mex_getcell(c23_u, 0));
  sf_mex_import("out", sf_mex_dup(c23_out), &c23_dv0, 1, 0, 0U, 1, 0U, 1, 6);
  for (c23_i1 = 0; c23_i1 < 6; c23_i1 = c23_i1 + 1) {
    c23_y[c23_i1] = c23_dv0[c23_i1];
  }

  sf_mex_destroy(&c23_out);
  for (c23_i2 = 0; c23_i2 < 6; c23_i2 = c23_i2 + 1) {
    (*c23_b_out)[c23_i2] = c23_y[c23_i2];
  }

  c23_is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim = sf_mex_dup
    (sf_mex_getcell(c23_u, 1));
  sf_mex_import("is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim",
                sf_mex_dup(
    c23_is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim), &c23_u0, 1, 3,
                0U, 0, 0U, 0);
  c23_b_y = c23_u0;
  sf_mex_destroy(&c23_is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim);
  *c23_b_is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim = c23_b_y;
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_M37_Sim_Forcing_003h_expe_infra_t();
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void sf_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c23_i3;
  int32_T c23_i4;
  int32_T c23_previousEvent;
  real_T (*c23_out)[6];
  real_T (*c23_vec)[6];
  c23_vec = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 0);
  c23_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,16);
  for (c23_i3 = 0; c23_i3 < 6; c23_i3 = c23_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c23_vec)[c23_i3], 0U);
  }

  for (c23_i4 = 0; c23_i4 < 6; c23_i4 = c23_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c23_out)[c23_i4], 1U);
  }

  c23_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c23_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  _sfEvent_ = c23_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void c23_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c23_i5;
  real_T c23_vec[6];
  real_T c23_nargout = 1.0;
  real_T c23_nargin = 1.0;
  real_T c23_eul_ang[3];
  real_T c23_E[9];
  real_T c23_pos[3];
  real_T c23_p[4];
  real_T c23_x6[4];
  real_T c23_x_cabin[3];
  real_T c23_E6[9];
  real_T c23_E5[9];
  real_T c23_E4[9];
  real_T c23_E3[9];
  real_T c23_E2[9];
  real_T c23_E1[9];
  real_T c23_D6[16];
  real_T c23_D5[16];
  real_T c23_D4[16];
  real_T c23_D3[16];
  real_T c23_D2[16];
  real_T c23_D1[16];
  real_T c23_SA6;
  real_T c23_CA6;
  real_T c23_SA5;
  real_T c23_CA5;
  real_T c23_SA4;
  real_T c23_CA4;
  real_T c23_SA3;
  real_T c23_CA3;
  real_T c23_SA2;
  real_T c23_CA2;
  real_T c23_SA1;
  real_T c23_CA1;
  real_T c23_A6;
  real_T c23_A5;
  real_T c23_A4;
  real_T c23_A3;
  real_T c23_A2;
  real_T c23_A1;
  real_T c23_Height_A2;
  real_T c23_d;
  real_T c23_l5;
  real_T c23_l4;
  real_T c23_l3;
  real_T c23_l2;
  real_T c23_l1;
  real_T c23_ang[6];
  real_T c23_J_ANG[6];
  real_T c23_RTD;
  real_T c23_DTR;
  real_T c23_out[6];
  int32_T c23_i6;
  int32_T c23_i7;
  real_T c23_a[6];
  int32_T c23_i8;
  int32_T c23_i9;
  int32_T c23_i10;
  real_T c23_b_ang[6];
  real_T c23_dv1[6];
  int32_T c23_i11;
  real_T c23_x;
  real_T c23_b_x;
  real_T c23_c_x;
  real_T c23_d_x;
  real_T c23_e_x;
  real_T c23_f_x;
  real_T c23_g_x;
  real_T c23_h_x;
  real_T c23_i_x;
  real_T c23_j_x;
  real_T c23_k_x;
  real_T c23_l_x;
  real_T c23_m_x;
  real_T c23_n_x;
  real_T c23_o_x;
  real_T c23_p_x;
  real_T c23_q_x;
  real_T c23_r_x;
  real_T c23_s_x;
  real_T c23_t_x;
  real_T c23_u_x;
  real_T c23_v_x;
  real_T c23_w_x;
  real_T c23_x_x;
  int32_T c23_i12;
  int32_T c23_i13;
  static real_T c23_dv2[4] = { 0.0, 0.0, 1.0, 0.0 };

  int32_T c23_i14;
  int32_T c23_i15;
  static real_T c23_dv3[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c23_i16;
  int32_T c23_i17;
  static real_T c23_dv4[4] = { 0.0, 1.0, 0.0, 0.0 };

  int32_T c23_i18;
  int32_T c23_i19;
  int32_T c23_i20;
  int32_T c23_i21;
  int32_T c23_i22;
  int32_T c23_i23;
  int32_T c23_i24;
  int32_T c23_i25;
  int32_T c23_i26;
  int32_T c23_i27;
  int32_T c23_i28;
  int32_T c23_i29;
  int32_T c23_i30;
  int32_T c23_i31;
  int32_T c23_i32;
  int32_T c23_i33;
  int32_T c23_i34;
  int32_T c23_i35;
  int32_T c23_i36;
  int32_T c23_i37;
  int32_T c23_i38;
  int32_T c23_i39;
  int32_T c23_i40;
  int32_T c23_i41;
  int32_T c23_i42;
  int32_T c23_i43;
  int32_T c23_i44;
  int32_T c23_i45;
  int32_T c23_i46;
  int32_T c23_i47;
  int32_T c23_i48;
  int32_T c23_i49;
  int32_T c23_i50;
  int32_T c23_i51;
  int32_T c23_i52;
  int32_T c23_i53;
  int32_T c23_i54;
  int32_T c23_i55;
  int32_T c23_i56;
  int32_T c23_i57;
  int32_T c23_i58;
  real_T c23_b_a[16];
  int32_T c23_i59;
  real_T c23_b[16];
  int32_T c23_i60;
  real_T c23_A[16];
  int32_T c23_i61;
  real_T c23_B[16];
  int32_T c23_i62;
  real_T c23_b_A[16];
  int32_T c23_i63;
  real_T c23_b_B[16];
  int32_T c23_i64;
  real_T c23_c_A[16];
  int32_T c23_i65;
  real_T c23_c_B[16];
  int32_T c23_i66;
  int32_T c23_i67;
  int32_T c23_i68;
  real_T c23_c_a[16];
  int32_T c23_i69;
  int32_T c23_i70;
  int32_T c23_i71;
  real_T c23_b_b[16];
  int32_T c23_i72;
  real_T c23_d_A[16];
  int32_T c23_i73;
  real_T c23_d_B[16];
  int32_T c23_i74;
  real_T c23_e_A[16];
  int32_T c23_i75;
  real_T c23_e_B[16];
  int32_T c23_i76;
  real_T c23_f_A[16];
  int32_T c23_i77;
  real_T c23_f_B[16];
  int32_T c23_i78;
  int32_T c23_i79;
  int32_T c23_i80;
  real_T c23_d_a[16];
  int32_T c23_i81;
  int32_T c23_i82;
  int32_T c23_i83;
  real_T c23_c_b[16];
  int32_T c23_i84;
  real_T c23_g_A[16];
  int32_T c23_i85;
  real_T c23_g_B[16];
  int32_T c23_i86;
  real_T c23_h_A[16];
  int32_T c23_i87;
  real_T c23_h_B[16];
  int32_T c23_i88;
  real_T c23_i_A[16];
  int32_T c23_i89;
  real_T c23_i_B[16];
  int32_T c23_i90;
  int32_T c23_i91;
  int32_T c23_i92;
  real_T c23_e_a[16];
  int32_T c23_i93;
  int32_T c23_i94;
  int32_T c23_i95;
  real_T c23_d_b[16];
  int32_T c23_i96;
  real_T c23_j_A[16];
  int32_T c23_i97;
  real_T c23_j_B[16];
  int32_T c23_i98;
  real_T c23_k_A[16];
  int32_T c23_i99;
  real_T c23_k_B[16];
  int32_T c23_i100;
  real_T c23_l_A[16];
  int32_T c23_i101;
  real_T c23_l_B[16];
  int32_T c23_i102;
  int32_T c23_i103;
  int32_T c23_i104;
  real_T c23_f_a[16];
  int32_T c23_i105;
  int32_T c23_i106;
  int32_T c23_i107;
  real_T c23_e_b[16];
  int32_T c23_i108;
  real_T c23_m_A[16];
  int32_T c23_i109;
  real_T c23_m_B[16];
  int32_T c23_i110;
  real_T c23_n_A[16];
  int32_T c23_i111;
  real_T c23_n_B[16];
  int32_T c23_i112;
  real_T c23_o_A[16];
  int32_T c23_i113;
  real_T c23_o_B[16];
  int32_T c23_i114;
  int32_T c23_i115;
  int32_T c23_i116;
  real_T c23_g_a[16];
  int32_T c23_i117;
  int32_T c23_i118;
  int32_T c23_i119;
  real_T c23_p_A[16];
  int32_T c23_i120;
  int32_T c23_i121;
  real_T c23_q_A[16];
  int32_T c23_i122;
  real_T c23_r_A[16];
  int32_T c23_i123;
  int32_T c23_i124;
  int32_T c23_i125;
  int32_T c23_i126;
  int32_T c23_i127;
  int32_T c23_i128;
  int32_T c23_i129;
  int32_T c23_i130;
  real_T c23_h_a[9];
  int32_T c23_i131;
  int32_T c23_i132;
  int32_T c23_i133;
  int32_T c23_i134;
  real_T c23_f_b[9];
  int32_T c23_i135;
  real_T c23_s_A[9];
  int32_T c23_i136;
  real_T c23_p_B[9];
  int32_T c23_i137;
  real_T c23_t_A[9];
  int32_T c23_i138;
  real_T c23_q_B[9];
  int32_T c23_i139;
  real_T c23_u_A[9];
  int32_T c23_i140;
  real_T c23_r_B[9];
  int32_T c23_i141;
  int32_T c23_i142;
  int32_T c23_i143;
  real_T c23_i_a[9];
  int32_T c23_i144;
  int32_T c23_i145;
  int32_T c23_i146;
  int32_T c23_i147;
  int32_T c23_i148;
  int32_T c23_i149;
  real_T c23_g_b[9];
  int32_T c23_i150;
  real_T c23_v_A[9];
  int32_T c23_i151;
  real_T c23_s_B[9];
  int32_T c23_i152;
  real_T c23_w_A[9];
  int32_T c23_i153;
  real_T c23_t_B[9];
  int32_T c23_i154;
  real_T c23_x_A[9];
  int32_T c23_i155;
  real_T c23_u_B[9];
  int32_T c23_i156;
  int32_T c23_i157;
  int32_T c23_i158;
  real_T c23_j_a[9];
  int32_T c23_i159;
  int32_T c23_i160;
  int32_T c23_i161;
  int32_T c23_i162;
  int32_T c23_i163;
  int32_T c23_i164;
  real_T c23_h_b[9];
  int32_T c23_i165;
  real_T c23_y_A[9];
  int32_T c23_i166;
  real_T c23_v_B[9];
  int32_T c23_i167;
  real_T c23_ab_A[9];
  int32_T c23_i168;
  real_T c23_w_B[9];
  int32_T c23_i169;
  real_T c23_bb_A[9];
  int32_T c23_i170;
  real_T c23_x_B[9];
  int32_T c23_i171;
  int32_T c23_i172;
  int32_T c23_i173;
  real_T c23_k_a[9];
  int32_T c23_i174;
  int32_T c23_i175;
  int32_T c23_i176;
  int32_T c23_i177;
  int32_T c23_i178;
  int32_T c23_i179;
  real_T c23_i_b[9];
  int32_T c23_i180;
  real_T c23_cb_A[9];
  int32_T c23_i181;
  real_T c23_y_B[9];
  int32_T c23_i182;
  real_T c23_db_A[9];
  int32_T c23_i183;
  real_T c23_ab_B[9];
  int32_T c23_i184;
  real_T c23_eb_A[9];
  int32_T c23_i185;
  real_T c23_bb_B[9];
  int32_T c23_i186;
  int32_T c23_i187;
  int32_T c23_i188;
  real_T c23_l_a[9];
  int32_T c23_i189;
  int32_T c23_i190;
  int32_T c23_i191;
  int32_T c23_i192;
  int32_T c23_i193;
  int32_T c23_i194;
  real_T c23_j_b[9];
  int32_T c23_i195;
  real_T c23_fb_A[9];
  int32_T c23_i196;
  real_T c23_cb_B[9];
  int32_T c23_i197;
  int32_T c23_i198;
  real_T c23_gb_A[9];
  int32_T c23_i199;
  real_T c23_db_B[9];
  int32_T c23_i200;
  real_T c23_hb_A[9];
  int32_T c23_i201;
  real_T c23_eb_B[9];
  int32_T c23_i202;
  int32_T c23_i203;
  int32_T c23_i204;
  int32_T c23_i205;
  int32_T c23_i206;
  int32_T c23_i207;
  real_T c23_D[9];
  real_T c23_b_nargout = 1.0;
  real_T c23_b_nargin = 1.0;
  real_T c23_y_x;
  real_T c23_ab_x;
  real_T c23_bb_x;
  real_T c23_d0;
  real_T c23_d1;
  real_T c23_dv5[3];
  int32_T c23_i208;
  int32_T c23_i209;
  real_T c23_k_b[3];
  int32_T c23_i210;
  real_T c23_y[3];
  int32_T c23_i211;
  int32_T c23_i212;
  real_T (*c23_b_out)[6];
  real_T (*c23_b_vec)[6];
  c23_b_vec = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 0);
  c23_b_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,16);
  for (c23_i5 = 0; c23_i5 < 6; c23_i5 = c23_i5 + 1) {
    c23_vec[c23_i5] = (*c23_b_vec)[c23_i5];
  }

  sf_debug_symbol_scope_push(51U, 0U);
  sf_debug_symbol_scope_add("nargout", &c23_nargout, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c23_nargin, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("eul_ang", &c23_eul_ang, c23_e_sf_marshall);
  sf_debug_symbol_scope_add("E", &c23_E, c23_d_sf_marshall);
  sf_debug_symbol_scope_add("pos", &c23_pos, c23_e_sf_marshall);
  sf_debug_symbol_scope_add("p", &c23_p, c23_f_sf_marshall);
  sf_debug_symbol_scope_add("x6", &c23_x6, c23_f_sf_marshall);
  sf_debug_symbol_scope_add("x_cabin", &c23_x_cabin, c23_e_sf_marshall);
  sf_debug_symbol_scope_add("E6", &c23_E6, c23_d_sf_marshall);
  sf_debug_symbol_scope_add("E5", &c23_E5, c23_d_sf_marshall);
  sf_debug_symbol_scope_add("E4", &c23_E4, c23_d_sf_marshall);
  sf_debug_symbol_scope_add("E3", &c23_E3, c23_d_sf_marshall);
  sf_debug_symbol_scope_add("E2", &c23_E2, c23_d_sf_marshall);
  sf_debug_symbol_scope_add("E1", &c23_E1, c23_d_sf_marshall);
  sf_debug_symbol_scope_add("D6", &c23_D6, c23_c_sf_marshall);
  sf_debug_symbol_scope_add("D5", &c23_D5, c23_c_sf_marshall);
  sf_debug_symbol_scope_add("D4", &c23_D4, c23_c_sf_marshall);
  sf_debug_symbol_scope_add("D3", &c23_D3, c23_c_sf_marshall);
  sf_debug_symbol_scope_add("D2", &c23_D2, c23_c_sf_marshall);
  sf_debug_symbol_scope_add("D1", &c23_D1, c23_c_sf_marshall);
  sf_debug_symbol_scope_add("SA6", &c23_SA6, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("CA6", &c23_CA6, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("SA5", &c23_SA5, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("CA5", &c23_CA5, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("SA4", &c23_SA4, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("CA4", &c23_CA4, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("SA3", &c23_SA3, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("CA3", &c23_CA3, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("SA2", &c23_SA2, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("CA2", &c23_CA2, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("SA1", &c23_SA1, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("CA1", &c23_CA1, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("A6", &c23_A6, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("A5", &c23_A5, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("A4", &c23_A4, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("A3", &c23_A3, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("A2", &c23_A2, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("A1", &c23_A1, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("Height_A2", &c23_Height_A2, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("d", &c23_d, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("l5", &c23_l5, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("l4", &c23_l4, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("l3", &c23_l3, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("l2", &c23_l2, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("l1", &c23_l1, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("ang", &c23_ang, c23_sf_marshall);
  sf_debug_symbol_scope_add("J_ANG", &c23_J_ANG, c23_sf_marshall);
  sf_debug_symbol_scope_add("RTD", &c23_RTD, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("DTR", &c23_DTR, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("out", &c23_out, c23_sf_marshall);
  sf_debug_symbol_scope_add("vec", &c23_vec, c23_sf_marshall);
  CV_EML_FCN(0, 0);

  /* -------------------------------------------------------------------------- */
  /*  */
  /*    This function solves the FORWARD kinematics of the 6-DOF KUKA arm and */
  /*    wrist. This is the  version, */
  /*    embedded in Simulink. The input and output are vectors that include the */
  /*    list of parameters as defined herafter */
  /*  */
  /*        *** Input variables, vec(1:13) *** */
  /*  */
  /*    vec(1: 3)    POS         Room coordinates of flange, NED in cm */
  /*    vec(4: 6)    EUL_ANG     Euler angles of the flange, phi, theta, psi, in deg */
  /*    vec(1:6)     J_ANG_0     The joint angles, in deg */
  /*  */
  /*        *** Output Variables *** */
  /*  */
  /*    out(1: 3)    POS         Room coordinates of flange, NED in cm */
  /*    out(4: 6)    EUL_ANG     Euler angles of the flange, phi, theta, psi, in deg */
  /*  */
  /*    The North_East_Down convention is used and psi, theta, phi rotation */
  /*    sequence; A2, A3, A5 are up positive and A4, A6 right rotation positive */
  /*    Note that this is different from the KUKA convention */
  /*  */
  /*    Written by Arthur J. Grunwald, Nov. 23, 2014 */
  /*  */
  /* -------------------------------------------------------------------------- */
  _SFD_EML_CALL(0,29);
  c23_DTR = 1.7453292519943295E-002;
  _SFD_EML_CALL(0,30);
  c23_RTD = 5.7295779513082323E+001;

  /*  reload variables */
  /*  the algorithm works in rad, so ang is in rad */
  _SFD_EML_CALL(0,34);
  for (c23_i6 = 0; c23_i6 < 6; c23_i6 = c23_i6 + 1) {
    c23_J_ANG[c23_i6] = c23_vec[c23_i6];
  }

  /*  Initial guess of the joint angles, in deg */
  _SFD_EML_CALL(0,35);
  for (c23_i7 = 0; c23_i7 < 6; c23_i7 = c23_i7 + 1) {
    c23_a[c23_i7] = c23_J_ANG[c23_i7];
  }

  for (c23_i8 = 0; c23_i8 < 6; c23_i8 = c23_i8 + 1) {
    c23_ang[c23_i8] = c23_a[c23_i8] * 1.7453292519943295E-002;
  }

  /*  reserve place for output */
  _SFD_EML_CALL(0,38);
  for (c23_i9 = 0; c23_i9 < 6; c23_i9 = c23_i9 + 1) {
    c23_out[c23_i9] = 0.0;
  }

  /*  define length of arms */
  _SFD_EML_CALL(0,41);
  c23_l1 = 50.0;

  /*  arm length in cm */
  _SFD_EML_CALL(0,42);
  c23_l2 = 130.0;
  _SFD_EML_CALL(0,43);
  c23_l3 = 66.0;
  _SFD_EML_CALL(0,44);
  c23_l4 = 36.5;
  _SFD_EML_CALL(0,45);
  c23_l5 = 29.0;
  _SFD_EML_CALL(0,46);
  c23_d = 5.5;

  /*  vertical offset of the center line of */
  /*  joint 4 from centerline of arm A3 */
  _SFD_EML_CALL(0,48);
  c23_Height_A2 = 210.5;

  /*  height link A2 above the ground */
  /*  4x4 Transfer matrices, include both rotation and translation */
  _SFD_EML_CALL(0,53);
  for (c23_i10 = 0; c23_i10 < 6; c23_i10 = c23_i10 + 1) {
    c23_b_ang[c23_i10] = c23_ang[c23_i10];
  }

  c23_adjust_ang(c23_b_ang, c23_dv1);
  for (c23_i11 = 0; c23_i11 < 6; c23_i11 = c23_i11 + 1) {
    c23_ang[c23_i11] = c23_dv1[c23_i11];
  }

  /*  ang is brought in the range +-pi */
  _SFD_EML_CALL(0,54);
  c23_A1 = c23_ang[0];
  _SFD_EML_CALL(0,55);
  c23_A2 = c23_ang[1];
  _SFD_EML_CALL(0,56);
  c23_A3 = c23_ang[2];
  _SFD_EML_CALL(0,57);
  c23_A4 = c23_ang[3];
  _SFD_EML_CALL(0,58);
  c23_A5 = c23_ang[4];
  _SFD_EML_CALL(0,59);
  c23_A6 = c23_ang[5];
  _SFD_EML_CALL(0,61);
  c23_x = c23_A1;
  c23_CA1 = c23_x;
  c23_b_x = c23_CA1;
  c23_CA1 = c23_b_x;
  c23_CA1 = muDoubleScalarCos(c23_CA1);
  _SFD_EML_CALL(0,62);
  c23_c_x = c23_A1;
  c23_SA1 = c23_c_x;
  c23_d_x = c23_SA1;
  c23_SA1 = c23_d_x;
  c23_SA1 = muDoubleScalarSin(c23_SA1);
  _SFD_EML_CALL(0,63);
  c23_e_x = c23_A2;
  c23_CA2 = c23_e_x;
  c23_f_x = c23_CA2;
  c23_CA2 = c23_f_x;
  c23_CA2 = muDoubleScalarCos(c23_CA2);
  _SFD_EML_CALL(0,64);
  c23_g_x = c23_A2;
  c23_SA2 = c23_g_x;
  c23_h_x = c23_SA2;
  c23_SA2 = c23_h_x;
  c23_SA2 = muDoubleScalarSin(c23_SA2);
  _SFD_EML_CALL(0,65);
  c23_i_x = c23_A3;
  c23_CA3 = c23_i_x;
  c23_j_x = c23_CA3;
  c23_CA3 = c23_j_x;
  c23_CA3 = muDoubleScalarCos(c23_CA3);
  _SFD_EML_CALL(0,66);
  c23_k_x = c23_A3;
  c23_SA3 = c23_k_x;
  c23_l_x = c23_SA3;
  c23_SA3 = c23_l_x;
  c23_SA3 = muDoubleScalarSin(c23_SA3);
  _SFD_EML_CALL(0,67);
  c23_m_x = c23_A4;
  c23_CA4 = c23_m_x;
  c23_n_x = c23_CA4;
  c23_CA4 = c23_n_x;
  c23_CA4 = muDoubleScalarCos(c23_CA4);
  _SFD_EML_CALL(0,68);
  c23_o_x = c23_A4;
  c23_SA4 = c23_o_x;
  c23_p_x = c23_SA4;
  c23_SA4 = c23_p_x;
  c23_SA4 = muDoubleScalarSin(c23_SA4);
  _SFD_EML_CALL(0,69);
  c23_q_x = c23_A5;
  c23_CA5 = c23_q_x;
  c23_r_x = c23_CA5;
  c23_CA5 = c23_r_x;
  c23_CA5 = muDoubleScalarCos(c23_CA5);
  _SFD_EML_CALL(0,70);
  c23_s_x = c23_A5;
  c23_SA5 = c23_s_x;
  c23_t_x = c23_SA5;
  c23_SA5 = c23_t_x;
  c23_SA5 = muDoubleScalarSin(c23_SA5);
  _SFD_EML_CALL(0,71);
  c23_u_x = c23_A6;
  c23_CA6 = c23_u_x;
  c23_v_x = c23_CA6;
  c23_CA6 = c23_v_x;
  c23_CA6 = muDoubleScalarCos(c23_CA6);
  _SFD_EML_CALL(0,72);
  c23_w_x = c23_A6;
  c23_SA6 = c23_w_x;
  c23_x_x = c23_SA6;
  c23_SA6 = c23_x_x;
  c23_SA6 = muDoubleScalarSin(c23_SA6);
  _SFD_EML_CALL(0,74);
  c23_D1[0] = c23_CA1;
  c23_D1[4] = -c23_SA1;
  c23_D1[8] = 0.0;
  c23_D1[12] = 0.0;
  c23_D1[1] = c23_SA1;
  c23_D1[5] = c23_CA1;
  c23_D1[9] = 0.0;
  c23_D1[13] = 0.0;
  c23_i12 = 0;
  for (c23_i13 = 0; c23_i13 < 4; c23_i13 = c23_i13 + 1) {
    c23_D1[c23_i12 + 2] = c23_dv2[c23_i13];
    c23_i12 = c23_i12 + 4;
  }

  c23_i14 = 0;
  for (c23_i15 = 0; c23_i15 < 4; c23_i15 = c23_i15 + 1) {
    c23_D1[c23_i14 + 3] = c23_dv3[c23_i15];
    c23_i14 = c23_i14 + 4;
  }

  _SFD_EML_CALL(0,75);
  c23_D2[0] = c23_CA2;
  c23_D2[4] = 0.0;
  c23_D2[8] = c23_SA2;
  c23_D2[12] = c23_l1;
  c23_i16 = 0;
  for (c23_i17 = 0; c23_i17 < 4; c23_i17 = c23_i17 + 1) {
    c23_D2[c23_i16 + 1] = c23_dv4[c23_i17];
    c23_i16 = c23_i16 + 4;
  }

  c23_D2[2] = -c23_SA2;
  c23_D2[6] = 0.0;
  c23_D2[10] = c23_CA2;
  c23_D2[14] = 0.0;
  c23_i18 = 0;
  for (c23_i19 = 0; c23_i19 < 4; c23_i19 = c23_i19 + 1) {
    c23_D2[c23_i18 + 3] = c23_dv3[c23_i19];
    c23_i18 = c23_i18 + 4;
  }

  _SFD_EML_CALL(0,76);
  c23_D3[0] = c23_CA3;
  c23_D3[4] = 0.0;
  c23_D3[8] = c23_SA3;
  c23_D3[12] = c23_l2;
  c23_i20 = 0;
  for (c23_i21 = 0; c23_i21 < 4; c23_i21 = c23_i21 + 1) {
    c23_D3[c23_i20 + 1] = c23_dv4[c23_i21];
    c23_i20 = c23_i20 + 4;
  }

  c23_D3[2] = -c23_SA3;
  c23_D3[6] = 0.0;
  c23_D3[10] = c23_CA3;
  c23_D3[14] = 0.0;
  c23_i22 = 0;
  for (c23_i23 = 0; c23_i23 < 4; c23_i23 = c23_i23 + 1) {
    c23_D3[c23_i22 + 3] = c23_dv3[c23_i23];
    c23_i22 = c23_i22 + 4;
  }

  _SFD_EML_CALL(0,77);
  c23_D4[0] = 1.0;
  c23_D4[4] = 0.0;
  c23_D4[8] = 0.0;
  c23_D4[12] = c23_l3;
  c23_D4[1] = 0.0;
  c23_D4[5] = c23_CA4;
  c23_D4[9] = -c23_SA4;
  c23_D4[13] = 0.0;
  c23_D4[2] = 0.0;
  c23_D4[6] = c23_SA4;
  c23_D4[10] = c23_CA4;
  c23_D4[14] = c23_d;
  c23_i24 = 0;
  for (c23_i25 = 0; c23_i25 < 4; c23_i25 = c23_i25 + 1) {
    c23_D4[c23_i24 + 3] = c23_dv3[c23_i25];
    c23_i24 = c23_i24 + 4;
  }

  _SFD_EML_CALL(0,78);
  c23_D5[0] = c23_CA5;
  c23_D5[4] = 0.0;
  c23_D5[8] = c23_SA5;
  c23_D5[12] = c23_l4;
  c23_i26 = 0;
  for (c23_i27 = 0; c23_i27 < 4; c23_i27 = c23_i27 + 1) {
    c23_D5[c23_i26 + 1] = c23_dv4[c23_i27];
    c23_i26 = c23_i26 + 4;
  }

  c23_D5[2] = -c23_SA5;
  c23_D5[6] = 0.0;
  c23_D5[10] = c23_CA5;
  c23_D5[14] = 0.0;
  c23_i28 = 0;
  for (c23_i29 = 0; c23_i29 < 4; c23_i29 = c23_i29 + 1) {
    c23_D5[c23_i28 + 3] = c23_dv3[c23_i29];
    c23_i28 = c23_i28 + 4;
  }

  _SFD_EML_CALL(0,79);
  c23_D6[0] = 1.0;
  c23_D6[4] = 0.0;
  c23_D6[8] = 0.0;
  c23_D6[12] = c23_l5;
  c23_D6[1] = 0.0;
  c23_D6[5] = c23_CA6;
  c23_D6[9] = -c23_SA6;
  c23_D6[13] = 0.0;
  c23_D6[2] = 0.0;
  c23_D6[6] = c23_SA6;
  c23_D6[10] = c23_CA6;
  c23_D6[14] = 0.0;
  c23_i30 = 0;
  for (c23_i31 = 0; c23_i31 < 4; c23_i31 = c23_i31 + 1) {
    c23_D6[c23_i30 + 3] = c23_dv3[c23_i31];
    c23_i30 = c23_i30 + 4;
  }

  /*  cut out the 3x3 DCM's for each of the transfer matrices */
  /*  Note that the DCM is for rotation from b->e */
  _SFD_EML_CALL(0,83);
  c23_i32 = 0;
  c23_i33 = 0;
  for (c23_i34 = 0; c23_i34 < 3; c23_i34 = c23_i34 + 1) {
    for (c23_i35 = 0; c23_i35 < 3; c23_i35 = c23_i35 + 1) {
      c23_E1[c23_i35 + c23_i32] = c23_D1[c23_i35 + c23_i33];
    }

    c23_i32 = c23_i32 + 3;
    c23_i33 = c23_i33 + 4;
  }

  _SFD_EML_CALL(0,84);
  c23_i36 = 0;
  c23_i37 = 0;
  for (c23_i38 = 0; c23_i38 < 3; c23_i38 = c23_i38 + 1) {
    for (c23_i39 = 0; c23_i39 < 3; c23_i39 = c23_i39 + 1) {
      c23_E2[c23_i39 + c23_i36] = c23_D2[c23_i39 + c23_i37];
    }

    c23_i36 = c23_i36 + 3;
    c23_i37 = c23_i37 + 4;
  }

  _SFD_EML_CALL(0,85);
  c23_i40 = 0;
  c23_i41 = 0;
  for (c23_i42 = 0; c23_i42 < 3; c23_i42 = c23_i42 + 1) {
    for (c23_i43 = 0; c23_i43 < 3; c23_i43 = c23_i43 + 1) {
      c23_E3[c23_i43 + c23_i40] = c23_D3[c23_i43 + c23_i41];
    }

    c23_i40 = c23_i40 + 3;
    c23_i41 = c23_i41 + 4;
  }

  _SFD_EML_CALL(0,86);
  c23_i44 = 0;
  c23_i45 = 0;
  for (c23_i46 = 0; c23_i46 < 3; c23_i46 = c23_i46 + 1) {
    for (c23_i47 = 0; c23_i47 < 3; c23_i47 = c23_i47 + 1) {
      c23_E4[c23_i47 + c23_i44] = c23_D4[c23_i47 + c23_i45];
    }

    c23_i44 = c23_i44 + 3;
    c23_i45 = c23_i45 + 4;
  }

  _SFD_EML_CALL(0,87);
  c23_i48 = 0;
  c23_i49 = 0;
  for (c23_i50 = 0; c23_i50 < 3; c23_i50 = c23_i50 + 1) {
    for (c23_i51 = 0; c23_i51 < 3; c23_i51 = c23_i51 + 1) {
      c23_E5[c23_i51 + c23_i48] = c23_D5[c23_i51 + c23_i49];
    }

    c23_i48 = c23_i48 + 3;
    c23_i49 = c23_i49 + 4;
  }

  _SFD_EML_CALL(0,88);
  c23_i52 = 0;
  c23_i53 = 0;
  for (c23_i54 = 0; c23_i54 < 3; c23_i54 = c23_i54 + 1) {
    for (c23_i55 = 0; c23_i55 < 3; c23_i55 = c23_i55 + 1) {
      c23_E6[c23_i55 + c23_i52] = c23_D6[c23_i55 + c23_i53];
    }

    c23_i52 = c23_i52 + 3;
    c23_i53 = c23_i53 + 4;
  }

  /*  --- computed position from links A1-A6 --- */
  _SFD_EML_CALL(0,92);
  for (c23_i56 = 0; c23_i56 < 3; c23_i56 = c23_i56 + 1) {
    c23_x_cabin[c23_i56] = 0.0;
  }

  /*  x,y,z cabin reference point (cm) */
  /*  to which the translation is made */
  _SFD_EML_CALL(0,94);
  for (c23_i57 = 0; c23_i57 < 4; c23_i57 = c23_i57 + 1) {
    c23_x6[c23_i57] = c23_dv3[c23_i57];
  }

  _SFD_EML_CALL(0,95);
  for (c23_i58 = 0; c23_i58 < 16; c23_i58 = c23_i58 + 1) {
    c23_b_a[c23_i58] = c23_D1[c23_i58];
  }

  for (c23_i59 = 0; c23_i59 < 16; c23_i59 = c23_i59 + 1) {
    c23_b[c23_i59] = c23_D2[c23_i59];
  }

  c23_eml_scalar_eg();
  c23_eml_scalar_eg();
  for (c23_i60 = 0; c23_i60 < 16; c23_i60 = c23_i60 + 1) {
    c23_A[c23_i60] = c23_b_a[c23_i60];
  }

  for (c23_i61 = 0; c23_i61 < 16; c23_i61 = c23_i61 + 1) {
    c23_B[c23_i61] = c23_b[c23_i61];
  }

  for (c23_i62 = 0; c23_i62 < 16; c23_i62 = c23_i62 + 1) {
    c23_b_A[c23_i62] = c23_A[c23_i62];
  }

  for (c23_i63 = 0; c23_i63 < 16; c23_i63 = c23_i63 + 1) {
    c23_b_B[c23_i63] = c23_B[c23_i63];
  }

  for (c23_i64 = 0; c23_i64 < 16; c23_i64 = c23_i64 + 1) {
    c23_c_A[c23_i64] = c23_b_A[c23_i64];
  }

  for (c23_i65 = 0; c23_i65 < 16; c23_i65 = c23_i65 + 1) {
    c23_c_B[c23_i65] = c23_b_B[c23_i65];
  }

  for (c23_i66 = 0; c23_i66 < 4; c23_i66 = c23_i66 + 1) {
    c23_i67 = 0;
    for (c23_i68 = 0; c23_i68 < 4; c23_i68 = c23_i68 + 1) {
      c23_c_a[c23_i67 + c23_i66] = 0.0;
      c23_i69 = 0;
      for (c23_i70 = 0; c23_i70 < 4; c23_i70 = c23_i70 + 1) {
        c23_c_a[c23_i67 + c23_i66] = c23_c_a[c23_i67 + c23_i66] +
          c23_c_A[c23_i69 + c23_i66] * c23_c_B[c23_i70 + c23_i67];
        c23_i69 = c23_i69 + 4;
      }

      c23_i67 = c23_i67 + 4;
    }
  }

  for (c23_i71 = 0; c23_i71 < 16; c23_i71 = c23_i71 + 1) {
    c23_b_b[c23_i71] = c23_D3[c23_i71];
  }

  c23_eml_scalar_eg();
  c23_eml_scalar_eg();
  for (c23_i72 = 0; c23_i72 < 16; c23_i72 = c23_i72 + 1) {
    c23_d_A[c23_i72] = c23_c_a[c23_i72];
  }

  for (c23_i73 = 0; c23_i73 < 16; c23_i73 = c23_i73 + 1) {
    c23_d_B[c23_i73] = c23_b_b[c23_i73];
  }

  for (c23_i74 = 0; c23_i74 < 16; c23_i74 = c23_i74 + 1) {
    c23_e_A[c23_i74] = c23_d_A[c23_i74];
  }

  for (c23_i75 = 0; c23_i75 < 16; c23_i75 = c23_i75 + 1) {
    c23_e_B[c23_i75] = c23_d_B[c23_i75];
  }

  for (c23_i76 = 0; c23_i76 < 16; c23_i76 = c23_i76 + 1) {
    c23_f_A[c23_i76] = c23_e_A[c23_i76];
  }

  for (c23_i77 = 0; c23_i77 < 16; c23_i77 = c23_i77 + 1) {
    c23_f_B[c23_i77] = c23_e_B[c23_i77];
  }

  for (c23_i78 = 0; c23_i78 < 4; c23_i78 = c23_i78 + 1) {
    c23_i79 = 0;
    for (c23_i80 = 0; c23_i80 < 4; c23_i80 = c23_i80 + 1) {
      c23_d_a[c23_i79 + c23_i78] = 0.0;
      c23_i81 = 0;
      for (c23_i82 = 0; c23_i82 < 4; c23_i82 = c23_i82 + 1) {
        c23_d_a[c23_i79 + c23_i78] = c23_d_a[c23_i79 + c23_i78] +
          c23_f_A[c23_i81 + c23_i78] * c23_f_B[c23_i82 + c23_i79];
        c23_i81 = c23_i81 + 4;
      }

      c23_i79 = c23_i79 + 4;
    }
  }

  for (c23_i83 = 0; c23_i83 < 16; c23_i83 = c23_i83 + 1) {
    c23_c_b[c23_i83] = c23_D4[c23_i83];
  }

  c23_eml_scalar_eg();
  c23_eml_scalar_eg();
  for (c23_i84 = 0; c23_i84 < 16; c23_i84 = c23_i84 + 1) {
    c23_g_A[c23_i84] = c23_d_a[c23_i84];
  }

  for (c23_i85 = 0; c23_i85 < 16; c23_i85 = c23_i85 + 1) {
    c23_g_B[c23_i85] = c23_c_b[c23_i85];
  }

  for (c23_i86 = 0; c23_i86 < 16; c23_i86 = c23_i86 + 1) {
    c23_h_A[c23_i86] = c23_g_A[c23_i86];
  }

  for (c23_i87 = 0; c23_i87 < 16; c23_i87 = c23_i87 + 1) {
    c23_h_B[c23_i87] = c23_g_B[c23_i87];
  }

  for (c23_i88 = 0; c23_i88 < 16; c23_i88 = c23_i88 + 1) {
    c23_i_A[c23_i88] = c23_h_A[c23_i88];
  }

  for (c23_i89 = 0; c23_i89 < 16; c23_i89 = c23_i89 + 1) {
    c23_i_B[c23_i89] = c23_h_B[c23_i89];
  }

  for (c23_i90 = 0; c23_i90 < 4; c23_i90 = c23_i90 + 1) {
    c23_i91 = 0;
    for (c23_i92 = 0; c23_i92 < 4; c23_i92 = c23_i92 + 1) {
      c23_e_a[c23_i91 + c23_i90] = 0.0;
      c23_i93 = 0;
      for (c23_i94 = 0; c23_i94 < 4; c23_i94 = c23_i94 + 1) {
        c23_e_a[c23_i91 + c23_i90] = c23_e_a[c23_i91 + c23_i90] +
          c23_i_A[c23_i93 + c23_i90] * c23_i_B[c23_i94 + c23_i91];
        c23_i93 = c23_i93 + 4;
      }

      c23_i91 = c23_i91 + 4;
    }
  }

  for (c23_i95 = 0; c23_i95 < 16; c23_i95 = c23_i95 + 1) {
    c23_d_b[c23_i95] = c23_D5[c23_i95];
  }

  c23_eml_scalar_eg();
  c23_eml_scalar_eg();
  for (c23_i96 = 0; c23_i96 < 16; c23_i96 = c23_i96 + 1) {
    c23_j_A[c23_i96] = c23_e_a[c23_i96];
  }

  for (c23_i97 = 0; c23_i97 < 16; c23_i97 = c23_i97 + 1) {
    c23_j_B[c23_i97] = c23_d_b[c23_i97];
  }

  for (c23_i98 = 0; c23_i98 < 16; c23_i98 = c23_i98 + 1) {
    c23_k_A[c23_i98] = c23_j_A[c23_i98];
  }

  for (c23_i99 = 0; c23_i99 < 16; c23_i99 = c23_i99 + 1) {
    c23_k_B[c23_i99] = c23_j_B[c23_i99];
  }

  for (c23_i100 = 0; c23_i100 < 16; c23_i100 = c23_i100 + 1) {
    c23_l_A[c23_i100] = c23_k_A[c23_i100];
  }

  for (c23_i101 = 0; c23_i101 < 16; c23_i101 = c23_i101 + 1) {
    c23_l_B[c23_i101] = c23_k_B[c23_i101];
  }

  for (c23_i102 = 0; c23_i102 < 4; c23_i102 = c23_i102 + 1) {
    c23_i103 = 0;
    for (c23_i104 = 0; c23_i104 < 4; c23_i104 = c23_i104 + 1) {
      c23_f_a[c23_i103 + c23_i102] = 0.0;
      c23_i105 = 0;
      for (c23_i106 = 0; c23_i106 < 4; c23_i106 = c23_i106 + 1) {
        c23_f_a[c23_i103 + c23_i102] = c23_f_a[c23_i103 + c23_i102] +
          c23_l_A[c23_i105 + c23_i102] * c23_l_B[c23_i106 + c23_i103];
        c23_i105 = c23_i105 + 4;
      }

      c23_i103 = c23_i103 + 4;
    }
  }

  for (c23_i107 = 0; c23_i107 < 16; c23_i107 = c23_i107 + 1) {
    c23_e_b[c23_i107] = c23_D6[c23_i107];
  }

  c23_eml_scalar_eg();
  c23_eml_scalar_eg();
  for (c23_i108 = 0; c23_i108 < 16; c23_i108 = c23_i108 + 1) {
    c23_m_A[c23_i108] = c23_f_a[c23_i108];
  }

  for (c23_i109 = 0; c23_i109 < 16; c23_i109 = c23_i109 + 1) {
    c23_m_B[c23_i109] = c23_e_b[c23_i109];
  }

  for (c23_i110 = 0; c23_i110 < 16; c23_i110 = c23_i110 + 1) {
    c23_n_A[c23_i110] = c23_m_A[c23_i110];
  }

  for (c23_i111 = 0; c23_i111 < 16; c23_i111 = c23_i111 + 1) {
    c23_n_B[c23_i111] = c23_m_B[c23_i111];
  }

  for (c23_i112 = 0; c23_i112 < 16; c23_i112 = c23_i112 + 1) {
    c23_o_A[c23_i112] = c23_n_A[c23_i112];
  }

  for (c23_i113 = 0; c23_i113 < 16; c23_i113 = c23_i113 + 1) {
    c23_o_B[c23_i113] = c23_n_B[c23_i113];
  }

  for (c23_i114 = 0; c23_i114 < 4; c23_i114 = c23_i114 + 1) {
    c23_i115 = 0;
    for (c23_i116 = 0; c23_i116 < 4; c23_i116 = c23_i116 + 1) {
      c23_g_a[c23_i115 + c23_i114] = 0.0;
      c23_i117 = 0;
      for (c23_i118 = 0; c23_i118 < 4; c23_i118 = c23_i118 + 1) {
        c23_g_a[c23_i115 + c23_i114] = c23_g_a[c23_i115 + c23_i114] +
          c23_o_A[c23_i117 + c23_i114] * c23_o_B[c23_i118 + c23_i115];
        c23_i117 = c23_i117 + 4;
      }

      c23_i115 = c23_i115 + 4;
    }
  }

  c23_c_eml_scalar_eg();
  c23_c_eml_scalar_eg();
  for (c23_i119 = 0; c23_i119 < 16; c23_i119 = c23_i119 + 1) {
    c23_p_A[c23_i119] = c23_g_a[c23_i119];
  }

  for (c23_i120 = 0; c23_i120 < 4; c23_i120 = c23_i120 + 1) {
    c23_p[c23_i120] = 0.0;
  }

  for (c23_i121 = 0; c23_i121 < 16; c23_i121 = c23_i121 + 1) {
    c23_q_A[c23_i121] = c23_p_A[c23_i121];
  }

  for (c23_i122 = 0; c23_i122 < 16; c23_i122 = c23_i122 + 1) {
    c23_r_A[c23_i122] = c23_q_A[c23_i122];
  }

  for (c23_i123 = 0; c23_i123 < 4; c23_i123 = c23_i123 + 1) {
    c23_p[c23_i123] = 0.0;
    c23_i124 = 0;
    for (c23_i125 = 0; c23_i125 < 4; c23_i125 = c23_i125 + 1) {
      c23_p[c23_i123] = c23_p[c23_i123] + c23_r_A[c23_i124 + c23_i123] *
        c23_dv3[c23_i125];
      c23_i124 = c23_i124 + 4;
    }
  }

  _SFD_EML_CALL(0,96);
  for (c23_i126 = 0; c23_i126 < 3; c23_i126 = c23_i126 + 1) {
    c23_pos[c23_i126] = c23_p[c23_i126];
  }

  /*  position of the cabin reference point in the */
  /*  NED system (cm) */
  /*  computed Euler angles from links A1-A6 */
  /*  Euler matrices for rotation from e->b (note the transpose) */
  _SFD_EML_CALL(0,101);
  c23_i127 = 0;
  for (c23_i128 = 0; c23_i128 < 3; c23_i128 = c23_i128 + 1) {
    c23_i129 = 0;
    for (c23_i130 = 0; c23_i130 < 3; c23_i130 = c23_i130 + 1) {
      c23_h_a[c23_i130 + c23_i127] = c23_E6[c23_i129 + c23_i128];
      c23_i129 = c23_i129 + 3;
    }

    c23_i127 = c23_i127 + 3;
  }

  c23_i131 = 0;
  for (c23_i132 = 0; c23_i132 < 3; c23_i132 = c23_i132 + 1) {
    c23_i133 = 0;
    for (c23_i134 = 0; c23_i134 < 3; c23_i134 = c23_i134 + 1) {
      c23_f_b[c23_i134 + c23_i131] = c23_E5[c23_i133 + c23_i132];
      c23_i133 = c23_i133 + 3;
    }

    c23_i131 = c23_i131 + 3;
  }

  c23_d_eml_scalar_eg();
  c23_d_eml_scalar_eg();
  for (c23_i135 = 0; c23_i135 < 9; c23_i135 = c23_i135 + 1) {
    c23_s_A[c23_i135] = c23_h_a[c23_i135];
  }

  for (c23_i136 = 0; c23_i136 < 9; c23_i136 = c23_i136 + 1) {
    c23_p_B[c23_i136] = c23_f_b[c23_i136];
  }

  for (c23_i137 = 0; c23_i137 < 9; c23_i137 = c23_i137 + 1) {
    c23_t_A[c23_i137] = c23_s_A[c23_i137];
  }

  for (c23_i138 = 0; c23_i138 < 9; c23_i138 = c23_i138 + 1) {
    c23_q_B[c23_i138] = c23_p_B[c23_i138];
  }

  for (c23_i139 = 0; c23_i139 < 9; c23_i139 = c23_i139 + 1) {
    c23_u_A[c23_i139] = c23_t_A[c23_i139];
  }

  for (c23_i140 = 0; c23_i140 < 9; c23_i140 = c23_i140 + 1) {
    c23_r_B[c23_i140] = c23_q_B[c23_i140];
  }

  for (c23_i141 = 0; c23_i141 < 3; c23_i141 = c23_i141 + 1) {
    c23_i142 = 0;
    for (c23_i143 = 0; c23_i143 < 3; c23_i143 = c23_i143 + 1) {
      c23_i_a[c23_i142 + c23_i141] = 0.0;
      c23_i144 = 0;
      for (c23_i145 = 0; c23_i145 < 3; c23_i145 = c23_i145 + 1) {
        c23_i_a[c23_i142 + c23_i141] = c23_i_a[c23_i142 + c23_i141] +
          c23_u_A[c23_i144 + c23_i141] * c23_r_B[c23_i145 + c23_i142];
        c23_i144 = c23_i144 + 3;
      }

      c23_i142 = c23_i142 + 3;
    }
  }

  c23_i146 = 0;
  for (c23_i147 = 0; c23_i147 < 3; c23_i147 = c23_i147 + 1) {
    c23_i148 = 0;
    for (c23_i149 = 0; c23_i149 < 3; c23_i149 = c23_i149 + 1) {
      c23_g_b[c23_i149 + c23_i146] = c23_E4[c23_i148 + c23_i147];
      c23_i148 = c23_i148 + 3;
    }

    c23_i146 = c23_i146 + 3;
  }

  c23_d_eml_scalar_eg();
  c23_d_eml_scalar_eg();
  for (c23_i150 = 0; c23_i150 < 9; c23_i150 = c23_i150 + 1) {
    c23_v_A[c23_i150] = c23_i_a[c23_i150];
  }

  for (c23_i151 = 0; c23_i151 < 9; c23_i151 = c23_i151 + 1) {
    c23_s_B[c23_i151] = c23_g_b[c23_i151];
  }

  for (c23_i152 = 0; c23_i152 < 9; c23_i152 = c23_i152 + 1) {
    c23_w_A[c23_i152] = c23_v_A[c23_i152];
  }

  for (c23_i153 = 0; c23_i153 < 9; c23_i153 = c23_i153 + 1) {
    c23_t_B[c23_i153] = c23_s_B[c23_i153];
  }

  for (c23_i154 = 0; c23_i154 < 9; c23_i154 = c23_i154 + 1) {
    c23_x_A[c23_i154] = c23_w_A[c23_i154];
  }

  for (c23_i155 = 0; c23_i155 < 9; c23_i155 = c23_i155 + 1) {
    c23_u_B[c23_i155] = c23_t_B[c23_i155];
  }

  for (c23_i156 = 0; c23_i156 < 3; c23_i156 = c23_i156 + 1) {
    c23_i157 = 0;
    for (c23_i158 = 0; c23_i158 < 3; c23_i158 = c23_i158 + 1) {
      c23_j_a[c23_i157 + c23_i156] = 0.0;
      c23_i159 = 0;
      for (c23_i160 = 0; c23_i160 < 3; c23_i160 = c23_i160 + 1) {
        c23_j_a[c23_i157 + c23_i156] = c23_j_a[c23_i157 + c23_i156] +
          c23_x_A[c23_i159 + c23_i156] * c23_u_B[c23_i160 + c23_i157];
        c23_i159 = c23_i159 + 3;
      }

      c23_i157 = c23_i157 + 3;
    }
  }

  c23_i161 = 0;
  for (c23_i162 = 0; c23_i162 < 3; c23_i162 = c23_i162 + 1) {
    c23_i163 = 0;
    for (c23_i164 = 0; c23_i164 < 3; c23_i164 = c23_i164 + 1) {
      c23_h_b[c23_i164 + c23_i161] = c23_E3[c23_i163 + c23_i162];
      c23_i163 = c23_i163 + 3;
    }

    c23_i161 = c23_i161 + 3;
  }

  c23_d_eml_scalar_eg();
  c23_d_eml_scalar_eg();
  for (c23_i165 = 0; c23_i165 < 9; c23_i165 = c23_i165 + 1) {
    c23_y_A[c23_i165] = c23_j_a[c23_i165];
  }

  for (c23_i166 = 0; c23_i166 < 9; c23_i166 = c23_i166 + 1) {
    c23_v_B[c23_i166] = c23_h_b[c23_i166];
  }

  for (c23_i167 = 0; c23_i167 < 9; c23_i167 = c23_i167 + 1) {
    c23_ab_A[c23_i167] = c23_y_A[c23_i167];
  }

  for (c23_i168 = 0; c23_i168 < 9; c23_i168 = c23_i168 + 1) {
    c23_w_B[c23_i168] = c23_v_B[c23_i168];
  }

  for (c23_i169 = 0; c23_i169 < 9; c23_i169 = c23_i169 + 1) {
    c23_bb_A[c23_i169] = c23_ab_A[c23_i169];
  }

  for (c23_i170 = 0; c23_i170 < 9; c23_i170 = c23_i170 + 1) {
    c23_x_B[c23_i170] = c23_w_B[c23_i170];
  }

  for (c23_i171 = 0; c23_i171 < 3; c23_i171 = c23_i171 + 1) {
    c23_i172 = 0;
    for (c23_i173 = 0; c23_i173 < 3; c23_i173 = c23_i173 + 1) {
      c23_k_a[c23_i172 + c23_i171] = 0.0;
      c23_i174 = 0;
      for (c23_i175 = 0; c23_i175 < 3; c23_i175 = c23_i175 + 1) {
        c23_k_a[c23_i172 + c23_i171] = c23_k_a[c23_i172 + c23_i171] +
          c23_bb_A[c23_i174 + c23_i171] * c23_x_B[c23_i175 + c23_i172];
        c23_i174 = c23_i174 + 3;
      }

      c23_i172 = c23_i172 + 3;
    }
  }

  c23_i176 = 0;
  for (c23_i177 = 0; c23_i177 < 3; c23_i177 = c23_i177 + 1) {
    c23_i178 = 0;
    for (c23_i179 = 0; c23_i179 < 3; c23_i179 = c23_i179 + 1) {
      c23_i_b[c23_i179 + c23_i176] = c23_E2[c23_i178 + c23_i177];
      c23_i178 = c23_i178 + 3;
    }

    c23_i176 = c23_i176 + 3;
  }

  c23_d_eml_scalar_eg();
  c23_d_eml_scalar_eg();
  for (c23_i180 = 0; c23_i180 < 9; c23_i180 = c23_i180 + 1) {
    c23_cb_A[c23_i180] = c23_k_a[c23_i180];
  }

  for (c23_i181 = 0; c23_i181 < 9; c23_i181 = c23_i181 + 1) {
    c23_y_B[c23_i181] = c23_i_b[c23_i181];
  }

  for (c23_i182 = 0; c23_i182 < 9; c23_i182 = c23_i182 + 1) {
    c23_db_A[c23_i182] = c23_cb_A[c23_i182];
  }

  for (c23_i183 = 0; c23_i183 < 9; c23_i183 = c23_i183 + 1) {
    c23_ab_B[c23_i183] = c23_y_B[c23_i183];
  }

  for (c23_i184 = 0; c23_i184 < 9; c23_i184 = c23_i184 + 1) {
    c23_eb_A[c23_i184] = c23_db_A[c23_i184];
  }

  for (c23_i185 = 0; c23_i185 < 9; c23_i185 = c23_i185 + 1) {
    c23_bb_B[c23_i185] = c23_ab_B[c23_i185];
  }

  for (c23_i186 = 0; c23_i186 < 3; c23_i186 = c23_i186 + 1) {
    c23_i187 = 0;
    for (c23_i188 = 0; c23_i188 < 3; c23_i188 = c23_i188 + 1) {
      c23_l_a[c23_i187 + c23_i186] = 0.0;
      c23_i189 = 0;
      for (c23_i190 = 0; c23_i190 < 3; c23_i190 = c23_i190 + 1) {
        c23_l_a[c23_i187 + c23_i186] = c23_l_a[c23_i187 + c23_i186] +
          c23_eb_A[c23_i189 + c23_i186] * c23_bb_B[c23_i190 + c23_i187];
        c23_i189 = c23_i189 + 3;
      }

      c23_i187 = c23_i187 + 3;
    }
  }

  c23_i191 = 0;
  for (c23_i192 = 0; c23_i192 < 3; c23_i192 = c23_i192 + 1) {
    c23_i193 = 0;
    for (c23_i194 = 0; c23_i194 < 3; c23_i194 = c23_i194 + 1) {
      c23_j_b[c23_i194 + c23_i191] = c23_E1[c23_i193 + c23_i192];
      c23_i193 = c23_i193 + 3;
    }

    c23_i191 = c23_i191 + 3;
  }

  c23_d_eml_scalar_eg();
  c23_d_eml_scalar_eg();
  for (c23_i195 = 0; c23_i195 < 9; c23_i195 = c23_i195 + 1) {
    c23_fb_A[c23_i195] = c23_l_a[c23_i195];
  }

  for (c23_i196 = 0; c23_i196 < 9; c23_i196 = c23_i196 + 1) {
    c23_cb_B[c23_i196] = c23_j_b[c23_i196];
  }

  for (c23_i197 = 0; c23_i197 < 9; c23_i197 = c23_i197 + 1) {
    c23_E[c23_i197] = 0.0;
  }

  for (c23_i198 = 0; c23_i198 < 9; c23_i198 = c23_i198 + 1) {
    c23_gb_A[c23_i198] = c23_fb_A[c23_i198];
  }

  for (c23_i199 = 0; c23_i199 < 9; c23_i199 = c23_i199 + 1) {
    c23_db_B[c23_i199] = c23_cb_B[c23_i199];
  }

  for (c23_i200 = 0; c23_i200 < 9; c23_i200 = c23_i200 + 1) {
    c23_hb_A[c23_i200] = c23_gb_A[c23_i200];
  }

  for (c23_i201 = 0; c23_i201 < 9; c23_i201 = c23_i201 + 1) {
    c23_eb_B[c23_i201] = c23_db_B[c23_i201];
  }

  for (c23_i202 = 0; c23_i202 < 3; c23_i202 = c23_i202 + 1) {
    c23_i203 = 0;
    for (c23_i204 = 0; c23_i204 < 3; c23_i204 = c23_i204 + 1) {
      c23_E[c23_i203 + c23_i202] = 0.0;
      c23_i205 = 0;
      for (c23_i206 = 0; c23_i206 < 3; c23_i206 = c23_i206 + 1) {
        c23_E[c23_i203 + c23_i202] = c23_E[c23_i203 + c23_i202] +
          c23_hb_A[c23_i205 + c23_i202] * c23_eb_B[c23_i206 + c23_i203];
        c23_i205 = c23_i205 + 3;
      }

      c23_i203 = c23_i203 + 3;
    }
  }

  _SFD_EML_CALL(0,102);
  for (c23_i207 = 0; c23_i207 < 9; c23_i207 = c23_i207 + 1) {
    c23_D[c23_i207] = c23_E[c23_i207];
  }

  sf_debug_symbol_scope_push(4U, 0U);
  sf_debug_symbol_scope_add("nargout", &c23_b_nargout, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c23_b_nargin, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("ang", &c23_eul_ang, c23_e_sf_marshall);
  sf_debug_symbol_scope_add("D", &c23_D, c23_d_sf_marshall);
  CV_SCRIPT_FCN(1, 0);

  /*  DCM to Euler angles */
  _SFD_SCRIPT_CALL(1,4);
  c23_y_x = c23_D[6];
  c23_ab_x = c23_y_x;
  if (c23_ab_x < -1.0) {
  } else if (1.0 < c23_ab_x) {
  } else {
    goto label_1;
  }

  c23_eml_error();
 label_1:
  ;
  c23_bb_x = c23_ab_x;
  c23_ab_x = c23_bb_x;
  c23_ab_x = muDoubleScalarAsin(c23_ab_x);
  c23_d0 = c23_atan2(c23_D[7], c23_D[8]);
  c23_d1 = c23_atan2(c23_D[3], c23_D[0]);
  c23_eul_ang[0] = c23_d0;
  c23_eul_ang[1] = -c23_ab_x;
  c23_eul_ang[2] = c23_d1;
  _SFD_SCRIPT_CALL(1,-4);
  sf_debug_symbol_scope_pop();

  /*  place into output vector */
  _SFD_EML_CALL(0,105);
  c23_dv5[0] = 0.0;
  c23_dv5[1] = 0.0;
  c23_dv5[2] = c23_Height_A2;
  for (c23_i208 = 0; c23_i208 < 3; c23_i208 = c23_i208 + 1) {
    c23_out[c23_i208] = c23_pos[c23_i208] - c23_dv5[c23_i208];
  }

  _SFD_EML_CALL(0,106);
  for (c23_i209 = 0; c23_i209 < 3; c23_i209 = c23_i209 + 1) {
    c23_k_b[c23_i209] = c23_eul_ang[c23_i209];
  }

  for (c23_i210 = 0; c23_i210 < 3; c23_i210 = c23_i210 + 1) {
    c23_y[c23_i210] = 5.7295779513082323E+001 * c23_k_b[c23_i210];
  }

  for (c23_i211 = 0; c23_i211 < 3; c23_i211 = c23_i211 + 1) {
    c23_out[c23_i211 + 3] = c23_y[c23_i211];
  }

  _SFD_EML_CALL(0,-106);
  sf_debug_symbol_scope_pop();
  for (c23_i212 = 0; c23_i212 < 6; c23_i212 = c23_i212 + 1) {
    (*c23_b_out)[c23_i212] = c23_out[c23_i212];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,16);
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c23_chartNumber, 0U, sf_debug_get_script_id(
    "C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/adjust_ang.m"));
  _SFD_SCRIPT_TRANSLATION(c23_chartNumber, 1U, sf_debug_get_script_id(
    "C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/DCM2Eul.m"
    ));
}

static void c23_adjust_ang(real_T c23_ang[6], real_T c23_b_ang[6])
{
  real_T c23_nargout = 1.0;
  real_T c23_nargin = 1.0;
  real_T c23_a;
  real_T c23_i;
  int32_T c23_i213;
  real_T c23_b_i;
  sf_debug_symbol_scope_push(6U, 0U);
  sf_debug_symbol_scope_add("nargout", &c23_nargout, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c23_nargin, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("a", &c23_a, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("i", &c23_i, c23_b_sf_marshall);
  sf_debug_symbol_scope_add("ang", c23_b_ang, c23_sf_marshall);
  sf_debug_symbol_scope_add("ang", c23_ang, c23_sf_marshall);
  for (c23_i213 = 0; c23_i213 < 6; c23_i213 = c23_i213 + 1) {
    c23_b_ang[c23_i213] = c23_ang[c23_i213];
  }

  CV_SCRIPT_FCN(0, 0);
  c23_i = 1.0;
  c23_b_i = 1.0;
  while (c23_b_i <= 6.0) {
    c23_i = c23_b_i;
    CV_SCRIPT_FOR(0, 0, 1);
    _SFD_SCRIPT_CALL(0,4);
    c23_a = c23_b_ang[_SFD_EML_ARRAY_BOUNDS_CHECK("ang", (int32_T)
      _SFD_INTEGER_CHECK("i", c23_i), 1, 6, 1, 0) - 1];
    while (CV_SCRIPT_WHILE(0, 0, c23_a > 3.1415926535897931E+000)) {
      _SFD_SCRIPT_CALL(0,5);
      c23_a = c23_a - 6.2831853071795862E+000;
      sf_mex_listen_for_ctrl_c(chartInstance.S);
    }

    while (CV_SCRIPT_WHILE(0, 1, c23_a < -3.1415926535897931E+000)) {
      _SFD_SCRIPT_CALL(0,6);
      c23_a = c23_a + 6.2831853071795862E+000;
      sf_mex_listen_for_ctrl_c(chartInstance.S);
    }

    _SFD_SCRIPT_CALL(0,7);
    c23_b_ang[_SFD_EML_ARRAY_BOUNDS_CHECK("ang", (int32_T)_SFD_INTEGER_CHECK("i",
      c23_i), 1, 6, 1, 0) - 1] = c23_a;
    c23_b_i = c23_b_i + 1.0;
    sf_mex_listen_for_ctrl_c(chartInstance.S);
  }

  CV_SCRIPT_FOR(0, 0, 0);
  _SFD_SCRIPT_CALL(0,-7);
  sf_debug_symbol_scope_pop();
}

static void c23_eml_scalar_eg(void)
{
}

static void c23_b_eml_scalar_eg(void)
{
}

static void c23_c_eml_scalar_eg(void)
{
}

static void c23_d_eml_scalar_eg(void)
{
}

static real_T c23_atan2(real_T c23_y, real_T c23_x)
{
  real_T c23_b_y;
  real_T c23_b_x;
  c23_b_eml_scalar_eg();
  c23_b_y = c23_y;
  c23_b_x = c23_x;
  return muDoubleScalarAtan2(c23_b_y, c23_b_x);
}

static void c23_eml_error(void)
{
  int32_T c23_i214;
  static char_T c23_cv0[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 'a',
    's', 'i', 'n', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c23_u[77];
  const mxArray *c23_y = NULL;
  int32_T c23_i215;
  static char_T c23_cv1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'a', 's', 'i', 'n', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c23_b_u[31];
  const mxArray *c23_b_y = NULL;
  for (c23_i214 = 0; c23_i214 < 77; c23_i214 = c23_i214 + 1) {
    c23_u[c23_i214] = c23_cv0[c23_i214];
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c23_i215 = 0; c23_i215 < 31; c23_i215 = c23_i215 + 1) {
    c23_b_u[c23_i215] = c23_cv1[c23_i215];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c23_b_y, 14, c23_y);
}

static const mxArray *c23_sf_marshall(void *c23_chartInstance, void *c23_u)
{
  const mxArray *c23_y = NULL;
  int32_T c23_i216;
  real_T c23_b_u[6];
  const mxArray *c23_b_y = NULL;
  c23_y = NULL;
  for (c23_i216 = 0; c23_i216 < 6; c23_i216 = c23_i216 + 1) {
    c23_b_u[c23_i216] = (*((real_T (*)[6])c23_u))[c23_i216];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c23_y, c23_b_y);
  return c23_y;
}

static const mxArray *c23_b_sf_marshall(void *c23_chartInstance, void *c23_u)
{
  const mxArray *c23_y = NULL;
  real_T c23_b_u;
  const mxArray *c23_b_y = NULL;
  c23_y = NULL;
  c23_b_u = *((real_T *)c23_u);
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c23_y, c23_b_y);
  return c23_y;
}

static const mxArray *c23_c_sf_marshall(void *c23_chartInstance, void *c23_u)
{
  const mxArray *c23_y = NULL;
  int32_T c23_i217;
  int32_T c23_i218;
  int32_T c23_i219;
  real_T c23_b_u[16];
  const mxArray *c23_b_y = NULL;
  c23_y = NULL;
  c23_i217 = 0;
  for (c23_i218 = 0; c23_i218 < 4; c23_i218 = c23_i218 + 1) {
    for (c23_i219 = 0; c23_i219 < 4; c23_i219 = c23_i219 + 1) {
      c23_b_u[c23_i219 + c23_i217] = (*((real_T (*)[16])c23_u))[c23_i219 +
        c23_i217];
    }

    c23_i217 = c23_i217 + 4;
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c23_y, c23_b_y);
  return c23_y;
}

static const mxArray *c23_d_sf_marshall(void *c23_chartInstance, void *c23_u)
{
  const mxArray *c23_y = NULL;
  int32_T c23_i220;
  int32_T c23_i221;
  int32_T c23_i222;
  real_T c23_b_u[9];
  const mxArray *c23_b_y = NULL;
  c23_y = NULL;
  c23_i220 = 0;
  for (c23_i221 = 0; c23_i221 < 3; c23_i221 = c23_i221 + 1) {
    for (c23_i222 = 0; c23_i222 < 3; c23_i222 = c23_i222 + 1) {
      c23_b_u[c23_i222 + c23_i220] = (*((real_T (*)[9])c23_u))[c23_i222 +
        c23_i220];
    }

    c23_i220 = c23_i220 + 3;
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c23_y, c23_b_y);
  return c23_y;
}

static const mxArray *c23_e_sf_marshall(void *c23_chartInstance, void *c23_u)
{
  const mxArray *c23_y = NULL;
  int32_T c23_i223;
  real_T c23_b_u[3];
  const mxArray *c23_b_y = NULL;
  c23_y = NULL;
  for (c23_i223 = 0; c23_i223 < 3; c23_i223 = c23_i223 + 1) {
    c23_b_u[c23_i223] = (*((real_T (*)[3])c23_u))[c23_i223];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c23_y, c23_b_y);
  return c23_y;
}

static const mxArray *c23_f_sf_marshall(void *c23_chartInstance, void *c23_u)
{
  const mxArray *c23_y = NULL;
  int32_T c23_i224;
  real_T c23_b_u[4];
  const mxArray *c23_b_y = NULL;
  c23_y = NULL;
  for (c23_i224 = 0; c23_i224 < 4; c23_i224 = c23_i224 + 1) {
    c23_b_u[c23_i224] = (*((real_T (*)[4])c23_u))[c23_i224];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c23_y, c23_b_y);
  return c23_y;
}

const mxArray
  *sf_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c23_nameCaptureInfo = NULL;
  c23_ResolvedFunctionInfo c23_info[58];
  const mxArray *c23_m0 = NULL;
  int32_T c23_i225;
  c23_ResolvedFunctionInfo *c23_r0;
  c23_nameCaptureInfo = NULL;
  c23_info_helper(c23_info);
  sf_mex_assign(&c23_m0, sf_mex_createstruct("nameCaptureInfo", 1, 58));
  for (c23_i225 = 0; c23_i225 < 58; c23_i225 = c23_i225 + 1) {
    c23_r0 = &c23_info[c23_i225];
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->context)), "context"
                    , "nameCaptureInfo", c23_i225);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->name)), "name",
                    "nameCaptureInfo", c23_i225);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      c23_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c23_i225);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->resolved)),
                    "resolved", "nameCaptureInfo", c23_i225);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c23_i225);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c23_i225);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c23_i225);
  }

  sf_mex_assign(&c23_nameCaptureInfo, c23_m0);
  return c23_nameCaptureInfo;
}

static void c23_info_helper(c23_ResolvedFunctionInfo c23_info[58])
{
  c23_info[0].context = "";
  c23_info[0].name = "pi";
  c23_info[0].dominantType = "";
  c23_info[0].resolved = "[B]pi";
  c23_info[0].fileLength = 0U;
  c23_info[0].fileTime1 = 0U;
  c23_info[0].fileTime2 = 0U;
  c23_info[1].context = "";
  c23_info[1].name = "mrdivide";
  c23_info[1].dominantType = "double";
  c23_info[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c23_info[1].fileLength = 800U;
  c23_info[1].fileTime1 = 1238434292U;
  c23_info[1].fileTime2 = 0U;
  c23_info[2].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c23_info[2].name = "nargin";
  c23_info[2].dominantType = "";
  c23_info[2].resolved = "[B]nargin";
  c23_info[2].fileLength = 0U;
  c23_info[2].fileTime1 = 0U;
  c23_info[2].fileTime2 = 0U;
  c23_info[3].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c23_info[3].name = "ge";
  c23_info[3].dominantType = "double";
  c23_info[3].resolved = "[B]ge";
  c23_info[3].fileLength = 0U;
  c23_info[3].fileTime1 = 0U;
  c23_info[3].fileTime2 = 0U;
  c23_info[4].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c23_info[4].name = "isscalar";
  c23_info[4].dominantType = "double";
  c23_info[4].resolved = "[B]isscalar";
  c23_info[4].fileLength = 0U;
  c23_info[4].fileTime1 = 0U;
  c23_info[4].fileTime2 = 0U;
  c23_info[5].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c23_info[5].name = "rdivide";
  c23_info[5].dominantType = "double";
  c23_info[5].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[5].fileLength = 620U;
  c23_info[5].fileTime1 = 1213926766U;
  c23_info[5].fileTime2 = 0U;
  c23_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[6].name = "gt";
  c23_info[6].dominantType = "double";
  c23_info[6].resolved = "[B]gt";
  c23_info[6].fileLength = 0U;
  c23_info[6].fileTime1 = 0U;
  c23_info[6].fileTime2 = 0U;
  c23_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[7].name = "isa";
  c23_info[7].dominantType = "double";
  c23_info[7].resolved = "[B]isa";
  c23_info[7].fileLength = 0U;
  c23_info[7].fileTime1 = 0U;
  c23_info[7].fileTime2 = 0U;
  c23_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[8].name = "isempty";
  c23_info[8].dominantType = "double";
  c23_info[8].resolved = "[B]isempty";
  c23_info[8].fileLength = 0U;
  c23_info[8].fileTime1 = 0U;
  c23_info[8].fileTime2 = 0U;
  c23_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[9].name = "not";
  c23_info[9].dominantType = "logical";
  c23_info[9].resolved = "[B]not";
  c23_info[9].fileLength = 0U;
  c23_info[9].fileTime1 = 0U;
  c23_info[9].fileTime2 = 0U;
  c23_info[10].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[10].name = "strcmp";
  c23_info[10].dominantType = "char";
  c23_info[10].resolved = "[B]strcmp";
  c23_info[10].fileLength = 0U;
  c23_info[10].fileTime1 = 0U;
  c23_info[10].fileTime2 = 0U;
  c23_info[11].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[11].name = "eq";
  c23_info[11].dominantType = "double";
  c23_info[11].resolved = "[B]eq";
  c23_info[11].fileLength = 0U;
  c23_info[11].fileTime1 = 0U;
  c23_info[11].fileTime2 = 0U;
  c23_info[12].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[12].name = "eml_warning";
  c23_info[12].dominantType = "char";
  c23_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c23_info[12].fileLength = 262U;
  c23_info[12].fileTime1 = 1236257278U;
  c23_info[12].fileTime2 = 0U;
  c23_info[13].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c23_info[13].name = "eml_div";
  c23_info[13].dominantType = "double";
  c23_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c23_info[13].fileLength = 4269U;
  c23_info[13].fileTime1 = 1228093826U;
  c23_info[13].fileTime2 = 0U;
  c23_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c23_info[14].name = "isinteger";
  c23_info[14].dominantType = "double";
  c23_info[14].resolved = "[B]isinteger";
  c23_info[14].fileLength = 0U;
  c23_info[14].fileTime1 = 0U;
  c23_info[14].fileTime2 = 0U;
  c23_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c23_info[15].name = "isreal";
  c23_info[15].dominantType = "double";
  c23_info[15].resolved = "[B]isreal";
  c23_info[15].fileLength = 0U;
  c23_info[15].fileTime1 = 0U;
  c23_info[15].fileTime2 = 0U;
  c23_info[16].context = "";
  c23_info[16].name = "mtimes";
  c23_info[16].dominantType = "double";
  c23_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[16].fileLength = 3302U;
  c23_info[16].fileTime1 = 1242750894U;
  c23_info[16].fileTime2 = 0U;
  c23_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[17].name = "size";
  c23_info[17].dominantType = "double";
  c23_info[17].resolved = "[B]size";
  c23_info[17].fileLength = 0U;
  c23_info[17].fileTime1 = 0U;
  c23_info[17].fileTime2 = 0U;
  c23_info[18].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[18].name = "class";
  c23_info[18].dominantType = "double";
  c23_info[18].resolved = "[B]class";
  c23_info[18].fileLength = 0U;
  c23_info[18].fileTime1 = 0U;
  c23_info[18].fileTime2 = 0U;
  c23_info[19].context = "";
  c23_info[19].name = "zeros";
  c23_info[19].dominantType = "double";
  c23_info[19].resolved = "[B]zeros";
  c23_info[19].fileLength = 0U;
  c23_info[19].fileTime1 = 0U;
  c23_info[19].fileTime2 = 0U;
  c23_info[20].context = "";
  c23_info[20].name = "plus";
  c23_info[20].dominantType = "double";
  c23_info[20].resolved = "[B]plus";
  c23_info[20].fileLength = 0U;
  c23_info[20].fileTime1 = 0U;
  c23_info[20].fileTime2 = 0U;
  c23_info[21].context = "";
  c23_info[21].name = "adjust_ang";
  c23_info[21].dominantType = "double";
  c23_info[21].resolved =
    "[]C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/adjust_ang.m";
  c23_info[21].fileLength = 171U;
  c23_info[21].fileTime1 = 1416490128U;
  c23_info[21].fileTime2 = 0U;
  c23_info[22].context =
    "[]C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/adjust_ang.m";
  c23_info[22].name = "minus";
  c23_info[22].dominantType = "double";
  c23_info[22].resolved = "[B]minus";
  c23_info[22].fileLength = 0U;
  c23_info[22].fileTime1 = 0U;
  c23_info[22].fileTime2 = 0U;
  c23_info[23].context =
    "[]C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/adjust_ang.m";
  c23_info[23].name = "uminus";
  c23_info[23].dominantType = "double";
  c23_info[23].resolved = "[B]uminus";
  c23_info[23].fileLength = 0U;
  c23_info[23].fileTime1 = 0U;
  c23_info[23].fileTime2 = 0U;
  c23_info[24].context =
    "[]C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/adjust_ang.m";
  c23_info[24].name = "lt";
  c23_info[24].dominantType = "double";
  c23_info[24].resolved = "[B]lt";
  c23_info[24].fileLength = 0U;
  c23_info[24].fileTime1 = 0U;
  c23_info[24].fileTime2 = 0U;
  c23_info[25].context = "";
  c23_info[25].name = "cos";
  c23_info[25].dominantType = "double";
  c23_info[25].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c23_info[25].fileLength = 324U;
  c23_info[25].fileTime1 = 1203447952U;
  c23_info[25].fileTime2 = 0U;
  c23_info[26].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c23_info[26].name = "eml_scalar_cos";
  c23_info[26].dominantType = "double";
  c23_info[26].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c23_info[26].fileLength = 602U;
  c23_info[26].fileTime1 = 1209330788U;
  c23_info[26].fileTime2 = 0U;
  c23_info[27].context = "";
  c23_info[27].name = "sin";
  c23_info[27].dominantType = "double";
  c23_info[27].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c23_info[27].fileLength = 324U;
  c23_info[27].fileTime1 = 1203448042U;
  c23_info[27].fileTime2 = 0U;
  c23_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c23_info[28].name = "eml_scalar_sin";
  c23_info[28].dominantType = "double";
  c23_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c23_info[28].fileLength = 601U;
  c23_info[28].fileTime1 = 1209330792U;
  c23_info[28].fileTime2 = 0U;
  c23_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[29].name = "ndims";
  c23_info[29].dominantType = "double";
  c23_info[29].resolved = "[B]ndims";
  c23_info[29].fileLength = 0U;
  c23_info[29].fileTime1 = 0U;
  c23_info[29].fileTime2 = 0U;
  c23_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[30].name = "le";
  c23_info[30].dominantType = "double";
  c23_info[30].resolved = "[B]le";
  c23_info[30].fileLength = 0U;
  c23_info[30].fileTime1 = 0U;
  c23_info[30].fileTime2 = 0U;
  c23_info[31].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[31].name = "ne";
  c23_info[31].dominantType = "logical";
  c23_info[31].resolved = "[B]ne";
  c23_info[31].fileLength = 0U;
  c23_info[31].fileTime1 = 0U;
  c23_info[31].fileTime2 = 0U;
  c23_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[32].name = "eml_index_class";
  c23_info[32].dominantType = "";
  c23_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c23_info[32].fileLength = 909U;
  c23_info[32].fileTime1 = 1192466782U;
  c23_info[32].fileTime2 = 0U;
  c23_info[33].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[33].name = "ones";
  c23_info[33].dominantType = "char";
  c23_info[33].resolved = "[B]ones";
  c23_info[33].fileLength = 0U;
  c23_info[33].fileTime1 = 0U;
  c23_info[33].fileTime2 = 0U;
  c23_info[34].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[34].name = "cast";
  c23_info[34].dominantType = "double";
  c23_info[34].resolved = "[B]cast";
  c23_info[34].fileLength = 0U;
  c23_info[34].fileTime1 = 0U;
  c23_info[34].fileTime2 = 0U;
  c23_info[35].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[35].name = "eml_scalar_eg";
  c23_info[35].dominantType = "double";
  c23_info[35].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c23_info[35].fileLength = 3068U;
  c23_info[35].fileTime1 = 1240262010U;
  c23_info[35].fileTime2 = 0U;
  c23_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c23_info[36].name = "false";
  c23_info[36].dominantType = "";
  c23_info[36].resolved = "[B]false";
  c23_info[36].fileLength = 0U;
  c23_info[36].fileTime1 = 0U;
  c23_info[36].fileTime2 = 0U;
  c23_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c23_info[37].name = "isstruct";
  c23_info[37].dominantType = "double";
  c23_info[37].resolved = "[B]isstruct";
  c23_info[37].fileLength = 0U;
  c23_info[37].fileTime1 = 0U;
  c23_info[37].fileTime2 = 0U;
  c23_info[38].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c23_info[38].name = "eml_xgemm";
  c23_info[38].dominantType = "int32";
  c23_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c23_info[38].fileLength = 3184U;
  c23_info[38].fileTime1 = 1209330852U;
  c23_info[38].fileTime2 = 0U;
  c23_info[39].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c23_info[39].name = "length";
  c23_info[39].dominantType = "double";
  c23_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c23_info[39].fileLength = 326U;
  c23_info[39].fileTime1 = 1226577276U;
  c23_info[39].fileTime2 = 0U;
  c23_info[40].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m/itcount";
  c23_info[40].name = "min";
  c23_info[40].dominantType = "double";
  c23_info[40].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c23_info[40].fileLength = 308U;
  c23_info[40].fileTime1 = 1192466634U;
  c23_info[40].fileTime2 = 0U;
  c23_info[41].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c23_info[41].name = "nargout";
  c23_info[41].dominantType = "";
  c23_info[41].resolved = "[B]nargout";
  c23_info[41].fileLength = 0U;
  c23_info[41].fileTime1 = 0U;
  c23_info[41].fileTime2 = 0U;
  c23_info[42].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c23_info[42].name = "eml_min_or_max";
  c23_info[42].dominantType = "char";
  c23_info[42].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c23_info[42].fileLength = 9969U;
  c23_info[42].fileTime1 = 1240262008U;
  c23_info[42].fileTime2 = 0U;
  c23_info[43].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c23_info[43].name = "ischar";
  c23_info[43].dominantType = "char";
  c23_info[43].resolved = "[B]ischar";
  c23_info[43].fileLength = 0U;
  c23_info[43].fileTime1 = 0U;
  c23_info[43].fileTime2 = 0U;
  c23_info[44].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c23_info[44].name = "isnumeric";
  c23_info[44].dominantType = "double";
  c23_info[44].resolved = "[B]isnumeric";
  c23_info[44].fileLength = 0U;
  c23_info[44].fileTime1 = 0U;
  c23_info[44].fileTime2 = 0U;
  c23_info[45].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c23_info[45].name = "islogical";
  c23_info[45].dominantType = "double";
  c23_info[45].resolved = "[B]islogical";
  c23_info[45].fileLength = 0U;
  c23_info[45].fileTime1 = 0U;
  c23_info[45].fileTime2 = 0U;
  c23_info[46].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m/eml_bin_extremum";
  c23_info[46].name = "eml_scalexp_alloc";
  c23_info[46].dominantType = "double";
  c23_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c23_info[46].fileLength = 808U;
  c23_info[46].fileTime1 = 1230494700U;
  c23_info[46].fileTime2 = 0U;
  c23_info[47].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c23_info[47].name = "eml_refblas_xgemm";
  c23_info[47].dominantType = "int32";
  c23_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c23_info[47].fileLength = 5748U;
  c23_info[47].fileTime1 = 1228093874U;
  c23_info[47].fileTime2 = 0U;
  c23_info[48].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c23_info[48].name = "eml_index_minus";
  c23_info[48].dominantType = "int32";
  c23_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c23_info[48].fileLength = 277U;
  c23_info[48].fileTime1 = 1192466784U;
  c23_info[48].fileTime2 = 0U;
  c23_info[49].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c23_info[49].name = "eml_index_times";
  c23_info[49].dominantType = "int32";
  c23_info[49].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c23_info[49].fileLength = 280U;
  c23_info[49].fileTime1 = 1192466788U;
  c23_info[49].fileTime2 = 0U;
  c23_info[50].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c23_info[50].name = "eml_index_plus";
  c23_info[50].dominantType = "int32";
  c23_info[50].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c23_info[50].fileLength = 272U;
  c23_info[50].fileTime1 = 1192466786U;
  c23_info[50].fileTime2 = 0U;
  c23_info[51].context = "";
  c23_info[51].name = "ctranspose";
  c23_info[51].dominantType = "double";
  c23_info[51].resolved = "[B]ctranspose";
  c23_info[51].fileLength = 0U;
  c23_info[51].fileTime1 = 0U;
  c23_info[51].fileTime2 = 0U;
  c23_info[52].context = "";
  c23_info[52].name = "DCM2Eul";
  c23_info[52].dominantType = "double";
  c23_info[52].resolved =
    "[]C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/DCM2Eul.m";
  c23_info[52].fileLength = 155U;
  c23_info[52].fileTime1 = 1416490132U;
  c23_info[52].fileTime2 = 0U;
  c23_info[53].context =
    "[]C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/DCM2Eul.m";
  c23_info[53].name = "atan2";
  c23_info[53].dominantType = "double";
  c23_info[53].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c23_info[53].fileLength = 605U;
  c23_info[53].fileTime1 = 1236257254U;
  c23_info[53].fileTime2 = 0U;
  c23_info[54].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c23_info[54].name = "eml_scalar_atan2";
  c23_info[54].dominantType = "double";
  c23_info[54].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c23_info[54].fileLength = 964U;
  c23_info[54].fileTime1 = 1209330786U;
  c23_info[54].fileTime2 = 0U;
  c23_info[55].context =
    "[]C:/Imose/BEC/Euromov/Motion_Patterns/EXP_Infra_trans/DCM2Eul.m";
  c23_info[55].name = "asin";
  c23_info[55].dominantType = "double";
  c23_info[55].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c23_info[55].fileLength = 585U;
  c23_info[55].fileTime1 = 1203447944U;
  c23_info[55].fileTime2 = 0U;
  c23_info[56].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c23_info[56].name = "eml_error";
  c23_info[56].dominantType = "char";
  c23_info[56].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c23_info[56].fileLength = 315U;
  c23_info[56].fileTime1 = 1213926746U;
  c23_info[56].fileTime2 = 0U;
  c23_info[57].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c23_info[57].name = "eml_scalar_asin";
  c23_info[57].dominantType = "double";
  c23_info[57].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asin.m";
  c23_info[57].fileLength = 588U;
  c23_info[57].fileTime1 = 1203447974U;
  c23_info[57].fileTime2 = 0U;
}

static const mxArray *c23_g_sf_marshall(void *c23_chartInstance, void *c23_u)
{
  const mxArray *c23_y = NULL;
  boolean_T c23_b_u;
  const mxArray *c23_b_y = NULL;
  c23_y = NULL;
  c23_b_u = *((boolean_T *)c23_u);
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c23_y, c23_b_y);
  return c23_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1448365459U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3848405954U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1068897693U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(870204566U);
}

mxArray
  *sf_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3564216018U);
    pr[1] = (double)(1424180378U);
    pr[2] = (double)(1093700778U);
    pr[3] = (double)(3161234863U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
  *sf_get_sim_state_info_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"out\",},{M[8],M[0],T\"is_active_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(&mxChecksum);
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
           23,
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
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"vec",0,(MexFcnForType)c23_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 6;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"out",0,(MexFcnForType)c23_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3102);
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
          real_T (*c23_vec)[6];
          real_T (*c23_out)[6];
          c23_vec = (real_T (*)[6])ssGetInputPortSignal(chartInstance.S, 0);
          c23_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c23_vec);
          _SFD_SET_DATA_VALUE_PTR(1U, c23_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  initialize_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_enable_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  enable_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_disable_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  disable_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_gateway_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  sf_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void
  sf_opaque_ext_mode_exec_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  ext_mode_exec_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static mxArray*
  sf_opaque_get_sim_state_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  return st;
}

static void
  sf_opaque_set_sim_state_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(sf_mex_dup(st));
}

static void sf_opaque_terminate_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",23,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",23,1);
      sf_mark_chart_reusable_outputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",23,1);
    }

    sf_set_rtw_dwork_info(S,"M37_Sim_Forcing_003h_expe_infra_transz_lim",
                          "M37_Sim_Forcing_003h_expe_infra_transz_lim",23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1552386650U));
  ssSetChecksum1(S,(2237478652U));
  ssSetChecksum2(S,(1139714413U));
  ssSetChecksum3(S,(3327706919U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",23);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim;
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

void c23_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(SimStruct *
  S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

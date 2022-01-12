/* Include files */

#include "blascompat32.h"
#include "M43_Sim_Forcing_003h_Trajectory_sfun.h"
#include "c7_M43_Sim_Forcing_003h_Trajectory.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M43_Sim_Forcing_003h_Trajectory_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c7_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc7_M43_Sim_Forcing_003h_TrajectoryInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c7_M43_Sim_Forcing_003h_Trajectory(void);
static void initialize_params_c7_M43_Sim_Forcing_003h_Trajectory(void);
static void enable_c7_M43_Sim_Forcing_003h_Trajectory(void);
static void disable_c7_M43_Sim_Forcing_003h_Trajectory(void);
static void c7_update_debugger_state_c7_M43_Sim_Forcing_003h_Trajectory(void);
static void ext_mode_exec_c7_M43_Sim_Forcing_003h_Trajectory(void);
static const mxArray *get_sim_state_c7_M43_Sim_Forcing_003h_Trajectory(void);
static void set_sim_state_c7_M43_Sim_Forcing_003h_Trajectory(const mxArray
  *c7_st);
static void finalize_c7_M43_Sim_Forcing_003h_Trajectory(void);
static void sf_c7_M43_Sim_Forcing_003h_Trajectory(void);
static void c7_c7_M43_Sim_Forcing_003h_Trajectory(void);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static real_T c7_mrdivide(real_T c7_A, real_T c7_B);
static void c7_eml_warning(void);
static real_T c7_sqrt(real_T c7_x);
static void c7_eml_error(void);
static real_T c7_mpower(real_T c7_a);
static void c7_eml_scalar_eg(void);
static real_T c7_abs(real_T c7_x);
static real_T c7_acos(real_T c7_x);
static void c7_b_eml_error(void);
static real_T c7_atan2(real_T c7_y, real_T c7_x);
static const mxArray *c7_sf_marshall(void *c7_chartInstance, void *c7_u);
static const mxArray *c7_b_sf_marshall(void *c7_chartInstance, void *c7_u);
static const mxArray *c7_c_sf_marshall(void *c7_chartInstance, void *c7_u);
static const mxArray *c7_d_sf_marshall(void *c7_chartInstance, void *c7_u);
static const mxArray *c7_e_sf_marshall(void *c7_chartInstance, void *c7_u);
static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[51]);
static const mxArray *c7_f_sf_marshall(void *c7_chartInstance, void *c7_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c7_M43_Sim_Forcing_003h_Trajectory(void)
{
  uint8_T *c7_is_active_c7_M43_Sim_Forcing_003h_Trajectory;
  c7_is_active_c7_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c7_is_active_c7_M43_Sim_Forcing_003h_Trajectory = 0U;
}

static void initialize_params_c7_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void enable_c7_M43_Sim_Forcing_003h_Trajectory(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c7_M43_Sim_Forcing_003h_Trajectory(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c7_update_debugger_state_c7_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void ext_mode_exec_c7_M43_Sim_Forcing_003h_Trajectory(void)
{
  c7_update_debugger_state_c7_M43_Sim_Forcing_003h_Trajectory();
}

static const mxArray *get_sim_state_c7_M43_Sim_Forcing_003h_Trajectory(void)
{
  const mxArray *c7_st = NULL;
  const mxArray *c7_y = NULL;
  int32_T c7_i0;
  real_T c7_u[7];
  const mxArray *c7_b_y = NULL;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  uint8_T *c7_is_active_c7_M43_Sim_Forcing_003h_Trajectory;
  real_T (*c7_out)[7];
  c7_is_active_c7_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c7_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(2));
  for (c7_i0 = 0; c7_i0 < 7; c7_i0 = c7_i0 + 1) {
    c7_u[c7_i0] = (*c7_out)[c7_i0];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_u = *c7_is_active_c7_M43_Sim_Forcing_003h_Trajectory;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y);
  return c7_st;
}

static void set_sim_state_c7_M43_Sim_Forcing_003h_Trajectory(const mxArray
  *c7_st)
{
  const mxArray *c7_u;
  const mxArray *c7_out;
  real_T c7_dv0[7];
  int32_T c7_i1;
  real_T c7_y[7];
  int32_T c7_i2;
  const mxArray *c7_is_active_c7_M43_Sim_Forcing_003h_Trajectory;
  uint8_T c7_u0;
  uint8_T c7_b_y;
  boolean_T *c7_doneDoubleBufferReInit;
  uint8_T *c7_b_is_active_c7_M43_Sim_Forcing_003h_Trajectory;
  real_T (*c7_b_out)[7];
  c7_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c7_b_is_active_c7_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c7_b_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  *c7_doneDoubleBufferReInit = true;
  c7_u = sf_mex_dup(c7_st);
  c7_out = sf_mex_dup(sf_mex_getcell(c7_u, 0));
  sf_mex_import("out", sf_mex_dup(c7_out), &c7_dv0, 1, 0, 0U, 1, 0U, 1, 7);
  for (c7_i1 = 0; c7_i1 < 7; c7_i1 = c7_i1 + 1) {
    c7_y[c7_i1] = c7_dv0[c7_i1];
  }

  sf_mex_destroy(&c7_out);
  for (c7_i2 = 0; c7_i2 < 7; c7_i2 = c7_i2 + 1) {
    (*c7_b_out)[c7_i2] = c7_y[c7_i2];
  }

  c7_is_active_c7_M43_Sim_Forcing_003h_Trajectory = sf_mex_dup(sf_mex_getcell
    (c7_u, 1));
  sf_mex_import("is_active_c7_M43_Sim_Forcing_003h_Trajectory", sf_mex_dup
                (c7_is_active_c7_M43_Sim_Forcing_003h_Trajectory), &c7_u0, 1
                , 3, 0U, 0, 0U, 0);
  c7_b_y = c7_u0;
  sf_mex_destroy(&c7_is_active_c7_M43_Sim_Forcing_003h_Trajectory);
  *c7_b_is_active_c7_M43_Sim_Forcing_003h_Trajectory = c7_b_y;
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_M43_Sim_Forcing_003h_Trajectory();
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void sf_c7_M43_Sim_Forcing_003h_Trajectory(void)
{
  int32_T c7_i3;
  int32_T c7_i4;
  int32_T c7_previousEvent;
  real_T (*c7_out)[7];
  real_T (*c7_vec)[12];
  c7_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  c7_vec = (real_T (*)[12])ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,6);
  for (c7_i3 = 0; c7_i3 < 12; c7_i3 = c7_i3 + 1) {
    _SFD_DATA_RANGE_CHECK((*c7_vec)[c7_i3], 0U);
  }

  for (c7_i4 = 0; c7_i4 < 7; c7_i4 = c7_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c7_out)[c7_i4], 1U);
  }

  c7_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c7_c7_M43_Sim_Forcing_003h_Trajectory();
  _sfEvent_ = c7_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void c7_c7_M43_Sim_Forcing_003h_Trajectory(void)
{
  int32_T c7_i5;
  real_T c7_vec[12];
  real_T c7_nargout = 1.0;
  real_T c7_nargin = 1.0;
  real_T c7_i;
  real_T c7_J_ANG[6];
  real_T c7_A6;
  real_T c7_A5;
  real_T c7_A4;
  real_T c7_A2;
  real_T c7_A1;
  real_T c7_delta;
  real_T c7_alpha;
  real_T c7_cos_alpha;
  real_T c7_dbeta;
  real_T c7_deps_dbeta;
  real_T c7_eps;
  real_T c7_dB_dbeta;
  real_T c7_dA_dbeta;
  real_T c7_B;
  real_T c7_A;
  real_T c7_dc_dbeta;
  real_T c7_db_dbeta;
  real_T c7_cos_beta;
  real_T c7_sin2_beta;
  real_T c7_sin_beta;
  real_T c7_beta;
  real_T c7_A3;
  real_T c7_margin;
  real_T c7_c;
  real_T c7_b;
  real_T c7_d;
  real_T c7_h;
  real_T c7_e;
  real_T c7_l;
  real_T c7_N;
  real_T c7_sin_theta;
  real_T c7_cos_theta;
  real_T c7_theta;
  real_T c7_z;
  real_T c7_y;
  real_T c7_x;
  real_T c7_Height_A2;
  real_T c7_offset;
  real_T c7_l5;
  real_T c7_l4;
  real_T c7_l3;
  real_T c7_l2;
  real_T c7_l1;
  real_T c7_SL[12];
  real_T c7_DTR;
  real_T c7_RTD;
  real_T c7_out[7];
  int32_T c7_i6;
  static real_T c7_dv1[12] = { 159.0, -159.0, 129.0, -19.0, 87.0, -87.0, 349.0,
    -349.0, 60.0, -60.0, 349.0, -349.0 };

  real_T c7_b_b;
  real_T c7_b_x;
  real_T c7_c_x;
  real_T c7_c_b;
  real_T c7_d_x;
  real_T c7_e_x;
  int32_T c7_i7;
  real_T c7_a;
  real_T c7_d_b;
  real_T c7_b_y;
  real_T c7_b_a;
  real_T c7_e_b;
  real_T c7_c_y;
  real_T c7_f_b;
  real_T c7_d_y;
  real_T c7_g_b;
  real_T c7_e_y;
  int32_T c7_i8;
  int32_T c7_i9;
  real_T c7_c_a;
  real_T c7_f_x;
  real_T c7_g_x;
  real_T c7_d_a;
  real_T c7_h_b;
  real_T c7_e_a;
  real_T c7_h_x;
  real_T c7_i_x;
  real_T c7_i_b;
  real_T c7_f_y;
  real_T c7_j_b;
  real_T c7_g_y;
  real_T c7_f_a;
  real_T c7_k_b;
  real_T c7_h_y;
  real_T c7_g_a;
  real_T c7_l_b;
  real_T c7_i_y;
  real_T c7_h_a;
  real_T c7_m_b;
  real_T c7_j_y;
  real_T c7_n_b;
  real_T c7_i_a;
  real_T c7_o_b;
  real_T c7_p_b;
  real_T c7_j_a;
  real_T c7_q_b;
  real_T c7_k_y;
  real_T c7_r_b;
  real_T c7_k_a;
  real_T c7_s_b;
  real_T c7_l_y;
  real_T c7_l_a;
  real_T c7_t_b;
  real_T c7_m_y;
  real_T c7_m_a;
  real_T c7_u_b;
  real_T c7_n_y;
  real_T c7_v_b;
  real_T c7_n_a;
  real_T c7_w_b;
  real_T c7_o_y;
  real_T c7_o_a;
  real_T c7_x_b;
  real_T c7_p_y;
  real_T c7_y_b;
  real_T c7_q_y;
  int32_T c7_i10;
  real_T c7_ab_b;
  real_T c7_p_a;
  real_T c7_bb_b;
  real_T c7_r_y;
  real_T c7_q_a;
  real_T c7_cb_b;
  real_T c7_s_y;
  real_T c7_r_a;
  real_T c7_db_b;
  real_T c7_t_y;
  real_T c7_s_a;
  real_T c7_eb_b;
  real_T c7_u_y;
  real_T c7_fb_b;
  real_T c7_gb_b;
  real_T c7_hb_b;
  real_T c7_b_A1[6];
  int32_T c7_i11;
  int32_T c7_i12;
  real_T c7_b_i;
  int32_T c7_i13;
  real_T (*c7_b_out)[7];
  real_T (*c7_b_vec)[12];
  c7_b_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
  c7_b_vec = (real_T (*)[12])ssGetInputPortSignal(chartInstance.S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,6);
  for (c7_i5 = 0; c7_i5 < 12; c7_i5 = c7_i5 + 1) {
    c7_vec[c7_i5] = (*c7_b_vec)[c7_i5];
  }

  sf_debug_symbol_scope_push(52U, 0U);
  sf_debug_symbol_scope_add("nargout", &c7_nargout, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c7_nargin, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("i", &c7_i, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("J_ANG", &c7_J_ANG, c7_e_sf_marshall);
  sf_debug_symbol_scope_add("A6", &c7_A6, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("A5", &c7_A5, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("A4", &c7_A4, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("A2", &c7_A2, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("A1", &c7_A1, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("delta", &c7_delta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("alpha", &c7_alpha, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("cos_alpha", &c7_cos_alpha, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("dbeta", &c7_dbeta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("deps_dbeta", &c7_deps_dbeta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("eps", &c7_eps, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("dB_dbeta", &c7_dB_dbeta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("dA_dbeta", &c7_dA_dbeta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("B", &c7_B, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("A", &c7_A, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("dc_dbeta", &c7_dc_dbeta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("db_dbeta", &c7_db_dbeta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("cos_beta", &c7_cos_beta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("sin2_beta", &c7_sin2_beta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("sin_beta", &c7_sin_beta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("beta", &c7_beta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("A3", &c7_A3, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("margin", &c7_margin, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("c", &c7_c, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("b", &c7_b, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("d", &c7_d, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("h", &c7_h, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("e", &c7_e, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("l", &c7_l, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("N", &c7_N, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("sin_theta", &c7_sin_theta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("cos_theta", &c7_cos_theta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("theta", &c7_theta, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("z", &c7_z, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("y", &c7_y, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("x", &c7_x, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("Height_A2", &c7_Height_A2, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("offset", &c7_offset, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("l5", &c7_l5, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("l4", &c7_l4, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("l3", &c7_l3, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("l2", &c7_l2, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("l1", &c7_l1, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("SL", &c7_SL, c7_d_sf_marshall);
  sf_debug_symbol_scope_add("DTR", &c7_DTR, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("RTD", &c7_RTD, c7_c_sf_marshall);
  sf_debug_symbol_scope_add("out", &c7_out, c7_b_sf_marshall);
  sf_debug_symbol_scope_add("vec", &c7_vec, c7_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  We use the NED convention */
  /*  This algorithm has a closed form solution and is based on the cosine rule */
  /*  However, due to the offset of the centerline of link A4 55 mm below the */
  /*  center of rotation of link A3, some small corrections have to be made; */
  /*  this is done iteratively by means of a second-order scheme. */
  /*  The gist of this routine is to show tha identical results are obtained */
  /*  with the fully-fledged 6-DOF inverse algorithm. */
  /*  */
  /*  The algorithm is also used for computing an initial guess for the */
  /*  fully-fledged inverse kinematics algorithm */
  /*  The initial guess uses only links A1, A2, A3 and assumes that the */
  /*  cabin at the end is straight and level and aligned with the arm */
  /*  Thus A4 and A6 are zero and A5 is A2 + A3 */
  /*  */
  /*    out(7) includes the parameter N */
  /*        N > 0           the number of iterations needed to converge */
  /*        N = -1          the iterative algorithm does not converge */
  /*        N = -2          out of reachable limits */
  /*        N -10<N<-30     upper limit of one of the joints A1-A6 exceeded */
  /*        N -100<N<-110   upper limit of one of the joints A1-A6 exceeded */
  /*  */
  /*    Written by Arthur Grunwald, November 11, 2014 */
  /*    Added correction because of offset of link A4, Dec 2, 2014 */
  /*    Added theta degree-of-freedom April 14, 2015 */
  /*    Modified the iterative scheme to second order NR scheme April 24, 2015 */
  /*    Modified FAR and CLOSE checks with intersecting circles May 6, 2015 */
  _SFD_EML_CALL(0,30);
  c7_RTD = 5.7295779513082323E+001;
  _SFD_EML_CALL(0,31);
  c7_DTR = 1.7453292519943295E-002;

  /*  May 7,2015 soft limits on the links (NED convention) */
  _SFD_EML_CALL(0,34);
  for (c7_i6 = 0; c7_i6 < 12; c7_i6 = c7_i6 + 1) {
    c7_SL[c7_i6] = c7_dv1[c7_i6];
  }

  /*  define length of the links */
  _SFD_EML_CALL(0,39);
  c7_l1 = 50.0;

  /*  arm length in cm */
  _SFD_EML_CALL(0,40);
  c7_l2 = 130.0;
  _SFD_EML_CALL(0,41);
  c7_l3 = 66.0;
  _SFD_EML_CALL(0,42);
  c7_l4 = 36.5;
  _SFD_EML_CALL(0,43);
  c7_l5 = 29.0;
  _SFD_EML_CALL(0,44);
  c7_offset = 5.5;

  /*  vertical offset of the center line of */
  /*  joint 4 from centerline of arm A3 */
  _SFD_EML_CALL(0,47);
  c7_Height_A2 = 210.5;

  /*  height link A2 above the ground */
  _SFD_EML_CALL(0,49);
  c7_x = c7_vec[0];
  _SFD_EML_CALL(0,50);
  c7_y = c7_vec[1];
  _SFD_EML_CALL(0,51);
  c7_z = c7_vec[2];
  _SFD_EML_CALL(0,53);
  c7_theta = c7_vec[4];
  _SFD_EML_CALL(0,54);
  c7_b_b = c7_vec[4];
  c7_b_x = 1.7453292519943295E-002 * c7_b_b;
  c7_cos_theta = c7_b_x;
  c7_c_x = c7_cos_theta;
  c7_cos_theta = c7_c_x;
  c7_cos_theta = muDoubleScalarCos(c7_cos_theta);
  _SFD_EML_CALL(0,55);
  c7_c_b = c7_vec[4];
  c7_d_x = 1.7453292519943295E-002 * c7_c_b;
  c7_sin_theta = c7_d_x;
  c7_e_x = c7_sin_theta;
  c7_sin_theta = c7_e_x;
  c7_sin_theta = muDoubleScalarSin(c7_sin_theta);
  _SFD_EML_CALL(0,57);
  c7_N = 1.0;
  _SFD_EML_CALL(0,58);
  for (c7_i7 = 0; c7_i7 < 7; c7_i7 = c7_i7 + 1) {
    c7_out[c7_i7] = 0.0;
  }

  /*  compute dimensions of triangle */
  _SFD_EML_CALL(0,61);
  c7_a = c7_y;
  c7_d_b = c7_y;
  c7_b_y = c7_a * c7_d_b;
  c7_b_a = c7_x;
  c7_e_b = c7_x;
  c7_c_y = c7_b_a * c7_e_b;
  c7_l = c7_sqrt(c7_c_y + c7_b_y);
  _SFD_EML_CALL(0,62);
  c7_f_b = c7_cos_theta;
  c7_d_y = 29.0 * c7_f_b;
  c7_e = (c7_l - c7_l1) - c7_d_y;
  _SFD_EML_CALL(0,63);
  c7_g_b = c7_sin_theta;
  c7_e_y = 29.0 * c7_g_b;
  c7_h = (-(c7_Height_A2 + c7_z)) - c7_e_y;
  _SFD_EML_CALL(0,64);
  c7_d = c7_sqrt(c7_mpower(c7_e) + c7_mpower(c7_h));

  /*  check whether the FAR location of C is reachable */
  _SFD_EML_CALL(0,67);
  c7_b = c7_l2;
  _SFD_EML_CALL(0,68);
  c7_c = c7_l3 + c7_l4;
  _SFD_EML_CALL(0,69);
  c7_margin = 5.0;

  /*  margin is 5 cm */
  _SFD_EML_CALL(0,70);
  if (CV_EML_IF(0, 0, c7_d > (c7_b + c7_c) - c7_margin)) {
    _SFD_EML_CALL(0,71);
    for (c7_i8 = 0; c7_i8 < 6; c7_i8 = c7_i8 + 1) {
      c7_out[c7_i8] = c7_vec[c7_i8 + 6];
    }

    /*  return angles 'as is' */
    _SFD_EML_CALL(0,72);
    c7_out[2] = -90.0;
    _SFD_EML_CALL(0,73);
    c7_out[6] = -2.0;
  } else {
    /*  check whether the CLOSE location of C is reachable */
    _SFD_EML_CALL(0,78);
    if (CV_EML_IF(0, 1, (c7_d + c7_c) - c7_margin < c7_b)) {
      _SFD_EML_CALL(0,79);
      for (c7_i9 = 0; c7_i9 < 6; c7_i9 = c7_i9 + 1) {
        c7_out[c7_i9] = c7_vec[c7_i9 + 6];
      }

      /*  return angles 'as is' */
      _SFD_EML_CALL(0,80);
      c7_out[2] = -90.0;
      _SFD_EML_CALL(0,81);
      c7_out[6] = -2.0;
    } else {
      /*  This iterative loop serves to correct for the offset of link A4 */
      /*  A first good guess is to assume that beta is initially 90 deg */
      /*  A second-order scheme is used */
      _SFD_EML_CALL(0,89);
      c7_A3 = c7_vec[8];
      _SFD_EML_CALL(0,90);
      c7_beta = c7_A3 + 180.0;
     label_1:
      ;
      CV_EML_WHILE(0, 0, true);
      _SFD_EML_CALL(0,94);
      c7_c_a = c7_beta;
      c7_f_x = c7_c_a * 1.7453292519943295E-002;
      c7_sin_beta = c7_f_x;
      c7_g_x = c7_sin_beta;
      c7_sin_beta = c7_g_x;
      c7_sin_beta = muDoubleScalarSin(c7_sin_beta);
      _SFD_EML_CALL(0,95);
      c7_d_a = c7_sin_beta;
      c7_h_b = c7_sin_beta;
      c7_sin2_beta = c7_d_a * c7_h_b;
      _SFD_EML_CALL(0,96);
      c7_e_a = c7_beta;
      c7_h_x = c7_e_a * 1.7453292519943295E-002;
      c7_cos_beta = c7_h_x;
      c7_i_x = c7_cos_beta;
      c7_cos_beta = c7_i_x;
      c7_cos_beta = muDoubleScalarCos(c7_cos_beta);
      _SFD_EML_CALL(0,98);
      c7_b = c7_l2 - c7_mrdivide(5.5, c7_sin_beta);
      _SFD_EML_CALL(0,99);
      c7_i_b = c7_cos_beta;
      c7_f_y = 5.5 * c7_i_b;
      c7_c = (c7_l3 + c7_l4) - c7_mrdivide(c7_f_y, c7_sin_beta);
      _SFD_EML_CALL(0,101);
      c7_j_b = c7_cos_beta;
      c7_g_y = 5.5 * c7_j_b;
      c7_db_dbeta = c7_mrdivide(c7_g_y, c7_sin2_beta);
      _SFD_EML_CALL(0,102);
      c7_dc_dbeta = c7_mrdivide(5.5, c7_sin2_beta);
      _SFD_EML_CALL(0,104);
      c7_f_a = c7_d;
      c7_k_b = c7_d;
      c7_h_y = c7_f_a * c7_k_b;
      c7_g_a = c7_c;
      c7_l_b = c7_c;
      c7_i_y = c7_g_a * c7_l_b;
      c7_h_a = c7_b;
      c7_m_b = c7_b;
      c7_j_y = c7_h_a * c7_m_b;
      c7_A = (c7_j_y + c7_i_y) - c7_h_y;
      _SFD_EML_CALL(0,105);
      c7_n_b = c7_b;
      c7_i_a = 2.0 * c7_n_b;
      c7_o_b = c7_c;
      c7_B = c7_i_a * c7_o_b;
      _SFD_EML_CALL(0,106);
      c7_p_b = c7_c;
      c7_j_a = 2.0 * c7_p_b;
      c7_q_b = c7_dc_dbeta;
      c7_k_y = c7_j_a * c7_q_b;
      c7_r_b = c7_b;
      c7_k_a = 2.0 * c7_r_b;
      c7_s_b = c7_db_dbeta;
      c7_l_y = c7_k_a * c7_s_b;
      c7_dA_dbeta = c7_l_y + c7_k_y;
      _SFD_EML_CALL(0,107);
      c7_l_a = c7_b;
      c7_t_b = c7_dc_dbeta;
      c7_m_y = c7_l_a * c7_t_b;
      c7_m_a = c7_db_dbeta;
      c7_u_b = c7_c;
      c7_n_y = c7_m_a * c7_u_b;
      c7_v_b = c7_n_y + c7_m_y;
      c7_dB_dbeta = 2.0 * c7_v_b;
      _SFD_EML_CALL(0,108);
      c7_eps = c7_cos_beta - c7_mrdivide(c7_A, c7_B);
      _SFD_EML_CALL(0,109);
      c7_n_a = c7_A;
      c7_w_b = c7_dB_dbeta;
      c7_o_y = c7_n_a * c7_w_b;
      c7_o_a = c7_dA_dbeta;
      c7_x_b = c7_B;
      c7_p_y = c7_o_a * c7_x_b;
      c7_deps_dbeta = (-c7_sin_beta) - c7_mrdivide(c7_p_y - c7_o_y, c7_mpower
        (c7_B));
      _SFD_EML_CALL(0,110);
      c7_y_b = c7_eps;
      c7_q_y = -5.7295779513082323E+001 * c7_y_b;
      c7_dbeta = c7_mrdivide(c7_q_y, c7_deps_dbeta);
      _SFD_EML_CALL(0,111);
      c7_beta = c7_beta + c7_dbeta;
      _SFD_EML_CALL(0,113);
      if (CV_EML_IF(0, 2, c7_abs(c7_dbeta) < 1.0E-005)) {
      } else {
        _SFD_EML_CALL(0,116);
        c7_N = c7_N + 1.0;
        _SFD_EML_CALL(0,117);
        sf_mex_listen_for_ctrl_c(chartInstance.S);
        if (CV_EML_IF(0, 3, c7_N > 100.0)) {
          _SFD_EML_CALL(0,118);
          c7_N = -2.0;
          _SFD_EML_CALL(0,119);
          for (c7_i10 = 0; c7_i10 < 6; c7_i10 = c7_i10 + 1) {
            c7_out[c7_i10] = c7_vec[c7_i10 + 6];
          }

          /*  return angles 'as is' */
          _SFD_EML_CALL(0,120);
          c7_out[2] = -90.0;
          _SFD_EML_CALL(0,121);
          c7_out[6] = c7_N;
        } else {
          goto label_1;
        }
      }

      /*  employ cosine rule on angles alpha and beta of triangle */
      _SFD_EML_CALL(0,127);
      c7_ab_b = c7_b;
      c7_p_a = 2.0 * c7_ab_b;
      c7_bb_b = c7_d;
      c7_r_y = c7_p_a * c7_bb_b;
      c7_q_a = c7_c;
      c7_cb_b = c7_c;
      c7_s_y = c7_q_a * c7_cb_b;
      c7_r_a = c7_d;
      c7_db_b = c7_d;
      c7_t_y = c7_r_a * c7_db_b;
      c7_s_a = c7_b;
      c7_eb_b = c7_b;
      c7_u_y = c7_s_a * c7_eb_b;
      c7_cos_alpha = c7_mrdivide((c7_u_y + c7_t_y) - c7_s_y, c7_r_y);
      _SFD_EML_CALL(0,129);
      c7_fb_b = c7_acos(c7_cos_alpha);
      c7_alpha = 5.7295779513082323E+001 * c7_fb_b;
      _SFD_EML_CALL(0,130);
      c7_gb_b = c7_atan2(c7_h, c7_e);
      c7_delta = 5.7295779513082323E+001 * c7_gb_b;

      /*  the link angles */
      _SFD_EML_CALL(0,133);
      c7_hb_b = c7_atan2(c7_y, c7_x);
      c7_A1 = 5.7295779513082323E+001 * c7_hb_b;
      _SFD_EML_CALL(0,134);
      c7_A2 = c7_alpha + c7_delta;
      _SFD_EML_CALL(0,135);
      c7_A3 = c7_beta - 180.0;
      _SFD_EML_CALL(0,136);
      c7_A4 = 0.0;
      _SFD_EML_CALL(0,137);
      c7_A5 = (-(c7_A2 + c7_A3)) + c7_theta;
      _SFD_EML_CALL(0,138);
      c7_A6 = 0.0;
      _SFD_EML_CALL(0,140);
      c7_b_A1[0] = c7_A1;
      c7_b_A1[1] = c7_A2;
      c7_b_A1[2] = c7_A3;
      c7_b_A1[3] = c7_A4;
      c7_b_A1[4] = c7_A5;
      c7_b_A1[5] = c7_A6;
      for (c7_i11 = 0; c7_i11 < 6; c7_i11 = c7_i11 + 1) {
        c7_J_ANG[c7_i11] = c7_b_A1[c7_i11];
      }

      _SFD_EML_CALL(0,141);
      for (c7_i12 = 0; c7_i12 < 6; c7_i12 = c7_i12 + 1) {
        c7_out[c7_i12] = c7_J_ANG[c7_i12];
      }

      /*  tests whether the links are within the set soft limits */
      c7_i = 1.0;
      c7_b_i = 1.0;
      while (c7_b_i <= 6.0) {
        c7_i = c7_b_i;
        CV_EML_FOR(0, 0, 1);
        _SFD_EML_CALL(0,145);
        if (CV_EML_IF(0, 4, c7_J_ANG[_SFD_EML_ARRAY_BOUNDS_CHECK("J_ANG",
              (int32_T)_SFD_INTEGER_CHECK("i", c7_i), 1, 6, 1, 0) - 1] >= c7_SL
                      [(
                        _SFD_EML_ARRAY_BOUNDS_CHECK("SL", (int32_T)
               _SFD_INTEGER_CHECK("i", c7_i), 1, 6, 2, 0) - 1) << 1])) {
          _SFD_EML_CALL(0,146);
          c7_N = -10.0 - c7_i;
        } else {
          _SFD_EML_CALL(0,147);
          if (CV_EML_IF(0, 5, c7_J_ANG[_SFD_EML_ARRAY_BOUNDS_CHECK("J_ANG",
                (int32_T)_SFD_INTEGER_CHECK("i", c7_i), 1, 6, 1, 0) - 1] <=
                        c7_SL[1
                        + ((_SFD_EML_ARRAY_BOUNDS_CHECK("SL", (int32_T)
                  _SFD_INTEGER_CHECK("i", c7_i), 1, 6, 2, 0) - 1) << 1)])) {
            _SFD_EML_CALL(0,148);
            c7_N = -100.0 - c7_i;
          }
        }

        c7_b_i = c7_b_i + 1.0;
        sf_mex_listen_for_ctrl_c(chartInstance.S);
      }

      CV_EML_FOR(0, 0, 0);
      _SFD_EML_CALL(0,152);
      c7_out[6] = c7_N;
    }
  }

  _SFD_EML_CALL(0,-152);
  sf_debug_symbol_scope_pop();
  for (c7_i13 = 0; c7_i13 < 7; c7_i13 = c7_i13 + 1) {
    (*c7_b_out)[c7_i13] = c7_out[c7_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,6);
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static real_T c7_mrdivide(real_T c7_A, real_T c7_B)
{
  real_T c7_x;
  real_T c7_b_y;
  real_T c7_b_x;
  real_T c7_c_y;
  real_T c7_c_x;
  real_T c7_d_y;
  c7_x = c7_A;
  c7_b_y = c7_B;
  if (c7_b_y == 0.0) {
    c7_eml_warning();
  }

  c7_b_x = c7_x;
  c7_c_y = c7_b_y;
  c7_c_x = c7_b_x;
  c7_d_y = c7_c_y;
  return c7_c_x / c7_d_y;
}

static void c7_eml_warning(void)
{
  int32_T c7_i14;
  static char_T c7_cv0[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c7_u[15];
  const mxArray *c7_y = NULL;
  int32_T c7_i15;
  static char_T c7_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c7_b_u[19];
  const mxArray *c7_b_y = NULL;
  for (c7_i14 = 0; c7_i14 < 15; c7_i14 = c7_i14 + 1) {
    c7_u[c7_i14] = c7_cv0[c7_i14];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c7_i15 = 0; c7_i15 < 19; c7_i15 = c7_i15 + 1) {
    c7_b_u[c7_i15] = c7_cv1[c7_i15];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c7_b_y, 14, c7_y);
}

static real_T c7_sqrt(real_T c7_x)
{
  real_T c7_b_x;
  real_T c7_c_x;
  c7_b_x = c7_x;
  if (c7_b_x < 0.0) {
    c7_eml_error();
  }

  c7_c_x = c7_b_x;
  c7_b_x = c7_c_x;
  return muDoubleScalarSqrt(c7_b_x);
}

static void c7_eml_error(void)
{
  int32_T c7_i16;
  static char_T c7_cv2[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c7_u[77];
  const mxArray *c7_y = NULL;
  int32_T c7_i17;
  static char_T c7_cv3[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c7_b_u[31];
  const mxArray *c7_b_y = NULL;
  for (c7_i16 = 0; c7_i16 < 77; c7_i16 = c7_i16 + 1) {
    c7_u[c7_i16] = c7_cv2[c7_i16];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c7_i17 = 0; c7_i17 < 31; c7_i17 = c7_i17 + 1) {
    c7_b_u[c7_i17] = c7_cv3[c7_i17];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c7_b_y, 14, c7_y);
}

static real_T c7_mpower(real_T c7_a)
{
  real_T c7_b_a;
  real_T c7_ak;
  c7_b_a = c7_a;
  c7_eml_scalar_eg();
  c7_ak = c7_b_a;
  return muDoubleScalarPower(c7_ak, 2.0);
}

static void c7_eml_scalar_eg(void)
{
}

static real_T c7_abs(real_T c7_x)
{
  real_T c7_b_x;
  c7_b_x = c7_x;
  return muDoubleScalarAbs(c7_b_x);
}

static real_T c7_acos(real_T c7_x)
{
  real_T c7_b_x;
  real_T c7_c_x;
  c7_b_x = c7_x;
  if (c7_b_x < -1.0) {
  } else if (1.0 < c7_b_x) {
  } else {
    goto label_1;
  }

  c7_b_eml_error();
 label_1:
  ;
  c7_c_x = c7_b_x;
  c7_b_x = c7_c_x;
  return muDoubleScalarAcos(c7_b_x);
}

static void c7_b_eml_error(void)
{
  int32_T c7_i18;
  static char_T c7_cv4[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 'a', 'c',
    'o', 's', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c7_u[77];
  const mxArray *c7_y = NULL;
  int32_T c7_i19;
  static char_T c7_cv5[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'a', 'c', 'o', 's', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c7_b_u[31];
  const mxArray *c7_b_y = NULL;
  for (c7_i18 = 0; c7_i18 < 77; c7_i18 = c7_i18 + 1) {
    c7_u[c7_i18] = c7_cv4[c7_i18];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c7_i19 = 0; c7_i19 < 31; c7_i19 = c7_i19 + 1) {
    c7_b_u[c7_i19] = c7_cv5[c7_i19];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c7_b_y, 14, c7_y);
}

static real_T c7_atan2(real_T c7_y, real_T c7_x)
{
  real_T c7_b_y;
  real_T c7_b_x;
  c7_eml_scalar_eg();
  c7_b_y = c7_y;
  c7_b_x = c7_x;
  return muDoubleScalarAtan2(c7_b_y, c7_b_x);
}

static const mxArray *c7_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  int32_T c7_i20;
  real_T c7_b_u[12];
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  for (c7_i20 = 0; c7_i20 < 12; c7_i20 = c7_i20 + 1) {
    c7_b_u[c7_i20] = (*((real_T (*)[12])c7_u))[c7_i20];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 1U, 0U, 1, 12));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static const mxArray *c7_b_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  int32_T c7_i21;
  real_T c7_b_u[7];
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  for (c7_i21 = 0; c7_i21 < 7; c7_i21 = c7_i21 + 1) {
    c7_b_u[c7_i21] = (*((real_T (*)[7])c7_u))[c7_i21];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 1U, 0U, 1, 7));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static const mxArray *c7_c_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  real_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  c7_b_u = *((real_T *)c7_u);
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static const mxArray *c7_d_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  int32_T c7_i22;
  int32_T c7_i23;
  int32_T c7_i24;
  real_T c7_b_u[12];
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  c7_i22 = 0;
  for (c7_i23 = 0; c7_i23 < 6; c7_i23 = c7_i23 + 1) {
    for (c7_i24 = 0; c7_i24 < 2; c7_i24 = c7_i24 + 1) {
      c7_b_u[c7_i24 + c7_i22] = (*((real_T (*)[12])c7_u))[c7_i24 + c7_i22];
    }

    c7_i22 = c7_i22 + 2;
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 1U, 0U, 2, 2, 6));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static const mxArray *c7_e_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  int32_T c7_i25;
  real_T c7_b_u[6];
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  for (c7_i25 = 0; c7_i25 < 6; c7_i25 = c7_i25 + 1) {
    c7_b_u[c7_i25] = (*((real_T (*)[6])c7_u))[c7_i25];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

const mxArray
  *sf_c7_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_ResolvedFunctionInfo c7_info[51];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i26;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_info_helper(c7_info);
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 51));
  for (c7_i26 = 0; c7_i26 < 51; c7_i26 = c7_i26 + 1) {
    c7_r0 = &c7_info[c7_i26];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context",
                    "nameCaptureInfo", c7_i26);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name",
                    "nameCaptureInfo", c7_i26);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c7_i26);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c7_i26);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c7_i26);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c7_i26
                    );
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c7_i26
                    );
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[51])
{
  c7_info[0].context = "";
  c7_info[0].name = "pi";
  c7_info[0].dominantType = "";
  c7_info[0].resolved = "[B]pi";
  c7_info[0].fileLength = 0U;
  c7_info[0].fileTime1 = 0U;
  c7_info[0].fileTime2 = 0U;
  c7_info[1].context = "";
  c7_info[1].name = "mrdivide";
  c7_info[1].dominantType = "double";
  c7_info[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c7_info[1].fileLength = 800U;
  c7_info[1].fileTime1 = 1238434292U;
  c7_info[1].fileTime2 = 0U;
  c7_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c7_info[2].name = "nargin";
  c7_info[2].dominantType = "";
  c7_info[2].resolved = "[B]nargin";
  c7_info[2].fileLength = 0U;
  c7_info[2].fileTime1 = 0U;
  c7_info[2].fileTime2 = 0U;
  c7_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c7_info[3].name = "ge";
  c7_info[3].dominantType = "double";
  c7_info[3].resolved = "[B]ge";
  c7_info[3].fileLength = 0U;
  c7_info[3].fileTime1 = 0U;
  c7_info[3].fileTime2 = 0U;
  c7_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c7_info[4].name = "isscalar";
  c7_info[4].dominantType = "double";
  c7_info[4].resolved = "[B]isscalar";
  c7_info[4].fileLength = 0U;
  c7_info[4].fileTime1 = 0U;
  c7_info[4].fileTime2 = 0U;
  c7_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c7_info[5].name = "rdivide";
  c7_info[5].dominantType = "double";
  c7_info[5].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[5].fileLength = 620U;
  c7_info[5].fileTime1 = 1213926766U;
  c7_info[5].fileTime2 = 0U;
  c7_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[6].name = "gt";
  c7_info[6].dominantType = "double";
  c7_info[6].resolved = "[B]gt";
  c7_info[6].fileLength = 0U;
  c7_info[6].fileTime1 = 0U;
  c7_info[6].fileTime2 = 0U;
  c7_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[7].name = "isa";
  c7_info[7].dominantType = "double";
  c7_info[7].resolved = "[B]isa";
  c7_info[7].fileLength = 0U;
  c7_info[7].fileTime1 = 0U;
  c7_info[7].fileTime2 = 0U;
  c7_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[8].name = "isempty";
  c7_info[8].dominantType = "double";
  c7_info[8].resolved = "[B]isempty";
  c7_info[8].fileLength = 0U;
  c7_info[8].fileTime1 = 0U;
  c7_info[8].fileTime2 = 0U;
  c7_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[9].name = "not";
  c7_info[9].dominantType = "logical";
  c7_info[9].resolved = "[B]not";
  c7_info[9].fileLength = 0U;
  c7_info[9].fileTime1 = 0U;
  c7_info[9].fileTime2 = 0U;
  c7_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[10].name = "strcmp";
  c7_info[10].dominantType = "char";
  c7_info[10].resolved = "[B]strcmp";
  c7_info[10].fileLength = 0U;
  c7_info[10].fileTime1 = 0U;
  c7_info[10].fileTime2 = 0U;
  c7_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[11].name = "eq";
  c7_info[11].dominantType = "double";
  c7_info[11].resolved = "[B]eq";
  c7_info[11].fileLength = 0U;
  c7_info[11].fileTime1 = 0U;
  c7_info[11].fileTime2 = 0U;
  c7_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[12].name = "eml_warning";
  c7_info[12].dominantType = "char";
  c7_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c7_info[12].fileLength = 262U;
  c7_info[12].fileTime1 = 1236257278U;
  c7_info[12].fileTime2 = 0U;
  c7_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[13].name = "eml_div";
  c7_info[13].dominantType = "double";
  c7_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c7_info[13].fileLength = 4269U;
  c7_info[13].fileTime1 = 1228093826U;
  c7_info[13].fileTime2 = 0U;
  c7_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c7_info[14].name = "isinteger";
  c7_info[14].dominantType = "double";
  c7_info[14].resolved = "[B]isinteger";
  c7_info[14].fileLength = 0U;
  c7_info[14].fileTime1 = 0U;
  c7_info[14].fileTime2 = 0U;
  c7_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c7_info[15].name = "isreal";
  c7_info[15].dominantType = "double";
  c7_info[15].resolved = "[B]isreal";
  c7_info[15].fileLength = 0U;
  c7_info[15].fileTime1 = 0U;
  c7_info[15].fileTime2 = 0U;
  c7_info[16].context = "";
  c7_info[16].name = "uminus";
  c7_info[16].dominantType = "double";
  c7_info[16].resolved = "[B]uminus";
  c7_info[16].fileLength = 0U;
  c7_info[16].fileTime1 = 0U;
  c7_info[16].fileTime2 = 0U;
  c7_info[17].context = "";
  c7_info[17].name = "plus";
  c7_info[17].dominantType = "double";
  c7_info[17].resolved = "[B]plus";
  c7_info[17].fileLength = 0U;
  c7_info[17].fileTime1 = 0U;
  c7_info[17].fileTime2 = 0U;
  c7_info[18].context = "";
  c7_info[18].name = "mtimes";
  c7_info[18].dominantType = "double";
  c7_info[18].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[18].fileLength = 3302U;
  c7_info[18].fileTime1 = 1242750894U;
  c7_info[18].fileTime2 = 0U;
  c7_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[19].name = "size";
  c7_info[19].dominantType = "double";
  c7_info[19].resolved = "[B]size";
  c7_info[19].fileLength = 0U;
  c7_info[19].fileTime1 = 0U;
  c7_info[19].fileTime2 = 0U;
  c7_info[20].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[20].name = "class";
  c7_info[20].dominantType = "double";
  c7_info[20].resolved = "[B]class";
  c7_info[20].fileLength = 0U;
  c7_info[20].fileTime1 = 0U;
  c7_info[20].fileTime2 = 0U;
  c7_info[21].context = "";
  c7_info[21].name = "cos";
  c7_info[21].dominantType = "double";
  c7_info[21].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c7_info[21].fileLength = 324U;
  c7_info[21].fileTime1 = 1203447952U;
  c7_info[21].fileTime2 = 0U;
  c7_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c7_info[22].name = "eml_scalar_cos";
  c7_info[22].dominantType = "double";
  c7_info[22].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c7_info[22].fileLength = 602U;
  c7_info[22].fileTime1 = 1209330788U;
  c7_info[22].fileTime2 = 0U;
  c7_info[23].context = "";
  c7_info[23].name = "sin";
  c7_info[23].dominantType = "double";
  c7_info[23].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c7_info[23].fileLength = 324U;
  c7_info[23].fileTime1 = 1203448042U;
  c7_info[23].fileTime2 = 0U;
  c7_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c7_info[24].name = "eml_scalar_sin";
  c7_info[24].dominantType = "double";
  c7_info[24].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c7_info[24].fileLength = 601U;
  c7_info[24].fileTime1 = 1209330792U;
  c7_info[24].fileTime2 = 0U;
  c7_info[25].context = "";
  c7_info[25].name = "zeros";
  c7_info[25].dominantType = "double";
  c7_info[25].resolved = "[B]zeros";
  c7_info[25].fileLength = 0U;
  c7_info[25].fileTime1 = 0U;
  c7_info[25].fileTime2 = 0U;
  c7_info[26].context = "";
  c7_info[26].name = "sqrt";
  c7_info[26].dominantType = "double";
  c7_info[26].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[26].fileLength = 572U;
  c7_info[26].fileTime1 = 1203448046U;
  c7_info[26].fileTime2 = 0U;
  c7_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[27].name = "lt";
  c7_info[27].dominantType = "double";
  c7_info[27].resolved = "[B]lt";
  c7_info[27].fileLength = 0U;
  c7_info[27].fileTime1 = 0U;
  c7_info[27].fileTime2 = 0U;
  c7_info[28].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[28].name = "eml_error";
  c7_info[28].dominantType = "char";
  c7_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c7_info[28].fileLength = 315U;
  c7_info[28].fileTime1 = 1213926746U;
  c7_info[28].fileTime2 = 0U;
  c7_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[29].name = "eml_scalar_sqrt";
  c7_info[29].dominantType = "double";
  c7_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c7_info[29].fileLength = 664U;
  c7_info[29].fileTime1 = 1209330794U;
  c7_info[29].fileTime2 = 0U;
  c7_info[30].context = "";
  c7_info[30].name = "minus";
  c7_info[30].dominantType = "double";
  c7_info[30].resolved = "[B]minus";
  c7_info[30].fileLength = 0U;
  c7_info[30].fileTime1 = 0U;
  c7_info[30].fileTime2 = 0U;
  c7_info[31].context = "";
  c7_info[31].name = "mpower";
  c7_info[31].dominantType = "double";
  c7_info[31].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[31].fileLength = 3710U;
  c7_info[31].fileTime1 = 1238434290U;
  c7_info[31].fileTime2 = 0U;
  c7_info[32].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[32].name = "ndims";
  c7_info[32].dominantType = "double";
  c7_info[32].resolved = "[B]ndims";
  c7_info[32].fileLength = 0U;
  c7_info[32].fileTime1 = 0U;
  c7_info[32].fileTime2 = 0U;
  c7_info[33].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[33].name = "power";
  c7_info[33].dominantType = "double";
  c7_info[33].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[33].fileLength = 5380U;
  c7_info[33].fileTime1 = 1228093898U;
  c7_info[33].fileTime2 = 0U;
  c7_info[34].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[34].name = "eml_scalar_eg";
  c7_info[34].dominantType = "double";
  c7_info[34].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[34].fileLength = 3068U;
  c7_info[34].fileTime1 = 1240262010U;
  c7_info[34].fileTime2 = 0U;
  c7_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c7_info[35].name = "false";
  c7_info[35].dominantType = "";
  c7_info[35].resolved = "[B]false";
  c7_info[35].fileLength = 0U;
  c7_info[35].fileTime1 = 0U;
  c7_info[35].fileTime2 = 0U;
  c7_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[36].name = "isstruct";
  c7_info[36].dominantType = "double";
  c7_info[36].resolved = "[B]isstruct";
  c7_info[36].fileLength = 0U;
  c7_info[36].fileTime1 = 0U;
  c7_info[36].fileTime2 = 0U;
  c7_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c7_info[37].name = "cast";
  c7_info[37].dominantType = "double";
  c7_info[37].resolved = "[B]cast";
  c7_info[37].fileLength = 0U;
  c7_info[37].fileTime1 = 0U;
  c7_info[37].fileTime2 = 0U;
  c7_info[38].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[38].name = "eml_scalexp_alloc";
  c7_info[38].dominantType = "double";
  c7_info[38].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c7_info[38].fileLength = 808U;
  c7_info[38].fileTime1 = 1230494700U;
  c7_info[38].fileTime2 = 0U;
  c7_info[39].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[39].name = "eml_scalar_floor";
  c7_info[39].dominantType = "double";
  c7_info[39].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c7_info[39].fileLength = 260U;
  c7_info[39].fileTime1 = 1209330790U;
  c7_info[39].fileTime2 = 0U;
  c7_info[40].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[40].name = "ne";
  c7_info[40].dominantType = "double";
  c7_info[40].resolved = "[B]ne";
  c7_info[40].fileLength = 0U;
  c7_info[40].fileTime1 = 0U;
  c7_info[40].fileTime2 = 0U;
  c7_info[41].context = "";
  c7_info[41].name = "abs";
  c7_info[41].dominantType = "double";
  c7_info[41].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[41].fileLength = 566U;
  c7_info[41].fileTime1 = 1221267134U;
  c7_info[41].fileTime2 = 0U;
  c7_info[42].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[42].name = "ischar";
  c7_info[42].dominantType = "double";
  c7_info[42].resolved = "[B]ischar";
  c7_info[42].fileLength = 0U;
  c7_info[42].fileTime1 = 0U;
  c7_info[42].fileTime2 = 0U;
  c7_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[43].name = "islogical";
  c7_info[43].dominantType = "double";
  c7_info[43].resolved = "[B]islogical";
  c7_info[43].fileLength = 0U;
  c7_info[43].fileTime1 = 0U;
  c7_info[43].fileTime2 = 0U;
  c7_info[44].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[44].name = "eml_scalar_abs";
  c7_info[44].dominantType = "double";
  c7_info[44].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c7_info[44].fileLength = 461U;
  c7_info[44].fileTime1 = 1203447960U;
  c7_info[44].fileTime2 = 0U;
  c7_info[45].context = "";
  c7_info[45].name = "acos";
  c7_info[45].dominantType = "double";
  c7_info[45].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c7_info[45].fileLength = 585U;
  c7_info[45].fileTime1 = 1203447930U;
  c7_info[45].fileTime2 = 0U;
  c7_info[46].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c7_info[46].name = "eml_scalar_acos";
  c7_info[46].dominantType = "double";
  c7_info[46].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m";
  c7_info[46].fileLength = 553U;
  c7_info[46].fileTime1 = 1203447962U;
  c7_info[46].fileTime2 = 0U;
  c7_info[47].context = "";
  c7_info[47].name = "atan2";
  c7_info[47].dominantType = "double";
  c7_info[47].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c7_info[47].fileLength = 605U;
  c7_info[47].fileTime1 = 1236257254U;
  c7_info[47].fileTime2 = 0U;
  c7_info[48].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c7_info[48].name = "eml_scalar_atan2";
  c7_info[48].dominantType = "double";
  c7_info[48].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c7_info[48].fileLength = 964U;
  c7_info[48].fileTime1 = 1209330786U;
  c7_info[48].fileTime2 = 0U;
  c7_info[49].context = "";
  c7_info[49].name = "ctranspose";
  c7_info[49].dominantType = "double";
  c7_info[49].resolved = "[B]ctranspose";
  c7_info[49].fileLength = 0U;
  c7_info[49].fileTime1 = 0U;
  c7_info[49].fileTime2 = 0U;
  c7_info[50].context = "";
  c7_info[50].name = "le";
  c7_info[50].dominantType = "double";
  c7_info[50].resolved = "[B]le";
  c7_info[50].fileLength = 0U;
  c7_info[50].fileTime1 = 0U;
  c7_info[50].fileTime2 = 0U;
}

static const mxArray *c7_f_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  boolean_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  c7_b_u = *((boolean_T *)c7_u);
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c7_M43_Sim_Forcing_003h_Trajectory_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1936897056U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3873609522U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(122218649U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(727357242U);
}

mxArray *sf_c7_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2628923291U);
    pr[1] = (double)(4008189770U);
    pr[2] = (double)(751154912U);
    pr[3] = (double)(2774781043U);
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

static mxArray *sf_get_sim_state_info_c7_M43_Sim_Forcing_003h_Trajectory(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"out\",},{M[8],M[0],T\"is_active_c7_M43_Sim_Forcing_003h_Trajectory\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_M43_Sim_Forcing_003h_Trajectory_get_check_sum(&mxChecksum);
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
           7,
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
                                1.0,0,"vec",0,(MexFcnForType)c7_sf_marshall);
          }

          {
            unsigned int dimVector[1];
            dimVector[0]= 7;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
                                1.0,0,"out",0,(MexFcnForType)c7_b_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,6,0,1,1,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4170);
        _SFD_CV_INIT_EML_IF(0,0,2360,2381,2542,2669);
        _SFD_CV_INIT_EML_IF(0,1,2542,2563,2866,3646);
        _SFD_CV_INIT_EML_IF(0,2,3428,3449,3491,3642);
        _SFD_CV_INIT_EML_IF(0,3,3491,3501,2866,3646);
        _SFD_CV_INIT_EML_IF(0,4,4046,4068,4092,4146);
        _SFD_CV_INIT_EML_IF(0,5,4092,4118,-1,4118);
        _SFD_CV_INIT_EML_FOR(0,0,4028,4042,4150);
        _SFD_CV_INIT_EML_WHILE(0,0,2866,2874,3646);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T (*c7_vec)[12];
          real_T (*c7_out)[7];
          c7_out = (real_T (*)[7])ssGetOutputPortSignal(chartInstance.S, 1);
          c7_vec = (real_T (*)[12])ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_vec);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c7_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c7_M43_Sim_Forcing_003h_Trajectory();
  initialize_c7_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_enable_c7_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  enable_c7_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_disable_c7_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  disable_c7_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_gateway_c7_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  sf_c7_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_ext_mode_exec_c7_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  ext_mode_exec_c7_M43_Sim_Forcing_003h_Trajectory();
}

static mxArray* sf_opaque_get_sim_state_c7_M43_Sim_Forcing_003h_Trajectory(void *
  chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c7_M43_Sim_Forcing_003h_Trajectory();
  return st;
}

static void sf_opaque_set_sim_state_c7_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c7_M43_Sim_Forcing_003h_Trajectory(sf_mex_dup(st));
}

static void sf_opaque_terminate_c7_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c7_M43_Sim_Forcing_003h_Trajectory();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_M43_Sim_Forcing_003h_Trajectory();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c7_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M43_Sim_Forcing_003h_Trajectory",
      "M43_Sim_Forcing_003h_Trajectory",7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("M43_Sim_Forcing_003h_Trajectory",
                "M43_Sim_Forcing_003h_Trajectory",7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M43_Sim_Forcing_003h_Trajectory","M43_Sim_Forcing_003h_Trajectory",7,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"M43_Sim_Forcing_003h_Trajectory",
        "M43_Sim_Forcing_003h_Trajectory",7,1);
      sf_mark_chart_reusable_outputs(S,"M43_Sim_Forcing_003h_Trajectory",
        "M43_Sim_Forcing_003h_Trajectory",7,1);
    }

    sf_set_rtw_dwork_info(S,"M43_Sim_Forcing_003h_Trajectory",
                          "M43_Sim_Forcing_003h_Trajectory",7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1465926110U));
  ssSetChecksum1(S,(1165358059U));
  ssSetChecksum2(S,(3379652250U));
  ssSetChecksum3(S,(1207474895U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c7_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M43_Sim_Forcing_003h_Trajectory",
      "M43_Sim_Forcing_003h_Trajectory",7);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c7_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c7_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c7_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c7_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c7_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.mdlStart = mdlStart_c7_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c7_M43_Sim_Forcing_003h_Trajectory;
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

void c7_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_M43_Sim_Forcing_003h_Trajectory_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

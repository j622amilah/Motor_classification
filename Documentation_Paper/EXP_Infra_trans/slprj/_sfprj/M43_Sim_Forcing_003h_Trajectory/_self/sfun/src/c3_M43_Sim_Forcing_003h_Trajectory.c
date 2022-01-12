/* Include files */

#include "blascompat32.h"
#include "M43_Sim_Forcing_003h_Trajectory_sfun.h"
#include "c3_M43_Sim_Forcing_003h_Trajectory.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M43_Sim_Forcing_003h_Trajectory_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c3_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc3_M43_Sim_Forcing_003h_TrajectoryInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c3_M43_Sim_Forcing_003h_Trajectory(void);
static void initialize_params_c3_M43_Sim_Forcing_003h_Trajectory(void);
static void enable_c3_M43_Sim_Forcing_003h_Trajectory(void);
static void disable_c3_M43_Sim_Forcing_003h_Trajectory(void);
static void c3_update_debugger_state_c3_M43_Sim_Forcing_003h_Trajectory(void);
static void ext_mode_exec_c3_M43_Sim_Forcing_003h_Trajectory(void);
static const mxArray *get_sim_state_c3_M43_Sim_Forcing_003h_Trajectory(void);
static void set_sim_state_c3_M43_Sim_Forcing_003h_Trajectory(const mxArray
  *c3_st);
static void finalize_c3_M43_Sim_Forcing_003h_Trajectory(void);
static void sf_c3_M43_Sim_Forcing_003h_Trajectory(void);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static void c3_eml_warning(void);
static const mxArray *c3_sf_marshall(void *c3_chartInstance, void *c3_u);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[44]);
static const mxArray *c3_b_sf_marshall(void *c3_chartInstance, void *c3_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c3_M43_Sim_Forcing_003h_Trajectory(void)
{
  uint8_T *c3_is_active_c3_M43_Sim_Forcing_003h_Trajectory;
  c3_is_active_c3_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c3_is_active_c3_M43_Sim_Forcing_003h_Trajectory = 0U;
}

static void initialize_params_c3_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void enable_c3_M43_Sim_Forcing_003h_Trajectory(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c3_M43_Sim_Forcing_003h_Trajectory(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c3_update_debugger_state_c3_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void ext_mode_exec_c3_M43_Sim_Forcing_003h_Trajectory(void)
{
  c3_update_debugger_state_c3_M43_Sim_Forcing_003h_Trajectory();
}

static const mxArray *get_sim_state_c3_M43_Sim_Forcing_003h_Trajectory(void)
{
  const mxArray *c3_st = NULL;
  const mxArray *c3_y = NULL;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T *c3_d_psi;
  uint8_T *c3_is_active_c3_M43_Sim_Forcing_003h_Trajectory;
  c3_is_active_c3_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c3_d_psi = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2));
  c3_u = *c3_d_psi;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_u = *c3_is_active_c3_M43_Sim_Forcing_003h_Trajectory;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y);
  return c3_st;
}

static void set_sim_state_c3_M43_Sim_Forcing_003h_Trajectory(const mxArray
  *c3_st)
{
  const mxArray *c3_u;
  const mxArray *c3_d_psi;
  real_T c3_d0;
  real_T c3_y;
  const mxArray *c3_is_active_c3_M43_Sim_Forcing_003h_Trajectory;
  uint8_T c3_u0;
  uint8_T c3_b_y;
  boolean_T *c3_doneDoubleBufferReInit;
  real_T *c3_b_d_psi;
  uint8_T *c3_b_is_active_c3_M43_Sim_Forcing_003h_Trajectory;
  c3_b_is_active_c3_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c3_b_d_psi = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c3_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  *c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  c3_d_psi = sf_mex_dup(sf_mex_getcell(c3_u, 0));
  sf_mex_import("d_psi", sf_mex_dup(c3_d_psi), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_d_psi);
  *c3_b_d_psi = c3_y;
  c3_is_active_c3_M43_Sim_Forcing_003h_Trajectory = sf_mex_dup(sf_mex_getcell
    (c3_u, 1));
  sf_mex_import("is_active_c3_M43_Sim_Forcing_003h_Trajectory", sf_mex_dup
                (c3_is_active_c3_M43_Sim_Forcing_003h_Trajectory), &c3_u0, 1
                , 3, 0U, 0, 0U, 0);
  c3_b_y = c3_u0;
  sf_mex_destroy(&c3_is_active_c3_M43_Sim_Forcing_003h_Trajectory);
  *c3_b_is_active_c3_M43_Sim_Forcing_003h_Trajectory = c3_b_y;
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_M43_Sim_Forcing_003h_Trajectory();
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void sf_c3_M43_Sim_Forcing_003h_Trajectory(void)
{
  int32_T c3_previousEvent;
  real_T c3_x_cab;
  real_T c3_y_cab;
  real_T c3_max_OOP_psi;
  real_T c3_nargout = 1.0;
  real_T c3_nargin = 3.0;
  real_T c3_psi_out;
  real_T c3_psi_in;
  real_T c3_RTD;
  real_T c3_DTR;
  real_T c3_d_psi;
  real_T c3_y;
  real_T c3_x;
  real_T c3_b_y;
  real_T c3_b_x;
  real_T c3_b;
  real_T c3_c_x;
  real_T c3_a;
  real_T c3_d_x;
  real_T c3_e_x;
  boolean_T c3_b_b;
  real_T c3_c_b;
  real_T c3_b_a;
  real_T c3_A;
  real_T c3_B;
  real_T c3_f_x;
  real_T c3_c_y;
  real_T c3_g_x;
  real_T c3_d_y;
  real_T c3_h_x;
  real_T c3_e_y;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_f_y;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_m_x;
  real_T c3_d_b;
  real_T *c3_b_d_psi;
  real_T *c3_b_max_OOP_psi;
  real_T *c3_b_y_cab;
  real_T *c3_b_x_cab;
  c3_b_max_OOP_psi = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c3_b_y_cab = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c3_b_x_cab = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c3_b_d_psi = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,2);
  _SFD_DATA_RANGE_CHECK(*c3_b_x_cab, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_b_y_cab, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_b_max_OOP_psi, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_b_d_psi, 3U);
  c3_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,2);
  c3_x_cab = *c3_b_x_cab;
  c3_y_cab = *c3_b_y_cab;
  c3_max_OOP_psi = *c3_b_max_OOP_psi;
  sf_debug_symbol_scope_push(10U, 0U);
  sf_debug_symbol_scope_add("nargout", &c3_nargout, c3_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c3_nargin, c3_sf_marshall);
  sf_debug_symbol_scope_add("psi_out", &c3_psi_out, c3_sf_marshall);
  sf_debug_symbol_scope_add("psi_in", &c3_psi_in, c3_sf_marshall);
  sf_debug_symbol_scope_add("RTD", &c3_RTD, c3_sf_marshall);
  sf_debug_symbol_scope_add("DTR", &c3_DTR, c3_sf_marshall);
  sf_debug_symbol_scope_add("d_psi", &c3_d_psi, c3_sf_marshall);
  sf_debug_symbol_scope_add("max_OOP_psi", &c3_max_OOP_psi, c3_sf_marshall);
  sf_debug_symbol_scope_add("y_cab", &c3_y_cab, c3_sf_marshall);
  sf_debug_symbol_scope_add("x_cab", &c3_x_cab, c3_sf_marshall);
  CV_EML_FCN(0, 0);

  /*  soft limits on out-of-plane psi OOP_psi */
  _SFD_EML_CALL(0,6);
  c3_DTR = 1.7453292519943295E-002;
  _SFD_EML_CALL(0,7);
  c3_RTD = 5.7295779513082323E+001;
  _SFD_EML_CALL(0,9);
  c3_y = c3_y_cab;
  c3_x = c3_x_cab;
  c3_b_y = c3_y;
  c3_b_x = c3_x;
  c3_b = muDoubleScalarAtan2(c3_b_y, c3_b_x);
  c3_psi_in = 5.7295779513082323E+001 * c3_b;
  _SFD_EML_CALL(0,10);
  c3_c_x = c3_psi_in;
  c3_a = c3_c_x;
  c3_d_x = c3_a;
  c3_a = c3_d_x;
  c3_e_x = c3_a;
  c3_b_b = rtIsNaN(c3_e_x);
  if (c3_b_b) {
    c3_a = rtNaN;
  } else if (c3_a > 0.0) {
    c3_a = 1.0;
  } else if (c3_a < 0.0) {
    c3_a = -1.0;
  } else {
    c3_a = 0.0;
  }

  c3_c_b = c3_max_OOP_psi;
  c3_b_a = c3_a * c3_c_b;
  c3_A = c3_psi_in;
  c3_B = c3_max_OOP_psi;
  c3_f_x = c3_A;
  c3_c_y = c3_B;
  if (c3_c_y == 0.0) {
    c3_eml_warning();
  }

  c3_g_x = c3_f_x;
  c3_d_y = c3_c_y;
  c3_h_x = c3_g_x;
  c3_e_y = c3_d_y;
  c3_i_x = c3_h_x / c3_e_y;
  c3_j_x = c3_i_x;
  c3_f_y = muDoubleScalarAbs(c3_j_x);
  c3_k_x = -c3_f_y;
  c3_l_x = c3_k_x;
  c3_m_x = c3_l_x;
  c3_l_x = c3_m_x;
  c3_l_x = muDoubleScalarExp(c3_l_x);
  c3_d_b = 1.0 - c3_l_x;
  c3_psi_out = c3_b_a * c3_d_b;
  _SFD_EML_CALL(0,11);
  c3_d_psi = c3_psi_in - c3_psi_out;
  _SFD_EML_CALL(0,-11);
  sf_debug_symbol_scope_pop();
  *c3_b_d_psi = c3_d_psi;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
  _sfEvent_ = c3_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static void c3_eml_warning(void)
{
  int32_T c3_i0;
  static char_T c3_cv0[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c3_u[15];
  const mxArray *c3_y = NULL;
  int32_T c3_i1;
  static char_T c3_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c3_b_u[19];
  const mxArray *c3_b_y = NULL;
  for (c3_i0 = 0; c3_i0 < 15; c3_i0 = c3_i0 + 1) {
    c3_u[c3_i0] = c3_cv0[c3_i0];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c3_i1 = 0; c3_i1 < 19; c3_i1 = c3_i1 + 1) {
    c3_b_u[c3_i1] = c3_cv1[c3_i1];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c3_b_y, 14, c3_y);
}

static const mxArray *c3_sf_marshall(void *c3_chartInstance, void *c3_u)
{
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  c3_y = NULL;
  c3_b_u = *((real_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

const mxArray
  *sf_c3_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_ResolvedFunctionInfo c3_info[44];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i2;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 44));
  for (c3_i2 = 0; c3_i2 < 44; c3_i2 = c3_i2 + 1) {
    c3_r0 = &c3_info[c3_i2];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context",
                    "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name",
                    "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c3_i2);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c3_i2);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[44])
{
  c3_info[0].context = "";
  c3_info[0].name = "pi";
  c3_info[0].dominantType = "";
  c3_info[0].resolved = "[B]pi";
  c3_info[0].fileLength = 0U;
  c3_info[0].fileTime1 = 0U;
  c3_info[0].fileTime2 = 0U;
  c3_info[1].context = "";
  c3_info[1].name = "mrdivide";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[1].fileLength = 800U;
  c3_info[1].fileTime1 = 1238434292U;
  c3_info[1].fileTime2 = 0U;
  c3_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[2].name = "nargin";
  c3_info[2].dominantType = "";
  c3_info[2].resolved = "[B]nargin";
  c3_info[2].fileLength = 0U;
  c3_info[2].fileTime1 = 0U;
  c3_info[2].fileTime2 = 0U;
  c3_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[3].name = "ge";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved = "[B]ge";
  c3_info[3].fileLength = 0U;
  c3_info[3].fileTime1 = 0U;
  c3_info[3].fileTime2 = 0U;
  c3_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[4].name = "isscalar";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved = "[B]isscalar";
  c3_info[4].fileLength = 0U;
  c3_info[4].fileTime1 = 0U;
  c3_info[4].fileTime2 = 0U;
  c3_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[5].name = "rdivide";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[5].fileLength = 620U;
  c3_info[5].fileTime1 = 1213926766U;
  c3_info[5].fileTime2 = 0U;
  c3_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[6].name = "gt";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved = "[B]gt";
  c3_info[6].fileLength = 0U;
  c3_info[6].fileTime1 = 0U;
  c3_info[6].fileTime2 = 0U;
  c3_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[7].name = "isa";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved = "[B]isa";
  c3_info[7].fileLength = 0U;
  c3_info[7].fileTime1 = 0U;
  c3_info[7].fileTime2 = 0U;
  c3_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[8].name = "isempty";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved = "[B]isempty";
  c3_info[8].fileLength = 0U;
  c3_info[8].fileTime1 = 0U;
  c3_info[8].fileTime2 = 0U;
  c3_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[9].name = "not";
  c3_info[9].dominantType = "logical";
  c3_info[9].resolved = "[B]not";
  c3_info[9].fileLength = 0U;
  c3_info[9].fileTime1 = 0U;
  c3_info[9].fileTime2 = 0U;
  c3_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[10].name = "strcmp";
  c3_info[10].dominantType = "char";
  c3_info[10].resolved = "[B]strcmp";
  c3_info[10].fileLength = 0U;
  c3_info[10].fileTime1 = 0U;
  c3_info[10].fileTime2 = 0U;
  c3_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[11].name = "eq";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved = "[B]eq";
  c3_info[11].fileLength = 0U;
  c3_info[11].fileTime1 = 0U;
  c3_info[11].fileTime2 = 0U;
  c3_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[12].name = "eml_warning";
  c3_info[12].dominantType = "char";
  c3_info[12].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c3_info[12].fileLength = 262U;
  c3_info[12].fileTime1 = 1236257278U;
  c3_info[12].fileTime2 = 0U;
  c3_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[13].name = "eml_div";
  c3_info[13].dominantType = "double";
  c3_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[13].fileLength = 4269U;
  c3_info[13].fileTime1 = 1228093826U;
  c3_info[13].fileTime2 = 0U;
  c3_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[14].name = "isinteger";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved = "[B]isinteger";
  c3_info[14].fileLength = 0U;
  c3_info[14].fileTime1 = 0U;
  c3_info[14].fileTime2 = 0U;
  c3_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c3_info[15].name = "isreal";
  c3_info[15].dominantType = "double";
  c3_info[15].resolved = "[B]isreal";
  c3_info[15].fileLength = 0U;
  c3_info[15].fileTime1 = 0U;
  c3_info[15].fileTime2 = 0U;
  c3_info[16].context = "";
  c3_info[16].name = "atan2";
  c3_info[16].dominantType = "double";
  c3_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c3_info[16].fileLength = 605U;
  c3_info[16].fileTime1 = 1236257254U;
  c3_info[16].fileTime2 = 0U;
  c3_info[17].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c3_info[17].name = "eml_scalar_eg";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[17].fileLength = 3068U;
  c3_info[17].fileTime1 = 1240262010U;
  c3_info[17].fileTime2 = 0U;
  c3_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c3_info[18].name = "false";
  c3_info[18].dominantType = "";
  c3_info[18].resolved = "[B]false";
  c3_info[18].fileLength = 0U;
  c3_info[18].fileTime1 = 0U;
  c3_info[18].fileTime2 = 0U;
  c3_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[19].name = "isstruct";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved = "[B]isstruct";
  c3_info[19].fileLength = 0U;
  c3_info[19].fileTime1 = 0U;
  c3_info[19].fileTime2 = 0U;
  c3_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c3_info[20].name = "class";
  c3_info[20].dominantType = "double";
  c3_info[20].resolved = "[B]class";
  c3_info[20].fileLength = 0U;
  c3_info[20].fileTime1 = 0U;
  c3_info[20].fileTime2 = 0U;
  c3_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c3_info[21].name = "cast";
  c3_info[21].dominantType = "double";
  c3_info[21].resolved = "[B]cast";
  c3_info[21].fileLength = 0U;
  c3_info[21].fileTime1 = 0U;
  c3_info[21].fileTime2 = 0U;
  c3_info[22].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c3_info[22].name = "plus";
  c3_info[22].dominantType = "double";
  c3_info[22].resolved = "[B]plus";
  c3_info[22].fileLength = 0U;
  c3_info[22].fileTime1 = 0U;
  c3_info[22].fileTime2 = 0U;
  c3_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c3_info[23].name = "eml_scalexp_alloc";
  c3_info[23].dominantType = "double";
  c3_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[23].fileLength = 808U;
  c3_info[23].fileTime1 = 1230494700U;
  c3_info[23].fileTime2 = 0U;
  c3_info[24].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[24].name = "minus";
  c3_info[24].dominantType = "double";
  c3_info[24].resolved = "[B]minus";
  c3_info[24].fileLength = 0U;
  c3_info[24].fileTime1 = 0U;
  c3_info[24].fileTime2 = 0U;
  c3_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c3_info[25].name = "eml_scalar_atan2";
  c3_info[25].dominantType = "double";
  c3_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c3_info[25].fileLength = 964U;
  c3_info[25].fileTime1 = 1209330786U;
  c3_info[25].fileTime2 = 0U;
  c3_info[26].context = "";
  c3_info[26].name = "mtimes";
  c3_info[26].dominantType = "double";
  c3_info[26].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[26].fileLength = 3302U;
  c3_info[26].fileTime1 = 1242750894U;
  c3_info[26].fileTime2 = 0U;
  c3_info[27].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[27].name = "size";
  c3_info[27].dominantType = "double";
  c3_info[27].resolved = "[B]size";
  c3_info[27].fileLength = 0U;
  c3_info[27].fileTime1 = 0U;
  c3_info[27].fileTime2 = 0U;
  c3_info[28].context = "";
  c3_info[28].name = "sign";
  c3_info[28].dominantType = "double";
  c3_info[28].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c3_info[28].fileLength = 408U;
  c3_info[28].fileTime1 = 1203448042U;
  c3_info[28].fileTime2 = 0U;
  c3_info[29].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c3_info[29].name = "eml_scalar_sign";
  c3_info[29].dominantType = "double";
  c3_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c3_info[29].fileLength = 543U;
  c3_info[29].fileTime1 = 1203448012U;
  c3_info[29].fileTime2 = 0U;
  c3_info[30].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c3_info[30].name = "isnan";
  c3_info[30].dominantType = "double";
  c3_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c3_info[30].fileLength = 506U;
  c3_info[30].fileTime1 = 1228093810U;
  c3_info[30].fileTime2 = 0U;
  c3_info[31].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c3_info[31].name = "eml_guarded_nan";
  c3_info[31].dominantType = "char";
  c3_info[31].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c3_info[31].fileLength = 485U;
  c3_info[31].fileTime1 = 1192466780U;
  c3_info[31].fileTime2 = 0U;
  c3_info[32].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c3_info[32].name = "eml_is_float_class";
  c3_info[32].dominantType = "char";
  c3_info[32].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[32].fileLength = 226U;
  c3_info[32].fileTime1 = 1197850442U;
  c3_info[32].fileTime2 = 0U;
  c3_info[33].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[33].name = "ischar";
  c3_info[33].dominantType = "char";
  c3_info[33].resolved = "[B]ischar";
  c3_info[33].fileLength = 0U;
  c3_info[33].fileTime1 = 0U;
  c3_info[33].fileTime2 = 0U;
  c3_info[34].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c3_info[34].name = "nan";
  c3_info[34].dominantType = "char";
  c3_info[34].resolved = "[B]nan";
  c3_info[34].fileLength = 0U;
  c3_info[34].fileTime1 = 0U;
  c3_info[34].fileTime2 = 0U;
  c3_info[35].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c3_info[35].name = "ones";
  c3_info[35].dominantType = "char";
  c3_info[35].resolved = "[B]ones";
  c3_info[35].fileLength = 0U;
  c3_info[35].fileTime1 = 0U;
  c3_info[35].fileTime2 = 0U;
  c3_info[36].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c3_info[36].name = "lt";
  c3_info[36].dominantType = "double";
  c3_info[36].resolved = "[B]lt";
  c3_info[36].fileLength = 0U;
  c3_info[36].fileTime1 = 0U;
  c3_info[36].fileTime2 = 0U;
  c3_info[37].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c3_info[37].name = "uminus";
  c3_info[37].dominantType = "double";
  c3_info[37].resolved = "[B]uminus";
  c3_info[37].fileLength = 0U;
  c3_info[37].fileTime1 = 0U;
  c3_info[37].fileTime2 = 0U;
  c3_info[38].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c3_info[38].name = "zeros";
  c3_info[38].dominantType = "char";
  c3_info[38].resolved = "[B]zeros";
  c3_info[38].fileLength = 0U;
  c3_info[38].fileTime1 = 0U;
  c3_info[38].fileTime2 = 0U;
  c3_info[39].context = "";
  c3_info[39].name = "abs";
  c3_info[39].dominantType = "double";
  c3_info[39].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[39].fileLength = 566U;
  c3_info[39].fileTime1 = 1221267134U;
  c3_info[39].fileTime2 = 0U;
  c3_info[40].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[40].name = "islogical";
  c3_info[40].dominantType = "double";
  c3_info[40].resolved = "[B]islogical";
  c3_info[40].fileLength = 0U;
  c3_info[40].fileTime1 = 0U;
  c3_info[40].fileTime2 = 0U;
  c3_info[41].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[41].name = "eml_scalar_abs";
  c3_info[41].dominantType = "double";
  c3_info[41].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[41].fileLength = 461U;
  c3_info[41].fileTime1 = 1203447960U;
  c3_info[41].fileTime2 = 0U;
  c3_info[42].context = "";
  c3_info[42].name = "exp";
  c3_info[42].dominantType = "double";
  c3_info[42].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c3_info[42].fileLength = 324U;
  c3_info[42].fileTime1 = 1240261974U;
  c3_info[42].fileTime2 = 0U;
  c3_info[43].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c3_info[43].name = "eml_scalar_exp";
  c3_info[43].dominantType = "double";
  c3_info[43].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c3_info[43].fileLength = 243U;
  c3_info[43].fileTime1 = 1240261972U;
  c3_info[43].fileTime2 = 0U;
}

static const mxArray *c3_b_sf_marshall(void *c3_chartInstance, void *c3_u)
{
  const mxArray *c3_y = NULL;
  boolean_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  c3_y = NULL;
  c3_b_u = *((boolean_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c3_M43_Sim_Forcing_003h_Trajectory_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2712334798U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(427557459U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2780251812U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(872410106U);
}

mxArray *sf_c3_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(889587396U);
    pr[1] = (double)(1137110183U);
    pr[2] = (double)(2799906736U);
    pr[3] = (double)(4245697446U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

static mxArray *sf_get_sim_state_info_c3_M43_Sim_Forcing_003h_Trajectory(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[8],T\"d_psi\",},{M[8],M[0],T\"is_active_c3_M43_Sim_Forcing_003h_Trajectory\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_M43_Sim_Forcing_003h_Trajectory_get_check_sum(&mxChecksum);
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
           3,
           1,
           1,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"x_cab",0,
                              (MexFcnForType)c3_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y_cab",0,
                              (MexFcnForType)c3_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "max_OOP_psi",0,(MexFcnForType)c3_sf_marshall);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"d_psi",0,
                              (MexFcnForType)c3_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",1,-1,297);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c3_x_cab;
          real_T *c3_y_cab;
          real_T *c3_max_OOP_psi;
          real_T *c3_d_psi;
          c3_max_OOP_psi = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c3_y_cab = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c3_x_cab = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c3_d_psi = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_x_cab);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_y_cab);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_max_OOP_psi);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_d_psi);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c3_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c3_M43_Sim_Forcing_003h_Trajectory();
  initialize_c3_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_enable_c3_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  enable_c3_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_disable_c3_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  disable_c3_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_gateway_c3_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  sf_c3_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_ext_mode_exec_c3_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  ext_mode_exec_c3_M43_Sim_Forcing_003h_Trajectory();
}

static mxArray* sf_opaque_get_sim_state_c3_M43_Sim_Forcing_003h_Trajectory(void *
  chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c3_M43_Sim_Forcing_003h_Trajectory();
  return st;
}

static void sf_opaque_set_sim_state_c3_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c3_M43_Sim_Forcing_003h_Trajectory(sf_mex_dup(st));
}

static void sf_opaque_terminate_c3_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c3_M43_Sim_Forcing_003h_Trajectory();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_M43_Sim_Forcing_003h_Trajectory();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c3_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M43_Sim_Forcing_003h_Trajectory",
      "M43_Sim_Forcing_003h_Trajectory",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("M43_Sim_Forcing_003h_Trajectory",
                "M43_Sim_Forcing_003h_Trajectory",3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M43_Sim_Forcing_003h_Trajectory","M43_Sim_Forcing_003h_Trajectory",3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"M43_Sim_Forcing_003h_Trajectory",
        "M43_Sim_Forcing_003h_Trajectory",3,3);
      sf_mark_chart_reusable_outputs(S,"M43_Sim_Forcing_003h_Trajectory",
        "M43_Sim_Forcing_003h_Trajectory",3,1);
    }

    sf_set_rtw_dwork_info(S,"M43_Sim_Forcing_003h_Trajectory",
                          "M43_Sim_Forcing_003h_Trajectory",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(3562119585U));
  ssSetChecksum1(S,(4030707243U));
  ssSetChecksum2(S,(2548621951U));
  ssSetChecksum3(S,(1521792413U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M43_Sim_Forcing_003h_Trajectory",
      "M43_Sim_Forcing_003h_Trajectory",3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c3_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c3_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c3_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c3_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c3_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.mdlStart = mdlStart_c3_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c3_M43_Sim_Forcing_003h_Trajectory;
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

void c3_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_M43_Sim_Forcing_003h_Trajectory_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

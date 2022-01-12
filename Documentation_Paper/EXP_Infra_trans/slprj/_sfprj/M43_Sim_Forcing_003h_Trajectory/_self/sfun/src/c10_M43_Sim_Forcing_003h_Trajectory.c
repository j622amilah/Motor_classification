/* Include files */

#include "blascompat32.h"
#include "M43_Sim_Forcing_003h_Trajectory_sfun.h"
#include "c10_M43_Sim_Forcing_003h_Trajectory.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M43_Sim_Forcing_003h_Trajectory_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c10_IN_NO_ACTIVE_CHILD         (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc10_M43_Sim_Forcing_003h_TrajectoryInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c10_M43_Sim_Forcing_003h_Trajectory(void);
static void initialize_params_c10_M43_Sim_Forcing_003h_Trajectory(void);
static void enable_c10_M43_Sim_Forcing_003h_Trajectory(void);
static void disable_c10_M43_Sim_Forcing_003h_Trajectory(void);
static void c10_update_debugger_state_c10_M43_Sim_Forcing_003h_Trajectory(void);
static void ext_mode_exec_c10_M43_Sim_Forcing_003h_Trajectory(void);
static const mxArray *get_sim_state_c10_M43_Sim_Forcing_003h_Trajectory(void);
static void set_sim_state_c10_M43_Sim_Forcing_003h_Trajectory(const mxArray
  *c10_st);
static void finalize_c10_M43_Sim_Forcing_003h_Trajectory(void);
static void sf_c10_M43_Sim_Forcing_003h_Trajectory(void);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static void c10_eml_warning(void);
static const mxArray *c10_sf_marshall(void *c10_chartInstance, void *c10_u);
static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[22]);
static const mxArray *c10_b_sf_marshall(void *c10_chartInstance, void *c10_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c10_M43_Sim_Forcing_003h_Trajectory(void)
{
  uint8_T *c10_is_active_c10_M43_Sim_Forcing_003h_Trajectory;
  c10_is_active_c10_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c10_is_active_c10_M43_Sim_Forcing_003h_Trajectory = 0U;
}

static void initialize_params_c10_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void enable_c10_M43_Sim_Forcing_003h_Trajectory(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c10_M43_Sim_Forcing_003h_Trajectory(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c10_update_debugger_state_c10_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void ext_mode_exec_c10_M43_Sim_Forcing_003h_Trajectory(void)
{
  c10_update_debugger_state_c10_M43_Sim_Forcing_003h_Trajectory();
}

static const mxArray *get_sim_state_c10_M43_Sim_Forcing_003h_Trajectory(void)
{
  const mxArray *c10_st = NULL;
  const mxArray *c10_y = NULL;
  real_T c10_u;
  const mxArray *c10_b_y = NULL;
  uint8_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  real_T *c10_v_body;
  uint8_T *c10_is_active_c10_M43_Sim_Forcing_003h_Trajectory;
  c10_is_active_c10_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c10_v_body = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(2));
  c10_u = *c10_v_body;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_u = *c10_is_active_c10_M43_Sim_Forcing_003h_Trajectory;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y);
  return c10_st;
}

static void set_sim_state_c10_M43_Sim_Forcing_003h_Trajectory(const mxArray
  *c10_st)
{
  const mxArray *c10_u;
  const mxArray *c10_v_body;
  real_T c10_d0;
  real_T c10_y;
  const mxArray *c10_is_active_c10_M43_Sim_Forcing_003h_Trajectory;
  uint8_T c10_u0;
  uint8_T c10_b_y;
  boolean_T *c10_doneDoubleBufferReInit;
  real_T *c10_b_v_body;
  uint8_T *c10_b_is_active_c10_M43_Sim_Forcing_003h_Trajectory;
  c10_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c10_b_is_active_c10_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c10_b_v_body = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  *c10_doneDoubleBufferReInit = true;
  c10_u = sf_mex_dup(c10_st);
  c10_v_body = sf_mex_dup(sf_mex_getcell(c10_u, 0));
  sf_mex_import("v_body", sf_mex_dup(c10_v_body), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_v_body);
  *c10_b_v_body = c10_y;
  c10_is_active_c10_M43_Sim_Forcing_003h_Trajectory = sf_mex_dup(sf_mex_getcell
    (c10_u, 1));
  sf_mex_import("is_active_c10_M43_Sim_Forcing_003h_Trajectory", sf_mex_dup
                (c10_is_active_c10_M43_Sim_Forcing_003h_Trajectory), &
                c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_b_y = c10_u0;
  sf_mex_destroy(&c10_is_active_c10_M43_Sim_Forcing_003h_Trajectory);
  *c10_b_is_active_c10_M43_Sim_Forcing_003h_Trajectory = c10_b_y;
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_M43_Sim_Forcing_003h_Trajectory();
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void sf_c10_M43_Sim_Forcing_003h_Trajectory(void)
{
  int32_T c10_previousEvent;
  real_T c10_V0;
  real_T c10_trigger;
  real_T c10_time;
  real_T c10_timecst;
  real_T c10_nargout = 1.0;
  real_T c10_nargin = 4.0;
  real_T c10_v_body;
  real_T c10_a;
  real_T c10_b_a;
  real_T c10_b;
  real_T c10_A;
  real_T c10_B;
  real_T c10_x;
  real_T c10_y;
  real_T c10_b_x;
  real_T c10_b_y;
  real_T c10_c_x;
  real_T c10_c_y;
  real_T c10_d_x;
  real_T c10_b_b;
  real_T c10_e_x;
  real_T *c10_b_V0;
  real_T *c10_b_trigger;
  real_T *c10_b_time;
  real_T *c10_b_v_body;
  real_T *c10_b_timecst;
  c10_b_time = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c10_b_timecst = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c10_b_V0 = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c10_b_v_body = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c10_b_trigger = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,8);
  _SFD_DATA_RANGE_CHECK(*c10_b_V0, 0U);
  _SFD_DATA_RANGE_CHECK(*c10_b_trigger, 1U);
  _SFD_DATA_RANGE_CHECK(*c10_b_time, 2U);
  _SFD_DATA_RANGE_CHECK(*c10_b_v_body, 3U);
  _SFD_DATA_RANGE_CHECK(*c10_b_timecst, 4U);
  c10_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,8);
  c10_V0 = *c10_b_V0;
  c10_trigger = *c10_b_trigger;
  c10_time = *c10_b_time;
  c10_timecst = *c10_b_timecst;
  sf_debug_symbol_scope_push(7U, 0U);
  sf_debug_symbol_scope_add("nargout", &c10_nargout, c10_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c10_nargin, c10_sf_marshall);
  sf_debug_symbol_scope_add("v_body", &c10_v_body, c10_sf_marshall);
  sf_debug_symbol_scope_add("timecst", &c10_timecst, c10_sf_marshall);
  sf_debug_symbol_scope_add("time", &c10_time, c10_sf_marshall);
  sf_debug_symbol_scope_add("trigger", &c10_trigger, c10_sf_marshall);
  sf_debug_symbol_scope_add("V0", &c10_V0, c10_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  if (CV_EML_IF(0, 0, c10_trigger < 0.1)) {
    _SFD_EML_CALL(0,4);
    c10_a = c10_V0;
    c10_b_a = -c10_time;
    c10_b = c10_time;
    c10_A = c10_b_a * c10_b;
    c10_B = c10_timecst;
    c10_x = c10_A;
    c10_y = c10_B;
    if (c10_y == 0.0) {
      c10_eml_warning();
    }

    c10_b_x = c10_x;
    c10_b_y = c10_y;
    c10_c_x = c10_b_x;
    c10_c_y = c10_b_y;
    c10_d_x = c10_c_x / c10_c_y;
    c10_b_b = c10_d_x;
    c10_e_x = c10_b_b;
    c10_b_b = c10_e_x;
    c10_b_b = muDoubleScalarExp(c10_b_b);
    c10_v_body = c10_a * c10_b_b;
  } else {
    _SFD_EML_CALL(0,6);
    c10_v_body = c10_V0;
  }

  _SFD_EML_CALL(0,-6);
  sf_debug_symbol_scope_pop();
  *c10_b_v_body = c10_v_body;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,8);
  _sfEvent_ = c10_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
}

static void c10_eml_warning(void)
{
  int32_T c10_i0;
  static char_T c10_cv0[15] = { 'D', 'i', 'v', 'i', 'd', 'e', ' ', 'b', 'y', ' ',
    'z', 'e', 'r', 'o', '.' };

  char_T c10_u[15];
  const mxArray *c10_y = NULL;
  int32_T c10_i1;
  static char_T c10_cv1[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'v',
    'i', 'd', 'e', 'B', 'y', 'Z', 'e', 'r', 'o' };

  char_T c10_b_u[19];
  const mxArray *c10_b_y = NULL;
  for (c10_i0 = 0; c10_i0 < 15; c10_i0 = c10_i0 + 1) {
    c10_u[c10_i0] = c10_cv0[c10_i0];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 10, 0U, 1U, 0U, 2, 1, 15));
  for (c10_i1 = 0; c10_i1 < 19; c10_i1 = c10_i1 + 1) {
    c10_b_u[c10_i1] = c10_cv1[c10_i1];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_call_debug("warning", 0U, 2U, 14, c10_b_y, 14, c10_y);
}

static const mxArray *c10_sf_marshall(void *c10_chartInstance, void *c10_u)
{
  const mxArray *c10_y = NULL;
  real_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  c10_y = NULL;
  c10_b_u = *((real_T *)c10_u);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

const mxArray
  *sf_c10_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_ResolvedFunctionInfo c10_info[22];
  const mxArray *c10_m0 = NULL;
  int32_T c10_i2;
  c10_ResolvedFunctionInfo *c10_r0;
  c10_nameCaptureInfo = NULL;
  c10_info_helper(c10_info);
  sf_mex_assign(&c10_m0, sf_mex_createstruct("nameCaptureInfo", 1, 22));
  for (c10_i2 = 0; c10_i2 < 22; c10_i2 = c10_i2 + 1) {
    c10_r0 = &c10_info[c10_i2];
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->context)), "context"
                    , "nameCaptureInfo", c10_i2);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->name)), "name",
                    "nameCaptureInfo", c10_i2);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      c10_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c10_i2);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->resolved)),
                    "resolved", "nameCaptureInfo", c10_i2);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c10_i2);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c10_i2);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c10_i2);
  }

  sf_mex_assign(&c10_nameCaptureInfo, c10_m0);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[22])
{
  c10_info[0].context = "";
  c10_info[0].name = "lt";
  c10_info[0].dominantType = "double";
  c10_info[0].resolved = "[B]lt";
  c10_info[0].fileLength = 0U;
  c10_info[0].fileTime1 = 0U;
  c10_info[0].fileTime2 = 0U;
  c10_info[1].context = "";
  c10_info[1].name = "uminus";
  c10_info[1].dominantType = "double";
  c10_info[1].resolved = "[B]uminus";
  c10_info[1].fileLength = 0U;
  c10_info[1].fileTime1 = 0U;
  c10_info[1].fileTime2 = 0U;
  c10_info[2].context = "";
  c10_info[2].name = "mtimes";
  c10_info[2].dominantType = "double";
  c10_info[2].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[2].fileLength = 3302U;
  c10_info[2].fileTime1 = 1242750894U;
  c10_info[2].fileTime2 = 0U;
  c10_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[3].name = "nargin";
  c10_info[3].dominantType = "";
  c10_info[3].resolved = "[B]nargin";
  c10_info[3].fileLength = 0U;
  c10_info[3].fileTime1 = 0U;
  c10_info[3].fileTime2 = 0U;
  c10_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[4].name = "gt";
  c10_info[4].dominantType = "double";
  c10_info[4].resolved = "[B]gt";
  c10_info[4].fileLength = 0U;
  c10_info[4].fileTime1 = 0U;
  c10_info[4].fileTime2 = 0U;
  c10_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[5].name = "isa";
  c10_info[5].dominantType = "double";
  c10_info[5].resolved = "[B]isa";
  c10_info[5].fileLength = 0U;
  c10_info[5].fileTime1 = 0U;
  c10_info[5].fileTime2 = 0U;
  c10_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[6].name = "isinteger";
  c10_info[6].dominantType = "double";
  c10_info[6].resolved = "[B]isinteger";
  c10_info[6].fileLength = 0U;
  c10_info[6].fileTime1 = 0U;
  c10_info[6].fileTime2 = 0U;
  c10_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[7].name = "isscalar";
  c10_info[7].dominantType = "double";
  c10_info[7].resolved = "[B]isscalar";
  c10_info[7].fileLength = 0U;
  c10_info[7].fileTime1 = 0U;
  c10_info[7].fileTime2 = 0U;
  c10_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[8].name = "strcmp";
  c10_info[8].dominantType = "char";
  c10_info[8].resolved = "[B]strcmp";
  c10_info[8].fileLength = 0U;
  c10_info[8].fileTime1 = 0U;
  c10_info[8].fileTime2 = 0U;
  c10_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[9].name = "size";
  c10_info[9].dominantType = "double";
  c10_info[9].resolved = "[B]size";
  c10_info[9].fileLength = 0U;
  c10_info[9].fileTime1 = 0U;
  c10_info[9].fileTime2 = 0U;
  c10_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[10].name = "eq";
  c10_info[10].dominantType = "double";
  c10_info[10].resolved = "[B]eq";
  c10_info[10].fileLength = 0U;
  c10_info[10].fileTime1 = 0U;
  c10_info[10].fileTime2 = 0U;
  c10_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[11].name = "class";
  c10_info[11].dominantType = "double";
  c10_info[11].resolved = "[B]class";
  c10_info[11].fileLength = 0U;
  c10_info[11].fileTime1 = 0U;
  c10_info[11].fileTime2 = 0U;
  c10_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[12].name = "not";
  c10_info[12].dominantType = "logical";
  c10_info[12].resolved = "[B]not";
  c10_info[12].fileLength = 0U;
  c10_info[12].fileTime1 = 0U;
  c10_info[12].fileTime2 = 0U;
  c10_info[13].context = "";
  c10_info[13].name = "mrdivide";
  c10_info[13].dominantType = "double";
  c10_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[13].fileLength = 800U;
  c10_info[13].fileTime1 = 1238434292U;
  c10_info[13].fileTime2 = 0U;
  c10_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[14].name = "ge";
  c10_info[14].dominantType = "double";
  c10_info[14].resolved = "[B]ge";
  c10_info[14].fileLength = 0U;
  c10_info[14].fileTime1 = 0U;
  c10_info[14].fileTime2 = 0U;
  c10_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c10_info[15].name = "rdivide";
  c10_info[15].dominantType = "double";
  c10_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[15].fileLength = 620U;
  c10_info[15].fileTime1 = 1213926766U;
  c10_info[15].fileTime2 = 0U;
  c10_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[16].name = "isempty";
  c10_info[16].dominantType = "double";
  c10_info[16].resolved = "[B]isempty";
  c10_info[16].fileLength = 0U;
  c10_info[16].fileTime1 = 0U;
  c10_info[16].fileTime2 = 0U;
  c10_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[17].name = "eml_warning";
  c10_info[17].dominantType = "char";
  c10_info[17].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c10_info[17].fileLength = 262U;
  c10_info[17].fileTime1 = 1236257278U;
  c10_info[17].fileTime2 = 0U;
  c10_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[18].name = "eml_div";
  c10_info[18].dominantType = "double";
  c10_info[18].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c10_info[18].fileLength = 4269U;
  c10_info[18].fileTime1 = 1228093826U;
  c10_info[18].fileTime2 = 0U;
  c10_info[19].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c10_info[19].name = "isreal";
  c10_info[19].dominantType = "double";
  c10_info[19].resolved = "[B]isreal";
  c10_info[19].fileLength = 0U;
  c10_info[19].fileTime1 = 0U;
  c10_info[19].fileTime2 = 0U;
  c10_info[20].context = "";
  c10_info[20].name = "exp";
  c10_info[20].dominantType = "double";
  c10_info[20].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c10_info[20].fileLength = 324U;
  c10_info[20].fileTime1 = 1240261974U;
  c10_info[20].fileTime2 = 0U;
  c10_info[21].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c10_info[21].name = "eml_scalar_exp";
  c10_info[21].dominantType = "double";
  c10_info[21].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c10_info[21].fileLength = 243U;
  c10_info[21].fileTime1 = 1240261972U;
  c10_info[21].fileTime2 = 0U;
}

static const mxArray *c10_b_sf_marshall(void *c10_chartInstance, void *c10_u)
{
  const mxArray *c10_y = NULL;
  boolean_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  c10_y = NULL;
  c10_b_u = *((boolean_T *)c10_u);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c10_M43_Sim_Forcing_003h_Trajectory_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3613321984U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(979125046U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2564861892U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1069534985U);
}

mxArray *sf_c10_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3096655958U);
    pr[1] = (double)(3295718885U);
    pr[2] = (double)(2894856802U);
    pr[3] = (double)(4259298876U);
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

static mxArray *sf_get_sim_state_info_c10_M43_Sim_Forcing_003h_Trajectory(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[6],T\"v_body\",},{M[8],M[0],T\"is_active_c10_M43_Sim_Forcing_003h_Trajectory\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_M43_Sim_Forcing_003h_Trajectory_get_check_sum(&mxChecksum);
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
           10,
           1,
           1,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"V0",0,
                              (MexFcnForType)c10_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"trigger",
                              0,(MexFcnForType)c10_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"time",0,
                              (MexFcnForType)c10_sf_marshall);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"v_body",
                              0,(MexFcnForType)c10_sf_marshall);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"timecst",
                              0,(MexFcnForType)c10_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,127);
        _SFD_CV_INIT_EML_IF(0,0,54,68,105,124);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c10_V0;
          real_T *c10_trigger;
          real_T *c10_time;
          real_T *c10_v_body;
          real_T *c10_timecst;
          c10_time = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c10_timecst = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c10_V0 = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c10_v_body = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c10_trigger = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c10_V0);
          _SFD_SET_DATA_VALUE_PTR(1U, c10_trigger);
          _SFD_SET_DATA_VALUE_PTR(2U, c10_time);
          _SFD_SET_DATA_VALUE_PTR(3U, c10_v_body);
          _SFD_SET_DATA_VALUE_PTR(4U, c10_timecst);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c10_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c10_M43_Sim_Forcing_003h_Trajectory();
  initialize_c10_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_enable_c10_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  enable_c10_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_disable_c10_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  disable_c10_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_gateway_c10_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  sf_c10_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_ext_mode_exec_c10_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  ext_mode_exec_c10_M43_Sim_Forcing_003h_Trajectory();
}

static mxArray* sf_opaque_get_sim_state_c10_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c10_M43_Sim_Forcing_003h_Trajectory();
  return st;
}

static void sf_opaque_set_sim_state_c10_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c10_M43_Sim_Forcing_003h_Trajectory(sf_mex_dup(st));
}

static void sf_opaque_terminate_c10_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c10_M43_Sim_Forcing_003h_Trajectory();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_M43_Sim_Forcing_003h_Trajectory(SimStruct
  *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_M43_Sim_Forcing_003h_Trajectory();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c10_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M43_Sim_Forcing_003h_Trajectory",
      "M43_Sim_Forcing_003h_Trajectory",10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("M43_Sim_Forcing_003h_Trajectory",
                "M43_Sim_Forcing_003h_Trajectory",10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M43_Sim_Forcing_003h_Trajectory","M43_Sim_Forcing_003h_Trajectory",10,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"M43_Sim_Forcing_003h_Trajectory",
        "M43_Sim_Forcing_003h_Trajectory",10,4);
      sf_mark_chart_reusable_outputs(S,"M43_Sim_Forcing_003h_Trajectory",
        "M43_Sim_Forcing_003h_Trajectory",10,1);
    }

    sf_set_rtw_dwork_info(S,"M43_Sim_Forcing_003h_Trajectory",
                          "M43_Sim_Forcing_003h_Trajectory",10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(4259121242U));
  ssSetChecksum1(S,(2916961651U));
  ssSetChecksum2(S,(1281750355U));
  ssSetChecksum3(S,(1878147536U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c10_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M43_Sim_Forcing_003h_Trajectory",
      "M43_Sim_Forcing_003h_Trajectory",10);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c10_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c10_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c10_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c10_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c10_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c10_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c10_M43_Sim_Forcing_003h_Trajectory;
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

void c10_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_M43_Sim_Forcing_003h_Trajectory_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

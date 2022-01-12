/* Include files */

#include "blascompat32.h"
#include "M43_Sim_Forcing_003h_Trajectory_sfun.h"
#include "c4_M43_Sim_Forcing_003h_Trajectory.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M43_Sim_Forcing_003h_Trajectory_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c4_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc4_M43_Sim_Forcing_003h_TrajectoryInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c4_M43_Sim_Forcing_003h_Trajectory(void);
static void initialize_params_c4_M43_Sim_Forcing_003h_Trajectory(void);
static void enable_c4_M43_Sim_Forcing_003h_Trajectory(void);
static void disable_c4_M43_Sim_Forcing_003h_Trajectory(void);
static void c4_update_debugger_state_c4_M43_Sim_Forcing_003h_Trajectory(void);
static void ext_mode_exec_c4_M43_Sim_Forcing_003h_Trajectory(void);
static const mxArray *get_sim_state_c4_M43_Sim_Forcing_003h_Trajectory(void);
static void set_sim_state_c4_M43_Sim_Forcing_003h_Trajectory(const mxArray
  *c4_st);
static void finalize_c4_M43_Sim_Forcing_003h_Trajectory(void);
static void sf_c4_M43_Sim_Forcing_003h_Trajectory(void);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static void c4_eml_error(void);
static const mxArray *c4_sf_marshall(void *c4_chartInstance, void *c4_u);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[17]);
static const mxArray *c4_b_sf_marshall(void *c4_chartInstance, void *c4_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c4_M43_Sim_Forcing_003h_Trajectory(void)
{
  uint8_T *c4_is_active_c4_M43_Sim_Forcing_003h_Trajectory;
  c4_is_active_c4_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c4_is_active_c4_M43_Sim_Forcing_003h_Trajectory = 0U;
}

static void initialize_params_c4_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void enable_c4_M43_Sim_Forcing_003h_Trajectory(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c4_M43_Sim_Forcing_003h_Trajectory(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c4_update_debugger_state_c4_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void ext_mode_exec_c4_M43_Sim_Forcing_003h_Trajectory(void)
{
  c4_update_debugger_state_c4_M43_Sim_Forcing_003h_Trajectory();
}

static const mxArray *get_sim_state_c4_M43_Sim_Forcing_003h_Trajectory(void)
{
  const mxArray *c4_st = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T *c4_R;
  uint8_T *c4_is_active_c4_M43_Sim_Forcing_003h_Trajectory;
  c4_is_active_c4_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c4_R = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2));
  c4_u = *c4_R;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_u = *c4_is_active_c4_M43_Sim_Forcing_003h_Trajectory;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y);
  return c4_st;
}

static void set_sim_state_c4_M43_Sim_Forcing_003h_Trajectory(const mxArray
  *c4_st)
{
  const mxArray *c4_u;
  const mxArray *c4_R;
  real_T c4_d0;
  real_T c4_y;
  const mxArray *c4_is_active_c4_M43_Sim_Forcing_003h_Trajectory;
  uint8_T c4_u0;
  uint8_T c4_b_y;
  boolean_T *c4_doneDoubleBufferReInit;
  real_T *c4_b_R;
  uint8_T *c4_b_is_active_c4_M43_Sim_Forcing_003h_Trajectory;
  c4_b_is_active_c4_M43_Sim_Forcing_003h_Trajectory = (uint8_T *)ssGetDWork
    (chartInstance.S, 2);
  c4_b_R = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c4_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  *c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_R = sf_mex_dup(sf_mex_getcell(c4_u, 0));
  sf_mex_import("R", sf_mex_dup(c4_R), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_R);
  *c4_b_R = c4_y;
  c4_is_active_c4_M43_Sim_Forcing_003h_Trajectory = sf_mex_dup(sf_mex_getcell
    (c4_u, 1));
  sf_mex_import("is_active_c4_M43_Sim_Forcing_003h_Trajectory", sf_mex_dup
                (c4_is_active_c4_M43_Sim_Forcing_003h_Trajectory), &c4_u0, 1
                , 3, 0U, 0, 0U, 0);
  c4_b_y = c4_u0;
  sf_mex_destroy(&c4_is_active_c4_M43_Sim_Forcing_003h_Trajectory);
  *c4_b_is_active_c4_M43_Sim_Forcing_003h_Trajectory = c4_b_y;
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_M43_Sim_Forcing_003h_Trajectory();
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_M43_Sim_Forcing_003h_Trajectory(void)
{
}

static void sf_c4_M43_Sim_Forcing_003h_Trajectory(void)
{
  int32_T c4_previousEvent;
  real_T c4_x;
  real_T c4_y;
  real_T c4_nargout = 1.0;
  real_T c4_nargin = 2.0;
  real_T c4_R;
  real_T c4_a;
  real_T c4_b;
  real_T c4_b_y;
  real_T c4_b_a;
  real_T c4_b_b;
  real_T c4_c_y;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T *c4_d_x;
  real_T *c4_d_y;
  real_T *c4_b_R;
  c4_d_x = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c4_b_R = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c4_d_y = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,3);
  _SFD_DATA_RANGE_CHECK(*c4_d_x, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_d_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_b_R, 2U);
  c4_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,3);
  c4_x = *c4_d_x;
  c4_y = *c4_d_y;
  sf_debug_symbol_scope_push(5U, 0U);
  sf_debug_symbol_scope_add("nargout", &c4_nargout, c4_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c4_nargin, c4_sf_marshall);
  sf_debug_symbol_scope_add("R", &c4_R, c4_sf_marshall);
  sf_debug_symbol_scope_add("y", &c4_y, c4_sf_marshall);
  sf_debug_symbol_scope_add("x", &c4_x, c4_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,4);
  c4_a = c4_y;
  c4_b = c4_y;
  c4_b_y = c4_a * c4_b;
  c4_b_a = c4_x;
  c4_b_b = c4_x;
  c4_c_y = c4_b_a * c4_b_b;
  c4_b_x = c4_c_y + c4_b_y;
  c4_R = c4_b_x;
  if (c4_R < 0.0) {
    c4_eml_error();
  }

  c4_c_x = c4_R;
  c4_R = c4_c_x;
  c4_R = muDoubleScalarSqrt(c4_R);
  _SFD_EML_CALL(0,-4);
  sf_debug_symbol_scope_pop();
  *c4_b_R = c4_R;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
  _sfEvent_ = c4_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_, chartInstance.chartNumber,
     chartInstance.
     instanceNumber);
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static void c4_eml_error(void)
{
  int32_T c4_i0;
  static char_T c4_cv0[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c4_u[77];
  const mxArray *c4_y = NULL;
  int32_T c4_i1;
  static char_T c4_cv1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c4_b_u[31];
  const mxArray *c4_b_y = NULL;
  for (c4_i0 = 0; c4_i0 < 77; c4_i0 = c4_i0 + 1) {
    c4_u[c4_i0] = c4_cv0[c4_i0];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c4_i1 = 0; c4_i1 < 31; c4_i1 = c4_i1 + 1) {
    c4_b_u[c4_i1] = c4_cv1[c4_i1];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c4_b_y, 14, c4_y);
}

static const mxArray *c4_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

const mxArray
  *sf_c4_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_ResolvedFunctionInfo c4_info[17];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i2;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 17));
  for (c4_i2 = 0; c4_i2 < 17; c4_i2 = c4_i2 + 1) {
    c4_r0 = &c4_info[c4_i2];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context",
                    "nameCaptureInfo", c4_i2);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name",
                    "nameCaptureInfo", c4_i2);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c4_i2);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c4_i2);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c4_i2);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c4_i2);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c4_i2);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[17])
{
  c4_info[0].context = "";
  c4_info[0].name = "mtimes";
  c4_info[0].dominantType = "double";
  c4_info[0].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[0].fileLength = 3302U;
  c4_info[0].fileTime1 = 1242750894U;
  c4_info[0].fileTime2 = 0U;
  c4_info[1].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[1].name = "nargin";
  c4_info[1].dominantType = "";
  c4_info[1].resolved = "[B]nargin";
  c4_info[1].fileLength = 0U;
  c4_info[1].fileTime1 = 0U;
  c4_info[1].fileTime2 = 0U;
  c4_info[2].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[2].name = "gt";
  c4_info[2].dominantType = "double";
  c4_info[2].resolved = "[B]gt";
  c4_info[2].fileLength = 0U;
  c4_info[2].fileTime1 = 0U;
  c4_info[2].fileTime2 = 0U;
  c4_info[3].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[3].name = "isa";
  c4_info[3].dominantType = "double";
  c4_info[3].resolved = "[B]isa";
  c4_info[3].fileLength = 0U;
  c4_info[3].fileTime1 = 0U;
  c4_info[3].fileTime2 = 0U;
  c4_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[4].name = "isinteger";
  c4_info[4].dominantType = "double";
  c4_info[4].resolved = "[B]isinteger";
  c4_info[4].fileLength = 0U;
  c4_info[4].fileTime1 = 0U;
  c4_info[4].fileTime2 = 0U;
  c4_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[5].name = "isscalar";
  c4_info[5].dominantType = "double";
  c4_info[5].resolved = "[B]isscalar";
  c4_info[5].fileLength = 0U;
  c4_info[5].fileTime1 = 0U;
  c4_info[5].fileTime2 = 0U;
  c4_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[6].name = "strcmp";
  c4_info[6].dominantType = "char";
  c4_info[6].resolved = "[B]strcmp";
  c4_info[6].fileLength = 0U;
  c4_info[6].fileTime1 = 0U;
  c4_info[6].fileTime2 = 0U;
  c4_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[7].name = "size";
  c4_info[7].dominantType = "double";
  c4_info[7].resolved = "[B]size";
  c4_info[7].fileLength = 0U;
  c4_info[7].fileTime1 = 0U;
  c4_info[7].fileTime2 = 0U;
  c4_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[8].name = "eq";
  c4_info[8].dominantType = "double";
  c4_info[8].resolved = "[B]eq";
  c4_info[8].fileLength = 0U;
  c4_info[8].fileTime1 = 0U;
  c4_info[8].fileTime2 = 0U;
  c4_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[9].name = "class";
  c4_info[9].dominantType = "double";
  c4_info[9].resolved = "[B]class";
  c4_info[9].fileLength = 0U;
  c4_info[9].fileTime1 = 0U;
  c4_info[9].fileTime2 = 0U;
  c4_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[10].name = "not";
  c4_info[10].dominantType = "logical";
  c4_info[10].resolved = "[B]not";
  c4_info[10].fileLength = 0U;
  c4_info[10].fileTime1 = 0U;
  c4_info[10].fileTime2 = 0U;
  c4_info[11].context = "";
  c4_info[11].name = "plus";
  c4_info[11].dominantType = "double";
  c4_info[11].resolved = "[B]plus";
  c4_info[11].fileLength = 0U;
  c4_info[11].fileTime1 = 0U;
  c4_info[11].fileTime2 = 0U;
  c4_info[12].context = "";
  c4_info[12].name = "sqrt";
  c4_info[12].dominantType = "double";
  c4_info[12].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[12].fileLength = 572U;
  c4_info[12].fileTime1 = 1203448046U;
  c4_info[12].fileTime2 = 0U;
  c4_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[13].name = "isreal";
  c4_info[13].dominantType = "double";
  c4_info[13].resolved = "[B]isreal";
  c4_info[13].fileLength = 0U;
  c4_info[13].fileTime1 = 0U;
  c4_info[13].fileTime2 = 0U;
  c4_info[14].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[14].name = "lt";
  c4_info[14].dominantType = "double";
  c4_info[14].resolved = "[B]lt";
  c4_info[14].fileLength = 0U;
  c4_info[14].fileTime1 = 0U;
  c4_info[14].fileTime2 = 0U;
  c4_info[15].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[15].name = "eml_error";
  c4_info[15].dominantType = "char";
  c4_info[15].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c4_info[15].fileLength = 315U;
  c4_info[15].fileTime1 = 1213926746U;
  c4_info[15].fileTime2 = 0U;
  c4_info[16].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c4_info[16].name = "eml_scalar_sqrt";
  c4_info[16].dominantType = "double";
  c4_info[16].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c4_info[16].fileLength = 664U;
  c4_info[16].fileTime1 = 1209330794U;
  c4_info[16].fileTime2 = 0U;
}

static const mxArray *c4_b_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  boolean_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_b_u = *((boolean_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c4_M43_Sim_Forcing_003h_Trajectory_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3263929703U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(850417553U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4188130548U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3456764328U);
}

mxArray *sf_c4_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(106417468U);
    pr[1] = (double)(2317170777U);
    pr[2] = (double)(272080223U);
    pr[3] = (double)(1900398417U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

static mxArray *sf_get_sim_state_info_c4_M43_Sim_Forcing_003h_Trajectory(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[6],T\"R\",},{M[8],M[0],T\"is_active_c4_M43_Sim_Forcing_003h_Trajectory\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_M43_Sim_Forcing_003h_Trajectory_get_check_sum(&mxChecksum);
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
           4,
           1,
           1,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"x",0,
                              (MexFcnForType)c4_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y",0,
                              (MexFcnForType)c4_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"R",0,
                              (MexFcnForType)c4_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,47);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c4_x;
          real_T *c4_y;
          real_T *c4_R;
          c4_x = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c4_R = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c4_y = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_R);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c4_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c4_M43_Sim_Forcing_003h_Trajectory();
  initialize_c4_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_enable_c4_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  enable_c4_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_disable_c4_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  disable_c4_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_gateway_c4_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  sf_c4_M43_Sim_Forcing_003h_Trajectory();
}

static void sf_opaque_ext_mode_exec_c4_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  ext_mode_exec_c4_M43_Sim_Forcing_003h_Trajectory();
}

static mxArray* sf_opaque_get_sim_state_c4_M43_Sim_Forcing_003h_Trajectory(void *
  chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c4_M43_Sim_Forcing_003h_Trajectory();
  return st;
}

static void sf_opaque_set_sim_state_c4_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c4_M43_Sim_Forcing_003h_Trajectory(sf_mex_dup(st));
}

static void sf_opaque_terminate_c4_M43_Sim_Forcing_003h_Trajectory(void
  *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c4_M43_Sim_Forcing_003h_Trajectory();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_M43_Sim_Forcing_003h_Trajectory();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c4_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M43_Sim_Forcing_003h_Trajectory",
      "M43_Sim_Forcing_003h_Trajectory",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("M43_Sim_Forcing_003h_Trajectory",
                "M43_Sim_Forcing_003h_Trajectory",4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M43_Sim_Forcing_003h_Trajectory","M43_Sim_Forcing_003h_Trajectory",4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"M43_Sim_Forcing_003h_Trajectory",
        "M43_Sim_Forcing_003h_Trajectory",4,2);
      sf_mark_chart_reusable_outputs(S,"M43_Sim_Forcing_003h_Trajectory",
        "M43_Sim_Forcing_003h_Trajectory",4,1);
    }

    sf_set_rtw_dwork_info(S,"M43_Sim_Forcing_003h_Trajectory",
                          "M43_Sim_Forcing_003h_Trajectory",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1144602043U));
  ssSetChecksum1(S,(4266098174U));
  ssSetChecksum2(S,(3388258146U));
  ssSetChecksum3(S,(3424855800U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M43_Sim_Forcing_003h_Trajectory",
      "M43_Sim_Forcing_003h_Trajectory",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_M43_Sim_Forcing_003h_Trajectory(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c4_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c4_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c4_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c4_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c4_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.mdlStart = mdlStart_c4_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_M43_Sim_Forcing_003h_Trajectory;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c4_M43_Sim_Forcing_003h_Trajectory;
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

void c4_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_M43_Sim_Forcing_003h_Trajectory(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_M43_Sim_Forcing_003h_Trajectory_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

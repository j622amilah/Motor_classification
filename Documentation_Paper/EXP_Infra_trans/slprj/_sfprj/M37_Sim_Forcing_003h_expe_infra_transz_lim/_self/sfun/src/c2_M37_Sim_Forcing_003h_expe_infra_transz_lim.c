/* Include files */

#include "blascompat32.h"
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun.h"
#include "c2_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_M37_Sim_Forcing_003h_expe_infra_transz_limInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void initialize_params_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void enable_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void disable_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c2_update_debugger_state_c2_M37_Sim_Forcing_003h_expe_infra_tra(void);
static void ext_mode_exec_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static const mxArray
  *get_sim_state_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void set_sim_state_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c2_st);
static void finalize_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void sf_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  uint8_T *c2_is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c2_is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c2_is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim = 0U;
}

static void initialize_params_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void enable_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c2_update_debugger_state_c2_M37_Sim_Forcing_003h_expe_infra_tra(void)
{
}

static void ext_mode_exec_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  c2_update_debugger_state_c2_M37_Sim_Forcing_003h_expe_infra_tra();
}

static const mxArray
  *get_sim_state_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T *c2_ac_out;
  real_T *c2_e_y;
  uint8_T *c2_is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c2_e_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_ac_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3));
  c2_u = *c2_ac_out;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_u = *c2_e_y;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_u = *c2_is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c2_st)
{
  const mxArray *c2_u;
  const mxArray *c2_ac_out;
  real_T c2_d0;
  real_T c2_y;
  const mxArray *c2_b_ac_out;
  real_T c2_d1;
  real_T c2_b_y;
  const mxArray *c2_is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  uint8_T c2_u0;
  uint8_T c2_c_y;
  boolean_T *c2_doneDoubleBufferReInit;
  real_T *c2_c_ac_out;
  real_T *c2_d_y;
  uint8_T *c2_b_is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c2_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c2_d_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_c_ac_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_b_is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  *c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_ac_out = sf_mex_dup(sf_mex_getcell(c2_u, 0));
  sf_mex_import("ac_out", sf_mex_dup(c2_ac_out), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_ac_out);
  *c2_c_ac_out = c2_y;
  c2_b_ac_out = sf_mex_dup(sf_mex_getcell(c2_u, 1));
  sf_mex_import("y", sf_mex_dup(c2_b_ac_out), &c2_d1, 1, 0, 0U, 0, 0U, 0);
  c2_b_y = c2_d1;
  sf_mex_destroy(&c2_b_ac_out);
  *c2_d_y = c2_b_y;
  c2_is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim = sf_mex_dup
    (sf_mex_getcell(c2_u, 2));
  sf_mex_import("is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim",
                sf_mex_dup(
    c2_is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim), &c2_u0, 1, 3,
                0U, 0, 0U, 0);
  c2_c_y = c2_u0;
  sf_mex_destroy(&c2_is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim);
  *c2_b_is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim = c2_c_y;
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_M37_Sim_Forcing_003h_expe_infra_tra();
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void sf_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c2_previousEvent;
  real_T c2_connect_x;
  real32_T c2_u;
  uint8_T c2_flag_in;
  real_T c2_ac_in;
  real_T c2_nargout = 2.0;
  real_T c2_nargin = 4.0;
  real_T c2_ac_out;
  real_T c2_y;
  real_T *c2_b_connect_x;
  real32_T *c2_b_u;
  real_T *c2_b_y;
  uint8_T *c2_b_flag_in;
  real_T *c2_b_ac_in;
  real_T *c2_b_ac_out;
  c2_b_u = (real32_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c2_b_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_b_ac_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c2_b_ac_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_b_flag_in = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c2_b_connect_x = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,1);
  _SFD_DATA_RANGE_CHECK(*c2_b_connect_x, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_b_u, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_y, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_b_flag_in, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_ac_in, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_ac_out, 5U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  c2_connect_x = *c2_b_connect_x;
  c2_u = *c2_b_u;
  c2_flag_in = *c2_b_flag_in;
  c2_ac_in = *c2_b_ac_in;
  sf_debug_symbol_scope_push(8U, 0U);
  sf_debug_symbol_scope_add("nargout", &c2_nargout, c2_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c2_nargin, c2_sf_marshall);
  sf_debug_symbol_scope_add("ac_out", &c2_ac_out, c2_sf_marshall);
  sf_debug_symbol_scope_add("y", &c2_y, c2_sf_marshall);
  sf_debug_symbol_scope_add("ac_in", &c2_ac_in, c2_sf_marshall);
  sf_debug_symbol_scope_add("flag_in", &c2_flag_in, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("u", &c2_u, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("connect_x", &c2_connect_x, c2_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  c2_ac_out = c2_ac_in;
  _SFD_EML_CALL(0,5);
  if (CV_EML_IF(0, 0, (real_T)c2_u > 0.01)) {
    _SFD_EML_CALL(0,6);
    c2_ac_out = 1.0;
    _SFD_EML_CALL(0,7);
    c2_y = 1.0;
  } else {
    _SFD_EML_CALL(0,9);
    if (CV_EML_IF(0, 1, c2_ac_out == 1.0)) {
      _SFD_EML_CALL(0,10);
      c2_y = 1.0;
      _SFD_EML_CALL(0,11);
      c2_ac_out = 1.0;
    } else {
      _SFD_EML_CALL(0,13);
      c2_y = 0.0;
      _SFD_EML_CALL(0,14);
      c2_ac_out = 0.0;
    }
  }

  _SFD_EML_CALL(0,18);
  if (CV_EML_IF(0, 2, (real_T)c2_flag_in == 1.0)) {
    _SFD_EML_CALL(0,19);
    c2_ac_out = 0.0;
    _SFD_EML_CALL(0,20);
    c2_y = 0.0;
  }

  _SFD_EML_CALL(0,23);
  if (CV_EML_IF(0, 3, c2_connect_x == 0.0)) {
    _SFD_EML_CALL(0,24);
    c2_y = 0.0;
    _SFD_EML_CALL(0,25);
    c2_ac_out = 0.0;
  }

  _SFD_EML_CALL(0,-25);
  sf_debug_symbol_scope_pop();
  *c2_b_y = c2_y;
  *c2_b_ac_out = c2_ac_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real32_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real32_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 1, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((uint8_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray
  *sf_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[2];
  c2_ResolvedFunctionInfo (*c2_b_info)[2];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[2])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "gt";
  (*c2_b_info)[0].dominantType = "single";
  (*c2_b_info)[0].resolved = "[B]gt";
  (*c2_b_info)[0].fileLength = 0U;
  (*c2_b_info)[0].fileTime1 = 0U;
  (*c2_b_info)[0].fileTime2 = 0U;
  (*c2_b_info)[1].context = "";
  (*c2_b_info)[1].name = "eq";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved = "[B]eq";
  (*c2_b_info)[1].fileLength = 0U;
  (*c2_b_info)[1].fileTime1 = 0U;
  (*c2_b_info)[1].fileTime2 = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2));
  for (c2_i0 = 0; c2_i0 < 2; c2_i0 = c2_i0 + 1) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2596912412U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3121430963U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3581158458U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3899574748U);
}

mxArray
  *sf_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3905947957U);
    pr[1] = (double)(1938022314U);
    pr[2] = (double)(2292686155U);
    pr[3] = (double)(233049950U);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
  *sf_get_sim_state_info_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[9],T\"ac_out\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(&mxChecksum);
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
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "connect_x",0,(MexFcnForType)c2_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,"u",0,
                              (MexFcnForType)c2_b_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y",0,
                              (MexFcnForType)c2_sf_marshall);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"flag_in",
                              0,(MexFcnForType)c2_c_sf_marshall);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"ac_in",0,
                              (MexFcnForType)c2_sf_marshall);
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"ac_out",
                              0,(MexFcnForType)c2_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,4,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,286);
        _SFD_CV_INIT_EML_IF(0,0,75,85,109,190);
        _SFD_CV_INIT_EML_IF(0,1,114,127,151,182);
        _SFD_CV_INIT_EML_IF(0,2,192,206,-1,237);
        _SFD_CV_INIT_EML_IF(0,3,239,255,-1,281);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c2_connect_x;
          real32_T *c2_u;
          real_T *c2_y;
          uint8_T *c2_flag_in;
          real_T *c2_ac_in;
          real_T *c2_ac_out;
          c2_u = (real32_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c2_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c2_ac_in = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c2_ac_out = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c2_flag_in = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c2_connect_x = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_connect_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_u);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_y);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_flag_in);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_ac_in);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_ac_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  initialize_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_enable_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void *
  chartInstanceVar)
{
  enable_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_disable_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  disable_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_gateway_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  sf_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void
  sf_opaque_ext_mode_exec_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  ext_mode_exec_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static mxArray*
  sf_opaque_get_sim_state_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  return st;
}

static void
  sf_opaque_set_sim_state_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(sf_mex_dup(st));
}

static void sf_opaque_terminate_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",2,4);
      sf_mark_chart_reusable_outputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",2,2);
    }

    sf_set_rtw_dwork_info(S,"M37_Sim_Forcing_003h_expe_infra_transz_lim",
                          "M37_Sim_Forcing_003h_expe_infra_transz_lim",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(3726817244U));
  ssSetChecksum1(S,(1484147199U));
  ssSetChecksum2(S,(2055246952U));
  ssSetChecksum3(S,(3850539286U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim;
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

void c2_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

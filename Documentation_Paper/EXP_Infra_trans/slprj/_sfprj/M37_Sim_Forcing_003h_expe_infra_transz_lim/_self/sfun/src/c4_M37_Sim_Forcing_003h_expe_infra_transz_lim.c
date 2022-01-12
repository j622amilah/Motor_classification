/* Include files */

#include "blascompat32.h"
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun.h"
#include "c4_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c4_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc4_M37_Sim_Forcing_003h_expe_infra_transz_limInstanceStruct
  chartInstance;

/* Function Declarations */
static void initialize_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void initialize_params_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void enable_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void disable_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void c4_update_debugger_state_c4_M37_Sim_Forcing_003h_expe_infra_tra(void);
static void ext_mode_exec_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static const mxArray
  *get_sim_state_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void set_sim_state_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c4_st);
static void finalize_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void sf_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_b_sf_marshall(void *c4_chartInstance, void *c4_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  uint8_T *c4_is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c4_is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c4_is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim = 0U;
}

static void initialize_params_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void enable_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c4_update_debugger_state_c4_M37_Sim_Forcing_003h_expe_infra_tra(void)
{
}

static void ext_mode_exec_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  c4_update_debugger_state_c4_M37_Sim_Forcing_003h_expe_infra_tra();
}

static const mxArray
  *get_sim_state_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const mxArray *c4_st = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T *c4_start_next;
  uint8_T *c4_is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c4_start_next = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c4_is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2));
  c4_u = *c4_start_next;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_u = *c4_is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y);
  return c4_st;
}

static void set_sim_state_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(const
  mxArray *c4_st)
{
  const mxArray *c4_u;
  const mxArray *c4_start_next;
  real_T c4_d0;
  real_T c4_y;
  const mxArray *c4_is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  uint8_T c4_u0;
  uint8_T c4_b_y;
  boolean_T *c4_doneDoubleBufferReInit;
  real_T *c4_b_start_next;
  uint8_T *c4_b_is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  c4_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance.S, 1);
  c4_b_start_next = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c4_b_is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim = (uint8_T *)
    ssGetDWork(chartInstance.S, 2);
  *c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_start_next = sf_mex_dup(sf_mex_getcell(c4_u, 0));
  sf_mex_import("start_next", sf_mex_dup(c4_start_next), &c4_d0, 1, 0, 0U, 0, 0U,
                0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_start_next);
  *c4_b_start_next = c4_y;
  c4_is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim = sf_mex_dup
    (sf_mex_getcell(c4_u, 1));
  sf_mex_import("is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim",
                sf_mex_dup(
    c4_is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim), &c4_u0, 1, 3,
                0U, 0, 0U, 0);
  c4_b_y = c4_u0;
  sf_mex_destroy(&c4_is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim);
  *c4_b_is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim = c4_b_y;
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_M37_Sim_Forcing_003h_expe_infra_tra();
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
}

static void sf_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  int32_T c4_previousEvent;
  real_T c4_Tarest;
  real_T c4_stim_time;
  real_T c4_nargout = 1.0;
  real_T c4_nargin = 2.0;
  real_T c4_start_next;
  real_T *c4_b_Tarest;
  real_T *c4_b_stim_time;
  real_T *c4_b_start_next;
  c4_b_Tarest = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c4_b_stim_time = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c4_b_start_next = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,3);
  _SFD_DATA_RANGE_CHECK(*c4_b_Tarest, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_b_stim_time, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_b_start_next, 2U);
  c4_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,3);
  c4_Tarest = *c4_b_Tarest;
  c4_stim_time = *c4_b_stim_time;
  sf_debug_symbol_scope_push(5U, 0U);
  sf_debug_symbol_scope_add("nargout", &c4_nargout, c4_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c4_nargin, c4_sf_marshall);
  sf_debug_symbol_scope_add("start_next", &c4_start_next, c4_sf_marshall);
  sf_debug_symbol_scope_add("stim_time", &c4_stim_time, c4_sf_marshall);
  sf_debug_symbol_scope_add("Tarest", &c4_Tarest, c4_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,4);
  if (CV_EML_IF(0, 0, c4_stim_time >= c4_Tarest + 5.0)) {
    _SFD_EML_CALL(0,5);
    c4_start_next = 1.0;
  } else {
    _SFD_EML_CALL(0,7);
    c4_start_next = 0.0;
  }

  _SFD_EML_CALL(0,-7);
  sf_debug_symbol_scope_pop();
  *c4_b_start_next = c4_start_next;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
  _sfEvent_ = c4_previousEvent;
  sf_debug_check_for_state_inconsistency
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
     chartInstance.chartNumber,
     chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
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
  *sf_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_ResolvedFunctionInfo c4_info[2];
  c4_ResolvedFunctionInfo (*c4_b_info)[2];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i0;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[2])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "plus";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved = "[B]plus";
  (*c4_b_info)[0].fileLength = 0U;
  (*c4_b_info)[0].fileTime1 = 0U;
  (*c4_b_info)[0].fileTime2 = 0U;
  (*c4_b_info)[1].context = "";
  (*c4_b_info)[1].name = "ge";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved = "[B]ge";
  (*c4_b_info)[1].fileLength = 0U;
  (*c4_b_info)[1].fileTime1 = 0U;
  (*c4_b_info)[1].fileTime2 = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2));
  for (c4_i0 = 0; c4_i0 < 2; c4_i0 = c4_i0 + 1) {
    c4_r0 = &c4_info[c4_i0];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context",
                    "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name",
                    "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c4_i0);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0);
  return c4_nameCaptureInfo;
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
void sf_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3735150746U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1423732230U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(219807721U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(829137248U);
}

mxArray
  *sf_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4003385588U);
    pr[1] = (double)(4160907605U);
    pr[2] = (double)(1293948828U);
    pr[3] = (double)(9542464U);
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

static mxArray
  *sf_get_sim_state_info_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"start_next\",},{M[8],M[0],T\"is_active_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(&mxChecksum);
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Tarest",
                              0,(MexFcnForType)c4_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "stim_time",0,(MexFcnForType)c4_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "start_next",0,(MexFcnForType)c4_sf_marshall);
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
        _SFD_CV_INIT_EML_IF(0,0,53,76,95,122);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c4_Tarest;
          real_T *c4_stim_time;
          real_T *c4_start_next;
          c4_Tarest = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c4_stim_time = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c4_start_next = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_Tarest);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_stim_time);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_start_next);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,
         chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  initialize_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_enable_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void *
  chartInstanceVar)
{
  enable_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_disable_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  disable_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void sf_opaque_gateway_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  sf_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static void
  sf_opaque_ext_mode_exec_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  ext_mode_exec_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

static mxArray*
  sf_opaque_get_sim_state_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *)
    get_sim_state_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  return st;
}

static void
  sf_opaque_set_sim_state_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(void
  *chartInstanceVar, const mxArray *st)
{
  set_sim_state_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(sf_mex_dup(st));
}

static void sf_opaque_terminate_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr[] = {
    "100 S1x3'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 3, 10);
}

static void mdlSetWorkWidths_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",
                "M37_Sim_Forcing_003h_expe_infra_transz_lim",4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",4,2);
      sf_mark_chart_reusable_outputs(S,
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",
        "M37_Sim_Forcing_003h_expe_infra_transz_lim",4,1);
    }

    sf_set_rtw_dwork_info(S,"M37_Sim_Forcing_003h_expe_infra_transz_lim",
                          "M37_Sim_Forcing_003h_expe_infra_transz_lim",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(3465218876U));
  ssSetChecksum1(S,(3148091957U));
  ssSetChecksum2(S,(3100303048U));
  ssSetChecksum3(S,(2850241322U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "M37_Sim_Forcing_003h_expe_infra_transz_lim",
      "M37_Sim_Forcing_003h_expe_infra_transz_lim",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW =
    mdlRTW_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlStart =
    mdlStart_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim;
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

void c4_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

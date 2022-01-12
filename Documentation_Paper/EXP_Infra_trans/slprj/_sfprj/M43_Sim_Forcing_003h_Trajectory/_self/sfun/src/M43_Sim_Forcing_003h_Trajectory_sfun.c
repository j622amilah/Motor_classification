/* Include files */

#include "M43_Sim_Forcing_003h_Trajectory_sfun.h"
#include "c1_M43_Sim_Forcing_003h_Trajectory.h"
#include "c2_M43_Sim_Forcing_003h_Trajectory.h"
#include "c3_M43_Sim_Forcing_003h_Trajectory.h"
#include "c4_M43_Sim_Forcing_003h_Trajectory.h"
#include "c5_M43_Sim_Forcing_003h_Trajectory.h"
#include "c6_M43_Sim_Forcing_003h_Trajectory.h"
#include "c7_M43_Sim_Forcing_003h_Trajectory.h"
#include "c8_M43_Sim_Forcing_003h_Trajectory.h"
#include "c10_M43_Sim_Forcing_003h_Trajectory.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
int32_T _sfEvent_;
uint32_T _M43_Sim_Forcing_003h_TrajectoryMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void M43_Sim_Forcing_003h_Trajectory_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void M43_Sim_Forcing_003h_Trajectory_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_M43_Sim_Forcing_003h_Trajectory_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_M43_Sim_Forcing_003h_Trajectory_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2711325320U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(294555530U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3712614651U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1143749082U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3878419790U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1986920763U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3071452804U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2212970178U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_M43_Sim_Forcing_003h_Trajectory_get_check_sum
            (mxArray *plhs[]);
          sf_c1_M43_Sim_Forcing_003h_Trajectory_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_M43_Sim_Forcing_003h_Trajectory_get_check_sum
            (mxArray *plhs[]);
          sf_c2_M43_Sim_Forcing_003h_Trajectory_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_M43_Sim_Forcing_003h_Trajectory_get_check_sum
            (mxArray *plhs[]);
          sf_c3_M43_Sim_Forcing_003h_Trajectory_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_M43_Sim_Forcing_003h_Trajectory_get_check_sum
            (mxArray *plhs[]);
          sf_c4_M43_Sim_Forcing_003h_Trajectory_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_M43_Sim_Forcing_003h_Trajectory_get_check_sum
            (mxArray *plhs[]);
          sf_c5_M43_Sim_Forcing_003h_Trajectory_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_M43_Sim_Forcing_003h_Trajectory_get_check_sum
            (mxArray *plhs[]);
          sf_c6_M43_Sim_Forcing_003h_Trajectory_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_M43_Sim_Forcing_003h_Trajectory_get_check_sum
            (mxArray *plhs[]);
          sf_c7_M43_Sim_Forcing_003h_Trajectory_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_M43_Sim_Forcing_003h_Trajectory_get_check_sum
            (mxArray *plhs[]);
          sf_c8_M43_Sim_Forcing_003h_Trajectory_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_M43_Sim_Forcing_003h_Trajectory_get_check_sum
            (mxArray *plhs[]);
          sf_c10_M43_Sim_Forcing_003h_Trajectory_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2364224360U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1521043920U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3255461816U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(789461005U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1484401676U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(938360352U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2784332156U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3263529255U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_M43_Sim_Forcing_003h_Trajectory_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray
          *sf_c1_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void);
        plhs[0] = sf_c1_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info
          ();
        break;
      }

     case 2:
      {
        extern mxArray
          *sf_c2_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void);
        plhs[0] = sf_c2_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info
          ();
        break;
      }

     case 3:
      {
        extern mxArray
          *sf_c3_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void);
        plhs[0] = sf_c3_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info
          ();
        break;
      }

     case 4:
      {
        extern mxArray
          *sf_c4_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void);
        plhs[0] = sf_c4_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info
          ();
        break;
      }

     case 5:
      {
        extern mxArray
          *sf_c5_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void);
        plhs[0] = sf_c5_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info
          ();
        break;
      }

     case 6:
      {
        extern mxArray
          *sf_c6_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void);
        plhs[0] = sf_c6_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info
          ();
        break;
      }

     case 7:
      {
        extern mxArray
          *sf_c7_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void);
        plhs[0] = sf_c7_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info
          ();
        break;
      }

     case 8:
      {
        extern mxArray
          *sf_c8_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void);
        plhs[0] = sf_c8_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info
          ();
        break;
      }

     case 10:
      {
        extern mxArray
          *sf_c10_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info(void);
        plhs[0] =
          sf_c10_M43_Sim_Forcing_003h_Trajectory_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info(
  int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_M43_Sim_Forcing_003h_Trajectory_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void M43_Sim_Forcing_003h_Trajectory_debug_initialize(void)
{
  _M43_Sim_Forcing_003h_TrajectoryMachineNumber_ = sf_debug_initialize_machine(
    "M43_Sim_Forcing_003h_Trajectory","sfun",0,9,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_M43_Sim_Forcing_003h_TrajectoryMachineNumber_,0);
}

void M43_Sim_Forcing_003h_Trajectory_register_exported_symbols(SimStruct* S)
{
}

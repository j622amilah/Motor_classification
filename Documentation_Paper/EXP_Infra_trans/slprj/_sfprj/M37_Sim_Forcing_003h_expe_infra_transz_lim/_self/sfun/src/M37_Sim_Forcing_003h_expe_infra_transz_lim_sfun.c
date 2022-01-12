/* Include files */

#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_sfun.h"
#include "c1_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c2_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c3_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c4_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c5_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c6_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c7_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c8_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c9_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c10_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c11_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c12_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c13_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c14_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c19_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c21_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c23_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c26_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "c27_M37_Sim_Forcing_003h_expe_infra_transz_lim.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
int32_T _sfEvent_;
uint32_T _M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void M37_Sim_Forcing_003h_expe_infra_transz_lim_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void M37_Sim_Forcing_003h_expe_infra_transz_lim_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher
  (SimStruct *simstructPtr, unsigned int chartFileNumber, int_T method, void
   *data)
{
  if (chartFileNumber==1) {
    c1_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==26) {
    c26_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==27) {
    c27_M37_Sim_Forcing_003h_expe_infra_transz_lim_method_dispatcher
      (simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int
  sf_M37_Sim_Forcing_003h_expe_infra_transz_lim_process_check_sum_call( int nlhs,
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1915854889U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2223439002U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2912142413U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4041134762U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2985996560U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3494392250U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2906774419U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4200216562U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void
            sf_c1_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c1_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void
            sf_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void
            sf_c3_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c3_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void
            sf_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void
            sf_c5_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c5_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void
            sf_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void
            sf_c7_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c7_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void
            sf_c8_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c8_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void
            sf_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void
            sf_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void
            sf_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void
            sf_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void
            sf_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void
            sf_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void
            sf_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void
            sf_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 23:
        {
          extern void
            sf_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 26:
        {
          extern void
            sf_c26_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c26_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
          break;
        }

       case 27:
        {
          extern void
            sf_c27_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum
            (mxArray *plhs[]);
          sf_c27_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3605693778U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(333626702U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(905523469U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2249964484U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_M37_Sim_Forcing_003h_expe_infra_transz_lim_autoinheritance_info(
  int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
          *sf_c1_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c1_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 2:
      {
        extern mxArray
          *sf_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 3:
      {
        extern mxArray
          *sf_c3_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c3_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 4:
      {
        extern mxArray
          *sf_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 5:
      {
        extern mxArray
          *sf_c5_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c5_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 6:
      {
        extern mxArray
          *sf_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 7:
      {
        extern mxArray
          *sf_c7_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c7_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 8:
      {
        extern mxArray
          *sf_c8_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c8_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 9:
      {
        extern mxArray
          *sf_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 10:
      {
        extern mxArray
          *sf_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 11:
      {
        extern mxArray
          *sf_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 12:
      {
        extern mxArray
          *sf_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 13:
      {
        extern mxArray
          *sf_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 14:
      {
        extern mxArray
          *sf_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 19:
      {
        extern mxArray
          *sf_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 21:
      {
        extern mxArray
          *sf_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 23:
      {
        extern mxArray
          *sf_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 26:
      {
        extern mxArray
          *sf_c26_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c26_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
        break;
      }

     case 27:
      {
        extern mxArray
          *sf_c27_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          (void);
        plhs[0] =
          sf_c27_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_autoinheritance_info
          ();
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

unsigned int
  sf_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info(
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
          *sf_c1_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray
          *sf_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 26:
      {
        extern const mxArray
          *sf_c26_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c26_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 27:
      {
        extern const mxArray
          *sf_c27_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c27_M37_Sim_Forcing_003h_expe_infra_transz_lim_get_eml_resolved_functions_info
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

void M37_Sim_Forcing_003h_expe_infra_transz_lim_debug_initialize(void)
{
  _M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_ =
    sf_debug_initialize_machine("M37_Sim_Forcing_003h_expe_infra_transz_lim",
    "sfun",0,19,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_M37_Sim_Forcing_003h_expe_infra_transz_limMachineNumber_,0);
}

void M37_Sim_Forcing_003h_expe_infra_transz_lim_register_exported_symbols
  (SimStruct* S)
{
}

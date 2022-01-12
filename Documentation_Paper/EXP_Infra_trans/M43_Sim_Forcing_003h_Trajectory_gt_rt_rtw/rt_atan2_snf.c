/*
 * rt_atan2_snf.c
 *
 * Real-Time Workshop code generation for Simulink model "M43_Sim_Forcing_003h_Trajectory.mdl".
 *
 * Model Version              : 1.1025
 * Real-Time Workshop version : 7.4  (R2009b)  29-Jun-2009
 * C source code generated on : Wed Dec 13 15:26:51 2017
 *
 * Target selection: gt_rt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 */

#include "rt_atan2_snf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include <math.h>

/* Calls ATAN2, with guards against domain error and non-finites */
real_T rt_atan2_snf(real_T a, real_T b)
{
  real_T retValue;
  if (rtIsNaN(a) || rtIsNaN(b)) {
    retValue = (rtNaN);
  } else {
    if (rtIsInf(a) && rtIsInf(b)) {
      if (b > 0.0) {
        b = 1.0;
      } else {
        b = -1.0;
      }

      if (a > 0.0) {
        a = 1.0;
      } else {
        a = -1.0;
      }

      retValue = atan2(a,b);
    } else if (b == 0.0) {
      if (a > 0.0) {
        retValue = (RT_PI)/2.0;
      } else if (a < 0.0) {
        retValue = -(RT_PI)/2.0;
      } else {
        retValue = 0.0;
      }
    } else {
      retValue = atan2(a,b);
    }
  }

  return retValue;
}                                      /* end rt_atan2_snf */

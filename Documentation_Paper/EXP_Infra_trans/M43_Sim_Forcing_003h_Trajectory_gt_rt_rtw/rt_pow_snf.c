/*
 * rt_pow_snf.c
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

#include "rt_pow_snf.h"
#include "rt_nonfinite.h"
#include <math.h>

/*
 * Calls double-precision version of POW, with guard against domain error
 * and guards against non-finites
 */
real_T rt_pow_snf(const real_T xr, const real_T yr)
{
  real_T ret, axr, ayr;
  if (rtIsNaN(xr) || rtIsNaN(yr)) {
    ret = (rtNaN);
  } else {
    axr = fabs(xr);
    ayr = fabs(yr);
    if (rtIsInf(ayr)) {
      if (axr == 1.0) {
        ret = (rtNaN);
      } else if (axr > 1.0) {
        if (yr > 0.0) {
          ret = (rtInf);
        } else {
          ret = 0.0;
        }
      } else {
        if (yr > 0.0) {
          ret = 0.0;
        } else {
          ret = (rtInf);
        }
      }
    } else {
      if (ayr == 0.0) {
        ret = 1.0;
      } else if (ayr == 1.0) {
        if (yr > 0.0) {
          ret = xr;
        } else {
          ret = 1.0/xr;
        }
      } else if (yr == 2.0) {
        ret = xr*xr;
      } else if (yr == 0.5 && xr >= 0.0) {
        ret = sqrt(xr);
      } else if ((xr < 0.0) && (yr > floor(yr))) {
        ret = (rtNaN);
      } else {
        ret = pow(xr,yr);
      }
    }
  }

  return ret;
}                                      /* end rt_pow_snf */

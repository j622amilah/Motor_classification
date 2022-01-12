/*
 * M37_Sim_Forcing_003h_expe_infra_transz_lim.c
 *
 * Real-Time Workshop code generation for Simulink model "M37_Sim_Forcing_003h_expe_infra_transz_lim.mdl".
 *
 * Model Version              : 1.1356
 * Real-Time Workshop version : 7.4  (R2009b)  29-Jun-2009
 * C source code generated on : Fri Feb 02 12:13:54 2018
 *
 * Target selection: gt_rt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M37_Sim_Forcing_003h_expe_infra_transz_lim.h"
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_private.h"
#include <stdio.h>
#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_dt.h"

/* Block signals (auto storage) */
BlockIO_M37_Sim_Forcing_003h_expe_infra_transz_lim
  M37_Sim_Forcing_003h_expe_infra_transz_lim_B;

/* Block states (auto storage) */
D_Work_M37_Sim_Forcing_003h_expe_infra_transz_lim
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork;

/* Real-time model */
RT_MODEL_M37_Sim_Forcing_003h_expe_infra_transz_lim
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M_;
RT_MODEL_M37_Sim_Forcing_003h_expe_infra_transz_lim
  *M37_Sim_Forcing_003h_expe_infra_transz_lim_M =
  &M37_Sim_Forcing_003h_expe_infra_transz_lim_M_;

/* Forward declaration for local functions */
static void M37_Sim_Forcing_003h_exp_invNxN(const real_T eml_x[36], real_T
  eml_y[36]);
static real_T M37_Sim_Forcing_003h_expe__norm(const real_T eml_x[6]);
uint8_T M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND = 0;/* uint8_T ground */
int64m_T M37_Sim_Forcing_003h_expe_infra_transz_lim_sfix64_En41_GND = { { 0UL,
    0UL } };                           /* int64m_T ground */

uint32_T MWDSP_EPH_R_U8(uint8_T evt, uint32_T *sta)
{
  uint32_T retVal;
  uint32_T curState;
  uint32_T newState;
  uint32_T newStateR;
  uint32_T lastzcevent;
  uint32_T previousState;

  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0U;
  newState = 5U;
  newStateR = 5U;
  if (evt > 0U) {
    curState = 2U;
  } else {
    curState = 1U;
  }

  if (previousState == 5U) {
    newStateR = curState;
  } else {
    if (curState != previousState) {
      if (previousState == 3U) {
        if (curState == 1U) {
          newStateR = 1U;
        } else {
          lastzcevent = 2U;
          previousState = 1U;
        }
      }

      if (previousState == 4U) {
        if (curState == 1U) {
          newStateR = 1U;
        } else {
          lastzcevent = 3U;
          previousState = 1U;
        }
      }

      if ((previousState == 1U) && (curState == 2U)) {
        retVal = 2U;
      }

      if (previousState == 0U) {
        retVal = 2U;
      }

      if (retVal == lastzcevent) {
        retVal = 0U;
      }

      if (curState == 1U) {
        if (retVal == 2U) {
          newState = 3U;
        } else if (retVal == 3U) {
          newState = 4U;
        } else {
          newState = curState;
        }
      } else {
        newState = curState;
      }
    }
  }

  if (newStateR != 5U) {
    *sta = newStateR;
    retVal = 0U;
  }

  if (newState != 5U) {
    *sta = newState;
  }

  return retVal;
}

void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;
  boolean_T isNegative1;
  boolean_T isNegative2;
  uint32_T cb1;
  uint32_T cb2;
  int32_T loop_ub;
  int32_T loop_ub_0;
  int32_T loop_ub_1;
  int32_T loop_ub_2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  loop_ub = n - 1;
  for (k = 0; k <= loop_ub; k = k + 1) {
    y[k] = 0U;
  }

  loop_ub_1 = n1 - 1;
  for (i = 0; i <= loop_ub_1; i = i + 1) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = u1i < cb1 ? 1U : 0U;
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    loop_ub_0 = nj - 1;
    for (j = 0; j <= loop_ub_0; j = j + 1) {
      yk = y[k];
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = u1i < cb2 ? 1U : 0U;
      }

      b1 = u1i >> 16U;
      u1i = u1i & 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = yk + cb;
      cb = yk < cb ? 1U : 0U;
      u1i = a0 * u1i;
      yk = yk + u1i;
      cb = (yk < u1i ? 1U : 0U) + cb;
      u1i = w10 << 16U;
      yk = yk + u1i;
      cb = (yk < u1i ? 1U : 0U) + cb;
      u1i = w01 << 16U;
      yk = yk + u1i;
      cb = (yk < u1i ? 1U : 0U) + cb;
      y[k] = yk;
      cb = (w10 >> 16U) + cb;
      cb = (w01 >> 16U) + cb;
      cb = a1 * b1 + cb;
      k = k + 1;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    loop_ub_2 = n - 1;
    for (k = 0; k <= loop_ub_2; k = k + 1) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = yk < cb ? 1U : 0U;
    }
  }
}

real_T sMultiWord2Double(const uint32_T u1[], int32_T n1)
{
  real_T y;
  int32_T i;
  int32_T exp_0;
  uint32_T u1i;
  uint32_T cb;
  int32_T loop_ub;
  int32_T loop_ub_0;
  y = 0.0;
  exp_0 = 0;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    loop_ub = n1 - 1;
    for (i = 0; i <= loop_ub; i = i + 1) {
      u1i = ~u1[i];
      cb = u1i + cb;
      y = y - ldexp((real_T)cb, exp_0);
      cb = cb < u1i ? 1U : 0U;
      exp_0 = exp_0 + 32;
    }
  } else {
    loop_ub_0 = n1 - 1;
    for (i = 0; i <= loop_ub_0; i = i + 1) {
      y = y + ldexp((real_T)u1[i], exp_0);
      exp_0 = exp_0 + 32;
    }
  }

  return y;
}

/*
 * Output and update for action system:
 *    '<S47>/If Action Subsystem1'
 *    '<S48>/If Action Subsystem1'
 *    '<S49>/If Action Subsystem1'
 *    '<S50>/If Action Subsystem1'
 *    '<S51>/If Action Subsystem1'
 *    '<S52>/If Action Subsystem1'
 */
void M37_Sim_Forc_IfActionSubsystem1(real_T rtu_Inc, real_T rtu_dif,
  rtB_IfActionSubsystem1_M37_Sim_ *localB, rtP_IfActionSubsystem1_M37_Sim_
  *localP)
{
  /* Switch: '<S54>/Switch' incorporates:
   *  Constant: '<S54>/PSEA2'
   */
  if (rtu_dif >= localP->Switch_Threshold) {
    localB->Switch = rtu_Inc;
  } else {
    localB->Switch = localP->PSEA2_Value;
  }
}

/*
 * Output and update for action system:
 *    '<S48>/If Action Subsystem'
 *    '<S49>/If Action Subsystem'
 *    '<S50>/If Action Subsystem'
 *    '<S51>/If Action Subsystem'
 *    '<S52>/If Action Subsystem'
 */
void M37_Sim_Forci_IfActionSubsystem(real_T rtu_Inc, real_T rtu_dif,
  rtB_IfActionSubsystem_M37_Sim_F *localB, rtP_IfActionSubsystem_M37_Sim_F
  *localP)
{
  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S55>/PSEA2'
   */
  if (rtu_dif >= localP->Switch_Threshold) {
    localB->Switch = rtu_Inc;
  } else {
    localB->Switch = localP->PSEA2_Value;
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S94>/Embedded MATLAB Function2'
 *    '<S94>/Embedded MATLAB Function5'
 */
void M3_EmbeddedMATLABFunction2_Init(rtDW_EmbeddedMATLABFunction2_M3 *localDW)
{
  /* InitializeConditions for Embedded MATLAB: '<S94>/Embedded MATLAB Function2' */
  localDW->is_active_c6_M37_Sim_Forcing_00 = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S94>/Embedded MATLAB Function2'
 *    '<S94>/Embedded MATLAB Function5'
 */
void M37_Sim_EmbeddedMATLABFunction2(real_T rtu_x, real_T rtu_x_max, real_T
  rtu_margin_max, rtB_EmbeddedMATLABFunction2_M37 *localB)
{
  {
    real_T eml_x;

    /* Embedded MATLAB: '<S94>/Embedded MATLAB Function2' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Move_cabin/expe_phase/Embedded MATLAB Function2': '<S97>:1' */
    /* -------------------------------------------------------------------------- */
    /*  */
    /*    argin_max and margin_min are the margins in which the exponetial */
    /*    saturation takes place */
    /*  */
    /*    x_max, x_min and margin_max and margin_min allow to compute the */
    /*    factor between 0 and 1 of x_max and x_min of the linear range */
    /*  */
    /*    Please note that x_max and x_min, margin_max and margin_min, are */
    /*    all positive values; where the max is for the positive values of x and  */
    /*    the min for the negative values */
    /*  */
    /* -------------------------------------------------------------------------- */
    /*      */
    /*      if x < x_max - margin_max && x >= 0 */
    /*          y = x; */
    /*      elseif x > -x_min + margin_min && x < 0 */
    /*          y = x; */
    /*      elseif x >= x_max - margin_max */
    /*          x1 = (x - x_max + margin_max); */
    /*          y = x_max*(1 -  margin_max/x_max*exp(-abs(x1)/margin_max)); */
    /*      else */
    /*          x1 = (x + x_min - margin_min); */
    /*          y = -x_min*(1 -  margin_min/x_min*exp(-abs(x1)/margin_min)); */
    /*      end */
    if ((rtu_x < rtu_x_max - rtu_margin_max) && (rtu_x >= 0.0)) {
      /* '<S97>:1:28' */
      /* '<S97>:1:29' */
      localB->y = rtu_x;

      /* '<S97>:1:30' */
      localB->gain = 1.0;
    } else if ((rtu_x > (-rtu_x_max) + rtu_margin_max) && (rtu_x < 0.0)) {
      /* '<S97>:1:31' */
      /* '<S97>:1:32' */
      localB->y = rtu_x;

      /* '<S97>:1:33' */
      localB->gain = 1.0;
    } else if (rtu_x >= rtu_x_max - rtu_margin_max) {
      /* '<S97>:1:34' */
      /* '<S97>:1:35' */
      eml_x = (rtu_x - rtu_x_max) + rtu_margin_max;

      /* '<S97>:1:36' */
      localB->y = (1.0 - rtu_margin_max / rtu_x_max * exp((-fabs(eml_x)) /
        rtu_margin_max)) * rtu_x_max;

      /* '<S97>:1:37' */
      localB->gain = exp((-fabs(eml_x)) / rtu_margin_max);
    } else {
      /* '<S97>:1:40' */
      eml_x = (rtu_x + rtu_x_max) - rtu_margin_max;

      /* '<S97>:1:41' */
      localB->y = (1.0 - rtu_margin_max / rtu_x_max * exp((-fabs(eml_x)) /
        rtu_margin_max)) * (-rtu_x_max);

      /* '<S97>:1:42' */
      localB->gain = exp((-fabs(eml_x)) / rtu_margin_max);
    }
  }
}

/* Function for Embedded MATLAB: '<S139>/Embedded MATLAB Function' */
static void M37_Sim_Forcing_003h_exp_invNxN(const real_T eml_x[36], real_T
  eml_y[36])
{
  int8_T eml_p[6];
  real_T eml_b_x[36];
  int8_T eml_ipiv[6];
  int32_T eml_jBcol;
  int32_T eml_kAcol;
  int32_T eml_k;
  int32_T eml_i;
  int32_T eml_loop_ub;
  int32_T eml_b_k;
  int32_T eml_mmj;
  int32_T eml_jp1j;
  int32_T eml_j;
  int32_T eml_jA;
  real_T eml_smax;
  real_T eml_c_x;
  for (eml_j = 0; eml_j < 36; eml_j++) {
    eml_y[eml_j] = 0.0;
    eml_b_x[eml_j] = eml_x[eml_j];
  }

  for (eml_j = 0; eml_j < 6; eml_j++) {
    eml_ipiv[eml_j] = (int8_T)(1 + eml_j);
  }

  for (eml_j = 0; eml_j < 5; eml_j++) {
    eml_mmj = 5 - eml_j;
    eml_loop_ub = eml_j * 7 + 1;
    eml_jp1j = eml_loop_ub + 1;
    eml_b_k = eml_mmj + 1;
    eml_jBcol = 1;
    eml_k = eml_loop_ub;
    eml_c_x = eml_b_x[eml_loop_ub - 1];
    eml_smax = fabs(eml_c_x);
    for (eml_kAcol = 2; eml_kAcol <= eml_b_k; eml_kAcol++) {
      eml_k++;
      eml_c_x = eml_b_x[eml_k - 1];
      eml_c_x = fabs(eml_c_x);
      if (eml_c_x > eml_smax) {
        eml_jBcol = eml_kAcol;
        eml_smax = eml_c_x;
      }
    }

    eml_b_k = eml_jBcol - 1;
    if (eml_b_x[(eml_loop_ub + eml_b_k) - 1] != 0.0) {
      if (eml_b_k != 0) {
        eml_ipiv[eml_j] = (int8_T)((eml_j + 1) + eml_b_k);
        eml_k = 1 + eml_j;
        eml_b_k += eml_k;
        for (eml_jBcol = 0; eml_jBcol < 6; eml_jBcol++) {
          eml_c_x = eml_b_x[eml_k - 1];
          eml_b_x[eml_k - 1] = eml_b_x[eml_b_k - 1];
          eml_b_x[eml_b_k - 1] = eml_c_x;
          eml_k += 6;
          eml_b_k += 6;
        }
      }

      eml_b_k = (eml_mmj - 1) + eml_jp1j;
      for (eml_jBcol = eml_jp1j; eml_jBcol <= eml_b_k; eml_jBcol++) {
        eml_b_x[eml_jBcol - 1] /= eml_b_x[eml_loop_ub - 1];
      }
    }

    eml_i = 5 - eml_j;
    eml_jA = eml_loop_ub + 6;
    eml_b_k = eml_loop_ub + 6;
    for (eml_jBcol = 1; eml_jBcol <= eml_i; eml_jBcol++) {
      eml_c_x = eml_b_x[eml_b_k - 1];
      if (eml_c_x != 0.0) {
        eml_c_x = -eml_c_x;
        eml_k = eml_jp1j;
        eml_kAcol = eml_mmj + eml_jA;
        for (eml_loop_ub = 1 + eml_jA; eml_loop_ub <= eml_kAcol; eml_loop_ub++)
        {
          eml_b_x[eml_loop_ub - 1] += eml_b_x[eml_k - 1] * eml_c_x;
          eml_k++;
        }
      }

      eml_b_k += 6;
      eml_jA += 6;
    }
  }

  for (eml_j = 0; eml_j < 6; eml_j++) {
    eml_p[eml_j] = (int8_T)(1 + eml_j);
  }

  for (eml_b_k = 0; eml_b_k < 6; eml_b_k++) {
    eml_jBcol = (int32_T)eml_ipiv[eml_b_k];
    if (eml_jBcol > eml_b_k + 1) {
      eml_k = (int32_T)eml_p[eml_jBcol - 1];
      eml_p[eml_jBcol - 1] = eml_p[eml_b_k];
      eml_p[eml_b_k] = (int8_T)eml_k;
    }
  }

  for (eml_b_k = 0; eml_b_k < 6; eml_b_k++) {
    eml_jBcol = (int32_T)eml_p[eml_b_k];
    eml_y[eml_b_k + 6 * (eml_jBcol - 1)] = 1.0;
    for (eml_k = eml_b_k + 1; eml_k < 7; eml_k++) {
      if (eml_y[(eml_jBcol - 1) * 6 + (eml_k - 1)] != 0.0) {
        for (eml_kAcol = eml_k + 1; eml_kAcol < 7; eml_kAcol++) {
          eml_y[(eml_kAcol - 1) + 6 * (eml_jBcol - 1)] = eml_y[(eml_jBcol - 1) *
            6 + (eml_kAcol - 1)] - eml_y[(eml_jBcol - 1) * 6 + (eml_k - 1)] *
            eml_b_x[(eml_k - 1) * 6 + (eml_kAcol - 1)];
        }
      }
    }
  }

  for (eml_b_k = 0; eml_b_k < 6; eml_b_k++) {
    eml_jBcol = eml_b_k * 6;
    for (eml_k = 6; eml_k > 0; eml_k += -1) {
      eml_kAcol = (eml_k - 1) * 6;
      if (eml_y[(eml_k + eml_jBcol) - 1] != 0.0) {
        eml_y[(eml_k + eml_jBcol) - 1] /= eml_b_x[(eml_k + eml_kAcol) - 1];
        eml_loop_ub = eml_k - 1;
        for (eml_i = 1; eml_i <= eml_loop_ub; eml_i++) {
          eml_y[(eml_i + eml_jBcol) - 1] -= eml_y[(eml_k + eml_jBcol) - 1] *
            eml_b_x[(eml_i + eml_kAcol) - 1];
        }
      }
    }
  }
}

/* Function for Embedded MATLAB: '<S139>/Embedded MATLAB Function' */
static real_T M37_Sim_Forcing_003h_expe__norm(const real_T eml_x[6])
{
  real_T eml_y;
  real_T eml_scale;
  boolean_T eml_firstNonZero;
  real_T eml_xk;
  real_T eml_t;
  int32_T eml_k;
  eml_y = 0.0;
  eml_scale = 0.0;
  eml_firstNonZero = true;
  for (eml_k = 0; eml_k < 6; eml_k++) {
    if (eml_x[eml_k] != 0.0) {
      eml_xk = fabs(eml_x[eml_k]);
      if (eml_firstNonZero) {
        eml_scale = eml_xk;
        eml_y = 1.0;
        eml_firstNonZero = false;
      } else if (eml_scale < eml_xk) {
        eml_t = eml_scale / eml_xk;
        eml_y = eml_y * eml_t * eml_t + 1.0;
        eml_scale = eml_xk;
      } else {
        eml_t = eml_xk / eml_scale;
        eml_y += eml_t * eml_t;
      }
    }
  }

  return eml_scale * sqrt(eml_y);
}

/* Model output function */
void M37_Sim_Forcing_003h_expe_infra_transz_lim_output(int_T tid)
{
  /* Reset subsysRan breadcrumbs */
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork._DOFVisualCab120615_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_h.IfActionSubsystem_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_c.IfActionSubsystem_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_h.IfActionSubsystem1_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_m.IfActionSubsystem_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_n.IfActionSubsystem1_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_n.IfActionSubsystem_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_p.IfActionSubsystem1_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_p.IfActionSubsystem_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_n5.IfActionSubsystem1_SubsysRanBC);
  srClearBC(M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.MoveUP1_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork._DOFControl_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_SubsysRanBC_i);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_SubsysRanB_o);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.fullinversekin_SubsysRanBC);
  srClearBC
    (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.SimplifiedInverseKin_SubsysRanB);

  {
    int32_T i;
    int32_T eml_k;
    real_T eml_x;
    real_T eml_varargin[3];
    boolean_T eml_searchingForNonNaN;
    int32_T eml_k_0;
    boolean_T eml_guard;
    boolean_T eml_exitg;
    real_T eml_ang[6];
    real_T eml_A;
    real_T eml_A_0;
    real_T eml_A_1;
    real_T eml_A_2;
    real_T eml_CA;
    real_T eml_SA;
    real_T eml_CA_0;
    real_T eml_SA_0;
    real_T eml_CA_1;
    real_T eml_CA_2;
    real_T eml_D[16];
    real_T eml_D_0[16];
    real_T eml_D_1[16];
    real_T eml_D_2[16];
    real_T eml_D_3[16];
    real_T eml_D_4[16];
    real_T eml_varargin_0[2];
    real_T eml_varargin_1[3];
    real_T eml_x_p[3];
    real_T eml_A_3[9];
    real_T eml_x_0;
    real_T eml_ang_0[6];
    real_T eml_A_4;
    real_T eml_A_5;
    real_T eml_A_6;
    real_T eml_A_7;
    real_T eml_E[9];
    real_T eml_E_0[9];
    real_T eml_E_1[9];
    real_T eml_E_2[9];
    real_T eml_E_3[9];
    real_T eml_d_ang[6];
    int32_T i_0;
    real_T eml_x_1[36];
    real_T tmp[36];
    real_T eml_D_5[9];
    real_T eml_D_6[9];
    real_T eml_D_7[9];
    real_T eml_D_8[16];
    real_T eml_D_9[16];
    real_T eml_D_a[4];
    real_T eml_x_2[16];
    real_T eml_D_b[16];
    real_T eml_D_c[16];
    real_T eml_D_d[16];
    real_T eml_D_e[16];
    real_T eml_D_f[16];
    real_T eml_D_g[4];
    real_T eml_D_h[4];
    real_T eml_D_i[4];
    real_T eml_D_j[4];
    real_T eml_x_3[24];
    real_T eml_A_8[9];
    real_T eml_A_9[9];
    real_T eml_A_a[9];
    real_T eml_A_b[9];
    real_T eml_A_c[9];
    real_T eml_A_d[3];
    real_T eml_A_e[3];
    real_T eml_A_f[3];
    real_T eml_A_g[3];
    real_T tmp_0[18];
    real_T eml_A_h[18];
    real_T eml_x_p_0[6];
    real_T eml_eul_ang_idx;
    real_T eml_eul_ang_idx_0;
    uint32_T tmp_1;
    uint32_T tmp_2;
    int64m_T tmp_3;
    int64m_T tmp_4;
    int64m_T tmp_5;
    int64m_T tmp_6;
    int64m_T tmp_7;
    int64m_T tmp_8;
    static int16_T tmp_9[12] = { 159, -159, 129, -19, 87, -87, 349, -349, 60,
      -60, 349, -349 };

    /* Level2 S-Function Block: '<S4>/GT-RT UDP RX' (gt_rt_udp_receive) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[11];
      sfcnOutputs(rts, 0);
    }

    /* Unpack: <S4>/Unpack */
    (void) memcpy(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m,
                  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o1,
                  10);
    (void) memcpy(&M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o2,
                  &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o1[10],
                  4);
    (void) memcpy(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o3,
                  &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o1[14],
                  24);
    (void) memcpy(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o4,
                  &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o1[38],
                  24);
    (void) memcpy(&M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o5,
                  &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o1[62],
                  4);

    /* Level2 S-Function Block: '<S4>/GT-RT UDP  Read' (gt_rt_udp_controller) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[12];
      sfcnOutputs(rts, 0);
    }

    /* Level2 S-Function Block: '<S126>/GT-RT UDP RX' (gt_rt_udp_receive) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[13];
      sfcnOutputs(rts, 0);
    }

    /* Unpack: <S126>/Unpack */
    (void) memcpy(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1,
                  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o1_h,
                  12);
    (void) memcpy(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o2_c,
                  &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o1_h
                  [12],
                  8);
    (void) memcpy(&M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o3_f,
                  &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o1_h
                  [20],
                  4);
    (void) memcpy(&M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o4_c,
                  &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o1_h
                  [24],
                  4);

    /* Level2 S-Function Block: '<S126>/GT-RT UDP  Read' (gt_rt_udp_controller) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[14];
      sfcnOutputs(rts, 0);
    }

    /* Sum: '<S3>/Sum10' incorporates:
     *  Constant: '<S3>/x_e1'
     *  Constant: '<S3>/x_e2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_o =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.x_e2_Value +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.x_e1_Value;

    /* UnitDelay: '<S69>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_c =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c0;

    /* DiscreteIntegrator: '<S100>/Discrete-Time Integrator1' */
    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_c &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevRes
          <= 0)) || ((!M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_c)
                     &&
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevRes
                      == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTATE
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator1_IC;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTATE;

    /* UnitDelay: '<S70>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay1_f =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_d;

    /* DiscreteIntegrator: '<S70>/Discrete-Time Integrator2' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay1_f &&
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator2_PrevRes
         <= 0)) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator2_DSTATE
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator2_IC;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator2 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator2_DSTATE;

    /* RelationalOperator: '<S115>/Compare' incorporates:
     *  Constant: '<S115>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Compare_g =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator2 >=
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value);

    /* UnitDelay: '<S70>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_e =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_b;

    /* DiscreteIntegrator: '<S70>/Discrete-Time Integrator1' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_e &&
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_b
         <= 0)) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_f
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator1_IC_f;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_f;

    /* RelationalOperator: '<S116>/Compare' incorporates:
     *  Constant: '<S116>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Compare_n =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_a >=
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_c);

    /* RelationalOperator: '<S117>/Compare' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6_n =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator2 ==
       0.0);

    /* Logic: '<S70>/Logical Operator6' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator6 =
      ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Compare_n != 0) &&
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6_n != 0));

    /* Logic: '<S70>/Logical Operator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1 =
      ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Compare_g != 0) ||
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator6);

    /* Logic: '<S94>/Logical Operator3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator3 =
      !M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1;

    /* UnitDelay: '<S70>/Unit Delay4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay4_DSTATE;

    /* Logic: '<S69>/Logical Operator' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator_a =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1 &&
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_c);

    /* Switch: '<S70>/Switch1' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator_a) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_a;
    }

    /* Embedded MATLAB: '<S70>/Embedded MATLAB Function1' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Timeline/Embedded MATLAB Function1': '<S119>:1' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_a >=
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1 + 5.0) {
      /* '<S119>:1:4' */
      /* '<S119>:1:5' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.start_next = 1.0;
    } else {
      /* '<S119>:1:7' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.start_next = 0.0;
    }

    /* DataTypeConversion: '<S70>/Data Type Conversion4' */
    if (rtIsNaN(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.start_next) ||
        rtIsInf(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.start_next)) {
      eml_x = 0.0;
    } else {
      eml_x = fmod(floor(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.start_next),
                   256.0);
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_o = eml_x <
      0.0 ? (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

    /* S-Function (sdspcount2): '<S3>/Counter' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator4 = false;
    if (MWDSP_EPH_R_U8
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_o,
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Counter_ClkEphState))
    {
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Counter_Count < 200)
      {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Counter_Count =
          (uint8_T)(uint32_T)
          (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Counter_Count + 1);
      } else {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Counter_Count = 0U;
      }
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Counter_Count;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Counter_Count ==
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Counter_HitValue) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator4 = true;
    }

    /* Fcn: '<Root>/Fcn1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_nl =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o3[5];

    /* Sum: '<S3>/Sum20' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum20 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a + (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_nl;

    /* UnitDelay: '<S72>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE;

    /* Embedded MATLAB: '<S72>/Embedded MATLAB Function2' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/select_ang_speed/Embedded MATLAB Function2': '<S124>:1' */
    /* '<S124>:1:4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[2] = 0.0;

    /* '<S124>:1:5' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.flag_out = 0.0;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum20 > 42.0) {
      /* '<S124>:1:7' */
      /* '<S124>:1:8' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.endOffile_out = -1.0;
    } else {
      /* '<S124>:1:9' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.endOffile_out =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay;
    }

    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay < 0.0) {
      /* '<S124>:1:12' */
      /* '<S124>:1:13' */
      /* '<S124>:1:14' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.target_ang_speed[0] = 0.0;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[0] = 0.0;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.target_ang_speed[1] = 0.0;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[1] = 0.0;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.target_ang_speed[2] = 0.0;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[2] = 0.0;

      /* '<S124>:1:15' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.vis_cond = 1.0;
    } else {
      /* '<S124>:1:16' */
      i_0 = (int32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum20 - 1;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.target_ang_speed[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.SFunction_p1_b[i_0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.target_ang_speed[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.SFunction_p1_b[i_0 + 42];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.target_ang_speed[2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.SFunction_p1_b[i_0 + 84];

      /* '<S124>:1:17' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.vis_cond =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.SFunction_p1_b[(int32_T)
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum20 + 167];

      /*      if(target_ang_speed(1)~=0)  */
      /*          mask(1)=1; */
      /*      end */
      /*      if(target_ang_speed(2)~=0)  */
      /*          mask(2)=1; */
      /*      end */
      /*      if(target_ang_speed(3)~=0)  */
      /*          mask(3)=1; */
      /*          flag_out=-1; */
      /*      end */
      /* '<S124>:1:29' */
      switch ((int32_T)
              M37_Sim_Forcing_003h_expe_infra_transz_lim_P.SFunction_p1_b
              [(int32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum20 + 125])
      {
       case 1:
        /* '<S124>:1:31' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[0] = 1.0;
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[1] = 0.0;
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[2] = 0.0;

        /* '<S124>:1:32' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.flag_out = 0.0;
        break;

       case 2:
        /* '<S124>:1:34' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[0] = 0.0;
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[1] = 1.0;
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[2] = 0.0;

        /* '<S124>:1:35' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.flag_out = 0.0;
        break;

       case 3:
        /* '<S124>:1:37' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[0] = 0.0;
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[1] = 0.0;
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[2] = 1.0;

        /* '<S124>:1:38' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.flag_out = -1.0;
        break;
      }
    }

    /* %flag out is to take care that the next trial involves yaw and then a change in the starting position must be handled */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.SFunction_p1_b[(int32_T)
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum20 + 1.0) + 125] == 3.0)
    {
      /* '<S124>:1:45' */
      /* '<S124>:1:46' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.flag_out = 1.0;
    }

    /* Switch: '<S3>/Switch1' incorporates:
     *  Constant: '<S3>/Constant4'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.endOffile_out != 0.0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant4_Value_o;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f = (real_T)
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[3];
    }

    /* Logic: '<S94>/Logical Operator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator4 =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator3 &&
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f != 0.0));

    /* Logic: '<S94>/Logical Operator5' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5 =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator4 ||
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[5] != 0));

    /* UnitDelay: '<S106>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityunt
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityunt;

    /* DiscreteIntegrator: '<S106>/pi//(zeta*T_transfer)//s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityunt;
    }

    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5 &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetStat
          <= 0)) ||
        ((!M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetStat
          == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityunt;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE;

    /* Product: '<S100>/Product' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1 *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers;

    /* DiscreteIntegrator: '<S101>/Discrete-Time Integrator1' */
    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_c &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_a
          <= 0)) || ((!M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_c)
                     &&
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_a
                      == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_o
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator1_IC_h;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_o;

    /* UnitDelay: '<S109>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_n
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_g;

    /* DiscreteIntegrator: '<S109>/pi//(zeta*T_transfer)//s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_j)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_h
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_n;
    }

    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5 &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_b
          <= 0)) ||
        ((!M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_b
          == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_h
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_n;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_f =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_h;

    /* Product: '<S101>/Product' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_f;

    /* Product: '<S104>/Alpha' incorporates:
     *  Constant: '<S94>/Constant11'
     *  Constant: '<S94>/Constant2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant11_Value /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value;

    /* Product: '<S104>/Product' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_k =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n;

    /* Embedded MATLAB: '<S104>/Get R' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Move_cabin/expe_phase/Stay within ellipse 20/07/15/Get R': '<S114>:1' */
    /* '<S114>:1:4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.R =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_k *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_k;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.R = sqrt
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.R);

    /* Product: '<S104>/Divide' incorporates:
     *  Constant: '<S94>/Constant11'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.R /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant11_Value;

    /* Switch: '<S104>/Switch' incorporates:
     *  Constant: '<S104>/Constant'
     */
    if (!(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n >=
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch_Threshold)) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_lj;
    }

    /* Product: '<S104>/Divide1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n;

    /* Constant: '<S94>/Constant6' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant6_Value;

    /* Constant: '<S94>/Constant5' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant5_Value;

    /* UnitDelay: '<S94>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay1 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE;

    /* Embedded MATLAB: '<S94>/Embedded MATLAB Function1' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Move_cabin/expe_phase/Embedded MATLAB Function1': '<S96>:1' */
    /* -------------------------------------------------------------------------- */
    /*  */
    /*    argin_max and margin_min are the margins in which the exponetial */
    /*    saturation takes place */
    /*  */
    /*    x_max, x_min and margin_max and margin_min allow to compute the */
    /*    factor between 0 and 1 of x_max and x_min of the linear range */
    /*  */
    /*    Please note that x_max and x_min, margin_max and margin_min, are */
    /*    all positive values; where the max is for the positive values of x and  */
    /*    the min for the negative values */
    /*  */
    /* -------------------------------------------------------------------------- */
    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1 <
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6 -
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5) &&
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1 >= 0.0)) {
      /* '<S96>:1:17' */
      /* '<S96>:1:18' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y_h =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1;

      /* '<S96>:1:19' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gain = 1.0;
    } else if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1 >
                (-M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6) +
                M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5) &&
               (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1 < 0.0)) {
      /* '<S96>:1:20' */
      /* '<S96>:1:21' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y_h =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1;

      /* '<S96>:1:22' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gain = 1.0;
    } else if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1 >=
               M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6 -
               M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5) {
      /* '<S96>:1:23' */
      /* '<S96>:1:24' */
      eml_x = (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1 -
               M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6) +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5;

      /* '<S96>:1:25' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y_h = (1.0 -
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5 /
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6 * exp((-fabs
        (eml_x)) / M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5)) *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6;

      /* '<S96>:1:26' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gain = exp((-fabs(eml_x)) /
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5);
    } else {
      /* '<S96>:1:29' */
      eml_x = (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1 +
               M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6) -
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5;

      /* '<S96>:1:30' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y_h = (1.0 -
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5 /
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6 * exp((-fabs
        (eml_x)) / M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5)) *
        (-M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6);

      /* '<S96>:1:31' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gain = exp((-fabs(eml_x)) /
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5);
    }

    /* Product: '<S104>/Divide2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide2 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n;

    /* Constant: '<S94>/Constant7' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant7_Value;

    /* Constant: '<S94>/Constant4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant4 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant4_Value;

    /* UnitDelay: '<S94>/Unit Delay2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay2 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay2_DSTATE;

    /* Embedded MATLAB: '<S94>/Embedded MATLAB Function2' */
    M37_Sim_EmbeddedMATLABFunction2
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide2,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant4,
       &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction2_j);

    /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_c &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_n
          <= 0)) || ((!M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_c)
                     &&
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_n
                      == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_n
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator1_IC_j;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_n;

    /* UnitDelay: '<S112>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_o
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_b;

    /* DiscreteIntegrator: '<S112>/pi//(zeta*T_transfer)//s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_i)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_l
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_o;
    }

    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5 &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_i
          <= 0)) ||
        ((!M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_i
          == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_l
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_o;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_j =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_l;

    /* Product: '<S102>/Product' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_g =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_j;

    /* Constant: '<S94>/Constant8' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant8 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant8_Value;

    /* Constant: '<S94>/Constant3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant3 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value;

    /* UnitDelay: '<S94>/Unit Delay3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay3 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay3_DSTATE;

    /* Embedded MATLAB: '<S94>/Embedded MATLAB Function5' */
    M37_Sim_EmbeddedMATLABFunction2
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_g,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant8,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant3,
       &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction5);

    /* SignalConversion: '<S95>/TmpSignal ConversionAt SFunction Inport1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFuncti_ii[
      0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y_h;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFuncti_ii[
      1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction2_j.y;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFuncti_ii[
      2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction5.y;

    /* Embedded MATLAB: '<S93>/Embedded MATLAB Function3' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Move_cabin/Subsystem/Embedded MATLAB Function3': '<S95>:1' */
    /* '<S95>:1:3' */
    eml_varargin[0] = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFuncti_ii
       [0]);
    eml_varargin[1] = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFuncti_ii
       [1]);
    eml_varargin[2] = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFuncti_ii
       [2]);
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.max_tilt = eml_varargin[0];
    eml_k = 1;
    i = 1;
    eml_guard = false;
    if (rtIsNaN(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.max_tilt)) {
      eml_searchingForNonNaN = true;
      eml_k_0 = 2;
      eml_exitg = false;
      while (((uint32_T)eml_exitg == 0U) && (eml_k_0 < 4)) {
        i++;
        if (!rtIsNaN(eml_varargin[i - 1])) {
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.max_tilt = eml_varargin[i
            - 1];
          eml_k = eml_k_0;
          eml_searchingForNonNaN = false;
          eml_exitg = true;
        } else {
          eml_k_0++;
        }
      }

      if (!eml_searchingForNonNaN) {
        eml_guard = true;
      }
    } else {
      eml_guard = true;
    }

    if (eml_guard) {
      for (eml_k++; eml_k < 4; eml_k++) {
        i++;
        if (eml_varargin[i - 1] >
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.max_tilt) {
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.max_tilt = eml_varargin[i
            - 1];
        }
      }
    }

    /* RelationalOperator: '<S93>/Relational Operator' incorporates:
     *  Constant: '<S93>/gain'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator4 =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.max_tilt <=
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.gain_Value);

    /* Logic: '<S93>/Logical Operator6' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_h =
      !(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f != 0.0);

    /* Logic: '<S93>/Logical Operator5' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_h =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1 ||
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_h);

    /* Logic: '<S93>/Logical Operator4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator4 =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator4 &&
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_h);

    /* Logic: '<S93>/Logical Operator3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_h =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1 &&
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f != 0.0));

    /* Logic: '<S93>/Logical Operator2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator2 =
      !(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[5] != 0);

    /* Logic: '<S93>/Logical Operator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_h =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_h ||
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator2);

    /* UnitDelay: '<S93>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator2 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c1;

    /* Logic: '<S93>/Logical Operator7' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator7 =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator4 &&
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_h &&
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f != 0.0) &&
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator2);

    /* UnitDelay: '<S71>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay1_g =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_b;

    /* UnitDelay: '<S71>/Unit Delay2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay2_b =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay2_DSTATE_h;

    /* Embedded MATLAB: '<S71>/Embedded MATLAB Function2' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/compute_offset/Embedded MATLAB Function2': '<S120>:1' */
    /* '<S120>:1:3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.current_axis =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.SFunction_p1[(int32_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum20 + 125];
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator7 == 1) {
      /* '<S120>:1:5' */
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum20 == 42.0) {
        /* '<S120>:1:6' */
        /* '<S120>:1:7' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.xytoz =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay2_b;

        /* '<S120>:1:8' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay1_g;
      } else {
        /* '<S120>:1:12' */
        eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.SFunction_p1
          [(int32_T)(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum20 + 1.0) +
          125];
        if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.current_axis == 1.0) ||
            (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.current_axis == 2.0))
        {
          /* '<S120>:1:14' */
          if (eml_x == 3.0) {
            /* '<S120>:1:15' */
            /* '<S120>:1:16' */
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.xytoz = 1.0;

            /* '<S120>:1:17' */
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state = 1.0;
          } else {
            /* '<S120>:1:19' */
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.xytoz = 0.0;

            /* '<S120>:1:20' */
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state = 0.0;
          }
        } else if (eml_x == 3.0) {
          /* '<S120>:1:23' */
          /* '<S120>:1:24' */
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.xytoz = 1.0;

          /* '<S120>:1:25' */
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state = 1.0;
        } else {
          /* '<S120>:1:27' */
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.xytoz = 0.0;

          /* '<S120>:1:28' */
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state = 0.0;
        }
      }

      /* mod=abs(gradual_state-1); */
      /*      if(gradual_state==1) */
      /*          mod=0; */
      /*      else */
      /*          if(current_axis==3) */
      /*              mod=0; */
      /*          else */
      /*              mod=1; */
      /*          end */
      /*      end */
    } else {
      /* '<S120>:1:43' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.xytoz =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay2_b;

      /* '<S120>:1:44' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay1_g;

      /*      mod=abs(gradual_state-1); */
      /*      if(gs_in==1) */
      /*          mod=0; */
      /*      else */
      /*          mod=1; */
      /*      end */
    }

    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state == 1.0) {
      /* '<S120>:1:54' */
      /* '<S120>:1:55' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mod = 0.0;
    } else if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.current_axis == 3.0)
    {
      /* '<S120>:1:57' */
      /* '<S120>:1:58' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mod = 0.0;
    } else {
      /* '<S120>:1:60' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mod = 1.0;
    }

    /* UnitDelay: '<S122>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_m
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_m;

    /* DiscreteIntegrator: '<S122>/pi//(zeta*T_transfer)//s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_d)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_g
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_m;
    }

    if (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state > 0.0) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_f
          <= 0)) || ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state
                      <= 0.0) &&
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_f
                      == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_g
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_m;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_g;

    /* Product: '<S71>/Product' incorporates:
     *  Constant: '<S71>/target_offset3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_f[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.target_offset3_Value[0] *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_i;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_f[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.target_offset3_Value[1] *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_i;

    /* Sum: '<S3>/Sum21' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y_h +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_f[0];

    /* Gain: '<S3>/Gain3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n;

    /* Sum: '<S3>/Sum9' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum9 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_o +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a;

    /* Gain: '<S3>/Gain2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction2_j.y;

    /* Sum: '<S3>/Sum15' incorporates:
     *  Constant: '<S3>/y_e1'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum15 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.y_e1_Value;

    /* Constant: '<S3>/Target PSI' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TargetPSI =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TargetPSI_Value;

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/Nominal mid point //!\ check with selected set'
     *  Constant: '<S3>/new mid point'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.newmidpoint_Value -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Nominalmidpointcheckwithselecte;

    /* Outputs for enable SubSystem: '<S3>/Move UP1' incorporates:
     *  Constant: '<S3>/Constant3'
     *  EnablePort: '<S68>/Enable'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_o > 0.0) {
      /* MultiPortSwitch: '<S68>/Multiport Switch' incorporates:
       *  Constant: '<S3>/Constant1'
       *  Constant: '<S68>/set for optimizing pure z'
       *  Constant: '<S68>/set for optimizing x and y'
       *  Constant: '<S68>/set for optimizing z'
       */
      switch ((int32_T)
              M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant1_Value) {
       case 1:
        for (i_0 = 0; i_0 < 6; i_0++) {
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch_l[i_0] =
            M37_Sim_Forcing_003h_expe_infra_transz_lim_P.setforoptimizingz_Value[
            i_0];
        }
        break;

       case 2:
        for (i_0 = 0; i_0 < 6; i_0++) {
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch_l[i_0] =
            M37_Sim_Forcing_003h_expe_infra_transz_lim_P.setforoptimizingpurez_Value
            [i_0];
        }
        break;

       default:
        for (i_0 = 0; i_0 < 6; i_0++) {
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch_l[i_0] =
            M37_Sim_Forcing_003h_expe_infra_transz_lim_P.setforoptimizingxandy_Value
            [i_0];
        }
        break;
      }

      /* UnitDelay: '<S88>/For saving position  and velocity until after switchover' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_k
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_d;

      /* SampleTimeMath: '<S91>/TSamp' */
      /* y = u * K where K = 1 / ( w * Ts )
       */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_o3 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_k
        * M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TSamp_WtEt_i;

      /* UnitDelay: '<S91>/UD' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_f =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_p;

      /* Sum: '<S91>/Diff' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_f =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_o3 -
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_f;

      /* Product: '<S88>/Product' incorporates:
       *  Constant: '<S68>/Constant2'
       */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_f =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_g *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_f;

      /* Gain: '<S88>/(zeta*T_transfer)//pi' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_h =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetaT_transferpi_Gain_f *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_f;

      /* DiscreteIntegrator: '<S88>/pi//(zeta*T_transfer)//s' */
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_o)
      {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_f
          =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_k;
      }

      if (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[1] > 0) &&
           (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetS_ot
            <= 0)) ||
          ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[1] <= 0) &&
           (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetS_ot
            == 1))) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_f
          =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_k;
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_g =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_f;

      /* Sum: '<S88>/Sum2' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_f = (real_T)
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[1] -
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_g;

      /* DiscreteIntegrator: '<S88>/4*zeta*pi//T_transfer //s' */
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_mw)
      {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_jy
          = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_h;
      }

      if (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[1] > 0) &&
           (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetS_nn
            <= 0)) ||
          ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[1] <= 0) &&
           (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetS_nn
            == 1))) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_jy
          = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_h;
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_h =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_jy;

      /* Sum: '<S88>/Sum1' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_f =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_f -
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_h;

      /* Product: '<S88>/Divide' incorporates:
       *  Constant: '<S68>/Constant2'
       */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_f =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_f /
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_g;

      /* Gain: '<S88>/4*zeta*pi' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_la =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain_f *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_f;

      /* Product: '<S88>/Divide1' incorporates:
       *  Constant: '<S68>/Constant2'
       */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_h =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_h /
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_g;

      /* Gain: '<S88>/pi//zeta' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_b =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain_cl *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_h;

      /* Embedded MATLAB: '<S89>/Embedded MATLAB Function' */
      /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Move UP1/add x_offset/Embedded MATLAB Function': '<S92>:1' */
      /* '<S92>:1:4' */
      for (i_0 = 0; i_0 < 6; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.set_out[i_0] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch_l[i_0];
      }

      /* '<S92>:1:5' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.set_out[2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch_l[2] +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum;

      /* Embedded MATLAB: '<S68>/curve' */
      /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Move UP1/curve': '<S90>:1' */
      /* ************************************************************************** */
      /*  */
      /*  for fitting a parabolic curve through 3 points */
      /*  */
      /*    set is a 3 x 2 matrix that include: */
      /*        (x1, z1) */
      /*        (x2, z2) */
      /*        (x3, z3) */
      /*  */
      /*    z is the abcis and x the ordinate of the curve */
      /*    fraction runs from 0 to 1 */
      /*  */
      /* ************************************************************************** */
      /* '<S90>:1:17' */
      /* '<S90>:1:18' */
      /* '<S90>:1:20' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.set_out[3];
      eml_x_p[0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.set_out[0];
      eml_A_3[0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[0] *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.set_out[4];
      eml_x_p[1] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.set_out[1];
      eml_A_3[1] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[1] *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[1];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.set_out[5];
      eml_x_p[2] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.set_out[2];
      eml_A_3[2] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[2] *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[2];
      eml_A_3[3] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[0];
      eml_A_3[4] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[1];
      eml_A_3[5] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[2];
      eml_A_3[6] = 1.0;
      eml_A_3[7] = 1.0;
      eml_A_3[8] = 1.0;

      /* '<S90>:1:21' */
      eml_k = 1;
      i = 2;
      eml_k_0 = 3;
      eml_x = fabs(eml_A_3[0]);
      eml_x_0 = fabs(eml_A_3[1]);
      if (eml_x_0 > eml_x) {
        eml_x = eml_x_0;
        eml_k = 2;
        i = 1;
      }

      if (fabs(eml_A_3[2]) > eml_x) {
        eml_k = 3;
        i = 2;
        eml_k_0 = 1;
      }

      eml_A_3[i - 1] /= eml_A_3[eml_k - 1];
      eml_A_3[eml_k_0 - 1] /= eml_A_3[eml_k - 1];
      eml_A_3[i + 2] -= eml_A_3[i - 1] * eml_A_3[eml_k + 2];
      eml_A_3[eml_k_0 + 2] -= eml_A_3[eml_k_0 - 1] * eml_A_3[eml_k + 2];
      eml_A_3[i + 5] = 1.0 - eml_A_3[i - 1];
      eml_A_3[eml_k_0 + 5] -= eml_A_3[eml_k_0 - 1] * eml_A_3[eml_k + 5];
      eml_x_0 = eml_A_3[i + 2];
      eml_x = eml_A_3[eml_k_0 + 2];
      if (fabs(eml_x) > fabs(eml_x_0)) {
        i_0 = i;
        i = eml_k_0;
        eml_k_0 = i_0;
      }

      eml_A_3[eml_k_0 + 2] /= eml_A_3[i + 2];
      eml_A_3[eml_k_0 + 5] -= eml_A_3[eml_k_0 + 2] * eml_A_3[i + 5];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[0] = eml_x_p[eml_k - 1];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[1] = eml_x_p[i - 1] -
        eml_A_3[i - 1] * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[2] = (eml_x_p[eml_k_0 - 1]
        - eml_A_3[eml_k_0 - 1] * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c
        [0]) - eml_A_3[eml_k_0 + 2] *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[1];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[2] / eml_A_3[eml_k_0 + 5];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[0] - eml_A_3[eml_k + 5] *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[2];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[1] - eml_A_3[i + 5] *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[2];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[1] / eml_A_3[i + 2];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[0] - eml_A_3[eml_k + 2] *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[1];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[0] / eml_A_3[eml_k - 1];

      /* '<S90>:1:23' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z =
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[2] -
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[0]) *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_g +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[0];

      /* '<S90>:1:25' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.x = 0.0;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.x =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[0] +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.x;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.x =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[1] +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.x;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.x =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.x +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[2];

      /* '<S90>:1:27' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.psi =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_g *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TargetPSI;
      srUpdateBC
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.MoveUP1_SubsysRanBC);
    }

    /* end of Outputs for SubSystem: '<S3>/Move UP1' */

    /* Sum: '<S3>/Sum13' incorporates:
     *  Constant: '<S3>/z_e1'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.z_e1_Value;

    /* Sum: '<S3>/Sum19' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_o =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction5.y
      + M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_f[1];

    /* Gain: '<S3>/Gain1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_o;

    /* Sum: '<S3>/Sum11' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum11 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* UnitDelay: '<S75>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_a;

    /* Sum: '<S75>/Sum' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* RelationalOperator: '<S84>/Compare' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Compare =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a != 0.0);

    /* UnitDelay: '<S75>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_e;

    /* RelationalOperator: '<S85>/Compare' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6_n =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a == 0.0);

    /* Switch: '<S75>/Switch' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6_n >=
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch_Threshold_m) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n;
    }

    /* Product: '<S75>/Divide1' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Product: '<S75>/Product3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product3 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* DiscreteIntegrator: '<S75>/1//s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_IC_LOADING) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product3;
    }

    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Compare > 0) &&
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_PrevResetState <= 0))
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product3;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE;

    /* Math: '<S75>/Math Function' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MathFunction = rt_mod_snf
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n);

    /* Product: '<S75>/Divide' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MathFunction /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n;

    /* Gain: '<S75>/Gain1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_f *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Gain: '<S75>/Gain2' incorporates:
     *  Constant: '<S66>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_j *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_e;

    /* Sum: '<S75>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a;

    /* Trigonometry: '<S75>/Trigonometric Function' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = sin
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* UnitDelay: '<S86>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_d
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_c;

    /* DiscreteIntegrator: '<S86>/pi//(zeta*T_transfer)//s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_iq)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_d
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_d;
    }

    if (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] > 0) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_o
          <= 0)) || ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4]
                      <= 0) &&
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_o
                      == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_d
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_d;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_b =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_d;

    /* DataTypeConversion: '<S86>/Data Type Conversion4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_nl = (real32_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_b;

    /* DataTypeConversion: '<S75>/Data Type Conversion4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4 = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_nl;

    /* Product: '<S75>/Product1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4;

    /* Gain: '<S66>/Gain' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain_Gain *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Sum: '<S3>/Sum17' incorporates:
     *  Constant: '<S3>/Phi1'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum17 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Phi1_Value;

    /* UnitDelay: '<S73>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_e;

    /* Sum: '<S73>/Sum' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* RelationalOperator: '<S76>/Compare' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Compare_c =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a != 0.0);

    /* UnitDelay: '<S73>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_g;

    /* RelationalOperator: '<S77>/Compare' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6_n =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a == 0.0);

    /* Switch: '<S73>/Switch' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6_n >=
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch_Threshold_l) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n;
    }

    /* Product: '<S73>/Divide1' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Product: '<S73>/Product3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product3_l =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* DiscreteIntegrator: '<S73>/1//s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_IC_LOADING_d) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE_i =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product3_l;
    }

    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Compare_c > 0) &&
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_PrevResetState_k <=
         0)) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE_i =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product3_l;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE_i;

    /* Math: '<S73>/Math Function' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MathFunction_f = rt_mod_snf
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n);

    /* Product: '<S73>/Divide' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MathFunction_f /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n;

    /* Gain: '<S73>/Gain1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_m *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Gain: '<S73>/Gain2' incorporates:
     *  Constant: '<S66>/Constant1'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_i *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant1_Value_h;

    /* Sum: '<S73>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a;

    /* Trigonometry: '<S73>/Trigonometric Function' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = sin
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* UnitDelay: '<S78>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_g
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_a;

    /* DiscreteIntegrator: '<S78>/pi//(zeta*T_transfer)//s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_n)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_o
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_g;
    }

    if (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] > 0) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_k
          <= 0)) || ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4]
                      <= 0) &&
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_k
                      == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_o
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_g;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_l =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_o;

    /* DataTypeConversion: '<S78>/Data Type Conversion4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_nl = (real32_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_l;

    /* DataTypeConversion: '<S73>/Data Type Conversion4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_a = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_nl;

    /* Product: '<S73>/Product1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_a;

    /* Gain: '<S66>/Gain1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_p *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Sum: '<S3>/Sum16' incorporates:
     *  Constant: '<S3>/Theta1'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum16 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1 +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Theta1_Value;

    /* UnitDelay: '<S74>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_ae;

    /* Sum: '<S74>/Sum' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* RelationalOperator: '<S80>/Compare' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Compare_b =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a != 0.0);

    /* UnitDelay: '<S74>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_f;

    /* RelationalOperator: '<S81>/Compare' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6_n =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a == 0.0);

    /* Switch: '<S74>/Switch' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6_n >=
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch_Threshold_ex) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n;
    }

    /* Product: '<S74>/Divide1' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Product: '<S74>/Product3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product3_p =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* DiscreteIntegrator: '<S74>/1//s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_IC_LOADING_e) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE_k =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product3_p;
    }

    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Compare_b > 0) &&
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_PrevResetState_l <=
         0)) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE_k =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product3_p;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE_k;

    /* Math: '<S74>/Math Function' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MathFunction_i = rt_mod_snf
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n);

    /* Product: '<S74>/Divide' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MathFunction_i /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n;

    /* Gain: '<S74>/Gain1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_n *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Gain: '<S74>/Gain2' incorporates:
     *  Constant: '<S66>/Constant4'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_ic *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant4_Value_b;

    /* Sum: '<S74>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a;

    /* Trigonometry: '<S74>/Trigonometric Function' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = sin
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* UnitDelay: '<S82>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_p
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_h;

    /* DiscreteIntegrator: '<S82>/pi//(zeta*T_transfer)//s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_f)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_a
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_p;
    }

    if (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] > 0) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_e
          <= 0)) || ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4]
                      <= 0) &&
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_e
                      == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_a
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_p;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_e =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_a;

    /* DataTypeConversion: '<S82>/Data Type Conversion4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_nl = (real32_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_e;

    /* DataTypeConversion: '<S74>/Data Type Conversion4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_c = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_nl;

    /* Product: '<S74>/Product1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_c;

    /* Gain: '<S66>/Gain2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_m *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Sum: '<S3>/Sum3' incorporates:
     *  Constant: '<S3>/y_e2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum3 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2 +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.y_e2_Value;

    /* DiscreteTransferFcn: '<S10>/Butterworth Filter 10 Hz' */
    for (i = 0; i < 3; i++) {
      eml_k_0 = i << 2;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_tmp_b
        [i] = ((((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1[i] -
                  M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Denomin_l
                  [1] *
                  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
                  [eml_k_0]) -
                 M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
                 [eml_k_0 + 1] *
                 M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Denomin_l
                 [2]) -
                M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
                [eml_k_0 + 2] *
                M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Denomin_l
                [3]) -
               M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
               [eml_k_0 + 3] *
               M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Denomin_l
               [4]) /
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Denomin_l
        [0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ButterworthFilter10Hz_m[i] =
        (((M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Numerat_o
           [0] *
           M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_tmp_b
           [i] +
           M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Numerat_o
           [1] *
           M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
           [eml_k_0]) +
          M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
          [eml_k_0 + 1] *
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Numerat_o
          [2]) +
         M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
         [eml_k_0 + 2] *
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Numerat_o
         [3]) +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
        [eml_k_0 + 3] *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Numerat_o
        [4];
    }

    /* Gain: '<S10>/Gain2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_nl =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_mb *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ButterworthFilter10Hz_m[1];

    /* Gain: '<S10>/Gain3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SumofElements =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_gk *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ButterworthFilter10Hz_m[2];

    /* Gain: '<S10>/Gain1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_g[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_kc *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_nl;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_g[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_kc *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ButterworthFilter10Hz_m[0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_g[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_kc *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SumofElements;

    /* Sum: '<S3>/Sum18' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.psi;

    /* Level2 S-Function Block: '<S12>/GT-RT CAN RX1' (gt_rt_can_receive) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[15];
      sfcnOutputs(rts, 0);
    }

    /* Gain: '<S16>/Gain2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_g = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_mbx *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o2[1]);

    /* Gain: '<S16>/Gain3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_f = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_h *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o2[2]);

    /* Gain: '<S16>/Gain4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_k = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_f *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o2[3]);

    /* Sum: '<S16>/Add' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Add = (int32_T)((uint32_T)
      (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_g << 1) +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o2[0]) +
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_f << 9)) + ((uint32_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_k << 17U));

    /* Gain: '<S12>/Gain' */
    tmp_1 = (uint32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain_Gain_f;
    tmp_2 = (uint32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Add;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_3.chunks[0U], 2);
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_c = tmp_3;

    /* Gain: '<S17>/Gain2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_k = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_b *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o2[5]);

    /* Gain: '<S17>/Gain3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_f = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_dt *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o2[6]);

    /* Gain: '<S17>/Gain4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_g = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_pf *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o2[7]);

    /* Sum: '<S17>/Add' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Add = (int32_T)((uint32_T)
      (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_k << 1) +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o2[4]) +
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_f << 9)) + ((uint32_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_g << 17U));

    /* Gain: '<S12>/Gain2' */
    tmp_1 = (uint32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_d;
    tmp_2 = (uint32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Add;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_4.chunks[0U], 2);
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_i = tmp_4;

    /* Level2 S-Function Block: '<S12>/GT-RT CAN RX2' (gt_rt_can_receive) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[16];
      sfcnOutputs(rts, 0);
    }

    /* Gain: '<S18>/Gain2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_k = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_gz *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o2[1]);

    /* Gain: '<S18>/Gain3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_f = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_a *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o2[2]);

    /* Gain: '<S18>/Gain4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_g = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_j *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o2[3]);

    /* Sum: '<S18>/Add' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Add = (int32_T)((uint32_T)
      (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_k << 1) +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o2[0]) +
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_f << 9)) + ((uint32_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_g << 17U));

    /* Gain: '<S12>/Gain6' */
    tmp_1 = (uint32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain6_Gain;
    tmp_2 = (uint32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Add;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_5.chunks[0U], 2);
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain6 = tmp_5;

    /* Gain: '<S19>/Gain2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_k = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_mi *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o2[5]);

    /* Gain: '<S19>/Gain3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_f = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_e *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o2[6]);

    /* Gain: '<S19>/Gain4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_g = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_fg *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o2[7]);

    /* Sum: '<S19>/Add' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Add = (int32_T)((uint32_T)
      (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_k << 1) +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o2[4]) +
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_f << 9)) + ((uint32_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_g << 17U));

    /* Gain: '<S12>/Gain1' */
    tmp_1 = (uint32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_ds;
    tmp_2 = (uint32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Add;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_6.chunks[0U], 2);
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_k = tmp_6;

    /* Level2 S-Function Block: '<S12>/GT-RT CAN RX3' (gt_rt_can_receive) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[17];
      sfcnOutputs(rts, 0);
    }

    /* Gain: '<S20>/Gain2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_k = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_l *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o2[1]);

    /* Gain: '<S20>/Gain3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_f = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_iy *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o2[2]);

    /* Gain: '<S20>/Gain4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_g = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_pa *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o2[3]);

    /* Sum: '<S20>/Add' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Add = (int32_T)((uint32_T)
      (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_k << 1) +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o2[0]) +
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_f << 9)) + ((uint32_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_g << 17U));

    /* Gain: '<S12>/Gain3' */
    tmp_1 = (uint32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_gg;
    tmp_2 = (uint32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Add;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_7.chunks[0U], 2);
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_d = tmp_7;

    /* Gain: '<S21>/Gain2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_k = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_jg *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o2[5]);

    /* Gain: '<S21>/Gain3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_f = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_p *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o2[6]);

    /* Gain: '<S21>/Gain4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_g = (uint16_T)
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_n *
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o2[7]);

    /* Sum: '<S21>/Add' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Add = (int32_T)((uint32_T)
      (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_k << 1) +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o2[4]) +
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_f << 9)) + ((uint32_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_g << 17U));

    /* Gain: '<S12>/Gain4' */
    tmp_1 = (uint32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_lp;
    tmp_2 = (uint32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Add;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_8.chunks[0U], 2);
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_k = tmp_8;

    /* DataTypeConversion: '<S132>/Data Type Conversion' */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_c;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[0] =
      ldexp(sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_i;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[1] =
      ldexp(sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain6;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[2] =
      ldexp(sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_k;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[3] =
      ldexp(sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_d;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[4] =
      ldexp(sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_k;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[5] =
      ldexp(sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);

    /* Sum: '<S132>/Sum3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[0] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Gain: '<S134>/Gain' */
    eml_ang_0[0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a;
    for (i_0 = 0; i_0 < 5; i_0++) {
      eml_ang_0[i_0 + 1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[1
        + i_0];
    }

    /* Embedded MATLAB: '<S129>/Embedded MATLAB Function' */
    /* Embedded MATLAB Function 'Joint Controller (May 7, 2015)1/Forward Kinematics/Embedded MATLAB Function': '<S133>:1' */
    /* -------------------------------------------------------------------------- */
    /*  */
    /*    This function solves the FORWARD kinematics of the 6-DOF KUKA arm and */
    /*    wrist. This is the  version, */
    /*    embedded in Simulink. The input and output are vectors that include the */
    /*    list of parameters as defined herafter */
    /*  */
    /*        *** Input variables, vec(1:13) *** */
    /*  */
    /*    vec(1: 3)    POS         Room coordinates of flange, NED in cm */
    /*    vec(4: 6)    EUL_ANG     Euler angles of the flange, phi, theta, psi, in deg */
    /*    vec(1:6)     J_ANG_0     The joint angles, in deg */
    /*  */
    /*        *** Output Variables *** */
    /*  */
    /*    out(1: 3)    POS         Room coordinates of flange, NED in cm */
    /*    out(4: 6)    EUL_ANG     Euler angles of the flange, phi, theta, psi, in deg */
    /*  */
    /*    The North_East_Down convention is used and psi, theta, phi rotation */
    /*    sequence; A2, A3, A5 are up positive and A4, A6 right rotation positive */
    /*    Note that this is different from the KUKA convention */
    /*  */
    /*    Written by Arthur J. Grunwald, Nov. 23, 2014 */
    /*  */
    /* -------------------------------------------------------------------------- */
    /*  reload variables */
    /*  the algorithm works in rad, so ang is in rad */
    /* '<S133>:1:34' */
    /*  Initial guess of the joint angles, in deg */
    /* '<S133>:1:35' */
    /*  reserve place for output */
    /* '<S133>:1:38' */
    /*  define length of arms */
    /* '<S133>:1:41' */
    /*  arm length in cm */
    /* '<S133>:1:42' */
    /* '<S133>:1:43' */
    /* '<S133>:1:44' */
    /* '<S133>:1:45' */
    /* '<S133>:1:46' */
    /*  vertical offset of the center line of */
    /*  joint 4 from centerline of arm A3 */
    /* '<S133>:1:48' */
    /*  height link A2 above the ground */
    /*  4x4 Transfer matrices, include both rotation and translation */
    /* '<S133>:1:53' */
    for (i_0 = 0; i_0 < 6; i_0++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[i_0]
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain_Gain_j[i_0] *
        eml_ang_0[i_0];

      /* Sum: '<S134>/Sum' incorporates:
       *  Constant: '<S134>/Constant'
       */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_i[i_0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[i_0]
        + M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_b[i_0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[i_0] = 0.0;
      eml_ang[i_0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_i[i_0] *
        1.7453292519943295E-002;
    }

    for (i = 0; i < 6; i++) {
      for (eml_A = eml_ang[i]; eml_A > 3.1415926535897931E+000; eml_A -=
           6.2831853071795862E+000) {
      }

      while (eml_A < -3.1415926535897931E+000) {
        eml_A += 6.2831853071795862E+000;
      }

      eml_ang[i] = eml_A;
    }

    /*  ang is brought in the range +-pi */
    /* '<S133>:1:54' */
    /* '<S133>:1:55' */
    /* '<S133>:1:56' */
    /* '<S133>:1:57' */
    /* '<S133>:1:58' */
    /* '<S133>:1:59' */
    /* '<S133>:1:61' */
    eml_x = cos(eml_ang[0]);

    /* '<S133>:1:62' */
    eml_x_0 = sin(eml_ang[0]);

    /* '<S133>:1:63' */
    eml_CA = cos(eml_ang[1]);

    /* '<S133>:1:64' */
    eml_SA = sin(eml_ang[1]);

    /* '<S133>:1:65' */
    eml_CA_0 = cos(eml_ang[2]);

    /* '<S133>:1:66' */
    eml_SA_0 = sin(eml_ang[2]);

    /* '<S133>:1:67' */
    eml_CA_1 = cos(eml_ang[3]);

    /* '<S133>:1:68' */
    eml_A_2 = sin(eml_ang[3]);

    /* '<S133>:1:69' */
    eml_CA_2 = cos(eml_ang[4]);

    /* '<S133>:1:70' */
    eml_A_0 = sin(eml_ang[4]);

    /* '<S133>:1:71' */
    eml_A_1 = cos(eml_ang[5]);

    /* '<S133>:1:72' */
    eml_A = sin(eml_ang[5]);

    /* '<S133>:1:74' */
    eml_D[0] = eml_x;
    eml_D[4] = -eml_x_0;
    eml_D[8] = 0.0;
    eml_D[12] = 0.0;
    eml_D[1] = eml_x_0;
    eml_D[5] = eml_x;
    eml_D[9] = 0.0;
    eml_D[13] = 0.0;
    eml_D[2] = 0.0;
    eml_D[6] = 0.0;
    eml_D[10] = 1.0;
    eml_D[14] = 0.0;
    eml_D[3] = 0.0;
    eml_D[7] = 0.0;
    eml_D[11] = 0.0;
    eml_D[15] = 1.0;

    /* '<S133>:1:75' */
    eml_D_0[0] = eml_CA;
    eml_D_0[4] = 0.0;
    eml_D_0[8] = eml_SA;
    eml_D_0[12] = 50.0;
    eml_D_0[1] = 0.0;
    eml_D_0[5] = 1.0;
    eml_D_0[9] = 0.0;
    eml_D_0[13] = 0.0;
    eml_D_0[2] = -eml_SA;
    eml_D_0[6] = 0.0;
    eml_D_0[10] = eml_CA;
    eml_D_0[14] = 0.0;
    eml_D_0[3] = 0.0;
    eml_D_0[7] = 0.0;
    eml_D_0[11] = 0.0;
    eml_D_0[15] = 1.0;

    /* '<S133>:1:76' */
    eml_D_1[0] = eml_CA_0;
    eml_D_1[4] = 0.0;
    eml_D_1[8] = eml_SA_0;
    eml_D_1[12] = 130.0;
    eml_D_1[1] = 0.0;
    eml_D_1[5] = 1.0;
    eml_D_1[9] = 0.0;
    eml_D_1[13] = 0.0;
    eml_D_1[2] = -eml_SA_0;
    eml_D_1[6] = 0.0;
    eml_D_1[10] = eml_CA_0;
    eml_D_1[14] = 0.0;
    eml_D_1[3] = 0.0;
    eml_D_1[7] = 0.0;
    eml_D_1[11] = 0.0;
    eml_D_1[15] = 1.0;

    /* '<S133>:1:77' */
    eml_D_2[0] = 1.0;
    eml_D_2[4] = 0.0;
    eml_D_2[8] = 0.0;
    eml_D_2[12] = 66.0;
    eml_D_2[1] = 0.0;
    eml_D_2[5] = eml_CA_1;
    eml_D_2[9] = -eml_A_2;
    eml_D_2[13] = 0.0;
    eml_D_2[2] = 0.0;
    eml_D_2[6] = eml_A_2;
    eml_D_2[10] = eml_CA_1;
    eml_D_2[14] = 5.5;
    eml_D_2[3] = 0.0;
    eml_D_2[7] = 0.0;
    eml_D_2[11] = 0.0;
    eml_D_2[15] = 1.0;

    /* '<S133>:1:78' */
    eml_D_3[0] = eml_CA_2;
    eml_D_3[4] = 0.0;
    eml_D_3[8] = eml_A_0;
    eml_D_3[12] = 36.5;
    eml_D_3[1] = 0.0;
    eml_D_3[5] = 1.0;
    eml_D_3[9] = 0.0;
    eml_D_3[13] = 0.0;
    eml_D_3[2] = -eml_A_0;
    eml_D_3[6] = 0.0;
    eml_D_3[10] = eml_CA_2;
    eml_D_3[14] = 0.0;
    eml_D_3[3] = 0.0;
    eml_D_3[7] = 0.0;
    eml_D_3[11] = 0.0;
    eml_D_3[15] = 1.0;

    /* '<S133>:1:79' */
    eml_D_4[0] = 1.0;
    eml_D_4[4] = 0.0;
    eml_D_4[8] = 0.0;
    eml_D_4[12] = 29.0;
    eml_D_4[1] = 0.0;
    eml_D_4[5] = eml_A_1;
    eml_D_4[9] = -eml_A;
    eml_D_4[13] = 0.0;
    eml_D_4[2] = 0.0;
    eml_D_4[6] = eml_A;
    eml_D_4[10] = eml_A_1;
    eml_D_4[14] = 0.0;
    eml_D_4[3] = 0.0;
    eml_D_4[7] = 0.0;
    eml_D_4[11] = 0.0;
    eml_D_4[15] = 1.0;

    /*  cut out the 3x3 DCM's for each of the transfer matrices */
    /*  Note that the DCM is for rotation from b->e */
    /* '<S133>:1:83' */
    /* '<S133>:1:84' */
    /* '<S133>:1:85' */
    /* '<S133>:1:86' */
    /* '<S133>:1:87' */
    /* '<S133>:1:88' */
    /*  --- computed position from links A1-A6 --- */
    /*  x,y,z cabin reference point (cm) */
    /*  to which the translation is made */
    /* '<S133>:1:95' */
    /* '<S133>:1:96' */
    /*  position of the cabin reference point in the */
    /*  NED system (cm) */
    /*  computed Euler angles from links A1-A6 */
    /*  Euler matrices for rotation from e->b (note the transpose) */
    /* '<S133>:1:101' */
    for (i_0 = 0; i_0 < 3; i_0++) {
      for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
        eml_D_5[i_0 + 3 * eml_k_0] = 0.0;
        eml_D_5[i_0 + 3 * eml_k_0] = eml_D_5[3 * eml_k_0 + i_0] + eml_D_4[i_0 <<
          2] * eml_D_3[eml_k_0];
        eml_D_5[i_0 + 3 * eml_k_0] = eml_D_4[(i_0 << 2) + 1] * eml_D_3[eml_k_0 +
          4] + eml_D_5[3 * eml_k_0 + i_0];
        eml_D_5[i_0 + 3 * eml_k_0] = eml_D_4[(i_0 << 2) + 2] * eml_D_3[eml_k_0 +
          8] + eml_D_5[3 * eml_k_0 + i_0];
      }
    }

    for (i_0 = 0; i_0 < 3; i_0++) {
      for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
        eml_D_6[i_0 + 3 * eml_k_0] = 0.0;
        eml_D_6[i_0 + 3 * eml_k_0] = eml_D_6[3 * eml_k_0 + i_0] + eml_D_5[i_0] *
          eml_D_2[eml_k_0];
        eml_D_6[i_0 + 3 * eml_k_0] = eml_D_6[3 * eml_k_0 + i_0] + eml_D_5[i_0 +
          3] * eml_D_2[eml_k_0 + 4];
        eml_D_6[i_0 + 3 * eml_k_0] = eml_D_6[3 * eml_k_0 + i_0] + eml_D_5[i_0 +
          6] * eml_D_2[eml_k_0 + 8];
      }
    }

    for (i_0 = 0; i_0 < 3; i_0++) {
      for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
        eml_D_7[i_0 + 3 * eml_k_0] = 0.0;
        eml_D_7[i_0 + 3 * eml_k_0] = eml_D_7[3 * eml_k_0 + i_0] + eml_D_6[i_0] *
          eml_D_1[eml_k_0];
        eml_D_7[i_0 + 3 * eml_k_0] = eml_D_7[3 * eml_k_0 + i_0] + eml_D_6[i_0 +
          3] * eml_D_1[eml_k_0 + 4];
        eml_D_7[i_0 + 3 * eml_k_0] = eml_D_7[3 * eml_k_0 + i_0] + eml_D_6[i_0 +
          6] * eml_D_1[eml_k_0 + 8];
      }
    }

    for (i_0 = 0; i_0 < 3; i_0++) {
      for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
        eml_D_5[i_0 + 3 * eml_k_0] = 0.0;
        eml_D_5[i_0 + 3 * eml_k_0] = eml_D_5[3 * eml_k_0 + i_0] + eml_D_7[i_0] *
          eml_D_0[eml_k_0];
        eml_D_5[i_0 + 3 * eml_k_0] = eml_D_5[3 * eml_k_0 + i_0] + eml_D_7[i_0 +
          3] * eml_D_0[eml_k_0 + 4];
        eml_D_5[i_0 + 3 * eml_k_0] = eml_D_5[3 * eml_k_0 + i_0] + eml_D_7[i_0 +
          6] * eml_D_0[eml_k_0 + 8];
      }
    }

    for (i_0 = 0; i_0 < 3; i_0++) {
      for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
        eml_A_3[i_0 + 3 * eml_k_0] = 0.0;
        eml_A_3[i_0 + 3 * eml_k_0] = eml_A_3[3 * eml_k_0 + i_0] + eml_D_5[i_0] *
          eml_D[eml_k_0];
        eml_A_3[i_0 + 3 * eml_k_0] = eml_A_3[3 * eml_k_0 + i_0] + eml_D_5[i_0 +
          3] * eml_D[eml_k_0 + 4];
        eml_A_3[i_0 + 3 * eml_k_0] = eml_A_3[3 * eml_k_0 + i_0] + eml_D_5[i_0 +
          6] * eml_D[eml_k_0 + 8];
      }
    }

    /* '<S133>:1:102' */
    /*  DCM to Euler angles */
    /*  place into output vector */
    /* '<S133>:1:105' */
    for (i_0 = 0; i_0 < 4; i_0++) {
      for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
        eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
        eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
          eml_D_0[eml_k_0 << 2] * eml_D[i_0];
        eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 1] * eml_D[i_0
          + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
        eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 2] * eml_D[i_0
          + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
        eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 3] * eml_D[i_0
          + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
      }
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
        eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
        eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
          eml_D_1[eml_k_0 << 2] * eml_D_8[i_0];
        eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 1] *
          eml_D_8[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
        eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 2] *
          eml_D_8[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
        eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 3] *
          eml_D_8[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
      }
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
        eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
        eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
          eml_D_2[eml_k_0 << 2] * eml_D_9[i_0];
        eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 1] *
          eml_D_9[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
        eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 2] *
          eml_D_9[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
        eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 3] *
          eml_D_9[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
      }
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
        eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
        eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
          eml_D_3[eml_k_0 << 2] * eml_D_8[i_0];
        eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 1] *
          eml_D_8[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
        eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 2] *
          eml_D_8[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
        eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 3] *
          eml_D_8[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
      }
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
        eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
        eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
          eml_D_4[eml_k_0 << 2] * eml_D_9[i_0];
        eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 1] *
          eml_D_9[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
        eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 2] *
          eml_D_9[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
        eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 3] *
          eml_D_9[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
      }
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      eml_x = eml_D_8[i_0 + 12] + (eml_D_8[i_0 + 8] * 0.0 + (eml_D_8[i_0 + 4] *
        0.0 + eml_D_8[i_0] * 0.0));
      eml_D_a[i_0] = eml_x;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[0] = eml_D_a[0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[1] = eml_D_a[1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[2] = eml_D_a[2] - 210.5;

    /* '<S133>:1:106' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[3] =
      5.7295779513082323E+001 * rt_atan2_snf(eml_A_3[7], eml_A_3[8]);
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[4] =
      5.7295779513082323E+001 * (-asin(eml_A_3[6]));
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[5] =
      5.7295779513082323E+001 * rt_atan2_snf(eml_A_3[3], eml_A_3[0]);

    /* DataTypeConversion: '<S70>/Data Type Conversion1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1 = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator_a;

    /* Logic: '<S3>/Logical Operator4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator2 =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1 ||
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1 != 0.0));

    /* Logic: '<S3>/Logical Operator5' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator2 =
      !M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator2;

    /* Logic: '<S3>/Logical Operator6' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator6_n =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator2 &&
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f != 0.0));

    /* UnitDelay: '<Root>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_k[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c[0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_k[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c[1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_k[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c[2];

    /* Logic: '<Root>/Logical Operator' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator2 =
      !(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1 != 0.0);

    /* Switch: '<S6>/SwitchControl' incorporates:
     *  Constant: '<S6>/Constant'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_o >
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.SwitchControl_Threshold) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl_b =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator2;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl_b = false;
    }

    /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl_b &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_PrevRese
          <= 0)) ||
        ((!M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl_b) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_PrevRese
          == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_DSTATE
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator_IC;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_DSTATE;

    /* Sum: '<S11>/Sum' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator -
      (real_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o4_c;

    /* Product: '<S11>/Divide' incorporates:
     *  Constant: '<S11>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_k;

    /* UnitDelay: '<S70>/Unit Delay3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay3_DSTATE_a;

    /* Constant: '<S3>/Constant7' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant7_Value_d;

    /* Constant: '<S3>/Constant6' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant6_Value_m;

    /* Embedded MATLAB: '<S3>/Embedded MATLAB Function' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Embedded MATLAB Function': '<S67>:1' */
    /* '<S67>:1:3' */

    /* Gain: '<S3>/Gain' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_j[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain_Gain_k *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.target_ang_speed[0];

    /* DataTypeConversion: '<S3>/Data Type Conversion' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[0] = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_g[0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[0] = 0.0;

    /* Gain: '<S3>/Gain' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_j[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain_Gain_k *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.target_ang_speed[1];

    /* DataTypeConversion: '<S3>/Data Type Conversion' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[1] = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_g[1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[1] = 0.0;

    /* Gain: '<S3>/Gain' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_j[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain_Gain_k *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.target_ang_speed[2];

    /* DataTypeConversion: '<S3>/Data Type Conversion' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[2] = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_g[2];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[2] = 0.0;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6_d != 0.0) {
      /* '<S67>:1:4' */
      /* '<S67>:1:6' */
      if (fabs(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[0])
          < M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7_n) {
        /* '<S67>:1:7' */
        /* '<S67>:1:8' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[0] = 0.0;
      } else {
        /* '<S67>:1:10' */
        if (rtIsNaN
            (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[0]))
        {
          eml_x = (rtNaN);
        } else if
            (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[0] >
             0.0) {
          eml_x = 1.0;
        } else if
            (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[0] <
             0.0) {
          eml_x = -1.0;
        } else {
          eml_x = 0.0;
        }

        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[0] = (fabs
          (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[0]) -
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7_n) * eml_x /
          (1.0 - M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7_n);
      }

      /* '<S67>:1:6' */
      if (fabs(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[1])
          < M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7_n) {
        /* '<S67>:1:7' */
        /* '<S67>:1:8' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[1] = 0.0;
      } else {
        /* '<S67>:1:10' */
        if (rtIsNaN
            (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[1]))
        {
          eml_x = (rtNaN);
        } else if
            (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[1] >
             0.0) {
          eml_x = 1.0;
        } else if
            (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[1] <
             0.0) {
          eml_x = -1.0;
        } else {
          eml_x = 0.0;
        }

        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[1] = (fabs
          (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[1]) -
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7_n) * eml_x /
          (1.0 - M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7_n);
      }

      /* '<S67>:1:6' */
      if (fabs(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[2])
          < M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7_n) {
        /* '<S67>:1:7' */
        /* '<S67>:1:8' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[2] = 0.0;
      } else {
        /* '<S67>:1:10' */
        if (rtIsNaN
            (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[2]))
        {
          eml_x = (rtNaN);
        } else if
            (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[2] >
             0.0) {
          eml_x = 1.0;
        } else if
            (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[2] <
             0.0) {
          eml_x = -1.0;
        } else {
          eml_x = 0.0;
        }

        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[2] = (fabs
          (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[2]) -
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7_n) * eml_x /
          (1.0 - M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7_n);
      }
    } else {
      /* '<S67>:1:14' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[1];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[2];
    }

    /* DataTypeConversion: '<S3>/Data Type Conversion1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1_p[0] =
      (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1_p[1] =
      (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1_p[2] =
      (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[2];

    /* Sum: '<S70>/Sum of Elements' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SumofElements =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1_p[0] +
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1_p[1]) +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1_p[2];

    /* Abs: '<S70>/Abs' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs = (real32_T)fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SumofElements);

    /* UnitDelay: '<S70>/Unit Delay2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay2_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay2_DSTATE_d;

    /* Embedded MATLAB: '<S70>/Embedded MATLAB Function' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Timeline/Embedded MATLAB Function': '<S118>:1' */
    if ((real_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs > 0.01) {
      /* '<S118>:1:5' */
      /* '<S118>:1:6' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ac_out = 1.0;

      /* '<S118>:1:7' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y = 1.0;
    } else if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay2_d == 1.0)
    {
      /* '<S118>:1:9' */
      /* '<S118>:1:10' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y = 1.0;

      /* '<S118>:1:11' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ac_out = 1.0;
    } else {
      /* '<S118>:1:13' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y = 0.0;

      /* '<S118>:1:14' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ac_out = 0.0;
    }

    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_o == 1)
    {
      /* '<S118>:1:18' */
      /* '<S118>:1:19' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ac_out = 0.0;

      /* '<S118>:1:20' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y = 0.0;
    }

    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f == 0.0) {
      /* '<S118>:1:23' */
      /* '<S118>:1:24' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y = 0.0;

      /* '<S118>:1:25' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ac_out = 0.0;
    }

    /* Switch: '<S70>/Switch2' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ac_out >
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch2_Threshold) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch2 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch2 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_a;
    }

    /* DiscreteIntegrator: '<S103>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i
      [0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i
      [1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i
      [2];

    /* Logic: '<S94>/Logical Operator2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator2 =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator3 &&
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f != 0.0));

    /* Switch: '<S94>/Switch4' incorporates:
     *  Constant: '<S94>/Constant10'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator2) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[1];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[2];
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant10_Value[0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant10_Value[1];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant10_Value[2];
    }

    /* Outputs for enable SubSystem: '<S5>/6_DOF Control' incorporates:
     *  EnablePort: '<S125>/Enable'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl_b) {
      /* DataTypeConversion: '<S125>/Data Type Conversion6' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6 =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.vis_cond;

      /* DataTypeConversion: '<S125>/Data Type Conversion7' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion7 =
        (real32_T)
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator6_n;

      /* Byte Packing: <S125>/Byte Packing 3 */
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking3 + 0,
                   (uint8_T*)
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6,
                   4);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking3 + 4,
                   (uint8_T*)
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion7,
                   4);

      /* DataTypeConversion: '<S125>/Data Type Conversion' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_g[0] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum9;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_g[1] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum15;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_g[2] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum11;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_g[3] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum17;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_g[4] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum16;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_g[5] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum3;

      /* DataTypeConversion: '<S125>/Data Type Conversion3' */
      for (i_0 = 0; i_0 < 6; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion3[i_0] =
          (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[i_0];
      }

      /* DataTypeConversion: '<S125>/Data Type Conversion4' */
      if (rtIsNaN(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum20) || rtIsInf
          (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum20)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum20),
                     256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_d = eml_x
        < 0.0 ? (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* DataTypeConversion: '<S125>/Data Type Conversion5' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion5 =
        (real32_T)
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_a;

      /* DataTypeConversion: '<S125>/Data Type Conversion8' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion8[0] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y_h;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion8[1] =
        (real32_T)
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction2_j.y;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion8[2] =
        (real32_T)
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction5.y;

      /* DataTypeConversion: '<S125>/Data Type Conversion10' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion10 =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide;

      /* DataTypeConversion: '<S125>/Data Type Conversion12' */
      if (rtIsNaN(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.vis_cond) ||
          rtIsInf(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.vis_cond)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.vis_cond),
                     256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion12 = eml_x <
        0.0 ? (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* DataTypeConversion: '<S125>/Data Type Conversion13' */
      if (rtIsNaN(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.current_axis) ||
          rtIsInf(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.current_axis)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.current_axis),
                     256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion13 = eml_x <
        0.0 ? (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* DataTypeConversion: '<S125>/Data Type Conversion14' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion14 =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch2;

      /* DataTypeConversion: '<S125>/Data Type Conversion9' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion9[0] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_k[0];

      /* DataTypeConversion: '<S125>/Data Type Conversion11' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion11[0] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_j[0];

      /* DataTypeConversion: '<S125>/Data Type Conversion16' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion16[0] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[0];

      /* DataTypeConversion: '<S125>/Data Type Conversion9' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion9[1] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_k[1];

      /* DataTypeConversion: '<S125>/Data Type Conversion11' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion11[1] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_j[1];

      /* DataTypeConversion: '<S125>/Data Type Conversion16' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion16[1] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[1];

      /* DataTypeConversion: '<S125>/Data Type Conversion9' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion9[2] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_k[2];

      /* DataTypeConversion: '<S125>/Data Type Conversion11' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion11[2] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_j[2];

      /* DataTypeConversion: '<S125>/Data Type Conversion16' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion16[2] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[2];

      /* DataTypeConversion: '<S125>/Data Type Conversion17' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion17[0] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion17[1] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion17[2] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2;

      /* DataTypeConversion: '<S125>/Data Type Conversion19' */
      if (rtIsNaN(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f) ||
          rtIsInf(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f),
                     256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion19 = eml_x <
        0.0 ? (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* DataTypeConversion: '<S125>/Data Type Conversion18' */
      if (rtIsNaN
          (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1) ||
          rtIsInf
          (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1),
                     256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion18 = eml_x <
        0.0 ? (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* Byte Packing: <S125>/Byte Packing  */
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking + 0,
                   (uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_g,
                   24);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking + 24,
                   (uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_g, 12);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking + 36,
                   (uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o2_c, 8);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking + 44,
                   (uint8_T*)
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o5, 4);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking + 48,
                   (uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion3,
                   24);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking + 72,
                   (uint8_T*)
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_d,
                   1);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking + 73,
                   (uint8_T*)
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion5,
                   4);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking + 77,
                   (uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion8,
                   12);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking + 89,
                   (uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion9,
                   12);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking +
                   101, (uint8_T*)
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion10,
                   4);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking +
                   105, (uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion11,
                   12);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking +
                   117, (uint8_T*)
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion12,
                   1);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking +
                   118, (uint8_T*)
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion13,
                   1);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking +
                   119, (uint8_T*)
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion14,
                   4);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking +
                   123, (uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_g, 12);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking +
                   135, (uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion16,
                   12);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking +
                   147, (uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion17,
                   12);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking +
                   159, (uint8_T*)
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion19,
                   1);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking +
                   160, (uint8_T*)
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion18,
                   1);

      /* Level2 S-Function Block: '<S125>/GT-RT UDP TX1' (gt_rt_udp_send) */
      {
        SimStruct *rts =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[5];
        sfcnOutputs(rts, 0);
      }

      /* Level2 S-Function Block: '<S125>/GT-RT UDP TX' (gt_rt_udp_send) */
      {
        SimStruct *rts =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[6];
        sfcnOutputs(rts, 0);
      }

      /* Level2 S-Function Block: '<S125>/GT-RT UDP  Write' (gt_rt_udp_controller) */
      {
        SimStruct *rts =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[7];
        sfcnOutputs(rts, 0);
      }

      /* Level2 S-Function Block: '<S125>/GT-RT UDP  Write1' (gt_rt_udp_controller) */
      {
        SimStruct *rts =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[8];
        sfcnOutputs(rts, 0);
      }

      srUpdateBC
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork._DOFControl_SubsysRanBC);
    }

    /* end of Outputs for SubSystem: '<S5>/6_DOF Control' */

    /* Sum: '<S3>/Sum2' incorporates:
     *  Constant: '<S3>/x_e'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.x +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.x_e_Value;

    /* Sum: '<S3>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n;

    /* Sum: '<S3>/Sum8' incorporates:
     *  Constant: '<S3>/y_e'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum8 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction2_j.y
      + M37_Sim_Forcing_003h_expe_infra_transz_lim_P.y_e_Value;

    /* Sum: '<S3>/Sum6' incorporates:
     *  Constant: '<S3>/z_e'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.z_e_Value;

    /* Sum: '<S3>/Sum4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum4 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_o;

    /* Sum: '<S3>/Sum7' incorporates:
     *  Constant: '<S3>/Phi'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum7 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Phi_Value;

    /* Sum: '<S3>/Sum5' incorporates:
     *  Constant: '<S3>/Theta'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum5 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1 +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Theta_Value;

    /* Sum: '<S3>/Sum14' incorporates:
     *  Constant: '<S3>/Psi'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Psi_Value;

    /* Sum: '<S3>/Sum12' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum12 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2 +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n;

    /* Outputs for enable SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' incorporates:
     *  EnablePort: '<S1>/Enable'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl_b) {
      /* DataTypeConversion: '<S1>/Data Type Conversion' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_o[0] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum9;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_o[1] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum15;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_o[2] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum11;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_o[3] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum17;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_o[4] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum16;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_o[5] =
        (real32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum3;

      /* DataTypeConversion: '<S1>/Data Type Conversion6' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6_o =
        (real32_T)
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator;

      /* Byte Packing: <S1>/Byte Packing  */
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking_e +
                   0, (uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_o,
                   24);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking_e +
                   24, (uint8_T*)
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o3_f, 4);
      (void)memcpy((uint8_T*)
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking_e +
                   28, (uint8_T*)
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6_o,
                   4);

      /* Level2 S-Function Block: '<S1>/GT-RT UDP TX' (gt_rt_udp_send) */
      {
        SimStruct *rts =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[0];
        sfcnOutputs(rts, 0);
      }

      /* Level2 S-Function Block: '<S1>/GT-RT UDP  Write' (gt_rt_udp_controller) */
      {
        SimStruct *rts =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[1];
        sfcnOutputs(rts, 0);
      }

      srUpdateBC
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork._DOFVisualCab120615_SubsysRanBC);
    }

    /* end of Outputs for SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' */

    /* Sum: '<S47>/Add2' incorporates:
     *  Constant: '<S47>/PSEA1'
     */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_c;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.PSEA1_Value;

    /* Abs: '<S47>/Abs2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2 = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n);

    /* UnitDelay: '<S131>/Unit Delay' */
    for (i_0 = 0; i_0 < 6; i_0++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_i[i_0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_ef[i_0];
    }

    /* DataTypeConversion: '<S3>/Data Type Conversion6' */
    if (rtIsNaN(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mod) || rtIsInf
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mod)) {
      eml_x = 0.0;
    } else {
      eml_x = fmod(floor(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mod),
                   256.0);
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6_n = eml_x <
      0.0 ? (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

    /* Logic: '<Root>/Logical Operator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_i =
      ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[2] != 0) &&
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6_n != 0));

    /* Switch: '<S131>/Switch1' incorporates:
     *  Constant: '<S131>/Constant'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_i) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_e = 0.0;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_e =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_ee;
    }

    /* Outputs for enable SubSystem: '<S138>/Simplified Inverse Kin' incorporates:
     *  EnablePort: '<S142>/Enable'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_e > 0.0) {
      /* SignalConversion: '<S145>/TmpSignal ConversionAt SFunction Inport1' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
        [0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
        [1] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum8;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
        [2] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum4;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
        [3] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum7;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
        [4] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum5;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
        [5] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum12;
      for (i_0 = 0; i_0 < 6; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
          [i_0 + 6] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_i[i_0];
      }

      /* Embedded MATLAB: '<S142>/Embedded MATLAB Function3' */
      /* Embedded MATLAB Function 'Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics/Simplified Inverse Kin/Embedded MATLAB Function3': '<S145>:1' */
      /* '<S145>:1:2' */
      for (i_0 = 0; i_0 < 7; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[i_0] = 0.0;
      }

      /* '<S145>:1:4' */
      eml_x =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
        [0] / 100.0;

      /* '<S145>:1:5' */
      eml_x_0 =
        (-M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
         [2]) / 100.0;

      /* '<S145>:1:6' */
      /* '<S145>:1:8' */
      /* '<S145>:1:9' */
      /* '<S145>:1:10' */
      /*  RTD=180/pi; */
      /* '<S145>:1:15' */
      eml_CA = cos
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
         [8] * 1.7453292519943295E-002);

      /* '<S145>:1:16' */
      eml_SA = sin
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
         [8] * 1.7453292519943295E-002);

      /* '<S145>:1:17' */
      /* '<S145>:1:18' */
      eml_CA_0 = cos
        ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
          [7] +
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
          [8]) * 1.7453292519943295E-002);

      /* '<S145>:1:19' */
      eml_SA_0 = sin
        ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
          [7] +
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
          [8]) * 1.7453292519943295E-002);

      /*  cth5i=cos(theta5_in*DTR); */
      /*  sth5i=sin(theta5_in*DTR); */
      /* '<S145>:1:22' */
      eml_CA_1 = cos
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
         [4]);

      /* '<S145>:1:23' */
      eml_A_2 = sin
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
         [4]);

      /* '<S145>:1:25' */
      /*  L3=0.66; */
      /*  L4=0.365; */
      /* '<S145>:1:31' */
      /* L3+L4; */
      /* K=L2*L2+offset*offset+(L34)*(L34); */
      /* '<S145>:1:35' */
      /* '<S145>:1:37' */
      /* left_side=0.3325; */
      /* equation to be solved: */
      /*  left_side= offset*sinus(theta3)+(L3+L4)cosinus(theta3) */
      /* we assume theta3 is small */
      /*  syms theta3 */
      /*  eqnth3 = left_side== offset*sin(theta3)+(L34)*cos(theta3); */
      /*  solth3=180*eval(solve(eqnth3,theta3))/pi; */
      /*   */
      /*  for i=1:length(solth3) */
      /*      if(solth3(i)<0) */
      /*          theta3=solth3(i); */
      /*      end */
      /*  end */
      /* '<S145>:1:54' */
      eml_x_0 = ((((((eml_x - 0.5) - 0.29 * eml_CA_1) * ((eml_x - 0.5) - 0.29 *
        eml_CA_1) + ((eml_x_0 - 2.105) - 0.29 * eml_A_2) * ((eml_x_0 - 2.105) -
        0.29 * eml_A_2)) - 2.7437) / 2.6 - (0.055 * eml_CA_1 + 1.025 * eml_A_2) *
                  eml_SA) - (-0.055 * eml_A_2 + 1.025 * eml_CA_1) * eml_CA) /
        ((0.055 * eml_CA_1 + 1.025 * eml_A_2) * eml_CA - (-0.055 * eml_A_2 +
          1.025 * eml_CA_1) * eml_SA);
      if (fabs(eml_x_0) > 0.01) {
        /* '<S145>:1:55' */
        /* '<S145>:1:56' */
        if (rtIsNaN(eml_x_0)) {
          eml_x_0 = (rtNaN);
        } else if (eml_x_0 > 0.0) {
          eml_x_0 = 1.0;
        } else if (eml_x_0 < 0.0) {
          eml_x_0 = -1.0;
        } else {
          eml_x_0 = 0.0;
        }

        eml_x_0 *= 0.01;
      }

      /* '<S145>:1:58' */
      eml_CA =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
        [8] + eml_x_0;

      /*  syms theta5 */
      /*  alpha=L2*cos(theta3*pi/180)+(L34); */
      /*  beta=L2*sin(theta3*pi/180)+offset; */
      /*  eqnth5 = X-L1-L5 == alpha*cos(theta5)-beta*sin(theta5); */
      /*  solth5=180*eval(solve(eqnth5,theta5))/pi; */
      /*   */
      /*  for i=1:length(solth5) */
      /*      if(solth5(i)>0) */
      /*          theta5=solth5(i); */
      /*      end */
      /*  end */
      /* '<S145>:1:73' */
      /* '<S145>:1:75' */
      eml_x_0 = (((((eml_x - 0.5) - 0.29 * eml_CA_1) - cos
                   (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
                    [7] * 1.7453292519943295E-002) * 1.3) - 0.055 * eml_SA_0) -
                 1.025 * eml_CA_0) / (0.055 * eml_CA_0 - 1.025 * eml_SA_0);
      if (fabs(eml_x_0) > 0.01) {
        /* '<S145>:1:76' */
        /* '<S145>:1:77' */
        if (rtIsNaN(eml_x_0)) {
          eml_x_0 = (rtNaN);
        } else if (eml_x_0 > 0.0) {
          eml_x_0 = 1.0;
        } else if (eml_x_0 < 0.0) {
          eml_x_0 = -1.0;
        } else {
          eml_x_0 = 0.0;
        }

        eml_x_0 *= 0.01;
      }

      /* '<S145>:1:79' */
      eml_x_0 +=
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
        [10];

      /* '<S145>:1:81' */
      /* '<S145>:1:83' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[0] = 0.0;

      /* '<S145>:1:84' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[1] =
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
         [4] - eml_CA) - eml_x_0;

      /* '<S145>:1:85' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[2] = eml_CA;

      /* '<S145>:1:86' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[3] = 0.0;

      /* '<S145>:1:87' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[4] = eml_x_0;

      /* '<S145>:1:88' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[5] = 0.0;

      /* Embedded MATLAB: '<S142>/Embedded MATLAB Function2' */
      /* Embedded MATLAB Function 'Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics/Simplified Inverse Kin/Embedded MATLAB Function2': '<S144>:1' */
      /* '<S144>:1:2' */
      for (i_0 = 0; i_0 < 6; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_m[i_0] = 0.0;
      }

      /* '<S144>:1:4' */
      /* '<S144>:1:5' */
      /* '<S144>:1:6' */
      /* '<S144>:1:9' */
      /*  L3=0.66; */
      /*  L4=0.365; */
      /* '<S144>:1:15' */
      /* L3+L4; */
      /* '<S144>:1:18' */
      eml_x = cos(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[1] *
                  1.7453292519943295E-002 +
                  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[2] *
                  1.7453292519943295E-002);

      /* '<S144>:1:19' */
      eml_x_0 = sin(M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[1] *
                    1.7453292519943295E-002 +
                    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[2] *
                    1.7453292519943295E-002);

      /* '<S144>:1:20' */
      /* '<S144>:1:21' */
      /* '<S144>:1:23' */
      eml_CA = (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[1] +
                M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[2]) +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[4];

      /* '<S144>:1:24' */
      /* '<S144>:1:25' */
      /* '<S144>:1:27' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_m[0] = ((((cos
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[1] *
         1.7453292519943295E-002) * 1.3 + 0.5) + 0.055 * eml_x_0) + 1.025 *
        eml_x) + cos(eml_CA * 1.7453292519943295E-002) * 0.29) * 100.0;

      /* '<S144>:1:28' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_m[2] = ((((sin
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[1] *
         1.7453292519943295E-002) * 1.3 + 2.105) - 0.055 * eml_x) + 1.025 *
        eml_x_0) + sin(eml_CA * 1.7453292519943295E-002) * 0.29) * -100.0;

      /* '<S144>:1:29' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_m[4] = eml_CA;

      /* SignalConversion: '<S143>/TmpSignal ConversionAt SFunction Inport1' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
        [0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
        [1] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum8;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
        [2] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum4;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
        [3] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum7;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
        [4] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum5;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
        [5] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum12;
      for (i_0 = 0; i_0 < 6; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
          [i_0 + 6] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_i[i_0];
      }

      /* Embedded MATLAB: '<S142>/Embedded MATLAB Function1' */
      /* Embedded MATLAB Function 'Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics/Simplified Inverse Kin/Embedded MATLAB Function1': '<S143>:1' */
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
      /*  May 7,2015 soft limits on the links (NED convention) */
      /* '<S143>:1:34' */
      /*  define length of the links */
      /* '<S143>:1:39' */
      /*  arm length in cm */
      /* '<S143>:1:40' */
      /* '<S143>:1:41' */
      /* '<S143>:1:42' */
      /*  vertical offset of the center line of */
      /*  joint 4 from centerline of arm A3 */
      /* '<S143>:1:47' */
      /*  height link A2 above the ground */
      /* '<S143>:1:49' */
      /* '<S143>:1:50' */
      /* '<S143>:1:51' */
      /* '<S143>:1:53' */
      /* '<S143>:1:54' */
      /* '<S143>:1:55' */
      /* '<S143>:1:57' */
      eml_k = 1;

      /* '<S143>:1:58' */
      for (i_0 = 0; i_0 < 7; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[i_0] = 0.0;
      }

      /*  compute dimensions of triangle */
      /* '<S143>:1:61' */
      /* '<S143>:1:62' */
      eml_x = (sqrt
               (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
                [0] *
                M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
                [0] +
                M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
                [1] *
                M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
                [1]) - 50.0) - cos(1.7453292519943295E-002 *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
        [4]) * 29.0;

      /* '<S143>:1:63' */
      eml_x_0 = (-(210.5 +
                   M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
                   [2])) - sin(1.7453292519943295E-002 *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
        [4]) * 29.0;

      /* '<S143>:1:64' */
      eml_CA = sqrt(rt_pow_snf(eml_x, 2.0) + rt_pow_snf(eml_x_0, 2.0));

      /*  check whether the FAR location of C is reachable */
      /* '<S143>:1:68' */
      /* '<S143>:1:69' */
      /*  margin is 5 cm */
      if (eml_CA > 227.5) {
        /* '<S143>:1:70' */
        /* '<S143>:1:71' */
        for (i_0 = 0; i_0 < 6; i_0++) {
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[i_0] =
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
            [6 + i_0];
        }

        /*  return angles 'as is' */
        /* '<S143>:1:72' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[2] = -90.0;

        /* '<S143>:1:73' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[6] = -2.0;
      } else {
        /*  check whether the CLOSE location of C is reachable */
        if ((eml_CA + 102.5) - 5.0 < 130.0) {
          /* '<S143>:1:78' */
          /* '<S143>:1:79' */
          for (i_0 = 0; i_0 < 6; i_0++) {
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[i_0] =
              M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
              [6 + i_0];
          }

          /*  return angles 'as is' */
          /* '<S143>:1:80' */
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[2] = -90.0;

          /* '<S143>:1:81' */
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[6] = -2.0;
        } else {
          /*  This iterative loop serves to correct for the offset of link A4 */
          /*  A first good guess is to assume that beta is initially 90 deg */
          /*  A second-order scheme is used */
          /* '<S143>:1:89' */
          /* '<S143>:1:90' */
          eml_SA =
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
            [8] + 180.0;
          do {
            i = 0;

            /* '<S143>:1:94' */
            eml_CA_0 = sin(eml_SA * 1.7453292519943295E-002);

            /* '<S143>:1:95' */
            eml_SA_0 = eml_CA_0 * eml_CA_0;

            /* '<S143>:1:96' */
            eml_CA_1 = cos(eml_SA * 1.7453292519943295E-002);

            /* '<S143>:1:98' */
            eml_A_2 = 130.0 - 5.5 / eml_CA_0;

            /* '<S143>:1:99' */
            eml_CA_2 = 102.5 - 5.5 * eml_CA_1 / eml_CA_0;

            /* '<S143>:1:101' */
            eml_A_0 = 5.5 * eml_CA_1 / eml_SA_0;

            /* '<S143>:1:102' */
            eml_A_1 = 5.5 / eml_SA_0;

            /* '<S143>:1:104' */
            eml_SA_0 = (eml_A_2 * eml_A_2 + eml_CA_2 * eml_CA_2) - eml_CA *
              eml_CA;

            /* '<S143>:1:105' */
            eml_A = 2.0 * eml_A_2 * eml_CA_2;

            /* '<S143>:1:106' */
            /* '<S143>:1:107' */
            /* '<S143>:1:108' */
            /* '<S143>:1:109' */
            /* '<S143>:1:110' */
            eml_A_1 = (eml_CA_1 - eml_SA_0 / eml_A) * -5.7295779513082323E+001 /
              ((-eml_CA_0) - ((2.0 * eml_A_2 * eml_A_0 + 2.0 * eml_CA_2 *
                               eml_A_1) * eml_A - (eml_A_0 * eml_CA_2 + eml_A_2 *
                 eml_A_1) * 2.0 * eml_SA_0) / rt_pow_snf(eml_A, 2.0));

            /* '<S143>:1:111' */
            eml_SA += eml_A_1;
            if (fabs(eml_A_1) < 1.0E-005) {
              /* '<S143>:1:113' */
              i = 1;
            } else {
              /* '<S143>:1:116' */
              eml_k++;
              if (eml_k > 100) {
                /* '<S143>:1:117' */
                /* '<S143>:1:118' */
                eml_k = -2;

                /* '<S143>:1:119' */
                for (i_0 = 0; i_0 < 6; i_0++) {
                  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[i_0] =
                    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
                    [6 + i_0];
                }

                /*  return angles 'as is' */
                /* '<S143>:1:120' */
                M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[2] = -90.0;

                /* '<S143>:1:121' */
                M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[6] = -2.0;
                i = 1;
              }
            }
          } while ((uint32_T)i == 0U);

          /*  employ cosine rule on angles alpha and beta of triangle */
          /* '<S143>:1:127' */
          /* '<S143>:1:129' */
          /* '<S143>:1:130' */
          /*  the link angles */
          /* '<S143>:1:133' */
          /* '<S143>:1:134' */
          eml_SA_0 = acos(((eml_A_2 * eml_A_2 + eml_CA * eml_CA) - eml_CA_2 *
                           eml_CA_2) / (2.0 * eml_A_2 * eml_CA)) *
            5.7295779513082323E+001 + 5.7295779513082323E+001 * rt_atan2_snf
            (eml_x_0, eml_x);

          /* '<S143>:1:135' */
          eml_A_1 = eml_SA - 180.0;

          /* '<S143>:1:136' */
          /* '<S143>:1:137' */
          /* '<S143>:1:138' */
          /* '<S143>:1:140' */
          eml_ang[0] = 5.7295779513082323E+001 * rt_atan2_snf
            (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
             [1],
             M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
             [0]);
          eml_ang[1] = eml_SA_0;
          eml_ang[2] = eml_A_1;
          eml_ang[3] = 0.0;
          eml_ang[4] = (-(eml_SA_0 + eml_A_1)) +
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
            [4];
          eml_ang[5] = 0.0;

          /* '<S143>:1:141' */
          for (i_0 = 0; i_0 < 6; i_0++) {
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[i_0] =
              eml_ang[i_0];
          }

          /*  tests whether the links are within the set soft limits */
          for (i = 0; i < 6; i++) {
            /* '<S143>:1:144' */
            if (eml_ang[i] >= (real_T)tmp_9[i << 1]) {
              /* '<S143>:1:145' */
              /* '<S143>:1:146' */
              eml_k = -11 - i;
            } else {
              if (eml_ang[i] <= (real_T)tmp_9[(i << 1) + 1]) {
                /* '<S143>:1:147' */
                /* '<S143>:1:148' */
                eml_k = -101 - i;
              }
            }
          }

          /* '<S143>:1:152' */
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[6] = (real_T)eml_k;
        }
      }

      srUpdateBC
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.SimplifiedInverseKin_SubsysRanB);
    }

    /* end of Outputs for SubSystem: '<S138>/Simplified Inverse Kin' */

    /* Sum: '<S138>/Sum' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_p[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_i[0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_p[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_i[1] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_p[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_i[2] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[2];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_p[3] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_i[3];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_p[4] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_i[4] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[4];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_p[5] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_i[5];

    /* DiscreteIntegrator: '<S138>/Discrete-Time Integrator1' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_IC_LOAD)
    {
      for (i_0 = 0; i_0 < 6; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_d
          [i_0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_p[i_0];
      }
    }

    if (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_e > 0.0) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_k
          <= 0)) || ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_e <=
                      0.0) &&
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_k
                      == 1))) {
      for (i_0 = 0; i_0 < 6; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_d
          [i_0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_p[i_0];
      }
    }

    /* Sum: '<S135>/Sum' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_l[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[0] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_l[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[1] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum8;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_l[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[2] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum4;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_l[3] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[3] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum7;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_l[4] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[4] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum5;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_l[5] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[5] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum12;

    /* DiscreteIntegrator: '<S135>/Discrete-Time Integrator' */
    for (i_0 = 0; i_0 < 6; i_0++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_j[i_0]
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_d
        [i_0];
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_IC_LOADI)
      {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_DSTATE_g
          [i_0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_l[i_0];
      }
    }

    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_i &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_PrevRe_i
          <= 0)) ||
        ((!M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_i) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_PrevRe_i
          == 1))) {
      for (i_0 = 0; i_0 < 6; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_DSTATE_g
          [i_0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_l[i_0];
      }
    }

    for (i_0 = 0; i_0 < 6; i_0++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[i_0]
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_DSTATE_g
        [i_0];
    }

    /* Sum: '<S135>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_n[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1 +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_n[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum8 +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_n[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum4 +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[2];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_n[3] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum7 +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[3];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_n[4] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum5 +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[4];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_n[5] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum12 +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[5];

    /* Outputs for enable SubSystem: '<S135>/full inverse kin' incorporates:
     *  EnablePort: '<S139>/Enable'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_i) {
      /* SignalConversion: '<S140>/TmpSignal ConversionAt SFunction Inport1' */
      for (i_0 = 0; i_0 < 6; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_f
          [i_0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_n[i_0];
      }

      /* Embedded MATLAB: '<S139>/Embedded MATLAB Function' */
      /* Embedded MATLAB Function 'Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Inverse Kinematics/full inverse kin/Embedded MATLAB Function': '<S140>:1' */
      /* -------------------------------------------------------------------------- */
      /*  */
      /*    This function solves the inverse kinematics of the 6-DOF KUKA arm and */
      /*    wrist by means of an iterative algorithm. This is the  version, */
      /*    embedded in Simulink. The input and output are vectors that include the */
      /*    list of parameters as defined herafter */
      /*  */
      /*        *** Input variables, vec(1:13) *** */
      /*  */
      /*    vec(1: 3)    POS         Room coordinates of flange, NED in cm */
      /*    vec(4: 6)    EUL_ANG     Euler angles of the flange, phi, theta, psi, in deg */
      /*    vec(7:12)    J_ANG_0     Initial guess of the joint angles, in deg */
      /*  */
      /*        *** Output Variables *** */
      /*  */
      /*    out(1:6)  J_ANG          The six joint angles after convergence */
      /*    out(7)    N, error code  Number of iterations, when negative, it is an */
      /*                             error code: */
      /*                                -1 no convergence */
      /*                                -2 out of reach of joints */
      /*                                -3 joint angles exceeded */
      /*  */
      /*    The North_East_Down convention is used and psi, theta, phi rotation */
      /*    sequence; A2, A3, A5 are up positive and A4, A6 right rotation positive */
      /*    Note that this is different from the KUKA convention */
      /*  */
      /*    Written by Arthur J. Grunwald, Nov. 14, 2014 */
      /*    Re-written for Simulink embedded, Nov. 20, 2014 */
      /*  */
      /* -------------------------------------------------------------------------- */
      /*  reload variables */
      /* '<S140>:1:37' */
      /*  Room coordinates of flange, NED in cm */
      /* '<S140>:1:38' */
      for (i_0 = 0; i_0 < 6; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_f
          [i_0 + 6] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_i[i_0];
        eml_ang[i_0] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_f
          [i_0 + 6];
      }

      eml_x_p[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_f
        [0];
      eml_x_p[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_f
        [1];
      eml_x_p[2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_f
        [2];

      /*  Euler angles of the flange, phi, theta, psi, in deg */
      /* '<S140>:1:39' */
      /*  Initial guess of the joint angles, in deg */
      /* '<S140>:1:40' */
      for (i_0 = 0; i_0 < 7; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_a[i_0] = 0.0;
      }

      /*  reserve place for out */
      /*  soft limits on the links (NED convention) */
      /*  SL = [   175    130     88    200    61    200 */
      /*          -175    -20    -88   -200   -61   -200]; */
      /*  Dec. 6, 2014: A2 and A3 limits changed to KUKA hardware */
      /*  May 7,2015 soft limits on the links (NED convention) */
      /* '<S140>:1:49' */
      /*  define length of arms */
      /* '<S140>:1:53' */
      /*  arm length in cm */
      /* '<S140>:1:54' */
      /* '<S140>:1:55' */
      /* '<S140>:1:56' */
      /* '<S140>:1:57' */
      /* '<S140>:1:58' */
      /*  vertical offset of the center line of */
      /*  joint 4 from centerline of arm A3 */
      /* '<S140>:1:60' */
      /*  height link A2 above the ground */
      /*  offset the height so that level zero is now at the height of the A2 joint */
      /* '<S140>:1:63' */
      eml_x_p[2] += 210.5;

      /*  set initial guess; the algorithm works in rad, so ang is in rad */
      /* '<S140>:1:66' */
      eml_k = 0;

      /* '<S140>:1:67' */
      for (i_0 = 0; i_0 < 6; i_0++) {
        eml_ang_0[i_0] = eml_ang[i_0] * 1.7453292519943295E-002;
      }

      /*  check for maximum range of arm links and exit with n = 2 when exceeded */
      /* '<S140>:1:71' */
      /* '<S140>:1:72' */
      if (sqrt(rt_pow_snf(eml_x_p[0], 2.0) + rt_pow_snf(eml_x_p[1], 2.0)) >
          (sqrt(68382.25 - rt_pow_snf(eml_x_p[2], 2.0)) + 50.0) - 5.0) {
        /* '<S140>:1:73' */
        /* '<S140>:1:74' */
        for (i_0 = 0; i_0 < 6; i_0++) {
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_a[i_0] = eml_ang[i_0];
        }

        /*  return vector as is */
        /* '<S140>:1:75' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_a[6] = -2.0;
      } else {
        /* -------------------------------- */
        /*  	start of iterative loop */
        /* -------------------------------- */
        do {
          i = 0;

          /*  4x4 Transfer matrices, include both rotation and translation */
          /* '<S140>:1:87' */
          for (eml_k_0 = 0; eml_k_0 < 6; eml_k_0++) {
            for (eml_A = eml_ang_0[eml_k_0]; eml_A > 3.1415926535897931E+000;
                 eml_A -= 6.2831853071795862E+000) {
            }

            while (eml_A < -3.1415926535897931E+000) {
              eml_A += 6.2831853071795862E+000;
            }

            eml_ang_0[eml_k_0] = eml_A;
          }

          /*  ang is brought in the range +-pi */
          /* '<S140>:1:88' */
          /* '<S140>:1:89' */
          /* '<S140>:1:90' */
          /* '<S140>:1:91' */
          /* '<S140>:1:92' */
          /* '<S140>:1:93' */
          /* '<S140>:1:95' */
          eml_x = cos(eml_ang_0[0]);

          /* '<S140>:1:96' */
          eml_x_0 = sin(eml_ang_0[0]);

          /* '<S140>:1:97' */
          eml_CA = cos(eml_ang_0[1]);

          /* '<S140>:1:98' */
          eml_SA = sin(eml_ang_0[1]);

          /* '<S140>:1:99' */
          eml_CA_0 = cos(eml_ang_0[2]);

          /* '<S140>:1:100' */
          eml_SA_0 = sin(eml_ang_0[2]);

          /* '<S140>:1:101' */
          eml_CA_1 = cos(eml_ang_0[3]);

          /* '<S140>:1:102' */
          eml_A_2 = sin(eml_ang_0[3]);

          /* '<S140>:1:103' */
          eml_CA_2 = cos(eml_ang_0[4]);

          /* '<S140>:1:104' */
          eml_A_0 = sin(eml_ang_0[4]);

          /* '<S140>:1:105' */
          eml_A_1 = cos(eml_ang_0[5]);

          /* '<S140>:1:106' */
          eml_A = sin(eml_ang_0[5]);

          /* '<S140>:1:108' */
          eml_D[0] = eml_x;
          eml_D[4] = -eml_x_0;
          eml_D[8] = 0.0;
          eml_D[12] = 0.0;
          eml_D[1] = eml_x_0;
          eml_D[5] = eml_x;
          eml_D[9] = 0.0;
          eml_D[13] = 0.0;
          eml_D[2] = 0.0;
          eml_D[6] = 0.0;
          eml_D[10] = 1.0;
          eml_D[14] = 0.0;
          eml_D[3] = 0.0;
          eml_D[7] = 0.0;
          eml_D[11] = 0.0;
          eml_D[15] = 1.0;

          /* '<S140>:1:109' */
          eml_D_0[0] = eml_CA;
          eml_D_0[4] = 0.0;
          eml_D_0[8] = eml_SA;
          eml_D_0[12] = 50.0;
          eml_D_0[1] = 0.0;
          eml_D_0[5] = 1.0;
          eml_D_0[9] = 0.0;
          eml_D_0[13] = 0.0;
          eml_D_0[2] = -eml_SA;
          eml_D_0[6] = 0.0;
          eml_D_0[10] = eml_CA;
          eml_D_0[14] = 0.0;
          eml_D_0[3] = 0.0;
          eml_D_0[7] = 0.0;
          eml_D_0[11] = 0.0;
          eml_D_0[15] = 1.0;

          /* '<S140>:1:110' */
          eml_D_1[0] = eml_CA_0;
          eml_D_1[4] = 0.0;
          eml_D_1[8] = eml_SA_0;
          eml_D_1[12] = 130.0;
          eml_D_1[1] = 0.0;
          eml_D_1[5] = 1.0;
          eml_D_1[9] = 0.0;
          eml_D_1[13] = 0.0;
          eml_D_1[2] = -eml_SA_0;
          eml_D_1[6] = 0.0;
          eml_D_1[10] = eml_CA_0;
          eml_D_1[14] = 0.0;
          eml_D_1[3] = 0.0;
          eml_D_1[7] = 0.0;
          eml_D_1[11] = 0.0;
          eml_D_1[15] = 1.0;

          /* '<S140>:1:111' */
          eml_D_2[0] = 1.0;
          eml_D_2[4] = 0.0;
          eml_D_2[8] = 0.0;
          eml_D_2[12] = 66.0;
          eml_D_2[1] = 0.0;
          eml_D_2[5] = eml_CA_1;
          eml_D_2[9] = -eml_A_2;
          eml_D_2[13] = 0.0;
          eml_D_2[2] = 0.0;
          eml_D_2[6] = eml_A_2;
          eml_D_2[10] = eml_CA_1;
          eml_D_2[14] = 5.5;
          eml_D_2[3] = 0.0;
          eml_D_2[7] = 0.0;
          eml_D_2[11] = 0.0;
          eml_D_2[15] = 1.0;

          /* '<S140>:1:112' */
          eml_D_3[0] = eml_CA_2;
          eml_D_3[4] = 0.0;
          eml_D_3[8] = eml_A_0;
          eml_D_3[12] = 36.5;
          eml_D_3[1] = 0.0;
          eml_D_3[5] = 1.0;
          eml_D_3[9] = 0.0;
          eml_D_3[13] = 0.0;
          eml_D_3[2] = -eml_A_0;
          eml_D_3[6] = 0.0;
          eml_D_3[10] = eml_CA_2;
          eml_D_3[14] = 0.0;
          eml_D_3[3] = 0.0;
          eml_D_3[7] = 0.0;
          eml_D_3[11] = 0.0;
          eml_D_3[15] = 1.0;

          /* '<S140>:1:113' */
          eml_D_4[0] = 1.0;
          eml_D_4[4] = 0.0;
          eml_D_4[8] = 0.0;
          eml_D_4[12] = 29.0;
          eml_D_4[1] = 0.0;
          eml_D_4[5] = eml_A_1;
          eml_D_4[9] = -eml_A;
          eml_D_4[13] = 0.0;
          eml_D_4[2] = 0.0;
          eml_D_4[6] = eml_A;
          eml_D_4[10] = eml_A_1;
          eml_D_4[14] = 0.0;
          eml_D_4[3] = 0.0;
          eml_D_4[7] = 0.0;
          eml_D_4[11] = 0.0;
          eml_D_4[15] = 1.0;

          /*  cut out the 3x3 DCM's for each of the transfer matrices */
          /*  Note that the DCM is for rotation from b->e */
          /* '<S140>:1:117' */
          for (i_0 = 0; i_0 < 3; i_0++) {
            eml_A_3[3 * i_0] = eml_D[i_0 << 2];
            eml_A_3[1 + 3 * i_0] = eml_D[(i_0 << 2) + 1];
            eml_A_3[2 + 3 * i_0] = eml_D[(i_0 << 2) + 2];
          }

          /* '<S140>:1:118' */
          for (i_0 = 0; i_0 < 3; i_0++) {
            eml_E[3 * i_0] = eml_D_0[i_0 << 2];
            eml_E[1 + 3 * i_0] = eml_D_0[(i_0 << 2) + 1];
            eml_E[2 + 3 * i_0] = eml_D_0[(i_0 << 2) + 2];
          }

          /* '<S140>:1:119' */
          for (i_0 = 0; i_0 < 3; i_0++) {
            eml_E_0[3 * i_0] = eml_D_1[i_0 << 2];
            eml_E_0[1 + 3 * i_0] = eml_D_1[(i_0 << 2) + 1];
            eml_E_0[2 + 3 * i_0] = eml_D_1[(i_0 << 2) + 2];
          }

          /* '<S140>:1:120' */
          for (i_0 = 0; i_0 < 3; i_0++) {
            eml_E_1[3 * i_0] = eml_D_2[i_0 << 2];
            eml_E_1[1 + 3 * i_0] = eml_D_2[(i_0 << 2) + 1];
            eml_E_1[2 + 3 * i_0] = eml_D_2[(i_0 << 2) + 2];
          }

          /* '<S140>:1:121' */
          for (i_0 = 0; i_0 < 3; i_0++) {
            eml_E_2[3 * i_0] = eml_D_3[i_0 << 2];
            eml_E_2[1 + 3 * i_0] = eml_D_3[(i_0 << 2) + 1];
            eml_E_2[2 + 3 * i_0] = eml_D_3[(i_0 << 2) + 2];
          }

          /* '<S140>:1:122' */
          /*  --- computed position from links A1-A6 --- */
          /* ---------------------------------------------------------------------- */
          /*    In order to move a point in the cabine in 6-DOF rather than the */
          /*    endplate, define the coordinates of that point in x_cabin */
          /* ---------------------------------------------------------------------- */
          /*  x,y,z cabin reference point (cm) */
          /* '<S140>:1:133' */
          /* '<S140>:1:134' */
          /*  position of the cabin reference point in the */
          /*  NED system (cm) */
          /*  computed Euler angles from links A1-A6 */
          /*  Euler matrices for rotation from e->b (note the transpose) */
          /* '<S140>:1:139' */
          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_D_5[i_0 + 3 * eml_k_0] = 0.0;
              eml_D_5[i_0 + 3 * eml_k_0] = eml_D_5[3 * eml_k_0 + i_0] +
                eml_D_4[i_0 << 2] * eml_E_2[eml_k_0];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_D_4[(i_0 << 2) + 1] *
                eml_E_2[eml_k_0 + 3] + eml_D_5[3 * eml_k_0 + i_0];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_D_4[(i_0 << 2) + 2] *
                eml_E_2[eml_k_0 + 6] + eml_D_5[3 * eml_k_0 + i_0];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_D_6[i_0 + 3 * eml_k_0] = 0.0;
              eml_D_6[i_0 + 3 * eml_k_0] = eml_D_6[3 * eml_k_0 + i_0] +
                eml_D_5[i_0] * eml_E_1[eml_k_0];
              eml_D_6[i_0 + 3 * eml_k_0] = eml_D_6[3 * eml_k_0 + i_0] +
                eml_D_5[i_0 + 3] * eml_E_1[eml_k_0 + 3];
              eml_D_6[i_0 + 3 * eml_k_0] = eml_D_6[3 * eml_k_0 + i_0] +
                eml_D_5[i_0 + 6] * eml_E_1[eml_k_0 + 6];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_D_7[i_0 + 3 * eml_k_0] = 0.0;
              eml_D_7[i_0 + 3 * eml_k_0] = eml_D_7[3 * eml_k_0 + i_0] +
                eml_D_6[i_0] * eml_E_0[eml_k_0];
              eml_D_7[i_0 + 3 * eml_k_0] = eml_D_7[3 * eml_k_0 + i_0] +
                eml_D_6[i_0 + 3] * eml_E_0[eml_k_0 + 3];
              eml_D_7[i_0 + 3 * eml_k_0] = eml_D_7[3 * eml_k_0 + i_0] +
                eml_D_6[i_0 + 6] * eml_E_0[eml_k_0 + 6];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_D_5[i_0 + 3 * eml_k_0] = 0.0;
              eml_D_5[i_0 + 3 * eml_k_0] = eml_D_5[3 * eml_k_0 + i_0] +
                eml_D_7[i_0] * eml_E[eml_k_0];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_D_5[3 * eml_k_0 + i_0] +
                eml_D_7[i_0 + 3] * eml_E[eml_k_0 + 3];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_D_5[3 * eml_k_0 + i_0] +
                eml_D_7[i_0 + 6] * eml_E[eml_k_0 + 6];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_E_3[i_0 + 3 * eml_k_0] = 0.0;
              eml_E_3[i_0 + 3 * eml_k_0] = eml_E_3[3 * eml_k_0 + i_0] +
                eml_D_5[i_0] * eml_A_3[eml_k_0];
              eml_E_3[i_0 + 3 * eml_k_0] = eml_E_3[3 * eml_k_0 + i_0] +
                eml_D_5[i_0 + 3] * eml_A_3[eml_k_0 + 3];
              eml_E_3[i_0 + 3 * eml_k_0] = eml_E_3[3 * eml_k_0 + i_0] +
                eml_D_5[i_0 + 6] * eml_A_3[eml_k_0 + 6];
            }
          }

          /* '<S140>:1:140' */
          /*  DCM to Euler angles */
          eml_eul_ang_idx = -asin(eml_E_3[6]);
          eml_eul_ang_idx_0 = rt_atan2_snf(eml_E_3[3], eml_E_3[0]);

          /*  determine the vectors of rotation of the endplate in e-system */
          /*  for each one of the links; this is a 3x6 matrix, when multiplied */
          /*  with the vector of the joint angles, it will give the vector */
          /*  of rotation of the endplate (and also of the cabin reference point) */
          /*  in the NED system */
          /* '<S140>:1:148' */
          /*  x-axis */
          /* '<S140>:1:149' */
          /*  y-axis */
          /* '<S140>:1:150' */
          /*  x-axis */
          /* '<S140>:1:151' */
          /*  y-axis */
          /* '<S140>:1:152' */
          /*  y-axis */
          /* '<S140>:1:153' */
          /*  z-axis */
          /* '<S140>:1:155' */
          /*  in order to see the changes in phi, theta, psi that this rotation */
          /*  vector causes, we have to transform e->b first in yaw and after that */
          /*  in pitch */
          /* '<S140>:1:160' */
          eml_A_4 = cos(eml_eul_ang_idx_0);

          /* '<S140>:1:161' */
          eml_A_5 = sin(eml_eul_ang_idx_0);

          /* '<S140>:1:162' */
          eml_A_6 = cos(eml_eul_ang_idx);

          /* '<S140>:1:163' */
          eml_A_7 = sin(eml_eul_ang_idx);

          /* '<S140>:1:165' */
          /* '<S140>:1:166' */
          /* '<S140>:1:167' */
          /*  the derivatives of D1-D6 for eah one of the link angles */
          /* '<S140>:1:172' */
          /* '<S140>:1:173' */
          /* '<S140>:1:174' */
          /* '<S140>:1:175' */
          /* '<S140>:1:176' */
          /* '<S140>:1:177' */
          /*  Hessian Matrix H; the inverse of this matrix determines the link */
          /*  angle speed as a function of the speed of x,y,z and the speed of the */
          /*  Euler angles */
          /* '<S140>:1:183' */
          /* '<S140>:1:184' */
          /* '<S140>:1:185' */
          /* '<S140>:1:186' */
          /* '<S140>:1:187' */
          /* '<S140>:1:188' */
          /* '<S140>:1:190' */
          /*  this 3x6 is th upper half of H */
          /* '<S140>:1:191' */
          /*  the lower 3x6 half is the matrix e */
          /* '<S140>:1:193' */
          eml_D_8[0] = -eml_x_0;
          eml_D_8[4] = -eml_x;
          eml_D_8[8] = 0.0;
          eml_D_8[12] = 0.0;
          eml_D_8[1] = eml_x;
          eml_D_8[5] = -eml_x_0;
          eml_D_8[9] = 0.0;
          eml_D_8[13] = 0.0;
          eml_D_8[2] = 0.0;
          eml_D_8[6] = 0.0;
          eml_D_8[10] = 0.0;
          eml_D_8[14] = 0.0;
          eml_D_8[3] = 0.0;
          eml_D_8[7] = 0.0;
          eml_D_8[11] = 0.0;
          eml_D_8[15] = 0.0;
          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
                eml_D_0[eml_k_0 << 2] * eml_D_8[i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_1[eml_k_0 << 2] * eml_D_9[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 1] *
                eml_D_9[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 2] *
                eml_D_9[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 3] *
                eml_D_9[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
                eml_D_2[eml_k_0 << 2] * eml_D_8[i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_3[eml_k_0 << 2] * eml_D_9[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 1] *
                eml_D_9[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 2] *
                eml_D_9[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 3] *
                eml_D_9[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_x_2[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_x_2[i_0 + (eml_k_0 << 2)] = eml_x_2[(eml_k_0 << 2) + i_0] +
                eml_D_4[eml_k_0 << 2] * eml_D_8[i_0];
              eml_x_2[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_x_2[(eml_k_0 << 2) + i_0];
              eml_x_2[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_x_2[(eml_k_0 << 2) + i_0];
              eml_x_2[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_x_2[(eml_k_0 << 2) + i_0];
            }
          }

          eml_D_8[0] = -eml_SA;
          eml_D_8[4] = 0.0;
          eml_D_8[8] = eml_CA;
          eml_D_8[12] = 0.0;
          eml_D_8[1] = 0.0;
          eml_D_8[5] = 0.0;
          eml_D_8[9] = 0.0;
          eml_D_8[13] = 0.0;
          eml_D_8[2] = -eml_CA;
          eml_D_8[6] = 0.0;
          eml_D_8[10] = -eml_SA;
          eml_D_8[14] = 0.0;
          eml_D_8[3] = 0.0;
          eml_D_8[7] = 0.0;
          eml_D_8[11] = 0.0;
          eml_D_8[15] = 0.0;
          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
                eml_D_8[eml_k_0 << 2] * eml_D[i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + 1] *
                eml_D[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + 2] *
                eml_D[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + 3] *
                eml_D[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_1[eml_k_0 << 2] * eml_D_9[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 1] *
                eml_D_9[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 2] *
                eml_D_9[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 3] *
                eml_D_9[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
                eml_D_2[eml_k_0 << 2] * eml_D_8[i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_3[eml_k_0 << 2] * eml_D_9[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 1] *
                eml_D_9[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 2] *
                eml_D_9[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 3] *
                eml_D_9[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_b[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_b[i_0 + (eml_k_0 << 2)] = eml_D_b[(eml_k_0 << 2) + i_0] +
                eml_D_4[eml_k_0 << 2] * eml_D_8[i_0];
              eml_D_b[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_D_b[(eml_k_0 << 2) + i_0];
              eml_D_b[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_D_b[(eml_k_0 << 2) + i_0];
              eml_D_b[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_D_b[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_0[eml_k_0 << 2] * eml_D[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 1] *
                eml_D[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 2] *
                eml_D[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 3] *
                eml_D[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          eml_D_9[0] = -eml_SA_0;
          eml_D_9[4] = 0.0;
          eml_D_9[8] = eml_CA_0;
          eml_D_9[12] = 0.0;
          eml_D_9[1] = 0.0;
          eml_D_9[5] = 0.0;
          eml_D_9[9] = 0.0;
          eml_D_9[13] = 0.0;
          eml_D_9[2] = -eml_CA_0;
          eml_D_9[6] = 0.0;
          eml_D_9[10] = -eml_SA_0;
          eml_D_9[14] = 0.0;
          eml_D_9[3] = 0.0;
          eml_D_9[7] = 0.0;
          eml_D_9[11] = 0.0;
          eml_D_9[15] = 0.0;
          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_c[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_c[(eml_k_0 << 2) + i_0] +
                eml_D_9[eml_k_0 << 2] * eml_D_8[i_0];
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_D_c[(eml_k_0 << 2) + i_0];
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_D_c[(eml_k_0 << 2) + i_0];
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_D_c[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_2[eml_k_0 << 2] * eml_D_c[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 1] *
                eml_D_c[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 2] *
                eml_D_c[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 3] *
                eml_D_c[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
                eml_D_3[eml_k_0 << 2] * eml_D_8[i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_d[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_d[i_0 + (eml_k_0 << 2)] = eml_D_d[(eml_k_0 << 2) + i_0] +
                eml_D_4[eml_k_0 << 2] * eml_D_9[i_0];
              eml_D_d[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 1] *
                eml_D_9[i_0 + 4] + eml_D_d[(eml_k_0 << 2) + i_0];
              eml_D_d[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 2] *
                eml_D_9[i_0 + 8] + eml_D_d[(eml_k_0 << 2) + i_0];
              eml_D_d[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 3] *
                eml_D_9[i_0 + 12] + eml_D_d[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_0[eml_k_0 << 2] * eml_D[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 1] *
                eml_D[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 2] *
                eml_D[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 3] *
                eml_D[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
                eml_D_1[eml_k_0 << 2] * eml_D_8[i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
            }
          }

          eml_D_8[0] = 0.0;
          eml_D_8[4] = 0.0;
          eml_D_8[8] = 0.0;
          eml_D_8[12] = 0.0;
          eml_D_8[1] = 0.0;
          eml_D_8[5] = -eml_A_2;
          eml_D_8[9] = -eml_CA_1;
          eml_D_8[13] = 0.0;
          eml_D_8[2] = 0.0;
          eml_D_8[6] = eml_CA_1;
          eml_D_8[10] = -eml_A_2;
          eml_D_8[14] = 0.0;
          eml_D_8[3] = 0.0;
          eml_D_8[7] = 0.0;
          eml_D_8[11] = 0.0;
          eml_D_8[15] = 0.0;
          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_c[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_c[(eml_k_0 << 2) + i_0] +
                eml_D_8[eml_k_0 << 2] * eml_D_9[i_0];
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + 1] *
                eml_D_9[i_0 + 4] + eml_D_c[(eml_k_0 << 2) + i_0];
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + 2] *
                eml_D_9[i_0 + 8] + eml_D_c[(eml_k_0 << 2) + i_0];
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + 3] *
                eml_D_9[i_0 + 12] + eml_D_c[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_3[eml_k_0 << 2] * eml_D_c[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 1] *
                eml_D_c[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 2] *
                eml_D_c[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 3] *
                eml_D_c[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_e[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_e[i_0 + (eml_k_0 << 2)] = eml_D_e[(eml_k_0 << 2) + i_0] +
                eml_D_4[eml_k_0 << 2] * eml_D_8[i_0];
              eml_D_e[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_D_e[(eml_k_0 << 2) + i_0];
              eml_D_e[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_D_e[(eml_k_0 << 2) + i_0];
              eml_D_e[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_D_e[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_0[eml_k_0 << 2] * eml_D[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 1] *
                eml_D[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 2] *
                eml_D[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 3] *
                eml_D[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
                eml_D_1[eml_k_0 << 2] * eml_D_8[i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_c[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_c[(eml_k_0 << 2) + i_0] +
                eml_D_2[eml_k_0 << 2] * eml_D_9[i_0];
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 1] *
                eml_D_9[i_0 + 4] + eml_D_c[(eml_k_0 << 2) + i_0];
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 2] *
                eml_D_9[i_0 + 8] + eml_D_c[(eml_k_0 << 2) + i_0];
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 3] *
                eml_D_9[i_0 + 12] + eml_D_c[(eml_k_0 << 2) + i_0];
            }
          }

          eml_D_8[0] = -eml_A_0;
          eml_D_8[4] = 0.0;
          eml_D_8[8] = eml_CA_2;
          eml_D_8[12] = 0.0;
          eml_D_8[1] = 0.0;
          eml_D_8[5] = 0.0;
          eml_D_8[9] = 0.0;
          eml_D_8[13] = 0.0;
          eml_D_8[2] = -eml_CA_2;
          eml_D_8[6] = 0.0;
          eml_D_8[10] = -eml_A_0;
          eml_D_8[14] = 0.0;
          eml_D_8[3] = 0.0;
          eml_D_8[7] = 0.0;
          eml_D_8[11] = 0.0;
          eml_D_8[15] = 0.0;
          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
                eml_D_8[eml_k_0 << 2] * eml_D_c[i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + 1] *
                eml_D_c[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + 2] *
                eml_D_c[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + 3] *
                eml_D_c[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_f[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_f[i_0 + (eml_k_0 << 2)] = eml_D_f[(eml_k_0 << 2) + i_0] +
                eml_D_4[eml_k_0 << 2] * eml_D_9[i_0];
              eml_D_f[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 1] *
                eml_D_9[i_0 + 4] + eml_D_f[(eml_k_0 << 2) + i_0];
              eml_D_f[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 2] *
                eml_D_9[i_0 + 8] + eml_D_f[(eml_k_0 << 2) + i_0];
              eml_D_f[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 3] *
                eml_D_9[i_0 + 12] + eml_D_f[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_0[eml_k_0 << 2] * eml_D[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 1] *
                eml_D[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 2] *
                eml_D[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 3] *
                eml_D[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
                eml_D_1[eml_k_0 << 2] * eml_D_8[i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_2[eml_k_0 << 2] * eml_D_9[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 1] *
                eml_D_9[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 2] *
                eml_D_9[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 3] *
                eml_D_9[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_c[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_c[(eml_k_0 << 2) + i_0] +
                eml_D_3[eml_k_0 << 2] * eml_D_8[i_0];
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_D_c[(eml_k_0 << 2) + i_0];
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_D_c[(eml_k_0 << 2) + i_0];
              eml_D_c[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_D_c[(eml_k_0 << 2) + i_0];
            }
          }

          eml_D_8[0] = 0.0;
          eml_D_8[4] = 0.0;
          eml_D_8[8] = 0.0;
          eml_D_8[12] = 0.0;
          eml_D_8[1] = 0.0;
          eml_D_8[5] = -eml_A;
          eml_D_8[9] = -eml_A_1;
          eml_D_8[13] = 0.0;
          eml_D_8[2] = 0.0;
          eml_D_8[6] = eml_A_1;
          eml_D_8[10] = -eml_A;
          eml_D_8[14] = 0.0;
          eml_D_8[3] = 0.0;
          eml_D_8[7] = 0.0;
          eml_D_8[11] = 0.0;
          eml_D_8[15] = 0.0;
          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
                eml_D_8[eml_k_0 << 2] * eml_D_c[i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + 1] *
                eml_D_c[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + 2] *
                eml_D_c[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + 3] *
                eml_D_c[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            eml_x = eml_x_2[i_0 + 12] + (eml_x_2[i_0 + 8] * 0.0 + (eml_x_2[i_0 +
              4] * 0.0 + eml_x_2[i_0] * 0.0));
            eml_x_0 = eml_D_b[i_0 + 12] + (eml_D_b[i_0 + 8] * 0.0 + (eml_D_b[i_0
              + 4] * 0.0 + eml_D_b[i_0] * 0.0));
            eml_CA = eml_D_d[i_0 + 12] + (eml_D_d[i_0 + 8] * 0.0 + (eml_D_d[i_0
              + 4] * 0.0 + eml_D_d[i_0] * 0.0));
            eml_SA = eml_D_e[i_0 + 12] + (eml_D_e[i_0 + 8] * 0.0 + (eml_D_e[i_0
              + 4] * 0.0 + eml_D_e[i_0] * 0.0));
            eml_CA_0 = eml_D_f[i_0 + 12] + (eml_D_f[i_0 + 8] * 0.0 +
              (eml_D_f[i_0 + 4] * 0.0 + eml_D_f[i_0] * 0.0));
            eml_SA_0 = eml_D_9[i_0 + 12] + (eml_D_9[i_0 + 8] * 0.0 +
              (eml_D_9[i_0 + 4] * 0.0 + eml_D_9[i_0] * 0.0));
            eml_x_3[i_0] = eml_x;
            eml_D_j[i_0] = eml_SA_0;
            eml_D_i[i_0] = eml_CA_0;
            eml_D_h[i_0] = eml_SA;
            eml_D_g[i_0] = eml_CA;
            eml_D_a[i_0] = eml_x_0;
          }

          eml_x_3[4] = eml_D_a[0];
          eml_x_3[5] = eml_D_a[1];
          eml_x_3[6] = eml_D_a[2];
          eml_x_3[7] = eml_D_a[3];
          eml_x_3[8] = eml_D_g[0];
          eml_x_3[9] = eml_D_g[1];
          eml_x_3[10] = eml_D_g[2];
          eml_x_3[11] = eml_D_g[3];
          eml_x_3[12] = eml_D_h[0];
          eml_x_3[13] = eml_D_h[1];
          eml_x_3[14] = eml_D_h[2];
          eml_x_3[15] = eml_D_h[3];
          eml_x_3[16] = eml_D_i[0];
          eml_x_3[17] = eml_D_i[1];
          eml_x_3[18] = eml_D_i[2];
          eml_x_3[19] = eml_D_i[3];
          eml_x_3[20] = eml_D_j[0];
          eml_x_3[21] = eml_D_j[1];
          eml_x_3[22] = eml_D_j[2];
          eml_x_3[23] = eml_D_j[3];
          eml_A_8[0] = eml_A_6;
          eml_A_8[3] = 0.0;
          eml_A_8[6] = -eml_A_7;
          eml_A_8[1] = 0.0;
          eml_A_8[4] = 1.0;
          eml_A_8[7] = 0.0;
          eml_A_8[2] = eml_A_7;
          eml_A_8[5] = 0.0;
          eml_A_8[8] = eml_A_6;
          eml_A_9[0] = eml_A_4;
          eml_A_9[3] = eml_A_5;
          eml_A_9[6] = 0.0;
          eml_A_9[1] = -eml_A_5;
          eml_A_9[4] = eml_A_4;
          eml_A_9[7] = 0.0;
          eml_A_9[2] = 0.0;
          eml_A_9[5] = 0.0;
          eml_A_9[8] = 1.0;
          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_A_a[i_0 + 3 * eml_k_0] = 0.0;
              eml_A_a[i_0 + 3 * eml_k_0] = eml_A_a[3 * eml_k_0 + i_0] + eml_E[3 *
                eml_k_0] * eml_A_3[i_0];
              eml_A_a[i_0 + 3 * eml_k_0] = eml_E[3 * eml_k_0 + 1] * eml_A_3[i_0
                + 3] + eml_A_a[3 * eml_k_0 + i_0];
              eml_A_a[i_0 + 3 * eml_k_0] = eml_E[3 * eml_k_0 + 2] * eml_A_3[i_0
                + 6] + eml_A_a[3 * eml_k_0 + i_0];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_D_5[i_0 + 3 * eml_k_0] = 0.0;
              eml_D_5[i_0 + 3 * eml_k_0] = eml_D_5[3 * eml_k_0 + i_0] + eml_E[3 *
                eml_k_0] * eml_A_3[i_0];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_E[3 * eml_k_0 + 1] * eml_A_3[i_0
                + 3] + eml_D_5[3 * eml_k_0 + i_0];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_E[3 * eml_k_0 + 2] * eml_A_3[i_0
                + 6] + eml_D_5[3 * eml_k_0 + i_0];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_A_b[i_0 + 3 * eml_k_0] = 0.0;
              eml_A_b[i_0 + 3 * eml_k_0] = eml_A_b[3 * eml_k_0 + i_0] + eml_E_0
                [3 * eml_k_0] * eml_D_5[i_0];
              eml_A_b[i_0 + 3 * eml_k_0] = eml_E_0[3 * eml_k_0 + 1] *
                eml_D_5[i_0 + 3] + eml_A_b[3 * eml_k_0 + i_0];
              eml_A_b[i_0 + 3 * eml_k_0] = eml_E_0[3 * eml_k_0 + 2] *
                eml_D_5[i_0 + 6] + eml_A_b[3 * eml_k_0 + i_0];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_D_5[i_0 + 3 * eml_k_0] = 0.0;
              eml_D_5[i_0 + 3 * eml_k_0] = eml_D_5[3 * eml_k_0 + i_0] + eml_E[3 *
                eml_k_0] * eml_A_3[i_0];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_E[3 * eml_k_0 + 1] * eml_A_3[i_0
                + 3] + eml_D_5[3 * eml_k_0 + i_0];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_E[3 * eml_k_0 + 2] * eml_A_3[i_0
                + 6] + eml_D_5[3 * eml_k_0 + i_0];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_D_6[i_0 + 3 * eml_k_0] = 0.0;
              eml_D_6[i_0 + 3 * eml_k_0] = eml_D_6[3 * eml_k_0 + i_0] + eml_E_0
                [3 * eml_k_0] * eml_D_5[i_0];
              eml_D_6[i_0 + 3 * eml_k_0] = eml_E_0[3 * eml_k_0 + 1] *
                eml_D_5[i_0 + 3] + eml_D_6[3 * eml_k_0 + i_0];
              eml_D_6[i_0 + 3 * eml_k_0] = eml_E_0[3 * eml_k_0 + 2] *
                eml_D_5[i_0 + 6] + eml_D_6[3 * eml_k_0 + i_0];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_A_c[i_0 + 3 * eml_k_0] = 0.0;
              eml_A_c[i_0 + 3 * eml_k_0] = eml_A_c[3 * eml_k_0 + i_0] + eml_E_1
                [3 * eml_k_0] * eml_D_6[i_0];
              eml_A_c[i_0 + 3 * eml_k_0] = eml_E_1[3 * eml_k_0 + 1] *
                eml_D_6[i_0 + 3] + eml_A_c[3 * eml_k_0 + i_0];
              eml_A_c[i_0 + 3 * eml_k_0] = eml_E_1[3 * eml_k_0 + 2] *
                eml_D_6[i_0 + 6] + eml_A_c[3 * eml_k_0 + i_0];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_D_5[i_0 + 3 * eml_k_0] = 0.0;
              eml_D_5[i_0 + 3 * eml_k_0] = eml_D_5[3 * eml_k_0 + i_0] + eml_E[3 *
                eml_k_0] * eml_A_3[i_0];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_E[3 * eml_k_0 + 1] * eml_A_3[i_0
                + 3] + eml_D_5[3 * eml_k_0 + i_0];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_E[3 * eml_k_0 + 2] * eml_A_3[i_0
                + 6] + eml_D_5[3 * eml_k_0 + i_0];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_D_6[i_0 + 3 * eml_k_0] = 0.0;
              eml_D_6[i_0 + 3 * eml_k_0] = eml_D_6[3 * eml_k_0 + i_0] + eml_E_0
                [3 * eml_k_0] * eml_D_5[i_0];
              eml_D_6[i_0 + 3 * eml_k_0] = eml_E_0[3 * eml_k_0 + 1] *
                eml_D_5[i_0 + 3] + eml_D_6[3 * eml_k_0 + i_0];
              eml_D_6[i_0 + 3 * eml_k_0] = eml_E_0[3 * eml_k_0 + 2] *
                eml_D_5[i_0 + 6] + eml_D_6[3 * eml_k_0 + i_0];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_D_7[i_0 + 3 * eml_k_0] = 0.0;
              eml_D_7[i_0 + 3 * eml_k_0] = eml_D_7[3 * eml_k_0 + i_0] + eml_E_1
                [3 * eml_k_0] * eml_D_6[i_0];
              eml_D_7[i_0 + 3 * eml_k_0] = eml_E_1[3 * eml_k_0 + 1] *
                eml_D_6[i_0 + 3] + eml_D_7[3 * eml_k_0 + i_0];
              eml_D_7[i_0 + 3 * eml_k_0] = eml_E_1[3 * eml_k_0 + 2] *
                eml_D_6[i_0 + 6] + eml_D_7[3 * eml_k_0 + i_0];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_D_5[i_0 + 3 * eml_k_0] = 0.0;
              eml_D_5[i_0 + 3 * eml_k_0] = eml_D_5[3 * eml_k_0 + i_0] + eml_E_2
                [3 * eml_k_0] * eml_D_7[i_0];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_E_2[3 * eml_k_0 + 1] *
                eml_D_7[i_0 + 3] + eml_D_5[3 * eml_k_0 + i_0];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_E_2[3 * eml_k_0 + 2] *
                eml_D_7[i_0 + 6] + eml_D_5[3 * eml_k_0 + i_0];
            }
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            eml_A_g[i_0] = eml_D_5[i_0 + 6] * 0.0 + (eml_D_5[i_0 + 3] * 0.0 +
              eml_D_5[i_0]);
            eml_A_f[i_0] = eml_A_c[i_0 + 6] * 0.0 + (eml_A_c[i_0 + 3] +
              eml_A_c[i_0] * 0.0);
            eml_A_e[i_0] = eml_A_b[i_0 + 6] * 0.0 + (eml_A_b[i_0 + 3] * 0.0 +
              eml_A_b[i_0]);
            eml_A_d[i_0] = eml_A_a[i_0 + 6] * 0.0 + (eml_A_a[i_0 + 3] +
              eml_A_a[i_0] * 0.0);
            eml_varargin[i_0] = eml_A_3[i_0 + 6] * 0.0 + (eml_A_3[i_0 + 3] +
              eml_A_3[i_0] * 0.0);
          }

          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 3; eml_k_0++) {
              eml_D_5[i_0 + 3 * eml_k_0] = 0.0;
              eml_D_5[i_0 + 3 * eml_k_0] = eml_D_5[3 * eml_k_0 + i_0] + eml_A_9
                [3 * eml_k_0] * eml_A_8[i_0];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_A_9[3 * eml_k_0 + 1] *
                eml_A_8[i_0 + 3] + eml_D_5[3 * eml_k_0 + i_0];
              eml_D_5[i_0 + 3 * eml_k_0] = eml_A_9[3 * eml_k_0 + 2] *
                eml_A_8[i_0 + 6] + eml_D_5[3 * eml_k_0 + i_0];
            }
          }

          tmp_0[0] = 0.0;
          tmp_0[1] = 0.0;
          tmp_0[2] = 1.0;
          tmp_0[3] = eml_varargin[0];
          tmp_0[4] = eml_varargin[1];
          tmp_0[5] = eml_varargin[2];
          tmp_0[6] = eml_A_d[0];
          tmp_0[7] = eml_A_d[1];
          tmp_0[8] = eml_A_d[2];
          tmp_0[9] = eml_A_e[0];
          tmp_0[10] = eml_A_e[1];
          tmp_0[11] = eml_A_e[2];
          tmp_0[12] = eml_A_f[0];
          tmp_0[13] = eml_A_f[1];
          tmp_0[14] = eml_A_f[2];
          tmp_0[15] = eml_A_g[0];
          tmp_0[16] = eml_A_g[1];
          tmp_0[17] = eml_A_g[2];
          for (i_0 = 0; i_0 < 3; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 6; eml_k_0++) {
              eml_A_h[i_0 + 3 * eml_k_0] = 0.0;
              eml_A_h[i_0 + 3 * eml_k_0] = eml_A_h[3 * eml_k_0 + i_0] + tmp_0[3 *
                eml_k_0] * eml_D_5[i_0];
              eml_A_h[i_0 + 3 * eml_k_0] = tmp_0[3 * eml_k_0 + 1] * eml_D_5[i_0
                + 3] + eml_A_h[3 * eml_k_0 + i_0];
              eml_A_h[i_0 + 3 * eml_k_0] = tmp_0[3 * eml_k_0 + 2] * eml_D_5[i_0
                + 6] + eml_A_h[3 * eml_k_0 + i_0];
            }
          }

          for (i_0 = 0; i_0 < 6; i_0++) {
            eml_x_1[6 * i_0] = eml_x_3[i_0 << 2];
            eml_x_1[1 + 6 * i_0] = eml_x_3[(i_0 << 2) + 1];
            eml_x_1[2 + 6 * i_0] = eml_x_3[(i_0 << 2) + 2];
          }

          for (i_0 = 0; i_0 < 6; i_0++) {
            eml_x_1[3 + 6 * i_0] = eml_A_h[3 * i_0];
            eml_x_1[4 + 6 * i_0] = eml_A_h[3 * i_0 + 1];
            eml_x_1[5 + 6 * i_0] = eml_A_h[3 * i_0 + 2];
          }

          M37_Sim_Forcing_003h_exp_invNxN(eml_x_1, tmp);
          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_0[eml_k_0 << 2] * eml_D[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 1] *
                eml_D[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 2] *
                eml_D[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_0[(eml_k_0 << 2) + 3] *
                eml_D[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
                eml_D_1[eml_k_0 << 2] * eml_D_8[i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_1[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_2[eml_k_0 << 2] * eml_D_9[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 1] *
                eml_D_9[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 2] *
                eml_D_9[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_2[(eml_k_0 << 2) + 3] *
                eml_D_9[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_9[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_9[(eml_k_0 << 2) + i_0] +
                eml_D_3[eml_k_0 << 2] * eml_D_8[i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 1] *
                eml_D_8[i_0 + 4] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 2] *
                eml_D_8[i_0 + 8] + eml_D_9[(eml_k_0 << 2) + i_0];
              eml_D_9[i_0 + (eml_k_0 << 2)] = eml_D_3[(eml_k_0 << 2) + 3] *
                eml_D_8[i_0 + 12] + eml_D_9[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            for (eml_k_0 = 0; eml_k_0 < 4; eml_k_0++) {
              eml_D_8[i_0 + (eml_k_0 << 2)] = 0.0;
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_8[(eml_k_0 << 2) + i_0] +
                eml_D_4[eml_k_0 << 2] * eml_D_9[i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 1] *
                eml_D_9[i_0 + 4] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 2] *
                eml_D_9[i_0 + 8] + eml_D_8[(eml_k_0 << 2) + i_0];
              eml_D_8[i_0 + (eml_k_0 << 2)] = eml_D_4[(eml_k_0 << 2) + 3] *
                eml_D_9[i_0 + 12] + eml_D_8[(eml_k_0 << 2) + i_0];
            }
          }

          for (i_0 = 0; i_0 < 4; i_0++) {
            eml_x = eml_D_8[i_0 + 12] + (eml_D_8[i_0 + 8] * 0.0 + (eml_D_8[i_0 +
              4] * 0.0 + eml_D_8[i_0] * 0.0));
            eml_D_a[i_0] = eml_x;
          }

          eml_x_p_0[0] = eml_x_p[0] - eml_D_a[0];
          eml_x_p_0[1] = eml_x_p[1] - eml_D_a[1];
          eml_x_p_0[2] = eml_x_p[2] - eml_D_a[2];
          eml_x_p_0[3] = 1.7453292519943295E-002 *
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_f
            [3] - rt_atan2_snf(eml_E_3[7], eml_E_3[8]);
          eml_x_p_0[4] = 1.7453292519943295E-002 *
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_f
            [4] - eml_eul_ang_idx;
          eml_x_p_0[5] = 1.7453292519943295E-002 *
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_f
            [5] - eml_eul_ang_idx_0;

          /* '<S140>:1:194' */
          for (i_0 = 0; i_0 < 6; i_0++) {
            eml_d_ang[i_0] = 0.0;
            for (eml_k_0 = 0; eml_k_0 < 6; eml_k_0++) {
              eml_d_ang[i_0] += tmp[6 * eml_k_0 + i_0] * eml_x_p_0[eml_k_0];
            }

            eml_ang_0[i_0] += eml_d_ang[i_0];
          }

          /* '<S140>:1:195' */
          for (eml_k_0 = 0; eml_k_0 < 6; eml_k_0++) {
            for (eml_A = eml_ang_0[eml_k_0]; eml_A > 3.1415926535897931E+000;
                 eml_A -= 6.2831853071795862E+000) {
            }

            while (eml_A < -3.1415926535897931E+000) {
              eml_A += 6.2831853071795862E+000;
            }

            eml_ang_0[eml_k_0] = eml_A;
          }

          if (M37_Sim_Forcing_003h_expe__norm(eml_d_ang) < 1.0E-006) {
            /* '<S140>:1:196' */
            /* '<S140>:1:197' */
            for (eml_k_0 = 0; eml_k_0 < 6; eml_k_0++) {
              for (eml_A = eml_ang_0[eml_k_0]; eml_A > 3.1415926535897931E+000;
                   eml_A -= 6.2831853071795862E+000) {
              }

              while (eml_A < -3.1415926535897931E+000) {
                eml_A += 6.2831853071795862E+000;
              }

              eml_ang_0[eml_k_0] = eml_A;
            }

            /* '<S140>:1:198' */
            for (i_0 = 0; i_0 < 6; i_0++) {
              eml_x = 5.7295779513082323E+001 * eml_ang_0[i_0];
              M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_a[i_0] = eml_x;
              eml_ang_0[i_0] = eml_x;
            }

            /* '<S140>:1:199' */
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_a[6] = (real_T)
              eml_k;

            /*  tests whether the links are within the set soft limits */
            eml_k_0 = 1;
            i = 2;
          } else {
            /* '<S140>:1:202' */
            eml_k++;

            /*  if more than 10 iterations, no convergence */
            if (eml_k > 10) {
              /* '<S140>:1:205' */
              /* '<S140>:1:206' */
              for (i_0 = 0; i_0 < 6; i_0++) {
                M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_a[i_0] =
                  eml_ang[i_0];
              }

              /*  return vector as is */
              /* '<S140>:1:207' */
              M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_a[6] = -1.0;
              i = 1;
            }
          }
        } while ((uint32_T)i == 0U);

        if ((uint32_T)i != 1U) {
          eml_guard = false;
          while (((uint32_T)eml_guard == 0U) && (eml_k_0 <= 6)) {
            /* '<S140>:1:213' */
            if (eml_ang_0[eml_k_0 - 1] >= (real_T)tmp_9[(eml_k_0 - 1) << 1]) {
              /* '<S140>:1:214' */
              /* '<S140>:1:215' */
              M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_a[6] = -3.0;
              eml_guard = true;
            } else if (eml_ang_0[eml_k_0 - 1] <= (real_T)tmp_9[((eml_k_0 - 1) <<
                        1) + 1]) {
              /* '<S140>:1:217' */
              /* '<S140>:1:218' */
              M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_a[6] = -3.0;
              eml_guard = true;
            } else {
              eml_k_0++;
            }
          }
        }
      }

      srUpdateBC
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.fullinversekin_SubsysRanBC);
    }

    /* end of Outputs for SubSystem: '<S135>/full inverse kin' */

    /* Switch: '<S131>/Switch' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_e >
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch_Threshold_h) {
      /* Switch: '<S136>/SwitchControl' incorporates:
       *  Constant: '<S136>/Constant'
       */
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_al >
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.SwitchControl_Threshold_h)
      {
        /* Sum: '<S138>/Sum1' */
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_a[0] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_j[
          0];
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_a[1] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[1] +
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_j[
          1];
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_a[2] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[2] +
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_j[
          2];
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_a[3] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_j[
          3];
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_a[4] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[4] +
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_j[
          4];
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_a[5] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_j[
          5];
        for (i_0 = 0; i_0 < 6; i_0++) {
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl[i_0] =
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_a[i_0];
        }

        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl[6] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[6];
      } else {
        for (i_0 = 0; i_0 < 7; i_0++) {
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl[i_0] =
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[i_0];
        }
      }

      for (i_0 = 0; i_0 < 7; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch[i_0] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl[i_0];
      }
    } else {
      for (i_0 = 0; i_0 < 7; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch[i_0] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_a[i_0];
      }
    }

    /* Sum: '<S8>/Sum2' */
    for (i_0 = 0; i_0 < 6; i_0++) {
      /* Gain: '<S137>/Gain' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum6[i_0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain_Gain_c[i_0] *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch[i_0];

      /* Sum: '<S137>/Sum' incorporates:
       *  Constant: '<S137>/Constant'
       */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_j[i_0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum6[i_0] +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_h[i_0];

      /* UnitDelay: '<S130>/Unit Delay6' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum6[i_0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay6_DSTATE[i_0];
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum2 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_j[0];

    /* Sum: '<S130>/Sum6' */
    eml_ang_0[0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum2;
    for (i_0 = 0; i_0 < 5; i_0++) {
      eml_ang_0[i_0 + 1] = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_j[1
        + i_0];
    }

    /* Sum: '<S8>/Sum1' */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_c;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ControlLoopGain[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum2 - ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_i;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ControlLoopGain[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_j[1] - ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain6;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ControlLoopGain[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_j[2] - ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_k;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ControlLoopGain[3] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_j[3] - ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_d;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ControlLoopGain[4] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_j[4] - ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_k;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ControlLoopGain[5] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_j[5] - ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);

    /* Gain: '<S8>/Gain1' incorporates:
     *  Constant: '<Root>/Gain'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_c *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain_Value;
    for (i_0 = 0; i_0 < 6; i_0++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum6[i_0] = eml_ang_0[i_0] -
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum6[i_0];

      /* Product: '<S8>/Control Loop Gain' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ControlLoopGain[i_0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ControlLoopGain[i_0] *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

      /* Sum: '<S8>/Sum' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_d[i_0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum6[i_0] +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ControlLoopGain[i_0];
    }

    /* DiscreteTransferFcn: '<S8>/Butterworth Filter 10 Hz' */
    for (i = 0; i < 6; i++) {
      eml_k_0 = i << 2;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_tmp[
        i] = ((((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_d[i] -
                 M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Denominat
                 [1] *
                 M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
                 [eml_k_0]) -
                M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
                [eml_k_0 + 1] *
                M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Denominat
                [2]) -
               M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
               [eml_k_0 + 2] *
               M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Denominat
               [3]) -
              M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
              [eml_k_0 + 3] *
              M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Denominat
              [4]) /
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Denominat
        [0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ButterworthFilter10Hz[i] =
        (((M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Numerator
           [0] *
           M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_tmp
           [i] +
           M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Numerator
           [1] *
           M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
           [eml_k_0]) +
          M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
          [eml_k_0 + 1] *
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Numerator
          [2]) +
         M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
         [eml_k_0 + 2] *
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Numerator
         [3]) +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
        [eml_k_0 + 3] *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Numerator
        [4];
    }

    /* Switch: '<Root>/Switch' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[0] >
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch_Threshold_bg) {
      for (i_0 = 0; i_0 < 6; i_0++) {
        /* Switch: '<S9>/SwitchControl' incorporates:
         *  Constant: '<S9>/Constant'
         */
        if (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_a >
            M37_Sim_Forcing_003h_expe_infra_transz_lim_P.SwitchControl_Threshold_e)
        {
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl_g[i_0] =
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ButterworthFilter10Hz[i_0];
        } else {
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl_g[i_0] =
            0.0;
        }

        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[i_0] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl_g[i_0];
      }
    } else {
      for (i_0 = 0; i_0 < 6; i_0++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[i_0] = 0.0;
      }
    }

    /* Sum: '<S47>/Add1' incorporates:
     *  Constant: '<S47>/NSEA1'
     */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_c;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.NSEA1_Value;

    /* Abs: '<S47>/Abs1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1 = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* If: '<S47>/If2' incorporates:
     *  ActionPort: '<S53>/Action Port'
     *  ActionPort: '<S54>/Action Port'
     *  SubSystem: '<S47>/If Action Subsystem'
     *  SubSystem: '<S47>/If Action Subsystem1'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[0] > 0.0) {
      /* Switch: '<S53>/Switch' incorporates:
       *  Constant: '<S53>/PSEA2'
       */
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2 >
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch_Threshold_k) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_n =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[0];
      } else {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_n =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.PSEA2_Value;
      }

      srUpdateBC
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_SubsysRanBC);
    } else {
      M37_Sim_Forc_IfActionSubsystem1
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[0],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1,
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1,
         (rtP_IfActionSubsystem1_M37_Sim_ *)
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.IfActionSubsystem1);
    }

    /* Switch: '<S47>/Switch1' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[0] != 0.0) {
      /* Switch: '<S47>/Switch' */
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[0] >
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch_Threshold_f) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_hj =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_n;
      } else {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_hj =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1.Switch;
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_n =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_hj;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_n =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[0];
    }

    /* Saturate: '<S15>/Vel Limiter A1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = rt_SATURATE
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_n,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.VelLimiterA1_LowerSat,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.VelLimiterA1_UpperSat);

    /* RateLimiter: '<S15>/Acc Limiter A1' */
    eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY;
    if (eml_x >
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA1_RisingLim) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA1 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA1_RisingLim;
    } else if (eml_x <
               M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA1_FallingLim)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA1 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA1_FallingLim;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA1 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA1;

    /* Sum: '<S48>/Add2' incorporates:
     *  Constant: '<S48>/PSEA1'
     */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_i;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.PSEA1_Value_h;

    /* Abs: '<S48>/Abs2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_b = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* Sum: '<S48>/Add1' incorporates:
     *  Constant: '<S48>/NSEA1'
     */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_i;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.NSEA1_Value_f;

    /* Abs: '<S48>/Abs1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_f = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* If: '<S48>/If2' incorporates:
     *  ActionPort: '<S55>/Action Port'
     *  ActionPort: '<S56>/Action Port'
     *  SubSystem: '<S48>/If Action Subsystem'
     *  SubSystem: '<S48>/If Action Subsystem1'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[1] > 0.0) {
      M37_Sim_Forci_IfActionSubsystem
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[1],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_b,
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_h,
         (rtP_IfActionSubsystem_M37_Sim_F *)
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.IfActionSubsystem_h);
    } else {
      M37_Sim_Forc_IfActionSubsystem1
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[1],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_f,
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_e,
         (rtP_IfActionSubsystem1_M37_Sim_ *)
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.IfActionSubsystem1_e);
    }

    /* Switch: '<S48>/Switch1' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[1] != 0.0) {
      /* Switch: '<S48>/Switch' */
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[1] >=
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch_Threshold_e) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_p =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_h.Switch;
      } else {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_p =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_e.Switch;
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_c =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_p;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_c =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[1];
    }

    /* Saturate: '<S15>/Vel Limiter A2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = rt_SATURATE
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_c,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.VelLimiterA2_LowerSat,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.VelLimiterA2_UpperSat);

    /* RateLimiter: '<S15>/Acc Limiter A2' */
    eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_j;
    if (eml_x >
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA2_RisingLim) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA2 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_j +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA2_RisingLim;
    } else if (eml_x <
               M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA2_FallingLim)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA2 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_j +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA2_FallingLim;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA2 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_j =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA2;

    /* Sum: '<S49>/Add2' incorporates:
     *  Constant: '<S49>/PSEA1'
     */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain6;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.PSEA1_Value_k;

    /* Abs: '<S49>/Abs2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_bs = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* Sum: '<S49>/Add1' incorporates:
     *  Constant: '<S49>/NSEA1'
     */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain6;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.NSEA1_Value_k;

    /* Abs: '<S49>/Abs1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_e = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* If: '<S49>/If2' incorporates:
     *  ActionPort: '<S57>/Action Port'
     *  ActionPort: '<S58>/Action Port'
     *  SubSystem: '<S49>/If Action Subsystem'
     *  SubSystem: '<S49>/If Action Subsystem1'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[2] > 0.0) {
      M37_Sim_Forci_IfActionSubsystem
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[2],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_bs,
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_c,
         (rtP_IfActionSubsystem_M37_Sim_F *)
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.IfActionSubsystem_c);
    } else {
      M37_Sim_Forc_IfActionSubsystem1
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[2],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_e,
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_h,
         (rtP_IfActionSubsystem1_M37_Sim_ *)
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.IfActionSubsystem1_h);
    }

    /* Switch: '<S49>/Switch1' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[2] != 0.0) {
      /* Switch: '<S49>/Switch' */
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[2] >=
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch_Threshold_b) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_kx =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_c.Switch;
      } else {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_kx =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_h.Switch;
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_nz =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_kx;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_nz =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[2];
    }

    /* Saturate: '<S15>/Vel Limiter A3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = rt_SATURATE
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_nz,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.VelLimiterA3_LowerSat,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.VelLimiterA3_UpperSat);

    /* RateLimiter: '<S15>/Acc Limiter A3' */
    eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_f;
    if (eml_x >
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA3_RisingLim) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA3 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_f +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA3_RisingLim;
    } else if (eml_x <
               M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA3_FallingLim)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA3 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_f +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA3_FallingLim;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA3 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_f =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA3;

    /* Sum: '<S50>/Add2' incorporates:
     *  Constant: '<S50>/PSEA1'
     */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_k;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.PSEA1_Value_j;

    /* Abs: '<S50>/Abs2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_l = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* Sum: '<S50>/Add1' incorporates:
     *  Constant: '<S50>/NSEA1'
     */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_k;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.NSEA1_Value_d;

    /* Abs: '<S50>/Abs1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_j = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* If: '<S50>/If2' incorporates:
     *  ActionPort: '<S59>/Action Port'
     *  ActionPort: '<S60>/Action Port'
     *  SubSystem: '<S50>/If Action Subsystem'
     *  SubSystem: '<S50>/If Action Subsystem1'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[3] > 0.0) {
      M37_Sim_Forci_IfActionSubsystem
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[3],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_l,
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_m,
         (rtP_IfActionSubsystem_M37_Sim_F *)
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.IfActionSubsystem_m);
    } else {
      M37_Sim_Forc_IfActionSubsystem1
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[3],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_j,
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_n,
         (rtP_IfActionSubsystem1_M37_Sim_ *)
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.IfActionSubsystem1_n);
    }

    /* Switch: '<S50>/Switch1' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[3] != 0.0) {
      /* Switch: '<S50>/Switch' */
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[3] >=
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch_Threshold_d) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_i =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_m.Switch;
      } else {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_i =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_n.Switch;
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_h =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_i;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_h =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[3];
    }

    /* Saturate: '<S15>/Vel Limiter A4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = rt_SATURATE
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_h,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.VelLimiterA4_LowerSat,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.VelLimiterA4_UpperSat);

    /* RateLimiter: '<S15>/Acc Limiter A4' */
    eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_o;
    if (eml_x >
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA4_RisingLim) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA4 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_o +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA4_RisingLim;
    } else if (eml_x <
               M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA4_FallingLim)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA4 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_o +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA4_FallingLim;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA4 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_o =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA4;

    /* Sum: '<S51>/Add2' incorporates:
     *  Constant: '<S51>/PSEA1'
     */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_d;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.PSEA1_Value_p;

    /* Abs: '<S51>/Abs2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_a = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* Sum: '<S51>/Add1' incorporates:
     *  Constant: '<S51>/NSEA1'
     */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_d;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.NSEA1_Value_l;

    /* Abs: '<S51>/Abs1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_i = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* If: '<S51>/If2' incorporates:
     *  ActionPort: '<S61>/Action Port'
     *  ActionPort: '<S62>/Action Port'
     *  SubSystem: '<S51>/If Action Subsystem'
     *  SubSystem: '<S51>/If Action Subsystem1'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[4] > 0.0) {
      M37_Sim_Forci_IfActionSubsystem
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[4],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_a,
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_n,
         (rtP_IfActionSubsystem_M37_Sim_F *)
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.IfActionSubsystem_n);
    } else {
      M37_Sim_Forc_IfActionSubsystem1
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[4],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_i,
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_p,
         (rtP_IfActionSubsystem1_M37_Sim_ *)
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.IfActionSubsystem1_p);
    }

    /* Switch: '<S51>/Switch1' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[4] != 0.0) {
      /* Switch: '<S51>/Switch' */
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[4] >=
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch_Threshold_i) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_h =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_n.Switch;
      } else {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_h =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_p.Switch;
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_l =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_h;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_l =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[4];
    }

    /* Saturate: '<S15>/Vel Limiter3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = rt_SATURATE
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_l,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.VelLimiter3_LowerSat,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.VelLimiter3_UpperSat);

    /* RateLimiter: '<S15>/Acc Limiter A5' */
    eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_l;
    if (eml_x >
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA5_RisingLim) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA5 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_l +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA5_RisingLim;
    } else if (eml_x <
               M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA5_FallingLim)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA5 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_l +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA5_FallingLim;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA5 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_l =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA5;

    /* Sum: '<S52>/Add2' incorporates:
     *  Constant: '<S52>/PSEA1'
     */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_k;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.PSEA1_Value_h0;

    /* Abs: '<S52>/Abs2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_lm = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* Sum: '<S52>/Add1' incorporates:
     *  Constant: '<S52>/NSEA1'
     */
    tmp_3 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_k;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.NSEA1_Value_kl;

    /* Abs: '<S52>/Abs1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_o = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a);

    /* If: '<S52>/If2' incorporates:
     *  ActionPort: '<S63>/Action Port'
     *  ActionPort: '<S64>/Action Port'
     *  SubSystem: '<S52>/If Action Subsystem'
     *  SubSystem: '<S52>/If Action Subsystem1'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[5] > 0.0) {
      M37_Sim_Forci_IfActionSubsystem
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[5],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_lm,
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_p,
         (rtP_IfActionSubsystem_M37_Sim_F *)
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.IfActionSubsystem_p);
    } else {
      M37_Sim_Forc_IfActionSubsystem1
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[5],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_o,
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_n5,
         (rtP_IfActionSubsystem1_M37_Sim_ *)
         &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.IfActionSubsystem1_n5);
    }

    /* Switch: '<S52>/Switch1' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[5] != 0.0) {
      /* Switch: '<S52>/Switch' */
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[5] >=
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Switch_Threshold_a) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_k =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_p.Switch;
      } else {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_k =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_n5.Switch;
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_j =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_k;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_j =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[5];
    }

    /* Saturate: '<S15>/Vel Limiter6' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = rt_SATURATE
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_j,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.VelLimiter6_LowerSat,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_P.VelLimiter6_UpperSat);

    /* RateLimiter: '<S15>/Acc Limiter A6' */
    eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_i;
    if (eml_x >
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA6_RisingLim) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA6 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_i +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA6_RisingLim;
    } else if (eml_x <
               M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA6_FallingLim)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA6 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_i +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA6_FallingLim;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA6 =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA6;

    /* Gain: '<S13>/Gain' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_ju =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain_Gain_a *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA1;

    /* Gain: '<S13>/Gain1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_e *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA2;

    /* Gain: '<S13>/Gain2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_k *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA3;

    /* Gain: '<S13>/Gain3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_i *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA4;

    /* Gain: '<S13>/Gain4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA5;

    /* Gain: '<S13>/Gain5' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain5 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain5_Gain *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA6;

    /* If: '<S13>/If' incorporates:
     *  ActionPort: '<S22>/Action Port'
     *  SubSystem: '<S13>/If Action Subsystem1'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o5) {
      /* Gain: '<S23>/Gain1' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_d *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_ju;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_e = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S29>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_ju, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent);

      /* Gain: '<S23>/Gain2' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_mq *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_j = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S30>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_ju, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_h);

      /* Gain: '<S23>/Gain3' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_g *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_c = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S31>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_ju, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_n);

      /* Gain: '<S23>/Gain4' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_e *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_f = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* Gain: '<S24>/Gain1' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_i *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_i;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_n = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S32>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_i, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_o);

      /* Gain: '<S24>/Gain2' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_me *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_d = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S33>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_i, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_ng);

      /* Gain: '<S24>/Gain3' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_m *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_m = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S34>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_i, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_on);

      /* Gain: '<S24>/Gain4' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_p4 *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_l = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* Level2 S-Function Block: '<S22>/GT-RT CAN TX' (gt_rt_can_send) */
      {
        SimStruct *rts =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[2];
        sfcnOutputs(rts, 0);
      }

      /* Gain: '<S25>/Gain1' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_o *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_n;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_nr = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S35>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_n, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_hw);

      /* Gain: '<S25>/Gain2' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_n *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_da = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S36>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_n, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_a);

      /* Gain: '<S25>/Gain3' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_n *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_dw = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S37>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_n, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_hj);

      /* Gain: '<S25>/Gain4' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_o *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_kd = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* Gain: '<S26>/Gain1' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_gi *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_f = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S38>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_i);

      /* Gain: '<S26>/Gain2' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_o *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_a = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S39>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_k);

      /* Gain: '<S26>/Gain3' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_l *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_n = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S40>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_ap);

      /* Gain: '<S26>/Gain4' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_h *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_k1 = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* Level2 S-Function Block: '<S22>/GT-RT CAN TX1' (gt_rt_can_send) */
      {
        SimStruct *rts =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[3];
        sfcnOutputs(rts, 0);
      }

      /* Gain: '<S27>/Gain1' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_f0 *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_a = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S41>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_m);

      /* Gain: '<S27>/Gain2' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_p *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_f = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S42>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_p);

      /* Gain: '<S27>/Gain3' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_i0 *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_d1 = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S43>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_kw);

      /* Gain: '<S27>/Gain4' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_a *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_j = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* Gain: '<S28>/Gain1' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_pw *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain5;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_c = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S44>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain5, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_oo);

      /* Gain: '<S28>/Gain2' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_jh *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_dk = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S45>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain5, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_h1);

      /* Gain: '<S28>/Gain3' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_d *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_fg = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* ArithShift: '<S46>/shift' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = ldexp
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain5, (int32_T)
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.shift_Power2Exponent_g);

      /* Gain: '<S28>/Gain4' */
      eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_l *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift;
      if (rtIsNaN(eml_x) || rtIsInf(eml_x)) {
        eml_x = 0.0;
      } else {
        eml_x = fmod(floor(eml_x), 256.0);
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_kf = eml_x < 0.0 ?
        (uint8_T)(int8_T)(-((int8_T)(uint8_T)(-eml_x))) : (uint8_T)eml_x;

      /* Level2 S-Function Block: '<S22>/GT-RT CAN TX2' (gt_rt_can_send) */
      {
        SimStruct *rts =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[4];
        sfcnOutputs(rts, 0);
      }

      srUpdateBC
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_SubsysRanBC);
    }

    /* SampleTimeMath: '<S79>/TSamp' */
    /* y = u * K where K = 1 / ( w * Ts )
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_g
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TSamp_WtEt;

    /* UnitDelay: '<S79>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE;

    /* Sum: '<S79>/Diff' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Product: '<S78>/Product' incorporates:
     *  Constant: '<S66>/Constant2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_c *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Gain: '<S78>/(zeta*T_transfer)//pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetaT_transferpi_Gain *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Sum: '<S78>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_l;

    /* DiscreteIntegrator: '<S78>/4*zeta*pi//T_transfer //s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi;
    }

    if (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] > 0) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetStat
          <= 0)) || ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4]
                      <= 0) &&
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetStat
                      == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE;

    /* Sum: '<S78>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n;

    /* Product: '<S78>/Divide' incorporates:
     *  Constant: '<S66>/Constant2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_c;

    /* Gain: '<S78>/4*zeta*pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Product: '<S78>/Divide1' incorporates:
     *  Constant: '<S66>/Constant2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_c;

    /* Gain: '<S78>/pi//zeta' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n;

    /* SampleTimeMath: '<S83>/TSamp' */
    /* y = u * K where K = 1 / ( w * Ts )
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_j =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_p
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TSamp_WtEt_h;

    /* UnitDelay: '<S83>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_f;

    /* Sum: '<S83>/Diff' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_j -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Product: '<S82>/Product' incorporates:
     *  Constant: '<S66>/Constant2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_c *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Gain: '<S82>/(zeta*T_transfer)//pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_g =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetaT_transferpi_Gain_l *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Sum: '<S82>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_e;

    /* DiscreteIntegrator: '<S82>/4*zeta*pi//T_transfer //s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_j)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_j
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_g;
    }

    if (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] > 0) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_l
          <= 0)) || ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4]
                      <= 0) &&
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_l
                      == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_j
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_g;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_j;

    /* Sum: '<S82>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n;

    /* Product: '<S82>/Divide' incorporates:
     *  Constant: '<S66>/Constant2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_c;

    /* Gain: '<S82>/4*zeta*pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain_j *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Product: '<S82>/Divide1' incorporates:
     *  Constant: '<S66>/Constant2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_c;

    /* Gain: '<S82>/pi//zeta' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_f =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain_b *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n;

    /* SampleTimeMath: '<S87>/TSamp' */
    /* y = u * K where K = 1 / ( w * Ts )
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_o =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_d
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TSamp_WtEt_g;

    /* UnitDelay: '<S87>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_n;

    /* Sum: '<S87>/Diff' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_o -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Product: '<S86>/Product' incorporates:
     *  Constant: '<S66>/Constant2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_c *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Gain: '<S86>/(zeta*T_transfer)//pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetaT_transferpi_Gain_j *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Sum: '<S86>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_b;

    /* DiscreteIntegrator: '<S86>/4*zeta*pi//T_transfer //s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_p)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_k
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_d;
    }

    if (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] > 0) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_g
          <= 0)) || ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4]
                      <= 0) &&
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_g
                      == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_k
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_d;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_k;

    /* Sum: '<S86>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n;

    /* Product: '<S86>/Divide' incorporates:
     *  Constant: '<S66>/Constant2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_c;

    /* Gain: '<S86>/4*zeta*pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_l =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain_g *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Product: '<S86>/Divide1' incorporates:
     *  Constant: '<S66>/Constant2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_c;

    /* Gain: '<S86>/pi//zeta' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_o =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain_a *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n;

    /* MultiPortSwitch: '<S71>/Multiport Switch' incorporates:
     *  Constant: '<S71>/target_offset'
     *  Constant: '<S71>/target_offset2'
     */
    if ((int32_T)M37_Sim_Forcing_003h_expe_infra_transz_lim_B.xytoz == 0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.target_offset2_Value[0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.target_offset2_Value[1];
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.target_offset_Value[0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.target_offset_Value[1];
    }

    /* Constant: '<S71>/Constant3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant3_g =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_f;

    /* Embedded MATLAB: '<S71>/Embedded MATLAB Function3' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/compute_offset/Embedded MATLAB Function3': '<S121>:1' */
    /* '<S121>:1:3' */
    eml_x = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch[0] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_f[0];
    eml_x_0 = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch[1] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_f[1];

    /* '<S121>:1:5' */
    eml_varargin_0[0] = fabs(eml_x);
    eml_varargin_0[1] = fabs(eml_x_0);
    eml_x = eml_varargin_0[0];
    i = 1;
    eml_k = 1;
    eml_guard = false;
    if (rtIsNaN(eml_varargin_0[0])) {
      eml_searchingForNonNaN = true;
      eml_k = 2;
      if (!rtIsNaN(eml_varargin_0[1])) {
        eml_x = eml_varargin_0[1];
        i = 2;
        eml_searchingForNonNaN = false;
      }

      if (!eml_searchingForNonNaN) {
        eml_guard = true;
      }
    } else {
      eml_guard = true;
    }

    if (eml_guard) {
      for (i++; i < 3; i = 3) {
        eml_k++;
        if (eml_varargin_0[eml_k - 1] > eml_x) {
          eml_x = eml_varargin_0[eml_k - 1];
        }
      }
    }

    if (eml_x > M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant3_g) {
      /* '<S121>:1:7' */
      /* '<S121>:1:8' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.status = 0.0;
    } else {
      /* '<S121>:1:10' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.status = 1.0;
    }

    /* Logic: '<S93>/Logical Operator' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator4 &&
       M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_h &&
       (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.status != 0.0));

    /* Logic: '<S93>/Logical Operator8' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator8 =
      !M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator;

    /* Switch: '<S94>/Switch3' incorporates:
     *  Constant: '<S94>/Constant10'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator2) {
      /* Switch: '<S69>/Switch' incorporates:
       *  Constant: '<S69>/Constant'
       */
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f != 0.0) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_l[0] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_j[0];
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_l[1] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_j[1];
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_l[2] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_j[2];
      } else {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_l[0] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_n[0];
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_l[1] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_n[1];
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_l[2] =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_n[2];
      }

      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch3[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_l[0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch3[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_l[1];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch3[2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_l[2];
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch3[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant10_Value[0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch3[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant10_Value[1];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch3[2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant10_Value[2];
    }

    /* Product: '<S94>/Product' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_m[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gain *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_m[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction2_j.gain
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_m[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction5.gain
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[2];

    /* Constant: '<S94>/Constant9' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant9 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant9_Value;

    /* UnitDelay: '<S94>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_j[0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_j[1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_j[2];

    /* Switch: '<S94>/Switch1' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator3) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y_h;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction2_j.y;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction5.y;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[1];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[2];
    }

    /* Embedded MATLAB: '<S94>/Embedded MATLAB Function3' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Move_cabin/expe_phase/Embedded MATLAB Function3': '<S98>:1' */
    /* abs_yaw=abs(com_or(1))+abs(com_or(2))+abs(com_or(3))+abs(com_or(4)); */
    /* '<S98>:1:4' */
    eml_varargin_1[0] = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[0]);
    eml_varargin_1[1] = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[1]);
    eml_varargin_1[2] = fabs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[2]);
    eml_x = eml_varargin_1[0];
    eml_k = 1;
    i = 1;
    eml_guard = false;
    if (rtIsNaN(eml_varargin_1[0])) {
      eml_searchingForNonNaN = true;
      eml_k_0 = 2;
      eml_exitg = false;
      while (((uint32_T)eml_exitg == 0U) && (eml_k_0 < 4)) {
        i++;
        if (!rtIsNaN(eml_varargin_1[i - 1])) {
          eml_x = eml_varargin_1[i - 1];
          eml_k = eml_k_0;
          eml_searchingForNonNaN = false;
          eml_exitg = true;
        } else {
          eml_k_0++;
        }
      }

      if (!eml_searchingForNonNaN) {
        eml_guard = true;
      }
    } else {
      eml_guard = true;
    }

    if (eml_guard) {
      for (eml_k++; eml_k < 4; eml_k++) {
        i++;
        if (eml_varargin_1[i - 1] > eml_x) {
          eml_x = eml_varargin_1[i - 1];
        }
      }
    }

    if (eml_x > M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant9) {
      /* '<S98>:1:6' */
      /* T=max_tilt/2; */
      /* '<S98>:1:8' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.T = eml_x / 3.0;
    } else {
      /* '<S98>:1:10' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.T = 7.0;

      /* note: threshold should be 21 */
      /* T=10; %note: threshold should be 20 */
    }

    /* Fcn: '<S94>/Fcn' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_m[1];

    /* Fcn: '<S94>/Fcn1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Fcn1 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_m[0];

    /* Fcn: '<S94>/Fcn2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_m[2];

    /* Switch: '<S94>/Switch2' incorporates:
     *  Constant: '<S94>/Constant1'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) {
      /* Saturate: '<S94>/Limit to +-1' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Limitto1[0] = rt_SATURATE
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1_p[0],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Limitto1_LowerSat,
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Limitto1_UpperSat);
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[0] = (real_T)
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Limitto1[0];

      /* Saturate: '<S94>/Limit to +-1' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Limitto1[1] = rt_SATURATE
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1_p[1],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Limitto1_LowerSat,
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Limitto1_UpperSat);
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[1] = (real_T)
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Limitto1[1];

      /* Saturate: '<S94>/Limit to +-1' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Limitto1[2] = rt_SATURATE
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1_p[2],
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Limitto1_LowerSat,
         M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Limitto1_UpperSat);
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[2] = (real_T)
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Limitto1[2];
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant1_Value_n[0];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant1_Value_n[1];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant1_Value_n[2];
    }

    /* Gain: '<S94>/Gain2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_g *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_g *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain2_Gain_g *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[2];

    /* Gain: '<S94>/Gain1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_g *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[0];

    /* Gain: '<S94>/Gain3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_o =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain3_Gain_f *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[1];

    /* Gain: '<S94>/Gain4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_c =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain4_Gain_p *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[2];

    /* DiscreteIntegrator: '<S105>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_lu =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_e;

    /* Sum: '<S100>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Fcn1 +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a;

    /* Sum: '<S105>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_lu;

    /* DiscreteIntegrator: '<S105>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_kq;

    /* Sum: '<S105>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;

    /* Product: '<S105>/Divide' incorporates:
     *  Constant: '<S100>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_d;

    /* Gain: '<S105>/4*zeta*pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_c =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain_k *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a;

    /* Product: '<S105>/Divide1' incorporates:
     *  Constant: '<S100>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_d;

    /* Gain: '<S105>/pi//zeta' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_k =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain_f *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;

    /* Switch: '<S100>/Switch' incorporates:
     *  Constant: '<S100>/Constant2'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_co;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.T;
    }

    /* SampleTimeMath: '<S107>/TSamp' */
    /* y = u * K where K = 1 / ( w * Ts )
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_f =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityunt
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TSamp_WtEt_e;

    /* UnitDelay: '<S107>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_h;

    /* Sum: '<S107>/Diff' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_f -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a;

    /* Product: '<S106>/Product' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a;

    /* Gain: '<S106>/(zeta*T_transfer)//pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_e =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetaT_transferpi_Gain_c *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a;

    /* Sum: '<S106>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5 -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers;

    /* DiscreteIntegrator: '<S106>/4*zeta*pi//T_transfer //s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_m)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_g
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_e;
    }

    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5 &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetS_lc
          <= 0)) ||
        ((!M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetS_lc
          == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_g
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_e;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_g;

    /* Sum: '<S106>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* Product: '<S106>/Divide' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;

    /* Gain: '<S106>/4*zeta*pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_lp =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain_b *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a;

    /* Product: '<S106>/Divide1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;

    /* Gain: '<S106>/pi//zeta' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_p =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain_c *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* DiscreteIntegrator: '<S108>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_in =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_d2;

    /* Sum: '<S101>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_o;

    /* Sum: '<S108>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_in;

    /* DiscreteIntegrator: '<S108>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_gb;

    /* Sum: '<S108>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* Product: '<S108>/Divide' incorporates:
     *  Constant: '<S101>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_l;

    /* Gain: '<S108>/4*zeta*pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_b =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain_n *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Product: '<S108>/Divide1' incorporates:
     *  Constant: '<S101>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_l;

    /* Gain: '<S108>/pi//zeta' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_l =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain_n *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* Switch: '<S101>/Switch' incorporates:
     *  Constant: '<S101>/Constant3'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_nd;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.T;
    }

    /* SampleTimeMath: '<S110>/TSamp' */
    /* y = u * K where K = 1 / ( w * Ts )
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_n
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TSamp_WtEt_k;

    /* UnitDelay: '<S110>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_e;

    /* Sum: '<S110>/Diff' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_n -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;

    /* Product: '<S109>/Product' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;

    /* Gain: '<S109>/(zeta*T_transfer)//pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_l =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetaT_transferpi_Gain_p *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;

    /* Sum: '<S109>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5 -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_f;

    /* DiscreteIntegrator: '<S109>/4*zeta*pi//T_transfer //s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_c)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_gu
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_l;
    }

    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5 &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_e
          <= 0)) ||
        ((!M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_e
          == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_gu
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_l;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_gu;

    /* Sum: '<S109>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* Product: '<S109>/Divide' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* Gain: '<S109>/4*zeta*pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_p =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain_n1 *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;

    /* Product: '<S109>/Divide1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* Gain: '<S109>/pi//zeta' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_kx =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain_d *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a;

    /* DiscreteIntegrator: '<S111>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_p =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_c;

    /* Sum: '<S102>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_c;

    /* Sum: '<S111>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_p;

    /* DiscreteIntegrator: '<S111>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_e;

    /* Sum: '<S111>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* Product: '<S111>/Divide' incorporates:
     *  Constant: '<S102>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_kc;

    /* Gain: '<S111>/4*zeta*pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain_i *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n;

    /* Product: '<S111>/Divide1' incorporates:
     *  Constant: '<S102>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_kc;

    /* Gain: '<S111>/pi//zeta' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_k5 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain_b1 *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* Switch: '<S102>/Switch' incorporates:
     *  Constant: '<S102>/Constant3'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_a;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.T;
    }

    /* SampleTimeMath: '<S113>/TSamp' */
    /* y = u * K where K = 1 / ( w * Ts )
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_o
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TSamp_WtEt_c;

    /* UnitDelay: '<S113>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_g;

    /* Sum: '<S113>/Diff' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_i -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;

    /* Product: '<S112>/Product' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;

    /* Gain: '<S112>/(zeta*T_transfer)//pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_f =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetaT_transferpi_Gain_h *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;

    /* Sum: '<S112>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d = (real_T)
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5 -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_j;

    /* DiscreteIntegrator: '<S112>/4*zeta*pi//T_transfer //s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_n)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_f
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_f;
    }

    if ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5 &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_a
          <= 0)) ||
        ((!M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_a
          == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_f
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_f;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_c =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_f;

    /* Sum: '<S112>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_c;

    /* Product: '<S112>/Divide' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* Gain: '<S112>/4*zeta*pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_m =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain_gm *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;

    /* Product: '<S112>/Divide1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_c =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_c /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* Gain: '<S112>/pi//zeta' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_c =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain_k *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_c;

    /* Sum: '<S103>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch3[0] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[0];

    /* DiscreteIntegrator: '<S103>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a
      [0];

    /* Sum: '<S103>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[0] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[0];

    /* Product: '<S103>/Divide' incorporates:
     *  Constant: '<S94>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[0] /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_i;

    /* Gain: '<S103>/4*zeta*pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_a4[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain_bz *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[0];

    /* Product: '<S103>/Divide1' incorporates:
     *  Constant: '<S94>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[0] /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_i;

    /* Gain: '<S103>/pi//zeta' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_ck[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain_o *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[0];

    /* Sum: '<S103>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch3[1] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[1];

    /* DiscreteIntegrator: '<S103>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a
      [1];

    /* Sum: '<S103>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[1] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[1];

    /* Product: '<S103>/Divide' incorporates:
     *  Constant: '<S94>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[1] /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_i;

    /* Gain: '<S103>/4*zeta*pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_a4[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain_bz *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[1];

    /* Product: '<S103>/Divide1' incorporates:
     *  Constant: '<S94>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[1] /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_i;

    /* Gain: '<S103>/pi//zeta' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_ck[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain_o *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[1];

    /* Sum: '<S103>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch3[2] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[2];

    /* DiscreteIntegrator: '<S103>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a
      [2];

    /* Sum: '<S103>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[2] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[2];

    /* Product: '<S103>/Divide' incorporates:
     *  Constant: '<S94>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[2] /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_i;

    /* Gain: '<S103>/4*zeta*pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_a4[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain_bz *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[2];

    /* Product: '<S103>/Divide1' incorporates:
     *  Constant: '<S94>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[2] /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_i;

    /* Gain: '<S103>/pi//zeta' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_ck[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain_o *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[2];

    /* Logic: '<S70>/Logical Operator10' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator10 =
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_o != 0);

    /* SampleTimeMath: '<S123>/TSamp' */
    /* y = u * K where K = 1 / ( w * Ts )
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_g =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_m
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TSamp_WtEt_e2;

    /* UnitDelay: '<S123>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_o;

    /* Sum: '<S123>/Diff' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_g -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* Product: '<S122>/Product' incorporates:
     *  Constant: '<S71>/Constant2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_i *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* Gain: '<S122>/(zeta*T_transfer)//pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_de =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetaT_transferpi_Gain_lo *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* Sum: '<S122>/Sum2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_i;

    /* DiscreteIntegrator: '<S122>/4*zeta*pi//T_transfer //s' */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_e)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_l
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_de;
    }

    if (((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state > 0.0) &&
         (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_n
          <= 0)) || ((M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state
                      <= 0.0) &&
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_n
                      == 1))) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_l
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_de;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_l;

    /* Sum: '<S122>/Sum1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;

    /* Product: '<S122>/Divide' incorporates:
     *  Constant: '<S71>/Constant2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_i;

    /* Gain: '<S122>/4*zeta*pi' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_k =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapi_Gain_c *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i;

    /* Product: '<S122>/Divide1' incorporates:
     *  Constant: '<S71>/Constant2'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d /
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_i;

    /* Gain: '<S122>/pi//zeta' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizeta_Gain_j *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d;
    for (i_0 = 0; i_0 < 6; i_0++) {
      /* Gain: '<S135>/Gain' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_jv[i_0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain_Gain_n *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[i_0];

      /* Gain: '<S138>/Gain1' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_o[i_0] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Gain1_Gain_k *
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_j[i_0];
    }

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Kuka_start_pos'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_k[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[0] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Kuka_start_pos_Value[0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_k[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[1] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Kuka_start_pos_Value[1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_k[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[2] -
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Kuka_start_pos_Value[2];

    /* Level2 S-Function Block: '<S7>/GT-RT CAN RX2' (gt_rt_can_receive) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[18];
      sfcnOutputs(rts, 0);
    }

    /* If: '<S7>/If' incorporates:
     *  ActionPort: '<S128>/Action Port'
     *  SubSystem: '<S7>/If Action Subsystem1'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o5_d) {
      /* Level2 S-Function Block: '<S128>/GT-RT CAN TX' (gt_rt_can_send) */
      {
        SimStruct *rts =
          M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[10];
        sfcnOutputs(rts, 0);
      }

      srUpdateBC
        (M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_SubsysRanB_o);
    }

    /* Level2 S-Function Block: '<Root>/GT-RT CAN Controller' (gt_rt_can_controller) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[19];
      sfcnOutputs(rts, 0);
    }
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void M37_Sim_Forcing_003h_expe_infra_transz_lim_update(int_T tid)
{
  {
    int32_T k;
    int32_T memOffset;

    /* Update for UnitDelay: '<S69>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c0 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator;

    /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTATE
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator1_gainval
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_lu +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTATE;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_c) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevRes
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevRes
        = 0;
    }

    /* Update for UnitDelay: '<S70>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator10;

    /* Update for DiscreteIntegrator: '<S70>/Discrete-Time Integrator2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator2_DSTATE
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator2_gainval
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator2_DSTATE;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay1_f) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator2_PrevRes
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator2_PrevRes
        = 0;
    }

    /* Update for UnitDelay: '<S70>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_b =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator10;

    /* Update for DiscreteIntegrator: '<S70>/Discrete-Time Integrator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_f
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator1_gainv_m
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_f;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_e) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_b
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_b
        = 0;
    }

    /* Update for UnitDelay: '<S70>/Unit Delay4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay4_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1;

    /* Update for UnitDelay: '<S72>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.endOffile_out;

    /* Update for UnitDelay: '<S106>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityunt
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers;

    /* Update for DiscreteIntegrator: '<S106>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_p +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetStat
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetStat
        = 0;
    }

    /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_o
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator1_gain_mo
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_in +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_o;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_c) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_a
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_a
        = 0;
    }

    /* Update for UnitDelay: '<S109>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_g
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_f;

    /* Update for DiscreteIntegrator: '<S109>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_j
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_h =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval_g *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_kx +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_h;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_b
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_b
        = 0;
    }

    /* Update for UnitDelay: '<S94>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y_h;

    /* Update for UnitDelay: '<S94>/Unit Delay2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay2_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction2_j.y;

    /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_n
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator1_gainv_n
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_p +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_n;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_c) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_n
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_n
        = 0;
    }

    /* Update for UnitDelay: '<S112>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_b
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_j;

    /* Update for DiscreteIntegrator: '<S112>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_i
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_l =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval_o *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_c +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_l;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_i
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_i
        = 0;
    }

    /* Update for UnitDelay: '<S94>/Unit Delay3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay3_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction5.y;

    /* Update for UnitDelay: '<S93>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c1 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator8;

    /* Update for UnitDelay: '<S71>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_b =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state;

    /* Update for UnitDelay: '<S71>/Unit Delay2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay2_DSTATE_h =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.xytoz;

    /* Update for UnitDelay: '<S122>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_m
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_i;

    /* Update for DiscreteIntegrator: '<S122>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_d
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_g =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval_k *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_a +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_g;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state > 0.0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_f
        = 1;
    } else if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state < 0.0)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_f
        = -1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_f
        = 0;
    }

    /* Update for enable SubSystem: '<S3>/Move UP1' incorporates:
     *  Constant: '<S3>/Constant3'
     *  Update for EnablePort: '<S68>/Enable'
     */
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_o > 0.0) {
      /* Update for UnitDelay: '<S88>/For saving position  and velocity until after switchover' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_d
        = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_g;

      /* Update for UnitDelay: '<S91>/UD' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_p =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_o3;

      /* Update for DiscreteIntegrator: '<S88>/pi//(zeta*T_transfer)//s' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_o
        = 0U;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_f
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval_p
        * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_b +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_f;
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[1] > 0) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetS_ot
          = 1;
      } else {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetS_ot
          = 0;
      }

      /* Update for DiscreteIntegrator: '<S88>/4*zeta*pi//T_transfer //s' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_mw
        = 0U;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_jy
        =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval_mg
        * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_la +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_jy;
      if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[1] > 0) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetS_nn
          = 1;
      } else {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetS_nn
          = 0;
      }
    }

    /* end of Update for SubSystem: '<S3>/Move UP1' */

    /* Update for UnitDelay: '<S75>/Unit Delay' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n;

    /* Update for UnitDelay: '<S75>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_e =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MathFunction;

    /* Update for DiscreteIntegrator: '<S75>/1//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_IC_LOADING = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.s_gainval *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4 +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Compare > 0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_PrevResetState = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_PrevResetState = 0;
    }

    /* Update for UnitDelay: '<S86>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_c
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_b;

    /* Update for DiscreteIntegrator: '<S86>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_iq
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval_l *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_o +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_d;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] > 0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_o
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_o
        = 0;
    }

    /* Update for UnitDelay: '<S73>/Unit Delay' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_e =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n;

    /* Update for UnitDelay: '<S73>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_g =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MathFunction_f;

    /* Update for DiscreteIntegrator: '<S73>/1//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_IC_LOADING_d = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.s_gainval_b *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_a +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE_i;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Compare_c > 0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_PrevResetState_k = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_PrevResetState_k = 0;
    }

    /* Update for UnitDelay: '<S78>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_a
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_l;

    /* Update for DiscreteIntegrator: '<S78>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_n
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_o =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval_kq *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_o;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] > 0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_k
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_k
        = 0;
    }

    /* Update for UnitDelay: '<S74>/Unit Delay' incorporates:
     *  Constant: '<S66>/Constant3'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_ae =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_n;

    /* Update for UnitDelay: '<S74>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_f =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MathFunction_i;

    /* Update for DiscreteIntegrator: '<S74>/1//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_IC_LOADING_e = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE_k =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.s_gainval_a *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_c +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE_k;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Compare_b > 0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_PrevResetState_l = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_PrevResetState_l = 0;
    }

    /* Update for UnitDelay: '<S82>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_h
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_e;

    /* Update for DiscreteIntegrator: '<S82>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_f
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval_i *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_f +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_a;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] > 0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_e
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_e
        = 0;
    }

    /* Update for DiscreteTransferFcn: '<S10>/Butterworth Filter 10 Hz' */
    for (k = 0; k < 3; k++) {
      memOffset = k << 2;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
        [memOffset + 3] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
        [memOffset + 2];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
        [memOffset + 2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
        [memOffset + 1];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
        [memOffset + 1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
        [memOffset];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
        [memOffset] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_tmp_b
        [k];
    }

    /* Update for UnitDelay: '<Root>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_k[0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_k[1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_k[2];

    /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S11>/Constant'
     */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_DSTATE
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator_gainval
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant_Value_k +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_DSTATE;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl_b) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_PrevRese
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_PrevRese
        = 0;
    }

    /* Update for UnitDelay: '<S70>/Unit Delay3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay3_DSTATE_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch2;

    /* Update for UnitDelay: '<S70>/Unit Delay2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay2_DSTATE_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ac_out;

    /* Update for DiscreteIntegrator: '<S103>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i
      [0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval_n *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_ck[0] +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i
      [0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i
      [1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval_n *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_ck[1] +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i
      [1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i
      [2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval_n *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_ck[2] +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i
      [2];

    /* Update for DiscreteIntegrator: '<S138>/Discrete-Time Integrator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_IC_LOAD
      = 0U;
    for (k = 0; k < 6; k++) {
      /* Update for UnitDelay: '<S131>/Unit Delay' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_ef[k] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch[k];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_d
        [k] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator1_gainv_d
        * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_o[k] +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_d
        [k];
    }

    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_e > 0.0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_k
        = 1;
    } else if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_e < 0.0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_k
        = -1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_k
        = 0;
    }

    /* Update for DiscreteIntegrator: '<S135>/Discrete-Time Integrator' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_IC_LOADI
      = 0U;
    for (k = 0; k < 6; k++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_DSTATE_g
        [k] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator_gainva_m
        * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_jv[k] +
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_DSTATE_g
        [k];
    }

    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator1_i) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_PrevRe_i
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_PrevRe_i
        = 0;
    }

    /* Update for UnitDelay: '<S130>/Unit Delay6' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay6_DSTATE[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum2;
    for (k = 0; k < 5; k++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay6_DSTATE[k + 1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_j[k + 1];
    }

    /* Update for DiscreteTransferFcn: '<S8>/Butterworth Filter 10 Hz' */
    for (k = 0; k < 6; k++) {
      memOffset = k << 2;
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
        [memOffset + 3] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
        [memOffset + 2];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
        [memOffset + 2] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
        [memOffset + 1];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
        [memOffset + 1] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
        [memOffset];
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
        [memOffset] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_tmp
        [k];
    }

    /* Update for UnitDelay: '<S79>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp;

    /* Update for DiscreteIntegrator: '<S78>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] > 0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetStat
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetStat
        = 0;
    }

    /* Update for UnitDelay: '<S83>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_f =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_j;

    /* Update for DiscreteIntegrator: '<S82>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_j
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_j =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval_f *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_a +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_j;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] > 0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_l
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_l
        = 0;
    }

    /* Update for UnitDelay: '<S87>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_o;

    /* Update for DiscreteIntegrator: '<S86>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_p
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_k =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval_d *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_l +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_k;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1_m[4] > 0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_g
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_g
        = 0;
    }

    /* Update for UnitDelay: '<S94>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_j[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_j[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_j[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[2];

    /* Update for DiscreteIntegrator: '<S105>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_e =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval_j *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_k +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_e;

    /* Update for DiscreteIntegrator: '<S105>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_kq
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval_h
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_c +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_kq;

    /* Update for UnitDelay: '<S107>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_h =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_f;

    /* Update for DiscreteIntegrator: '<S106>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_m
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_g =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval_m *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_lp +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_g;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetS_lc
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetS_lc
        = 0;
    }

    /* Update for DiscreteIntegrator: '<S108>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_d2
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval_d
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_l +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_d2;

    /* Update for DiscreteIntegrator: '<S108>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_gb
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval_n
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_b +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_gb;

    /* Update for UnitDelay: '<S110>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_e =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_n;

    /* Update for DiscreteIntegrator: '<S109>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_c
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_gu
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval_c
      * M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_p +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_gu;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_e
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_e
        = 0;
    }

    /* Update for DiscreteIntegrator: '<S111>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_c =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_gainval_j0 *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_k5 +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_c;

    /* Update for DiscreteIntegrator: '<S111>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_e =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval_ci *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_i +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_e;

    /* Update for UnitDelay: '<S113>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_g =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_i;

    /* Update for DiscreteIntegrator: '<S112>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_n
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_f =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval_b *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_m +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_f;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.LogicalOperator5) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_a
        = 1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_a
        = 0;
    }

    /* Update for DiscreteIntegrator: '<S103>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a
      [0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval_b1 *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_a4[0] +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a
      [0];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a
      [1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval_b1 *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_a4[1] +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a
      [1];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a
      [2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval_b1 *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_a4[2] +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a
      [2];

    /* Update for UnitDelay: '<S123>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_o =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_g;

    /* Update for DiscreteIntegrator: '<S122>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_e
      = 0U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_l =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_gainval_md *
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_k +
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_l;
    if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state > 0.0) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_n
        = 1;
    } else if (M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state < 0.0)
    {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_n
        = -1;
    } else {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_n
        = 0;
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.clockTick0))
    ++M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.clockTickH0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.t[0] =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.clockTick0 *
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.stepSize0 +
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.clockTickH0 *
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.stepSize0 *
    4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void M37_Sim_Forcing_003h_expe_infra_transz_lim_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)M37_Sim_Forcing_003h_expe_infra_transz_lim_M,0,
                sizeof(RT_MODEL_M37_Sim_Forcing_003h_expe_infra_transz_lim));
  rtsiSetSolverName(&M37_Sim_Forcing_003h_expe_infra_transz_lim_M->solverInfo,
                    "FixedStepDiscrete");
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->solverInfoPtr =
    (&M37_Sim_Forcing_003h_expe_infra_transz_lim_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.sampleTimeTaskIDPtr = (
      &mdlTsMap[0]);
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.sampleTimes =
      (&M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.sampleTimesArray[0]);
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.offsetTimes =
      (&M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.offsetTimesArray[0]);

    /* task periods */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.sampleTimes[0] = (0.004);

    /* task offsets */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(M37_Sim_Forcing_003h_expe_infra_transz_lim_M,
             &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.sampleHits =
      (&mdlSampleHits[0]);
  }

  rtmSetTFinal(M37_Sim_Forcing_003h_expe_infra_transz_lim_M, -1);
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.stepSize0 = 0.004;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo =
      &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo, (NULL));
    rtliSetLogT(M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo, "tout");
    rtliSetLogX(M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo, "");
    rtliSetLogXFinal(M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo,
                     "");
    rtliSetSigLog(M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo,
                      1000);
    rtliSetLogDecimation
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo, 1);
    rtliSetLogY(M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_M->rtwLogInfo, (NULL));
  }

  /* external mode info */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.checksums[0] =
    (3858551847U);
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.checksums[1] =
    (1921636303U);
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.checksums[2] =
    (3285997524U);
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.checksums[3] =
    (2607645871U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[76];
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork._DOFVisualCab120615_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_h.IfActionSubsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_h.IfActionSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_c.IfActionSubsystem_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_c.IfActionSubsystem_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_h.IfActionSubsystem1_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_h.IfActionSubsystem1_SubsysRanBC;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_m.IfActionSubsystem_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_m.IfActionSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_n.IfActionSubsystem1_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_n.IfActionSubsystem1_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_n.IfActionSubsystem_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_n.IfActionSubsystem_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_p.IfActionSubsystem1_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_p.IfActionSubsystem1_SubsysRanBC;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_p.IfActionSubsystem_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_p.IfActionSubsystem_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_n5.IfActionSubsystem1_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_n5.IfActionSubsystem1_SubsysRanBC;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.MoveUP1_SubsysRanBC;
    systemRan[37] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.MoveUP1_SubsysRanBC;
    systemRan[38] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.MoveUP1_SubsysRanBC;
    systemRan[39] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.MoveUP1_SubsysRanBC;
    systemRan[40] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.MoveUP1_SubsysRanBC;
    systemRan[41] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.MoveUP1_SubsysRanBC;
    systemRan[42] = &rtAlwaysEnabled;
    systemRan[43] = &rtAlwaysEnabled;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = &rtAlwaysEnabled;
    systemRan[46] = &rtAlwaysEnabled;
    systemRan[47] = &rtAlwaysEnabled;
    systemRan[48] = &rtAlwaysEnabled;
    systemRan[49] = &rtAlwaysEnabled;
    systemRan[50] = &rtAlwaysEnabled;
    systemRan[51] = &rtAlwaysEnabled;
    systemRan[52] = &rtAlwaysEnabled;
    systemRan[53] = &rtAlwaysEnabled;
    systemRan[54] = &rtAlwaysEnabled;
    systemRan[55] = &rtAlwaysEnabled;
    systemRan[56] = &rtAlwaysEnabled;
    systemRan[57] = &rtAlwaysEnabled;
    systemRan[58] = &rtAlwaysEnabled;
    systemRan[59] = &rtAlwaysEnabled;
    systemRan[60] = &rtAlwaysEnabled;
    systemRan[61] = &rtAlwaysEnabled;
    systemRan[62] = &rtAlwaysEnabled;
    systemRan[63] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork._DOFControl_SubsysRanBC;
    systemRan[64] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem_SubsysRanBC_i;
    systemRan[65] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.IfActionSubsystem1_SubsysRanB_o;
    systemRan[66] = &rtAlwaysEnabled;
    systemRan[67] = &rtAlwaysEnabled;
    systemRan[68] = &rtAlwaysEnabled;
    systemRan[69] = &rtAlwaysEnabled;
    systemRan[70] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.fullinversekin_SubsysRanBC;
    systemRan[71] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.fullinversekin_SubsysRanBC;
    systemRan[72] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.SimplifiedInverseKin_SubsysRanB;
    systemRan[73] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.SimplifiedInverseKin_SubsysRanB;
    systemRan[74] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.SimplifiedInverseKin_SubsysRanB;
    systemRan[75] = (sysRanDType *)
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.SimplifiedInverseKin_SubsysRanB;
    rteiSetModelMappingInfoPtr
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_M->extModeInfo,
       &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_M->extModeInfo,
       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.checksums);
    rteiSetTPtr(M37_Sim_Forcing_003h_expe_infra_transz_lim_M->extModeInfo,
                rtmGetTPtr(M37_Sim_Forcing_003h_expe_infra_transz_lim_M));
  }

  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->solverInfoPtr =
    (&M37_Sim_Forcing_003h_expe_infra_transz_lim_M->solverInfo);
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.stepSize = (0.004);
  rtsiSetFixedStepSize(&M37_Sim_Forcing_003h_expe_infra_transz_lim_M->solverInfo,
                       0.004);
  rtsiSetSolverMode(&M37_Sim_Forcing_003h_expe_infra_transz_lim_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->ModelData.blockIO = ((void *)
    &M37_Sim_Forcing_003h_expe_infra_transz_lim_B);
  (void) memset(((void *) &M37_Sim_Forcing_003h_expe_infra_transz_lim_B),0,
                sizeof(BlockIO_M37_Sim_Forcing_003h_expe_infra_transz_lim));

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_i[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_i[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_p[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_j[i] =
        0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_l[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_n[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_j[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_d[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ButterworthFilter10Hz[i] =
        0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_e[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_jv[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_o[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_m[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_f[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_a[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1_a[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.out_o[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch_l[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.set_out[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SwitchControl_g[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctionI
        [i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_i
        [i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFunctio_f
        [i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ControlLoopGain[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator_k[i] =
        0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum6[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o3[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o4[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_g[i] =
        0.0F;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion3[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion_o[i] =
        0.0F;
    }

    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator2 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator1_a = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum20 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_f = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityunt
      = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_n
      = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_f = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_k = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay1 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide2 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant4 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay2 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_o
      = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_j = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_g = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant8 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant3 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay3 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay1_g = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay2_b = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_m
      = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_i = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_f[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_f[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum9 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum15 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TargetPSI = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum11 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product3 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MathFunction = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_d
      = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_b = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum17 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product3_l = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MathFunction_f = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_g
      = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_l = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_a = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum16 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product3_p = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MathFunction_i = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_p
      = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_e = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion4_c = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum3 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_k[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_k[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay_k[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DiscreteTimeIntegrator = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_j[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_j[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_j[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7_n = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6_d = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.UnitDelay2_d = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch2 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch4[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum1 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum8 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum4 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum7 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum5 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum12 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_e = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum2 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_n = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA1 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_b = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_f = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_c = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA2 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_bs = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_e = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_nz = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA3 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_l = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_j = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_h = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA4 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_a = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_i = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_l = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA5 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs2_lm = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs1_o = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_j = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.AccLimiterA6 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_ju = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_i = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_n = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain5 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_j = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_g = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_a = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_f = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_o = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_d = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_l = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_o = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.MultiportSwitch[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant3_g = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch3[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch3[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch3[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_m[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_m[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Product_m[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant9 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch1_ho[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Fcn1 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_lu = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_c = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_k = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_f = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_e = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_lp = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_p = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_in = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_b = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_l = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_n = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_l = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_p = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_kx = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_p = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_i = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_k5 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_i = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_f = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_m = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_c = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_a4[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_a4[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_a4[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_ck[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_ck[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_ck[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_g = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_de = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_k = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_a = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_k[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_k[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Sum_k[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.target_ang_speed[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.target_ang_speed[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.target_ang_speed[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mask[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.vis_cond = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.flag_out = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.endOffile_out = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.status = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.xytoz = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gradual_state = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.mod = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.current_axis = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.start_next = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ac_out = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.R = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.T = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.y_h = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.gain = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_l[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_l[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_l[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.max_tilt = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Forsavingpositionandvelocityu_k
      = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TSamp_o3 = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetaT_transferpi_h = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizetaT_transfers_g = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.zetapi_la = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.pizeta_b = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.x = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.psi = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.c[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.z_p[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.stick_out[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_k = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_h = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_i = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_kx = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_p = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_n = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Switch_hj = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFuncti_ii[
      0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFuncti_ii[
      1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TmpSignalConversionAtSFuncti_ii[
      2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_h = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_o = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_c = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_c[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[0] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[1] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_e[2] = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_f = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_i = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_d = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.shift = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_n = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide_a = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Divide1_a = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain_c =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_sfix64_En41_GND;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_sfix64_En41_GND;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain6 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_sfix64_En41_GND;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_k =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_sfix64_En41_GND;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_sfix64_En41_GND;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_k =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_sfix64_En41_GND;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o2 = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o5 = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1[0] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1[1] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o1[2] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o3_f = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Unpack_o4_c = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_g[0] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_g[1] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_g[2] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1_p[0] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1_p[1] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion1_p[2] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Abs = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6 = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion7 = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion5 = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion8[0] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion8[1] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion8[2] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion9[0] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion9[1] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion9[2] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion10 = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion11[0] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion11[1] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion11[2] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion14 = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion16[0] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion16[1] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion16[2] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion17[0] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion17[1] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion17[2] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Limitto1[0] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Limitto1[1] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Limitto1[2] = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.DataTypeConversion6_o = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ButterworthFilter10Hz_m[0] =
      0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ButterworthFilter10Hz_m[1] =
      0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.ButterworthFilter10Hz_m[2] =
      0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.SumofElements = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_nl = 0.0F;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction5.y =
      0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction5.gain
      = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction2_j.y =
      0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.sf_EmbeddedMATLABFunction2_j.gain
      = 0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_n5.Switch =
      0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_p.Switch =
      0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_p.Switch =
      0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_n.Switch =
      0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_n.Switch =
      0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_m.Switch =
      0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_h.Switch =
      0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_c.Switch =
      0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1_e.Switch =
      0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem_h.Switch =
      0.0;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_B.IfActionSubsystem1.Switch = 0.0;
  }

  /* parameters */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->ModelData.defaultParam =
    ((real_T *) &M37_Sim_Forcing_003h_expe_infra_transz_lim_P);

  /* states (dwork) */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Work.dwork = ((void *)
    &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork);
  (void) memset((void *)&M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork, 0,
                sizeof(D_Work_M37_Sim_Forcing_003h_expe_infra_transz_lim));
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTATE
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator2_DSTATE
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_f
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay4_DSTATE = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityunt
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_o
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_g
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_h =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay2_DSTATE = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_n
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_b
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_l =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay3_DSTATE = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_b = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay2_DSTATE_h = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_m
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_g =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_a = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_e = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_c
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_d =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_e = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_g = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE_i = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_a
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_o =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_ae = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_f = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_DSTATE_k = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_h
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_a =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c[0] = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c[1] = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c[2] = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_DSTATE
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay3_DSTATE_a = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay2_DSTATE_d = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i[0]
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i[1]
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i[2]
    = 0.0;

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_ef[i] =
        0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_d
        [i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_DSTATE_g
        [i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay6_DSTATE[i] =
        0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 24; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
        [i] = 0.0;
    }
  }

  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_f = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_j =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_n = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_k =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_j[0] = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_j[1] = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_j[2] = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_e =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_kq =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_h = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_g =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_d2 =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_gb =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_e = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_gu =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_c =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_e =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_g = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_f =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a[0]
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a[1]
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a[2]
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_o = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_l =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_d
    = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_p = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_f =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_jy =
    0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Sum20_DWORK1 = 0.0;

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Sum1_DWORK1[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_tmp[
        i] = 0.0;
    }
  }

  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_j = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_f = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_o = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_l = 0.0;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_i = 0.0;

  {
    int_T i;
    for (i = 0; i < 12; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
        [i] = 0.0F;
    }
  }

  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_tmp_b[0]
    = 0.0F;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_tmp_b[1]
    = 0.0F;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_tmp_b[2]
    = 0.0F;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->SpecialInfo.mappingInfo =
      (&dtInfo);
    dtInfo.numDataTypes = 150;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.sfcnInfo;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr
                   (M37_Sim_Forcing_003h_expe_infra_transz_lim_M));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal
                     (M37_Sim_Forcing_003h_expe_infra_transz_lim_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (M37_Sim_Forcing_003h_expe_infra_transz_lim_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo,
                      &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->solverInfoPtr);
  }

  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.numSFcns = (20);

  /* register each child */
  {
    (void) memset((void *)
                  &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.childSFunctions
                  [0],0,
                  20*sizeof(SimStruct));
    M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions =
      (&M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.childSFunctionPtrs
       [0]);

    {
      int_T i;
      for (i = 0; i < 20; i++) {
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[i] =
          (&M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.childSFunctions
           [i]);
      }
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S1>/GT-RT UDP TX (gt_rt_udp_send) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn0.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;
          sfcnUPtrs[1] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;
          sfcnUPtrs[2] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;
          sfcnUPtrs[3] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 4);
        }

        /* port 1 */
        {
          uint16_T const **sfcnUPtrs = (uint16_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] =
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_gm;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn0.UPtrs2;

          {
            int_T i1;
            const uint8_T *u2 =
              M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking_e;
            for (i1=0; i1 < 32; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 32);
        }

        /* port 3 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn0.UPtrs3;
          sfcnUPtrs[0] =
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_b;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPTX_i));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP TX");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/6_DOF Visual Cab 12//06//15/GT-RT UDP TX");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPTX_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPTX_P2_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPTX_PWORK_i
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPTX_PWORK_i
                   [0]);
      }

      /* registration */
      gt_rt_udp_send(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 2, 32);
      ssSetInputPortDataType(rts, 2, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 2, 0);
      ssSetInputPortFrameData(rts, 2, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 0);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S1>/GT-RT UDP  Write (gt_rt_udp_controller) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Write");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/6_DOF Visual Cab 12//06//15/GT-RT UDP  Write");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPWrite_P1_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPWrite_PWORK_e);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPWrite_PWORK_e);
      }

      /* registration */
      gt_rt_udp_controller(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S22>/GT-RT CAN TX (gt_rt_can_send) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [2]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn2.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] =
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TXCANID1_Value;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_e;
          sfcnUPtrs[1] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_j;
          sfcnUPtrs[2] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_c;
          sfcnUPtrs[3] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_f;
          sfcnUPtrs[4] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_n;
          sfcnUPtrs[5] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_d;
          sfcnUPtrs[6] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_m;
          sfcnUPtrs[7] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_l;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN TX");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/GT-RT CAN TX");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANTX_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANTX_P2_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANTX_PWORK_o);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANTX_PWORK_o);
      }

      /* registration */
      gt_rt_can_send(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 1, 8);
      ssSetInputPortDataType(rts, 1, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S22>/GT-RT CAN TX1 (gt_rt_can_send) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [3]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn3.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] =
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TXCANID2_Value;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn3.UPtrs1;
          sfcnUPtrs[0] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_nr;
          sfcnUPtrs[1] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_da;
          sfcnUPtrs[2] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_dw;
          sfcnUPtrs[3] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_kd;
          sfcnUPtrs[4] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_f;
          sfcnUPtrs[5] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_a;
          sfcnUPtrs[6] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_n;
          sfcnUPtrs[7] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_k1;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN TX1");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/GT-RT CAN TX1");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANTX1_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANTX1_P2_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANTX1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANTX1_PWORK);
      }

      /* registration */
      gt_rt_can_send(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 1, 8);
      ssSetInputPortDataType(rts, 1, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S22>/GT-RT CAN TX2 (gt_rt_can_send) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [4]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn4.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] =
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TXCANID3_Value;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_a;
          sfcnUPtrs[1] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_f;
          sfcnUPtrs[2] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_d1;
          sfcnUPtrs[3] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_j;
          sfcnUPtrs[4] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain1_c;
          sfcnUPtrs[5] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain2_dk;
          sfcnUPtrs[6] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain3_fg;
          sfcnUPtrs[7] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Gain4_kf;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN TX2");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/GT-RT CAN TX2");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANTX2_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANTX2_P2_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANTX2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANTX2_PWORK);
      }

      /* registration */
      gt_rt_can_send(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 1, 8);
      ssSetInputPortDataType(rts, 1, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S125>/GT-RT UDP TX1 (gt_rt_udp_send) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [5]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn5.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;
          sfcnUPtrs[1] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;
          sfcnUPtrs[2] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;
          sfcnUPtrs[3] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 4);
        }

        /* port 1 */
        {
          uint16_T const **sfcnUPtrs = (uint16_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn5.UPtrs1;
          sfcnUPtrs[0] =
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant8_Value_p;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn5.UPtrs2;

          {
            int_T i1;
            const uint8_T *u2 =
              M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking3;
            for (i1=0; i1 < 8; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 8);
        }

        /* port 3 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn5.UPtrs3;
          sfcnUPtrs[0] =
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant9_Value_l;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn5.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPTX1));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP TX1");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/Data to Control Node 12//06//15/6_DOF Control/GT-RT UDP TX1");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPTX1_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPTX1_P2_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPTX1_PWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPTX1_PWORK
                   [0]);
      }

      /* registration */
      gt_rt_udp_send(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 2, 8);
      ssSetInputPortDataType(rts, 2, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 2, 0);
      ssSetInputPortFrameData(rts, 2, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 0);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S125>/GT-RT UDP TX (gt_rt_udp_send) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [6]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn6.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;
          sfcnUPtrs[1] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;
          sfcnUPtrs[2] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;
          sfcnUPtrs[3] = &M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 4);
        }

        /* port 1 */
        {
          uint16_T const **sfcnUPtrs = (uint16_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] =
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant2_Value_j;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn6.UPtrs2;

          {
            int_T i1;
            const uint8_T *u2 =
              M37_Sim_Forcing_003h_expe_infra_transz_lim_B.BytePacking;
            for (i1=0; i1 < 161; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 161);
        }

        /* port 3 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn6.UPtrs3;
          sfcnUPtrs[0] =
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_p;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn6.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPTX));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP TX");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/Data to Control Node 12//06//15/6_DOF Control/GT-RT UDP TX");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPTX_P1_Size_m
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPTX_P2_Size_h
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPTX_PWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPTX_PWORK
                   [0]);
      }

      /* registration */
      gt_rt_udp_send(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 2, 161);
      ssSetInputPortDataType(rts, 2, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 2, 0);
      ssSetInputPortFrameData(rts, 2, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 0);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S125>/GT-RT UDP  Write (gt_rt_udp_controller) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [7]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [7]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Write");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/Data to Control Node 12//06//15/6_DOF Control/GT-RT UDP  Write");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPWrite_P1_Size_f
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPWrite_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPWrite_PWORK);
      }

      /* registration */
      gt_rt_udp_controller(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S125>/GT-RT UDP  Write1 (gt_rt_udp_controller) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [8]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [8]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Write1");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/Data to Control Node 12//06//15/6_DOF Control/GT-RT UDP  Write1");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPWrite1_P1_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPWrite1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPWrite1_PWORK);
      }

      /* registration */
      gt_rt_udp_controller(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S127>/GT-RT CAN TX (gt_rt_can_send) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [9]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn9.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn9.UPtrs0;
          sfcnUPtrs[0] =
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TXCANID1_Value_i;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn9.UPtrs1;
          sfcnUPtrs[0] =
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TXData_Value;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN TX");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/Handshake CAN/If Action Subsystem/GT-RT CAN TX");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANTX_P1_Size_c
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANTX_P2_Size_o
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANTX_PWORK_n);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn9.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn9.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANTX_PWORK_n);
      }

      /* registration */
      gt_rt_can_send(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S128>/GT-RT CAN TX (gt_rt_can_send) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [10]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [10]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn10.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn10.UPtrs0;
          sfcnUPtrs[0] =
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TXCANID1_Value_b;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn10.UPtrs1;
          sfcnUPtrs[0] =
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TXData_Value_d;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN TX");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/Handshake CAN/If Action Subsystem1/GT-RT CAN TX");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANTX_P1_Size_k
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANTX_P2_Size_d
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANTX_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn10.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn10.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANTX_PWORK);
      }

      /* registration */
      gt_rt_can_send(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S4>/GT-RT UDP RX (gt_rt_udp_receive) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [11]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [11]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn11.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 66);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((boolean_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 4);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((uint16_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((int32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP RX");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/Controls to GT-RT/GT-RT UDP RX");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPRX_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPRX_P2_Size
                       [0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPRX_P3_Size
                       [0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPRX_P4_Size
                       [0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPRX_IWORK);
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPRX_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn11.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn11.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPRX_IWORK);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPRX_PWORK);
      }

      /* registration */
      gt_rt_udp_receive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S4>/GT-RT UDP  Read (gt_rt_udp_controller) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [12]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [12]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [12]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Read");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/Controls to GT-RT/GT-RT UDP  Read");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPRead_P1_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPRead_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn12.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn12.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPRead_PWORK);
      }

      /* registration */
      gt_rt_udp_controller(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S126>/GT-RT UDP RX (gt_rt_udp_receive) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [13]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [13]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [13]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn13.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 28);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o1_h));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o2_p));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((boolean_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o3_p));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 4);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o4_j));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((uint16_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o5_m));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((int32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTUDPRX_o6_m));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP RX");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/Data to Control Node 12//06//15/Interaction device from VIS (Stick) /GT-RT UDP RX");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPRX_P1_Size_e
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPRX_P2_Size_i
                       [0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPRX_P3_Size_g
                       [0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPRX_P4_Size_e
                       [0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPRX_IWORK_k);
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPRX_PWORK_b);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn13.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn13.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPRX_IWORK_k);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPRX_PWORK_b);
      }

      /* registration */
      gt_rt_udp_receive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S126>/GT-RT UDP  Read (gt_rt_udp_controller) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[14];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn14.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn14.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn14.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [14]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [14]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [14]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Read");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/Data to Control Node 12//06//15/Interaction device from VIS (Stick) /GT-RT UDP  Read");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn14.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTUDPRead_P1_Size_n
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPRead_PWORK_l);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn14.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn14.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTUDPRead_PWORK_l);
      }

      /* registration */
      gt_rt_udp_controller(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S12>/GT-RT CAN RX1 (gt_rt_can_receive) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[15];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn15.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn15.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn15.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [15]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [15]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [15]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn15.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 8);
          ssSetOutputPortSignal(rts, 1, ((uint8_T *)
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((uint8_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((boolean_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((uint32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX1_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN RX1");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Receive/GT-RT CAN RX1");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn15.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX1_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX1_P2_Size
                       [0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX1_P3_Size
                       [0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX1_P4_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANRX1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn15.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn15.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANRX1_PWORK);
      }

      /* registration */
      gt_rt_can_receive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 0);
      _ssSetOutputPortConnected(rts, 4, 0);
      _ssSetOutputPortConnected(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S12>/GT-RT CAN RX2 (gt_rt_can_receive) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[16];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn16.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn16.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn16.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [16]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [16]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [16]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn16.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 8);
          ssSetOutputPortSignal(rts, 1, ((uint8_T *)
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((uint8_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((boolean_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((uint32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN RX2");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Receive/GT-RT CAN RX2");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn16.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX2_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX2_P2_Size
                       [0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX2_P3_Size
                       [0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX2_P4_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANRX2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn16.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn16.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANRX2_PWORK);
      }

      /* registration */
      gt_rt_can_receive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 0);
      _ssSetOutputPortConnected(rts, 4, 0);
      _ssSetOutputPortConnected(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S12>/GT-RT CAN RX3 (gt_rt_can_receive) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[17];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn17.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn17.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn17.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [17]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [17]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [17]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn17.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 8);
          ssSetOutputPortSignal(rts, 1, ((uint8_T *)
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((uint8_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((boolean_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((uint32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX3_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN RX3");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Receive/GT-RT CAN RX3");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn17.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX3_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX3_P2_Size
                       [0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX3_P3_Size
                       [0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX3_P4_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANRX3_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn17.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn17.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANRX3_PWORK);
      }

      /* registration */
      gt_rt_can_receive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 0);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<S7>/GT-RT CAN RX2 (gt_rt_can_receive) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[18];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn18.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn18.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn18.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [18]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [18]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [18]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn18.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o1_c));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 8);
          ssSetOutputPortSignal(rts, 1, ((uint8_T *)
            M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o2_n));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((uint8_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o3_i));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o4_g));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((boolean_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o5_d));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((uint32_T *)
            &M37_Sim_Forcing_003h_expe_infra_transz_lim_B.GTRTCANRX2_o6_m));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN RX2");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/Handshake CAN/GT-RT CAN RX2");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn18.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX2_P1_Size_h
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX2_P2_Size_o
                       [0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX2_P3_Size_m
                       [0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANRX2_P4_Size_c
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANRX2_PWORK_b);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn18.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn18.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANRX2_PWORK_b);
      }

      /* registration */
      gt_rt_can_receive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 0);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: M37_Sim_Forcing_003h_expe_infra_transz_lim/<Root>/GT-RT CAN Controller (gt_rt_can_controller) */
    {
      SimStruct *rts =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[19];

      /* timing info */
      time_T *sfcnPeriod =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn19.sfcnPeriod;
      time_T *sfcnOffset =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn19.sfcnOffset;
      int_T *sfcnTsMap =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn19.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.blkInfo2
                         [19]);
      }

      ssSetRTWSfcnInfo(rts,
                       M37_Sim_Forcing_003h_expe_infra_transz_lim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods2
                           [19]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.methods3
                           [19]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN Controller");
      ssSetPath(rts,
                "M37_Sim_Forcing_003h_expe_infra_transz_lim/GT-RT CAN Controller");
      ssSetRTModel(rts,M37_Sim_Forcing_003h_expe_infra_transz_lim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn19.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANController_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M37_Sim_Forcing_003h_expe_infra_transz_lim_P.GTRTCANController_P2_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANController_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn19.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M37_Sim_Forcing_003h_expe_infra_transz_lim_M->NonInlinedSFcns.Sfcn19.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.GTRTCANController_PWORK);
      }

      /* registration */
      gt_rt_can_controller(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.004);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }
  }
}

/* Model terminate function */
void M37_Sim_Forcing_003h_expe_infra_transz_lim_terminate(void)
{
  /* Level2 S-Function Block: '<S4>/GT-RT UDP RX' (gt_rt_udp_receive) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/GT-RT UDP  Read' (gt_rt_udp_controller) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S126>/GT-RT UDP RX' (gt_rt_udp_receive) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S126>/GT-RT UDP  Read' (gt_rt_udp_controller) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[14];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S12>/GT-RT CAN RX1' (gt_rt_can_receive) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[15];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S12>/GT-RT CAN RX2' (gt_rt_can_receive) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[16];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S12>/GT-RT CAN RX3' (gt_rt_can_receive) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[17];
    sfcnTerminate(rts);
  }

  /* Terminate for enable SubSystem: '<S5>/6_DOF Control' */
  /* Level2 S-Function Block: '<S125>/GT-RT UDP TX1' (gt_rt_udp_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S125>/GT-RT UDP TX' (gt_rt_udp_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S125>/GT-RT UDP  Write' (gt_rt_udp_controller) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S125>/GT-RT UDP  Write1' (gt_rt_udp_controller) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* end of Terminate for SubSystem: '<S5>/6_DOF Control' */

  /* Terminate for enable SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' */
  /* Level2 S-Function Block: '<S1>/GT-RT UDP TX' (gt_rt_udp_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/GT-RT UDP  Write' (gt_rt_udp_controller) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* end of Terminate for SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' */

  /* Terminate for ifaction SubSystem: '<S13>/If Action Subsystem1' */
  /* Level2 S-Function Block: '<S22>/GT-RT CAN TX' (gt_rt_can_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S22>/GT-RT CAN TX1' (gt_rt_can_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S22>/GT-RT CAN TX2' (gt_rt_can_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* end of Terminate for SubSystem: '<S13>/If Action Subsystem1' */

  /* Terminate for ifaction SubSystem: '<S7>/If Action Subsystem' */
  /* Level2 S-Function Block: '<S127>/GT-RT CAN TX' (gt_rt_can_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* end of Terminate for SubSystem: '<S7>/If Action Subsystem' */

  /* Level2 S-Function Block: '<S7>/GT-RT CAN RX2' (gt_rt_can_receive) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[18];
    sfcnTerminate(rts);
  }

  /* Terminate for ifaction SubSystem: '<S7>/If Action Subsystem1' */
  /* Level2 S-Function Block: '<S128>/GT-RT CAN TX' (gt_rt_can_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* end of Terminate for SubSystem: '<S7>/If Action Subsystem1' */

  /* Level2 S-Function Block: '<Root>/GT-RT CAN Controller' (gt_rt_can_controller) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[19];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  M37_Sim_Forcing_003h_expe_infra_transz_lim_output(tid);
}

void MdlUpdate(int_T tid)
{
  M37_Sim_Forcing_003h_expe_infra_transz_lim_update(tid);
}

void MdlInitializeSizes(void)
{
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.numContStates = (0);/* Number of continuous states */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.numY = (0);/* Number of model outputs */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.numU = (0);/* Number of model inputs */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.numSampTimes = (1);/* Number of sample times */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.numBlocks = (792);/* Number of blocks */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.numBlockIO = (385);/* Number of block outputs */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_M->Sizes.numBlockPrms = (1674);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S69>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c0 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0_fb;

    /* InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTATE
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator1_IC;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevRes
      = 2;

    /* InitializeConditions for UnitDelay: '<S70>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay1_X0_m;

    /* InitializeConditions for DiscreteIntegrator: '<S70>/Discrete-Time Integrator2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator2_DSTATE
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator2_IC;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator2_PrevRes
      = 2;

    /* InitializeConditions for UnitDelay: '<S70>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_b =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0_ps;

    /* InitializeConditions for DiscreteIntegrator: '<S70>/Discrete-Time Integrator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_f
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator1_IC_f;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_b
      = 2;

    /* InitializeConditions for UnitDelay: '<S70>/Unit Delay4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay4_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay4_X0;

    /* InitializeConditions for Embedded MATLAB: '<S70>/Embedded MATLAB Function1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c4_M37_Sim_Forcing_00
      = 0U;

    /* InitializeConditions for S-Function (sdspcount2): '<S3>/Counter' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Counter_ClkEphState = 5U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Counter_Count =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Counter_InitialCount;

    /* InitializeConditions for UnitDelay: '<S72>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0;

    /* InitializeConditions for Embedded MATLAB: '<S72>/Embedded MATLAB Function2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c19_M37_Sim_Forcing_0
      = 0U;

    /* InitializeConditions for UnitDelay: '<S106>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityunt
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Forsavingpositionandvelocityunt;

    /* InitializeConditions for DiscreteIntegrator: '<S106>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetStat
      = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S101>/Discrete-Time Integrator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_o
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator1_IC_h;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_a
      = 2;

    /* InitializeConditions for UnitDelay: '<S109>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_g
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Forsavingpositionandvelocityu_o;

    /* InitializeConditions for DiscreteIntegrator: '<S109>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_j
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_b
      = 2;

    /* InitializeConditions for Embedded MATLAB: '<S104>/Get R' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c3_M37_Sim_Forcing_00
      = 0U;

    /* InitializeConditions for UnitDelay: '<S94>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay1_X0;

    /* InitializeConditions for Embedded MATLAB: '<S94>/Embedded MATLAB Function1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c5_M37_Sim_Forcing_00
      = 0U;

    /* InitializeConditions for UnitDelay: '<S94>/Unit Delay2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay2_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay2_X0;

    /* InitializeConditions for Embedded MATLAB: '<S94>/Embedded MATLAB Function2' */
    M3_EmbeddedMATLABFunction2_Init
      (&M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.sf_EmbeddedMATLABFunction2_j);

    /* InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_DSTAT_n
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator1_IC_j;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_n
      = 2;

    /* InitializeConditions for UnitDelay: '<S112>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_b
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Forsavingpositionandvelocityu_c;

    /* InitializeConditions for DiscreteIntegrator: '<S112>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_i
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_i
      = 2;

    /* InitializeConditions for UnitDelay: '<S94>/Unit Delay3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay3_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay3_X0;

    /* InitializeConditions for Embedded MATLAB: '<S94>/Embedded MATLAB Function5' */
    M3_EmbeddedMATLABFunction2_Init
      (&M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.sf_EmbeddedMATLABFunction5);

    /* InitializeConditions for Embedded MATLAB: '<S93>/Embedded MATLAB Function3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c7_M37_Sim_Forcing_00
      = 0U;

    /* InitializeConditions for UnitDelay: '<S93>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c1 =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0_eq;

    /* InitializeConditions for UnitDelay: '<S71>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_b =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay1_X0_f;

    /* InitializeConditions for UnitDelay: '<S71>/Unit Delay2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay2_DSTATE_h =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay2_X0_n;

    /* InitializeConditions for Embedded MATLAB: '<S71>/Embedded MATLAB Function2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c12_M37_Sim_Forcing_0
      = 0U;

    /* InitializeConditions for UnitDelay: '<S122>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_m
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Forsavingpositionandvelocity_o5;

    /* InitializeConditions for DiscreteIntegrator: '<S122>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_d
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_f
      = 2;

    /* InitializeConditions for UnitDelay: '<S75>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0_n;

    /* InitializeConditions for UnitDelay: '<S75>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_e =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay1_X0_j;

    /* InitializeConditions for DiscreteIntegrator: '<S75>/1//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_IC_LOADING = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_PrevResetState = 2;

    /* InitializeConditions for UnitDelay: '<S86>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_c
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Forsavingpositionandvelocityu_n;

    /* InitializeConditions for DiscreteIntegrator: '<S86>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_iq
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_o
      = 2;

    /* InitializeConditions for UnitDelay: '<S73>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_e =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0_b;

    /* InitializeConditions for UnitDelay: '<S73>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_g =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay1_X0_e;

    /* InitializeConditions for DiscreteIntegrator: '<S73>/1//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_IC_LOADING_d = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_PrevResetState_k = 2;

    /* InitializeConditions for UnitDelay: '<S78>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_a
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Forsavingpositionandvelocityu_a;

    /* InitializeConditions for DiscreteIntegrator: '<S78>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_n
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_k
      = 2;

    /* InitializeConditions for UnitDelay: '<S74>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_ae =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0_e;

    /* InitializeConditions for UnitDelay: '<S74>/Unit Delay1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay1_DSTATE_f =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay1_X0_o;

    /* InitializeConditions for DiscreteIntegrator: '<S74>/1//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_IC_LOADING_e = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.s_PrevResetState_l = 2;

    /* InitializeConditions for UnitDelay: '<S82>/For saving position  and velocity until after switchover' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_h
      =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Forsavingpositionandvelocityu_e;

    /* InitializeConditions for DiscreteIntegrator: '<S82>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_f
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetSt_e
      = 2;

    /* InitializeConditions for DiscreteTransferFcn: '<S10>/Butterworth Filter 10 Hz' */
    for (i = 0; i < 12; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE_l
        [i] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_Initial_a;
    }

    /* InitializeConditions for Embedded MATLAB: '<S129>/Embedded MATLAB Function' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c23_M37_Sim_Forcing_0
      = 0U;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_DSTATE
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.DiscreteTimeIntegrator_IC;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_PrevRese
      = 2;

    /* InitializeConditions for UnitDelay: '<S70>/Unit Delay3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay3_DSTATE_a =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay3_X0_f;

    /* InitializeConditions for Embedded MATLAB: '<S3>/Embedded MATLAB Function' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c21_M37_Sim_Forcing_0
      = 0U;

    /* InitializeConditions for UnitDelay: '<S70>/Unit Delay2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay2_DSTATE_d =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay2_X0_n4;

    /* InitializeConditions for Embedded MATLAB: '<S70>/Embedded MATLAB Function' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c2_M37_Sim_Forcing_00
      = 0U;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0_f[0];

    /* InitializeConditions for DiscreteIntegrator: '<S103>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i
      [0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_IC;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0_f[1];

    /* InitializeConditions for DiscreteIntegrator: '<S103>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i
      [1] = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_IC;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_c[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0_f[2];

    /* InitializeConditions for DiscreteIntegrator: '<S103>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_i
      [2] = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S138>/Discrete-Time Integrator1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_IC_LOAD
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator1_PrevR_k
      = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S135>/Discrete-Time Integrator' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_IC_LOADI
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.DiscreteTimeIntegrator_PrevRe_i
      = 2;
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for UnitDelay: '<S131>/Unit Delay' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_ef[i] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0_l[i];

      /* InitializeConditions for UnitDelay: '<S130>/Unit Delay6' */
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay6_DSTATE[i] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay6_X0[i];
    }

    /* InitializeConditions for DiscreteTransferFcn: '<S8>/Butterworth Filter 10 Hz' */
    for (i = 0; i < 24; i++) {
      M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.ButterworthFilter10Hz_DSTATE
        [i] =
        M37_Sim_Forcing_003h_expe_infra_transz_lim_P.ButterworthFilter10Hz_InitialSt;
    }

    /* InitializeConditions for RateLimiter: '<S15>/Acc Limiter A1' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA1_IC;

    /* InitializeConditions for RateLimiter: '<S15>/Acc Limiter A2' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_j =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA2_IC;

    /* InitializeConditions for RateLimiter: '<S15>/Acc Limiter A3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_f =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA3_IC;

    /* InitializeConditions for RateLimiter: '<S15>/Acc Limiter A4' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_o =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA4_IC;

    /* InitializeConditions for RateLimiter: '<S15>/Acc Limiter A5' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_l =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA5_IC;

    /* InitializeConditions for RateLimiter: '<S15>/Acc Limiter A6' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.PrevY_i =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.AccLimiterA6_IC;

    /* InitializeConditions for UnitDelay: '<S79>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UD_X0;

    /* InitializeConditions for DiscreteIntegrator: '<S78>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetStat
      = 2;

    /* InitializeConditions for UnitDelay: '<S83>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_f =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UD_X0_n;

    /* InitializeConditions for DiscreteIntegrator: '<S82>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_j
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_l
      = 2;

    /* InitializeConditions for UnitDelay: '<S87>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_n =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UD_X0_nl;

    /* InitializeConditions for DiscreteIntegrator: '<S86>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_p
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_g
      = 2;

    /* InitializeConditions for Embedded MATLAB: '<S71>/Embedded MATLAB Function3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c13_M37_Sim_Forcing_0
      = 0U;

    /* InitializeConditions for Embedded MATLAB: '<S94>/Embedded MATLAB Function3' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c9_M37_Sim_Forcing_00
      = 0U;

    /* InitializeConditions for DiscreteIntegrator: '<S105>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_e =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_IC_i;

    /* InitializeConditions for DiscreteIntegrator: '<S105>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_kq
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_IC;

    /* InitializeConditions for UnitDelay: '<S107>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_h =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UD_X0_i;

    /* InitializeConditions for DiscreteIntegrator: '<S106>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_m
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetS_lc
      = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S108>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_d2
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_IC_e;

    /* InitializeConditions for DiscreteIntegrator: '<S108>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_gb
      = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_IC_p;

    /* InitializeConditions for UnitDelay: '<S110>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_e =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UD_X0_f;

    /* InitializeConditions for DiscreteIntegrator: '<S109>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_c
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_e
      = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S111>/pi//(zeta*T_transfer)//s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_DSTATE_c =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.pizetaT_transfers_IC_h;

    /* InitializeConditions for DiscreteIntegrator: '<S111>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_e =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_IC_e;

    /* InitializeConditions for UnitDelay: '<S113>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_g =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UD_X0_p;

    /* InitializeConditions for DiscreteIntegrator: '<S112>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_n
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_a
      = 2;

    /* InitializeConditions for UnitDelay: '<S94>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_j[0] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0_p[0];

    /* InitializeConditions for DiscreteIntegrator: '<S103>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a
      [0] = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_IC_m;

    /* InitializeConditions for UnitDelay: '<S94>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_j[1] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0_p[1];

    /* InitializeConditions for DiscreteIntegrator: '<S103>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a
      [1] = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_IC_m;

    /* InitializeConditions for UnitDelay: '<S94>/Unit Delay' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UnitDelay_DSTATE_j[2] =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UnitDelay_X0_p[2];

    /* InitializeConditions for DiscreteIntegrator: '<S103>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_DSTATE_a
      [2] = M37_Sim_Forcing_003h_expe_infra_transz_lim_P.zetapiT_transfers_IC_m;

    /* InitializeConditions for UnitDelay: '<S123>/UD' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_o =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UD_X0_ib;

    /* InitializeConditions for DiscreteIntegrator: '<S122>/4*zeta*pi//T_transfer //s' */
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_e
      = 1U;
    M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetSt_n
      = 2;
  }
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<S4>/GT-RT UDP RX' (gt_rt_udp_receive) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[11];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/GT-RT UDP  Read' (gt_rt_udp_controller) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S126>/GT-RT UDP RX' (gt_rt_udp_receive) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[13];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S126>/GT-RT UDP  Read' (gt_rt_udp_controller) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[14];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S94>/Constant6' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6 =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant6_Value;

  /* Start for Constant: '<S94>/Constant5' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant5 =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant5_Value;

  /* Start for Constant: '<S94>/Constant7' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7 =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant7_Value;

  /* Start for Constant: '<S94>/Constant4' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant4 =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant4_Value;

  /* Start for Constant: '<S94>/Constant8' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant8 =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant8_Value;

  /* Start for Constant: '<S94>/Constant3' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant3 =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value;

  /* Start for Constant: '<S3>/Target PSI' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.TargetPSI =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_P.TargetPSI_Value;

  /* Start for enable SubSystem: '<S3>/Move UP1' */

  /* InitializeConditions for UnitDelay: '<S88>/For saving position  and velocity until after switchover' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.Forsavingpositionandvelocityu_d
    =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Forsavingpositionandvelocity_az;

  /* InitializeConditions for UnitDelay: '<S91>/UD' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.UD_DSTATE_p =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_P.UD_X0_d;

  /* InitializeConditions for DiscreteIntegrator: '<S88>/pi//(zeta*T_transfer)//s' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_IC_LOADING_o
    = 1U;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.pizetaT_transfers_PrevResetS_ot
    = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S88>/4*zeta*pi//T_transfer //s' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_IC_LOADING_mw
    = 1U;
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.zetapiT_transfers_PrevResetS_nn
    = 2;

  /* InitializeConditions for Embedded MATLAB: '<S89>/Embedded MATLAB Function' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c1_M37_Sim_Forcing_00
    = 0U;

  /* InitializeConditions for Embedded MATLAB: '<S68>/curve' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c8_M37_Sim_Forcing_00
    = 0U;

  /* end of Start for SubSystem: '<S3>/Move UP1' */

  /* Level2 S-Function Block: '<S12>/GT-RT CAN RX1' (gt_rt_can_receive) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[15];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S12>/GT-RT CAN RX2' (gt_rt_can_receive) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[16];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S12>/GT-RT CAN RX3' (gt_rt_can_receive) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[17];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S3>/Constant7' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant7_n =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant7_Value_d;

  /* Start for Constant: '<S3>/Constant6' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant6_d =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant6_Value_m;

  /* Start for enable SubSystem: '<S5>/6_DOF Control' */

  /* Level2 S-Function Block: '<S125>/GT-RT UDP TX1' (gt_rt_udp_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S125>/GT-RT UDP TX' (gt_rt_udp_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S125>/GT-RT UDP  Write' (gt_rt_udp_controller) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S125>/GT-RT UDP  Write1' (gt_rt_udp_controller) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* end of Start for SubSystem: '<S5>/6_DOF Control' */

  /* Start for enable SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' */

  /* Level2 S-Function Block: '<S1>/GT-RT UDP TX' (gt_rt_udp_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/GT-RT UDP  Write' (gt_rt_udp_controller) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* end of Start for SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' */

  /* Start for enable SubSystem: '<S138>/Simplified Inverse Kin' */

  /* InitializeConditions for Embedded MATLAB: '<S142>/Embedded MATLAB Function3' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c11_M37_Sim_Forcing_0
    = 0U;

  /* InitializeConditions for Embedded MATLAB: '<S142>/Embedded MATLAB Function2' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c10_M37_Sim_Forcing_0
    = 0U;

  /* InitializeConditions for Embedded MATLAB: '<S142>/Embedded MATLAB Function1' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c27_M37_Sim_Forcing_0
    = 0U;

  /* end of Start for SubSystem: '<S138>/Simplified Inverse Kin' */

  /* Start for enable SubSystem: '<S135>/full inverse kin' */

  /* InitializeConditions for Embedded MATLAB: '<S139>/Embedded MATLAB Function' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork.is_active_c26_M37_Sim_Forcing_0
    = 0U;

  /* end of Start for SubSystem: '<S135>/full inverse kin' */

  /* Start for ifaction SubSystem: '<S13>/If Action Subsystem1' */

  /* Level2 S-Function Block: '<S22>/GT-RT CAN TX' (gt_rt_can_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S22>/GT-RT CAN TX1' (gt_rt_can_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S22>/GT-RT CAN TX2' (gt_rt_can_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* end of Start for SubSystem: '<S13>/If Action Subsystem1' */

  /* Start for Constant: '<S71>/Constant3' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant3_g =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant3_Value_f;

  /* Start for Constant: '<S94>/Constant9' */
  M37_Sim_Forcing_003h_expe_infra_transz_lim_B.Constant9 =
    M37_Sim_Forcing_003h_expe_infra_transz_lim_P.Constant9_Value;

  /* Start for ifaction SubSystem: '<S7>/If Action Subsystem' */

  /* Level2 S-Function Block: '<S127>/GT-RT CAN TX' (gt_rt_can_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* end of Start for SubSystem: '<S7>/If Action Subsystem' */

  /* Level2 S-Function Block: '<S7>/GT-RT CAN RX2' (gt_rt_can_receive) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[18];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for ifaction SubSystem: '<S7>/If Action Subsystem1' */

  /* Level2 S-Function Block: '<S128>/GT-RT CAN TX' (gt_rt_can_send) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* end of Start for SubSystem: '<S7>/If Action Subsystem1' */

  /* Level2 S-Function Block: '<Root>/GT-RT CAN Controller' (gt_rt_can_controller) */
  {
    SimStruct *rts =
      M37_Sim_Forcing_003h_expe_infra_transz_lim_M->childSfunctions[19];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  M37_Sim_Forcing_003h_expe_infra_transz_lim_terminate();
}

RT_MODEL_M37_Sim_Forcing_003h_expe_infra_transz_lim
  *M37_Sim_Forcing_003h_expe_infra_transz_lim(void)
{
  M37_Sim_Forcing_003h_expe_infra_transz_lim_initialize(1);
  return M37_Sim_Forcing_003h_expe_infra_transz_lim_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/

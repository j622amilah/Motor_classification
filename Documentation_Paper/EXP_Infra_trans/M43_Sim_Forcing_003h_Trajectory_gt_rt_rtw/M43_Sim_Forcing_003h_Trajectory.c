/*
 * M43_Sim_Forcing_003h_Trajectory.c
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
 */

#include "M43_Sim_Forcing_003h_Trajectory.h"
#include "M43_Sim_Forcing_003h_Trajectory_private.h"
#include <stdio.h>
#include "M43_Sim_Forcing_003h_Trajectory_dt.h"

/* Block signals (auto storage) */
BlockIO_M43_Sim_Forcing_003h_Trajectory M43_Sim_Forcing_003h_Trajectory_B;

/* Block states (auto storage) */
D_Work_M43_Sim_Forcing_003h_Trajectory M43_Sim_Forcing_003h_Trajectory_DWork;

/* Real-time model */
RT_MODEL_M43_Sim_Forcing_003h_Trajectory M43_Sim_Forcing_003h_Trajectory_M_;
RT_MODEL_M43_Sim_Forcing_003h_Trajectory *M43_Sim_Forcing_003h_Trajectory_M =
  &M43_Sim_Forcing_003h_Trajectory_M_;

/* Forward declaration for local functions */
static void M43_Sim_Forcing_003h_Tra_invNxN(const real_T eml_x[36], real_T
  eml_y[36]);
static real_T M43_Sim_Forcing_003h_Traje_norm(const real_T eml_x[6]);
uint8_T M43_Sim_Forcing_003h_Trajectory_U8GND = 0;/* uint8_T ground */
int64m_T M43_Sim_Forcing_003h_Trajectory_sfix64_En41_GND = { { 0UL, 0UL } };/* int64m_T ground */

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
 *    '<S52>/If Action Subsystem1'
 *    '<S53>/If Action Subsystem1'
 *    '<S54>/If Action Subsystem1'
 *    '<S55>/If Action Subsystem1'
 *    '<S56>/If Action Subsystem1'
 *    '<S57>/If Action Subsystem1'
 */
void M43_Sim_Forc_IfActionSubsystem1(real_T rtu_Inc, real_T rtu_dif,
  rtB_IfActionSubsystem1_M43_Sim_ *localB, rtP_IfActionSubsystem1_M43_Sim_
  *localP)
{
  /* Switch: '<S59>/Switch' incorporates:
   *  Constant: '<S59>/PSEA2'
   */
  if (rtu_dif >= localP->Switch_Threshold) {
    localB->Switch = rtu_Inc;
  } else {
    localB->Switch = localP->PSEA2_Value;
  }
}

/*
 * Output and update for action system:
 *    '<S53>/If Action Subsystem'
 *    '<S54>/If Action Subsystem'
 *    '<S55>/If Action Subsystem'
 *    '<S56>/If Action Subsystem'
 *    '<S57>/If Action Subsystem'
 */
void M43_Sim_Forci_IfActionSubsystem(real_T rtu_Inc, real_T rtu_dif,
  rtB_IfActionSubsystem_M43_Sim_F *localB, rtP_IfActionSubsystem_M43_Sim_F
  *localP)
{
  /* Switch: '<S60>/Switch' incorporates:
   *  Constant: '<S60>/PSEA2'
   */
  if (rtu_dif >= localP->Switch_Threshold) {
    localB->Switch = rtu_Inc;
  } else {
    localB->Switch = localP->PSEA2_Value;
  }
}

/* Function for Embedded MATLAB: '<S113>/Embedded MATLAB Function' */
static void M43_Sim_Forcing_003h_Tra_invNxN(const real_T eml_x[36], real_T
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
    eml_smax = fabs(eml_b_x[eml_loop_ub - 1]);
    for (eml_kAcol = 2; eml_kAcol <= eml_b_k; eml_kAcol++) {
      eml_k++;
      eml_c_x = fabs(eml_b_x[eml_k - 1]);
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

/* Function for Embedded MATLAB: '<S113>/Embedded MATLAB Function' */
static real_T M43_Sim_Forcing_003h_Traje_norm(const real_T eml_x[6])
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
void M43_Sim_Forcing_003h_Trajectory_output(int_T tid)
{
  /* Reset subsysRan breadcrumbs */
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork._DOFVisualCab120615_SubsysRanBC);
  srClearBC(M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_SubsysRanBC);
  srClearBC(M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_SubsysRanBC);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_h.IfActionSubsystem_SubsysRanBC);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_f.IfActionSubsystem1_SubsysRanBC);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_i.IfActionSubsystem_SubsysRanBC);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_k.IfActionSubsystem1_SubsysRanBC);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_d.IfActionSubsystem_SubsysRanBC);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_p.IfActionSubsystem1_SubsysRanBC);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_e.IfActionSubsystem_SubsysRanBC);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_d.IfActionSubsystem1_SubsysRanBC);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_d0.IfActionSubsystem_SubsysRanBC);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC);
  srClearBC(M43_Sim_Forcing_003h_Trajectory_DWork.MoveUP1_SubsysRanBC);
  srClearBC(M43_Sim_Forcing_003h_Trajectory_DWork._DOFControl_SubsysRanBC);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_SubsysRanBC_p);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_SubsysRanB_l);
  srClearBC(M43_Sim_Forcing_003h_Trajectory_DWork.fullinversekin_SubsysRanBC);
  srClearBC
    (M43_Sim_Forcing_003h_Trajectory_DWork.SimplifiedInverseKin_SubsysRanB);

  {
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
    real_T eml_x_p[3];
    real_T eml_A_3[9];
    int32_T eml_r;
    int32_T eml_r_0;
    int32_T eml_r_1;
    real_T eml_maxval;
    real_T eml_x;
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
    boolean_T eml_exitg;
    int32_T i;
    real_T eml_x_0[36];
    real_T tmp[36];
    real_T eml_D_5[9];
    real_T eml_D_6[9];
    real_T eml_D_7[9];
    real_T eml_D_8[16];
    real_T eml_D_9[16];
    real_T eml_D_a[4];
    real_T eml_x_1[16];
    real_T eml_D_b[16];
    real_T eml_D_c[16];
    real_T eml_D_d[16];
    real_T eml_D_e[16];
    real_T eml_D_f[16];
    real_T eml_D_g[4];
    real_T eml_D_h[4];
    real_T eml_D_i[4];
    real_T eml_D_j[4];
    real_T eml_x_2[24];
    real_T eml_A_8[9];
    real_T eml_A_9[9];
    real_T eml_A_a[9];
    real_T eml_A_b[9];
    real_T eml_A_c[9];
    real_T eml_A_d[3];
    real_T eml_A_e[3];
    real_T eml_A_f[3];
    real_T eml_A_g[3];
    real_T eml_A_h[3];
    real_T tmp_0[18];
    real_T eml_A_i[18];
    real_T eml_z_p[6];
    real_T eml_c_idx;
    real_T eml_c_idx_0;
    real_T eml_z_p_idx;
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
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[15];
      sfcnOutputs(rts, 0);
    }

    /* Unpack: <S4>/Unpack */
    (void) memcpy(M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c,
                  M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1,
                  10);
    (void) memcpy(&M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2,
                  &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1[10],
                  4);
    (void) memcpy(M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3,
                  &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1[14],
                  24);
    (void) memcpy(M43_Sim_Forcing_003h_Trajectory_B.Unpack_o4,
                  &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1[38],
                  24);
    (void) memcpy(&M43_Sim_Forcing_003h_Trajectory_B.Unpack_o5,
                  &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1[62],
                  4);

    /* Level2 S-Function Block: '<S4>/GT-RT UDP  Read' (gt_rt_udp_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[16];
      sfcnOutputs(rts, 0);
    }

    /* Level2 S-Function Block: '<S100>/GT-RT UDP RX' (gt_rt_udp_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[17];
      sfcnOutputs(rts, 0);
    }

    /* Unpack: <S100>/Unpack */
    (void) memcpy(M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1,
                  M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_o,
                  12);
    (void) memcpy(M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_p,
                  &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_o[12],
                  8);
    (void) memcpy(&M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3_p,
                  &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_o[20],
                  4);

    /* Level2 S-Function Block: '<S100>/GT-RT UDP  Read' (gt_rt_udp_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[18];
      sfcnOutputs(rts, 0);
    }

    /* Sum: '<S3>/Sum10' incorporates:
     *  Constant: '<S3>/x_e1'
     *  Constant: '<S3>/x_e2'
     */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_e =
      M43_Sim_Forcing_003h_Trajectory_P.x_e2_Value +
      M43_Sim_Forcing_003h_Trajectory_P.x_e1_Value;

    /* DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
    if (((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[3] > 0) &&
         (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_PrevRese <=
          0)) || ((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[3] <= 0) &&
                  (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_PrevRese
                   == 1))) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE =
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC;
    }

    M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1 =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE;

    /* Sum: '<S3>/Sum9' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum9 =
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_e +
      M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1;

    /* DiscreteIntegrator: '<S93>/Discrete-Time Integrator2' */
    if (((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[3] > 0) &&
         (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator2_PrevRes <=
          0)) || ((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[3] <= 0) &&
                  (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator2_PrevRes
                   == 1))) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator2_DSTATE =
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator2_IC;
    }

    M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1 =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator2_DSTATE;

    /* Sum: '<S3>/Sum15' incorporates:
     *  Constant: '<S3>/y_e1'
     */
    M43_Sim_Forcing_003h_Trajectory_B.Sum15 =
      M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1 +
      M43_Sim_Forcing_003h_Trajectory_P.y_e1_Value;

    /* Constant: '<S3>/Target PSI' */
    M43_Sim_Forcing_003h_Trajectory_B.TargetPSI =
      M43_Sim_Forcing_003h_Trajectory_P.TargetPSI_Value;

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/Nominal mid point //!\ check with selected set'
     *  Constant: '<S3>/new mid point'
     */
    M43_Sim_Forcing_003h_Trajectory_B.Sum =
      M43_Sim_Forcing_003h_Trajectory_P.newmidpoint_Value -
      M43_Sim_Forcing_003h_Trajectory_P.Nominalmidpointcheckwithselecte;

    /* Sum: '<S3>/Sum of Elements' */
    M43_Sim_Forcing_003h_Trajectory_B.SumofElements = (uint8_T)(uint32_T)
      ((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[3] +
        M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[4]) +
       M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[5]);

    /* RelationalOperator: '<S71>/Compare' */
    M43_Sim_Forcing_003h_Trajectory_B.Compare =
      (M43_Sim_Forcing_003h_Trajectory_B.SumofElements == 0);

    /* Outputs for enable SubSystem: '<S3>/Move UP1' incorporates:
     *  EnablePort: '<S73>/Enable'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.Compare > 0) {
      /* MultiPortSwitch: '<S73>/Multiport Switch' incorporates:
       *  Constant: '<S3>/Constant1'
       *  Constant: '<S73>/set for optimizing pure z'
       *  Constant: '<S73>/set for optimizing x and y'
       *  Constant: '<S73>/set for optimizing z'
       */
      switch ((int32_T)M43_Sim_Forcing_003h_Trajectory_P.Constant1_Value) {
       case 1:
        for (i = 0; i < 6; i++) {
          M43_Sim_Forcing_003h_Trajectory_B.MultiportSwitch[i] =
            M43_Sim_Forcing_003h_Trajectory_P.setforoptimizingz_Value[i];
        }
        break;

       case 2:
        for (i = 0; i < 6; i++) {
          M43_Sim_Forcing_003h_Trajectory_B.MultiportSwitch[i] =
            M43_Sim_Forcing_003h_Trajectory_P.setforoptimizingpurez_Value[i];
        }
        break;

       default:
        for (i = 0; i < 6; i++) {
          M43_Sim_Forcing_003h_Trajectory_B.MultiportSwitch[i] =
            M43_Sim_Forcing_003h_Trajectory_P.setforoptimizingxandy_Value[i];
        }
        break;
      }

      /* UnitDelay: '<S87>/For saving position  and velocity until after switchover' */
      M43_Sim_Forcing_003h_Trajectory_B.Forsavingpositionandvelocityunt =
        M43_Sim_Forcing_003h_Trajectory_DWork.Forsavingpositionandvelocityunt;

      /* SampleTimeMath: '<S90>/TSamp' */
      /* y = u * K where K = 1 / ( w * Ts )
       */
      M43_Sim_Forcing_003h_Trajectory_B.TSamp =
        M43_Sim_Forcing_003h_Trajectory_B.Forsavingpositionandvelocityunt *
        M43_Sim_Forcing_003h_Trajectory_P.TSamp_WtEt;

      /* UnitDelay: '<S90>/UD' */
      M43_Sim_Forcing_003h_Trajectory_B.Divide =
        M43_Sim_Forcing_003h_Trajectory_DWork.UD_DSTATE;

      /* Sum: '<S90>/Diff' */
      M43_Sim_Forcing_003h_Trajectory_B.Divide =
        M43_Sim_Forcing_003h_Trajectory_B.TSamp -
        M43_Sim_Forcing_003h_Trajectory_B.Divide;

      /* Product: '<S87>/Product' incorporates:
       *  Constant: '<S73>/Constant2'
       */
      M43_Sim_Forcing_003h_Trajectory_B.Divide =
        M43_Sim_Forcing_003h_Trajectory_P.Constant2_Value_e *
        M43_Sim_Forcing_003h_Trajectory_B.Divide;

      /* Gain: '<S87>/(zeta*T_transfer)//pi' */
      M43_Sim_Forcing_003h_Trajectory_B.zetaT_transferpi =
        M43_Sim_Forcing_003h_Trajectory_P.zetaT_transferpi_Gain *
        M43_Sim_Forcing_003h_Trajectory_B.Divide;

      /* DiscreteIntegrator: '<S87>/pi//(zeta*T_transfer)//s' */
      if (M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_IC_LOADING) {
        M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_DSTATE_i =
          M43_Sim_Forcing_003h_Trajectory_B.Forsavingpositionandvelocityunt;
      }

      if (((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[1] > 0) &&
           (M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_PrevResetStat
            <= 0)) || ((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[1] <= 0) &&
                       (M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_PrevResetStat
                        == 1))) {
        M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_DSTATE_i =
          M43_Sim_Forcing_003h_Trajectory_B.Forsavingpositionandvelocityunt;
      }

      M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers_d =
        M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_DSTATE_i;

      /* Sum: '<S87>/Sum2' */
      M43_Sim_Forcing_003h_Trajectory_B.Divide = (real_T)
        M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[1] -
        M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers_d;

      /* DiscreteIntegrator: '<S87>/4*zeta*pi//T_transfer //s' */
      if (M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_IC_LOADING) {
        M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_DSTATE_p =
          M43_Sim_Forcing_003h_Trajectory_B.zetaT_transferpi;
      }

      if (((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[1] > 0) &&
           (M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_PrevResetStat
            <= 0)) || ((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[1] <= 0) &&
                       (M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_PrevResetStat
                        == 1))) {
        M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_DSTATE_p =
          M43_Sim_Forcing_003h_Trajectory_B.zetaT_transferpi;
      }

      M43_Sim_Forcing_003h_Trajectory_B.Divide1_m =
        M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_DSTATE_p;

      /* Sum: '<S87>/Sum1' */
      M43_Sim_Forcing_003h_Trajectory_B.Divide =
        M43_Sim_Forcing_003h_Trajectory_B.Divide -
        M43_Sim_Forcing_003h_Trajectory_B.Divide1_m;

      /* Product: '<S87>/Divide' incorporates:
       *  Constant: '<S73>/Constant2'
       */
      M43_Sim_Forcing_003h_Trajectory_B.Divide =
        M43_Sim_Forcing_003h_Trajectory_B.Divide /
        M43_Sim_Forcing_003h_Trajectory_P.Constant2_Value_e;

      /* Gain: '<S87>/4*zeta*pi' */
      M43_Sim_Forcing_003h_Trajectory_B.zetapi_b =
        M43_Sim_Forcing_003h_Trajectory_P.zetapi_Gain_n *
        M43_Sim_Forcing_003h_Trajectory_B.Divide;

      /* Product: '<S87>/Divide1' incorporates:
       *  Constant: '<S73>/Constant2'
       */
      M43_Sim_Forcing_003h_Trajectory_B.Divide1_m =
        M43_Sim_Forcing_003h_Trajectory_B.Divide1_m /
        M43_Sim_Forcing_003h_Trajectory_P.Constant2_Value_e;

      /* Gain: '<S87>/pi//zeta' */
      M43_Sim_Forcing_003h_Trajectory_B.pizeta_i =
        M43_Sim_Forcing_003h_Trajectory_P.pizeta_Gain_h *
        M43_Sim_Forcing_003h_Trajectory_B.Divide1_m;

      /* Embedded MATLAB: '<S88>/Embedded MATLAB Function' */
      /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Move UP1/add x_offset/Embedded MATLAB Function': '<S91>:1' */
      /* '<S91>:1:4' */
      for (i = 0; i < 6; i++) {
        M43_Sim_Forcing_003h_Trajectory_B.set_out[i] =
          M43_Sim_Forcing_003h_Trajectory_B.MultiportSwitch[i];
      }

      /* '<S91>:1:5' */
      M43_Sim_Forcing_003h_Trajectory_B.set_out[2] =
        M43_Sim_Forcing_003h_Trajectory_B.MultiportSwitch[2] +
        M43_Sim_Forcing_003h_Trajectory_B.Sum;

      /* Embedded MATLAB: '<S73>/curve' */
      /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Move UP1/curve': '<S89>:1' */
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
      /* '<S89>:1:17' */
      /* '<S89>:1:18' */
      /* '<S89>:1:20' */
      eml_x_p[0] = M43_Sim_Forcing_003h_Trajectory_B.set_out[0];
      eml_A_3[0] = M43_Sim_Forcing_003h_Trajectory_B.set_out[3] *
        M43_Sim_Forcing_003h_Trajectory_B.set_out[3];
      eml_x_p[1] = M43_Sim_Forcing_003h_Trajectory_B.set_out[1];
      eml_A_3[1] = M43_Sim_Forcing_003h_Trajectory_B.set_out[4] *
        M43_Sim_Forcing_003h_Trajectory_B.set_out[4];
      eml_x_p[2] = M43_Sim_Forcing_003h_Trajectory_B.set_out[2];
      eml_A_3[2] = M43_Sim_Forcing_003h_Trajectory_B.set_out[5] *
        M43_Sim_Forcing_003h_Trajectory_B.set_out[5];
      eml_A_3[3] = M43_Sim_Forcing_003h_Trajectory_B.set_out[3];
      eml_A_3[4] = M43_Sim_Forcing_003h_Trajectory_B.set_out[4];
      eml_A_3[5] = M43_Sim_Forcing_003h_Trajectory_B.set_out[5];
      eml_A_3[6] = 1.0;
      eml_A_3[7] = 1.0;
      eml_A_3[8] = 1.0;

      /* '<S89>:1:21' */
      eml_r = 1;
      eml_r_0 = 2;
      eml_r_1 = 3;
      eml_maxval = fabs(eml_A_3[0]);
      eml_x = fabs(eml_A_3[1]);
      if (eml_x > eml_maxval) {
        eml_maxval = eml_x;
        eml_r = 2;
        eml_r_0 = 1;
      }

      if (fabs(eml_A_3[2]) > eml_maxval) {
        eml_r = 3;
        eml_r_0 = 2;
        eml_r_1 = 1;
      }

      eml_A_3[eml_r_0 - 1] /= eml_A_3[eml_r - 1];
      eml_A_3[eml_r_1 - 1] /= eml_A_3[eml_r - 1];
      eml_A_3[eml_r_0 + 2] -= eml_A_3[eml_r_0 - 1] * eml_A_3[eml_r + 2];
      eml_A_3[eml_r_1 + 2] -= eml_A_3[eml_r_1 - 1] * eml_A_3[eml_r + 2];
      eml_A_3[eml_r_0 + 5] = 1.0 - eml_A_3[eml_r_0 - 1];
      eml_A_3[eml_r_1 + 5] -= eml_A_3[eml_r_1 - 1] * eml_A_3[eml_r + 5];
      if (fabs(eml_A_3[eml_r_1 + 2]) > fabs(eml_A_3[eml_r_0 + 2])) {
        i = eml_r_0;
        eml_r_0 = eml_r_1;
        eml_r_1 = i;
      }

      eml_A_3[eml_r_1 + 2] /= eml_A_3[eml_r_0 + 2];
      eml_A_3[eml_r_1 + 5] -= eml_A_3[eml_r_1 + 2] * eml_A_3[eml_r_0 + 5];
      eml_maxval = eml_x_p[eml_r - 1];
      eml_c_idx = eml_x_p[eml_r_0 - 1] - eml_A_3[eml_r_0 - 1] * eml_maxval;
      eml_c_idx_0 = ((eml_x_p[eml_r_1 - 1] - eml_A_3[eml_r_1 - 1] * eml_maxval)
                     - eml_A_3[eml_r_1 + 2] * eml_c_idx) / eml_A_3[eml_r_1 + 5];
      eml_maxval -= eml_A_3[eml_r + 5] * eml_c_idx_0;
      eml_c_idx -= eml_A_3[eml_r_0 + 5] * eml_c_idx_0;
      eml_c_idx /= eml_A_3[eml_r_0 + 2];
      eml_maxval -= eml_A_3[eml_r + 2] * eml_c_idx;
      eml_maxval /= eml_A_3[eml_r - 1];

      /* '<S89>:1:23' */
      M43_Sim_Forcing_003h_Trajectory_B.z =
        (M43_Sim_Forcing_003h_Trajectory_B.set_out[5] -
         M43_Sim_Forcing_003h_Trajectory_B.set_out[3]) *
        M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers_d +
        M43_Sim_Forcing_003h_Trajectory_B.set_out[3];

      /* '<S89>:1:25' */
      M43_Sim_Forcing_003h_Trajectory_B.x = 0.0;
      M43_Sim_Forcing_003h_Trajectory_B.x = M43_Sim_Forcing_003h_Trajectory_B.z *
        M43_Sim_Forcing_003h_Trajectory_B.z * eml_maxval +
        M43_Sim_Forcing_003h_Trajectory_B.x;
      M43_Sim_Forcing_003h_Trajectory_B.x = M43_Sim_Forcing_003h_Trajectory_B.z *
        eml_c_idx + M43_Sim_Forcing_003h_Trajectory_B.x;
      M43_Sim_Forcing_003h_Trajectory_B.x = M43_Sim_Forcing_003h_Trajectory_B.x
        + eml_c_idx_0;

      /* '<S89>:1:27' */
      M43_Sim_Forcing_003h_Trajectory_B.psi =
        M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers_d *
        M43_Sim_Forcing_003h_Trajectory_B.TargetPSI;
      srUpdateBC(M43_Sim_Forcing_003h_Trajectory_DWork.MoveUP1_SubsysRanBC);
    }

    /* end of Outputs for SubSystem: '<S3>/Move UP1' */

    /* Sum: '<S3>/Sum13' incorporates:
     *  Constant: '<S3>/z_e1'
     */
    M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1 =
      M43_Sim_Forcing_003h_Trajectory_B.z +
      M43_Sim_Forcing_003h_Trajectory_P.z_e1_Value;

    /* DiscreteIntegrator: '<S94>/Discrete-Time Integrator1' */
    if (((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[5] > 0) &&
         (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevRes <=
          0)) || ((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[5] <= 0) &&
                  (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevRes
                   == 1))) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTATE =
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC;
    }

    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_e =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTATE;

    /* Sum: '<S3>/Sum11' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum11 =
      M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1 +
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_e;

    /* Constant: '<S3>/Phi1' */
    M43_Sim_Forcing_003h_Trajectory_B.Phi1 =
      M43_Sim_Forcing_003h_Trajectory_P.Phi1_Value;

    /* Constant: '<S3>/Theta1' */
    M43_Sim_Forcing_003h_Trajectory_B.Theta1 =
      M43_Sim_Forcing_003h_Trajectory_P.Theta1_Value;

    /* DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
    if (((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[4] > 0) &&
         (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_p <=
          0)) || ((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[4] <= 0) &&
                  (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_p
                   == 1))) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_d =
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_m;
    }

    M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1 =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_d;

    /* Sum: '<S3>/Sum3' incorporates:
     *  Constant: '<S3>/y_e2'
     */
    M43_Sim_Forcing_003h_Trajectory_B.Sum3 =
      M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1 +
      M43_Sim_Forcing_003h_Trajectory_P.y_e2_Value;

    /* DiscreteTransferFcn: '<S13>/Butterworth Filter 10 Hz' */
    for (eml_r_0 = 0; eml_r_0 < 3; eml_r_0++) {
      eml_r_1 = eml_r_0 << 2;
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp_p[eml_r_0]
        = ((((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1[eml_r_0] -
              M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denomin_f
              [1] *
              M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a
              [eml_r_1]) -
             M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a
             [eml_r_1 + 1] *
             M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denomin_f[2])
            - M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a
            [eml_r_1 + 2] *
            M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denomin_f[3])
           - M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a
           [eml_r_1 + 3] *
           M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denomin_f[4])
        / M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denomin_f[0];
      M43_Sim_Forcing_003h_Trajectory_B.ButterworthFilter10Hz_i[eml_r_0] =
        (((M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerat_k[0] *
           M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp_p[eml_r_0]
           + M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerat_k[1]
           * M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a
           [eml_r_1]) +
          M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a[eml_r_1
          + 1] *
          M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerat_k[2])
         + M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a[eml_r_1
         + 2] *
         M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerat_k[3]) +
        M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a[eml_r_1
        + 3] *
        M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerat_k[4];
    }

    /* Gain: '<S13>/Gain2' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_be =
      M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_mm *
      M43_Sim_Forcing_003h_Trajectory_B.ButterworthFilter10Hz_i[1];

    /* Gain: '<S13>/Gain3' */
    M43_Sim_Forcing_003h_Trajectory_B.Alpha =
      M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_k *
      M43_Sim_Forcing_003h_Trajectory_B.ButterworthFilter10Hz_i[2];

    /* Gain: '<S13>/Gain1' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain1_o[0] =
      M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_g *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_be;
    M43_Sim_Forcing_003h_Trajectory_B.Gain1_o[1] =
      M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_g *
      M43_Sim_Forcing_003h_Trajectory_B.ButterworthFilter10Hz_i[0];
    M43_Sim_Forcing_003h_Trajectory_B.Gain1_o[2] =
      M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_g *
      M43_Sim_Forcing_003h_Trajectory_B.Alpha;

    /* Level2 S-Function Block: '<S17>/GT-RT CAN RX1' (gt_rt_can_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[19];
      sfcnOutputs(rts, 0);
    }

    /* Gain: '<S21>/Gain2' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain4_f = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_g *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o2[1]);

    /* Gain: '<S21>/Gain3' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain3_h = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_f *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o2[2]);

    /* Gain: '<S21>/Gain4' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain2_d = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_m1 *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o2[3]);

    /* Sum: '<S21>/Add' */
    M43_Sim_Forcing_003h_Trajectory_B.Add = (int32_T)((uint32_T)
      (((M43_Sim_Forcing_003h_Trajectory_B.Gain4_f << 1) +
        M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o2[0]) +
       (M43_Sim_Forcing_003h_Trajectory_B.Gain3_h << 9)) + ((uint32_T)
      M43_Sim_Forcing_003h_Trajectory_B.Gain2_d << 17U));

    /* Gain: '<S17>/Gain' */
    tmp_1 = (uint32_T)M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_it;
    tmp_2 = (uint32_T)M43_Sim_Forcing_003h_Trajectory_B.Add;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_3.chunks[0U], 2);
    M43_Sim_Forcing_003h_Trajectory_B.Gain_m = tmp_3;

    /* Gain: '<S22>/Gain2' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain2_d = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_k *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o2[5]);

    /* Gain: '<S22>/Gain3' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain3_h = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_b *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o2[6]);

    /* Gain: '<S22>/Gain4' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain4_f = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_e *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o2[7]);

    /* Sum: '<S22>/Add' */
    M43_Sim_Forcing_003h_Trajectory_B.Add = (int32_T)((uint32_T)
      (((M43_Sim_Forcing_003h_Trajectory_B.Gain2_d << 1) +
        M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o2[4]) +
       (M43_Sim_Forcing_003h_Trajectory_B.Gain3_h << 9)) + ((uint32_T)
      M43_Sim_Forcing_003h_Trajectory_B.Gain4_f << 17U));

    /* Gain: '<S17>/Gain2' */
    tmp_1 = (uint32_T)M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_a;
    tmp_2 = (uint32_T)M43_Sim_Forcing_003h_Trajectory_B.Add;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_4.chunks[0U], 2);
    M43_Sim_Forcing_003h_Trajectory_B.Gain2_e = tmp_4;

    /* Level2 S-Function Block: '<S17>/GT-RT CAN RX2' (gt_rt_can_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[20];
      sfcnOutputs(rts, 0);
    }

    /* Gain: '<S23>/Gain2' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain2_d = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_f *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o2[1]);

    /* Gain: '<S23>/Gain3' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain3_h = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_mk *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o2[2]);

    /* Gain: '<S23>/Gain4' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain4_f = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_ck *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o2[3]);

    /* Sum: '<S23>/Add' */
    M43_Sim_Forcing_003h_Trajectory_B.Add = (int32_T)((uint32_T)
      (((M43_Sim_Forcing_003h_Trajectory_B.Gain2_d << 1) +
        M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o2[0]) +
       (M43_Sim_Forcing_003h_Trajectory_B.Gain3_h << 9)) + ((uint32_T)
      M43_Sim_Forcing_003h_Trajectory_B.Gain4_f << 17U));

    /* Gain: '<S17>/Gain6' */
    tmp_1 = (uint32_T)M43_Sim_Forcing_003h_Trajectory_P.Gain6_Gain;
    tmp_2 = (uint32_T)M43_Sim_Forcing_003h_Trajectory_B.Add;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_5.chunks[0U], 2);
    M43_Sim_Forcing_003h_Trajectory_B.Gain6 = tmp_5;

    /* Gain: '<S24>/Gain2' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain2_d = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_h *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o2[5]);

    /* Gain: '<S24>/Gain3' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain3_h = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_mo *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o2[6]);

    /* Gain: '<S24>/Gain4' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain4_f = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_e0 *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o2[7]);

    /* Sum: '<S24>/Add' */
    M43_Sim_Forcing_003h_Trajectory_B.Add = (int32_T)((uint32_T)
      (((M43_Sim_Forcing_003h_Trajectory_B.Gain2_d << 1) +
        M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o2[4]) +
       (M43_Sim_Forcing_003h_Trajectory_B.Gain3_h << 9)) + ((uint32_T)
      M43_Sim_Forcing_003h_Trajectory_B.Gain4_f << 17U));

    /* Gain: '<S17>/Gain1' */
    tmp_1 = (uint32_T)M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_b;
    tmp_2 = (uint32_T)M43_Sim_Forcing_003h_Trajectory_B.Add;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_6.chunks[0U], 2);
    M43_Sim_Forcing_003h_Trajectory_B.Gain1_e = tmp_6;

    /* Level2 S-Function Block: '<S17>/GT-RT CAN RX3' (gt_rt_can_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[21];
      sfcnOutputs(rts, 0);
    }

    /* Gain: '<S25>/Gain2' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain2_d = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_ia *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o2[1]);

    /* Gain: '<S25>/Gain3' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain3_h = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_kp *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o2[2]);

    /* Gain: '<S25>/Gain4' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain4_f = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_l *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o2[3]);

    /* Sum: '<S25>/Add' */
    M43_Sim_Forcing_003h_Trajectory_B.Add = (int32_T)((uint32_T)
      (((M43_Sim_Forcing_003h_Trajectory_B.Gain2_d << 1) +
        M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o2[0]) +
       (M43_Sim_Forcing_003h_Trajectory_B.Gain3_h << 9)) + ((uint32_T)
      M43_Sim_Forcing_003h_Trajectory_B.Gain4_f << 17U));

    /* Gain: '<S17>/Gain3' */
    tmp_1 = (uint32_T)M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_d;
    tmp_2 = (uint32_T)M43_Sim_Forcing_003h_Trajectory_B.Add;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_7.chunks[0U], 2);
    M43_Sim_Forcing_003h_Trajectory_B.Gain3_b = tmp_7;

    /* Gain: '<S26>/Gain2' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain2_d = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_ip *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o2[5]);

    /* Gain: '<S26>/Gain3' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain3_h = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_d2 *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o2[6]);

    /* Gain: '<S26>/Gain4' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain4_f = (uint16_T)
      (M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_b *
       M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o2[7]);

    /* Sum: '<S26>/Add' */
    M43_Sim_Forcing_003h_Trajectory_B.Add = (int32_T)((uint32_T)
      (((M43_Sim_Forcing_003h_Trajectory_B.Gain2_d << 1) +
        M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o2[4]) +
       (M43_Sim_Forcing_003h_Trajectory_B.Gain3_h << 9)) + ((uint32_T)
      M43_Sim_Forcing_003h_Trajectory_B.Gain4_f << 17U));

    /* Gain: '<S17>/Gain4' */
    tmp_1 = (uint32_T)M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_fc;
    tmp_2 = (uint32_T)M43_Sim_Forcing_003h_Trajectory_B.Add;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_8.chunks[0U], 2);
    M43_Sim_Forcing_003h_Trajectory_B.Gain4_m = tmp_8;

    /* DataTypeConversion: '<S107>/Data Type Conversion' */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain_m;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[0] = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain2_e;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[1] = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain6;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[2] = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain1_e;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[3] = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain3_b;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[4] = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain4_m;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[5] = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41);

    /* Sum: '<S107>/Sum3' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_e =
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[0] -
      M43_Sim_Forcing_003h_Trajectory_B.psi;

    /* Gain: '<S109>/Gain' */
    eml_ang_0[0] = M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_e;
    for (i = 0; i < 5; i++) {
      eml_ang_0[i + 1] =
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[1 + i];
    }

    /* Embedded MATLAB: '<S104>/Embedded MATLAB Function' */
    /* Embedded MATLAB Function 'Joint Controller (May 7, 2015)/Forward Kinematics/Embedded MATLAB Function': '<S108>:1' */
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
    /* '<S108>:1:34' */
    /*  Initial guess of the joint angles, in deg */
    /* '<S108>:1:35' */
    /*  reserve place for output */
    /* '<S108>:1:38' */
    /*  define length of arms */
    /* '<S108>:1:41' */
    /*  arm length in cm */
    /* '<S108>:1:42' */
    /* '<S108>:1:43' */
    /* '<S108>:1:44' */
    /* '<S108>:1:45' */
    /* '<S108>:1:46' */
    /*  vertical offset of the center line of */
    /*  joint 4 from centerline of arm A3 */
    /* '<S108>:1:48' */
    /*  height link A2 above the ground */
    /*  4x4 Transfer matrices, include both rotation and translation */
    /* '<S108>:1:53' */
    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[i] =
        M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain[i] * eml_ang_0[i];

      /* Sum: '<S109>/Sum' incorporates:
       *  Constant: '<S109>/Constant'
       */
      M43_Sim_Forcing_003h_Trajectory_B.Sum_j[i] =
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[i] +
        M43_Sim_Forcing_003h_Trajectory_P.Constant_Value[i];
      M43_Sim_Forcing_003h_Trajectory_B.out_m[i] = 0.0;
      eml_ang[i] = M43_Sim_Forcing_003h_Trajectory_B.Sum_j[i] *
        1.7453292519943295E-002;
    }

    for (eml_r = 0; eml_r < 6; eml_r++) {
      for (eml_A = eml_ang[eml_r]; eml_A > 3.1415926535897931E+000; eml_A -=
           6.2831853071795862E+000) {
      }

      while (eml_A < -3.1415926535897931E+000) {
        eml_A += 6.2831853071795862E+000;
      }

      eml_ang[eml_r] = eml_A;
    }

    /*  ang is brought in the range +-pi */
    /* '<S108>:1:54' */
    /* '<S108>:1:55' */
    /* '<S108>:1:56' */
    /* '<S108>:1:57' */
    /* '<S108>:1:58' */
    /* '<S108>:1:59' */
    /* '<S108>:1:61' */
    eml_maxval = cos(eml_ang[0]);

    /* '<S108>:1:62' */
    eml_x = sin(eml_ang[0]);

    /* '<S108>:1:63' */
    eml_CA = cos(eml_ang[1]);

    /* '<S108>:1:64' */
    eml_SA = sin(eml_ang[1]);

    /* '<S108>:1:65' */
    eml_CA_0 = cos(eml_ang[2]);

    /* '<S108>:1:66' */
    eml_SA_0 = sin(eml_ang[2]);

    /* '<S108>:1:67' */
    eml_CA_1 = cos(eml_ang[3]);

    /* '<S108>:1:68' */
    eml_A_2 = sin(eml_ang[3]);

    /* '<S108>:1:69' */
    eml_CA_2 = cos(eml_ang[4]);

    /* '<S108>:1:70' */
    eml_A_0 = sin(eml_ang[4]);

    /* '<S108>:1:71' */
    eml_A_1 = cos(eml_ang[5]);

    /* '<S108>:1:72' */
    eml_A = sin(eml_ang[5]);

    /* '<S108>:1:74' */
    eml_D[0] = eml_maxval;
    eml_D[4] = -eml_x;
    eml_D[8] = 0.0;
    eml_D[12] = 0.0;
    eml_D[1] = eml_x;
    eml_D[5] = eml_maxval;
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

    /* '<S108>:1:75' */
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

    /* '<S108>:1:76' */
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

    /* '<S108>:1:77' */
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

    /* '<S108>:1:78' */
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

    /* '<S108>:1:79' */
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
    /* '<S108>:1:83' */
    /* '<S108>:1:84' */
    /* '<S108>:1:85' */
    /* '<S108>:1:86' */
    /* '<S108>:1:87' */
    /* '<S108>:1:88' */
    /*  --- computed position from links A1-A6 --- */
    /*  x,y,z cabin reference point (cm) */
    /*  to which the translation is made */
    /* '<S108>:1:95' */
    /* '<S108>:1:96' */
    /*  position of the cabin reference point in the */
    /*  NED system (cm) */
    /*  computed Euler angles from links A1-A6 */
    /*  Euler matrices for rotation from e->b (note the transpose) */
    /* '<S108>:1:101' */
    for (i = 0; i < 3; i++) {
      for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
        eml_D_5[i + 3 * eml_r_1] = 0.0;
        eml_D_5[i + 3 * eml_r_1] = eml_D_5[3 * eml_r_1 + i] + eml_D_4[i << 2] *
          eml_D_3[eml_r_1];
        eml_D_5[i + 3 * eml_r_1] = eml_D_4[(i << 2) + 1] * eml_D_3[eml_r_1 + 4]
          + eml_D_5[3 * eml_r_1 + i];
        eml_D_5[i + 3 * eml_r_1] = eml_D_4[(i << 2) + 2] * eml_D_3[eml_r_1 + 8]
          + eml_D_5[3 * eml_r_1 + i];
      }
    }

    for (i = 0; i < 3; i++) {
      for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
        eml_D_6[i + 3 * eml_r_1] = 0.0;
        eml_D_6[i + 3 * eml_r_1] = eml_D_6[3 * eml_r_1 + i] + eml_D_5[i] *
          eml_D_2[eml_r_1];
        eml_D_6[i + 3 * eml_r_1] = eml_D_6[3 * eml_r_1 + i] + eml_D_5[i + 3] *
          eml_D_2[eml_r_1 + 4];
        eml_D_6[i + 3 * eml_r_1] = eml_D_6[3 * eml_r_1 + i] + eml_D_5[i + 6] *
          eml_D_2[eml_r_1 + 8];
      }
    }

    for (i = 0; i < 3; i++) {
      for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
        eml_D_7[i + 3 * eml_r_1] = 0.0;
        eml_D_7[i + 3 * eml_r_1] = eml_D_7[3 * eml_r_1 + i] + eml_D_6[i] *
          eml_D_1[eml_r_1];
        eml_D_7[i + 3 * eml_r_1] = eml_D_7[3 * eml_r_1 + i] + eml_D_6[i + 3] *
          eml_D_1[eml_r_1 + 4];
        eml_D_7[i + 3 * eml_r_1] = eml_D_7[3 * eml_r_1 + i] + eml_D_6[i + 6] *
          eml_D_1[eml_r_1 + 8];
      }
    }

    for (i = 0; i < 3; i++) {
      for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
        eml_D_5[i + 3 * eml_r_1] = 0.0;
        eml_D_5[i + 3 * eml_r_1] = eml_D_5[3 * eml_r_1 + i] + eml_D_7[i] *
          eml_D_0[eml_r_1];
        eml_D_5[i + 3 * eml_r_1] = eml_D_5[3 * eml_r_1 + i] + eml_D_7[i + 3] *
          eml_D_0[eml_r_1 + 4];
        eml_D_5[i + 3 * eml_r_1] = eml_D_5[3 * eml_r_1 + i] + eml_D_7[i + 6] *
          eml_D_0[eml_r_1 + 8];
      }
    }

    for (i = 0; i < 3; i++) {
      for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
        eml_A_3[i + 3 * eml_r_1] = 0.0;
        eml_A_3[i + 3 * eml_r_1] = eml_A_3[3 * eml_r_1 + i] + eml_D_5[i] *
          eml_D[eml_r_1];
        eml_A_3[i + 3 * eml_r_1] = eml_A_3[3 * eml_r_1 + i] + eml_D_5[i + 3] *
          eml_D[eml_r_1 + 4];
        eml_A_3[i + 3 * eml_r_1] = eml_A_3[3 * eml_r_1 + i] + eml_D_5[i + 6] *
          eml_D[eml_r_1 + 8];
      }
    }

    /* '<S108>:1:102' */
    /*  DCM to Euler angles */
    /*  place into output vector */
    /* '<S108>:1:105' */
    for (i = 0; i < 4; i++) {
      for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
        eml_D_8[i + (eml_r_1 << 2)] = 0.0;
        eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
          eml_D_0[eml_r_1 << 2] * eml_D[i];
        eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 1] * eml_D[i + 4]
          + eml_D_8[(eml_r_1 << 2) + i];
        eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 2] * eml_D[i + 8]
          + eml_D_8[(eml_r_1 << 2) + i];
        eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 3] * eml_D[i + 12]
          + eml_D_8[(eml_r_1 << 2) + i];
      }
    }

    for (i = 0; i < 4; i++) {
      for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
        eml_D_9[i + (eml_r_1 << 2)] = 0.0;
        eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
          eml_D_1[eml_r_1 << 2] * eml_D_8[i];
        eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 1] * eml_D_8[i +
          4] + eml_D_9[(eml_r_1 << 2) + i];
        eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 2] * eml_D_8[i +
          8] + eml_D_9[(eml_r_1 << 2) + i];
        eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 3] * eml_D_8[i +
          12] + eml_D_9[(eml_r_1 << 2) + i];
      }
    }

    for (i = 0; i < 4; i++) {
      for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
        eml_D_8[i + (eml_r_1 << 2)] = 0.0;
        eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
          eml_D_2[eml_r_1 << 2] * eml_D_9[i];
        eml_D_8[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 1] * eml_D_9[i +
          4] + eml_D_8[(eml_r_1 << 2) + i];
        eml_D_8[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 2] * eml_D_9[i +
          8] + eml_D_8[(eml_r_1 << 2) + i];
        eml_D_8[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 3] * eml_D_9[i +
          12] + eml_D_8[(eml_r_1 << 2) + i];
      }
    }

    for (i = 0; i < 4; i++) {
      for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
        eml_D_9[i + (eml_r_1 << 2)] = 0.0;
        eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
          eml_D_3[eml_r_1 << 2] * eml_D_8[i];
        eml_D_9[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 1] * eml_D_8[i +
          4] + eml_D_9[(eml_r_1 << 2) + i];
        eml_D_9[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 2] * eml_D_8[i +
          8] + eml_D_9[(eml_r_1 << 2) + i];
        eml_D_9[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 3] * eml_D_8[i +
          12] + eml_D_9[(eml_r_1 << 2) + i];
      }
    }

    for (i = 0; i < 4; i++) {
      for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
        eml_D_8[i + (eml_r_1 << 2)] = 0.0;
        eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
          eml_D_4[eml_r_1 << 2] * eml_D_9[i];
        eml_D_8[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 1] * eml_D_9[i +
          4] + eml_D_8[(eml_r_1 << 2) + i];
        eml_D_8[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 2] * eml_D_9[i +
          8] + eml_D_8[(eml_r_1 << 2) + i];
        eml_D_8[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 3] * eml_D_9[i +
          12] + eml_D_8[(eml_r_1 << 2) + i];
      }
    }

    for (i = 0; i < 4; i++) {
      eml_maxval = eml_D_8[i + 12] + (eml_D_8[i + 8] * 0.0 + (eml_D_8[i + 4] *
        0.0 + eml_D_8[i] * 0.0));
      eml_D_a[i] = eml_maxval;
    }

    M43_Sim_Forcing_003h_Trajectory_B.out_m[0] = eml_D_a[0];
    M43_Sim_Forcing_003h_Trajectory_B.out_m[1] = eml_D_a[1];
    M43_Sim_Forcing_003h_Trajectory_B.out_m[2] = eml_D_a[2] - 210.5;

    /* '<S108>:1:106' */
    M43_Sim_Forcing_003h_Trajectory_B.out_m[3] = 5.7295779513082323E+001 *
      rt_atan2_snf(eml_A_3[7], eml_A_3[8]);
    M43_Sim_Forcing_003h_Trajectory_B.out_m[4] = 5.7295779513082323E+001 *
      (-asin(eml_A_3[6]));
    M43_Sim_Forcing_003h_Trajectory_B.out_m[5] = 5.7295779513082323E+001 *
      rt_atan2_snf(eml_A_3[3], eml_A_3[0]);

    /* Level2 S-Function Block: '<S6>/GT-RT UDP RX' (gt_rt_udp_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[22];
      sfcnOutputs(rts, 0);
    }

    /* Unpack: <S6>/Unpack */
    (void) memcpy(&M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_a,
                  M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_f,
                  4);
    (void) memcpy(&M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_a,
                  &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_f[4],
                  4);
    (void) memcpy(&M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3_k,
                  &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_f[8],
                  4);
    (void) memcpy(&M43_Sim_Forcing_003h_Trajectory_B.Unpack_o4_n,
                  &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_f[12],
                  4);
    (void) memcpy(&M43_Sim_Forcing_003h_Trajectory_B.Unpack_o5_o,
                  &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_f[16],
                  4);
    (void) memcpy(&M43_Sim_Forcing_003h_Trajectory_B.Unpack_o6,
                  &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_f[20],
                  4);

    /* Switch: '<S7>/SwitchControl' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<S7>/Constant'
     */
    if (M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_g >
        M43_Sim_Forcing_003h_Trajectory_P.SwitchControl_Threshold) {
      M43_Sim_Forcing_003h_Trajectory_B.SwitchControl =
        M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_f;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.SwitchControl = 0.0;
    }

    /* Outputs for enable SubSystem: '<S5>/6_DOF Control' incorporates:
     *  EnablePort: '<S99>/Enable'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.SwitchControl > 0.0) {
      /* DataTypeConversion: '<S99>/Data Type Conversion' */
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion[0] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum9;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion[1] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum15;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion[2] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum11;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion[3] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Phi1;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion[4] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Theta1;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion[5] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum3;

      /* DataTypeConversion: '<S99>/Data Type Conversion3' */
      for (i = 0; i < 6; i++) {
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_m[i] = (real32_T)
          M43_Sim_Forcing_003h_Trajectory_B.out_m[i];
      }

      /* Byte Packing: <S99>/Byte Packing  */
      (void)memcpy((uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.BytePacking + 0,
                   (uint8_T*)
                   M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion, 24);
      (void)memcpy((uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.BytePacking + 24,
                   (uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.Gain1_o, 12);
      (void)memcpy((uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.BytePacking + 36,
                   (uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_p, 8);
      (void)memcpy((uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.BytePacking + 44,
                   (uint8_T*)&M43_Sim_Forcing_003h_Trajectory_B.Unpack_o5, 4);
      (void)memcpy((uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.BytePacking + 48,
                   (uint8_T*)
                   M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_m, 24);

      /* Switch: '<S101>/Switch1' incorporates:
       *  Constant: '<S99>/Constant'
       */
      if (M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_hy >=
          M43_Sim_Forcing_003h_Trajectory_P.Switch1_Threshold) {
        M43_Sim_Forcing_003h_Trajectory_B.Sum2_n =
          M43_Sim_Forcing_003h_Trajectory_B.Unpack_o5_o;
      } else {
        M43_Sim_Forcing_003h_Trajectory_B.Sum2_n = 0.0F;
      }

      /* Sum: '<S101>/Sum2' */
      M43_Sim_Forcing_003h_Trajectory_B.Sum2_n =
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion[3] +
        M43_Sim_Forcing_003h_Trajectory_B.Sum2_n;

      /* Switch: '<S101>/Switch' incorporates:
       *  Constant: '<S99>/Constant'
       */
      if (M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_hy >=
          M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_ki) {
        M43_Sim_Forcing_003h_Trajectory_B.Sum_m =
          M43_Sim_Forcing_003h_Trajectory_B.Unpack_o4_n;
      } else {
        M43_Sim_Forcing_003h_Trajectory_B.Sum_m = 0.0F;
      }

      /* Sum: '<S101>/Sum' */
      M43_Sim_Forcing_003h_Trajectory_B.Sum_m =
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion[4] +
        M43_Sim_Forcing_003h_Trajectory_B.Sum_m;

      /* Switch: '<S101>/Switch2' incorporates:
       *  Constant: '<S99>/Constant'
       */
      if (M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_hy >=
          M43_Sim_Forcing_003h_Trajectory_P.Switch2_Threshold) {
        /* Sum: '<S99>/Sum' incorporates:
         *  Constant: '<S99>/Constant7'
         */
        M43_Sim_Forcing_003h_Trajectory_B.Sum_c = (real_T)
          M43_Sim_Forcing_003h_Trajectory_B.Unpack_o6 +
          M43_Sim_Forcing_003h_Trajectory_P.Constant7_Value;
        M43_Sim_Forcing_003h_Trajectory_B.Switch2 =
          M43_Sim_Forcing_003h_Trajectory_B.Sum_c;
      } else {
        M43_Sim_Forcing_003h_Trajectory_B.Switch2 = 0.0;
      }

      /* DataTypeConversion: '<S101>/Data Type Conversion1' */
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_b = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Switch2;

      /* Sum: '<S101>/Sum1' */
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_b =
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion[5] +
        M43_Sim_Forcing_003h_Trajectory_B.Sum1_b;

      /* DataTypeConversion: '<S101>/Data Type Conversion3' */
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_p[0] =
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion[0];
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_p[1] =
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion[1];
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_p[2] =
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion[2];
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_p[3] =
        M43_Sim_Forcing_003h_Trajectory_B.Sum2_n;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_p[4] =
        M43_Sim_Forcing_003h_Trajectory_B.Sum_m;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_p[5] =
        M43_Sim_Forcing_003h_Trajectory_B.Sum1_b;

      /* Byte Packing: <S99>/Byte Packing 1 */
      (void)memcpy((uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.BytePacking1 + 0,
                   (uint8_T*)
                   M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_p, 24);

      /* Byte Packing: <S99>/Byte Packing 2 */
      (void)memcpy((uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.BytePacking2 + 0,
                   (uint8_T*)
                   M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion, 24);

      /* Level2 S-Function Block: '<S99>/GT-RT UDP TX' (gt_rt_udp_send) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[7];
        sfcnOutputs(rts, 0);
      }

      /* Level2 S-Function Block: '<S99>/GT-RT UDP TX1' (gt_rt_udp_send) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[8];
        sfcnOutputs(rts, 0);
      }

      /* Level2 S-Function Block: '<S99>/GT-RT UDP TX2' (gt_rt_udp_send) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[9];
        sfcnOutputs(rts, 0);
      }

      /* Level2 S-Function Block: '<S99>/GT-RT UDP  Write' (gt_rt_udp_controller) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[10];
        sfcnOutputs(rts, 0);
      }

      /* Level2 S-Function Block: '<S99>/GT-RT UDP  Write1' (gt_rt_udp_controller) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[11];
        sfcnOutputs(rts, 0);
      }

      /* Level2 S-Function Block: '<S99>/GT-RT UDP  Write2' (gt_rt_udp_controller) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[12];
        sfcnOutputs(rts, 0);
      }

      srUpdateBC(M43_Sim_Forcing_003h_Trajectory_DWork._DOFControl_SubsysRanBC);
    }

    /* end of Outputs for SubSystem: '<S5>/6_DOF Control' */

    /* Sum: '<S6>/Sum2' incorporates:
     *  Constant: '<S6>/Constant2'
     */
    M43_Sim_Forcing_003h_Trajectory_B.Sum2 =
      M43_Sim_Forcing_003h_Trajectory_P.Constant2_Value - (real_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3_k;

    /* Sum: '<S6>/Sum3' incorporates:
     *  Constant: '<S6>/Constant'
     */
    M43_Sim_Forcing_003h_Trajectory_B.Sum3_d =
      M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_h - (real_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_a;

    /* Sum: '<S6>/Sum1' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    M43_Sim_Forcing_003h_Trajectory_B.Sum1 =
      M43_Sim_Forcing_003h_Trajectory_P.Constant1_Value_l + (real_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_a;

    /* Level2 S-Function Block: '<S6>/GT-RT UDP  Read' (gt_rt_udp_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[23];
      sfcnOutputs(rts, 0);
    }

    /* Unpack: <S8>/Unpack */
    (void) memcpy(&M43_Sim_Forcing_003h_Trajectory_B.Unpack,
                  &M43_Sim_Forcing_003h_Trajectory_U8GND,
                  4);

    /* Level2 S-Function Block: '<S8>/GT-RT UDP RX' (gt_rt_udp_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[24];
      sfcnOutputs(rts, 0);
    }

    /* Level2 S-Function Block: '<S8>/GT-RT UDP  Read' (gt_rt_udp_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[25];
      sfcnOutputs(rts, 0);
    }

    /* Sum: '<S3>/Sum2' incorporates:
     *  Constant: '<S3>/x_e'
     */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_e =
      M43_Sim_Forcing_003h_Trajectory_B.x +
      M43_Sim_Forcing_003h_Trajectory_P.x_e_Value;

    /* DiscreteIntegrator: '<S81>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_l =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_c;

    /* Gain: '<S75>/from cm to m' */
    M43_Sim_Forcing_003h_Trajectory_B.fromcmtom =
      M43_Sim_Forcing_003h_Trajectory_P.fromcmtom_Gain *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_l;

    /* Sum: '<S3>/Sum1' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_n =
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_e +
      M43_Sim_Forcing_003h_Trajectory_B.fromcmtom;

    /* DiscreteIntegrator: '<S83>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_e =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_e;

    /* Gain: '<S76>/from cm to m' */
    M43_Sim_Forcing_003h_Trajectory_B.fromcmtom_f =
      M43_Sim_Forcing_003h_Trajectory_P.fromcmtom_Gain_d *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_e;

    /* Sum: '<S3>/Sum8' incorporates:
     *  Constant: '<S3>/y_e'
     */
    M43_Sim_Forcing_003h_Trajectory_B.Sum8 =
      M43_Sim_Forcing_003h_Trajectory_B.fromcmtom_f +
      M43_Sim_Forcing_003h_Trajectory_P.y_e_Value;

    /* Sum: '<S3>/Sum6' incorporates:
     *  Constant: '<S3>/z_e'
     */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_p =
      M43_Sim_Forcing_003h_Trajectory_B.z +
      M43_Sim_Forcing_003h_Trajectory_P.z_e_Value;

    /* DiscreteIntegrator: '<S84>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_h =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_d;

    /* Gain: '<S77>/from cm to m' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_h =
      M43_Sim_Forcing_003h_Trajectory_P.fromcmtom_Gain_n *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_h;

    /* Sum: '<S3>/Sum4' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum4 =
      M43_Sim_Forcing_003h_Trajectory_B.Product1_p +
      M43_Sim_Forcing_003h_Trajectory_B.Product1_h;

    /* DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_h =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_i;

    /* Gain: '<S76>/Gain1' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_p =
      M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain *
      M43_Sim_Forcing_003h_Trajectory_B.Product1_h;

    /* Sum: '<S3>/Sum7' incorporates:
     *  Constant: '<S3>/Phi'
     */
    M43_Sim_Forcing_003h_Trajectory_B.Sum7 =
      M43_Sim_Forcing_003h_Trajectory_B.Product1_p +
      M43_Sim_Forcing_003h_Trajectory_P.Phi_Value;

    /* DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_p =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_g;

    /* Gain: '<S75>/Gain1' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide2 =
      M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_a *
      M43_Sim_Forcing_003h_Trajectory_B.Product1_p;

    /* Sum: '<S3>/Sum5' incorporates:
     *  Constant: '<S3>/Theta'
     */
    M43_Sim_Forcing_003h_Trajectory_B.Sum5 =
      M43_Sim_Forcing_003h_Trajectory_B.Divide2 +
      M43_Sim_Forcing_003h_Trajectory_P.Theta_Value;

    /* Constant: '<S70>/Allowed Psi' */
    M43_Sim_Forcing_003h_Trajectory_B.AllowedPsi =
      M43_Sim_Forcing_003h_Trajectory_P.AllowedPsi_Value;

    /* Embedded MATLAB: '<S78>/Embedded MATLAB Function' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Cabin Motion/Reduce Out-of-Plane Yaw1/Embedded MATLAB Function': '<S85>:1' */
    /*  soft limits on out-of-plane psi OOP_psi */
    /* '<S85>:1:9' */
    eml_maxval = 5.7295779513082323E+001 * rt_atan2_snf
      (M43_Sim_Forcing_003h_Trajectory_B.fromcmtom_f,
       M43_Sim_Forcing_003h_Trajectory_B.fromcmtom);

    /* '<S85>:1:10' */
    if (rtIsNaN(eml_maxval)) {
      eml_x = (rtNaN);
    } else if (eml_maxval > 0.0) {
      eml_x = 1.0;
    } else if (eml_maxval < 0.0) {
      eml_x = -1.0;
    } else {
      eml_x = 0.0;
    }

    /* '<S85>:1:11' */
    M43_Sim_Forcing_003h_Trajectory_B.d_psi = eml_maxval - (1.0 - exp(-fabs
      (eml_maxval / M43_Sim_Forcing_003h_Trajectory_B.AllowedPsi))) * (eml_x *
      M43_Sim_Forcing_003h_Trajectory_B.AllowedPsi);

    /* Switch: '<S78>/Switch' incorporates:
     *  Constant: '<S70>/1 for enable'
     */
    if (M43_Sim_Forcing_003h_Trajectory_P.forenable_Value != 0.0) {
      M43_Sim_Forcing_003h_Trajectory_B.Divide2 =
        M43_Sim_Forcing_003h_Trajectory_B.d_psi;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.Divide2 =
        M43_Sim_Forcing_003h_Trajectory_P.forenable_Value;
    }

    /* DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_f;

    /* Sum: '<S3>/Sum14' incorporates:
     *  Constant: '<S3>/Psi'
     */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c =
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator +
      M43_Sim_Forcing_003h_Trajectory_P.Psi_Value;

    /* Sum: '<S3>/Sum12' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum12 =
      M43_Sim_Forcing_003h_Trajectory_B.Divide2 +
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c;

    /* UnitDelay: '<S106>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.UnitDelay[i] =
        M43_Sim_Forcing_003h_Trajectory_DWork.UnitDelay_DSTATE[i];
    }

    /* Switch: '<S106>/Switch1' incorporates:
     *  Constant: '<S106>/Constant'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[2] >
        M43_Sim_Forcing_003h_Trajectory_P.Switch1_Threshold_a) {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1 = 0.0;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1 =
        M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_p;
    }

    /* Outputs for enable SubSystem: '<S112>/Simplified Inverse Kin' incorporates:
     *  EnablePort: '<S116>/Enable'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch1 > 0.0) {
      /* SignalConversion: '<S117>/TmpSignal ConversionAt SFunction Inport1' */
      M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[0] =
        M43_Sim_Forcing_003h_Trajectory_B.Sum1_n;
      M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[1] =
        M43_Sim_Forcing_003h_Trajectory_B.Sum8;
      M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[2] =
        M43_Sim_Forcing_003h_Trajectory_B.Sum4;
      M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[3] =
        M43_Sim_Forcing_003h_Trajectory_B.Sum7;
      M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[4] =
        M43_Sim_Forcing_003h_Trajectory_B.Sum5;
      M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[5] =
        M43_Sim_Forcing_003h_Trajectory_B.Sum12;
      for (i = 0; i < 6; i++) {
        M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[i + 6]
          = M43_Sim_Forcing_003h_Trajectory_B.UnitDelay[i];
      }

      /* Embedded MATLAB: '<S116>/Embedded MATLAB Function1' */
      /* Embedded MATLAB Function 'Joint Controller (May 7, 2015)/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics/Simplified Inverse Kin/Embedded MATLAB Function1': '<S117>:1' */
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
      /* '<S117>:1:34' */
      /*  define length of the links */
      /* '<S117>:1:39' */
      /*  arm length in cm */
      /* '<S117>:1:40' */
      /* '<S117>:1:41' */
      /* '<S117>:1:42' */
      /*  vertical offset of the center line of */
      /*  joint 4 from centerline of arm A3 */
      /* '<S117>:1:47' */
      /*  height link A2 above the ground */
      /* '<S117>:1:49' */
      /* '<S117>:1:50' */
      /* '<S117>:1:51' */
      /* '<S117>:1:53' */
      /* '<S117>:1:54' */
      /* '<S117>:1:55' */
      /* '<S117>:1:57' */
      eml_r_0 = 1;

      /* '<S117>:1:58' */
      for (i = 0; i < 7; i++) {
        M43_Sim_Forcing_003h_Trajectory_B.out[i] = 0.0;
      }

      /*  compute dimensions of triangle */
      /* '<S117>:1:61' */
      /* '<S117>:1:62' */
      eml_maxval = (sqrt
                    (M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI
                     [0] *
                     M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI
                     [0] +
                     M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI
                     [1] *
                     M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI
                     [1]) - 50.0) - cos(1.7453292519943295E-002 *
        M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[4]) *
        29.0;

      /* '<S117>:1:63' */
      eml_x = (-(210.5 +
                 M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI
                 [2])) - sin(1.7453292519943295E-002 *
        M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[4]) *
        29.0;

      /* '<S117>:1:64' */
      eml_CA = sqrt(rt_pow_snf(eml_maxval, 2.0) + rt_pow_snf(eml_x, 2.0));

      /*  check whether the FAR location of C is reachable */
      /* '<S117>:1:68' */
      /* '<S117>:1:69' */
      /*  margin is 5 cm */
      if (eml_CA > 227.5) {
        /* '<S117>:1:70' */
        /* '<S117>:1:71' */
        for (i = 0; i < 6; i++) {
          M43_Sim_Forcing_003h_Trajectory_B.out[i] =
            M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[6
            + i];
        }

        /*  return angles 'as is' */
        /* '<S117>:1:72' */
        M43_Sim_Forcing_003h_Trajectory_B.out[2] = -90.0;

        /* '<S117>:1:73' */
        M43_Sim_Forcing_003h_Trajectory_B.out[6] = -2.0;
      } else {
        /*  check whether the CLOSE location of C is reachable */
        if ((eml_CA + 102.5) - 5.0 < 130.0) {
          /* '<S117>:1:78' */
          /* '<S117>:1:79' */
          for (i = 0; i < 6; i++) {
            M43_Sim_Forcing_003h_Trajectory_B.out[i] =
              M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI
              [6 + i];
          }

          /*  return angles 'as is' */
          /* '<S117>:1:80' */
          M43_Sim_Forcing_003h_Trajectory_B.out[2] = -90.0;

          /* '<S117>:1:81' */
          M43_Sim_Forcing_003h_Trajectory_B.out[6] = -2.0;
        } else {
          /*  This iterative loop serves to correct for the offset of link A4 */
          /*  A first good guess is to assume that beta is initially 90 deg */
          /*  A second-order scheme is used */
          /* '<S117>:1:89' */
          /* '<S117>:1:90' */
          eml_SA =
            M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[8]
            + 180.0;
          do {
            eml_r = 0;

            /* '<S117>:1:94' */
            eml_CA_0 = sin(eml_SA * 1.7453292519943295E-002);

            /* '<S117>:1:95' */
            eml_SA_0 = eml_CA_0 * eml_CA_0;

            /* '<S117>:1:96' */
            eml_CA_1 = cos(eml_SA * 1.7453292519943295E-002);

            /* '<S117>:1:98' */
            eml_A_2 = 130.0 - 5.5 / eml_CA_0;

            /* '<S117>:1:99' */
            eml_CA_2 = 102.5 - 5.5 * eml_CA_1 / eml_CA_0;

            /* '<S117>:1:101' */
            eml_A_0 = 5.5 * eml_CA_1 / eml_SA_0;

            /* '<S117>:1:102' */
            eml_A_1 = 5.5 / eml_SA_0;

            /* '<S117>:1:104' */
            eml_SA_0 = (eml_A_2 * eml_A_2 + eml_CA_2 * eml_CA_2) - eml_CA *
              eml_CA;

            /* '<S117>:1:105' */
            eml_A = 2.0 * eml_A_2 * eml_CA_2;

            /* '<S117>:1:106' */
            /* '<S117>:1:107' */
            /* '<S117>:1:108' */
            /* '<S117>:1:109' */
            /* '<S117>:1:110' */
            eml_A_1 = (eml_CA_1 - eml_SA_0 / eml_A) * -5.7295779513082323E+001 /
              ((-eml_CA_0) - ((2.0 * eml_A_2 * eml_A_0 + 2.0 * eml_CA_2 *
                               eml_A_1) * eml_A - (eml_A_0 * eml_CA_2 + eml_A_2 *
                 eml_A_1) * 2.0 * eml_SA_0) / rt_pow_snf(eml_A, 2.0));

            /* '<S117>:1:111' */
            eml_SA += eml_A_1;
            if (fabs(eml_A_1) < 1.0E-005) {
              /* '<S117>:1:113' */
              eml_r = 1;
            } else {
              /* '<S117>:1:116' */
              eml_r_0++;
              if (eml_r_0 > 100) {
                /* '<S117>:1:117' */
                /* '<S117>:1:118' */
                eml_r_0 = -2;

                /* '<S117>:1:119' */
                for (i = 0; i < 6; i++) {
                  M43_Sim_Forcing_003h_Trajectory_B.out[i] =
                    M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI
                    [6 + i];
                }

                /*  return angles 'as is' */
                /* '<S117>:1:120' */
                M43_Sim_Forcing_003h_Trajectory_B.out[2] = -90.0;

                /* '<S117>:1:121' */
                M43_Sim_Forcing_003h_Trajectory_B.out[6] = -2.0;
                eml_r = 1;
              }
            }
          } while ((uint32_T)eml_r == 0U);

          /*  employ cosine rule on angles alpha and beta of triangle */
          /* '<S117>:1:127' */
          /* '<S117>:1:129' */
          /* '<S117>:1:130' */
          /*  the link angles */
          /* '<S117>:1:133' */
          /* '<S117>:1:134' */
          eml_SA_0 = acos(((eml_A_2 * eml_A_2 + eml_CA * eml_CA) - eml_CA_2 *
                           eml_CA_2) / (2.0 * eml_A_2 * eml_CA)) *
            5.7295779513082323E+001 + 5.7295779513082323E+001 * rt_atan2_snf
            (eml_x, eml_maxval);

          /* '<S117>:1:135' */
          eml_A_1 = eml_SA - 180.0;

          /* '<S117>:1:136' */
          /* '<S117>:1:137' */
          /* '<S117>:1:138' */
          /* '<S117>:1:140' */
          eml_ang[0] = 5.7295779513082323E+001 * rt_atan2_snf
            (M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[1],
             M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[0]);
          eml_ang[1] = eml_SA_0;
          eml_ang[2] = eml_A_1;
          eml_ang[3] = 0.0;
          eml_ang[4] = (-(eml_SA_0 + eml_A_1)) +
            M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[4];
          eml_ang[5] = 0.0;

          /* '<S117>:1:141' */
          for (i = 0; i < 6; i++) {
            M43_Sim_Forcing_003h_Trajectory_B.out[i] = eml_ang[i];
          }

          /*  tests whether the links are within the set soft limits */
          for (eml_r = 0; eml_r < 6; eml_r++) {
            /* '<S117>:1:144' */
            if (eml_ang[eml_r] >= (real_T)tmp_9[eml_r << 1]) {
              /* '<S117>:1:145' */
              /* '<S117>:1:146' */
              eml_r_0 = -11 - eml_r;
            } else {
              if (eml_ang[eml_r] <= (real_T)tmp_9[(eml_r << 1) + 1]) {
                /* '<S117>:1:147' */
                /* '<S117>:1:148' */
                eml_r_0 = -101 - eml_r;
              }
            }
          }

          /* '<S117>:1:152' */
          M43_Sim_Forcing_003h_Trajectory_B.out[6] = (real_T)eml_r_0;
        }
      }

      srUpdateBC
        (M43_Sim_Forcing_003h_Trajectory_DWork.SimplifiedInverseKin_SubsysRanB);
    }

    /* end of Outputs for SubSystem: '<S112>/Simplified Inverse Kin' */

    /* Sum: '<S112>/Sum' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum_d[0] =
      M43_Sim_Forcing_003h_Trajectory_B.UnitDelay[0];
    M43_Sim_Forcing_003h_Trajectory_B.Sum_d[1] =
      M43_Sim_Forcing_003h_Trajectory_B.UnitDelay[1] -
      M43_Sim_Forcing_003h_Trajectory_B.out[1];
    M43_Sim_Forcing_003h_Trajectory_B.Sum_d[2] =
      M43_Sim_Forcing_003h_Trajectory_B.UnitDelay[2] -
      M43_Sim_Forcing_003h_Trajectory_B.out[2];
    M43_Sim_Forcing_003h_Trajectory_B.Sum_d[3] =
      M43_Sim_Forcing_003h_Trajectory_B.UnitDelay[3];
    M43_Sim_Forcing_003h_Trajectory_B.Sum_d[4] =
      M43_Sim_Forcing_003h_Trajectory_B.UnitDelay[4] -
      M43_Sim_Forcing_003h_Trajectory_B.out[4];
    M43_Sim_Forcing_003h_Trajectory_B.Sum_d[5] =
      M43_Sim_Forcing_003h_Trajectory_B.UnitDelay[5];

    /* DiscreteIntegrator: '<S112>/Discrete-Time Integrator1' */
    if (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_IC_LOAD) {
      for (i = 0; i < 6; i++) {
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_l[i]
          = M43_Sim_Forcing_003h_Trajectory_B.Sum_d[i];
      }
    }

    if (((M43_Sim_Forcing_003h_Trajectory_B.Switch1 > 0.0) &&
         (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_k <=
          0)) || ((M43_Sim_Forcing_003h_Trajectory_B.Switch1 <= 0.0) &&
                  (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_k
                   == 1))) {
      for (i = 0; i < 6; i++) {
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_l[i]
          = M43_Sim_Forcing_003h_Trajectory_B.Sum_d[i];
      }
    }

    /* Sum: '<S110>/Sum' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum_n[0] =
      M43_Sim_Forcing_003h_Trajectory_B.out_m[0] -
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_n;
    M43_Sim_Forcing_003h_Trajectory_B.Sum_n[1] =
      M43_Sim_Forcing_003h_Trajectory_B.out_m[1] -
      M43_Sim_Forcing_003h_Trajectory_B.Sum8;
    M43_Sim_Forcing_003h_Trajectory_B.Sum_n[2] =
      M43_Sim_Forcing_003h_Trajectory_B.out_m[2] -
      M43_Sim_Forcing_003h_Trajectory_B.Sum4;
    M43_Sim_Forcing_003h_Trajectory_B.Sum_n[3] =
      M43_Sim_Forcing_003h_Trajectory_B.out_m[3] -
      M43_Sim_Forcing_003h_Trajectory_B.Sum7;
    M43_Sim_Forcing_003h_Trajectory_B.Sum_n[4] =
      M43_Sim_Forcing_003h_Trajectory_B.out_m[4] -
      M43_Sim_Forcing_003h_Trajectory_B.Sum5;
    M43_Sim_Forcing_003h_Trajectory_B.Sum_n[5] =
      M43_Sim_Forcing_003h_Trajectory_B.out_m[5] -
      M43_Sim_Forcing_003h_Trajectory_B.Sum12;

    /* DiscreteIntegrator: '<S110>/Discrete-Time Integrator' */
    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1[i] =
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_l[i];
      if (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_IC_LOADI)
      {
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_b[i]
          = M43_Sim_Forcing_003h_Trajectory_B.Sum_n[i];
      }
    }

    if (((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[2] > 0) &&
         (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_PrevRe_d <=
          0)) || ((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[2] <= 0) &&
                  (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_PrevRe_d
                   == 1))) {
      for (i = 0; i < 6; i++) {
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_b[i]
          = M43_Sim_Forcing_003h_Trajectory_B.Sum_n[i];
      }
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[i] =
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_b[i];
    }

    /* Sum: '<S110>/Sum1' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_k[0] =
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_n +
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[0];
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_k[1] =
      M43_Sim_Forcing_003h_Trajectory_B.Sum8 +
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[1];
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_k[2] =
      M43_Sim_Forcing_003h_Trajectory_B.Sum4 +
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[2];
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_k[3] =
      M43_Sim_Forcing_003h_Trajectory_B.Sum7 +
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[3];
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_k[4] =
      M43_Sim_Forcing_003h_Trajectory_B.Sum5 +
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[4];
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_k[5] =
      M43_Sim_Forcing_003h_Trajectory_B.Sum12 +
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[5];

    /* Outputs for enable SubSystem: '<S110>/full inverse kin' incorporates:
     *  EnablePort: '<S113>/Enable'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[2] > 0) {
      /* SignalConversion: '<S114>/TmpSignal ConversionAt SFunction Inport1' */
      for (i = 0; i < 6; i++) {
        M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctio_i[i] =
          M43_Sim_Forcing_003h_Trajectory_B.Sum1_k[i];
      }

      /* Embedded MATLAB: '<S113>/Embedded MATLAB Function' */
      /* Embedded MATLAB Function 'Joint Controller (May 7, 2015)/Inverse Kinematics May 6, 2015/Inverse Kinematics/full inverse kin/Embedded MATLAB Function': '<S114>:1' */
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
      /* '<S114>:1:37' */
      /*  Room coordinates of flange, NED in cm */
      /* '<S114>:1:38' */
      for (i = 0; i < 6; i++) {
        M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctio_i[i + 6]
          = M43_Sim_Forcing_003h_Trajectory_B.UnitDelay[i];
        eml_ang[i] =
          M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctio_i[i +
          6];
      }

      eml_x_p[0] =
        M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctio_i[3];
      eml_x_p[1] =
        M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctio_i[4];
      eml_x_p[2] =
        M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctio_i[5];

      /*  Euler angles of the flange, phi, theta, psi, in deg */
      /* '<S114>:1:39' */
      /*  Initial guess of the joint angles, in deg */
      /* '<S114>:1:40' */
      for (i = 0; i < 7; i++) {
        M43_Sim_Forcing_003h_Trajectory_B.out_g[i] = 0.0;
      }

      /*  reserve place for out */
      /*  soft limits on the links (NED convention) */
      /*  SL = [   175    130     88    200    61    200 */
      /*          -175    -20    -88   -200   -61   -200]; */
      /*  Dec. 6, 2014: A2 and A3 limits changed to KUKA hardware */
      /*  May 7,2015 soft limits on the links (NED convention) */
      /* '<S114>:1:49' */
      /*  define length of arms */
      /* '<S114>:1:53' */
      /*  arm length in cm */
      /* '<S114>:1:54' */
      /* '<S114>:1:55' */
      /* '<S114>:1:56' */
      /* '<S114>:1:57' */
      /* '<S114>:1:58' */
      /*  vertical offset of the center line of */
      /*  joint 4 from centerline of arm A3 */
      /* '<S114>:1:60' */
      /*  height link A2 above the ground */
      /*  offset the height so that level zero is now at the height of the A2 joint */
      /* '<S114>:1:63' */
      eml_z_p_idx =
        M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctio_i[2] +
        210.5;

      /*  set initial guess; the algorithm works in rad, so ang is in rad */
      /* '<S114>:1:66' */
      eml_r = 0;

      /* '<S114>:1:67' */
      for (i = 0; i < 6; i++) {
        eml_ang_0[i] = eml_ang[i] * 1.7453292519943295E-002;
      }

      /*  check for maximum range of arm links and exit with n = 2 when exceeded */
      /* '<S114>:1:71' */
      /* '<S114>:1:72' */
      if (sqrt(rt_pow_snf
               (M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctio_i
                [0], 2.0) + rt_pow_snf
               (M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctio_i
                [1], 2.0)) > (sqrt(68382.25 - rt_pow_snf(eml_z_p_idx, 2.0)) +
                              50.0) - 5.0) {
        /* '<S114>:1:73' */
        /* '<S114>:1:74' */
        for (i = 0; i < 6; i++) {
          M43_Sim_Forcing_003h_Trajectory_B.out_g[i] = eml_ang[i];
        }

        /*  return vector as is */
        /* '<S114>:1:75' */
        M43_Sim_Forcing_003h_Trajectory_B.out_g[6] = -2.0;
      } else {
        /* -------------------------------- */
        /*  	start of iterative loop */
        /* -------------------------------- */
        do {
          eml_r_0 = 0;

          /*  4x4 Transfer matrices, include both rotation and translation */
          /* '<S114>:1:87' */
          for (eml_r_1 = 0; eml_r_1 < 6; eml_r_1++) {
            for (eml_A = eml_ang_0[eml_r_1]; eml_A > 3.1415926535897931E+000;
                 eml_A -= 6.2831853071795862E+000) {
            }

            while (eml_A < -3.1415926535897931E+000) {
              eml_A += 6.2831853071795862E+000;
            }

            eml_ang_0[eml_r_1] = eml_A;
          }

          /*  ang is brought in the range +-pi */
          /* '<S114>:1:88' */
          /* '<S114>:1:89' */
          /* '<S114>:1:90' */
          /* '<S114>:1:91' */
          /* '<S114>:1:92' */
          /* '<S114>:1:93' */
          /* '<S114>:1:95' */
          eml_maxval = cos(eml_ang_0[0]);

          /* '<S114>:1:96' */
          eml_x = sin(eml_ang_0[0]);

          /* '<S114>:1:97' */
          eml_CA = cos(eml_ang_0[1]);

          /* '<S114>:1:98' */
          eml_SA = sin(eml_ang_0[1]);

          /* '<S114>:1:99' */
          eml_CA_0 = cos(eml_ang_0[2]);

          /* '<S114>:1:100' */
          eml_SA_0 = sin(eml_ang_0[2]);

          /* '<S114>:1:101' */
          eml_CA_1 = cos(eml_ang_0[3]);

          /* '<S114>:1:102' */
          eml_A_2 = sin(eml_ang_0[3]);

          /* '<S114>:1:103' */
          eml_CA_2 = cos(eml_ang_0[4]);

          /* '<S114>:1:104' */
          eml_A_0 = sin(eml_ang_0[4]);

          /* '<S114>:1:105' */
          eml_A_1 = cos(eml_ang_0[5]);

          /* '<S114>:1:106' */
          eml_A = sin(eml_ang_0[5]);

          /* '<S114>:1:108' */
          eml_D[0] = eml_maxval;
          eml_D[4] = -eml_x;
          eml_D[8] = 0.0;
          eml_D[12] = 0.0;
          eml_D[1] = eml_x;
          eml_D[5] = eml_maxval;
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

          /* '<S114>:1:109' */
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

          /* '<S114>:1:110' */
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

          /* '<S114>:1:111' */
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

          /* '<S114>:1:112' */
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

          /* '<S114>:1:113' */
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
          /* '<S114>:1:117' */
          for (i = 0; i < 3; i++) {
            eml_A_3[3 * i] = eml_D[i << 2];
            eml_A_3[1 + 3 * i] = eml_D[(i << 2) + 1];
            eml_A_3[2 + 3 * i] = eml_D[(i << 2) + 2];
          }

          /* '<S114>:1:118' */
          for (i = 0; i < 3; i++) {
            eml_E[3 * i] = eml_D_0[i << 2];
            eml_E[1 + 3 * i] = eml_D_0[(i << 2) + 1];
            eml_E[2 + 3 * i] = eml_D_0[(i << 2) + 2];
          }

          /* '<S114>:1:119' */
          for (i = 0; i < 3; i++) {
            eml_E_0[3 * i] = eml_D_1[i << 2];
            eml_E_0[1 + 3 * i] = eml_D_1[(i << 2) + 1];
            eml_E_0[2 + 3 * i] = eml_D_1[(i << 2) + 2];
          }

          /* '<S114>:1:120' */
          for (i = 0; i < 3; i++) {
            eml_E_1[3 * i] = eml_D_2[i << 2];
            eml_E_1[1 + 3 * i] = eml_D_2[(i << 2) + 1];
            eml_E_1[2 + 3 * i] = eml_D_2[(i << 2) + 2];
          }

          /* '<S114>:1:121' */
          for (i = 0; i < 3; i++) {
            eml_E_2[3 * i] = eml_D_3[i << 2];
            eml_E_2[1 + 3 * i] = eml_D_3[(i << 2) + 1];
            eml_E_2[2 + 3 * i] = eml_D_3[(i << 2) + 2];
          }

          /* '<S114>:1:122' */
          /*  --- computed position from links A1-A6 --- */
          /* ---------------------------------------------------------------------- */
          /*    In order to move a point in the cabine in 6-DOF rather than the */
          /*    endplate, define the coordinates of that point in x_cabin */
          /* ---------------------------------------------------------------------- */
          /*  x,y,z cabin reference point (cm) */
          /* '<S114>:1:133' */
          /* '<S114>:1:134' */
          /*  position of the cabin reference point in the */
          /*  NED system (cm) */
          /*  computed Euler angles from links A1-A6 */
          /*  Euler matrices for rotation from e->b (note the transpose) */
          /* '<S114>:1:139' */
          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_D_5[i + 3 * eml_r_1] = 0.0;
              eml_D_5[i + 3 * eml_r_1] = eml_D_5[3 * eml_r_1 + i] + eml_D_4[i <<
                2] * eml_E_2[eml_r_1];
              eml_D_5[i + 3 * eml_r_1] = eml_D_4[(i << 2) + 1] * eml_E_2[eml_r_1
                + 3] + eml_D_5[3 * eml_r_1 + i];
              eml_D_5[i + 3 * eml_r_1] = eml_D_4[(i << 2) + 2] * eml_E_2[eml_r_1
                + 6] + eml_D_5[3 * eml_r_1 + i];
            }
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_D_6[i + 3 * eml_r_1] = 0.0;
              eml_D_6[i + 3 * eml_r_1] = eml_D_6[3 * eml_r_1 + i] + eml_D_5[i] *
                eml_E_1[eml_r_1];
              eml_D_6[i + 3 * eml_r_1] = eml_D_6[3 * eml_r_1 + i] + eml_D_5[i +
                3] * eml_E_1[eml_r_1 + 3];
              eml_D_6[i + 3 * eml_r_1] = eml_D_6[3 * eml_r_1 + i] + eml_D_5[i +
                6] * eml_E_1[eml_r_1 + 6];
            }
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_D_7[i + 3 * eml_r_1] = 0.0;
              eml_D_7[i + 3 * eml_r_1] = eml_D_7[3 * eml_r_1 + i] + eml_D_6[i] *
                eml_E_0[eml_r_1];
              eml_D_7[i + 3 * eml_r_1] = eml_D_7[3 * eml_r_1 + i] + eml_D_6[i +
                3] * eml_E_0[eml_r_1 + 3];
              eml_D_7[i + 3 * eml_r_1] = eml_D_7[3 * eml_r_1 + i] + eml_D_6[i +
                6] * eml_E_0[eml_r_1 + 6];
            }
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_D_5[i + 3 * eml_r_1] = 0.0;
              eml_D_5[i + 3 * eml_r_1] = eml_D_5[3 * eml_r_1 + i] + eml_D_7[i] *
                eml_E[eml_r_1];
              eml_D_5[i + 3 * eml_r_1] = eml_D_5[3 * eml_r_1 + i] + eml_D_7[i +
                3] * eml_E[eml_r_1 + 3];
              eml_D_5[i + 3 * eml_r_1] = eml_D_5[3 * eml_r_1 + i] + eml_D_7[i +
                6] * eml_E[eml_r_1 + 6];
            }
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_E_3[i + 3 * eml_r_1] = 0.0;
              eml_E_3[i + 3 * eml_r_1] = eml_E_3[3 * eml_r_1 + i] + eml_D_5[i] *
                eml_A_3[eml_r_1];
              eml_E_3[i + 3 * eml_r_1] = eml_E_3[3 * eml_r_1 + i] + eml_D_5[i +
                3] * eml_A_3[eml_r_1 + 3];
              eml_E_3[i + 3 * eml_r_1] = eml_E_3[3 * eml_r_1 + i] + eml_D_5[i +
                6] * eml_A_3[eml_r_1 + 6];
            }
          }

          /* '<S114>:1:140' */
          /*  DCM to Euler angles */
          eml_c_idx = -asin(eml_E_3[6]);
          eml_c_idx_0 = rt_atan2_snf(eml_E_3[3], eml_E_3[0]);

          /*  determine the vectors of rotation of the endplate in e-system */
          /*  for each one of the links; this is a 3x6 matrix, when multiplied */
          /*  with the vector of the joint angles, it will give the vector */
          /*  of rotation of the endplate (and also of the cabin reference point) */
          /*  in the NED system */
          /* '<S114>:1:148' */
          /*  x-axis */
          /* '<S114>:1:149' */
          /*  y-axis */
          /* '<S114>:1:150' */
          /*  x-axis */
          /* '<S114>:1:151' */
          /*  y-axis */
          /* '<S114>:1:152' */
          /*  y-axis */
          /* '<S114>:1:153' */
          /*  z-axis */
          /* '<S114>:1:155' */
          /*  in order to see the changes in phi, theta, psi that this rotation */
          /*  vector causes, we have to transform e->b first in yaw and after that */
          /*  in pitch */
          /* '<S114>:1:160' */
          eml_A_4 = cos(eml_c_idx_0);

          /* '<S114>:1:161' */
          eml_A_5 = sin(eml_c_idx_0);

          /* '<S114>:1:162' */
          eml_A_6 = cos(eml_c_idx);

          /* '<S114>:1:163' */
          eml_A_7 = sin(eml_c_idx);

          /* '<S114>:1:165' */
          /* '<S114>:1:166' */
          /* '<S114>:1:167' */
          /*  the derivatives of D1-D6 for eah one of the link angles */
          /* '<S114>:1:172' */
          /* '<S114>:1:173' */
          /* '<S114>:1:174' */
          /* '<S114>:1:175' */
          /* '<S114>:1:176' */
          /* '<S114>:1:177' */
          /*  Hessian Matrix H; the inverse of this matrix determines the link */
          /*  angle speed as a function of the speed of x,y,z and the speed of the */
          /*  Euler angles */
          /* '<S114>:1:183' */
          /* '<S114>:1:184' */
          /* '<S114>:1:185' */
          /* '<S114>:1:186' */
          /* '<S114>:1:187' */
          /* '<S114>:1:188' */
          /* '<S114>:1:190' */
          /*  this 3x6 is th upper half of H */
          /* '<S114>:1:191' */
          /*  the lower 3x6 half is the matrix e */
          /* '<S114>:1:193' */
          eml_D_8[0] = -eml_x;
          eml_D_8[4] = -eml_maxval;
          eml_D_8[8] = 0.0;
          eml_D_8[12] = 0.0;
          eml_D_8[1] = eml_maxval;
          eml_D_8[5] = -eml_x;
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
          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_9[i + (eml_r_1 << 2)] = 0.0;
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
                eml_D_0[eml_r_1 << 2] * eml_D_8[i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_D_9[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_1[eml_r_1 << 2] * eml_D_9[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 1] *
                eml_D_9[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 2] *
                eml_D_9[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 3] *
                eml_D_9[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_9[i + (eml_r_1 << 2)] = 0.0;
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
                eml_D_2[eml_r_1 << 2] * eml_D_8[i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_D_9[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_3[eml_r_1 << 2] * eml_D_9[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 1] *
                eml_D_9[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 2] *
                eml_D_9[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 3] *
                eml_D_9[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_x_1[i + (eml_r_1 << 2)] = 0.0;
              eml_x_1[i + (eml_r_1 << 2)] = eml_x_1[(eml_r_1 << 2) + i] +
                eml_D_4[eml_r_1 << 2] * eml_D_8[i];
              eml_x_1[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_x_1[(eml_r_1 << 2) + i];
              eml_x_1[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_x_1[(eml_r_1 << 2) + i];
              eml_x_1[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_x_1[(eml_r_1 << 2) + i];
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
          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_9[i + (eml_r_1 << 2)] = 0.0;
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
                eml_D_8[eml_r_1 << 2] * eml_D[i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + 1] *
                eml_D[i + 4] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + 2] *
                eml_D[i + 8] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + 3] *
                eml_D[i + 12] + eml_D_9[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_1[eml_r_1 << 2] * eml_D_9[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 1] *
                eml_D_9[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 2] *
                eml_D_9[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 3] *
                eml_D_9[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_9[i + (eml_r_1 << 2)] = 0.0;
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
                eml_D_2[eml_r_1 << 2] * eml_D_8[i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_D_9[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_3[eml_r_1 << 2] * eml_D_9[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 1] *
                eml_D_9[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 2] *
                eml_D_9[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 3] *
                eml_D_9[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_b[i + (eml_r_1 << 2)] = 0.0;
              eml_D_b[i + (eml_r_1 << 2)] = eml_D_b[(eml_r_1 << 2) + i] +
                eml_D_4[eml_r_1 << 2] * eml_D_8[i];
              eml_D_b[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_D_b[(eml_r_1 << 2) + i];
              eml_D_b[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_D_b[(eml_r_1 << 2) + i];
              eml_D_b[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_D_b[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_0[eml_r_1 << 2] * eml_D[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 1] *
                eml_D[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 2] *
                eml_D[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 3] *
                eml_D[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
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
          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_c[i + (eml_r_1 << 2)] = 0.0;
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_c[(eml_r_1 << 2) + i] +
                eml_D_9[eml_r_1 << 2] * eml_D_8[i];
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_D_c[(eml_r_1 << 2) + i];
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_D_c[(eml_r_1 << 2) + i];
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_D_c[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_2[eml_r_1 << 2] * eml_D_c[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 1] *
                eml_D_c[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 2] *
                eml_D_c[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 3] *
                eml_D_c[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_9[i + (eml_r_1 << 2)] = 0.0;
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
                eml_D_3[eml_r_1 << 2] * eml_D_8[i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_D_9[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_d[i + (eml_r_1 << 2)] = 0.0;
              eml_D_d[i + (eml_r_1 << 2)] = eml_D_d[(eml_r_1 << 2) + i] +
                eml_D_4[eml_r_1 << 2] * eml_D_9[i];
              eml_D_d[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 1] *
                eml_D_9[i + 4] + eml_D_d[(eml_r_1 << 2) + i];
              eml_D_d[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 2] *
                eml_D_9[i + 8] + eml_D_d[(eml_r_1 << 2) + i];
              eml_D_d[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 3] *
                eml_D_9[i + 12] + eml_D_d[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_0[eml_r_1 << 2] * eml_D[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 1] *
                eml_D[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 2] *
                eml_D[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 3] *
                eml_D[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_9[i + (eml_r_1 << 2)] = 0.0;
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
                eml_D_1[eml_r_1 << 2] * eml_D_8[i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_D_9[(eml_r_1 << 2) + i];
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
          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_c[i + (eml_r_1 << 2)] = 0.0;
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_c[(eml_r_1 << 2) + i] +
                eml_D_8[eml_r_1 << 2] * eml_D_9[i];
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + 1] *
                eml_D_9[i + 4] + eml_D_c[(eml_r_1 << 2) + i];
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + 2] *
                eml_D_9[i + 8] + eml_D_c[(eml_r_1 << 2) + i];
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + 3] *
                eml_D_9[i + 12] + eml_D_c[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_3[eml_r_1 << 2] * eml_D_c[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 1] *
                eml_D_c[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 2] *
                eml_D_c[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 3] *
                eml_D_c[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_e[i + (eml_r_1 << 2)] = 0.0;
              eml_D_e[i + (eml_r_1 << 2)] = eml_D_e[(eml_r_1 << 2) + i] +
                eml_D_4[eml_r_1 << 2] * eml_D_8[i];
              eml_D_e[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_D_e[(eml_r_1 << 2) + i];
              eml_D_e[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_D_e[(eml_r_1 << 2) + i];
              eml_D_e[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_D_e[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_0[eml_r_1 << 2] * eml_D[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 1] *
                eml_D[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 2] *
                eml_D[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 3] *
                eml_D[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_9[i + (eml_r_1 << 2)] = 0.0;
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
                eml_D_1[eml_r_1 << 2] * eml_D_8[i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_D_9[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_c[i + (eml_r_1 << 2)] = 0.0;
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_c[(eml_r_1 << 2) + i] +
                eml_D_2[eml_r_1 << 2] * eml_D_9[i];
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 1] *
                eml_D_9[i + 4] + eml_D_c[(eml_r_1 << 2) + i];
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 2] *
                eml_D_9[i + 8] + eml_D_c[(eml_r_1 << 2) + i];
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 3] *
                eml_D_9[i + 12] + eml_D_c[(eml_r_1 << 2) + i];
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
          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_9[i + (eml_r_1 << 2)] = 0.0;
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
                eml_D_8[eml_r_1 << 2] * eml_D_c[i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + 1] *
                eml_D_c[i + 4] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + 2] *
                eml_D_c[i + 8] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + 3] *
                eml_D_c[i + 12] + eml_D_9[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_f[i + (eml_r_1 << 2)] = 0.0;
              eml_D_f[i + (eml_r_1 << 2)] = eml_D_f[(eml_r_1 << 2) + i] +
                eml_D_4[eml_r_1 << 2] * eml_D_9[i];
              eml_D_f[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 1] *
                eml_D_9[i + 4] + eml_D_f[(eml_r_1 << 2) + i];
              eml_D_f[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 2] *
                eml_D_9[i + 8] + eml_D_f[(eml_r_1 << 2) + i];
              eml_D_f[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 3] *
                eml_D_9[i + 12] + eml_D_f[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_0[eml_r_1 << 2] * eml_D[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 1] *
                eml_D[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 2] *
                eml_D[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 3] *
                eml_D[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_9[i + (eml_r_1 << 2)] = 0.0;
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
                eml_D_1[eml_r_1 << 2] * eml_D_8[i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_D_9[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_2[eml_r_1 << 2] * eml_D_9[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 1] *
                eml_D_9[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 2] *
                eml_D_9[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 3] *
                eml_D_9[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_c[i + (eml_r_1 << 2)] = 0.0;
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_c[(eml_r_1 << 2) + i] +
                eml_D_3[eml_r_1 << 2] * eml_D_8[i];
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_D_c[(eml_r_1 << 2) + i];
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_D_c[(eml_r_1 << 2) + i];
              eml_D_c[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_D_c[(eml_r_1 << 2) + i];
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
          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_9[i + (eml_r_1 << 2)] = 0.0;
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
                eml_D_8[eml_r_1 << 2] * eml_D_c[i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + 1] *
                eml_D_c[i + 4] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + 2] *
                eml_D_c[i + 8] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + 3] *
                eml_D_c[i + 12] + eml_D_9[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            eml_maxval = eml_x_1[i + 12] + (eml_x_1[i + 8] * 0.0 + (eml_x_1[i +
              4] * 0.0 + eml_x_1[i] * 0.0));
            eml_x = eml_D_b[i + 12] + (eml_D_b[i + 8] * 0.0 + (eml_D_b[i + 4] *
              0.0 + eml_D_b[i] * 0.0));
            eml_CA = eml_D_d[i + 12] + (eml_D_d[i + 8] * 0.0 + (eml_D_d[i + 4] *
              0.0 + eml_D_d[i] * 0.0));
            eml_SA = eml_D_e[i + 12] + (eml_D_e[i + 8] * 0.0 + (eml_D_e[i + 4] *
              0.0 + eml_D_e[i] * 0.0));
            eml_CA_0 = eml_D_f[i + 12] + (eml_D_f[i + 8] * 0.0 + (eml_D_f[i + 4]
              * 0.0 + eml_D_f[i] * 0.0));
            eml_SA_0 = eml_D_9[i + 12] + (eml_D_9[i + 8] * 0.0 + (eml_D_9[i + 4]
              * 0.0 + eml_D_9[i] * 0.0));
            eml_x_2[i] = eml_maxval;
            eml_D_j[i] = eml_SA_0;
            eml_D_i[i] = eml_CA_0;
            eml_D_h[i] = eml_SA;
            eml_D_g[i] = eml_CA;
            eml_D_a[i] = eml_x;
          }

          eml_x_2[4] = eml_D_a[0];
          eml_x_2[5] = eml_D_a[1];
          eml_x_2[6] = eml_D_a[2];
          eml_x_2[7] = eml_D_a[3];
          eml_x_2[8] = eml_D_g[0];
          eml_x_2[9] = eml_D_g[1];
          eml_x_2[10] = eml_D_g[2];
          eml_x_2[11] = eml_D_g[3];
          eml_x_2[12] = eml_D_h[0];
          eml_x_2[13] = eml_D_h[1];
          eml_x_2[14] = eml_D_h[2];
          eml_x_2[15] = eml_D_h[3];
          eml_x_2[16] = eml_D_i[0];
          eml_x_2[17] = eml_D_i[1];
          eml_x_2[18] = eml_D_i[2];
          eml_x_2[19] = eml_D_i[3];
          eml_x_2[20] = eml_D_j[0];
          eml_x_2[21] = eml_D_j[1];
          eml_x_2[22] = eml_D_j[2];
          eml_x_2[23] = eml_D_j[3];
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
          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_A_a[i + 3 * eml_r_1] = 0.0;
              eml_A_a[i + 3 * eml_r_1] = eml_A_a[3 * eml_r_1 + i] + eml_E[3 *
                eml_r_1] * eml_A_3[i];
              eml_A_a[i + 3 * eml_r_1] = eml_E[3 * eml_r_1 + 1] * eml_A_3[i + 3]
                + eml_A_a[3 * eml_r_1 + i];
              eml_A_a[i + 3 * eml_r_1] = eml_E[3 * eml_r_1 + 2] * eml_A_3[i + 6]
                + eml_A_a[3 * eml_r_1 + i];
            }
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_D_5[i + 3 * eml_r_1] = 0.0;
              eml_D_5[i + 3 * eml_r_1] = eml_D_5[3 * eml_r_1 + i] + eml_E[3 *
                eml_r_1] * eml_A_3[i];
              eml_D_5[i + 3 * eml_r_1] = eml_E[3 * eml_r_1 + 1] * eml_A_3[i + 3]
                + eml_D_5[3 * eml_r_1 + i];
              eml_D_5[i + 3 * eml_r_1] = eml_E[3 * eml_r_1 + 2] * eml_A_3[i + 6]
                + eml_D_5[3 * eml_r_1 + i];
            }
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_A_b[i + 3 * eml_r_1] = 0.0;
              eml_A_b[i + 3 * eml_r_1] = eml_A_b[3 * eml_r_1 + i] + eml_E_0[3 *
                eml_r_1] * eml_D_5[i];
              eml_A_b[i + 3 * eml_r_1] = eml_E_0[3 * eml_r_1 + 1] * eml_D_5[i +
                3] + eml_A_b[3 * eml_r_1 + i];
              eml_A_b[i + 3 * eml_r_1] = eml_E_0[3 * eml_r_1 + 2] * eml_D_5[i +
                6] + eml_A_b[3 * eml_r_1 + i];
            }
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_D_5[i + 3 * eml_r_1] = 0.0;
              eml_D_5[i + 3 * eml_r_1] = eml_D_5[3 * eml_r_1 + i] + eml_E[3 *
                eml_r_1] * eml_A_3[i];
              eml_D_5[i + 3 * eml_r_1] = eml_E[3 * eml_r_1 + 1] * eml_A_3[i + 3]
                + eml_D_5[3 * eml_r_1 + i];
              eml_D_5[i + 3 * eml_r_1] = eml_E[3 * eml_r_1 + 2] * eml_A_3[i + 6]
                + eml_D_5[3 * eml_r_1 + i];
            }
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_D_6[i + 3 * eml_r_1] = 0.0;
              eml_D_6[i + 3 * eml_r_1] = eml_D_6[3 * eml_r_1 + i] + eml_E_0[3 *
                eml_r_1] * eml_D_5[i];
              eml_D_6[i + 3 * eml_r_1] = eml_E_0[3 * eml_r_1 + 1] * eml_D_5[i +
                3] + eml_D_6[3 * eml_r_1 + i];
              eml_D_6[i + 3 * eml_r_1] = eml_E_0[3 * eml_r_1 + 2] * eml_D_5[i +
                6] + eml_D_6[3 * eml_r_1 + i];
            }
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_A_c[i + 3 * eml_r_1] = 0.0;
              eml_A_c[i + 3 * eml_r_1] = eml_A_c[3 * eml_r_1 + i] + eml_E_1[3 *
                eml_r_1] * eml_D_6[i];
              eml_A_c[i + 3 * eml_r_1] = eml_E_1[3 * eml_r_1 + 1] * eml_D_6[i +
                3] + eml_A_c[3 * eml_r_1 + i];
              eml_A_c[i + 3 * eml_r_1] = eml_E_1[3 * eml_r_1 + 2] * eml_D_6[i +
                6] + eml_A_c[3 * eml_r_1 + i];
            }
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_D_5[i + 3 * eml_r_1] = 0.0;
              eml_D_5[i + 3 * eml_r_1] = eml_D_5[3 * eml_r_1 + i] + eml_E[3 *
                eml_r_1] * eml_A_3[i];
              eml_D_5[i + 3 * eml_r_1] = eml_E[3 * eml_r_1 + 1] * eml_A_3[i + 3]
                + eml_D_5[3 * eml_r_1 + i];
              eml_D_5[i + 3 * eml_r_1] = eml_E[3 * eml_r_1 + 2] * eml_A_3[i + 6]
                + eml_D_5[3 * eml_r_1 + i];
            }
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_D_6[i + 3 * eml_r_1] = 0.0;
              eml_D_6[i + 3 * eml_r_1] = eml_D_6[3 * eml_r_1 + i] + eml_E_0[3 *
                eml_r_1] * eml_D_5[i];
              eml_D_6[i + 3 * eml_r_1] = eml_E_0[3 * eml_r_1 + 1] * eml_D_5[i +
                3] + eml_D_6[3 * eml_r_1 + i];
              eml_D_6[i + 3 * eml_r_1] = eml_E_0[3 * eml_r_1 + 2] * eml_D_5[i +
                6] + eml_D_6[3 * eml_r_1 + i];
            }
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_D_7[i + 3 * eml_r_1] = 0.0;
              eml_D_7[i + 3 * eml_r_1] = eml_D_7[3 * eml_r_1 + i] + eml_E_1[3 *
                eml_r_1] * eml_D_6[i];
              eml_D_7[i + 3 * eml_r_1] = eml_E_1[3 * eml_r_1 + 1] * eml_D_6[i +
                3] + eml_D_7[3 * eml_r_1 + i];
              eml_D_7[i + 3 * eml_r_1] = eml_E_1[3 * eml_r_1 + 2] * eml_D_6[i +
                6] + eml_D_7[3 * eml_r_1 + i];
            }
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_D_5[i + 3 * eml_r_1] = 0.0;
              eml_D_5[i + 3 * eml_r_1] = eml_D_5[3 * eml_r_1 + i] + eml_E_2[3 *
                eml_r_1] * eml_D_7[i];
              eml_D_5[i + 3 * eml_r_1] = eml_E_2[3 * eml_r_1 + 1] * eml_D_7[i +
                3] + eml_D_5[3 * eml_r_1 + i];
              eml_D_5[i + 3 * eml_r_1] = eml_E_2[3 * eml_r_1 + 2] * eml_D_7[i +
                6] + eml_D_5[3 * eml_r_1 + i];
            }
          }

          for (i = 0; i < 3; i++) {
            eml_A_h[i] = eml_D_5[i + 6] * 0.0 + (eml_D_5[i + 3] * 0.0 +
              eml_D_5[i]);
            eml_A_g[i] = eml_A_c[i + 6] * 0.0 + (eml_A_c[i + 3] + eml_A_c[i] *
              0.0);
            eml_A_f[i] = eml_A_b[i + 6] * 0.0 + (eml_A_b[i + 3] * 0.0 +
              eml_A_b[i]);
            eml_A_e[i] = eml_A_a[i + 6] * 0.0 + (eml_A_a[i + 3] + eml_A_a[i] *
              0.0);
            eml_A_d[i] = eml_A_3[i + 6] * 0.0 + (eml_A_3[i + 3] + eml_A_3[i] *
              0.0);
          }

          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 3; eml_r_1++) {
              eml_D_5[i + 3 * eml_r_1] = 0.0;
              eml_D_5[i + 3 * eml_r_1] = eml_D_5[3 * eml_r_1 + i] + eml_A_9[3 *
                eml_r_1] * eml_A_8[i];
              eml_D_5[i + 3 * eml_r_1] = eml_A_9[3 * eml_r_1 + 1] * eml_A_8[i +
                3] + eml_D_5[3 * eml_r_1 + i];
              eml_D_5[i + 3 * eml_r_1] = eml_A_9[3 * eml_r_1 + 2] * eml_A_8[i +
                6] + eml_D_5[3 * eml_r_1 + i];
            }
          }

          tmp_0[0] = 0.0;
          tmp_0[1] = 0.0;
          tmp_0[2] = 1.0;
          tmp_0[3] = eml_A_d[0];
          tmp_0[4] = eml_A_d[1];
          tmp_0[5] = eml_A_d[2];
          tmp_0[6] = eml_A_e[0];
          tmp_0[7] = eml_A_e[1];
          tmp_0[8] = eml_A_e[2];
          tmp_0[9] = eml_A_f[0];
          tmp_0[10] = eml_A_f[1];
          tmp_0[11] = eml_A_f[2];
          tmp_0[12] = eml_A_g[0];
          tmp_0[13] = eml_A_g[1];
          tmp_0[14] = eml_A_g[2];
          tmp_0[15] = eml_A_h[0];
          tmp_0[16] = eml_A_h[1];
          tmp_0[17] = eml_A_h[2];
          for (i = 0; i < 3; i++) {
            for (eml_r_1 = 0; eml_r_1 < 6; eml_r_1++) {
              eml_A_i[i + 3 * eml_r_1] = 0.0;
              eml_A_i[i + 3 * eml_r_1] = eml_A_i[3 * eml_r_1 + i] + tmp_0[3 *
                eml_r_1] * eml_D_5[i];
              eml_A_i[i + 3 * eml_r_1] = tmp_0[3 * eml_r_1 + 1] * eml_D_5[i + 3]
                + eml_A_i[3 * eml_r_1 + i];
              eml_A_i[i + 3 * eml_r_1] = tmp_0[3 * eml_r_1 + 2] * eml_D_5[i + 6]
                + eml_A_i[3 * eml_r_1 + i];
            }
          }

          for (i = 0; i < 6; i++) {
            eml_x_0[6 * i] = eml_x_2[i << 2];
            eml_x_0[1 + 6 * i] = eml_x_2[(i << 2) + 1];
            eml_x_0[2 + 6 * i] = eml_x_2[(i << 2) + 2];
          }

          for (i = 0; i < 6; i++) {
            eml_x_0[3 + 6 * i] = eml_A_i[3 * i];
            eml_x_0[4 + 6 * i] = eml_A_i[3 * i + 1];
            eml_x_0[5 + 6 * i] = eml_A_i[3 * i + 2];
          }

          M43_Sim_Forcing_003h_Tra_invNxN(eml_x_0, tmp);
          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_0[eml_r_1 << 2] * eml_D[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 1] *
                eml_D[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 2] *
                eml_D[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_0[(eml_r_1 << 2) + 3] *
                eml_D[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_9[i + (eml_r_1 << 2)] = 0.0;
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
                eml_D_1[eml_r_1 << 2] * eml_D_8[i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_1[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_D_9[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_2[eml_r_1 << 2] * eml_D_9[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 1] *
                eml_D_9[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 2] *
                eml_D_9[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_2[(eml_r_1 << 2) + 3] *
                eml_D_9[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_9[i + (eml_r_1 << 2)] = 0.0;
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_9[(eml_r_1 << 2) + i] +
                eml_D_3[eml_r_1 << 2] * eml_D_8[i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 1] *
                eml_D_8[i + 4] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 2] *
                eml_D_8[i + 8] + eml_D_9[(eml_r_1 << 2) + i];
              eml_D_9[i + (eml_r_1 << 2)] = eml_D_3[(eml_r_1 << 2) + 3] *
                eml_D_8[i + 12] + eml_D_9[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            for (eml_r_1 = 0; eml_r_1 < 4; eml_r_1++) {
              eml_D_8[i + (eml_r_1 << 2)] = 0.0;
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_8[(eml_r_1 << 2) + i] +
                eml_D_4[eml_r_1 << 2] * eml_D_9[i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 1] *
                eml_D_9[i + 4] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 2] *
                eml_D_9[i + 8] + eml_D_8[(eml_r_1 << 2) + i];
              eml_D_8[i + (eml_r_1 << 2)] = eml_D_4[(eml_r_1 << 2) + 3] *
                eml_D_9[i + 12] + eml_D_8[(eml_r_1 << 2) + i];
            }
          }

          for (i = 0; i < 4; i++) {
            eml_maxval = eml_D_8[i + 12] + (eml_D_8[i + 8] * 0.0 + (eml_D_8[i +
              4] * 0.0 + eml_D_8[i] * 0.0));
            eml_D_a[i] = eml_maxval;
          }

          eml_z_p[0] =
            M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctio_i[0]
            - eml_D_a[0];
          eml_z_p[1] =
            M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctio_i[1]
            - eml_D_a[1];
          eml_z_p[2] = eml_z_p_idx - eml_D_a[2];
          eml_z_p[3] = 1.7453292519943295E-002 * eml_x_p[0] - rt_atan2_snf
            (eml_E_3[7], eml_E_3[8]);
          eml_z_p[4] = 1.7453292519943295E-002 * eml_x_p[1] - eml_c_idx;
          eml_z_p[5] = 1.7453292519943295E-002 * eml_x_p[2] - eml_c_idx_0;

          /* '<S114>:1:194' */
          for (i = 0; i < 6; i++) {
            eml_d_ang[i] = 0.0;
            for (eml_r_1 = 0; eml_r_1 < 6; eml_r_1++) {
              eml_d_ang[i] += tmp[6 * eml_r_1 + i] * eml_z_p[eml_r_1];
            }

            eml_ang_0[i] += eml_d_ang[i];
          }

          /* '<S114>:1:195' */
          for (eml_r_1 = 0; eml_r_1 < 6; eml_r_1++) {
            for (eml_A = eml_ang_0[eml_r_1]; eml_A > 3.1415926535897931E+000;
                 eml_A -= 6.2831853071795862E+000) {
            }

            while (eml_A < -3.1415926535897931E+000) {
              eml_A += 6.2831853071795862E+000;
            }

            eml_ang_0[eml_r_1] = eml_A;
          }

          if (M43_Sim_Forcing_003h_Traje_norm(eml_d_ang) < 1.0E-006) {
            /* '<S114>:1:196' */
            /* '<S114>:1:197' */
            for (eml_r_1 = 0; eml_r_1 < 6; eml_r_1++) {
              for (eml_A = eml_ang_0[eml_r_1]; eml_A > 3.1415926535897931E+000;
                   eml_A -= 6.2831853071795862E+000) {
              }

              while (eml_A < -3.1415926535897931E+000) {
                eml_A += 6.2831853071795862E+000;
              }

              eml_ang_0[eml_r_1] = eml_A;
            }

            /* '<S114>:1:198' */
            for (i = 0; i < 6; i++) {
              eml_maxval = 5.7295779513082323E+001 * eml_ang_0[i];
              M43_Sim_Forcing_003h_Trajectory_B.out_g[i] = eml_maxval;
              eml_ang_0[i] = eml_maxval;
            }

            /* '<S114>:1:199' */
            M43_Sim_Forcing_003h_Trajectory_B.out_g[6] = (real_T)eml_r;

            /*  tests whether the links are within the set soft limits */
            eml_r_1 = 1;
            eml_r_0 = 2;
          } else {
            /* '<S114>:1:202' */
            eml_r++;

            /*  if more than 10 iterations, no convergence */
            if (eml_r > 10) {
              /* '<S114>:1:205' */
              /* '<S114>:1:206' */
              for (i = 0; i < 6; i++) {
                M43_Sim_Forcing_003h_Trajectory_B.out_g[i] = eml_ang[i];
              }

              /*  return vector as is */
              /* '<S114>:1:207' */
              M43_Sim_Forcing_003h_Trajectory_B.out_g[6] = -1.0;
              eml_r_0 = 1;
            }
          }
        } while ((uint32_T)eml_r_0 == 0U);

        if ((uint32_T)eml_r_0 != 1U) {
          eml_exitg = false;
          while (((uint32_T)eml_exitg == 0U) && (eml_r_1 <= 6)) {
            /* '<S114>:1:213' */
            if (eml_ang_0[eml_r_1 - 1] >= (real_T)tmp_9[(eml_r_1 - 1) << 1]) {
              /* '<S114>:1:214' */
              /* '<S114>:1:215' */
              M43_Sim_Forcing_003h_Trajectory_B.out_g[6] = -3.0;
              eml_exitg = true;
            } else if (eml_ang_0[eml_r_1 - 1] <= (real_T)tmp_9[((eml_r_1 - 1) <<
                        1) + 1]) {
              /* '<S114>:1:217' */
              /* '<S114>:1:218' */
              M43_Sim_Forcing_003h_Trajectory_B.out_g[6] = -3.0;
              eml_exitg = true;
            } else {
              eml_r_1++;
            }
          }
        }
      }

      srUpdateBC
        (M43_Sim_Forcing_003h_Trajectory_DWork.fullinversekin_SubsysRanBC);
    }

    /* end of Outputs for SubSystem: '<S110>/full inverse kin' */

    /* Switch: '<S106>/Switch' */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch1 >
        M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold) {
      /* Sum: '<S112>/Sum1' */
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_j[0] =
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1[0];
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_j[1] =
        M43_Sim_Forcing_003h_Trajectory_B.out[1] +
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1[1];
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_j[2] =
        M43_Sim_Forcing_003h_Trajectory_B.out[2] +
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1[2];
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_j[3] =
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1[3];
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_j[4] =
        M43_Sim_Forcing_003h_Trajectory_B.out[4] +
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1[4];
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_j[5] =
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1[5];
      for (i = 0; i < 6; i++) {
        M43_Sim_Forcing_003h_Trajectory_B.Switch[i] =
          M43_Sim_Forcing_003h_Trajectory_B.Sum1_j[i];
      }

      M43_Sim_Forcing_003h_Trajectory_B.Switch[6] =
        M43_Sim_Forcing_003h_Trajectory_B.out[6];
    } else {
      for (i = 0; i < 7; i++) {
        M43_Sim_Forcing_003h_Trajectory_B.Switch[i] =
          M43_Sim_Forcing_003h_Trajectory_B.out_g[i];
      }
    }

    for (i = 0; i < 6; i++) {
      /* Gain: '<S111>/Gain' */
      M43_Sim_Forcing_003h_Trajectory_B.Sum6[i] =
        M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_p[i] *
        M43_Sim_Forcing_003h_Trajectory_B.Switch[i];

      /* Sum: '<S111>/Sum' incorporates:
       *  Constant: '<S111>/Constant'
       */
      M43_Sim_Forcing_003h_Trajectory_B.Sum_b[i] =
        M43_Sim_Forcing_003h_Trajectory_B.Sum6[i] +
        M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_k[i];
    }

    /* Sum: '<S10>/Sum2' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum2_b =
      M43_Sim_Forcing_003h_Trajectory_B.psi +
      M43_Sim_Forcing_003h_Trajectory_B.Sum_b[0];

    /* Outputs for enable SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' incorporates:
     *  EnablePort: '<S1>/Enable'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.SwitchControl > 0.0) {
      /* DataTypeConversion: '<S1>/Data Type Conversion' */
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion_b[0] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum9;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion_b[1] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum15;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion_b[2] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum11;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion_b[3] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Phi1;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion_b[4] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Theta1;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion_b[5] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum3;

      /* Byte Packing: <S1>/Byte Packing  */
      (void)memcpy((uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.BytePacking_g + 0,
                   (uint8_T*)
                   M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion_b, 24);
      (void)memcpy((uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.BytePacking_g +
                   24, (uint8_T*)&M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3_p,
                   4);

      /* DataTypeConversion: '<S1>/Data Type Conversion4' */
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion4[0] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum1_n;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion4[1] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum8;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion4[2] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum4;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion4[3] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum7;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion4[4] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum5;
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion4[5] = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Sum12;

      /* Gain: '<S15>/Gain1' */
      M43_Sim_Forcing_003h_Trajectory_B.Gain1_g =
        M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_h *
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion4[3];

      /* Gain: '<S15>/Gain' */
      M43_Sim_Forcing_003h_Trajectory_B.Gain_j =
        M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_ir *
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion4[4];

      /* Gain: '<S15>/Gain2' */
      M43_Sim_Forcing_003h_Trajectory_B.Sum_b4 =
        M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_lz *
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion4[5];

      /* Sum: '<S15>/Sum' */
      M43_Sim_Forcing_003h_Trajectory_B.Sum_l =
        M43_Sim_Forcing_003h_Trajectory_B.Sum_b4 +
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion_b[5];

      /* Switch: '<S16>/SwitchControl' incorporates:
       *  Constant: '<S16>/Constant'
       */
      if (M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_d >
          M43_Sim_Forcing_003h_Trajectory_P.SwitchControl_Threshold_p) {
        M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_d[0] =
          M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion_b[0];
        M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_d[1] =
          M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion_b[1];
        M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_d[2] =
          M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion_b[2];
        M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_d[3] =
          M43_Sim_Forcing_003h_Trajectory_B.Gain1_g;
        M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_d[4] =
          M43_Sim_Forcing_003h_Trajectory_B.Gain_j;
        M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_d[5] =
          M43_Sim_Forcing_003h_Trajectory_B.Sum_l;
      } else {
        /* DataTypeConversion: '<S1>/Data Type Conversion2' */
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion2[0] = (real32_T)
          M43_Sim_Forcing_003h_Trajectory_B.Sum2_b;
        for (i = 0; i < 5; i++) {
          M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion2[i + 1] =
            (real32_T)M43_Sim_Forcing_003h_Trajectory_B.Sum_b[i + 1];
        }

        for (i = 0; i < 6; i++) {
          M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_d[i] =
            M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion2[i];
        }
      }

      /* DataTypeConversion: '<S1>/Data Type Conversion3' */
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_c = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_p[0];

      /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_ae =
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_n;

      /* Byte Packing: <S1>/Byte Packing 1 */
      (void)memcpy((uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.BytePacking1_m +
                   0, (uint8_T*)
                   M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_d, 24);
      (void)memcpy((uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.BytePacking1_m +
                   24, (uint8_T*)
                   &M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_c, 4);
      (void)memcpy((uint8_T*)M43_Sim_Forcing_003h_Trajectory_B.BytePacking1_m +
                   28, (uint8_T*)
                   &M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_ae,
                   4);

      /* Level2 S-Function Block: '<S1>/GT-RT UDP TX' (gt_rt_udp_send) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[0];
        sfcnOutputs(rts, 0);
      }

      /* Level2 S-Function Block: '<S1>/GT-RT UDP TX1' (gt_rt_udp_send) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[1];
        sfcnOutputs(rts, 0);
      }

      /* Logic: '<S14>/Logical Operator' */
      M43_Sim_Forcing_003h_Trajectory_B.LogicalOperator_a =
        ((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_p[5] != 0) ||
         (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_p[4] != 0));

      /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
      if ((!M43_Sim_Forcing_003h_Trajectory_B.LogicalOperator_a) &&
          (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_c
           == 1)) {
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f =
          M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_o;
      }

      if (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f >=
          M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_Upper_a) {
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f =
          M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_Upper_a;
      } else {
        if (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f
            <= M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_Lower_p)
        {
          M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f =
            M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_Lower_p;
        }
      }

      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_a =
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f;

      /* DataTypeConversion: '<S14>/Data Type Conversion1' */
      M43_Sim_Forcing_003h_Trajectory_B.Sum_b4 = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_p[4];

      /* DataTypeConversion: '<S14>/Data Type Conversion2' */
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion2_o = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_p[5];

      /* DataTypeConversion: '<S14>/Data Type Conversion3' */
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_pr = (real32_T)
        M43_Sim_Forcing_003h_Trajectory_B.LogicalOperator_a;

      /* Sum: '<S14>/Sum' */
      M43_Sim_Forcing_003h_Trajectory_B.Sum_b4 =
        M43_Sim_Forcing_003h_Trajectory_B.Sum_b4 -
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion2_o;

      /* Product: '<S14>/Product' */
      M43_Sim_Forcing_003h_Trajectory_B.Product_m =
        M43_Sim_Forcing_003h_Trajectory_B.Sum_b4 *
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_a;

      /* Level2 S-Function Block: '<S1>/GT-RT UDP  Write' (gt_rt_udp_controller) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[2];
        sfcnOutputs(rts, 0);
      }

      /* Level2 S-Function Block: '<S1>/GT-RT UDP  Write1' (gt_rt_udp_controller) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[3];
        sfcnOutputs(rts, 0);
      }

      srUpdateBC
        (M43_Sim_Forcing_003h_Trajectory_DWork._DOFVisualCab120615_SubsysRanBC);
    }

    /* end of Outputs for SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' */

    /* Sum: '<S52>/Add2' incorporates:
     *  Constant: '<S52>/PSEA1'
     */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain_m;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M43_Sim_Forcing_003h_Trajectory_P.PSEA1_Value;

    /* Abs: '<S52>/Abs2' */
    M43_Sim_Forcing_003h_Trajectory_B.Abs2 = fabs
      (M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c);

    /* UnitDelay: '<S105>/Unit Delay6' */
    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Sum6[i] =
        M43_Sim_Forcing_003h_Trajectory_DWork.UnitDelay6_DSTATE[i];
    }

    /* Sum: '<S105>/Sum6' */
    eml_ang_0[0] = M43_Sim_Forcing_003h_Trajectory_B.Sum2_b;
    for (i = 0; i < 5; i++) {
      eml_ang_0[i + 1] = M43_Sim_Forcing_003h_Trajectory_B.Sum_b[1 + i];
    }

    /* Sum: '<S10>/Sum1' */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain_m;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_o[0] =
      M43_Sim_Forcing_003h_Trajectory_B.Sum2_b - ldexp(sMultiWord2Double
      (&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain2_e;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_o[1] =
      M43_Sim_Forcing_003h_Trajectory_B.Sum_b[1] - ldexp(sMultiWord2Double
      (&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain6;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_o[2] =
      M43_Sim_Forcing_003h_Trajectory_B.Sum_b[2] - ldexp(sMultiWord2Double
      (&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain1_e;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_o[3] =
      M43_Sim_Forcing_003h_Trajectory_B.Sum_b[3] - ldexp(sMultiWord2Double
      (&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain3_b;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_o[4] =
      M43_Sim_Forcing_003h_Trajectory_B.Sum_b[4] - ldexp(sMultiWord2Double
      (&tmp_3.chunks[0U], 2), -41);
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain4_m;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_o[5] =
      M43_Sim_Forcing_003h_Trajectory_B.Sum_b[5] - ldexp(sMultiWord2Double
      (&tmp_3.chunks[0U], 2), -41);

    /* Gain: '<S10>/Gain1' incorporates:
     *  Constant: '<Root>/Gain'
     */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c =
      M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_e *
      M43_Sim_Forcing_003h_Trajectory_P.Gain_Value;
    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Sum6[i] = eml_ang_0[i] -
        M43_Sim_Forcing_003h_Trajectory_B.Sum6[i];

      /* Product: '<S10>/Control Loop Gain' */
      M43_Sim_Forcing_003h_Trajectory_B.ControlLoopGain[i] =
        M43_Sim_Forcing_003h_Trajectory_B.Sum1_o[i] *
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c;

      /* Sum: '<S10>/Sum' */
      M43_Sim_Forcing_003h_Trajectory_B.Sum_k[i] =
        M43_Sim_Forcing_003h_Trajectory_B.Sum6[i] +
        M43_Sim_Forcing_003h_Trajectory_B.ControlLoopGain[i];
    }

    /* DiscreteTransferFcn: '<S10>/Butterworth Filter 10 Hz' */
    for (eml_r_0 = 0; eml_r_0 < 6; eml_r_0++) {
      eml_r_1 = eml_r_0 << 2;
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp[eml_r_0] =
        ((((M43_Sim_Forcing_003h_Trajectory_B.Sum_k[eml_r_0] -
            M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denominat[1]
            * M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[
            eml_r_1]) -
           M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[eml_r_1
           + 1] *
           M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denominat[2])
          - M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[eml_r_1
          + 2] *
          M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denominat[3])
         - M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[eml_r_1
         + 3] *
         M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denominat[4]) /
        M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denominat[0];
      M43_Sim_Forcing_003h_Trajectory_B.ButterworthFilter10Hz[eml_r_0] =
        (((M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerator[0] *
           M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp[eml_r_0]
           + M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerator[1]
           * M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[eml_r_1])
          + M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[eml_r_1
          + 1] *
          M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerator[2])
         + M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[eml_r_1
         + 2] *
         M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerator[3]) +
        M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[eml_r_1
        + 3] *
        M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerator[4];
    }

    /* Switch: '<Root>/Switch' */
    if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[0] >
        M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_d) {
      for (i = 0; i < 6; i++) {
        /* Switch: '<S11>/SwitchControl' incorporates:
         *  Constant: '<S11>/Constant'
         */
        if (M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_e >
            M43_Sim_Forcing_003h_Trajectory_P.SwitchControl_Threshold_a) {
          M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_a[i] =
            M43_Sim_Forcing_003h_Trajectory_B.ButterworthFilter10Hz[i];
        } else {
          M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_a[i] = 0.0;
        }

        M43_Sim_Forcing_003h_Trajectory_B.Switch_m[i] =
          M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_a[i];
      }
    } else {
      for (i = 0; i < 6; i++) {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_m[i] = 0.0;
      }
    }

    /* Sum: '<S52>/Add1' incorporates:
     *  Constant: '<S52>/NSEA1'
     */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain_m;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M43_Sim_Forcing_003h_Trajectory_P.NSEA1_Value;

    /* Abs: '<S52>/Abs1' */
    M43_Sim_Forcing_003h_Trajectory_B.Abs1 = fabs
      (M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c);

    /* If: '<S52>/If2' incorporates:
     *  ActionPort: '<S58>/Action Port'
     *  ActionPort: '<S59>/Action Port'
     *  SubSystem: '<S52>/If Action Subsystem'
     *  SubSystem: '<S52>/If Action Subsystem1'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[0] > 0.0) {
      /* Switch: '<S58>/Switch' incorporates:
       *  Constant: '<S58>/PSEA2'
       */
      if (M43_Sim_Forcing_003h_Trajectory_B.Abs2 >
          M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_i) {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_dx =
          M43_Sim_Forcing_003h_Trajectory_B.Switch_m[0];
      } else {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_dx =
          M43_Sim_Forcing_003h_Trajectory_P.PSEA2_Value;
      }

      srUpdateBC
        (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_SubsysRanBC);
    } else {
      M43_Sim_Forc_IfActionSubsystem1
        (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[0],
         M43_Sim_Forcing_003h_Trajectory_B.Abs1,
         &M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1,
         (rtP_IfActionSubsystem1_M43_Sim_ *)
         &M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1);
    }

    /* Switch: '<S52>/Switch1' */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[0] != 0.0) {
      /* Switch: '<S52>/Switch' */
      if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[0] >
          M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_b) {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_po =
          M43_Sim_Forcing_003h_Trajectory_B.Switch_dx;
      } else {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_po =
          M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1.Switch;
      }

      M43_Sim_Forcing_003h_Trajectory_B.Switch1_d =
        M43_Sim_Forcing_003h_Trajectory_B.Switch_po;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_d =
        M43_Sim_Forcing_003h_Trajectory_B.Switch_m[0];
    }

    /* Saturate: '<S20>/Vel Limiter A1' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = rt_SATURATE
      (M43_Sim_Forcing_003h_Trajectory_B.Switch1_d,
       M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA1_LowerSat,
       M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA1_UpperSat);

    /* RateLimiter: '<S20>/Acc Limiter A1' */
    eml_maxval = M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c -
      M43_Sim_Forcing_003h_Trajectory_DWork.PrevY;
    if (eml_maxval > M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA1_RisingLim) {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA1 =
        M43_Sim_Forcing_003h_Trajectory_DWork.PrevY +
        M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA1_RisingLim;
    } else if (eml_maxval <
               M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA1_FallingLim) {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA1 =
        M43_Sim_Forcing_003h_Trajectory_DWork.PrevY +
        M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA1_FallingLim;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA1 =
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c;
    }

    M43_Sim_Forcing_003h_Trajectory_DWork.PrevY =
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA1;

    /* Sum: '<S53>/Add2' incorporates:
     *  Constant: '<S53>/PSEA1'
     */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain2_e;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M43_Sim_Forcing_003h_Trajectory_P.PSEA1_Value_k;

    /* Abs: '<S53>/Abs2' */
    M43_Sim_Forcing_003h_Trajectory_B.Abs2_m = fabs
      (M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c);

    /* Sum: '<S53>/Add1' incorporates:
     *  Constant: '<S53>/NSEA1'
     */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain2_e;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M43_Sim_Forcing_003h_Trajectory_P.NSEA1_Value_l;

    /* Abs: '<S53>/Abs1' */
    M43_Sim_Forcing_003h_Trajectory_B.Abs1_h = fabs
      (M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c);

    /* If: '<S53>/If2' incorporates:
     *  ActionPort: '<S60>/Action Port'
     *  ActionPort: '<S61>/Action Port'
     *  SubSystem: '<S53>/If Action Subsystem'
     *  SubSystem: '<S53>/If Action Subsystem1'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[1] > 0.0) {
      M43_Sim_Forci_IfActionSubsystem
        (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[1],
         M43_Sim_Forcing_003h_Trajectory_B.Abs2_m,
         &M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_h,
         (rtP_IfActionSubsystem_M43_Sim_F *)
         &M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_h);
    } else {
      M43_Sim_Forc_IfActionSubsystem1
        (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[1],
         M43_Sim_Forcing_003h_Trajectory_B.Abs1_h,
         &M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_f,
         (rtP_IfActionSubsystem1_M43_Sim_ *)
         &M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_f);
    }

    /* Switch: '<S53>/Switch1' */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[1] != 0.0) {
      /* Switch: '<S53>/Switch' */
      if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[1] >=
          M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_h) {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_dh =
          M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_h.Switch;
      } else {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_dh =
          M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_f.Switch;
      }

      M43_Sim_Forcing_003h_Trajectory_B.Switch1_a =
        M43_Sim_Forcing_003h_Trajectory_B.Switch_dh;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_a =
        M43_Sim_Forcing_003h_Trajectory_B.Switch_m[1];
    }

    /* Saturate: '<S20>/Vel Limiter A2' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = rt_SATURATE
      (M43_Sim_Forcing_003h_Trajectory_B.Switch1_a,
       M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA2_LowerSat,
       M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA2_UpperSat);

    /* RateLimiter: '<S20>/Acc Limiter A2' */
    eml_maxval = M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c -
      M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_n;
    if (eml_maxval > M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA2_RisingLim) {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA2 =
        M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_n +
        M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA2_RisingLim;
    } else if (eml_maxval <
               M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA2_FallingLim) {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA2 =
        M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_n +
        M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA2_FallingLim;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA2 =
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c;
    }

    M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_n =
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA2;

    /* Sum: '<S54>/Add2' incorporates:
     *  Constant: '<S54>/PSEA1'
     */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain6;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M43_Sim_Forcing_003h_Trajectory_P.PSEA1_Value_j;

    /* Abs: '<S54>/Abs2' */
    M43_Sim_Forcing_003h_Trajectory_B.Abs2_g = fabs
      (M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c);

    /* Sum: '<S54>/Add1' incorporates:
     *  Constant: '<S54>/NSEA1'
     */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain6;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M43_Sim_Forcing_003h_Trajectory_P.NSEA1_Value_d;

    /* Abs: '<S54>/Abs1' */
    M43_Sim_Forcing_003h_Trajectory_B.Abs1_i = fabs
      (M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c);

    /* If: '<S54>/If2' incorporates:
     *  ActionPort: '<S62>/Action Port'
     *  ActionPort: '<S63>/Action Port'
     *  SubSystem: '<S54>/If Action Subsystem'
     *  SubSystem: '<S54>/If Action Subsystem1'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[2] > 0.0) {
      M43_Sim_Forci_IfActionSubsystem
        (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[2],
         M43_Sim_Forcing_003h_Trajectory_B.Abs2_g,
         &M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_i,
         (rtP_IfActionSubsystem_M43_Sim_F *)
         &M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_i);
    } else {
      M43_Sim_Forc_IfActionSubsystem1
        (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[2],
         M43_Sim_Forcing_003h_Trajectory_B.Abs1_i,
         &M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_k,
         (rtP_IfActionSubsystem1_M43_Sim_ *)
         &M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_k);
    }

    /* Switch: '<S54>/Switch1' */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[2] != 0.0) {
      /* Switch: '<S54>/Switch' */
      if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[2] >=
          M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_k) {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_n =
          M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_i.Switch;
      } else {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_n =
          M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_k.Switch;
      }

      M43_Sim_Forcing_003h_Trajectory_B.Switch1_b =
        M43_Sim_Forcing_003h_Trajectory_B.Switch_n;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_b =
        M43_Sim_Forcing_003h_Trajectory_B.Switch_m[2];
    }

    /* Saturate: '<S20>/Vel Limiter A3' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = rt_SATURATE
      (M43_Sim_Forcing_003h_Trajectory_B.Switch1_b,
       M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA3_LowerSat,
       M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA3_UpperSat);

    /* RateLimiter: '<S20>/Acc Limiter A3' */
    eml_maxval = M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c -
      M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_i;
    if (eml_maxval > M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA3_RisingLim) {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA3 =
        M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_i +
        M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA3_RisingLim;
    } else if (eml_maxval <
               M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA3_FallingLim) {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA3 =
        M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_i +
        M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA3_FallingLim;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA3 =
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c;
    }

    M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_i =
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA3;

    /* Sum: '<S55>/Add2' incorporates:
     *  Constant: '<S55>/PSEA1'
     */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain1_e;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M43_Sim_Forcing_003h_Trajectory_P.PSEA1_Value_c;

    /* Abs: '<S55>/Abs2' */
    M43_Sim_Forcing_003h_Trajectory_B.Abs2_c = fabs
      (M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c);

    /* Sum: '<S55>/Add1' incorporates:
     *  Constant: '<S55>/NSEA1'
     */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain1_e;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M43_Sim_Forcing_003h_Trajectory_P.NSEA1_Value_p;

    /* Abs: '<S55>/Abs1' */
    M43_Sim_Forcing_003h_Trajectory_B.Abs1_ha = fabs
      (M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c);

    /* If: '<S55>/If2' incorporates:
     *  ActionPort: '<S64>/Action Port'
     *  ActionPort: '<S65>/Action Port'
     *  SubSystem: '<S55>/If Action Subsystem'
     *  SubSystem: '<S55>/If Action Subsystem1'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[3] > 0.0) {
      M43_Sim_Forci_IfActionSubsystem
        (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[3],
         M43_Sim_Forcing_003h_Trajectory_B.Abs2_c,
         &M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_d,
         (rtP_IfActionSubsystem_M43_Sim_F *)
         &M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_d);
    } else {
      M43_Sim_Forc_IfActionSubsystem1
        (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[3],
         M43_Sim_Forcing_003h_Trajectory_B.Abs1_ha,
         &M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_p,
         (rtP_IfActionSubsystem1_M43_Sim_ *)
         &M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_p);
    }

    /* Switch: '<S55>/Switch1' */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[3] != 0.0) {
      /* Switch: '<S55>/Switch' */
      if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[3] >=
          M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_a) {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_d =
          M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_d.Switch;
      } else {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_d =
          M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_p.Switch;
      }

      M43_Sim_Forcing_003h_Trajectory_B.Switch1_n =
        M43_Sim_Forcing_003h_Trajectory_B.Switch_d;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_n =
        M43_Sim_Forcing_003h_Trajectory_B.Switch_m[3];
    }

    /* Saturate: '<S20>/Vel Limiter A4' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = rt_SATURATE
      (M43_Sim_Forcing_003h_Trajectory_B.Switch1_n,
       M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA4_LowerSat,
       M43_Sim_Forcing_003h_Trajectory_P.VelLimiterA4_UpperSat);

    /* RateLimiter: '<S20>/Acc Limiter A4' */
    eml_maxval = M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c -
      M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_b;
    if (eml_maxval > M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA4_RisingLim) {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA4 =
        M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_b +
        M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA4_RisingLim;
    } else if (eml_maxval <
               M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA4_FallingLim) {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA4 =
        M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_b +
        M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA4_FallingLim;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA4 =
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c;
    }

    M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_b =
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA4;

    /* Sum: '<S56>/Add2' incorporates:
     *  Constant: '<S56>/PSEA1'
     */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain3_b;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M43_Sim_Forcing_003h_Trajectory_P.PSEA1_Value_n;

    /* Abs: '<S56>/Abs2' */
    M43_Sim_Forcing_003h_Trajectory_B.Abs2_b = fabs
      (M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c);

    /* Sum: '<S56>/Add1' incorporates:
     *  Constant: '<S56>/NSEA1'
     */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain3_b;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M43_Sim_Forcing_003h_Trajectory_P.NSEA1_Value_i;

    /* Abs: '<S56>/Abs1' */
    M43_Sim_Forcing_003h_Trajectory_B.Abs1_f = fabs
      (M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c);

    /* If: '<S56>/If2' incorporates:
     *  ActionPort: '<S66>/Action Port'
     *  ActionPort: '<S67>/Action Port'
     *  SubSystem: '<S56>/If Action Subsystem'
     *  SubSystem: '<S56>/If Action Subsystem1'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[4] > 0.0) {
      M43_Sim_Forci_IfActionSubsystem
        (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[4],
         M43_Sim_Forcing_003h_Trajectory_B.Abs2_b,
         &M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_e,
         (rtP_IfActionSubsystem_M43_Sim_F *)
         &M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_e);
    } else {
      M43_Sim_Forc_IfActionSubsystem1
        (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[4],
         M43_Sim_Forcing_003h_Trajectory_B.Abs1_f,
         &M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_d,
         (rtP_IfActionSubsystem1_M43_Sim_ *)
         &M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_d);
    }

    /* Switch: '<S56>/Switch1' */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[4] != 0.0) {
      /* Switch: '<S56>/Switch' */
      if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[4] >=
          M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_f) {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_p =
          M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_e.Switch;
      } else {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_p =
          M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_d.Switch;
      }

      M43_Sim_Forcing_003h_Trajectory_B.Switch1_c =
        M43_Sim_Forcing_003h_Trajectory_B.Switch_p;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_c =
        M43_Sim_Forcing_003h_Trajectory_B.Switch_m[4];
    }

    /* Saturate: '<S20>/Vel Limiter3' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = rt_SATURATE
      (M43_Sim_Forcing_003h_Trajectory_B.Switch1_c,
       M43_Sim_Forcing_003h_Trajectory_P.VelLimiter3_LowerSat,
       M43_Sim_Forcing_003h_Trajectory_P.VelLimiter3_UpperSat);

    /* RateLimiter: '<S20>/Acc Limiter A5' */
    eml_maxval = M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c -
      M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_bp;
    if (eml_maxval > M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA5_RisingLim) {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA5 =
        M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_bp +
        M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA5_RisingLim;
    } else if (eml_maxval <
               M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA5_FallingLim) {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA5 =
        M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_bp +
        M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA5_FallingLim;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA5 =
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c;
    }

    M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_bp =
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA5;

    /* Sum: '<S57>/Add2' incorporates:
     *  Constant: '<S57>/PSEA1'
     */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain4_m;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M43_Sim_Forcing_003h_Trajectory_P.PSEA1_Value_nt;

    /* Abs: '<S57>/Abs2' */
    M43_Sim_Forcing_003h_Trajectory_B.Abs2_f = fabs
      (M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c);

    /* Sum: '<S57>/Add1' incorporates:
     *  Constant: '<S57>/NSEA1'
     */
    tmp_3 = M43_Sim_Forcing_003h_Trajectory_B.Gain4_m;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = ldexp
      (sMultiWord2Double(&tmp_3.chunks[0U], 2), -41) -
      M43_Sim_Forcing_003h_Trajectory_P.NSEA1_Value_m;

    /* Abs: '<S57>/Abs1' */
    M43_Sim_Forcing_003h_Trajectory_B.Abs1_f5 = fabs
      (M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c);

    /* If: '<S57>/If2' incorporates:
     *  ActionPort: '<S68>/Action Port'
     *  ActionPort: '<S69>/Action Port'
     *  SubSystem: '<S57>/If Action Subsystem'
     *  SubSystem: '<S57>/If Action Subsystem1'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[5] > 0.0) {
      M43_Sim_Forci_IfActionSubsystem
        (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[5],
         M43_Sim_Forcing_003h_Trajectory_B.Abs2_f,
         &M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_d0,
         (rtP_IfActionSubsystem_M43_Sim_F *)
         &M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_d0);
    } else {
      M43_Sim_Forc_IfActionSubsystem1
        (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[5],
         M43_Sim_Forcing_003h_Trajectory_B.Abs1_f5,
         &M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_e,
         (rtP_IfActionSubsystem1_M43_Sim_ *)
         &M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_e);
    }

    /* Switch: '<S57>/Switch1' */
    if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[5] != 0.0) {
      /* Switch: '<S57>/Switch' */
      if (M43_Sim_Forcing_003h_Trajectory_B.Switch_m[5] >=
          M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_iw) {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_mx =
          M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_d0.Switch;
      } else {
        M43_Sim_Forcing_003h_Trajectory_B.Switch_mx =
          M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_e.Switch;
      }

      M43_Sim_Forcing_003h_Trajectory_B.Switch1_f =
        M43_Sim_Forcing_003h_Trajectory_B.Switch_mx;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_f =
        M43_Sim_Forcing_003h_Trajectory_B.Switch_m[5];
    }

    /* Saturate: '<S20>/Vel Limiter6' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = rt_SATURATE
      (M43_Sim_Forcing_003h_Trajectory_B.Switch1_f,
       M43_Sim_Forcing_003h_Trajectory_P.VelLimiter6_LowerSat,
       M43_Sim_Forcing_003h_Trajectory_P.VelLimiter6_UpperSat);

    /* RateLimiter: '<S20>/Acc Limiter A6' */
    eml_maxval = M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c -
      M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_p;
    if (eml_maxval > M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA6_RisingLim) {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA6 =
        M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_p +
        M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA6_RisingLim;
    } else if (eml_maxval <
               M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA6_FallingLim) {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA6 =
        M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_p +
        M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA6_FallingLim;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA6 =
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c;
    }

    M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_p =
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA6;

    /* Sum: '<S2>/Sum1' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_ks[0] =
      M43_Sim_Forcing_003h_Trajectory_B.Switch_m[0] -
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA1;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_ks[1] =
      M43_Sim_Forcing_003h_Trajectory_B.Switch_m[1] -
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA2;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_ks[2] =
      M43_Sim_Forcing_003h_Trajectory_B.Switch_m[2] -
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA3;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_ks[3] =
      M43_Sim_Forcing_003h_Trajectory_B.Switch_m[3] -
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA4;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_ks[4] =
      M43_Sim_Forcing_003h_Trajectory_B.Switch_m[4] -
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA5;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_ks[5] =
      M43_Sim_Forcing_003h_Trajectory_B.Switch_m[5] -
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA6;

    /* Gain: '<S18>/Gain' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain =
      M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_k *
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA1;

    /* Gain: '<S18>/Gain1' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain1 =
      M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_i *
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA2;

    /* Gain: '<S18>/Gain2' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain2 =
      M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain *
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA3;

    /* Gain: '<S18>/Gain3' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain3 =
      M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain *
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA4;

    /* Gain: '<S18>/Gain4' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain4 =
      M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain *
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA5;

    /* Gain: '<S18>/Gain5' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain5 =
      M43_Sim_Forcing_003h_Trajectory_P.Gain5_Gain *
      M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA6;

    /* If: '<S18>/If' incorporates:
     *  ActionPort: '<S27>/Action Port'
     *  SubSystem: '<S18>/If Action Subsystem1'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o5) {
      /* Gain: '<S28>/Gain1' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_p3 *
        M43_Sim_Forcing_003h_Trajectory_B.Gain;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain1_p = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S34>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent);

      /* Gain: '<S28>/Gain2' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_j *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain2_b = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S35>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_g);

      /* Gain: '<S28>/Gain3' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_p *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain3_i = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S36>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_k);

      /* Gain: '<S28>/Gain4' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_m *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain4_b = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* Gain: '<S29>/Gain1' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_l *
        M43_Sim_Forcing_003h_Trajectory_B.Gain1;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain1_a = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S37>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain1, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_n);

      /* Gain: '<S29>/Gain2' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_c *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain2_g = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S38>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain1, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_c);

      /* Gain: '<S29>/Gain3' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_ik *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain3_be = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S39>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain1, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_e);

      /* Gain: '<S29>/Gain4' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_f *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain4_n = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* Level2 S-Function Block: '<S27>/GT-RT CAN TX' (gt_rt_can_send) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[4];
        sfcnOutputs(rts, 0);
      }

      /* Gain: '<S30>/Gain1' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_n *
        M43_Sim_Forcing_003h_Trajectory_B.Gain2;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain1_n = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S40>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain2, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_j);

      /* Gain: '<S30>/Gain2' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_m *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain2_l = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S41>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain2, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_a);

      /* Gain: '<S30>/Gain3' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_o *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain3_ic = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S42>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain2, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_p);

      /* Gain: '<S30>/Gain4' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_g *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain4_g = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* Gain: '<S31>/Gain1' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_j *
        M43_Sim_Forcing_003h_Trajectory_B.Gain3;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain1_op = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S43>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain3, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_d);

      /* Gain: '<S31>/Gain2' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_l *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain2_ga = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S44>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain3, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_nk);

      /* Gain: '<S31>/Gain3' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_oc *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain3_l = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S45>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain3, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_kt);

      /* Gain: '<S31>/Gain4' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_c *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain4_c = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* Level2 S-Function Block: '<S27>/GT-RT CAN TX1' (gt_rt_can_send) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[5];
        sfcnOutputs(rts, 0);
      }

      /* Gain: '<S32>/Gain1' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_jm *
        M43_Sim_Forcing_003h_Trajectory_B.Gain4;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain1_d = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S46>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain4, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_dd);

      /* Gain: '<S32>/Gain2' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_p *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain2_f = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S47>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain4, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_g3);

      /* Gain: '<S32>/Gain3' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_h *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain3_d = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S48>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain4, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_f);

      /* Gain: '<S32>/Gain4' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_fl *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain4_k = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* Gain: '<S33>/Gain1' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_d *
        M43_Sim_Forcing_003h_Trajectory_B.Gain5;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain1_p2 = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S49>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain5, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_nj);

      /* Gain: '<S33>/Gain2' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain2_Gain_i *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain2_p = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S50>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain5, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_gq);

      /* Gain: '<S33>/Gain3' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_p5 *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain3_ha = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* ArithShift: '<S51>/shift' */
      M43_Sim_Forcing_003h_Trajectory_B.shift = ldexp
        (M43_Sim_Forcing_003h_Trajectory_B.Gain5, (int32_T)
         M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent_ed);

      /* Gain: '<S33>/Gain4' */
      eml_maxval = M43_Sim_Forcing_003h_Trajectory_P.Gain4_Gain_gu *
        M43_Sim_Forcing_003h_Trajectory_B.shift;
      if (rtIsNaN(eml_maxval) || rtIsInf(eml_maxval)) {
        eml_maxval = 0.0;
      } else {
        eml_maxval = fmod(floor(eml_maxval), 256.0);
      }

      M43_Sim_Forcing_003h_Trajectory_B.Gain4_h = eml_maxval < 0.0 ? (uint8_T)
        (int8_T)(-((int8_T)(uint8_T)(-eml_maxval))) : (uint8_T)eml_maxval;

      /* Level2 S-Function Block: '<S27>/GT-RT CAN TX2' (gt_rt_can_send) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[6];
        sfcnOutputs(rts, 0);
      }

      srUpdateBC
        (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_SubsysRanBC);
    }

    /* DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
    if (((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[3] > 0) &&
         (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_b <=
          0)) || ((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[3] <= 0) &&
                  (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_b
                   == 1))) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_k =
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_p;
    }

    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_k;

    /* Gain: '<S74>/from cm to m' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide2 =
      M43_Sim_Forcing_003h_Trajectory_P.fromcmtom_Gain_h *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c;

    /* DiscreteIntegrator: '<S98>/pi//(zeta*T_transfer)//s' */
    M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers =
      M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_DSTATE;

    /* Gain: '<S74>/Gain1' */
    M43_Sim_Forcing_003h_Trajectory_B.Switch_o =
      M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_c *
      M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers;

    /* Product: '<S74>/Product1' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1 =
      M43_Sim_Forcing_003h_Trajectory_B.Divide2 *
      M43_Sim_Forcing_003h_Trajectory_B.Switch_o;

    /* DiscreteTransferFcn: '<S3>/Butterworth Filter 10 Hz' */
    M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp_f =
      ((((M43_Sim_Forcing_003h_Trajectory_B.Product1 -
          M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denomin_p[1] *
          M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[0])
         - M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denomin_p[2] *
         M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[1])
        - M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denomin_p[3] *
        M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[2])
       - M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denomin_p[4] *
       M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[3]) /
      M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Denomin_p[0];
    M43_Sim_Forcing_003h_Trajectory_B.Switch_o =
      (((M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerat_a[0] *
         M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp_f +
         M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerat_a[1] *
         M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[0])
        + M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerat_a[2] *
        M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[1])
       + M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerat_a[3] *
       M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[2])
      + M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Numerat_a[4] *
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[3];

    /* DataTypeConversion: '<S72>/Data Type Conversion1' */
    M43_Sim_Forcing_003h_Trajectory_B.Alpha = (real32_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_p[6];

    /* DataTypeConversion: '<S72>/Data Type Conversion2' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_be = (real32_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_p[7];

    /* Sum: '<S72>/Sum' */
    M43_Sim_Forcing_003h_Trajectory_B.Alpha =
      M43_Sim_Forcing_003h_Trajectory_B.Alpha -
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_be;

    /* Logic: '<S72>/Logical Operator' */
    M43_Sim_Forcing_003h_Trajectory_B.LogicalOperator =
      ((M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_p[7] != 0) ||
       (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_p[6] != 0));

    /* DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
    if ((!M43_Sim_Forcing_003h_Trajectory_B.LogicalOperator) &&
        (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_f ==
         1)) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g =
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_h;
    }

    if (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g >=
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_UpperSa) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g =
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_UpperSa;
    } else {
      if (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g <=
          M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_LowerSa) {
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g =
          M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_LowerSa;
      }
    }

    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_be =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g;

    /* Product: '<S72>/Product' */
    M43_Sim_Forcing_003h_Trajectory_B.Alpha =
      M43_Sim_Forcing_003h_Trajectory_B.Alpha *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_be;

    /* Switch: '<S3>/Switch1' incorporates:
     *  Constant: '<S3>/Constant'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[3] >
        M43_Sim_Forcing_003h_Trajectory_P.Switch1_Threshold_a2) {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[0] = (real_T)
        M43_Sim_Forcing_003h_Trajectory_B.Gain1_o[0];
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[0] =
        M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_o[0];
    }

    if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[4] >
        M43_Sim_Forcing_003h_Trajectory_P.Switch1_Threshold_a2) {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[1] = (real_T)
        M43_Sim_Forcing_003h_Trajectory_B.Gain1_o[1];
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[1] =
        M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_o[1];
    }

    if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[5] >
        M43_Sim_Forcing_003h_Trajectory_P.Switch1_Threshold_a2) {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[2] = (real_T)
        M43_Sim_Forcing_003h_Trajectory_B.Alpha;
    } else {
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[2] =
        M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_o[2];
    }

    /* Product: '<S70>/Product4' */
    M43_Sim_Forcing_003h_Trajectory_B.Product4[0] = (real_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3[0] *
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[0];
    M43_Sim_Forcing_003h_Trajectory_B.Product4[1] = (real_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3[1] *
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[1];
    M43_Sim_Forcing_003h_Trajectory_B.Product4[2] = (real_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3[2] *
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[2];

    /* Product: '<S70>/Product2' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide2 = (real_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3[1] *
      M43_Sim_Forcing_003h_Trajectory_B.Switch_o;

    /* Product: '<S79>/Alpha' */
    M43_Sim_Forcing_003h_Trajectory_B.Alpha =
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3[0] /
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3[1];

    /* Product: '<S79>/Product' */
    M43_Sim_Forcing_003h_Trajectory_B.Product =
      M43_Sim_Forcing_003h_Trajectory_B.Divide2 * (real_T)
      M43_Sim_Forcing_003h_Trajectory_B.Alpha;

    /* Embedded MATLAB: '<S79>/Get R' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Cabin Motion/Stay within ellipse 20/07/15/Get R': '<S86>:1' */
    /* '<S86>:1:4' */
    M43_Sim_Forcing_003h_Trajectory_B.R =
      M43_Sim_Forcing_003h_Trajectory_B.Product4[0] *
      M43_Sim_Forcing_003h_Trajectory_B.Product4[0] +
      M43_Sim_Forcing_003h_Trajectory_B.Product *
      M43_Sim_Forcing_003h_Trajectory_B.Product;
    M43_Sim_Forcing_003h_Trajectory_B.R = sqrt
      (M43_Sim_Forcing_003h_Trajectory_B.R);

    /* Product: '<S79>/Divide' */
    M43_Sim_Forcing_003h_Trajectory_B.Switch_o =
      M43_Sim_Forcing_003h_Trajectory_B.R / (real_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3[0];

    /* Switch: '<S79>/Switch' incorporates:
     *  Constant: '<S79>/Constant'
     */
    if (!(M43_Sim_Forcing_003h_Trajectory_B.Switch_o >=
          M43_Sim_Forcing_003h_Trajectory_P.Switch_Threshold_g)) {
      M43_Sim_Forcing_003h_Trajectory_B.Switch_o =
        M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_kw;
    }

    /* Product: '<S79>/Divide1' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide1 =
      M43_Sim_Forcing_003h_Trajectory_B.Product4[0] /
      M43_Sim_Forcing_003h_Trajectory_B.Switch_o;

    /* Gain: '<S75>/Gain' */
    M43_Sim_Forcing_003h_Trajectory_B.Product_l =
      M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_c *
      M43_Sim_Forcing_003h_Trajectory_B.Divide1;

    /* DataTypeConversion: '<S70>/Data Type Conversion' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_b = (real_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2;

    /* Gain: '<S75>/Gain3' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_j =
      M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_i *
      M43_Sim_Forcing_003h_Trajectory_B.Product1_b;

    /* Product: '<S75>/Product' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_n =
      M43_Sim_Forcing_003h_Trajectory_B.Product1_b *
      M43_Sim_Forcing_003h_Trajectory_B.Product1_b;

    /* DiscreteIntegrator: '<S80>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide1_l =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTA_ds;

    /* Product: '<S80>/Product' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide_o =
      M43_Sim_Forcing_003h_Trajectory_B.Product1_n *
      M43_Sim_Forcing_003h_Trajectory_B.Product_l;

    /* Product: '<S80>/Product1' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_p =
      M43_Sim_Forcing_003h_Trajectory_B.Product1_n *
      M43_Sim_Forcing_003h_Trajectory_B.Product1_p;

    /* Product: '<S80>/Product3' */
    M43_Sim_Forcing_003h_Trajectory_B.Product_l =
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_j *
      M43_Sim_Forcing_003h_Trajectory_B.Product_l;

    /* Sum: '<S80>/Sum5' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum5_c =
      M43_Sim_Forcing_003h_Trajectory_B.Product_l +
      M43_Sim_Forcing_003h_Trajectory_B.Divide1_l;

    /* Product: '<S80>/Product2' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide1_l =
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_j *
      M43_Sim_Forcing_003h_Trajectory_B.Sum5_c;

    /* Sum: '<S80>/Sum4' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum4_k =
      (M43_Sim_Forcing_003h_Trajectory_B.Divide_o -
       M43_Sim_Forcing_003h_Trajectory_B.Product1_p) -
      M43_Sim_Forcing_003h_Trajectory_B.Divide1_l;

    /* DiscreteIntegrator: '<S81>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_l =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_n;

    /* Product: '<S81>/Product1' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_n =
      M43_Sim_Forcing_003h_Trajectory_B.Product1_n *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_l;

    /* Product: '<S81>/Product2' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_j =
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_j *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_l;

    /* Sum: '<S81>/Sum4' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum4_g =
      (M43_Sim_Forcing_003h_Trajectory_B.Divide1 -
       M43_Sim_Forcing_003h_Trajectory_B.Product1_n) -
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_j;

    /* Product: '<S79>/Divide2' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide2 =
      M43_Sim_Forcing_003h_Trajectory_B.Divide2 /
      M43_Sim_Forcing_003h_Trajectory_B.Switch_o;

    /* Gain: '<S76>/Gain' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide_o =
      M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_a *
      M43_Sim_Forcing_003h_Trajectory_B.Divide2;

    /* Gain: '<S76>/Gain3' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide1_l =
      M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_g *
      M43_Sim_Forcing_003h_Trajectory_B.Product1_b;

    /* Product: '<S76>/Product' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_n =
      M43_Sim_Forcing_003h_Trajectory_B.Product1_b *
      M43_Sim_Forcing_003h_Trajectory_B.Product1_b;

    /* DiscreteIntegrator: '<S82>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_j =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_b;

    /* Product: '<S82>/Product' */
    M43_Sim_Forcing_003h_Trajectory_B.Product_l =
      M43_Sim_Forcing_003h_Trajectory_B.Product1_n *
      M43_Sim_Forcing_003h_Trajectory_B.Divide_o;

    /* Product: '<S82>/Product1' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_h =
      M43_Sim_Forcing_003h_Trajectory_B.Product1_n *
      M43_Sim_Forcing_003h_Trajectory_B.Product1_h;

    /* Product: '<S82>/Product3' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide_o =
      M43_Sim_Forcing_003h_Trajectory_B.Divide1_l *
      M43_Sim_Forcing_003h_Trajectory_B.Divide_o;

    /* Sum: '<S82>/Sum5' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum5_d =
      M43_Sim_Forcing_003h_Trajectory_B.Divide_o +
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_j;

    /* Product: '<S82>/Product2' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide_o =
      M43_Sim_Forcing_003h_Trajectory_B.Divide1_l *
      M43_Sim_Forcing_003h_Trajectory_B.Sum5_d;

    /* Sum: '<S82>/Sum4' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum4_k2 =
      (M43_Sim_Forcing_003h_Trajectory_B.Product_l -
       M43_Sim_Forcing_003h_Trajectory_B.Product1_h) -
      M43_Sim_Forcing_003h_Trajectory_B.Divide_o;

    /* DiscreteIntegrator: '<S83>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_i =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_o;

    /* Product: '<S83>/Product1' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_n =
      M43_Sim_Forcing_003h_Trajectory_B.Product1_n *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_e;

    /* Product: '<S83>/Product2' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide1_l =
      M43_Sim_Forcing_003h_Trajectory_B.Divide1_l *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_i;

    /* Sum: '<S83>/Sum4' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum4_b =
      (M43_Sim_Forcing_003h_Trajectory_B.Divide2 -
       M43_Sim_Forcing_003h_Trajectory_B.Product1_n) -
      M43_Sim_Forcing_003h_Trajectory_B.Divide1_l;

    /* Gain: '<S77>/Gain3' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide_o =
      M43_Sim_Forcing_003h_Trajectory_P.Gain3_Gain_m *
      M43_Sim_Forcing_003h_Trajectory_B.Product1_b;

    /* Product: '<S77>/Product' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_b =
      M43_Sim_Forcing_003h_Trajectory_B.Product1_b *
      M43_Sim_Forcing_003h_Trajectory_B.Product1_b;

    /* DiscreteIntegrator: '<S84>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_b =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTA_ko;

    /* Product: '<S84>/Product1' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_b =
      M43_Sim_Forcing_003h_Trajectory_B.Product1_b *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_h;

    /* Product: '<S84>/Product2' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide_o =
      M43_Sim_Forcing_003h_Trajectory_B.Divide_o *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_b;

    /* Sum: '<S84>/Sum4' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum4_o =
      (M43_Sim_Forcing_003h_Trajectory_B.Product4[2] -
       M43_Sim_Forcing_003h_Trajectory_B.Product1_b) -
      M43_Sim_Forcing_003h_Trajectory_B.Divide_o;

    /* DataTypeConversion: '<S72>/Data Type Conversion3' */
    M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3 = (real32_T)
      M43_Sim_Forcing_003h_Trajectory_B.LogicalOperator;

    /* Gain: '<S92>/Gain1' */
    M43_Sim_Forcing_003h_Trajectory_B.Gain1_k =
      M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_p *
      M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers;

    /* Constant: '<S92>/x_max' */
    M43_Sim_Forcing_003h_Trajectory_B.x_max =
      M43_Sim_Forcing_003h_Trajectory_P.x_max_Value;

    /* Embedded MATLAB: '<S92>/Exp_saturation' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Newtonian Dynamics 31/07/15/Adaptive Psi computation/Exp_saturation': '<S96>:1' */
    /* '<S96>:1:4' */
    if (rtIsNaN(M43_Sim_Forcing_003h_Trajectory_B.Gain1_k)) {
      eml_maxval = (rtNaN);
    } else if (M43_Sim_Forcing_003h_Trajectory_B.Gain1_k > 0.0) {
      eml_maxval = 1.0;
    } else if (M43_Sim_Forcing_003h_Trajectory_B.Gain1_k < 0.0) {
      eml_maxval = -1.0;
    } else {
      eml_maxval = 0.0;
    }

    M43_Sim_Forcing_003h_Trajectory_B.x_out = (1.0 - exp(-fabs
      (M43_Sim_Forcing_003h_Trajectory_B.Gain1_k /
       M43_Sim_Forcing_003h_Trajectory_B.x_max))) * (eml_maxval *
      M43_Sim_Forcing_003h_Trajectory_B.x_max);

    /* Gain: '<S92>/Gain' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide_o =
      M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_l *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator;

    /* Sum: '<S92>/Sum' */
    M43_Sim_Forcing_003h_Trajectory_B.Sum_nx =
      M43_Sim_Forcing_003h_Trajectory_B.x_out -
      M43_Sim_Forcing_003h_Trajectory_B.Divide_o;

    /* Gain: '<S74>/Gain' */
    M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1 =
      M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_j *
      M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1;

    /* Product: '<S74>/Product' */
    M43_Sim_Forcing_003h_Trajectory_B.Product_k[0] = (real_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o4[0] *
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[0];
    M43_Sim_Forcing_003h_Trajectory_B.Product_k[1] = (real_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o4[1] *
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[1];
    M43_Sim_Forcing_003h_Trajectory_B.Product_k[2] = (real_T)
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o4[2] *
      M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[2];

    /* Abs: '<S93>/Abs' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide_o = fabs
      (M43_Sim_Forcing_003h_Trajectory_B.Product_k[0]);

    /* Constant: '<S93>/Constant1' */
    M43_Sim_Forcing_003h_Trajectory_B.Constant1 =
      M43_Sim_Forcing_003h_Trajectory_P.Constant1_Value_g;

    /* Product: '<S93>/Product' */
    M43_Sim_Forcing_003h_Trajectory_B.Product_g =
      M43_Sim_Forcing_003h_Trajectory_B.Product_k[0] *
      M43_Sim_Forcing_003h_Trajectory_B.Divide_o;

    /* DiscreteIntegrator: '<S93>/Discrete-Time Integrator3' */
    if (((M43_Sim_Forcing_003h_Trajectory_B.Product_g > 0.0) &&
         (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_PrevRes <=
          0)) || ((M43_Sim_Forcing_003h_Trajectory_B.Product_g <= 0.0) &&
                  (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_PrevRes
                   == 1))) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_DSTATE =
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator3_IC;
    }

    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator3 =
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_DSTATE;

    /* Embedded MATLAB: '<S93>/Natural Speed Down' */
    /* Embedded MATLAB Function 'Breaking_Control 20/07/15/Newtonian Dynamics 31/07/15/Newtonian Dynamics x/Natural Speed Down': '<S97>:1' */
    if (M43_Sim_Forcing_003h_Trajectory_B.Product_g < 0.1) {
      /* '<S97>:1:3' */
      /* '<S97>:1:4' */
      M43_Sim_Forcing_003h_Trajectory_B.v_body = exp
        ((-M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator3) *
         M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator3 /
         M43_Sim_Forcing_003h_Trajectory_B.Constant1) * 0.0;
    } else {
      /* '<S97>:1:6' */
      M43_Sim_Forcing_003h_Trajectory_B.v_body = 0.0;
    }

    /* Trigonometry: '<S93>/Trigonometric Function' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide_o = cos
      (M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1);

    /* Product: '<S93>/Product1' */
    M43_Sim_Forcing_003h_Trajectory_B.Product1_j =
      M43_Sim_Forcing_003h_Trajectory_B.Divide_o *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c;

    /* Trigonometry: '<S93>/Trigonometric Function1' */
    M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1 = sin
      (M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1);

    /* Product: '<S93>/Product2' */
    M43_Sim_Forcing_003h_Trajectory_B.Product2 =
      M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1 *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c;

    /* Gain: '<S93>/from m to cm' */
    M43_Sim_Forcing_003h_Trajectory_B.frommtocm =
      M43_Sim_Forcing_003h_Trajectory_P.frommtocm_Gain *
      M43_Sim_Forcing_003h_Trajectory_B.Product_g;

    /* Gain: '<S94>/from m to cm' */
    M43_Sim_Forcing_003h_Trajectory_B.frommtocm_a =
      M43_Sim_Forcing_003h_Trajectory_P.frommtocm_Gain_i *
      M43_Sim_Forcing_003h_Trajectory_B.Product_k[2];

    /* Sum: '<S98>/Sum2' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide_o =
      M43_Sim_Forcing_003h_Trajectory_B.Product_k[1] -
      M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers;

    /* DiscreteIntegrator: '<S98>/4*zeta*pi//T_transfer //s' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide1_l =
      M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_DSTATE;

    /* Sum: '<S98>/Sum1' */
    M43_Sim_Forcing_003h_Trajectory_B.Divide_o =
      M43_Sim_Forcing_003h_Trajectory_B.Divide_o -
      M43_Sim_Forcing_003h_Trajectory_B.Divide1_l;

    /* Product: '<S98>/Divide' incorporates:
     *  Constant: '<S95>/Constant'
     */
    M43_Sim_Forcing_003h_Trajectory_B.Divide_o =
      M43_Sim_Forcing_003h_Trajectory_B.Divide_o /
      M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_n;

    /* Gain: '<S98>/4*zeta*pi' */
    M43_Sim_Forcing_003h_Trajectory_B.zetapi =
      M43_Sim_Forcing_003h_Trajectory_P.zetapi_Gain *
      M43_Sim_Forcing_003h_Trajectory_B.Divide_o;

    /* Product: '<S98>/Divide1' incorporates:
     *  Constant: '<S95>/Constant'
     */
    M43_Sim_Forcing_003h_Trajectory_B.Divide1_l =
      M43_Sim_Forcing_003h_Trajectory_B.Divide1_l /
      M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_n;

    /* Gain: '<S98>/pi//zeta' */
    M43_Sim_Forcing_003h_Trajectory_B.pizeta =
      M43_Sim_Forcing_003h_Trajectory_P.pizeta_Gain *
      M43_Sim_Forcing_003h_Trajectory_B.Divide1_l;
    for (i = 0; i < 6; i++) {
      /* Gain: '<S110>/Gain' */
      M43_Sim_Forcing_003h_Trajectory_B.Gain_f[i] =
        M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_i *
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[i];

      /* Gain: '<S112>/Gain1' */
      M43_Sim_Forcing_003h_Trajectory_B.Gain1_j[i] =
        M43_Sim_Forcing_003h_Trajectory_P.Gain1_Gain_o *
        M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1[i];
    }

    /* Level2 S-Function Block: '<S9>/GT-RT CAN RX2' (gt_rt_can_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[26];
      sfcnOutputs(rts, 0);
    }

    /* If: '<S9>/If' incorporates:
     *  ActionPort: '<S103>/Action Port'
     *  SubSystem: '<S9>/If Action Subsystem1'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o5_i) {
      /* Level2 S-Function Block: '<S103>/GT-RT CAN TX' (gt_rt_can_send) */
      {
        SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[14];
        sfcnOutputs(rts, 0);
      }

      srUpdateBC
        (M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_SubsysRanB_l);
    }

    /* Level2 S-Function Block: '<Root>/GT-RT CAN Controller' (gt_rt_can_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[27];
      sfcnOutputs(rts, 0);
    }
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void M43_Sim_Forcing_003h_Trajectory_update(int_T tid)
{
  {
    int32_T k;
    int32_T memOffset;

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainval *
      M43_Sim_Forcing_003h_Trajectory_B.Product1_j +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE;
    if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[3] > 0) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_PrevRese = 1;
    } else {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_PrevRese = 0;
    }

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator2' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator2_DSTATE =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator2_gainval *
      M43_Sim_Forcing_003h_Trajectory_B.Product2 +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator2_DSTATE;
    if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[3] > 0) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator2_PrevRes = 1;
    } else {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator2_PrevRes = 0;
    }

    /* Update for enable SubSystem: '<S3>/Move UP1' incorporates:
     *  Update for EnablePort: '<S73>/Enable'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.Compare > 0) {
      /* Update for UnitDelay: '<S87>/For saving position  and velocity until after switchover' */
      M43_Sim_Forcing_003h_Trajectory_DWork.Forsavingpositionandvelocityunt =
        M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers_d;

      /* Update for UnitDelay: '<S90>/UD' */
      M43_Sim_Forcing_003h_Trajectory_DWork.UD_DSTATE =
        M43_Sim_Forcing_003h_Trajectory_B.TSamp;

      /* Update for DiscreteIntegrator: '<S87>/pi//(zeta*T_transfer)//s' */
      M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_IC_LOADING = 0U;
      M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_DSTATE_i =
        M43_Sim_Forcing_003h_Trajectory_P.pizetaT_transfers_gainval_c *
        M43_Sim_Forcing_003h_Trajectory_B.pizeta_i +
        M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_DSTATE_i;
      if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[1] > 0) {
        M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_PrevResetStat =
          1;
      } else {
        M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_PrevResetStat =
          0;
      }

      /* Update for DiscreteIntegrator: '<S87>/4*zeta*pi//T_transfer //s' */
      M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_IC_LOADING = 0U;
      M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_DSTATE_p =
        M43_Sim_Forcing_003h_Trajectory_P.zetapiT_transfers_gainval_j *
        M43_Sim_Forcing_003h_Trajectory_B.zetapi_b +
        M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_DSTATE_p;
      if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[1] > 0) {
        M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_PrevResetStat =
          1;
      } else {
        M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_PrevResetStat =
          0;
      }
    }

    /* end of Update for SubSystem: '<S3>/Move UP1' */

    /* Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTATE =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainval *
      M43_Sim_Forcing_003h_Trajectory_B.frommtocm_a +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTATE;
    if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[5] > 0) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevRes = 1;
    } else {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevRes = 0;
    }

    /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_d =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_i *
      M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_d;
    if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[4] > 0) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_p = 1;
    } else {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_p = 0;
    }

    /* Update for DiscreteTransferFcn: '<S13>/Butterworth Filter 10 Hz' */
    for (k = 0; k < 3; k++) {
      memOffset = k << 2;
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a[memOffset
        + 3] =
        M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a[memOffset
        + 2];
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a[memOffset
        + 2] =
        M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a[memOffset
        + 1];
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a[memOffset
        + 1] =
        M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a[memOffset];
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a[memOffset]
        = M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp_p[k];
    }

    /* Update for DiscreteIntegrator: '<S81>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_c =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainva_e *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_l +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_c;

    /* Update for DiscreteIntegrator: '<S83>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_e =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainva_j *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_i +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_e;

    /* Update for DiscreteIntegrator: '<S84>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_d =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainva_f *
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_b +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_d;

    /* Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_i =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainv_ex *
      M43_Sim_Forcing_003h_Trajectory_B.Sum5_d +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_i;

    /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_g =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainv_jz *
      M43_Sim_Forcing_003h_Trajectory_B.Sum5_c +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_g;

    /* Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_f =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainva_l *
      M43_Sim_Forcing_003h_Trajectory_B.Sum_nx +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_f;

    /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_IC_LOAD = 0U;
    for (k = 0; k < 6; k++) {
      /* Update for UnitDelay: '<S106>/Unit Delay' */
      M43_Sim_Forcing_003h_Trajectory_DWork.UnitDelay_DSTATE[k] =
        M43_Sim_Forcing_003h_Trajectory_B.Switch[k];
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_l[k] =
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_a *
        M43_Sim_Forcing_003h_Trajectory_B.Gain1_j[k] +
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_l[k];
    }

    if (M43_Sim_Forcing_003h_Trajectory_B.Switch1 > 0.0) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_k = 1;
    } else if (M43_Sim_Forcing_003h_Trajectory_B.Switch1 < 0.0) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_k = -1;
    } else {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_k = 0;
    }

    /* Update for DiscreteIntegrator: '<S110>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_IC_LOADI = 0U;
    for (k = 0; k < 6; k++) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_b[k] =
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainva_k *
        M43_Sim_Forcing_003h_Trajectory_B.Gain_f[k] +
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_b[k];
    }

    if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[2] > 0) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_PrevRe_d = 1;
    } else {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_PrevRe_d = 0;
    }

    /* Update for enable SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' incorporates:
     *  Update for EnablePort: '<S1>/Enable'
     */
    if (M43_Sim_Forcing_003h_Trajectory_B.SwitchControl > 0.0) {
      /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_n =
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_gainva_o *
        M43_Sim_Forcing_003h_Trajectory_B.Product_m +
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_n;

      /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f =
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gain_p4 *
        M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_pr +
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f;
      if (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f >=
          M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_Upper_a) {
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f =
          M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_Upper_a;
      } else {
        if (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f
            <= M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_Lower_p)
        {
          M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f =
            M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_Lower_p;
        }
      }

      if (M43_Sim_Forcing_003h_Trajectory_B.LogicalOperator_a) {
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_c =
          1;
      } else {
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_c =
          0;
      }
    }

    /* end of Update for SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' */

    /* Update for UnitDelay: '<S105>/Unit Delay6' */
    M43_Sim_Forcing_003h_Trajectory_DWork.UnitDelay6_DSTATE[0] =
      M43_Sim_Forcing_003h_Trajectory_B.Sum2_b;
    for (k = 0; k < 5; k++) {
      M43_Sim_Forcing_003h_Trajectory_DWork.UnitDelay6_DSTATE[k + 1] =
        M43_Sim_Forcing_003h_Trajectory_B.Sum_b[k + 1];
    }

    /* Update for DiscreteTransferFcn: '<S10>/Butterworth Filter 10 Hz' */
    for (k = 0; k < 6; k++) {
      memOffset = k << 2;
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[memOffset
        + 3] =
        M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[memOffset
        + 2];
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[memOffset
        + 2] =
        M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[memOffset
        + 1];
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[memOffset
        + 1] =
        M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[memOffset];
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[memOffset]
        = M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp[k];
    }

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_k =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_j *
      M43_Sim_Forcing_003h_Trajectory_B.frommtocm +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_k;
    if (M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_c[3] > 0) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_b = 1;
    } else {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_b = 0;
    }

    /* Update for DiscreteIntegrator: '<S98>/pi//(zeta*T_transfer)//s' */
    M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_DSTATE =
      M43_Sim_Forcing_003h_Trajectory_P.pizetaT_transfers_gainval *
      M43_Sim_Forcing_003h_Trajectory_B.pizeta +
      M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_DSTATE;

    /* Update for DiscreteTransferFcn: '<S3>/Butterworth Filter 10 Hz' */
    M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[3] =
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[2];
    M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[2] =
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[1];
    M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[1] =
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[0];
    M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[0] =
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp_f;

    /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_k *
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3 +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g;
    if (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g >=
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_UpperSa) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g =
        M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_UpperSa;
    } else {
      if (M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g <=
          M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_LowerSa) {
        M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g =
          M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_LowerSa;
      }
    }

    if (M43_Sim_Forcing_003h_Trajectory_B.LogicalOperator) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_f = 1;
    } else {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_f = 0;
    }

    /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTA_ds =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gain_a4 *
      M43_Sim_Forcing_003h_Trajectory_B.Sum4_k +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTA_ds;

    /* Update for DiscreteIntegrator: '<S81>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_n =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_p *
      M43_Sim_Forcing_003h_Trajectory_B.Sum4_g +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_n;

    /* Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_b =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_f *
      M43_Sim_Forcing_003h_Trajectory_B.Sum4_k2 +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_b;

    /* Update for DiscreteIntegrator: '<S83>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_o =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_g *
      M43_Sim_Forcing_003h_Trajectory_B.Sum4_b +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_o;

    /* Update for DiscreteIntegrator: '<S84>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTA_ko =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_gainv_h *
      M43_Sim_Forcing_003h_Trajectory_B.Sum4_o +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTA_ko;

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator3' incorporates:
     *  Constant: '<S93>/Constant'
     */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_DSTATE =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator3_gainval *
      M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_hu +
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_DSTATE;
    if (M43_Sim_Forcing_003h_Trajectory_B.Product_g > 0.0) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_PrevRes = 1;
    } else if (M43_Sim_Forcing_003h_Trajectory_B.Product_g < 0.0) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_PrevRes = -1;
    } else {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_PrevRes = 0;
    }

    /* Update for DiscreteIntegrator: '<S98>/4*zeta*pi//T_transfer //s' */
    M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_DSTATE =
      M43_Sim_Forcing_003h_Trajectory_P.zetapiT_transfers_gainval *
      M43_Sim_Forcing_003h_Trajectory_B.zetapi +
      M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_DSTATE;
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
  if (!(++M43_Sim_Forcing_003h_Trajectory_M->Timing.clockTick0))
    ++M43_Sim_Forcing_003h_Trajectory_M->Timing.clockTickH0;
  M43_Sim_Forcing_003h_Trajectory_M->Timing.t[0] =
    M43_Sim_Forcing_003h_Trajectory_M->Timing.clockTick0 *
    M43_Sim_Forcing_003h_Trajectory_M->Timing.stepSize0 +
    M43_Sim_Forcing_003h_Trajectory_M->Timing.clockTickH0 *
    M43_Sim_Forcing_003h_Trajectory_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void M43_Sim_Forcing_003h_Trajectory_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_LowerSa =
    rtMinusInfF;
  M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_Lower_p =
    rtMinusInfF;

  /* initialize real-time model */
  (void) memset((void *)M43_Sim_Forcing_003h_Trajectory_M,0,
                sizeof(RT_MODEL_M43_Sim_Forcing_003h_Trajectory));
  rtsiSetSolverName(&M43_Sim_Forcing_003h_Trajectory_M->solverInfo,
                    "FixedStepDiscrete");
  M43_Sim_Forcing_003h_Trajectory_M->solverInfoPtr =
    (&M43_Sim_Forcing_003h_Trajectory_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      M43_Sim_Forcing_003h_Trajectory_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    M43_Sim_Forcing_003h_Trajectory_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    M43_Sim_Forcing_003h_Trajectory_M->Timing.sampleTimes =
      (&M43_Sim_Forcing_003h_Trajectory_M->Timing.sampleTimesArray[0]);
    M43_Sim_Forcing_003h_Trajectory_M->Timing.offsetTimes =
      (&M43_Sim_Forcing_003h_Trajectory_M->Timing.offsetTimesArray[0]);

    /* task periods */
    M43_Sim_Forcing_003h_Trajectory_M->Timing.sampleTimes[0] = (0.004);

    /* task offsets */
    M43_Sim_Forcing_003h_Trajectory_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(M43_Sim_Forcing_003h_Trajectory_M,
             &M43_Sim_Forcing_003h_Trajectory_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      M43_Sim_Forcing_003h_Trajectory_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    M43_Sim_Forcing_003h_Trajectory_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(M43_Sim_Forcing_003h_Trajectory_M, -1);
  M43_Sim_Forcing_003h_Trajectory_M->Timing.stepSize0 = 0.004;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo, (NULL));
    rtliSetLogT(M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo, "tout");
    rtliSetLogX(M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo, "");
    rtliSetLogXFinal(M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo, "");
    rtliSetSigLog(M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo,
      "rt_");
    rtliSetLogFormat(M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo, 1);
    rtliSetLogY(M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(M43_Sim_Forcing_003h_Trajectory_M->rtwLogInfo, (NULL));
  }

  /* external mode info */
  M43_Sim_Forcing_003h_Trajectory_M->Sizes.checksums[0] = (2587801539U);
  M43_Sim_Forcing_003h_Trajectory_M->Sizes.checksums[1] = (3199151868U);
  M43_Sim_Forcing_003h_Trajectory_M->Sizes.checksums[2] = (3146686446U);
  M43_Sim_Forcing_003h_Trajectory_M->Sizes.checksums[3] = (2988718197U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[58];
    M43_Sim_Forcing_003h_Trajectory_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork._DOFVisualCab120615_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork._DOFVisualCab120615_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_SubsysRanBC;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_h.IfActionSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_h.IfActionSubsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_f.IfActionSubsystem1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_f.IfActionSubsystem1_SubsysRanBC;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_i.IfActionSubsystem_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_i.IfActionSubsystem_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_k.IfActionSubsystem1_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_k.IfActionSubsystem1_SubsysRanBC;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_d.IfActionSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_d.IfActionSubsystem_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_p.IfActionSubsystem1_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_p.IfActionSubsystem1_SubsysRanBC;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_e.IfActionSubsystem_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_e.IfActionSubsystem_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_d.IfActionSubsystem1_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_d.IfActionSubsystem1_SubsysRanBC;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_d0.IfActionSubsystem_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_d0.IfActionSubsystem_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.MoveUP1_SubsysRanBC;
    systemRan[39] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.MoveUP1_SubsysRanBC;
    systemRan[40] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.MoveUP1_SubsysRanBC;
    systemRan[41] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.MoveUP1_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.MoveUP1_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.MoveUP1_SubsysRanBC;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = &rtAlwaysEnabled;
    systemRan[46] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork._DOFControl_SubsysRanBC;
    systemRan[47] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork._DOFControl_SubsysRanBC;
    systemRan[48] = &rtAlwaysEnabled;
    systemRan[49] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_SubsysRanBC_p;
    systemRan[50] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_SubsysRanB_l;
    systemRan[51] = &rtAlwaysEnabled;
    systemRan[52] = &rtAlwaysEnabled;
    systemRan[53] = &rtAlwaysEnabled;
    systemRan[54] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.fullinversekin_SubsysRanBC;
    systemRan[55] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.fullinversekin_SubsysRanBC;
    systemRan[56] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.SimplifiedInverseKin_SubsysRanB;
    systemRan[57] = (sysRanDType *)
      &M43_Sim_Forcing_003h_Trajectory_DWork.SimplifiedInverseKin_SubsysRanB;
    rteiSetModelMappingInfoPtr(M43_Sim_Forcing_003h_Trajectory_M->extModeInfo,
      &M43_Sim_Forcing_003h_Trajectory_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(M43_Sim_Forcing_003h_Trajectory_M->extModeInfo,
                        M43_Sim_Forcing_003h_Trajectory_M->Sizes.checksums);
    rteiSetTPtr(M43_Sim_Forcing_003h_Trajectory_M->extModeInfo, rtmGetTPtr
                (M43_Sim_Forcing_003h_Trajectory_M));
  }

  M43_Sim_Forcing_003h_Trajectory_M->solverInfoPtr =
    (&M43_Sim_Forcing_003h_Trajectory_M->solverInfo);
  M43_Sim_Forcing_003h_Trajectory_M->Timing.stepSize = (0.004);
  rtsiSetFixedStepSize(&M43_Sim_Forcing_003h_Trajectory_M->solverInfo, 0.004);
  rtsiSetSolverMode(&M43_Sim_Forcing_003h_Trajectory_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  M43_Sim_Forcing_003h_Trajectory_M->ModelData.blockIO = ((void *)
    &M43_Sim_Forcing_003h_Trajectory_B);
  (void) memset(((void *) &M43_Sim_Forcing_003h_Trajectory_B),0,
                sizeof(BlockIO_M43_Sim_Forcing_003h_Trajectory));

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Sum_j[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.UnitDelay[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Sum_d[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Sum_n[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_k[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Sum_b[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_o[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Sum_k[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.ButterworthFilter10Hz[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Switch_m[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_ks[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Gain_f[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Gain1_j[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.out[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.out_g[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Sum1_j[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.out_m[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.MultiportSwitch[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.set_out[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_a[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.ControlLoopGain[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctionI[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.TmpSignalConversionAtSFunctio_i[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_a[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Sum6[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.Unpack_o4[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_m[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_p[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion_b[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion4[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.SwitchControl_d[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion2[i] = 0.0F;
    }

    M43_Sim_Forcing_003h_Trajectory_B.Sum9 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum15 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.TargetPSI = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum11 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Phi1 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Theta1 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum3 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.SwitchControl = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum2 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum3_d = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.fromcmtom = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_n = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.fromcmtom_f = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum8 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum4 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum7 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum5 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.AllowedPsi = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum12 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch1 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum2_b = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Abs2 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Abs1 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch1_d = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA1 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Abs2_m = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Abs1_h = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch1_a = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA2 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Abs2_g = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Abs1_i = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch1_b = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA3 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Abs2_c = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Abs1_ha = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch1_n = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA4 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Abs2_b = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Abs1_f = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch1_c = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA5 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Abs2_f = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Abs1_f5 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch1_f = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.AccLimiterA6 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Gain = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Gain1 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Gain2 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Gain3 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Gain4 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Gain5 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product1 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product4[0] = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product4[1] = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product4[2] = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum5_c = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum4_k = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_l = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum4_g = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum5_d = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum4_k2 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_i = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum4_b = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_b = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum4_o = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Gain1_k = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.x_max = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum_nx = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Constant1 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product_g = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator3 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product1_j = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product2 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.frommtocm = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.frommtocm_a = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.zetapi = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.pizeta = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Sum_c = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.v_body = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.x_out = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Forsavingpositionandvelocityunt = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.TSamp = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.zetaT_transferpi = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.pizetaT_transfers_d = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.zetapi_b = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.pizeta_i = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.x = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.z = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.psi = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.R = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.d_psi = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch_mx = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch_p = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch_d = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch_n = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch_dh = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch_dx = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch_po = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_l = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_h = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[0] = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[1] = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch1_nd[2] = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Divide1 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product_k[0] = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product_k[1] = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product_k[2] = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch2 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Divide1_m = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product1_h = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product_l = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product1_b = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_j = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product1_p = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Switch_o = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Product1_n = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_e = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Divide2 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.TrigonometricFunction1 = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Divide1_l = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Divide = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Divide_o = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.shift = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_c = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.Gain_m =
      M43_Sim_Forcing_003h_Trajectory_sfix64_En41_GND;
    M43_Sim_Forcing_003h_Trajectory_B.Gain2_e =
      M43_Sim_Forcing_003h_Trajectory_sfix64_En41_GND;
    M43_Sim_Forcing_003h_Trajectory_B.Gain6 =
      M43_Sim_Forcing_003h_Trajectory_sfix64_En41_GND;
    M43_Sim_Forcing_003h_Trajectory_B.Gain1_e =
      M43_Sim_Forcing_003h_Trajectory_sfix64_En41_GND;
    M43_Sim_Forcing_003h_Trajectory_B.Gain3_b =
      M43_Sim_Forcing_003h_Trajectory_sfix64_En41_GND;
    M43_Sim_Forcing_003h_Trajectory_B.Gain4_m =
      M43_Sim_Forcing_003h_Trajectory_sfix64_En41_GND;
    M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2 = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Unpack_o5 = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1[0] = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1[1] = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1[2] = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3_p = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Gain1_o[0] = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Gain1_o[1] = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Gain1_o[2] = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Unpack_o1_a = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2_a = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Unpack_o3_k = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Unpack_o4_n = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Unpack_o5_o = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Unpack_o6 = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Unpack = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3 = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Gain1_g = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Gain_j = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Sum_l = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_c = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator_ae = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_a = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion3_pr = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Product_m = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.ButterworthFilter10Hz_i[0] = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.ButterworthFilter10Hz_i[1] = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.ButterworthFilter10Hz_i[2] = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.DataTypeConversion2_o = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Sum2_n = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Sum_m = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Sum1_b = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.DiscreteTimeIntegrator1_be = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Sum_b4 = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.Alpha = 0.0F;
    M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_e.Switch = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_d0.Switch = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_d.Switch = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_e.Switch = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_p.Switch = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_d.Switch = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_k.Switch = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_i.Switch = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_f.Switch = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_h.Switch = 0.0;
    M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1.Switch = 0.0;
  }

  /* parameters */
  M43_Sim_Forcing_003h_Trajectory_M->ModelData.defaultParam = ((real_T *)
    &M43_Sim_Forcing_003h_Trajectory_P);

  /* states (dwork) */
  M43_Sim_Forcing_003h_Trajectory_M->Work.dwork = ((void *)
    &M43_Sim_Forcing_003h_Trajectory_DWork);
  (void) memset((void *)&M43_Sim_Forcing_003h_Trajectory_DWork, 0,
                sizeof(D_Work_M43_Sim_Forcing_003h_Trajectory));
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator2_DSTATE = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTATE = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_d = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_c = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_e = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_d = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_i = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_g = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_f = 0.0;

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_DWork.UnitDelay_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_l[i] =
        0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_b[i] =
        0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_DWork.UnitDelay6_DSTATE[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 24; i++) {
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[i] =
        0.0;
    }
  }

  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_k = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_DSTATE = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[0] = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[1] = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[2] = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[3] = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTA_ds = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_n = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_b = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_o = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTA_ko = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_DSTATE = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_DSTATE = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.Forsavingpositionandvelocityunt = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.UD_DSTATE = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_DSTATE_i = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_DSTATE_p = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.Sum2_DWORK1 = 0.0;

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_DWork.Sum1_DWORK1[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp[i] = 0.0;
    }
  }

  M43_Sim_Forcing_003h_Trajectory_DWork.PrevY = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_n = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_i = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_b = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_bp = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_p = 0.0;
  M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp_f = 0.0;

  {
    int_T i;
    for (i = 0; i < 12; i++) {
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a[i] =
        0.0F;
    }
  }

  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g = 0.0F;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_n = 0.0F;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f = 0.0F;
  M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp_p[0] = 0.0F;
  M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp_p[1] = 0.0F;
  M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_tmp_p[2] = 0.0F;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    M43_Sim_Forcing_003h_Trajectory_M->SpecialInfo.mappingInfo = (&dtInfo);
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
      &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.sfcnInfo;
    M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (M43_Sim_Forcing_003h_Trajectory_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &M43_Sim_Forcing_003h_Trajectory_M->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(M43_Sim_Forcing_003h_Trajectory_M));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(M43_Sim_Forcing_003h_Trajectory_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(M43_Sim_Forcing_003h_Trajectory_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (M43_Sim_Forcing_003h_Trajectory_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &M43_Sim_Forcing_003h_Trajectory_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (M43_Sim_Forcing_003h_Trajectory_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &M43_Sim_Forcing_003h_Trajectory_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &M43_Sim_Forcing_003h_Trajectory_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &M43_Sim_Forcing_003h_Trajectory_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &M43_Sim_Forcing_003h_Trajectory_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &M43_Sim_Forcing_003h_Trajectory_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &M43_Sim_Forcing_003h_Trajectory_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &M43_Sim_Forcing_003h_Trajectory_M->solverInfoPtr);
  }

  M43_Sim_Forcing_003h_Trajectory_M->Sizes.numSFcns = (28);

  /* register each child */
  {
    (void) memset((void *)
                  &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.childSFunctions
                  [0],0,
                  28*sizeof(SimStruct));
    M43_Sim_Forcing_003h_Trajectory_M->childSfunctions =
      (&M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 28; i++) {
        M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[i] =
          (&M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S1>/GT-RT UDP TX (gt_rt_udp_send) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn0.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[1] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[2] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[3] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 4);
        }

        /* port 1 */
        {
          uint16_T const **sfcnUPtrs = (uint16_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.Constant2_Value_l;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn0.UPtrs2;

          {
            int_T i1;
            const uint8_T *u2 = M43_Sim_Forcing_003h_Trajectory_B.BytePacking_g;
            for (i1=0; i1 < 28; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 28);
        }

        /* port 3 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn0.UPtrs3;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.Constant3_Value;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPTX_b));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP TX");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/6_DOF Visual Cab 12//06//15/GT-RT UDP TX");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX_P2_Size[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX_PWORK_o[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX_PWORK_o[0]);
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
      ssSetInputPortWidth(rts, 2, 28);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S1>/GT-RT UDP TX1 (gt_rt_udp_send) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn1.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[1] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[2] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[3] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 4);
        }

        /* port 1 */
        {
          uint16_T const **sfcnUPtrs = (uint16_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.Constant1_Value_d;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn1.UPtrs2;

          {
            int_T i1;
            const uint8_T *u2 = M43_Sim_Forcing_003h_Trajectory_B.BytePacking1_m;
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
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn1.UPtrs3;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.Constant4_Value;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn1.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPTX1_e));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP TX1");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/6_DOF Visual Cab 12//06//15/GT-RT UDP TX1");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX1_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX1_P2_Size[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX1_PWORK_f[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX1_PWORK_f[0]);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S1>/GT-RT UDP  Write (gt_rt_udp_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [2]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [2]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Write");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/6_DOF Visual Cab 12//06//15/GT-RT UDP  Write");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite_P1_Size[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite_PWORK_m);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite_PWORK_m);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S1>/GT-RT UDP  Write1 (gt_rt_udp_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [3]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [3]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Write1");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/6_DOF Visual Cab 12//06//15/GT-RT UDP  Write1");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite1_P1_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite1_PWORK_j);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite1_PWORK_j);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S27>/GT-RT CAN TX (gt_rt_can_send) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [4]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn4.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.TXCANID1_Value;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_B.Gain1_p;
          sfcnUPtrs[1] = &M43_Sim_Forcing_003h_Trajectory_B.Gain2_b;
          sfcnUPtrs[2] = &M43_Sim_Forcing_003h_Trajectory_B.Gain3_i;
          sfcnUPtrs[3] = &M43_Sim_Forcing_003h_Trajectory_B.Gain4_b;
          sfcnUPtrs[4] = &M43_Sim_Forcing_003h_Trajectory_B.Gain1_a;
          sfcnUPtrs[5] = &M43_Sim_Forcing_003h_Trajectory_B.Gain2_g;
          sfcnUPtrs[6] = &M43_Sim_Forcing_003h_Trajectory_B.Gain3_be;
          sfcnUPtrs[7] = &M43_Sim_Forcing_003h_Trajectory_B.Gain4_n;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN TX");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/GT-RT CAN TX");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P2_Size[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX_PWORK_j);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX_PWORK_j);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S27>/GT-RT CAN TX1 (gt_rt_can_send) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [5]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn5.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.TXCANID2_Value;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn5.UPtrs1;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_B.Gain1_n;
          sfcnUPtrs[1] = &M43_Sim_Forcing_003h_Trajectory_B.Gain2_l;
          sfcnUPtrs[2] = &M43_Sim_Forcing_003h_Trajectory_B.Gain3_ic;
          sfcnUPtrs[3] = &M43_Sim_Forcing_003h_Trajectory_B.Gain4_g;
          sfcnUPtrs[4] = &M43_Sim_Forcing_003h_Trajectory_B.Gain1_op;
          sfcnUPtrs[5] = &M43_Sim_Forcing_003h_Trajectory_B.Gain2_ga;
          sfcnUPtrs[6] = &M43_Sim_Forcing_003h_Trajectory_B.Gain3_l;
          sfcnUPtrs[7] = &M43_Sim_Forcing_003h_Trajectory_B.Gain4_c;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN TX1");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/GT-RT CAN TX1");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX1_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX1_P2_Size[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX1_PWORK);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S27>/GT-RT CAN TX2 (gt_rt_can_send) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [6]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn6.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.TXCANID3_Value;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_B.Gain1_d;
          sfcnUPtrs[1] = &M43_Sim_Forcing_003h_Trajectory_B.Gain2_f;
          sfcnUPtrs[2] = &M43_Sim_Forcing_003h_Trajectory_B.Gain3_d;
          sfcnUPtrs[3] = &M43_Sim_Forcing_003h_Trajectory_B.Gain4_k;
          sfcnUPtrs[4] = &M43_Sim_Forcing_003h_Trajectory_B.Gain1_p2;
          sfcnUPtrs[5] = &M43_Sim_Forcing_003h_Trajectory_B.Gain2_p;
          sfcnUPtrs[6] = &M43_Sim_Forcing_003h_Trajectory_B.Gain3_ha;
          sfcnUPtrs[7] = &M43_Sim_Forcing_003h_Trajectory_B.Gain4_h;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN TX2");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/GT-RT CAN TX2");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX2_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX2_P2_Size[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX2_PWORK);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S99>/GT-RT UDP TX (gt_rt_udp_send) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [7]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn7.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[1] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[2] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[3] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 4);
        }

        /* port 1 */
        {
          uint16_T const **sfcnUPtrs = (uint16_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn7.UPtrs1;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.Constant2_Value_i;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn7.UPtrs2;

          {
            int_T i1;
            const uint8_T *u2 = M43_Sim_Forcing_003h_Trajectory_B.BytePacking;
            for (i1=0; i1 < 72; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 72);
        }

        /* port 3 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn7.UPtrs3;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.Constant3_Value_n;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn7.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPTX));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP TX");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Data to Control Node 12//06//15/6_DOF Control/GT-RT UDP TX");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX_P1_Size_g[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX_P2_Size_l[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX_PWORK[0]);
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
      ssSetInputPortWidth(rts, 2, 72);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S99>/GT-RT UDP TX1 (gt_rt_udp_send) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [8]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn8.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[1] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[2] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[3] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 4);
        }

        /* port 1 */
        {
          uint16_T const **sfcnUPtrs = (uint16_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn8.UPtrs1;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.Constant1_Value_i;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn8.UPtrs2;

          {
            int_T i1;
            const uint8_T *u2 = M43_Sim_Forcing_003h_Trajectory_B.BytePacking2;
            for (i1=0; i1 < 24; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 24);
        }

        /* port 3 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn8.UPtrs3;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.Constant4_Value_c;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn8.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPTX1));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP TX1");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Data to Control Node 12//06//15/6_DOF Control/GT-RT UDP TX1");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX1_P1_Size_b[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX1_P2_Size_a[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX1_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX1_PWORK[0]);
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
      ssSetInputPortWidth(rts, 2, 24);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S99>/GT-RT UDP TX2 (gt_rt_udp_send) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [9]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn9.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn9.UPtrs0;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[1] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[2] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          sfcnUPtrs[3] = &M43_Sim_Forcing_003h_Trajectory_U8GND;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 4);
        }

        /* port 1 */
        {
          uint16_T const **sfcnUPtrs = (uint16_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn9.UPtrs1;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.Constant5_Value;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn9.UPtrs2;

          {
            int_T i1;
            const uint8_T *u2 = M43_Sim_Forcing_003h_Trajectory_B.BytePacking1;
            for (i1=0; i1 < 24; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 24);
        }

        /* port 3 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn9.UPtrs3;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.Constant6_Value;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn9.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPTX2));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP TX2");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Data to Control Node 12//06//15/6_DOF Control/GT-RT UDP TX2");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX2_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPTX2_P2_Size[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX2_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn9.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn9.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPTX2_PWORK[0]);
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
      ssSetInputPortWidth(rts, 2, 24);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S99>/GT-RT UDP  Write (gt_rt_udp_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn10.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [10]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [10]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Write");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Data to Control Node 12//06//15/6_DOF Control/GT-RT UDP  Write");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite_P1_Size_f[
                       0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn10.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn10.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite_PWORK);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S99>/GT-RT UDP  Write1 (gt_rt_udp_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn11.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [11]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [11]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Write1");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Data to Control Node 12//06//15/6_DOF Control/GT-RT UDP  Write1");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite1_P1_Size_m
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn11.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn11.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite1_PWORK);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S99>/GT-RT UDP  Write2 (gt_rt_udp_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn12.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [12]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [12]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [12]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Write2");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Data to Control Node 12//06//15/6_DOF Control/GT-RT UDP  Write2");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPWrite2_P1_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn12.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn12.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPWrite2_PWORK);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S102>/GT-RT CAN TX (gt_rt_can_send) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn13.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [13]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [13]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [13]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn13.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn13.UPtrs0;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.TXCANID1_Value_f;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn13.UPtrs1;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.TXData_Value;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN TX");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Handshake CAN/If Action Subsystem/GT-RT CAN TX");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P1_Size_h[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P2_Size_d[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX_PWORK_l);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn13.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn13.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX_PWORK_l);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S103>/GT-RT CAN TX (gt_rt_can_send) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[14];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn14.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn14.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn14.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [14]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [14]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [14]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn14.inputPortInfo
          [0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn14.UPtrs0;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.TXCANID1_Value_h;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn14.UPtrs1;
          sfcnUPtrs[0] = &M43_Sim_Forcing_003h_Trajectory_P.TXData_Value_d;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN TX");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Handshake CAN/If Action Subsystem1/GT-RT CAN TX");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn14.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P1_Size_f[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANTX_P2_Size_i[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn14.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn14.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANTX_PWORK);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S4>/GT-RT UDP RX (gt_rt_udp_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[15];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn15.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn15.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn15.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [15]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [15]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [15]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn15.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 66);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((boolean_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 4);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((uint16_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((int32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP RX");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Controls to GT-RT/GT-RT UDP RX");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn15.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P4_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_IWORK);
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn15.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn15.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_IWORK);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_PWORK);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S4>/GT-RT UDP  Read (gt_rt_udp_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[16];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn16.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn16.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn16.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [16]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [16]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [16]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Read");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Controls to GT-RT/GT-RT UDP  Read");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn16.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRead_P1_Size[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRead_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn16.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn16.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRead_PWORK);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S100>/GT-RT UDP RX (gt_rt_udp_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[17];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn17.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn17.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn17.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [17]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [17]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [17]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn17.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 24);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_o));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o2_d));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((boolean_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o3_o));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 4);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o4_k));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((uint16_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o5_c));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((int32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o6_a));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP RX");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Data to Control Node 12//06//15/Interaction device from VIS (Stick) /GT-RT UDP RX");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn17.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P1_Size_i[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P2_Size_m[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P3_Size_f[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P4_Size_j[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_IWORK_a);
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_PWORK_b);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn17.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn17.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_IWORK_a);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_PWORK_b);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S100>/GT-RT UDP  Read (gt_rt_udp_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[18];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn18.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn18.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn18.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [18]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [18]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [18]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Read");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Data to Control Node 12//06//15/Interaction device from VIS (Stick) /GT-RT UDP  Read");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn18.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRead_P1_Size_c
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRead_PWORK_f);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn18.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn18.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRead_PWORK_f);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S17>/GT-RT CAN RX1 (gt_rt_can_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[19];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn19.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn19.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn19.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [19]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [19]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [19]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn19.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 8);
          ssSetOutputPortSignal(rts, 1, ((uint8_T *)
            M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((uint8_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((boolean_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((uint32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX1_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN RX1");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Receive/GT-RT CAN RX1");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn19.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX1_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX1_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX1_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX1_P4_Size[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANRX1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn19.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn19.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANRX1_PWORK);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S17>/GT-RT CAN RX2 (gt_rt_can_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[20];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn20.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn20.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn20.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [20]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [20]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [20]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn20.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 8);
          ssSetOutputPortSignal(rts, 1, ((uint8_T *)
            M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((uint8_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((boolean_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((uint32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN RX2");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Receive/GT-RT CAN RX2");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn20.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P4_Size[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANRX2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn20.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn20.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANRX2_PWORK);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S17>/GT-RT CAN RX3 (gt_rt_can_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[21];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn21.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn21.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn21.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [21]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [21]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [21]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn21.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 8);
          ssSetOutputPortSignal(rts, 1, ((uint8_T *)
            M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((uint8_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((boolean_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((uint32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX3_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN RX3");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Receive/GT-RT CAN RX3");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn21.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX3_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX3_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX3_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX3_P4_Size[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANRX3_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn21.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn21.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANRX3_PWORK);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S6>/GT-RT UDP RX (gt_rt_udp_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[22];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn22.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn22.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn22.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [22]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [22]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [22]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn22.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 24);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_f));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o2_p));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((boolean_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o3_l));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 4);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o4_b));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((uint16_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o5_f));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((int32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o6_b));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP RX");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Data_from_Unity/GT-RT UDP RX");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn22.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P1_Size_n[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P2_Size_l[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P3_Size_p[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P4_Size_n[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_IWORK_j);
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_PWORK_l);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn22.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn22.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_IWORK_j);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_PWORK_l);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S6>/GT-RT UDP  Read (gt_rt_udp_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[23];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn23.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn23.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn23.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [23]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [23]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [23]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Read");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Data_from_Unity/GT-RT UDP  Read");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn23.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRead_P1_Size_p
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRead_PWORK_g);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn23.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn23.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRead_PWORK_g);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S8>/GT-RT UDP RX (gt_rt_udp_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[24];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn24.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn24.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn24.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [24]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [24]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [24]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn24.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 4);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1_d));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o2_l));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((boolean_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o3_d));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 4);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o4_g));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((uint16_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o5_g));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((int32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o6_m));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP RX");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/FNiRSS to GT-RT1/GT-RT UDP RX");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn24.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P1_Size_o[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P2_Size_c[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P3_Size_d[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P4_Size_c[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_IWORK_p);
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_PWORK_bv);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn24.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn24.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_IWORK_p);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_PWORK_bv);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S8>/GT-RT UDP  Read (gt_rt_udp_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[25];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn25.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn25.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn25.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [25]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [25]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [25]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT UDP\n Read");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/FNiRSS to GT-RT1/GT-RT UDP  Read");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn25.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRead_P1_Size_d
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRead_PWORK_l);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn25.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn25.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRead_PWORK_l);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<S9>/GT-RT CAN RX2 (gt_rt_can_receive) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[26];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn26.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn26.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn26.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [26]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [26]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [26]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn26.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o1_f));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 8);
          ssSetOutputPortSignal(rts, 1, ((uint8_T *)
            M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o2_d));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((uint8_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o3_e));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((uint8_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o4_d));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((boolean_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o5_i));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((uint32_T *)
            &M43_Sim_Forcing_003h_Trajectory_B.GTRTCANRX2_o6_h));
        }
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN RX2");
      ssSetPath(rts,
                "M43_Sim_Forcing_003h_Trajectory/Handshake CAN/GT-RT CAN RX2");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn26.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P1_Size_o[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P2_Size_b[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P3_Size_p[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANRX2_P4_Size_a[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANRX2_PWORK_a);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn26.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn26.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANRX2_PWORK_a);
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

    /* Level2 S-Function Block: M43_Sim_Forcing_003h_Trajectory/<Root>/GT-RT CAN Controller (gt_rt_can_controller) */
    {
      SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[27];

      /* timing info */
      time_T *sfcnPeriod =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn27.sfcnPeriod;
      time_T *sfcnOffset =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn27.sfcnOffset;
      int_T *sfcnTsMap =
        M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn27.sfcnTsMap;
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
                         &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.blkInfo2
                         [27]);
      }

      ssSetRTWSfcnInfo(rts, M43_Sim_Forcing_003h_Trajectory_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods2
                           [27]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.methods3
                           [27]);
      }

      /* path info */
      ssSetModelName(rts, "GT-RT CAN Controller");
      ssSetPath(rts, "M43_Sim_Forcing_003h_Trajectory/GT-RT CAN Controller");
      ssSetRTModel(rts,M43_Sim_Forcing_003h_Trajectory_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn27.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANController_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &M43_Sim_Forcing_003h_Trajectory_P.GTRTCANController_P2_Size
                       [0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANController_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn27.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &M43_Sim_Forcing_003h_Trajectory_M->NonInlinedSFcns.Sfcn27.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &M43_Sim_Forcing_003h_Trajectory_DWork.GTRTCANController_PWORK);
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
void M43_Sim_Forcing_003h_Trajectory_terminate(void)
{
  /* Level2 S-Function Block: '<S4>/GT-RT UDP RX' (gt_rt_udp_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[15];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/GT-RT UDP  Read' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[16];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S100>/GT-RT UDP RX' (gt_rt_udp_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[17];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S100>/GT-RT UDP  Read' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[18];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S17>/GT-RT CAN RX1' (gt_rt_can_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[19];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S17>/GT-RT CAN RX2' (gt_rt_can_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[20];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S17>/GT-RT CAN RX3' (gt_rt_can_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[21];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S6>/GT-RT UDP RX' (gt_rt_udp_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[22];
    sfcnTerminate(rts);
  }

  /* Terminate for enable SubSystem: '<S5>/6_DOF Control' */
  /* Level2 S-Function Block: '<S99>/GT-RT UDP TX' (gt_rt_udp_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S99>/GT-RT UDP TX1' (gt_rt_udp_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S99>/GT-RT UDP TX2' (gt_rt_udp_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S99>/GT-RT UDP  Write' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S99>/GT-RT UDP  Write1' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S99>/GT-RT UDP  Write2' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* end of Terminate for SubSystem: '<S5>/6_DOF Control' */

  /* Level2 S-Function Block: '<S6>/GT-RT UDP  Read' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[23];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/GT-RT UDP RX' (gt_rt_udp_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[24];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/GT-RT UDP  Read' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[25];
    sfcnTerminate(rts);
  }

  /* Terminate for enable SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' */
  /* Level2 S-Function Block: '<S1>/GT-RT UDP TX' (gt_rt_udp_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/GT-RT UDP TX1' (gt_rt_udp_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/GT-RT UDP  Write' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/GT-RT UDP  Write1' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* end of Terminate for SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' */

  /* Terminate for ifaction SubSystem: '<S18>/If Action Subsystem1' */
  /* Level2 S-Function Block: '<S27>/GT-RT CAN TX' (gt_rt_can_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S27>/GT-RT CAN TX1' (gt_rt_can_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S27>/GT-RT CAN TX2' (gt_rt_can_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* end of Terminate for SubSystem: '<S18>/If Action Subsystem1' */

  /* Terminate for ifaction SubSystem: '<S9>/If Action Subsystem' */
  /* Level2 S-Function Block: '<S102>/GT-RT CAN TX' (gt_rt_can_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* end of Terminate for SubSystem: '<S9>/If Action Subsystem' */

  /* Level2 S-Function Block: '<S9>/GT-RT CAN RX2' (gt_rt_can_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[26];
    sfcnTerminate(rts);
  }

  /* Terminate for ifaction SubSystem: '<S9>/If Action Subsystem1' */
  /* Level2 S-Function Block: '<S103>/GT-RT CAN TX' (gt_rt_can_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[14];
    sfcnTerminate(rts);
  }

  /* end of Terminate for SubSystem: '<S9>/If Action Subsystem1' */

  /* Level2 S-Function Block: '<Root>/GT-RT CAN Controller' (gt_rt_can_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[27];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  M43_Sim_Forcing_003h_Trajectory_output(tid);
}

void MdlUpdate(int_T tid)
{
  M43_Sim_Forcing_003h_Trajectory_update(tid);
}

void MdlInitializeSizes(void)
{
  M43_Sim_Forcing_003h_Trajectory_M->Sizes.numContStates = (0);/* Number of continuous states */
  M43_Sim_Forcing_003h_Trajectory_M->Sizes.numY = (0);/* Number of model outputs */
  M43_Sim_Forcing_003h_Trajectory_M->Sizes.numU = (0);/* Number of model inputs */
  M43_Sim_Forcing_003h_Trajectory_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  M43_Sim_Forcing_003h_Trajectory_M->Sizes.numSampTimes = (1);/* Number of sample times */
  M43_Sim_Forcing_003h_Trajectory_M->Sizes.numBlocks = (561);/* Number of blocks */
  M43_Sim_Forcing_003h_Trajectory_M->Sizes.numBlockIO = (297);/* Number of block outputs */
  M43_Sim_Forcing_003h_Trajectory_M->Sizes.numBlockPrms = (1463);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  {
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC;
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_PrevRese = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator2' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator2_DSTATE =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator2_IC;
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator2_PrevRes = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S94>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTATE =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC;
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevRes = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_d =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_m;
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_p = 2;

    /* InitializeConditions for DiscreteTransferFcn: '<S13>/Butterworth Filter 10 Hz' */
    for (i = 0; i < 12; i++) {
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a[i] =
        M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Initial_l;
    }

    /* InitializeConditions for Embedded MATLAB: '<S104>/Embedded MATLAB Function' */
    M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c5_M43_Sim_Forcing_00 = 0U;

    /* InitializeConditions for DiscreteIntegrator: '<S81>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_c =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_d;

    /* InitializeConditions for DiscreteIntegrator: '<S83>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_e =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_o;

    /* InitializeConditions for DiscreteIntegrator: '<S84>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_d =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_h;

    /* InitializeConditions for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_i =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_c;

    /* InitializeConditions for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_g =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_f;

    /* InitializeConditions for Embedded MATLAB: '<S78>/Embedded MATLAB Function' */
    M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c3_M43_Sim_Forcing_00 = 0U;

    /* InitializeConditions for DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_f =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_g;

    /* InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_IC_LOAD = 1U;
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_k = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S110>/Discrete-Time Integrator' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_IC_LOADI = 1U;
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_PrevRe_d = 2;
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for UnitDelay: '<S106>/Unit Delay' */
      M43_Sim_Forcing_003h_Trajectory_DWork.UnitDelay_DSTATE[i] =
        M43_Sim_Forcing_003h_Trajectory_P.UnitDelay_X0[i];

      /* InitializeConditions for UnitDelay: '<S105>/Unit Delay6' */
      M43_Sim_Forcing_003h_Trajectory_DWork.UnitDelay6_DSTATE[i] =
        M43_Sim_Forcing_003h_Trajectory_P.UnitDelay6_X0[i];
    }

    /* InitializeConditions for DiscreteTransferFcn: '<S10>/Butterworth Filter 10 Hz' */
    for (i = 0; i < 24; i++) {
      M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE[i] =
        M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_InitialSt;
    }

    /* InitializeConditions for RateLimiter: '<S20>/Acc Limiter A1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.PrevY =
      M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA1_IC;

    /* InitializeConditions for RateLimiter: '<S20>/Acc Limiter A2' */
    M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_n =
      M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA2_IC;

    /* InitializeConditions for RateLimiter: '<S20>/Acc Limiter A3' */
    M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_i =
      M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA3_IC;

    /* InitializeConditions for RateLimiter: '<S20>/Acc Limiter A4' */
    M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_b =
      M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA4_IC;

    /* InitializeConditions for RateLimiter: '<S20>/Acc Limiter A5' */
    M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_bp =
      M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA5_IC;

    /* InitializeConditions for RateLimiter: '<S20>/Acc Limiter A6' */
    M43_Sim_Forcing_003h_Trajectory_DWork.PrevY_p =
      M43_Sim_Forcing_003h_Trajectory_P.AccLimiterA6_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_k =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_p;
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_b = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S98>/pi//(zeta*T_transfer)//s' */
    M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_DSTATE =
      M43_Sim_Forcing_003h_Trajectory_P.pizetaT_transfers_IC;

    /* InitializeConditions for DiscreteTransferFcn: '<S3>/Butterworth Filter 10 Hz' */
    M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[0] =
      M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Initial_f;
    M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[1] =
      M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Initial_f;
    M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[2] =
      M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Initial_f;
    M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_b[3] =
      M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Initial_f;

    /* InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_g =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_h;
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_f = 2;

    /* InitializeConditions for Embedded MATLAB: '<S79>/Get R' */
    M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c4_M43_Sim_Forcing_00 = 0U;

    /* InitializeConditions for DiscreteIntegrator: '<S80>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTA_ds =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_k;

    /* InitializeConditions for DiscreteIntegrator: '<S81>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_n =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_kd;

    /* InitializeConditions for DiscreteIntegrator: '<S82>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_b =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_pa;

    /* InitializeConditions for DiscreteIntegrator: '<S83>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_o =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_n;

    /* InitializeConditions for DiscreteIntegrator: '<S84>/Discrete-Time Integrator1' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTA_ko =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_b;

    /* InitializeConditions for Embedded MATLAB: '<S92>/Exp_saturation' */
    M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c2_M43_Sim_Forcing_00 = 0U;

    /* InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator3' */
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_DSTATE =
      M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator3_IC;
    M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator3_PrevRes = 2;

    /* InitializeConditions for Embedded MATLAB: '<S93>/Natural Speed Down' */
    M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c10_M43_Sim_Forcing_0 = 0U;

    /* InitializeConditions for DiscreteIntegrator: '<S98>/4*zeta*pi//T_transfer //s' */
    M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_DSTATE =
      M43_Sim_Forcing_003h_Trajectory_P.zetapiT_transfers_IC;
  }
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<S4>/GT-RT UDP RX' (gt_rt_udp_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[15];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S4>/GT-RT UDP  Read' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[16];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S100>/GT-RT UDP RX' (gt_rt_udp_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[17];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S100>/GT-RT UDP  Read' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[18];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S3>/Target PSI' */
  M43_Sim_Forcing_003h_Trajectory_B.TargetPSI =
    M43_Sim_Forcing_003h_Trajectory_P.TargetPSI_Value;

  /* Start for enable SubSystem: '<S3>/Move UP1' */

  /* InitializeConditions for UnitDelay: '<S87>/For saving position  and velocity until after switchover' */
  M43_Sim_Forcing_003h_Trajectory_DWork.Forsavingpositionandvelocityunt =
    M43_Sim_Forcing_003h_Trajectory_P.Forsavingpositionandvelocityunt;

  /* InitializeConditions for UnitDelay: '<S90>/UD' */
  M43_Sim_Forcing_003h_Trajectory_DWork.UD_DSTATE =
    M43_Sim_Forcing_003h_Trajectory_P.UD_X0;

  /* InitializeConditions for DiscreteIntegrator: '<S87>/pi//(zeta*T_transfer)//s' */
  M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_IC_LOADING = 1U;
  M43_Sim_Forcing_003h_Trajectory_DWork.pizetaT_transfers_PrevResetStat = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S87>/4*zeta*pi//T_transfer //s' */
  M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_IC_LOADING = 1U;
  M43_Sim_Forcing_003h_Trajectory_DWork.zetapiT_transfers_PrevResetStat = 2;

  /* InitializeConditions for Embedded MATLAB: '<S88>/Embedded MATLAB Function' */
  M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c1_M43_Sim_Forcing_00 = 0U;

  /* InitializeConditions for Embedded MATLAB: '<S73>/curve' */
  M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c8_M43_Sim_Forcing_00 = 0U;

  /* end of Start for SubSystem: '<S3>/Move UP1' */

  /* Level2 S-Function Block: '<S17>/GT-RT CAN RX1' (gt_rt_can_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[19];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S17>/GT-RT CAN RX2' (gt_rt_can_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[20];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S17>/GT-RT CAN RX3' (gt_rt_can_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[21];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S6>/GT-RT UDP RX' (gt_rt_udp_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[22];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for enable SubSystem: '<S5>/6_DOF Control' */

  /* Level2 S-Function Block: '<S99>/GT-RT UDP TX' (gt_rt_udp_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S99>/GT-RT UDP TX1' (gt_rt_udp_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S99>/GT-RT UDP TX2' (gt_rt_udp_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S99>/GT-RT UDP  Write' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S99>/GT-RT UDP  Write1' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[11];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S99>/GT-RT UDP  Write2' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* end of Start for SubSystem: '<S5>/6_DOF Control' */

  /* Level2 S-Function Block: '<S6>/GT-RT UDP  Read' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[23];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S8>/GT-RT UDP RX' (gt_rt_udp_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[24];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S8>/GT-RT UDP  Read' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[25];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S70>/Allowed Psi' */
  M43_Sim_Forcing_003h_Trajectory_B.AllowedPsi =
    M43_Sim_Forcing_003h_Trajectory_P.AllowedPsi_Value;

  /* Start for enable SubSystem: '<S112>/Simplified Inverse Kin' */

  /* InitializeConditions for Embedded MATLAB: '<S116>/Embedded MATLAB Function1' */
  M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c7_M43_Sim_Forcing_00 = 0U;

  /* end of Start for SubSystem: '<S112>/Simplified Inverse Kin' */

  /* Start for enable SubSystem: '<S110>/full inverse kin' */

  /* InitializeConditions for Embedded MATLAB: '<S113>/Embedded MATLAB Function' */
  M43_Sim_Forcing_003h_Trajectory_DWork.is_active_c6_M43_Sim_Forcing_00 = 0U;

  /* end of Start for SubSystem: '<S110>/full inverse kin' */

  /* Start for enable SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' */

  /* Level2 S-Function Block: '<S1>/GT-RT UDP TX' (gt_rt_udp_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/GT-RT UDP TX1' (gt_rt_udp_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/GT-RT UDP  Write' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S1>/GT-RT UDP  Write1' (gt_rt_udp_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE_n =
    M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator_IC_l;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_DSTAT_f =
    M43_Sim_Forcing_003h_Trajectory_P.DiscreteTimeIntegrator1_IC_o;
  M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_PrevR_c = 2;

  /* end of Start for SubSystem: '<Root>/6_DOF Visual Cab 12//06//15' */

  /* Start for ifaction SubSystem: '<S18>/If Action Subsystem1' */

  /* Level2 S-Function Block: '<S27>/GT-RT CAN TX' (gt_rt_can_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S27>/GT-RT CAN TX1' (gt_rt_can_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S27>/GT-RT CAN TX2' (gt_rt_can_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* end of Start for SubSystem: '<S18>/If Action Subsystem1' */

  /* Start for Constant: '<S92>/x_max' */
  M43_Sim_Forcing_003h_Trajectory_B.x_max =
    M43_Sim_Forcing_003h_Trajectory_P.x_max_Value;

  /* Start for Constant: '<S93>/Constant1' */
  M43_Sim_Forcing_003h_Trajectory_B.Constant1 =
    M43_Sim_Forcing_003h_Trajectory_P.Constant1_Value_g;

  /* Start for ifaction SubSystem: '<S9>/If Action Subsystem' */

  /* Level2 S-Function Block: '<S102>/GT-RT CAN TX' (gt_rt_can_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[13];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* end of Start for SubSystem: '<S9>/If Action Subsystem' */

  /* Level2 S-Function Block: '<S9>/GT-RT CAN RX2' (gt_rt_can_receive) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[26];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for ifaction SubSystem: '<S9>/If Action Subsystem1' */

  /* Level2 S-Function Block: '<S103>/GT-RT CAN TX' (gt_rt_can_send) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[14];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* end of Start for SubSystem: '<S9>/If Action Subsystem1' */

  /* Level2 S-Function Block: '<Root>/GT-RT CAN Controller' (gt_rt_can_controller) */
  {
    SimStruct *rts = M43_Sim_Forcing_003h_Trajectory_M->childSfunctions[27];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  M43_Sim_Forcing_003h_Trajectory_terminate();
}

RT_MODEL_M43_Sim_Forcing_003h_Trajectory *M43_Sim_Forcing_003h_Trajectory(void)
{
  M43_Sim_Forcing_003h_Trajectory_initialize(1);
  return M43_Sim_Forcing_003h_Trajectory_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/

/*
 * M43_Sim_Forcing_003h_Trajectory_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(uint8_T),
  sizeof(uint16_T),
  sizeof(uint8_T),
  sizeof(uint16_T),
  sizeof(uint8_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(int64m_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(int64m_T),
  sizeof(uint64m_T),
  sizeof(int96m_T),
  sizeof(uint96m_T),
  sizeof(int128m_T),
  sizeof(uint128m_T),
  sizeof(int160m_T),
  sizeof(uint160m_T),
  sizeof(int192m_T),
  sizeof(uint192m_T),
  sizeof(int224m_T),
  sizeof(uint224m_T),
  sizeof(int256m_T),
  sizeof(uint256m_T),
  sizeof(int288m_T),
  sizeof(uint288m_T),
  sizeof(int320m_T),
  sizeof(uint320m_T),
  sizeof(int352m_T),
  sizeof(uint352m_T),
  sizeof(int384m_T),
  sizeof(uint384m_T),
  sizeof(int416m_T),
  sizeof(uint416m_T),
  sizeof(int448m_T),
  sizeof(uint448m_T),
  sizeof(int480m_T),
  sizeof(uint480m_T),
  sizeof(int512m_T),
  sizeof(uint512m_T),
  sizeof(int544m_T),
  sizeof(uint544m_T),
  sizeof(int576m_T),
  sizeof(uint576m_T),
  sizeof(int608m_T),
  sizeof(uint608m_T),
  sizeof(int640m_T),
  sizeof(uint640m_T),
  sizeof(int672m_T),
  sizeof(uint672m_T),
  sizeof(int704m_T),
  sizeof(uint704m_T),
  sizeof(int736m_T),
  sizeof(uint736m_T),
  sizeof(int768m_T),
  sizeof(uint768m_T),
  sizeof(int800m_T),
  sizeof(uint800m_T),
  sizeof(int832m_T),
  sizeof(uint832m_T),
  sizeof(int864m_T),
  sizeof(uint864m_T),
  sizeof(int896m_T),
  sizeof(uint896m_T),
  sizeof(int928m_T),
  sizeof(uint928m_T),
  sizeof(int960m_T),
  sizeof(uint960m_T),
  sizeof(int992m_T),
  sizeof(uint992m_T),
  sizeof(int1024m_T),
  sizeof(uint1024m_T),
  sizeof(int1056m_T),
  sizeof(uint1056m_T),
  sizeof(int1088m_T),
  sizeof(uint1088m_T),
  sizeof(int1120m_T),
  sizeof(uint1120m_T),
  sizeof(int1152m_T),
  sizeof(uint1152m_T),
  sizeof(int1184m_T),
  sizeof(uint1184m_T),
  sizeof(int1216m_T),
  sizeof(uint1216m_T),
  sizeof(int1248m_T),
  sizeof(uint1248m_T),
  sizeof(int1280m_T),
  sizeof(uint1280m_T),
  sizeof(int1312m_T),
  sizeof(uint1312m_T),
  sizeof(int1344m_T),
  sizeof(uint1344m_T),
  sizeof(int1376m_T),
  sizeof(uint1376m_T),
  sizeof(int1408m_T),
  sizeof(uint1408m_T),
  sizeof(int1440m_T),
  sizeof(uint1440m_T),
  sizeof(int1472m_T),
  sizeof(uint1472m_T),
  sizeof(int1504m_T),
  sizeof(uint1504m_T),
  sizeof(int1536m_T),
  sizeof(uint1536m_T),
  sizeof(int1568m_T),
  sizeof(uint1568m_T),
  sizeof(int1600m_T),
  sizeof(uint1600m_T),
  sizeof(int1632m_T),
  sizeof(uint1632m_T),
  sizeof(int1664m_T),
  sizeof(uint1664m_T),
  sizeof(int1696m_T),
  sizeof(uint1696m_T),
  sizeof(int1728m_T),
  sizeof(uint1728m_T),
  sizeof(int1760m_T),
  sizeof(uint1760m_T),
  sizeof(int1792m_T),
  sizeof(uint1792m_T),
  sizeof(int1824m_T),
  sizeof(uint1824m_T),
  sizeof(int1856m_T),
  sizeof(uint1856m_T),
  sizeof(int1888m_T),
  sizeof(uint1888m_T),
  sizeof(int1920m_T),
  sizeof(uint1920m_T),
  sizeof(int1952m_T),
  sizeof(uint1952m_T),
  sizeof(int1984m_T),
  sizeof(uint1984m_T),
  sizeof(int2016m_T),
  sizeof(uint2016m_T),
  sizeof(int2048m_T),
  sizeof(uint2048m_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "uint8_T",
  "uint16_T",
  "uint8_T",
  "uint16_T",
  "uint8_T",
  "uint16_T",
  "int32_T",
  "int64m_T",
  "int32_T",
  "uint32_T",
  "int64m_T",
  "uint64m_T",
  "int96m_T",
  "uint96m_T",
  "int128m_T",
  "uint128m_T",
  "int160m_T",
  "uint160m_T",
  "int192m_T",
  "uint192m_T",
  "int224m_T",
  "uint224m_T",
  "int256m_T",
  "uint256m_T",
  "int288m_T",
  "uint288m_T",
  "int320m_T",
  "uint320m_T",
  "int352m_T",
  "uint352m_T",
  "int384m_T",
  "uint384m_T",
  "int416m_T",
  "uint416m_T",
  "int448m_T",
  "uint448m_T",
  "int480m_T",
  "uint480m_T",
  "int512m_T",
  "uint512m_T",
  "int544m_T",
  "uint544m_T",
  "int576m_T",
  "uint576m_T",
  "int608m_T",
  "uint608m_T",
  "int640m_T",
  "uint640m_T",
  "int672m_T",
  "uint672m_T",
  "int704m_T",
  "uint704m_T",
  "int736m_T",
  "uint736m_T",
  "int768m_T",
  "uint768m_T",
  "int800m_T",
  "uint800m_T",
  "int832m_T",
  "uint832m_T",
  "int864m_T",
  "uint864m_T",
  "int896m_T",
  "uint896m_T",
  "int928m_T",
  "uint928m_T",
  "int960m_T",
  "uint960m_T",
  "int992m_T",
  "uint992m_T",
  "int1024m_T",
  "uint1024m_T",
  "int1056m_T",
  "uint1056m_T",
  "int1088m_T",
  "uint1088m_T",
  "int1120m_T",
  "uint1120m_T",
  "int1152m_T",
  "uint1152m_T",
  "int1184m_T",
  "uint1184m_T",
  "int1216m_T",
  "uint1216m_T",
  "int1248m_T",
  "uint1248m_T",
  "int1280m_T",
  "uint1280m_T",
  "int1312m_T",
  "uint1312m_T",
  "int1344m_T",
  "uint1344m_T",
  "int1376m_T",
  "uint1376m_T",
  "int1408m_T",
  "uint1408m_T",
  "int1440m_T",
  "uint1440m_T",
  "int1472m_T",
  "uint1472m_T",
  "int1504m_T",
  "uint1504m_T",
  "int1536m_T",
  "uint1536m_T",
  "int1568m_T",
  "uint1568m_T",
  "int1600m_T",
  "uint1600m_T",
  "int1632m_T",
  "uint1632m_T",
  "int1664m_T",
  "uint1664m_T",
  "int1696m_T",
  "uint1696m_T",
  "int1728m_T",
  "uint1728m_T",
  "int1760m_T",
  "uint1760m_T",
  "int1792m_T",
  "uint1792m_T",
  "int1824m_T",
  "uint1824m_T",
  "int1856m_T",
  "uint1856m_T",
  "int1888m_T",
  "uint1888m_T",
  "int1920m_T",
  "uint1920m_T",
  "int1952m_T",
  "uint1952m_T",
  "int1984m_T",
  "uint1984m_T",
  "int2016m_T",
  "uint2016m_T",
  "int2048m_T",
  "uint2048m_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.Sum9), 0, 0, 278 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.Gain_m), 21, 0, 6 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.Unpack_o2), 1, 0, 83 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o6), 6, 0, 13 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o2), 7, 0, 8 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o5), 5, 0, 4 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o1[0]), 3, 0, 398 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.GTRTUDPRX_o3), 8, 0, 10 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem1_e.Switch),
    0, 0, 1 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_d0.Switch),
    0, 0, 2 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_e.Switch), 0,
    0, 2 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_d.Switch), 0,
    0, 2 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_i.Switch), 0,
    0, 2 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_B.IfActionSubsystem_h.Switch), 0,
    0, 2 }
  ,

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_DSTATE), 0, 0,
    95 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_PWORK), 11, 0,
    41 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.ButterworthFilter10Hz_DSTATE_a[0]),
    1, 0, 18 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_DWork.Add_DWORK1), 7, 0, 1 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_DWork.GTRTUDPRX_IWORK), 10, 0,
    28 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator_PrevRese), 2,
    0, 21 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.DiscreteTimeIntegrator1_IC_LOAD), 3,
    0, 13 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_DWork.isStable), 8, 0, 18 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_d0.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_d.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_e.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_p.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_d.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_k.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_i.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1_f.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem_h.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_DWork.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC),
    2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  33U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_P.GTRTUDPRX_P1_Size[0]), 0, 0,
    1346 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_P.ButterworthFilter10Hz_Initial_l), 1, 0,
    27 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_P.Constant3_Value), 7, 0, 10 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_P.Gain_Gain_it), 6, 0, 6 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_P.shift_Power2Exponent), 4, 0,
    18 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_P.Constant2_Value_l), 5, 0, 5 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_P.Constant_Value_g), 3, 0, 29 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_e.PSEA2_Value), 0, 0,
    2 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_d0.PSEA2_Value), 0, 0,
    2 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_d.PSEA2_Value), 0, 0,
    2 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_e.PSEA2_Value), 0, 0,
    2 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_p.PSEA2_Value), 0, 0,
    2 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_d.PSEA2_Value), 0, 0,
    2 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_k.PSEA2_Value), 0, 0,
    2 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_i.PSEA2_Value), 0, 0,
    2 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1_f.PSEA2_Value), 0, 0,
    2 },

  { (char_T *)
    (&M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem_h.PSEA2_Value), 0, 0,
    2 },

  { (char_T *)(&M43_Sim_Forcing_003h_Trajectory_P.IfActionSubsystem1.PSEA2_Value),
    0, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  18U,
  rtPTransitions
};

/* [EOF] M43_Sim_Forcing_003h_Trajectory_dt.h */

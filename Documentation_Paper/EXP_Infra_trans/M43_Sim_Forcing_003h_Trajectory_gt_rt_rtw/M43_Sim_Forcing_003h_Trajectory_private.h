/*
 * M43_Sim_Forcing_003h_Trajectory_private.h
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
#ifndef RTW_HEADER_M43_Sim_Forcing_003h_Trajectory_private_h_
#define RTW_HEADER_M43_Sim_Forcing_003h_Trajectory_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (-1)
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y[], int32_T n);
extern real_T sMultiWord2Double(const uint32_T u1[], int32_T n1);
extern void gt_rt_udp_send(SimStruct *rts);
extern void gt_rt_udp_controller(SimStruct *rts);
extern void gt_rt_can_send(SimStruct *rts);
extern void gt_rt_udp_receive(SimStruct *rts);
extern void gt_rt_can_receive(SimStruct *rts);
extern void gt_rt_can_controller(SimStruct *rts);
extern void M43_Sim_Forc_IfActionSubsystem1(real_T rtu_Inc, real_T rtu_dif,
  rtB_IfActionSubsystem1_M43_Sim_ *localB, rtP_IfActionSubsystem1_M43_Sim_
  *localP);
extern void M43_Sim_Forci_IfActionSubsystem(real_T rtu_Inc, real_T rtu_dif,
  rtB_IfActionSubsystem_M43_Sim_F *localB, rtP_IfActionSubsystem_M43_Sim_F
  *localP);

#endif                                 /* RTW_HEADER_M43_Sim_Forcing_003h_Trajectory_private_h_ */

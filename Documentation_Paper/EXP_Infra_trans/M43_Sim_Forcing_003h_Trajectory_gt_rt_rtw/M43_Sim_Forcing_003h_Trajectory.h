/*
 * M43_Sim_Forcing_003h_Trajectory.h
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
#ifndef RTW_HEADER_M43_Sim_Forcing_003h_Trajectory_h_
#define RTW_HEADER_M43_Sim_Forcing_003h_Trajectory_h_
#ifndef M43_Sim_Forcing_003h_Trajectory_COMMON_INCLUDES_
# define M43_Sim_Forcing_003h_Trajectory_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_SATURATE.h"
#include "rt_atan2_snf.h"
#include "rt_pow_snf.h"
#endif                                 /* M43_Sim_Forcing_003h_Trajectory_COMMON_INCLUDES_ */

#include "M43_Sim_Forcing_003h_Trajectory_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define M43_Sim_Forcing_003h_Trajectory_rtModel RT_MODEL_M43_Sim_Forcing_003h_Trajectory

/* Block signals for system '<S52>/If Action Subsystem1' */
typedef struct {
  real_T Switch;                       /* '<S59>/Switch' */
} rtB_IfActionSubsystem1_M43_Sim_;

/* Block states (auto storage) for system '<S52>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S52>/If Action Subsystem1' */
} rtDW_IfActionSubsystem1_M43_Sim;

/* Block signals for system '<S53>/If Action Subsystem' */
typedef struct {
  real_T Switch;                       /* '<S60>/Switch' */
} rtB_IfActionSubsystem_M43_Sim_F;

/* Block states (auto storage) for system '<S53>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S53>/If Action Subsystem' */
} rtDW_IfActionSubsystem_M43_Sim_;

/* Block signals (auto storage) */
typedef struct {
  real_T Sum9;                         /* '<S3>/Sum9' */
  real_T Sum15;                        /* '<S3>/Sum15' */
  real_T TargetPSI;                    /* '<S3>/Target PSI' */
  real_T Sum;                          /* '<S3>/Sum' */
  real_T Sum11;                        /* '<S3>/Sum11' */
  real_T Phi1;                         /* '<S3>/Phi1' */
  real_T Theta1;                       /* '<S3>/Theta1' */
  real_T Sum3;                         /* '<S3>/Sum3' */
  real_T Sum_j[6];                     /* '<S109>/Sum' */
  real_T SwitchControl;                /* '<S7>/SwitchControl' */
  real_T Sum2;                         /* '<S6>/Sum2' */
  real_T Sum3_d;                       /* '<S6>/Sum3' */
  real_T Sum1;                         /* '<S6>/Sum1' */
  real_T fromcmtom;                    /* '<S75>/from cm to m' */
  real_T Sum1_n;                       /* '<S3>/Sum1' */
  real_T fromcmtom_f;                  /* '<S76>/from cm to m' */
  real_T Sum8;                         /* '<S3>/Sum8' */
  real_T Sum4;                         /* '<S3>/Sum4' */
  real_T Sum7;                         /* '<S3>/Sum7' */
  real_T Sum5;                         /* '<S3>/Sum5' */
  real_T AllowedPsi;                   /* '<S70>/Allowed Psi' */
  real_T DiscreteTimeIntegrator;       /* '<S92>/Discrete-Time Integrator' */
  real_T Sum12;                        /* '<S3>/Sum12' */
  real_T UnitDelay[6];                 /* '<S106>/Unit Delay' */
  real_T Switch1;                      /* '<S106>/Switch1' */
  real_T Sum_d[6];                     /* '<S112>/Sum' */
  real_T DiscreteTimeIntegrator1[6];   /* '<S112>/Discrete-Time Integrator1' */
  real_T Sum_n[6];                     /* '<S110>/Sum' */
  real_T Sum1_k[6];                    /* '<S110>/Sum1' */
  real_T Switch[7];                    /* '<S106>/Switch' */
  real_T Sum_b[6];                     /* '<S111>/Sum' */
  real_T Sum2_b;                       /* '<S10>/Sum2' */
  real_T Abs2;                         /* '<S52>/Abs2' */
  real_T Sum1_o[6];                    /* '<S10>/Sum1' */
  real_T Sum_k[6];                     /* '<S10>/Sum' */
  real_T ButterworthFilter10Hz[6];     /* '<S10>/Butterworth Filter 10 Hz' */
  real_T Switch_m[6];                  /* '<Root>/Switch' */
  real_T Abs1;                         /* '<S52>/Abs1' */
  real_T Switch1_d;                    /* '<S52>/Switch1' */
  real_T AccLimiterA1;                 /* '<S20>/Acc Limiter A1' */
  real_T Abs2_m;                       /* '<S53>/Abs2' */
  real_T Abs1_h;                       /* '<S53>/Abs1' */
  real_T Switch1_a;                    /* '<S53>/Switch1' */
  real_T AccLimiterA2;                 /* '<S20>/Acc Limiter A2' */
  real_T Abs2_g;                       /* '<S54>/Abs2' */
  real_T Abs1_i;                       /* '<S54>/Abs1' */
  real_T Switch1_b;                    /* '<S54>/Switch1' */
  real_T AccLimiterA3;                 /* '<S20>/Acc Limiter A3' */
  real_T Abs2_c;                       /* '<S55>/Abs2' */
  real_T Abs1_ha;                      /* '<S55>/Abs1' */
  real_T Switch1_n;                    /* '<S55>/Switch1' */
  real_T AccLimiterA4;                 /* '<S20>/Acc Limiter A4' */
  real_T Abs2_b;                       /* '<S56>/Abs2' */
  real_T Abs1_f;                       /* '<S56>/Abs1' */
  real_T Switch1_c;                    /* '<S56>/Switch1' */
  real_T AccLimiterA5;                 /* '<S20>/Acc Limiter A5' */
  real_T Abs2_f;                       /* '<S57>/Abs2' */
  real_T Abs1_f5;                      /* '<S57>/Abs1' */
  real_T Switch1_f;                    /* '<S57>/Switch1' */
  real_T AccLimiterA6;                 /* '<S20>/Acc Limiter A6' */
  real_T Sum1_ks[6];                   /* '<S2>/Sum1' */
  real_T Gain;                         /* '<S18>/Gain' */
  real_T Gain1;                        /* '<S18>/Gain1' */
  real_T Gain2;                        /* '<S18>/Gain2' */
  real_T Gain3;                        /* '<S18>/Gain3' */
  real_T Gain4;                        /* '<S18>/Gain4' */
  real_T Gain5;                        /* '<S18>/Gain5' */
  real_T pizetaT_transfers;            /* '<S98>/pi//(zeta*T_transfer)//s' */
  real_T Product1;                     /* '<S74>/Product1' */
  real_T Product4[3];                  /* '<S70>/Product4' */
  real_T Product;                      /* '<S79>/Product' */
  real_T Sum5_c;                       /* '<S80>/Sum5' */
  real_T Sum4_k;                       /* '<S80>/Sum4' */
  real_T DiscreteTimeIntegrator1_l;    /* '<S81>/Discrete-Time Integrator1' */
  real_T Sum4_g;                       /* '<S81>/Sum4' */
  real_T Sum5_d;                       /* '<S82>/Sum5' */
  real_T Sum4_k2;                      /* '<S82>/Sum4' */
  real_T DiscreteTimeIntegrator1_i;    /* '<S83>/Discrete-Time Integrator1' */
  real_T Sum4_b;                       /* '<S83>/Sum4' */
  real_T DiscreteTimeIntegrator1_b;    /* '<S84>/Discrete-Time Integrator1' */
  real_T Sum4_o;                       /* '<S84>/Sum4' */
  real_T Gain1_k;                      /* '<S92>/Gain1' */
  real_T x_max;                        /* '<S92>/x_max' */
  real_T Sum_nx;                       /* '<S92>/Sum' */
  real_T Constant1;                    /* '<S93>/Constant1' */
  real_T Product_g;                    /* '<S93>/Product' */
  real_T DiscreteTimeIntegrator3;      /* '<S93>/Discrete-Time Integrator3' */
  real_T Product1_j;                   /* '<S93>/Product1' */
  real_T Product2;                     /* '<S93>/Product2' */
  real_T frommtocm;                    /* '<S93>/from m to cm' */
  real_T frommtocm_a;                  /* '<S94>/from m to cm' */
  real_T zetapi;                       /* '<S98>/4*zeta*pi' */
  real_T pizeta;                       /* '<S98>/pi//zeta' */
  real_T Gain_f[6];                    /* '<S110>/Gain' */
  real_T Gain1_j[6];                   /* '<S112>/Gain1' */
  real_T out[7];                       /* '<S116>/Embedded MATLAB Function1' */
  real_T out_g[7];                     /* '<S113>/Embedded MATLAB Function' */
  real_T Sum1_j[6];                    /* '<S112>/Sum1' */
  real_T out_m[6];                     /* '<S104>/Embedded MATLAB Function' */
  real_T Sum_c;                        /* '<S99>/Sum' */
  real_T v_body;                       /* '<S93>/Natural Speed Down' */
  real_T x_out;                        /* '<S92>/Exp_saturation' */
  real_T MultiportSwitch[6];           /* '<S73>/Multiport Switch' */
  real_T Forsavingpositionandvelocityunt;/* '<S87>/For saving position  and velocity until after switchover' */
  real_T TSamp;                        /* '<S90>/TSamp' */
  real_T zetaT_transferpi;             /* '<S87>/(zeta*T_transfer)//pi' */
  real_T pizetaT_transfers_d;          /* '<S87>/pi//(zeta*T_transfer)//s' */
  real_T zetapi_b;                     /* '<S87>/4*zeta*pi' */
  real_T pizeta_i;                     /* '<S87>/pi//zeta' */
  real_T x;                            /* '<S73>/curve' */
  real_T z;                            /* '<S73>/curve' */
  real_T psi;                          /* '<S73>/curve' */
  real_T set_out[6];                   /* '<S88>/Embedded MATLAB Function' */
  real_T R;                            /* '<S79>/Get R' */
  real_T d_psi;                        /* '<S78>/Embedded MATLAB Function' */
  real_T Switch_mx;                    /* '<S57>/Switch' */
  real_T Switch_p;                     /* '<S56>/Switch' */
  real_T Switch_d;                     /* '<S55>/Switch' */
  real_T Switch_n;                     /* '<S54>/Switch' */
  real_T Switch_dh;                    /* '<S53>/Switch' */
  real_T Switch_dx;                    /* '<S58>/Switch' */
  real_T Switch_po;                    /* '<S52>/Switch' */
  real_T SwitchControl_a[6];           /* '<S11>/SwitchControl' */
  real_T DiscreteTimeIntegrator_l;     /* '<S81>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_h;     /* '<S84>/Discrete-Time Integrator' */
  real_T ControlLoopGain[6];           /* '<S10>/Control Loop Gain' */
  real_T Switch1_nd[3];                /* '<S3>/Switch1' */
  real_T Divide1;                      /* '<S79>/Divide1' */
  real_T Product_k[3];                 /* '<S74>/Product' */
  real_T TmpSignalConversionAtSFunctionI[12];/* '<S116>/Embedded MATLAB Function1' */
  real_T TmpSignalConversionAtSFunctio_i[12];/* '<S113>/Embedded MATLAB Function' */
  real_T Switch2;                      /* '<S101>/Switch2' */
  real_T Divide1_m;                    /* '<S87>/Divide1' */
  real_T DiscreteTimeIntegrator_a[6];  /* '<S110>/Discrete-Time Integrator' */
  real_T Product1_h;                   /* '<S82>/Product1' */
  real_T Sum6[6];                      /* '<S105>/Sum6' */
  real_T Product_l;                    /* '<S82>/Product' */
  real_T Product1_b;                   /* '<S84>/Product1' */
  real_T DiscreteTimeIntegrator1_j;    /* '<S82>/Discrete-Time Integrator1' */
  real_T Product1_p;                   /* '<S80>/Product1' */
  real_T Switch_o;                     /* '<S79>/Switch' */
  real_T Product1_n;                   /* '<S83>/Product1' */
  real_T DiscreteTimeIntegrator_e;     /* '<S83>/Discrete-Time Integrator' */
  real_T Divide2;                      /* '<S79>/Divide2' */
  real_T TrigonometricFunction1;       /* '<S93>/Trigonometric Function1' */
  real_T Divide1_l;                    /* '<S98>/Divide1' */
  real_T Divide;                       /* '<S87>/Divide' */
  real_T Divide_o;                     /* '<S98>/Divide' */
  real_T shift;                        /* '<S51>/shift' */
  real_T DiscreteTimeIntegrator1_c;    /* '<S93>/Discrete-Time Integrator1' */
  int64m_T Gain_m;                     /* '<S17>/Gain' */
  int64m_T Gain2_e;                    /* '<S17>/Gain2' */
  int64m_T Gain6;                      /* '<S17>/Gain6' */
  int64m_T Gain1_e;                    /* '<S17>/Gain1' */
  int64m_T Gain3_b;                    /* '<S17>/Gain3' */
  int64m_T Gain4_m;                    /* '<S17>/Gain4' */
  real32_T Unpack_o2;                  /* '<S4>/Unpack' */
  real32_T Unpack_o3[6];               /* '<S4>/Unpack' */
  real32_T Unpack_o4[6];               /* '<S4>/Unpack' */
  real32_T Unpack_o5;                  /* '<S4>/Unpack' */
  real32_T Unpack_o1[3];               /* '<S100>/Unpack' */
  real32_T Unpack_o3_p;                /* '<S100>/Unpack' */
  real32_T Gain1_o[3];                 /* '<S13>/Gain1' */
  real32_T Unpack_o1_a;                /* '<S6>/Unpack' */
  real32_T Unpack_o2_a;                /* '<S6>/Unpack' */
  real32_T Unpack_o3_k;                /* '<S6>/Unpack' */
  real32_T Unpack_o4_n;                /* '<S6>/Unpack' */
  real32_T Unpack_o5_o;                /* '<S6>/Unpack' */
  real32_T Unpack_o6;                  /* '<S6>/Unpack' */
  real32_T Unpack;                     /* '<S8>/Unpack' */
  real32_T DataTypeConversion3;        /* '<S72>/Data Type Conversion3' */
  real32_T DataTypeConversion[6];      /* '<S99>/Data Type Conversion' */
  real32_T DataTypeConversion3_m[6];   /* '<S99>/Data Type Conversion3' */
  real32_T DataTypeConversion3_p[6];   /* '<S101>/Data Type Conversion3' */
  real32_T DataTypeConversion_b[6];    /* '<S1>/Data Type Conversion' */
  real32_T DataTypeConversion4[6];     /* '<S1>/Data Type Conversion4' */
  real32_T Gain1_g;                    /* '<S15>/Gain1' */
  real32_T Gain_j;                     /* '<S15>/Gain' */
  real32_T Sum_l;                      /* '<S15>/Sum' */
  real32_T SwitchControl_d[6];         /* '<S16>/SwitchControl' */
  real32_T DataTypeConversion3_c;      /* '<S1>/Data Type Conversion3' */
  real32_T DiscreteTimeIntegrator_ae;  /* '<S14>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_a;  /* '<S14>/Discrete-Time Integrator1' */
  real32_T DataTypeConversion3_pr;     /* '<S14>/Data Type Conversion3' */
  real32_T Product_m;                  /* '<S14>/Product' */
  real32_T DataTypeConversion2[6];     /* '<S1>/Data Type Conversion2' */
  real32_T ButterworthFilter10Hz_i[3]; /* '<S13>/Butterworth Filter 10 Hz' */
  real32_T DataTypeConversion2_o;      /* '<S14>/Data Type Conversion2' */
  real32_T Sum2_n;                     /* '<S101>/Sum2' */
  real32_T Sum_m;                      /* '<S101>/Sum' */
  real32_T Sum1_b;                     /* '<S101>/Sum1' */
  real32_T DiscreteTimeIntegrator1_be; /* '<S72>/Discrete-Time Integrator1' */
  real32_T Sum_b4;                     /* '<S14>/Sum' */
  real32_T Alpha;                      /* '<S79>/Alpha' */
  int32_T GTRTUDPRX_o6;                /* '<S4>/GT-RT UDP RX' */
  int32_T GTRTUDPRX_o6_a;              /* '<S100>/GT-RT UDP RX' */
  int32_T GTRTCANRX1_o1;               /* '<S17>/GT-RT CAN RX1' */
  int32_T GTRTCANRX2_o1;               /* '<S17>/GT-RT CAN RX2' */
  int32_T GTRTCANRX3_o1;               /* '<S17>/GT-RT CAN RX3' */
  int32_T GTRTUDPRX_o6_b;              /* '<S6>/GT-RT UDP RX' */
  int32_T GTRTUDPRX_o6_m;              /* '<S8>/GT-RT UDP RX' */
  int32_T GTRTCANRX2_o1_f;             /* '<S9>/GT-RT CAN RX2' */
  int32_T GTRTUDPTX;                   /* '<S99>/GT-RT UDP TX' */
  int32_T GTRTUDPTX1;                  /* '<S99>/GT-RT UDP TX1' */
  int32_T GTRTUDPTX2;                  /* '<S99>/GT-RT UDP TX2' */
  int32_T GTRTUDPTX_b;                 /* '<S1>/GT-RT UDP TX' */
  int32_T GTRTUDPTX1_e;                /* '<S1>/GT-RT UDP TX1' */
  int32_T Add;                         /* '<S26>/Add' */
  uint32_T GTRTUDPRX_o2;               /* '<S4>/GT-RT UDP RX' */
  uint32_T GTRTUDPRX_o2_d;             /* '<S100>/GT-RT UDP RX' */
  uint32_T GTRTCANRX1_o6;              /* '<S17>/GT-RT CAN RX1' */
  uint32_T GTRTCANRX2_o6;              /* '<S17>/GT-RT CAN RX2' */
  uint32_T GTRTCANRX3_o6;              /* '<S17>/GT-RT CAN RX3' */
  uint32_T GTRTUDPRX_o2_p;             /* '<S6>/GT-RT UDP RX' */
  uint32_T GTRTUDPRX_o2_l;             /* '<S8>/GT-RT UDP RX' */
  uint32_T GTRTCANRX2_o6_h;            /* '<S9>/GT-RT CAN RX2' */
  uint16_T GTRTUDPRX_o5;               /* '<S4>/GT-RT UDP RX' */
  uint16_T GTRTUDPRX_o5_c;             /* '<S100>/GT-RT UDP RX' */
  uint16_T GTRTUDPRX_o5_f;             /* '<S6>/GT-RT UDP RX' */
  uint16_T GTRTUDPRX_o5_g;             /* '<S8>/GT-RT UDP RX' */
  uint16_T Gain4_f;                    /* '<S26>/Gain4' */
  uint16_T Gain3_h;                    /* '<S26>/Gain3' */
  uint16_T Gain2_d;                    /* '<S26>/Gain2' */
  uint8_T GTRTUDPRX_o1[66];            /* '<S4>/GT-RT UDP RX' */
  uint8_T GTRTUDPRX_o4[4];             /* '<S4>/GT-RT UDP RX' */
  uint8_T Unpack_o1_c[10];             /* '<S4>/Unpack' */
  uint8_T GTRTUDPRX_o1_o[24];          /* '<S100>/GT-RT UDP RX' */
  uint8_T GTRTUDPRX_o4_k[4];           /* '<S100>/GT-RT UDP RX' */
  uint8_T Unpack_o2_p[8];              /* '<S100>/Unpack' */
  uint8_T Compare;                     /* '<S71>/Compare' */
  uint8_T GTRTCANRX1_o2[8];            /* '<S17>/GT-RT CAN RX1' */
  uint8_T GTRTCANRX1_o3;               /* '<S17>/GT-RT CAN RX1' */
  uint8_T GTRTCANRX1_o4;               /* '<S17>/GT-RT CAN RX1' */
  uint8_T GTRTCANRX2_o2[8];            /* '<S17>/GT-RT CAN RX2' */
  uint8_T GTRTCANRX2_o3;               /* '<S17>/GT-RT CAN RX2' */
  uint8_T GTRTCANRX2_o4;               /* '<S17>/GT-RT CAN RX2' */
  uint8_T GTRTCANRX3_o2[8];            /* '<S17>/GT-RT CAN RX3' */
  uint8_T GTRTCANRX3_o3;               /* '<S17>/GT-RT CAN RX3' */
  uint8_T GTRTCANRX3_o4;               /* '<S17>/GT-RT CAN RX3' */
  uint8_T GTRTUDPRX_o1_f[24];          /* '<S6>/GT-RT UDP RX' */
  uint8_T GTRTUDPRX_o4_b[4];           /* '<S6>/GT-RT UDP RX' */
  uint8_T GTRTUDPRX_o1_d[4];           /* '<S8>/GT-RT UDP RX' */
  uint8_T GTRTUDPRX_o4_g[4];           /* '<S8>/GT-RT UDP RX' */
  uint8_T GTRTCANRX2_o2_d[8];          /* '<S9>/GT-RT CAN RX2' */
  uint8_T GTRTCANRX2_o3_e;             /* '<S9>/GT-RT CAN RX2' */
  uint8_T GTRTCANRX2_o4_d;             /* '<S9>/GT-RT CAN RX2' */
  uint8_T BytePacking[72];             /* '<S99>/Byte Packing ' */
  uint8_T BytePacking1[24];            /* '<S99>/Byte Packing 1' */
  uint8_T BytePacking2[24];            /* '<S99>/Byte Packing 2' */
  uint8_T Gain1_p;                     /* '<S28>/Gain1' */
  uint8_T Gain2_b;                     /* '<S28>/Gain2' */
  uint8_T Gain3_i;                     /* '<S28>/Gain3' */
  uint8_T Gain4_b;                     /* '<S28>/Gain4' */
  uint8_T Gain1_a;                     /* '<S29>/Gain1' */
  uint8_T Gain2_g;                     /* '<S29>/Gain2' */
  uint8_T Gain3_be;                    /* '<S29>/Gain3' */
  uint8_T Gain4_n;                     /* '<S29>/Gain4' */
  uint8_T Gain1_n;                     /* '<S30>/Gain1' */
  uint8_T Gain2_l;                     /* '<S30>/Gain2' */
  uint8_T Gain3_ic;                    /* '<S30>/Gain3' */
  uint8_T Gain4_g;                     /* '<S30>/Gain4' */
  uint8_T Gain1_op;                    /* '<S31>/Gain1' */
  uint8_T Gain2_ga;                    /* '<S31>/Gain2' */
  uint8_T Gain3_l;                     /* '<S31>/Gain3' */
  uint8_T Gain4_c;                     /* '<S31>/Gain4' */
  uint8_T Gain1_d;                     /* '<S32>/Gain1' */
  uint8_T Gain2_f;                     /* '<S32>/Gain2' */
  uint8_T Gain3_d;                     /* '<S32>/Gain3' */
  uint8_T Gain4_k;                     /* '<S32>/Gain4' */
  uint8_T Gain1_p2;                    /* '<S33>/Gain1' */
  uint8_T Gain2_p;                     /* '<S33>/Gain2' */
  uint8_T Gain3_ha;                    /* '<S33>/Gain3' */
  uint8_T Gain4_h;                     /* '<S33>/Gain4' */
  uint8_T BytePacking_g[28];           /* '<S1>/Byte Packing ' */
  uint8_T BytePacking1_m[32];          /* '<S1>/Byte Packing 1' */
  uint8_T SumofElements;               /* '<S3>/Sum of Elements' */
  boolean_T GTRTUDPRX_o3;              /* '<S4>/GT-RT UDP RX' */
  boolean_T GTRTUDPRX_o3_o;            /* '<S100>/GT-RT UDP RX' */
  boolean_T GTRTCANRX1_o5;             /* '<S17>/GT-RT CAN RX1' */
  boolean_T GTRTCANRX2_o5;             /* '<S17>/GT-RT CAN RX2' */
  boolean_T GTRTCANRX3_o5;             /* '<S17>/GT-RT CAN RX3' */
  boolean_T GTRTUDPRX_o3_l;            /* '<S6>/GT-RT UDP RX' */
  boolean_T GTRTUDPRX_o3_d;            /* '<S8>/GT-RT UDP RX' */
  boolean_T LogicalOperator;           /* '<S72>/Logical Operator' */
  boolean_T GTRTCANRX2_o5_i;           /* '<S9>/GT-RT CAN RX2' */
  boolean_T LogicalOperator_a;         /* '<S14>/Logical Operator' */
  rtB_IfActionSubsystem1_M43_Sim_ IfActionSubsystem1_e;/* '<S57>/If Action Subsystem1' */
  rtB_IfActionSubsystem_M43_Sim_F IfActionSubsystem_d0;/* '<S57>/If Action Subsystem' */
  rtB_IfActionSubsystem1_M43_Sim_ IfActionSubsystem1_d;/* '<S56>/If Action Subsystem1' */
  rtB_IfActionSubsystem_M43_Sim_F IfActionSubsystem_e;/* '<S56>/If Action Subsystem' */
  rtB_IfActionSubsystem1_M43_Sim_ IfActionSubsystem1_p;/* '<S55>/If Action Subsystem1' */
  rtB_IfActionSubsystem_M43_Sim_F IfActionSubsystem_d;/* '<S55>/If Action Subsystem' */
  rtB_IfActionSubsystem1_M43_Sim_ IfActionSubsystem1_k;/* '<S54>/If Action Subsystem1' */
  rtB_IfActionSubsystem_M43_Sim_F IfActionSubsystem_i;/* '<S54>/If Action Subsystem' */
  rtB_IfActionSubsystem1_M43_Sim_ IfActionSubsystem1_f;/* '<S53>/If Action Subsystem1' */
  rtB_IfActionSubsystem_M43_Sim_F IfActionSubsystem_h;/* '<S53>/If Action Subsystem' */
  rtB_IfActionSubsystem1_M43_Sim_ IfActionSubsystem1;/* '<S52>/If Action Subsystem1' */
} BlockIO_M43_Sim_Forcing_003h_Trajectory;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S93>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S93>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S94>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator1_DSTAT_d;/* '<S95>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S81>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S83>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S84>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S82>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S80>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S92>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE[6];          /* '<S106>/Unit Delay' */
  real_T DiscreteTimeIntegrator1_DSTAT_l[6];/* '<S112>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_b[6];/* '<S110>/Discrete-Time Integrator' */
  real_T UnitDelay6_DSTATE[6];         /* '<S105>/Unit Delay6' */
  real_T ButterworthFilter10Hz_DSTATE[24];/* '<S10>/Butterworth Filter 10 Hz' */
  real_T DiscreteTimeIntegrator1_DSTAT_k;/* '<S93>/Discrete-Time Integrator1' */
  real_T pizetaT_transfers_DSTATE;     /* '<S98>/pi//(zeta*T_transfer)//s' */
  real_T ButterworthFilter10Hz_DSTATE_b[4];/* '<S3>/Butterworth Filter 10 Hz' */
  real_T DiscreteTimeIntegrator1_DSTA_ds;/* '<S80>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator1_DSTAT_n;/* '<S81>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S82>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator1_DSTAT_o;/* '<S83>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator1_DSTA_ko;/* '<S84>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S93>/Discrete-Time Integrator3' */
  real_T zetapiT_transfers_DSTATE;     /* '<S98>/4*zeta*pi//T_transfer //s' */
  real_T Forsavingpositionandvelocityunt;/* '<S87>/For saving position  and velocity until after switchover' */
  real_T UD_DSTATE;                    /* '<S90>/UD' */
  real_T pizetaT_transfers_DSTATE_i;   /* '<S87>/pi//(zeta*T_transfer)//s' */
  real_T zetapiT_transfers_DSTATE_p;   /* '<S87>/4*zeta*pi//T_transfer //s' */
  real_T Sum2_DWORK1;                  /* '<S6>/Sum2' */
  real_T Sum1_DWORK1[6];               /* '<S10>/Sum1' */
  real_T ButterworthFilter10Hz_tmp[6]; /* '<S10>/Butterworth Filter 10 Hz' */
  real_T PrevY;                        /* '<S20>/Acc Limiter A1' */
  real_T PrevY_n;                      /* '<S20>/Acc Limiter A2' */
  real_T PrevY_i;                      /* '<S20>/Acc Limiter A3' */
  real_T PrevY_b;                      /* '<S20>/Acc Limiter A4' */
  real_T PrevY_bp;                     /* '<S20>/Acc Limiter A5' */
  real_T PrevY_p;                      /* '<S20>/Acc Limiter A6' */
  real_T ButterworthFilter10Hz_tmp_f;  /* '<S3>/Butterworth Filter 10 Hz' */
  void *GTRTUDPRX_PWORK;               /* '<S4>/GT-RT UDP RX' */
  void *GTRTUDPRead_PWORK;             /* '<S4>/GT-RT UDP  Read' */
  void *GTRTUDPRX_PWORK_b;             /* '<S100>/GT-RT UDP RX' */
  void *GTRTUDPRead_PWORK_f;           /* '<S100>/GT-RT UDP  Read' */
  void *GTRTCANRX1_PWORK;              /* '<S17>/GT-RT CAN RX1' */
  void *GTRTCANRX2_PWORK;              /* '<S17>/GT-RT CAN RX2' */
  void *GTRTCANRX3_PWORK;              /* '<S17>/GT-RT CAN RX3' */
  void *GTRTUDPRX_PWORK_l;             /* '<S6>/GT-RT UDP RX' */
  void *GTRTUDPRead_PWORK_g;           /* '<S6>/GT-RT UDP  Read' */
  void *GTRTUDPRX_PWORK_bv;            /* '<S8>/GT-RT UDP RX' */
  void *GTRTUDPRead_PWORK_l;           /* '<S8>/GT-RT UDP  Read' */
  struct {
    void *LoggedData;
  } INC_Comparison_PWORK;              /* '<Root>/INC_Comparison' */

  struct {
    void *LoggedData;
  } J_ANG_ERROR_PWORK;                 /* '<S12>/J_ANG_ERROR' */

  struct {
    void *LoggedData;
  } ANG_ACT_PWORK;                     /* '<S12>/ANG_ACT' */

  struct {
    void *LoggedData;
  } POS_ACT_PWORK;                     /* '<S12>/POS_ACT' */

  struct {
    void *LoggedData;
  } ANGCOM_PWORK;                      /* '<S12>/ANG COM' */

  struct {
    void *LoggedData;
  } POSCOM_PWORK;                      /* '<S12>/POS COM' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S92>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S106>/Scope1' */

  void *GTRTCANRX2_PWORK_a;            /* '<S9>/GT-RT CAN RX2' */
  void *GTRTCANController_PWORK;       /* '<Root>/GT-RT CAN Controller' */
  void *GTRTCANTX_PWORK;               /* '<S103>/GT-RT CAN TX' */
  void *GTRTCANTX_PWORK_l;             /* '<S102>/GT-RT CAN TX' */
  void *GTRTUDPTX_PWORK[2];            /* '<S99>/GT-RT UDP TX' */
  void *GTRTUDPTX1_PWORK[2];           /* '<S99>/GT-RT UDP TX1' */
  void *GTRTUDPTX2_PWORK[2];           /* '<S99>/GT-RT UDP TX2' */
  void *GTRTUDPWrite_PWORK;            /* '<S99>/GT-RT UDP  Write' */
  void *GTRTUDPWrite1_PWORK;           /* '<S99>/GT-RT UDP  Write1' */
  void *GTRTUDPWrite2_PWORK;           /* '<S99>/GT-RT UDP  Write2' */
  void *GTRTCANTX_PWORK_j;             /* '<S27>/GT-RT CAN TX' */
  void *GTRTCANTX1_PWORK;              /* '<S27>/GT-RT CAN TX1' */
  void *GTRTCANTX2_PWORK;              /* '<S27>/GT-RT CAN TX2' */
  void *GTRTUDPTX_PWORK_o[2];          /* '<S1>/GT-RT UDP TX' */
  void *GTRTUDPTX1_PWORK_f[2];         /* '<S1>/GT-RT UDP TX1' */
  void *GTRTUDPWrite_PWORK_m;          /* '<S1>/GT-RT UDP  Write' */
  void *GTRTUDPWrite1_PWORK_j;         /* '<S1>/GT-RT UDP  Write1' */
  real32_T ButterworthFilter10Hz_DSTATE_a[12];/* '<S13>/Butterworth Filter 10 Hz' */
  real32_T DiscreteTimeIntegrator1_DSTAT_g;/* '<S72>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S14>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_f;/* '<S14>/Discrete-Time Integrator1' */
  real32_T ButterworthFilter10Hz_tmp_p[3];/* '<S13>/Butterworth Filter 10 Hz' */
  uint32_T Add_DWORK1;                 /* '<S21>/Add' */
  int_T GTRTUDPRX_IWORK;               /* '<S4>/GT-RT UDP RX' */
  int_T GTRTUDPRX_IWORK_a;             /* '<S100>/GT-RT UDP RX' */
  int_T GTRTUDPRX_IWORK_j;             /* '<S6>/GT-RT UDP RX' */
  int_T GTRTUDPRX_IWORK_p;             /* '<S8>/GT-RT UDP RX' */
  int_T BytePacking_IWORK[10];         /* '<S99>/Byte Packing ' */
  int_T BytePacking1_IWORK[2];         /* '<S99>/Byte Packing 1' */
  int_T BytePacking2_IWORK[2];         /* '<S99>/Byte Packing 2' */
  int_T BytePacking_IWORK_m[4];        /* '<S1>/Byte Packing ' */
  int_T BytePacking1_IWORK_e[6];       /* '<S1>/Byte Packing 1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S93>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator2_PrevRes;/* '<S93>/Discrete-Time Integrator2' */
  int8_T MoveUP1_SubsysRanBC;          /* '<S3>/Move UP1' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S94>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_p;/* '<S95>/Discrete-Time Integrator1' */
  int8_T _DOFControl_SubsysRanBC;      /* '<S5>/6_DOF Control' */
  int8_T SimplifiedInverseKin_SubsysRanB;/* '<S112>/Simplified Inverse Kin' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S112>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_d;/* '<S110>/Discrete-Time Integrator' */
  int8_T fullinversekin_SubsysRanBC;   /* '<S110>/full inverse kin' */
  int8_T _DOFVisualCab120615_SubsysRanBC;/* '<Root>/6_DOF Visual Cab 12//06//15' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S52>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S18>/If Action Subsystem1' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S93>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator1_PrevR_f;/* '<S72>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator3_PrevRes;/* '<S93>/Discrete-Time Integrator3' */
  int8_T IfActionSubsystem_SubsysRanBC_p;/* '<S9>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_l;/* '<S9>/If Action Subsystem1' */
  int8_T pizetaT_transfers_PrevResetStat;/* '<S87>/pi//(zeta*T_transfer)//s' */
  int8_T zetapiT_transfers_PrevResetStat;/* '<S87>/4*zeta*pi//T_transfer //s' */
  int8_T DiscreteTimeIntegrator1_PrevR_c;/* '<S14>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S112>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S110>/Discrete-Time Integrator' */
  uint8_T is_active_c7_M43_Sim_Forcing_00;/* '<S116>/Embedded MATLAB Function1' */
  uint8_T is_active_c6_M43_Sim_Forcing_00;/* '<S113>/Embedded MATLAB Function' */
  uint8_T is_active_c5_M43_Sim_Forcing_00;/* '<S104>/Embedded MATLAB Function' */
  uint8_T is_active_c10_M43_Sim_Forcing_0;/* '<S93>/Natural Speed Down' */
  uint8_T is_active_c2_M43_Sim_Forcing_00;/* '<S92>/Exp_saturation' */
  uint8_T pizetaT_transfers_IC_LOADING;/* '<S87>/pi//(zeta*T_transfer)//s' */
  uint8_T zetapiT_transfers_IC_LOADING;/* '<S87>/4*zeta*pi//T_transfer //s' */
  uint8_T is_active_c8_M43_Sim_Forcing_00;/* '<S73>/curve' */
  uint8_T is_active_c1_M43_Sim_Forcing_00;/* '<S88>/Embedded MATLAB Function' */
  uint8_T is_active_c4_M43_Sim_Forcing_00;/* '<S79>/Get R' */
  uint8_T is_active_c3_M43_Sim_Forcing_00;/* '<S78>/Embedded MATLAB Function' */
  boolean_T isStable;                  /* '<S116>/Embedded MATLAB Function1' */
  boolean_T doneDoubleBufferReInit;    /* '<S116>/Embedded MATLAB Function1' */
  boolean_T isStable_f;                /* '<S113>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_j;  /* '<S113>/Embedded MATLAB Function' */
  boolean_T isStable_fp;               /* '<S104>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_o;  /* '<S104>/Embedded MATLAB Function' */
  boolean_T isStable_m;                /* '<S93>/Natural Speed Down' */
  boolean_T doneDoubleBufferReInit_jd; /* '<S93>/Natural Speed Down' */
  boolean_T isStable_fz;               /* '<S92>/Exp_saturation' */
  boolean_T doneDoubleBufferReInit_e;  /* '<S92>/Exp_saturation' */
  boolean_T isStable_m5;               /* '<S73>/curve' */
  boolean_T doneDoubleBufferReInit_k;  /* '<S73>/curve' */
  boolean_T isStable_l;                /* '<S88>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_c;  /* '<S88>/Embedded MATLAB Function' */
  boolean_T isStable_fk;               /* '<S79>/Get R' */
  boolean_T doneDoubleBufferReInit_m;  /* '<S79>/Get R' */
  boolean_T isStable_a;                /* '<S78>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_n;  /* '<S78>/Embedded MATLAB Function' */
  rtDW_IfActionSubsystem1_M43_Sim IfActionSubsystem1_e;/* '<S57>/If Action Subsystem1' */
  rtDW_IfActionSubsystem_M43_Sim_ IfActionSubsystem_d0;/* '<S57>/If Action Subsystem' */
  rtDW_IfActionSubsystem1_M43_Sim IfActionSubsystem1_d;/* '<S56>/If Action Subsystem1' */
  rtDW_IfActionSubsystem_M43_Sim_ IfActionSubsystem_e;/* '<S56>/If Action Subsystem' */
  rtDW_IfActionSubsystem1_M43_Sim IfActionSubsystem1_p;/* '<S55>/If Action Subsystem1' */
  rtDW_IfActionSubsystem_M43_Sim_ IfActionSubsystem_d;/* '<S55>/If Action Subsystem' */
  rtDW_IfActionSubsystem1_M43_Sim IfActionSubsystem1_k;/* '<S54>/If Action Subsystem1' */
  rtDW_IfActionSubsystem_M43_Sim_ IfActionSubsystem_i;/* '<S54>/If Action Subsystem' */
  rtDW_IfActionSubsystem1_M43_Sim IfActionSubsystem1_f;/* '<S53>/If Action Subsystem1' */
  rtDW_IfActionSubsystem_M43_Sim_ IfActionSubsystem_h;/* '<S53>/If Action Subsystem' */
  rtDW_IfActionSubsystem1_M43_Sim IfActionSubsystem1;/* '<S52>/If Action Subsystem1' */
} D_Work_M43_Sim_Forcing_003h_Trajectory;

/* Backward compatible GRT Identifiers */
#define rtB                            M43_Sim_Forcing_003h_Trajectory_B
#define BlockIO                        BlockIO_M43_Sim_Forcing_003h_Trajectory
#define rtXdot                         M43_Sim_Forcing_003h_Trajectory_Xdot
#define StateDerivatives               StateDerivatives_M43_Sim_Forcing_003h_Trajectory
#define tXdis                          M43_Sim_Forcing_003h_Trajectory_Xdis
#define StateDisabled                  StateDisabled_M43_Sim_Forcing_003h_Trajectory
#define rtP                            M43_Sim_Forcing_003h_Trajectory_P
#define Parameters                     Parameters_M43_Sim_Forcing_003h_Trajectory
#define rtDWork                        M43_Sim_Forcing_003h_Trajectory_DWork
#define D_Work                         D_Work_M43_Sim_Forcing_003h_Trajectory

/* Parameters for system: '<S52>/If Action Subsystem1' */
struct rtP_IfActionSubsystem1_M43_Sim__ {
  real_T PSEA2_Value;                  /* Expression: 0
                                        * Referenced by: '<S59>/PSEA2'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S59>/Switch'
                                        */
};

/* Parameters for system: '<S53>/If Action Subsystem' */
struct rtP_IfActionSubsystem_M43_Sim_F_ {
  real_T PSEA2_Value;                  /* Expression: 0
                                        * Referenced by: '<S60>/PSEA2'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S60>/Switch'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_M43_Sim_Forcing_003h_Trajectory_ {
  real_T GTRTUDPRX_P1_Size[2];         /* Computed Parameter: GTRTUDPRX_P1_Size
                                        * Referenced by: '<S4>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P1[29];             /* Computed Parameter: GTRTUDPRX_P1
                                        * Referenced by: '<S4>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P2_Size[2];         /* Computed Parameter: GTRTUDPRX_P2_Size
                                        * Referenced by: '<S4>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P2;                 /* Expression: receive_buffer_size
                                        * Referenced by: '<S4>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P3_Size[2];         /* Computed Parameter: GTRTUDPRX_P3_Size
                                        * Referenced by: '<S4>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P3;                 /* Expression: timeout
                                        * Referenced by: '<S4>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P4_Size[2];         /* Computed Parameter: GTRTUDPRX_P4_Size
                                        * Referenced by: '<S4>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P4;                 /* Expression: sample_time
                                        * Referenced by: '<S4>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRead_P1_Size[2];       /* Computed Parameter: GTRTUDPRead_P1_Size
                                        * Referenced by: '<S4>/GT-RT UDP  Read'
                                        */
  real_T GTRTUDPRead_P1[29];           /* Computed Parameter: GTRTUDPRead_P1
                                        * Referenced by: '<S4>/GT-RT UDP  Read'
                                        */
  real_T GTRTUDPRX_P1_Size_i[2];       /* Computed Parameter: GTRTUDPRX_P1_Size_i
                                        * Referenced by: '<S100>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P1_i[29];           /* Computed Parameter: GTRTUDPRX_P1_i
                                        * Referenced by: '<S100>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P2_Size_m[2];       /* Computed Parameter: GTRTUDPRX_P2_Size_m
                                        * Referenced by: '<S100>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P2_a;               /* Expression: receive_buffer_size
                                        * Referenced by: '<S100>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P3_Size_f[2];       /* Computed Parameter: GTRTUDPRX_P3_Size_f
                                        * Referenced by: '<S100>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P3_e;               /* Expression: timeout
                                        * Referenced by: '<S100>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P4_Size_j[2];       /* Computed Parameter: GTRTUDPRX_P4_Size_j
                                        * Referenced by: '<S100>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P4_c;               /* Expression: sample_time
                                        * Referenced by: '<S100>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRead_P1_Size_c[2];     /* Computed Parameter: GTRTUDPRead_P1_Size_c
                                        * Referenced by: '<S100>/GT-RT UDP  Read'
                                        */
  real_T GTRTUDPRead_P1_o[29];         /* Computed Parameter: GTRTUDPRead_P1_o
                                        * Referenced by: '<S100>/GT-RT UDP  Read'
                                        */
  real_T x_e2_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/x_e2'
                                        */
  real_T x_e1_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/x_e1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S93>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: -1100
                                        * Referenced by: '<S93>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                          * Referenced by: '<S93>/Discrete-Time Integrator2'
                                          */
  real_T DiscreteTimeIntegrator2_IC;   /* Expression: 0
                                        * Referenced by: '<S93>/Discrete-Time Integrator2'
                                        */
  real_T y_e1_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/y_e1'
                                        */
  real_T TargetPSI_Value;              /* Expression: -90
                                        * Referenced by: '<S3>/Target PSI'
                                        */
  real_T Constant1_Value;              /* Expression: 3
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T newmidpoint_Value;            /* Expression: 141.15
                                        * Referenced by: '<S3>/new mid point'
                                        */
  real_T Nominalmidpointcheckwithselecte;/* Expression: 141.15
                                          * Referenced by: '<S3>/Nominal mid point //!\ check with selected set'
                                          */
  real_T z_e1_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/z_e1'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S94>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S94>/Discrete-Time Integrator1'
                                        */
  real_T Phi1_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/Phi1'
                                        */
  real_T Theta1_Value;                 /* Expression: 0
                                        * Referenced by: '<S3>/Theta1'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_i;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_i
                                          * Referenced by: '<S95>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_m; /* Expression: 0
                                        * Referenced by: '<S95>/Discrete-Time Integrator1'
                                        */
  real_T y_e2_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/y_e2'
                                        */
  real_T GTRTCANRX1_P1_Size[2];        /* Computed Parameter: GTRTCANRX1_P1_Size
                                        * Referenced by: '<S17>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P1[32];            /* Computed Parameter: GTRTCANRX1_P1
                                        * Referenced by: '<S17>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P2_Size[2];        /* Computed Parameter: GTRTCANRX1_P2_Size
                                        * Referenced by: '<S17>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P2;                /* Expression: receive_all_can_ids
                                        * Referenced by: '<S17>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P3_Size[2];        /* Computed Parameter: GTRTCANRX1_P3_Size
                                        * Referenced by: '<S17>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P3;                /* Expression: can_id
                                        * Referenced by: '<S17>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P4_Size[2];        /* Computed Parameter: GTRTCANRX1_P4_Size
                                        * Referenced by: '<S17>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P4;                /* Expression: sample_time
                                        * Referenced by: '<S17>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX2_P1_Size[2];        /* Computed Parameter: GTRTCANRX2_P1_Size
                                        * Referenced by: '<S17>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P1[32];            /* Computed Parameter: GTRTCANRX2_P1
                                        * Referenced by: '<S17>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P2_Size[2];        /* Computed Parameter: GTRTCANRX2_P2_Size
                                        * Referenced by: '<S17>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P2;                /* Expression: receive_all_can_ids
                                        * Referenced by: '<S17>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P3_Size[2];        /* Computed Parameter: GTRTCANRX2_P3_Size
                                        * Referenced by: '<S17>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P3;                /* Expression: can_id
                                        * Referenced by: '<S17>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P4_Size[2];        /* Computed Parameter: GTRTCANRX2_P4_Size
                                        * Referenced by: '<S17>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P4;                /* Expression: sample_time
                                        * Referenced by: '<S17>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX3_P1_Size[2];        /* Computed Parameter: GTRTCANRX3_P1_Size
                                        * Referenced by: '<S17>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P1[32];            /* Computed Parameter: GTRTCANRX3_P1
                                        * Referenced by: '<S17>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P2_Size[2];        /* Computed Parameter: GTRTCANRX3_P2_Size
                                        * Referenced by: '<S17>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P2;                /* Expression: receive_all_can_ids
                                        * Referenced by: '<S17>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P3_Size[2];        /* Computed Parameter: GTRTCANRX3_P3_Size
                                        * Referenced by: '<S17>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P3;                /* Expression: can_id
                                        * Referenced by: '<S17>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P4_Size[2];        /* Computed Parameter: GTRTCANRX3_P4_Size
                                        * Referenced by: '<S17>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P4;                /* Expression: sample_time
                                        * Referenced by: '<S17>/GT-RT CAN RX3'
                                        */
  real_T Gain_Gain[6];                 /* Expression: [1 -1 -1 -1 -1 -1]
                                        * Referenced by: '<S109>/Gain'
                                        */
  real_T Constant_Value[6];            /* Expression: [0 0 0 0 0 15.89]
                                        * Referenced by: '<S109>/Constant'
                                        */
  real_T GTRTUDPRX_P1_Size_n[2];       /* Computed Parameter: GTRTUDPRX_P1_Size_n
                                        * Referenced by: '<S6>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P1_n[29];           /* Computed Parameter: GTRTUDPRX_P1_n
                                        * Referenced by: '<S6>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P2_Size_l[2];       /* Computed Parameter: GTRTUDPRX_P2_Size_l
                                        * Referenced by: '<S6>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P2_i;               /* Expression: receive_buffer_size
                                        * Referenced by: '<S6>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P3_Size_p[2];       /* Computed Parameter: GTRTUDPRX_P3_Size_p
                                        * Referenced by: '<S6>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P3_j;               /* Expression: timeout
                                        * Referenced by: '<S6>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P4_Size_n[2];       /* Computed Parameter: GTRTUDPRX_P4_Size_n
                                        * Referenced by: '<S6>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P4_g;               /* Expression: sample_time
                                        * Referenced by: '<S6>/GT-RT UDP RX'
                                        */
  real_T Constant2_Value;              /* Expression: -8000
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Constant_Value_h;             /* Expression: -6000
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value_l;            /* Expression: -499.6
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T GTRTUDPRead_P1_Size_p[2];     /* Computed Parameter: GTRTUDPRead_P1_Size_p
                                        * Referenced by: '<S6>/GT-RT UDP  Read'
                                        */
  real_T GTRTUDPRead_P1_ob[29];        /* Computed Parameter: GTRTUDPRead_P1_ob
                                        * Referenced by: '<S6>/GT-RT UDP  Read'
                                        */
  real_T GTRTUDPRX_P1_Size_o[2];       /* Computed Parameter: GTRTUDPRX_P1_Size_o
                                        * Referenced by: '<S8>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P1_j[29];           /* Computed Parameter: GTRTUDPRX_P1_j
                                        * Referenced by: '<S8>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P2_Size_c[2];       /* Computed Parameter: GTRTUDPRX_P2_Size_c
                                        * Referenced by: '<S8>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P2_c;               /* Expression: receive_buffer_size
                                        * Referenced by: '<S8>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P3_Size_d[2];       /* Computed Parameter: GTRTUDPRX_P3_Size_d
                                        * Referenced by: '<S8>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P3_eq;              /* Expression: timeout
                                        * Referenced by: '<S8>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P4_Size_c[2];       /* Computed Parameter: GTRTUDPRX_P4_Size_c
                                        * Referenced by: '<S8>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P4_m;               /* Expression: sample_time
                                        * Referenced by: '<S8>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRead_P1_Size_d[2];     /* Computed Parameter: GTRTUDPRead_P1_Size_d
                                        * Referenced by: '<S8>/GT-RT UDP  Read'
                                        */
  real_T GTRTUDPRead_P1_h[29];         /* Computed Parameter: GTRTUDPRead_P1_h
                                        * Referenced by: '<S8>/GT-RT UDP  Read'
                                        */
  real_T x_e_Value;                    /* Expression: 0
                                        * Referenced by: '<S3>/x_e'
                                        */
  real_T DiscreteTimeIntegrator_gainva_e;/* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                          * Referenced by: '<S81>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_d;  /* Expression: 0
                                        * Referenced by: '<S81>/Discrete-Time Integrator'
                                        */
  real_T fromcmtom_Gain;               /* Expression: 100
                                        * Referenced by: '<S75>/from cm to m'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                          * Referenced by: '<S83>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_o;  /* Expression: 0
                                        * Referenced by: '<S83>/Discrete-Time Integrator'
                                        */
  real_T fromcmtom_Gain_d;             /* Expression: 100
                                        * Referenced by: '<S76>/from cm to m'
                                        */
  real_T y_e_Value;                    /* Expression: 0
                                        * Referenced by: '<S3>/y_e'
                                        */
  real_T z_e_Value;                    /* Expression: 0
                                        * Referenced by: '<S3>/z_e'
                                        */
  real_T DiscreteTimeIntegrator_gainva_f;/* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                                          * Referenced by: '<S84>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_h;  /* Expression: 0
                                        * Referenced by: '<S84>/Discrete-Time Integrator'
                                        */
  real_T fromcmtom_Gain_n;             /* Expression: 100
                                        * Referenced by: '<S77>/from cm to m'
                                        */
  real_T DiscreteTimeIntegrator_gainv_ex;/* Computed Parameter: DiscreteTimeIntegrator_gainv_ex
                                          * Referenced by: '<S82>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S82>/Discrete-Time Integrator'
                                        */
  real_T Gain1_Gain;                   /* Expression: -180/pi
                                        * Referenced by: '<S76>/Gain1'
                                        */
  real_T Phi_Value;                    /* Expression: 0
                                        * Referenced by: '<S3>/Phi'
                                        */
  real_T DiscreteTimeIntegrator_gainv_jz;/* Computed Parameter: DiscreteTimeIntegrator_gainv_jz
                                          * Referenced by: '<S80>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_f;  /* Expression: 0
                                        * Referenced by: '<S80>/Discrete-Time Integrator'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: 180/pi
                                        * Referenced by: '<S75>/Gain1'
                                        */
  real_T Theta_Value;                  /* Expression: 0
                                        * Referenced by: '<S3>/Theta'
                                        */
  real_T AllowedPsi_Value;             /* Expression: 150
                                        * Referenced by: '<S70>/Allowed Psi'
                                        */
  real_T forenable_Value;              /* Expression: 0
                                        * Referenced by: '<S70>/1 for enable'
                                        */
  real_T DiscreteTimeIntegrator_gainva_l;/* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                          * Referenced by: '<S92>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_g;  /* Expression: 0
                                        * Referenced by: '<S92>/Discrete-Time Integrator'
                                        */
  real_T Psi_Value;                    /* Expression: 0
                                        * Referenced by: '<S3>/Psi'
                                        */
  real_T UnitDelay_X0[6];              /* Expression: [0 50 -68 0 18 0]'
                                        * Referenced by: '<S106>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_a;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_a
                                          * Referenced by: '<S112>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator_gainva_k;/* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                          * Referenced by: '<S110>/Discrete-Time Integrator'
                                          */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S106>/Switch'
                                        */
  real_T Gain_Gain_p[6];               /* Expression: [1 -1 -1 -1 -1 -1]
                                        * Referenced by: '<S111>/Gain'
                                        */
  real_T Constant_Value_k[6];          /* Expression: [0 0 0 0 0 15.89]
                                        * Referenced by: '<S111>/Constant'
                                        */
  real_T PSEA1_Value;                  /* Expression: 160
                                        * Referenced by: '<S52>/PSEA1'
                                        */
  real_T UnitDelay6_X0[6];             /* Expression: [0 50 -68 0 18 0]'
                                        * Referenced by: '<S105>/Unit Delay6'
                                        */
  real_T Gain_Value;                   /* Expression: 2
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 0.004
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T ButterworthFilter10Hz_InitialSt;/* Expression: 0
                                          * Referenced by: '<S10>/Butterworth Filter 10 Hz'
                                          */
  real_T ButterworthFilter10Hz_Numerator[5];/* Expression: [0.000183216023369   0.000732864093478   0.001099296140221   0.000732864093475   0.000183216023371]
                                             * Referenced by: '<S10>/Butterworth Filter 10 Hz'
                                             */
  real_T ButterworthFilter10Hz_Denominat[5];/* Expression: [1.000000000000000  -3.344067837711873   4.238863950884063  -2.409342856586317   0.517478199788040
                                               ]
                                             * Referenced by: '<S10>/Butterworth Filter 10 Hz'
                                             */
  real_T NSEA1_Value;                  /* Expression: -160
                                        * Referenced by: '<S52>/NSEA1'
                                        */
  real_T VelLimiterA1_UpperSat;        /* Expression: 68.34
                                        * Referenced by: '<S20>/Vel Limiter A1'
                                        */
  real_T VelLimiterA1_LowerSat;        /* Expression: -68.34
                                        * Referenced by: '<S20>/Vel Limiter A1'
                                        */
  real_T AccLimiterA1_RisingLim;       /* Computed Parameter: AccLimiterA1_RisingLim
                                        * Referenced by: '<S20>/Acc Limiter A1'
                                        */
  real_T AccLimiterA1_FallingLim;      /* Computed Parameter: AccLimiterA1_FallingLim
                                        * Referenced by: '<S20>/Acc Limiter A1'
                                        */
  real_T AccLimiterA1_IC;              /* Expression: 0
                                        * Referenced by: '<S20>/Acc Limiter A1'
                                        */
  real_T PSEA1_Value_k;                /* Expression: 20
                                        * Referenced by: '<S53>/PSEA1'
                                        */
  real_T NSEA1_Value_l;                /* Expression: -130
                                        * Referenced by: '<S53>/NSEA1'
                                        */
  real_T VelLimiterA2_UpperSat;        /* Expression: 57
                                        * Referenced by: '<S20>/Vel Limiter A2'
                                        */
  real_T VelLimiterA2_LowerSat;        /* Expression: -57
                                        * Referenced by: '<S20>/Vel Limiter A2'
                                        */
  real_T AccLimiterA2_RisingLim;       /* Computed Parameter: AccLimiterA2_RisingLim
                                        * Referenced by: '<S20>/Acc Limiter A2'
                                        */
  real_T AccLimiterA2_FallingLim;      /* Computed Parameter: AccLimiterA2_FallingLim
                                        * Referenced by: '<S20>/Acc Limiter A2'
                                        */
  real_T AccLimiterA2_IC;              /* Expression: 0
                                        * Referenced by: '<S20>/Acc Limiter A2'
                                        */
  real_T PSEA1_Value_j;                /* Expression: 88
                                        * Referenced by: '<S54>/PSEA1'
                                        */
  real_T NSEA1_Value_d;                /* Expression: -88
                                        * Referenced by: '<S54>/NSEA1'
                                        */
  real_T VelLimiterA3_UpperSat;        /* Expression: 69
                                        * Referenced by: '<S20>/Vel Limiter A3'
                                        */
  real_T VelLimiterA3_LowerSat;        /* Expression: -69
                                        * Referenced by: '<S20>/Vel Limiter A3'
                                        */
  real_T AccLimiterA3_RisingLim;       /* Computed Parameter: AccLimiterA3_RisingLim
                                        * Referenced by: '<S20>/Acc Limiter A3'
                                        */
  real_T AccLimiterA3_FallingLim;      /* Computed Parameter: AccLimiterA3_FallingLim
                                        * Referenced by: '<S20>/Acc Limiter A3'
                                        */
  real_T AccLimiterA3_IC;              /* Expression: 0
                                        * Referenced by: '<S20>/Acc Limiter A3'
                                        */
  real_T PSEA1_Value_c;                /* Expression: 350
                                        * Referenced by: '<S55>/PSEA1'
                                        */
  real_T NSEA1_Value_p;                /* Expression: -350
                                        * Referenced by: '<S55>/NSEA1'
                                        */
  real_T VelLimiterA4_UpperSat;        /* Expression: 76
                                        * Referenced by: '<S20>/Vel Limiter A4'
                                        */
  real_T VelLimiterA4_LowerSat;        /* Expression: -76
                                        * Referenced by: '<S20>/Vel Limiter A4'
                                        */
  real_T AccLimiterA4_RisingLim;       /* Computed Parameter: AccLimiterA4_RisingLim
                                        * Referenced by: '<S20>/Acc Limiter A4'
                                        */
  real_T AccLimiterA4_FallingLim;      /* Computed Parameter: AccLimiterA4_FallingLim
                                        * Referenced by: '<S20>/Acc Limiter A4'
                                        */
  real_T AccLimiterA4_IC;              /* Expression: 0
                                        * Referenced by: '<S20>/Acc Limiter A4'
                                        */
  real_T PSEA1_Value_n;                /* Expression: 61
                                        * Referenced by: '<S56>/PSEA1'
                                        */
  real_T NSEA1_Value_i;                /* Expression: -61
                                        * Referenced by: '<S56>/NSEA1'
                                        */
  real_T VelLimiter3_UpperSat;         /* Expression: 76
                                        * Referenced by: '<S20>/Vel Limiter3'
                                        */
  real_T VelLimiter3_LowerSat;         /* Expression: -76
                                        * Referenced by: '<S20>/Vel Limiter3'
                                        */
  real_T AccLimiterA5_RisingLim;       /* Computed Parameter: AccLimiterA5_RisingLim
                                        * Referenced by: '<S20>/Acc Limiter A5'
                                        */
  real_T AccLimiterA5_FallingLim;      /* Computed Parameter: AccLimiterA5_FallingLim
                                        * Referenced by: '<S20>/Acc Limiter A5'
                                        */
  real_T AccLimiterA5_IC;              /* Expression: 0
                                        * Referenced by: '<S20>/Acc Limiter A5'
                                        */
  real_T PSEA1_Value_nt;               /* Expression: 350
                                        * Referenced by: '<S57>/PSEA1'
                                        */
  real_T NSEA1_Value_m;                /* Expression: -350
                                        * Referenced by: '<S57>/NSEA1'
                                        */
  real_T VelLimiter6_UpperSat;         /* Expression: 120
                                        * Referenced by: '<S20>/Vel Limiter6'
                                        */
  real_T VelLimiter6_LowerSat;         /* Expression: -120
                                        * Referenced by: '<S20>/Vel Limiter6'
                                        */
  real_T AccLimiterA6_RisingLim;       /* Computed Parameter: AccLimiterA6_RisingLim
                                        * Referenced by: '<S20>/Acc Limiter A6'
                                        */
  real_T AccLimiterA6_FallingLim;      /* Computed Parameter: AccLimiterA6_FallingLim
                                        * Referenced by: '<S20>/Acc Limiter A6'
                                        */
  real_T AccLimiterA6_IC;              /* Expression: 0
                                        * Referenced by: '<S20>/Acc Limiter A6'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 1e8
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 1e8
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1e8
                                        * Referenced by: '<S18>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1e8
                                        * Referenced by: '<S18>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1e8
                                        * Referenced by: '<S18>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1e8
                                        * Referenced by: '<S18>/Gain5'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_j;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_j
                                          * Referenced by: '<S93>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_p; /* Expression: 0
                                        * Referenced by: '<S93>/Discrete-Time Integrator1'
                                        */
  real_T fromcmtom_Gain_h;             /* Expression: 0.01
                                        * Referenced by: '<S74>/from cm to m'
                                        */
  real_T pizetaT_transfers_gainval;    /* Computed Parameter: pizetaT_transfers_gainval
                                        * Referenced by: '<S98>/pi//(zeta*T_transfer)//s'
                                        */
  real_T pizetaT_transfers_IC;         /* Expression: 0
                                        * Referenced by: '<S98>/pi//(zeta*T_transfer)//s'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: pi/180
                                        * Referenced by: '<S74>/Gain1'
                                        */
  real_T ButterworthFilter10Hz_Initial_f;/* Expression: 0
                                          * Referenced by: '<S3>/Butterworth Filter 10 Hz'
                                          */
  real_T ButterworthFilter10Hz_Numerat_a[5];/* Expression: [0.000183216023369   0.000732864093478   0.001099296140221   0.000732864093475   0.000183216023371]
                                             * Referenced by: '<S3>/Butterworth Filter 10 Hz'
                                             */
  real_T ButterworthFilter10Hz_Denomin_p[5];/* Expression: [1.000000000000000  -3.344067837711873   4.238863950884063  -2.409342856586317   0.517478199788040
                                               ]
                                             * Referenced by: '<S3>/Butterworth Filter 10 Hz'
                                             */
  real_T Constant_Value_o[3];          /* Expression: zeros(3,1)
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 1
                                        * Referenced by: '<S79>/Switch'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 1/9.81
                                        * Referenced by: '<S75>/Gain'
                                        */
  real_T Gain3_Gain_i;                 /* Expression: sqrt(2)
                                        * Referenced by: '<S75>/Gain3'
                                        */
  real_T DiscreteTimeIntegrator1_gain_a4;/* Computed Parameter: DiscreteTimeIntegrator1_gain_a4
                                          * Referenced by: '<S80>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_k; /* Expression: 0
                                        * Referenced by: '<S80>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_p;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_p
                                          * Referenced by: '<S81>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_kd;/* Expression: 0
                                        * Referenced by: '<S81>/Discrete-Time Integrator1'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 1/9.81
                                        * Referenced by: '<S76>/Gain'
                                        */
  real_T Gain3_Gain_g;                 /* Expression: sqrt(2)
                                        * Referenced by: '<S76>/Gain3'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_f;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_f
                                          * Referenced by: '<S82>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_pa;/* Expression: 0
                                        * Referenced by: '<S82>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_g;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_g
                                          * Referenced by: '<S83>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_n; /* Expression: 0
                                        * Referenced by: '<S83>/Discrete-Time Integrator1'
                                        */
  real_T Gain3_Gain_m;                 /* Expression: sqrt(2)
                                        * Referenced by: '<S77>/Gain3'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_h;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_h
                                          * Referenced by: '<S84>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_b; /* Expression: 0
                                        * Referenced by: '<S84>/Discrete-Time Integrator1'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 1
                                        * Referenced by: '<S92>/Gain1'
                                        */
  real_T x_max_Value;                  /* Expression: 8
                                        * Referenced by: '<S92>/x_max'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 0.25
                                        * Referenced by: '<S92>/Gain'
                                        */
  real_T Gain_Gain_j;                  /* Expression: pi/180
                                        * Referenced by: '<S74>/Gain'
                                        */
  real_T Constant_Value_hu;            /* Expression: 0.4
                                        * Referenced by: '<S93>/Constant'
                                        */
  real_T Constant1_Value_g;            /* Expression: 1
                                        * Referenced by: '<S93>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator3_gainval;/* Computed Parameter: DiscreteTimeIntegrator3_gainval
                                          * Referenced by: '<S93>/Discrete-Time Integrator3'
                                          */
  real_T DiscreteTimeIntegrator3_IC;   /* Expression: 0
                                        * Referenced by: '<S93>/Discrete-Time Integrator3'
                                        */
  real_T frommtocm_Gain;               /* Expression: 100
                                        * Referenced by: '<S93>/from m to cm'
                                        */
  real_T frommtocm_Gain_i;             /* Expression: 100
                                        * Referenced by: '<S94>/from m to cm'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S95>/Constant'
                                        */
  real_T zetapiT_transfers_gainval;    /* Computed Parameter: zetapiT_transfers_gainval
                                        * Referenced by: '<S98>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapiT_transfers_IC;         /* Expression: 0
                                        * Referenced by: '<S98>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain;                  /* Expression: 3.2*pi
                                        * Referenced by: '<S98>/4*zeta*pi'
                                        */
  real_T pizeta_Gain;                  /* Expression: pi/0.8
                                        * Referenced by: '<S98>/pi//zeta'
                                        */
  real_T Gain_Gain_i;                  /* Expression: -0.1
                                        * Referenced by: '<S110>/Gain'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: -0.1
                                        * Referenced by: '<S112>/Gain1'
                                        */
  real_T GTRTCANRX2_P1_Size_o[2];      /* Computed Parameter: GTRTCANRX2_P1_Size_o
                                        * Referenced by: '<S9>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P1_g[32];          /* Computed Parameter: GTRTCANRX2_P1_g
                                        * Referenced by: '<S9>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P2_Size_b[2];      /* Computed Parameter: GTRTCANRX2_P2_Size_b
                                        * Referenced by: '<S9>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P2_e;              /* Expression: receive_all_can_ids
                                        * Referenced by: '<S9>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P3_Size_p[2];      /* Computed Parameter: GTRTCANRX2_P3_Size_p
                                        * Referenced by: '<S9>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P3_e;              /* Expression: can_id
                                        * Referenced by: '<S9>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P4_Size_a[2];      /* Computed Parameter: GTRTCANRX2_P4_Size_a
                                        * Referenced by: '<S9>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P4_o;              /* Expression: sample_time
                                        * Referenced by: '<S9>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANController_P1_Size[2]; /* Computed Parameter: GTRTCANController_P1_Size
                                        * Referenced by: '<Root>/GT-RT CAN Controller'
                                        */
  real_T GTRTCANController_P1[32];     /* Computed Parameter: GTRTCANController_P1
                                        * Referenced by: '<Root>/GT-RT CAN Controller'
                                        */
  real_T GTRTCANController_P2_Size[2]; /* Computed Parameter: GTRTCANController_P2_Size
                                        * Referenced by: '<Root>/GT-RT CAN Controller'
                                        */
  real_T GTRTCANController_P2[12];     /* Computed Parameter: GTRTCANController_P2
                                        * Referenced by: '<Root>/GT-RT CAN Controller'
                                        */
  real_T GTRTUDPTX_P1_Size[2];         /* Computed Parameter: GTRTUDPTX_P1_Size
                                        * Referenced by: '<S1>/GT-RT UDP TX'
                                        */
  real_T GTRTUDPTX_P1[29];             /* Computed Parameter: GTRTUDPTX_P1
                                        * Referenced by: '<S1>/GT-RT UDP TX'
                                        */
  real_T GTRTUDPTX_P2_Size[2];         /* Computed Parameter: GTRTUDPTX_P2_Size
                                        * Referenced by: '<S1>/GT-RT UDP TX'
                                        */
  real_T GTRTUDPTX_P2[14];             /* Computed Parameter: GTRTUDPTX_P2
                                        * Referenced by: '<S1>/GT-RT UDP TX'
                                        */
  real_T GTRTUDPTX1_P1_Size[2];        /* Computed Parameter: GTRTUDPTX1_P1_Size
                                        * Referenced by: '<S1>/GT-RT UDP TX1'
                                        */
  real_T GTRTUDPTX1_P1[29];            /* Computed Parameter: GTRTUDPTX1_P1
                                        * Referenced by: '<S1>/GT-RT UDP TX1'
                                        */
  real_T GTRTUDPTX1_P2_Size[2];        /* Computed Parameter: GTRTUDPTX1_P2_Size
                                        * Referenced by: '<S1>/GT-RT UDP TX1'
                                        */
  real_T GTRTUDPTX1_P2[14];            /* Computed Parameter: GTRTUDPTX1_P2
                                        * Referenced by: '<S1>/GT-RT UDP TX1'
                                        */
  real_T GTRTUDPWrite_P1_Size[2];      /* Computed Parameter: GTRTUDPWrite_P1_Size
                                        * Referenced by: '<S1>/GT-RT UDP  Write'
                                        */
  real_T GTRTUDPWrite_P1[29];          /* Computed Parameter: GTRTUDPWrite_P1
                                        * Referenced by: '<S1>/GT-RT UDP  Write'
                                        */
  real_T GTRTUDPWrite1_P1_Size[2];     /* Computed Parameter: GTRTUDPWrite1_P1_Size
                                        * Referenced by: '<S1>/GT-RT UDP  Write1'
                                        */
  real_T GTRTUDPWrite1_P1[29];         /* Computed Parameter: GTRTUDPWrite1_P1
                                        * Referenced by: '<S1>/GT-RT UDP  Write1'
                                        */
  real_T Gain1_Gain_p3;                /* Expression: 1
                                        * Referenced by: '<S28>/Gain1'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: 1
                                        * Referenced by: '<S28>/Gain2'
                                        */
  real_T Gain3_Gain_p;                 /* Expression: 1
                                        * Referenced by: '<S28>/Gain3'
                                        */
  real_T Gain4_Gain_m;                 /* Expression: 1
                                        * Referenced by: '<S28>/Gain4'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S29>/Gain1'
                                        */
  real_T Gain2_Gain_c;                 /* Expression: 1
                                        * Referenced by: '<S29>/Gain2'
                                        */
  real_T Gain3_Gain_ik;                /* Expression: 1
                                        * Referenced by: '<S29>/Gain3'
                                        */
  real_T Gain4_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S29>/Gain4'
                                        */
  real_T GTRTCANTX_P1_Size[2];         /* Computed Parameter: GTRTCANTX_P1_Size
                                        * Referenced by: '<S27>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P1[32];             /* Computed Parameter: GTRTCANTX_P1
                                        * Referenced by: '<S27>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P2_Size[2];         /* Computed Parameter: GTRTCANTX_P2_Size
                                        * Referenced by: '<S27>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P2;                 /* Expression: mff
                                        * Referenced by: '<S27>/GT-RT CAN TX'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S30>/Gain1'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 1
                                        * Referenced by: '<S30>/Gain2'
                                        */
  real_T Gain3_Gain_o;                 /* Expression: 1
                                        * Referenced by: '<S30>/Gain3'
                                        */
  real_T Gain4_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S30>/Gain4'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 1
                                        * Referenced by: '<S31>/Gain1'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S31>/Gain2'
                                        */
  real_T Gain3_Gain_oc;                /* Expression: 1
                                        * Referenced by: '<S31>/Gain3'
                                        */
  real_T Gain4_Gain_c;                 /* Expression: 1
                                        * Referenced by: '<S31>/Gain4'
                                        */
  real_T GTRTCANTX1_P1_Size[2];        /* Computed Parameter: GTRTCANTX1_P1_Size
                                        * Referenced by: '<S27>/GT-RT CAN TX1'
                                        */
  real_T GTRTCANTX1_P1[32];            /* Computed Parameter: GTRTCANTX1_P1
                                        * Referenced by: '<S27>/GT-RT CAN TX1'
                                        */
  real_T GTRTCANTX1_P2_Size[2];        /* Computed Parameter: GTRTCANTX1_P2_Size
                                        * Referenced by: '<S27>/GT-RT CAN TX1'
                                        */
  real_T GTRTCANTX1_P2;                /* Expression: mff
                                        * Referenced by: '<S27>/GT-RT CAN TX1'
                                        */
  real_T Gain1_Gain_jm;                /* Expression: 1
                                        * Referenced by: '<S32>/Gain1'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 1
                                        * Referenced by: '<S32>/Gain2'
                                        */
  real_T Gain3_Gain_h;                 /* Expression: 1
                                        * Referenced by: '<S32>/Gain3'
                                        */
  real_T Gain4_Gain_fl;                /* Expression: 1
                                        * Referenced by: '<S32>/Gain4'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 1
                                        * Referenced by: '<S33>/Gain1'
                                        */
  real_T Gain2_Gain_i;                 /* Expression: 1
                                        * Referenced by: '<S33>/Gain2'
                                        */
  real_T Gain3_Gain_p5;                /* Expression: 1
                                        * Referenced by: '<S33>/Gain3'
                                        */
  real_T Gain4_Gain_gu;                /* Expression: 1
                                        * Referenced by: '<S33>/Gain4'
                                        */
  real_T GTRTCANTX2_P1_Size[2];        /* Computed Parameter: GTRTCANTX2_P1_Size
                                        * Referenced by: '<S27>/GT-RT CAN TX2'
                                        */
  real_T GTRTCANTX2_P1[32];            /* Computed Parameter: GTRTCANTX2_P1
                                        * Referenced by: '<S27>/GT-RT CAN TX2'
                                        */
  real_T GTRTCANTX2_P2_Size[2];        /* Computed Parameter: GTRTCANTX2_P2_Size
                                        * Referenced by: '<S27>/GT-RT CAN TX2'
                                        */
  real_T GTRTCANTX2_P2;                /* Expression: mff
                                        * Referenced by: '<S27>/GT-RT CAN TX2'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 0
                                        * Referenced by: '<S52>/Switch'
                                        */
  real_T PSEA2_Value;                  /* Expression: 0
                                        * Referenced by: '<S58>/PSEA2'
                                        */
  real_T Switch_Threshold_i;           /* Expression: 1
                                        * Referenced by: '<S58>/Switch'
                                        */
  real_T Switch_Threshold_h;           /* Expression: 0
                                        * Referenced by: '<S53>/Switch'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0
                                        * Referenced by: '<S54>/Switch'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S55>/Switch'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0
                                        * Referenced by: '<S56>/Switch'
                                        */
  real_T Switch_Threshold_iw;          /* Expression: 0
                                        * Referenced by: '<S57>/Switch'
                                        */
  real_T Constant_Value_kw;            /* Expression: 1
                                        * Referenced by: '<S79>/Constant'
                                        */
  real_T setforoptimizingxandy_Value[6];/* Expression: [258.3 -273.22;  220 -330; 141.15 -390]
                                         * Referenced by: '<S73>/set for optimizing x and y'
                                         */
  real_T setforoptimizingpurez_Value[6];/* Expression: [258.3 -273.22;  251.45 -281.21; 244.6 -289.2]
                                         * Referenced by: '<S73>/set for optimizing pure z'
                                         */
  real_T setforoptimizingz_Value[6];   /* Expression: [258.3 -273.22;  240.025 -296.285; 221.75 -319.35]
                                        * Referenced by: '<S73>/set for optimizing z'
                                        */
  real_T Constant2_Value_e;            /* Expression: 50
                                        * Referenced by: '<S73>/Constant2'
                                        */
  real_T Forsavingpositionandvelocityunt;/* Expression: 0
                                          * Referenced by: '<S87>/For saving position  and velocity until after switchover'
                                          */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S90>/TSamp'
                                        */
  real_T UD_X0;                        /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S90>/UD'
                                        */
  real_T zetaT_transferpi_Gain;        /* Expression: 0.8/pi
                                        * Referenced by: '<S87>/(zeta*T_transfer)//pi'
                                        */
  real_T pizetaT_transfers_gainval_c;  /* Computed Parameter: pizetaT_transfers_gainval_c
                                        * Referenced by: '<S87>/pi//(zeta*T_transfer)//s'
                                        */
  real_T zetapiT_transfers_gainval_j;  /* Computed Parameter: zetapiT_transfers_gainval_j
                                        * Referenced by: '<S87>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain_n;                /* Expression: 3.2*pi
                                        * Referenced by: '<S87>/4*zeta*pi'
                                        */
  real_T pizeta_Gain_h;                /* Expression: pi/0.8
                                        * Referenced by: '<S87>/pi//zeta'
                                        */
  real_T Constant7_Value;              /* Expression: 180
                                        * Referenced by: '<S99>/Constant7'
                                        */
  real_T Constant_Value_hy;            /* Expression: 0
                                        * Referenced by: '<S99>/Constant'
                                        */
  real_T Switch1_Threshold;            /* Expression: 1
                                        * Referenced by: '<S101>/Switch1'
                                        */
  real_T Switch_Threshold_ki;          /* Expression: 1
                                        * Referenced by: '<S101>/Switch'
                                        */
  real_T Switch2_Threshold;            /* Expression: 1
                                        * Referenced by: '<S101>/Switch2'
                                        */
  real_T GTRTUDPTX_P1_Size_g[2];       /* Computed Parameter: GTRTUDPTX_P1_Size_g
                                        * Referenced by: '<S99>/GT-RT UDP TX'
                                        */
  real_T GTRTUDPTX_P1_n[29];           /* Computed Parameter: GTRTUDPTX_P1_n
                                        * Referenced by: '<S99>/GT-RT UDP TX'
                                        */
  real_T GTRTUDPTX_P2_Size_l[2];       /* Computed Parameter: GTRTUDPTX_P2_Size_l
                                        * Referenced by: '<S99>/GT-RT UDP TX'
                                        */
  real_T GTRTUDPTX_P2_n[14];           /* Computed Parameter: GTRTUDPTX_P2_n
                                        * Referenced by: '<S99>/GT-RT UDP TX'
                                        */
  real_T GTRTUDPTX1_P1_Size_b[2];      /* Computed Parameter: GTRTUDPTX1_P1_Size_b
                                        * Referenced by: '<S99>/GT-RT UDP TX1'
                                        */
  real_T GTRTUDPTX1_P1_j[29];          /* Computed Parameter: GTRTUDPTX1_P1_j
                                        * Referenced by: '<S99>/GT-RT UDP TX1'
                                        */
  real_T GTRTUDPTX1_P2_Size_a[2];      /* Computed Parameter: GTRTUDPTX1_P2_Size_a
                                        * Referenced by: '<S99>/GT-RT UDP TX1'
                                        */
  real_T GTRTUDPTX1_P2_n[14];          /* Computed Parameter: GTRTUDPTX1_P2_n
                                        * Referenced by: '<S99>/GT-RT UDP TX1'
                                        */
  real_T GTRTUDPTX2_P1_Size[2];        /* Computed Parameter: GTRTUDPTX2_P1_Size
                                        * Referenced by: '<S99>/GT-RT UDP TX2'
                                        */
  real_T GTRTUDPTX2_P1[29];            /* Computed Parameter: GTRTUDPTX2_P1
                                        * Referenced by: '<S99>/GT-RT UDP TX2'
                                        */
  real_T GTRTUDPTX2_P2_Size[2];        /* Computed Parameter: GTRTUDPTX2_P2_Size
                                        * Referenced by: '<S99>/GT-RT UDP TX2'
                                        */
  real_T GTRTUDPTX2_P2[14];            /* Computed Parameter: GTRTUDPTX2_P2
                                        * Referenced by: '<S99>/GT-RT UDP TX2'
                                        */
  real_T GTRTUDPWrite_P1_Size_f[2];    /* Computed Parameter: GTRTUDPWrite_P1_Size_f
                                        * Referenced by: '<S99>/GT-RT UDP  Write'
                                        */
  real_T GTRTUDPWrite_P1_f[29];        /* Computed Parameter: GTRTUDPWrite_P1_f
                                        * Referenced by: '<S99>/GT-RT UDP  Write'
                                        */
  real_T GTRTUDPWrite1_P1_Size_m[2];   /* Computed Parameter: GTRTUDPWrite1_P1_Size_m
                                        * Referenced by: '<S99>/GT-RT UDP  Write1'
                                        */
  real_T GTRTUDPWrite1_P1_e[29];       /* Computed Parameter: GTRTUDPWrite1_P1_e
                                        * Referenced by: '<S99>/GT-RT UDP  Write1'
                                        */
  real_T GTRTUDPWrite2_P1_Size[2];     /* Computed Parameter: GTRTUDPWrite2_P1_Size
                                        * Referenced by: '<S99>/GT-RT UDP  Write2'
                                        */
  real_T GTRTUDPWrite2_P1[29];         /* Computed Parameter: GTRTUDPWrite2_P1
                                        * Referenced by: '<S99>/GT-RT UDP  Write2'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T GTRTCANTX_P1_Size_h[2];       /* Computed Parameter: GTRTCANTX_P1_Size_h
                                        * Referenced by: '<S102>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P1_n[32];           /* Computed Parameter: GTRTCANTX_P1_n
                                        * Referenced by: '<S102>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P2_Size_d[2];       /* Computed Parameter: GTRTCANTX_P2_Size_d
                                        * Referenced by: '<S102>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P2_c;               /* Expression: mff
                                        * Referenced by: '<S102>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P1_Size_f[2];       /* Computed Parameter: GTRTCANTX_P1_Size_f
                                        * Referenced by: '<S103>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P1_h[32];           /* Computed Parameter: GTRTCANTX_P1_h
                                        * Referenced by: '<S103>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P2_Size_i[2];       /* Computed Parameter: GTRTCANTX_P2_Size_i
                                        * Referenced by: '<S103>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P2_k;               /* Expression: mff
                                        * Referenced by: '<S103>/GT-RT CAN TX'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S106>/Constant'
                                        */
  real32_T ButterworthFilter10Hz_Initial_l;/* Computed Parameter: ButterworthFilter10Hz_Initial_l
                                            * Referenced by: '<S13>/Butterworth Filter 10 Hz'
                                            */
  real32_T ButterworthFilter10Hz_Numerat_k[5];/* Computed Parameter: ButterworthFilter10Hz_Numerat_k
                                               * Referenced by: '<S13>/Butterworth Filter 10 Hz'
                                               */
  real32_T ButterworthFilter10Hz_Denomin_f[5];/* Computed Parameter: ButterworthFilter10Hz_Denomin_f
                                               * Referenced by: '<S13>/Butterworth Filter 10 Hz'
                                               */
  real32_T Gain2_Gain_mm;              /* Computed Parameter: Gain2_Gain_mm
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real32_T Gain3_Gain_k;               /* Computed Parameter: Gain3_Gain_k
                                        * Referenced by: '<S13>/Gain3'
                                        */
  real32_T Gain1_Gain_g;               /* Computed Parameter: Gain1_Gain_g
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_k;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_k
                                            * Referenced by: '<S72>/Discrete-Time Integrator1'
                                            */
  real32_T DiscreteTimeIntegrator1_IC_h;/* Computed Parameter: DiscreteTimeIntegrator1_IC_h
                                         * Referenced by: '<S72>/Discrete-Time Integrator1'
                                         */
  real32_T DiscreteTimeIntegrator1_UpperSa;/* Computed Parameter: DiscreteTimeIntegrator1_UpperSa
                                            * Referenced by: '<S72>/Discrete-Time Integrator1'
                                            */
  real32_T DiscreteTimeIntegrator1_LowerSa;/* Computed Parameter: DiscreteTimeIntegrator1_LowerSa
                                            * Referenced by: '<S72>/Discrete-Time Integrator1'
                                            */
  real32_T Gain1_Gain_h;               /* Computed Parameter: Gain1_Gain_h
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real32_T Gain_Gain_ir;               /* Computed Parameter: Gain_Gain_ir
                                        * Referenced by: '<S15>/Gain'
                                        */
  real32_T Gain2_Gain_lz;              /* Computed Parameter: Gain2_Gain_lz
                                        * Referenced by: '<S15>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator_gainva_o;/* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                                            * Referenced by: '<S14>/Discrete-Time Integrator'
                                            */
  real32_T DiscreteTimeIntegrator_IC_l;/* Computed Parameter: DiscreteTimeIntegrator_IC_l
                                        * Referenced by: '<S14>/Discrete-Time Integrator'
                                        */
  real32_T DiscreteTimeIntegrator1_gain_p4;/* Computed Parameter: DiscreteTimeIntegrator1_gain_p4
                                            * Referenced by: '<S14>/Discrete-Time Integrator1'
                                            */
  real32_T DiscreteTimeIntegrator1_IC_o;/* Computed Parameter: DiscreteTimeIntegrator1_IC_o
                                         * Referenced by: '<S14>/Discrete-Time Integrator1'
                                         */
  real32_T DiscreteTimeIntegrator1_Upper_a;/* Computed Parameter: DiscreteTimeIntegrator1_Upper_a
                                            * Referenced by: '<S14>/Discrete-Time Integrator1'
                                            */
  real32_T DiscreteTimeIntegrator1_Lower_p;/* Computed Parameter: DiscreteTimeIntegrator1_Lower_p
                                            * Referenced by: '<S14>/Discrete-Time Integrator1'
                                            */
  uint32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S1>/Constant3'
                                        */
  uint32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S1>/Constant4'
                                        */
  uint32_T TXCANID1_Value;             /* Computed Parameter: TXCANID1_Value
                                        * Referenced by: '<S27>/TX CAN ID1'
                                        */
  uint32_T TXCANID2_Value;             /* Computed Parameter: TXCANID2_Value
                                        * Referenced by: '<S27>/TX CAN ID2'
                                        */
  uint32_T TXCANID3_Value;             /* Computed Parameter: TXCANID3_Value
                                        * Referenced by: '<S27>/TX CAN ID3'
                                        */
  uint32_T Constant3_Value_n;          /* Computed Parameter: Constant3_Value_n
                                        * Referenced by: '<S99>/Constant3'
                                        */
  uint32_T Constant4_Value_c;          /* Computed Parameter: Constant4_Value_c
                                        * Referenced by: '<S99>/Constant4'
                                        */
  uint32_T Constant6_Value;            /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<S99>/Constant6'
                                        */
  uint32_T TXCANID1_Value_f;           /* Computed Parameter: TXCANID1_Value_f
                                        * Referenced by: '<S102>/TX CAN ID1'
                                        */
  uint32_T TXCANID1_Value_h;           /* Computed Parameter: TXCANID1_Value_h
                                        * Referenced by: '<S103>/TX CAN ID1'
                                        */
  int32_T Gain_Gain_it;                /* Computed Parameter: Gain_Gain_it
                                        * Referenced by: '<S17>/Gain'
                                        */
  int32_T Gain2_Gain_a;                /* Computed Parameter: Gain2_Gain_a
                                        * Referenced by: '<S17>/Gain2'
                                        */
  int32_T Gain6_Gain;                  /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S17>/Gain6'
                                        */
  int32_T Gain1_Gain_b;                /* Computed Parameter: Gain1_Gain_b
                                        * Referenced by: '<S17>/Gain1'
                                        */
  int32_T Gain3_Gain_d;                /* Computed Parameter: Gain3_Gain_d
                                        * Referenced by: '<S17>/Gain3'
                                        */
  int32_T Gain4_Gain_fc;               /* Computed Parameter: Gain4_Gain_fc
                                        * Referenced by: '<S17>/Gain4'
                                        */
  int16_T shift_Power2Exponent;        /* Computed Parameter: shift_Power2Exponent
                                        * Referenced by: '<S34>/shift'
                                        */
  int16_T shift_Power2Exponent_g;      /* Computed Parameter: shift_Power2Exponent_g
                                        * Referenced by: '<S35>/shift'
                                        */
  int16_T shift_Power2Exponent_k;      /* Computed Parameter: shift_Power2Exponent_k
                                        * Referenced by: '<S36>/shift'
                                        */
  int16_T shift_Power2Exponent_n;      /* Computed Parameter: shift_Power2Exponent_n
                                        * Referenced by: '<S37>/shift'
                                        */
  int16_T shift_Power2Exponent_c;      /* Computed Parameter: shift_Power2Exponent_c
                                        * Referenced by: '<S38>/shift'
                                        */
  int16_T shift_Power2Exponent_e;      /* Computed Parameter: shift_Power2Exponent_e
                                        * Referenced by: '<S39>/shift'
                                        */
  int16_T shift_Power2Exponent_j;      /* Computed Parameter: shift_Power2Exponent_j
                                        * Referenced by: '<S40>/shift'
                                        */
  int16_T shift_Power2Exponent_a;      /* Computed Parameter: shift_Power2Exponent_a
                                        * Referenced by: '<S41>/shift'
                                        */
  int16_T shift_Power2Exponent_p;      /* Computed Parameter: shift_Power2Exponent_p
                                        * Referenced by: '<S42>/shift'
                                        */
  int16_T shift_Power2Exponent_d;      /* Computed Parameter: shift_Power2Exponent_d
                                        * Referenced by: '<S43>/shift'
                                        */
  int16_T shift_Power2Exponent_nk;     /* Computed Parameter: shift_Power2Exponent_nk
                                        * Referenced by: '<S44>/shift'
                                        */
  int16_T shift_Power2Exponent_kt;     /* Computed Parameter: shift_Power2Exponent_kt
                                        * Referenced by: '<S45>/shift'
                                        */
  int16_T shift_Power2Exponent_dd;     /* Computed Parameter: shift_Power2Exponent_dd
                                        * Referenced by: '<S46>/shift'
                                        */
  int16_T shift_Power2Exponent_g3;     /* Computed Parameter: shift_Power2Exponent_g3
                                        * Referenced by: '<S47>/shift'
                                        */
  int16_T shift_Power2Exponent_f;      /* Computed Parameter: shift_Power2Exponent_f
                                        * Referenced by: '<S48>/shift'
                                        */
  int16_T shift_Power2Exponent_nj;     /* Computed Parameter: shift_Power2Exponent_nj
                                        * Referenced by: '<S49>/shift'
                                        */
  int16_T shift_Power2Exponent_gq;     /* Computed Parameter: shift_Power2Exponent_gq
                                        * Referenced by: '<S50>/shift'
                                        */
  int16_T shift_Power2Exponent_ed;     /* Computed Parameter: shift_Power2Exponent_ed
                                        * Referenced by: '<S51>/shift'
                                        */
  uint16_T Constant2_Value_l;          /* Computed Parameter: Constant2_Value_l
                                        * Referenced by: '<S1>/Constant2'
                                        */
  uint16_T Constant1_Value_d;          /* Computed Parameter: Constant1_Value_d
                                        * Referenced by: '<S1>/Constant1'
                                        */
  uint16_T Constant2_Value_i;          /* Computed Parameter: Constant2_Value_i
                                        * Referenced by: '<S99>/Constant2'
                                        */
  uint16_T Constant1_Value_i;          /* Computed Parameter: Constant1_Value_i
                                        * Referenced by: '<S99>/Constant1'
                                        */
  uint16_T Constant5_Value;            /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S99>/Constant5'
                                        */
  uint8_T Constant_Value_g;            /* Expression: uint8(1)
                                        * Referenced by: '<S7>/Constant'
                                        */
  uint8_T SwitchControl_Threshold;     /* Expression: uint8(0)
                                        * Referenced by: '<S7>/SwitchControl'
                                        */
  uint8_T Switch1_Threshold_a;         /* Computed Parameter: Switch1_Threshold_a
                                        * Referenced by: '<S106>/Switch1'
                                        */
  uint8_T Switch_Threshold_d;          /* Computed Parameter: Switch_Threshold_d
                                        * Referenced by: '<Root>/Switch'
                                        */
  uint8_T Switch1_Threshold_a2;        /* Computed Parameter: Switch1_Threshold_a2
                                        * Referenced by: '<S3>/Switch1'
                                        */
  uint8_T Constant_Value_e;            /* Expression: uint8(1)
                                        * Referenced by: '<S11>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_a;   /* Expression: uint8(0)
                                        * Referenced by: '<S11>/SwitchControl'
                                        */
  uint8_T Constant_Value_d;            /* Expression: uint8(1)
                                        * Referenced by: '<S16>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_p;   /* Expression: uint8(0)
                                        * Referenced by: '<S16>/SwitchControl'
                                        */
  uint8_T TXData_Value;                /* Computed Parameter: TXData_Value
                                        * Referenced by: '<S102>/TX Data'
                                        */
  uint8_T TXData_Value_d;              /* Computed Parameter: TXData_Value_d
                                        * Referenced by: '<S103>/TX Data'
                                        */
  uint8_T Gain2_Gain_g;                /* Computed Parameter: Gain2_Gain_g
                                        * Referenced by: '<S21>/Gain2'
                                        */
  uint8_T Gain2_Gain_k;                /* Computed Parameter: Gain2_Gain_k
                                        * Referenced by: '<S22>/Gain2'
                                        */
  uint8_T Gain2_Gain_f;                /* Computed Parameter: Gain2_Gain_f
                                        * Referenced by: '<S23>/Gain2'
                                        */
  uint8_T Gain2_Gain_h;                /* Computed Parameter: Gain2_Gain_h
                                        * Referenced by: '<S24>/Gain2'
                                        */
  uint8_T Gain2_Gain_ia;               /* Computed Parameter: Gain2_Gain_ia
                                        * Referenced by: '<S25>/Gain2'
                                        */
  uint8_T Gain2_Gain_ip;               /* Computed Parameter: Gain2_Gain_ip
                                        * Referenced by: '<S26>/Gain2'
                                        */
  uint8_T Gain3_Gain_f;                /* Computed Parameter: Gain3_Gain_f
                                        * Referenced by: '<S21>/Gain3'
                                        */
  uint8_T Gain3_Gain_b;                /* Computed Parameter: Gain3_Gain_b
                                        * Referenced by: '<S22>/Gain3'
                                        */
  uint8_T Gain3_Gain_mk;               /* Computed Parameter: Gain3_Gain_mk
                                        * Referenced by: '<S23>/Gain3'
                                        */
  uint8_T Gain3_Gain_mo;               /* Computed Parameter: Gain3_Gain_mo
                                        * Referenced by: '<S24>/Gain3'
                                        */
  uint8_T Gain3_Gain_kp;               /* Computed Parameter: Gain3_Gain_kp
                                        * Referenced by: '<S25>/Gain3'
                                        */
  uint8_T Gain3_Gain_d2;               /* Computed Parameter: Gain3_Gain_d2
                                        * Referenced by: '<S26>/Gain3'
                                        */
  uint8_T Gain4_Gain_m1;               /* Computed Parameter: Gain4_Gain_m1
                                        * Referenced by: '<S21>/Gain4'
                                        */
  uint8_T Gain4_Gain_e;                /* Computed Parameter: Gain4_Gain_e
                                        * Referenced by: '<S22>/Gain4'
                                        */
  uint8_T Gain4_Gain_ck;               /* Computed Parameter: Gain4_Gain_ck
                                        * Referenced by: '<S23>/Gain4'
                                        */
  uint8_T Gain4_Gain_e0;               /* Computed Parameter: Gain4_Gain_e0
                                        * Referenced by: '<S24>/Gain4'
                                        */
  uint8_T Gain4_Gain_l;                /* Computed Parameter: Gain4_Gain_l
                                        * Referenced by: '<S25>/Gain4'
                                        */
  uint8_T Gain4_Gain_b;                /* Computed Parameter: Gain4_Gain_b
                                        * Referenced by: '<S26>/Gain4'
                                        */
  rtP_IfActionSubsystem1_M43_Sim_ IfActionSubsystem1_e;/* '<S52>/If Action Subsystem1' */
  rtP_IfActionSubsystem_M43_Sim_F IfActionSubsystem_d0;/* '<S53>/If Action Subsystem' */
  rtP_IfActionSubsystem1_M43_Sim_ IfActionSubsystem1_d;/* '<S52>/If Action Subsystem1' */
  rtP_IfActionSubsystem_M43_Sim_F IfActionSubsystem_e;/* '<S53>/If Action Subsystem' */
  rtP_IfActionSubsystem1_M43_Sim_ IfActionSubsystem1_p;/* '<S52>/If Action Subsystem1' */
  rtP_IfActionSubsystem_M43_Sim_F IfActionSubsystem_d;/* '<S53>/If Action Subsystem' */
  rtP_IfActionSubsystem1_M43_Sim_ IfActionSubsystem1_k;/* '<S52>/If Action Subsystem1' */
  rtP_IfActionSubsystem_M43_Sim_F IfActionSubsystem_i;/* '<S53>/If Action Subsystem' */
  rtP_IfActionSubsystem1_M43_Sim_ IfActionSubsystem1_f;/* '<S52>/If Action Subsystem1' */
  rtP_IfActionSubsystem_M43_Sim_F IfActionSubsystem_h;/* '<S53>/If Action Subsystem' */
  rtP_IfActionSubsystem1_M43_Sim_ IfActionSubsystem1;/* '<S52>/If Action Subsystem1' */
};

/* Real-time Model Data Structure */
struct RT_MODEL_M43_Sim_Forcing_003h_Trajectory {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    SimStruct childSFunctions[28];
    SimStruct *childSFunctionPtrs[28];
    struct _ssBlkInfo2 blkInfo2[28];
    struct _ssSFcnModelMethods2 methods2[28];
    struct _ssSFcnModelMethods3 methods3[28];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[4];
      real_T const *UPtrs0[4];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[28];
      real_T const *UPtrs3[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[4];
      real_T const *UPtrs0[4];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[32];
      real_T const *UPtrs3[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[8];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[8];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[8];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[4];
      real_T const *UPtrs0[4];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[72];
      real_T const *UPtrs3[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[4];
      real_T const *UPtrs0[4];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[24];
      real_T const *UPtrs3[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[4];
      real_T const *UPtrs0[4];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[24];
      real_T const *UPtrs3[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn11;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn12;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn13;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn14;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn15;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn16;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn17;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn18;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn19;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn20;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn21;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn22;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn23;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn24;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn25;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn26;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn27;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_M43_Sim_Forcing_003h_Trajectory
  M43_Sim_Forcing_003h_Trajectory_P;

/* Block signals (auto storage) */
extern BlockIO_M43_Sim_Forcing_003h_Trajectory M43_Sim_Forcing_003h_Trajectory_B;

/* Block states (auto storage) */
extern D_Work_M43_Sim_Forcing_003h_Trajectory
  M43_Sim_Forcing_003h_Trajectory_DWork;

/* External data declarations for dependent source files */
extern uint8_T M43_Sim_Forcing_003h_Trajectory_U8GND;/* uint8_T ground */
extern int64m_T M43_Sim_Forcing_003h_Trajectory_sfix64_En41_GND;/* int64m_T ground */
extern uint8_T M43_Sim_Forcing_003h_Trajectory_U8GND;/* uint8_T ground */
extern int64m_T M43_Sim_Forcing_003h_Trajectory_sfix64_En41_GND;/* int64m_T ground */

/* Model entry point functions */
extern void M43_Sim_Forcing_003h_Trajectory_initialize(boolean_T firstTime);
extern void M43_Sim_Forcing_003h_Trajectory_output(int_T tid);
extern void M43_Sim_Forcing_003h_Trajectory_update(int_T tid);
extern void M43_Sim_Forcing_003h_Trajectory_terminate(void);

/* Real-time Model object */
extern RT_MODEL_M43_Sim_Forcing_003h_Trajectory
  *M43_Sim_Forcing_003h_Trajectory_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : M43_Sim_Forcing_003h_Trajectory
 * '<S1>'   : M43_Sim_Forcing_003h_Trajectory/6_DOF Visual Cab 12//06//15
 * '<S2>'   : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)
 * '<S3>'   : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15
 * '<S4>'   : M43_Sim_Forcing_003h_Trajectory/Controls to GT-RT
 * '<S5>'   : M43_Sim_Forcing_003h_Trajectory/Data to Control Node 12//06//15
 * '<S6>'   : M43_Sim_Forcing_003h_Trajectory/Data_from_Unity
 * '<S7>'   : M43_Sim_Forcing_003h_Trajectory/Enable_connection
 * '<S8>'   : M43_Sim_Forcing_003h_Trajectory/FNiRSS to GT-RT1
 * '<S9>'   : M43_Sim_Forcing_003h_Trajectory/Handshake CAN
 * '<S10>'  : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)
 * '<S11>'  : M43_Sim_Forcing_003h_Trajectory/Safety Connect
 * '<S12>'  : M43_Sim_Forcing_003h_Trajectory/Scopes
 * '<S13>'  : M43_Sim_Forcing_003h_Trajectory/Stick Conditioning
 * '<S14>'  : M43_Sim_Forcing_003h_Trajectory/6_DOF Visual Cab 12//06//15/Align Psi with Heading1
 * '<S15>'  : M43_Sim_Forcing_003h_Trajectory/6_DOF Visual Cab 12//06//15/Compensate for Roll and pitch
 * '<S16>'  : M43_Sim_Forcing_003h_Trajectory/6_DOF Visual Cab 12//06//15/Data_to_UNITY
 * '<S17>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Receive
 * '<S18>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send
 * '<S19>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches
 * '<S20>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/velocity and acceleration limitation
 * '<S21>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Receive/Convert 4*uni8 to int
 * '<S22>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Receive/Convert 4*uni8 to int1
 * '<S23>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Receive/Convert 4*uni8 to int2
 * '<S24>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Receive/Convert 4*uni8 to int3
 * '<S25>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Receive/Convert 4*uni8 to int4
 * '<S26>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Receive/Convert 4*uni8 to int5
 * '<S27>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1
 * '<S28>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8
 * '<S29>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 1
 * '<S30>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 2
 * '<S31>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 3
 * '<S32>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 4
 * '<S33>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 5
 * '<S34>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 /Shift Arithmetic
 * '<S35>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 /Shift Arithmetic1
 * '<S36>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 /Shift Arithmetic2
 * '<S37>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 1/Shift Arithmetic
 * '<S38>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 1/Shift Arithmetic1
 * '<S39>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 1/Shift Arithmetic2
 * '<S40>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 2/Shift Arithmetic
 * '<S41>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 2/Shift Arithmetic1
 * '<S42>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 2/Shift Arithmetic2
 * '<S43>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 3/Shift Arithmetic
 * '<S44>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 3/Shift Arithmetic1
 * '<S45>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 3/Shift Arithmetic2
 * '<S46>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 4/Shift Arithmetic
 * '<S47>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 4/Shift Arithmetic1
 * '<S48>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 4/Shift Arithmetic2
 * '<S49>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 5/Shift Arithmetic
 * '<S50>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 5/Shift Arithmetic1
 * '<S51>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 5/Shift Arithmetic2
 * '<S52>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem
 * '<S53>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem1
 * '<S54>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem2
 * '<S55>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem3
 * '<S56>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem4
 * '<S57>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem5
 * '<S58>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem/If Action Subsystem
 * '<S59>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem/If Action Subsystem1
 * '<S60>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem1/If Action Subsystem
 * '<S61>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem1/If Action Subsystem1
 * '<S62>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem2/If Action Subsystem
 * '<S63>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem2/If Action Subsystem1
 * '<S64>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem3/If Action Subsystem
 * '<S65>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem3/If Action Subsystem1
 * '<S66>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem4/If Action Subsystem
 * '<S67>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem4/If Action Subsystem1
 * '<S68>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem5/If Action Subsystem
 * '<S69>'  : M43_Sim_Forcing_003h_Trajectory/BEC (May 7, 2015)/Software limit switches/Subsystem5/If Action Subsystem1
 * '<S70>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Cabin Motion
 * '<S71>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Compare To Zero
 * '<S72>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Compute Stick z with direction hat
 * '<S73>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Move UP1
 * '<S74>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Newtonian Dynamics 31//07//15
 * '<S75>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Cabin Motion/Cabin Motion x
 * '<S76>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Cabin Motion/Cabin Motion y
 * '<S77>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Cabin Motion/Cabin Motion z
 * '<S78>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Cabin Motion/Reduce Out-of-Plane Yaw1
 * '<S79>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Cabin Motion/Stay within ellipse 20//07//15
 * '<S80>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Cabin Motion/Cabin Motion x/theta-filter
 * '<S81>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Cabin Motion/Cabin Motion x/x-filter
 * '<S82>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Cabin Motion/Cabin Motion y/theta-filter
 * '<S83>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Cabin Motion/Cabin Motion y/x-filter
 * '<S84>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Cabin Motion/Cabin Motion z/x-filter
 * '<S85>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Cabin Motion/Reduce Out-of-Plane Yaw1/Embedded MATLAB Function
 * '<S86>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Cabin Motion/Stay within ellipse 20//07//15/Get R
 * '<S87>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Move UP1/Smooth Displacement Second-Order Filter, zeta 0.8
 * '<S88>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Move UP1/add x_offset
 * '<S89>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Move UP1/curve
 * '<S90>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Move UP1/Smooth Displacement Second-Order Filter, zeta 0.8/Discrete Derivative
 * '<S91>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Move UP1/add x_offset/Embedded MATLAB Function
 * '<S92>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Newtonian Dynamics 31//07//15/Adaptive Psi computation
 * '<S93>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Newtonian Dynamics 31//07//15/Newtonian Dynamics x
 * '<S94>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Newtonian Dynamics 31//07//15/Newtonian Dynamics z 17//06//15
 * '<S95>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Newtonian Dynamics 31//07//15/Rate Control Dynamics Psi
 * '<S96>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Newtonian Dynamics 31//07//15/Adaptive Psi computation/Exp_saturation
 * '<S97>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Newtonian Dynamics 31//07//15/Newtonian Dynamics x/Natural Speed Down
 * '<S98>'  : M43_Sim_Forcing_003h_Trajectory/Breaking_Control 20//07//15/Newtonian Dynamics 31//07//15/Rate Control Dynamics Psi/Second-Order Filter, zeta 0.8
 * '<S99>'  : M43_Sim_Forcing_003h_Trajectory/Data to Control Node 12//06//15/6_DOF Control
 * '<S100>' : M43_Sim_Forcing_003h_Trajectory/Data to Control Node 12//06//15/Interaction device from VIS (Stick)
 * '<S101>' : M43_Sim_Forcing_003h_Trajectory/Data to Control Node 12//06//15/6_DOF Control/Pass_Oculus_Orientation
 * '<S102>' : M43_Sim_Forcing_003h_Trajectory/Handshake CAN/If Action Subsystem
 * '<S103>' : M43_Sim_Forcing_003h_Trajectory/Handshake CAN/If Action Subsystem1
 * '<S104>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Forward Kinematics
 * '<S105>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Increments
 * '<S106>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Inverse Kinematics May 6, 2015
 * '<S107>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Subtract psi offset
 * '<S108>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Forward Kinematics/Embedded MATLAB Function
 * '<S109>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Forward Kinematics/KUKA2NED
 * '<S110>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Inverse Kinematics May 6, 2015/Inverse Kinematics
 * '<S111>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Inverse Kinematics May 6, 2015/NED2KUKA
 * '<S112>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics
 * '<S113>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Inverse Kinematics May 6, 2015/Inverse Kinematics/full inverse kin
 * '<S114>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Inverse Kinematics May 6, 2015/Inverse Kinematics/full inverse kin/Embedded MATLAB Function
 * '<S115>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics/A1-A6 COM
 * '<S116>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics/Simplified Inverse Kin
 * '<S117>' : M43_Sim_Forcing_003h_Trajectory/Joint Controller (May 7, 2015)/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics/Simplified Inverse Kin/Embedded MATLAB Function1
 */
#endif                                 /* RTW_HEADER_M43_Sim_Forcing_003h_Trajectory_h_ */

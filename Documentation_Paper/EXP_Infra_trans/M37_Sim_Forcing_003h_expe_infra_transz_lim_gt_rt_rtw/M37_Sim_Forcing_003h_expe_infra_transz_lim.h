/*
 * M37_Sim_Forcing_003h_expe_infra_transz_lim.h
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
#ifndef RTW_HEADER_M37_Sim_Forcing_003h_expe_infra_transz_lim_h_
#define RTW_HEADER_M37_Sim_Forcing_003h_expe_infra_transz_lim_h_
#ifndef M37_Sim_Forcing_003h_expe_infra_transz_lim_COMMON_INCLUDES_
# define M37_Sim_Forcing_003h_expe_infra_transz_lim_COMMON_INCLUDES_
#include <stddef.h>
#include <float.h>
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
#include "rt_mod_snf.h"
#include "rt_pow_snf.h"
#endif                                 /* M37_Sim_Forcing_003h_expe_infra_transz_lim_COMMON_INCLUDES_ */

#include "M37_Sim_Forcing_003h_expe_infra_transz_lim_types.h"

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
#define M37_Sim_Forcing_003h_expe_infra_transz_lim_rtModel RT_MODEL_M37_Sim_Forcing_003h_expe_infra_transz_lim

/* Block signals for system '<S47>/If Action Subsystem1' */
typedef struct {
  real_T Switch;                       /* '<S54>/Switch' */
} rtB_IfActionSubsystem1_M37_Sim_;

/* Block states (auto storage) for system '<S47>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S47>/If Action Subsystem1' */
} rtDW_IfActionSubsystem1_M37_Sim;

/* Block signals for system '<S48>/If Action Subsystem' */
typedef struct {
  real_T Switch;                       /* '<S55>/Switch' */
} rtB_IfActionSubsystem_M37_Sim_F;

/* Block states (auto storage) for system '<S48>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S48>/If Action Subsystem' */
} rtDW_IfActionSubsystem_M37_Sim_;

/* Block signals for system '<S94>/Embedded MATLAB Function2' */
typedef struct {
  real_T y;                            /* '<S94>/Embedded MATLAB Function2' */
  real_T gain;                         /* '<S94>/Embedded MATLAB Function2' */
} rtB_EmbeddedMATLABFunction2_M37;

/* Block states (auto storage) for system '<S94>/Embedded MATLAB Function2' */
typedef struct {
  uint8_T is_active_c6_M37_Sim_Forcing_00;/* '<S94>/Embedded MATLAB Function2' */
  boolean_T isStable;                  /* '<S94>/Embedded MATLAB Function2' */
  boolean_T doneDoubleBufferReInit;    /* '<S94>/Embedded MATLAB Function2' */
} rtDW_EmbeddedMATLABFunction2_M3;

/* Block signals (auto storage) */
typedef struct {
  real_T DiscreteTimeIntegrator1;      /* '<S100>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2;      /* '<S70>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator1_a;    /* '<S70>/Discrete-Time Integrator1' */
  real_T Switch1;                      /* '<S70>/Switch1' */
  real_T Sum20;                        /* '<S3>/Sum20' */
  real_T UnitDelay;                    /* '<S72>/Unit Delay' */
  real_T Switch1_f;                    /* '<S3>/Switch1' */
  real_T Forsavingpositionandvelocityunt;/* '<S106>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers;            /* '<S106>/pi//(zeta*T_transfer)//s' */
  real_T Product;                      /* '<S100>/Product' */
  real_T Forsavingpositionandvelocityu_n;/* '<S109>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers_f;          /* '<S109>/pi//(zeta*T_transfer)//s' */
  real_T Product_k;                    /* '<S104>/Product' */
  real_T Divide1;                      /* '<S104>/Divide1' */
  real_T Constant6;                    /* '<S94>/Constant6' */
  real_T Constant5;                    /* '<S94>/Constant5' */
  real_T UnitDelay1;                   /* '<S94>/Unit Delay1' */
  real_T Divide2;                      /* '<S104>/Divide2' */
  real_T Constant7;                    /* '<S94>/Constant7' */
  real_T Constant4;                    /* '<S94>/Constant4' */
  real_T UnitDelay2;                   /* '<S94>/Unit Delay2' */
  real_T Forsavingpositionandvelocityu_o;/* '<S112>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers_j;          /* '<S112>/pi//(zeta*T_transfer)//s' */
  real_T Product_g;                    /* '<S102>/Product' */
  real_T Constant8;                    /* '<S94>/Constant8' */
  real_T Constant3;                    /* '<S94>/Constant3' */
  real_T UnitDelay3;                   /* '<S94>/Unit Delay3' */
  real_T UnitDelay1_g;                 /* '<S71>/Unit Delay1' */
  real_T UnitDelay2_b;                 /* '<S71>/Unit Delay2' */
  real_T Forsavingpositionandvelocityu_m;/* '<S122>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers_i;          /* '<S122>/pi//(zeta*T_transfer)//s' */
  real_T Product_f[2];                 /* '<S71>/Product' */
  real_T Sum9;                         /* '<S3>/Sum9' */
  real_T Sum15;                        /* '<S3>/Sum15' */
  real_T TargetPSI;                    /* '<S3>/Target PSI' */
  real_T Sum;                          /* '<S3>/Sum' */
  real_T Sum11;                        /* '<S3>/Sum11' */
  real_T Product3;                     /* '<S75>/Product3' */
  real_T MathFunction;                 /* '<S75>/Math Function' */
  real_T Forsavingpositionandvelocityu_d;/* '<S86>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers_b;          /* '<S86>/pi//(zeta*T_transfer)//s' */
  real_T DataTypeConversion4;          /* '<S75>/Data Type Conversion4' */
  real_T Gain;                         /* '<S66>/Gain' */
  real_T Sum17;                        /* '<S3>/Sum17' */
  real_T Product3_l;                   /* '<S73>/Product3' */
  real_T MathFunction_f;               /* '<S73>/Math Function' */
  real_T Forsavingpositionandvelocityu_g;/* '<S78>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers_l;          /* '<S78>/pi//(zeta*T_transfer)//s' */
  real_T DataTypeConversion4_a;        /* '<S73>/Data Type Conversion4' */
  real_T Gain1;                        /* '<S66>/Gain1' */
  real_T Sum16;                        /* '<S3>/Sum16' */
  real_T Product3_p;                   /* '<S74>/Product3' */
  real_T MathFunction_i;               /* '<S74>/Math Function' */
  real_T Forsavingpositionandvelocityu_p;/* '<S82>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers_e;          /* '<S82>/pi//(zeta*T_transfer)//s' */
  real_T DataTypeConversion4_c;        /* '<S74>/Data Type Conversion4' */
  real_T Gain2;                        /* '<S66>/Gain2' */
  real_T Sum3;                         /* '<S3>/Sum3' */
  real_T Sum_i[6];                     /* '<S134>/Sum' */
  real_T DataTypeConversion1;          /* '<S70>/Data Type Conversion1' */
  real_T UnitDelay_k[3];               /* '<Root>/Unit Delay' */
  real_T DiscreteTimeIntegrator;       /* '<S11>/Discrete-Time Integrator' */
  real_T Divide;                       /* '<S11>/Divide' */
  real_T Gain_j[3];                    /* '<S3>/Gain' */
  real_T Constant7_n;                  /* '<S3>/Constant7' */
  real_T Constant6_d;                  /* '<S3>/Constant6' */
  real_T DataTypeConversion[3];        /* '<S3>/Data Type Conversion' */
  real_T UnitDelay2_d;                 /* '<S70>/Unit Delay2' */
  real_T Switch2;                      /* '<S70>/Switch2' */
  real_T Switch4[3];                   /* '<S94>/Switch4' */
  real_T Sum1;                         /* '<S3>/Sum1' */
  real_T Sum8;                         /* '<S3>/Sum8' */
  real_T Sum4;                         /* '<S3>/Sum4' */
  real_T Sum7;                         /* '<S3>/Sum7' */
  real_T Sum5;                         /* '<S3>/Sum5' */
  real_T Sum12;                        /* '<S3>/Sum12' */
  real_T Abs2;                         /* '<S47>/Abs2' */
  real_T UnitDelay_i[6];               /* '<S131>/Unit Delay' */
  real_T Switch1_e;                    /* '<S131>/Switch1' */
  real_T Sum_p[6];                     /* '<S138>/Sum' */
  real_T DiscreteTimeIntegrator1_j[6]; /* '<S138>/Discrete-Time Integrator1' */
  real_T Sum_l[6];                     /* '<S135>/Sum' */
  real_T Sum1_n[6];                    /* '<S135>/Sum1' */
  real_T Switch[7];                    /* '<S131>/Switch' */
  real_T Sum_j[6];                     /* '<S137>/Sum' */
  real_T Sum2;                         /* '<S8>/Sum2' */
  real_T Sum_d[6];                     /* '<S8>/Sum' */
  real_T ButterworthFilter10Hz[6];     /* '<S8>/Butterworth Filter 10 Hz' */
  real_T Switch_e[6];                  /* '<Root>/Switch' */
  real_T Abs1;                         /* '<S47>/Abs1' */
  real_T Switch1_n;                    /* '<S47>/Switch1' */
  real_T AccLimiterA1;                 /* '<S15>/Acc Limiter A1' */
  real_T Abs2_b;                       /* '<S48>/Abs2' */
  real_T Abs1_f;                       /* '<S48>/Abs1' */
  real_T Switch1_c;                    /* '<S48>/Switch1' */
  real_T AccLimiterA2;                 /* '<S15>/Acc Limiter A2' */
  real_T Abs2_bs;                      /* '<S49>/Abs2' */
  real_T Abs1_e;                       /* '<S49>/Abs1' */
  real_T Switch1_nz;                   /* '<S49>/Switch1' */
  real_T AccLimiterA3;                 /* '<S15>/Acc Limiter A3' */
  real_T Abs2_l;                       /* '<S50>/Abs2' */
  real_T Abs1_j;                       /* '<S50>/Abs1' */
  real_T Switch1_h;                    /* '<S50>/Switch1' */
  real_T AccLimiterA4;                 /* '<S15>/Acc Limiter A4' */
  real_T Abs2_a;                       /* '<S51>/Abs2' */
  real_T Abs1_i;                       /* '<S51>/Abs1' */
  real_T Switch1_l;                    /* '<S51>/Switch1' */
  real_T AccLimiterA5;                 /* '<S15>/Acc Limiter A5' */
  real_T Abs2_lm;                      /* '<S52>/Abs2' */
  real_T Abs1_o;                       /* '<S52>/Abs1' */
  real_T Switch1_j;                    /* '<S52>/Switch1' */
  real_T AccLimiterA6;                 /* '<S15>/Acc Limiter A6' */
  real_T Gain_ju;                      /* '<S13>/Gain' */
  real_T Gain1_i;                      /* '<S13>/Gain1' */
  real_T Gain2_n;                      /* '<S13>/Gain2' */
  real_T Gain3;                        /* '<S13>/Gain3' */
  real_T Gain4;                        /* '<S13>/Gain4' */
  real_T Gain5;                        /* '<S13>/Gain5' */
  real_T TSamp;                        /* '<S79>/TSamp' */
  real_T zetaT_transferpi;             /* '<S78>/(zeta*T_transfer)//pi' */
  real_T zetapi;                       /* '<S78>/4*zeta*pi' */
  real_T pizeta;                       /* '<S78>/pi//zeta' */
  real_T TSamp_j;                      /* '<S83>/TSamp' */
  real_T zetaT_transferpi_g;           /* '<S82>/(zeta*T_transfer)//pi' */
  real_T zetapi_a;                     /* '<S82>/4*zeta*pi' */
  real_T pizeta_f;                     /* '<S82>/pi//zeta' */
  real_T TSamp_o;                      /* '<S87>/TSamp' */
  real_T zetaT_transferpi_d;           /* '<S86>/(zeta*T_transfer)//pi' */
  real_T zetapi_l;                     /* '<S86>/4*zeta*pi' */
  real_T pizeta_o;                     /* '<S86>/pi//zeta' */
  real_T MultiportSwitch[2];           /* '<S71>/Multiport Switch' */
  real_T Constant3_g;                  /* '<S71>/Constant3' */
  real_T Switch3[3];                   /* '<S94>/Switch3' */
  real_T Product_m[3];                 /* '<S94>/Product' */
  real_T Constant9;                    /* '<S94>/Constant9' */
  real_T Switch1_ho[3];                /* '<S94>/Switch1' */
  real_T Fcn1;                         /* '<S94>/Fcn1' */
  real_T pizetaT_transfers_lu;         /* '<S105>/pi//(zeta*T_transfer)//s' */
  real_T zetapi_c;                     /* '<S105>/4*zeta*pi' */
  real_T pizeta_k;                     /* '<S105>/pi//zeta' */
  real_T TSamp_f;                      /* '<S107>/TSamp' */
  real_T zetaT_transferpi_e;           /* '<S106>/(zeta*T_transfer)//pi' */
  real_T zetapi_lp;                    /* '<S106>/4*zeta*pi' */
  real_T pizeta_p;                     /* '<S106>/pi//zeta' */
  real_T pizetaT_transfers_in;         /* '<S108>/pi//(zeta*T_transfer)//s' */
  real_T zetapi_b;                     /* '<S108>/4*zeta*pi' */
  real_T pizeta_l;                     /* '<S108>/pi//zeta' */
  real_T TSamp_n;                      /* '<S110>/TSamp' */
  real_T zetaT_transferpi_l;           /* '<S109>/(zeta*T_transfer)//pi' */
  real_T zetapi_p;                     /* '<S109>/4*zeta*pi' */
  real_T pizeta_kx;                    /* '<S109>/pi//zeta' */
  real_T pizetaT_transfers_p;          /* '<S111>/pi//(zeta*T_transfer)//s' */
  real_T zetapi_i;                     /* '<S111>/4*zeta*pi' */
  real_T pizeta_k5;                    /* '<S111>/pi//zeta' */
  real_T TSamp_i;                      /* '<S113>/TSamp' */
  real_T zetaT_transferpi_f;           /* '<S112>/(zeta*T_transfer)//pi' */
  real_T zetapi_m;                     /* '<S112>/4*zeta*pi' */
  real_T pizeta_c;                     /* '<S112>/pi//zeta' */
  real_T zetapi_a4[3];                 /* '<S103>/4*zeta*pi' */
  real_T pizeta_ck[3];                 /* '<S103>/pi//zeta' */
  real_T TSamp_g;                      /* '<S123>/TSamp' */
  real_T zetaT_transferpi_de;          /* '<S122>/(zeta*T_transfer)//pi' */
  real_T zetapi_k;                     /* '<S122>/4*zeta*pi' */
  real_T pizeta_a;                     /* '<S122>/pi//zeta' */
  real_T Gain_jv[6];                   /* '<S135>/Gain' */
  real_T Gain1_o[6];                   /* '<S138>/Gain1' */
  real_T Sum_k[3];                     /* '<Root>/Sum' */
  real_T out[7];                       /* '<S142>/Embedded MATLAB Function3' */
  real_T out_m[6];                     /* '<S142>/Embedded MATLAB Function2' */
  real_T out_f[7];                     /* '<S142>/Embedded MATLAB Function1' */
  real_T out_a[7];                     /* '<S139>/Embedded MATLAB Function' */
  real_T SwitchControl[7];             /* '<S136>/SwitchControl' */
  real_T Sum1_a[6];                    /* '<S138>/Sum1' */
  real_T out_o[6];                     /* '<S129>/Embedded MATLAB Function' */
  real_T target_ang_speed[3];          /* '<S72>/Embedded MATLAB Function2' */
  real_T mask[3];                      /* '<S72>/Embedded MATLAB Function2' */
  real_T vis_cond;                     /* '<S72>/Embedded MATLAB Function2' */
  real_T flag_out;                     /* '<S72>/Embedded MATLAB Function2' */
  real_T endOffile_out;                /* '<S72>/Embedded MATLAB Function2' */
  real_T status;                       /* '<S71>/Embedded MATLAB Function3' */
  real_T xytoz;                        /* '<S71>/Embedded MATLAB Function2' */
  real_T gradual_state;                /* '<S71>/Embedded MATLAB Function2' */
  real_T mod;                          /* '<S71>/Embedded MATLAB Function2' */
  real_T current_axis;                 /* '<S71>/Embedded MATLAB Function2' */
  real_T start_next;                   /* '<S70>/Embedded MATLAB Function1' */
  real_T y;                            /* '<S70>/Embedded MATLAB Function' */
  real_T ac_out;                       /* '<S70>/Embedded MATLAB Function' */
  real_T R;                            /* '<S104>/Get R' */
  real_T T;                            /* '<S94>/Embedded MATLAB Function3' */
  real_T y_h;                          /* '<S94>/Embedded MATLAB Function1' */
  real_T gain;                         /* '<S94>/Embedded MATLAB Function1' */
  real_T Switch_l[3];                  /* '<S69>/Switch' */
  real_T max_tilt;                     /* '<S93>/Embedded MATLAB Function3' */
  real_T MultiportSwitch_l[6];         /* '<S68>/Multiport Switch' */
  real_T Forsavingpositionandvelocityu_k;/* '<S88>/For saving position  and velocity until after switchover' */
  real_T TSamp_o3;                     /* '<S91>/TSamp' */
  real_T zetaT_transferpi_h;           /* '<S88>/(zeta*T_transfer)//pi' */
  real_T pizetaT_transfers_g;          /* '<S88>/pi//(zeta*T_transfer)//s' */
  real_T zetapi_la;                    /* '<S88>/4*zeta*pi' */
  real_T pizeta_b;                     /* '<S88>/pi//zeta' */
  real_T x;                            /* '<S68>/curve' */
  real_T z;                            /* '<S68>/curve' */
  real_T psi;                          /* '<S68>/curve' */
  real_T c[3];                         /* '<S68>/curve' */
  real_T z_p[3];                       /* '<S68>/curve' */
  real_T set_out[6];                   /* '<S89>/Embedded MATLAB Function' */
  real_T stick_out[3];                 /* '<S3>/Embedded MATLAB Function' */
  real_T Switch_k;                     /* '<S52>/Switch' */
  real_T Switch_h;                     /* '<S51>/Switch' */
  real_T Switch_i;                     /* '<S50>/Switch' */
  real_T Switch_kx;                    /* '<S49>/Switch' */
  real_T Switch_p;                     /* '<S48>/Switch' */
  real_T Switch_n;                     /* '<S53>/Switch' */
  real_T Switch_hj;                    /* '<S47>/Switch' */
  real_T SwitchControl_g[6];           /* '<S9>/SwitchControl' */
  real_T TmpSignalConversionAtSFunctionI[12];/* '<S142>/Embedded MATLAB Function3' */
  real_T TmpSignalConversionAtSFunctio_i[12];/* '<S142>/Embedded MATLAB Function1' */
  real_T TmpSignalConversionAtSFunctio_f[12];/* '<S139>/Embedded MATLAB Function' */
  real_T TmpSignalConversionAtSFuncti_ii[3];/* '<S93>/Embedded MATLAB Function3' */
  real_T ControlLoopGain[6];           /* '<S8>/Control Loop Gain' */
  real_T Divide1_h;                    /* '<S88>/Divide1' */
  real_T Gain3_o;                      /* '<S94>/Gain3' */
  real_T DiscreteTimeIntegrator_k[6];  /* '<S135>/Discrete-Time Integrator' */
  real_T Sum6[6];                      /* '<S130>/Sum6' */
  real_T Divide1_c;                    /* '<S112>/Divide1' */
  real_T Divide_c[3];                  /* '<S103>/Divide' */
  real_T Divide1_e[3];                 /* '<S103>/Divide1' */
  real_T Divide_f;                     /* '<S88>/Divide' */
  real_T Divide_i;                     /* '<S122>/Divide' */
  real_T Divide1_d;                    /* '<S122>/Divide1' */
  real_T shift;                        /* '<S46>/shift' */
  real_T Divide_n;                     /* '<S111>/Divide' */
  real_T Divide_a;                     /* '<S106>/Divide' */
  real_T Divide1_a;                    /* '<S109>/Divide1' */
  int64m_T Gain_c;                     /* '<S12>/Gain' */
  int64m_T Gain2_i;                    /* '<S12>/Gain2' */
  int64m_T Gain6;                      /* '<S12>/Gain6' */
  int64m_T Gain1_k;                    /* '<S12>/Gain1' */
  int64m_T Gain3_d;                    /* '<S12>/Gain3' */
  int64m_T Gain4_k;                    /* '<S12>/Gain4' */
  real32_T Unpack_o2;                  /* '<S4>/Unpack' */
  real32_T Unpack_o3[6];               /* '<S4>/Unpack' */
  real32_T Unpack_o4[6];               /* '<S4>/Unpack' */
  real32_T Unpack_o5;                  /* '<S4>/Unpack' */
  real32_T Unpack_o1[3];               /* '<S126>/Unpack' */
  real32_T Unpack_o3_f;                /* '<S126>/Unpack' */
  real32_T Unpack_o4_c;                /* '<S126>/Unpack' */
  real32_T Gain1_g[3];                 /* '<S10>/Gain1' */
  real32_T DataTypeConversion1_p[3];   /* '<S3>/Data Type Conversion1' */
  real32_T Abs;                        /* '<S70>/Abs' */
  real32_T DataTypeConversion6;        /* '<S125>/Data Type Conversion6' */
  real32_T DataTypeConversion7;        /* '<S125>/Data Type Conversion7' */
  real32_T DataTypeConversion_g[6];    /* '<S125>/Data Type Conversion' */
  real32_T DataTypeConversion3[6];     /* '<S125>/Data Type Conversion3' */
  real32_T DataTypeConversion5;        /* '<S125>/Data Type Conversion5' */
  real32_T DataTypeConversion8[3];     /* '<S125>/Data Type Conversion8' */
  real32_T DataTypeConversion9[3];     /* '<S125>/Data Type Conversion9' */
  real32_T DataTypeConversion10;       /* '<S125>/Data Type Conversion10' */
  real32_T DataTypeConversion11[3];    /* '<S125>/Data Type Conversion11' */
  real32_T DataTypeConversion14;       /* '<S125>/Data Type Conversion14' */
  real32_T DataTypeConversion16[3];    /* '<S125>/Data Type Conversion16' */
  real32_T DataTypeConversion17[3];    /* '<S125>/Data Type Conversion17' */
  real32_T Limitto1[3];                /* '<S94>/Limit to +-1' */
  real32_T DataTypeConversion_o[6];    /* '<S1>/Data Type Conversion' */
  real32_T DataTypeConversion6_o;      /* '<S1>/Data Type Conversion6' */
  real32_T ButterworthFilter10Hz_m[3]; /* '<S10>/Butterworth Filter 10 Hz' */
  real32_T SumofElements;              /* '<S70>/Sum of Elements' */
  real32_T Gain2_nl;                   /* '<S10>/Gain2' */
  int32_T GTRTUDPRX_o6;                /* '<S4>/GT-RT UDP RX' */
  int32_T GTRTUDPRX_o6_m;              /* '<S126>/GT-RT UDP RX' */
  int32_T GTRTCANRX1_o1;               /* '<S12>/GT-RT CAN RX1' */
  int32_T GTRTCANRX2_o1;               /* '<S12>/GT-RT CAN RX2' */
  int32_T GTRTCANRX3_o1;               /* '<S12>/GT-RT CAN RX3' */
  int32_T GTRTCANRX2_o1_c;             /* '<S7>/GT-RT CAN RX2' */
  int32_T GTRTUDPTX1;                  /* '<S125>/GT-RT UDP TX1' */
  int32_T GTRTUDPTX;                   /* '<S125>/GT-RT UDP TX' */
  int32_T GTRTUDPTX_i;                 /* '<S1>/GT-RT UDP TX' */
  int32_T Add;                         /* '<S21>/Add' */
  uint32_T GTRTUDPRX_o2;               /* '<S4>/GT-RT UDP RX' */
  uint32_T GTRTUDPRX_o2_p;             /* '<S126>/GT-RT UDP RX' */
  uint32_T GTRTCANRX1_o6;              /* '<S12>/GT-RT CAN RX1' */
  uint32_T GTRTCANRX2_o6;              /* '<S12>/GT-RT CAN RX2' */
  uint32_T GTRTCANRX3_o6;              /* '<S12>/GT-RT CAN RX3' */
  uint32_T GTRTCANRX2_o6_m;            /* '<S7>/GT-RT CAN RX2' */
  uint16_T GTRTUDPRX_o5;               /* '<S4>/GT-RT UDP RX' */
  uint16_T GTRTUDPRX_o5_m;             /* '<S126>/GT-RT UDP RX' */
  uint16_T Gain4_g;                    /* '<S21>/Gain4' */
  uint16_T Gain3_f;                    /* '<S21>/Gain3' */
  uint16_T Gain2_k;                    /* '<S21>/Gain2' */
  uint8_T GTRTUDPRX_o1[66];            /* '<S4>/GT-RT UDP RX' */
  uint8_T GTRTUDPRX_o4[4];             /* '<S4>/GT-RT UDP RX' */
  uint8_T Unpack_o1_m[10];             /* '<S4>/Unpack' */
  uint8_T GTRTUDPRX_o1_h[28];          /* '<S126>/GT-RT UDP RX' */
  uint8_T GTRTUDPRX_o4_j[4];           /* '<S126>/GT-RT UDP RX' */
  uint8_T Unpack_o2_c[8];              /* '<S126>/Unpack' */
  uint8_T DataTypeConversion4_o;       /* '<S70>/Data Type Conversion4' */
  uint8_T Compare;                     /* '<S84>/Compare' */
  uint8_T Compare_c;                   /* '<S76>/Compare' */
  uint8_T Compare_b;                   /* '<S80>/Compare' */
  uint8_T GTRTCANRX1_o2[8];            /* '<S12>/GT-RT CAN RX1' */
  uint8_T GTRTCANRX1_o3;               /* '<S12>/GT-RT CAN RX1' */
  uint8_T GTRTCANRX1_o4;               /* '<S12>/GT-RT CAN RX1' */
  uint8_T GTRTCANRX2_o2[8];            /* '<S12>/GT-RT CAN RX2' */
  uint8_T GTRTCANRX2_o3;               /* '<S12>/GT-RT CAN RX2' */
  uint8_T GTRTCANRX2_o4;               /* '<S12>/GT-RT CAN RX2' */
  uint8_T GTRTCANRX3_o2[8];            /* '<S12>/GT-RT CAN RX3' */
  uint8_T GTRTCANRX3_o3;               /* '<S12>/GT-RT CAN RX3' */
  uint8_T GTRTCANRX3_o4;               /* '<S12>/GT-RT CAN RX3' */
  uint8_T GTRTCANRX2_o2_n[8];          /* '<S7>/GT-RT CAN RX2' */
  uint8_T GTRTCANRX2_o3_i;             /* '<S7>/GT-RT CAN RX2' */
  uint8_T GTRTCANRX2_o4_g;             /* '<S7>/GT-RT CAN RX2' */
  uint8_T BytePacking3[8];             /* '<S125>/Byte Packing 3' */
  uint8_T DataTypeConversion4_d;       /* '<S125>/Data Type Conversion4' */
  uint8_T DataTypeConversion12;        /* '<S125>/Data Type Conversion12' */
  uint8_T DataTypeConversion13;        /* '<S125>/Data Type Conversion13' */
  uint8_T DataTypeConversion19;        /* '<S125>/Data Type Conversion19' */
  uint8_T DataTypeConversion18;        /* '<S125>/Data Type Conversion18' */
  uint8_T BytePacking[161];            /* '<S125>/Byte Packing ' */
  uint8_T Gain1_e;                     /* '<S23>/Gain1' */
  uint8_T Gain2_j;                     /* '<S23>/Gain2' */
  uint8_T Gain3_c;                     /* '<S23>/Gain3' */
  uint8_T Gain4_f;                     /* '<S23>/Gain4' */
  uint8_T Gain1_n;                     /* '<S24>/Gain1' */
  uint8_T Gain2_d;                     /* '<S24>/Gain2' */
  uint8_T Gain3_m;                     /* '<S24>/Gain3' */
  uint8_T Gain4_l;                     /* '<S24>/Gain4' */
  uint8_T Gain1_nr;                    /* '<S25>/Gain1' */
  uint8_T Gain2_da;                    /* '<S25>/Gain2' */
  uint8_T Gain3_dw;                    /* '<S25>/Gain3' */
  uint8_T Gain4_kd;                    /* '<S25>/Gain4' */
  uint8_T Gain1_f;                     /* '<S26>/Gain1' */
  uint8_T Gain2_a;                     /* '<S26>/Gain2' */
  uint8_T Gain3_n;                     /* '<S26>/Gain3' */
  uint8_T Gain4_k1;                    /* '<S26>/Gain4' */
  uint8_T Gain1_a;                     /* '<S27>/Gain1' */
  uint8_T Gain2_f;                     /* '<S27>/Gain2' */
  uint8_T Gain3_d1;                    /* '<S27>/Gain3' */
  uint8_T Gain4_j;                     /* '<S27>/Gain4' */
  uint8_T Gain1_c;                     /* '<S28>/Gain1' */
  uint8_T Gain2_dk;                    /* '<S28>/Gain2' */
  uint8_T Gain3_fg;                    /* '<S28>/Gain3' */
  uint8_T Gain4_kf;                    /* '<S28>/Gain4' */
  uint8_T BytePacking_e[32];           /* '<S1>/Byte Packing ' */
  uint8_T Compare_g;                   /* '<S115>/Compare' */
  uint8_T Compare_n;                   /* '<S116>/Compare' */
  uint8_T DataTypeConversion6_n;       /* '<S3>/Data Type Conversion6' */
  boolean_T GTRTUDPRX_o3;              /* '<S4>/GT-RT UDP RX' */
  boolean_T GTRTUDPRX_o3_p;            /* '<S126>/GT-RT UDP RX' */
  boolean_T UnitDelay_c;               /* '<S69>/Unit Delay' */
  boolean_T UnitDelay1_f;              /* '<S70>/Unit Delay1' */
  boolean_T UnitDelay_e;               /* '<S70>/Unit Delay' */
  boolean_T LogicalOperator6;          /* '<S70>/Logical Operator6' */
  boolean_T LogicalOperator1;          /* '<S70>/Logical Operator1' */
  boolean_T LogicalOperator5;          /* '<S94>/Logical Operator5' */
  boolean_T LogicalOperator7;          /* '<S93>/Logical Operator7' */
  boolean_T GTRTCANRX1_o5;             /* '<S12>/GT-RT CAN RX1' */
  boolean_T GTRTCANRX2_o5;             /* '<S12>/GT-RT CAN RX2' */
  boolean_T GTRTCANRX3_o5;             /* '<S12>/GT-RT CAN RX3' */
  boolean_T LogicalOperator6_n;        /* '<S3>/Logical Operator6' */
  boolean_T SwitchControl_b;           /* '<S6>/SwitchControl' */
  boolean_T LogicalOperator1_i;        /* '<Root>/Logical Operator1' */
  boolean_T LogicalOperator;           /* '<S93>/Logical Operator' */
  boolean_T LogicalOperator8;          /* '<S93>/Logical Operator8' */
  boolean_T LogicalOperator10;         /* '<S70>/Logical Operator10' */
  boolean_T GTRTCANRX2_o5_d;           /* '<S7>/GT-RT CAN RX2' */
  boolean_T LogicalOperator3;          /* '<S94>/Logical Operator3' */
  boolean_T LogicalOperator_a;         /* '<S69>/Logical Operator' */
  boolean_T LogicalOperator4;          /* '<S93>/Logical Operator4' */
  boolean_T LogicalOperator1_h;        /* '<S93>/Logical Operator1' */
  boolean_T LogicalOperator2;          /* '<S94>/Logical Operator2' */
  rtB_EmbeddedMATLABFunction2_M37 sf_EmbeddedMATLABFunction5;/* '<S94>/Embedded MATLAB Function5' */
  rtB_EmbeddedMATLABFunction2_M37 sf_EmbeddedMATLABFunction2_j;/* '<S94>/Embedded MATLAB Function2' */
  rtB_IfActionSubsystem1_M37_Sim_ IfActionSubsystem1_n5;/* '<S52>/If Action Subsystem1' */
  rtB_IfActionSubsystem_M37_Sim_F IfActionSubsystem_p;/* '<S52>/If Action Subsystem' */
  rtB_IfActionSubsystem1_M37_Sim_ IfActionSubsystem1_p;/* '<S51>/If Action Subsystem1' */
  rtB_IfActionSubsystem_M37_Sim_F IfActionSubsystem_n;/* '<S51>/If Action Subsystem' */
  rtB_IfActionSubsystem1_M37_Sim_ IfActionSubsystem1_n;/* '<S50>/If Action Subsystem1' */
  rtB_IfActionSubsystem_M37_Sim_F IfActionSubsystem_m;/* '<S50>/If Action Subsystem' */
  rtB_IfActionSubsystem1_M37_Sim_ IfActionSubsystem1_h;/* '<S49>/If Action Subsystem1' */
  rtB_IfActionSubsystem_M37_Sim_F IfActionSubsystem_c;/* '<S49>/If Action Subsystem' */
  rtB_IfActionSubsystem1_M37_Sim_ IfActionSubsystem1_e;/* '<S48>/If Action Subsystem1' */
  rtB_IfActionSubsystem_M37_Sim_F IfActionSubsystem_h;/* '<S48>/If Action Subsystem' */
  rtB_IfActionSubsystem1_M37_Sim_ IfActionSubsystem1;/* '<S47>/If Action Subsystem1' */
} BlockIO_M37_Sim_Forcing_003h_expe_infra_transz_lim;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S100>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S70>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator1_DSTAT_f;/* '<S70>/Discrete-Time Integrator1' */
  real_T UnitDelay4_DSTATE;            /* '<S70>/Unit Delay4' */
  real_T UnitDelay_DSTATE;             /* '<S72>/Unit Delay' */
  real_T Forsavingpositionandvelocityunt;/* '<S106>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers_DSTATE;     /* '<S106>/pi//(zeta*T_transfer)//s' */
  real_T DiscreteTimeIntegrator1_DSTAT_o;/* '<S101>/Discrete-Time Integrator1' */
  real_T Forsavingpositionandvelocityu_g;/* '<S109>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers_DSTATE_h;   /* '<S109>/pi//(zeta*T_transfer)//s' */
  real_T UnitDelay1_DSTATE;            /* '<S94>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S94>/Unit Delay2' */
  real_T DiscreteTimeIntegrator1_DSTAT_n;/* '<S102>/Discrete-Time Integrator1' */
  real_T Forsavingpositionandvelocityu_b;/* '<S112>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers_DSTATE_l;   /* '<S112>/pi//(zeta*T_transfer)//s' */
  real_T UnitDelay3_DSTATE;            /* '<S94>/Unit Delay3' */
  real_T UnitDelay1_DSTATE_b;          /* '<S71>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_h;          /* '<S71>/Unit Delay2' */
  real_T Forsavingpositionandvelocityu_m;/* '<S122>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers_DSTATE_g;   /* '<S122>/pi//(zeta*T_transfer)//s' */
  real_T UnitDelay_DSTATE_a;           /* '<S75>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e;          /* '<S75>/Unit Delay1' */
  real_T s_DSTATE;                     /* '<S75>/1//s' */
  real_T Forsavingpositionandvelocityu_c;/* '<S86>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers_DSTATE_d;   /* '<S86>/pi//(zeta*T_transfer)//s' */
  real_T UnitDelay_DSTATE_e;           /* '<S73>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g;          /* '<S73>/Unit Delay1' */
  real_T s_DSTATE_i;                   /* '<S73>/1//s' */
  real_T Forsavingpositionandvelocityu_a;/* '<S78>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers_DSTATE_o;   /* '<S78>/pi//(zeta*T_transfer)//s' */
  real_T UnitDelay_DSTATE_ae;          /* '<S74>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S74>/Unit Delay1' */
  real_T s_DSTATE_k;                   /* '<S74>/1//s' */
  real_T Forsavingpositionandvelocityu_h;/* '<S82>/For saving position  and velocity until after switchover' */
  real_T pizetaT_transfers_DSTATE_a;   /* '<S82>/pi//(zeta*T_transfer)//s' */
  real_T UnitDelay_DSTATE_c[3];        /* '<Root>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S11>/Discrete-Time Integrator' */
  real_T UnitDelay3_DSTATE_a;          /* '<S70>/Unit Delay3' */
  real_T UnitDelay2_DSTATE_d;          /* '<S70>/Unit Delay2' */
  real_T pizetaT_transfers_DSTATE_i[3];/* '<S103>/pi//(zeta*T_transfer)//s' */
  real_T UnitDelay_DSTATE_ef[6];       /* '<S131>/Unit Delay' */
  real_T DiscreteTimeIntegrator1_DSTAT_d[6];/* '<S138>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_g[6];/* '<S135>/Discrete-Time Integrator' */
  real_T UnitDelay6_DSTATE[6];         /* '<S130>/Unit Delay6' */
  real_T ButterworthFilter10Hz_DSTATE[24];/* '<S8>/Butterworth Filter 10 Hz' */
  real_T UD_DSTATE;                    /* '<S79>/UD' */
  real_T zetapiT_transfers_DSTATE;     /* '<S78>/4*zeta*pi//T_transfer //s' */
  real_T UD_DSTATE_f;                  /* '<S83>/UD' */
  real_T zetapiT_transfers_DSTATE_j;   /* '<S82>/4*zeta*pi//T_transfer //s' */
  real_T UD_DSTATE_n;                  /* '<S87>/UD' */
  real_T zetapiT_transfers_DSTATE_k;   /* '<S86>/4*zeta*pi//T_transfer //s' */
  real_T UnitDelay_DSTATE_j[3];        /* '<S94>/Unit Delay' */
  real_T pizetaT_transfers_DSTATE_e;   /* '<S105>/pi//(zeta*T_transfer)//s' */
  real_T zetapiT_transfers_DSTATE_kq;  /* '<S105>/4*zeta*pi//T_transfer //s' */
  real_T UD_DSTATE_h;                  /* '<S107>/UD' */
  real_T zetapiT_transfers_DSTATE_g;   /* '<S106>/4*zeta*pi//T_transfer //s' */
  real_T pizetaT_transfers_DSTATE_d2;  /* '<S108>/pi//(zeta*T_transfer)//s' */
  real_T zetapiT_transfers_DSTATE_gb;  /* '<S108>/4*zeta*pi//T_transfer //s' */
  real_T UD_DSTATE_e;                  /* '<S110>/UD' */
  real_T zetapiT_transfers_DSTATE_gu;  /* '<S109>/4*zeta*pi//T_transfer //s' */
  real_T pizetaT_transfers_DSTATE_c;   /* '<S111>/pi//(zeta*T_transfer)//s' */
  real_T zetapiT_transfers_DSTATE_e;   /* '<S111>/4*zeta*pi//T_transfer //s' */
  real_T UD_DSTATE_g;                  /* '<S113>/UD' */
  real_T zetapiT_transfers_DSTATE_f;   /* '<S112>/4*zeta*pi//T_transfer //s' */
  real_T zetapiT_transfers_DSTATE_a[3];/* '<S103>/4*zeta*pi//T_transfer //s' */
  real_T UD_DSTATE_o;                  /* '<S123>/UD' */
  real_T zetapiT_transfers_DSTATE_l;   /* '<S122>/4*zeta*pi//T_transfer //s' */
  real_T Forsavingpositionandvelocityu_d;/* '<S88>/For saving position  and velocity until after switchover' */
  real_T UD_DSTATE_p;                  /* '<S91>/UD' */
  real_T pizetaT_transfers_DSTATE_f;   /* '<S88>/pi//(zeta*T_transfer)//s' */
  real_T zetapiT_transfers_DSTATE_jy;  /* '<S88>/4*zeta*pi//T_transfer //s' */
  real_T Sum20_DWORK1;                 /* '<S3>/Sum20' */
  real_T Sum1_DWORK1[6];               /* '<S8>/Sum1' */
  real_T ButterworthFilter10Hz_tmp[6]; /* '<S8>/Butterworth Filter 10 Hz' */
  real_T PrevY;                        /* '<S15>/Acc Limiter A1' */
  real_T PrevY_j;                      /* '<S15>/Acc Limiter A2' */
  real_T PrevY_f;                      /* '<S15>/Acc Limiter A3' */
  real_T PrevY_o;                      /* '<S15>/Acc Limiter A4' */
  real_T PrevY_l;                      /* '<S15>/Acc Limiter A5' */
  real_T PrevY_i;                      /* '<S15>/Acc Limiter A6' */
  void *GTRTUDPRX_PWORK;               /* '<S4>/GT-RT UDP RX' */
  void *GTRTUDPRead_PWORK;             /* '<S4>/GT-RT UDP  Read' */
  void *GTRTUDPRX_PWORK_b;             /* '<S126>/GT-RT UDP RX' */
  void *GTRTUDPRead_PWORK_l;           /* '<S126>/GT-RT UDP  Read' */
  void *GTRTCANRX1_PWORK;              /* '<S12>/GT-RT CAN RX1' */
  void *GTRTCANRX2_PWORK;              /* '<S12>/GT-RT CAN RX2' */
  void *GTRTCANRX3_PWORK;              /* '<S12>/GT-RT CAN RX3' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S94>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S94>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S94>/Scope2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_p;                    /* '<S131>/Scope1' */

  void *GTRTCANRX2_PWORK_b;            /* '<S7>/GT-RT CAN RX2' */
  void *GTRTCANController_PWORK;       /* '<Root>/GT-RT CAN Controller' */
  void *GTRTCANTX_PWORK;               /* '<S128>/GT-RT CAN TX' */
  void *GTRTCANTX_PWORK_n;             /* '<S127>/GT-RT CAN TX' */
  void *GTRTUDPTX1_PWORK[2];           /* '<S125>/GT-RT UDP TX1' */
  void *GTRTUDPTX_PWORK[2];            /* '<S125>/GT-RT UDP TX' */
  void *GTRTUDPWrite_PWORK;            /* '<S125>/GT-RT UDP  Write' */
  void *GTRTUDPWrite1_PWORK;           /* '<S125>/GT-RT UDP  Write1' */
  void *GTRTCANTX_PWORK_o;             /* '<S22>/GT-RT CAN TX' */
  void *GTRTCANTX1_PWORK;              /* '<S22>/GT-RT CAN TX1' */
  void *GTRTCANTX2_PWORK;              /* '<S22>/GT-RT CAN TX2' */
  void *GTRTUDPTX_PWORK_i[2];          /* '<S1>/GT-RT UDP TX' */
  void *GTRTUDPWrite_PWORK_e;          /* '<S1>/GT-RT UDP  Write' */
  real32_T ButterworthFilter10Hz_DSTATE_l[12];/* '<S10>/Butterworth Filter 10 Hz' */
  real32_T ButterworthFilter10Hz_tmp_b[3];/* '<S10>/Butterworth Filter 10 Hz' */
  uint32_T Counter_ClkEphState;        /* '<S3>/Counter' */
  uint32_T Add_DWORK1;                 /* '<S16>/Add' */
  int_T GTRTUDPRX_IWORK;               /* '<S4>/GT-RT UDP RX' */
  int_T GTRTUDPRX_IWORK_k;             /* '<S126>/GT-RT UDP RX' */
  int_T BytePacking3_IWORK[4];         /* '<S125>/Byte Packing 3' */
  int_T BytePacking_IWORK[38];         /* '<S125>/Byte Packing ' */
  int_T BytePacking_IWORK_k[6];        /* '<S1>/Byte Packing ' */
  boolean_T UnitDelay_DSTATE_c0;       /* '<S69>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_d;       /* '<S70>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_b;        /* '<S70>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_c1;       /* '<S93>/Unit Delay' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S100>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator2_PrevRes;/* '<S70>/Discrete-Time Integrator2' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S70>/Discrete-Time Integrator1' */
  int8_T pizetaT_transfers_PrevResetStat;/* '<S106>/pi//(zeta*T_transfer)//s' */
  int8_T DiscreteTimeIntegrator1_PrevR_a;/* '<S101>/Discrete-Time Integrator1' */
  int8_T pizetaT_transfers_PrevResetSt_b;/* '<S109>/pi//(zeta*T_transfer)//s' */
  int8_T DiscreteTimeIntegrator1_PrevR_n;/* '<S102>/Discrete-Time Integrator1' */
  int8_T pizetaT_transfers_PrevResetSt_i;/* '<S112>/pi//(zeta*T_transfer)//s' */
  int8_T pizetaT_transfers_PrevResetSt_f;/* '<S122>/pi//(zeta*T_transfer)//s' */
  int8_T MoveUP1_SubsysRanBC;          /* '<S3>/Move UP1' */
  int8_T s_PrevResetState;             /* '<S75>/1//s' */
  int8_T pizetaT_transfers_PrevResetSt_o;/* '<S86>/pi//(zeta*T_transfer)//s' */
  int8_T s_PrevResetState_k;           /* '<S73>/1//s' */
  int8_T pizetaT_transfers_PrevResetSt_k;/* '<S78>/pi//(zeta*T_transfer)//s' */
  int8_T s_PrevResetState_l;           /* '<S74>/1//s' */
  int8_T pizetaT_transfers_PrevResetSt_e;/* '<S82>/pi//(zeta*T_transfer)//s' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S11>/Discrete-Time Integrator' */
  int8_T _DOFControl_SubsysRanBC;      /* '<S5>/6_DOF Control' */
  int8_T _DOFVisualCab120615_SubsysRanBC;/* '<Root>/6_DOF Visual Cab 12//06//15' */
  int8_T SimplifiedInverseKin_SubsysRanB;/* '<S138>/Simplified Inverse Kin' */
  int8_T DiscreteTimeIntegrator1_PrevR_k;/* '<S138>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRe_i;/* '<S135>/Discrete-Time Integrator' */
  int8_T fullinversekin_SubsysRanBC;   /* '<S135>/full inverse kin' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S47>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S13>/If Action Subsystem1' */
  int8_T zetapiT_transfers_PrevResetStat;/* '<S78>/4*zeta*pi//T_transfer //s' */
  int8_T zetapiT_transfers_PrevResetSt_l;/* '<S82>/4*zeta*pi//T_transfer //s' */
  int8_T zetapiT_transfers_PrevResetSt_g;/* '<S86>/4*zeta*pi//T_transfer //s' */
  int8_T zetapiT_transfers_PrevResetS_lc;/* '<S106>/4*zeta*pi//T_transfer //s' */
  int8_T zetapiT_transfers_PrevResetSt_e;/* '<S109>/4*zeta*pi//T_transfer //s' */
  int8_T zetapiT_transfers_PrevResetSt_a;/* '<S112>/4*zeta*pi//T_transfer //s' */
  int8_T zetapiT_transfers_PrevResetSt_n;/* '<S122>/4*zeta*pi//T_transfer //s' */
  int8_T IfActionSubsystem_SubsysRanBC_i;/* '<S7>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_o;/* '<S7>/If Action Subsystem1' */
  int8_T pizetaT_transfers_PrevResetS_ot;/* '<S88>/pi//(zeta*T_transfer)//s' */
  int8_T zetapiT_transfers_PrevResetS_nn;/* '<S88>/4*zeta*pi//T_transfer //s' */
  uint8_T Counter_Count;               /* '<S3>/Counter' */
  uint8_T pizetaT_transfers_IC_LOADING;/* '<S106>/pi//(zeta*T_transfer)//s' */
  uint8_T pizetaT_transfers_IC_LOADING_j;/* '<S109>/pi//(zeta*T_transfer)//s' */
  uint8_T pizetaT_transfers_IC_LOADING_i;/* '<S112>/pi//(zeta*T_transfer)//s' */
  uint8_T pizetaT_transfers_IC_LOADING_d;/* '<S122>/pi//(zeta*T_transfer)//s' */
  uint8_T s_IC_LOADING;                /* '<S75>/1//s' */
  uint8_T pizetaT_transfers_IC_LOADING_iq;/* '<S86>/pi//(zeta*T_transfer)//s' */
  uint8_T s_IC_LOADING_d;              /* '<S73>/1//s' */
  uint8_T pizetaT_transfers_IC_LOADING_n;/* '<S78>/pi//(zeta*T_transfer)//s' */
  uint8_T s_IC_LOADING_e;              /* '<S74>/1//s' */
  uint8_T pizetaT_transfers_IC_LOADING_f;/* '<S82>/pi//(zeta*T_transfer)//s' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S138>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S135>/Discrete-Time Integrator' */
  uint8_T zetapiT_transfers_IC_LOADING;/* '<S78>/4*zeta*pi//T_transfer //s' */
  uint8_T zetapiT_transfers_IC_LOADING_j;/* '<S82>/4*zeta*pi//T_transfer //s' */
  uint8_T zetapiT_transfers_IC_LOADING_p;/* '<S86>/4*zeta*pi//T_transfer //s' */
  uint8_T zetapiT_transfers_IC_LOADING_m;/* '<S106>/4*zeta*pi//T_transfer //s' */
  uint8_T zetapiT_transfers_IC_LOADING_c;/* '<S109>/4*zeta*pi//T_transfer //s' */
  uint8_T zetapiT_transfers_IC_LOADING_n;/* '<S112>/4*zeta*pi//T_transfer //s' */
  uint8_T zetapiT_transfers_IC_LOADING_e;/* '<S122>/4*zeta*pi//T_transfer //s' */
  uint8_T is_active_c11_M37_Sim_Forcing_0;/* '<S142>/Embedded MATLAB Function3' */
  uint8_T is_active_c10_M37_Sim_Forcing_0;/* '<S142>/Embedded MATLAB Function2' */
  uint8_T is_active_c27_M37_Sim_Forcing_0;/* '<S142>/Embedded MATLAB Function1' */
  uint8_T is_active_c26_M37_Sim_Forcing_0;/* '<S139>/Embedded MATLAB Function' */
  uint8_T is_active_c23_M37_Sim_Forcing_0;/* '<S129>/Embedded MATLAB Function' */
  uint8_T is_active_c19_M37_Sim_Forcing_0;/* '<S72>/Embedded MATLAB Function2' */
  uint8_T is_active_c13_M37_Sim_Forcing_0;/* '<S71>/Embedded MATLAB Function3' */
  uint8_T is_active_c12_M37_Sim_Forcing_0;/* '<S71>/Embedded MATLAB Function2' */
  uint8_T is_active_c4_M37_Sim_Forcing_00;/* '<S70>/Embedded MATLAB Function1' */
  uint8_T is_active_c2_M37_Sim_Forcing_00;/* '<S70>/Embedded MATLAB Function' */
  uint8_T is_active_c3_M37_Sim_Forcing_00;/* '<S104>/Get R' */
  uint8_T is_active_c9_M37_Sim_Forcing_00;/* '<S94>/Embedded MATLAB Function3' */
  uint8_T is_active_c5_M37_Sim_Forcing_00;/* '<S94>/Embedded MATLAB Function1' */
  uint8_T is_active_c7_M37_Sim_Forcing_00;/* '<S93>/Embedded MATLAB Function3' */
  uint8_T pizetaT_transfers_IC_LOADING_o;/* '<S88>/pi//(zeta*T_transfer)//s' */
  uint8_T zetapiT_transfers_IC_LOADING_mw;/* '<S88>/4*zeta*pi//T_transfer //s' */
  uint8_T is_active_c8_M37_Sim_Forcing_00;/* '<S68>/curve' */
  uint8_T is_active_c1_M37_Sim_Forcing_00;/* '<S89>/Embedded MATLAB Function' */
  uint8_T is_active_c21_M37_Sim_Forcing_0;/* '<S3>/Embedded MATLAB Function' */
  boolean_T isStable;                  /* '<S142>/Embedded MATLAB Function3' */
  boolean_T doneDoubleBufferReInit;    /* '<S142>/Embedded MATLAB Function3' */
  boolean_T isStable_l;                /* '<S142>/Embedded MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_e;  /* '<S142>/Embedded MATLAB Function2' */
  boolean_T isStable_h;                /* '<S142>/Embedded MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_j;  /* '<S142>/Embedded MATLAB Function1' */
  boolean_T isStable_b;                /* '<S139>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S139>/Embedded MATLAB Function' */
  boolean_T isStable_k;                /* '<S129>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_p;  /* '<S129>/Embedded MATLAB Function' */
  boolean_T isStable_g;                /* '<S72>/Embedded MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_m;  /* '<S72>/Embedded MATLAB Function2' */
  boolean_T isStable_e;                /* '<S71>/Embedded MATLAB Function3' */
  boolean_T doneDoubleBufferReInit_g;  /* '<S71>/Embedded MATLAB Function3' */
  boolean_T isStable_m;                /* '<S71>/Embedded MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_b;  /* '<S71>/Embedded MATLAB Function2' */
  boolean_T isStable_n;                /* '<S70>/Embedded MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_f;  /* '<S70>/Embedded MATLAB Function1' */
  boolean_T isStable_o;                /* '<S70>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_a;  /* '<S70>/Embedded MATLAB Function' */
  boolean_T isStable_gm;               /* '<S104>/Get R' */
  boolean_T doneDoubleBufferReInit_gj; /* '<S104>/Get R' */
  boolean_T isStable_j;                /* '<S94>/Embedded MATLAB Function3' */
  boolean_T doneDoubleBufferReInit_k;  /* '<S94>/Embedded MATLAB Function3' */
  boolean_T isStable_f;                /* '<S94>/Embedded MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_ee; /* '<S94>/Embedded MATLAB Function1' */
  boolean_T isStable_n1;               /* '<S93>/Embedded MATLAB Function3' */
  boolean_T doneDoubleBufferReInit_jo; /* '<S93>/Embedded MATLAB Function3' */
  boolean_T isStable_c;                /* '<S68>/curve' */
  boolean_T doneDoubleBufferReInit_e5; /* '<S68>/curve' */
  boolean_T isStable_ox;               /* '<S89>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_i;  /* '<S89>/Embedded MATLAB Function' */
  boolean_T isStable_kt;               /* '<S3>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_gy; /* '<S3>/Embedded MATLAB Function' */
  rtDW_EmbeddedMATLABFunction2_M3 sf_EmbeddedMATLABFunction5;/* '<S94>/Embedded MATLAB Function5' */
  rtDW_EmbeddedMATLABFunction2_M3 sf_EmbeddedMATLABFunction2_j;/* '<S94>/Embedded MATLAB Function2' */
  rtDW_IfActionSubsystem1_M37_Sim IfActionSubsystem1_n5;/* '<S52>/If Action Subsystem1' */
  rtDW_IfActionSubsystem_M37_Sim_ IfActionSubsystem_p;/* '<S52>/If Action Subsystem' */
  rtDW_IfActionSubsystem1_M37_Sim IfActionSubsystem1_p;/* '<S51>/If Action Subsystem1' */
  rtDW_IfActionSubsystem_M37_Sim_ IfActionSubsystem_n;/* '<S51>/If Action Subsystem' */
  rtDW_IfActionSubsystem1_M37_Sim IfActionSubsystem1_n;/* '<S50>/If Action Subsystem1' */
  rtDW_IfActionSubsystem_M37_Sim_ IfActionSubsystem_m;/* '<S50>/If Action Subsystem' */
  rtDW_IfActionSubsystem1_M37_Sim IfActionSubsystem1_h;/* '<S49>/If Action Subsystem1' */
  rtDW_IfActionSubsystem_M37_Sim_ IfActionSubsystem_c;/* '<S49>/If Action Subsystem' */
  rtDW_IfActionSubsystem1_M37_Sim IfActionSubsystem1_e;/* '<S48>/If Action Subsystem1' */
  rtDW_IfActionSubsystem_M37_Sim_ IfActionSubsystem_h;/* '<S48>/If Action Subsystem' */
  rtDW_IfActionSubsystem1_M37_Sim IfActionSubsystem1;/* '<S47>/If Action Subsystem1' */
} D_Work_M37_Sim_Forcing_003h_expe_infra_transz_lim;

/* Backward compatible GRT Identifiers */
#define rtB                            M37_Sim_Forcing_003h_expe_infra_transz_lim_B
#define BlockIO                        BlockIO_M37_Sim_Forcing_003h_expe_infra_transz_lim
#define rtXdot                         M37_Sim_Forcing_003h_expe_infra_transz_lim_Xdot
#define StateDerivatives               StateDerivatives_M37_Sim_Forcing_003h_expe_infra_transz_lim
#define tXdis                          M37_Sim_Forcing_003h_expe_infra_transz_lim_Xdis
#define StateDisabled                  StateDisabled_M37_Sim_Forcing_003h_expe_infra_transz_lim
#define rtP                            M37_Sim_Forcing_003h_expe_infra_transz_lim_P
#define Parameters                     Parameters_M37_Sim_Forcing_003h_expe_infra_transz_lim
#define rtDWork                        M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork
#define D_Work                         D_Work_M37_Sim_Forcing_003h_expe_infra_transz_lim

/* Parameters for system: '<S47>/If Action Subsystem1' */
struct rtP_IfActionSubsystem1_M37_Sim__ {
  real_T PSEA2_Value;                  /* Expression: 0
                                        * Referenced by: '<S54>/PSEA2'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S54>/Switch'
                                        */
};

/* Parameters for system: '<S48>/If Action Subsystem' */
struct rtP_IfActionSubsystem_M37_Sim_F_ {
  real_T PSEA2_Value;                  /* Expression: 0
                                        * Referenced by: '<S55>/PSEA2'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S55>/Switch'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_M37_Sim_Forcing_003h_expe_infra_transz_lim_ {
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
  real_T GTRTUDPRX_P1_Size_e[2];       /* Computed Parameter: GTRTUDPRX_P1_Size_e
                                        * Referenced by: '<S126>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P1_h[29];           /* Computed Parameter: GTRTUDPRX_P1_h
                                        * Referenced by: '<S126>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P2_Size_i[2];       /* Computed Parameter: GTRTUDPRX_P2_Size_i
                                        * Referenced by: '<S126>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P2_n;               /* Expression: receive_buffer_size
                                        * Referenced by: '<S126>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P3_Size_g[2];       /* Computed Parameter: GTRTUDPRX_P3_Size_g
                                        * Referenced by: '<S126>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P3_l;               /* Expression: timeout
                                        * Referenced by: '<S126>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P4_Size_e[2];       /* Computed Parameter: GTRTUDPRX_P4_Size_e
                                        * Referenced by: '<S126>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRX_P4_o;               /* Expression: sample_time
                                        * Referenced by: '<S126>/GT-RT UDP RX'
                                        */
  real_T GTRTUDPRead_P1_Size_n[2];     /* Computed Parameter: GTRTUDPRead_P1_Size_n
                                        * Referenced by: '<S126>/GT-RT UDP  Read'
                                        */
  real_T GTRTUDPRead_P1_h[29];         /* Computed Parameter: GTRTUDPRead_P1_h
                                        * Referenced by: '<S126>/GT-RT UDP  Read'
                                        */
  real_T x_e2_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/x_e2'
                                        */
  real_T x_e1_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/x_e1'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S100>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S100>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                          * Referenced by: '<S70>/Discrete-Time Integrator2'
                                          */
  real_T DiscreteTimeIntegrator2_IC;   /* Expression: 0
                                        * Referenced by: '<S70>/Discrete-Time Integrator2'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * Referenced by: '<S115>/Constant'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_m;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_m
                                          * Referenced by: '<S70>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_f; /* Expression: 0
                                        * Referenced by: '<S70>/Discrete-Time Integrator1'
                                        */
  real_T Constant_Value_c;             /* Expression: const
                                        * Referenced by: '<S116>/Constant'
                                        */
  real_T UnitDelay4_X0;                /* Expression: 0
                                        * Referenced by: '<S70>/Unit Delay4'
                                        */
  real_T UnitDelay_X0;                 /* Expression: 0
                                        * Referenced by: '<S72>/Unit Delay'
                                        */
  real_T Forsavingpositionandvelocityunt;/* Expression: 0
                                          * Referenced by: '<S106>/For saving position  and velocity until after switchover'
                                          */
  real_T pizetaT_transfers_gainval;    /* Computed Parameter: pizetaT_transfers_gainval
                                        * Referenced by: '<S106>/pi//(zeta*T_transfer)//s'
                                        */
  real_T DiscreteTimeIntegrator1_gain_mo;/* Computed Parameter: DiscreteTimeIntegrator1_gain_mo
                                          * Referenced by: '<S101>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_h; /* Expression: 0
                                        * Referenced by: '<S101>/Discrete-Time Integrator1'
                                        */
  real_T Forsavingpositionandvelocityu_o;/* Expression: 0
                                          * Referenced by: '<S109>/For saving position  and velocity until after switchover'
                                          */
  real_T pizetaT_transfers_gainval_g;  /* Computed Parameter: pizetaT_transfers_gainval_g
                                        * Referenced by: '<S109>/pi//(zeta*T_transfer)//s'
                                        */
  real_T Constant11_Value;             /* Expression: 70
                                        * Referenced by: '<S94>/Constant11'
                                        */
  real_T Constant2_Value;              /* Expression: 120
                                        * Referenced by: '<S94>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S104>/Switch'
                                        */
  real_T Constant6_Value;              /* Expression: 75
                                        * Referenced by: '<S94>/Constant6'
                                        */
  real_T Constant5_Value;              /* Expression: 25
                                        * Referenced by: '<S94>/Constant5'
                                        */
  real_T UnitDelay1_X0;                /* Expression: 0
                                        * Referenced by: '<S94>/Unit Delay1'
                                        */
  real_T target_offset3_Value[2];      /* Expression: [103.45 100.8]
                                        * Referenced by: '<S71>/target_offset3'
                                        */
  real_T Constant7_Value;              /* Expression: 120
                                        * Referenced by: '<S94>/Constant7'
                                        */
  real_T Constant4_Value;              /* Expression: 25
                                        * Referenced by: '<S94>/Constant4'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S94>/Unit Delay2'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_n;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_n
                                          * Referenced by: '<S102>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_j; /* Expression: 0
                                        * Referenced by: '<S102>/Discrete-Time Integrator1'
                                        */
  real_T Forsavingpositionandvelocityu_c;/* Expression: 0
                                          * Referenced by: '<S112>/For saving position  and velocity until after switchover'
                                          */
  real_T pizetaT_transfers_gainval_o;  /* Computed Parameter: pizetaT_transfers_gainval_o
                                        * Referenced by: '<S112>/pi//(zeta*T_transfer)//s'
                                        */
  real_T Constant8_Value;              /* Expression: 70
                                        * Referenced by: '<S94>/Constant8'
                                        */
  real_T Constant3_Value;              /* Expression: 10
                                        * Referenced by: '<S94>/Constant3'
                                        */
  real_T UnitDelay3_X0;                /* Expression: 0
                                        * Referenced by: '<S94>/Unit Delay3'
                                        */
  real_T gain_Value;                   /* Expression: 0.004
                                        * Referenced by: '<S93>/gain'
                                        */
  real_T UnitDelay1_X0_f;              /* Expression: 0
                                        * Referenced by: '<S71>/Unit Delay1'
                                        */
  real_T UnitDelay2_X0_n;              /* Expression: 0
                                        * Referenced by: '<S71>/Unit Delay2'
                                        */
  real_T Forsavingpositionandvelocity_o5;/* Expression: 0
                                          * Referenced by: '<S122>/For saving position  and velocity until after switchover'
                                          */
  real_T pizetaT_transfers_gainval_k;  /* Computed Parameter: pizetaT_transfers_gainval_k
                                        * Referenced by: '<S122>/pi//(zeta*T_transfer)//s'
                                        */
  real_T Gain3_Gain;                   /* Expression: 10
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 10
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T y_e1_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/y_e1'
                                        */
  real_T TargetPSI_Value;              /* Expression: 0
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
  real_T Constant3_Value_o;            /* Expression: 1
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T z_e1_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/z_e1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 10
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T UnitDelay_X0_n;               /* Expression: 0
                                        * Referenced by: '<S75>/Unit Delay'
                                        */
  real_T Constant3_Value_n;            /* Expression: 60
                                        * Referenced by: '<S66>/Constant3'
                                        */
  real_T UnitDelay1_X0_j;              /* Expression: 0
                                        * Referenced by: '<S75>/Unit Delay1'
                                        */
  real_T s_gainval;                    /* Computed Parameter: s_gainval
                                        * Referenced by: '<S75>/1//s'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 2*pi
                                        * Referenced by: '<S75>/Gain1'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S66>/Constant'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: pi/180
                                        * Referenced by: '<S75>/Gain2'
                                        */
  real_T Forsavingpositionandvelocityu_n;/* Expression: 0
                                          * Referenced by: '<S86>/For saving position  and velocity until after switchover'
                                          */
  real_T pizetaT_transfers_gainval_l;  /* Computed Parameter: pizetaT_transfers_gainval_l
                                        * Referenced by: '<S86>/pi//(zeta*T_transfer)//s'
                                        */
  real_T Gain_Gain;                    /* Expression: 0
                                        * Referenced by: '<S66>/Gain'
                                        */
  real_T Phi1_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/Phi1'
                                        */
  real_T UnitDelay_X0_b;               /* Expression: 0
                                        * Referenced by: '<S73>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_e;              /* Expression: 0
                                        * Referenced by: '<S73>/Unit Delay1'
                                        */
  real_T s_gainval_b;                  /* Computed Parameter: s_gainval_b
                                        * Referenced by: '<S73>/1//s'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 2*pi
                                        * Referenced by: '<S73>/Gain1'
                                        */
  real_T Constant1_Value_h;            /* Expression: 90
                                        * Referenced by: '<S66>/Constant1'
                                        */
  real_T Gain2_Gain_i;                 /* Expression: pi/180
                                        * Referenced by: '<S73>/Gain2'
                                        */
  real_T Forsavingpositionandvelocityu_a;/* Expression: 0
                                          * Referenced by: '<S78>/For saving position  and velocity until after switchover'
                                          */
  real_T pizetaT_transfers_gainval_kq; /* Computed Parameter: pizetaT_transfers_gainval_kq
                                        * Referenced by: '<S78>/pi//(zeta*T_transfer)//s'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 1
                                        * Referenced by: '<S66>/Gain1'
                                        */
  real_T Theta1_Value;                 /* Expression: 0
                                        * Referenced by: '<S3>/Theta1'
                                        */
  real_T UnitDelay_X0_e;               /* Expression: 0
                                        * Referenced by: '<S74>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_o;              /* Expression: 0
                                        * Referenced by: '<S74>/Unit Delay1'
                                        */
  real_T s_gainval_a;                  /* Computed Parameter: s_gainval_a
                                        * Referenced by: '<S74>/1//s'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 2*pi
                                        * Referenced by: '<S74>/Gain1'
                                        */
  real_T Constant4_Value_b;            /* Expression: 0
                                        * Referenced by: '<S66>/Constant4'
                                        */
  real_T Gain2_Gain_ic;                /* Expression: pi/180
                                        * Referenced by: '<S74>/Gain2'
                                        */
  real_T Forsavingpositionandvelocityu_e;/* Expression: 0
                                          * Referenced by: '<S82>/For saving position  and velocity until after switchover'
                                          */
  real_T pizetaT_transfers_gainval_i;  /* Computed Parameter: pizetaT_transfers_gainval_i
                                        * Referenced by: '<S82>/pi//(zeta*T_transfer)//s'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 1
                                        * Referenced by: '<S66>/Gain2'
                                        */
  real_T y_e2_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/y_e2'
                                        */
  real_T GTRTCANRX1_P1_Size[2];        /* Computed Parameter: GTRTCANRX1_P1_Size
                                        * Referenced by: '<S12>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P1[32];            /* Computed Parameter: GTRTCANRX1_P1
                                        * Referenced by: '<S12>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P2_Size[2];        /* Computed Parameter: GTRTCANRX1_P2_Size
                                        * Referenced by: '<S12>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P2;                /* Expression: receive_all_can_ids
                                        * Referenced by: '<S12>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P3_Size[2];        /* Computed Parameter: GTRTCANRX1_P3_Size
                                        * Referenced by: '<S12>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P3;                /* Expression: can_id
                                        * Referenced by: '<S12>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P4_Size[2];        /* Computed Parameter: GTRTCANRX1_P4_Size
                                        * Referenced by: '<S12>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX1_P4;                /* Expression: sample_time
                                        * Referenced by: '<S12>/GT-RT CAN RX1'
                                        */
  real_T GTRTCANRX2_P1_Size[2];        /* Computed Parameter: GTRTCANRX2_P1_Size
                                        * Referenced by: '<S12>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P1[32];            /* Computed Parameter: GTRTCANRX2_P1
                                        * Referenced by: '<S12>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P2_Size[2];        /* Computed Parameter: GTRTCANRX2_P2_Size
                                        * Referenced by: '<S12>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P2;                /* Expression: receive_all_can_ids
                                        * Referenced by: '<S12>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P3_Size[2];        /* Computed Parameter: GTRTCANRX2_P3_Size
                                        * Referenced by: '<S12>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P3;                /* Expression: can_id
                                        * Referenced by: '<S12>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P4_Size[2];        /* Computed Parameter: GTRTCANRX2_P4_Size
                                        * Referenced by: '<S12>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P4;                /* Expression: sample_time
                                        * Referenced by: '<S12>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX3_P1_Size[2];        /* Computed Parameter: GTRTCANRX3_P1_Size
                                        * Referenced by: '<S12>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P1[32];            /* Computed Parameter: GTRTCANRX3_P1
                                        * Referenced by: '<S12>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P2_Size[2];        /* Computed Parameter: GTRTCANRX3_P2_Size
                                        * Referenced by: '<S12>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P2;                /* Expression: receive_all_can_ids
                                        * Referenced by: '<S12>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P3_Size[2];        /* Computed Parameter: GTRTCANRX3_P3_Size
                                        * Referenced by: '<S12>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P3;                /* Expression: can_id
                                        * Referenced by: '<S12>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P4_Size[2];        /* Computed Parameter: GTRTCANRX3_P4_Size
                                        * Referenced by: '<S12>/GT-RT CAN RX3'
                                        */
  real_T GTRTCANRX3_P4;                /* Expression: sample_time
                                        * Referenced by: '<S12>/GT-RT CAN RX3'
                                        */
  real_T Gain_Gain_j[6];               /* Expression: [1 -1 -1 -1 -1 -1]
                                        * Referenced by: '<S134>/Gain'
                                        */
  real_T Constant_Value_b[6];          /* Expression: [0 0 0 0 0 15.89]
                                        * Referenced by: '<S134>/Constant'
                                        */
  real_T UnitDelay_X0_f[3];            /* Expression: [0 0 0]
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S11>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_k;             /* Expression: 0.01
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 0.05
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T UnitDelay3_X0_f;              /* Expression: 0
                                        * Referenced by: '<S70>/Unit Delay3'
                                        */
  real_T Constant7_Value_d;            /* Expression: 0.1
                                        * Referenced by: '<S3>/Constant7'
                                        */
  real_T Constant6_Value_m;            /* Expression: 1
                                        * Referenced by: '<S3>/Constant6'
                                        */
  real_T UnitDelay2_X0_n4;             /* Expression: 0
                                        * Referenced by: '<S70>/Unit Delay2'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S70>/Switch2'
                                        */
  real_T pizetaT_transfers_gainval_n;  /* Computed Parameter: pizetaT_transfers_gainval_n
                                        * Referenced by: '<S103>/pi//(zeta*T_transfer)//s'
                                        */
  real_T pizetaT_transfers_IC;         /* Expression: 0
                                        * Referenced by: '<S103>/pi//(zeta*T_transfer)//s'
                                        */
  real_T Constant10_Value[3];          /* Expression: [0; 0; 0]
                                        * Referenced by: '<S94>/Constant10'
                                        */
  real_T x_e_Value;                    /* Expression: 0
                                        * Referenced by: '<S3>/x_e'
                                        */
  real_T y_e_Value;                    /* Expression: 0
                                        * Referenced by: '<S3>/y_e'
                                        */
  real_T z_e_Value;                    /* Expression: 0
                                        * Referenced by: '<S3>/z_e'
                                        */
  real_T Phi_Value;                    /* Expression: 0
                                        * Referenced by: '<S3>/Phi'
                                        */
  real_T Theta_Value;                  /* Expression: 0
                                        * Referenced by: '<S3>/Theta'
                                        */
  real_T Psi_Value;                    /* Expression: 0
                                        * Referenced by: '<S3>/Psi'
                                        */
  real_T PSEA1_Value;                  /* Expression: 160
                                        * Referenced by: '<S47>/PSEA1'
                                        */
  real_T UnitDelay_X0_l[6];            /* Expression: [0 50 -68 0 18 0]'
                                        * Referenced by: '<S131>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_d;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_d
                                          * Referenced by: '<S138>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator_gainva_m;/* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                          * Referenced by: '<S135>/Discrete-Time Integrator'
                                          */
  real_T Switch_Threshold_h;           /* Expression: 0
                                        * Referenced by: '<S131>/Switch'
                                        */
  real_T Gain_Gain_c[6];               /* Expression: [1 -1 -1 -1 -1 -1]
                                        * Referenced by: '<S137>/Gain'
                                        */
  real_T Constant_Value_h[6];          /* Expression: [0 0 0 0 0 15.89]
                                        * Referenced by: '<S137>/Constant'
                                        */
  real_T UnitDelay6_X0[6];             /* Expression: [0 50 -68 0 18 0]'
                                        * Referenced by: '<S130>/Unit Delay6'
                                        */
  real_T Gain_Value;                   /* Expression: 2
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 0.004
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T ButterworthFilter10Hz_InitialSt;/* Expression: 0
                                          * Referenced by: '<S8>/Butterworth Filter 10 Hz'
                                          */
  real_T ButterworthFilter10Hz_Numerator[5];/* Expression: [0.000183216023369   0.000732864093478   0.001099296140221   0.000732864093475   0.000183216023371]
                                             * Referenced by: '<S8>/Butterworth Filter 10 Hz'
                                             */
  real_T ButterworthFilter10Hz_Denominat[5];/* Expression: [1.000000000000000  -3.344067837711873   4.238863950884063  -2.409342856586317   0.517478199788040
                                               ]
                                             * Referenced by: '<S8>/Butterworth Filter 10 Hz'
                                             */
  real_T NSEA1_Value;                  /* Expression: -160
                                        * Referenced by: '<S47>/NSEA1'
                                        */
  real_T VelLimiterA1_UpperSat;        /* Expression: 68.34
                                        * Referenced by: '<S15>/Vel Limiter A1'
                                        */
  real_T VelLimiterA1_LowerSat;        /* Expression: -68.34
                                        * Referenced by: '<S15>/Vel Limiter A1'
                                        */
  real_T AccLimiterA1_RisingLim;       /* Computed Parameter: AccLimiterA1_RisingLim
                                        * Referenced by: '<S15>/Acc Limiter A1'
                                        */
  real_T AccLimiterA1_FallingLim;      /* Computed Parameter: AccLimiterA1_FallingLim
                                        * Referenced by: '<S15>/Acc Limiter A1'
                                        */
  real_T AccLimiterA1_IC;              /* Expression: 0
                                        * Referenced by: '<S15>/Acc Limiter A1'
                                        */
  real_T PSEA1_Value_h;                /* Expression: 20
                                        * Referenced by: '<S48>/PSEA1'
                                        */
  real_T NSEA1_Value_f;                /* Expression: -130
                                        * Referenced by: '<S48>/NSEA1'
                                        */
  real_T VelLimiterA2_UpperSat;        /* Expression: 57
                                        * Referenced by: '<S15>/Vel Limiter A2'
                                        */
  real_T VelLimiterA2_LowerSat;        /* Expression: -57
                                        * Referenced by: '<S15>/Vel Limiter A2'
                                        */
  real_T AccLimiterA2_RisingLim;       /* Computed Parameter: AccLimiterA2_RisingLim
                                        * Referenced by: '<S15>/Acc Limiter A2'
                                        */
  real_T AccLimiterA2_FallingLim;      /* Computed Parameter: AccLimiterA2_FallingLim
                                        * Referenced by: '<S15>/Acc Limiter A2'
                                        */
  real_T AccLimiterA2_IC;              /* Expression: 0
                                        * Referenced by: '<S15>/Acc Limiter A2'
                                        */
  real_T PSEA1_Value_k;                /* Expression: 88
                                        * Referenced by: '<S49>/PSEA1'
                                        */
  real_T NSEA1_Value_k;                /* Expression: -88
                                        * Referenced by: '<S49>/NSEA1'
                                        */
  real_T VelLimiterA3_UpperSat;        /* Expression: 69
                                        * Referenced by: '<S15>/Vel Limiter A3'
                                        */
  real_T VelLimiterA3_LowerSat;        /* Expression: -69
                                        * Referenced by: '<S15>/Vel Limiter A3'
                                        */
  real_T AccLimiterA3_RisingLim;       /* Computed Parameter: AccLimiterA3_RisingLim
                                        * Referenced by: '<S15>/Acc Limiter A3'
                                        */
  real_T AccLimiterA3_FallingLim;      /* Computed Parameter: AccLimiterA3_FallingLim
                                        * Referenced by: '<S15>/Acc Limiter A3'
                                        */
  real_T AccLimiterA3_IC;              /* Expression: 0
                                        * Referenced by: '<S15>/Acc Limiter A3'
                                        */
  real_T PSEA1_Value_j;                /* Expression: 350
                                        * Referenced by: '<S50>/PSEA1'
                                        */
  real_T NSEA1_Value_d;                /* Expression: -350
                                        * Referenced by: '<S50>/NSEA1'
                                        */
  real_T VelLimiterA4_UpperSat;        /* Expression: 76
                                        * Referenced by: '<S15>/Vel Limiter A4'
                                        */
  real_T VelLimiterA4_LowerSat;        /* Expression: -76
                                        * Referenced by: '<S15>/Vel Limiter A4'
                                        */
  real_T AccLimiterA4_RisingLim;       /* Computed Parameter: AccLimiterA4_RisingLim
                                        * Referenced by: '<S15>/Acc Limiter A4'
                                        */
  real_T AccLimiterA4_FallingLim;      /* Computed Parameter: AccLimiterA4_FallingLim
                                        * Referenced by: '<S15>/Acc Limiter A4'
                                        */
  real_T AccLimiterA4_IC;              /* Expression: 0
                                        * Referenced by: '<S15>/Acc Limiter A4'
                                        */
  real_T PSEA1_Value_p;                /* Expression: 61
                                        * Referenced by: '<S51>/PSEA1'
                                        */
  real_T NSEA1_Value_l;                /* Expression: -61
                                        * Referenced by: '<S51>/NSEA1'
                                        */
  real_T VelLimiter3_UpperSat;         /* Expression: 76
                                        * Referenced by: '<S15>/Vel Limiter3'
                                        */
  real_T VelLimiter3_LowerSat;         /* Expression: -76
                                        * Referenced by: '<S15>/Vel Limiter3'
                                        */
  real_T AccLimiterA5_RisingLim;       /* Computed Parameter: AccLimiterA5_RisingLim
                                        * Referenced by: '<S15>/Acc Limiter A5'
                                        */
  real_T AccLimiterA5_FallingLim;      /* Computed Parameter: AccLimiterA5_FallingLim
                                        * Referenced by: '<S15>/Acc Limiter A5'
                                        */
  real_T AccLimiterA5_IC;              /* Expression: 0
                                        * Referenced by: '<S15>/Acc Limiter A5'
                                        */
  real_T PSEA1_Value_h0;               /* Expression: 350
                                        * Referenced by: '<S52>/PSEA1'
                                        */
  real_T NSEA1_Value_kl;               /* Expression: -350
                                        * Referenced by: '<S52>/NSEA1'
                                        */
  real_T VelLimiter6_UpperSat;         /* Expression: 120
                                        * Referenced by: '<S15>/Vel Limiter6'
                                        */
  real_T VelLimiter6_LowerSat;         /* Expression: -120
                                        * Referenced by: '<S15>/Vel Limiter6'
                                        */
  real_T AccLimiterA6_RisingLim;       /* Computed Parameter: AccLimiterA6_RisingLim
                                        * Referenced by: '<S15>/Acc Limiter A6'
                                        */
  real_T AccLimiterA6_FallingLim;      /* Computed Parameter: AccLimiterA6_FallingLim
                                        * Referenced by: '<S15>/Acc Limiter A6'
                                        */
  real_T AccLimiterA6_IC;              /* Expression: 0
                                        * Referenced by: '<S15>/Acc Limiter A6'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 1e8
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 1e8
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: 1e8
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real_T Gain3_Gain_i;                 /* Expression: 1e8
                                        * Referenced by: '<S13>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1e8
                                        * Referenced by: '<S13>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1e8
                                        * Referenced by: '<S13>/Gain5'
                                        */
  real_T Constant2_Value_c;            /* Expression: 30
                                        * Referenced by: '<S66>/Constant2'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S79>/TSamp'
                                        */
  real_T UD_X0;                        /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S79>/UD'
                                        */
  real_T zetaT_transferpi_Gain;        /* Expression: 0.8/pi
                                        * Referenced by: '<S78>/(zeta*T_transfer)//pi'
                                        */
  real_T zetapiT_transfers_gainval;    /* Computed Parameter: zetapiT_transfers_gainval
                                        * Referenced by: '<S78>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain;                  /* Expression: 3.2*pi
                                        * Referenced by: '<S78>/4*zeta*pi'
                                        */
  real_T pizeta_Gain;                  /* Expression: pi/0.8
                                        * Referenced by: '<S78>/pi//zeta'
                                        */
  real_T TSamp_WtEt_h;                 /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S83>/TSamp'
                                        */
  real_T UD_X0_n;                      /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S83>/UD'
                                        */
  real_T zetaT_transferpi_Gain_l;      /* Expression: 0.8/pi
                                        * Referenced by: '<S82>/(zeta*T_transfer)//pi'
                                        */
  real_T zetapiT_transfers_gainval_f;  /* Computed Parameter: zetapiT_transfers_gainval_f
                                        * Referenced by: '<S82>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain_j;                /* Expression: 3.2*pi
                                        * Referenced by: '<S82>/4*zeta*pi'
                                        */
  real_T pizeta_Gain_b;                /* Expression: pi/0.8
                                        * Referenced by: '<S82>/pi//zeta'
                                        */
  real_T TSamp_WtEt_g;                 /* Computed Parameter: TSamp_WtEt_g
                                        * Referenced by: '<S87>/TSamp'
                                        */
  real_T UD_X0_nl;                     /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S87>/UD'
                                        */
  real_T zetaT_transferpi_Gain_j;      /* Expression: 0.8/pi
                                        * Referenced by: '<S86>/(zeta*T_transfer)//pi'
                                        */
  real_T zetapiT_transfers_gainval_d;  /* Computed Parameter: zetapiT_transfers_gainval_d
                                        * Referenced by: '<S86>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain_g;                /* Expression: 3.2*pi
                                        * Referenced by: '<S86>/4*zeta*pi'
                                        */
  real_T pizeta_Gain_a;                /* Expression: pi/0.8
                                        * Referenced by: '<S86>/pi//zeta'
                                        */
  real_T Constant3_Value_f;            /* Expression: 0.5
                                        * Referenced by: '<S71>/Constant3'
                                        */
  real_T Constant_Value_i;             /* Expression: 4
                                        * Referenced by: '<S94>/Constant'
                                        */
  real_T Constant9_Value;              /* Expression: 21
                                        * Referenced by: '<S94>/Constant9'
                                        */
  real_T UnitDelay_X0_p[3];            /* Expression: [0 0 0]
                                        * Referenced by: '<S94>/Unit Delay'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: 30
                                        * Referenced by: '<S94>/Gain2'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S94>/Gain1'
                                        */
  real_T Gain3_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S94>/Gain3'
                                        */
  real_T Gain4_Gain_p;                 /* Expression: -1
                                        * Referenced by: '<S94>/Gain4'
                                        */
  real_T Constant_Value_d;             /* Expression: 0.2
                                        * Referenced by: '<S100>/Constant'
                                        */
  real_T pizetaT_transfers_gainval_j;  /* Computed Parameter: pizetaT_transfers_gainval_j
                                        * Referenced by: '<S105>/pi//(zeta*T_transfer)//s'
                                        */
  real_T pizetaT_transfers_IC_i;       /* Expression: 0
                                        * Referenced by: '<S105>/pi//(zeta*T_transfer)//s'
                                        */
  real_T zetapiT_transfers_gainval_h;  /* Computed Parameter: zetapiT_transfers_gainval_h
                                        * Referenced by: '<S105>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapiT_transfers_IC;         /* Expression: 0
                                        * Referenced by: '<S105>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain_k;                /* Expression: 3.2*pi
                                        * Referenced by: '<S105>/4*zeta*pi'
                                        */
  real_T pizeta_Gain_f;                /* Expression: pi/0.8
                                        * Referenced by: '<S105>/pi//zeta'
                                        */
  real_T TSamp_WtEt_e;                 /* Computed Parameter: TSamp_WtEt_e
                                        * Referenced by: '<S107>/TSamp'
                                        */
  real_T UD_X0_i;                      /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S107>/UD'
                                        */
  real_T zetaT_transferpi_Gain_c;      /* Expression: 0.8/pi
                                        * Referenced by: '<S106>/(zeta*T_transfer)//pi'
                                        */
  real_T zetapiT_transfers_gainval_m;  /* Computed Parameter: zetapiT_transfers_gainval_m
                                        * Referenced by: '<S106>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain_b;                /* Expression: 3.2*pi
                                        * Referenced by: '<S106>/4*zeta*pi'
                                        */
  real_T pizeta_Gain_c;                /* Expression: pi/0.8
                                        * Referenced by: '<S106>/pi//zeta'
                                        */
  real_T Constant_Value_l;             /* Expression: 0.2
                                        * Referenced by: '<S101>/Constant'
                                        */
  real_T pizetaT_transfers_gainval_d;  /* Computed Parameter: pizetaT_transfers_gainval_d
                                        * Referenced by: '<S108>/pi//(zeta*T_transfer)//s'
                                        */
  real_T pizetaT_transfers_IC_e;       /* Expression: 0
                                        * Referenced by: '<S108>/pi//(zeta*T_transfer)//s'
                                        */
  real_T zetapiT_transfers_gainval_n;  /* Computed Parameter: zetapiT_transfers_gainval_n
                                        * Referenced by: '<S108>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapiT_transfers_IC_p;       /* Expression: 0
                                        * Referenced by: '<S108>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain_n;                /* Expression: 3.2*pi
                                        * Referenced by: '<S108>/4*zeta*pi'
                                        */
  real_T pizeta_Gain_n;                /* Expression: pi/0.8
                                        * Referenced by: '<S108>/pi//zeta'
                                        */
  real_T TSamp_WtEt_k;                 /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S110>/TSamp'
                                        */
  real_T UD_X0_f;                      /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S110>/UD'
                                        */
  real_T zetaT_transferpi_Gain_p;      /* Expression: 0.8/pi
                                        * Referenced by: '<S109>/(zeta*T_transfer)//pi'
                                        */
  real_T zetapiT_transfers_gainval_c;  /* Computed Parameter: zetapiT_transfers_gainval_c
                                        * Referenced by: '<S109>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain_n1;               /* Expression: 3.2*pi
                                        * Referenced by: '<S109>/4*zeta*pi'
                                        */
  real_T pizeta_Gain_d;                /* Expression: pi/0.8
                                        * Referenced by: '<S109>/pi//zeta'
                                        */
  real_T Constant_Value_kc;            /* Expression: 0.2
                                        * Referenced by: '<S102>/Constant'
                                        */
  real_T pizetaT_transfers_gainval_j0; /* Computed Parameter: pizetaT_transfers_gainval_j0
                                        * Referenced by: '<S111>/pi//(zeta*T_transfer)//s'
                                        */
  real_T pizetaT_transfers_IC_h;       /* Expression: 0
                                        * Referenced by: '<S111>/pi//(zeta*T_transfer)//s'
                                        */
  real_T zetapiT_transfers_gainval_ci; /* Computed Parameter: zetapiT_transfers_gainval_ci
                                        * Referenced by: '<S111>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapiT_transfers_IC_e;       /* Expression: 0
                                        * Referenced by: '<S111>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain_i;                /* Expression: 3.2*pi
                                        * Referenced by: '<S111>/4*zeta*pi'
                                        */
  real_T pizeta_Gain_b1;               /* Expression: pi/0.8
                                        * Referenced by: '<S111>/pi//zeta'
                                        */
  real_T TSamp_WtEt_c;                 /* Computed Parameter: TSamp_WtEt_c
                                        * Referenced by: '<S113>/TSamp'
                                        */
  real_T UD_X0_p;                      /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S113>/UD'
                                        */
  real_T zetaT_transferpi_Gain_h;      /* Expression: 0.8/pi
                                        * Referenced by: '<S112>/(zeta*T_transfer)//pi'
                                        */
  real_T zetapiT_transfers_gainval_b;  /* Computed Parameter: zetapiT_transfers_gainval_b
                                        * Referenced by: '<S112>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain_gm;               /* Expression: 3.2*pi
                                        * Referenced by: '<S112>/4*zeta*pi'
                                        */
  real_T pizeta_Gain_k;                /* Expression: pi/0.8
                                        * Referenced by: '<S112>/pi//zeta'
                                        */
  real_T zetapiT_transfers_gainval_b1; /* Computed Parameter: zetapiT_transfers_gainval_b1
                                        * Referenced by: '<S103>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapiT_transfers_IC_m;       /* Expression: 0
                                        * Referenced by: '<S103>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain_bz;               /* Expression: 3.6*pi
                                        * Referenced by: '<S103>/4*zeta*pi'
                                        */
  real_T pizeta_Gain_o;                /* Expression: pi/0.9
                                        * Referenced by: '<S103>/pi//zeta'
                                        */
  real_T Constant2_Value_i;            /* Expression: 20
                                        * Referenced by: '<S71>/Constant2'
                                        */
  real_T TSamp_WtEt_e2;                /* Computed Parameter: TSamp_WtEt_e2
                                        * Referenced by: '<S123>/TSamp'
                                        */
  real_T UD_X0_ib;                     /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S123>/UD'
                                        */
  real_T zetaT_transferpi_Gain_lo;     /* Expression: 0.8/pi
                                        * Referenced by: '<S122>/(zeta*T_transfer)//pi'
                                        */
  real_T zetapiT_transfers_gainval_md; /* Computed Parameter: zetapiT_transfers_gainval_md
                                        * Referenced by: '<S122>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain_c;                /* Expression: 3.2*pi
                                        * Referenced by: '<S122>/4*zeta*pi'
                                        */
  real_T pizeta_Gain_j;                /* Expression: pi/0.8
                                        * Referenced by: '<S122>/pi//zeta'
                                        */
  real_T Gain_Gain_n;                  /* Expression: -0.1
                                        * Referenced by: '<S135>/Gain'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: -0.1
                                        * Referenced by: '<S138>/Gain1'
                                        */
  real_T Kuka_start_pos_Value[3];      /* Expression: [141.15; 0; -390]
                                        * Referenced by: '<Root>/Kuka_start_pos'
                                        */
  real_T GTRTCANRX2_P1_Size_h[2];      /* Computed Parameter: GTRTCANRX2_P1_Size_h
                                        * Referenced by: '<S7>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P1_b[32];          /* Computed Parameter: GTRTCANRX2_P1_b
                                        * Referenced by: '<S7>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P2_Size_o[2];      /* Computed Parameter: GTRTCANRX2_P2_Size_o
                                        * Referenced by: '<S7>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P2_m;              /* Expression: receive_all_can_ids
                                        * Referenced by: '<S7>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P3_Size_m[2];      /* Computed Parameter: GTRTCANRX2_P3_Size_m
                                        * Referenced by: '<S7>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P3_m;              /* Expression: can_id
                                        * Referenced by: '<S7>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P4_Size_c[2];      /* Computed Parameter: GTRTCANRX2_P4_Size_c
                                        * Referenced by: '<S7>/GT-RT CAN RX2'
                                        */
  real_T GTRTCANRX2_P4_k;              /* Expression: sample_time
                                        * Referenced by: '<S7>/GT-RT CAN RX2'
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
  real_T GTRTUDPWrite_P1_Size[2];      /* Computed Parameter: GTRTUDPWrite_P1_Size
                                        * Referenced by: '<S1>/GT-RT UDP  Write'
                                        */
  real_T GTRTUDPWrite_P1[29];          /* Computed Parameter: GTRTUDPWrite_P1
                                        * Referenced by: '<S1>/GT-RT UDP  Write'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 1
                                        * Referenced by: '<S23>/Gain1'
                                        */
  real_T Gain2_Gain_mq;                /* Expression: 1
                                        * Referenced by: '<S23>/Gain2'
                                        */
  real_T Gain3_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S23>/Gain3'
                                        */
  real_T Gain4_Gain_e;                 /* Expression: 1
                                        * Referenced by: '<S23>/Gain4'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 1
                                        * Referenced by: '<S24>/Gain1'
                                        */
  real_T Gain2_Gain_me;                /* Expression: 1
                                        * Referenced by: '<S24>/Gain2'
                                        */
  real_T Gain3_Gain_m;                 /* Expression: 1
                                        * Referenced by: '<S24>/Gain3'
                                        */
  real_T Gain4_Gain_p4;                /* Expression: 1
                                        * Referenced by: '<S24>/Gain4'
                                        */
  real_T GTRTCANTX_P1_Size[2];         /* Computed Parameter: GTRTCANTX_P1_Size
                                        * Referenced by: '<S22>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P1[32];             /* Computed Parameter: GTRTCANTX_P1
                                        * Referenced by: '<S22>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P2_Size[2];         /* Computed Parameter: GTRTCANTX_P2_Size
                                        * Referenced by: '<S22>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P2;                 /* Expression: mff
                                        * Referenced by: '<S22>/GT-RT CAN TX'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 1
                                        * Referenced by: '<S25>/Gain1'
                                        */
  real_T Gain2_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S25>/Gain2'
                                        */
  real_T Gain3_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S25>/Gain3'
                                        */
  real_T Gain4_Gain_o;                 /* Expression: 1
                                        * Referenced by: '<S25>/Gain4'
                                        */
  real_T Gain1_Gain_gi;                /* Expression: 1
                                        * Referenced by: '<S26>/Gain1'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: 1
                                        * Referenced by: '<S26>/Gain2'
                                        */
  real_T Gain3_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S26>/Gain3'
                                        */
  real_T Gain4_Gain_h;                 /* Expression: 1
                                        * Referenced by: '<S26>/Gain4'
                                        */
  real_T GTRTCANTX1_P1_Size[2];        /* Computed Parameter: GTRTCANTX1_P1_Size
                                        * Referenced by: '<S22>/GT-RT CAN TX1'
                                        */
  real_T GTRTCANTX1_P1[32];            /* Computed Parameter: GTRTCANTX1_P1
                                        * Referenced by: '<S22>/GT-RT CAN TX1'
                                        */
  real_T GTRTCANTX1_P2_Size[2];        /* Computed Parameter: GTRTCANTX1_P2_Size
                                        * Referenced by: '<S22>/GT-RT CAN TX1'
                                        */
  real_T GTRTCANTX1_P2;                /* Expression: mff
                                        * Referenced by: '<S22>/GT-RT CAN TX1'
                                        */
  real_T Gain1_Gain_f0;                /* Expression: 1
                                        * Referenced by: '<S27>/Gain1'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 1
                                        * Referenced by: '<S27>/Gain2'
                                        */
  real_T Gain3_Gain_i0;                /* Expression: 1
                                        * Referenced by: '<S27>/Gain3'
                                        */
  real_T Gain4_Gain_a;                 /* Expression: 1
                                        * Referenced by: '<S27>/Gain4'
                                        */
  real_T Gain1_Gain_pw;                /* Expression: 1
                                        * Referenced by: '<S28>/Gain1'
                                        */
  real_T Gain2_Gain_jh;                /* Expression: 1
                                        * Referenced by: '<S28>/Gain2'
                                        */
  real_T Gain3_Gain_d;                 /* Expression: 1
                                        * Referenced by: '<S28>/Gain3'
                                        */
  real_T Gain4_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S28>/Gain4'
                                        */
  real_T GTRTCANTX2_P1_Size[2];        /* Computed Parameter: GTRTCANTX2_P1_Size
                                        * Referenced by: '<S22>/GT-RT CAN TX2'
                                        */
  real_T GTRTCANTX2_P1[32];            /* Computed Parameter: GTRTCANTX2_P1
                                        * Referenced by: '<S22>/GT-RT CAN TX2'
                                        */
  real_T GTRTCANTX2_P2_Size[2];        /* Computed Parameter: GTRTCANTX2_P2_Size
                                        * Referenced by: '<S22>/GT-RT CAN TX2'
                                        */
  real_T GTRTCANTX2_P2;                /* Expression: mff
                                        * Referenced by: '<S22>/GT-RT CAN TX2'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0
                                        * Referenced by: '<S47>/Switch'
                                        */
  real_T PSEA2_Value;                  /* Expression: 0
                                        * Referenced by: '<S53>/PSEA2'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 1
                                        * Referenced by: '<S53>/Switch'
                                        */
  real_T Switch_Threshold_e;           /* Expression: 0
                                        * Referenced by: '<S48>/Switch'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 0
                                        * Referenced by: '<S49>/Switch'
                                        */
  real_T Switch_Threshold_d;           /* Expression: 0
                                        * Referenced by: '<S50>/Switch'
                                        */
  real_T Switch_Threshold_i;           /* Expression: 0
                                        * Referenced by: '<S51>/Switch'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S52>/Switch'
                                        */
  real_T Constant4_Value_o;            /* Expression: 0
                                        * Referenced by: '<S3>/Constant4'
                                        */
  real_T setforoptimizingxandy_Value[6];/* Expression: [258.3 -273.22;  220 -330; 141.15 -390]
                                         * Referenced by: '<S68>/set for optimizing x and y'
                                         */
  real_T setforoptimizingpurez_Value[6];/* Expression: [258.3 -273.22;  251.45 -281.21; 244.6 -289.2]
                                         * Referenced by: '<S68>/set for optimizing pure z'
                                         */
  real_T setforoptimizingz_Value[6];   /* Expression: [258.3 -273.22;  240.025 -296.285; 221.75 -319.35]
                                        * Referenced by: '<S68>/set for optimizing z'
                                        */
  real_T Constant2_Value_g;            /* Expression: 50
                                        * Referenced by: '<S68>/Constant2'
                                        */
  real_T Forsavingpositionandvelocity_az;/* Expression: 0
                                          * Referenced by: '<S88>/For saving position  and velocity until after switchover'
                                          */
  real_T TSamp_WtEt_i;                 /* Computed Parameter: TSamp_WtEt_i
                                        * Referenced by: '<S91>/TSamp'
                                        */
  real_T UD_X0_d;                      /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S91>/UD'
                                        */
  real_T zetaT_transferpi_Gain_f;      /* Expression: 0.8/pi
                                        * Referenced by: '<S88>/(zeta*T_transfer)//pi'
                                        */
  real_T pizetaT_transfers_gainval_p;  /* Computed Parameter: pizetaT_transfers_gainval_p
                                        * Referenced by: '<S88>/pi//(zeta*T_transfer)//s'
                                        */
  real_T zetapiT_transfers_gainval_mg; /* Computed Parameter: zetapiT_transfers_gainval_mg
                                        * Referenced by: '<S88>/4*zeta*pi//T_transfer //s'
                                        */
  real_T zetapi_Gain_f;                /* Expression: 3.2*pi
                                        * Referenced by: '<S88>/4*zeta*pi'
                                        */
  real_T pizeta_Gain_cl;               /* Expression: pi/0.8
                                        * Referenced by: '<S88>/pi//zeta'
                                        */
  real_T Constant_Value_n[3];          /* Expression: [0 0 0]
                                        * Referenced by: '<S69>/Constant'
                                        */
  real_T Constant1_Value_n[3];         /* Expression: [0; 0; 0]
                                        * Referenced by: '<S94>/Constant1'
                                        */
  real_T Constant2_Value_co;           /* Expression: 0.1
                                        * Referenced by: '<S100>/Constant2'
                                        */
  real_T Constant3_Value_nd;           /* Expression: 0.1
                                        * Referenced by: '<S101>/Constant3'
                                        */
  real_T Constant3_Value_a;            /* Expression: 0.1
                                        * Referenced by: '<S102>/Constant3'
                                        */
  real_T Constant_Value_lj;            /* Expression: 1
                                        * Referenced by: '<S104>/Constant'
                                        */
  real_T target_offset_Value[2];       /* Expression: [103.45 100.8]
                                        * Referenced by: '<S71>/target_offset'
                                        */
  real_T target_offset2_Value[2];      /* Expression: [0 0]
                                        * Referenced by: '<S71>/target_offset2'
                                        */
  real_T SFunction_p1[210];            /* Expression: B
                                        * Referenced by: '<S71>/Embedded MATLAB Function2'
                                        */
  real_T SFunction_p1_b[210];          /* Expression: B
                                        * Referenced by: '<S72>/Embedded MATLAB Function2'
                                        */
  real_T GTRTUDPTX1_P1_Size[2];        /* Computed Parameter: GTRTUDPTX1_P1_Size
                                        * Referenced by: '<S125>/GT-RT UDP TX1'
                                        */
  real_T GTRTUDPTX1_P1[29];            /* Computed Parameter: GTRTUDPTX1_P1
                                        * Referenced by: '<S125>/GT-RT UDP TX1'
                                        */
  real_T GTRTUDPTX1_P2_Size[2];        /* Computed Parameter: GTRTUDPTX1_P2_Size
                                        * Referenced by: '<S125>/GT-RT UDP TX1'
                                        */
  real_T GTRTUDPTX1_P2[14];            /* Computed Parameter: GTRTUDPTX1_P2
                                        * Referenced by: '<S125>/GT-RT UDP TX1'
                                        */
  real_T GTRTUDPTX_P1_Size_m[2];       /* Computed Parameter: GTRTUDPTX_P1_Size_m
                                        * Referenced by: '<S125>/GT-RT UDP TX'
                                        */
  real_T GTRTUDPTX_P1_l[29];           /* Computed Parameter: GTRTUDPTX_P1_l
                                        * Referenced by: '<S125>/GT-RT UDP TX'
                                        */
  real_T GTRTUDPTX_P2_Size_h[2];       /* Computed Parameter: GTRTUDPTX_P2_Size_h
                                        * Referenced by: '<S125>/GT-RT UDP TX'
                                        */
  real_T GTRTUDPTX_P2_n[14];           /* Computed Parameter: GTRTUDPTX_P2_n
                                        * Referenced by: '<S125>/GT-RT UDP TX'
                                        */
  real_T GTRTUDPWrite_P1_Size_f[2];    /* Computed Parameter: GTRTUDPWrite_P1_Size_f
                                        * Referenced by: '<S125>/GT-RT UDP  Write'
                                        */
  real_T GTRTUDPWrite_P1_g[29];        /* Computed Parameter: GTRTUDPWrite_P1_g
                                        * Referenced by: '<S125>/GT-RT UDP  Write'
                                        */
  real_T GTRTUDPWrite1_P1_Size[2];     /* Computed Parameter: GTRTUDPWrite1_P1_Size
                                        * Referenced by: '<S125>/GT-RT UDP  Write1'
                                        */
  real_T GTRTUDPWrite1_P1[29];         /* Computed Parameter: GTRTUDPWrite1_P1
                                        * Referenced by: '<S125>/GT-RT UDP  Write1'
                                        */
  real_T GTRTCANTX_P1_Size_c[2];       /* Computed Parameter: GTRTCANTX_P1_Size_c
                                        * Referenced by: '<S127>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P1_a[32];           /* Computed Parameter: GTRTCANTX_P1_a
                                        * Referenced by: '<S127>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P2_Size_o[2];       /* Computed Parameter: GTRTCANTX_P2_Size_o
                                        * Referenced by: '<S127>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P2_f;               /* Expression: mff
                                        * Referenced by: '<S127>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P1_Size_k[2];       /* Computed Parameter: GTRTCANTX_P1_Size_k
                                        * Referenced by: '<S128>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P1_o[32];           /* Computed Parameter: GTRTCANTX_P1_o
                                        * Referenced by: '<S128>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P2_Size_d[2];       /* Computed Parameter: GTRTCANTX_P2_Size_d
                                        * Referenced by: '<S128>/GT-RT CAN TX'
                                        */
  real_T GTRTCANTX_P2_m;               /* Expression: mff
                                        * Referenced by: '<S128>/GT-RT CAN TX'
                                        */
  real_T Constant_Value_ee;            /* Expression: 1
                                        * Referenced by: '<S131>/Constant'
                                        */
  real32_T ButterworthFilter10Hz_Initial_a;/* Computed Parameter: ButterworthFilter10Hz_Initial_a
                                            * Referenced by: '<S10>/Butterworth Filter 10 Hz'
                                            */
  real32_T ButterworthFilter10Hz_Numerat_o[5];/* Computed Parameter: ButterworthFilter10Hz_Numerat_o
                                               * Referenced by: '<S10>/Butterworth Filter 10 Hz'
                                               */
  real32_T ButterworthFilter10Hz_Denomin_l[5];/* Computed Parameter: ButterworthFilter10Hz_Denomin_l
                                               * Referenced by: '<S10>/Butterworth Filter 10 Hz'
                                               */
  real32_T Gain2_Gain_mb;              /* Computed Parameter: Gain2_Gain_mb
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real32_T Gain3_Gain_gk;              /* Computed Parameter: Gain3_Gain_gk
                                        * Referenced by: '<S10>/Gain3'
                                        */
  real32_T Gain1_Gain_kc;              /* Computed Parameter: Gain1_Gain_kc
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real32_T Limitto1_UpperSat;          /* Computed Parameter: Limitto1_UpperSat
                                        * Referenced by: '<S94>/Limit to +-1'
                                        */
  real32_T Limitto1_LowerSat;          /* Computed Parameter: Limitto1_LowerSat
                                        * Referenced by: '<S94>/Limit to +-1'
                                        */
  uint32_T Constant3_Value_b;          /* Computed Parameter: Constant3_Value_b
                                        * Referenced by: '<S1>/Constant3'
                                        */
  uint32_T TXCANID1_Value;             /* Computed Parameter: TXCANID1_Value
                                        * Referenced by: '<S22>/TX CAN ID1'
                                        */
  uint32_T TXCANID2_Value;             /* Computed Parameter: TXCANID2_Value
                                        * Referenced by: '<S22>/TX CAN ID2'
                                        */
  uint32_T TXCANID3_Value;             /* Computed Parameter: TXCANID3_Value
                                        * Referenced by: '<S22>/TX CAN ID3'
                                        */
  uint32_T Constant9_Value_l;          /* Computed Parameter: Constant9_Value_l
                                        * Referenced by: '<S125>/Constant9'
                                        */
  uint32_T Constant3_Value_p;          /* Computed Parameter: Constant3_Value_p
                                        * Referenced by: '<S125>/Constant3'
                                        */
  uint32_T TXCANID1_Value_i;           /* Computed Parameter: TXCANID1_Value_i
                                        * Referenced by: '<S127>/TX CAN ID1'
                                        */
  uint32_T TXCANID1_Value_b;           /* Computed Parameter: TXCANID1_Value_b
                                        * Referenced by: '<S128>/TX CAN ID1'
                                        */
  int32_T Gain_Gain_f;                 /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S12>/Gain'
                                        */
  int32_T Gain2_Gain_d;                /* Computed Parameter: Gain2_Gain_d
                                        * Referenced by: '<S12>/Gain2'
                                        */
  int32_T Gain6_Gain;                  /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S12>/Gain6'
                                        */
  int32_T Gain1_Gain_ds;               /* Computed Parameter: Gain1_Gain_ds
                                        * Referenced by: '<S12>/Gain1'
                                        */
  int32_T Gain3_Gain_gg;               /* Computed Parameter: Gain3_Gain_gg
                                        * Referenced by: '<S12>/Gain3'
                                        */
  int32_T Gain4_Gain_lp;               /* Computed Parameter: Gain4_Gain_lp
                                        * Referenced by: '<S12>/Gain4'
                                        */
  int16_T shift_Power2Exponent;        /* Computed Parameter: shift_Power2Exponent
                                        * Referenced by: '<S29>/shift'
                                        */
  int16_T shift_Power2Exponent_h;      /* Computed Parameter: shift_Power2Exponent_h
                                        * Referenced by: '<S30>/shift'
                                        */
  int16_T shift_Power2Exponent_n;      /* Computed Parameter: shift_Power2Exponent_n
                                        * Referenced by: '<S31>/shift'
                                        */
  int16_T shift_Power2Exponent_o;      /* Computed Parameter: shift_Power2Exponent_o
                                        * Referenced by: '<S32>/shift'
                                        */
  int16_T shift_Power2Exponent_ng;     /* Computed Parameter: shift_Power2Exponent_ng
                                        * Referenced by: '<S33>/shift'
                                        */
  int16_T shift_Power2Exponent_on;     /* Computed Parameter: shift_Power2Exponent_on
                                        * Referenced by: '<S34>/shift'
                                        */
  int16_T shift_Power2Exponent_hw;     /* Computed Parameter: shift_Power2Exponent_hw
                                        * Referenced by: '<S35>/shift'
                                        */
  int16_T shift_Power2Exponent_a;      /* Computed Parameter: shift_Power2Exponent_a
                                        * Referenced by: '<S36>/shift'
                                        */
  int16_T shift_Power2Exponent_hj;     /* Computed Parameter: shift_Power2Exponent_hj
                                        * Referenced by: '<S37>/shift'
                                        */
  int16_T shift_Power2Exponent_i;      /* Computed Parameter: shift_Power2Exponent_i
                                        * Referenced by: '<S38>/shift'
                                        */
  int16_T shift_Power2Exponent_k;      /* Computed Parameter: shift_Power2Exponent_k
                                        * Referenced by: '<S39>/shift'
                                        */
  int16_T shift_Power2Exponent_ap;     /* Computed Parameter: shift_Power2Exponent_ap
                                        * Referenced by: '<S40>/shift'
                                        */
  int16_T shift_Power2Exponent_m;      /* Computed Parameter: shift_Power2Exponent_m
                                        * Referenced by: '<S41>/shift'
                                        */
  int16_T shift_Power2Exponent_p;      /* Computed Parameter: shift_Power2Exponent_p
                                        * Referenced by: '<S42>/shift'
                                        */
  int16_T shift_Power2Exponent_kw;     /* Computed Parameter: shift_Power2Exponent_kw
                                        * Referenced by: '<S43>/shift'
                                        */
  int16_T shift_Power2Exponent_oo;     /* Computed Parameter: shift_Power2Exponent_oo
                                        * Referenced by: '<S44>/shift'
                                        */
  int16_T shift_Power2Exponent_h1;     /* Computed Parameter: shift_Power2Exponent_h1
                                        * Referenced by: '<S45>/shift'
                                        */
  int16_T shift_Power2Exponent_g;      /* Computed Parameter: shift_Power2Exponent_g
                                        * Referenced by: '<S46>/shift'
                                        */
  uint16_T Constant2_Value_gm;         /* Computed Parameter: Constant2_Value_gm
                                        * Referenced by: '<S1>/Constant2'
                                        */
  uint16_T Constant8_Value_p;          /* Computed Parameter: Constant8_Value_p
                                        * Referenced by: '<S125>/Constant8'
                                        */
  uint16_T Constant2_Value_j;          /* Computed Parameter: Constant2_Value_j
                                        * Referenced by: '<S125>/Constant2'
                                        */
  uint8_T Counter_InitialCount;        /* Computed Parameter: Counter_InitialCount
                                        * Referenced by: '<S3>/Counter'
                                        */
  uint8_T Counter_HitValue;            /* Computed Parameter: Counter_HitValue
                                        * Referenced by: '<S3>/Counter'
                                        */
  uint8_T Switch_Threshold_m;          /* Computed Parameter: Switch_Threshold_m
                                        * Referenced by: '<S75>/Switch'
                                        */
  uint8_T Switch_Threshold_l;          /* Computed Parameter: Switch_Threshold_l
                                        * Referenced by: '<S73>/Switch'
                                        */
  uint8_T Switch_Threshold_ex;         /* Computed Parameter: Switch_Threshold_ex
                                        * Referenced by: '<S74>/Switch'
                                        */
  uint8_T Constant_Value_o;            /* Expression: uint8(1)
                                        * Referenced by: '<S6>/Constant'
                                        */
  uint8_T SwitchControl_Threshold;     /* Expression: uint8(0)
                                        * Referenced by: '<S6>/SwitchControl'
                                        */
  uint8_T Switch_Threshold_bg;         /* Computed Parameter: Switch_Threshold_bg
                                        * Referenced by: '<Root>/Switch'
                                        */
  uint8_T Constant_Value_a;            /* Expression: uint8(1)
                                        * Referenced by: '<S9>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_e;   /* Expression: uint8(0)
                                        * Referenced by: '<S9>/SwitchControl'
                                        */
  uint8_T TXData_Value;                /* Computed Parameter: TXData_Value
                                        * Referenced by: '<S127>/TX Data'
                                        */
  uint8_T TXData_Value_d;              /* Computed Parameter: TXData_Value_d
                                        * Referenced by: '<S128>/TX Data'
                                        */
  uint8_T Constant_Value_al;           /* Expression: uint8(1)
                                        * Referenced by: '<S136>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_h;   /* Expression: uint8(0)
                                        * Referenced by: '<S136>/SwitchControl'
                                        */
  boolean_T UnitDelay_X0_fb;           /* Computed Parameter: UnitDelay_X0_fb
                                        * Referenced by: '<S69>/Unit Delay'
                                        */
  boolean_T UnitDelay1_X0_m;           /* Computed Parameter: UnitDelay1_X0_m
                                        * Referenced by: '<S70>/Unit Delay1'
                                        */
  boolean_T UnitDelay_X0_ps;           /* Computed Parameter: UnitDelay_X0_ps
                                        * Referenced by: '<S70>/Unit Delay'
                                        */
  boolean_T UnitDelay_X0_eq;           /* Computed Parameter: UnitDelay_X0_eq
                                        * Referenced by: '<S93>/Unit Delay'
                                        */
  uint8_T Gain2_Gain_mbx;              /* Computed Parameter: Gain2_Gain_mbx
                                        * Referenced by: '<S16>/Gain2'
                                        */
  uint8_T Gain2_Gain_b;                /* Computed Parameter: Gain2_Gain_b
                                        * Referenced by: '<S17>/Gain2'
                                        */
  uint8_T Gain2_Gain_gz;               /* Computed Parameter: Gain2_Gain_gz
                                        * Referenced by: '<S18>/Gain2'
                                        */
  uint8_T Gain2_Gain_mi;               /* Computed Parameter: Gain2_Gain_mi
                                        * Referenced by: '<S19>/Gain2'
                                        */
  uint8_T Gain2_Gain_l;                /* Computed Parameter: Gain2_Gain_l
                                        * Referenced by: '<S20>/Gain2'
                                        */
  uint8_T Gain2_Gain_jg;               /* Computed Parameter: Gain2_Gain_jg
                                        * Referenced by: '<S21>/Gain2'
                                        */
  uint8_T Gain3_Gain_h;                /* Computed Parameter: Gain3_Gain_h
                                        * Referenced by: '<S16>/Gain3'
                                        */
  uint8_T Gain3_Gain_dt;               /* Computed Parameter: Gain3_Gain_dt
                                        * Referenced by: '<S17>/Gain3'
                                        */
  uint8_T Gain3_Gain_a;                /* Computed Parameter: Gain3_Gain_a
                                        * Referenced by: '<S18>/Gain3'
                                        */
  uint8_T Gain3_Gain_e;                /* Computed Parameter: Gain3_Gain_e
                                        * Referenced by: '<S19>/Gain3'
                                        */
  uint8_T Gain3_Gain_iy;               /* Computed Parameter: Gain3_Gain_iy
                                        * Referenced by: '<S20>/Gain3'
                                        */
  uint8_T Gain3_Gain_p;                /* Computed Parameter: Gain3_Gain_p
                                        * Referenced by: '<S21>/Gain3'
                                        */
  uint8_T Gain4_Gain_f;                /* Computed Parameter: Gain4_Gain_f
                                        * Referenced by: '<S16>/Gain4'
                                        */
  uint8_T Gain4_Gain_pf;               /* Computed Parameter: Gain4_Gain_pf
                                        * Referenced by: '<S17>/Gain4'
                                        */
  uint8_T Gain4_Gain_j;                /* Computed Parameter: Gain4_Gain_j
                                        * Referenced by: '<S18>/Gain4'
                                        */
  uint8_T Gain4_Gain_fg;               /* Computed Parameter: Gain4_Gain_fg
                                        * Referenced by: '<S19>/Gain4'
                                        */
  uint8_T Gain4_Gain_pa;               /* Computed Parameter: Gain4_Gain_pa
                                        * Referenced by: '<S20>/Gain4'
                                        */
  uint8_T Gain4_Gain_n;                /* Computed Parameter: Gain4_Gain_n
                                        * Referenced by: '<S21>/Gain4'
                                        */
  rtP_IfActionSubsystem1_M37_Sim_ IfActionSubsystem1_n5;/* '<S47>/If Action Subsystem1' */
  rtP_IfActionSubsystem_M37_Sim_F IfActionSubsystem_p;/* '<S48>/If Action Subsystem' */
  rtP_IfActionSubsystem1_M37_Sim_ IfActionSubsystem1_p;/* '<S47>/If Action Subsystem1' */
  rtP_IfActionSubsystem_M37_Sim_F IfActionSubsystem_n;/* '<S48>/If Action Subsystem' */
  rtP_IfActionSubsystem1_M37_Sim_ IfActionSubsystem1_n;/* '<S47>/If Action Subsystem1' */
  rtP_IfActionSubsystem_M37_Sim_F IfActionSubsystem_m;/* '<S48>/If Action Subsystem' */
  rtP_IfActionSubsystem1_M37_Sim_ IfActionSubsystem1_h;/* '<S47>/If Action Subsystem1' */
  rtP_IfActionSubsystem_M37_Sim_F IfActionSubsystem_c;/* '<S48>/If Action Subsystem' */
  rtP_IfActionSubsystem1_M37_Sim_ IfActionSubsystem1_e;/* '<S47>/If Action Subsystem1' */
  rtP_IfActionSubsystem_M37_Sim_F IfActionSubsystem_h;/* '<S48>/If Action Subsystem' */
  rtP_IfActionSubsystem1_M37_Sim_ IfActionSubsystem1;/* '<S47>/If Action Subsystem1' */
};

/* Real-time Model Data Structure */
struct RT_MODEL_M37_Sim_Forcing_003h_expe_infra_transz_lim {
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
    SimStruct childSFunctions[20];
    SimStruct *childSFunctionPtrs[20];
    struct _ssBlkInfo2 blkInfo2[20];
    struct _ssSFcnModelMethods2 methods2[20];
    struct _ssSFcnModelMethods3 methods3[20];
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
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

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
    } Sfcn2;

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
      struct _ssPortInputs inputPortInfo[4];
      real_T const *UPtrs0[4];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[8];
      real_T const *UPtrs3[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[4];
      real_T const *UPtrs0[4];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[161];
      real_T const *UPtrs3[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn8;

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
    } Sfcn9;

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
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
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
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn13;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[1];
      mxArray *params[1];
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
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn15;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[4];
      mxArray *params[4];
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
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn17;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn18;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn19;
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
extern Parameters_M37_Sim_Forcing_003h_expe_infra_transz_lim
  M37_Sim_Forcing_003h_expe_infra_transz_lim_P;

/* Block signals (auto storage) */
extern BlockIO_M37_Sim_Forcing_003h_expe_infra_transz_lim
  M37_Sim_Forcing_003h_expe_infra_transz_lim_B;

/* Block states (auto storage) */
extern D_Work_M37_Sim_Forcing_003h_expe_infra_transz_lim
  M37_Sim_Forcing_003h_expe_infra_transz_lim_DWork;

/* External data declarations for dependent source files */
extern uint8_T M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;/* uint8_T ground */
extern int64m_T M37_Sim_Forcing_003h_expe_infra_transz_lim_sfix64_En41_GND;/* int64m_T ground */
extern uint8_T M37_Sim_Forcing_003h_expe_infra_transz_lim_U8GND;/* uint8_T ground */
extern int64m_T M37_Sim_Forcing_003h_expe_infra_transz_lim_sfix64_En41_GND;/* int64m_T ground */

/* Model entry point functions */
extern void M37_Sim_Forcing_003h_expe_infra_transz_lim_initialize(boolean_T
  firstTime);
extern void M37_Sim_Forcing_003h_expe_infra_transz_lim_output(int_T tid);
extern void M37_Sim_Forcing_003h_expe_infra_transz_lim_update(int_T tid);
extern void M37_Sim_Forcing_003h_expe_infra_transz_lim_terminate(void);

/* Real-time Model object */
extern RT_MODEL_M37_Sim_Forcing_003h_expe_infra_transz_lim
  *M37_Sim_Forcing_003h_expe_infra_transz_lim_M;

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
 * '<Root>' : M37_Sim_Forcing_003h_expe_infra_transz_lim
 * '<S1>'   : M37_Sim_Forcing_003h_expe_infra_transz_lim/6_DOF Visual Cab 12//06//15
 * '<S2>'   : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)
 * '<S3>'   : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15
 * '<S4>'   : M37_Sim_Forcing_003h_expe_infra_transz_lim/Controls to GT-RT
 * '<S5>'   : M37_Sim_Forcing_003h_expe_infra_transz_lim/Data to Control Node 12//06//15
 * '<S6>'   : M37_Sim_Forcing_003h_expe_infra_transz_lim/Enable_connection
 * '<S7>'   : M37_Sim_Forcing_003h_expe_infra_transz_lim/Handshake CAN
 * '<S8>'   : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1
 * '<S9>'   : M37_Sim_Forcing_003h_expe_infra_transz_lim/Safety Connect
 * '<S10>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Stick Conditioning
 * '<S11>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/delay_calc
 * '<S12>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Receive
 * '<S13>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send
 * '<S14>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches
 * '<S15>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/velocity and acceleration limitation
 * '<S16>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Receive/Convert 4*uni8 to int
 * '<S17>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Receive/Convert 4*uni8 to int1
 * '<S18>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Receive/Convert 4*uni8 to int2
 * '<S19>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Receive/Convert 4*uni8 to int3
 * '<S20>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Receive/Convert 4*uni8 to int4
 * '<S21>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Receive/Convert 4*uni8 to int5
 * '<S22>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1
 * '<S23>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8
 * '<S24>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 1
 * '<S25>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 2
 * '<S26>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 3
 * '<S27>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 4
 * '<S28>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 5
 * '<S29>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 /Shift Arithmetic
 * '<S30>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 /Shift Arithmetic1
 * '<S31>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 /Shift Arithmetic2
 * '<S32>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 1/Shift Arithmetic
 * '<S33>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 1/Shift Arithmetic1
 * '<S34>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 1/Shift Arithmetic2
 * '<S35>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 2/Shift Arithmetic
 * '<S36>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 2/Shift Arithmetic1
 * '<S37>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 2/Shift Arithmetic2
 * '<S38>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 3/Shift Arithmetic
 * '<S39>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 3/Shift Arithmetic1
 * '<S40>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 3/Shift Arithmetic2
 * '<S41>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 4/Shift Arithmetic
 * '<S42>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 4/Shift Arithmetic1
 * '<S43>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 4/Shift Arithmetic2
 * '<S44>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 5/Shift Arithmetic
 * '<S45>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 5/Shift Arithmetic1
 * '<S46>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/CAN Send/If Action Subsystem1/Convert int to 4*uni8 5/Shift Arithmetic2
 * '<S47>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem
 * '<S48>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem1
 * '<S49>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem2
 * '<S50>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem3
 * '<S51>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem4
 * '<S52>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem5
 * '<S53>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem/If Action Subsystem
 * '<S54>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem/If Action Subsystem1
 * '<S55>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem1/If Action Subsystem
 * '<S56>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem1/If Action Subsystem1
 * '<S57>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem2/If Action Subsystem
 * '<S58>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem2/If Action Subsystem1
 * '<S59>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem3/If Action Subsystem
 * '<S60>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem3/If Action Subsystem1
 * '<S61>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem4/If Action Subsystem
 * '<S62>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem4/If Action Subsystem1
 * '<S63>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem5/If Action Subsystem
 * '<S64>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/BEC (May 7, 2015)/Software limit switches/Subsystem5/If Action Subsystem1
 * '<S65>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Compare To Zero
 * '<S66>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion
 * '<S67>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Embedded MATLAB Function
 * '<S68>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move UP1
 * '<S69>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin
 * '<S70>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Timeline
 * '<S71>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/compute_offset
 * '<S72>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/select_ang_speed
 * '<S73>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 1
 * '<S74>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 2
 * '<S75>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 2015
 * '<S76>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 1/Compare To Zero
 * '<S77>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 1/Compare To Zero1
 * '<S78>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 1/Smooth Displacement Second-Order Filter, zeta 0.8
 * '<S79>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 1/Smooth Displacement Second-Order Filter, zeta 0.8/Discrete Derivative
 * '<S80>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 2/Compare To Zero
 * '<S81>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 2/Compare To Zero1
 * '<S82>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 2/Smooth Displacement Second-Order Filter, zeta 0.8
 * '<S83>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 2/Smooth Displacement Second-Order Filter, zeta 0.8/Discrete Derivative
 * '<S84>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 2015/Compare To Zero
 * '<S85>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 2015/Compare To Zero1
 * '<S86>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 2015/Smooth Displacement Second-Order Filter, zeta 0.8
 * '<S87>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Ellipse motion/Phase Shifted Sine 17th 2015/Smooth Displacement Second-Order Filter, zeta 0.8/Discrete Derivative
 * '<S88>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move UP1/Smooth Displacement Second-Order Filter, zeta 0.8
 * '<S89>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move UP1/add x_offset
 * '<S90>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move UP1/curve
 * '<S91>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move UP1/Smooth Displacement Second-Order Filter, zeta 0.8/Discrete Derivative
 * '<S92>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move UP1/add x_offset/Embedded MATLAB Function
 * '<S93>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/Subsystem
 * '<S94>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase
 * '<S95>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/Subsystem/Embedded MATLAB Function3
 * '<S96>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Embedded MATLAB Function1
 * '<S97>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Embedded MATLAB Function2
 * '<S98>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Embedded MATLAB Function3
 * '<S99>'  : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Embedded MATLAB Function5
 * '<S100>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Rate Control Dynamics X
 * '<S101>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Rate Control Dynamics Y
 * '<S102>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Rate Control Dynamics Z
 * '<S103>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Second-Order Filter, zeta 0.9
 * '<S104>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Stay within ellipse 20//07//15
 * '<S105>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Rate Control Dynamics X/Second-Order Filter, zeta 0.8
 * '<S106>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Rate Control Dynamics X/Smooth Displacement Second-Order Filter, zeta 0.8
 * '<S107>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Rate Control Dynamics X/Smooth Displacement Second-Order Filter, zeta 0.8/Discrete Derivative
 * '<S108>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Rate Control Dynamics Y/Second-Order Filter, zeta 0.8
 * '<S109>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Rate Control Dynamics Y/Smooth Displacement Second-Order Filter, zeta 0.8
 * '<S110>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Rate Control Dynamics Y/Smooth Displacement Second-Order Filter, zeta 0.8/Discrete Derivative
 * '<S111>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Rate Control Dynamics Z/Second-Order Filter, zeta 0.8
 * '<S112>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Rate Control Dynamics Z/Smooth Displacement Second-Order Filter, zeta 0.8
 * '<S113>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Rate Control Dynamics Z/Smooth Displacement Second-Order Filter, zeta 0.8/Discrete Derivative
 * '<S114>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Move_cabin/expe_phase/Stay within ellipse 20//07//15/Get R
 * '<S115>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Timeline/Compare To Constant5
 * '<S116>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Timeline/Compare To Constant9
 * '<S117>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Timeline/Compare To Zero
 * '<S118>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Timeline/Embedded MATLAB Function
 * '<S119>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/Timeline/Embedded MATLAB Function1
 * '<S120>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/compute_offset/Embedded MATLAB Function2
 * '<S121>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/compute_offset/Embedded MATLAB Function3
 * '<S122>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/compute_offset/Smooth Displacement Second-Order Filter, zeta 0.8
 * '<S123>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/compute_offset/Smooth Displacement Second-Order Filter, zeta 0.8/Discrete Derivative
 * '<S124>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Breaking_Control 20//07//15/select_ang_speed/Embedded MATLAB Function2
 * '<S125>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Data to Control Node 12//06//15/6_DOF Control
 * '<S126>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Data to Control Node 12//06//15/Interaction device from VIS (Stick)
 * '<S127>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Handshake CAN/If Action Subsystem
 * '<S128>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Handshake CAN/If Action Subsystem1
 * '<S129>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Forward Kinematics
 * '<S130>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Increments
 * '<S131>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015
 * '<S132>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Subtract psi offset
 * '<S133>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Forward Kinematics/Embedded MATLAB Function
 * '<S134>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Forward Kinematics/KUKA2NED
 * '<S135>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Inverse Kinematics
 * '<S136>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Manual Switch
 * '<S137>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/NED2KUKA
 * '<S138>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics
 * '<S139>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Inverse Kinematics/full inverse kin
 * '<S140>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Inverse Kinematics/full inverse kin/Embedded MATLAB Function
 * '<S141>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics/A1-A6 COM
 * '<S142>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics/Simplified Inverse Kin
 * '<S143>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics/Simplified Inverse Kin/Embedded MATLAB Function1
 * '<S144>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics/Simplified Inverse Kin/Embedded MATLAB Function2
 * '<S145>' : M37_Sim_Forcing_003h_expe_infra_transz_lim/Joint Controller (May 7, 2015)1/Inverse Kinematics May 6, 2015/Simplified Inverse Kinematics/Simplified Inverse Kin/Embedded MATLAB Function3
 */
#endif                                 /* RTW_HEADER_M37_Sim_Forcing_003h_expe_infra_transz_lim_h_ */

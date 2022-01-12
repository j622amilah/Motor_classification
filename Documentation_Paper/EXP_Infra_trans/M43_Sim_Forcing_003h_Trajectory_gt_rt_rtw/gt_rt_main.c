/******************************************************************** 
 * Copyright (C) 2008 GIGATRONIK Stuttgart GmbH
 *
 * $Id: gt_rt_main.c 435 2011-04-01 11:50:57Z gt\pfand $
 *
 *
 * Compiler specified defines:
 *	RT              - Required.
 *      MODEL=modelname - Required.
 *	NUMST=#         - Required. Number of sample times.
 *	NCSTATES=#      - Required. Number of continuous states.
 *      TID01EQ=1 or 0  - Optional. Only define to 1 if sample time task
 *                        id's 0 and 1 have equal rates.
 *      MULTITASKING    - Optional. (use MT for a synonym).
 *	SAVEFILE        - Optional (non-quoted) name of .mat file to create.
 *			  Default is <MODEL>.mat
 ********************************************************************/

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <getopt.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

#include <linux/unistd.h>

#include <sys/prctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <malloc.h>

#include <gt_rt_core/gt_rt_core.h>
#include <gt_rt_core/gt_rt_log.h>
#include <gt_rt_xcp/gt_rt_xcp_server.h>
#include <gt_rt_monitor/gt_rt_monitor.h>

#include "rtwtypes.h"
#include "rtmodel.h"
#include "rt_sim.h"
#include "rt_logging.h"
#ifdef UseMMIDataLogging
#include "rt_logging_mmi.h"
#endif
#include "rt_nonfinite.h"

#include "ext_work.h"

/********************************************************************
  no include for this function 
********************************************************************/ 
extern int clock_nanosleep(clockid_t __clock_id, int __flags,
			   __const struct timespec *__req,
			   struct timespec *__rem);

/********************************************************************
  defines
********************************************************************/ 
#define EXTCOMM_SLEEP_USEC  10000
#define STAT_COMM_USEC      1000000
#define USEC_PER_SEC		1000000
#define NSEC_PER_SEC		1000000000
#define SCHEDULER           SCHED_RR

#ifndef MIN
#define MIN(x,y) (((x)<(y))?(x):(y))
#endif
#ifndef MAX
#define MAX(x,y) (((x)>(y))?(x):(y))
#endif

#ifndef TRUE
#define FALSE (0)
#define TRUE  (1)
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE  1
#endif
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS  0
#endif

#define QUOTE1(name) #name
#define QUOTE(name) QUOTE1(name)    /* need to expand name    */

#ifndef RT
# error "must define RT"
#endif

#ifndef MODEL
# error "must define MODEL"
#endif

#ifndef NUMST
# error "must define number of sample times, NUMST"
#endif

#ifndef NCSTATES
# error "must define NCSTATES"
#endif

#ifndef SAVEFILE
# define MATFILE2(file) #file ".mat"
# define MATFILE1(file) MATFILE2(file)
# define MATFILE MATFILE1(MODEL)
#else
# define MATFILE QUOTE(SAVEFILE)
#endif

#define RUN_FOREVER -1.0

#define EXPAND_CONCAT(name1,name2) name1 ## name2
#define CONCAT(name1,name2) EXPAND_CONCAT(name1,name2)
#define RT_MODEL            CONCAT(MODEL,_rtModel)


/********************************************************************
  external RTW functions
********************************************************************/ 
extern RT_MODEL *MODEL(void);

extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

#if NCSTATES > 0
extern void rt_ODECreateIntegrationData(RTWSolverInfo *si);
extern void rt_ODEUpdateContinuousStates(RTWSolverInfo *si);

# define rt_CreateIntegrationData(S)                    \
  rt_ODECreateIntegrationData(rtmGetRTWSolverInfo(S));
# define rt_UpdateContinuousStates(S)                   \
  rt_ODEUpdateContinuousStates(rtmGetRTWSolverInfo(S));
# else
# define rt_CreateIntegrationData(S)                                    \
  rtsiSetSolverName(rtmGetRTWSolverInfo(S),"FixedStepDiscrete");
# define rt_UpdateContinuousStates(S) /* Do Nothing */
#endif

#ifdef EXT_MODE
#  define rtExtModeSingleTaskUpload(S)                          \
  {                                                             \
    int stIdx;                                                  \
    rtExtModeUploadCheckTrigger(rtmGetNumSampleTimes(S));       \
    for (stIdx=0; stIdx<NUMST; stIdx++) {                       \
      if (rtmIsSampleHit(S, stIdx, 0 /*unused*/)) {             \
        rtExtModeUpload(stIdx,rtmGetTaskTime(S,stIdx));         \
      }                                                         \
    }                                                           \
  }
#else
#  define rtExtModeSingleTaskUpload(S) /* Do nothing */
#endif


/********************************************************************
  global data local to this module
********************************************************************/ 
typedef struct {
  long cur_time;
  long min_time;
  long max_time;
} time_info_type;

typedef struct {
  pthread_t thread;
  pthread_attr_t attr;
  time_info_type jitter;
  time_info_type duration;
  int prio;
  int rate_idx;
  int overrun_flag;
} thread_info_type;

static thread_info_type thread_infos[NUMST];


static struct {
  int_T stop_execution_flag;
  const char_T *errmsg;
  RT_MODEL *S;
} GLOBAL;



#if !defined(MT)  /* SINGLETASKING */
/********************************************************************
  rt_OneStep - single-tasking

  @param S the RTW model
********************************************************************/ 
static void rt_OneStep(RT_MODEL *S)
{
  real_T tnext;
  
  /***********************************************
   * Check and see if error status has been set  *
   ***********************************************/
  
  if (rtmGetErrorStatus(S) != NULL) {
    GLOBAL.stop_execution_flag = 1;
    return;
  }
  
  /* enable interrupts here */
  
  tnext = rt_SimGetNextSampleHit();
  rtsiSetSolverStopTime(rtmGetRTWSolverInfo(S),tnext);
  
  MdlOutputs(0);
  
  rtExtModeSingleTaskUpload(S);

  GLOBAL.errmsg = rt_UpdateTXYLogVars(rtmGetRTWLogInfo(S),
				      rtmGetTPtr(S));
  if (GLOBAL.errmsg != NULL) {
    GLOBAL.stop_execution_flag = 1;
    return;
  }
  
  rt_UpdateSigLogVars(rtmGetRTWLogInfo(S), rtmGetTPtr(S));

  MdlUpdate(0);
  rt_SimUpdateDiscreteTaskSampleHits(rtmGetNumSampleTimes(S),
				     rtmGetTimingData(S),
				     rtmGetSampleHitPtr(S),
				     rtmGetTPtr(S));
  if (rtmGetSampleTime(S,0) == CONTINUOUS_SAMPLE_TIME) {
    rt_UpdateContinuousStates(S);
  }
  
  rtExtModeCheckEndTrigger();
  
} /* end rtOneStep */

#else /* MT */

# if TID01EQ == 1
#  define FIRST_TID 1
# else
#  define FIRST_TID 0
# endif

/********************************************************************
  rt_OneStep - multi-tasking

  @param S the RTW model
********************************************************************/ 
static void rt_OneStep(RT_MODEL *S)
{
  int_T  i;
  real_T tnext;
  int_T  *sampleHit = rtmGetSampleHitPtr(S);

  /***********************************************
   * Check and see if error status has been set  *
   ***********************************************/

  if (rtmGetErrorStatus(S) != NULL) {
    GLOBAL.stop_execution_flag = 1;
    return;
  }
  /* enable interrupts here */

  /************************************************************************
   * Update discrete events and buffer event flags locally so that ISR is *
   * re-entrant.                                                          *
   ************************************************************************/

  tnext = rt_SimUpdateDiscreteEvents(rtmGetNumSampleTimes(S),
                                     rtmGetTimingData(S),
                                     rtmGetSampleHitPtr(S),
                                     rtmGetPerTaskSampleHitsPtr(S));
  rtsiSetSolverStopTime(rtmGetRTWSolverInfo(S),tnext);
  for (i=FIRST_TID+1; i < NUMST; i++) {
    if (sampleHit[i]) {
      /* signal sub rate to compute */
      pthread_kill(thread_infos[i].thread, SIGRTMIN);
    }
  }

  /*******************************************
   * Step the model for the base sample time *
   *******************************************/

  MdlOutputs(FIRST_TID);

  rtExtModeUploadCheckTrigger(rtmGetNumSampleTimes(S));
  rtExtModeUpload(FIRST_TID,rtmGetTaskTime(S, FIRST_TID));

  GLOBAL.errmsg = rt_UpdateTXYLogVars(rtmGetRTWLogInfo(S),
                                      rtmGetTPtr(S));
  if (GLOBAL.errmsg != NULL) {
    GLOBAL.stop_execution_flag = 1;
    return;
  }

  rt_UpdateSigLogVars(rtmGetRTWLogInfo(S), rtmGetTPtr(S));

  MdlUpdate(FIRST_TID);

  if (rtmGetSampleTime(S,0) == CONTINUOUS_SAMPLE_TIME) {
    rt_UpdateContinuousStates(S);
  }
  else {
    rt_SimUpdateDiscreteTaskTime(rtmGetTPtr(S), 
                                 rtmGetTimingData(S), 0);
  }

#if FIRST_TID == 1
  rt_SimUpdateDiscreteTaskTime(rtmGetTPtr(S), 
                               rtmGetTimingData(S),1);
#endif


  /************************************************************************
   * Model step complete for base sample time, now it is okay to          *
   * re-interrupt this ISR.                                               *
   ************************************************************************/


  rtExtModeCheckEndTrigger();

} /* end rtOneStep */

#endif /* MT */


/**********************************************************************
 * display_usage
 *
 * Displays the command line usage
 **********************************************************************/
static void display_usage (void)
{
  printf("usage: %s -w -port <TCPport>\n", QUOTE(MODEL));
  printf("arguments:\n");
  printf("  -w              - waits for Simulink to start model "
         "in External Mode.\n");
  printf("  -port <TCPport> - overrides 17725 default port in "
         "External Mode, valid range 256 to 65535.\n");
}

/**********************************************************************
 * setprio
 *
 * Sets the priority and scheduling policy of the active thread
 *
 * @param prio The priority
 * @param sched The scheduling policy (SCHED_RR or SCHED_FIFO)
 **********************************************************************/
static void setprio(int prio, int sched)
{
  struct sched_param schedp;

  memset(&schedp, 0, sizeof(schedp));
  schedp.sched_priority = prio;
  if (sched_setscheduler(0, sched, &schedp) < 0) {
    perror("sched_setscheduler failed");
  }
}

/**********************************************************************
 * signal_handler
 *
 * Handler function for SIGTERM and SIGINT
 *
 * @param sig Signal received
 **********************************************************************/
static void signal_handler(int sig)
{
  GLOBAL.stop_execution_flag = 1;
}


/**********************************************************************
 * timespec_norm
 *
 * Normalizes the nanoseconds in timespec structs
 *
 * @param ts Pointer to the timespec struct
 **********************************************************************/
static void timespec_norm(struct timespec *ts)
{
  while (ts->tv_nsec >= NSEC_PER_SEC) {
    ts->tv_nsec -= NSEC_PER_SEC;
    ++ts->tv_sec;
  }
}

/**********************************************************************
 * timespec_diff
 *
 * Computes the time difference in micro seconds
 *
 * @param t1 later time
 * @param t2 earlier time
 **********************************************************************/
static long timespec_diff(struct timespec t1, struct timespec t2)
{
  long diff;
  diff = USEC_PER_SEC * (t1.tv_sec - t2.tv_sec);
  diff += (t1.tv_nsec - t2.tv_nsec) / 1000;
  return diff;
}

/**********************************************************************
 * time_info_compute
 *
 * Computes the minimum and maximum values of jitter and duration
 *
 * @param t time_info_type struct
 **********************************************************************/
static void time_info_compute(time_info_type* t)
{
  t->min_time = MIN(t->min_time, t->cur_time);
  t->max_time = MAX(t->max_time, t->cur_time);
}


/**********************************************************************
 * base_rate_thread
 *
 * Thread function for Simulink base rate
 *
 * @param param Thread parameters
 **********************************************************************/
static void* base_rate_thread(void* param)
{
  thread_info_type* thread_info;
  struct timespec next;
  struct timespec interval;
  struct timespec start;
  struct timespec end;
  sigset_t sigset;
  double step_size;
  long step_size_usecs;
  int sig;

  thread_info = (thread_info_type*)param;

  /* compute interval timespec */
  step_size = rtmGetStepSize(GLOBAL.S);
  interval.tv_sec = 0;
  while (step_size > 1.0) {
    step_size -= 1.0;
    ++interval.tv_sec;
  }
  interval.tv_nsec = (long)(step_size * NSEC_PER_SEC + 0.5);
  step_size_usecs = (long)(step_size * USEC_PER_SEC + 0.5);

  /* block SIGALRM */
  sigemptyset(&sigset);
  sigaddset(&sigset, SIGALRM);
  sigaddset(&sigset, SIGRTMIN);
  //sigprocmask(SIG_SETMASK, &sigset, NULL);
  pthread_sigmask(SIG_SETMASK, &sigset, NULL);

  /* set RT policy and priority */
  setprio(thread_info->prio, SCHEDULER);

  /* wait for signal from main thread */
  while ((sig = sigwaitinfo(&sigset, NULL)) != SIGRTMIN) {
    if (sig == -1) {
      perror("Sigwaitinfo failed." 
	     " Some signal other than SIGRTMIN and SIGALRM has been caught"
	     " by some signal handler. Most likely by gdb.");
    } 
  }

  /* compute next time point */
  clock_gettime(CLOCK_REALTIME, &next);
  start = next;
  next.tv_sec += interval.tv_sec;
  next.tv_nsec += interval.tv_nsec;
  timespec_norm(&next);
  
  while (!GLOBAL.stop_execution_flag) {
    /* wait for next time step */
    clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &next, NULL);
    /* compute jitter */
    clock_gettime(CLOCK_REALTIME, &start);
    thread_info->jitter.cur_time = timespec_diff(start, next);
    time_info_compute(&thread_info->jitter);
    /* compute next time point */
    next.tv_sec += interval.tv_sec;
    next.tv_nsec += interval.tv_nsec;
    timespec_norm(&next);
    /* compute Simulink model */
    rt_OneStep(GLOBAL.S);
    /* get current time */
    clock_gettime(CLOCK_REALTIME, &end);
    /* XCP event */
    gt_rt_xcp_server_send_event(0, NULL);
    /* check for overrun */
    thread_info->duration.cur_time = timespec_diff(end, start);
    time_info_compute(&thread_info->duration);
    if (thread_info->duration.cur_time > step_size_usecs) {
      thread_info->overrun_flag = 1;
    }
  }

  /* switch back to normal */
  setprio(0, SCHED_OTHER);

  return NULL;
}

/**********************************************************************
 * sub_rate_thread
 *
 * Thread function for Simulink sub rates (only for Simulink multitasking)
 *
 * @param param Thread parameters
 **********************************************************************/
#ifdef MT
static void* sub_rate_thread(void* param)
{
  thread_info_type* thread_info;
  struct timespec next;
  struct timespec interval;
  struct timespec start;
  struct timespec end;
  int first_time;
  sigset_t sigset;
  double step_size;
  long step_size_usecs;

  thread_info = (thread_info_type*)param;


  /* compute interval timespec */
  step_size = rtmGetSampleTime(GLOBAL.S, thread_info->rate_idx);
  interval.tv_sec = 0;
  while (step_size > 1.0) {
    step_size -= 1.0;
    ++interval.tv_sec;
  }
  interval.tv_nsec = (long)(step_size * NSEC_PER_SEC + 0.5);
  step_size_usecs = (long)(step_size * USEC_PER_SEC + 0.5);

  /* block SIGALRM */
  sigemptyset(&sigset);
  sigaddset(&sigset, SIGALRM);
  sigaddset(&sigset, SIGRTMIN);
  //sigprocmask(SIG_SETMASK, &sigset, NULL);
  pthread_sigmask(SIG_SETMASK, &sigset, NULL);

  /* set RT policy and priority */
  setprio(thread_info->prio, SCHEDULER);


  /* loop endlessly */
  first_time = 1;
  while (!GLOBAL.stop_execution_flag) {
    /* wait for activation by base_rate_thread */
    if (sigwaitinfo(&sigset, NULL) == SIGRTMIN) {
      /* compute jitter */
      clock_gettime(CLOCK_REALTIME, &start);
      if (first_time) {
	first_time = 0;
	next = start;
      } else {
	thread_info->jitter.cur_time = timespec_diff(start, next);
	time_info_compute(&thread_info->jitter);
      }

      /* compute next time point */
      next.tv_sec += interval.tv_sec;
      next.tv_nsec += interval.tv_nsec;
      timespec_norm(&next);

      /* compute model */
      MdlOutputs(thread_info->rate_idx);
      
      rtExtModeUpload(thread_info->rate_idx, rtmGetTaskTime(GLOBAL.S, thread_info->rate_idx));
      
      MdlUpdate(thread_info->rate_idx);
      
      rt_SimUpdateDiscreteTaskTime(rtmGetTPtr(GLOBAL.S), 
				   rtmGetTimingData(GLOBAL.S), thread_info->rate_idx);

      /* XCP event */
      /*
        gt_rt_xcp_server_send_event(thread_info->rate_idx, NULL);
      */

      
      /* check for overrun */
      clock_gettime(CLOCK_REALTIME, &end);
      thread_info->duration.cur_time = timespec_diff(end, start);
      time_info_compute(&thread_info->duration);
      if (thread_info->duration.cur_time > step_size_usecs) {
        thread_info->overrun_flag = 1;
      }
    }
  }

  return NULL;
}
#endif /* MT */

/**********************************************************************
 * main
 **********************************************************************/
int_T main(int argc, char *argv[])
{
  GError* err = NULL;
  sigset_t sigset;
  int i;
  int prio;
  int32_t elapsed_usec;
  guint _log_handler_id = 0;
  
  /* change the column_count to the number of columns in your thread info table. */
  const int column_count = 11;
  int mono_stat_array[NUMST*column_count]; 

  /* preparing the data for the monitor start */
  const char userinfo[] = SIMULINKUSER ", " SIMULINKHOST;
  
  /* lock memory into RAM */
  if (mlockall(MCL_CURRENT | MCL_FUTURE)) {
    fprintf(stderr, "mlockall failed");    exit(EXIT_FAILURE);
  }
  mallopt(M_TRIM_THRESHOLD, -1);
  mallopt(M_MMAP_MAX, 0);

  gt_rt_core_init(argc, argv, &err);
  if (err != NULL) {
    fprintf(stderr, "Failed to parse command line options: %s\n",
	    err->message);
    g_error_free(err);
    exit(1);
  }
  
  /* parse command line arguments */
  rtExtModeParseArgs(argc, (const char_T**)argv, NULL);

  /* check for unprocessed arguments */
  for (i=1; i<argc; ++i) {
    if (argv[i] != NULL) {
      fprintf(stderr, "Unexpected command line argument: %s\n", argv[i]);
      display_usage();
      exit(EXIT_FAILURE);
    }
  }
  
  /* initialize log handler */
  _log_handler_id = gt_rt_log_init(G_LOG_DOMAIN, NULL);

  /* initialize global info data */
  memset(&GLOBAL, 0, sizeof(GLOBAL));

  /* initialize thread info data */
  prio = sched_get_priority_max(SCHEDULER);
  if (NUMST > prio) {
    g_critical("The model has too many tasks: %d. The maximum number of tasks is %d.",
               NUMST, prio);
    exit(EXIT_FAILURE);
  }
  for (i=0; i<NUMST; ++i) {
    memset(&thread_infos[i], 0, sizeof(thread_infos[i]));
    thread_infos[i].rate_idx = i;
    thread_infos[i].prio = prio;
    --prio;
    thread_infos[i].jitter.min_time = LONG_MAX;
    thread_infos[i].jitter.max_time = LONG_MIN;
    thread_infos[i].duration.min_time = LONG_MAX;
    thread_infos[i].duration.max_time = LONG_MIN;
  }


  /* initialize signal handling */
  sigemptyset(&sigset);
  sigaddset(&sigset, SIGALRM);
  sigaddset(&sigset, SIGRTMIN);
  //sigprocmask(SIG_SETMASK, &sigset, NULL);
  pthread_sigmask(SIG_SETMASK, &sigset, NULL);
  signal(SIGINT, signal_handler);
  signal(SIGTERM, signal_handler);

  /* initialize the model */
  rt_InitInfAndNaN(sizeof(real_T));
  
  GLOBAL.S = MODEL();
  if (rtmGetErrorStatus(GLOBAL.S) != NULL) {
    g_critical("Error during model registration: %s",
               rtmGetErrorStatus(GLOBAL.S));
    exit(EXIT_FAILURE);
  }

  MdlInitializeSizes();
  MdlInitializeSampleTimes();
  
  GLOBAL.errmsg = rt_SimInitTimingEngine(rtmGetNumSampleTimes(GLOBAL.S),
                                         rtmGetStepSize(GLOBAL.S),
                                         rtmGetSampleTimePtr(GLOBAL.S),
                                         rtmGetOffsetTimePtr(GLOBAL.S),
                                         rtmGetSampleHitPtr(GLOBAL.S),
                                         rtmGetSampleTimeTaskIDPtr(GLOBAL.S),
                                         rtmGetTStart(GLOBAL.S),
                                         &rtmGetSimTimeStep(GLOBAL.S),
                                         &rtmGetTimingData(GLOBAL.S));
  
  if (GLOBAL.errmsg != NULL) {
    g_critical(
               "Failed to initialize sample time engine: %s", GLOBAL.errmsg);
    exit(EXIT_FAILURE);
  }
  rt_CreateIntegrationData(GLOBAL.S);
  
#ifdef UseMMIDataLogging
  rt_FillStateSigInfoFromMMI(rtmGetRTWLogInfo(GLOBAL.S),&rtmGetErrorStatus(GLOBAL.S));
  rt_FillSigLogInfoFromMMI(rtmGetRTWLogInfo(GLOBAL.S),&rtmGetErrorStatus(GLOBAL.S));
#endif
  GLOBAL.errmsg = rt_StartDataLogging(rtmGetRTWLogInfo(GLOBAL.S),
				      rtmGetTFinal(GLOBAL.S),
				      rtmGetStepSize(GLOBAL.S),
				      &rtmGetErrorStatus(GLOBAL.S));
  if (GLOBAL.errmsg != NULL) {
    g_critical("Error starting data logging: %s",GLOBAL.errmsg);
    return(EXIT_FAILURE);
  }
  
  rtExtModeCheckInit(rtmGetNumSampleTimes(GLOBAL.S));
  rtExtModeWaitForStartPkt(rtmGetRTWExtModeInfo(GLOBAL.S),
			   rtmGetNumSampleTimes(GLOBAL.S),
			   (boolean_T *)&rtmGetStopRequested(GLOBAL.S));

  /* Start the XCP server.*/
  /*g_message("starting the XCP server");
  gt_rt_xcp_server_start(prio, SCHEDULER, &err);
  if (err != NULL) {
    g_critical("Failed to start XCP server: %s", err->message);
    g_error_free(err);
    err = NULL;
  }
  */
  /* Mono monitor start.*/
  if (gt_rt_get_option_no_monitor()) {
    g_message("model info update in GT-RT web monitor is deactivated");
  } else {
    g_message("starting the GT-RT monitor");
    gt_rt_monitor_start(NUMST, mono_stat_array, prio-1, SCHEDULER, 
                        userinfo, "ID,Step size,Offset,Jitter Current,Jitter Min,Jitter Max,Duration Current,Duration Min,Duration Max,Overrun,Priority",column_count, QUOTE(MODEL), &err);
    if (err != NULL) {
      g_critical("Failed to start GT-RT monitor: %s\n", err->message);
      g_error_free(err);
      err = NULL;
    } 
  }

  g_message("starting the model");
  MdlStart();
  if (rtmGetErrorStatus(GLOBAL.S) != NULL) {
    g_critical("Failed to initialize the model: %s",
	       rtmGetErrorStatus(GLOBAL.S));
    g_critical("THE SIMULINK MODEL WILL BE STOPPED AND TERMINATED!!!");
    GLOBAL.stop_execution_flag = 1;
  }
  
  /* create base rate thread */
  g_message("creating base rate thread");
  if (pthread_attr_init(&thread_infos[0].attr)) {
    g_critical("Failed to initialize thread attributes");
    exit(EXIT_FAILURE);
  }
  if (pthread_attr_setstacksize(&thread_infos[0].attr, PTHREAD_STACK_MIN + 2000*1024)) {
    g_critical("Failed to set thread stack size");
    exit(EXIT_FAILURE);
  }
  pthread_create(&thread_infos[0].thread, &thread_infos[0].attr, base_rate_thread, &thread_infos[0]);

#ifdef MT
  /* create sub rate threads */
  for (i=FIRST_TID+1; i<NUMST; ++i) {
    g_message("creating sub rate thread %d", i);
    if (pthread_attr_init(&thread_infos[i].attr)) {
      g_critical("Failed to initialize thread attributes");
      exit(EXIT_FAILURE);
    }
    if (pthread_attr_setstacksize(&thread_infos[i].attr, PTHREAD_STACK_MIN + 2000*1024)) {
      g_critical("Failed to set thread stack size");
      exit(EXIT_FAILURE);
    }
    pthread_create(&thread_infos[i].thread, &thread_infos[i].attr, sub_rate_thread, &thread_infos[i]);
  }
#endif /* MT */

  /* execute the model */
  if (rtmGetTFinal(GLOBAL.S) == RUN_FOREVER) {
    g_message ("May run forever. Model stop time set to infinity.");
  }

  /* start the base rate thread */
  pthread_kill(thread_infos[0].thread, SIGRTMIN);

  /* loop endlessly and do external mode communication */
  elapsed_usec = 0;
  while (!GLOBAL.stop_execution_flag) {
    rtExtModePauseIfNeeded(rtmGetRTWExtModeInfo(GLOBAL.S),
			   rtmGetNumSampleTimes(GLOBAL.S),
			   (boolean_T *)&rtmGetStopRequested(GLOBAL.S));
    
    if (rtmGetStopRequested(GLOBAL.S)) {
      GLOBAL.stop_execution_flag = 1;
    }
    rtExtModeOneStep(rtmGetRTWExtModeInfo(GLOBAL.S),
		     rtmGetNumSampleTimes(GLOBAL.S),
		     (boolean_T *)&rtmGetStopRequested(GLOBAL.S));
    usleep(EXTCOMM_SLEEP_USEC);
    if (!gt_rt_get_option_no_monitor()) {
      elapsed_usec += EXTCOMM_SLEEP_USEC;
      if (elapsed_usec >= STAT_COMM_USEC) {
        /* Store thread statistics in micro seconds to the mono_stat_array */
        for (i=0; i<NUMST; ++i) {      
          if (i == 0) {
            mono_stat_array[0 * column_count + 1] = (int)(rtmGetStepSize(GLOBAL.S)*1e6);
            mono_stat_array[0 * column_count + 2] = 0;
          }
          else {
            mono_stat_array[i * column_count + 1] = (int)(rtmGetSampleTime(GLOBAL.S, i)*1e6);
            mono_stat_array[i * column_count + 2] = (int)(((rtmGetOffsetTimePtr(GLOBAL.S))[i])*1e6);
          }
          mono_stat_array[i * column_count     ] = i;	
          mono_stat_array[i * column_count + 3 ] = thread_infos[i].jitter.cur_time;
          mono_stat_array[i * column_count + 4 ] = thread_infos[i].jitter.min_time;
          mono_stat_array[i * column_count + 5 ] = thread_infos[i].jitter.max_time;		
          mono_stat_array[i * column_count + 6 ] = thread_infos[i].duration.cur_time;
          mono_stat_array[i * column_count + 7 ] = thread_infos[i].duration.min_time;
          mono_stat_array[i * column_count + 8 ] = thread_infos[i].duration.max_time;
          mono_stat_array[i * column_count + 9 ] = thread_infos[i].overrun_flag;
          mono_stat_array[i * column_count + 10] = thread_infos[i].prio;
        }
        elapsed_usec = 0;
      }
    }
  }
  
  	//write a small stat file containing the last current stats of the execution
	FILE *file = fopen("stats_avr.log", "r");
	if (file == NULL) {
		file = fopen("stats_avr.log", "a");
		fprintf(file, "JitterMin JitterMax DurationMin DurationMax Overrun\n");
	} else {
		fclose(file);
		file = fopen("stats_avr.log", "a");
	}

	fprintf(file, "%i %i %i %i %i\n", 
		mono_stat_array[4],
		mono_stat_array[5],
		mono_stat_array[7],
		mono_stat_array[8],
		mono_stat_array[9]);
	fclose(file);

#ifdef MT
  /* kill sub rate threads */
  for (i=FIRST_TID+1; i<NUMST; ++i) {
    g_message("joining sub rate thread %d", i);
    /* Send SIGRTMIN signal to sub rates so that they do not wait for ever
       on sigwaitinfo after base rate has died */
    pthread_kill(thread_infos[i].thread, SIGRTMIN);
    if (pthread_join(thread_infos[i].thread, NULL) != 0) {
      g_message("join failed. Killing sub rate thread %d", i);
      pthread_kill(thread_infos[i].thread, SIGTERM);
    }
  }
#endif /* MT */

    /* kill base rate thread */
    g_message("joining base rate thread");
    if (pthread_join(thread_infos[0].thread, NULL) != 0) {
      g_message("join failed. Killing base rate thread");
      pthread_kill(thread_infos[0].thread, SIGTERM);
    }

    g_message("terminating the Simulink model");
    MdlTerminate();

    /* clean up and exit */
    g_message("shutting down data logging");

#ifdef UseMMIDataLogging
    rt_CleanUpForStateLogWithMMI(rtmGetRTWLogInfo(GLOBAL.S));
    rt_CleanUpForSigLogWithMMI(rtmGetRTWLogInfo(GLOBAL.S));
#endif
    rt_StopDataLogging(MATFILE,rtmGetRTWLogInfo(GLOBAL.S));

    g_message("shutting down external mode");
    rtExtModeShutdown(rtmGetNumSampleTimes(GLOBAL.S));

    /* Stop Mono monitor.*/
    if (gt_rt_get_option_no_monitor()) {
      g_message("GT-RT monitor is not stopped since it is not running");
    } else {
      g_message("shutting down GT-RT monitor");
      gt_rt_monitor_stop(&err);
      if (err != NULL) {
        g_critical("Failed to stop GT-RT monitor: %s", err->message);
        g_error_free(err);
        err = NULL;
      }
    }
	
    /* Stop XCP server.*/
    g_message("stopping the XCP server");
    gt_rt_xcp_server_stop(&err);
    if (err != NULL) {
      g_critical("Failed to stop XCP server: %s", err->message);
      g_error_free(err);
      err = NULL;
    }
  
    if (GLOBAL.errmsg) {
      g_critical("Error occured: %s\n",GLOBAL.errmsg);
      exit(EXIT_FAILURE);
    }
  
    if (rtmGetErrorStatus(GLOBAL.S) != NULL) {
      g_critical("ErrorStatus set: %s", rtmGetErrorStatus(GLOBAL.S));
      exit(EXIT_FAILURE);
    }
  
    for (i=0; i<NUMST; ++i) {
      if (thread_infos[i].overrun_flag) {
        g_critical(
                   "%s thread overrun - sampling rate is too fast for "
                   "sample time index %d", QUOTE(MODEL), i);
        exit(EXIT_FAILURE);
      }
    }
    g_message("The End. Exiting ...");
    gt_rt_log_exit(G_LOG_DOMAIN, _log_handler_id, NULL);
    gt_rt_core_exit();	
	
    return(EXIT_SUCCESS);
  } /* end main */



  /* EOF: gt_rt_main.c */

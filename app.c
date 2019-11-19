/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                          (c) Copyright 2003-2013; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                            EXAMPLE CODE
*
*                                         uC/OS-III on POSIX
*
*
* Filename      : app.c
* Version       : V1.00
* Programmer(s) : DC
*                 SB
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/
#include  <app_cfg.h>
#include  <os.h>

#include  <stdio.h>
#include  <lib_mem.h>
#include  <lib_math.h>


/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/

static	OS_TCB			App_TaskStartTCB;
static	OS_TCB			App_TaskStartTCB1;
static	OS_TCB			App_TaskStartTCB2;
static	OS_TCB			App_TaskStartTCB3;
static	OS_TCB			App_TaskStartTCB_Controller;
static	CPU_STK_SIZE	App_TaskStartStk[APP_CFG_TASK_START_STK_SIZE];

static	CPU_INT32U		App_iterT1 = 0u;
static	CPU_INT32U		App_iterT2 = 0u;
static	CPU_INT32U		App_iterT3 = 0u;


/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  App_TaskStart					(void       *p_arg);
static  void  App_TaskStart1				(void       *p_arg);
static  void  App_TaskStart2				(void       *p_arg);
static  void  App_TaskStart3				(void       *p_arg);
static  void  App_TaskStart_Controller		(void       *p_arg);


/*
 *	tsInSec - figure out how much timestamp in one second
 */
static CPU_INT32U tsInSec() {
	OS_ERR		err;
	CPU_INT32U	tsStart = CPU_TS_Get32();
	CPU_INT32U	tsPerSec;
    OSTimeDlyHMSM(0u, 0u, 1u, 0u,
                  OS_OPT_TIME_HMSM_STRICT,
                  &err);
    tsPerSec = CPU_TS_Get32() - tsStart;
    printf("One second has %u timestamp\n", tsPerSec);
    return tsPerSec;
}


/*
 *	ts2sec - convert timestamp to second
 */
static CPU_FP32 ts2sec(CPU_INT32U ts) {
	return (CPU_FP32)ts/(CPU_FP32)tsInSec();
}


/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will call
*               main() once you have performed all necessary initialization.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : This the main standard entry point.
*
* Note(s)     : none.
*********************************************************************************************************
*/

int  main (void)
{
    OS_ERR  err;

    printf("\n\nmain: OSInit\n");
    OSInit(&err);                                               /* Initialize "uC/OS-III, The Real-Time Kernel"         */

#if 0
    OSTaskCreate((OS_TCB     *)&App_TaskStartTCB,               /* Create the start task                                */
                 (CPU_CHAR   *)"main: App Task Start",
                 (OS_TASK_PTR ) App_TaskStart,
                 (void       *) 0,
                 (OS_PRIO     ) APP_CFG_TASK_START_PRIO,
                 (CPU_STK    *)&App_TaskStartStk[0],
                 (CPU_STK     )(APP_CFG_TASK_START_STK_SIZE / 10u),
                 (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
                 (OS_MSG_QTY  ) 0,
                 (OS_TICK     ) 0,
                 (void       *) 0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);
#endif

    //Task 1
    OSTaskCreate((OS_TCB     *)&App_TaskStartTCB1,               /* Create the start task                                */
                 (CPU_CHAR   *)"main: App Task Start1",
                 (OS_TASK_PTR ) App_TaskStart1,
                 (void       *) 0,
                 (OS_PRIO     ) APP_CFG_TASK_START_PRIO,
                 (CPU_STK    *)&App_TaskStartStk[1],
                 (CPU_STK     )(APP_CFG_TASK_START_STK_SIZE / 10u),
                 (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
                 (OS_MSG_QTY  ) 0,
                 (OS_TICK     ) 0,
                 (void       *) 0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);

    //Task 2
    OSTaskCreate((OS_TCB     *)&App_TaskStartTCB2,               /* Create the start task                                */
                 (CPU_CHAR   *)"main: App Task Start2",
                 (OS_TASK_PTR ) App_TaskStart2,
                 (void       *) 0,
                 (OS_PRIO     ) APP_CFG_TASK_START_PRIO,
                 (CPU_STK    *)&App_TaskStartStk[2],
                 (CPU_STK     )(APP_CFG_TASK_START_STK_SIZE / 10u),
                 (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
                 (OS_MSG_QTY  ) 0,
                 (OS_TICK     ) 0,
                 (void       *) 0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);

    //Task 3
    OSTaskCreate((OS_TCB     *)&App_TaskStartTCB3,               /* Create the start task                                */
                 (CPU_CHAR   *)"main: App Task Start3",
                 (OS_TASK_PTR ) App_TaskStart3,
                 (void       *) 0,
                 (OS_PRIO     ) APP_CFG_TASK_START_PRIO,
                 (CPU_STK    *)&App_TaskStartStk[3],
                 (CPU_STK     )(APP_CFG_TASK_START_STK_SIZE / 10u),
                 (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
                 (OS_MSG_QTY  ) 0,
                 (OS_TICK     ) 0,
                 (void       *) 0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);

    //Task Controller
    OSTaskCreate((OS_TCB     *)&App_TaskStartTCB_Controller,               /* Create the start task                                */
                 (CPU_CHAR   *)"main: App Task Start_Controller",
                 (OS_TASK_PTR ) App_TaskStart_Controller,
                 (void       *) 0,
                 (OS_PRIO     ) APP_CFG_TASK_START_PRIO,
                 (CPU_STK    *)&App_TaskStartStk[4],
                 (CPU_STK     )(APP_CFG_TASK_START_STK_SIZE / 10u),
                 (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
                 (OS_MSG_QTY  ) 0,
                 (OS_TICK     ) 0,
                 (void       *) 0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);

    printf("\n\nmain: OSStart\n");
    OSStart(&err);                                              /* Start multitasking (i.e. give control to uC/OS-III). */

    printf("\n\nmain: should never see this!\n");
    while(DEF_ON){												/* Should Never Get Here							    */
    };
}


/*
*********************************************************************************************************
*                                          App_TaskStart()
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Argument(s) : p_arg   is the argument passed to 'App_TaskStart()' by 'OSTaskCreate()'.
*
* Return(s)   : none.
*
* Caller(s)   : This is a task.
*
* Notes       : (1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                   used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/
static  void  App_TaskStart (void *p_arg)
{
    OS_ERR      os_err;

    (void)p_arg;                                                /* See Note #1                                          */

    CPU_Init();
    Mem_Init();                                                 /* Initialize the Memory Management Module              */
    Math_Init();                                                /* Initialize the Mathematical Module                   */

    OS_CPU_SysTickInit();

    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.       */
    	printf("uCOS-III is running.\n");
        OSTimeDlyHMSM(0u, 0u, 1u, 0u,
                      OS_OPT_TIME_HMSM_STRICT,
                      &os_err);
    }
}


//Task 1: get timestamp
static  void  App_TaskStart1 (void *p_arg)
{
    OS_ERR      os_err;

    (void)p_arg;                                                /* See Note #1                                          */

    printf("App_TaskStart1\n");

    CPU_Init();
    Mem_Init();                                                 /* Initialize the Memory Management Module              */
    Math_Init();                                                /* Initialize the Mathematical Module                   */

    OS_CPU_SysTickInit();

    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.       */
    	printf("T1 is running: ##\n");
    	CPU_INT32U tsStart = CPU_TS_Get32();
    	printf("T1: timestamp = %u\n", tsStart);
    	CPU_INT32U tsEnd = CPU_TS_Get32();
    	printf("T1: Took %9.6f seconds\n", ts2sec(tsEnd-tsStart));
    	App_iterT1++;
    }
}


//Task 2: delay 100ms
static  void  App_TaskStart2 (void *p_arg)
{
    OS_ERR      os_err;

    (void)p_arg;                                                /* See Note #1                                          */

    printf("App_TaskStart2\n");

    CPU_Init();
    Mem_Init();                                                 /* Initialize the Memory Management Module              */
    Math_Init();                                                /* Initialize the Mathematical Module                   */

    OS_CPU_SysTickInit();

    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.       */
    	printf("T2 is running: ####\n");
    	CPU_INT32U tsStart = CPU_TS_Get32();
    	printf("T2: delay...\n");
        OSTimeDlyHMSM(0u, 0u, 0u, 100u,
                      OS_OPT_TIME_HMSM_STRICT,
                      &os_err);
        CPU_INT32U tsEnd = CPU_TS_Get32();
        printf("T2: Took %9.6f seconds\n", ts2sec(tsEnd-tsStart));
        App_iterT2++;
    }
}


//Task 3: noop
static  void  App_TaskStart3 (void *p_arg)
{
    OS_ERR      os_err;

    (void)p_arg;                                                /* See Note #1                                          */

    printf("App_TaskStart3\n");

    CPU_Init();
    Mem_Init();                                                 /* Initialize the Memory Management Module              */
    Math_Init();                                                /* Initialize the Mathematical Module                   */

    OS_CPU_SysTickInit();

    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.       */
    	printf("T3 is running: ######\n");
    	CPU_INT32U tsStart = CPU_TS_Get32();
    	printf("T3: noop\n");
    	CPU_INT32U tsEnd = CPU_TS_Get32();
    	printf("T3: Took %9.6f seconds\n", ts2sec(tsEnd-tsStart));
    	App_iterT3++;
    }
}


//Task Controller
static  void  App_TaskStart_Controller(void *p_arg)
{
    OS_ERR      os_err;

    (void)p_arg;                                                /* See Note #1                                          */

    printf("App_TaskStart_Controller\n");

    CPU_Init();
    Mem_Init();                                                 /* Initialize the Memory Management Module              */
    Math_Init();                                                /* Initialize the Mathematical Module                   */
    OS_CPU_SysTickInit();

    //CPU_INT32U tsStart = CPU_TS_Get32();
    //CPU_INT32U tsNow = 0u;
    //CPU_INT32U tsPERIOD = 60 * 60 * tsInSec();

    //delay for 2 minutes before suspending the 6 tasks
    OSTimeDlyHMSM(0u, 2u, 0u, 0u,
                  OS_OPT_TIME_HMSM_STRICT,
                  &os_err);
	printf("TC: suspending all tasks.\n");
    OSTaskSuspend((OS_TCB *)&App_TaskStartTCB1, (OS_ERR *)&os_err);
    OSTaskSuspend((OS_TCB *)&App_TaskStartTCB2, (OS_ERR *)&os_err);
    OSTaskSuspend((OS_TCB *)&App_TaskStartTCB3, (OS_ERR *)&os_err);

    printf("TC: deleting all tasks.\n");
    OSTaskDel((OS_TCB *)&App_TaskStartTCB1, (OS_ERR *)&os_err);
    OSTaskDel((OS_TCB *)&App_TaskStartTCB2, (OS_ERR *)&os_err);
    OSTaskDel((OS_TCB *)&App_TaskStartTCB3, (OS_ERR *)&os_err);

    //print summary
    printf("TC: Summary of all Tasks:\n");
    printf("Task 1 has executed %u times\n", App_iterT1);
    printf("Task 2 has executed %u times\n", App_iterT2);
    printf("Task 3 has executed %u times\n", App_iterT3);

    //self suspend
    OSTaskSuspend((OS_TCB *)&App_TaskStartTCB_Controller, (OS_ERR *)&os_err);
    printf("TC: self suspending.\n");

#if 0
    while (DEF_TRUE) { /* Task body, always written as an infinite loop.       */
    	tsNow = CPU_TS_Get32();
    	if (tsNow - tsStart > tsPERIOD) {

    	}
    	printf("TC: App_TaskStart_Controller is running.......  tsNow = %u\n", tsNow);
    }
#endif
}

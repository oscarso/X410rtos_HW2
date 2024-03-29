/*
*********************************************************************************************************
*                                               uC/CPU
*                                    CPU CONFIGURATION & PORT LAYER
*
*                          (c) Copyright 2004-2009; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*
*               uC/CPU is provided in source form for FREE evaluation, for educational
*               use or peaceful research.  If you plan on using uC/CPU in a commercial
*               product you need to contact Micrium to properly license its use in your
*               product.  We provide ALL the source code for your convenience and to
*               help you experience uC/CPU.  The fact that the source code is provided
*               does NOT mean that you can use it without paying a licensing fee.
*
*               Knowledge of the source code may NOT be used to develop a similar product.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                       CPU CONFIGURATION FILE
*
*                                              TEMPLATE
*
* Filename      : cpu_cfg.h
* Version       : V1.23
* Programmer(s) : SR
*                 ITJ
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                       CPU NAME CONFIGURATION
*
* Note(s) : (1) Configure CPU_CFG_NAME_EN to enable/disable CPU name feature :
*
*               (a) CPU name storage
*               (b) CPU name API functions
*
*           (2) Configure CPU_CFG_NAME_SIZE with the desired ASCII string size of the CPU name, NOT
*               including the terminating NULL character.
*
*               See also 'cpu_core.h  GLOBAL VARIABLES  Note #1'.
*********************************************************************************************************
*/

                                                                /* Configure CPU name feature (see Note #1) :           */
#define  CPU_CFG_NAME_EN                        DEF_DISABLED
                                                                /*   DEF_DISABLED  CPU name DISABLED                    */
                                                                /*   DEF_ENABLED   CPU name ENABLED                     */

#define  CPU_CFG_NAME_SIZE                                16    /* Configure CPU name ASCII string size (see Note #2).  */


/*$PAGE*/
/*
*********************************************************************************************************
*                                     CPU TIMESTAMP CONFIGURATION
*
* Note(s) : (1) Configure CPU_CFG_TS_EN to enable/disable CPU timestamp feature.
*********************************************************************************************************
*/
                                                                /* Configure CPU timestamp features (see Note #1) :     */
#define  CPU_CFG_TS_32_EN                       DEF_ENABLED
#define  CPU_CFG_TS_64_EN                       DEF_DISABLED
                                                                /*   DEF_DISABLED  CPU timestamps DISABLED              */
                                                                /*   DEF_ENABLED   CPU timestamps ENABLED               */

                                                                /* Configure CPU timestamp timer word size ...          */
                                                                /* ... (see Note #2) :                                  */
#define  CPU_CFG_TS_TMR_SIZE                    CPU_WORD_SIZE_32

/*
*********************************************************************************************************
*                        CPU INTERRUPTS DISABLED TIME MEASUREMENT CONFIGURATION
*
* Note(s) : (1) (a) Configure CPU_CFG_INT_DIS_MEAS_EN to enable/disable measuring CPU's interrupts 
*                   disabled time :
*
*                   (a)  Enabled,       if CPU_CFG_INT_DIS_MEAS_EN      #define'd in 'cpu_cfg.h'
*
*                   (b) Disabled,       if CPU_CFG_INT_DIS_MEAS_EN  NOT #define'd in 'cpu_cfg.h'
*
*                   See also 'cpu_core.h  FUNCTION PROTOTYPES  Note #1'
*                          & 'cpu_core.h  CPU INCLUDE FILES    Note #3'.
*
*               (b) !!!! Recommended configuration value = 1, even for instruction-cache-enabled CPUs.
*********************************************************************************************************
*/

#if 0                                                           /* Configure CPU interrupts disabled time ...           */
#define  CPU_CFG_INT_DIS_MEAS_EN                                /* ... measurements feature (see Note #1a).             */
#endif

                                                                /* Configure number of interrupts disabled overhead ... */
#define  CPU_CFG_INT_DIS_MEAS_OVRHD_NBR                    1    /* ... time measurements (see Note #1b).                */


/*
*********************************************************************************************************
*                                CPU COUNT LEADING ZEROS CONFIGURATION
*
* Note(s) : (1) Configure CPU_CFG_LEAD_ZEROS_ASM_PRESENT to prototype/define count leading zeros bits 
*               function(s) in :
*
*               (a) 'cpu.h'/'cpu_a.asm',       if CPU_CFG_LEAD_ZEROS_ASM_PRESENT      #define'd in 'cpu.h'/
*                                                 'cpu_cfg.h' to enable assembly-version function(s)
*
*               (b) 'cpu_core.h'/'cpu_core.c', if CPU_CFG_LEAD_ZEROS_ASM_PRESENT  NOT #define'd in 'cpu.h'/
*                                                 'cpu_cfg.h' to enable C-source-version function(s) otherwise
*
*               See also 'cpu_core.h  FUNCTION PROTOTYPES  Note #2'
*                      & 'cpu_core.h  CPU INCLUDE FILES    Note #3'.
*********************************************************************************************************
*/

#if 0                                                           /* Configure CPU count leading zeros bits ...           */
#define  CPU_CFG_LEAD_ZEROS_ASM_PRESENT                         /* ... assembly-version (see Note #1).                  */
#endif


/*
*********************************************************************************************************
*                                   CRITITAL SECTION CONFIGURATION
*
*********************************************************************************************************
*/

#define  CPU_CFG_CRITICAL_METHOD_WIN32          WIN32_CRITICAL_SECTION

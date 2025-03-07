/** @file HL_sys_startup.c 
*   @brief Startup Source File
*   @date 11-Dec-2018
*   @version 04.07.01
*
*   This file contains:
*   - Include Files
*   - Type Definitions
*   - External Functions
*   - VIM RAM Setup
*   - Startup Routine
*   .
*   which are relevant for the Startup.
*/

/* 
* Copyright (C) 2009-2018 Texas Instruments Incorporated - www.ti.com  
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */
/* USER CODE END */


/* Include Files */

#include "HL_sys_common.h"
#include "HL_system.h"
#include "HL_sys_vim.h"
#include "HL_sys_core.h"
#include "HL_esm.h"
#include "HL_sys_mpu.h"
#include "HL_errata_SSWF021_45.h"

/* USER CODE BEGIN (1) */
/* USER CODE END */

/* USER CODE BEGIN (2) */
/* USER CODE END */

/* External Functions */
extern void __cmain(void);


/* USER CODE BEGIN (3) */
/* USER CODE END */
void handlePLLLockFail(void);
/* Startup Routine */
void _c_int00(void);
#define PLL_RETRIES 5U
/* USER CODE BEGIN (4) */
/* USER CODE END */

/* Note: stackless keyword is supported since compiler version 6.20.1 */
__stackless
__arm

/* SourceId : STARTUP_SourceId_001 */
/* DesignId : STARTUP_DesignId_001 */
/* Requirements : HL_CONQ_STARTUP_SR1 */
void _c_int00(void)
{
	register resetSource_t rstSrc;
/* USER CODE BEGIN (5) */
/* USER CODE END */

    /* Initialize Core Registers to avoid CCM Error */
    _coreInitRegisters_();
	
    /* Initialize Stack Pointers */
    _coreInitStackPointer_();

    /* Reset handler: the following instructions read from the system exception status register
     * to identify the cause of the CPU reset.
     */
	rstSrc = getResetSource();
    switch(rstSrc)
    {
        case POWERON_RESET:
		/* Initialize L2RAM to avoid ECC errors right after power on */
		_memInit_();

		/* Add condition to check whether PLL can be started successfully */
        if (_errata_SSWF021_45_both_plls(PLL_RETRIES) != 0U)
		{
			/* Put system in a safe state */
			handlePLLLockFail();
		}
		
/*SAFETYMCUSW 62 S MR:15.2, 15.5 <APPROVED> "Need to continue to handle POWERON Reset" */
        case DEBUG_RESET:
        case EXT_RESET:

/* USER CODE BEGIN (6) */
/* USER CODE END */

        /* Initialize L2RAM to avoid ECC errors right after power on */
		if(rstSrc != POWERON_RESET)
		{
			_memInit_();
		}

/* USER CODE BEGIN (7) */
/* USER CODE END */

/* USER CODE BEGIN (8) */
/* USER CODE END */


/* USER CODE BEGIN (9) */
/* USER CODE END */

        /* Enable CPU Event Export */
        /* This allows the CPU to signal any single-bit or double-bit errors detected
         * by its ECC logic for accesses to program flash or data RAM.
         */
        _coreEnableEventBusExport_();

/* USER CODE BEGIN (10) */
/* USER CODE END */

        /* Check if there were ESM group3 errors during power-up.
         * These could occur during eFuse auto-load or during reads from flash OTP
         * during power-up. Device operation is not reliable and not recommended
         * in this case. */
        if ((esmREG->SR1[2]) != 0U)
        {
           esmGroup3Notification(esmREG,esmREG->SR1[2]);               
        }
	
        /* Initialize System - Clock, Flash settings with Efuse self check */
        systemInit();

/* USER CODE BEGIN (11) */
/* USER CODE END */

        /* Enable IRQ offset via Vic controller */
        _coreEnableIrqVicOffset_();
            
        /* Initialize VIM table */
	    vimInit();

/* USER CODE BEGIN (12) */
/* USER CODE END */
        /* Configure system response to error conditions signaled to the ESM group1 */
        /* This function can be configured from the ESM tab of HALCoGen */
        esmInit();

/* USER CODE BEGIN (13) */
/* USER CODE END */

        break;

        case OSC_FAILURE_RESET:
/* USER CODE BEGIN (14) */
/* USER CODE END */
        break;
		
        case WATCHDOG_RESET:
        case WATCHDOG2_RESET:
				
/* USER CODE BEGIN (15) */
/* USER CODE END */
        break;
    
        case CPU0_RESET:
/* USER CODE BEGIN (16) */
/* USER CODE END */

/* USER CODE BEGIN (17) */
/* USER CODE END */
		
/* USER CODE BEGIN (18) */
/* USER CODE END */

        /* Enable CPU Event Export */
        /* This allows the CPU to signal any single-bit or double-bit errors detected
         * by its ECC logic for accesses to program flash or data RAM.
         */
        _coreEnableEventBusExport_();
		
/* USER CODE BEGIN (19) */
/* USER CODE END */
        break;
    
        case SW_RESET:
		
/* USER CODE BEGIN (20) */
/* USER CODE END */
        break;
    
        default:
/* USER CODE BEGIN (21) */
/* USER CODE END */
        break;
    }

/* USER CODE BEGIN (22) */
/* USER CODE END */

    _mpuInit_();
	
/* USER CODE BEGIN (23) */
/* USER CODE END */

    _cacheEnable_();

/* USER CODE BEGIN (24) */
/* USER CODE END */

/* USER CODE BEGIN (26) */
/* USER CODE END */
    
        /* call the application */
    __cmain();

/* USER CODE BEGIN (28) */
/* USER CODE END */

}

/* USER CODE BEGIN (29) */
/* USER CODE END */

/** @fn void handlePLLLockFail(void)
*   @brief This function handles PLL lock fail.
*/
/* USER CODE BEGIN (30) */
/* USER CODE END */
void handlePLLLockFail(void)
{
/* USER CODE BEGIN (31) */
/* USER CODE END */
	while(1)
	{
		
	}
/* USER CODE BEGIN (32) */
/* USER CODE END */
}
/* USER CODE BEGIN (33) */
/* USER CODE END */

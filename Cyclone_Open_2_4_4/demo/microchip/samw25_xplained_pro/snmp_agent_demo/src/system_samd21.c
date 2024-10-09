/**
 * \file
 *
 * \brief Low-level initialization functions called upon chip startup.
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#include "samd21.h"

/**
 * Initial system clock frequency. The System RC Oscillator (RCSYS) provides
 *  the source for the main clock at chip startup.
 */
#define __SYSTEM_CLOCK    (48000000)

uint32_t SystemCoreClock = __SYSTEM_CLOCK;/*!< System Clock Frequency (Core Clock)*/

/**
 * Initialize the system
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
void SystemInit(void)
{
	// Change the timing of the NVM access
	NVMCTRL->CTRLB.bit.RWS = NVMCTRL_CTRLB_RWS_HALF_Val;

	// Enable the bus clock for the clock system
	PM->APBAMASK.bit.GCLK_ = 1;
	// Make a software reset of the clock system
	GCLK->CTRL.bit.SWRST = 1;

	// Wait for synchronization
	while(GCLK->CTRL.bit.SWRST && GCLK->STATUS.bit.SYNCBUSY);

	// Make sure the OCM8M keeps running
	SYSCTRL->OSC8M.bit.ONDEMAND = 0;
	// Set the division factor to 64, which reduces the 1MHz source to 15.625kHz
	GCLK->GENDIV.reg = GCLK_GENDIV_ID(3) | GCLK_GENDIV_DIV(64);

	// Create generic clock generator 3 for the 15KHz signal of the DFLL
	GCLK->GENCTRL.reg = GCLK_GENCTRL_ID(3) | GCLK_GENCTRL_SRC_OSC8M |
		GCLK_GENCTRL_GENEN;

	// Wait for synchronization
	while(GCLK->STATUS.bit.SYNCBUSY) {};

	// Configure DFLL
	GCLK->CLKCTRL.reg = GCLK_CLKCTRL_ID_DFLL48 | GCLK_CLKCTRL_GEN(3) |
		GCLK_CLKCTRL_CLKEN;

	// Wait for synchronization
	while(GCLK->STATUS.bit.SYNCBUSY);

	// Workaround to be able to configure the DFLL
	SYSCTRL->DFLLCTRL.bit.ONDEMAND = 0;

	// Wait for synchronization
	while(!SYSCTRL->PCLKSR.bit.DFLLRDY);

	// Change the multiplication factor
	SYSCTRL->DFLLMUL.bit.MUL = 3072;
	SYSCTRL->DFLLMUL.bit.CSTEP = 1;
	SYSCTRL->DFLLMUL.bit.FSTEP = 1;

	// Wait for synchronization
	while(!SYSCTRL->PCLKSR.bit.DFLLRDY);

	// Start closed-loop mode
	SYSCTRL->DFLLCTRL.reg |= SYSCTRL_DFLLCTRL_MODE | SYSCTRL_DFLLCTRL_QLDIS;

	// Wait for synchronization
	while(!SYSCTRL->PCLKSR.bit.DFLLRDY);

	// Clear the lock flags
	//SYSCTRL->INTFLAG.bit.DFLLLCKC = 1;
	//SYSCTRL->INTFLAG.bit.DFLLLCKF = 1;
	//SYSCTRL->INTFLAG.bit.DFLLRDY = 1;
	SYSCTRL->INTFLAG.reg = 0xFFFFFFFF;

	// Enable the DFLL
	SYSCTRL->DFLLCTRL.bit.ENABLE = 1;

	// Wait for synchronization
	while(!SYSCTRL->PCLKSR.bit.DFLLRDY);
	// Wait for the fine and coarse locks
	while(!SYSCTRL->INTFLAG.bit.DFLLLCKC && !SYSCTRL->INTFLAG.bit.DFLLLCKF);
	// Wait until the DFLL is ready
	while(!SYSCTRL->INTFLAG.bit.DFLLRDY);

	// Set the divisor of generic clock 0 to 0
	GCLK->GENDIV.reg = GCLK_GENDIV_ID(0) | GCLK_GENDIV_DIV(0);

	// Wait for synchronization
	while(GCLK->STATUS.bit.SYNCBUSY);

	// Switch generic clock 0 to the DFLL
	GCLK->GENCTRL.reg = GCLK_GENCTRL_ID(0) | GCLK_GENCTRL_SRC_DFLL48M |
		GCLK_GENCTRL_IDC | GCLK_GENCTRL_GENEN;

	// Wait for synchronization
	while(GCLK->STATUS.bit.SYNCBUSY);

	// Keep the default device state after reset
	SystemCoreClock = __SYSTEM_CLOCK;
	return;
}

/**
 * Update SystemCoreClock variable
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
void SystemCoreClockUpdate(void)
{
   // Not implemented
   SystemCoreClock = __SYSTEM_CLOCK;
   return;
}

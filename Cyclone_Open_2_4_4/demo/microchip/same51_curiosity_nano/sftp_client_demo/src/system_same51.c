/**
 * \file
 *
 * \brief System configuration file for SAME51
 *
 * Copyright (c) 2022 Microchip Technology Inc.
 *
 * \license_start
 *
 * \page License
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \license_stop
 *
 */

#include "sam.h"

/**
 * Initial system clock frequency.
 */
#define __SYSTEM_CLOCK    (120000000)

uint32_t SystemCoreClock = __SYSTEM_CLOCK;  /*!< System Clock Frequency (Core Clock)*/

/**
 * Initialize the system
 *
 * \brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
void SystemInit(void)
{
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    // Enable FPU
    SCB->CPACR |= (3UL << (10 * 2)) | (3UL << (11 * 2));
#endif

    // Enable XOSC32K clock
    OSC32KCTRL_REGS->OSC32KCTRL_XOSC32K = OSC32KCTRL_XOSC32K_CGM_XT |
        OSC32KCTRL_XOSC32K_EN32K_Msk | OSC32KCTRL_XOSC32K_XTALEN_Msk |
        OSC32KCTRL_XOSC32K_ENABLE_Msk;

    while((OSC32KCTRL_REGS->OSC32KCTRL_STATUS & OSC32KCTRL_STATUS_XOSC32KRDY_Msk) == 0)
    {
    }

    // Software reset
    GCLK_REGS->GCLK_CTRLA |= GCLK_CTRLA_SWRST_Msk;

    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_SWRST_Msk) != 0)
    {
    }

    // Connect OSCULP32K to clock generator 0
    GCLK_REGS->GCLK_GENCTRL[0] = GCLK_GENCTRL_GENEN_Msk | GCLK_GENCTRL_SRC_OSCULP32K;

    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_GENCTRL_GCLK0) != 0)
    {
    }

    // Connect XOSC32K to clock generator 3
    GCLK_REGS->GCLK_GENCTRL[3] = GCLK_GENCTRL_GENEN_Msk | GCLK_GENCTRL_SRC_XOSC32K;

    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_GENCTRL_GCLK3) != 0)
    {
    }

    // Configure DFLL48M
    OSCCTRL_REGS->OSCCTRL_DFLLCTRLA = 0;

    OSCCTRL_REGS->OSCCTRL_DFLLMUL = OSCCTRL_DFLLMUL_CSTEP(1) |
        OSCCTRL_DFLLMUL_FSTEP(1) | OSCCTRL_DFLLMUL_MUL(0);

    while((OSCCTRL_REGS->OSCCTRL_DFLLSYNC & OSCCTRL_DFLLSYNC_DFLLMUL_Msk) != 0)
    {
    }

    OSCCTRL_REGS->OSCCTRL_DFLLCTRLB = 0;

    while((OSCCTRL_REGS->OSCCTRL_DFLLSYNC & OSCCTRL_DFLLSYNC_DFLLCTRLB_Msk) != 0)
    {
    }

    OSCCTRL_REGS->OSCCTRL_DFLLCTRLA |= OSCCTRL_DFLLCTRLA_ENABLE_Msk;

    while((OSCCTRL_REGS->OSCCTRL_DFLLSYNC & OSCCTRL_DFLLSYNC_ENABLE_Msk) != 0)
    {
    }

    OSCCTRL_REGS->OSCCTRL_DFLLVAL = OSCCTRL_REGS->OSCCTRL_DFLLVAL;

    while((OSCCTRL_REGS->OSCCTRL_DFLLSYNC & OSCCTRL_DFLLSYNC_DFLLVAL_Msk) != 0)
    {
    }

    OSCCTRL_REGS->OSCCTRL_DFLLCTRLB = OSCCTRL_DFLLCTRLB_WAITLOCK_Msk |
        OSCCTRL_DFLLCTRLB_CCDIS_Msk | OSCCTRL_DFLLCTRLB_USBCRM_Msk;

    while((OSCCTRL_REGS->OSCCTRL_STATUS & OSCCTRL_STATUS_DFLLRDY_Msk) == 0)
    {
    }

    // Connect DFLL48M / 48 to clock generator 5 (1MHz)
    GCLK_REGS->GCLK_GENCTRL[5] = GCLK_GENCTRL_DIV(48) | GCLK_GENCTRL_GENEN_Msk |
        GCLK_GENCTRL_SRC_DFLL;

    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_GENCTRL_GCLK5) != 0)
    {
    }

    // Setup DPLL0 to 120MHz
    GCLK_REGS->GCLK_PCHCTRL[OSCCTRL_GCLK_ID_FDPLL0] = GCLK_PCHCTRL_CHEN_Msk |
        GCLK_PCHCTRL_GEN_GCLK5;

    OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLRATIO = OSCCTRL_DPLLRATIO_LDRFRAC(0) |
        OSCCTRL_DPLLRATIO_LDR(119);

    while((OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLSYNCBUSY & OSCCTRL_DPLLSYNCBUSY_DPLLRATIO_Msk) != 0)
    {
    }

    OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLCTRLB = OSCCTRL_DPLLCTRLB_LBYPASS_Msk |
        OSCCTRL_DPLLCTRLB_REFCLK_GCLK;

    OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLCTRLA = OSCCTRL_DPLLCTRLA_ENABLE_Msk;

    while((OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLSTATUS & OSCCTRL_DPLLSTATUS_CLKRDY_Msk) == 0 ||
       (OSCCTRL_REGS->DPLL[0].OSCCTRL_DPLLSTATUS & OSCCTRL_DPLLSTATUS_LOCK_Msk) == 0)
    {
    }

    // Connect DPLL0 to clock generator 0 (120MHz)
    GCLK_REGS->GCLK_GENCTRL[0] = GCLK_GENCTRL_DIV(1) | GCLK_GENCTRL_GENEN_Msk |
        GCLK_GENCTRL_SRC_DPLL0;

    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_GENCTRL_GCLK0) != 0)
    {
    }

    MCLK_REGS->MCLK_CPUDIV = MCLK_CPUDIV_DIV_DIV1;

    // Update system clock frequency
    SystemCoreClock = __SYSTEM_CLOCK;
    return;
}

/**
 * Update SystemCoreClock variable
 *
 * \brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
void SystemCoreClockUpdate(void)
{
    // Not implemented
    SystemCoreClock = __SYSTEM_CLOCK;
    return;
}

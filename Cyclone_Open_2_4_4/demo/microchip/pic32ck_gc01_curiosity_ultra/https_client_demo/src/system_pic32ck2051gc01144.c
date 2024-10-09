/**
 * \file
 *
 * \brief System configuration file for PIC32CK2051GC01144
 *
 * Copyright (c) 2023 Microchip Technology Inc.
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

#include "pic32ck2051gc01144.h"

/** \cond 0 */
/* *INDENT-OFF* */
#ifdef __cplusplus
extern "C" {
#endif
/* *INDENT-ON* */
/** \endcond */

/**
 * Initial system clock frequency. The System RC Oscillator (RCSYS) provides
 *  the source for the main clock at chip startup.
 */
#define __SYSTEM_CLOCK    (120000000)

uint32_t SystemCoreClock = __SYSTEM_CLOCK;  /*!< System Clock Frequency (Core Clock)*/

static void OSC32KCTRL_Initialize(void)
{

    OSC32KCTRL_REGS->OSC32KCTRL_CLKSELCTRL = OSC32KCTRL_CLKSELCTRL_RTCSEL(1U) | OSC32KCTRL_CLKSELCTRL_HSMSEL(0U);
}

static void PLL0_Initialize(void)
{
    /* Enable Additional Voltage Regulator */
    SUPC_REGS->SUPC_VREGCTRL |= SUPC_VREGCTRL_AVREGEN_Msk;
    while ((SUPC_REGS->SUPC_STATUS & SUPC_STATUS_ADDVREGRDY_Msk) != SUPC_STATUS_ADDVREGRDY_Msk)
    {
        /* Do Nothing */
    }

    /****************** PLL0 Initialization  *********************************/

    /* Configure PLL0 */
    OSCCTRL_REGS->OSCCTRL_PLL0REFDIV = OSCCTRL_PLL0REFDIV_REFDIV(12U);
    OSCCTRL_REGS->OSCCTRL_PLL0FBDIV = OSCCTRL_PLL0FBDIV_FBDIV(240U);

    OSCCTRL_REGS->OSCCTRL_FRACDIV0 = OSCCTRL_FRACDIV0_REMDIV(0U) | OSCCTRL_FRACDIV0_INTDIV(0U);
    while((OSCCTRL_REGS->OSCCTRL_SYNCBUSY & OSCCTRL_SYNCBUSY_FRACDIV0_Msk) == OSCCTRL_SYNCBUSY_FRACDIV0_Msk)
    {
        /* Waiting for the synchronization */
    }

    OSCCTRL_REGS->OSCCTRL_PLL0POSTDIVA = OSCCTRL_PLL0POSTDIVA_OUTEN0_Msk | OSCCTRL_PLL0POSTDIVA_POSTDIV0(8U);


    OSCCTRL_REGS->OSCCTRL_PLL0CTRL |= OSCCTRL_PLL0CTRL_BWSEL(0x1U) | OSCCTRL_PLL0CTRL_REFSEL(2U) | OSCCTRL_PLL0CTRL_ENABLE_Msk;

    while((OSCCTRL_REGS->OSCCTRL_STATUS & OSCCTRL_STATUS_PLL0LOCK_Msk) != OSCCTRL_STATUS_PLL0LOCK_Msk)
    {
        /* Waiting for the Ready state */
    }
}

static void GCLK0_Initialize(void)
{

    GCLK_REGS->GCLK_GENCTRL[0] = GCLK_GENCTRL_DIV(1U) | GCLK_GENCTRL_SRC(6U) | GCLK_GENCTRL_GENEN_Msk;

    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_GENCTRL0_Msk) == GCLK_SYNCBUSY_GENCTRL0_Msk)
    {
        /* Wait for the Generator 0 synchronization */
    }
}

static void GCLK1_Initialize(void)
{
    GCLK_REGS->GCLK_GENCTRL[1] = GCLK_GENCTRL_DIV(2U) | GCLK_GENCTRL_SRC(6U) | GCLK_GENCTRL_GENEN_Msk;

    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_GENCTRL1_Msk) == GCLK_SYNCBUSY_GENCTRL1_Msk)
    {
        /* Wait for the Generator 1 synchronization */
    }
}

void CLOCK_Initialize (void)
{
    /* Function to Initialize the 32KHz Oscillators */
    OSC32KCTRL_Initialize();

    PLL0_Initialize();
    GCLK0_Initialize();
    GCLK1_Initialize();
}

void PM_Initialize( void )
{
    /* Standby Configuration */
    PM_REGS->PM_STDBYCFG = PM_STDBYCFG_RAMCFG(0U)| PM_STDBYCFG_LPRAM_Msk;
    /* Hibernate Configuration */
    PM_REGS->PM_HIBCFG = PM_HIBCFG_RAMCFG(0U)| PM_HIBCFG_LPRAM_Msk;
}

/**
 * Initialize the system
 *
 * \brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
void SystemInit(void)
{
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
   SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2));  /* set CP10 and CP11 Full Access */
#endif

    /* Clock initialization */
    CLOCK_Initialize();
    /* Power Manager initialization */
    PM_Initialize();

    // Keep the default device state after reset
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

/** \cond 0 */
/* *INDENT-OFF* */
#ifdef __cplusplus
}
#endif
/* *INDENT-ON* */
/** \endcond */

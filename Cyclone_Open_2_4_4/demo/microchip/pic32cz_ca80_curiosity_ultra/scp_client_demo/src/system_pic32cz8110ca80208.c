/**
 * \file
 *
 * \brief System configuration file for PIC32CZ8110CA80208
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

#include "pic32cz8110ca80208.h"

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
#define __SYSTEM_CLOCK    (300000000)

uint32_t SystemCoreClock = __SYSTEM_CLOCK;  /*!< System Clock Frequency (Core Clock)*/

static void OSCCTRL_Initialize(void)
{
    /****************** XOSC Initialization ********************************/

    /* Configure External Oscillator */
    OSCCTRL_REGS->OSCCTRL_XOSCCTRLA = OSCCTRL_XOSCCTRLA_STARTUP(14U) | OSCCTRL_XOSCCTRLA_ENABLE_Msk;
    while((OSCCTRL_REGS->OSCCTRL_STATUS & OSCCTRL_STATUS_XOSCRDY_Msk) != OSCCTRL_STATUS_XOSCRDY_Msk)
    {
        /* Waiting for the XOSC Ready state */
    }
}

static void OSC32KCTRL_Initialize(void)
{
    /****************** XOSC32K initialization  ******************************/

    /* Configure 32K External Oscillator */
    OSC32KCTRL_REGS->OSC32KCTRL_XOSC32K = OSC32KCTRL_XOSC32K_STARTUP(0x7U) | OSC32KCTRL_XOSC32K_ENABLE_Msk | OSC32KCTRL_XOSC32K_CGM(0x0U) | OSC32KCTRL_XOSC32K_XTALEN_Msk;

    while(!((OSC32KCTRL_REGS->OSC32KCTRL_STATUS & OSC32KCTRL_STATUS_XOSC32KRDY_Msk) == OSC32KCTRL_STATUS_XOSC32KRDY_Msk))
    {
        /* Waiting for the XOSC32K Ready state */
    }

    OSC32KCTRL_REGS->OSC32KCTRL_CLKSELCTRL = OSC32KCTRL_CLKSELCTRL_RTCSEL(2U);
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
    OSCCTRL_REGS->OSCCTRL_PLL0REFDIV = OSCCTRL_PLL0REFDIV_REFDIV(3U);
    OSCCTRL_REGS->OSCCTRL_PLL0FBDIV = OSCCTRL_PLL0FBDIV_FBDIV(225U);

    OSCCTRL_REGS->OSCCTRL_FRACDIV0 = OSCCTRL_FRACDIV0_REMDIV(0U) | OSCCTRL_FRACDIV0_INTDIV(0U);
    while((OSCCTRL_REGS->OSCCTRL_SYNCBUSY & OSCCTRL_SYNCBUSY_FRACDIV0_Msk) == OSCCTRL_SYNCBUSY_FRACDIV0_Msk)
    {
        /* Waiting for the synchronization */
    }

    OSCCTRL_REGS->OSCCTRL_PLL0POSTDIVA = OSCCTRL_PLL0POSTDIVA_OUTEN0_Msk | OSCCTRL_PLL0POSTDIVA_POSTDIV0(3U);

    OSCCTRL_REGS->OSCCTRL_PLL0CTRL |= OSCCTRL_PLL0CTRL_BWSEL(0x1U) | OSCCTRL_PLL0CTRL_REFSEL(1U) | OSCCTRL_PLL0CTRL_ENABLE_Msk;

    while((OSCCTRL_REGS->OSCCTRL_STATUS & OSCCTRL_STATUS_PLL0LOCK_Msk) != OSCCTRL_STATUS_PLL0LOCK_Msk)
    {
        /* Waiting for the Ready state */
    }
}

static void PLL1_Initialize(void)
{
    /* Enable Additional Voltage Regulator */
    SUPC_REGS->SUPC_VREGCTRL |= SUPC_VREGCTRL_AVREGEN_Msk;
    while ((SUPC_REGS->SUPC_STATUS & SUPC_STATUS_ADDVREGRDY_Msk) != SUPC_STATUS_ADDVREGRDY_Msk)
	{
		/* Do Nothing */
	}


    /****************** PLL1 Initialization  *********************************/

    /* Configure PLL1 */
    OSCCTRL_REGS->OSCCTRL_PLL1REFDIV = OSCCTRL_PLL1REFDIV_REFDIV(3U);
    OSCCTRL_REGS->OSCCTRL_PLL1FBDIV = OSCCTRL_PLL1FBDIV_FBDIV(250U);

    OSCCTRL_REGS->OSCCTRL_FRACDIV1 = OSCCTRL_FRACDIV1_REMDIV(0U) | OSCCTRL_FRACDIV1_INTDIV(0U);
    while((OSCCTRL_REGS->OSCCTRL_SYNCBUSY & OSCCTRL_SYNCBUSY_FRACDIV1_Msk) == OSCCTRL_SYNCBUSY_FRACDIV1_Msk)
    {
        /* Waiting for the synchronization */
    }

    OSCCTRL_REGS->OSCCTRL_PLL1POSTDIVA = OSCCTRL_PLL1POSTDIVA_OUTEN0_Msk | OSCCTRL_PLL1POSTDIVA_POSTDIV0(8U);

    OSCCTRL_REGS->OSCCTRL_PLL1CTRL |= OSCCTRL_PLL1CTRL_BWSEL(0x1U) | OSCCTRL_PLL1CTRL_REFSEL(1U) | OSCCTRL_PLL1CTRL_ENABLE_Msk;

    while((OSCCTRL_REGS->OSCCTRL_STATUS & OSCCTRL_STATUS_PLL1LOCK_Msk) != OSCCTRL_STATUS_PLL1LOCK_Msk)
    {
        /* Waiting for the Ready state */
    }
}

static void DFLL_Initialize(void)
{
}


static void GCLK0_Initialize(void)
{

    /* Selection of the Clock Domain Division Factor */
    MCLK_REGS->MCLK_CLKDIV[1] = MCLK_CLKDIV_DIV(0x02U);

    while((MCLK_REGS->MCLK_INTFLAG & MCLK_INTFLAG_CKRDY_Msk) != MCLK_INTFLAG_CKRDY_Msk)
    {
        /* Wait for the Main Clock to be Ready */
    }
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

static void GCLK2_Initialize(void)
{
    GCLK_REGS->GCLK_GENCTRL[2] = GCLK_GENCTRL_DIV(1U) | GCLK_GENCTRL_SRC(10U) | GCLK_GENCTRL_GENEN_Msk;

    while((GCLK_REGS->GCLK_SYNCBUSY & GCLK_SYNCBUSY_GENCTRL2_Msk) == GCLK_SYNCBUSY_GENCTRL2_Msk)
    {
        /* Wait for the Generator 2 synchronization */
    }
}

void CLOCK_Initialize (void)
{
    /* Function to Initialize the Oscillators */
    OSCCTRL_Initialize();

    /* Function to Initialize the 32KHz Oscillators */
    OSC32KCTRL_Initialize();

    PLL1_Initialize();
    PLL0_Initialize();
    DFLL_Initialize();
    GCLK0_Initialize();
    GCLK1_Initialize();
    GCLK2_Initialize();

    /* Selection of the Generator and write Lock for SERCOM1_CORE */
    GCLK_REGS->GCLK_PCHCTRL[22] = GCLK_PCHCTRL_GEN(0x1)  | GCLK_PCHCTRL_CHEN_Msk;

    while((GCLK_REGS->GCLK_PCHCTRL[22] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for ETH_TX */
    GCLK_REGS->GCLK_PCHCTRL[54] = GCLK_PCHCTRL_GEN(0x2)  | GCLK_PCHCTRL_CHEN_Msk;

    while((GCLK_REGS->GCLK_PCHCTRL[54] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }
    /* Selection of the Generator and write Lock for ETH_TSU */
    GCLK_REGS->GCLK_PCHCTRL[55] = GCLK_PCHCTRL_GEN(0x2)  | GCLK_PCHCTRL_CHEN_Msk;

    while((GCLK_REGS->GCLK_PCHCTRL[55] & GCLK_PCHCTRL_CHEN_Msk) != GCLK_PCHCTRL_CHEN_Msk)
    {
        /* Wait for synchronization */
    }

    /* Disable DFLL */
    OSCCTRL_REGS->OSCCTRL_DFLLCTRLA &= ~(OSCCTRL_DFLLCTRLA_ENABLE_Msk);
    while((OSCCTRL_REGS->OSCCTRL_SYNCBUSY & OSCCTRL_SYNCBUSY_DFLLENABLE_Msk) == OSCCTRL_SYNCBUSY_DFLLENABLE_Msk)
    {
        /* Waiting for the DFLL48M enable synchronization */
    }
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

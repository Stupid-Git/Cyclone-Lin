/**
 * \file
 *
 * \brief System configuration file for PIC32CX2051MTG128
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

#include "pic32cx2051mtg128.h"

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
#define __SYSTEM_CLOCK    (196608000)

uint32_t SystemCoreClock = __SYSTEM_CLOCK;  /*!< System Clock Frequency (Core Clock)*/

#define NUM_RESET_MD_CLOCK_CYCLES 2U
#define RESET_WAIT_COUNT  ((__SYSTEM_CLOCK / 32000U) * NUM_RESET_MD_CLOCK_CYCLES)

#define PLLA_RECOMMENDED_ACR    0x0F020038U
#define PLLB_RECOMMENDED_ACR    0x28020038U
#define PLLC_RECOMMENDED_ACR    0x28020038U

#define PLLA_UPDT_STUPTIM_VAL   0x02U
#define PLLB_UPDT_STUPTIM_VAL   0x00U
#define PLLC_UPDT_STUPTIM_VAL   0x00U

typedef enum
{
    PLLA = 0U,
    PLLB,
    PLLC
}pll_id_t;

typedef struct pmc_pll_cfg_tag {
    uint32_t ctrl0;
    uint32_t ctrl1;
    uint32_t ctrl2;
    uint32_t ssr;
    uint32_t acr;
    uint32_t stuptim;
}pmc_pll_cfg_t;

static const pmc_pll_cfg_t plla_cfg = {
    (PMC_PLL_CTRL0_ENLOCK_Msk | PMC_PLL_CTRL0_ENPLL_Msk |
    PMC_PLL_CTRL0_PLLMS(0U) | PMC_PLL_CTRL0_ENPLLO1_Msk |
    PMC_PLL_CTRL0_DIVPMC1(1U)| PMC_PLL_CTRL0_ENPLLO0_Msk |
    PMC_PLL_CTRL0_DIVPMC0(19U)),
    PMC_PLL_CTRL1_MUL(12206U),
    PMC_PLL_CTRL2_FRACR(131072U),
    0U,
    PLLA_RECOMMENDED_ACR,
    PLLA_UPDT_STUPTIM_VAL
};

static const pmc_pll_cfg_t pllb_cfg = {
    (PMC_PLL_CTRL0_ENLOCK_Msk | PMC_PLL_CTRL0_ENPLL_Msk |
    PMC_PLL_CTRL0_PLLMS(0U) | PMC_PLL_CTRL0_ENPLLO0_Msk |
    PMC_PLL_CTRL0_DIVPMC0(1U)),
    PMC_PLL_CTRL1_MUL(23U),
    PMC_PLL_CTRL2_FRACR(0U),
    0U,
    PLLB_RECOMMENDED_ACR,
    PLLB_UPDT_STUPTIM_VAL
};

static void SlowClockInitialize(void)
{
    /* 32KHz Crystal Oscillator is selected as the Slow Clock (SLCK) source.
       Enable 32KHz Crystal Oscillator  */
    SUPC_REGS->SUPC_CR |= SUPC_CR_KEY_PASSWD | SUPC_CR_TDXTALSEL_XTAL;

    /* Wait until Slow Clock (SLCK) is switched from RC */
    while ((SUPC_REGS->SUPC_SR & SUPC_SR_TDOSCSEL_XTAL) == 0U)
    {
        /* Wait for status to set */
    }
}

static void DisableMainRCOscillator(void)
{
    /* Disable the RC Oscillator */
    PMC_REGS->CKGR_MOR = CKGR_MOR_KEY_PASSWD | (PMC_REGS->CKGR_MOR & ~CKGR_MOR_MOSCRCEN_Msk);
}

static void PLLInitialize(uint32_t pll_id, const pmc_pll_cfg_t *pll_cfg)
{
    /* STEP 1: Define the ID and startup time by configuring the fields
    PMC_PLL_UPDT.ID and PMC_PLL_UPDT.STUPTIM. Set PMC_PLL_UPDT.UPDATE to 0 */
    uint32_t reg = PMC_REGS->PMC_PLL_UPDT & ~(PMC_PLL_UPDT_Msk);
    reg |= (PMC_PLL_UPDT_ID(pll_id)  | PMC_PLL_UPDT_STUPTIM(pll_cfg->stuptim));
    PMC_REGS->PMC_PLL_UPDT = reg;

    /* STEP 2: Configure PMC_PLL_ACR.LOOP_FILTER */
    PMC_REGS->PMC_PLL_ACR = pll_cfg->acr;

    /* STEP 3: Define the MUL and FRACR to be applied to PLL(n) in PMC_PLL_CTRL1 */
    PMC_REGS->PMC_PLL_CTRL1 = pll_cfg->ctrl1;
    PMC_REGS->PMC_PLL_CTRL2 = pll_cfg->ctrl2;

    /* STEP 4: Set PMC_PLL_UPDT.UPDATE to 1 */
    PMC_REGS->PMC_PLL_UPDT |= PMC_PLL_UPDT_UPDATE_Msk;

    /* STEP 5: In PMC_PLL_CTRL0, Enable PLL and configure outputs and dividers*/
    reg = PMC_REGS->PMC_PLL_CTRL0 & ~(PMC_PLL_CTRL0_Msk);
    reg |= pll_cfg->ctrl0;
    PMC_REGS->PMC_PLL_CTRL0 = reg;

    /* STEP 6: Set PMC_PLL_UPDT.UPDATE to 1 */
    PMC_REGS->PMC_PLL_UPDT |= PMC_PLL_UPDT_UPDATE_Msk;

    /* STEP 7: Wait for PLL initialization */
    while ((PMC_REGS->PMC_PLL_ISR0 & (1UL << (uint32_t)pll_id)) == 0U)
    {
        /* Wait for PLL lock to rise */
    }

    /* STEP 8: Setup spread spectrum, if enabled */
    if(pll_cfg->ssr != 0U)
    {
        reg = PMC_REGS->PMC_PLL_SSR & ~(PMC_PLL_SSR_Msk);
        reg |= pll_cfg->ssr;
        PMC_REGS->PMC_PLL_SSR = reg;
    }
}

static void CPUClockInitialize(void)
{
    /* Program PMC_CPU_CKR.PRES and wait for PMC_SR.MCKRDY to be set   */
    uint32_t reg = (PMC_REGS->PMC_CPU_CKR & ~PMC_CPU_CKR_PRES_Msk);
    PMC_REGS->PMC_CPU_CKR = (reg | PMC_CPU_CKR_PRES_CLK_1);
    while ((PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) != PMC_SR_MCKRDY_Msk)
    {
        /* Wait for status MCKRDY */
    }

    /* Program PMC_CPU_CKR.CSS and MCK dividers and Wait for PMC_SR.MCKRDY to be set    */
    reg = (PMC_REGS->PMC_CPU_CKR & ~(PMC_CPU_CKR_CSS_Msk |
                                     PMC_CPU_CKR_RATIO_MCK0DIV_Msk |
                                     PMC_CPU_CKR_RATIO_MCK0DIV2_Msk));
    reg |= (PMC_CPU_CKR_CSS_PLLACK1 | PMC_CPU_CKR_RATIO_MCK0DIV_Msk );
    PMC_REGS->PMC_CPU_CKR = reg;
    while ((PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) != PMC_SR_MCKRDY_Msk)
    {
        /* Wait for status MCKRDY */
    }

    /* Set coprocessor clock dummy prescaler */
    reg = (PMC_REGS->PMC_CPU_CKR & ~(PMC_CPU_CKR_CPPRES_Msk | PMC_CPU_CKR_RATIO_MCK1DIV_Msk));
    reg |= (PMC_CPU_CKR_CPPRES_CLK_2 | PMC_CPU_CKR_RATIO_MCK1DIV_Msk);
    PMC_REGS->PMC_CPU_CKR = reg;

    /* Program PMC_CPU_CKR.CPCSS and Wait for PMC_SR.CPMCKRDY to be set    */
    reg = (PMC_REGS->PMC_CPU_CKR & ~PMC_CPU_CKR_CPCSS_Msk);
    PMC_REGS->PMC_CPU_CKR = (reg | PMC_CPU_CKR_CPCSS_PLLBCK);
    while ((PMC_REGS->PMC_SR & PMC_SR_CPMCKRDY_Msk) != PMC_SR_CPMCKRDY_Msk)
    {
        /* Wait for status CPMCKRDY */
    }

    /* Program PMC_CPU_CKR.CPPRES and wait for PMC_SR.CPMCKRDY to be set   */
    reg = (PMC_REGS->PMC_CPU_CKR & ~(PMC_CPU_CKR_CPPRES_Msk | PMC_CPU_CKR_RATIO_MCK1DIV_Msk));
    reg |= (PMC_CPU_CKR_CPPRES_CLK_1 | PMC_CPU_CKR_RATIO_MCK1DIV_Msk);
    PMC_REGS->PMC_CPU_CKR = reg;
    while ((PMC_REGS->PMC_SR & PMC_SR_CPMCKRDY_Msk) != PMC_SR_CPMCKRDY_Msk)
    {
        /* Wait for status CPMCKRDY */
    }

    /* Enable co-processor bus clock  */
    PMC_REGS->PMC_SCER = (PMC_SCER_CPKEY_PASSWD | PMC_SCER_CPBMCK_Msk);
}

static void ApplyFlashPatch(void)
{
    SFR_REGS->SFR_WPMR = SFR_WPMR_WPKEY_PASSWD;
    /*Enable Flash high speed patch */
    SFR_REGS->SFR_FLASH = 0x0U;
    SFR_REGS->SFR_WPMR = (SFR_WPMR_WPKEY_PASSWD | SFR_WPMR_WPEN_Msk);
}

void CLK_Initialize( void )
{
   /* Initialize TD slow clock */
   SlowClockInitialize();

   /* Initialize PLLA */
   PLLInitialize((uint32_t)PLLA, &plla_cfg);

   /* Initialize PLLB */
   PLLInitialize((uint32_t)PLLB, &pllb_cfg);

   /* Apply flash patch */
   ApplyFlashPatch();

   /* Initialize CPU clock */
   CPUClockInitialize();

   /* Disable Main RC Oscillator */
   DisableMainRCOscillator();
}


/**
 * Initialize the system
 *
 * \brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
void SystemInit(void)
{
   volatile uint32_t i;

#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
   SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
#endif

    /* Disable watchdog timers */
    DWDT_REGS->DWDT_WDT0_MR = DWDT_WDT0_MR_WDDIS_Msk;
    DWDT_REGS->DWDT_WDT1_MR = DWDT_WDT1_MR_WDDIS_Msk;

    /* Set Flash wait states */
    SEFC0_REGS->SEFC_EEFC_FMR = SEFC_EEFC_FMR_FWS(7U) | SEFC_EEFC_FMR_CLOE_Msk |
        SEFC_EEFC_FMR_ALWAYS1_Msk;

    SEFC1_REGS->SEFC_EEFC_FMR = SEFC_EEFC_FMR_FWS(7U) | SEFC_EEFC_FMR_CLOE_Msk |
        SEFC_EEFC_FMR_ALWAYS1_Msk;

    /* Clock initialization */
    CLK_Initialize();
   
    /* RSTC initialization */
    RSTC_REGS->RSTC_MR = RSTC_MR_KEY_PASSWD | RSTC_MR_ERSTL(0U) |
        RSTC_MR_PWRSW(0x0U) | RSTC_MR_CPEREN_Msk | RSTC_MR_URSTASYNC_Msk |
        RSTC_MR_SFTPMCRS_Msk | RSTC_MR_WDTPMC0_Msk | RSTC_MR_WDTPMC1_Msk |
        RSTC_MR_URSTEN_Msk;

    /* Wait for 2 MD_SLCK cycles after deasserting reset */
    for(i = 0U; i < RESET_WAIT_COUNT; i++)
    {
       __NOP();
    }
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

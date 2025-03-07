/**************************************************************************//**
 * @file     system_M480.c
 * @version  V1.000
 * @brief    CMSIS Cortex-M4 Core Peripheral Access Layer Source File for M480
 *
 * @copyright (C) 2016 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#include "M480.h"


/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock  = __SYSTEM_CLOCK;    /*!< System Clock Frequency (Core Clock)*/
uint32_t CyclesPerUs      = (__HSI / 1000000UL); /* Cycles per micro second */
uint32_t PllClock         = __HSI;             /*!< PLL Output Clock Frequency         */
uint32_t gau32ClkSrcTbl[] = {__HXT, __LXT, 0UL, __LIRC, 0UL, 0UL, 0UL, __HIRC};

/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{
    uint32_t u32Freq, u32ClkSrc;
    uint32_t u32HclkDiv;

    /* Update PLL Clock */
    PllClock = CLK_GetPLLClockFreq();

    u32ClkSrc = CLK->CLKSEL0 & CLK_CLKSEL0_HCLKSEL_Msk;

    if(u32ClkSrc == CLK_CLKSEL0_HCLKSEL_PLL) {
        /* Use PLL clock */
        u32Freq = PllClock;
    } else {
        /* Use the clock sources directly */
        u32Freq = gau32ClkSrcTbl[u32ClkSrc];
    }

    u32HclkDiv = (CLK->CLKDIV0 & CLK_CLKDIV0_HCLKDIV_Msk) + 1UL;

    /* Update System Core Clock */
    SystemCoreClock = u32Freq / u32HclkDiv;


    //if(SystemCoreClock == 0)
    //    __BKPT(0);

    CyclesPerUs = (SystemCoreClock + 500000UL) / 1000000UL;
}

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the micro controller system.
 *         Initialize the System.
 */
void SystemInit (void)
{
    /* ToDo: add code to initialize the system
             do not use global variables because this function is called before
             reaching pre-main. RW section maybe overwritten afterwards.          */


    /* FPU settings ------------------------------------------------------------*/
#if (__FPU_PRESENT == 1U) && (__FPU_USED == 1U)
    SCB->CPACR |= ((3UL << 10*2) |                 /* set CP10 Full Access */
                   (3UL << 11*2)  );               /* set CP11 Full Access */
#endif

    /* Disable Flash Access Cycle Auto-tuning, set access cycle for CPU @ 192MHz */
    FMC->CYCCTL = FMC_CYCCTL_FADIS_Msk | (8 << FMC_CYCCTL_CYCLE_Pos);

    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Set XT1_OUT(PF.2) and XT1_IN(PF.3) to input mode */
    PF->MODE &= ~(GPIO_MODE_MODE2_Msk | GPIO_MODE_MODE3_Msk);

    /* Enable External XTAL (4~24 MHz) */
    CLK_EnableXtalRC(CLK_PWRCTL_HXTEN_Msk);

    /* Waiting for 12MHz clock ready */
    CLK_WaitClockReady(CLK_STATUS_HXTSTB_Msk);

    /* Set core clock as PLL_CLOCK from PLL */
    CLK_SetCoreClock(FREQ_192MHZ);

    /* Set both PCLK0 and PCLK1 as HCLK/2 */
    CLK->PCLKDIV = CLK_PCLKDIV_PCLK0DIV2 | CLK_PCLKDIV_PCLK1DIV2;

    /* Lock protected registers */
    /* SYS_LockReg(); */
}

/*** (C) COPYRIGHT 2016 Nuvoton Technology Corp. ***/

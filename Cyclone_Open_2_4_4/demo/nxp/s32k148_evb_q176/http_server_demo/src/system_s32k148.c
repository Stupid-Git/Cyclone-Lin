/*
** ###################################################################
**     Processor:           S32K148
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright (c) 2015 Freescale Semiconductor, Inc.
**     Copyright 2016-2017 NXP
**     All rights reserved.
**
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
**
** ###################################################################
*/

/*!
 * @file S32K148
 * @brief Device specific configuration file for S32K148 (implementation file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency.
 */

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block
 * scope if its identifier only appears in a single function.
 * An object with static storage duration declared at block scope cannot be
 * accessed directly from outside the block.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 11.4, A conversion should not be performed
 * between a pointer to object and an integer type.
 * The cast is required to initialize a pointer with an unsigned int define,
 * representing an address.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 11.6, A cast shall not be performed
 * between pointer to void and an arithmetic type.
 * The cast is required to initialize a pointer with an unsigned int define,
 * representing an address.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External could be made static.
 * Function is defined for usage by application code.
 *
 */

#include "S32K148.h"
#include "S32K148_features.h"
#include "system_S32K148.h"
#include "stdbool.h"

/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/*FUNCTION**********************************************************************
 *
 * Function Name : SystemInit
 * Description   : Typically this function configures the oscillator that is part
 * of the microcontroller device. For systems with variable clock speed it also
 * updates the variable SystemCoreClock. SystemInit is called from startup_device file.
 *
 * Implements    : SystemInit_Activity
 *END**************************************************************************/
void SystemInit(void)
{
/**************************************************************************/
                      /* FPU ENABLE*/
/**************************************************************************/
#ifdef ENABLE_FPU
  /* Enable CP10 and CP11 coprocessors */
  S32_SCB->CPACR |= (S32_SCB_CPACR_CP10_MASK | S32_SCB_CPACR_CP11_MASK);
#ifdef  ERRATA_E6940
  /* Disable lazy context save of floating point state by clearing LSPEN bit
   * Workaround for errata e6940 */
  S32_SCB->FPCCR &= ~(S32_SCB_FPCCR_LSPEN_MASK);
#endif
#endif /* ENABLE_FPU */

/**************************************************************************/
                      /* WDOG DISABLE*/
/**************************************************************************/

#if (DISABLE_WDOG)
  /* Write of the WDOG unlock key to CNT register, must be done in order to allow any modifications*/
  WDOG->CNT = (uint32_t ) FEATURE_WDOG_UNLOCK_VALUE;
  /* The dummy read is used in order to make sure that the WDOG registers will be configured only
   * after the write of the unlock value was completed. */
  (void)WDOG->CNT;

  /* Initial write of WDOG configuration register:
   * enables support for 32-bit refresh/unlock command write words,
   * clock select from LPO, update enable, watchdog disabled */
  WDOG->CS  = (uint32_t ) ( (1UL << WDOG_CS_CMD32EN_SHIFT)                       |
                            (FEATURE_WDOG_CLK_FROM_LPO << WDOG_CS_CLK_SHIFT)     |
                            (0U << WDOG_CS_EN_SHIFT)                             |
                            (1U << WDOG_CS_UPDATE_SHIFT)                         );

  /* Configure timeout */
  WDOG->TOVAL = (uint32_t )0xFFFF;
#endif /* (DISABLE_WDOG) */

/**************************************************************************/
            /* ENABLE CACHE */
/**************************************************************************/
#if (ICACHE_ENABLE)
  /* Invalidate and enable code cache */
  LMEM->PCCCR = LMEM_PCCCR_INVW0(1) | LMEM_PCCCR_INVW1(1) | LMEM_PCCCR_GO(1) | LMEM_PCCCR_ENCACHE(1);
#endif /* (ICACHE_ENABLE) */

/**************************************************************************/
            /* GRANT ACCESS TO ALL BUS MASTERS IN MPU */
/**************************************************************************/
#if ENABLE_ALL_BUS_MASTERS_IN_MPU
    /* Bus masters 0-2 are already enabled r/w/x in supervisor & user modes after reset */
    /* Enable also bus master 3 (ENET) in S/U modes in default region 0 */
    MPU->RGDAAC[0] |= ( MPU_RGDAAC_M3SM(3)  /* 11b - Same as User mode defined in M3UM */
                      | MPU_RGDAAC_M3UM(7) /* 111b - r/w/x */ );
#endif /* ENABLE_ALL_BUS_MASTERS_IN_MPU */

    SCG->SOSCCSR = SCG_SOSCCSR_SOSCERR(1U);

    /* set up OSC clock. */
    /* Setup dividers. */
    SCG->SOSCDIV = (SCG_SOSCDIV_SOSCDIV1(1U) |
                    SCG_SOSCDIV_SOSCDIV2(1U)  );

    /* Set OSC configuration. */
    SCG->SOSCCFG = (SCG_SOSCCFG_EREFS(1U) |
                    SCG_SOSCCFG_RANGE(2U)  );

    /* Enable clock. */
    SCG->SOSCCSR = (SCG_SOSCCSR_SOSCEN(1U) );

    /* Wait for OSC clock to be valid. */
    while (!(SCG->SOSCCSR & SCG_SOSCCSR_SOSCVLD(1U))) __NOP();

    /* Init SIRC */
    SCG->SIRCCSR = 0U;

    /* Setup dividers. */
    SCG->SIRCDIV = (SCG_SIRCDIV_SIRCDIV1(1U) |
                    SCG_SIRCDIV_SIRCDIV2(2U)  );

    /* Set SIRC configuration. */
    SCG->SIRCCFG = SCG_SIRCCFG_RANGE(1U);

    /* Enable clock. */
    SCG->SIRCCSR = SCG_SIRCCSR_SIRCEN(1U);

    /* Wait for SIRC clock to be valid. */
    while (!(SCG->SIRCCSR & SCG_SIRCCSR_SIRCVLD(1U))) __NOP();

    /* Change to SIRC as system clock source */
    SCG->RCCR = (SCG_RCCR_DIVSLOW(3U) |
                 SCG_RCCR_DIVBUS(0U)  |
                 SCG_RCCR_DIVCORE(0U) |
                 SCG_RCCR_SCS(2U)     );

    /* Wait for clock source switch finished. */
    while ((SCG->RCCR & 0x0F000000) != 0x02000000) __NOP();;

    /* Init Firc */
    SCG->FIRCCSR = 0U;

    /* Setup dividers. */
    SCG->FIRCDIV = (SCG_FIRCDIV_FIRCDIV1(1U) |
                    SCG_FIRCDIV_FIRCDIV2(1U)  );

    /* Set FIRC configuration. */
    SCG->FIRCCFG = SCG_FIRCCFG_RANGE(0U);

    /* Enable clock. */
    SCG->FIRCCSR |= SCG_FIRCCSR_FIRCEN(1U);

    /* Wait for FIRC clock to be valid. */
    while (!(SCG->FIRCCSR & SCG_FIRCCSR_FIRCVLD(1U))) __NOP();;

    /* Init SysPll */
    SCG->SPLLCSR = SCG_SPLLCSR_SPLLERR(1U);

    /* Setup dividers. */
    SCG->SPLLDIV = (SCG_SPLLDIV_SPLLDIV1(1U) |
                    SCG_SPLLDIV_SPLLDIV2(2U)  );

    /* Set PLL configuration. */
    SCG->SPLLCFG = (SCG_SPLLCFG_PREDIV(0U) |                     /* prediv 1 */
                    SCG_SPLLCFG_MULT(8U)   );                    /* pll multiply 24 */

    /* Enable clock. */
    SCG->SPLLCSR = SCG_SPLLCSR_SPLLEN(1U);

    /* Wait for PLL clock to be valid. */
    while (!(SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD(1U))) __NOP();

    /* Change to use PLL as system clock source */
    SCG->RCCR = (SCG_RCCR_DIVSLOW(4U) |
                 SCG_RCCR_DIVBUS(1U)  |
                 SCG_RCCR_DIVCORE(0U) |
                 SCG_RCCR_SCS(6U)     );

    /* Wait for clock source switch finished. */
    while ((SCG->RCCR & 0x0F000000) != 0x06000000) __NOP();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SystemCoreClockUpdate
 * Description   : This function must be called whenever the core clock is changed
 * during program execution. It evaluates the clock register settings and calculates
 * the current core clock.
 *
 * Implements    : SystemCoreClockUpdate_Activity
 *END**************************************************************************/
void SystemCoreClockUpdate(void)
{
  uint32_t SCGOUTClock = 0U;      /* Variable to store output clock frequency of the SCG module */
  uint32_t regValue;              /* Temporary variable */
  uint32_t divider, prediv, multi;
  bool validSystemClockSource = true;
  static const uint32_t fircFreq[] = {
      FEATURE_SCG_FIRC_FREQ0,
      FEATURE_SCG_FIRC_FREQ1,
      FEATURE_SCG_FIRC_FREQ2,
      FEATURE_SCG_FIRC_FREQ3,
  };

  divider = ((SCG->CSR & SCG_CSR_DIVCORE_MASK) >> SCG_CSR_DIVCORE_SHIFT) + 1U;

  switch ((SCG->CSR & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT) {
    case 0x1:
      /* System OSC */
      SCGOUTClock = CPU_XTAL_CLK_HZ;
      break;
    case 0x2:
      /* Slow IRC */
      regValue = (SCG->SIRCCFG & SCG_SIRCCFG_RANGE_MASK) >> SCG_SIRCCFG_RANGE_SHIFT;
      SCGOUTClock = (regValue != 0U) ?
                    FEATURE_SCG_SIRC_HIGH_RANGE_FREQ : FEATURE_SCG_SIRC_LOW_RANGE_FREQ;
      break;
    case 0x3:
      /* Fast IRC */
      regValue = (SCG->FIRCCFG & SCG_FIRCCFG_RANGE_MASK) >> SCG_FIRCCFG_RANGE_SHIFT;
      SCGOUTClock= fircFreq[regValue];
      break;
    case 0x6:
      /* System PLL */
      SCGOUTClock = CPU_XTAL_CLK_HZ;
      prediv = ((SCG->SPLLCFG & SCG_SPLLCFG_PREDIV_MASK) >> SCG_SPLLCFG_PREDIV_SHIFT) + 1U;
      multi = ((SCG->SPLLCFG & SCG_SPLLCFG_MULT_MASK) >> SCG_SPLLCFG_MULT_SHIFT) + 16U;
      SCGOUTClock = SCGOUTClock * multi / (prediv * 2U);
      break;
    default:
      validSystemClockSource = false;
      break;
  }

  if (validSystemClockSource == true) {
     SystemCoreClock = (SCGOUTClock / divider);
  }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SystemSoftwareReset
 * Description   : This function is used to software reset the microcontroller.
 *
 * Implements    : SystemSoftwareReset_Activity
 *END**************************************************************************/
void SystemSoftwareReset(void)
{
    uint32_t regValue;

    /* Read Application Interrupt and Reset Control Register */
    regValue = S32_SCB->AIRCR;

    /* Clear register key */
    regValue &= ~( S32_SCB_AIRCR_VECTKEY_MASK);

    /* Configure System reset request bit and Register Key */
    regValue |= S32_SCB_AIRCR_VECTKEY(FEATURE_SCB_VECTKEY);
    regValue |= S32_SCB_AIRCR_SYSRESETREQ(0x1u);

    /* Write computed register value */
    S32_SCB->AIRCR = regValue;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/

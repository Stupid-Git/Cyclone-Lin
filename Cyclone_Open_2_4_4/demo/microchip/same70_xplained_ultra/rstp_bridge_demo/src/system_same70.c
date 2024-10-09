/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) 2015, Atmel Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/*                                                                              */
/*                                                             modified by Keil */
/* ---------------------------------------------------------------------------- */

#include "sam.h"

/* @cond 0 */
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/* @endcond */

/* %ATMEL_SYSTEM% */
/* Clock Settings (600MHz PLL VDDIO 3.3V and VDDCORE 1.2V) */
/* Clock Settings (300MHz HCLK, 150MHz MCK)=> PRESC = 2, MDIV = 2 */
#define SYS_BOARD_OSCOUNT   (CKGR_MOR_MOSCXTST(0x8U))
#define SYS_BOARD_PLLAR     (CKGR_PLLAR_ONE_Msk | CKGR_PLLAR_MULA(0x31U) | \
                            CKGR_PLLAR_PLLACOUNT(0x3fU) | CKGR_PLLAR_DIVA(0x1U))
#define SYS_BOARD_MCKR      (PMC_MCKR_PRES_CLK_2 | PMC_MCKR_CSS_PLLA_CLK | (1<<8))

uint32_t SystemCoreClock = CHIP_FREQ_MAINCK_RC_4MHZ;

/**
 * \brief Setup the microcontroller system.
 * Initialize the System and update the SystemFrequency variable.
 */
 void SystemInit( void )
{
#if (__FPU_USED == 1)                   // Keil
  /* enable FPU if available and used */
  SCB->CPACR |= ((3UL << 10*2) |             /* set CP10 Full Access               */
                 (3UL << 11*2)  );           /* set CP11 Full Access               */
#endif

  /* Set FWS according to SYS_BOARD_MCKR configuration */
  EFC_REGS->EEFC_FMR = EEFC_FMR_FWS(5) | EEFC_FMR_CLOE_Msk;

  /* Initialize main oscillator */
  if ( !(PMC_REGS->CKGR_MOR & CKGR_MOR_MOSCSEL_Msk) )
  {
    PMC_REGS->CKGR_MOR = CKGR_MOR_KEY_PASSWD | SYS_BOARD_OSCOUNT |
      CKGR_MOR_MOSCRCEN_Msk | CKGR_MOR_MOSCXTEN_Msk;

    while ( !(PMC_REGS->PMC_SR & PMC_SR_MOSCXTS_Msk) )
    {
    }
  }

  /* Switch to 3-20MHz Xtal oscillator */
  PMC_REGS->CKGR_MOR = CKGR_MOR_KEY_PASSWD | SYS_BOARD_OSCOUNT |
    CKGR_MOR_MOSCRCEN_Msk | CKGR_MOR_MOSCXTEN_Msk | CKGR_MOR_MOSCSEL_Msk;

  while ( !(PMC_REGS->PMC_SR & PMC_SR_MOSCSELS_Msk) )
  {
  }

  PMC_REGS->PMC_MCKR = (PMC_REGS->PMC_MCKR & ~(uint32_t)PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_MAIN_CLK;

  while ( !(PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) )
  {
  }

  /* Initialize PLLA */
  PMC_REGS->CKGR_PLLAR = SYS_BOARD_PLLAR;
  while ( !(PMC_REGS->PMC_SR & PMC_SR_LOCKA_Msk) )
  {
  }

  /* Switch to main clock */
  PMC_REGS->PMC_MCKR = (SYS_BOARD_MCKR & ~PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_MAIN_CLK;
  while ( !(PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) )
  {
  }

  /* Switch to PLLA */
  PMC_REGS->PMC_MCKR = SYS_BOARD_MCKR;
  while ( !(PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) )
  {
  }

  SystemCoreClock = CHIP_FREQ_CPU_MAX;
}

void SystemCoreClockUpdate( void )
{
  /* Determine clock frequency according to clock register values */
  switch (PMC_REGS->PMC_MCKR & (uint32_t) PMC_MCKR_CSS_Msk)
  {
    case PMC_MCKR_CSS_SLOW_CLK: /* Slow clock */
      if ( SUPC_REGS->SUPC_SR & SUPC_SR_OSCSEL_Msk )
      {
        SystemCoreClock = CHIP_FREQ_XTAL_32K;
      }
      else
      {
        SystemCoreClock = CHIP_FREQ_SLCK_RC;
      }
    break;

    case PMC_MCKR_CSS_MAIN_CLK: /* Main clock */
      if ( PMC_REGS->CKGR_MOR & CKGR_MOR_MOSCSEL_Msk )
      {
        SystemCoreClock = CHIP_FREQ_XTAL_12M;
      }
      else
      {
        SystemCoreClock = CHIP_FREQ_MAINCK_RC_4MHZ;

        switch ( PMC_REGS->CKGR_MOR & CKGR_MOR_MOSCRCF_Msk )
        {
          case CKGR_MOR_MOSCRCF_4_MHz:
          break;

          case CKGR_MOR_MOSCRCF_8_MHz:
            SystemCoreClock *= 2U;
          break;

          case CKGR_MOR_MOSCRCF_12_MHz:
            SystemCoreClock *= 3U;
          break;

          default:
          break;
        }
      }
    break;

    case PMC_MCKR_CSS_PLLA_CLK:	/* PLLA clock */
      if ( PMC_REGS->CKGR_MOR & CKGR_MOR_MOSCSEL_Msk )
      {
        SystemCoreClock = CHIP_FREQ_XTAL_12M ;
      }
      else
      {
        SystemCoreClock = CHIP_FREQ_MAINCK_RC_4MHZ;

        switch ( PMC_REGS->CKGR_MOR & CKGR_MOR_MOSCRCF_Msk )
        {
          case CKGR_MOR_MOSCRCF_4_MHz:
          break;

          case CKGR_MOR_MOSCRCF_8_MHz:
            SystemCoreClock *= 2U;
          break;

          case CKGR_MOR_MOSCRCF_12_MHz:
            SystemCoreClock *= 3U;
          break;

          default:
          break;
        }
      }

      if ( (uint32_t) (PMC_REGS->PMC_MCKR & (uint32_t) PMC_MCKR_CSS_Msk) == PMC_MCKR_CSS_PLLA_CLK )
      {
        SystemCoreClock *= ((((PMC_REGS->CKGR_PLLAR) & CKGR_PLLAR_MULA_Msk) >> CKGR_PLLAR_MULA_Pos) + 1U);
        SystemCoreClock /= ((((PMC_REGS->CKGR_PLLAR) & CKGR_PLLAR_DIVA_Msk) >> CKGR_PLLAR_DIVA_Pos));
      }
    break;

    default:
    break;
  }

  if ( (PMC_REGS->PMC_MCKR & PMC_MCKR_PRES_Msk) == PMC_MCKR_PRES_CLK_3 )
  {
    SystemCoreClock /= 3U;
  }
  else
  {
    SystemCoreClock >>= ((PMC_REGS->PMC_MCKR & PMC_MCKR_PRES_Msk) >> PMC_MCKR_PRES_Pos);
  }
}
/**
 * Initialize flash.
 */
void system_init_flash( uint32_t ul_clk )
{
  /* Set FWS for embedded Flash access according to operating frequency */
  if ( ul_clk < CHIP_FREQ_FWS_0 )
  {
    EFC_REGS->EEFC_FMR = EEFC_FMR_FWS(0) | EEFC_FMR_CLOE_Msk;
  }
  else
  {
    if (ul_clk < CHIP_FREQ_FWS_1)
    {
      EFC_REGS->EEFC_FMR = EEFC_FMR_FWS(1) | EEFC_FMR_CLOE_Msk;
    }
    else
    {
      if (ul_clk < CHIP_FREQ_FWS_2)
      {
        EFC_REGS->EEFC_FMR = EEFC_FMR_FWS(2) | EEFC_FMR_CLOE_Msk;
      }
      else
      {
        if ( ul_clk < CHIP_FREQ_FWS_3 )
        {
          EFC_REGS->EEFC_FMR = EEFC_FMR_FWS(3) | EEFC_FMR_CLOE_Msk;
        }
        else
        {
          if ( ul_clk < CHIP_FREQ_FWS_4 )
          {
            EFC_REGS->EEFC_FMR = EEFC_FMR_FWS(4) | EEFC_FMR_CLOE_Msk;
          }
          else
          {
            EFC_REGS->EEFC_FMR = EEFC_FMR_FWS(5) | EEFC_FMR_CLOE_Msk;
          }
        }
      }
    }
  }
}
/* @cond 0 */
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/* @endcond */

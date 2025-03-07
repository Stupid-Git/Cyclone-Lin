/**
  ******************************************************************************
  * @file    system_stm32f4xx.c
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M4 Device Peripheral Access Layer System Source File.
  *
  *   This file provides two functions and one global variable to be called from
  *   user application:
  *      - SystemInit(): This function is called at startup just after reset and
  *                      before branch to main program. This call is made inside
  *                      the "startup_stm32f4xx.s" file.
  *
  *      - SystemCoreClock variable: Contains the core clock (HCLK), it can be used
  *                                  by the user application to setup the SysTick
  *                                  timer or configure other parameters.
  *
  *      - SystemCoreClockUpdate(): Updates the variable SystemCoreClock and must
  *                                 be called whenever the core clock is changed
  *                                 during program execution.
  *
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f4xx_system
  * @{
  */

/** @addtogroup STM32F4xx_System_Private_Includes
  * @{
  */

#include "stm32f4xx.h"

/**
  * @}
  */

/** @addtogroup STM32F4xx_System_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F4xx_System_Private_Defines
  * @{
  */

/************************* Miscellaneous Configuration ************************/
/*!< Uncomment the following line if you need to use external SRAM or SDRAM mounted
     on STM324xG_EVAL/STM324x7I_EVAL/STM324x9I_EVAL boards as data memory  */
#define DATA_IN_ExtSRAM
/* #define DATA_IN_ExtSDRAM */

/*!< Uncomment the following line if you need to relocate your vector Table in
     Internal SRAM. */
/* #define VECT_TAB_SRAM */
#define VECT_TAB_OFFSET  0x00 /*!< Vector Table base offset field.
                                   This value must be a multiple of 0x200. */
/******************************************************************************/

/**
  * @}
  */

/** @addtogroup STM32F4xx_System_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F4xx_System_Private_Variables
  * @{
  */
uint32_t SystemCoreClock = 16800000;
const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APBPrescTable[8]  = {0, 0, 0, 0, 1, 2, 3, 4};

/**
  * @}
  */

/** @addtogroup STM32F4xx_System_Private_FunctionPrototypes
  * @{
  */

#if defined (DATA_IN_ExtSRAM) || defined (DATA_IN_ExtSDRAM)
  static void SystemInit_ExtMemCtl(void);
#endif /* DATA_IN_ExtSRAM || DATA_IN_ExtSDRAM */

/**
  * @}
  */

/** @addtogroup STM32F4xx_System_Private_Functions
  * @{
  */

/**
  * @brief  Setup the microcontroller system
  *         Initialize the Embedded Flash Interface, the PLL and update the
  *         SystemFrequency variable.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
  /* FPU settings ------------------------------------------------------------*/
  #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
  #endif
  /* Reset the RCC clock configuration to the default reset state ------------*/
  /* Set HSION bit */
  RCC->CR |= (uint32_t)0x00000001;

  /* Reset CFGR register */
  RCC->CFGR = 0x00000000;

  /* Reset HSEON, CSSON and PLLON bits */
  RCC->CR &= (uint32_t)0xFEF6FFFF;

  /* Reset PLLCFGR register */
  RCC->PLLCFGR = 0x24003010;

  /* Reset HSEBYP bit */
  RCC->CR &= (uint32_t)0xFFFBFFFF;

  /* Disable all interrupts */
  RCC->CIR = 0x00000000;

#if defined (DATA_IN_ExtSRAM) || defined (DATA_IN_ExtSDRAM)
  SystemInit_ExtMemCtl();
#endif /* DATA_IN_ExtSRAM || DATA_IN_ExtSDRAM */

  /* Configure the Vector Table location add offset address ------------------*/
#ifdef VECT_TAB_SRAM
  //SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM */
#else
  //SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */
#endif
}

/**
   * @brief  Update SystemCoreClock variable according to Clock Register Values.
  *         The SystemCoreClock variable contains the core clock (HCLK), it can
  *         be used by the user application to setup the SysTick timer or configure
  *         other parameters.
  *
  * @note   Each time the core clock (HCLK) changes, this function must be called
  *         to update SystemCoreClock variable value. Otherwise, any configuration
  *         based on this variable will be incorrect.
  *
  * @note   - The system frequency computed by this function is not the real
  *           frequency in the chip. It is calculated based on the predefined
  *           constant and the selected clock source:
  *
  *           - If SYSCLK source is HSI, SystemCoreClock will contain the HSI_VALUE(*)
  *
  *           - If SYSCLK source is HSE, SystemCoreClock will contain the HSE_VALUE(**)
  *
  *           - If SYSCLK source is PLL, SystemCoreClock will contain the HSE_VALUE(**)
  *             or HSI_VALUE(*) multiplied/divided by the PLL factors.
  *
  *         (*) HSI_VALUE is a constant defined in stm32f4xx.h file (default value
  *             16 MHz) but the real value may vary depending on the variations
  *             in voltage and temperature.
  *
  *         (**) HSE_VALUE is a constant defined in stm32f4xx.h file (default value
  *              25 MHz), user has to ensure that HSE_VALUE is same as the real
  *              frequency of the crystal used. Otherwise, this function may
  *              have wrong result.
  *
  *         - The result of this function could be not correct when using fractional
  *           value for HSE crystal.
  *
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate(void)
{
  uint32_t tmp = 0, pllvco = 0, pllp = 2, pllsource = 0, pllm = 2;

  /* Get SYSCLK source -------------------------------------------------------*/
  tmp = RCC->CFGR & RCC_CFGR_SWS;

  switch (tmp)
  {
    case 0x00:  /* HSI used as system clock source */
      SystemCoreClock = HSI_VALUE;
      break;
    case 0x04:  /* HSE used as system clock source */
      SystemCoreClock = HSE_VALUE;
      break;
    case 0x08:  /* PLL used as system clock source */

      /* PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N
         SYSCLK = PLL_VCO / PLL_P
         */
      pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC) >> 22;
      pllm = RCC->PLLCFGR & RCC_PLLCFGR_PLLM;

      if (pllsource != 0)
      {
        /* HSE used as PLL clock source */
        pllvco = (HSE_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
      }
      else
      {
        /* HSI used as PLL clock source */
        pllvco = (HSI_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6);
      }

      pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >>16) + 1 ) *2;
      SystemCoreClock = pllvco/pllp;
      break;
    default:
      SystemCoreClock = HSI_VALUE;
      break;
  }
  /* Compute HCLK frequency --------------------------------------------------*/
  /* Get HCLK prescaler */
  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
  /* HCLK frequency */
  SystemCoreClock >>= tmp;
}

/**
  * @brief  Setup the external memory controller. Called in startup_stm32f4xx.s
  *          before jump to __main
  * @param  None
  * @retval None
  */
#ifdef DATA_IN_ExtSRAM
/**
  * @brief  Setup the external memory controller.
  *         Called in startup_stm32f4xx.s before jump to main.
  *         This function configures the external SRAM mounted on STM324xG_EVAL/STM324x7I boards
  *         This SRAM will be used as program data memory (including heap and stack).
  * @param  None
  * @retval None
  */
void SystemInit_ExtMemCtl(void)
{
/*-- GPIOs Configuration -----------------------------------------------------*/
/*
 +-------------------+--------------------+------------------+---------------+
 +                       SRAM pins assignment                                +
 +-------------------+--------------------+------------------+---------------+
 | PD0  <-> FMC_D2  | PE0  <-> FMC_NBL0 | PF0  <-> FMC_A0 | PG0  <-> FMC_A10 |
 | PD1  <-> FMC_D3  | PE1  <-> FMC_NBL1 | PF1  <-> FMC_A1 | PG1  <-> FMC_A11 |
 | PD4  <-> FMC_NOE | PE3  <-> FMC_A19  | PF2  <-> FMC_A2 | PG2  <-> FMC_A12 |
 | PD5  <-> FMC_NWE | PE4  <-> FMC_A20  | PF3  <-> FMC_A3 | PG3  <-> FMC_A13 |
 | PD8  <-> FMC_D13 | PE7  <-> FMC_D4   | PF4  <-> FMC_A4 | PG4  <-> FMC_A14 |
 | PD9  <-> FMC_D14 | PE8  <-> FMC_D5   | PF5  <-> FMC_A5 | PG5  <-> FMC_A15 |
 | PD10 <-> FMC_D15 | PE9  <-> FMC_D6   | PF12 <-> FMC_A6 | PG10 <-> FMC_NE3 |
 | PD11 <-> FMC_A16 | PE10 <-> FMC_D7   | PF13 <-> FMC_A7 |------------------+
 | PD12 <-> FMC_A17 | PE11 <-> FMC_D8   | PF14 <-> FMC_A8 |
 | PD13 <-> FMC_A18 | PE12 <-> FMC_D9   | PF15 <-> FMC_A9 |
 | PD14 <-> FMC_D0  | PE13 <-> FMC_D10  |-----------------+
 | PD15 <-> FMC_D1  | PE14 <-> FMC_D11  |
 |                  | PE15 <-> FMC_D12  |
 +------------------+------------------+
*/
  //FSMC_NORSRAMInitTypeDef FSMC_NORSRAMInitStructure;
  //FSMC_NORSRAMTimingInitTypeDef p;

  /* Enable GPIOD, GPIOE, GPIOF and GPIOG interface clock */
  RCC->AHB1ENR = 0x00000078;

  /* Connect PDx pins to FSMC Alternate function */
  GPIOD->AFR[0] = 0x00cc00cc;
  GPIOD->AFR[1] = 0xcccccccc;
  /* Configure PDx pins in Alternate function mode */
  GPIOD->MODER = 0xaaaa0a0a;
  /* Configure PDx pins speed to 100 MHz */
  GPIOD->OSPEEDR = 0xffff0f0f;
  /* Configure PDx pins Output type to push-pull */
  GPIOD->OTYPER = 0x00000000;
  /* No pull-up, pull-down for PDx pins */
  GPIOD->PUPDR = 0x00000000;

  /* Connect PEx pins to FSMC Alternate function */
  GPIOE->AFR[0] = 0xc00cc0cc;
  GPIOE->AFR[1] = 0xcccccccc;
  /* Configure PEx pins in Alternate function mode */
  GPIOE->MODER = 0xaaaa828a;
  /* Configure PEx pins speed to 100 MHz */
  GPIOE->OSPEEDR = 0xffffc3cf;
  /* Configure PEx pins Output type to push-pull */
  GPIOE->OTYPER = 0x00000000;
  /* No pull-up, pull-down for PEx pins */
  GPIOE->PUPDR = 0x00000000;

  /* Connect PFx pins to FSMC Alternate function */
  GPIOF->AFR[0] = 0x00cccccc;
  GPIOF->AFR[1] = 0xcccc0000;
  /* Configure PFx pins in Alternate function mode */
  GPIOF->MODER = 0xaa000aaa;
  /* Configure PFx pins speed to 100 MHz */
  GPIOF->OSPEEDR = 0xff000fff;
  /* Configure PFx pins Output type to push-pull */
  GPIOF->OTYPER = 0x00000000;
  /* No pull-up, pull-down for PFx pins */
  GPIOF->PUPDR = 0x00000000;

  /* Connect PGx pins to FSMC Alternate function */
#if 1
  GPIOG->AFR[0] = 0x00cccccc;
  GPIOG->AFR[1] = 0x000c0c00; //was 0x000000c0
  /* Configure PGx pins in Alternate function mode */
  GPIOG->MODER = 0x02200aaa; //was 0x00080aaa
  /* Configure PGx pins speed to 100 MHz */
  GPIOG->OSPEEDR = 0x03300fff; //was 0x000c0fff
  /* Configure PGx pins Output type to push-pull */
  GPIOG->OTYPER = 0x00000000;
  /* No pull-up, pull-down for PGx pins */
  GPIOG->PUPDR = 0x00000000;
#else
  GPIOG->AFR[0] = 0x00cccccc;
  GPIOG->AFR[1] = 0x00000c00; //was 0x000000c0
  /* Configure PGx pins in Alternate function mode */
  GPIOG->MODER = 0x00200aaa; //was 0x00080aaa
  /* Configure PGx pins speed to 100 MHz */
  GPIOG->OSPEEDR = 0x00300fff; //was 0x000c0fff
  /* Configure PGx pins Output type to push-pull */
  GPIOG->OTYPER = 0x00000000;
  /* No pull-up, pull-down for PGx pins */
  GPIOG->PUPDR = 0x00000000;
#endif

  /*-- FSMC Configuration ------------------------------------------------------*/
  /* Enable the FSMC interface clock */
  RCC->AHB3ENR |= 0x00000001;                           /* enable FSMC clock */
  //RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, ENABLE);

  /* Configure and enable Bank1_SRAM3 */
  FSMC_Bank1->BTCR[4] = 0x00001011;
  FSMC_Bank1->BTCR[5] = 0x00010603;
  FSMC_Bank1E->BWTR[4] = 0x0fffffff;

/* Bank1_SRAM3 is configured as follow: */
/*
p.FSMC_AddressSetupTime = 3;
p.FSMC_AddressHoldTime = 0;
p.FSMC_DataSetupTime = 6;
p.FSMC_BusTurnAroundDuration = 1;
p.FSMC_CLKDivision = 0;
p.FSMC_DataLatency = 0;
p.FSMC_AccessMode = FSMC_AccessMode_A;

//FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM2;
FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM3; //For Keil
FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
//FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_PSRAM;
FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM; //For Keil

FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;
FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;

FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);

FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM3, ENABLE);*/
}
#endif /* DATA_IN_ExtSRAM */

#ifdef DATA_IN_ExtSDRAM
/**
  * @brief  Setup the external memory controller.
  *         Called in startup_stm32f4xx.s before jump to main.
  *         This function configures the external SDRAM mounted on STM324x9I_EVAL board
  *         This SDRAM will be used as program data memory (including heap and stack).
  * @param  None
  * @retval None
  */
void SystemInit_ExtMemCtl(void)
{
  register uint32_t tmpreg = 0, timeout = 0xFFFF;
  register uint32_t index;

  /* Enable GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH and GPIOI interface
      clock */
  RCC->AHB1ENR |= 0x000001FC;

  /* Connect PCx pins to FMC Alternate function */
  GPIOC->AFR[0]  = 0x0000000c;
  GPIOC->AFR[1]  = 0x00007700;
  /* Configure PCx pins in Alternate function mode */
  GPIOC->MODER   = 0x00a00002;
  /* Configure PCx pins speed to 50 MHz */
  GPIOC->OSPEEDR = 0x00a00002;
  /* Configure PCx pins Output type to push-pull */
  GPIOC->OTYPER  = 0x00000000;
  /* No pull-up, pull-down for PCx pins */
  GPIOC->PUPDR   = 0x00500000;

  /* Connect PDx pins to FMC Alternate function */
  GPIOD->AFR[0]  = 0x000000CC;
  GPIOD->AFR[1]  = 0xCC000CCC;
  /* Configure PDx pins in Alternate function mode */
  GPIOD->MODER   = 0xA02A000A;
  /* Configure PDx pins speed to 50 MHz */
  GPIOD->OSPEEDR = 0xA02A000A;
  /* Configure PDx pins Output type to push-pull */
  GPIOD->OTYPER  = 0x00000000;
  /* No pull-up, pull-down for PDx pins */
  GPIOD->PUPDR   = 0x00000000;

  /* Connect PEx pins to FMC Alternate function */
  GPIOE->AFR[0]  = 0xC00000CC;
  GPIOE->AFR[1]  = 0xCCCCCCCC;
  /* Configure PEx pins in Alternate function mode */
  GPIOE->MODER   = 0xAAAA800A;
  /* Configure PEx pins speed to 50 MHz */
  GPIOE->OSPEEDR = 0xAAAA800A;
  /* Configure PEx pins Output type to push-pull */
  GPIOE->OTYPER  = 0x00000000;
  /* No pull-up, pull-down for PEx pins */
  GPIOE->PUPDR   = 0x00000000;

  /* Connect PFx pins to FMC Alternate function */
  GPIOF->AFR[0]  = 0xcccccccc;
  GPIOF->AFR[1]  = 0xcccccccc;
  /* Configure PFx pins in Alternate function mode */
  GPIOF->MODER   = 0xAA800AAA;
  /* Configure PFx pins speed to 50 MHz */
  GPIOF->OSPEEDR = 0xAA800AAA;
  /* Configure PFx pins Output type to push-pull */
  GPIOF->OTYPER  = 0x00000000;
  /* No pull-up, pull-down for PFx pins */
  GPIOF->PUPDR   = 0x00000000;

  /* Connect PGx pins to FMC Alternate function */
  GPIOG->AFR[0]  = 0xcccccccc;
  GPIOG->AFR[1]  = 0xcccccccc;
  /* Configure PGx pins in Alternate function mode */
  GPIOG->MODER   = 0xaaaaaaaa;
  /* Configure PGx pins speed to 50 MHz */
  GPIOG->OSPEEDR = 0xaaaaaaaa;
  /* Configure PGx pins Output type to push-pull */
  GPIOG->OTYPER  = 0x00000000;
  /* No pull-up, pull-down for PGx pins */
  GPIOG->PUPDR   = 0x00000000;

  /* Connect PHx pins to FMC Alternate function */
  GPIOH->AFR[0]  = 0x00C0CC00;
  GPIOH->AFR[1]  = 0xCCCCCCCC;
  /* Configure PHx pins in Alternate function mode */
  GPIOH->MODER   = 0xAAAA08A0;
  /* Configure PHx pins speed to 50 MHz */
  GPIOH->OSPEEDR = 0xAAAA08A0;
  /* Configure PHx pins Output type to push-pull */
  GPIOH->OTYPER  = 0x00000000;
  /* No pull-up, pull-down for PHx pins */
  GPIOH->PUPDR   = 0x00000000;

  /* Connect PIx pins to FMC Alternate function */
  GPIOI->AFR[0]  = 0xCCCCCCCC;
  GPIOI->AFR[1]  = 0x00000CC0;
  /* Configure PIx pins in Alternate function mode */
  GPIOI->MODER   = 0x0028AAAA;
  /* Configure PIx pins speed to 50 MHz */
  GPIOI->OSPEEDR = 0x0028AAAA;
  /* Configure PIx pins Output type to push-pull */
  GPIOI->OTYPER  = 0x00000000;
  /* No pull-up, pull-down for PIx pins */
  GPIOI->PUPDR   = 0x00000000;

/*-- FMC Configuration ------------------------------------------------------*/
  /* Enable the FMC interface clock */
  RCC->AHB3ENR |= 0x00000001;

  /* Configure and enable SDRAM bank1 */
  FMC_Bank5_6->SDCR[0] = 0x000029D0;
  FMC_Bank5_6->SDTR[0] = 0x01115351;

  /* SDRAM initialization sequence */
  /* Clock enable command */
  FMC_Bank5_6->SDCMR = 0x00000011;
  tmpreg = FMC_Bank5_6->SDSR & 0x00000020;
  while((tmpreg != 0) & (timeout-- > 0))
  {
    tmpreg = FMC_Bank5_6->SDSR & 0x00000020;
  }

  /* Delay */
  for (index = 0; index<1000; index++);

  /* PALL command */
  FMC_Bank5_6->SDCMR = 0x00000012;
  timeout = 0xFFFF;
  while((tmpreg != 0) & (timeout-- > 0))
  {
  tmpreg = FMC_Bank5_6->SDSR & 0x00000020;
  }

  /* Auto refresh command */
  FMC_Bank5_6->SDCMR = 0x00000073;
  timeout = 0xFFFF;
  while((tmpreg != 0) & (timeout-- > 0))
  {
  tmpreg = FMC_Bank5_6->SDSR & 0x00000020;
  }

  /* MRD register program */
  FMC_Bank5_6->SDCMR = 0x00046014;
  timeout = 0xFFFF;
  while((tmpreg != 0) & (timeout-- > 0))
  {
  tmpreg = FMC_Bank5_6->SDSR & 0x00000020;
  }

  /* Set refresh count */
  tmpreg = FMC_Bank5_6->SDRTR;
  FMC_Bank5_6->SDRTR = (tmpreg | (0x0000027C<<1));

  /* Disable write protection */
  tmpreg = FMC_Bank5_6->SDCR[0];
  FMC_Bank5_6->SDCR[0] = (tmpreg & 0xFFFFFDFF);

/*
  Bank1_SDRAM is configured as follow:

  FMC_SDRAMTimingInitStructure.FMC_LoadToActiveDelay = 2;
  FMC_SDRAMTimingInitStructure.FMC_ExitSelfRefreshDelay = 6;
  FMC_SDRAMTimingInitStructure.FMC_SelfRefreshTime = 4;
  FMC_SDRAMTimingInitStructure.FMC_RowCycleDelay = 6;
  FMC_SDRAMTimingInitStructure.FMC_WriteRecoveryTime = 2;
  FMC_SDRAMTimingInitStructure.FMC_RPDelay = 2;
  FMC_SDRAMTimingInitStructure.FMC_RCDDelay = 2;

  FMC_SDRAMInitStructure.FMC_Bank = SDRAM_BANK;
  FMC_SDRAMInitStructure.FMC_ColumnBitsNumber = FMC_ColumnBits_Number_8b;
  FMC_SDRAMInitStructure.FMC_RowBitsNumber = FMC_RowBits_Number_11b;
  FMC_SDRAMInitStructure.FMC_SDMemoryDataWidth = FMC_SDMemory_Width_16b;
  FMC_SDRAMInitStructure.FMC_InternalBankNumber = FMC_InternalBank_Number_4;
  FMC_SDRAMInitStructure.FMC_CASLatency = FMC_CAS_Latency_3;
  FMC_SDRAMInitStructure.FMC_WriteProtection = FMC_Write_Protection_Disable;
  FMC_SDRAMInitStructure.FMC_SDClockPeriod = FMC_SDClock_Period_2;
  FMC_SDRAMInitStructure.FMC_ReadBurst = FMC_Read_Burst_disable;
  FMC_SDRAMInitStructure.FMC_ReadPipeDelay = FMC_ReadPipe_Delay_1;
  FMC_SDRAMInitStructure.FMC_SDRAMTimingStruct = &FMC_SDRAMTimingInitStructure;
*/

}
#endif /* DATA_IN_ExtSDRAM */


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

//Dependencies
#include "sam.h"

//Linker file constants
extern uint32_t _sfixed;
extern uint32_t _efixed;
extern uint32_t _etext;
extern uint32_t _srelocate;
extern uint32_t _erelocate;
extern uint32_t _szero;
extern uint32_t _ezero;
extern uint32_t _sstack;
extern uint32_t _estack;

//Function declaration
void SystemInit(void);
void __libc_init_array(void);
int main(void);

//Default empty handler
void Default_Handler(void);

//Cortex-M4 core handlers
void Reset_Handler            (void);
void NonMaskableInt_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void MemoryManagement_Handler (void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler         (void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler           (void) __attribute__((weak, alias("Default_Handler")));
void DebugMonitor_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler           (void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler          (void) __attribute__((weak, alias("Default_Handler")));

//Peripheral handlers
void SUPC_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void RSTC_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void RTC_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void RTT_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void WDT_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void PMC_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void EFC_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void FLEXCOM7_Handler         (void) __attribute__((weak, alias("Default_Handler")));
void FLEXCOM0_Handler         (void) __attribute__((weak, alias("Default_Handler")));
void FLEXCOM1_Handler         (void) __attribute__((weak, alias("Default_Handler")));
void PIOA_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void PIOB_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void PDMIC0_Handler           (void) __attribute__((weak, alias("Default_Handler")));
void FLEXCOM2_Handler         (void) __attribute__((weak, alias("Default_Handler")));
void MEM2MEM_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void I2SC0_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void I2SC1_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void PDMIC1_Handler           (void) __attribute__((weak, alias("Default_Handler")));
void FLEXCOM3_Handler         (void) __attribute__((weak, alias("Default_Handler")));
void FLEXCOM4_Handler         (void) __attribute__((weak, alias("Default_Handler")));
void FLEXCOM5_Handler         (void) __attribute__((weak, alias("Default_Handler")));
void FLEXCOM6_Handler         (void) __attribute__((weak, alias("Default_Handler")));
void TC0_CH0_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC0_CH1_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC0_CH2_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC1_CH0_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC1_CH1_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC1_CH2_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void ADC_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void UHP_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void UDP_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void CRCCU_Handler            (void) __attribute__((weak, alias("Default_Handler")));

//Vector table
__attribute__((section(".vectors")))
const uint32_t vectorTable[66] =
{
   //Initial stack pointer
   (uint32_t) (&_estack),

   //Core handlers
   (uint32_t) Reset_Handler,
   (uint32_t) NonMaskableInt_Handler,
   (uint32_t) HardFault_Handler,
   (uint32_t) MemoryManagement_Handler,
   (uint32_t) BusFault_Handler,
   (uint32_t) UsageFault_Handler,
   (uint32_t) 0,
   (uint32_t) 0,
   (uint32_t) 0,
   (uint32_t) 0,
   (uint32_t) SVCall_Handler,
   (uint32_t) DebugMonitor_Handler,
   (uint32_t) 0,
   (uint32_t) PendSV_Handler,
   (uint32_t) SysTick_Handler,

   //Peripheral handlers
   (uint32_t) SUPC_Handler,     // 0  Supply Controller
   (uint32_t) RSTC_Handler,     // 1  Reset Controller
   (uint32_t) RTC_Handler,      // 2  Real-time Clock
   (uint32_t) RTT_Handler,      // 3  Real-time Timer
   (uint32_t) WDT_Handler,      // 4  Watchdog Timer
   (uint32_t) PMC_Handler,      // 5  Power Management Controller
   (uint32_t) EFC_Handler,      // 6  Embedded Flash Controller
   (uint32_t) FLEXCOM7_Handler, // 7  Flexible Serial Communication
   (uint32_t) FLEXCOM0_Handler, // 8  Flexible Serial Communication
   (uint32_t) FLEXCOM1_Handler, // 9  Flexible Serial Communication
   (uint32_t) 0,                // 10 Reserved
   (uint32_t) PIOA_Handler,     // 11 Parallel Input/Output Controller
   (uint32_t) PIOB_Handler,     // 12 Parallel Input/Output Controller
   (uint32_t) PDMIC0_Handler,   // 13 Pulse Density Modulation Interface Controller
   (uint32_t) FLEXCOM2_Handler, // 14 Flexible Serial Communication
   (uint32_t) MEM2MEM_Handler,  // 15 Memory to Memory
   (uint32_t) I2SC0_Handler,    // 16 Inter-IC Sound Controller
   (uint32_t) I2SC1_Handler,    // 17 Inter-IC Sound Controller
   (uint32_t) PDMIC1_Handler,   // 18 Pulse Density Modulation Interface Controller
   (uint32_t) FLEXCOM3_Handler, // 19 Flexible Serial Communication
   (uint32_t) FLEXCOM4_Handler, // 20 Flexible Serial Communication
   (uint32_t) FLEXCOM5_Handler, // 21 Flexible Serial Communication
   (uint32_t) FLEXCOM6_Handler, // 22 Flexible Serial Communication
   (uint32_t) TC0_CH0_Handler,  // 23 Timer/Counter 0 Channel 0
   (uint32_t) TC0_CH1_Handler,  // 24 Timer/Counter 0 Channel 1
   (uint32_t) TC0_CH2_Handler,  // 25 Timer/Counter 0 Channel 2
   (uint32_t) TC1_CH0_Handler,  // 26 Timer/Counter 1 Channel 0
   (uint32_t) TC1_CH1_Handler,  // 27 Timer/Counter 1 Channel 1
   (uint32_t) TC1_CH2_Handler,  // 28 Timer/Counter 1 Channel 2
   (uint32_t) ADC_Handler,      // 29 Analog-to-Digital Converter
   (uint32_t) 0,                // 30 Reserved
   (uint32_t) 0,                // 31 Reserved
   (uint32_t) 0,                // 32 Reserved
   (uint32_t) 0,                // 33 Reserved
   (uint32_t) 0,                // 34 Reserved
   (uint32_t) 0,                // 35 Reserved
   (uint32_t) 0,                // 36 Reserved
   (uint32_t) 0,                // 37 Reserved
   (uint32_t) 0,                // 38 Reserved
   (uint32_t) 0,                // 39 Reserved
   (uint32_t) 0,                // 40 Reserved
   (uint32_t) 0,                // 41 Reserved
   (uint32_t) 0,                // 42 Reserved
   (uint32_t) 0,                // 43 Reserved
   (uint32_t) 0,                // 44 Reserved
   (uint32_t) 0,                // 45 Reserved
   (uint32_t) 0,                // 46 Reserved
   (uint32_t) UHP_Handler,      // 47 USB Host Port
   (uint32_t) UDP_Handler,      // 48 USB Device Port
   (uint32_t) CRCCU_Handler     // 49 Cyclic Redundancy Check Calculation Unit
};


/**
 * @brief Reset handler
 **/

void Reset_Handler(void)
{
   uint32_t *src;
   uint32_t *dest;

   //System initialization
   SystemInit();

   //Initialize the relocate segment
   src = &_etext;
   dest = &_srelocate;

   if(src != dest)
   {
      while(dest < &_erelocate)
	  {
         *dest++ = *src++;
      }
   }

   //Clear the zero segment
   for(dest = &_szero; dest < &_ezero;)
   {
      *dest++ = 0;
   }

   //Set the vector table base address
   src = (uint32_t *) & _sfixed;
   SCB->VTOR = ((uint32_t) src & SCB_VTOR_TBLOFF_Msk);

   //C library initialization
   __libc_init_array();

   //Branch to main function
   main();

   //Endless loop
   while(1);
}


/**
 * @brief Default interrupt handler
 **/

void Default_Handler(void)
{
   while(1)
   {
   }
}

//Dependencies
#include "samd21.h"

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
void Reset_Handler      (void);
void NMI_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler  (void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler (void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler   (void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler     (void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler    (void) __attribute__((weak, alias("Default_Handler")));

//Peripheral handlers
void PM_Handler         (void) __attribute__((weak, alias("Default_Handler")));
void SYSCTRL_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void WDT_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void RTC_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void EIC_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void NVMCTRL_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void DMAC_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void USB_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void EVSYS_Handler      (void) __attribute__((weak, alias("Default_Handler")));
void SERCOM0_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void SERCOM1_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void SERCOM2_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void SERCOM3_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void SERCOM4_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void SERCOM5_Handler    (void) __attribute__((weak, alias("Default_Handler")));
void TCC0_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void TCC1_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void TCC2_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void TC3_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void TC4_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void TC5_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void TC6_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void TC7_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void ADC_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void AC_Handler         (void) __attribute__((weak, alias("Default_Handler")));
void DAC_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void PTC_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void I2S_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void AC1_Handler        (void) __attribute__((weak, alias("Default_Handler")));

//Vector table
__attribute__((section(".vectors")))
const uint32_t vectorTable[45] =
{
   //Initial stack pointer
   (uint32_t) (&_estack),

   //Core handlers
   (uint32_t) Reset_Handler,
   (uint32_t) NMI_Handler,
   (uint32_t) HardFault_Handler,
   (uint32_t) MemManage_Handler,
   (uint32_t) BusFault_Handler,
   (uint32_t) UsageFault_Handler,
   (uint32_t) 0,
   (uint32_t) 0,
   (uint32_t) 0,
   (uint32_t) 0,
   (uint32_t) SVC_Handler,
   (uint32_t) DebugMon_Handler,
   (uint32_t) 0,
   (uint32_t) PendSV_Handler,
   (uint32_t) SysTick_Handler,

   //Peripheral handlers
   (uint32_t) PM_Handler,      //Power Manager
   (uint32_t) SYSCTRL_Handler, //System Control
   (uint32_t) WDT_Handler,     //Watchdog Timer
   (uint32_t) RTC_Handler,     //Real-Time Counter
   (uint32_t) EIC_Handler,     //External Interrupt Controller
   (uint32_t) NVMCTRL_Handler, //Non-Volatile Memory Controller
   (uint32_t) DMAC_Handler,    //Direct Memory Access Controller
   (uint32_t) USB_Handler,     //Universal Serial Bus
   (uint32_t) EVSYS_Handler,   //Event System Interface
   (uint32_t) SERCOM0_Handler, //Serial Communication Interface 0
   (uint32_t) SERCOM1_Handler, //Serial Communication Interface 1
   (uint32_t) SERCOM2_Handler, //Serial Communication Interface 2
   (uint32_t) SERCOM3_Handler, //Serial Communication Interface 3
   (uint32_t) SERCOM4_Handler, //Serial Communication Interface 4
   (uint32_t) SERCOM5_Handler, //Serial Communication Interface 5
   (uint32_t) TCC0_Handler,    //Timer Counter Control 0
   (uint32_t) TCC1_Handler,    //Timer Counter Control 1
   (uint32_t) TCC2_Handler,    //Timer Counter Control 2
   (uint32_t) TC3_Handler,     //Basic Timer Counter 0
   (uint32_t) TC4_Handler,     //Basic Timer Counter 1
   (uint32_t) TC5_Handler,     //Basic Timer Counter 2
   (uint32_t) TC6_Handler,     //Basic Timer Counter 3
   (uint32_t) TC7_Handler,     //Basic Timer Counter 4
   (uint32_t) ADC_Handler,     //Analog Digital Converter
   (uint32_t) AC_Handler,      //Analog Comparators
   (uint32_t) DAC_Handler,     //Digital Analog Converter
   (uint32_t) PTC_Handler,     //Peripheral Touch Controller
   (uint32_t) I2S_Handler,     //Inter-IC Sound Interface
   (uint32_t) AC1_Handler      //Analog Comparators 1
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

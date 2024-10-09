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

//Cortex-M7 core handlers
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
void UART0_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void UART1_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void PIOA_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void PIOB_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void PIOC_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void USART0_Handler           (void) __attribute__((weak, alias("Default_Handler")));
void USART1_Handler           (void) __attribute__((weak, alias("Default_Handler")));
void USART2_Handler           (void) __attribute__((weak, alias("Default_Handler")));
void PIOD_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void PIOE_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void HSMCI_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void TWIHS0_Handler           (void) __attribute__((weak, alias("Default_Handler")));
void TWIHS1_Handler           (void) __attribute__((weak, alias("Default_Handler")));
void SPI0_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void SSC_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void TC0_CH0_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC0_CH1_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC0_CH2_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC1_CH0_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC1_CH1_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC1_CH2_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void AFEC0_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void DACC_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void PWM0_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void ICM_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void ACC_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void USBHS_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void MCAN0_INT0_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void MCAN0_INT1_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void MCAN1_INT0_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void MCAN1_INT1_Handler       (void) __attribute__((weak, alias("Default_Handler")));
void GMAC_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void AFEC1_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void TWIHS2_Handler           (void) __attribute__((weak, alias("Default_Handler")));
void SPI1_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void QSPI_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void UART2_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void UART3_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void UART4_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void TC2_CH0_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC2_CH1_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC2_CH2_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC3_CH0_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC3_CH1_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void TC3_CH2_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void MLB_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void AES_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void TRNG_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void XDMAC_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void ISI_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void PWM1_Handler             (void) __attribute__((weak, alias("Default_Handler")));
void FPU_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void RSWDT_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void CCW_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void CCF_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void GMAC_Q1_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void GMAC_Q2_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void IXC_Handler              (void) __attribute__((weak, alias("Default_Handler")));
void I2SC0_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void I2SC1_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void GMAC_Q3_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void GMAC_Q4_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void GMAC_Q5_Handler          (void) __attribute__((weak, alias("Default_Handler")));

//Vector table
__attribute__((section(".vectors")))
const uint32_t vectorTable[90] =
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
   (uint32_t) SUPC_Handler,       // 0  Supply Controller
   (uint32_t) RSTC_Handler,       // 1  Reset Controller
   (uint32_t) RTC_Handler,        // 2  Real-time Clock
   (uint32_t) RTT_Handler,        // 3  Real-time Timer
   (uint32_t) WDT_Handler,        // 4  Watchdog Timer
   (uint32_t) PMC_Handler,        // 5  Power Management Controller
   (uint32_t) EFC_Handler,        // 6  Embedded Flash Controller
   (uint32_t) UART0_Handler,      // 7  Universal Asynchronous Receiver Transmitter
   (uint32_t) UART1_Handler,      // 8  Universal Asynchronous Receiver Transmitter
   (uint32_t) (0UL),              // 9  Reserved
   (uint32_t) PIOA_Handler,       // 10 Parallel Input/Output Controller
   (uint32_t) PIOB_Handler,       // 11 Parallel Input/Output Controller
   (uint32_t) PIOC_Handler,       // 12 Parallel Input/Output Controller
   (uint32_t) USART0_Handler,     // 13 Universal Synchronous Asynchronous Receiver Transmitter
   (uint32_t) USART1_Handler,     // 14 Universal Synchronous Asynchronous Receiver Transmitter
   (uint32_t) USART2_Handler,     // 15 Universal Synchronous Asynchronous Receiver Transmitter
   (uint32_t) PIOD_Handler,       // 16 Parallel Input/Output Controller
   (uint32_t) PIOE_Handler,       // 17 Parallel Input/Output Controller
   (uint32_t) HSMCI_Handler,      // 18 High Speed MultiMedia Card Interface
   (uint32_t) TWIHS0_Handler,     // 19 Two-wire Interface High Speed
   (uint32_t) TWIHS1_Handler,     // 20 Two-wire Interface High Speed
   (uint32_t) SPI0_Handler,       // 21 Serial Peripheral Interface
   (uint32_t) SSC_Handler,        // 22 Synchronous Serial Controller
   (uint32_t) TC0_CH0_Handler,    // 23 Timer/Counter 0 Channel 0
   (uint32_t) TC0_CH1_Handler,    // 24 Timer/Counter 0 Channel 1
   (uint32_t) TC0_CH2_Handler,    // 25 Timer/Counter 0 Channel 2
   (uint32_t) TC1_CH0_Handler,    // 26 Timer/Counter 1 Channel 0
   (uint32_t) TC1_CH1_Handler,    // 27 Timer/Counter 1 Channel 1
   (uint32_t) TC1_CH2_Handler,    // 28 Timer/Counter 1 Channel 2
   (uint32_t) AFEC0_Handler,      // 29 Analog Front-End Controller
   (uint32_t) DACC_Handler,       // 30 Digital-to-Analog Converter Controller
   (uint32_t) PWM0_Handler,       // 31 Pulse Width Modulation Controller
   (uint32_t) ICM_Handler,        // 32 Integrity Check Monitor
   (uint32_t) ACC_Handler,        // 33 Analog Comparator Controller
   (uint32_t) USBHS_Handler,      // 34 USB High-Speed Interface
   (uint32_t) MCAN0_INT0_Handler, // 35 Controller Area Network
   (uint32_t) MCAN0_INT1_Handler, // 36 Controller Area Network
   (uint32_t) MCAN1_INT0_Handler, // 37 Controller Area Network
   (uint32_t) MCAN1_INT1_Handler, // 38 Controller Area Network
   (uint32_t) GMAC_Handler,       // 39 Gigabit Ethernet MAC
   (uint32_t) AFEC1_Handler,      // 40 Analog Front-End Controller
   (uint32_t) TWIHS2_Handler,     // 41 Two-wire Interface High Speed
   (uint32_t) SPI1_Handler,       // 42 Serial Peripheral Interface
   (uint32_t) QSPI_Handler,       // 43 Quad Serial Peripheral Interface
   (uint32_t) UART2_Handler,      // 44 Universal Asynchronous Receiver Transmitter
   (uint32_t) UART3_Handler,      // 45 Universal Asynchronous Receiver Transmitter
   (uint32_t) UART4_Handler,      // 46 Universal Asynchronous Receiver Transmitter
   (uint32_t) TC2_CH0_Handler,    // 47 Timer/Counter 2 Channel 0
   (uint32_t) TC2_CH1_Handler,    // 48 Timer/Counter 2 Channel 1
   (uint32_t) TC2_CH2_Handler,    // 49 Timer/Counter 2 Channel 2
   (uint32_t) TC3_CH0_Handler,    // 50 Timer/Counter 3 Channel 0
   (uint32_t) TC3_CH1_Handler,    // 51 Timer/Counter 3 Channel 1
   (uint32_t) TC3_CH2_Handler,    // 52 Timer/Counter 3 Channel 2
   (uint32_t) MLB_Handler,        // 53 MediaLB
   (uint32_t) (0UL),              // 54 Reserved
   (uint32_t) (0UL),              // 55 Reserved
   (uint32_t) AES_Handler,        // 56 Advanced Encryption Standard
   (uint32_t) TRNG_Handler,       // 57 True Random Number Generator
   (uint32_t) XDMAC_Handler,      // 58 Extensible DMA Controller
   (uint32_t) ISI_Handler,        // 59 Image Sensor Interface
   (uint32_t) PWM1_Handler,       // 60 Pulse Width Modulation Controller
   (uint32_t) FPU_Handler,        // 61 Floating Point Unit
   (uint32_t) 0,                  // 62 Reserved
   (uint32_t) RSWDT_Handler,      // 63 Reinforced Safety Watchdog Timer
   (uint32_t) CCW_Handler,        // 64 System Control Block
   (uint32_t) CCF_Handler,        // 65 System Control Block
   (uint32_t) GMAC_Q1_Handler,    // 66 Gigabit Ethernet MAC
   (uint32_t) GMAC_Q2_Handler,    // 67 Gigabit Ethernet MAC
   (uint32_t) IXC_Handler,        // 68 Floating Point Unit
   (uint32_t) I2SC0_Handler,      // 69 Inter-IC Sound Controller
   (uint32_t) I2SC1_Handler,      // 70 Inter-IC Sound Controller
   (uint32_t) GMAC_Q3_Handler,    // 71 Gigabit Ethernet MAC
   (uint32_t) GMAC_Q4_Handler,    // 72 Gigabit Ethernet MAC
   (uint32_t) GMAC_Q5_Handler     // 73 Gigabit Ethernet MAC
};


/**
 * @brief Enable TCM memory
 **/

__STATIC_INLINE void TCM_Enable(void) 
{
   __DSB();
   __ISB();
   SCB->ITCMCR = (SCB_ITCMCR_EN_Msk | SCB_ITCMCR_RMW_Msk | SCB_ITCMCR_RETEN_Msk);
   SCB->DTCMCR = (SCB_DTCMCR_EN_Msk | SCB_DTCMCR_RMW_Msk | SCB_DTCMCR_RETEN_Msk);
   __DSB();
   __ISB();
}


/**
 * @brief Disable TCM memory
 **/

__STATIC_INLINE void TCM_Disable(void) 
{
   __DSB();
   __ISB();
   SCB->ITCMCR &= ~((uint32_t) SCB_ITCMCR_EN_Msk);
   SCB->DTCMCR &= ~((uint32_t) SCB_ITCMCR_EN_Msk);
   __DSB();
   __ISB();
}


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

#ifdef ENABLE_TCM 
   //32KB
   EFC_REGS->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(8));
   EFC_REGS->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_SGPB | EEFC_FCR_FARG(7));

   TCM_Enable();
#else
   EFC_REGS->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(8));
   EFC_REGS->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(7));

   TCM_Disable();
#endif

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

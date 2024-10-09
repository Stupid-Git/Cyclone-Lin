;
; The modules in this file are included in the libraries, and may be replaced
; by any user-defined modules that define the PUBLIC symbol _program_start or
; a user defined start symbol.
; To override the cstartup defined in the library, simply add your modified
; version to the workbench project.
;
; The vector table is normally located at address 0.
; When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
; The name "__vector_table" has special meaning for C-SPY:
; it is where the SP start value is found, and the NVIC vector
; table register (VTOR) is initialized to this address if != 0.
;
; Cortex-M version
;

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table

        DATA
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler             ; Reset Handler

        DCD     NMI_Handler               ; NMI Handler
        DCD     HardFault_Handler         ; Hard Fault Handler
        DCD     MemManage_Handler         ; MPU Fault Handler
        DCD     BusFault_Handler          ; Bus Fault Handler
        DCD     UsageFault_Handler        ; Usage Fault Handler
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     SVC_Handler               ; SVCall Handler
        DCD     DebugMon_Handler          ; Debug Monitor Handler
        DCD     0                         ; Reserved
        DCD     PendSV_Handler            ; PendSV Handler
        DCD     SysTick_Handler           ; SysTick Handler

        ; External Interrupts

        DCD     GPIOA_Handler             ;   0: GPIO Port A
        DCD     GPIOB_Handler             ;   1: GPIO Port B
        DCD     GPIOC_Handler             ;   2: GPIO Port C
        DCD     GPIOD_Handler             ;   3: GPIO Port D
        DCD     GPIOE_Handler             ;   4: GPIO Port E
        DCD     UART0_Handler             ;   5: UART0 Rx and Tx
        DCD     UART1_Handler             ;   6: UART1 Rx and Tx
        DCD     SSI0_Handler              ;   7: SSI0 Rx and Tx
        DCD     I2C0_Handler              ;   8: I2C0 Master and Slave
        DCD     PMW0_FAULT_Handler        ;   9: PWM Fault
        DCD     PWM0_0_Handler            ;  10: PWM Generator 0
        DCD     PWM0_1_Handler            ;  11: PWM Generator 1
        DCD     PWM0_2_Handler            ;  12: PWM Generator 2
        DCD     QEI0_Handler              ;  13: Quadrature Encoder 0
        DCD     ADC0SS0_Handler           ;  14: ADC Sequence 0
        DCD     ADC0SS1_Handler           ;  15: ADC Sequence 1
        DCD     ADC0SS2_Handler           ;  16: ADC Sequence 2
        DCD     ADC0SS3_Handler           ;  17: ADC Sequence 3
        DCD     WDT0_Handler              ;  18: Watchdog timer
        DCD     TIMER0A_Handler           ;  19: Timer 0 subtimer A
        DCD     TIMER0B_Handler           ;  20: Timer 0 subtimer B
        DCD     TIMER1A_Handler           ;  21: Timer 1 subtimer A
        DCD     TIMER1B_Handler           ;  22: Timer 1 subtimer B
        DCD     TIMER2A_Handler           ;  23: Timer 2 subtimer A
        DCD     TIMER2B_Handler           ;  24: Timer 2 subtimer B
        DCD     COMP0_Handler             ;  25: Analog Comparator 0
        DCD     COMP1_Handler             ;  26: Analog Comparator 1
        DCD     COMP2_Handler             ;  27: Analog Comparator 2
        DCD     SYSCTL_Handler            ;  28: System Control (PLL, OSC, BO)
        DCD     FLASH_Handler             ;  29: FLASH Control
        DCD     GPIOF_Handler             ;  30: GPIO Port F
        DCD     GPIOG_Handler             ;  31: GPIO Port G
        DCD     GPIOH_Handler             ;  32: GPIO Port H
        DCD     UART2_Handler             ;  33: UART2 Rx and Tx
        DCD     SSI1_Handler              ;  34: SSI1 Rx and Tx
        DCD     TIMER3A_Handler           ;  35: Timer 3 subtimer A
        DCD     TIMER3B_Handler           ;  36: Timer 3 subtimer B
        DCD     I2C1_Handler              ;  37: I2C1 Master and Slave                    
        DCD     CAN0_Handler              ;  38: CAN0
        DCD     CAN1_Handler              ;  39: CAN1
        DCD     EMAC0_Handler             ;  40: EMAC0
        DCD     HIB_Handler               ;  41: Hibernate
        DCD     USB0_Handler              ;  42: USB0
        DCD     PWM0_3_Handler            ;  43: PWM Generator 3
        DCD     UDMA_Handler              ;  44: uDMA Software Transfer
        DCD     UDMAERR_Handler           ;  45: uDMA Error
        DCD     ADC1SS0_Handler           ;  46: ADC1 Sequence 0
        DCD     ADC1SS1_Handler           ;  47: ADC1 Sequence 1
        DCD     ADC1SS2_Handler           ;  48: ADC1 Sequence 2
        DCD     ADC1SS3_Handler           ;  49: ADC1 Sequence 3
        DCD     EBI0_Handler              ;  50: External Bus Interface 0
        DCD     GPIOJ_Handler             ;  51: GPIO Port J
        DCD     GPIOK_Handler             ;  52: GPIO Port K
        DCD     GPIOL_Handler             ;  53: GPIO Port L
        DCD     SSI2_Handler              ;  54: SSI2 Rx and Tx
        DCD     SSI3_Handler              ;  55: SSI3 Rx and Tx
        DCD     UART3_Handler             ;  56: UART3 Rx and Tx
        DCD     UART4_Handler             ;  57: UART4 Rx and Tx
        DCD     UART5_Handler             ;  58: UART5 Rx and Tx
        DCD     UART6_Handler             ;  59: UART6 Rx and Tx
        DCD     UART7_Handler             ;  60: UART7 Rx and Tx
        DCD     I2C2_Handler              ;  61: I2C2 Master and Slave
        DCD     I2C3_Handler              ;  62: I2C3 Master and Slave
        DCD     TIMER4A_Handler           ;  63: Timer 4 subtimer A
        DCD     TIMER4B_Handler           ;  64: Timer 4 subtimer B
        DCD     TIMER5A_Handler           ;  65: Timer 5 subtimer A
        DCD     TIMER5B_Handler           ;  66: Timer 5 subtimer B
        DCD     FPU_Handler               ;  67: FPU
        DCD     0                         ;  68: Reserved
        DCD     0                         ;  69: Reserved
        DCD     I2C4_Handler              ;  70: I2C4 Master and Slave
        DCD     I2C5_Handler              ;  71: I2C5 Master and Slave
        DCD     GPIOM_Handler             ;  72: GPIO Port M
        DCD     GPION_Handler             ;  73: GPIO Port N
        DCD     0                         ;  74: Reserved
        DCD     TAMPER_Handler            ;  75: Tamper
        DCD     GPIOP0_Handler            ;  76: GPIO Port P (Summary or P0)
        DCD     GPIOP1_Handler            ;  77: GPIO Port P1
        DCD     GPIOP2_Handler            ;  78: GPIO Port P2
        DCD     GPIOP3_Handler            ;  79: GPIO Port P3
        DCD     GPIOP4_Handler            ;  80: GPIO Port P4
        DCD     GPIOP5_Handler            ;  81: GPIO Port P5
        DCD     GPIOP6_Handler            ;  82: GPIO Port P6
        DCD     GPIOP7_Handler            ;  83: GPIO Port P7
        DCD     GPIOQ0_Handler            ;  84: GPIO Port Q (Summary or Q0)
        DCD     GPIOQ1_Handler            ;  85: GPIO Port Q1
        DCD     GPIOQ2_Handler            ;  86: GPIO Port Q2
        DCD     GPIOQ3_Handler            ;  87: GPIO Port Q3
        DCD     GPIOQ4_Handler            ;  88: GPIO Port Q4
        DCD     GPIOQ5_Handler            ;  89: GPIO Port Q5
        DCD     GPIOQ6_Handler            ;  90: GPIO Port Q6
        DCD     GPIOQ7_Handler            ;  91: GPIO Port Q7
        DCD     GPIOR_Handler             ;  92: GPIO Port R
        DCD     GPIOS_Handler             ;  93: GPIO Port S
        DCD     SHAMD5_Handler            ;  94: SHA/MD5 0
        DCD     AES_Handler               ;  95: AES 0
        DCD     DES3DES_Handler           ;  96: DES3DES 0
        DCD     LCDCONTROLLER_Handler     ;  97: LCD Controller 0
        DCD     TIMER6A_Handler           ;  98: Timer 6 subtimer A
        DCD     TIMER6B_Handler           ;  99: Timer 6 subtimer B
        DCD     TIMER7A_Handler           ; 100: Timer 7 subtimer A
        DCD     TIMER7B_Handler           ; 101: Timer 7 subtimer B
        DCD     I2C6_Handler              ; 102: I2C6 Master and Slave
        DCD     I2C7_Handler              ; 103: I2C7 Master and Slave
        DCD     HIMSCANKEYBOARD_Handler   ; 104: HIM Scan Matrix Keyboard 0
        DCD     ONEWIRE_Handler           ; 105: One Wire 0
        DCD     HIMPS2_Handler            ; 106: HIM PS/2 0
        DCD     HIMLEDSEQUENCER_Handler   ; 107: HIM LED Sequencer 0
        DCD     HIMCONSUMERIR_Handler     ; 108: HIM Consumer IR 0
        DCD     I2C8_Handler              ; 109: I2C8 Master and Slave
        DCD     I2C9_Handler              ; 110: I2C9 Master and Slave
        DCD     GPIOT_Handler             ; 111: GPIO Port T

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB
        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler

        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0

        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
        B NMI_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
        B HardFault_Handler

        PUBWEAK MemManage_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
MemManage_Handler
        B MemManage_Handler

        PUBWEAK BusFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
BusFault_Handler
        B BusFault_Handler

        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UsageFault_Handler
        B UsageFault_Handler

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
        B SVC_Handler

        PUBWEAK DebugMon_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
DebugMon_Handler
        B DebugMon_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
        B PendSV_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
        B SysTick_Handler

        PUBWEAK GPIOA_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOA_Handler
        B GPIOA_Handler

        PUBWEAK GPIOB_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOB_Handler
        B GPIOB_Handler

        PUBWEAK GPIOC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOC_Handler
        B GPIOC_Handler

        PUBWEAK GPIOD_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOD_Handler
        B GPIOD_Handler

        PUBWEAK GPIOE_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOE_Handler
        B GPIOE_Handler

        PUBWEAK UART0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART0_Handler
        B UART0_Handler

        PUBWEAK UART1_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART1_Handler
        B UART1_Handler

        PUBWEAK SSI0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SSI0_Handler
        B SSI0_Handler

        PUBWEAK I2C0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C0_Handler
        B I2C0_Handler

        PUBWEAK PMW0_FAULT_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PMW0_FAULT_Handler
        B PMW0_FAULT_Handler

        PUBWEAK PWM0_0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PWM0_0_Handler
        B PWM0_0_Handler

        PUBWEAK PWM0_1_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PWM0_1_Handler
        B PWM0_1_Handler

        PUBWEAK PWM0_2_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PWM0_2_Handler
        B PWM0_2_Handler

        PUBWEAK QEI0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
QEI0_Handler
        B QEI0_Handler

        PUBWEAK ADC0SS0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC0SS0_Handler
        B ADC0SS0_Handler

        PUBWEAK ADC0SS1_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC0SS1_Handler
        B ADC0SS1_Handler

        PUBWEAK ADC0SS2_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC0SS2_Handler
        B ADC0SS2_Handler

        PUBWEAK ADC0SS3_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC0SS3_Handler
        B ADC0SS3_Handler

        PUBWEAK WDT0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
WDT0_Handler
        B WDT0_Handler

        PUBWEAK TIMER0A_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER0A_Handler
        B TIMER0A_Handler

        PUBWEAK TIMER0B_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER0B_Handler
        B TIMER0B_Handler

        PUBWEAK TIMER1A_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER1A_Handler
        B TIMER1A_Handler

        PUBWEAK TIMER1B_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER1B_Handler
        B TIMER1B_Handler

        PUBWEAK TIMER2A_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER2A_Handler
        B TIMER2A_Handler

        PUBWEAK TIMER2B_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER2B_Handler
        B TIMER2B_Handler

        PUBWEAK COMP0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
COMP0_Handler
        B COMP0_Handler

        PUBWEAK COMP1_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
COMP1_Handler
        B COMP1_Handler

        PUBWEAK COMP2_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
COMP2_Handler
        B COMP2_Handler

        PUBWEAK SYSCTL_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SYSCTL_Handler
        B SYSCTL_Handler

        PUBWEAK FLASH_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
FLASH_Handler
        B FLASH_Handler

        PUBWEAK GPIOF_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOF_Handler
        B GPIOF_Handler

        PUBWEAK GPIOG_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOG_Handler
        B GPIOG_Handler

        PUBWEAK GPIOH_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOH_Handler
        B GPIOH_Handler

        PUBWEAK UART2_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART2_Handler
        B UART2_Handler

        PUBWEAK SSI1_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SSI1_Handler
        B SSI1_Handler

        PUBWEAK TIMER3A_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER3A_Handler
        B TIMER3A_Handler

        PUBWEAK TIMER3B_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER3B_Handler
        B TIMER3B_Handler

        PUBWEAK I2C1_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C1_Handler
        B I2C1_Handler

        PUBWEAK CAN0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
CAN0_Handler
        B CAN0_Handler

        PUBWEAK CAN1_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
CAN1_Handler
        B CAN1_Handler

        PUBWEAK EMAC0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
EMAC0_Handler
        B EMAC0_Handler

        PUBWEAK HIB_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HIB_Handler
        B HIB_Handler

        PUBWEAK USB0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
USB0_Handler
        B USB0_Handler

        PUBWEAK PWM0_3_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PWM0_3_Handler
        B PWM0_3_Handler

        PUBWEAK UDMA_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UDMA_Handler
        B UDMA_Handler

        PUBWEAK UDMAERR_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UDMAERR_Handler
        B UDMAERR_Handler

        PUBWEAK ADC1SS0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC1SS0_Handler
        B ADC1SS0_Handler

        PUBWEAK ADC1SS1_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC1SS1_Handler
        B ADC1SS1_Handler

        PUBWEAK ADC1SS2_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC1SS2_Handler
        B ADC1SS2_Handler

        PUBWEAK ADC1SS3_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC1SS3_Handler
        B ADC1SS3_Handler

        PUBWEAK EBI0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
EBI0_Handler
        B EBI0_Handler

        PUBWEAK GPIOJ_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOJ_Handler
        B GPIOJ_Handler

        PUBWEAK GPIOK_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOK_Handler
        B GPIOK_Handler

        PUBWEAK GPIOL_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOL_Handler
        B GPIOL_Handler

        PUBWEAK SSI2_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SSI2_Handler
        B SSI2_Handler

        PUBWEAK SSI3_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SSI3_Handler
        B SSI3_Handler

        PUBWEAK UART3_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART3_Handler
        B UART3_Handler

        PUBWEAK UART4_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART4_Handler
        B UART4_Handler

        PUBWEAK UART5_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART5_Handler
        B UART5_Handler

        PUBWEAK UART6_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART6_Handler
        B UART6_Handler

        PUBWEAK UART7_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART7_Handler
        B UART7_Handler

        PUBWEAK I2C2_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C2_Handler
        B I2C2_Handler

        PUBWEAK I2C3_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C3_Handler
        B I2C3_Handler

        PUBWEAK TIMER4A_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER4A_Handler
        B TIMER4A_Handler

        PUBWEAK TIMER4B_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER4B_Handler
        B TIMER4B_Handler

        PUBWEAK TIMER5A_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER5A_Handler
        B TIMER5A_Handler

        PUBWEAK TIMER5B_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER5B_Handler
        B TIMER5B_Handler

        PUBWEAK FPU_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
FPU_Handler
        B FPU_Handler

        PUBWEAK I2C4_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C4_Handler
        B I2C4_Handler

        PUBWEAK I2C5_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C5_Handler
        B I2C5_Handler

        PUBWEAK GPIOM_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOM_Handler
        B GPIOM_Handler

        PUBWEAK GPION_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPION_Handler
        B GPION_Handler

        PUBWEAK TAMPER_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TAMPER_Handler
        B TAMPER_Handler

        PUBWEAK GPIOP0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOP0_Handler
        B GPIOP0_Handler

        PUBWEAK GPIOP1_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOP1_Handler
        B GPIOP1_Handler

        PUBWEAK GPIOP2_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOP2_Handler
        B GPIOP2_Handler

        PUBWEAK GPIOP3_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOP3_Handler
        B GPIOP3_Handler

        PUBWEAK GPIOP4_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOP4_Handler
        B GPIOP4_Handler

        PUBWEAK GPIOP5_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOP5_Handler
        B GPIOP5_Handler

        PUBWEAK GPIOP6_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOP6_Handler
        B GPIOP6_Handler

        PUBWEAK GPIOP7_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOP7_Handler
        B GPIOP7_Handler

        PUBWEAK GPIOQ0_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOQ0_Handler
        B GPIOQ0_Handler

        PUBWEAK GPIOQ1_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOQ1_Handler
        B GPIOQ1_Handler

        PUBWEAK GPIOQ2_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOQ2_Handler
        B GPIOQ2_Handler

        PUBWEAK GPIOQ3_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOQ3_Handler
        B GPIOQ3_Handler

        PUBWEAK GPIOQ4_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOQ4_Handler
        B GPIOQ4_Handler

        PUBWEAK GPIOQ5_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOQ5_Handler
        B GPIOQ5_Handler

        PUBWEAK GPIOQ6_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOQ6_Handler
        B GPIOQ6_Handler

        PUBWEAK GPIOQ7_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOQ7_Handler
        B GPIOQ7_Handler

        PUBWEAK GPIOR_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOR_Handler
        B GPIOR_Handler

        PUBWEAK GPIOS_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOS_Handler
        B GPIOS_Handler

        PUBWEAK SHAMD5_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SHAMD5_Handler
        B SHAMD5_Handler

        PUBWEAK AES_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
AES_Handler
        B AES_Handler

        PUBWEAK DES3DES_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
DES3DES_Handler
        B DES3DES_Handler

        PUBWEAK LCDCONTROLLER_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
LCDCONTROLLER_Handler
        B LCDCONTROLLER_Handler

        PUBWEAK TIMER6A_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER6A_Handler
        B TIMER6A_Handler

        PUBWEAK TIMER6B_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER6B_Handler
        B TIMER6B_Handler

        PUBWEAK TIMER7A_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER7A_Handler
        B TIMER7A_Handler

        PUBWEAK TIMER7B_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIMER7B_Handler
        B TIMER7B_Handler

        PUBWEAK I2C6_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C6_Handler
        B I2C6_Handler

        PUBWEAK I2C7_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C7_Handler
        B I2C7_Handler

        PUBWEAK HIMSCANKEYBOARD_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HIMSCANKEYBOARD_Handler
        B HIMSCANKEYBOARD_Handler

        PUBWEAK ONEWIRE_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
ONEWIRE_Handler
        B ONEWIRE_Handler

        PUBWEAK HIMPS2_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HIMPS2_Handler
        B HIMPS2_Handler

        PUBWEAK HIMLEDSEQUENCER_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HIMLEDSEQUENCER_Handler
        B HIMLEDSEQUENCER_Handler

        PUBWEAK HIMCONSUMERIR_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HIMCONSUMERIR_Handler
        B HIMCONSUMERIR_Handler

        PUBWEAK I2C8_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C8_Handler
        B I2C8_Handler

        PUBWEAK I2C9_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C9_Handler
        B I2C9_Handler

        PUBWEAK GPIOT_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
GPIOT_Handler
        B GPIOT_Handler

        END

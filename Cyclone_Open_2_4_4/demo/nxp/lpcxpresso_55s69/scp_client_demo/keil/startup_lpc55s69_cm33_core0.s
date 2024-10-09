; * -------------------------------------------------------------------------
; *  @file:    startup_LPC55S69_cm33_core0.s
; *  @purpose: CMSIS Cortex-M33 Core Device Startup File for the LPC55S69_cm33_core0
; *  @version: 1.1
; *  @date:    2019-5-16
; * -------------------------------------------------------------------------
; *
; * Copyright 1997-2016 Freescale Semiconductor, Inc.
; * Copyright 2016-2021 NXP
; *
; * SPDX-License-Identifier: BSD-3-Clause
; *
; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------
; *
; *****************************************************************************/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

;Heap_Size       EQU     0x400

;                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
;__heap_base
;Heap_Mem        SPACE   Heap_Size
;__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp                        ;Top of Stack
                DCD     Reset_Handler                       ;Reset Handler
                DCD     NMI_Handler                         ;NMI Handler
                DCD     HardFault_Handler                   ;Hard Fault Handler
                DCD     MemManage_Handler                   ;MPU Fault Handler
                DCD     BusFault_Handler                    ;Bus Fault Handler
                DCD     UsageFault_Handler                  ;Usage Fault Handler
                DCD     0                                   ;Reserved
                DCD     0                                   ;Reserved
                DCD     0                                   ;Reserved
                DCD     0                                   ;Reserved
                DCD     SVC_Handler                         ;SVCall Handler
                DCD     DebugMon_Handler                    ;Debug Monitor Handler
                DCD     0                                   ;Reserved
                DCD     PendSV_Handler                      ;PendSV Handler
                DCD     SysTick_Handler                     ;SysTick Handler

                                                            ;External Interrupts
                DCD     WDT_BOD_IRQHandler                  ;Windowed watchdog timer, Brownout detect, Flash interrupt
                DCD     DMA0_IRQHandler                     ;DMA0 controller
                DCD     GINT0_IRQHandler                    ;GPIO group 0
                DCD     GINT1_IRQHandler                    ;GPIO group 1
                DCD     PIN_INT0_IRQHandler                 ;Pin interrupt 0 or pattern match engine slice 0
                DCD     PIN_INT1_IRQHandler                 ;Pin interrupt 1or pattern match engine slice 1
                DCD     PIN_INT2_IRQHandler                 ;Pin interrupt 2 or pattern match engine slice 2
                DCD     PIN_INT3_IRQHandler                 ;Pin interrupt 3 or pattern match engine slice 3
                DCD     UTICK0_IRQHandler                   ;Micro-tick Timer
                DCD     MRT0_IRQHandler                     ;Multi-rate timer
                DCD     CTIMER0_IRQHandler                  ;Standard counter/timer CTIMER0
                DCD     CTIMER1_IRQHandler                  ;Standard counter/timer CTIMER1
                DCD     SCT0_IRQHandler                     ;SCTimer/PWM
                DCD     CTIMER3_IRQHandler                  ;Standard counter/timer CTIMER3
                DCD     FLEXCOMM0_IRQHandler                ;Flexcomm Interface 0 (USART, SPI, I2C, I2S, FLEXCOMM)
                DCD     FLEXCOMM1_IRQHandler                ;Flexcomm Interface 1 (USART, SPI, I2C, I2S, FLEXCOMM)
                DCD     FLEXCOMM2_IRQHandler                ;Flexcomm Interface 2 (USART, SPI, I2C, I2S, FLEXCOMM)
                DCD     FLEXCOMM3_IRQHandler                ;Flexcomm Interface 3 (USART, SPI, I2C, I2S, FLEXCOMM)
                DCD     FLEXCOMM4_IRQHandler                ;Flexcomm Interface 4 (USART, SPI, I2C, I2S, FLEXCOMM)
                DCD     FLEXCOMM5_IRQHandler                ;Flexcomm Interface 5 (USART, SPI, I2C, I2S, FLEXCOMM)
                DCD     FLEXCOMM6_IRQHandler                ;Flexcomm Interface 6 (USART, SPI, I2C, I2S, FLEXCOMM)
                DCD     FLEXCOMM7_IRQHandler                ;Flexcomm Interface 7 (USART, SPI, I2C, I2S, FLEXCOMM)
                DCD     ADC0_IRQHandler                     ;ADC0 
                DCD     Reserved39_IRQHandler               ;Reserved interrupt
                DCD     ACMP_IRQHandler                     ;ACMP  interrupts
                DCD     Reserved41_IRQHandler               ;Reserved interrupt
                DCD     Reserved42_IRQHandler               ;Reserved interrupt
                DCD     USB0_NEEDCLK_IRQHandler             ;USB Activity Wake-up Interrupt
                DCD     USB0_IRQHandler                     ;USB device
                DCD     RTC_IRQHandler                      ;RTC alarm and wake-up interrupts
                DCD     Reserved46_IRQHandler               ;Reserved interrupt
                DCD     MAILBOX_IRQHandler                  ;WAKEUP,Mailbox interrupt (present on selected devices)
                DCD     PIN_INT4_IRQHandler                 ;Pin interrupt 4 or pattern match engine slice 4 int
                DCD     PIN_INT5_IRQHandler                 ;Pin interrupt 5 or pattern match engine slice 5 int
                DCD     PIN_INT6_IRQHandler                 ;Pin interrupt 6 or pattern match engine slice 6 int
                DCD     PIN_INT7_IRQHandler                 ;Pin interrupt 7 or pattern match engine slice 7 int
                DCD     CTIMER2_IRQHandler                  ;Standard counter/timer CTIMER2
                DCD     CTIMER4_IRQHandler                  ;Standard counter/timer CTIMER4
                DCD     OS_EVENT_IRQHandler                 ;OSEVTIMER0 and OSEVTIMER0_WAKEUP interrupts
                DCD     Reserved55_IRQHandler               ;Reserved interrupt
                DCD     Reserved56_IRQHandler               ;Reserved interrupt
                DCD     Reserved57_IRQHandler               ;Reserved interrupt
                DCD     SDIO_IRQHandler                     ;SD/MMC 
                DCD     Reserved59_IRQHandler               ;Reserved interrupt
                DCD     Reserved60_IRQHandler               ;Reserved interrupt
                DCD     Reserved61_IRQHandler               ;Reserved interrupt
                DCD     USB1_PHY_IRQHandler                 ;USB1_PHY
                DCD     USB1_IRQHandler                     ;USB1 interrupt
                DCD     USB1_NEEDCLK_IRQHandler             ;USB1 activity
                DCD     SEC_HYPERVISOR_CALL_IRQHandler      ;SEC_HYPERVISOR_CALL interrupt
                DCD     SEC_GPIO_INT0_IRQ0_IRQHandler       ;SEC_GPIO_INT0_IRQ0 interrupt
                DCD     SEC_GPIO_INT0_IRQ1_IRQHandler       ;SEC_GPIO_INT0_IRQ1 interrupt
                DCD     PLU_IRQHandler                      ;PLU interrupt
                DCD     SEC_VIO_IRQHandler                  ;SEC_VIO interrupt
                DCD     HASHCRYPT_IRQHandler                ;HASHCRYPT interrupt
                DCD     CASER_IRQHandler                    ;CASPER interrupt
                DCD     PUF_IRQHandler                      ;PUF interrupt
                DCD     PQ_IRQHandler                       ;PQ interrupt
                DCD     DMA1_IRQHandler                     ;DMA1 interrupt
                DCD     FLEXCOMM8_IRQHandler                ;Flexcomm Interface 8 (SPI, FLEXCOMM)
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main

                CPSID   I               ; Mask interrupts
                LDR     R0, =0xE000ED08
                LDR     R1, =__Vectors
                STR     R1, [R0]
                LDR     R2, [R1]
                MSR     MSP, R2
                LDR     R0, =SystemInit
                BLX     R0
                CPSIE   i               ; Unmask interrupts
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)
NMI_Handler\
                PROC
                EXPORT  NMI_Handler                          [WEAK]
                B       .
                ENDP

HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler                    [WEAK]
                B       .
                ENDP

MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler                    [WEAK]
                B       .
                ENDP

BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler                     [WEAK]
                B       .
                ENDP

UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler                   [WEAK]
                B       .
                ENDP
SVC_Handler\
                PROC
                EXPORT  SVC_Handler                          [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler                     [WEAK]
                B       .
                ENDP
PendSV_Handler\
                PROC
                EXPORT  PendSV_Handler                       [WEAK]
                B       .
                ENDP
SysTick_Handler\
                PROC
                EXPORT  SysTick_Handler                      [WEAK]
                B       .
                ENDP
WDT_BOD_IRQHandler\
                PROC
                EXPORT  WDT_BOD_IRQHandler                   [WEAK]
                LDR     R0, =WDT_BOD_DriverIRQHandler
                BX      R0
                ENDP

DMA0_IRQHandler\
                PROC
                EXPORT  DMA0_IRQHandler                      [WEAK]
                LDR     R0, =DMA0_DriverIRQHandler
                BX      R0
                ENDP

GINT0_IRQHandler\
                PROC
                EXPORT  GINT0_IRQHandler                     [WEAK]
                LDR     R0, =GINT0_DriverIRQHandler
                BX      R0
                ENDP

GINT1_IRQHandler\
                PROC
                EXPORT  GINT1_IRQHandler                     [WEAK]
                LDR     R0, =GINT1_DriverIRQHandler
                BX      R0
                ENDP

PIN_INT0_IRQHandler\
                PROC
                EXPORT  PIN_INT0_IRQHandler                  [WEAK]
                LDR     R0, =PIN_INT0_DriverIRQHandler
                BX      R0
                ENDP

PIN_INT1_IRQHandler\
                PROC
                EXPORT  PIN_INT1_IRQHandler                  [WEAK]
                LDR     R0, =PIN_INT1_DriverIRQHandler
                BX      R0
                ENDP

PIN_INT2_IRQHandler\
                PROC
                EXPORT  PIN_INT2_IRQHandler                  [WEAK]
                LDR     R0, =PIN_INT2_DriverIRQHandler
                BX      R0
                ENDP

PIN_INT3_IRQHandler\
                PROC
                EXPORT  PIN_INT3_IRQHandler                  [WEAK]
                LDR     R0, =PIN_INT3_DriverIRQHandler
                BX      R0
                ENDP

UTICK0_IRQHandler\
                PROC
                EXPORT  UTICK0_IRQHandler                    [WEAK]
                LDR     R0, =UTICK0_DriverIRQHandler
                BX      R0
                ENDP

MRT0_IRQHandler\
                PROC
                EXPORT  MRT0_IRQHandler                      [WEAK]
                LDR     R0, =MRT0_DriverIRQHandler
                BX      R0
                ENDP

CTIMER0_IRQHandler\
                PROC
                EXPORT  CTIMER0_IRQHandler                   [WEAK]
                LDR     R0, =CTIMER0_DriverIRQHandler
                BX      R0
                ENDP

CTIMER1_IRQHandler\
                PROC
                EXPORT  CTIMER1_IRQHandler                   [WEAK]
                LDR     R0, =CTIMER1_DriverIRQHandler
                BX      R0
                ENDP

SCT0_IRQHandler\
                PROC
                EXPORT  SCT0_IRQHandler                      [WEAK]
                LDR     R0, =SCT0_DriverIRQHandler
                BX      R0
                ENDP

CTIMER3_IRQHandler\
                PROC
                EXPORT  CTIMER3_IRQHandler                   [WEAK]
                LDR     R0, =CTIMER3_DriverIRQHandler
                BX      R0
                ENDP

FLEXCOMM0_IRQHandler\
                PROC
                EXPORT  FLEXCOMM0_IRQHandler                 [WEAK]
                LDR     R0, =FLEXCOMM0_DriverIRQHandler
                BX      R0
                ENDP

FLEXCOMM1_IRQHandler\
                PROC
                EXPORT  FLEXCOMM1_IRQHandler                 [WEAK]
                LDR     R0, =FLEXCOMM1_DriverIRQHandler
                BX      R0
                ENDP

FLEXCOMM2_IRQHandler\
                PROC
                EXPORT  FLEXCOMM2_IRQHandler                 [WEAK]
                LDR     R0, =FLEXCOMM2_DriverIRQHandler
                BX      R0
                ENDP

FLEXCOMM3_IRQHandler\
                PROC
                EXPORT  FLEXCOMM3_IRQHandler                 [WEAK]
                LDR     R0, =FLEXCOMM3_DriverIRQHandler
                BX      R0
                ENDP

FLEXCOMM4_IRQHandler\
                PROC
                EXPORT  FLEXCOMM4_IRQHandler                 [WEAK]
                LDR     R0, =FLEXCOMM4_DriverIRQHandler
                BX      R0
                ENDP

FLEXCOMM5_IRQHandler\
                PROC
                EXPORT  FLEXCOMM5_IRQHandler                 [WEAK]
                LDR     R0, =FLEXCOMM5_DriverIRQHandler
                BX      R0
                ENDP

FLEXCOMM6_IRQHandler\
                PROC
                EXPORT  FLEXCOMM6_IRQHandler                 [WEAK]
                LDR     R0, =FLEXCOMM6_DriverIRQHandler
                BX      R0
                ENDP

FLEXCOMM7_IRQHandler\
                PROC
                EXPORT  FLEXCOMM7_IRQHandler                 [WEAK]
                LDR     R0, =FLEXCOMM7_DriverIRQHandler
                BX      R0
                ENDP

ADC0_IRQHandler\
                PROC
                EXPORT  ADC0_IRQHandler                      [WEAK]
                LDR     R0, =ADC0_DriverIRQHandler
                BX      R0
                ENDP

ACMP_IRQHandler\
                PROC
                EXPORT  ACMP_IRQHandler                      [WEAK]
                LDR     R0, =ACMP_DriverIRQHandler
                BX      R0
                ENDP

USB0_NEEDCLK_IRQHandler\
                PROC
                EXPORT  USB0_NEEDCLK_IRQHandler              [WEAK]
                LDR     R0, =USB0_NEEDCLK_DriverIRQHandler
                BX      R0
                ENDP

USB0_IRQHandler\
                PROC
                EXPORT  USB0_IRQHandler                      [WEAK]
                LDR     R0, =USB0_DriverIRQHandler
                BX      R0
                ENDP

RTC_IRQHandler\
                PROC
                EXPORT  RTC_IRQHandler                       [WEAK]
                LDR     R0, =RTC_DriverIRQHandler
                BX      R0
                ENDP

MAILBOX_IRQHandler\
                PROC
                EXPORT  MAILBOX_IRQHandler                   [WEAK]
                LDR     R0, =MAILBOX_DriverIRQHandler
                BX      R0
                ENDP

PIN_INT4_IRQHandler\
                PROC
                EXPORT  PIN_INT4_IRQHandler                  [WEAK]
                LDR     R0, =PIN_INT4_DriverIRQHandler
                BX      R0
                ENDP

PIN_INT5_IRQHandler\
                PROC
                EXPORT  PIN_INT5_IRQHandler                  [WEAK]
                LDR     R0, =PIN_INT5_DriverIRQHandler
                BX      R0
                ENDP

PIN_INT6_IRQHandler\
                PROC
                EXPORT  PIN_INT6_IRQHandler                  [WEAK]
                LDR     R0, =PIN_INT6_DriverIRQHandler
                BX      R0
                ENDP

PIN_INT7_IRQHandler\
                PROC
                EXPORT  PIN_INT7_IRQHandler                  [WEAK]
                LDR     R0, =PIN_INT7_DriverIRQHandler
                BX      R0
                ENDP

CTIMER2_IRQHandler\
                PROC
                EXPORT  CTIMER2_IRQHandler                   [WEAK]
                LDR     R0, =CTIMER2_DriverIRQHandler
                BX      R0
                ENDP

CTIMER4_IRQHandler\
                PROC
                EXPORT  CTIMER4_IRQHandler                   [WEAK]
                LDR     R0, =CTIMER4_DriverIRQHandler
                BX      R0
                ENDP

OS_EVENT_IRQHandler\
                PROC
                EXPORT  OS_EVENT_IRQHandler                  [WEAK]
                LDR     R0, =OS_EVENT_DriverIRQHandler
                BX      R0
                ENDP

SDIO_IRQHandler\
                PROC
                EXPORT  SDIO_IRQHandler                      [WEAK]
                LDR     R0, =SDIO_DriverIRQHandler
                BX      R0
                ENDP

USB1_PHY_IRQHandler\
                PROC
                EXPORT  USB1_PHY_IRQHandler                  [WEAK]
                LDR     R0, =USB1_PHY_DriverIRQHandler
                BX      R0
                ENDP

USB1_IRQHandler\
                PROC
                EXPORT  USB1_IRQHandler                      [WEAK]
                LDR     R0, =USB1_DriverIRQHandler
                BX      R0
                ENDP

USB1_NEEDCLK_IRQHandler\
                PROC
                EXPORT  USB1_NEEDCLK_IRQHandler              [WEAK]
                LDR     R0, =USB1_NEEDCLK_DriverIRQHandler
                BX      R0
                ENDP

SEC_HYPERVISOR_CALL_IRQHandler\
                PROC
                EXPORT  SEC_HYPERVISOR_CALL_IRQHandler       [WEAK]
                LDR     R0, =SEC_HYPERVISOR_CALL_DriverIRQHandler
                BX      R0
                ENDP

SEC_GPIO_INT0_IRQ0_IRQHandler\
                PROC
                EXPORT  SEC_GPIO_INT0_IRQ0_IRQHandler        [WEAK]
                LDR     R0, =SEC_GPIO_INT0_IRQ0_DriverIRQHandler
                BX      R0
                ENDP

SEC_GPIO_INT0_IRQ1_IRQHandler\
                PROC
                EXPORT  SEC_GPIO_INT0_IRQ1_IRQHandler        [WEAK]
                LDR     R0, =SEC_GPIO_INT0_IRQ1_DriverIRQHandler
                BX      R0
                ENDP

PLU_IRQHandler\
                PROC
                EXPORT  PLU_IRQHandler                       [WEAK]
                LDR     R0, =PLU_DriverIRQHandler
                BX      R0
                ENDP

SEC_VIO_IRQHandler\
                PROC
                EXPORT  SEC_VIO_IRQHandler                   [WEAK]
                LDR     R0, =SEC_VIO_DriverIRQHandler
                BX      R0
                ENDP

HASHCRYPT_IRQHandler\
                PROC
                EXPORT  HASHCRYPT_IRQHandler                 [WEAK]
                LDR     R0, =HASHCRYPT_DriverIRQHandler
                BX      R0
                ENDP

CASER_IRQHandler\
                PROC
                EXPORT  CASER_IRQHandler                     [WEAK]
                LDR     R0, =CASER_DriverIRQHandler
                BX      R0
                ENDP

PUF_IRQHandler\
                PROC
                EXPORT  PUF_IRQHandler                       [WEAK]
                LDR     R0, =PUF_DriverIRQHandler
                BX      R0
                ENDP

PQ_IRQHandler\
                PROC
                EXPORT  PQ_IRQHandler                        [WEAK]
                LDR     R0, =PQ_DriverIRQHandler
                BX      R0
                ENDP

DMA1_IRQHandler\
                PROC
                EXPORT  DMA1_IRQHandler                      [WEAK]
                LDR     R0, =DMA1_DriverIRQHandler
                BX      R0
                ENDP

FLEXCOMM8_IRQHandler\
                PROC
                EXPORT  FLEXCOMM8_IRQHandler                 [WEAK]
                LDR     R0, =FLEXCOMM8_DriverIRQHandler
                BX      R0
                ENDP


Default_Handler\
                PROC
                EXPORT  WDT_BOD_DriverIRQHandler             [WEAK]
                EXPORT  DMA0_DriverIRQHandler                [WEAK]
                EXPORT  GINT0_DriverIRQHandler               [WEAK]
                EXPORT  GINT1_DriverIRQHandler               [WEAK]
                EXPORT  PIN_INT0_DriverIRQHandler            [WEAK]
                EXPORT  PIN_INT1_DriverIRQHandler            [WEAK]
                EXPORT  PIN_INT2_DriverIRQHandler            [WEAK]
                EXPORT  PIN_INT3_DriverIRQHandler            [WEAK]
                EXPORT  UTICK0_DriverIRQHandler              [WEAK]
                EXPORT  MRT0_DriverIRQHandler                [WEAK]
                EXPORT  CTIMER0_DriverIRQHandler             [WEAK]
                EXPORT  CTIMER1_DriverIRQHandler             [WEAK]
                EXPORT  SCT0_DriverIRQHandler                [WEAK]
                EXPORT  CTIMER3_DriverIRQHandler             [WEAK]
                EXPORT  FLEXCOMM0_DriverIRQHandler           [WEAK]
                EXPORT  FLEXCOMM1_DriverIRQHandler           [WEAK]
                EXPORT  FLEXCOMM2_DriverIRQHandler           [WEAK]
                EXPORT  FLEXCOMM3_DriverIRQHandler           [WEAK]
                EXPORT  FLEXCOMM4_DriverIRQHandler           [WEAK]
                EXPORT  FLEXCOMM5_DriverIRQHandler           [WEAK]
                EXPORT  FLEXCOMM6_DriverIRQHandler           [WEAK]
                EXPORT  FLEXCOMM7_DriverIRQHandler           [WEAK]
                EXPORT  ADC0_DriverIRQHandler                [WEAK]
                EXPORT  Reserved39_IRQHandler                [WEAK]
                EXPORT  ACMP_DriverIRQHandler                [WEAK]
                EXPORT  Reserved41_IRQHandler                [WEAK]
                EXPORT  Reserved42_IRQHandler                [WEAK]
                EXPORT  USB0_NEEDCLK_DriverIRQHandler        [WEAK]
                EXPORT  USB0_DriverIRQHandler                [WEAK]
                EXPORT  RTC_DriverIRQHandler                 [WEAK]
                EXPORT  Reserved46_IRQHandler                [WEAK]
                EXPORT  MAILBOX_DriverIRQHandler             [WEAK]
                EXPORT  PIN_INT4_DriverIRQHandler            [WEAK]
                EXPORT  PIN_INT5_DriverIRQHandler            [WEAK]
                EXPORT  PIN_INT6_DriverIRQHandler            [WEAK]
                EXPORT  PIN_INT7_DriverIRQHandler            [WEAK]
                EXPORT  CTIMER2_DriverIRQHandler             [WEAK]
                EXPORT  CTIMER4_DriverIRQHandler             [WEAK]
                EXPORT  OS_EVENT_DriverIRQHandler            [WEAK]
                EXPORT  Reserved55_IRQHandler                [WEAK]
                EXPORT  Reserved56_IRQHandler                [WEAK]
                EXPORT  Reserved57_IRQHandler                [WEAK]
                EXPORT  SDIO_DriverIRQHandler                [WEAK]
                EXPORT  Reserved59_IRQHandler                [WEAK]
                EXPORT  Reserved60_IRQHandler                [WEAK]
                EXPORT  Reserved61_IRQHandler                [WEAK]
                EXPORT  USB1_PHY_DriverIRQHandler            [WEAK]
                EXPORT  USB1_DriverIRQHandler                [WEAK]
                EXPORT  USB1_NEEDCLK_DriverIRQHandler        [WEAK]
                EXPORT  SEC_HYPERVISOR_CALL_DriverIRQHandler [WEAK]
                EXPORT  SEC_GPIO_INT0_IRQ0_DriverIRQHandler  [WEAK]
                EXPORT  SEC_GPIO_INT0_IRQ1_DriverIRQHandler  [WEAK]
                EXPORT  PLU_DriverIRQHandler                 [WEAK]
                EXPORT  SEC_VIO_DriverIRQHandler             [WEAK]
                EXPORT  HASHCRYPT_DriverIRQHandler           [WEAK]
                EXPORT  CASER_DriverIRQHandler               [WEAK]
                EXPORT  PUF_DriverIRQHandler                 [WEAK]
                EXPORT  PQ_DriverIRQHandler                  [WEAK]
                EXPORT  DMA1_DriverIRQHandler                [WEAK]
                EXPORT  FLEXCOMM8_DriverIRQHandler           [WEAK]
WDT_BOD_DriverIRQHandler
DMA0_DriverIRQHandler
GINT0_DriverIRQHandler
GINT1_DriverIRQHandler
PIN_INT0_DriverIRQHandler
PIN_INT1_DriverIRQHandler
PIN_INT2_DriverIRQHandler
PIN_INT3_DriverIRQHandler
UTICK0_DriverIRQHandler
MRT0_DriverIRQHandler
CTIMER0_DriverIRQHandler
CTIMER1_DriverIRQHandler
SCT0_DriverIRQHandler
CTIMER3_DriverIRQHandler
FLEXCOMM0_DriverIRQHandler
FLEXCOMM1_DriverIRQHandler
FLEXCOMM2_DriverIRQHandler
FLEXCOMM3_DriverIRQHandler
FLEXCOMM4_DriverIRQHandler
FLEXCOMM5_DriverIRQHandler
FLEXCOMM6_DriverIRQHandler
FLEXCOMM7_DriverIRQHandler
ADC0_DriverIRQHandler
Reserved39_IRQHandler
ACMP_DriverIRQHandler
Reserved41_IRQHandler
Reserved42_IRQHandler
USB0_NEEDCLK_DriverIRQHandler
USB0_DriverIRQHandler
RTC_DriverIRQHandler
Reserved46_IRQHandler
MAILBOX_DriverIRQHandler
PIN_INT4_DriverIRQHandler
PIN_INT5_DriverIRQHandler
PIN_INT6_DriverIRQHandler
PIN_INT7_DriverIRQHandler
CTIMER2_DriverIRQHandler
CTIMER4_DriverIRQHandler
OS_EVENT_DriverIRQHandler
Reserved55_IRQHandler
Reserved56_IRQHandler
Reserved57_IRQHandler
SDIO_DriverIRQHandler
Reserved59_IRQHandler
Reserved60_IRQHandler
Reserved61_IRQHandler
USB1_PHY_DriverIRQHandler
USB1_DriverIRQHandler
USB1_NEEDCLK_DriverIRQHandler
SEC_HYPERVISOR_CALL_DriverIRQHandler
SEC_GPIO_INT0_IRQ0_DriverIRQHandler
SEC_GPIO_INT0_IRQ1_DriverIRQHandler
PLU_DriverIRQHandler
SEC_VIO_DriverIRQHandler
HASHCRYPT_DriverIRQHandler
CASER_DriverIRQHandler
PUF_DriverIRQHandler
PQ_DriverIRQHandler
DMA1_DriverIRQHandler
FLEXCOMM8_DriverIRQHandler
DefaultISR
                LDR    R0, =DefaultISR
                BX     R0
                ENDP
                ALIGN


; User Initial Stack & Heap

;                IF      :DEF:__MICROLIB

;                EXPORT  __initial_sp
;                EXPORT  __heap_base
;                EXPORT  __heap_limit

;                ELSE

;                IMPORT  __use_two_region_memory
;                EXPORT  __user_initial_stackheap
;__user_initial_stackheap

;                LDR     R0, =  Heap_Mem
;                LDR     R1, =(Stack_Mem + Stack_Size)
;                LDR     R2, = (Heap_Mem +  Heap_Size)
;                LDR     R3, = Stack_Mem
;                BX      LR

;                ALIGN

;                ENDIF


                END

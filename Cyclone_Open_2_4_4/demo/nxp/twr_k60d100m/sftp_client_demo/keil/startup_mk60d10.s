; * ---------------------------------------------------------------------------------------
; *  @file:    startup_MK60D10.s
; *  @purpose: CMSIS Cortex-M4 Core Device Startup File
; *            MK60D10
; *  @version: 1.9
; *  @date:    2015-7-29
; *  @build:   b170112
; * ---------------------------------------------------------------------------------------
; *
; * Copyright (c) 1997 - 2016, Freescale Semiconductor, Inc.
; * Copyright 2016 - 2017 NXP
; * Redistribution and use in source and binary forms, with or without modification,
; * are permitted provided that the following conditions are met:
; *
; * o Redistributions of source code must retain the above copyright notice, this list
; *   of conditions and the following disclaimer.
; *
; * o Redistributions in binary form must reproduce the above copyright notice, this
; *   list of conditions and the following disclaimer in the documentation and/or
; *   other materials provided with the distribution.
; *
; * o Neither the name of the copyright holder nor the names of its
; *   contributors may be used to endorse or promote products derived from this
; *   software without specific prior written permission.
; *
; * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
; * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
; * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
; * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
; * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
; * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
; * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
; * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
; * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
; * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; *
; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------
; *
; *****************************************************************************/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

;Heap_Size       EQU     0x00000000

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

__Vectors       DCD     __initial_sp  ; Top of Stack
                DCD     Reset_Handler  ; Reset Handler
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
                DCD     DMA0_IRQHandler                     ;DMA channel 0 transfer complete
                DCD     DMA1_IRQHandler                     ;DMA channel 1 transfer complete
                DCD     DMA2_IRQHandler                     ;DMA channel 2 transfer complete
                DCD     DMA3_IRQHandler                     ;DMA channel 3 transfer complete
                DCD     DMA4_IRQHandler                     ;DMA channel 4 transfer complete
                DCD     DMA5_IRQHandler                     ;DMA channel 5 transfer complete
                DCD     DMA6_IRQHandler                     ;DMA channel 6 transfer complete
                DCD     DMA7_IRQHandler                     ;DMA channel 7 transfer complete
                DCD     DMA8_IRQHandler                     ;DMA channel 8 transfer complete
                DCD     DMA9_IRQHandler                     ;DMA channel 9 transfer complete
                DCD     DMA10_IRQHandler                    ;DMA channel 10 transfer complete
                DCD     DMA11_IRQHandler                    ;DMA channel 11 transfer complete
                DCD     DMA12_IRQHandler                    ;DMA channel 12 transfer complete
                DCD     DMA13_IRQHandler                    ;DMA channel 13 transfer complete
                DCD     DMA14_IRQHandler                    ;DMA channel 14 transfer complete
                DCD     DMA15_IRQHandler                    ;DMA channel 15 transfer complete
                DCD     DMA_Error_IRQHandler                ;DMA channel 0 - 15 error
                DCD     MCM_IRQHandler                      ;MCM normal interrupt
                DCD     FTFL_IRQHandler                     ;FTFL command complete
                DCD     Read_Collision_IRQHandler           ;FTFL read collision
                DCD     LVD_LVW_IRQHandler                  ;PMC controller low-voltage detect, low-voltage warning
                DCD     LLWU_IRQHandler                     ;Low leakage wakeup
                DCD     WDOG_EWM_IRQHandler                 ;Single interrupt vector for  WDOG and EWM
                DCD     RNG_IRQHandler                      ;Randon number generator
                DCD     I2C0_IRQHandler                     ;Inter-integrated circuit 0
                DCD     I2C1_IRQHandler                     ;Inter-integrated circuit 1
                DCD     SPI0_IRQHandler                     ;Serial peripheral Interface 0
                DCD     SPI1_IRQHandler                     ;Serial peripheral Interface 1
                DCD     SPI2_IRQHandler                     ;Serial peripheral Interface 1
                DCD     CAN0_ORed_Message_buffer_IRQHandler ;CAN0 ORed message buffers
                DCD     CAN0_Bus_Off_IRQHandler             ;CAN0 bus off
                DCD     CAN0_Error_IRQHandler               ;CAN0 error
                DCD     CAN0_Tx_Warning_IRQHandler          ;CAN0 Tx warning
                DCD     CAN0_Rx_Warning_IRQHandler          ;CAN0 Rx warning
                DCD     CAN0_Wake_Up_IRQHandler             ;CAN0 wake up
                DCD     I2S0_Tx_IRQHandler                  ;Integrated interchip sound 0 transmit interrupt
                DCD     I2S0_Rx_IRQHandler                  ;Integrated interchip sound 0 receive interrupt
                DCD     CAN1_ORed_Message_buffer_IRQHandler ;CAN1 OR'd message buffers interrupt
                DCD     CAN1_Bus_Off_IRQHandler             ;CAN1 bus off interrupt
                DCD     CAN1_Error_IRQHandler               ;CAN1 error interrupt
                DCD     CAN1_Tx_Warning_IRQHandler          ;CAN1 Tx warning interrupt
                DCD     CAN1_Rx_Warning_IRQHandler          ;CAN1 Rx warning interrupt
                DCD     CAN1_Wake_Up_IRQHandler             ;CAN1 wake up interrupt
                DCD     Reserved59_IRQHandler               ;Reserved interrupt
                DCD     UART0_LON_IRQHandler                ;UART0 LON
                DCD     UART0_RX_TX_IRQHandler              ;UART0 receive/transmit interrupt
                DCD     UART0_ERR_IRQHandler                ;UART0 error interrupt
                DCD     UART1_RX_TX_IRQHandler              ;UART1 receive/transmit interrupt
                DCD     UART1_ERR_IRQHandler                ;UART1 error interrupt
                DCD     UART2_RX_TX_IRQHandler              ;UART2 receive/transmit interrupt
                DCD     UART2_ERR_IRQHandler                ;UART2 error interrupt
                DCD     UART3_RX_TX_IRQHandler              ;UART3 receive/transmit interrupt
                DCD     UART3_ERR_IRQHandler                ;UART3 error interrupt
                DCD     UART4_RX_TX_IRQHandler              ;UART4 receive/transmit interrupt
                DCD     UART4_ERR_IRQHandler                ;UART4 error interrupt
                DCD     UART5_RX_TX_IRQHandler              ;UART5 receive/transmit interrupt
                DCD     UART5_ERR_IRQHandler                ;UART5 error interrupt
                DCD     ADC0_IRQHandler                     ;Analog-to-digital converter 0
                DCD     ADC1_IRQHandler                     ;Analog-to-digital converter 1
                DCD     CMP0_IRQHandler                     ;Comparator 0
                DCD     CMP1_IRQHandler                     ;Comparator 1
                DCD     CMP2_IRQHandler                     ;Comparator 2
                DCD     FTM0_IRQHandler                     ;FlexTimer module 0 fault, overflow and channels interrupt
                DCD     FTM1_IRQHandler                     ;FlexTimer module 1 fault, overflow and channels interrupt
                DCD     FTM2_IRQHandler                     ;FlexTimer module 2 fault, overflow and channels interrupt
                DCD     CMT_IRQHandler                      ;Carrier modulator transmitter
                DCD     RTC_IRQHandler                      ;Real time clock
                DCD     RTC_Seconds_IRQHandler              ;Real time clock seconds
                DCD     PIT0_IRQHandler                     ;Periodic interrupt timer channel 0
                DCD     PIT1_IRQHandler                     ;Periodic interrupt timer channel 1
                DCD     PIT2_IRQHandler                     ;Periodic interrupt timer channel 2
                DCD     PIT3_IRQHandler                     ;Periodic interrupt timer channel 3
                DCD     PDB0_IRQHandler                     ;Programmable delay block
                DCD     USB0_IRQHandler                     ;USB OTG interrupt
                DCD     USBDCD_IRQHandler                   ;USB charger detect
                DCD     ENET_1588_Timer_IRQHandler          ;Ethernet MAC IEEE 1588 timer
                DCD     ENET_Transmit_IRQHandler            ;Ethernet MAC transmit
                DCD     ENET_Receive_IRQHandler             ;Ethernet MAC receive
                DCD     ENET_Error_IRQHandler               ;Ethernet MAC error and miscelaneous
                DCD     Reserved95_IRQHandler               ;Reserved interrupt
                DCD     SDHC_IRQHandler                     ;Secured digital host controller
                DCD     DAC0_IRQHandler                     ;Digital-to-analog converter 0
                DCD     DAC1_IRQHandler                     ;Digital-to-analog converter 1
                DCD     TSI0_IRQHandler                     ;TSI0 Interrupt
                DCD     MCG_IRQHandler                      ;Multipurpose clock generator
                DCD     LPTMR0_IRQHandler                   ;Low power timer interrupt
                DCD     Reserved102_IRQHandler              ;Reserved interrupt
                DCD     PORTA_IRQHandler                    ;Port A interrupt
                DCD     PORTB_IRQHandler                    ;Port B interrupt
                DCD     PORTC_IRQHandler                    ;Port C interrupt
                DCD     PORTD_IRQHandler                    ;Port D interrupt
                DCD     PORTE_IRQHandler                    ;Port E interrupt
                DCD     Reserved108_IRQHandler              ;Reserved interrupt
                DCD     Reserved109_IRQHandler              ;Reserved interrupt
                DCD     SWI_IRQHandler                      ;Software interrupt
                DCD     Reserved111_IRQHandler              ;Reserved interrupt
                DCD     Reserved112_IRQHandler              ;Reserved interrupt
                DCD     Reserved113_IRQHandler              ;Reserved interrupt
                DCD     Reserved114_IRQHandler              ;Reserved interrupt
                DCD     Reserved115_IRQHandler              ;Reserved interrupt
                DCD     Reserved116_IRQHandler              ;Reserved interrupt
                DCD     Reserved117_IRQHandler              ;Reserved interrupt
                DCD     Reserved118_IRQHandler              ;Reserved interrupt
                DCD     Reserved119_IRQHandler              ;Reserved interrupt
                DCD     DefaultISR                          ;120
                DCD     DefaultISR                          ;121
                DCD     DefaultISR                          ;122
                DCD     DefaultISR                          ;123
                DCD     DefaultISR                          ;124
                DCD     DefaultISR                          ;125
                DCD     DefaultISR                          ;126
                DCD     DefaultISR                          ;127
                DCD     DefaultISR                          ;128
                DCD     DefaultISR                          ;129
                DCD     DefaultISR                          ;130
                DCD     DefaultISR                          ;131
                DCD     DefaultISR                          ;132
                DCD     DefaultISR                          ;133
                DCD     DefaultISR                          ;134
                DCD     DefaultISR                          ;135
                DCD     DefaultISR                          ;136
                DCD     DefaultISR                          ;137
                DCD     DefaultISR                          ;138
                DCD     DefaultISR                          ;139
                DCD     DefaultISR                          ;140
                DCD     DefaultISR                          ;141
                DCD     DefaultISR                          ;142
                DCD     DefaultISR                          ;143
                DCD     DefaultISR                          ;144
                DCD     DefaultISR                          ;145
                DCD     DefaultISR                          ;146
                DCD     DefaultISR                          ;147
                DCD     DefaultISR                          ;148
                DCD     DefaultISR                          ;149
                DCD     DefaultISR                          ;150
                DCD     DefaultISR                          ;151
                DCD     DefaultISR                          ;152
                DCD     DefaultISR                          ;153
                DCD     DefaultISR                          ;154
                DCD     DefaultISR                          ;155
                DCD     DefaultISR                          ;156
                DCD     DefaultISR                          ;157
                DCD     DefaultISR                          ;158
                DCD     DefaultISR                          ;159
                DCD     DefaultISR                          ;160
                DCD     DefaultISR                          ;161
                DCD     DefaultISR                          ;162
                DCD     DefaultISR                          ;163
                DCD     DefaultISR                          ;164
                DCD     DefaultISR                          ;165
                DCD     DefaultISR                          ;166
                DCD     DefaultISR                          ;167
                DCD     DefaultISR                          ;168
                DCD     DefaultISR                          ;169
                DCD     DefaultISR                          ;170
                DCD     DefaultISR                          ;171
                DCD     DefaultISR                          ;172
                DCD     DefaultISR                          ;173
                DCD     DefaultISR                          ;174
                DCD     DefaultISR                          ;175
                DCD     DefaultISR                          ;176
                DCD     DefaultISR                          ;177
                DCD     DefaultISR                          ;178
                DCD     DefaultISR                          ;179
                DCD     DefaultISR                          ;180
                DCD     DefaultISR                          ;181
                DCD     DefaultISR                          ;182
                DCD     DefaultISR                          ;183
                DCD     DefaultISR                          ;184
                DCD     DefaultISR                          ;185
                DCD     DefaultISR                          ;186
                DCD     DefaultISR                          ;187
                DCD     DefaultISR                          ;188
                DCD     DefaultISR                          ;189
                DCD     DefaultISR                          ;190
                DCD     DefaultISR                          ;191
                DCD     DefaultISR                          ;192
                DCD     DefaultISR                          ;193
                DCD     DefaultISR                          ;194
                DCD     DefaultISR                          ;195
                DCD     DefaultISR                          ;196
                DCD     DefaultISR                          ;197
                DCD     DefaultISR                          ;198
                DCD     DefaultISR                          ;199
                DCD     DefaultISR                          ;200
                DCD     DefaultISR                          ;201
                DCD     DefaultISR                          ;202
                DCD     DefaultISR                          ;203
                DCD     DefaultISR                          ;204
                DCD     DefaultISR                          ;205
                DCD     DefaultISR                          ;206
                DCD     DefaultISR                          ;207
                DCD     DefaultISR                          ;208
                DCD     DefaultISR                          ;209
                DCD     DefaultISR                          ;210
                DCD     DefaultISR                          ;211
                DCD     DefaultISR                          ;212
                DCD     DefaultISR                          ;213
                DCD     DefaultISR                          ;214
                DCD     DefaultISR                          ;215
                DCD     DefaultISR                          ;216
                DCD     DefaultISR                          ;217
                DCD     DefaultISR                          ;218
                DCD     DefaultISR                          ;219
                DCD     DefaultISR                          ;220
                DCD     DefaultISR                          ;221
                DCD     DefaultISR                          ;222
                DCD     DefaultISR                          ;223
                DCD     DefaultISR                          ;224
                DCD     DefaultISR                          ;225
                DCD     DefaultISR                          ;226
                DCD     DefaultISR                          ;227
                DCD     DefaultISR                          ;228
                DCD     DefaultISR                          ;229
                DCD     DefaultISR                          ;230
                DCD     DefaultISR                          ;231
                DCD     DefaultISR                          ;232
                DCD     DefaultISR                          ;233
                DCD     DefaultISR                          ;234
                DCD     DefaultISR                          ;235
                DCD     DefaultISR                          ;236
                DCD     DefaultISR                          ;237
                DCD     DefaultISR                          ;238
                DCD     DefaultISR                          ;239
                DCD     DefaultISR                          ;240
                DCD     DefaultISR                          ;241
                DCD     DefaultISR                          ;242
                DCD     DefaultISR                          ;243
                DCD     DefaultISR                          ;244
                DCD     DefaultISR                          ;245
                DCD     DefaultISR                          ;246
                DCD     DefaultISR                          ;247
                DCD     DefaultISR                          ;248
                DCD     DefaultISR                          ;249
                DCD     DefaultISR                          ;250
                DCD     DefaultISR                          ;251
                DCD     DefaultISR                          ;252
                DCD     DefaultISR                          ;253
                DCD     DefaultISR                          ;254
                DCD     0xFFFFFFFF                          ; Reserved for user TRIM value
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

; <h> Flash Configuration
;   <i> 16-byte flash configuration field that stores default protection settings (loaded on reset)
;   <i> and security information that allows the MCU to restrict access to the FTFL module.
;   <h> Backdoor Comparison Key
;     <o0>  Backdoor Comparison Key 0.  <0x0-0xFF:2>
;     <o1>  Backdoor Comparison Key 1.  <0x0-0xFF:2>
;     <o2>  Backdoor Comparison Key 2.  <0x0-0xFF:2>
;     <o3>  Backdoor Comparison Key 3.  <0x0-0xFF:2>
;     <o4>  Backdoor Comparison Key 4.  <0x0-0xFF:2>
;     <o5>  Backdoor Comparison Key 5.  <0x0-0xFF:2>
;     <o6>  Backdoor Comparison Key 6.  <0x0-0xFF:2>
;     <o7>  Backdoor Comparison Key 7.  <0x0-0xFF:2>
BackDoorK0      EQU     0xFF
BackDoorK1      EQU     0xFF
BackDoorK2      EQU     0xFF
BackDoorK3      EQU     0xFF
BackDoorK4      EQU     0xFF
BackDoorK5      EQU     0xFF
BackDoorK6      EQU     0xFF
BackDoorK7      EQU     0xFF
;   </h>
;   <h> Program flash protection bytes (FPROT)
;     <i> Each program flash region can be protected from program and erase operation by setting the associated PROT bit.
;     <i> Each bit protects a 1/32 region of the program flash memory.
;     <h> FPROT0
;       <i> Program Flash Region Protect Register 0
;       <i> 1/32 - 8/32 region
;       <o.0>   FPROT0.0
;       <o.1>   FPROT0.1
;       <o.2>   FPROT0.2
;       <o.3>   FPROT0.3
;       <o.4>   FPROT0.4
;       <o.5>   FPROT0.5
;       <o.6>   FPROT0.6
;       <o.7>   FPROT0.7
nFPROT0         EQU     0x00
FPROT0          EQU     nFPROT0:EOR:0xFF
;     </h>
;     <h> FPROT1
;       <i> Program Flash Region Protect Register 1
;       <i> 9/32 - 16/32 region
;       <o.0>   FPROT1.0
;       <o.1>   FPROT1.1
;       <o.2>   FPROT1.2
;       <o.3>   FPROT1.3
;       <o.4>   FPROT1.4
;       <o.5>   FPROT1.5
;       <o.6>   FPROT1.6
;       <o.7>   FPROT1.7
nFPROT1         EQU     0x00
FPROT1          EQU     nFPROT1:EOR:0xFF
;     </h>
;     <h> FPROT2
;       <i> Program Flash Region Protect Register 2
;       <i> 17/32 - 24/32 region
;       <o.0>   FPROT2.0
;       <o.1>   FPROT2.1
;       <o.2>   FPROT2.2
;       <o.3>   FPROT2.3
;       <o.4>   FPROT2.4
;       <o.5>   FPROT2.5
;       <o.6>   FPROT2.6
;       <o.7>   FPROT2.7
nFPROT2         EQU     0x00
FPROT2          EQU     nFPROT2:EOR:0xFF
;     </h>
;     <h> FPROT3
;       <i> Program Flash Region Protect Register 3
;       <i> 25/32 - 32/32 region
;       <o.0>   FPROT3.0
;       <o.1>   FPROT3.1
;       <o.2>   FPROT3.2
;       <o.3>   FPROT3.3
;       <o.4>   FPROT3.4
;       <o.5>   FPROT3.5
;       <o.6>   FPROT3.6
;       <o.7>   FPROT3.7
nFPROT3         EQU     0x00
FPROT3          EQU     nFPROT3:EOR:0xFF
;     </h>
;   </h>
;   <h> Data flash protection byte (FDPROT)
;     <i> Each bit protects a 1/8 region of the data flash memory.
;     <i> (Program flash only devices: Reserved)
;       <o.0>   FDPROT.0
;       <o.1>   FDPROT.1
;       <o.2>   FDPROT.2
;       <o.3>   FDPROT.3
;       <o.4>   FDPROT.4
;       <o.5>   FDPROT.5
;       <o.6>   FDPROT.6
;       <o.7>   FDPROT.7
nFDPROT         EQU     0x00
FDPROT          EQU     nFDPROT:EOR:0xFF
;   </h>
;   <h> EEPROM protection byte (FEPROT)
;     <i> FlexNVM devices: Each bit protects a 1/8 region of the EEPROM.
;     <i> (Program flash only devices: Reserved)
;       <o.0>   FEPROT.0
;       <o.1>   FEPROT.1
;       <o.2>   FEPROT.2
;       <o.3>   FEPROT.3
;       <o.4>   FEPROT.4
;       <o.5>   FEPROT.5
;       <o.6>   FEPROT.6
;       <o.7>   FEPROT.7
nFEPROT         EQU     0x00
FEPROT          EQU     nFEPROT:EOR:0xFF
;   </h>
;   <h> Flash nonvolatile option byte (FOPT)
;     <i> Allows the user to customize the operation of the MCU at boot time.
;     <o.0> LPBOOT
;       <0=> Low-power boot
;       <1=> Normal boot
;     <o.1> EZPORT_DIS
;       <0=> EzPort operation is disabled
;       <1=> EzPort operation is enabled
;     <o.2> NMI_DIS
;       <0=> NMI interrupts are always blocked
;       <1=> NMI_b pin/interrupts reset default to enabled
FOPT          EQU     0xFF
;   </h>
;   <h> Flash security byte (FSEC)
;     <i> WARNING: If SEC field is configured as "MCU security status is secure" and MEEN field is configured as "Mass erase is disabled",
;     <i> MCU's security status cannot be set back to unsecure state since Mass erase via the debugger is blocked !!!
;     <o.0..1> SEC
;       <2=> MCU security status is unsecure
;       <3=> MCU security status is secure
;         <i> Flash Security
;     <o.2..3> FSLACC
;       <2=> Freescale factory access denied
;       <3=> Freescale factory access granted
;         <i> Freescale Failure Analysis Access Code
;     <o.4..5> MEEN
;       <2=> Mass erase is disabled
;       <3=> Mass erase is enabled
;     <o.6..7> KEYEN
;       <2=> Backdoor key access enabled
;       <3=> Backdoor key access disabled
;         <i> Backdoor Key Security Enable
FSEC          EQU     0xFE
;   </h>
; </h>
                IF      :LNOT::DEF:RAM_TARGET
                AREA    |.ARM.__at_0x400|, CODE, READONLY
                DCB     BackDoorK0, BackDoorK1, BackDoorK2, BackDoorK3
                DCB     BackDoorK4, BackDoorK5, BackDoorK6, BackDoorK7
                DCB     FPROT0    , FPROT1    , FPROT2    , FPROT3
                DCB     FSEC      , FOPT      , FEPROT    , FDPROT
                ENDIF


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
                EXPORT  NMI_Handler         [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler         [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler\
                PROC
                EXPORT  SVC_Handler         [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler         [WEAK]
                B       .
                ENDP
PendSV_Handler\
                PROC
                EXPORT  PendSV_Handler         [WEAK]
                B       .
                ENDP
SysTick_Handler\
                PROC
                EXPORT  SysTick_Handler         [WEAK]
                B       .
                ENDP
DMA0_IRQHandler\
                PROC
                EXPORT  DMA0_IRQHandler         [WEAK]
                LDR     R0, =DMA0_DriverIRQHandler
                BX      R0
                ENDP

DMA1_IRQHandler\
                PROC
                EXPORT  DMA1_IRQHandler         [WEAK]
                LDR     R0, =DMA1_DriverIRQHandler
                BX      R0
                ENDP

DMA2_IRQHandler\
                PROC
                EXPORT  DMA2_IRQHandler         [WEAK]
                LDR     R0, =DMA2_DriverIRQHandler
                BX      R0
                ENDP

DMA3_IRQHandler\
                PROC
                EXPORT  DMA3_IRQHandler         [WEAK]
                LDR     R0, =DMA3_DriverIRQHandler
                BX      R0
                ENDP

DMA4_IRQHandler\
                PROC
                EXPORT  DMA4_IRQHandler         [WEAK]
                LDR     R0, =DMA4_DriverIRQHandler
                BX      R0
                ENDP

DMA5_IRQHandler\
                PROC
                EXPORT  DMA5_IRQHandler         [WEAK]
                LDR     R0, =DMA5_DriverIRQHandler
                BX      R0
                ENDP

DMA6_IRQHandler\
                PROC
                EXPORT  DMA6_IRQHandler         [WEAK]
                LDR     R0, =DMA6_DriverIRQHandler
                BX      R0
                ENDP

DMA7_IRQHandler\
                PROC
                EXPORT  DMA7_IRQHandler         [WEAK]
                LDR     R0, =DMA7_DriverIRQHandler
                BX      R0
                ENDP

DMA8_IRQHandler\
                PROC
                EXPORT  DMA8_IRQHandler         [WEAK]
                LDR     R0, =DMA8_DriverIRQHandler
                BX      R0
                ENDP

DMA9_IRQHandler\
                PROC
                EXPORT  DMA9_IRQHandler         [WEAK]
                LDR     R0, =DMA9_DriverIRQHandler
                BX      R0
                ENDP

DMA10_IRQHandler\
                PROC
                EXPORT  DMA10_IRQHandler         [WEAK]
                LDR     R0, =DMA10_DriverIRQHandler
                BX      R0
                ENDP

DMA11_IRQHandler\
                PROC
                EXPORT  DMA11_IRQHandler         [WEAK]
                LDR     R0, =DMA11_DriverIRQHandler
                BX      R0
                ENDP

DMA12_IRQHandler\
                PROC
                EXPORT  DMA12_IRQHandler         [WEAK]
                LDR     R0, =DMA12_DriverIRQHandler
                BX      R0
                ENDP

DMA13_IRQHandler\
                PROC
                EXPORT  DMA13_IRQHandler         [WEAK]
                LDR     R0, =DMA13_DriverIRQHandler
                BX      R0
                ENDP

DMA14_IRQHandler\
                PROC
                EXPORT  DMA14_IRQHandler         [WEAK]
                LDR     R0, =DMA14_DriverIRQHandler
                BX      R0
                ENDP

DMA15_IRQHandler\
                PROC
                EXPORT  DMA15_IRQHandler         [WEAK]
                LDR     R0, =DMA15_DriverIRQHandler
                BX      R0
                ENDP

DMA_Error_IRQHandler\
                PROC
                EXPORT  DMA_Error_IRQHandler         [WEAK]
                LDR     R0, =DMA_Error_DriverIRQHandler
                BX      R0
                ENDP

I2C0_IRQHandler\
                PROC
                EXPORT  I2C0_IRQHandler         [WEAK]
                LDR     R0, =I2C0_DriverIRQHandler
                BX      R0
                ENDP

I2C1_IRQHandler\
                PROC
                EXPORT  I2C1_IRQHandler         [WEAK]
                LDR     R0, =I2C1_DriverIRQHandler
                BX      R0
                ENDP

SPI0_IRQHandler\
                PROC
                EXPORT  SPI0_IRQHandler         [WEAK]
                LDR     R0, =SPI0_DriverIRQHandler
                BX      R0
                ENDP

SPI1_IRQHandler\
                PROC
                EXPORT  SPI1_IRQHandler         [WEAK]
                LDR     R0, =SPI1_DriverIRQHandler
                BX      R0
                ENDP

SPI2_IRQHandler\
                PROC
                EXPORT  SPI2_IRQHandler         [WEAK]
                LDR     R0, =SPI2_DriverIRQHandler
                BX      R0
                ENDP

CAN0_ORed_Message_buffer_IRQHandler\
                PROC
                EXPORT  CAN0_ORed_Message_buffer_IRQHandler         [WEAK]
                LDR     R0, =CAN0_DriverIRQHandler
                BX      R0
                ENDP

CAN0_Bus_Off_IRQHandler\
                PROC
                EXPORT  CAN0_Bus_Off_IRQHandler         [WEAK]
                LDR     R0, =CAN0_DriverIRQHandler
                BX      R0
                ENDP

CAN0_Error_IRQHandler\
                PROC
                EXPORT  CAN0_Error_IRQHandler         [WEAK]
                LDR     R0, =CAN0_DriverIRQHandler
                BX      R0
                ENDP

CAN0_Tx_Warning_IRQHandler\
                PROC
                EXPORT  CAN0_Tx_Warning_IRQHandler         [WEAK]
                LDR     R0, =CAN0_DriverIRQHandler
                BX      R0
                ENDP

CAN0_Rx_Warning_IRQHandler\
                PROC
                EXPORT  CAN0_Rx_Warning_IRQHandler         [WEAK]
                LDR     R0, =CAN0_DriverIRQHandler
                BX      R0
                ENDP

CAN0_Wake_Up_IRQHandler\
                PROC
                EXPORT  CAN0_Wake_Up_IRQHandler         [WEAK]
                LDR     R0, =CAN0_DriverIRQHandler
                BX      R0
                ENDP

I2S0_Tx_IRQHandler\
                PROC
                EXPORT  I2S0_Tx_IRQHandler         [WEAK]
                LDR     R0, =I2S0_Tx_DriverIRQHandler
                BX      R0
                ENDP

I2S0_Rx_IRQHandler\
                PROC
                EXPORT  I2S0_Rx_IRQHandler         [WEAK]
                LDR     R0, =I2S0_Rx_DriverIRQHandler
                BX      R0
                ENDP

CAN1_ORed_Message_buffer_IRQHandler\
                PROC
                EXPORT  CAN1_ORed_Message_buffer_IRQHandler         [WEAK]
                LDR     R0, =CAN1_DriverIRQHandler
                BX      R0
                ENDP

CAN1_Bus_Off_IRQHandler\
                PROC
                EXPORT  CAN1_Bus_Off_IRQHandler         [WEAK]
                LDR     R0, =CAN1_DriverIRQHandler
                BX      R0
                ENDP

CAN1_Error_IRQHandler\
                PROC
                EXPORT  CAN1_Error_IRQHandler         [WEAK]
                LDR     R0, =CAN1_DriverIRQHandler
                BX      R0
                ENDP

CAN1_Tx_Warning_IRQHandler\
                PROC
                EXPORT  CAN1_Tx_Warning_IRQHandler         [WEAK]
                LDR     R0, =CAN1_DriverIRQHandler
                BX      R0
                ENDP

CAN1_Rx_Warning_IRQHandler\
                PROC
                EXPORT  CAN1_Rx_Warning_IRQHandler         [WEAK]
                LDR     R0, =CAN1_DriverIRQHandler
                BX      R0
                ENDP

CAN1_Wake_Up_IRQHandler\
                PROC
                EXPORT  CAN1_Wake_Up_IRQHandler         [WEAK]
                LDR     R0, =CAN1_DriverIRQHandler
                BX      R0
                ENDP

UART0_LON_IRQHandler\
                PROC
                EXPORT  UART0_LON_IRQHandler         [WEAK]
                LDR     R0, =UART0_LON_DriverIRQHandler
                BX      R0
                ENDP

UART0_RX_TX_IRQHandler\
                PROC
                EXPORT  UART0_RX_TX_IRQHandler         [WEAK]
                LDR     R0, =UART0_RX_TX_DriverIRQHandler
                BX      R0
                ENDP

UART0_ERR_IRQHandler\
                PROC
                EXPORT  UART0_ERR_IRQHandler         [WEAK]
                LDR     R0, =UART0_ERR_DriverIRQHandler
                BX      R0
                ENDP

UART1_RX_TX_IRQHandler\
                PROC
                EXPORT  UART1_RX_TX_IRQHandler         [WEAK]
                LDR     R0, =UART1_RX_TX_DriverIRQHandler
                BX      R0
                ENDP

UART1_ERR_IRQHandler\
                PROC
                EXPORT  UART1_ERR_IRQHandler         [WEAK]
                LDR     R0, =UART1_ERR_DriverIRQHandler
                BX      R0
                ENDP

UART2_RX_TX_IRQHandler\
                PROC
                EXPORT  UART2_RX_TX_IRQHandler         [WEAK]
                LDR     R0, =UART2_RX_TX_DriverIRQHandler
                BX      R0
                ENDP

UART2_ERR_IRQHandler\
                PROC
                EXPORT  UART2_ERR_IRQHandler         [WEAK]
                LDR     R0, =UART2_ERR_DriverIRQHandler
                BX      R0
                ENDP

UART3_RX_TX_IRQHandler\
                PROC
                EXPORT  UART3_RX_TX_IRQHandler         [WEAK]
                LDR     R0, =UART3_RX_TX_DriverIRQHandler
                BX      R0
                ENDP

UART3_ERR_IRQHandler\
                PROC
                EXPORT  UART3_ERR_IRQHandler         [WEAK]
                LDR     R0, =UART3_ERR_DriverIRQHandler
                BX      R0
                ENDP

UART4_RX_TX_IRQHandler\
                PROC
                EXPORT  UART4_RX_TX_IRQHandler         [WEAK]
                LDR     R0, =UART4_RX_TX_DriverIRQHandler
                BX      R0
                ENDP

UART4_ERR_IRQHandler\
                PROC
                EXPORT  UART4_ERR_IRQHandler         [WEAK]
                LDR     R0, =UART4_ERR_DriverIRQHandler
                BX      R0
                ENDP

UART5_RX_TX_IRQHandler\
                PROC
                EXPORT  UART5_RX_TX_IRQHandler         [WEAK]
                LDR     R0, =UART5_RX_TX_DriverIRQHandler
                BX      R0
                ENDP

UART5_ERR_IRQHandler\
                PROC
                EXPORT  UART5_ERR_IRQHandler         [WEAK]
                LDR     R0, =UART5_ERR_DriverIRQHandler
                BX      R0
                ENDP

ENET_1588_Timer_IRQHandler\
                PROC
                EXPORT  ENET_1588_Timer_IRQHandler         [WEAK]
                LDR     R0, =ENET_1588_Timer_DriverIRQHandler
                BX      R0
                ENDP

ENET_Transmit_IRQHandler\
                PROC
                EXPORT  ENET_Transmit_IRQHandler         [WEAK]
                LDR     R0, =ENET_Transmit_DriverIRQHandler
                BX      R0
                ENDP

ENET_Receive_IRQHandler\
                PROC
                EXPORT  ENET_Receive_IRQHandler         [WEAK]
                LDR     R0, =ENET_Receive_DriverIRQHandler
                BX      R0
                ENDP

ENET_Error_IRQHandler\
                PROC
                EXPORT  ENET_Error_IRQHandler         [WEAK]
                LDR     R0, =ENET_Error_DriverIRQHandler
                BX      R0
                ENDP

SDHC_IRQHandler\
                PROC
                EXPORT  SDHC_IRQHandler         [WEAK]
                LDR     R0, =SDHC_DriverIRQHandler
                BX      R0
                ENDP

Default_Handler\
                PROC
                EXPORT  DMA0_DriverIRQHandler         [WEAK]
                EXPORT  DMA1_DriverIRQHandler         [WEAK]
                EXPORT  DMA2_DriverIRQHandler         [WEAK]
                EXPORT  DMA3_DriverIRQHandler         [WEAK]
                EXPORT  DMA4_DriverIRQHandler         [WEAK]
                EXPORT  DMA5_DriverIRQHandler         [WEAK]
                EXPORT  DMA6_DriverIRQHandler         [WEAK]
                EXPORT  DMA7_DriverIRQHandler         [WEAK]
                EXPORT  DMA8_DriverIRQHandler         [WEAK]
                EXPORT  DMA9_DriverIRQHandler         [WEAK]
                EXPORT  DMA10_DriverIRQHandler         [WEAK]
                EXPORT  DMA11_DriverIRQHandler         [WEAK]
                EXPORT  DMA12_DriverIRQHandler         [WEAK]
                EXPORT  DMA13_DriverIRQHandler         [WEAK]
                EXPORT  DMA14_DriverIRQHandler         [WEAK]
                EXPORT  DMA15_DriverIRQHandler         [WEAK]
                EXPORT  DMA_Error_DriverIRQHandler         [WEAK]
                EXPORT  MCM_IRQHandler         [WEAK]
                EXPORT  FTFL_IRQHandler         [WEAK]
                EXPORT  Read_Collision_IRQHandler         [WEAK]
                EXPORT  LVD_LVW_IRQHandler         [WEAK]
                EXPORT  LLWU_IRQHandler         [WEAK]
                EXPORT  WDOG_EWM_IRQHandler         [WEAK]
                EXPORT  RNG_IRQHandler         [WEAK]
                EXPORT  I2C0_DriverIRQHandler         [WEAK]
                EXPORT  I2C1_DriverIRQHandler         [WEAK]
                EXPORT  SPI0_DriverIRQHandler         [WEAK]
                EXPORT  SPI1_DriverIRQHandler         [WEAK]
                EXPORT  SPI2_DriverIRQHandler         [WEAK]
                EXPORT  CAN0_DriverIRQHandler         [WEAK]
                EXPORT  I2S0_Tx_DriverIRQHandler         [WEAK]
                EXPORT  I2S0_Rx_DriverIRQHandler         [WEAK]
                EXPORT  CAN1_DriverIRQHandler         [WEAK]
                EXPORT  Reserved59_IRQHandler         [WEAK]
                EXPORT  UART0_LON_DriverIRQHandler         [WEAK]
                EXPORT  UART0_RX_TX_DriverIRQHandler         [WEAK]
                EXPORT  UART0_ERR_DriverIRQHandler         [WEAK]
                EXPORT  UART1_RX_TX_DriverIRQHandler         [WEAK]
                EXPORT  UART1_ERR_DriverIRQHandler         [WEAK]
                EXPORT  UART2_RX_TX_DriverIRQHandler         [WEAK]
                EXPORT  UART2_ERR_DriverIRQHandler         [WEAK]
                EXPORT  UART3_RX_TX_DriverIRQHandler         [WEAK]
                EXPORT  UART3_ERR_DriverIRQHandler         [WEAK]
                EXPORT  UART4_RX_TX_DriverIRQHandler         [WEAK]
                EXPORT  UART4_ERR_DriverIRQHandler         [WEAK]
                EXPORT  UART5_RX_TX_DriverIRQHandler         [WEAK]
                EXPORT  UART5_ERR_DriverIRQHandler         [WEAK]
                EXPORT  ADC0_IRQHandler         [WEAK]
                EXPORT  ADC1_IRQHandler         [WEAK]
                EXPORT  CMP0_IRQHandler         [WEAK]
                EXPORT  CMP1_IRQHandler         [WEAK]
                EXPORT  CMP2_IRQHandler         [WEAK]
                EXPORT  FTM0_IRQHandler         [WEAK]
                EXPORT  FTM1_IRQHandler         [WEAK]
                EXPORT  FTM2_IRQHandler         [WEAK]
                EXPORT  CMT_IRQHandler         [WEAK]
                EXPORT  RTC_IRQHandler         [WEAK]
                EXPORT  RTC_Seconds_IRQHandler         [WEAK]
                EXPORT  PIT0_IRQHandler         [WEAK]
                EXPORT  PIT1_IRQHandler         [WEAK]
                EXPORT  PIT2_IRQHandler         [WEAK]
                EXPORT  PIT3_IRQHandler         [WEAK]
                EXPORT  PDB0_IRQHandler         [WEAK]
                EXPORT  USB0_IRQHandler         [WEAK]
                EXPORT  USBDCD_IRQHandler         [WEAK]
                EXPORT  ENET_1588_Timer_DriverIRQHandler         [WEAK]
                EXPORT  ENET_Transmit_DriverIRQHandler         [WEAK]
                EXPORT  ENET_Receive_DriverIRQHandler         [WEAK]
                EXPORT  ENET_Error_DriverIRQHandler         [WEAK]
                EXPORT  Reserved95_IRQHandler         [WEAK]
                EXPORT  SDHC_DriverIRQHandler         [WEAK]
                EXPORT  DAC0_IRQHandler         [WEAK]
                EXPORT  DAC1_IRQHandler         [WEAK]
                EXPORT  TSI0_IRQHandler         [WEAK]
                EXPORT  MCG_IRQHandler         [WEAK]
                EXPORT  LPTMR0_IRQHandler         [WEAK]
                EXPORT  Reserved102_IRQHandler         [WEAK]
                EXPORT  PORTA_IRQHandler         [WEAK]
                EXPORT  PORTB_IRQHandler         [WEAK]
                EXPORT  PORTC_IRQHandler         [WEAK]
                EXPORT  PORTD_IRQHandler         [WEAK]
                EXPORT  PORTE_IRQHandler         [WEAK]
                EXPORT  Reserved108_IRQHandler         [WEAK]
                EXPORT  Reserved109_IRQHandler         [WEAK]
                EXPORT  SWI_IRQHandler         [WEAK]
                EXPORT  Reserved111_IRQHandler         [WEAK]
                EXPORT  Reserved112_IRQHandler         [WEAK]
                EXPORT  Reserved113_IRQHandler         [WEAK]
                EXPORT  Reserved114_IRQHandler         [WEAK]
                EXPORT  Reserved115_IRQHandler         [WEAK]
                EXPORT  Reserved116_IRQHandler         [WEAK]
                EXPORT  Reserved117_IRQHandler         [WEAK]
                EXPORT  Reserved118_IRQHandler         [WEAK]
                EXPORT  Reserved119_IRQHandler         [WEAK]
                EXPORT  DefaultISR         [WEAK]
DMA0_DriverIRQHandler
DMA1_DriverIRQHandler
DMA2_DriverIRQHandler
DMA3_DriverIRQHandler
DMA4_DriverIRQHandler
DMA5_DriverIRQHandler
DMA6_DriverIRQHandler
DMA7_DriverIRQHandler
DMA8_DriverIRQHandler
DMA9_DriverIRQHandler
DMA10_DriverIRQHandler
DMA11_DriverIRQHandler
DMA12_DriverIRQHandler
DMA13_DriverIRQHandler
DMA14_DriverIRQHandler
DMA15_DriverIRQHandler
DMA_Error_DriverIRQHandler
MCM_IRQHandler
FTFL_IRQHandler
Read_Collision_IRQHandler
LVD_LVW_IRQHandler
LLWU_IRQHandler
WDOG_EWM_IRQHandler
RNG_IRQHandler
I2C0_DriverIRQHandler
I2C1_DriverIRQHandler
SPI0_DriverIRQHandler
SPI1_DriverIRQHandler
SPI2_DriverIRQHandler
CAN0_DriverIRQHandler
I2S0_Tx_DriverIRQHandler
I2S0_Rx_DriverIRQHandler
CAN1_DriverIRQHandler
Reserved59_IRQHandler
UART0_LON_DriverIRQHandler
UART0_RX_TX_DriverIRQHandler
UART0_ERR_DriverIRQHandler
UART1_RX_TX_DriverIRQHandler
UART1_ERR_DriverIRQHandler
UART2_RX_TX_DriverIRQHandler
UART2_ERR_DriverIRQHandler
UART3_RX_TX_DriverIRQHandler
UART3_ERR_DriverIRQHandler
UART4_RX_TX_DriverIRQHandler
UART4_ERR_DriverIRQHandler
UART5_RX_TX_DriverIRQHandler
UART5_ERR_DriverIRQHandler
ADC0_IRQHandler
ADC1_IRQHandler
CMP0_IRQHandler
CMP1_IRQHandler
CMP2_IRQHandler
FTM0_IRQHandler
FTM1_IRQHandler
FTM2_IRQHandler
CMT_IRQHandler
RTC_IRQHandler
RTC_Seconds_IRQHandler
PIT0_IRQHandler
PIT1_IRQHandler
PIT2_IRQHandler
PIT3_IRQHandler
PDB0_IRQHandler
USB0_IRQHandler
USBDCD_IRQHandler
ENET_1588_Timer_DriverIRQHandler
ENET_Transmit_DriverIRQHandler
ENET_Receive_DriverIRQHandler
ENET_Error_DriverIRQHandler
Reserved95_IRQHandler
SDHC_DriverIRQHandler
DAC0_IRQHandler
DAC1_IRQHandler
TSI0_IRQHandler
MCG_IRQHandler
LPTMR0_IRQHandler
Reserved102_IRQHandler
PORTA_IRQHandler
PORTB_IRQHandler
PORTC_IRQHandler
PORTD_IRQHandler
PORTE_IRQHandler
Reserved108_IRQHandler
Reserved109_IRQHandler
SWI_IRQHandler
Reserved111_IRQHandler
Reserved112_IRQHandler
Reserved113_IRQHandler
Reserved114_IRQHandler
Reserved115_IRQHandler
Reserved116_IRQHandler
Reserved117_IRQHandler
Reserved118_IRQHandler
Reserved119_IRQHandler
DefaultISR
                B      DefaultISR
                ENDP
                  ALIGN


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

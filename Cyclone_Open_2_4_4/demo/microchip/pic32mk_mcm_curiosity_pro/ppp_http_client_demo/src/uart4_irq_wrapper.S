//Dependencies
#include "isr_support.h"

   .global uart4TxIrqWrapper
   .global uart4RxIrqWrapper
   .extern uartTxIrqHandler
   .extern uartRxIrqHandler
   .extern xISRStackTop

   .set nomips16
   .set noreorder
   .set noat

   .ent uart4TxIrqWrapper

//UART4 TX interrupt
uart4TxIrqWrapper:
   //Save the current task context
   portSAVE_CONTEXT
   //Call interrupt handler
   jal uartTxIrqHandler
   nop
   //Restore the context of the next task to execute
   portRESTORE_CONTEXT

   .end uart4TxIrqWrapper

   .ent uart4RxIrqWrapper

//UART4 RX interrupt
uart4RxIrqWrapper:
   //Save the current task context
   portSAVE_CONTEXT
   //Call interrupt handler
   jal uartRxIrqHandler
   nop
   //Restore the context of the next task to execute
   portRESTORE_CONTEXT

   .end uart4RxIrqWrapper
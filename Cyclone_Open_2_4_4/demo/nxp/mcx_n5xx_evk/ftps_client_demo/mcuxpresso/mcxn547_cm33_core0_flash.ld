/*
** ###################################################################
**     Processors:          MCXN547VDF_cm33_core0
**                          MCXN547VNL_cm33_core0
**
**     Compiler:            GNU C Compiler
**     Reference manual:    MCXNx4x Reference Manual
**     Version:             rev. 1.0, 2021-08-03
**     Build:               b231116
**
**     Abstract:
**         Linker file for the GNU C Compiler
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2023 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
** ###################################################################
*/

_StackSize = 0x800;
_HeapSize = 0x20000;

GROUP (
  "libgcc.a"
  "libc.a"
  "libm.a"
)

MEMORY
{
  /* Define each memory region */
  PROGRAM_FLASH0 (rx) : ORIGIN = 0x0, LENGTH = 0x100000 /* 1M bytes (alias Flash) */  
  PROGRAM_FLASH1 (rx) : ORIGIN = 0x100000, LENGTH = 0x100000 /* 1M bytes (alias Flash2) */  
  SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x60000 /* 384K bytes (alias RAM) */  
  SRAMX (rwx) : ORIGIN = 0x4000000, LENGTH = 0x18000 /* 96K bytes (alias RAM2) */  
  SRAMH (rwx) : ORIGIN = 0x20060000, LENGTH = 0x8000 /* 32K bytes (alias RAM3) */  
  USB_RAM (rwx) : ORIGIN = 0x400ba000, LENGTH = 0x1000 /* 4K bytes (alias RAM4) */  
}

  /* Define a symbol for the top of each memory region */
  __base_PROGRAM_FLASH0 = 0x0  ; /* PROGRAM_FLASH0 */
  __base_Flash = 0x0 ; /* Flash */
  __top_PROGRAM_FLASH0 = 0x0 + 0x100000 ; /* 1M bytes */
  __top_Flash = 0x0 + 0x100000 ; /* 1M bytes */
  __base_PROGRAM_FLASH1 = 0x100000  ; /* PROGRAM_FLASH1 */
  __base_Flash2 = 0x100000 ; /* Flash2 */
  __top_PROGRAM_FLASH1 = 0x100000 + 0x100000 ; /* 1M bytes */
  __top_Flash2 = 0x100000 + 0x100000 ; /* 1M bytes */
  __base_SRAM = 0x20000000  ; /* SRAM */
  __base_RAM = 0x20000000 ; /* RAM */
  __top_SRAM = 0x20000000 + 0x60000 ; /* 384K bytes */
  __top_RAM = 0x20000000 + 0x60000 ; /* 384K bytes */
  __base_SRAMX = 0x4000000  ; /* SRAMX */
  __base_RAM2 = 0x4000000 ; /* RAM2 */
  __top_SRAMX = 0x4000000 + 0x18000 ; /* 96K bytes */
  __top_RAM2 = 0x4000000 + 0x18000 ; /* 96K bytes */
  __base_SRAMH = 0x20060000  ; /* SRAMH */
  __base_RAM3 = 0x20060000 ; /* RAM3 */
  __top_SRAMH = 0x20060000 + 0x8000 ; /* 32K bytes */
  __top_RAM3 = 0x20060000 + 0x8000 ; /* 32K bytes */
  __base_USB_RAM = 0x400ba000  ; /* USB_RAM */
  __base_RAM4 = 0x400ba000 ; /* RAM4 */
  __top_USB_RAM = 0x400ba000 + 0x1000 ; /* 4K bytes */
  __top_RAM4 = 0x400ba000 + 0x1000 ; /* 4K bytes */

ENTRY(ResetISR)

SECTIONS
{
     .text_Flash2 : ALIGN(4)
    {
       FILL(0xff)
        *(.text_Flash2) /* for compatibility with previous releases */
        *(.text_PROGRAM_FLASH1) /* for compatibility with previous releases */
        *(.text.$Flash2)
        *(.text.$PROGRAM_FLASH1)
        *(.text_Flash2.*) /* for compatibility with previous releases */
        *(.text_PROGRAM_FLASH1.*) /* for compatibility with previous releases */
        *(.text.$Flash2.*)
        *(.text.$PROGRAM_FLASH1.*)
        *(.rodata.$Flash2)
        *(.rodata.$PROGRAM_FLASH1)
        *(.rodata.$Flash2.*)
        *(.rodata.$PROGRAM_FLASH1.*)            } > PROGRAM_FLASH1

    /* MAIN TEXT SECTION */
    .text : ALIGN(4)
    {
        FILL(0xff)
        __vectors_start__ = ABSOLUTE(.) ;
        KEEP(*(.isr_vector))
        /* Global Section Table */
        . = ALIGN(4) ;
        __section_table_start = .;
        __data_section_table = .;
        LONG(LOADADDR(.data));
        LONG(    ADDR(.data));
        LONG(  SIZEOF(.data));
        LONG(LOADADDR(.data_RAM2));
        LONG(    ADDR(.data_RAM2));
        LONG(  SIZEOF(.data_RAM2));
        LONG(LOADADDR(.data_RAM3));
        LONG(    ADDR(.data_RAM3));
        LONG(  SIZEOF(.data_RAM3));
        LONG(LOADADDR(.data_RAM4));
        LONG(    ADDR(.data_RAM4));
        LONG(  SIZEOF(.data_RAM4));
        __data_section_table_end = .;
        __bss_section_table = .;
        LONG(    ADDR(.bss));
        LONG(  SIZEOF(.bss));
        LONG(    ADDR(.bss_RAM2));
        LONG(  SIZEOF(.bss_RAM2));
        LONG(    ADDR(.bss_RAM3));
        LONG(  SIZEOF(.bss_RAM3));
        LONG(    ADDR(.bss_RAM4));
        LONG(  SIZEOF(.bss_RAM4));
        __bss_section_table_end = .;
        __section_table_end = . ;
        /* End of Global Section Table */

        *(.after_vectors*)

       *(.text*)
       *(.rodata .rodata.* .constdata .constdata.*)
       . = ALIGN(4);
    } > PROGRAM_FLASH0
    /*
     * for exception handling/unwind - some Newlib functions (in common
     * with C++ and STDC++) use this.
     */
    .ARM.extab : ALIGN(4)
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > PROGRAM_FLASH0

    .ARM.exidx : ALIGN(4)
    {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > PROGRAM_FLASH0
 
    _etext = .;
        
 
    /* USB_RAM */
    .m_usb_data (NOLOAD) :
    {
        *(m_usb_global)
    } > USB_RAM AT> USB_RAM
    /* DATA section for SRAMX */

    .data_RAM2 : ALIGN(4)
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM2 = .) ;
        PROVIDE(__start_data_SRAMX = .) ;
        *(.ramfunc.$RAM2)
        *(.ramfunc.$SRAMX)
        *(.data.$RAM2)
        *(.data.$SRAMX)
        *(.data.$RAM2.*)
        *(.data.$SRAMX.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM2 = .) ;
        PROVIDE(__end_data_SRAMX = .) ;
     } > SRAMX AT>PROGRAM_FLASH0

    /* DATA section for SRAMH */

    .data_RAM3 : ALIGN(4)
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM3 = .) ;
        PROVIDE(__start_data_SRAMH = .) ;
        *(.ramfunc.$RAM3)
        *(.ramfunc.$SRAMH)
        *(.data.$RAM3)
        *(.data.$SRAMH)
        *(.data.$RAM3.*)
        *(.data.$SRAMH.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM3 = .) ;
        PROVIDE(__end_data_SRAMH = .) ;
     } > SRAMH AT>PROGRAM_FLASH0

    /* DATA section for USB_RAM */

    .data_RAM4 : ALIGN(4)
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM4 = .) ;
        PROVIDE(__start_data_USB_RAM = .) ;
        *(.ramfunc.$RAM4)
        *(.ramfunc.$USB_RAM)
        *(.data.$RAM4)
        *(.data.$USB_RAM)
        *(.data.$RAM4.*)
        *(.data.$USB_RAM.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM4 = .) ;
        PROVIDE(__end_data_USB_RAM = .) ;
     } > USB_RAM AT>PROGRAM_FLASH0

    /* MAIN DATA SECTION */
    .uninit_RESERVED (NOLOAD) : ALIGN(4)
    {
        _start_uninit_RESERVED = .;
        KEEP(*(.bss.$RESERVED*))
       . = ALIGN(4) ;
        _end_uninit_RESERVED = .;
    } > SRAM AT> SRAM

    /* Main DATA section (SRAM) */
    .data : ALIGN(4)
    {
       FILL(0xff)
       _data = . ;
       PROVIDE(__start_data_RAM = .) ;
       PROVIDE(__start_data_SRAM = .) ;
       *(vtable)
       *(.ramfunc*)
       KEEP(*(CodeQuickAccess))
       KEEP(*(DataQuickAccess))
       *(RamFunction)
       *(.data*)
       . = ALIGN(4) ;
       _edata = . ;
       PROVIDE(__end_data_RAM = .) ;
       PROVIDE(__end_data_SRAM = .) ;
    } > SRAM AT>PROGRAM_FLASH0

    /* BSS section for SRAMX */
    .bss_RAM2 (NOLOAD) : ALIGN(4)
    {
       PROVIDE(__start_bss_RAM2 = .) ;
       PROVIDE(__start_bss_SRAMX = .) ;
       *(.bss.$RAM2)
       *(.bss.$SRAMX)
       *(.bss.$RAM2.*)
       *(.bss.$SRAMX.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM2 = .) ;
       PROVIDE(__end_bss_SRAMX = .) ;
    } > SRAMX AT> SRAMX

    /* BSS section for SRAMH */
    .bss_RAM3 (NOLOAD) : ALIGN(4)
    {
       PROVIDE(__start_bss_RAM3 = .) ;
       PROVIDE(__start_bss_SRAMH = .) ;
       *(.bss.$RAM3)
       *(.bss.$SRAMH)
       *(.bss.$RAM3.*)
       *(.bss.$SRAMH.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM3 = .) ;
       PROVIDE(__end_bss_SRAMH = .) ;
    } > SRAMH AT> SRAMH

    /* BSS section for USB_RAM */
    .bss_RAM4 (NOLOAD) : ALIGN(4)
    {
       PROVIDE(__start_bss_RAM4 = .) ;
       PROVIDE(__start_bss_USB_RAM = .) ;
       *(.bss.$RAM4)
       *(.bss.$USB_RAM)
       *(.bss.$RAM4.*)
       *(.bss.$USB_RAM.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM4 = .) ;
       PROVIDE(__end_bss_USB_RAM = .) ;
    } > USB_RAM AT> USB_RAM

    /* MAIN BSS SECTION */
    .bss (NOLOAD) : ALIGN(4)
    {
        _bss = .;
        PROVIDE(__start_bss_RAM = .) ;
        PROVIDE(__start_bss_SRAM = .) ;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4) ;
        _ebss = .;
        PROVIDE(__end_bss_RAM = .) ;
        PROVIDE(__end_bss_SRAM = .) ;
        PROVIDE(end = .);
    } > SRAM AT> SRAM

    /* NOINIT section for SRAMX */
    .noinit_RAM2 (NOLOAD) : ALIGN(4)
    {
       PROVIDE(__start_noinit_RAM2 = .) ;
       PROVIDE(__start_noinit_SRAMX = .) ;
       *(.noinit.$RAM2)
       *(.noinit.$SRAMX)
       *(.noinit.$RAM2.*)
       *(.noinit.$SRAMX.*)
       . = ALIGN(4) ;
       PROVIDE(__end_noinit_RAM2 = .) ;
       PROVIDE(__end_noinit_SRAMX = .) ;
    } > SRAMX AT> SRAMX

    /* NOINIT section for SRAMH */
    .noinit_RAM3 (NOLOAD) : ALIGN(4)
    {
       PROVIDE(__start_noinit_RAM3 = .) ;
       PROVIDE(__start_noinit_SRAMH = .) ;
       *(.noinit.$RAM3)
       *(.noinit.$SRAMH)
       *(.noinit.$RAM3.*)
       *(.noinit.$SRAMH.*)
       . = ALIGN(4) ;
       PROVIDE(__end_noinit_RAM3 = .) ;
       PROVIDE(__end_noinit_SRAMH = .) ;
    } > SRAMH AT> SRAMH

    /* NOINIT section for USB_RAM */
    .noinit_RAM4 (NOLOAD) : ALIGN(4)
    {
       PROVIDE(__start_noinit_RAM4 = .) ;
       PROVIDE(__start_noinit_USB_RAM = .) ;
       *(.noinit.$RAM4)
       *(.noinit.$USB_RAM)
       *(.noinit.$RAM4.*)
       *(.noinit.$USB_RAM.*)
       . = ALIGN(4) ;
       PROVIDE(__end_noinit_RAM4 = .) ;
       PROVIDE(__end_noinit_USB_RAM = .) ;
    } > USB_RAM AT> USB_RAM

    /* DEFAULT NOINIT SECTION */
    .noinit (NOLOAD): ALIGN(4)
    {
        _noinit = .;
        PROVIDE(__start_noinit_RAM = .) ;
        PROVIDE(__start_noinit_SRAM = .) ;
        *(.noinit*)
         . = ALIGN(4) ;
        _end_noinit = .;
       PROVIDE(__end_noinit_RAM = .) ;
       PROVIDE(__end_noinit_SRAM = .) ;        
    } > SRAM AT> SRAM

    /* Reserve and place Heap within memory map */
    .heap (NOLOAD) :  ALIGN(4)
    {
        _pvHeapStart = .;
        . += _HeapSize;
        . = ALIGN(4);
        _pvHeapLimit = .;
    } > SRAM

     /* Reserve space in memory for Stack */
    .heap2stackfill (NOLOAD) :
    {
        . += _StackSize;
    } > SRAM
    /* Locate actual Stack in memory map */
    .stack ORIGIN(SRAM) + LENGTH(SRAM) - _StackSize - 0 (NOLOAD) :  ALIGN(4)
    {
        _vStackBase = .;
        . = ALIGN(4);
        _vStackTop = . + _StackSize;
    } > SRAM

    /* Provide basic symbols giving location and size of main text
     * block, including initial values of RW data sections. Note that
     * these will need extending to give a complete picture with
     * complex images (e.g multiple Flash banks).
     */
    _image_start = LOADADDR(.text);
    _image_end = LOADADDR(.data) + SIZEOF(.data);
    _image_size = _image_end - _image_start;
}
_StackSize = 4K;
_HeapSize = 110K;

GROUP (
  "libgcc.a"
  "libc.a"
  "libm.a"
)

MEMORY
{
  SRAM_DTC (rwx)                 : ORIGIN = 0x20000000, LENGTH = 64K
  SRAM_ITC (rwx)                 : ORIGIN = 0x00000000, LENGTH = 64K
  SRAM_OC (rwx)                  : ORIGIN = 0x20200000, LENGTH = 112K
  SRAM_OC_NONCACHEABLE (rwx)     : ORIGIN = 0x2021C000, LENGTH = 16K
  BOARD_FLASH (rx)               : ORIGIN = 0x60000000, LENGTH = 4M
  BOARD_SDRAM (rwx)              : ORIGIN = 0x80000000, LENGTH = 30M
  BOARD_SDRAM_NONCACHEABLE (rwx) : ORIGIN = 0x81e00000, LENGTH = 2M
}

ENTRY(ResetISR)

SECTIONS
{
     /* Image Vector Table and Boot Data for booting from external flash */
    .boot_hdr : ALIGN(4)
    {
        FILL(0xff)
        __boot_hdr_start__ = ABSOLUTE(.) ;
        KEEP(*(.boot_hdr.conf))
        . = 0x1000 ;
        KEEP(*(.boot_hdr.ivt))
        . = 0x1020 ;
        KEEP(*(.boot_hdr.boot_data))
        . = 0x1030 ;
        KEEP(*(.boot_hdr.dcd_data))
        __boot_hdr_end__ = ABSOLUTE(.) ;
        . = 0x2000 ;
    } >BOARD_FLASH

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
        LONG(LOADADDR(.data_RAM5));
        LONG(    ADDR(.data_RAM5));
        LONG(  SIZEOF(.data_RAM5));
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
        LONG(    ADDR(.bss_RAM5));
        LONG(  SIZEOF(.bss_RAM5));
        __bss_section_table_end = .;
        __section_table_end = . ;
        /* End of Global Section Table */

        *(.after_vectors*)

    } > BOARD_FLASH

    .text : ALIGN(4)
    {
       *(.text*)
       *(.rodata .rodata.* .constdata .constdata.*)
       . = ALIGN(4);
    } > BOARD_FLASH
    /*
     * for exception handling/unwind - some Newlib functions (in common
     * with C++ and STDC++) use this. 
     */
    .ARM.extab : ALIGN(4) 
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > BOARD_FLASH

    __exidx_start = .;

    .ARM.exidx : ALIGN(4)
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > BOARD_FLASH
    __exidx_end = .;
 
    _etext = .;
        
    /* DATA section for BOARD_SDRAM_NONCACHEABLE */

    .data_RAM2 : ALIGN(4)
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM2 = .) ;
        *(.ramfunc.$RAM2)
        *(.ramfunc.$BOARD_SDRAM_NONCACHEABLE)
       *(NonCacheable.init)
        *(.data.$RAM2)
        *(.data.$BOARD_SDRAM_NONCACHEABLE)
        *(.data.$RAM2.*)
        *(.data.$BOARD_SDRAM_NONCACHEABLE.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM2 = .) ;
     } > SRAM_OC_NONCACHEABLE AT>BOARD_FLASH /*BOARD_SDRAM_NONCACHEABLE*/
    /* DATA section for SRAM_DTC */

    .data_RAM3 : ALIGN(4)
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM3 = .) ;
        *(.ramfunc.$RAM3)
        *(.ramfunc.$SRAM_DTC)
        *(.data.$RAM3)
        *(.data.$SRAM_DTC)
        *(.data.$RAM3.*)
        *(.data.$SRAM_DTC.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM3 = .) ;
     } > SRAM_DTC AT>BOARD_FLASH
    /* DATA section for SRAM_ITC */

    .data_RAM4 : ALIGN(4)
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM4 = .) ;
        *(.ramfunc.$RAM4)
        *(.ramfunc.$SRAM_ITC)
        *(.data.$RAM4)
        *(.data.$SRAM_ITC)
        *(.data.$RAM4.*)
        *(.data.$SRAM_ITC.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM4 = .) ;
     } > SRAM_ITC AT>BOARD_FLASH
    /* DATA section for SRAM_OC */

    .data_RAM5 : ALIGN(4)
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM5 = .) ;
        *(.ramfunc.$RAM5)
        *(.ramfunc.$SRAM_OC)
        *(.data.$RAM5)
        *(.data.$SRAM_OC)
        *(.data.$RAM5.*)
        *(.data.$SRAM_OC.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM5 = .) ;
     } > SRAM_OC AT>BOARD_FLASH
    /* MAIN DATA SECTION */
    .uninit_RESERVED (NOLOAD) :
    {
        . = ALIGN(4) ;
        KEEP(*(.bss.$RESERVED*))
       . = ALIGN(4) ;
        _end_uninit_RESERVED = .;
    } > SRAM_DTC

    /* Main DATA section (SRAM_DTC) */
    .data : ALIGN(4)
    {
       FILL(0xff)
       _data = . ;
       *(vtable)
       *(.ramfunc*)
       *(.data*)
       . = ALIGN(4) ;
       _edata = . ;
    } > SRAM_DTC AT>BOARD_FLASH

    /* BSS section for BOARD_SDRAM_NONCACHEABLE */
    .bss_RAM2 :
    {
       . = ALIGN(4) ;
       PROVIDE(__start_bss_RAM2 = .) ;
       *(NonCacheable)
       *(.bss.$RAM2)
       *(.bss.$BOARD_SDRAM_NONCACHEABLE)
       *(.bss.$RAM2.*)
       *(.bss.$BOARD_SDRAM_NONCACHEABLE.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM2 = .) ;
    } > SRAM_OC_NONCACHEABLE /*BOARD_SDRAM_NONCACHEABLE*/

    /* BSS section for SRAM_DTC */
    .bss_RAM3 :
    {
       . = ALIGN(4) ;
       PROVIDE(__start_bss_RAM3 = .) ;
       *(.bss.$RAM3)
       *(.bss.$SRAM_DTC)
       *(.bss.$RAM3.*)
       *(.bss.$SRAM_DTC.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM3 = .) ;
    } > SRAM_DTC

    /* BSS section for SRAM_ITC */
    .bss_RAM4 :
    {
       . = ALIGN(4) ;
       PROVIDE(__start_bss_RAM4 = .) ;
       *(.bss.$RAM4)
       *(.bss.$SRAM_ITC)
       *(.bss.$RAM4.*)
       *(.bss.$SRAM_ITC.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM4 = .) ;
    } > SRAM_ITC

    /* BSS section for SRAM_OC */
    .bss_RAM5 :
    {
       . = ALIGN(4) ;
       PROVIDE(__start_bss_RAM5 = .) ;
       *(.bss.$RAM5)
       *(.bss.$SRAM_OC)
       *(.bss.$RAM5.*)
       *(.bss.$SRAM_OC.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM5 = .) ;
    } > SRAM_OC

    /* MAIN BSS SECTION */
    .bss :
    {
        . = ALIGN(4) ;
        _bss = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4) ;
        _ebss = .;
        PROVIDE(end = .);
    } > SRAM_DTC

    /* NOINIT section for BOARD_SDRAM_NONCACHEABLE */
    .noinit_RAM2 (NOLOAD) :
    {
       . = ALIGN(4) ;
       *(.noinit.$RAM2)
       *(.noinit.$BOARD_SDRAM_NONCACHEABLE)
       *(.noinit.$RAM2.*)
       *(.noinit.$BOARD_SDRAM_NONCACHEABLE.*)
       . = ALIGN(4) ;
    } > SRAM_OC_NONCACHEABLE /*BOARD_SDRAM_NONCACHEABLE*/

    /* NOINIT section for SRAM_DTC */
    .noinit_RAM3 (NOLOAD) :
    {
       . = ALIGN(4) ;
       *(.noinit.$RAM3)
       *(.noinit.$SRAM_DTC)
       *(.noinit.$RAM3.*)
       *(.noinit.$SRAM_DTC.*)
       . = ALIGN(4) ;
    } > SRAM_DTC

    /* NOINIT section for SRAM_ITC */
    .noinit_RAM4 (NOLOAD) :
    {
       . = ALIGN(4) ;
       *(.noinit.$RAM4)
       *(.noinit.$SRAM_ITC)
       *(.noinit.$RAM4.*)
       *(.noinit.$SRAM_ITC.*)
       . = ALIGN(4) ;
    } > SRAM_ITC

    /* NOINIT section for SRAM_OC */
    .noinit_RAM5 (NOLOAD) :
    {
       . = ALIGN(4) ;
       *(.noinit.$RAM5)
       *(.noinit.$SRAM_OC)
       *(.noinit.$RAM5.*)
       *(.noinit.$SRAM_OC.*)
       . = ALIGN(4) ;
    } > SRAM_OC

    /* NOINIT section for SRAM_OC_NONCACHEABLE */
    .noinit_RAM5_non_cacheable (NOLOAD) :
    {
       . = ALIGN(4) ;
       *(.ram_no_cache)
       . = ALIGN(4) ;
    } > SRAM_OC_NONCACHEABLE

    /* DEFAULT NOINIT SECTION */
    .noinit (NOLOAD):
    {
         . = ALIGN(4) ;
        _noinit = .;
        *(.noinit*)
         . = ALIGN(4) ;
        _end_noinit = .;
    } > SRAM_DTC

    /* Reserve and place Heap within memory map */
    .heap :  ALIGN(4)
    {
        _pvHeapStart = .;
        . += _HeapSize;
        . = ALIGN(4);
        _pvHeapLimit = .;
    } > SRAM_OC

     /* Reserve space in memory for Stack */
    .heap2stackfill  :
    {
        . += _StackSize;
    } > SRAM_DTC
    /* Locate actual Stack in memory map */
    .stack ORIGIN(SRAM_DTC) + LENGTH(SRAM_DTC) - _StackSize - 0:  ALIGN(4)
    {
        _vStackBase = .;
        . = ALIGN(4);
        _vStackTop = . + _StackSize;
    } > SRAM_DTC

    /* Provide basic symbols giving location and size of main text
     * block, including initial values of RW data sections. Note that
     * these will need extending to give a complete picture with
     * complex images (e.g multiple Flash banks).
     */
    _image_start = LOADADDR(.text);
    _image_end = LOADADDR(.data) + SIZEOF(.data);
    _image_size = _image_end - _image_start;
}

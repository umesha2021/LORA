ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 256K
  RAM   (rwx): ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
  .isr_vector : 
  {
    KEEP(*(.isr_vector))
  } > FLASH

  .text : 
  {
    *(.text*)
    *(.rodata*)
    *(.glue_7)
    *(.glue_7t)
  } > FLASH

  .data : AT (ADDR(.text) + SIZEOF(.text))
  {
    _sdata = .;
    *(.data*)
    _edata = .;
  } > RAM

  _sidata = LOADADDR(.data);

  .bss :
  {
    _sbss = .;
    *(.bss*)
    *(COMMON)
    _ebss = .;
  } > RAM

  . = ALIGN(4);
  _estack = ORIGIN(RAM) + LENGTH(RAM);
}


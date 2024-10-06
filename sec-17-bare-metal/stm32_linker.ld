/*
Notes: 
- all the sections in the linker script are given in caps
- in SECTIONS, *(.text) means merge all text from input files
- > VMA AT LMA - so VMA is the 
- VMA: The Virtual Memory Address is the address where a section is 
       expected to reside during program exec
- LMA: The Load Memory Address is the address where a section will be loaded into memory
- the descripency exists in the .data section, as the data must be copied from the FLASH memory
  to the SRAM memory. This is just dynamic data that can change during exection, 
  no need to waste FLASH memory
- to know the VMA and LMA: `arm-none-eabi-objdump -h <whatever>.o`
- to link use with no std lib:
```
arm-none-eabi-gcc -nostdlib -T stm32_linker.ld *.o -o run.elf

```


 */

ENTRY(Reset_Handler)

MEMORY
{
    FLASH(rx):ORIGIN = 0x08000000, LENGTH = 1024K
    SRAM(rwx):ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
    .text :
    {
        *(.isr_vector)
        *(.text)
        *(.rodata)
        /* align the location counter to the next word boundary*/
        . = ALIGN(4);
        /* the `.` is the location counter, it gets updated with the length of all the above merged sections */
        _end_of_text_section = .;
    }> FLASH AT> FLASH

    .data :
    {
        /* the location counter tracks the VMA of the current section so using here would mean
           this address: 0x20000000
        */
        _start_of_data_section = .;
        *(.data)
        . = ALIGN(4);
        _end_of_data_section = .;
    }> SRAM AT> FLASH

    .bss :
    {
        _start_of_bss_section = .;
        *(.bss)
        *(COMMON)
        . = ALIGN(4);
        _end_of_bss_section = .;
    }> SRAM

}
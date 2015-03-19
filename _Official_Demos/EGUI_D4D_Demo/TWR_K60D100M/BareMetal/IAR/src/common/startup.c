/*
 * File:    startup.c
 * Purpose: Generic Kinetis startup code
 *
 * Notes:   
 */

#include "common.h"

#pragma section = ".data"
#pragma section = ".data_init"
#pragma section = ".bss"
#pragma section = "CodeRelocate"
#pragma section = "CodeRelocateRam" 

#ifndef NEW_COMMON_DEFINITION
/******************************************************************************
 * System register file definitions                                           *
 ******************************************************************************/
__root __no_init volatile uint8 SystemRegisterFile[32] @ 0x40041000;
#endif

/********************************************************************/
void
common_startup(void)
{
//    extern char __DATA_ROM[];
//    extern char __DATA_RAM[];
//    extern char __DATA_END[];
  
    /* Declare a counter we'll use in all of the copy loops */
    uint32 n;
 
 
    /* Addresses for VECTOR_TABLE come from the linker file */  
    extern uint32 __VECTOR_TABLE[];

    /* Point the VTOR to the new copy of the vector table */
    write_vtor((uint32)__VECTOR_TABLE);    
    
    /* Get the addresses for the .data section (initialized data section) */
    uint8* data_ram = __section_begin(".data");
    uint8* data_rom = __section_begin(".data_init");
    uint8* data_rom_end = __section_end(".data_init");
    
    /* Copy initialized data from ROM to RAM */
    n = data_rom_end - data_rom;
    while (n--)
      *data_ram++ = *data_rom++;
 
 
    /* Get the addresses for the .bss section (zero-initialized data) */
    uint8* bss_start = __section_begin(".bss");
    uint8* bss_end = __section_end(".bss");
    
    /* Clear the zero-initialized data section */
    n = bss_end - bss_start;
    while(n--)
      *bss_start++ = 0;    
    
    /* Get addresses for any code sections that need to be copied from ROM to RAM.
     * The IAR tools have a predefined keyword that can be used to mark individual
     * functions for execution from RAM. Add "__ramfunc" before the return type in
     * the function prototype for any routines you need to execute from RAM instead 
     * of ROM. ex: __ramfunc void foo(void);
     */
    uint8* code_relocate_ram = __section_begin("CodeRelocateRam");
    uint8* code_relocate = __section_begin("CodeRelocate");
    uint8* code_relocate_end = __section_end("CodeRelocate");
    
    /* Copy functions from ROM to RAM */
    n = code_relocate_end - code_relocate;
    while (n--)
      *code_relocate_ram++ = *code_relocate++;
}
/********************************************************************/

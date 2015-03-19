/******************************************************************************
* File:    isr.h
* Purpose: Define interrupt service routines referenced by the vector table.
* Note: Only "vectors.c" should include this header file.
******************************************************************************/
#ifndef __ISR_H
#define __ISR_H

extern void pit_ch0_isr (void);

#undef  VECTOR_084
#define VECTOR_084 pit_ch0_isr

#endif  //__ISR_H

/* End of "isr.h" */

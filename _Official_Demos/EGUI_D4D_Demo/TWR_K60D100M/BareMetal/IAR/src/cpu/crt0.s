/*
 * File:	crt0.s
 * Purpose:	Lowest level routines for Kinetis.
 *
 * Notes:	
 *
 */

;         AREA   Crt0, CODE, READONLY      ; name this block of code
  SECTION .noinit : CODE

        EXPORT  __startup
__startup
      MOVS    r0,#0                   ; Initialize the GPRs
      MOV     r1,r0
      MOV     r2,r0
      MOV     r3,r0
      MOV     r4,r0
      MOV     r5,r0
      MOV     r6,r0
      MOV     r7,r0
      MOV     r8,r0
      MOV     r9,r0
      MOV     r10,r0
      MOV     r11,r0
      MOV     r12,r0
	CPSID   i                       ; Disable interrupt by default
        import start
        BL      start                   ; call the C code
__done
        B       __done


        END

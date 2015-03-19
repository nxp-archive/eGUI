/*
 * File:	arch_delay.s
 * Purpose:	Delay software execution by given number of core clock ticks.
 *
 * Notes:
 */

;         AREA   arch_delay, CODE, READONLY      ; name this block of code
  SECTION .text : CODE
      EXPORT  arch_delay
arch_delay
      subs  r0,#8   ; subtract function entry and exit code execution ticks
loop: subs  r0,#5
      bpl   loop   
      bx    lr
      end
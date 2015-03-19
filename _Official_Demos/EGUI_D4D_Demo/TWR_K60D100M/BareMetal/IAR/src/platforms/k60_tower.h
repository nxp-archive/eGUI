/*
 * File:        k60_tower.h
 * Purpose:     Definitions for the Kinetis K60 tower card
 *
 * Notes:
 */

#ifndef __K60_TOWER_H__
#define __K60_TOWER_H__

/********************************************************************/

/* Defines specific to the K60 tower board */


/* Define for the CPU on the K60 board */
#define CPU_MK60N512VMD100

/*
 * System Bus Clock Info
 */
#define REF_CLK             XTAL50 /* 50MHz crystal                               */
#define CORE_CLK_MHZ        PLL96  /* 96MHz is only freq tested for a clock input */

#endif /* __K60_TOWER_H__ */

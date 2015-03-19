/*****************************************************************************
 * (c) Copyright 2010, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      common.h
 * @author    R55013
 * @version   1.0.7.0
 * @date      Apr-4-2013
 * @brief     Common macros header file.
 ******************************************************************************/
#ifndef __COMMON_H
#define __COMMON_H

#ifndef NEW_COMMON_DEFINITION
/*
 * Misc. Defines
 */
#ifdef	FALSE
#undef	FALSE
#endif
#define FALSE	(0)

#ifdef	TRUE
#undef	TRUE
#endif
#define	TRUE	(1)

#ifdef	NULL
#undef	NULL
#endif
#define NULL	(0)

#ifdef  ON
#undef  ON
#endif
#define ON      (1)

#ifdef  OFF
#undef  OFF
#endif
#define OFF     (0)

/***********************************************************************/
/*
 * The basic data types
 */
typedef unsigned char		uint8;  /*  8 bits */
typedef unsigned short int	uint16; /* 16 bits */
typedef unsigned long int	uint32; /* 32 bits */

typedef char			int8;   /*  8 bits */
typedef short int	        int16;  /* 16 bits */
typedef int		        int32;  /* 32 bits */

typedef volatile int8		vint8;  /*  8 bits */
typedef volatile int16		vint16; /* 16 bits */
typedef volatile int32		vint32; /* 32 bits */

typedef volatile uint8		vuint8;  /*  8 bits */
typedef volatile uint16		vuint16; /* 16 bits */
typedef volatile uint32		vuint32; /* 32 bits */


/* 
 * Include the platform specific header file 
 */
#if (defined(TWR_K40X256))
  #include "k40_tower.h"
#elif (defined(TWR_K60N512))
 #include "k60_tower.h"
#else
  #error "No valid platform defined"
#endif

/* 
 * Include the cpu specific header file 
 */
#if (defined(CPU_MK40X256VMD100))
  #include "MK40X256VMD100.h"
#elif (defined(CPU_MK40N512VMD100))
  #include "MK40N512VMD100.h"
#elif (defined(CPU_MK60N512VMD100))
  #include "MK60N512VMD100.h"
#else
  #error "No valid CPU defined"
#endif


/* 
 * Include any toolchain specfic header files 
 */
#if (defined(__MWERKS__))
  #include "mwerks.h"
#elif (defined(__DCC__))
  #include "build/wrs/diab.h"
#elif (defined(__ghs__))
  #include "build/ghs/ghs.h"
#elif (defined(__GNUC__))
  #include "build/gnu/gnu.h"
#elif (defined(IAR))
  #include "iar.h"
#else
#warning "No toolchain specific header included"
#endif

/* defines for peripheral configuration structures                            */ 
#define SET(mask)       mask
#define CLR(mask)       0

/* 
 * Common macros
 */
#define REG_SetVal(reg,mask,val,shift)  { reg = ((reg & ~mask)|(val<<shift)); }
//#define REG_SetVal(reg,mask,x)  { reg=((reg&~mask##_MASK)|(x<<mask##_SHIFT)); }

/******************************************************************************
 * System register file declaration                                           *
 ******************************************************************************/
extern volatile uint8 SystemRegisterFile[];

/* 
 * Include common utilities
 */
#include "intrinsics.h"
#include "startup.h"
#include "arm_cm4.h"
#include "arch_delay.h"
#include "dsp.h"

#else

  /******************************************************************************
   * The basic data types                                                       *
   ******************************************************************************/
  typedef unsigned char		uint8;  /*  8 bits */
  typedef unsigned short int	uint16; /* 16 bits */
  typedef unsigned long int	uint32; /* 32 bits */

  typedef char			int8;   /*  8 bits */
  typedef short int	        int16;  /* 16 bits */
  typedef int		        int32;  /* 32 bits */

  typedef volatile int8		vint8;  /*  8 bits */
  typedef volatile int16		vint16; /* 16 bits */
  typedef volatile int32		vint32; /* 32 bits */

  typedef volatile uint8		vuint8;  /*  8 bits */
  typedef volatile uint16		vuint16; /* 16 bits */
  typedef volatile uint32		vuint32; /* 32 bits */

  /******************************************************************************
   * Common macros and defines                                                  *
   ******************************************************************************/
  #ifndef NULL
    #define NULL (void*)0
  #endif

  #define TRUE                        1
  #define FALSE                       0

  #define SET(mask)                       mask
  #define CLR(mask)                       0
  #define REG_SetVal(reg,mask,val,shift)  { reg = ((reg & ~mask)|(val<<shift)); }

  /******************************************************************************
   * System register file declaration                                           *
   ******************************************************************************/
  extern __root __no_init volatile uint8 SystemRegisterFile[];

  /******************************************************************************
   * Include common utilities                                                   *
   ******************************************************************************/
  #include "appconfig.h"
  #if (defined(CPU_MK40X256VMD100))
    #include "MK40X256VMD100.h"
  #elif (defined(CPU_MK40N512VMD100))
    #include "MK40N512VMD100.h"
  #elif (defined(CPU_MK60N512VMD100))
    #include "MK60N512VMD100.h"
  #else
    #error "No valid CPU defined"
  #endif

  #include "intrinsics.h"
  #include "startup.h"
  #include "arm_cm4.h"
  #include "arch_delay.h"
  #include "dsp.h"

#endif

/********************************************************************/

#endif /* _COMMON_H_ */

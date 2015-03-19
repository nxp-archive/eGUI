/*****************************************************************************
 * (c) Copyright 2010, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      pit.h
 * @author    R55013
 * @version   1.0.4.0
 * @date      Mar-8-2011
 * @brief     PIT driver header file.
 ******************************************************************************/
#ifndef __PIT_H
#define __PIT_H 
 
/******************************************************************************
 * definition configuration structures                                        *
 ******************************************************************************/
typedef struct { uint32 TCTRL;  } tPIT_CH;

/******************************************************************************
 * default configurations                                                     *
 ******************************************************************************/
#define PIT_CH_CONFIG     /* interrupt enabled and timer active           */  \
(tPIT_CH){                                                                    \
/* TCTRL  */ SET(PIT_TCTRL_TIE_MASK)|SET(PIT_TCTRL_TEN_MASK),                 \
}

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
typedef void (*PIT_CH_CALLBACK)(void);

/* PIT macro definitions                                                      */
#define PIT0_LDVAL(x)                     { PIT_LDVAL0 = (x); }
#define PIT1_LDVAL(x)                     { PIT_LDVAL1 = (x); }
#define PIT2_LDVAL(x)                     { PIT_LDVAL2 = (x); }
#define PIT3_LDVAL(x)                     { PIT_LDVAL3 = (x); }
/***************************************************************************//*!
 * @brief   Macro sets load value register.
 * @param   ch        - PIT0|PIT1|PIT2|PIT3
 * @param   loadValue - 32-bit load register value 
 * @return  none
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define PIT_SetLoadVal(ch,loadValue)      ch##_LDVAL(loadValue)

/***************************************************************************//*!
 * @brief   Macro enables PIT modules.
 * @return  none
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define PIT_Enable()                      { PIT_MCR &= ~PIT_MCR_MDIS_MASK; }

/***************************************************************************//*!
 * @brief   Macro enables PIT modules in debug mode.
 * @return  none
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define PIT_DebugFreezeOn()               { PIT_MCR |=   PIT_MCR_FRZ_MASK; }

/***************************************************************************//*!
 * @brief   Macro disables PIT modules in debug mode.
 * @return  none
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define PIT_DebugFreezeOff()              { PIT_MCR &=  ~PIT_MCR_FRZ_MASK; }

/* Function redefinition                                                      */
/***************************************************************************//*!
 * @brief   PIT initialization function.
 * @param   ch        - PIT0|PIT1|PIT2|PIT3
 * @param   cfg       - PIT module configuration structure passed by value: 
 *                      PIT_CH_CONFIG.
 * @param   loadValue - 32-bit load register value  
 * @param   ip        - interrupt priority 0..15
 * @param   callback  - pointer to TPM_CALLBACK function
 * @return  none
 * @note    Implemented as function call.
 ******************************************************************************/
#define PIT_Init(ch,cfg,loadValue,ip,callback)   ch##_Init(cfg,loadValue,ip,callback)
  
/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/    
extern void PIT0_Init  (tPIT_CH ch, uint32 loadValue, uint8 ip, PIT_CH_CALLBACK pCallback);
extern void PIT1_Init  (tPIT_CH ch, uint32 loadValue, uint8 ip, PIT_CH_CALLBACK pCallback);
extern void PIT2_Init  (tPIT_CH ch, uint32 loadValue, uint8 ip, PIT_CH_CALLBACK pCallback);
extern void PIT3_Init  (tPIT_CH ch, uint32 loadValue, uint8 ip, PIT_CH_CALLBACK pCallback);

#endif /* __PIT_H */ 
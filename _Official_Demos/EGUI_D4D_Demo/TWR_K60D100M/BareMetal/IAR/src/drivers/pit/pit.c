/*****************************************************************************
 * (c) Copyright 2010, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      pit.c
 * @author    R55013
 * @version   1.0.3.0
 * @date      May-23-2012
 * @brief     PIT driver implementation.
 * @par       Driver example:
 * @include   src\projects\drivers_test\drivers_test.c
 * @par       Interrupt vector definition(s):
 * @include   src\projects\drivers_test\isr.h		
 ******************************************************************************/
#include "common.h"
#include "pit.h"

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static PIT_CH_CALLBACK volatile pCallbackCH0=NULL;
static PIT_CH_CALLBACK volatile pCallbackCH1=NULL;
static PIT_CH_CALLBACK volatile pCallbackCH2=NULL;
static PIT_CH_CALLBACK volatile pCallbackCH3=NULL;

/******************************************************************************
 * interrupt functions prototype                                              *
 ******************************************************************************/
void pit_ch0_isr (void);
void pit_ch1_isr (void);
void pit_ch2_isr (void);
void pit_ch3_isr (void);

/******************************************************************************
 * Public functions definitions                                               *
 ******************************************************************************/
#pragma diag_suppress=Pa082
void PIT0_Init  (tPIT_CH ch, uint32 loadValue, uint8 ip, PIT_CH_CALLBACK pCallback)
{
  /* interrupt configuration                                                  */
  if (pCallback != NULL) { pCallbackCH0 = pCallback; NVIC_SetIsr(84,ip); }
  /* timer configuration                                                      */
  PIT_LDVAL0  = loadValue;
  PIT_TCTRL0  = ch.TCTRL;     
}

void PIT1_Init  (tPIT_CH ch, uint32 loadValue, uint8 ip, PIT_CH_CALLBACK pCallback)
{
  /* interrupt configuration                                                  */
  if (pCallback != NULL) { pCallbackCH1 = pCallback; NVIC_SetIsr(85,ip); }
  /* timer configuration                                                      */
  PIT_LDVAL1  = loadValue;
  PIT_TCTRL1  = ch.TCTRL;     
}

void PIT2_Init  (tPIT_CH ch, uint32 loadValue, uint8 ip, PIT_CH_CALLBACK pCallback)
{
  /* interrupt configuration                                                  */
  if (pCallback != NULL) { pCallbackCH2 = pCallback; NVIC_SetIsr(86,ip); }
  /* timer configuration                                                      */
  PIT_LDVAL2  = loadValue;
  PIT_TCTRL2  = ch.TCTRL;     
}

void PIT3_Init  (tPIT_CH ch, uint32 loadValue, uint8 ip, PIT_CH_CALLBACK pCallback)
{
  /* interrupt configuration                                                  */
  if (pCallback != NULL) { pCallbackCH3 = pCallback; NVIC_SetIsr(87,ip); }
  /* timer configuration                                                      */
  PIT_LDVAL3  = loadValue;
  PIT_TCTRL3  = ch.TCTRL;     
}

/******************************************************************************
 * interrupt functions definitions                                            *
 ******************************************************************************/
vuint32 dummy;
void pit_ch0_isr (void) 
{ 
  PIT_TFLG0   = PIT_TFLG_TIF_MASK;  /* clear peripheral interrupt flag                    */  
  dummy = PIT_TCTRL0;               /* dummy read TCTRL0, necessary for 0M33Z mask -> bug */ 
  /* process interrupt callback function                                                  */  
  if (pCallbackCH0 != (PIT_CH_CALLBACK)NULL) { pCallbackCH0 (); }
}

void pit_ch1_isr (void) 
{ 
  PIT_TFLG1   = PIT_TFLG_TIF_MASK;  /* clear peripheral interrupt flag                    */
  dummy = PIT_TCTRL1;               /* dummy read TCTRL1, necessary for 0M33Z mask -> bug */ 
  /* process interrupt callback function                                                  */  
  if (pCallbackCH1 != (PIT_CH_CALLBACK)NULL) { pCallbackCH1 (); }
}

void pit_ch2_isr (void) 
{ 
  PIT_TFLG2   = PIT_TFLG_TIF_MASK;  /* clear peripheral interrupt flag                    */
  dummy = PIT_TCTRL2;               /* dummy read TCTRL2, necessary for 0M33Z mask -> bug */ 
  /* process interrupt callback function                                                  */  
  if (pCallbackCH2 != (PIT_CH_CALLBACK)NULL) { pCallbackCH2 (); }
}

void pit_ch3_isr (void) 
{ 
  PIT_TFLG3   = PIT_TFLG_TIF_MASK;  /* clear peripheral interrupt flag                    */
  dummy = PIT_TCTRL3;               /* dummy read TCTRL3, necessary for 0M33Z mask -> bug */ 
  /* process interrupt callback function                                                  */  
  if (pCallbackCH3 != (PIT_CH_CALLBACK)NULL) { pCallbackCH3 (); }
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/
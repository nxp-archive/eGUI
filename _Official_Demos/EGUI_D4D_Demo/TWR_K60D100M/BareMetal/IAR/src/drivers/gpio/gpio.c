/*****************************************************************************
 * (c) Copyright 2010, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      gpio.c
 * @author    R55013
 * @version   1.0.5.0
 * @date      May-4-2011
 * @brief     GPIO and PORT drivers implementation.
 * @par       Driver example:
 * @include   drivers_test\drivers_test.c
 * @par       Interrupt vector definition(s):
 * @include   drivers_test\isr.h		
 ******************************************************************************/
#include "common.h"
#include "gpio.h"

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
static PORT_CALLBACK volatile pCallbackPORTA=NULL;
static PORT_CALLBACK volatile pCallbackPORTB=NULL;
static PORT_CALLBACK volatile pCallbackPORTC=NULL;
static PORT_CALLBACK volatile pCallbackPORTD=NULL;
static PORT_CALLBACK volatile pCallbackPORTE=NULL;

/******************************************************************************
 * interrupt functions prototype                                              *
 ******************************************************************************/
void porta_isr (void);
void portb_isr (void);
void portc_isr (void);
void portd_isr (void);
void porte_isr (void);

/******************************************************************************
 * Public functions definitions                                               *
 ******************************************************************************/
#pragma diag_suppress=Pa082
void PORTA_Init (tPORT port, uint32 pin_mask, uint8 ip, PORT_CALLBACK pCallback)
{
  register uint16 i;
  
  /* interrupt configuration                                                  */
  if (pCallback != NULL) { pCallbackPORTA = pCallback; NVIC_SetIsr(INT_PORTA,ip); }

  /* port configuration                                                       */
  for (i=0; i<32; i++)
    if(pin_mask & (uint32)(1l << i)) { PORTA_BASE_PTR->PCR[i] = port.PCR; }
  PORTA_DFER |= (port.DFER & pin_mask); /* DFER content OR-ed with pin_mask   */ 
  PORTA_DFCR  = port.DFCR;
  PORTA_DFWR  = port.DFWR;  
  PORTA_ISFR &= ~pin_mask;  
}

void PORTB_Init (tPORT port, uint32 pin_mask, uint8 ip, PORT_CALLBACK pCallback)
{
  register uint16 i;
  
  /* interrupt configuration                                                  */
  if (pCallback != NULL) { pCallbackPORTB = pCallback; NVIC_SetIsr(INT_PORTB,ip); }
  
  /* port configuration                                                       */
  for (i=0; i<32; i++)
    if(pin_mask & (uint32)(1l << i)) { PORTB_BASE_PTR->PCR[i] = port.PCR; }
  PORTB_DFER |= (port.DFER & pin_mask); /* DFER content OR-ed with pin_mask   */ 
  PORTB_DFCR  = port.DFCR;              
  PORTB_DFWR  = port.DFWR;  
  PORTB_ISFR &= ~pin_mask;  
}

void PORTC_Init (tPORT port, uint32 pin_mask, uint8 ip, PORT_CALLBACK pCallback)
{
  register uint16 i;
  
  /* interrupt configuration                                                  */
  if (pCallback != NULL) { pCallbackPORTC = pCallback; NVIC_SetIsr(INT_PORTC,ip); }
  
  /* port configuration                                                       */
  for (i=0; i<32; i++)
    if(pin_mask & (uint32)(1l << i)) { PORTC_BASE_PTR->PCR[i] = port.PCR; }
  PORTC_DFER |= (port.DFER & pin_mask); /* DFER content OR-ed with pin_mask   */ 
  PORTC_DFCR  = port.DFCR;              
  PORTC_DFWR  = port.DFWR;  
  PORTC_ISFR &= ~pin_mask;
}

void PORTD_Init (tPORT port, uint32 pin_mask, uint8 ip, PORT_CALLBACK pCallback)
{
  register uint16 i;
  
  /* interrupt configuration                                                  */
  if (pCallback != NULL) { pCallbackPORTD = pCallback; NVIC_SetIsr(INT_PORTD,ip); }
  
  /* port configuration                                                       */
  for (i=0; i<32; i++)
    if(pin_mask & (uint32)(1l << i)) { PORTD_BASE_PTR->PCR[i] = port.PCR; }
  PORTD_DFER |= (port.DFER & pin_mask); /* DFER content OR-ed with pin_mask   */ 
  PORTD_DFCR  = port.DFCR;              
  PORTD_DFWR  = port.DFWR;  
  PORTD_ISFR &= ~pin_mask;  
}

void PORTE_Init (tPORT port, uint32 pin_mask, uint8 ip, PORT_CALLBACK pCallback)
{
  register uint16 i;
  
  /* interrupt configuration                                                  */
  if (pCallback != NULL) { pCallbackPORTE = pCallback; NVIC_SetIsr(INT_PORTE,ip); }
  
  /* port configuration                                                       */
  for (i=0; i<32; i++)
    if(pin_mask & (uint32)(1l << i)) { PORTE_BASE_PTR->PCR[i] = port.PCR; }
  PORTE_DFER |= (port.DFER & pin_mask); /* DFER content OR-ed with pin_mask   */ 
  PORTE_DFCR  = port.DFCR;              
  PORTE_DFWR  = port.DFWR;  
  PORTE_ISFR &= ~pin_mask;  
}

void GPIOA_Init (tGPIO gpio, uint32 pin_mask)
{
  GPIOA_PDDR |= (gpio.PDDR & pin_mask); /* PDDR content OR-ed with pin_mask   */
}

void GPIOB_Init (tGPIO gpio, uint32 pin_mask)
{
  GPIOB_PDDR |= (gpio.PDDR & pin_mask); /* PDDR content OR-ed with pin_mask   */
}

void GPIOC_Init (tGPIO gpio, uint32 pin_mask)
{
  GPIOC_PDDR |= (gpio.PDDR & pin_mask); /* PDDR content OR-ed with pin_mask   */
}

void GPIOD_Init (tGPIO gpio, uint32 pin_mask)
{
  GPIOD_PDDR |= (gpio.PDDR & pin_mask); /* PDDR content OR-ed with pin_mask   */
}

void GPIOE_Init (tGPIO gpio, uint32 pin_mask)
{
  GPIOE_PDDR |= (gpio.PDDR & pin_mask); /* PDDR content OR-ed with pin_mask   */
}

/******************************************************************************
 * interrupt functions definitions                                            *
 ******************************************************************************/
void porta_isr (void) 
{ 
  register uint32 temp32 = PORTA_ISFR;
  PORTA_ISFR |= temp32;             /* clear peripheral interrupt flags       */
  /* process interrupt callback function                                      */  
  if (pCallbackPORTA != (PORT_CALLBACK)NULL) { pCallbackPORTA (temp32); }
}

void portb_isr (void) 
{ 
  register uint32 temp32 = PORTB_ISFR;
  PORTB_ISFR |= temp32;             /* clear peripheral interrupt flags       */
  /* process interrupt callback function                                      */  
  if (pCallbackPORTB != (PORT_CALLBACK)NULL) { pCallbackPORTB (temp32); }
}

void portc_isr (void) 
{ 
  register uint32 temp32 = PORTC_ISFR;
  PORTC_ISFR |= temp32;             /* clear peripheral interrupt flags       */
  /* process interrupt callback function                                      */  
  if (pCallbackPORTC != (PORT_CALLBACK)NULL) { pCallbackPORTC (temp32); }
}

void portd_isr (void) 
{ 
  register uint32 temp32 = PORTD_ISFR;
  PORTD_ISFR |= temp32;             /* clear peripheral interrupt flags       */
  /* process interrupt callback function                                      */  
  if (pCallbackPORTD != (PORT_CALLBACK)NULL) { pCallbackPORTD (temp32); }
}

void porte_isr (void) 
{ 
  register uint32 temp32 = PORTE_ISFR;
  PORTE_ISFR |= temp32;             /* clear peripheral interrupt flags       */
  /* process interrupt callback function                                      */  
  if (pCallbackPORTE != (PORT_CALLBACK)NULL) { pCallbackPORTE (temp32); }
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/
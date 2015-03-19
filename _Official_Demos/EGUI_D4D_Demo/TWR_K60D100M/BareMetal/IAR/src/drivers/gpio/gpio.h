/*****************************************************************************
 * (c) Copyright 2010, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      gpio.h
 * @author    R55013
 * @version   1.0.6.0
 * @date      Mar-8-2011
 * @brief     GPIO and PORT drivers header file.
 ******************************************************************************/
#ifndef __GPIO_H
#define __GPIO_H 
 
/******************************************************************************
 * definition configuration structure                                         *
 ******************************************************************************/
typedef struct { uint32 PCR, DFER, DFCR, DFWR;  } tPORT; 
typedef struct { uint32 PDDR;                   } tGPIO; 

/******************************************************************************
 * PORT default configurations                                                *
 ******************************************************************************/
#define PORT_MODULE_LED_MODE        /* GPIO push-pull mode                */  \
(tPORT){                                                                      \
/* PCR      */ PORT_PCR_MUX(1)|PORT_PCR_DSE_MASK,                             \
/* DFER     */ 0l,                                                            \
/* DFCR     */ 0l,                                                            \
/* DFER     */ 0l,                                                            \
}

#define PORT_MODULE_ALT1_MODE       /* ALT1 push-pull mode high strength  */  \
(tPORT){                                                                      \
/* PCR      */ PORT_PCR_MUX(1)|PORT_PCR_DSE_MASK,                             \
/* DFER     */ 0l,                                                            \
/* DFCR     */ 0l,                                                            \
/* DFER     */ 0l,                                                            \
}

#define PORT_MODULE_ALT2_MODE       /* ALT2 push-pull mode high strength  */  \
(tPORT){                                                                      \
/* PCR      */ PORT_PCR_MUX(2)|PORT_PCR_DSE_MASK,                             \
/* DFER     */ 0l,                                                            \
/* DFCR     */ 0l,                                                            \
/* DFER     */ 0l,                                                            \
}

#define PORT_MODULE_ALT3_MODE       /* ALT3 push-pull mode high strength  */  \
(tPORT){                                                                      \
/* PCR      */ PORT_PCR_MUX(3)|PORT_PCR_DSE_MASK,                             \
/* DFER     */ 0l,                                                            \
/* DFCR     */ 0l,                                                            \
/* DFER     */ 0l,                                                            \
}

#define PORT_MODULE_ALT4_MODE       /* ALT4 push-pull mode high strength  */  \
(tPORT){                                                                      \
/* PCR      */ PORT_PCR_MUX(4)|PORT_PCR_DSE_MASK,                             \
/* DFER     */ 0l,                                                            \
/* DFCR     */ 0l,                                                            \
/* DFER     */ 0l,                                                            \
}

#define PORT_MODULE_ALT5_MODE       /* ALT5 push-pull mode high strength  */  \
(tPORT){                                                                      \
/* PCR      */ PORT_PCR_MUX(5)|PORT_PCR_DSE_MASK,                             \
/* DFER     */ 0l,                                                            \
/* DFCR     */ 0l,                                                            \
/* DFER     */ 0l,                                                            \
}

#define PORT_MODULE_ALT6_MODE       /* ALT6 push-pull mode high strength  */  \
(tPORT){                                                                      \
/* PCR      */ PORT_PCR_MUX(6)|PORT_PCR_DSE_MASK,                             \
/* DFER     */ 0l,                                                            \
/* DFCR     */ 0l,                                                            \
/* DFER     */ 0l,                                                            \
}

#define PORT_MODULE_ALT7_MODE       /* ALT7 push-pull mode high strength  */  \
(tPORT){                                                                      \
/* PCR      */ PORT_PCR_MUX(7)|PORT_PCR_DSE_MASK,                             \
/* DFER     */ 0l,                                                            \
/* DFCR     */ 0l,                                                            \
/* DFER     */ 0l,                                                            \
}

#define PORT_MODULE_BUTTON_MODE     /* GPIO mode, pull-up & filter enabled*/  \
(tPORT){                                                                      \
/* PCR      */ PORT_PCR_MUX(1)|PORT_PCR_PS_MASK|PORT_PCR_PE_MASK|             \
               PORT_PCR_PFE_MASK,                                             \
/* DFER     */ PORT_DFER_DFE_MASK,                                            \
/* DFCR     */ 0l,                                                            \
/* DFWR     */ PORT_DFWR_FILT(10),                                            \
}

#define PORT_MODULE_BUTTON_IRQ_MODE /* GPIO mode, pull-up enabled, IRQ on */  \
(tPORT){                                                                      \
/* PCR      */ PORT_PCR_MUX(1)|PORT_PCR_PS_MASK|PORT_PCR_PE_MASK|             \
               PORT_PCR_PFE_MASK|PORT_PCR_IRQC(10),                           \
/* DFER     */ PORT_DFER_DFE_MASK,                                            \
/* DFCR     */ 0l,                                                            \
/* DFWR     */ PORT_DFWR_FILT(10),                                            \
}

/******************************************************************************
 * PIN default configurations                                                 *
 ******************************************************************************/
#define GPIO_PIN_OUTPUT             /* GPIO pin configured in output mode */  \
(tGPIO){                                                                      \
/* PDDR     */ GPIO_PDDR_PDD_MASK,                                            \
}

#define GPIO_PIN_INPUT              /* GPIO pin configured in input mode  */  \
(tGPIO){                                                                      \
/* PDDR     */ 0l,                                                            \
}

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/
typedef void (*PORT_CALLBACK)(vuint32 pin_number);

/******************************************************************************
 * command definitions                                                        *
 ******************************************************************************/
/* pin names definition for use with GPIO macros                              */
#define PIN_0         (uint32)(1 <<  0)
#define PIN_1         (uint32)(1 <<  1)
#define PIN_2         (uint32)(1 <<  2)
#define PIN_3         (uint32)(1 <<  3)
#define PIN_4         (uint32)(1 <<  4)
#define PIN_5         (uint32)(1 <<  5)
#define PIN_6         (uint32)(1 <<  6)
#define PIN_7         (uint32)(1 <<  7)
#define PIN_8         (uint32)(1 <<  8)
#define PIN_9         (uint32)(1 <<  9)
#define PIN_10        (uint32)(1 << 10)
#define PIN_11        (uint32)(1 << 11)
#define PIN_12        (uint32)(1 << 12)
#define PIN_13        (uint32)(1 << 13)
#define PIN_14        (uint32)(1 << 14)
#define PIN_15        (uint32)(1 << 15)
#define PIN_16        (uint32)(1 << 16)
#define PIN_17        (uint32)(1 << 17)
#define PIN_18        (uint32)(1 << 18)
#define PIN_19        (uint32)(1 << 19)
#define PIN_20        (uint32)(1 << 20)
#define PIN_21        (uint32)(1 << 21)
#define PIN_22        (uint32)(1 << 22)
#define PIN_23        (uint32)(1 << 23)
#define PIN_24        (uint32)(1 << 24)
#define PIN_25        (uint32)(1 << 25)
#define PIN_26        (uint32)(1 << 26)
#define PIN_27        (uint32)(1 << 27)
#define PIN_28        (uint32)(1 << 28)
#define PIN_29        (uint32)(1 << 29)
#define PIN_30        (uint32)(1 << 30)
#define PIN_31        (uint32)(1 << 31)

/* GPIO macro definitions                                                     */
/***************************************************************************//*!
 * @brief   Macro returns state of port pins.
 * @param   port    - GPIOA|GPIOB|GPIOC|GPIOD|GPIOE  
 * @return  32-bit status of the port pins
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define GPIO_Get(port)        port##_PDIR     /* reading value from GPIO port */

/***************************************************************************//*!
 * @brief   Macro set port pins.
 * @param   port    - GPIOA|GPIOB|GPIOC|GPIOD|GPIOE  
 * @param   mask    - PIN_0..PIN_32  
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define GPIO_Set(port,mask)   port##_PSOR=(mask); /* set bits on GPIO port    */

/***************************************************************************//*!
 * @brief   Macro clear port pins.
 * @param   port    - GPIOA|GPIOB|GPIOC|GPIOD|GPIOE  
 * @param   mask    - PIN_0..PIN_32  
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define GPIO_Clr(port,mask)   port##_PCOR=(mask); /* clear bits on GPIO port  */

/***************************************************************************//*!
 * @brief   Macro toglle port pins.
 * @param   port    - GPIOA|GPIOB|GPIOC|GPIOD|GPIOE  
 * @param   mask    - PIN_0..PIN_32  
 * @note    Implemented as inlined macro.
 ******************************************************************************/

#define GPIO_Tgl(port,mask)   port##_PTOR=(mask); /* toggle bits on GPIO port */

/* Function redefinition                                                      */
/***************************************************************************//*!
 * @brief   PORT initialization function.
 * @param   port    - PORTA|PORTB|PORTC|PORTD|PORTE
 * @param   cfg     - PORT configuration structure passed by value: 
 *                    PORT_MODULE_LED_MODE,
 *                    PORT_MODULE_ALT1_MODE,
 *                    PORT_MODULE_ALT2_MODE,
 *                    PORT_MODULE_ALT3_MODE,
 *                    PORT_MODULE_ALT4_MODE,
 *                    PORT_MODULE_ALT5_MODE,
 *                    PORT_MODULE_ALT6_MODE,
 *                    PORT_MODULE_ALT7_MODE,
 *                    PORT_MODULE_BUTTON_IRQ_MODE,
 *                    PORT_MODULE_BUTTON_MODE.
 * @param   mask    - PIN_0..PIN_32 
 * @param   ip      - interrupt priority 0..15
 * @param   callback- pointer to PORT_CALLBACK function
 * @return  none
 * @note    Implemented as function call.
 ******************************************************************************/
#define PORT_Init(port,cfg,mask,ip,callback)  port##_Init(cfg,mask,ip,callback)

/***************************************************************************//*!
 * @brief   GPIO initialization function.
 * @param   gpio    - GPIOA|GPIOB|GPIOC|GPIOD|GPIOE
 * @param   cfg     - GPIO configuration structure passed by value: 
 *                    GPIO_PIN_OUTPUT,
 *                    GPIO_PIN_INPUT.
 * @param   mask    - PIN_0..PIN_32 
 * @return  none
 * @note    Implemented as function call.
 ******************************************************************************/
#define GPIO_Init(gpio,cfg,mask)               gpio##_Init(cfg,mask)

/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/    
extern void PORTA_Init (tPORT port, uint32 pin_mask, uint8 ip, PORT_CALLBACK pCallback);
extern void PORTB_Init (tPORT port, uint32 pin_mask, uint8 ip, PORT_CALLBACK pCallback);
extern void PORTC_Init (tPORT port, uint32 pin_mask, uint8 ip, PORT_CALLBACK pCallback);
extern void PORTD_Init (tPORT port, uint32 pin_mask, uint8 ip, PORT_CALLBACK pCallback);
extern void PORTE_Init (tPORT port, uint32 pin_mask, uint8 ip, PORT_CALLBACK pCallback);

extern void GPIOA_Init (tGPIO gpio, uint32 pin_mask);
extern void GPIOB_Init (tGPIO gpio, uint32 pin_mask);
extern void GPIOC_Init (tGPIO gpio, uint32 pin_mask);
extern void GPIOD_Init (tGPIO gpio, uint32 pin_mask);
extern void GPIOE_Init (tGPIO gpio, uint32 pin_mask);
   
#endif /* __GPIO_H */
/*****************************************************************************
 * (c) Copyright 2010, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      sim.h
 * @author    R55013
 * @version   1.0.4.0
 * @date      Apr-4-2013
 * @brief     SIM driver header file.
 ******************************************************************************/
#ifndef __SIM_H
#define __SIM_H 
 
/******************************************************************************
 * definition configuration structure                                         *
 ******************************************************************************/
typedef struct 
{ 
  uint32 SOPT1, SOPT2, SOPT4, SOPT5, SOPT6, SOPT7, SCGC1, SCGC2, SCGC3, SCGC4, 
         SCGC5, SCGC6, SCGC7, CLKDIV1, CLKDIV2;
} tSIM;

/* clock divider definitions                                                  */
#define DIV_BY_1    (uint8)0x00
#define DIV_BY_2    (uint8)0x01
#define DIV_BY_3    (uint8)0x02
#define DIV_BY_4    (uint8)0x03
#define DIV_BY_5    (uint8)0x04
#define DIV_BY_6    (uint8)0x05
#define DIV_BY_7    (uint8)0x06
#define DIV_BY_8    (uint8)0x07
#define DIV_BY_9    (uint8)0x08
#define DIV_BY_10   (uint8)0x09
#define DIV_BY_11   (uint8)0x0a
#define DIV_BY_12   (uint8)0x0b
#define DIV_BY_13   (uint8)0x0c
#define DIV_BY_14   (uint8)0x0d
#define DIV_BY_15   (uint8)0x0e
#define DIV_BY_16   (uint8)0x0f

#define OSCCLK      (uint8)0x00
#define RTCCLK      (uint8)0x01

/******************************************************************************
 * default configurations                                                     *
 ******************************************************************************/
#if (defined(CPU_MK60N512VMD100))
#define SIM_MODULE_CONFIG                                  /* all clocks on */\
(tSIM){                                                                       \
/* SOPT1   */ SIM_SOPT1_USBREGEN_MASK|SIM_SOPT1_USBSTBY_MASK,                 \
/* SOPT2   */ SIM_SOPT2_TRACECLKSEL_MASK,                                     \
/* SOPT4   */ 0l,                                                             \
/* SOPT5   */ 0l,                                                             \
/* SOPT6   */ 0l,                                                             \
/* SOPT7   */ 0l,                                                             \
/* SCGC1   */ SIM_SCGC1_UART4_MASK|SIM_SCGC1_UART5_MASK,                      \
/* SCGC2   */ SIM_SCGC2_ENET_MASK|SIM_SCGC2_DAC0_MASK|SIM_SCGC2_DAC1_MASK,    \
/* SCGC3   */ SIM_SCGC3_SDHC_MASK|SIM_SCGC3_FTM2_MASK|SIM_SCGC3_ADC1_MASK|    \
              SIM_SCGC3_RNGB_MASK|SIM_SCGC3_FLEXCAN1_MASK|SIM_SCGC3_SPI2_MASK,\
/* SCGC4   */ SIM_SCGC4_USBOTG_MASK|SIM_SCGC4_CMP_MASK|SIM_SCGC4_VREF_MASK|   \
              SIM_SCGC4_LLWU_MASK|SIM_SCGC4_EWM_MASK|SIM_SCGC4_CMT_MASK|      \
              SIM_SCGC4_I2C0_MASK|SIM_SCGC4_I2C1_MASK|SIM_SCGC4_UART0_MASK|   \
              SIM_SCGC4_UART1_MASK|SIM_SCGC4_UART2_MASK|SIM_SCGC4_UART3_MASK, \
/* SCGC5   */ SIM_SCGC5_LPTIMER_MASK|SIM_SCGC5_REGFILE_MASK|                  \
              SIM_SCGC5_TSI_MASK|SIM_SCGC5_PORTA_MASK|SIM_SCGC5_PORTB_MASK|   \
              SIM_SCGC5_PORTC_MASK|SIM_SCGC5_PORTD_MASK|SIM_SCGC5_PORTE_MASK, \
/* SCGC6   */ SIM_SCGC6_CRC_MASK|SIM_SCGC6_USBDCD_MASK|SIM_SCGC6_PIT_MASK|    \
              SIM_SCGC6_PDB_MASK|SIM_SCGC6_FTM0_MASK|SIM_SCGC6_FTM1_MASK|     \
              SIM_SCGC6_ADC0_MASK|SIM_SCGC6_RTC_MASK|SIM_SCGC6_FTFL_MASK|     \
              SIM_SCGC6_DMAMUX_MASK|SIM_SCGC6_FLEXCAN0_MASK|                  \
              SIM_SCGC6_DSPI0_MASK|SIM_SCGC6_SPI1_MASK|SIM_SCGC6_I2S_MASK,    \
/* SCGC7   */ SIM_SCGC7_FLEXBUS_MASK|SIM_SCGC7_DMA_MASK|SIM_SCGC7_MPU_MASK,   \
/* CLKDIV1 */ SIM_CLKDIV1_OUTDIV1(DIV_BY_1)|SIM_CLKDIV1_OUTDIV2(DIV_BY_1)|    \
              SIM_CLKDIV1_OUTDIV3(DIV_BY_1)|SIM_CLKDIV1_OUTDIV4(DIV_BY_1),    \
/* CLKDIV2 */ SIM_CLKDIV2_I2SDIV(1)|SIM_CLKDIV2_I2SFRAC(0)|                   \
              SIM_CLKDIV2_USBDIV(0)|SIM_CLKDIV2_USBFRAC_MASK,                 \
}
#endif

#if (defined(CPU_MK40N512VMD100))
#define SIM_MODULE_CONFIG                                  /* all clocks on */\
(tSIM){                                                                       \
/* SOPT1   */ SIM_SOPT1_USBREGEN_MASK|SIM_SOPT1_USBSTBY_MASK,                 \
/* SOPT2   */ SIM_SOPT2_TRACECLKSEL_MASK,                                     \
/* SOPT4   */ 0l,                                                             \
/* SOPT5   */ 0l,                                                             \
/* SOPT6   */ 0l,                                                             \
/* SOPT7   */ 0l,                                                             \
/* SCGC1   */ SIM_SCGC1_UART4_MASK|SIM_SCGC1_UART5_MASK,                      \
/* SCGC2   */ SIM_SCGC2_DAC0_MASK|SIM_SCGC2_DAC1_MASK,                        \
/* SCGC3   */ SIM_SCGC3_SDHC_MASK|SIM_SCGC3_FTM2_MASK|SIM_SCGC3_ADC1_MASK|    \
              SIM_SCGC3_SLCD_MASK|SIM_SCGC3_FLEXCAN1_MASK|SIM_SCGC3_SPI2_MASK,\
/* SCGC4   */ SIM_SCGC4_USBOTG_MASK|SIM_SCGC4_CMP_MASK|SIM_SCGC4_VREF_MASK|   \
              SIM_SCGC4_LLWU_MASK|SIM_SCGC4_EWM_MASK|SIM_SCGC4_CMT_MASK|      \
              SIM_SCGC4_I2C0_MASK|SIM_SCGC4_I2C1_MASK|SIM_SCGC4_UART0_MASK|   \
              SIM_SCGC4_UART1_MASK|SIM_SCGC4_UART2_MASK|SIM_SCGC4_UART3_MASK, \
/* SCGC5   */ SIM_SCGC5_LPTIMER_MASK|SIM_SCGC5_REGFILE_MASK|                  \
              SIM_SCGC5_TSI_MASK|SIM_SCGC5_PORTA_MASK|SIM_SCGC5_PORTB_MASK|   \
              SIM_SCGC5_PORTC_MASK|SIM_SCGC5_PORTD_MASK|SIM_SCGC5_PORTE_MASK, \
/* SCGC6   */ SIM_SCGC6_CRC_MASK|SIM_SCGC6_USBDCD_MASK|SIM_SCGC6_PIT_MASK|    \
              SIM_SCGC6_PDB_MASK|SIM_SCGC6_FTM0_MASK|SIM_SCGC6_FTM1_MASK|     \
              SIM_SCGC6_ADC0_MASK|SIM_SCGC6_RTC_MASK|SIM_SCGC6_FTFL_MASK|     \
              SIM_SCGC6_DMAMUX_MASK|SIM_SCGC6_FLEXCAN0_MASK|                  \
              SIM_SCGC6_DSPI0_MASK|SIM_SCGC6_SPI1_MASK|SIM_SCGC6_I2S_MASK,    \
/* SCGC7   */ SIM_SCGC7_FLEXBUS_MASK|SIM_SCGC7_DMA_MASK|SIM_SCGC7_MPU_MASK,   \
/* CLKDIV1 */ SIM_CLKDIV1_OUTDIV1(DIV_BY_1)|SIM_CLKDIV1_OUTDIV2(DIV_BY_1)|    \
              SIM_CLKDIV1_OUTDIV3(DIV_BY_1)|SIM_CLKDIV1_OUTDIV4(DIV_BY_1),    \
/* CLKDIV2 */ SIM_CLKDIV2_I2SDIV(1)|SIM_CLKDIV2_I2SFRAC(0)|                   \
              SIM_CLKDIV2_USBDIV(0)|SIM_CLKDIV2_USBFRAC_MASK,                 \
}
#endif

#if (defined(CPU_MK40X256VMD100))
#define SIM_MODULE_CONFIG                                  /* all clocks on */\
(tSIM){                                                                       \
/* SOPT1   */ SIM_SOPT1_USBREGEN_MASK|SIM_SOPT1_USBSTBY_MASK,                 \
/* SOPT2   */ SIM_SOPT2_TRACECLKSEL_MASK,                                     \
/* SOPT4   */ 0l,                                                             \
/* SOPT5   */ 0l,                                                             \
/* SOPT6   */ 0l,                                                             \
/* SOPT7   */ 0l,                                                             \
/* SCGC1   */ SIM_SCGC1_UART4_MASK|SIM_SCGC1_UART5_MASK,                      \
/* SCGC2   */ SIM_SCGC2_DAC0_MASK|SIM_SCGC2_DAC1_MASK,                        \
/* SCGC3   */ SIM_SCGC3_SDHC_MASK|SIM_SCGC3_FTM2_MASK|SIM_SCGC3_ADC1_MASK|    \
              SIM_SCGC3_SLCD_MASK|SIM_SCGC3_FLEXCAN1_MASK|SIM_SCGC3_SPI2_MASK,\
/* SCGC4   */ SIM_SCGC4_USBOTG_MASK|SIM_SCGC4_CMP_MASK|SIM_SCGC4_VREF_MASK|   \
              SIM_SCGC4_LLWU_MASK|SIM_SCGC4_EWM_MASK|SIM_SCGC4_CMT_MASK|      \
              SIM_SCGC4_I2C0_MASK|SIM_SCGC4_I2C1_MASK|SIM_SCGC4_UART0_MASK|   \
              SIM_SCGC4_UART1_MASK|SIM_SCGC4_UART2_MASK|SIM_SCGC4_UART3_MASK, \
/* SCGC5   */ SIM_SCGC5_LPTIMER_MASK|SIM_SCGC5_REGFILE_MASK|                  \
              SIM_SCGC5_TSI_MASK|SIM_SCGC5_PORTA_MASK|SIM_SCGC5_PORTB_MASK|   \
              SIM_SCGC5_PORTC_MASK|SIM_SCGC5_PORTD_MASK|SIM_SCGC5_PORTE_MASK, \
/* SCGC6   */ SIM_SCGC6_CRC_MASK|SIM_SCGC6_USBDCD_MASK|SIM_SCGC6_PIT_MASK|    \
              SIM_SCGC6_PDB_MASK|SIM_SCGC6_FTM0_MASK|SIM_SCGC6_FTM1_MASK|     \
              SIM_SCGC6_ADC0_MASK|SIM_SCGC6_RTC_MASK|SIM_SCGC6_FTFL_MASK|     \
              SIM_SCGC6_DMAMUX_MASK|SIM_SCGC6_FLEXCAN0_MASK|                  \
              SIM_SCGC6_DSPI0_MASK|SIM_SCGC6_SPI1_MASK|SIM_SCGC6_I2S_MASK,    \
/* SCGC7   */ SIM_SCGC7_FLEXBUS_MASK|SIM_SCGC7_DMA_MASK|SIM_SCGC7_MPU_MASK,   \
/* CLKDIV1 */ SIM_CLKDIV1_OUTDIV1(DIV_BY_1)|SIM_CLKDIV1_OUTDIV2(DIV_BY_1)|    \
              SIM_CLKDIV1_OUTDIV3(DIV_BY_1)|SIM_CLKDIV1_OUTDIV4(DIV_BY_1),    \
/* CLKDIV2 */ SIM_CLKDIV2_I2SDIV(1)|SIM_CLKDIV2_I2SFRAC(0)|                   \
              SIM_CLKDIV2_USBDIV(0)|SIM_CLKDIV2_USBFRAC_MASK,                 \
}
#endif

/******************************************************************************
 * data type definitions                                                      *
 ******************************************************************************/

/******************************************************************************
 * command definitions                                                        *
 ******************************************************************************/
/***************************************************************************//*!
 * @brief   Macro sets the divide value for the core/system clock.
 * @param   x - DIV_BY_01|DIV_BY_02|DIV_BY_03|DIV_BY_04|DIV_BY_05|DIV_BY_06|
 *              DIV_BY_07|DIV_BY_08|DIV_BY_09|DIV_BY_10|DIV_BY_11|DIV_BY_12|
 *              DIV_BY_13|DIV_BY_14|DIV_BY_15|DIV_BY_16.\n
 * @return  none
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define SIM_SetOUTDIV1(x)                                                                     \
{                                                                                             \
  REG_SetVal(SIM_CLKDIV1,SIM_CLKDIV1_OUTDIV1_MASK,(uint32)(x&0x0f),SIM_CLKDIV1_OUTDIV1_SHIFT);\
}

/***************************************************************************//*!
 * @brief   Macro sets the divide value for the peripheral clock.
 * @param   x - DIV_BY_01|DIV_BY_02|DIV_BY_03|DIV_BY_04|DIV_BY_05|DIV_BY_06|
 *              DIV_BY_07|DIV_BY_08|DIV_BY_09|DIV_BY_10|DIV_BY_11|DIV_BY_12|
 *              DIV_BY_13|DIV_BY_14|DIV_BY_15|DIV_BY_16.\n
 * @return  none
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define SIM_SetOUTDIV2(x)                                                                     \
{                                                                                             \
  REG_SetVal(SIM_CLKDIV1,SIM_CLKDIV1_OUTDIV2_MASK,(uint32)(x&0x0f),SIM_CLKDIV1_OUTDIV2_SHIFT);\
} 

/***************************************************************************//*!
 * @brief   Macro sets the divide value for FlexBus clock driven to the external 
 *          pin (FB_CLK).
 * @param   x - DIV_BY_01|DIV_BY_02|DIV_BY_03|DIV_BY_04|DIV_BY_05|DIV_BY_06|
 *              DIV_BY_07|DIV_BY_08|DIV_BY_09|DIV_BY_10|DIV_BY_11|DIV_BY_12|
 *              DIV_BY_13|DIV_BY_14|DIV_BY_15|DIV_BY_16.\n
 * @return  none
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define SIM_SetOUTDIV3(x)                                                                     \
{                                                                                             \
  REG_SetVal(SIM_CLKDIV1,SIM_CLKDIV1_OUTDIV3_MASK,(uint32)(x&0x0f),SIM_CLKDIV1_OUTDIV3_SHIFT);\
} 

/***************************************************************************//*!
 * @brief   Macro sets the divide value for the for the flash clock.
 * @param   x - DIV_BY_01|DIV_BY_02|DIV_BY_03|DIV_BY_04|DIV_BY_05|DIV_BY_06|
 *              DIV_BY_07|DIV_BY_08|DIV_BY_09|DIV_BY_10|DIV_BY_11|DIV_BY_12|
 *              DIV_BY_13|DIV_BY_14|DIV_BY_15|DIV_BY_16.\n
 * @return  none
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define SIM_SetOUTDIV4(x)                                                                     \
{                                                                                             \
  REG_SetVal(SIM_CLKDIV1,SIM_CLKDIV1_OUTDIV4_MASK,(uint32)(x&0x0f),SIM_CLKDIV1_OUTDIV4_SHIFT);\
}

/***************************************************************************//*!
 * @brief   Macro sets clock source for MCG module.
 * @param   x - OSCCLK (System oscillator OSCCLK)
 * @param   x - RTCCLK (32.768kHz RTC oscillator)
 * @return  none
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define SIM_SetMcgClockSource(x)                                                    \
{                                                                             \
  REG_SetVal(SIM_SOPT2,SIM_SOPT2_MCGCLKSEL_MASK,x,SIM_SOPT2_MCGCLKSEL_SHIFT); \
}
/******************************************************************************
 * public function prototypes                                                 *
 ******************************************************************************/    
extern void SIM_Init (tSIM sim);
   
#endif /* __SIM_H */ 
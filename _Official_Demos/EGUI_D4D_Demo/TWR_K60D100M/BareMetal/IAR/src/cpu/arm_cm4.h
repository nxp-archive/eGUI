/*****************************************************************************
 * (c) Copyright 2010, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      arm_cm4.h
 * @author    MSG
 * @version   1.0.3.0
 * @date      Mar-8-2011
 * @brief     arm_cm4 drivers header file.
 ******************************************************************************/
#ifndef _CPU_ARM_CM4_H
#define _CPU_ARM_CM4_H

/*ARM Cortex M4 implementation for interrupt priority shift*/
#define ARM_INTERRUPT_LEVEL_BITS          4

/**********************************************************************/
// function prototypes for arm_cm4.c
void stop (void);
void wait (void);
void write_vtor (int);
void enable_irq (int);
void disable_irq (int);
void set_irq_priority (int, int);

/***************************************************************************//*!
 * @brief   Macro enables all interrupts.
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define EnableInterrupts        asm(" CPSIE i");

/***************************************************************************//*!
 * @brief   Macro disables all interrupts.
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define DisableInterrupts       asm(" CPSID i");

/***************************************************************************//*!
 * @brief   Macro enables all fault exceptions.
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define EnableFaultInterrupts   asm(" CPSIE f");

/***************************************************************************//*!
 * @brief   Macro prevents activation all fault exceptions except for Non-Maskable
 *          Interrupt (NMI).
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define DisableFaultInterrupts  asm(" CPSID f");

/***************************************************************************//*!
 * @brief   Macro sets BASEPRI bits. The processor does not process any 
 *          exception with a priority value greater than or equal to BASEPRI
 * @param   level     - 0x00    = no effect\n 
 *                      nonzero = base priority for exception processing
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define MaskInterrupts(level)   __set_BASEPRI((level)<<ARM_INTERRUPT_LEVEL_BITS)

/***************************************************************************//*!
 * @brief   Macro to switch to unprivilege (user) mode of execution. It can be 
 *          called from software running in privilege (supervisor) mode.   
 * @note    Implemented as inlined macro. 
 ******************************************************************************/
#define ARMCM4_UserMode()       __set_CONTROL(__get_CONTROL()| 0x00000001l)

/***************************************************************************//*!
 * @brief   Macro to switch to privilege (supervisor) mode of execution. It can 
 *          be called from software running in handler or privilege (supervisor) 
 *          modes. Calling it from unprivilege (user) mode of execution causes
 *          not entering into privilege (supervisor) mode of execution - use 
 *          ARMCM4_SVCall() instead.   
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define ARMCM4_SupervisorMode() __set_CONTROL(__get_CONTROL()&~0x00000001l)

/***************************************************************************//*!
 * @brief   Macro performs supervisor call. Service routine exexutes in handler 
 *          mode.
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define ARMCM4_SVCall()         asm("SVC #0x00")

#define IRQ(x)              ((x)-16)         
#define ICPR_VALUE(x)       (uint16)(IRQ(x)/32)
#define ICPR_SHIFT(x)       (uint16)(IRQ(x)%32)
/***************************************************************************//*!
 * @brief   Macro enables interrupt request and sets its priority.
 * @param   src       <b>MK60 Device Interrupt Sources List:</b>
 *                    INT_DMA0|INT_DMA1|INT_DMA2|INT_DMA3|INT_DMA4|INT_DMA5|
 *                    INT_DMA6|INT_DMA7|INT_DMA8|INT_DMA9|INT_DMA10|INT_DMA11|
 *                    INT_DMA12|INT_DMA13|INT_DMA14|INT_DMA15|INT_DMA_Error|
 *                    INT_MCM|INT_FTFL|INT_Read_Collision|INT_LVD_LVW|INT_LLW|
 *                    INT_Watchdog|INT_RNGB|INT_I2C0|INT_I2C1|INT_SPI0|INT_SPI1|
 *                    INT_SPI2|INT_CAN0_ORed_Message_buffer|INT_CAN0_Bus_Off|
 *                    INT_CAN0_Error|INT_CAN0_Tx_Warning|INT_CAN0_Rx_Warning|
 *                    INT_CAN0_Wake_Up|INT_CAN0_IMEU|INT_CAN0_Lost_Rx|
 *                    INT_CAN1_ORed_Message_buffer|INT_CAN1_Bus_Off|
 *                    INT_CAN1_Error|INT_CAN1_Tx_Warning|INT_CAN1_Rx_Warning|
 *                    INT_CAN1_Wake_Up|INT_CAN1_IMEU|INT_CAN1_Lost_Rx|
 *                    INT_UART0_RX_TX|INT_UART0_ERR|INT_UART1_RX_TX|
 *                    INT_UART1_ERR|INT_UART2_RX_TX|INT_UART2_ERR|
 *                    INT_UART3_RX_TX|INT_UART3_ERR|INT_UART4_RX_TX|
 *                    INT_UART4_ERR|INT_UART5_RX_TX|INT_UART5_ERR|INT_ADC0|
 *                    INT_ADC1|INT_HSCMP0|INT_HSCMP1|INT_HSCMP2||INT_FTM0|
 *                    INT_FTM1|INT_FTM2|INT_CMT|INT_RTC|INT_PIT0|INT_PIT1|
 *                    INT_PIT2|INT_PIT3|INT_PDB0|INT_USB0|INT_USBDCD|
 *                    INT_ENET_1588_Timer|INT_ENET_Transmit|INT_ENET_Receive|
 *                    INT_ENET_Error|INT_I2S0|INT_SDHC|INT_DAC0|INT_DAC1|
 *                    INT_TSI0|INT_MCG|INT_LPTimer|INT_PORTA|INT_PORTB|
 *                    INT_PORTC|INT_PORTD|INT_PORTE|INT_Reserved108|
 *                    INT_Reserved109|INT_Reserved110|INT_Reserved111
 *                    \n\n<b>MK40 Device Interrupt Sources List:</b>
 *                    INT_DMA0|INT_DMA1|INT_DMA2|INT_DMA3|INT_DMA4|INT_DMA5|
 *                    INT_DMA6|INT_DMA7|INT_DMA8|INT_DMA9|INT_DMA10|INT_DMA11|
 *                    INT_DMA12|INT_DMA13|INT_DMA14|INT_DMA15|INT_DMA_Error|
 *                    INT_MCM|INT_FTFL|INT_Read_Collision|INT_LVD_LVW|INT_LLW|
 *                    INT_Watchdog|INT_I2C0|INT_I2C1|INT_SPI0|INT_SPI1|
 *                    INT_SPI2|INT_CAN0_ORed_Message_buffer|INT_CAN0_Bus_Off|
 *                    INT_CAN0_Error|INT_CAN0_Tx_Warning|INT_CAN0_Rx_Warning|
 *                    INT_CAN0_Wake_Up|INT_CAN0_IMEU|INT_CAN0_Lost_Rx|
 *                    INT_CAN1_ORed_Message_buffer|INT_CAN1_Bus_Off|
 *                    INT_CAN1_Error|INT_CAN1_Tx_Warning|INT_CAN1_Rx_Warning|
 *                    INT_CAN1_Wake_Up|INT_CAN1_IMEU|INT_CAN1_Lost_Rx|
 *                    INT_UART0_RX_TX|INT_UART0_ERR|INT_UART1_RX_TX|
 *                    INT_UART1_ERR|INT_UART2_RX_TX|INT_UART2_ERR|
 *                    INT_UART3_RX_TX|INT_UART3_ERR|INT_UART4_RX_TX|
 *                    INT_UART4_ERR|INT_UART5_RX_TX|INT_UART5_ERR|INT_ADC0|
 *                    INT_ADC1|INT_HSCMP0|INT_HSCMP1|INT_HSCMP2||INT_FTM0|
 *                    INT_FTM1|INT_FTM2|INT_CMT|INT_RTC|INT_PIT0|INT_PIT1|
 *                    INT_PIT2|INT_PIT3|INT_PDB0|INT_USB0|INT_I2S0|INT_SDHC|
 *                    INT_DAC0|INT_DAC1|INT_TSI0|INT_MCG|INT_LPTimer|INT_LCD|
 *                    INT_PORTA|INT_PORTB|INT_PORTC|INT_PORTD|INT_PORTE|
 *                    INT_Reserved108|INT_Reserved109|INT_Reserved110|
 *                    INT_Reserved111
 * @param   ipr     - interrupt priority <0-15>; lower means higher priority
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define NVIC_SetIsr(src,ipr){                                                     \
                              NVIC_ICPR_REG(NVIC_BASE_PTR,ICPR_VALUE(src)) |=     \
                              (uint32)(1l << ICPR_SHIFT(src));                    \
                              NVIC_ISER_REG(NVIC_BASE_PTR,ICPR_VALUE(src)) |=     \
                              (uint32)(1l << ICPR_SHIFT(src));                    \
                              NVIC_IP_REG(NVIC_BASE_PTR,IRQ(src)) |=              \
                              (uint32)((uint32)(ipr)<<ARM_INTERRUPT_LEVEL_BITS);  \
                            }
/***************************************************************************//*!
 * @brief   Macro disables interrupt request.
 * @param   src       <b>MK60 Device Interrupt Sources List:</b>
 *                    INT_DMA0|INT_DMA1|INT_DMA2|INT_DMA3|INT_DMA4|INT_DMA5|
 *                    INT_DMA6|INT_DMA7|INT_DMA8|INT_DMA9|INT_DMA10|INT_DMA11|
 *                    INT_DMA12|INT_DMA13|INT_DMA14|INT_DMA15|INT_DMA_Error|
 *                    INT_MCM|INT_FTFL|INT_Read_Collision|INT_LVD_LVW|INT_LLW|
 *                    INT_Watchdog|INT_RNGB|INT_I2C0|INT_I2C1|INT_SPI0|INT_SPI1|
 *                    INT_SPI2|INT_CAN0_ORed_Message_buffer|INT_CAN0_Bus_Off|
 *                    INT_CAN0_Error|INT_CAN0_Tx_Warning|INT_CAN0_Rx_Warning|
 *                    INT_CAN0_Wake_Up|INT_CAN0_IMEU|INT_CAN0_Lost_Rx|
 *                    INT_CAN1_ORed_Message_buffer|INT_CAN1_Bus_Off|
 *                    INT_CAN1_Error|INT_CAN1_Tx_Warning|INT_CAN1_Rx_Warning|
 *                    INT_CAN1_Wake_Up|INT_CAN1_IMEU|INT_CAN1_Lost_Rx|
 *                    INT_UART0_RX_TX|INT_UART0_ERR|INT_UART1_RX_TX|
 *                    INT_UART1_ERR|INT_UART2_RX_TX|INT_UART2_ERR|
 *                    INT_UART3_RX_TX|INT_UART3_ERR|INT_UART4_RX_TX|
 *                    INT_UART4_ERR|INT_UART5_RX_TX|INT_UART5_ERR|INT_ADC0|
 *                    INT_ADC1|INT_HSCMP0|INT_HSCMP1|INT_HSCMP2||INT_FTM0|
 *                    INT_FTM1|INT_FTM2|INT_CMT|INT_RTC|INT_PIT0|INT_PIT1|
 *                    INT_PIT2|INT_PIT3|INT_PDB0|INT_USB0|INT_USBDCD|
 *                    INT_ENET_1588_Timer|INT_ENET_Transmit|INT_ENET_Receive|
 *                    INT_ENET_Error|INT_I2S0|INT_SDHC|INT_DAC0|INT_DAC1|
 *                    INT_TSI0|INT_MCG|INT_LPTimer|INT_PORTA|INT_PORTB|
 *                    INT_PORTC|INT_PORTD|INT_PORTE|INT_Reserved108|
 *                    INT_Reserved109|INT_Reserved110|INT_Reserved111
 *                    \n\n<b>MK40 Device Interrupt Sources List:</b>
 *                    INT_DMA0|INT_DMA1|INT_DMA2|INT_DMA3|INT_DMA4|INT_DMA5|
 *                    INT_DMA6|INT_DMA7|INT_DMA8|INT_DMA9|INT_DMA10|INT_DMA11|
 *                    INT_DMA12|INT_DMA13|INT_DMA14|INT_DMA15|INT_DMA_Error|
 *                    INT_MCM|INT_FTFL|INT_Read_Collision|INT_LVD_LVW|INT_LLW|
 *                    INT_Watchdog|INT_I2C0|INT_I2C1|INT_SPI0|INT_SPI1|
 *                    INT_SPI2|INT_CAN0_ORed_Message_buffer|INT_CAN0_Bus_Off|
 *                    INT_CAN0_Error|INT_CAN0_Tx_Warning|INT_CAN0_Rx_Warning|
 *                    INT_CAN0_Wake_Up|INT_CAN0_IMEU|INT_CAN0_Lost_Rx|
 *                    INT_CAN1_ORed_Message_buffer|INT_CAN1_Bus_Off|
 *                    INT_CAN1_Error|INT_CAN1_Tx_Warning|INT_CAN1_Rx_Warning|
 *                    INT_CAN1_Wake_Up|INT_CAN1_IMEU|INT_CAN1_Lost_Rx|
 *                    INT_UART0_RX_TX|INT_UART0_ERR|INT_UART1_RX_TX|
 *                    INT_UART1_ERR|INT_UART2_RX_TX|INT_UART2_ERR|
 *                    INT_UART3_RX_TX|INT_UART3_ERR|INT_UART4_RX_TX|
 *                    INT_UART4_ERR|INT_UART5_RX_TX|INT_UART5_ERR|INT_ADC0|
 *                    INT_ADC1|INT_HSCMP0|INT_HSCMP1|INT_HSCMP2||INT_FTM0|
 *                    INT_FTM1|INT_FTM2|INT_CMT|INT_RTC|INT_PIT0|INT_PIT1|
 *                    INT_PIT2|INT_PIT3|INT_PDB0|INT_USB0|INT_I2S0|INT_SDHC|
 *                    INT_DAC0|INT_DAC1|INT_TSI0|INT_MCG|INT_LPTimer|INT_LCD|
 *                    INT_PORTA|INT_PORTB|INT_PORTC|INT_PORTD|INT_PORTE|
 *                    INT_Reserved108|INT_Reserved109|INT_Reserved110|
 *                    INT_Reserved111
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define NVIC_ClrIsr(src)    {                                                     \
                              NVIC_ICER_REG(NVIC_BASE_PTR,ICPR_VALUE(src)) |=     \
                              (uint32)(1l << ICPR_SHIFT(src));                    \
                              NVIC_IP_REG(NVIC_BASE_PTR,IRQ(src)) &=              \
                              ~((uint32)((uint32)0x0f<<ARM_INTERRUPT_LEVEL_BITS));\
                            }

/***************************************************************************//*!
 * @brief   Macro calls isr.
 * @param   src       <b>MK60 Device Interrupt Sources List:</b>
 *                    INT_DMA0|INT_DMA1|INT_DMA2|INT_DMA3|INT_DMA4|INT_DMA5|
 *                    INT_DMA6|INT_DMA7|INT_DMA8|INT_DMA9|INT_DMA10|INT_DMA11|
 *                    INT_DMA12|INT_DMA13|INT_DMA14|INT_DMA15|INT_DMA_Error|
 *                    INT_MCM|INT_FTFL|INT_Read_Collision|INT_LVD_LVW|INT_LLW|
 *                    INT_Watchdog|INT_RNGB|INT_I2C0|INT_I2C1|INT_SPI0|INT_SPI1|
 *                    INT_SPI2|INT_CAN0_ORed_Message_buffer|INT_CAN0_Bus_Off|
 *                    INT_CAN0_Error|INT_CAN0_Tx_Warning|INT_CAN0_Rx_Warning|
 *                    INT_CAN0_Wake_Up|INT_CAN0_IMEU|INT_CAN0_Lost_Rx|
 *                    INT_CAN1_ORed_Message_buffer|INT_CAN1_Bus_Off|
 *                    INT_CAN1_Error|INT_CAN1_Tx_Warning|INT_CAN1_Rx_Warning|
 *                    INT_CAN1_Wake_Up|INT_CAN1_IMEU|INT_CAN1_Lost_Rx|
 *                    INT_UART0_RX_TX|INT_UART0_ERR|INT_UART1_RX_TX|
 *                    INT_UART1_ERR|INT_UART2_RX_TX|INT_UART2_ERR|
 *                    INT_UART3_RX_TX|INT_UART3_ERR|INT_UART4_RX_TX|
 *                    INT_UART4_ERR|INT_UART5_RX_TX|INT_UART5_ERR|INT_ADC0|
 *                    INT_ADC1|INT_HSCMP0|INT_HSCMP1|INT_HSCMP2||INT_FTM0|
 *                    INT_FTM1|INT_FTM2|INT_CMT|INT_RTC|INT_PIT0|INT_PIT1|
 *                    INT_PIT2|INT_PIT3|INT_PDB0|INT_USB0|INT_USBDCD|
 *                    INT_ENET_1588_Timer|INT_ENET_Transmit|INT_ENET_Receive|
 *                    INT_ENET_Error|INT_I2S0|INT_SDHC|INT_DAC0|INT_DAC1|
 *                    INT_TSI0|INT_MCG|INT_LPTimer|INT_PORTA|INT_PORTB|
 *                    INT_PORTC|INT_PORTD|INT_PORTE|INT_Reserved108|
 *                    INT_Reserved109|INT_Reserved110|INT_Reserved111
 *                    \n\n<b>MK40 Device Interrupt Sources List:</b>
 *                    INT_DMA0|INT_DMA1|INT_DMA2|INT_DMA3|INT_DMA4|INT_DMA5|
 *                    INT_DMA6|INT_DMA7|INT_DMA8|INT_DMA9|INT_DMA10|INT_DMA11|
 *                    INT_DMA12|INT_DMA13|INT_DMA14|INT_DMA15|INT_DMA_Error|
 *                    INT_MCM|INT_FTFL|INT_Read_Collision|INT_LVD_LVW|INT_LLW|
 *                    INT_Watchdog|INT_I2C0|INT_I2C1|INT_SPI0|INT_SPI1|
 *                    INT_SPI2|INT_CAN0_ORed_Message_buffer|INT_CAN0_Bus_Off|
 *                    INT_CAN0_Error|INT_CAN0_Tx_Warning|INT_CAN0_Rx_Warning|
 *                    INT_CAN0_Wake_Up|INT_CAN0_IMEU|INT_CAN0_Lost_Rx|
 *                    INT_CAN1_ORed_Message_buffer|INT_CAN1_Bus_Off|
 *                    INT_CAN1_Error|INT_CAN1_Tx_Warning|INT_CAN1_Rx_Warning|
 *                    INT_CAN1_Wake_Up|INT_CAN1_IMEU|INT_CAN1_Lost_Rx|
 *                    INT_UART0_RX_TX|INT_UART0_ERR|INT_UART1_RX_TX|
 *                    INT_UART1_ERR|INT_UART2_RX_TX|INT_UART2_ERR|
 *                    INT_UART3_RX_TX|INT_UART3_ERR|INT_UART4_RX_TX|
 *                    INT_UART4_ERR|INT_UART5_RX_TX|INT_UART5_ERR|INT_ADC0|
 *                    INT_ADC1|INT_HSCMP0|INT_HSCMP1|INT_HSCMP2||INT_FTM0|
 *                    INT_FTM1|INT_FTM2|INT_CMT|INT_RTC|INT_PIT0|INT_PIT1|
 *                    INT_PIT2|INT_PIT3|INT_PDB0|INT_USB0|INT_I2S0|INT_SDHC|
 *                    INT_DAC0|INT_DAC1|INT_TSI0|INT_MCG|INT_LPTimer|INT_LCD|
 *                    INT_PORTA|INT_PORTB|INT_PORTC|INT_PORTD|INT_PORTE|
 *                    INT_Reserved108|INT_Reserved109|INT_Reserved110|
 *                    INT_Reserved111
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define NVIC_CallIsr(src) {                                                   \
                            NVIC_ISPR_REG(NVIC_BASE_PTR,ICPR_VALUE(src)) |=   \
                              (uint32)(1l << ICPR_SHIFT(src));                \
                            }

static uint32_t volatile * const SHPR_REG_PTR[] = {&SCB_SHPR1, &SCB_SHPR2, &SCB_SHPR3};
#define SHPR_INDEX(x)       (uint32)(((x)-4)/4)       
#define SHPR_SHIFT(x)       (uint32)(8*((x)%4))
/***************************************************************************//*!
 * @brief   Macro enables fault exception and sets its priority.
 * @param   src       <b>Fault Exceptions List:</b>
 *                    INT_NMI|INT_Hard_Fault|INT_MemManage_Fault|INT_Bus_Fault|
 *                    INT_Usage_Fault| INT_SVCall|INT_DebugMonitor|
 *                    INT_PendableSrvReq|INT_SysTick
 * @param   ipr     - interrupt priority <0-15>; lower means higher priority.
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define FAULT_SetIsr(src,ipr) {                                               \
                              SCB_SHCSR |= (uint32)(1l<<(src-4+16));          \
                              *SHPR_REG_PTR[SHPR_INDEX(src)] |=               \
                              (((uint32)((uint32)ipr<<4))<<SHPR_SHIFT(src));  \
                              }
/***************************************************************************//*!
 * @brief   Macro disables fault exception.
 * @param   src       <b>Fault Exceptions List:</b>
 *                    INT_NMI|INT_Hard_Fault|INT_MemManage_Fault|INT_Bus_Fault|
 *                    INT_Usage_Fault| INT_SVCall|INT_DebugMonitor|
 *                    INT_PendableSrvReq|INT_SysTick
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#define FAULT_ClrIsr(src)     {                                               \
                              SCB_SHCSR &= ~((uint32)(1l<<(src-4+16)));       \
                              *SHPR_REG_PTR[SHPR_INDEX(src)] &=               \
                              ~(((uint32)((uint32)0xf<<4))<<SHPR_SHIFT(src)); \
                              }

/***************************************************************************//*!
 * @brief   Macro generates system reset.
 * @note    Implemented as inlined macro.
 ******************************************************************************/
#pragma diag_suppress=Pe111
#define NVIC_SystemReset()    {                                               \
                                SCB_AIRCR = SCB_AIRCR_VECTKEY(0x5FA)|         \
                                            SCB_AIRCR_SYSRESETREQ_MASK;       \
                                while(1);                                     \
                              }

/***********************************************************************/
// function prototype for main function
void main(void);

/***********************************************************************/
#endif	/* _CPU_ARM_CM4_H */


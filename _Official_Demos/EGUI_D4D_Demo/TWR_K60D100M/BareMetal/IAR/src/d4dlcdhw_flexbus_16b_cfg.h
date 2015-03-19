/******************************************************************************
* 
* Copyright (c) 2010 Freescale Semiconductor;
* All Rights Reserved                       
*
*******************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
***************************************************************************//*!
*
* @file      d4dlcdhw_flexbus_16b_cfg.h
*
* @author    b01119
* 
* @version   0.0.3.0
* 
* @date      Feb-3-2011
* 
* @brief     D4D driver - flexbus_16b HW lcd config for Kinetis TWR-K60N512 
*
*******************************************************************************/

#ifndef __D4DLCDHW_FLEXBUS_16B_CFG_H
#define __D4DLCDHW_FLEXBUS_16B_CFG_H

  /******************************************************************************
  * includes
  ******************************************************************************/
  // include here what the driver need for run for example "derivative.h"
 //#include "derivative.h"    /* include peripheral declarations and more for S08 and CV1 */ 

 #include "MK60N512VMD100.h"
  
  /******************************************************************************
  * Constants
  ******************************************************************************/

  #define ALT5 (PORT_PCR_MUX(5)|PORT_PCR_DSE_MASK)           // Alternative function 5 = FB enable
  #define FLEX_CLK_INIT (SIM_CLKDIV1 |= SIM_CLKDIV1_OUTDIV3(1))// FlexBus = Sysclk/2 = ~48MHz 

  #define D4DLCD_DISPLAY_MCU_USER_INIT SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;\
                                       PORTC_PCR0=ALT5; PORTC_PCR1=ALT5; PORTC_PCR2=ALT5; PORTC_PCR3=ALT5; PORTC_PCR4=ALT5; PORTC_PCR5=ALT5; PORTC_PCR6=ALT5; PORTC_PCR7=ALT5; PORTC_PCR8=ALT5; PORTC_PCR9=ALT5; PORTC_PCR10=ALT5; PORTC_PCR11=ALT5;\
                                       PORTD_PCR1=ALT5; PORTD_PCR2=ALT5; PORTD_PCR3=ALT5; PORTD_PCR4=ALT5; PORTD_PCR5=ALT5; PORTD_PCR6=ALT5; PORTB_PCR17=ALT5; PORTB_PCR18=ALT5;\
                                       FLEX_CLK_INIT;SIM_SOPT2 |= SIM_SOPT2_FBSL(3); SIM_SCGC7 |= SIM_SCGC7_FLEXBUS_MASK;
                                       
                                         
                                                                                                                                                       
  #define D4DLCD_FLEX_BASE_ADDRESS  0x60010000
  #define D4DLCD_FLEX_DC_ADDRESS    0x60000000
  #define D4DLCD_FLEX_ADRESS_MASK   0x00010000
  
  #define D4DLCD_FLEX_CS 0
//#define CSCR_RESET 0x003ffC00
#define CSCR_RESET 0x00000000

// Kinetis Flexbus Register Macro redefinitions
  #define D4DLCD_FLEX_CSAR FB_CSAR0
  #define D4DLCD_FLEX_CSMR FB_CSMR0
  #define D4DLCD_FLEX_CSCR FB_CSCR0

// MUX mode + Wait States
  #define D4DLCD_FLEX_CSCR_MUX_MASK  (FB_CSCR_BLS_MASK | CSCR_RESET)
  #define D4DLCD_FLEX_CSMR_V_MASK    FB_CSMR_V_MASK 
  #define D4DLCD_FLEX_CSCR_AA_MASK   FB_CSCR_AA_MASK 
  #define D4DLCD_FLEX_CSCR_PS1_MASK  (FB_CSCR_PS(2)) 


  /*******************************************
  * Signals definition
  *******************************************/

  // Define void macros, because TWR-K60 board doesn't use RESET pin
  #define D4DLCD_INIT_RESET
  #define D4DLCD_ASSERT_RESET
  #define D4DLCD_DEASSERT_RESET
  
  // RESET pin definition -if used

  //#define D4DLCD_RESET        x           // Pin number 
  //#define D4DLCD_RESET_PORT   GPIOx_PDOR  // PortX Output Data Output  
  //#define D4DLCD_RESET_DDR    GPIOx_POER  // PortX Output Enable              
  //#define D4DLCD_RESET_PCR    PORTx_PCRx  // PAD configuration register 
           
  
  // BACKLIGHT pin definition -if used 
  
  //#define D4DLCD_BACKLIGHT        x           // Pin number 
  //#define D4DLCD_BACKLIGHT_PORT   GPIOx_PDOR  // PortX Output Data Output  
  //#define D4DLCD_BACKLIGHT_DDR    GPIOx_POER  // PortX Output Enable              
  //#define D4DLCD_BACKLIGHT_PCR    PORTx_PCRx  // PAD configuration register 

  
  /*********** Power macros - for modification uncoment and modify ***********/

  
  //#define D4DLCD_INIT_RESET OUTPUT(D4DLCD_RESET);
  //#define D4DLCD_ASSERT_RESET RESET(D4DLCD_RESET);
  //#define D4DLCD_DEASSERT_RESET SET(D4DLCD_RESET);
  
  // define here what you need to be configurable

#endif /* __D4DLCDHW_FLEXBUS_16B_CFG_H */
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
* @file      d4dlcdhw_kinetis_spi_cfg.h
*
* @author    b01119
* 
* @version   0.0.3.0
* 
* @date      Apr-4-2011
* 
* @brief     D4D driver - template hardware lcd driver configuration header file 
*
*******************************************************************************/

#ifndef __D4DLCDHW_KINETIS_SPI_CFG_H
#define __D4DLCDHW_KINETIS_SPI_CFG_H

  /******************************************************************************
  * includes
  ******************************************************************************/
  // include here what the driver need for run for example "derivative.h"
  // #include "derivative.h"    /* include peripheral declarations and more for S08 and CV1 */ 

 #include "MK60N512VMD100.h"


 /*******************************************
  * Signals definition
  *******************************************/
 
  #define D4DLCD_SPI_ID 2       // SPI module number
  #define D4DLCD_SPI_PCS_ID 0   // Chip Select used by SPI

  // tweak off the SPI frequency to maximum 25Mb/s, standard 12Mb/s
  #define D4DLCD_SPI_DBL_BRATE    


  
  // configure PADs for SPI functionality

  #define D4DLCD_SPI_MISO_PCR   PORTD_PCR14
  #define D4DLCD_SPI_MOSI_PCR   PORTD_PCR13
  #define D4DLCD_SPI_CLK_PCR    PORTD_PCR12
  #define D4DLCD_SPI_CS_PCR     PORTD_PCR11 // PCS0
  // #define D4DLCD_SPI_CS_PCR   PORTD_PCR15 // PCS1
    

 
  #define D4DLCD_DC             17          // PTB_17 
  #define D4DLCD_DC_PORT        GPIOB_PDOR  // PortB Output Data Output 
  #define D4DLCD_DC_DDR         GPIOB_PDDR  // PortB Output Enable 
  #define D4DLCD_DC_PCR         PORTB_PCR17 // PAD configuration register 

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
  

 // Enable clock to SPI module and Peripheral ports
  #define D4DLCD_DISPLAY_MCU_USER_INIT SIM_SCGC3 |= SIM_SCGC3_SPI2_MASK;\
                               SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK\
                               | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK \
                               | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;


 /*********** Power macros - for modification uncoment and modify ***********/

  //#define D4DLCD_INIT_CS OUTPUT(D4DLCD_CS);
  //#define D4DLCD_ASSERT_CS RESET(D4DLCD_CS);
  //#define D4DLCD_DEASSERT_CS SET(D4DLCD_CS);
  
  //#define D4DLCD_INIT_DC OUTPUT(D4DLCD_DC);
  //#define D4DLCD_ASSERT_DC RESET(D4DLCD_DC);
  //#define D4DLCD_DEASSERT_DC SET(D4DLCD_DC);
  
  //#define D4DLCD_INIT_RESET OUTPUT(D4DLCD_RESET);
  //#define D4DLCD_ASSERT_RESET RESET(D4DLCD_RESET);
  //#define D4DLCD_DEASSERT_RESET SET(D4DLCD_RESET);

  
  /******************************************************************************
  * Constants
  ******************************************************************************/ 
  // define here what you need to be configurable

#endif /* __D4DLCDHW_KINETIS_SPI_CFG_H */
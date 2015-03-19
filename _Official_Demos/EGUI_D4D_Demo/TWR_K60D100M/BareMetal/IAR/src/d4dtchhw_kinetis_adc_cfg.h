/******************************************************************************
* 
* Copyright (c) 2009 Freescale Semiconductor;
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
* @file      d4dtchhw_kinetis_adc_cfg.h
*
* @author    b01119
* 
* @version   0.0.3.0
* 
* @date      Apr-4-2011
* 
* @brief     D4D driver - resistive touch screen driver function header file 
*
*******************************************************************************/

#ifndef __D4DTCH_RESISTIVE_CFG_H
#define __D4DTCH_RESISTIVE_CFG_H


  /******************************************************************************
  * includes
  ******************************************************************************/
  
  //#include "derivative.h"    /* include peripheral declarations and more for S08 and CV1 */ 
  //#include "support_common.h" /* include peripheral declarations and more for CV2 */

  #include "MK60N512VMD100.h"

  /******************************************************************************
  * Constants
  ******************************************************************************/
  
  #define D4DTCH_ADC_HW D4DTCH_ADC_HW_KINETIS
  
  #define D4DTCH_ADC_ID 1 // Use ADC module 1
  
  // X+ wire definition  
  #define D4DTCH_X_PLUS   4
  #define D4DTCH_X_PLUS_PORT  GPIOB_PDOR  // Data output register
  #define D4DTCH_X_PLUS_DDR   GPIOB_PDDR  // Output enable register
  #define D4DTCH_X_PLUS_ADCH  10          // ADC channel number
  #define D4DTCH_X_PLUS_PCR   PORTB_PCR4

//#define D4DTCH_X_PLUS_ADCH_PIN_ENABLE  (D4DTCH_X_PLUS_PCR = PORT_PCR_MUX(0)); // Mux ADC
//#define D4DTCH_X_PLUS_ADCH_PIN_DISABLE (D4DTCH_X_PLUS_PCR = PORT_PCR_MUX(1)); // Mux GPIO

  //#define D4DTCH_INIT_X_PLUS  OUTPUT(D4DTCH_X_PLUS); RESET(D4DTCH_X_PLUS); 
  //#define D4DTCH_RESET_X_PLUS RESET(D4DTCH_X_PLUS);
  //#define D4DTCH_SET_X_PLUS   SET(D4DTCH_X_PLUS);
  
  // X- wire definition 
  #define D4DTCH_X_MINUS  6        
  #define D4DTCH_X_MINUS_PORT  GPIOB_PDOR  
  #define D4DTCH_X_MINUS_DDR   GPIOB_PDDR
  #define D4DTCH_X_MINUS_PCR   PORTB_PCR6
  
  //#define D4DTCH_INIT_X_MINUS  OUTPUT(D4DTCH_X_MINUS); RESET(D4DTCH_X_MINUS); 
  //#define D4DTCH_RESET_X_MINUS RESET(D4DTCH_X_MINUS);
  //#define D4DTCH_SET_X_MINUS   SET(D4DTCH_X_MINUS);  
  //#define D4DTCH_X_MINUS_HIGH_Z_ENABLE INPUT(D4DTCH_X_MINUS);
  //#define D4DTCH_X_MINUS_HIGH_Z_DISABLE OUTPUT(D4DTCH_X_MINUS);
  
  // Y+ wire definition 
  #define D4DTCH_Y_PLUS   7      
  #define D4DTCH_Y_PLUS_PORT  GPIOB_PDOR  
  #define D4DTCH_Y_PLUS_DDR   GPIOB_PDDR
  #define D4DTCH_Y_PLUS_ADCH   13
  #define D4DTCH_Y_PLUS_PCR   PORTB_PCR7

//#define D4DTCH_Y_PLUS_ADCH_PIN_ENABLE  (D4DTCH_Y_PLUS_PCR = PORT_PCR_MUX(0)); // Mux ADC
//#define D4DTCH_Y_PLUS_ADCH_PIN_DISABLE (D4DTCH_Y_PLUS_PCR = PORT_PCR_MUX(1)); // Mux GPIO

  //#define D4DTCH_INIT_Y_PLUS  OUTPUT(D4DTCH_Y_PLUS); RESET(D4DTCH_Y_PLUS); 
  //#define D4DTCH_RESET_Y_PLUS RESET(D4DTCH_Y_PLUS);
  //#define D4DTCH_SET_Y_PLUS   SET(D4DTCH_Y_PLUS);
  
  // Y- wire definition 
  #define D4DTCH_Y_MINUS  5  
  #define D4DTCH_Y_MINUS_PORT  GPIOB_PDOR  
  #define D4DTCH_Y_MINUS_DDR   GPIOB_PDDR
  #define D4DTCH_Y_MINUS_PCR   PORTB_PCR5
 
  //#define D4DTCH_INIT_Y_MINUS  OUTPUT(D4DTCH_Y_MINUS); RESET(D4DTCH_Y_MINUS); 
  //#define D4DTCH_RESET_Y_MINUS RESET(D4DTCH_Y_MINUS);
  //#define D4DTCH_SET_Y_MINUS   SET(D4DTCH_Y_MINUS);  
  //#define D4DTCH_Y_MINUS_HIGH_Z_ENABLE INPUT(D4DTCH_Y_MINUS);
  //#define D4DTCH_Y_MINUS_HIGH_Z_DISABLE OUTPUT(D4DTCH_Y_MINUS);
  
  // definition of calibration cross offset on on screen in pixels
  //#define D4DTCH_CALIB_CROSS_OFFSET 30

  // Constant specifying maximum ADC value for a screen touch (=12bits)
  #define D4DTCH_FULL_SCALE           0x0FFF

  // Constants specifying minimum ADC value for a screen touch
  //#define D4DTCH_X_TOUCH_MIN              (D4DTCH_FULL_SCALE / 10)
  //#define D4DTCH_Y_TOUCH_MIN              (D4DTCH_FULL_SCALE / 10)

  //#define D4DTCH_X_TOUCH_OFFMAX              (D4DTCH_X_TOUCH_MIN * 4 / 2)
  //#define D4DTCH_Y_TOUCH_OFFMAX              (D4DTCH_Y_TOUCH_MIN * 4 / 2)

  // Constants specifying ADC difference for touch screen sample
  //#define D4DTCH_SAMPLE_MARGIN            (D4DTCH_FULL_SCALE / 256)

#endif /* __D4DTCH_RESISTIVE_CFG_H */
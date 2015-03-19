/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved                       
*
* Copyright (c) 1989-2008 ARC International;
* All Rights Reserved
*
*************************************************************************** 
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
**************************************************************************
*
* $FileName: main.c$
* $Version : 1.0$
* $Date    : Mar-19-2015$
*
* Comments:
*
*   This file contains the source for the eGUI example program.
*
*END************************************************************************/

// Jumper settings on LCD story - TWR-LCD-REV A:

// TWRK60N512 + TWR_LCD SW1 configuration:
// POS:   1 2 3 4 5 6 7 8
// SPI:   0 1 1 1 1 1 1 0
// FLEX:  1 0 1 1 1 1 1 0

#include "main.h"
#include <stdio.h>
#include "common.h"
#include "mcg.h"
#include "sim.h"
#include "pit.h"

D4D_EXTERN_SCREEN(screen_entry)

TIME_FLAGS time;
LWord time100sm_cnt = 0;


/*PIT CallBack*---------------------------------------
* 
* Function Name    : Time_event25ms
* Comments     :
*    This function do: 	periodical events in 25ms
*
*END*-----------------------------------------------------*/
static void Time_event25ms(void)
{
  static Byte actual_time = 0;
  TIME_FLAGS t_flags;

  D4D_TimeTickPut();
		
  /* set the internal time flags */
  actual_time++;
  t_flags.all = (LWord)(actual_time ^ (actual_time - 1));

  time.all |= t_flags.all;
  
  if(t_flags.bits.b50ms)
    D4D_CheckTouchScreen();
  
  if(t_flags.bits.b100ms)
    time100sm_cnt++;		
}

/*TASK*-----------------------------------------------------
* 
* Task Name    : main
* Comments     :
*    Example application of eGUI display
*
*END*-----------------------------------------------------*/
void main(void)
{
  SIM_Init  (SIM_MODULE_CONFIG);  
  PLL_Init  (CORE_CLK_MHZ, REF_CLK); 
  printf("Hello from eGUI demo\n\r");     

  // Init eGUI
  if(!D4D_Init(&screen_entry))
  {
    // D4D initialization failed
    printf("eGUI/D4D initialization failed\n\r");   
  }

  // Setup right screen orientation
  D4D_SetOrientation(D4D_ORIENT_LANDSCAPE);

  // Force calibration screen
  D4D_CalibrateTouchScreen();
  
  // Init periodical timer
  PIT_Init(PIT0, PIT_CH_CONFIG, (uint32)(0.025 / (1.0/D4D_MCU_BUS_CLOCK)), 8, Time_event25ms);
  PIT_Enable();
  
  // Enable interrupts
  EnableInterrupts;
  
  for(;;)
  {
    // Periodical call of the eGUI handler
    D4D_Poll();
  }
}

/* EOF */

/*****************************************************************************
 * (c) Copyright 2010, Freescale Semiconductor Inc.
 * ALL RIGHTS RESERVED.
 ***************************************************************************//*!
 * @file      sim.c
 * @author    R55013
 * @version   1.0.5.0
 * @date      Jan-24-2013
 * @brief     SIM driver implementation.
 * @par       Driver example:
 * @include   vref_test\vref_test.c
 * @par       Interrupt vector definition(s):
 * @include   vref_test\isr.h		
 ******************************************************************************/
#include "common.h"
#include "sim.h"

/******************************************************************************
 * Public functions definitions                                               *
 ******************************************************************************/
 
/***************************************************************************//*!
 * @brief   SIM module initialization function.
 * @param   sim     - SIM module configuration structure passed by value:\n 
 *                    SIM_MODULE_CONFIG\n
 * @return  none
 * @note    Implemented as function call.
 ******************************************************************************/
#pragma diag_suppress=Pa082
void SIM_Init (tSIM sim)
{
    SIM_SOPT1   |= sim.SOPT1;
    SIM_SOPT2   |= sim.SOPT2;
    SIM_SOPT4   |= sim.SOPT4;
    SIM_SOPT5   |= sim.SOPT5;
    //SIM_SOPT6   |= sim.SOPT6; B34185
    SIM_SOPT7   |= sim.SOPT7;
    SIM_SCGC1   |= sim.SCGC1;
    SIM_SCGC2   |= sim.SCGC2;
    SIM_SCGC3   |= sim.SCGC3;
    SIM_SCGC4   |= sim.SCGC4;
    SIM_SCGC5   |= sim.SCGC5;
    SIM_SCGC6   |= sim.SCGC6;
    SIM_SCGC7   |= sim.SCGC7;
    SIM_CLKDIV1 |= sim.CLKDIV1;
    SIM_CLKDIV2 |= sim.CLKDIV2;
}
/******************************************************************************
 * End of module                                                              *
 ******************************************************************************/
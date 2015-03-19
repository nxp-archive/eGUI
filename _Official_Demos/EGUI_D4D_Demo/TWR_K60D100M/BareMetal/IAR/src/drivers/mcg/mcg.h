/*
 * File:    pll_init.h
 * Purpose: pll_driver specific declarations
 *
 * Notes:
 */
#ifndef __MCG_H__
#define __MCG_H__
/********************************************************************/

void PLL_Init(unsigned char, unsigned char);

enum clk_option
{
  PLL50,
  PLL100,
  PLL96,
  PLL48
};

enum crystal_val
{
  XTAL2,
  XTAL4,
  XTAL6,
  XTAL8,
  XTAL10,
  XTAL12,
  XTAL14,
  XTAL16,
  XTAL18,
  XTAL20,
  XTAL22,
  XTAL24,
  XTAL26,
  XTAL28,
  XTAL30,
  XTAL32,
  XTAL34,
  XTAL36,
  XTAL38,
  XTAL40,
  XTAL42,
  XTAL44,
  XTAL46,
  XTAL48,
  XTAL50                    
};

/********************************************************************/
#endif /* __MCG_H__ */

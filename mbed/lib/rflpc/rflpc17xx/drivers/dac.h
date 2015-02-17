/* This file is part of rflpc. Copyright 2010-2011 Michael Hauspie
 *
 * rflpc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rflpc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rflpc.  If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 * Digital To Analog Converter (DAC) driver
 */

#ifndef __RFLPC_DAC_H__
#define __RFLPC_DAC_H__

/*
  Author: Christophe Bacara <christophe.bacara@etudiant.univ-lille1.fr
*/

#ifdef RFLPC_CONFIG_ENABLE_DAC

#include "../rflpc17xx.h"

/** @addtogroup dac DAC
 * Digital-To-Analog Converter driver
 * @ingroup drivers
 * @{
 */

/**
 * Initializes the Digital To Analog Converter.
 *
 * @param clock_divider The divider applied to CPU clock.
 *
 * @note The DAC is only connected on pin P0.26, thus the init cannot
 * change the pin. On the MBED it corresponds to the DIP18 pin
 */
extern void rflpc_dac_init(uint8_t clock_divider);

/**
 * Set the value of DAC register.
 *
 * @param value A 10-bits value to be converted.
 */
static inline void rflpc_dac_write(uint16_t value)
{
   RFLPC_SET_BITS_VAL (LPC_DAC->DACR, 6, (value & 0x3FF), 10);
}

#endif /* RFLPC_CONFIG_ENABLE_DAC */

/** @} */

#endif /* __RFLPC_DAC_H__ */

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
/*
  Author: Michael Hauspie <michael.hauspie@univ-lille1.fr>
  Created:
  Time-stamp: <2012-12-19 16:05:13 (hauspie)>

  Provides macro to set pin function and modes
*/

#include "pinconf.h"

void rflpc_pin_set(rflpc_pin_t p, int function, rflpc_pin_mode_t mode, int opendrain)
{
    int register_idx = 2*RFLPC_PIN_GET_PORT(p);
    int pin = RFLPC_PIN_GET_PIN(p);

    if (pin >= 16)
    {
	pin -= 16;
	register_idx++;
    }

    /* Configure function */
    *(&(LPC_PINCON->PINSEL0) + register_idx) &= ~(3 << (pin * 2));
    *(&(LPC_PINCON->PINSEL0) + register_idx) |= ((function & 0x3) << (pin * 2));

    /* Configure mode */
    *(&(LPC_PINCON->PINMODE0) + register_idx) &= ~(3 << (pin * 2));
    *(&(LPC_PINCON->PINMODE0) + register_idx) |= ((mode & 0x3) << (pin * 2));

    /* Configure opendrain */
    if (opendrain)
	*(&(LPC_PINCON->PINMODE_OD0) + RFLPC_PIN_GET_PORT(p)) |= (1 << pin);
    else
	*(&(LPC_PINCON->PINMODE_OD0) + RFLPC_PIN_GET_PORT(p)) &= ~(1 << pin);
}

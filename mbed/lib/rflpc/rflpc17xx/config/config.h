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
#ifndef __RFLPC_CONFIG_H__
#define __RFLPC_CONFIG_H__
/** @file
 * Platform independent configuration options.
 * */


/*
    Author: Michael Hauspie <michael.hauspie@univ-lille1.fr>
    Created: 2011-07-04
    Time-stamp: <2012-03-21 09:56:54 (hauspie)>

    This files permits the configuration of the platform.
    It includes a platform-dependent config file for your target.

    Only mbed is available, but you can create one for your LPC17xx platform.

 */

/* Include file that defines what is compiled in the library */
#include "config-options.h"

#ifdef RFLPC_CONFIG_PLATFORM_MBED
/* If you want to use the library on another LPC17xx based platform, create a
   config-xxx.h file for it (copy the config-mbed.h as a starting base). The file
   should define some pin connections and the activation/deactivation macro for
   parts of the library.
*/
#include "config-mbed.h"
#endif



/** @addtogroup config 
 * @ingroup system
 * @{
 */

/** @name Stack configuration */
/** @{ */
/** size of the stack in bytes */
#ifndef RFLPC_STACK_SIZE
#define RFLPC_STACK_SIZE 1024
#endif
/** @} */


/** @name Interrupt configuration */
/** @{ */
/** If this constant is defined, then freeze the device on unhandled interrupt
 */
#define RFLPC_IRQ_DEBUG_ENABLE

/** This is the size of the interrupt vector */
#define RFLPC_IRQn_COUNT (PLL1_IRQn + 16 +1)
/** @} */

/** @} */

#endif

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

#ifndef __RFLPC_PRINTF_H__
#define __RFLPC_PRINTF_H__
/*
  Author: Michael Hauspie <michael.hauspie@univ-lille1.fr>
  Created:
  Time-stamp: <2012-03-21 09:14:56 (hauspie)>
*/
/** @file
 * An implementation of formated output
 */

#ifdef RFLPC_CONFIG_ENABLE_PRINTF

/** @addtogroup libc
 * @{ */

/** Formated output function.
 * This function is similar to stdio's printf.
    However, it only handles:
    - %%d
    - %%x/X (%0?X can also be used, where ? is a digit [1-9])
    - %%p
    - %%c
    - %%s

    @note If another format char is used, int is assumed to skip
    argument, but nothing is printed unless RFLPC_VERBOSE_PRINTF
    is defined when compiling lib. If RFLPC_CONFIG_ENABLE_ATOMIC_PRINTF is defined,
    interrupts are disabled when entering printf and enabled before exiting

    @warning This function uses a function pointer to output each character. 
    By default, it uses a function which eventually call ::rflpc_uart_putchar with ::RFLPC_UART0.
    If you want to use your own putchar function, you have to call ::rflpc_printf_set_putchar
    to set the function pointer.

   @param [in] format The format string. Prefer to use constant string
   instead of user supplied string to be sure that some escape characters are not put for wrong purpose.
*/
extern int printf(const char *format,...);


/** Sets the internal function pointer that is used by ::printf to output a character.
 * By default, it uses a function that call ::rflpc_uart_putchar with ::RFLPC_UART0.
 * @param [in] putchar_func a pointer to a function that takes a character to put and returns it.
 */
extern void rflpc_printf_set_putchar(int (*putchar_func)(int c));

/** @} */

#endif /* ENABLE_PRINTF */

#endif

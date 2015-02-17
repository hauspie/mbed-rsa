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
    Time-stamp: <2014-02-14 12:25:22 (hauspie)>
*/

#ifdef RFLPC_CONFIG_ENABLE_PRINTF

#include <stdarg.h>
#include <stdint.h>
#include "printf.h"
#include "../interrupt.h"

#ifdef RFLPC_CONFIG_ENABLE_UART
#include "../drivers/uart.h"
#endif
static int _rflpc_default_putchar(int c)
{
#ifdef RFLPC_CONFIG_ENABLE_UART
    rflpc_uart_putchar(RFLPC_UART0, c);
#endif
    return c;
}

static int (*_rflpc_putchar)(int c) = _rflpc_default_putchar;

#define PUTCHAR(c) do { ++count; _rflpc_putchar((c)); } while(0)
#define PUTS(s) do {const char *str=s; while (*str) PUTCHAR(*str++);}while(0)


#define PUT_HEXA_DIGIT(d,a_letter) do {			\
	if ((d) >=0 && (d) <= 9)			\
	    PUTCHAR('0' + (d));				\
	else						\
	    PUTCHAR((a_letter) + ((d) - 0xA));		\
    } while (0)

#define PUT_HEXA_BYTE(b, a_letter) do {				\
	PUT_HEXA_DIGIT(((b)>>4), (a_letter));			\
	PUT_HEXA_DIGIT(((b) & 0xF), (a_letter));		\
    } while (0)

#define PUT_HEXA_VAL(val,a_letter,bits, print_zero) do {		\
	int b = (bits) - 4;						\
	if (!(print_zero)) {						\
	    while ((b > 0) && (((val) >> b) & 0xF) == 0)		\
		b -=4;							\
	}								\
	for ( ; b >= 0 ; b -= 4)					\
	    PUT_HEXA_DIGIT(((val) >> b) & 0xF, (a_letter));		\
    } while(0)


#define PUT_INT_DIGIT(i) do {			\
	PUTCHAR('0' + (i));			\
    } while(0);

#define PUT_INT_NUMBER(i) do {					\
	unsigned int max_pow = 1;				\
	unsigned int val = i;					\
	while ((val) / (max_pow) >= 10) max_pow*=10;		\
	for ( ; max_pow >= 1; max_pow /= 10)			\
	{							\
	    PUT_INT_DIGIT((val)/max_pow);			\
	    val = val % max_pow;				\
	}							\
    } while(0);

int printf(const char *format, ...)
{
    va_list args;
    int count = 0; /* number of char printed */
    int print_zero = 0;
    int ccount = sizeof(unsigned int);
    va_start(args, format);

#ifdef RFLPC_CONFIG_ENABLE_ATOMIC_PRINTF
   rflpc_irq_global_disable();
#endif
    while (*format)
    {
	switch (*format)
	{
	    case '%':
		++format;
		if (*format == '0')
		{
		    print_zero = 1;
		    ++format;
		}
		if (*format >= '2' && *format <= '4')
		{
		    ccount = (*format - '0') / 2;
		    ++format;
		}
		switch(*format)
		{
		    case 'd':
		    case 'i':
		    {
			int i = (int) va_arg(args,int);
			if (i < 0)
			{
			    i = -i;
			    PUTCHAR('-');
			}
			PUT_INT_NUMBER(i);
		    }
		    break;
		    case 'u':
		    {
			unsigned int i = (unsigned int) va_arg(args,unsigned int);
			PUT_INT_NUMBER(i);
		    }
		    break;
		    case 'p':
		    case 'P':
		    {
			void *p = (void *)va_arg(args,void*);
			PUTCHAR('0');
			PUTCHAR('x');
			PUT_HEXA_VAL((uint32_t)p,(*format - ('p' - 'a')), sizeof(void*)<<3, 1);
		    }
		    break;
		    case 'x':
		    case 'X':
		    {
			unsigned int val = (unsigned int) va_arg(args, unsigned int);
			/* print the hexa val using lower case letter or upper
			 * case letter depending on 'x' or 'X' */
			PUT_HEXA_VAL(val,(*format - ('x' - 'a')),ccount<<3, print_zero);
			print_zero = 0;
		    }
		    break;
		    case 'c':
		    {
			char c = (char) va_arg(args, int);
			PUTCHAR(c);
			break;
		    }
		    case 's':
		    {
			const char *s = (const char*) va_arg(args, const char*);
			PUTS(s);
			break;
		    }
		    case '%':
			PUTCHAR('%');
		    break;

		    default:
		    {
			/* not handled arg, assume int and get next */
			(int) va_arg(args, int);
#ifdef RFLPC_VERBOSE_PRINTF
			PUTS("!Not handled format char: '");
			PUTCHAR(*format);
			PUTS("', treated as int!");
#endif
		    }
		    break;
		}
		break;
	    default:
		PUTCHAR(*format);
		break;
	}
	++format;
    }
    va_end(args);
#ifdef RFLPC_CONFIG_ENABLE_ATOMIC_PRINTF
    rflpc_irq_global_enable();
#endif
    return count;
}

void rflpc_printf_set_putchar(int (*putchar_func)(int c))
{
    _rflpc_putchar = putchar_func;
}

#endif /* ENABLE_PRINTF */

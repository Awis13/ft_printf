/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:55:00 by nipostni          #+#    #+#             */
/*   Updated: 2023/02/07 16:01:48 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include "../include/libft.h"
#include "../include/ft_printf.h"
#include <fcntl.h>
#include <stdbool.h>
#include <limits.h>

void ft_putchar(char c, int *printed_len)
{
	write(1, &c, 1);
	*printed_len += 1;
}


void ft_put_hex(unsigned long n, int *printed_len, bool is_capital)
{
	char *hex;
	char *hex_capital;

	hex = "0123456789abcdef";
	hex_capital = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_put_hex(n / 16, printed_len, is_capital);
		ft_put_hex(n % 16, printed_len, is_capital);
	}
	else
	{
		if (is_capital)
			ft_putchar(hex_capital[n], printed_len);
		else
			ft_putchar(hex[n], printed_len);
	}
}

void ft_putstr(char *format, int *printed_len)
{
	while (*format)
		ft_putchar(*format++, printed_len);
}

void ft_putnbr(long n, int *printed_len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", printed_len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', printed_len);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, printed_len);
		ft_putnbr(n % 10, printed_len);
	}
	else
		ft_putchar(n + '0', printed_len);
}


void	ft_handle_string(char *temp, int *printed_len)
{
	if (temp == NULL)
		ft_putstr("(null)", printed_len);
	else
		ft_putstr(temp, printed_len);
}

void ft_handle_ptr(void *ptr, int *printed_len)
{
	ft_putstr("0x", printed_len);
	ft_put_hex((unsigned long)ptr, printed_len, false);
}


int ft_printf(const char *format, ...)
{
	int			printed_len;
	va_list 	args;
	
	printed_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
				ft_putnbr(va_arg(args, int), &printed_len);
			else if (*format == 's')
				ft_handle_string(va_arg(args, char *), &printed_len);
			else if (*format == 'c')
				ft_putchar(va_arg(args, int), &printed_len);
			else if (*format == 'i')
				ft_putnbr(va_arg(args, int), &printed_len);
			else if (*format == 'u')
				ft_putnbr(va_arg(args, unsigned int), &printed_len);
			else if (*format == 'x')
				ft_put_hex(va_arg(args, unsigned int), &printed_len, false);
			else if (*format == 'X')
				ft_put_hex(va_arg(args, unsigned int), &printed_len, true);
			else if (*format == 'p')
				ft_handle_ptr(va_arg(args, void *), &printed_len);
			else if (*format == '%')
				ft_putchar('%', &printed_len);
			format++;
		}
		else
			ft_putchar(*format++, &printed_len);
	}
	va_end(args);
	return (printed_len);
}

// int main(void)
// {
//     char *x = " %s ";
// 	char *y = "hello";
//     ft_printf(x, y);
//     printf("\n");
//     printf(x, y);
// }
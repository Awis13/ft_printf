/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <nipostni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:55:00 by nipostni          #+#    #+#             */
/*   Updated: 2023/02/06 18:32:19 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include "../include/libft.h"
#include "../include/ft_printf.h"
#include <fcntl.h>
#include <stdbool.h>

void ft_putchar(char c, int *printed_len)
{
	write(1, &c, 1);
	*printed_len += 1;
}

void ft_putstr(char *str, int *printed_len)
{
	while (*str)
	{
		ft_putchar(*str, printed_len);
		str++;
	}
}

void ft_putnbr(int n, int *printed_len)
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


int ft_printf(const char *format, ...)
{
	char *str;
	int printed_len;
	va_list args;
	str = (char *)format;
	printed_len = 0;
	va_start(args, format);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd')
			{
				ft_putnbr(va_arg(args, int), &printed_len);
				str++;
			}
			else if (*str == 's')
			{
				char *temp = va_arg(args, char *);
				if (temp == NULL)
					ft_putstr("(null)", &printed_len);
				else {
					ft_putstr(temp, &printed_len);
				}
				str++;
			}
			else if (*str == 'c')
			{
				ft_putchar(va_arg(args, int), &printed_len);
				str++;
			}
			else if (*str == 'i')
			{
				ft_putnbr(va_arg(args, int), &printed_len);
				str++;
			}
			else if (*str == 'u')
			{
				ft_putnbr(va_arg(args, unsigned int), &printed_len);
				str++;
			}
			else if (*str == 'x')
			{
				ft_putnbr(va_arg(args, unsigned int), &printed_len);
				str++;
			}
			else if (*str == 'X')
			{
				ft_putnbr(va_arg(args, unsigned int), &printed_len);
				str++;
			}
			else if (*str == 'p')
			{
				ft_putnbr(va_arg(args, unsigned long), &printed_len);
				str++;
			}
			else if (*str == '%')
			{
				ft_putchar('%', &printed_len);
				str++;
			}
		}
		else
		{
			ft_putchar(*str, &printed_len);
			str++;
		}
	}

	return (printed_len);
}

// int main(void)
// {
//     char *x = "NULL %s NULL";
// 	char *y = NULL;
//     ft_printf(x, y);
//     printf("\n");
//     printf(x, y);
// }
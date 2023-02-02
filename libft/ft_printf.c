/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <nipostni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:55:00 by nipostni          #+#    #+#             */
/*   Updated: 2023/02/02 16:53:19 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include "../include/libft.h"
#include <fcntl.h>
#include <stdbool.h>

char *ft_check_the_flag(va_list args, int flag, bool *done, const char *format, int position)
{

	
	if(flag == 's')
	{
		char *str = va_arg(args, char *);
		ft_putstr_fd(str, 1);
	}
    if(flag == 'd')
    {
        ft_putnbr_fd((va_arg(args, int)), 1);
    }
    if(flag == 'c')
    {
        char c = ((va_arg(args, int)), 1);
        ft_putchar_fd(c, 1);
    }
    if(flag == 'i')
    {
        ft_putnbr_fd((va_arg(args, int)), 1);
    }
    if(flag == 'u')
    {
        unsigned int integer = va_arg(args, unsigned int);
        ft_putnbr_fd(integer, 1);

    }
    
    if(flag == '%')
    {
        ft_putchar_fd('%', 1);
    }
                
	if(ft_isdigit(flag) == 1)
	{
       
		int i = 0;
		int integer = va_arg(args, int);
		int len = ft_strlen(ft_itoa(integer));
		int width = flag - '0';
		while(i < width - len)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		ft_putnbr_fd(integer, 1);
		
		*done = true;
	
	}
  
    return(0);
}

int ft_printf(const char *format, ...)
{
    // char *temp;
    // int len;
    va_list args;
    int i = 0;
    // len = ft_strlen(format);
    va_start(args, format);
	bool done = false;

    while (format[i] && done == false)
    {
        char c = format[i];
        if(c == '%')
        {
            ft_check_the_flag(args, format[i + 1], &done, format, i);
            i += 2;
        }
        else
        {
        ft_putchar_fd(c, 1); 
        i++;
        }
    }
    


    va_end(args);
    return(0);
}

int main(void)
{
    char *x = "%7d";
	int y = 33;
    ft_printf(x, y);
    printf("\n");
    printf(x, y);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <nipostni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:55:00 by nipostni          #+#    #+#             */
/*   Updated: 2023/01/30 18:28:35 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include "../include/libft.h"

char *ft_check_the_flag(va_list args, const char *format, int flag)
{
    if(flag == 'd')
    {
        ft_putnbr_fd((va_arg(args, int)), 1);
    }
    if(flag == 'c')
    {
        ft_putchar_fd((va_arg(args, int)), 1);
    }
   
    
}

int ft_printf(const char *format, ...)
{
    char *temp;
    int len;
    va_list args;
    int i = 0;
    len = ft_strlen(format);
    va_start(args, format);

    while (format[i])
    {
        char c = format[i];
        if(c == '%')
        {
            ft_check_the_flag(args, format, format[i + 1]);
            i = i + 2;
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
    char *x = "111%d222%d333%c444%c555\n";
    int y = 5;
    int z = 9;
    ft_printf(x, y, z, 'z', 'q');
}
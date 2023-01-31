/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <nipostni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:55:00 by nipostni          #+#    #+#             */
/*   Updated: 2023/01/31 18:15:38 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include "../include/libft.h"

char *ft_check_the_flag(va_list args, int flag)
{
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
        ft_putchar_fd('%', 1);
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

    while (format[i])
    {
        char c = format[i];
        if(c == '%')
        {
            ft_check_the_flag(args, format[i + 1]);
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

// int main(void)
// {
//     char *x = "%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c";
    
//     // char *x = "%utest\n";
//     // int y = 5;
//     // int z = 9;
//     // ft_printf(x, y, z, 'z', 'q', 8, -4);
//     // printf(x, y, z, 'z', 'q', 8, -4);
//     // printf(x, y);
//     ft_printf(x, 1);
//     printf(x, 1);
// }
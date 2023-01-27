/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <nipostni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:55:00 by nipostni          #+#    #+#             */
/*   Updated: 2023/01/27 18:49:41 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

int ft_printf(const char *format, ...)
{
    char x;
    va_list args;
    va_start(args, format);
    while (args)
    {
        x = va_arg(args, char);
        printf("%c", x);
    }
    
    va_end(args);
    return(0);
}

int main(void)
{
    char c = 'a';
    ft_printf(c);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:44:09 by Nipostni          #+#    #+#             */
/*   Updated: 2022/12/20 16:17:40 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Counts the number of digits in an integer
 */

int ft_int_count(int n) {
    int count = 0;
    if (n == 0) return 1;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

/*
 * Converts an integer to a string and returns a pointer to the resulting string
 */

char *ft_itoa(int n) {
    long lon = n;
    int len = ft_int_count(n);
    char *str;

    if (lon < 0) {
        lon = -lon;
        len++;
    }

    str = malloc(sizeof(char) * (len + 1));
    if (!str) return NULL;

    str[len] = '\0';
    if (n == 0) str[0] = '0';

    while (lon != 0) {
        str[len - 1] = (lon % 10) + '0';
        lon /= 10;
        len--;
    }

    if (n < 0) str[0] = '-';
    return str;
}

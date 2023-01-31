/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:25:13 by nipostni          #+#    #+#             */
/*   Updated: 2022/12/06 20:37:21 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** The ft_atoi function converts a string representation of an integer to its
** integer equivalent. It skips over leading whitespace and handles optional
** leading +/- signs before processing the numerical digits and returning the
** result.
*/

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	return (result * sign);
}

// int	main(void)
// {
// 	const char *str1 = "42";
// 	const char *str2 = "-13";
// 	const char *str3 = "   17";
// 	const char *str4 = "  +15";

// 	printf("%d\n", ft_atoi(str1));
// 	printf("%d\n", ft_atoi(str2));
// 	printf("%d\n", ft_atoi(str3));
// 	printf("%d\n", ft_atoi(str4));

// 	return (0);
// }
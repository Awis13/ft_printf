/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:34:49 by Nipostni          #+#    #+#             */
/*   Updated: 2022/12/06 20:37:51 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isalnum checks if the given character is alphanumeric, i.e.,
** if it is a letter (upper or lower case) or a digit.
**
** The function takes an integer representing an ASCII code as an argument.
**
** If the character is alphanumeric, the function returns 1 (true),
** otherwise it returns 0 (false).
*/

#include "libft.h"
#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	int c;

	c = 'a';
	printf("ft_isalnum('%c') = %d\n", c, ft_isalnum(c));

	c = 'Z';
	printf("ft_isalnum('%c') = %d\n", c, ft_isalnum(c));

	c = '9';
	printf("ft_isalnum('%c') = %d\n", c, ft_isalnum(c));

	c = ' ';
	printf("ft_isalnum('%c') = %d\n", c, ft_isalnum(c));

	c = '@';
	printf("ft_isalnum('%c') = %d\n", c, ft_isalnum(c));

	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:46:23 by nipostni          #+#    #+#             */
/*   Updated: 2022/12/20 16:46:25 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memcmp compares the first n bytes of memory area s1 and s2.
** It returns an integer less than, equal to, or greater than zero if the
** first n bytes of s1 are found, respectively, to be less than, to match,
** or be greater than the first n bytes of s2.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sp1 = s1;
	const unsigned char	*sp2 = s2;

	if (n != 0)
	{
		while (n != 0)
		{
			if (*sp1 != *sp2)
			{
				return (*sp1 - *sp2);
			}
			sp1++;
			sp2++;
			n--;
		}
	}
	return (0);
}

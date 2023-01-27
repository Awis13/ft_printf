/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:31:42 by Nipostni          #+#    #+#             */
/*   Updated: 2022/12/20 17:34:34 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies 'n' bytes from memory area 'src' to memory area 'dst'.
** The memory areas may overlap.
*/

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dstt;
	char	*srct;
	int		i;

	if (dst == src || n == 0)
		return (dst);
	i = -1;
	if (dst == NULL && src == NULL)
		return (NULL);
	dstt = (char *) dst;
	srct = (char *) src;
	if (dstt > srct)
	{
		i = n - 1;
		while (i >= 0)
		{
			dstt[i] = srct[i];
			i--;
		}
	}
	else
	{
		i = -1;
		while (++i < (int) n)
			dstt[i] = srct[i];
	}
	return (dst);
}

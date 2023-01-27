/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:27:39 by nipostni          #+#    #+#             */
/*   Updated: 2022/12/20 16:35:08 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memchr - searches for the first occurrence of a particular character
**             in the first n bytes of the memory area pointed to by s.
**
** @s: pointer to the memory area to search
** @c: character to search for
** @n: number of bytes to search
**
** Returns a pointer to the matching byte, or NULL if the character is not found.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *tmp;

	if (s == NULL || n == 0)
		return (NULL);

	tmp = (unsigned char *)s;
	while (tmp < (unsigned char *)(s + n))
	{
		if (*tmp ^ (unsigned char) c)
			tmp++;
		else
			return ((void *)tmp);
	}
	return (NULL);
}

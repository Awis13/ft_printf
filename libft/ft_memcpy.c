/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:15:54 by Nipostni          #+#    #+#             */
/*   Updated: 2022/12/20 17:22:39 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies the first n bytes of memory from the source buffer to the destination buffer,
   taking into account the possibility of overlapping buffers. If either the destination
   or source buffer is a null pointer, returns a null pointer. If the destination and
   source buffers are the same, returns the destination buffer without copying any bytes. */

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    char *destc = (char *)dest;
    const char *srcc = (const char *)src;

    if (dest == NULL || src == NULL)
    {
        return dest;
    }

    if (dest < src)
    {
        while (n-- > 0)
        {
            *destc++ = *srcc++;
        }
    }
    else if (dest > src)
    {
        destc += n;
        srcc += n;
        while (n-- > 0)
        {
            *--destc = *--srcc;
        }
    }

    return dest;
}

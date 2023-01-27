/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:21:57 by Nipostni          #+#    #+#             */
/*   Updated: 2022/12/20 17:37:37 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memset() sets the first n bytes of the memory block pointed to by s
** to the specified value c.
*/

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *dest_ptr = (unsigned char *)s;

    while (n--)
    {
        *dest_ptr++ = (unsigned char)c;
    }
    return s;
}

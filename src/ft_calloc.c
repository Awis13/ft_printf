/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <nipostni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:25:46 by nipostni          #+#    #+#             */
/*   Updated: 2023/01/27 15:45:57 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdint.h>

/*
** Allocates memory for an array of `count` elements of `size` bytes each
** and returns a pointer to the allocated memory. The memory is initialized
** to zero.
**
** If `count` or `size` is 0, or if `count * size` exceeds the maximum
** value that can be stored in a `size_t` type (`SIZE_MAX`), the function
** returns `NULL`.
**
** Returns a pointer to the allocated and initialized memory, or `NULL` if
** the memory could not be allocated.
*/

void *ft_calloc(size_t count, size_t size)
{
    void *ptr;
 

    if (count == 0 || size == 0 || count > SIZE_MAX / size)
    {
        return NULL;
    }

    ptr = malloc(count * size);
    if (ptr == NULL)
    {
        return NULL;
    }

    if (ft_memset(ptr, 0, count * size) == NULL)
    {
        free(ptr);
        return NULL;
    }

    return ptr;
}


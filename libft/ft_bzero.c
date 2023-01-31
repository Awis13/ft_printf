/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:58:42 by Nipostni          #+#    #+#             */
/*   Updated: 2022/12/06 20:36:39 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_bzero() sets the first length bytes of the memory block pointed to by b
// to zero.

void	ft_bzero(void *b, size_t length)
{
	ft_memset(b, 0, length * sizeof(char));
}

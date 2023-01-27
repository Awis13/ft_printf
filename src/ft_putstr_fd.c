/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:22:59 by Nipostni          #+#    #+#             */
/*   Updated: 2022/12/20 17:55:35 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes the string 's' to the file descriptor 'fd'.
*/

void ft_putstr_fd(char *s, int fd)
{
    if (s)
    {
        while (*s)
        {
            write(fd, s, 1);
            s++;
        }
    }
}

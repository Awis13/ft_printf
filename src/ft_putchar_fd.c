/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipostni <awis@me.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:18:14 by Nipostni          #+#    #+#             */
/*   Updated: 2022/12/20 17:41:00 by nipostni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function writes a character 'c' to the file descriptor 'fd'.
** It uses the 'write' function to write a single byte to the specified file.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

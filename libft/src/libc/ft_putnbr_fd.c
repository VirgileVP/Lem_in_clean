/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:10:52 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:34:32 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void		ft_putnbr_fd(int nb, int fd)
{
	static char		buffer[11];
	int				i;
	unsigned int	uval;

	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	uval = (nb < 0) ? -nb : nb;
	i = 10;
	while (1)
	{
		buffer[i] = uval % 10 + '0';
		uval /= 10;
		if (uval == 0)
			break ;
		i--;
	}
	if (nb < 0)
		buffer[--i] = '-';
	write(fd, buffer + i, 11 - i);
}

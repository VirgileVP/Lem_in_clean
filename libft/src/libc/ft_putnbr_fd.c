/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:10:52 by zseignon          #+#    #+#             */
/*   Updated: 2020/05/01 17:47:08 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

int			ft_putnbr_fd(int nb, int fd)
{
	static char		buffer[11];
	int				i;
	unsigned int	uval;

	if (nb == -2147483648)
	{
		return (write(fd, "-2147483648", 11));
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
	return (write(fd, buffer + i, 11 - i));
}

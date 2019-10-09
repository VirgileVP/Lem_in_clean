/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 18:10:52 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 10:00:29 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

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

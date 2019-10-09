/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:47:45 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 09:46:03 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	long	nb;
	long	sign;

	nb = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\f' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	sign = (str[i] == '-');
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + str[i] - 48;
		i++;
	}
	nb = sign ? -nb : nb;
	if (nb < INT_MIN || nb > INT_MAX)
		return (sign ? 0 : -1);
	return ((int)nb);
}

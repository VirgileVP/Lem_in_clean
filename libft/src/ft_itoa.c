/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 17:36:39 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 17:16:31 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		is_n(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char			*ft_itoa(int n)
{
	int		t;
	int		len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	t = n;
	len = 1;
	negative = 0;
	is_n(&n, &negative);
	while (t /= 10)
		len++;
	len = len + negative;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 07:36:07 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 11:36:39 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	small_set(t_ul dstp, t_byte c, size_t len)
{
	while (len-- > 0)
	{
		((t_byte *)dstp)[0] = c;
		dstp += 1;
	}
}

static void	medium_set(t_ul dstp, t_ul cccc, size_t xlen)
{
	while (xlen-- > 0)
	{
		((t_ul *)dstp)[0] = cccc;
		dstp += 8;
	}
}

static void	big_set(t_ul dstp, t_ul cccc, size_t xlen)
{
	while (xlen-- > 0)
	{
		((t_ul *)dstp)[0] = cccc;
		((t_ul *)dstp)[1] = cccc;
		((t_ul *)dstp)[2] = cccc;
		((t_ul *)dstp)[3] = cccc;
		((t_ul *)dstp)[4] = cccc;
		((t_ul *)dstp)[5] = cccc;
		((t_ul *)dstp)[6] = cccc;
		((t_ul *)dstp)[7] = cccc;
		dstp += 64;
	}
}

void		*ft_memset(void *dst, int c, size_t len)
{
	t_ul		dstp;
	t_ul		cccc;
	size_t		xlen;

	dstp = (t_ul)dst;
	cccc = (t_byte)c * LOMAGIC;
	if (len >= 64)
	{
		xlen = len / 64;
		len %= 64;
		big_set(dstp, cccc, xlen);
		dstp += xlen * 64;
	}
	if (len >= 8)
	{
		xlen = len / 8;
		len %= 8;
		medium_set(dstp, cccc, xlen);
		dstp += xlen * 8;
	}
	if (len > 0)
		small_set(dstp, (t_byte)c, len);
	return (dst);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 08:18:57 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 11:27:19 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_ul		small_chr(t_ul pp, t_byte c, size_t len)
{
	if (len >= 1 && ((t_byte *)pp)[0] == c)
		return (pp);
	if (len >= 2 && ((t_byte *)pp)[1] == c)
		return (pp + 1);
	if (len >= 3 && ((t_byte *)pp)[2] == c)
		return (pp + 2);
	if (len >= 4 && ((t_byte *)pp)[3] == c)
		return (pp + 3);
	if (len >= 5 && ((t_byte *)pp)[4] == c)
		return (pp + 4);
	if (len >= 6 && ((t_byte *)pp)[5] == c)
		return (pp + 5);
	if (len >= 7 && ((t_byte *)pp)[6] == c)
		return (pp + 6);
	if (len >= 8 && ((t_byte *)pp)[7] == c)
		return (pp + 7);
	return (0);
}

static t_ul		medium_chr(t_ul pp, t_ul cccc, size_t xlen)
{
	t_ul		k;

	while (xlen-- > 0)
	{
		k = ((t_ul *)pp)[0] ^ cccc;
		if ((k - LOMAGIC) & ~k & HIMAGIC)
			return (small_chr(pp, (t_byte)cccc, 8));
		pp += 8;
	}
	return (0);
}

void			*ft_memchr(const void *p, int c, size_t len)
{
	t_ul		pp;
	t_ul		cccc;
	t_ul		ret;
	size_t		xlen;

	pp = (t_ul)p;
	cccc = (t_byte)c * LOMAGIC;
	if (len >= 8)
	{
		xlen = len / 8;
		len %= 8;
		if ((ret = medium_chr(pp, cccc, xlen)) != 0)
			return ((void *)ret);
		pp += xlen * 8;
	}
	if (len > 0 && (ret = small_chr(pp, (t_byte)c, len)) != 0)
		return ((void *)ret);
	return (NULL);
}

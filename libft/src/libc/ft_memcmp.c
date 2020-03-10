/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 08:25:23 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:33:39 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

static int		small_cmp(t_ul pp1, t_ul pp2, size_t len)
{
	if (((t_byte *)pp1)[0] != ((t_byte *)pp2)[0] || len == 1)
		return (((t_byte *)pp1)[0] - ((t_byte *)pp2)[0]);
	else if (((t_byte *)pp1)[1] != ((t_byte *)pp2)[1] || len == 2)
		return (((t_byte *)pp1)[1] - ((t_byte *)pp2)[1]);
	else if (((t_byte *)pp1)[2] != ((t_byte *)pp2)[2] || len == 3)
		return (((t_byte *)pp1)[2] - ((t_byte *)pp2)[2]);
	else if (((t_byte *)pp1)[3] != ((t_byte *)pp2)[3] || len == 4)
		return (((t_byte *)pp1)[3] - ((t_byte *)pp2)[3]);
	else if (((t_byte *)pp1)[4] != ((t_byte *)pp2)[4] || len == 5)
		return (((t_byte *)pp1)[4] - ((t_byte *)pp2)[4]);
	else if (((t_byte *)pp1)[5] != ((t_byte *)pp2)[5] || len == 6)
		return (((t_byte *)pp1)[5] - ((t_byte *)pp2)[5]);
	else
		return (((t_byte *)pp1)[6] - ((t_byte *)pp2)[6]);
}

static int		medium_cmp(t_ul pp1, t_ul pp2, size_t len, size_t xlen)
{
	while (xlen-- > 0)
	{
		if (((t_ul *)pp1)[0] != ((t_ul *)pp2)[0])
			return (small_cmp(pp1, pp2, 8));
		pp1 += 8;
		pp2 += 8;
	}
	return (small_cmp(pp1, pp2, len));
}

static int		big_cmp(t_ul pp1, t_ul pp2, size_t len, size_t xlen)
{
	while (xlen-- > 0)
	{
		if (((t_ul *)pp1)[0] != ((t_ul *)pp2)[0])
			return (small_cmp(pp1, pp2, 8));
		if (((t_ul *)pp1)[1] != ((t_ul *)pp2)[1])
			return (small_cmp(pp1 + 8, pp2 + 8, 8));
		if (((t_ul *)pp1)[2] != ((t_ul *)pp2)[2])
			return (small_cmp(pp1 + 16, pp2 + 16, 8));
		if (((t_ul *)pp1)[3] != ((t_ul *)pp2)[3])
			return (small_cmp(pp1 + 24, pp2 + 24, 8));
		if (((t_ul *)pp1)[4] != ((t_ul *)pp2)[4])
			return (small_cmp(pp1 + 32, pp2 + 32, 8));
		if (((t_ul *)pp1)[5] != ((t_ul *)pp2)[5])
			return (small_cmp(pp1 + 40, pp2 + 40, 8));
		if (((t_ul *)pp1)[6] != ((t_ul *)pp2)[6])
			return (small_cmp(pp1 + 48, pp2 + 48, 8));
		if (((t_ul *)pp1)[7] != ((t_ul *)pp2)[7])
			return (small_cmp(pp1 + 56, pp2 + 56, 8));
		pp1 += 64;
		pp2 += 64;
	}
	if (len > 8)
		return (medium_cmp(pp1, pp2, len % 8, len / 8));
	return (small_cmp(pp1, pp2, len));
}

int				ft_memcmp(const void *p1, const void *p2, size_t len)
{
	t_ul		pp1;
	t_ul		pp2;

	pp1 = (t_ul)p1;
	pp2 = (t_ul)p2;
	if (len >= 64)
		return (big_cmp(pp1, pp2, len % 64, len / 64));
	else if (len >= 8)
		return (medium_cmp(pp1, pp2, len % 8, len / 8));
	return (small_cmp(pp1, pp2, len));
}

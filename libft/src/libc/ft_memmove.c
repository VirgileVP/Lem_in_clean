/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 07:48:00 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:33:50 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

static void	small_move(t_ul dstp, t_ul srcp, size_t len)
{
	while (len-- > 0)
	{
		((t_byte *)dstp)[0] = ((t_byte *)srcp)[0];
		dstp -= 1;
		srcp -= 1;
	}
}

static void	medium_move(t_ul dstp, t_ul srcp, size_t xlen)
{
	while (xlen-- > 0)
	{
		((t_ul *)dstp)[0] = ((t_ul *)srcp)[0];
		dstp -= 8;
		srcp -= 8;
	}
}

static void	big_move(t_ul dstp, t_ul srcp, size_t xlen)
{
	while (xlen-- > 0)
	{
		((t_ul *)dstp)[7] = ((t_ul *)srcp)[0];
		((t_ul *)dstp)[6] = ((t_ul *)srcp)[1];
		((t_ul *)dstp)[5] = ((t_ul *)srcp)[2];
		((t_ul *)dstp)[4] = ((t_ul *)srcp)[3];
		((t_ul *)dstp)[3] = ((t_ul *)srcp)[4];
		((t_ul *)dstp)[2] = ((t_ul *)srcp)[5];
		((t_ul *)dstp)[1] = ((t_ul *)srcp)[6];
		((t_ul *)dstp)[0] = ((t_ul *)srcp)[7];
		srcp -= 64;
		dstp -= 64;
	}
}

static void	rev_move(t_ul dstp, t_ul srcp, size_t len, t_ul gap)
{
	size_t		xlen;

	if (len >= 64 && gap > 64)
	{
		xlen = len / 64;
		len %= 64;
		big_move(dstp, srcp, xlen);
		dstp -= xlen * 64;
		srcp -= xlen * 64;
	}
	if (len >= 8 && gap > 8)
	{
		xlen = len / 64;
		len %= 64;
		medium_move(dstp, srcp, xlen);
		dstp -= xlen * 8;
		srcp -= xlen * 8;
	}
	if (len > 0)
		small_move(dstp, srcp, len);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	t_ul	r_dstp;
	t_ul	r_srcp;

	r_dstp = (t_ul)dst + len - 1;
	r_srcp = (t_ul)src + len - 1;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
		rev_move(r_dstp, r_srcp, len, (t_ul)(dst - src));
	return (dst);
}

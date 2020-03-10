/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 07:42:50 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:33:44 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

static void	small_cpy(t_ul dstp, t_ul srcp, size_t len)
{
	while (len-- > 0)
	{
		((t_byte *)dstp)[0] = ((t_byte *)srcp)[0];
		dstp += 1;
		srcp += 1;
	}
}

static void	medium_cpy(t_ul dstp, t_ul srcp, size_t xlen)
{
	while (xlen-- > 0)
	{
		((t_ul *)dstp)[0] = ((t_ul *)srcp)[0];
		dstp += 8;
		srcp += 8;
	}
}

static void	big_cpy(t_ul dstp, t_ul srcp, size_t xlen)
{
	while (xlen-- > 0)
	{
		((t_ul *)dstp)[0] = ((t_ul *)srcp)[0];
		((t_ul *)dstp)[1] = ((t_ul *)srcp)[1];
		((t_ul *)dstp)[2] = ((t_ul *)srcp)[2];
		((t_ul *)dstp)[3] = ((t_ul *)srcp)[3];
		((t_ul *)dstp)[4] = ((t_ul *)srcp)[4];
		((t_ul *)dstp)[5] = ((t_ul *)srcp)[5];
		((t_ul *)dstp)[6] = ((t_ul *)srcp)[6];
		((t_ul *)dstp)[7] = ((t_ul *)srcp)[7];
		srcp += 64;
		dstp += 64;
	}
}

void		*ft_memcpy(void *dst, const void *src, size_t len)
{
	t_ul		dstp;
	t_ul		srcp;
	size_t		xlen;

	dstp = (t_ul)dst;
	srcp = (t_ul)src;
	if (len >= 64)
	{
		xlen = len / 64;
		len %= 64;
		big_cpy(dstp, srcp, xlen);
		dstp += xlen * 64;
		srcp += xlen * 64;
	}
	if (len >= 8)
	{
		xlen = len / 8;
		len %= 8;
		medium_cpy(dstp, srcp, xlen);
		dstp += xlen * 8;
		srcp += xlen * 8;
	}
	if (len > 0)
		small_cpy(dstp, srcp, len);
	return (dst);
}

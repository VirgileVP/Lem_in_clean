/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:48:26 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:33:28 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	t_ul	p;
	size_t	size;

	p = (t_ul)ft_memchr(src, c, len);
	if (p == 0)
	{
		ft_memcpy(dst, src, len);
		return (NULL);
	}
	else
	{
		size = p - (t_ul)src + 1;
		ft_memcpy(dst, src, size);
		return ((void *)((t_ul)dst + (t_ul)size));
	}
}

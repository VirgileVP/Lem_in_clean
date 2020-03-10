/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 09:12:29 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:24:41 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "typedef.h"
#include "libc.h"

void				*ft_memdup(const void *src, size_t len)
{
	void		*dst;

	if (!(dst = ft_malloc(sizeof(t_byte) * len)))
		return (NULL);
	ft_memcpy(dst, src, len);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 09:09:40 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:24:17 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "typedef.h"
#include "libc.h"

void	*ft_memalloc(size_t len)
{
	void	*p;

	if (!(p = ft_malloc(sizeof(t_byte) * len)))
		return (NULL);
	ft_bzero(p, len);
	return (p);
}

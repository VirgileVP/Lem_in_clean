/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:01:33 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/05 15:01:35 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "ft_cmp.h"
#include "libc.h"

int			ft_icmp(const void *p1, const void *p2)
{
	return (*((int *)p1) - *((int *)p2));
}

int			ft_ccmp(const void *p1, const void *p2)
{
	return (*((char *)p1) - *((char *)p2));
}

int			ft_scmp(const void *p1, const void *p2)
{
	return (ft_strcmp((char *)p1, (char *)p2));
}

int			ft_zcmp(const void *p1, const void *p2)
{
	return (*((t_size *)p1) - *((t_size *)p2));
}

int			ft_pcmp(const void *p1, const void *p2)
{
	return (*((void **)p1) - *((void **)p2));
}

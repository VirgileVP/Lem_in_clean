/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 13:52:26 by zdebugs           #+#    #+#             */
/*   Updated: 2020/03/16 14:14:34 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "way.h"
#include "libft.h"

void		way_init(t_vect *restrict self)
{
	vect_init(self, sizeof(t_uint), 256);
}

void		way_del(t_vect *restrict self)
{
	ft_memdel((void **)&self->mem);
	self->xitem = 0;
}

void		way_clean(t_vect *restrict self)
{
	vect_clean(self);
}
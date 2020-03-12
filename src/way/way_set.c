/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:02:52 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 09:34:51 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "way.h"

void		way_set_init(t_way_set *restrict self, t_uint max_way)
{
	self->ways = (t_way *)ft_malloc(sizeof(t_way) * max_way);
	self->moves = 0;
}

void		way_set_del(t_way_set *restrict self)
{
	ft_free(self->ways);
}

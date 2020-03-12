/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roadset_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:08:37 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 09:46:23 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "way.h"

t_roadset			*roadset_convert(t_way_set *restrict set)
{
	t_roadset		*rs;
	t_size			n;
	t_size			x;

	n = 0;
	rs = (t_roadset *)ft_malloc(sizeof(t_roadset) * (set->xway + 1));
	while (n < set->xway)
	{
		x = 0;
		rs->t = (t_rdata *)ft_malloc(set->ways[n].len);
		while (x < set->ways[n].len)
		{
			rs[n].t[x].n = set->ways[n].node_index[x];
			rs[n].t[x].ant_index = 0;
			x++;
		}
		rs[n].nb_ant = set->ways[n].ants;
		rs[n].len = set->ways[n].len;
		n++;
	}
	rs[n].t = NULL;
	way_set_del(set);
	return (rs);
}

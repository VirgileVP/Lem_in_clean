/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_ant_dispatch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 08:22:44 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/16 14:28:05 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "way.h"

void		way_ant_dispatch(t_way_set *restrict set, t_uint lemin)
{
	t_size	i;
	t_size	j;

	i = 0;
	while (lemin > 0)
	{
		if (i + 1 < set->xway && set->ways[i + 1].len - 1 < set->moves + 1)
			i += 1;
		set->ways[i].ants += 1;
		lemin -= 1;
		set->moves = set->ways[i].ants + set->ways[i].len - 2;
		j = 0;
		while (j < i)
		{
			while (lemin > 0 &&
					set->ways[j].ants + set->ways[j].len - 2 < set->moves)
			{
				set->ways[j].ants += 1;
				lemin -= 1;
			}
			j += 1;
		}
	}
}

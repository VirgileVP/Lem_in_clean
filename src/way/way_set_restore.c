/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_set_restore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:45:44 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 13:11:05 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "way.h"

static void	way_swap(t_way *w1, t_way *w2)
{
	t_way		*tmp;
	
	tmp = w1;
	w1 = w2;
	w2 = tmp;
}

static void	way_qsort(t_way *restrict t, t_uint bot, t_uint top)
{
	t_uint		i;
	t_uint		j;

	i = bot;
	j = bot;
	while (j < top)
	{
		if (t[j].len < t[top].len)
		{
			way_swap(&t[i], &t[j]);
			i++;
		}
		j++;		
	}
	way_swap(&t[i], &t[top]);
	if (bot < top)
	{
		way_qsort(t, bot, i - 1);
		way_qsort(t, i, top);
	}
}

static void	way_add(t_way_set *restrict set, t_vect *restrict way, t_uint way_index)
{
	t_size		n;

	n = 0;
	while (n < way->xitem)
	{
		set->ways[way_index].node_index[n] = *(t_uint *)vect(way, n);
		n++;
	}
}

static void	way_find(t_graph *restrict graph, t_vect *restrict way, t_node *node)
{
	t_iter				iter;
	t_connect *restrict	tmp;

	vect_add(way, node);
	iter_init(&iter, node, ITER_FORBIDDEN);
	while (*(t_uint *)vect_top(way) != graph->end)
	{
		tmp = iter_next(&iter);
		vect_add(way, &tmp->dst);
		iter_init(&iter, graph_node(graph, tmp->dst), ITER_FORBIDDEN);
	}
}

void		way_set_restore(t_way_set *restrict set, t_graph *restrict graph,
t_uint xway, t_uint lemin)
{
	t_iter				iter;
	t_vect				way;
	t_size				way_index;
	t_connect 			*connect;
	
	way_index = 0;
	vect_init(&way, sizeof(t_uint), 256);
	way_set_init(set, xway);
	iter_init(&iter, graph_node(graph, graph->start), ITER_FORBIDDEN);
	while ((connect = iter_next(&iter)))
	{
		way_find(graph, &way, graph_node(graph, connect->dst));
		way_add(set, &way, way_index);
		vect_clean(&way);
		way_index++;
	}
	set->xway = way_index;
	ft_free(way.mem);
	way_qsort(set->ways, 0, set->xway - 1);
	way_ant_dispatch(set, lemin);
}

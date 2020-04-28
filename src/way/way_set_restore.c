/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_set_restore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:45:44 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/26 14:48:25 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "way.h"
#include "ft_qsort.h"

static void	way_add(t_way *dst, t_vect *restrict way)
{
	t_size		n;

	n = 0;
	dst->node_index = ft_malloc(sizeof(t_uint) * way->xitem);
	while (n < way->xitem)
	{
		dst->node_index[n] = *(t_uint *)vect(way, n);
		n++;
	}
	dst->ants = 0;
	dst->len = way->xitem;
}

static void	way_find(t_graph *restrict graph, t_vect *restrict way, t_uint node)
{
	t_iter				iter;
	t_connect *restrict	tmp;

	vect_add(way, &graph->start);
	vect_add(way, &node);
	iter_init(&iter, graph_node(graph, node), ITER_FORBIDDEN);
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
	t_connect			*connect;

	way_index = 0;
	way_init(&way);
	way_set_init(set, xway);
	iter_init(&iter, graph_node(graph, graph->start), ITER_FORBIDDEN);
	while ((connect = iter_next(&iter)))
	{
		way_find(graph, &way, connect->dst);
		way_add(&set->ways[way_index], &way);
		way_clean(&way);
		way_index++;
	}
	set->xway = way_index;
	way_del(&way);
	ft_qsort(set->ways, 0, set->xway - 1);
	way_ant_dispatch(set, lemin);
}

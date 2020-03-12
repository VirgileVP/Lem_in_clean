/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_reverse_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:51:47 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 13:08:35 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "way.h"

static void		parent_new(t_node *restrict node, t_graph *restrict graph)
{
	t_connect	*connect;
	int			best_weight;
	t_uint		ret;
	int			tmp_weight;
	t_iter		iter;

	best_weight = INT_MAX;
	ret = node->parent;
	iter_init(&iter, node, ITER_POSITIVE);
	while ((connect = iter_next(&iter)))
	{
		if ((tmp_weight = graph_node(graph, connect->dst)->weight) < best_weight)
		{
			best_weight = tmp_weight;
			ret = connect->dst;
		}
	}
	node->parent = ret;
}

static void		connect_reverse(t_connect_data connect)
{
	if (connect.src_dst->state == CONNECT_FORBIDDEN ||
		connect.src_dst->state == CONNECT_NEGATIVE)
	{
		connect.src_dst->state = CONNECT_POSITIVE;
		connect.dst_src->state = CONNECT_POSITIVE;
		connect.dst->separate = 0;
	}
	else
	{
		connect.src_dst->state = CONNECT_NEGATIVE;
		connect.dst_src->state = CONNECT_FORBIDDEN;
		connect.src->separate = 1;
		connect.dst->separate = 1;
	}
}

void			way_reverse_new(t_graph *restrict graph)
{
	t_uint			pos;
	t_connect_data	connect;
	t_iter			iter;

	pos = graph->end;
	connect.src = graph_node(graph, pos);
	while (pos != graph->start)
	{
		connect.dst = graph_node(graph, connect.src->parent);
		connect.src_dst = graph_connect(&connect.src->connect, connect.src->parent);
		connect.dst_src = graph_connect(&connect.dst->connect, pos);
		if (connect.dst->separate && connect.dst->sep_type == MARKED_OUT &&
			connect.src_dst->state == CONNECT_POSITIVE)
		{
			iter_init(&iter, connect.dst, ITER_FORBIDDEN);
			connect.dst->parent = iter_next(&iter)->dst;
		}
		if (connect.dst->in_new_way)
			parent_new(connect.dst, graph);
		connect.dst->in_new_way = 1;
		connect_reverse(connect);
		pos = connect.src->parent;
		connect.src = connect.dst;
	}
	connect.src->separate = 0;
}

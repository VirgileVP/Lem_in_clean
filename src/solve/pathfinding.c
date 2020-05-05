/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:58:45 by zseignon          #+#    #+#             */
/*   Updated: 2020/05/05 11:22:57 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

static t_roadset	*roadset_convert(t_way_set *restrict set)
{
	t_roadset		*rs;
	t_size			n;
	t_size			x;

	n = 0;
	rs = (t_roadset *)ft_malloc(sizeof(t_roadset) * (set->xway + 1));
	while (n < set->xway)
	{
		x = 0;
		rs[n].t = (t_rdata *)ft_malloc(sizeof(t_rdata) * set->ways[n].len);
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
	return (rs);
}

static void			best_change(t_uint *min_moves, t_way_set *tmp,
	t_way_set *prev)
{
	*min_moves < UINT_MAX ? way_set_del(prev) : 0;
	*min_moves = tmp->moves;
	*prev = *tmp;
}

static int			pathfinding(t_graph *restrict graph)
{
	t_queue			queue;
	t_node			*end_node;
	t_node_data		tmp;

	tmp.self = graph->start;
	tmp.self = 0;
	tmp.ptr = graph_node(graph, graph->start);
	queue_init(&queue);
	queue_add_head(&queue, &tmp);
	node_mark(tmp.ptr, 0, 0, 0);
	end_node = graph_node(graph, graph->end);
	while (end_node->marked == 0 && queue.xitem > 0)
		node_bypass(graph, &queue);
	queue_del(&queue);
	if (end_node->marked == 1)
		way_reverse_new(graph);
	return (end_node->marked);
}

t_roadset			*solve(t_graph *graph, t_uint lemin)
{
	t_uint			min_moves;
	t_uint			max_way;
	t_uint			xway;
	t_way_set		tmp;
	t_way_set		prev;

	min_moves = UINT_MAX;
	max_way = graph_node(graph, graph->end)->connect.xitem;
	xway = 0;
	while (pathfinding(graph) == 1)
	{
		xway++;
		way_set_restore(&tmp, graph, xway, lemin);
		if (tmp.moves < min_moves)
			best_change(&min_moves, &tmp, &prev);
		else
			way_set_del(&tmp);
		if (tmp.moves > min_moves || xway == max_way)
			break ;
		graph_reset_state(graph);
	}
	return (prev.xway > 0 ? roadset_convert(&prev) : NULL);
}

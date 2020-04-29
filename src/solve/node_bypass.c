/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_bypass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:07:08 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/30 11:53:39 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "queue.h"

static void			queue_insert(t_queue *restrict queue, t_node_data data)
{
	t_qnode		*cur;

	if (queue->xitem == 0 ||
		queue->head->item.weight >= data.weight)
		queue_add_head(queue, &data);
	else if (queue->tail->item.weight <= data.weight)
		queue_add_tail(queue, &data);
	else
	{
		cur = queue->head->next;
		while (cur->item.weight < data.weight)
			cur = cur->next;
		queue_add_after(queue, cur, &data);
	}
	data.ptr->in_queue = 1;
}

static t_node_data	data_set(t_node_data src, t_connect_data connect)
{
	t_node_data		ret;

	ret.ptr = connect.dst;
	ret.self = connect.src_dst->dst;
	ret.weight = src.weight + connect.src_dst->state;
	return (ret);
}

static void			weight_change(t_queue *restrict queue, t_uint item,
									int weight)
{
	t_node_data	tmp;
	t_qnode		*cur;
	t_qnode		*next;

	cur = queue->head;
	next = cur->next;
	tmp = cur->item;
	if (tmp.self == item)
	{
		tmp.weight = weight;
		return ;
	}
	while ((tmp = next->item).self != item)
	{
		cur = next;
		next = cur->next;
	}
	tmp = queue_pop_after(queue, cur);
	tmp.weight = weight;
	queue_insert(queue, tmp);
}

static void			node_check(t_queue *restrict queue, t_node_data src,
							t_connect_data connect)
{
	t_node_data		tmp;

	tmp = data_set(src, connect);
	if (connect.dst->marked == 0)
	{
		queue_insert(queue, tmp);
		node_mark(connect.dst, connect.src_dst->state, tmp.weight, src.self);
	}
	else if (connect.dst->separate == 1 &&
			connect.dst->sep_type == MARKED_IN &&
			connect.src_dst->state == CONNECT_NEGATIVE)
	{
		if (connect.dst->weight <= tmp.weight)
			connect.dst->sep_type = MARKED_OUT;
		else
			node_mark(connect.dst, connect.src_dst->state, tmp.weight, src.self);
		if (connect.dst->in_queue == 0)
			queue_insert(queue, tmp);
		else
			weight_change(queue, connect.src_dst->dst, tmp.weight);
	}
	else if (connect.dst->weight > tmp.weight)
	{
		node_mark(connect.dst, connect.src_dst->state, tmp.weight, src.self);
		if (connect.dst->in_queue == 0)
			queue_insert(queue, tmp);
		else
			weight_change(queue, connect.src_dst->dst, tmp.weight);
	}
}

void				node_bypass(t_graph *restrict graph,
	t_queue *restrict queue)
{
	t_iter			iter;
	t_node_data		src;
	t_connect_data	connect;

	src = queue_pop_head(queue);
	connect.src = src.ptr;
	connect.src->in_queue = 0;
	iter_init(&iter, connect.src, ITER_BY_NODE);
	while ((connect.src_dst = iter_next(&iter)) != NULL)
	{
		connect.dst = graph_node(graph, connect.src_dst->dst);
		node_check(queue, src, connect);
	}
}

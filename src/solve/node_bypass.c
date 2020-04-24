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

__attribute__ ((unused))static void			queue_print(t_queue *restrict self)
{
	t_qnode			*tmp;
	t_size			n;

	tmp = self->head;
	n = 0;
	printf("queue[%ld] = |", self->xitem);
	while (n < self->xitem)
	{
		printf("%d|", tmp->item.self);
		tmp = tmp->next;
		n++;
	}
	printf("\n");
	fflush(stdout);
}
/*
static void			check_queue(t_queue *queue)
{
	t_qnode			*p1;
	t_qnode			*p2;
	t_size			x = 0, y = 0;;

	p1 = queue->head;
	while (x < queue->xitem)
	{
		p2 = p1->next;
		y = x + 1;
		while (y < queue->xitem)
		{
			if (p2 == p1)
			{
				printf("cycling\n");
				exit(1);
			}
			p2 = p2->next;
			y += 1;
		}
		x += 1;
	}
}*/

static void			check_queue(t_queue *queue)
{
	t_qnode			*slow_p = queue->head, *fast_p = queue->head;

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
		{
			printf("cycling\n");
			exit(1);
		}
	}
}

static void			queue_insert(t_queue *restrict queue, t_node_data data)
{
	t_qnode		*cur;

//	printf("\t\t\t\t\tqueue_insert __start\n");
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
//	printf("\t\t\t\t\tqueue_insert __end\n");
}

static t_node_data	data_set(t_node_data src, t_connect_data connect)
{
	t_node_data		ret;

//	printf("\t\t\t\t\tdata_set __start\n");
	ret.ptr = connect.dst;
	ret.self = connect.src_dst->dst;
	ret.weight = src.weight + connect.src_dst->state;
//	printf("\t\t\t\t\tdata_set __end\n");
	return (ret);
}

static void			weight_change(t_queue *restrict queue, t_uint item,
									int weight)
{
	t_node_data	tmp;
	t_qnode		*cur;
	t_qnode		*next;

	int			i = 0;


//	printf("\t\t\t\t\tweight_change __start\n");
	cur = queue->head;
	next = cur->next;
	tmp = cur->item;
	if (tmp.self == item)
	{
		tmp.weight = weight;
		return ;
	}
	check_queue(queue);
//	printf("\t\t\t\t\t\tfind_place __start\n");
	while ((tmp = next->item).self != item)
	{
//		printf("\t\t\t\t\t\t%d|%d|%ld|%d\n", item, tmp.self, queue->xitem, i);
		cur = next;
		next = cur->next;
		i++;
	}
//	printf("\t\t\t\t\t\tfind_place __end\n");
//	printf("\t\t\t\t\t\tqueue_pop_after __start\n");
	tmp = queue_pop_after(queue, cur);
//	printf("\t\t\t\t\t\tqueue_pop_after __end\n");
	tmp.weight = weight;
	queue_insert(queue, tmp);
//	printf("\t\t\t\t\tweight_change __end\n");
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
	else if (connect.dst->separate  == 1 &&
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

void				node_bypass(t_graph *restrict graph, t_queue *restrict queue)
{
	t_iter			iter;
	t_node_data		src;
	t_connect_data	connect;

//	printf("\t\t\tnodebypass __start\n");
//	printf("\t\t\t\tqueue_pophead __start\n");
	src = queue_pop_head(queue);
//	printf("\t\t\t\tqueue_pophead __end\n");
	connect.src = src.ptr;
	connect.src->in_queue = 0;
//	printf("\t\t\t\titer_init __start\n");
	iter_init(&iter, connect.src, ITER_BY_NODE);
//	printf("\t\t\t\titer_init __end\n");
//	printf("\t\t\t\titer_next-loop __start\n");
	while ((connect.src_dst = iter_next(&iter)) != NULL)
	{
		connect.dst = graph_node(graph, connect.src_dst->dst);
//		printf("\t\t\t\tnode_check __start\n");
		node_check(queue, src, connect);
//		printf("\t\t\t\tnode_check __end\n");
	}
//	printf("\t\t\t\titer_next-loop __end\n");
//	printf("\t\t\tnodebypass __end\n");
}
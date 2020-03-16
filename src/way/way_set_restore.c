/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_set_restore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:45:44 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/16 15:01:19 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "way.h"

static void	way_swap(
	t_way *w1,
	t_way *w2
	)
{
	t_way		*tmp;
	
	tmp = w1;
	w1 = w2;
	w2 = tmp;
}

static void	way_qsort(
	t_way *restrict t,
	t_uint bot,
	t_uint top
	)
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

static void	way_add(
	t_way *dst,
	t_vect *restrict way
	)
{
	t_size		n;
	static t_uint	way_index = 0;

	n = 0;
	dst->node_index = ft_malloc(sizeof(t_uint) * way->xitem);
	printf("WAY[%d]=|", way_index);
	while (n < way->xitem)
	{
		dst->node_index[n] = *(t_uint *)vect(way, n);
		printf("%d|", dst->node_index[n]);
		n++;
	}
	dst->ants = 0;
	dst->len = way->xitem;
	printf("\nlen = %ld\n", dst->len);
}

static void	way_find(
	t_graph *restrict graph,
	t_vect *restrict way,
	t_uint node
	)
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

void		way_set_restore(
	t_way_set *restrict set,
	t_graph *restrict graph,
	t_uint xway,
	t_uint lemin
	)
{
	t_iter				iter;
	t_vect				way;
	t_size				way_index;
	t_connect 			*connect;
	
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
	way_qsort(set->ways, 0, set->xway - 1);
	way_ant_dispatch(set, lemin);
}

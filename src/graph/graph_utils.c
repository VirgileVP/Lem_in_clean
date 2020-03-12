/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:59:35 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 12:37:08 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void		graph_reset_state(t_graph *restrict graph)
{
	t_size		n;
	t_node		*node;

	n = 0;
	while (n < graph->size)
	{
		node = graph_node(graph, n);
		node->in_new_way = 0;
		node->in_queue = 0;
		node->marked = 0;
		node->weight = 0;
		node->parent = 0;
	}
	graph_node(graph, graph->start)->separate = 0;
	graph_node(graph, graph->end)->separate = 0;
}
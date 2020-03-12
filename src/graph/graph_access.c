/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:13:10 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 09:37:35 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_node			*graph_node(t_graph *restrict graph, t_uint index)
{
	return (graph->nodes[index]);
}

t_connect 		*graph_connect(t_vect *restrict self, t_uint dst)
{
	t_connect	*connect;
	t_size		n;

	n = 0;
	while ((connect = (t_connect *)vect(self, n))->dst != dst)
		n++;
	return (connect);
}

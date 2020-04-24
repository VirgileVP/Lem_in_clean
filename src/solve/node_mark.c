/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_mark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:17:00 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 13:01:15 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void		node_mark(t_node *restrict node, t_int state,
						t_int weight, t_uint parent)
{
//	printf("\t\t\t\t\tnode_mark __start\n");
	node->weight = weight;
	node->marked = 1;
	node->parent = parent;
	if (node->separate)
	{
		if (state == CONNECT_NEGATIVE)
			node->sep_type = MARKED_OUT;
		else
			node->sep_type = MARKED_IN;
	}
//	printf("\t\t\t\t\tnode_mark __end\n");
}
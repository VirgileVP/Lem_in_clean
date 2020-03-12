/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:40:33 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 11:35:37 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void			iter_init(t_iter *restrict iter, t_node *restrict node,
		t_uint type)
{
	iter->n = 0;
	iter->connect = &node->connect;
	if (type == ITER_BY_NODE)
		iter->fct = (node->separate && node->sep_type == MARKED_IN) ?
			ITER_NEGATIVE : ITER_ALLOWED;
	else
		iter->fct = type;
}

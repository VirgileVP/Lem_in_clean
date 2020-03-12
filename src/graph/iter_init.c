/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:40:33 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 09:44:12 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_iter			*iter_init(t_iter *restrict iter, t_node *restrict node,
		t_uint type)
{
	iter->count_connects = node->count_connects;
	iter->i = 0;
	iter->connects = node->connect;
	if (type == ITER_BY_NODE)
		iter->fct = (node->separate && node->sep_type == MARKED_IN) ?
			ITER_NEGATIVE : ITER_ALLOWED;
	else
		iter->func = type;
	return (iter);
}

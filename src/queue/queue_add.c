/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 09:21:01 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/26 11:54:04 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "graph.h"

static t_qnode		*qnode_new(t_node_data *item)
{
	t_qnode			*new;
	
	new = ft_malloc(sizeof(t_qnode));
	new->mem = ft_malloc(sizeof(t_node_data));
	new->next = NULL;
	ft_memcpy(new->mem, item, sizeof(t_node_data));
	return (new);
}

void				queue_add_head(t_queue *restrict self, t_node_data *item)
{
	t_qnode			*new;

	new = qnode_new(item);
	if (self->xitem == 0)
	{
		self->head = new;
		self->tail = new;
	}
	else
	{
		new->next = self->head;
		self->head = new;
	}
	(self->xitem)++;
}

void				queue_add_tail(t_queue *restrict self, t_node_data *item)
{
	t_qnode			*new;

	new = qnode_new(item);
	self->tail->next = new;
	self->tail = new;
	(self->xitem)++;
}

void				queue_add_after(t_queue *restrict self, t_qnode *cur,
	t_node_data *item)
{
	t_qnode			*new;

	new = qnode_new(item);
	new->next = cur->next;
	cur->next = new;
	(self->xitem)++;
}
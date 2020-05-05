/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 09:37:55 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/26 11:54:59 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "graph.h"

t_node_data				queue_pop_head(t_queue *restrict self)
{
	t_node_data			item;
	t_qnode				*tmp;

	item = self->head->item;
	tmp = self->head;
	if (self->xitem > 1)
		self->head = self->head->next;
	else
	{
		self->head = NULL;
		self->tail = NULL;
	}
	(self->xitem)--;
	ft_free(tmp);
	return (item);
}

t_node_data				queue_pop_after(t_queue *restrict self, t_qnode *cur)
{
	t_qnode		*next;
	t_node_data	item;

	next = cur->next;
	(self->xitem)--;
	if (next == self->tail)
		self->tail = cur;
	cur->next = next->next;
	item = next->item;
	ft_free(next);
	return (item);
}

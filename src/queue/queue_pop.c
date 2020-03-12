/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 09:37:55 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/11 12:14:44 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

static void			queue_cache_add(t_queue *restrict self, void *item)
{
	if (self->xcache > 0)
	{
		self->cache_tail->next = item;
		self->cache_tail = item;
	}
	else
	{
		self->cache_head = item;
		self->cache_tail = item;
	}
}

void				*queue_pop_head(t_queue *restrict self)
{
	t_item_lst		*item;

	item = self->head;
	(self->xitem)--;
	if (self->xitem > 0)
		self->head = item->next;
	queue_cache_add(self, item);
	return (item->mem);
}

void				*queue_pop_after(t_queue *restrict self, t_item_lst *cur)
{
	t_item_lst		*item;

	item = cur->next;
	(self->xitem)--;
	if (item == self->tail)
		self->tail = cur;
	queue_cache_add(self, item);
	return (item->mem);
}
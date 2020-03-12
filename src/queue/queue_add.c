/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 09:21:01 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/11 11:30:19 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

static t_item_lst	*queue_cache_pop(t_queue *restrict self)
{
	t_item_lst	*ret;

	ret = self->cache_head;
	(self->xcache)--;
	if (self->xcache > 0)
		self->cache_head = self->cache_head->next;
	return (ret);
}

static t_item_lst	*queue_lst_new(t_queue *restrict self)
{
	t_item_lst	*new;

	new = ft_malloc(sizeof(t_item_lst));
	new->mem = ft_malloc(self->item_size);
	return (new);
}

void				queue_add_head(t_queue *restrict self, void *item)
{
	t_item_lst	*new;

	new = (self->xcache > 0 ? queue_cache_pop(self) : queue_lst_new(self));
	ft_memcpy(new->mem, item, self->item_size);
	new->next = self->head;
	self->head = new;
	(self->xitem)++;
}

void				queue_add_tail(t_queue *restrict self, void *item)
{
	t_item_lst	*new;

	new = (self->xcache > 0 ? queue_cache_pop(self) : queue_lst_new(self));
	ft_memcpy(new->mem, item, self->item_size);
	self->tail->next = new;
	self->tail = new;
	(self->xitem)++;
}

void			queue_add_after(t_queue *restrict self, t_item_lst *cur, void *item)
{
	t_item_lst		*new;

	new = (self->xcache > 0 ? queue_cache_pop(self) : queue_lst_new(self));
	ft_memcpy(new->mem, item, self->item_size);
	new->next = cur->next;
	cur->next = new;
	(self->xitem)++;
}
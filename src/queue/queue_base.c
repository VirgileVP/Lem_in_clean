/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:24:33 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/11 09:19:26 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "queue.h"

void		queue_init(t_queue *restrict self, t_size item_size)
{
	ft_bzero(self, sizeof(t_queue));
	self->item_size = item_size;
}

void		queue_clean(t_queue *restrict self)
{
	while (self->xitem > 0)
		queue_pop_head(self);
}

void		queue_del(t_queue *restrict self)
{
	t_item_lst	*tmp;
	t_item_lst	*next;

	tmp = self->head;
	while (self->xitem > 0)
	{
		next = tmp->next;
		ft_free(tmp->mem);
		ft_free(tmp);
		tmp = next;
		(self->xitem)--;
	}
	tmp = self->cache_head;
	while (self->xcache > 0)
	{
		next = tmp->next;
		ft_free(tmp->mem);
		ft_free(tmp);
		tmp = next;
		(self->xcache)--;
	}
}
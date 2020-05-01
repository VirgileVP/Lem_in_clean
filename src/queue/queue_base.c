/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:24:33 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/26 09:38:16 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "queue.h"

void		queue_init(t_queue *restrict self)
{
	self->head = NULL;
	self->tail = NULL;
	self->xitem = 0;
}

void		queue_clean(t_queue *restrict self)
{
	while (self->xitem > 0)
		queue_pop_head(self);
	ft_bzero(self, sizeof(t_queue));
}

void		queue_del(t_queue *restrict self)
{
	while (self->xitem > 0)
		queue_pop_head(self);
}

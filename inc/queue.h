/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 07:25:03 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/11 13:28:39 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "graph.h"

typedef struct				s_item_lst
{
	void *restrict			mem;
	struct s_item_lst		*next;
}							t_item_lst;

typedef struct				s_queue
{
	t_item_lst *restrict	head;
	t_item_lst *restrict	tail;
	t_item_lst *restrict	cache_head;
	t_item_lst *restrict	cache_tail;
	t_size					xitem;
	t_size					xcache;
	t_size					item_size;
}							t_queue;

/*
**	queue_base.c
*/

void						queue_init(t_queue *restrict self, t_size item_size);
void						queue_clean(t_queue *restrict self);
void						queue_del(t_queue *restrict self);

/*
**	queue_add.c
*/

void						queue_add_head(t_queue *restrict self, void *item);
void						queue_add_tail(t_queue *restrict self, void *item);
void						queue_add_after(t_queue *restrict self, t_item_lst *cur, void *item);

/*
**	queue_pop.c
*/

void						*queue_pop_head(t_queue *restrict self);
void						*queue_pop_after(t_queue *restrict self, t_item_lst *cur);

#endif
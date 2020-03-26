/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 07:25:03 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/26 10:11:42 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "typedef.h"
# include "libft.h"

typedef struct s_node_data	t_node_data;

typedef struct				s_qnode
{
	void *restrict			mem;
	struct s_qnode			*next;
}							t_qnode;

typedef struct				s_queue
{
	t_qnode *restrict		head;
	t_qnode *restrict		tail;
	t_size					xitem;
}							t_queue;

void						queue_init(t_queue *restrict self);
void						queue_clean(t_queue *restrict self);
void						queue_del(t_queue *restrict self);

void						queue_add_head(t_queue *restrict self, t_node_data *item);
void						queue_add_tail(t_queue *restrict self, t_node_data *item);
void						queue_add_after(t_queue *restrict self, t_qnode *cur,
	t_node_data *item);

t_node_data					*queue_pop_head(t_queue *restrict self);
t_node_data					*queue_pop_after(t_queue *restrict self, t_qnode *cur);

#endif
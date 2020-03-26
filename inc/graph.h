/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:07:29 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/26 09:54:47 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "libft.h"
# include "typedef.h"
# include "queue.h"

/*
**	NODE
*/

# define MARKED_OUT			0
# define MARKED_IN			1

typedef struct			s_node
{
	t_vect				connect;
	t_uint				parent;
	int					weight;
	t_uint				marked		: 1;
	t_uint				in_queue	: 1;
	t_uint				separate	: 1;
	t_uint				sep_type	: 1;
	t_uint				in_new_way	: 1;
}						t_node;

typedef struct			s_node_data
{
	t_node				*ptr;
	t_uint				self;
	int					weight;
}						t_node_data;

/*
**	CONNECT
*/

# define CONNECT_POSITIVE	1
# define CONNECT_NEGATIVE	-1
# define CONNECT_FORBIDDEN	0

typedef struct			s_connect
{
	t_uint				dst;
	int					state	: 2;
}						t_connect;

typedef struct			s_connect_data
{
	t_node *restrict	src;
	t_node *restrict	dst;
	t_connect *restrict	src_dst;
	t_connect *restrict dst_src;
}						t_connect_data;

/*
**	GRAPH
*/

typedef struct			s_graph
{
	t_node **restrict	nodes;
	t_size				size;
	t_uint				start;
	t_uint				end;
	
}						t_graph;

t_node					*graph_node(t_graph *restrict graph, t_uint index);
t_connect				*graph_connect(t_vect *restrict self, t_uint dst);
void					graph_reset_state(t_graph *restrict graph);
void					graph_del(t_graph *graph);

void					node_bypass(t_graph *restrict graph, t_queue *restrict queue);
void					node_mark(t_node *restrict node, int state, int weight, t_uint parent);

t_connect_data			*graph_connect_data(t_graph *restrict graph, t_uint src, t_uint dst, t_connect *data);
void					graph_connect_reverse(t_connect_data *connect);

/*
**	ITER
*/

# define ITER_ALL			0
# define ITER_ALLOWED		1
# define ITER_NEGATIVE		2
# define ITER_FORBIDDEN		3
# define ITER_POSITIVE		4
# define ITER_BY_NODE		5


typedef struct			s_iter
{
	t_vect *restrict	connect;
	t_size				n;
	t_uint				fct;
}						t_iter;

void					iter_init(t_iter *restrict iter, t_node *restrict node,
		t_uint type);
t_connect				*iter_next(t_iter *iter);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 08:44:27 by zseignon          #+#    #+#             */
/*   Updated: 2020/05/01 17:31:50 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAY_H
# define WAY_H

# include "graph.h"
# include "typedef.h"

typedef struct			s_way
{
	t_uint *restrict	node_index;
	t_size				len;
	t_uint				ants;
}						t_way;

typedef struct			s_way_set
{
	t_way *restrict		ways;
	t_size				xway;
	t_uint				moves;
}						t_way_set;

void					way_init(t_vect *restrict self);
void					way_del(t_vect *restrict self);
void					way_clean(t_vect *restrict self);

void					way_set_init(t_way_set *restrict self, t_uint max_way);
void					way_set_del(t_way_set *restrict self);

void					way_reverse_new(t_graph *restrict graph);
void					way_ant_dispatch(t_way_set *restrict set,
		t_uint lemin);
void					way_set_restore(t_way_set *restrict set,
		t_graph *restrict graph, t_uint xway, t_uint lemin);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:51:45 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/16 13:47:13 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "graph.h"
# include "misc.h"

typedef __uint32_t		t_uint;
typedef __int32_t		t_int;

typedef struct			s_read_room
{
	char				**room;
	int					decla_nb_ant;
	int					nb_room;
	int					nb_line;
}						t_read_room;

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
}						t_room;

typedef struct			s_anthill
{
	struct s_vect		farm;
	struct s_room		*room_data;
	int					nb_ant;
	int					nb_room;
	int					start;
	int					end;
}						t_anthill;

typedef struct			s_rdata
{
	int					n;
	int					ant_index;
}						t_rdata;

typedef struct			s_roadset
{
	t_rdata				*t;
	size_t				len;
	int					nb_ant;
}						t_roadset;

int						parse_map(t_anthill *ah, char **entry);
int						read_error(t_read_room *pars);
int						empty_road(t_roadset *roads, int road_index);
t_roadset				*solve(t_graph *restrict graph, t_uint lemin);

#endif

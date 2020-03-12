/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:51:45 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 10:21:20 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "pathfinding.h"
# include "graph.h"

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

typedef struct			s_connect
{
	int					dst;
	t_uint				state : 1;
}						t_connect;

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
void					print_path(int ant, char *room);
int						how_much_road(t_roadset *roads);
int						empty_road(t_roadset *roads, int road_index);
int						which_resolution(t_anthill *anthill, t_roadset *roads);
int						multi_path(t_anthill *anthill, t_roadset *roads);
int						all_ant_one_path(t_anthill *anthill, t_roadset *roads);
void					oneshot(t_anthill *anthill);

#endif

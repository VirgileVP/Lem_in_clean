/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lemin.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 13:51:45 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 14:36:17 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "stdio.h"
#include "libft.h"

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	size_t				nb_ant;
}						t_room;

typedef struct			s_read_room
{
	char				**room;
	int					decla_nb_ant;
	int					nb_room;
	int					nb_line;
}						t_read_room;

typedef struct			s_anthill
{
	struct s_room		*room_data;
	t_ul				**matrix;
	size_t				xlen;
	size_t				nb_room;
	size_t				nb_ant;
	int					start;	
	int					end;
}						t_anthill;

typedef struct			s_rdata
{
	int					n;			//room index
	int					ant_index;	//ant index
}						t_rdata;

typedef struct			s_roadset
{
	t_rdata				*t;
	size_t				len;		//size of the road
	int					nb_ant;		//number of ant to send
}						t_roadset;

int						parse_map(t_anthill *ah, char **entry);
int						read_error(t_read_room *pars);
int						pathfinding(t_anthill *ah, t_roadset **rs);
void					print_path(int ant, char *room);
int						how_much_road(t_roadset *roads);
int						empty_road(t_roadset *roads, int road_index);
int						which_resolution(t_anthill *anthill, t_roadset *roads);
int						multi_path(t_anthill *anthill, t_roadset *roads);
int						all_ant_one_path(t_anthill *anthill, t_roadset *roads);
void					oneshot(t_anthill *anthill);



#endif

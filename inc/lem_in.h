/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 13:51:45 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 12:46:47 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

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
	int					nb_room;
}						t_read_room;

typedef struct			s_anthill
{
	struct s_room		*room_data;
	t_ul				**matrix;
	size_t				nb_room;
	size_t				total_ant;
	int					start;	
	int					end;
}						t_anthill;

typedef struct			s_roadset
{
	int					**roadmap;
	size_t				nb_road;
}						t_roadset;

int						parse(char **entry, t_anthill *ah, t_room *rdata);
int						read_error(t_read_room *pars);

#endif

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pathfinding.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 14:30:42 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 12:43:05 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PATHFINDING_H
# define PATHFINDING_H

#include "lem_in.h"

enum					flag
{
	PROCEED,
	STOP
};

typedef struct			s_rlink
{
	int					room;
	struct s_rlink		*next;
	struct s_rlink		*prev;
}						t_rlink;

typedef struct			s_rlist
{
	struct rlink		*begin;
	struct rlink		*p;
	size_t				len;
}						t_rlist;

typedef struct			s_ant
{
	char				*used;
	struct s_rlist		*roadmap;
	int					pos;
	struct s_ant		*next;
	struct s_ant		*prev;
}						t_ant;

typedef struct			s_colony
{
	struct s_ant		*begin;
	struct s_ant		*p;
	size_t				len;
}						t_colony;

t_colony				ant_spawn;

#endif

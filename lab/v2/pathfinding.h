/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pathfinding.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 10:25:42 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 12:45:52 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PATHFINDING_H
# define PATHFINDING_H

# include "lem_in.h"

# define BZERO				0x8000000000000000UL

typedef struct				s_rlink
{
	int						n;
	struct s_rlink			*next;
}							t_rlink;

typedef struct				s_bindex
{
	size_t					xn;
	t_ul					cccc;
	size_t					x;
}							t_bindex;

typedef struct				s_ant
{
	struct s_rlink			*root;
	struct s_rlink			*p;
	size_t					rlen;
	unsigned long			*used;
	struct s_ant			*next;
}							t_ant;

typedef struct				s_colony
{
	struct s_ant			*p;
	size_t					len;
}							t_colony;

typedef struct				s_rtab
{
	int						*t;
	size_t					len;
	struct s_rtab			*next;
}							t_rtab;

typedef struct				s_rclass;
{
	struct s_rtab			*rtab;
	struct s_rtab			*t;
	unsigned long			*barr;
	struct s_rclass			*next;
	struct s_rclass			*c;
}							t_rclass;

typedef struct				s_pfinding
{
	struct s_colony			*wander;
	struct s_colony			*end;
	struct s_rclass			*root;
	struct s_rclass			*best;
	unsigned long			**xmatrix;
	size_t					xlen;
	size_t					len;
}							t_pfinding;

#endif

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pathfinding.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 10:25:42 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 11:44:58 by zseignon    ###    #+. /#+    ###.fr     */
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
	struct s_ant			*prev;
	struct s_ant			*next;
}							t_ant;

typedef struct				s_colony
{
	struct s_ant			*p;
	size_t					len;
}							t_colony;

typedef struct				s_rmap
{
	t_rlink					*p;
	size_t					len;
	struct s_rmap			*next;
}							t_rmap;

typedef struct				s_rclass;
{
	struct s_rmap			*rmap;
	struct s_rmap			*m;
	size_t					rlen;
	unsigned long			*barr;
	struct s_rclass			*next;
}							t_rclass;

typedef struct				s_pfinding
{
	struct s_colony			*wander;
	struct s_colony			*end;
	struct s_rclass			*root;
	struct s_rclass			*c;
	struct s_rclass			*best;
	unsigned long			**matrix;
	size_t					len;
}							t_pfinding;

t_rclass					*rclass_chr(t_pfinding *pf, t_ant *ant);
t_rclass					*rclass_new(t_pfinding *pf);
int							rclass_add_ant(t_rclass *r, t_ant *ant, t_pfinding *pf);

#endif


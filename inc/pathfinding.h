/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pathfinding.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 10:25:42 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 08:26:17 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PATHFINDING_H
# define PATHFINDING_H

# include "lem_in.h"

# define BZERO				0x8000000000000000UL

typedef struct				s_bindex
{
	size_t					xn;
	size_t					x;
	t_ul					cccc;
}							t_bindex;

typedef struct				s_rlink
{
	int						n;
	struct s_rlink			*next;
}							t_rlink;

typedef struct				s_ant
{
	struct s_rlink			*root;
	struct s_rlink			*p;
	size_t					len;
	unsigned long			*used;
	struct s_ant			*prev;
	struct s_ant			*next;
}							t_ant;

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
	size_t					value;
	char					flag;
	unsigned long			*barr;
	struct s_rclass			*next;
}							t_rclass;

typedef struct				s_pfinding
{
	struct s_ant			*ant;
	size_t					xant;
	struct s_rclass			*root;
	struct s_rclass			*c;
	struct s_rclass			*best;
	unsigned long			**matrix;
	size_t					xm;
	size_t					lemin;
	int						start;
	int						end;
}							t_pfinding;

enum 						e_pstat
{
	PROCEED = 0,
	RCLASS_SORT = 1,
	EVAL = 2,
	ANT_KILL = 3,
	STOP = -1,
	MALLOC_ERROR = -2,
	NO_PATH = -3,
};

int							pathfinding(t_anthill *ah, t_roadset **rs);
void						pfinding_free(t_pfinding **pf);
t_rclass					*rclass_new(t_pfinding *pf);
enum e_pstat				ant_scout(t_ant *ant, int pos, t_pfinding *pf);
int							roadset_set(t_roadaset **rs, t_rclass *rc);
enum e_pstat				rclass_add(t_pfinding *pf);
enum e_pstat				ant_kill(t_pfinding *pf);
enum e_pstat				pf_eval(t_pfinding *pf);

#endif

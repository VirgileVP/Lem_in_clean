/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pathfinding.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/18 10:00:05 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 13:11:07 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PATHFINDING_H
# define PATHFINDING_H

# include "lemin.h"

# define BINIT				0x8000000000000000UL

# define MALLOC_ERROR		-1
# define NO_PATH			-2
# define STOP				0
# define CONTINUE			1

typedef struct				s_bindex
{
	t_ul					cccc;
	size_t					xn;
	size_t					x;
}							t_bindex;

typedef struct				s_rlink
{
	int						n;
	struct s_rlink			*next;
}							t_rlink;

typedef struct				s_ant
{
	struct s_rlink			*root;
	struct s_rlink			*r;
	size_t					len;
	t_ul					*barr;
	struct s_ant			*prev;
	struct s_ant			*next;
}							t_ant;

typedef struct				s_rclass
{
	int						*best;
	size_t					blen;
	int						*brep;
	int						bvalue;
	int						*tmp;
	int						*trep;
	size_t					tlen;
	int						tvalue;
	t_ul					*barr;
}							t_rclass;

typedef struct				s_pf
{
	struct s_ant			*ant;
	size_t					xant;
	struct s_ant			*end;
	struct s_ant			*tend;
	size_t					xend;
	int						start_index;
	int						end_index;
	t_ul					**matrix;
	size_t					xlen;
	size_t					lemin;
}							t_pf;

void						ant_kill(t_pf *pf);
void						end_kill(t_pf *pf);
int							ant_dup(t_pf *pf);
int							ant_scout(t_pf *pf);
int							ant_convert(t_pf *pf);

int							barr_cmp(t_ul *t1, t_ul *t2, size_t len);
void						barr_add(t_ul *dst, t_ul *src, size_t len);
void						barr_remove(t_ul *dst, t_ul *src, size_t len);

int							bf_main(t_pf *pf, t_roadset **rs);
int							eval(t_pf *pf, t_rclass *rc);

#endif

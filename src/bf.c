/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bf.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 11:11:50 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 12:51:56 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

static int		rclass_convert(t_rclass *rc, t_roadset **rs, t_pf *pf)
{
	size_t			y;
	size_t			x;
	t_rlink			*tmp;

	if (!(*rs = (t_roadset *)malloc(sizeof(t_roadset) * rc->blen)))
		return (MALLOC_ERROR);
	y = 0;
	while (y < rc->blen)
	{
		(*rs)[y].len = pf->end[rc->best[y]].len;
			if (!((*rs)[y].t = (t_rdata *)malloc(sizeof(int) * (*rs)[y].len)))
				return (MALLOC_ERROR);
		x = 0;
		tmp = pf->end[rc->best[y]].root;
		while (x < (*rs)[y].len)
		{
			(*rs)[y].t[x].n = tmp->n;
			x += 1;
			tmp = tmp->next;
		}
		//(*rs)[y].ant = rc->rep[y];
		y += 1;
	}
	return (1);
}

static void		rclass_free(t_rclass **rc)
{
	free((*rc)->best);
	free((*rc)->brep);
	free((*rc)->tmp);
	free((*rc)->trep);
	free((*rc)->barr);
	free(*rc);
	*rc = NULL;
}

static int		bf(t_pf *pf, t_rclass *rclass, int i)
{
	int				n;
	char			check;

	n = i;
	check = 1;
	while (n < pf->xend)
	{
		if (barr_cmp(pf->end[n].barr, pf->end[n].barr, pf->xlen) == 1)
		{
			check = 0;
			rclass->tmp[i] = n;
			barr_add(pf->end[n].barr, pf->end[n].barr, pf->xlen);
			bf(pf, rclass, i + 1);
			barr_remove(pf->end[n].barr, rclass->barr, pf->xlen);
		}
		n += 1;
	}
	if (check == 1)
	{
		rclass->tlen = i;
		if (eval(pf, rclass) == MALLOC_ERROR)
			return (MALLOC_ERROR);
	}
	return (1);
}

int				bf_main(t_pf *pf, t_roadset **rs)
{
	t_rclass		*rc;

	if (!(rc = (t_rclass *)ft_memalloc(sizeof(t_rclass))) ||
			!(rc->tmp = (int *)malloc(sizeof(int) * pf->xend)) ||
			!(rc->trep = (int *)malloc(sizeof(int) * pf->xend)) ||
			!(rc->barr = (t_ul *)ft_memalloc(sizeof(t_ul) * pf->xlen)) ||
			bf(pf, rc, 0) == MALLOC_ERROR ||
			rclass_convert(rc, rs, pf) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	rclass_free(&rc);
	return (1);
}

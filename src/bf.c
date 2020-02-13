/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bf.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 11:11:50 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 10:23:01 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

/*						PRINT FCT						*/

static void		print_roadset(t_roadset *rs)
{
	size_t			y;
	size_t			x;

	y = 0;
	printf("PRINTING ROADSET\n");
	while (rs[y].t != NULL)
	{
		x = 0;
		printf("rs[%zu].len = %zu\n", y, rs[y].len);
		printf("rs[%zu].t = |", y);
		while (x < rs[y].len)
		{
			printf("%d|", rs[y].t[x].n);
			x += 1;
		}
		printf("\n");
		printf("rs[%zu].ant = %d\n", y, rs[y].nb_ant);
		y += 1;
	}
}

/*------------------------------------------------------*/

static int		rclass_convert(t_rclass *rc, t_roadset **rs, t_pf *pf)
{
	size_t			y;
	size_t			x;
	t_rlink			*tmp;

	if (!(*rs = (t_roadset *)malloc(sizeof(t_roadset) * rc->blen + 1)))
		return (MALLOC_ERROR);
	y = 0;
	while (y < rc->blen)
	{
		(*rs)[y].len = pf->tend[rc->best[y]].len;
		if (!((*rs)[y].t = (t_rdata *)malloc(sizeof(t_rdata) * (*rs)[y].len)))
				return (MALLOC_ERROR);
		x = 0;
		tmp = pf->tend[rc->best[y]].root;
		while (x < (*rs)[y].len)
		{
			(*rs)[y].t[x].n = tmp->n;
			(*rs)[y].t[x].ant_index = 0;
			x += 1;
			tmp = tmp->next;
		}
		(*rs)[y].nb_ant = rc->brep[y];
		y += 1;
	}
	(*rs)[y].t = NULL;
	print_roadset(*rs);
	return (1);
}

static void		rclass_free(t_rclass *rc)
{
	free(rc->best);
	free(rc->brep);
	free(rc->tmp);
	free(rc->trep);
	free(rc->barr);
}

static int		rclass_init(t_rclass *rc, t_pf *pf)
{
	if (!(rc->tmp = (int *)ft_memalloc(sizeof(int) * pf->xend)) ||
			!(rc->trep = (int *)malloc(sizeof(int) * pf->xend)) ||
			!(rc->barr = (t_ul *)ft_memalloc(sizeof(t_ul) * pf->xlen)))
		return (MALLOC_ERROR);
	rc->bvalue = INT_MAX;
	rc->tvalue = 0;
	rc->best = NULL;
	rc->blen = 0;
	rc->brep = NULL;
	rc->tlen = 0;
	return (1);
}

static int		bf(t_pf *pf, t_rclass *rclass, int i)
{
	int				n;
	char			check;

	n = i;
	check = 1;
	while (n < pf->xend)
	{
		if (barr_cmp(pf->tend[n].barr, rclass->barr, pf->xlen) == 1)
		{
			check = 0;
			rclass->tmp[i] = n;
			barr_add(pf->tend[n].barr, rclass->barr, pf->xlen);
			bf(pf, rclass, i + 1);
			barr_remove(pf->tend[n].barr, rclass->barr, pf->xlen);
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
	t_rclass		rc;

	if (rclass_init(&rc, pf) == MALLOC_ERROR ||
			bf(pf, &rc, 0) == MALLOC_ERROR ||
			rclass_convert(&rc, rs, pf) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	rclass_free(&rc);
	return (1);
}

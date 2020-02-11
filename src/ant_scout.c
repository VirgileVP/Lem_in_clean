/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_scout.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 11:06:30 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 12:33:21 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

static void		ant_end(t_pf *pf)
{
	t_ant			*tmp;

	tmp = pf->ant;
	tmp->next->prev = tmp->prev->next;
	tmp->prev->next = tmp->next->prev;
	if (pf->xant > 1)
		pf->ant = pf->ant->next;
	else
		pf->ant = NULL;
	pf->xant -= 1;
	if (pf->xend == 0)
	{
		pf->end = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->next = pf->end;
		tmp->prev = pf->end->prev;
		pf->end->prev->next = tmp;
		pf->end->prev = tmp;
		pf->end = tmp;
	}
	pf->xend += 1;
}

static int		ant_move(t_pf *pf, t_bindex *i)
{
	if (!(pf->ant->r->next = (t_rlink *)malloc(sizeof(t_rlink))))
		return (MALLOC_ERROR);
	pf->ant->r = pf->ant->r->next;
	pf->ant->r->n = i->x;
	pf->ant->len += 1;
	pf->ant->barr[i->xn] |= i->cccc;
	return (1);
}

static int		barr_chr(t_bindex *i, t_ul *t, t_ul *u, size_t len)
{
	while (i->xn < len)
	{
		if (t[i->xn] != 0)
		{
			if (i->cccc == 0)
			{
				i->x = i->xn * 64;
				i->cccc = BINIT;
			}
			while (i->cccc != 0)
			{
				if (!(i->cccc & u[i->xn]) && (i->cccc & t[i->xn]))
					return (1);
				i->cccc >>= 1;
				i->x += 1;
			}
		}
		i->xn += 1;
	}
	return (0);
}

static int		ant_multi(t_pf *pf, t_bindex *i, t_bindex *n)
{
	if (ant_dup(pf) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	ant_move(pf, i);
	ft_memcpy(&i, &n, sizeof(t_bindex));
	n->x += 1;
	n->cccc >>= 1;
	while (barr_chr(n, pf->matrix[pf->ant->r->n], pf->ant->barr, pf->xlen) == 1)
	{
		if (ant_dup(pf) == MALLOC_ERROR)
			return (MALLOC_ERROR);
		ant_move(pf, i);
		if (i->x == pf->end_index)
			ant_end(pf);
		else
			pf->ant = pf->ant->next;
		i = n;
		ft_memcpy(&i, &n, sizeof(t_bindex));
		n->x += 1;
		n->cccc >>= 1;
	}
	ant_move(pf, i);
	if (i->x == pf->end_index)
		ant_end(pf);
	else
		pf->ant = pf->ant->next;
}

int				ant_scout(t_pf *pf)
{
	t_bindex		i;
	t_bindex		n;

	while (pf->xant > 0)
	{
		ft_memset(&i, 0, sizeof(t_bindex));
		barr_chr(&i, pf->matrix[pf->ant->r->n], pf->ant->barr, pf->xlen);
		ft_memcpy(&n, &i, sizeof(t_bindex));
		n.cccc >>= 1;
		n.x += 1;
		if (barr_chr(&n, pf->matrix[pf->ant->r->n], pf->ant->barr, pf->xlen) == 1)
		{
			if (ant_multi(pf, &i, &n) == MALLOC_ERROR)
				return (MALLOC_ERROR);
		}
		else
		{
			if (ant_move(pf, &i) == MALLOC_ERROR)
				return (MALLOC_ERROR);
		}
		if (i.x == pf->end_index)
			ant_end(pf);
		else
			pf->ant = pf->ant->next;
	}
	if (pf->xend == 0)
		return (NO_PATH);
	return (1);
}

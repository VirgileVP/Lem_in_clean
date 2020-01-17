/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_scout.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 09:00:55 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 08:18:30 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

static int		sbchr(t_bindex *i, t_ul t, t_ul u)
{
	while (i->cccc != 0)
	{
		if ((i->cccc & t) && !(i->cccc & u))
			return (1);
		i->cccc >>= 1;
		i->x += 1;
	}
	return (0);
}

static int		bchr(t_bindex *i, t_ul *t, t_ul *used, size_t len)
{
	while (i->xn < len)
	{
		if (t[i->xn] & used[i->xn])
		{
			if (sbchr(i, t[i->xn], u[i->xn]) == 1)
				return (1);
			else
			{
				i->cccc = BZERO;
				i->x = i->xn * 64;
			}
		}
		i->xn += 1;
		i->x += 64;
	}
	i->xn = 0;
	i->x = 0;
	return (0);
}

static int		ant_dup(t_pfinding *pf)
{
	t_ant			*a;
	t_rlink			*tmp;

	if ((a = (t_ant *)ft_memalloc(sizeof(t_ant))) == NULL ||
			(a->used = (t_ul *)ft_memdup(pf->ant->used, sizeof(t_ul) * pf->xm)) == NULL)
		return (-1);
	tmp = pf->ant->root;
	while (a->rlen < pf->ant->len)
	{
		rlink_add(a, tmp->n);
		tmp = tmp->next;
	}
	pf->ant->next->prev = a;
	a->next = c->p->next;
	a->prev = c->p;
	pf->ant->next = a;
	return (1);
}

static int		ant_move(t_ant *ant, t_bindex *i)
{
	if ((ant->p->next = (t_rlink *)malloc(sizeof(t_rlink))) == NULL)
		return (-1);
	ant->p = ant->p->next;
	ant->p->n = i->x;
	ant->p->next = NULL;
	ant->used[i->xn] |= i->cccc;
	ant->len += 1;
}

enum e_pstat	ant_scout(t_ant *ant, int pos, t_pfinding *pf)
{
	static t_bindex	*i = NULL;
	t_bindex		n;

	if (i == NULL && (i = (t_bindex *)ft_memalloc(sizeof(t_bindex))))
		return (MALLOC_ERROR);
	if (bchr(i, pf->matrix[pos], ant->used, pf->xm) == 1)
	{
		n = *i;
		n.cccc >>= 1;
		n.x += 1;
		if (bchr(&n, pf->matrix[pos], ant->used, pf->xm) == 1 &&
				ant_dup(pf) < 0)
			return (MALLOC_ERROR);
		if (ant_move(ant, i) < 0)
			return (MALLOC_ERROR);
		*i = n;
		i->cccc >>= 1;
		i->x += 1;
		if (ant->p->n == pf->end)
			return (RCLASS_SORT);
	}
	else
		return (ANT_KILL);
	pf->ant = pf->ant->next;
	return (PROCEED);
}

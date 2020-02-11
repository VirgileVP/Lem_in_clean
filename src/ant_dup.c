/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_dup.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 13:23:46 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 14:23:22 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

static int		rmap_cpy(t_pf *pf, t_ant *a)
{
	t_rlink			*r;

	r = pf->ant->root;
	while (a->len < pf->ant->len)
	{
		if (!(a->r->next = (t_rlink *)malloc(sizeof(t_rlink))))
			return (MALLOC_ERROR);
		a->r = a->r->next;
		a->r->next = NULL;
		a->r->n = r->n;
		a->len += 1;
		r = r->next;
	}
	return (1);
}

int				ant_dup(t_pf *pf)
{
	t_ant			*a;

	if (!(a = (t_ant *)malloc(sizeof(t_ant))) ||
			!(a->barr = ft_memdup(pf->ant->barr, sizeof(t_ul) * pf->xlen)) ||
			!(a->root = (t_rlink *)malloc(sizeof(t_rlink))))
		return (MALLOC_ERROR);
	a->root->next = NULL;
	a->root->n = pf->start_index;
	a->r = a->root;
	a->r = pf->ant->root->next;
	if (rmap_cpy(pf, a) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	a->prev = pf->ant->prev;
	a->next = pf->ant;
	pf->ant->prev = a;
	pf->ant = a;
	return (1);
}

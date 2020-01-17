/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rclass_add.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 11:34:37 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 08:20:26 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

static t_rclass	*rclass_chr(t_pfinding *pf, t_ant *ant)
{
	t_rclass		*tmp;
	size_t			n;
	char			check;

	tmp = pf->root;
	check = 1;
	while (tmp != NULL)
	{
		n = 0;
		while (n < pf->xlen)
		{
			if ((tmp->barr[n] & ant->used[n]) != 0)
			{
				check = 0;
				break ;
			}
			n += 1;
		}
		if (check)
			return (tmp);
		else
			tmp = tmp->next;
	}
	return (NULL);
}

static int		rclass_add_ant(t_rclass *r, t_ant *ant, t_pfinding *pf)
{
	t_rmap			*map;
	size_t			n;

	if ((map = (t_rmap *)malloc(sizeof(t_rmap))) == NULL)
		return (-1);
	map->p = ant->root;
	map->len = ant->rlen;
	map->next = NULL;
	if (r->rmap == NULL)
	{
		r->rmap = map;
		r->m = map;
	}
	else
	{
		r->m->next = map;
		r->m = r->m->next;
	}
	n = 0;
	while (n < pf->xlen)
	{
		r->barr[n] |= ant->used[n];
		n += 1;
	}
	return (1);
}

enum e_pstat	rclass_add(t_pfinding *pf)
{
	t_rclass		*t;

	if (((t = rclass_chr(pf, pf->ant)) == NULL &&
				(pf->c->next = rclass_new(pf) == NULL)) ||
			rclass_add_ant(t, pf->ant, pf) == -1)
		return (MALLOC_ERROR);
	t->flag = -1;
	return (EVAL);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pfinding_free.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 07:58:46 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 08:03:25 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

static void		rclass_free(t_rclass **r);
{
	t_rmap				*tmp;
	t_rlink				*p;

	while ((*r)->rmap != NULL)
	{
		tmp = (*r)->rmap->next;
		while ((*r)->rmap->p != NULL)
		{
			p = (*r)->rmap->p->next;
			free((*r)->rmap->p);
			(*r)->rmap->p = p;
		}
		free((*r)->rmap);
		(*r)->rmap = tmp;
	}
	free((*r)->barr);
	free(*r);
	*r = NULL;
}

void			pfinding_free(t_pfinding **pf)
{
	t_rclass			*tmp;

	while ((*pf)->xant > 0)
		ant_kill(*pf);
	while ((*pf)->root != NULL)
	{
		tmp = (*pf)->root->next;
		rclass_free(&(*pf)->root);
		(*pf)->root = tmp;
	}
	free(*pf);
	*pf = NULL;
}

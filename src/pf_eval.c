/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_eval.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 10:07:33 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 11:29:13 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

void				r_value(t_rclass *r, t_pfinding *pf)
{
	while ()
	{
		prev = t->len - 2;
		next = t->next->len - 2;
		if (next < value)
		{
		}
	}
}

static enum e_pstat	rclass_cmp(t_rclass **best, t_rclass *t, t_pfinding *pf)
{
	t->value = r_value(t, pf);
	if (t->value < (*best)->value)
		*best = t;
	if (t->m->len > pf->lemin)
		return (STOP);
	else
		return (PROCEED);
}

enum e_pstat		pf_eval(t_pfinding *pf)
{
	t_rclass		*t;

	t = pf->root;
	if (pf->best == NULL)
		pf->best = t;
	while (t != NULL)
	{
		if (t->flag == -1)
		{
			t->flag = 1;
			if (t->m->len < pf->lemin)
				return (rclass_cmp(pf->best, t, pf));
			else
				return (STOP);
		}
		t = t->next;
	}
}

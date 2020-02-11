/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 12:17:11 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 15:02:09 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

static void		eval_fill(int ant, t_rclass *rc, t_pf *pf)
{
	int		i;
	int		j;

	i = 0;
	while (ant > 0 && rc->tvalue < rc->bvalue)
	{
		if (i + 1 < rc->tlen && pf->end[i + 1].len - 1 < rc->tvalue)
			i += 1;
		rc->trep[i] += 1;
		ant -= 1;
		rc->tvalue = rc->trep[i] + pf->end[i].len - 2;
		j = 0;
		while (j < i)
		{
			while (rc->trep[j] + pf->end[j].len - 2 < rc->tvalue)
			{
				rc->trep[j] += 1;
				ant -= 1;
			}
			j += 1;
		}
	}
}

int				eval(t_pf *pf, t_rclass *rc)
{
	ft_memset(rc->trep, 0, sizeof(int) * rc->tlen);
	rc->tvalue = 0;
	eval_fill(pf->lemin, rc, pf);
	if (rc->tvalue < rc->bvalue)
	{
		free(rc->best);
		free(rc->brep);
		rc->best = ft_memdup(rc->tmp, sizeof(int) * rc->tlen);
		rc->brep = ft_memdup(rc->trep, sizeof(int) * rc->tlen);
		rc->blen = rc->tlen;
		rc->bvalue = rc->tlen;
	}
	return (1);
}

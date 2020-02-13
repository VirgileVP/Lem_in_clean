/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 12:17:11 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 14:23:40 by zseignon    ###    #+. /#+    ###.fr     */
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
		if (i + 1 < rc->tlen && pf->tend[i + 1].len - 1 < rc->tvalue + 1)
			i += 1;
		rc->trep[i] += 1;
		ant -= 1;
		rc->tvalue = rc->trep[i] + pf->tend[i].len - 2;	
		j = 0;
//		printf("rc->trep[%d] = %d\n", i, rc->trep[i]);
		while (j < i)
		{
//			printf("rc->trep[%d] = %d\n", j, rc->trep[j]);
			while (ant > 0 && rc->trep[j] + pf->tend[j].len - 2 < rc->tvalue)
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
	ft_memset(rc->trep, 0, sizeof(int) * pf->xend);
	eval_fill(pf->lemin, rc, pf);
	if (rc->tvalue < rc->bvalue)
	{
		free(rc->best);
		free(rc->brep);
		if (!(rc->best))
			free(rc->best);
		if (!(rc->brep))
			free(rc->brep);
		if (!(rc->best = ft_memdup(rc->tmp, sizeof(int) * rc->tlen)) ||
				!(rc->brep = ft_memdup(rc->trep, sizeof(int) * rc->tlen)))
			return (MALLOC_ERROR);
		rc->blen = rc->tlen;
		rc->bvalue = rc->tvalue;
		rc->tlen = 0;
		rc->tvalue = 0;
	}
	return (1);
}

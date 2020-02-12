/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_convert.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 11:50:12 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 11:51:58 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

int				ant_convert(t_pf *pf)
{
	t_ant			*tmp1;
	t_ant			*tmp2;
	size_t			y;

	if (!(pf->tend = (t_ant *)malloc(sizeof(t_ant) * pf->xend)))
		return (MALLOC_ERROR);
	y = 0;
	tmp1 = pf->end;
	while (y < pf->xend)
	{
		tmp2 = tmp1->next;
		ft_memcpy(&pf->tend[y], tmp1, sizeof(t_ant));
		free(tmp1);
		tmp1 = tmp2;
		y += 1;
	}
	pf->end = NULL;
	return (1);
}

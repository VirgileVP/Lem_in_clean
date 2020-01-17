/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_loop.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 09:57:22 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 08:28:35 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

enum e_ant		ant_loop(t_pfinding *pf)
{
	int				ret;

	while (pf->xant > 0)
	{
		if ((ret = ant_scout() == END_REACHED)
			return (END_REACHED);
		pf->ant = pf->ant->next;
	}
	return (EMTPY_COLONY);
}

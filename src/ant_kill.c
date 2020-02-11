/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_kill.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 11:08:47 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 11:10:14 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

static	void	rmap_del(t_ant *ant)
{
	/*
	MISSING FCTN
	*/
}

void			ant_kill(t_pf *pf)
{
	t_ant			*a;

	rmap_del(pf->ant);
	free(pf->ant->barr);
	pf->ant->prev->next = pf->ant->next;
	pf->ant->next->prev = pf->ant->prev;
	a = pf->ant;
	pf->ant = pf->ant->next;
	free(a);
}

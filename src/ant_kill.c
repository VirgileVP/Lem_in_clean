/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_kill.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 10:22:08 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 08:21:34 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

enum e_pstat	ant_kill(t_pfinding *pf)
{
	t_ant			*a;

	a = pf->ant;
	a->prev->next = a->next;
	a->next->prev = a->prev;
	pf->ant = pf->ant->next;
	free(a->used);
	free(a);
	pf->xant -= 1;
	return (PROCEED);
}

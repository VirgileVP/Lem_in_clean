/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_kill.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 11:08:47 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 14:24:28 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

void			ant_kill(t_pf *pf)
{
	t_ant			*a;
	t_rlink			*tmp1;
	t_rlink			*tmp2;

	tmp1 = a->root;
	while (a->len > 0)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
		a->len -= 1;
	}
	free(pf->ant->barr);
	pf->ant->prev->next = pf->ant->next;
	pf->ant->next->prev = pf->ant->prev;
	a = pf->ant;
	pf->ant = pf->ant->next;
	free(a);
}

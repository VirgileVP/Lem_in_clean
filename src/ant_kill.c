/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_kill.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 11:08:47 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 11:21:53 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

void			end_kill(t_pf *pf)
{
	t_ant			*a;
	t_rlink			*tmp1;
	t_rlink			*tmp2;

	a = pf->end;
	tmp1 = a->root;
	while (a->len > 0)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
		a->len -= 1;
	}
	free(pf->end->barr);
	pf->end->prev->next = pf->end->next;
	pf->end->next->prev = pf->end->prev;
	pf->end = pf->end->next;
	free(a);
	pf->xend -= 1;
}

void			ant_kill(t_pf *pf)
{
	t_ant			*a;
	t_rlink			*tmp1;
	t_rlink			*tmp2;

	a = pf->ant;
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
	pf->ant = pf->ant->next;
	pf->xant -= 1;
	free(a);
}

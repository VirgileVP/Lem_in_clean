/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_move.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 09:50:10 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 09:54:12 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

int				ant_move(t_ant *ant, t_bindex *i)
{
	if ((ant->p->next = (t_rlink *)malloc(sizeof(t_rlink))) == NULL)
		return (-1);
	ant->p = ant->p->next;
	ant->p->n = i->x;
	ant->p->next = NULL;
	ant->used[i->xn] |= i->cccc;
	ant->len += 1;
}

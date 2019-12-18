/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_kill.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:19:00 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 09:12:18 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "colony.h"

int				ant_kill(t_colony *c)
{
	t_ant			*tmp;

	if (c->len > 1)
	{
		tmp = c->ant->next;
		c->ant->prev->next = c->ant->next;
		c->ant->next->prev = c->ant->prev;
	}
	else
		tmp = NULL;
	free(c->ant->used);
	roadmap_free(&c->ant->begin, c->ant->rlen);
	free(c->ant);
	c->ant = tmp;
	c->len -= 1;
	return (1);
}

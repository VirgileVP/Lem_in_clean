/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colony_push.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:43:17 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 10:34:48 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "colony.h"

static void		src_relink(t_colony *c)
{
	t_ant			*last;
	t_ant			*first;

	if (c->len == 1)
		c->ant = NULL;
	else
	{
		last = c->ant->prev;
		first = c->ant->next;
		last->next = first;
		first->prev = last;
		c->ant = first;
	}
}

static void		dst_relink(t_colony *c, t_ant *new)
{
	t_ant			*first;
	t_ant			*last;

	if (c->len == 0)
	{
		new->next = new;
		new->prev = new;
		c->ant = new;
	}
	else
	{
		first = c->ant;
		last = c->ant->prev;
		new->next = first;
		new->prev = last;
		first->prev = new;
		last->next = new;
		c->ant = new;
	}
}

int				colony_push(t_colony *dst, t_colony *src)
{
	t_ant			*tmp;

	if (src->len > 0)
	{
		tmp = src->ant;
		src_relink(src);
		dst_relink(dst, tmp);
		src->len -= 1;
		dst->len += 1;
		return (1);
	}
	return (0);
}

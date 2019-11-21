/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colony.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 12:58:37 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 10:04:39 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"
#include "pathfinding.h"

t_colony		*colony_init(size_t len)
{
	t_colony		*c;

	if (!(c = (t_colony *)malloc(sizeof(t_colony))))
		return (NULL);
	if (len > 0 && ant_spawn(c, len) == -1)
		return (NULL);
	c->len = len;
	return (c);
}

void			colony_destroy(t_colony **c)
{
	t_ant			*tmp;
	t_ant			*a;

	a = (*c)->p;
	while ((*c)->len > 0)
	{
		tmp = a->next;
		free(a->roadmap);
		free(a->used);
		free(a);
		a = tmp;
		(*c)->len -= 1;
	}
}

static void		src_relink(t_colony *src)
{
	t_ant			*first;
	t_ant			*last;

	if (src->len == 1)
		src->p = NULL;
	else
	{
		first = src->p->next;
		last = src->p->prev;
		first->prev = last;
		last->next = first;
		src->p = first;
	}
}

static void		dst_relink(t_colony *dst, t_ant *new)
{
	t_ant			*first;
	t_ant			*last;

	if (dst->len == 0)
	{
		new->next = new;
		new->prev = new;
		dst->p = new;
	}
	else
	{
		first = dst->p;
		last = dst->p->prev;
		first->prev = new;
		last->next = new;
		new->next = first;
		new->prev = last;
		dst->p = new;
	}
	
}

void            colony_push(t_colony *dst, t_colony *src)
{
	t_ant           *tmp;

	if (src->len > 0)
	{
		tmp = src->p;
		src_relink(src);
		dst_relink(dst, tmp);
		src->len -= 1;
		dst->len -= 1;
	}
}
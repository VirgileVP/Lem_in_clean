/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 14:05:04 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 10:37:47 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"
#include "lem_in.h"

int				ant_spawn(t_colony *c, size_t n, t_anthill *ah)
{
	t_colony		tmp;

	tmp.len = n;
	while (tmp.len > 0)
	{
		if (!(tmp.p = (t_ant *)malloc(sizeof(t_ant))) ||
			!(tmp.p->used = ft_memalloc(sizeof(char) * ah->nb_room)) ||
			!(tmp.p->roadmap = roadmap_new()))
			return (-1);
		tmp.p->pos = 0;
		ant_push(c, &tmp);
	}
	return (1);
}

void			ant_dup(t_colony *wander, size_t n, t_anthill *ah)
{

	t_colony		c;

	c.len = n;
	while (c.len > 0)
	{
		if (!(c.p = (t_ant *)malloc(sizeof(t_ant))) ||
			!(c.p->used = ft_memdup(wander->p->used, sizeof(char) * ah->nb_room)) ||
			!(c.p->roadmap = roadmap_cpy(wander->p->roadmap)))
			exit (-1);
		c.len -= 1;
	}
}

int				ant_rewind(t_ant *a, t_anthill *ah)
{
	if (a->roadmap->len == 0)
		return (-1);
	else if (a->roadmap->len == 1)
	{
		free(a->roadmap->p);
		a->roadmap->begin = NULL;
		a->roadmap->p = NULL;
		a->roadmap->len = 0;
		a->used[a->pos] = 0;
	}
	else
	{
		a->roadmap->p = a->roadmap->p->prev;
		a->used[a->pos] = 0;
		a->pos = a->roadmap->p->room;
		free(a->roadmap->p->next);
		a->roadmap->len -= 1;
	}
	return (1);
}

void			ant_kill(t_colony *wander)
{
	free(*wander->p->used);
	while ()
}
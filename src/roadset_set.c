/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   roadset_set.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 08:28:52 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 10:01:38 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

static int		set_line(t_rlink *r, int **t, size_t y, size_t len)
{
	size_t		x;

	x = 0;
	if ((t[y] = (int *)malloc(sizeof(int) * len)) == NULL)
		return (-1);
	while (r != NULL)
	{
		t[y][x] = r->n;
		x += 1;
		r = r->next;
	}
	return (1);
}

int				roadset_set(t_roadset **rs, t_rclass *rc)
{
	size_t			y;
	t_rmap			*p;

	if (((*rs) = (t_roadset *)malloc(sizeof(t_roadset))) == NULL ||
			 !((*rs)->roadmap = (int **)malloc(sizeof(int *) * rc->rlen)))
		return (-1);
	y = 0;
	p = rc->rmap;
	while (y < rc->rlen)
	{
		if (set_line(p, (*rs)->roadmap, y, p->len) == -1)
			return (-1);
		y += 1;
		p = p->next;
	}
	return (1);
}

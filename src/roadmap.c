/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   roadmap.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 09:41:02 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 12:43:05 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"
#include "pathfinding.h"

t_rlist			*roadmap_new(void)
{
	t_rlist			*r;

	if (!(r = (t_rlist *)malloc(sizeof(t_rlist))))
		return (NULL);
	r->begin = NULL;
	r->p = NULL;
	r->len = 0;
	return (r);
}

int				roadmap_add(t_rlist *r, int n)
{
	t_rlink			*new;

	if (!(new = (t_rlink *)malloc(sizeof(t_rlink))))
		return (-1);
}

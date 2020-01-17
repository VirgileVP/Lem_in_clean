/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rclass_new.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 12:37:58 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 07:41:29 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

t_rclass		*rclass_new(t_pfinding *pf)
{
	t_rclass		*r;

	if ((r = (t_rclass *)malloc(sizeof(t_rclass))) == NULL)
		return (NULL);
	r->rmap = NULL;
	r->t = NULL;
	if ((r->barr = (t_ul)ft_memalloc(sizeof(t_ul) * pf->len)) == NULL)
		return (NULL);
	r->next = NULL;
	return (r);
}

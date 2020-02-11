/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_dup.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 13:23:46 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 13:25:26 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

/*static int		rmap_cpy()
{
	while (a->len < pf->ant->len)
	{
		if (!(a->r->next = (t_rlink *)malloc(sizeof(t_rlink))))
			return (MALLOC_ERROR);
		a->r = a->r->next;
		a->r->next = NULL;
		a->r->n = r->n;
		a->len += 1;
		r = r->next;
	}
}*/

int				ant_dup(t_pf *pf)
{
	t_ant			*a;

	if (!(a = (t_ant *)malloc(sizeof(t_ant))) ||
			!(a->barr = ft_memdup(pf->ant->barr, sizeof(t_ul) * pf->xlen)) ||
			!(a->root = (t_rlink *)malloc(sizeof(t_rlink))))
		return (MALLOC_ERROR);
	a->root->next = NULL;
	a->root->n = pf->start_index;
	a->r = a->root;
	a->r = pf->ant->root->next;
	
	a->prev = pf->ant->prev;
	a->next = pf->ant;
	pf->ant->prev = a;
	pf->ant = a;
	return (1);
}

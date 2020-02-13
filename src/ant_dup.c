/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_dup.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 13:23:46 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 13:25:57 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

static void		print_ant(t_ant *a, size_t nb_room)
{
	t_ul			cccc = BINIT;
	size_t			xn = 0;

	printf("a->len = %zu\n\t|", a->len);
	for (t_rlink *tmp = a->root; tmp != NULL; tmp = tmp->next)
		printf("%d|", tmp->n);
	printf("\nbarr\t");
	for (size_t x = 0; x < nb_room; x += 1)
	{

		if (a->barr[xn] & cccc)
			printf("1|");
		else
			printf("0|");
		cccc >>= 1;
		if (cccc == 0)
		{
			cccc = 0x8000000000000000UL;
			xn += 1;
		}
	}
	printf("\n");
}

static void		print_dup(t_ant *a1, t_ant *a2, size_t nb_room)
{
	printf("-ant_dup:\n");
	print_ant(a1, nb_room);
	print_ant(a2, nb_room);
	printf("-ant_dup-quit\n");
}

static int		rmap_cpy(t_pf *pf, t_ant *a)
{
	t_rlink			*r;

	r = pf->ant->root->next;
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
	return (1);
}

int				ant_dup(t_pf *pf)
{
	t_ant			*a;

	if (!(a = (t_ant *)malloc(sizeof(t_ant))) ||
			!(a->barr = ft_memdup(pf->ant->barr, sizeof(t_ul) * pf->xlen)) ||
			!(a->root = (t_rlink *)malloc(sizeof(t_rlink))))
		return (MALLOC_ERROR);
	a->len = 1;
	a->root->next = NULL;
	a->root->n = pf->start_index;
	a->r = a->root;
	if (rmap_cpy(pf, a) == MALLOC_ERROR)
		return (MALLOC_ERROR);
//	print_dup(pf->ant, a, pf->nb_room);
	a->prev = pf->ant->prev;
	a->next = pf->ant;
	pf->ant->prev->next = a;
	pf->ant->prev = a;
	pf->ant = a;
	pf->xant += 1;
	return (1);
}

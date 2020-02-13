/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_scout.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 11:06:30 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 13:25:24 by zseignon    ###    #+. /#+    ###.fr     */
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

static void		print_xant(t_pf *pf)
{
	size_t			n = 0;
	t_ant			*a = pf->ant;

	printf("---PRINT ALL ANT\npf->xant = %zu\n", pf->xant);
	while (n < pf->xant)
	{
		print_ant(a, pf->nb_room);
		a = a->next;
		n += 1;
	}
	printf("pf->xend = %zu\n", pf->xend);
	a = pf->end;
	n = 0;
	while (n < pf->xend)
	{
		print_ant(a, pf->nb_room);
		a = a->next;
		n += 1;
	}
	printf("---PRINT OVER\n");
}

static void		ant_end(t_pf *pf)
{
	t_ant			*tmp;
	t_ant			*first;
	t_ant			*last;

	tmp = pf->ant;
	first = pf->ant->next;
	last = pf->ant->prev;
	if (pf->xant > 1)
	{
		first->prev = last;
		last->next = first;
		pf->ant = first;
	}
	else
		pf->ant = NULL;
	pf->xant -= 1;
	if (pf->xend > 0)
	{
		first = pf->end;
		last = pf->end->prev;
		first->prev = tmp;
		last->next = tmp;
		tmp->next = first;
		tmp->prev = last;
		pf->end = tmp;
	}
	else
	{
		pf->end = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	pf->xend += 1;
}

static int		ant_move(t_pf *pf, t_bindex *i)
{
//	printf("-ant_move:%zu\n", i->x);
	if (i->x == pf->start_index)
		ant_kill(pf);
	else
	{
		if (!(pf->ant->r->next = (t_rlink *)malloc(sizeof(t_rlink))))
			return (MALLOC_ERROR);
		pf->ant->r = pf->ant->r->next;
		pf->ant->r->n = i->x;
		pf->ant->r->next = NULL;
		pf->ant->len += 1;
//		print_ant(pf->ant, pf->nb_room);
		if (i->x == pf->end_index)
			ant_end(pf);
		else
		{
			pf->ant->barr[i->xn] |= i->cccc;
			pf->ant = pf->ant->next;
		}
//		printf("-ant_move-quit\n");
	}
	return (1);
}

static int		barr_chr(t_bindex *i, t_ul *t, t_ul *u, size_t len)
{
	while (i->xn < len)
	{
		if (t[i->xn] != 0)
		{
			if (i->cccc == 0)
			{
				i->x = i->xn * 64;
				i->cccc = BINIT;
			}
			while (i->cccc != 0)
			{
				if (!(i->cccc & u[i->xn]) && (i->cccc & t[i->xn]))
					return (1);
				i->cccc >>= 1;
				i->x += 1;
			}
		}
		i->xn += 1;
	}
	return (0);
}

static int		ant_multi(t_pf *pf, t_bindex *i, t_bindex *n)
{
	if (ant_dup(pf) == MALLOC_ERROR || ant_move(pf, i) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	ft_memcpy(i, n, sizeof(t_bindex));
	n->x += 1;
	n->cccc >>= 1;
	while (barr_chr(n, pf->matrix[pf->ant->r->n], pf->ant->barr, pf->xlen) == 1)
	{
		if (ant_dup(pf) == MALLOC_ERROR || ant_move(pf, i) == MALLOC_ERROR)
			return (MALLOC_ERROR);
		ft_memcpy(i, n, sizeof(t_bindex));
		n->x += 1;
		n->cccc >>= 1;
	}
	if (ant_move(pf, i) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	return (1);
}

int				ant_scout(t_pf *pf)
{
	t_bindex		i;
	t_bindex		n;

	while (pf->xant > 0)
	{
		ft_memset(&i, 0, sizeof(t_bindex));
		if (barr_chr(&i, pf->matrix[pf->ant->r->n],
					pf->ant->barr, pf->xlen) == 0)
			ant_kill(pf);
		else
		{
			ft_memcpy(&n, &i, sizeof(t_bindex));
			n.cccc >>= 1;
			n.x += 1;
			if (barr_chr(&n, pf->matrix[pf->ant->r->n],
						pf->ant->barr, pf->xlen) == 1)
			{
				if (ant_multi(pf, &i, &n) == MALLOC_ERROR)
					return (MALLOC_ERROR);
			}
			else
			{
				if (ant_move(pf, &i) == MALLOC_ERROR)
					return (MALLOC_ERROR);
			}
		}
//		print_xant(pf);
	}
	if (pf->xend == 0)
		return (NO_PATH);
	return (1);
}

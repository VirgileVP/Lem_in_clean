/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:58:45 by zseignon          #+#    #+#             */
/*   Updated: 2020/02/17 14:23:44 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding.h"

static int		pf_init(t_pf *pf, t_anthill *ah)
{
	size_t			n;

	if (!(pf->cost = (int *)malloc(sizeof(int) * ah->nb_room)) ||
			!(pf->rmap = (int *)malloc(sizeof(int) * ah->nb_room)) ||
			!(pf->data = (char *)ft_memalloc(sizeof(char) * ah->nb_room)))
		return (MALLOC_ERROR);
	n = 0;
	pf->rlen = 0;
	pf->scope = ah->nb_room;
	pf->nb_room = ah->nb_room;
	pf->start = ah->start;
	pf->end = ah->end;
	pf->lemin = ah->nb_ant;
	pf->matrix = ah->matrix;
	return (1);
}

static int		cost_tool(t_pf *pf, int pos, size_t depth)
{
	if (pf->data[pos] & MARKED)
	{
		if (depth < pf->cost[pos])
			pf->cost[pos] = depth;
		else
			return (0);
	}
	else
	{
		pf->cost[pos] = depth;
		pf->data[pos] |= MARKED;
	}
	if (depth >= pf->scope)
		return (0);
	return (1);
}

static void		cost_calc(t_pf *pf, int pos, size_t depth)
{
	int				n;

	if (cost_tool(pf, pos, depth) == 0)
		return ;
	pf->data[pos] |= USED;
	n = 0;
	while (n < pf->nb_room)
	{
		if (pf->matrix[pos][n] == 1 && !(pf->data[n] & USED)  && n != pos)
		{
		//	printf("connection from %7d to %7d found in depth %4zu |%5d\n", pos, n, depth, pf->scope);
			if (n == pf->start)
			{
				pf->scope = depth + 1;
				pf->data[pos] ^= USED;
				return ;
			}
			cost_calc(pf, n, depth + 1);
		}
		n += 1;
	}
	pf->data[pos] ^= USED;
}

static void		shortest_path(t_pf *pf)
{
	size_t			pos;
	size_t			x;
	int				cost;
	int				node;

	pos = pf->start;
	pf->rlen = 1;
	pf->rmap[0] = pos;
	while (pos != pf->end)
	{
		cost = INT_MAX;
		x = 0;
		while (x < pf->nb_room)
		{
			if (pf->matrix[pos][x] == 1 && (pf->data[x] & MARKED) && pf->cost[x] < cost)
			{
				cost = pf->cost[x];
				node = x;
			}
			x += 1;
		}
		pf->rmap[pf->rlen] = node;
		pos = node;
		pf->rlen += 1;
	}
}

static int		roadset_convert(t_pf *pf, t_roadset **rs)
{
	size_t			x;
	
	if (
			!(*rs = (t_roadset *)malloc(sizeof(t_roadset) * 2)) ||
			!((*rs)[0].t = (t_rdata *)malloc(sizeof(t_rdata) * pf->rlen))
	   )
		return (MALLOC_ERROR);
	x = 0;
	(*rs)[0].len = pf->rlen;
	(*rs)[0].nb_ant = pf->lemin;
	while (x < pf->rlen)
	{
		(*rs)[0].t[x].n = pf->rmap[x];
		(*rs)[0].t[x].ant_index = 0;
		x += 1;
	}
	(*rs)[1].t = NULL;
	return (1);
}

int				pathfinding(t_anthill *ah, t_roadset **rs)
{
	t_pf			pf;

	if (pf_init(&pf, ah) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	cost_calc(&pf, pf.end, 0);
	shortest_path(&pf);
	if (roadset_convert(&pf, rs) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	return (1);
}

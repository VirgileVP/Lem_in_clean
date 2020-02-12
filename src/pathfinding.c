/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pathfinding.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 11:05:53 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 13:18:52 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

static int		pf_init(t_pf *pf, t_anthill *ah)
{
	t_bindex		i;

	if (!(pf->ant = (t_ant *)malloc(sizeof(t_ant))) ||
			!(pf->ant->root = (t_rlink *)malloc(sizeof(t_rlink))) ||
			!(pf->ant->barr = (t_ul *)ft_memalloc(sizeof(t_ul) * ah->xlen)))
		return (MALLOC_ERROR);
	pf->ant->root->n = ah->start;
	pf->ant->root->next = NULL;
	pf->ant->r = pf->ant->root;
	pf->ant->len = 1;
	pf->ant->prev = pf->ant;
	pf->ant->next = pf->ant;
	i.cccc = BINIT >> (ah->start % 64);
	i.xn = ah->start / 64;
	pf->ant->barr[i.xn] |= i.cccc;
	pf->end = NULL;
	pf->xant = 1;
	pf->xend = 0;
	pf->start_index = ah->start;
	pf->end_index = ah->end;
	pf->matrix = ah->matrix;
	pf->xlen = ah->xlen;
	pf->lemin = ah->nb_ant;
	pf->tend = NULL;
	return (1);
}

static void		pf_free(t_pf *pf)
{
	while (pf->xant > 0)
		ant_kill(pf);
	while (pf->end != NULL)
		end_kill(pf);
	if (pf->tend != NULL)
		free(pf->tend);
}

int				pathfinding(t_anthill *ah, t_roadset **rs)
{
	t_pf			pf;
	int				ret;

	if ((pf_init(&pf, ah)) == MALLOC_ERROR ||
			(ret = ant_scout(&pf)) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	if (ret < 0)
		return (-1);
	if (ant_convert(&pf) == MALLOC_ERROR ||
			bf_main(&pf, rs) == MALLOC_ERROR)
		return (-1);
//	pf_free(&pf);
	return (1);
}

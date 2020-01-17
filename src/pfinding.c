/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pfinding.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 08:37:41 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 07:46:01 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

enum e_pstat		(*const path_fct[])(
		t_pfinding *
		) = {
	&ant_scout,
	&rclass_add,
	&pf_eval,
	&ant_kill
};

static int			pfinding_init(t_pfinding **pf, t_anthill *ah)
{
	if (((*pf) = (t_pfinding *)malloc(sizeof(t_pfinding))) == NULL)
		return (-1);
	(*pf)->root = NULL;
	(*pf)->c = NULL;
	(*pf)->best = NULL;
	(*pf)->matrix = ah->matrix;
	(*pf)->xm = ah->len;
	(*pf)->start = ah->start;
	(*pf)->end = ah->end;
	(*pf)->lemin = ah->nb_ant;
	return (1);
}

int					pathfinding(t_anthill *ah, t_roadset **rs)
{
	t_pfinding			*pf;
	enum e_pstat		status;

	if (pfinding_init(&pf, ah) == -1)
		return (-1);
	status = PROCEED;
	while (status >= PROCEED && pf->xant > 0)
		status = path_fct[status];
	if (status == MALLOC_ERROR)
	{
		pfinding_free(&pf);
		return (-1);
	}
	else if (status != NO_PATH && pf->best != NULL)
		roadset_set(rs, pf->best);
	pfinding_free(&pf);
	if (status == NO_PATH)
		return (0);
	return (1);
}

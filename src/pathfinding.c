/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pathfinding.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 14:30:52 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 11:14:39 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"
#include "lem_in.h"


static enum flag		eval(t_roadset *rmap, t_anthill *ah)
{
	return (STOP);
}

static void		ant_loop(t_colony *wander, t_colony *reacher, t_anthill *ah)
{
	char			end_reached;
	int				tubes;
	
	end_reached = 0;
	while (wander > 0 && !end_reached)
	{
		if ((tubes = (tube_count(ah, wander))) != 2)
		{
			if (tubes > 2)
				ant_dup(wander, tubes);
			else if ((ant_rewind(wander->p, ah)) == -1)
				ant_kill(wander, ah);
		}
		else
		{
			ant_scout(wander, ah);
			if (wander->p->pos == ah->end)
			{
				colony_push(wander, reacher);
				end_reached = 1;
			}
			else
				wander->p = wander->p->next;
		}
	}
}

t_ant			**path_finder(int **matrix, t_anthill *ah)
{
	t_colony		*wander;
	t_colony		*reacher;
	t_roadset		*rmap;

	wander = colony_init(tube_count(ah->matrix, ah->start));
	reacher = colony_init(0);
	rmap = roadmap_new();
	while (eval(reacher, ah) == PROCEED)
	{
		ant_loop(wander, reacher, ah);
		roadset_analysis(rmap, reacher);
		if (wander->len == 0)
			break ;
	}
	colony_destroy(&wander);
	colony_destroy(&reacher);
	return (rmap);
}

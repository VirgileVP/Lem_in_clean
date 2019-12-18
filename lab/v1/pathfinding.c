/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pathfinding.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 10:52:36 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 14:10:26 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "colony.h"

t_roadset				pathfinding(t_anthill *ah)
{
	t_colony				*wander;
	t_colony				*end;
	t_roadset				*roadset;
	t_rclass_root			*rclass;

	if (
			rclass_root_new(&rclass) < 0 ||
			colony_new(&wander, ah, tube_count(ah->start, ah)) < 0 ||
			colony_new(&end, ah, 0) < 0
		)
		return (NULL);
	while ((ret = eval(end, rclass, &roadset)) == PROCEED)
	{
		ant_loop(wander, end, ah);
		road_classify(end, rclass);
		if (wander->len == 0)
			break ;
	}
	return (roadset);
}

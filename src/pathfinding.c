/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pathfinding.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 14:30:52 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 10:56:36 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

static int		eval(t_ant **reached, t_anthill *ah)
{

}

static void		ant_loop(t_ant **ant, t_ant **reached, size_t *nb_ant)
{
	char			end_reached;
	size_t			n;
	
	n = 0;
	end_reached = 0;
	while (*nb_ant > 0 && !end_reached)
	{
		if ((tubes = (tube_count(matrix, ant[n].pos)) - 1) > 1)
			ant_dup(ant, n, tubes);
		else if (tubes == 0)
			if ((ant_rewind(ant, n, matrix)) == -1)
				ant_kill(ant, n, matrix, nb_ant);
		ant_scout(ant, n, matrix);
		if (ant[n].pos == 1)
		{
			reached_add(ant, reached, n);
			*nb_ant -= 1;
			end_reached = 1;
		}
		else
			n += 1;
	}
}

t_ant			**path_finder(int **matrix, t_anthill *ah)
{
	t_colony		**ant;
	t_colony		**reached;
	t_roadmap		*rmap;
	size_t			nb_ant;

	nb_ant = tube_count(matrix, 0);
	ant = ant_spawn(nb_ant);
	reached = NULL;
	rmap = rmap_init();
	while (eval(reached, ah) == PROCEED)
	{
		ant_loop(ant, reached, &nb_ant);
		rmap_add(rmap, reached);
		if (nb_ant == 0)
			break ;
	}
	return (rmap);
}

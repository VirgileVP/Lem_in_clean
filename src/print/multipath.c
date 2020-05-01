/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveyrat- <vveyrat-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:42:26 by vveyrat-          #+#    #+#             */
/*   Updated: 2020/03/10 11:42:28 by vveyrat-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "print.h"
#include "resolve_print.h"

/*
** solo_ant :
**
** if an ant is solo in a road, move it simply
*/

static void	solo_ant(t_anthill *anthill,
			t_roadset *roads, int road_index, int *remaining_ants)
{
	size_t	count;
	int		actual_ant;

	count = 0;
	actual_ant = which_ant(roads, road_index) + 1;
	if (empty_road(roads, road_index) == 1)
		roads[road_index].t[1].ant_index = actual_ant;
	else
	{
		while (count < roads[road_index].len)
		{
			if (roads[road_index].t[count].ant_index == actual_ant)
			{
				roads[road_index].t[count].ant_index = 0;
				if (count + 1 < roads[road_index].len)
					roads[road_index].t[count + 1].ant_index = actual_ant;
				break ;
			}
			count++;
		}
	}
	if (remaining_ants[road_index] > 0)
		print_step(anthill, roads, road_index);
	if (count == roads[road_index].len - 1)
		remaining_ants[road_index] = 0;
}

/*
** print_step_update_ant :
**
** Determines if print_step is necessary
** Update ant_index
*/

static void	print_step_update_ant(t_anthill *anthill,
			t_roadset *roads, int *remaining_ants, int road_index)
{
	if (remaining_ants[road_index] >= 1)
		print_step(anthill, roads, road_index);
	if (roads[road_index].t[roads[road_index].len - 1].ant_index
	== which_ant(roads, road_index + 1))
		remaining_ants[road_index] = 0;
}

/*
** update_roads_rooms2 :
**
** move ants;
*/

static void	update_roads_rooms2(t_roadset *roads,
			int *remaining_ants, int road_index, int count)
{
	if (roads[road_index].t[count].ant_index ==
	which_ant(roads, road_index + 1))
		roads[road_index].t[count].ant_index = 0;
	else if (count == 1 || roads[road_index].t[count - 1].ant_index > 1)
		roads[road_index].t[count].ant_index++;
	else if (roads[road_index].t[count].ant_index ==
	which_ant(roads, road_index) + roads[road_index].nb_ant - 1)
		roads[road_index].t[count].ant_index++;
}

/*
** update_roads_rooms :
**
** browse all room in a road, move ants and print step;
*/

static void	update_roads_rooms(t_anthill *anthill,
			t_roadset *roads, int *remaining_ants, int road_index)
{
	size_t	count;

	count = 0;
	if (is_starting(roads, road_index, anthill) == 1)
		return ;
	while (count < roads[road_index].len)
	{
		if (roads[road_index].t[count].ant_index != 0)
			update_roads_rooms2(roads, remaining_ants, road_index, count);
		else if (roads[road_index].t[count].ant_index == 0
		&& count >= 1 && roads[road_index].t[count - 1].ant_index ==
		which_ant(roads, road_index) + 2)
		{
			roads[road_index].t[count].ant_index =
			roads[road_index].t[count - 1].ant_index - 1;
		}
		count++;
	}
	print_step_update_ant(anthill, roads, remaining_ants, road_index);
}

int			multi_path(t_anthill *anthill, t_roadset *roads)
{
	int		count;
	int		nb_road;
	int		*remaining_ants;

	count = 0;
	nb_road = how_much_road(roads);
	if (!(remaining_ants = ft_malloc(sizeof(int) * nb_road)))
		return (-1);
	fill_remaining_ants(roads, remaining_ants, nb_road);
	while (total_ant(remaining_ants, nb_road) > 0)
	{
		count = 0;
		while (count < nb_road)
		{
			if (remaining_ants[count] == 1)
				solo_ant(anthill, roads, count, remaining_ants);
			else if (remaining_ants[count] > 1)
				update_roads_rooms(anthill, roads, remaining_ants, count);
			count++;
		}
		ft_putchar('\n');
	}
	ft_memdel((void*)&remaining_ants);
	return (0);
}

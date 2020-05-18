/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unipath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveyrat- <vveyrat-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:42:26 by vveyrat-          #+#    #+#             */
/*   Updated: 2020/03/10 11:42:28 by vveyrat-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "resolve_print.h"

/*
** print_step :
**
** print the new road status
*/

static void		print_step_unipath(t_anthill *anthill, t_roadset *roads)
{
	int			count;

	count = roads[0].len - 1;
	while (count >= 0)
	{
		if (roads[0].t[count].ant_index != 0)
		{
			print_path(roads[0].t[count].ant_index,
			anthill->room_data[roads[0].t[count].n].name);
			if (roads[0].t[count - 1].ant_index != 0)
				ft_putchar(' ');
		}
		count--;
	}
	ft_putchar('\n');
}

/*
** update_roads_rooms :
**
** browse all room in a road and move ants in next room
*/

static void		update_roads_rooms(t_anthill *anthill, t_roadset *roads)
{
	size_t		current_room;

	current_room = roads[0].len - 1;
	while (current_room > 0)
	{
		if (roads[0].t[current_room].ant_index != 0)
		{
			if (roads[0].t[current_room].ant_index < roads[0].nb_ant)
			{
				if (current_room == 1)
					roads[0].t[current_room].ant_index++;
			}
			else
			{
				roads[0].t[current_room].ant_index = 0;
			}
			if (current_room < roads[0].len - 1)
				roads[0].t[current_room + 1].ant_index++;
		}
		current_room--;
	}
	print_step_unipath(anthill, roads);
	if (roads[0].t[roads[0].len - 1].ant_index == roads[0].nb_ant)
		roads[0].nb_ant = 0;
}

static int		solo_ant(t_anthill *anthill, t_roadset *roads)
{
	size_t		count;

	count = 1;
	while (count < roads[0].len)
	{
		print_path(1, anthill->room_data[roads[0].t[count].n].name);
		ft_putchar('\n');
		count++;
	}
	return (0);
}

int				all_ant_one_path(t_anthill *anthill, t_roadset *roads)
{
	int			begin;

	begin = 1;
	if (roads[0].nb_ant == 1)
		return (solo_ant(anthill, roads));
	while (roads[0].nb_ant > 0)
	{
		if (begin == 1)
		{
			roads[0].t[1].ant_index = 1;
			print_path(roads[0].t[1].ant_index,
			anthill->room_data[roads[0].t[1].n].name);
			ft_putchar('\n');
			begin = 0;
		}
		else
			update_roads_rooms(anthill, roads);
	}
	return (0);
}

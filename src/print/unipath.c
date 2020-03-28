/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unipath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:38:45 by vveyrat-          #+#    #+#             */
/*   Updated: 2020/03/12 12:52:45 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		print_road_status(t_roadset *roads, int road)
{
	int			count;

	count = 0;
	printf("Road %2d | Rooms : ", road);
	while (count < roads[road].len)
	{
		printf("|%d|", roads[road].t[count].n);
		fflush(stdout);
		count++;
	}
	printf("\n          Ants  : ");
	count = 0;
	while (count < roads[road].len)
	{
		printf("|%d|", roads[road].t[count].ant_index);
		fflush(stdout);
		count++;
	}
	printf("\n");
	fflush(stdout);
}

/*
** print_step :
**
** print the new road status
*/

static void		print_step(t_anthill *anthill, t_roadset *roads)
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
	size_t		curr_room;

	curr_room = roads[0].len - 1;
	while (curr_room > 0)
	{
		if (roads[0].t[curr_room].ant_index != 0)
		{
			if (roads[0].t[curr_room].ant_index < roads[0].nb_ant)
			{
				if (curr_room == 1)
					roads[0].t[curr_room].ant_index++;
			}
			else
			{
				roads[0].t[curr_room].ant_index = 0;
			}
			if (curr_room < roads[0].len - 1)
				roads[0].t[curr_room + 1].ant_index++;
		}
		curr_room--;
	}
	print_step(anthill, roads);
	if (roads[0].t[roads[0].len - 1].ant_index == roads[0].nb_ant)
		roads[0].nb_ant = 0;
}

static int		solo_ant(t_anthill *anthill, t_roadset *roads)
{
	size_t		count;

	count = 0;
	roads[0].t[1].ant_index = 1;
	while (roads[0].nb_ant == 1)
	{
		count = 0;
		while (count < roads[0].len)
		{
			if (roads[0].t[count].ant_index == 1)
			{
				roads[0].t[count].ant_index = 0;
				if (count + 1 < roads[0].len)
					roads[0].t[count + 1].ant_index = 1;
				else
					roads[0].nb_ant = 0;
				print_path(1, anthill->room_data[roads[0].t[count].n].name);
				ft_putchar((count == roads[0].len - 1) ? '\n' : ' ');
				break;
			}
			count++;
		}
	}
	return (0);
}

int				all_ant_one_path(t_anthill *anthill, t_roadset *roads)
{
	ft_putstr("\nUNIPATH\n\n");
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

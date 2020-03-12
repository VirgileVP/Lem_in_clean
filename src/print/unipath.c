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
/*
static void		print_road_status(t_roadset *roads, int road)
{
	int		count;

	count = 0;
	printf("Road %2d | Rooms : ", road);
	while (count < roads[road].len)
	{
		printf("|%d|", roads[road].t[count].n);
		count++;
	}
	printf("\n          Ants  : ");
	count = 0;
	while (count < roads[road].len)
	{
		printf("|%d|", roads[road].t[count].ant_index);
		count++;
	}
	printf("\n\n");
}
*/
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

static void		update_roads_rooms(t_anthill *anthill,
t_roadset *roads, int room_index)
{
	size_t			count;

	count = room_index;
	while (count < roads[0].len)
	{
		if (roads[0].t[count].ant_index != 0)
		{
			if (roads[0].t[count].ant_index == roads[0].nb_ant)
				roads[0].t[count].ant_index = 0;
			else if ((int)count == room_index || roads[0].t[count - 1].ant_index > 1)
				roads[0].t[count].ant_index++;
			else if (roads[0].t[count].ant_index == roads[0].nb_ant - 1)
				roads[0].t[count].ant_index++;
		}
		else if ((int)count == room_index || roads[0].t[count - 1].ant_index >= 1)
			roads[0].t[count].ant_index++;
		count++;
	}
	//print_road_status(roads, 0);
	print_step(anthill, roads);
	if (roads[0].t[roads[0].len - 1].ant_index == roads[0].nb_ant)
		roads[0].nb_ant = 0;
}

static int		solo_ant(t_anthill *anthill, t_roadset *roads)
{
	size_t			count;

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
	int			count_room;
	int			begin;

	begin = 1;
	count_room = 0;
	if (roads[0].nb_ant == 1)
		return (solo_ant(anthill, roads));
	while (roads[0].nb_ant > 0)
	{
		count_room = 0;
		while (count_room < (int)roads[0].len)
		{
			if (roads[0].t[count_room].ant_index != 0)
			{
				update_roads_rooms(anthill, roads, count_room);
				begin = 0;
				count_room = roads[0].len;
			}
			count_room++;
		}
		if (begin == 1)
		{
			roads[0].t[1].ant_index = 1;
			print_path(roads[0].t[1].ant_index,
			anthill->room_data[roads[0].t[1].n].name);
			ft_putchar('\n');
		}
	}
	return (0);
}
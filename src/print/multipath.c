/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:36:30 by vveyrat-          #+#    #+#             */
/*   Updated: 2020/03/16 15:22:12 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
/*
static void		print_road_status(t_roadset *roads, int road)
{
	int		count;

	count = 0;
	printf("\nRooms : ");
	while (count < roads[road].len)
	{
		printf("|%d|", roads[road].t[count].n);
		count++;
	}
	printf("\nAnts  : ");
	count = 0;
	while (count < roads[road].len)
	{
		printf("|%d|", roads[road].t[count].ant_index);
		count++;
	}
	printf("\n");
}
*/
/*
** fill_remaining_ants :
**
** fill int *remaining_ants with the number of ant in each road
*/

static void		fill_remaining_ants(t_roadset *roads, int *remaining_ants, int nb_road)
{
	int		count;

	count = 0;
	while (count < nb_road)
	{
		remaining_ants[count] = roads[count].nb_ant;
		count++;
	}
}

/*
** total_ant :
**
** calcul total ant in int *remaining_ants
*/

static int		total_ant(int *remaining_ants, int nb_road)
{
	int		count;
	int		ret;

	count = 0;
	ret = 0;
	while (count < nb_road)
	{
		ret += remaining_ants[count];
		count++;
	}
	return (ret);
}

/*
** which_ant :
**
** return index of the last ant in the road_index-1 room()
*/

static int	which_ant(t_roadset *roads, int road_index)
{
	int		count;
	int		ret;

	ret = 0;
	count = 0;
	while (count < road_index)
	{
		ret += roads[count].nb_ant;
		count++;
	}
	return (ret);
}

/*
** is_starting :
**
** return start
** start = 1 if 1st cycle (all ant in start room)
** start = 0 if ant(s) is/are out start room
** if start == 1, move 1st ant out start room
*/

static int	is_starting(t_roadset *roads, int road_index, t_anthill *anthill)
{
	size_t	count;
	int		start;

	count = 0;
	start = 1;
	while (count < roads[road_index].len)
	{
		if (roads[road_index].t[count].ant_index != 0)
			start = 0;
		count++;
	}
	if (start == 1)
	{
		if (road_index == 0)
			roads[road_index].t[1].ant_index = 1;
		else
		    roads[road_index].t[1].ant_index = which_ant(roads, road_index) + 1;
		//printf("\nanthill->room_data[%d].name\n",roads[road_index].t[1].n);
		print_path(roads[road_index].t[1].ant_index, anthill->room_data[roads[road_index].t[1].n].name);
		ft_putchar(' ');
	}
	return (start);
}

/*
** print_step :
**
** print the new road status
*/

static void		print_step(t_anthill *anthill, t_roadset *roads, int road_index)
{
	int			count;

	count = roads[road_index].len - 1;
	while (count >= 0)
	{
		if (roads[road_index].t[count].ant_index != 0)
		{
			print_path(roads[road_index].t[count].ant_index, anthill->room_data[roads[road_index].t[count].n].name);
			if (road_index < how_much_road(roads) - 1 && count > 1)
				ft_putchar(' ');
		}
		count--;
	}
}

/*
** solo_ant :
**
** if an ant is solo in a road, move it simply
*/

static void		solo_ant(t_anthill *anthill, t_roadset *roads, int road_index, int *remaining_ants)
{
	size_t		count;
	int			actual_ant;

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
				break;
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
** update_roads_rooms :
**
** browse all room in a road, move ants and print step;
*/

static void	update_roads_rooms(t_anthill *anthill, t_roadset *roads, int *remaining_ants, int road_index)
{
	size_t	count;

	count = 0;
	if (is_starting(roads, road_index, anthill) == 1)
		return;
	while (count < roads[road_index].len)
	{
		if (roads[road_index].t[count].ant_index != 0)
		{
			if (roads[road_index].t[count].ant_index == which_ant(roads, road_index + 1))
				roads[road_index].t[count].ant_index = 0;
			else if (count == 1 || roads[road_index].t[count - 1].ant_index > 1)
				roads[road_index].t[count].ant_index++;
			else if (roads[road_index].t[count].ant_index == which_ant(roads, road_index) + roads[road_index].nb_ant - 1)
				roads[road_index].t[count].ant_index++;
		}
		else if (roads[road_index].t[count].ant_index == 0 && count >= 1 && roads[road_index].t[count - 1].ant_index == which_ant(roads, road_index) + 2)
			roads[road_index].t[count].ant_index = roads[road_index].t[count - 1].ant_index - 1;
		count++;
	}
	if (remaining_ants[road_index] >= 1)
		print_step(anthill, roads, road_index);
	if (roads[road_index].t[roads[road_index].len - 1].ant_index == which_ant(roads, road_index + 1))
		remaining_ants[road_index] = 0;
}

int			multi_path(t_anthill *anthill, t_roadset *roads)
{
	ft_putstr("\nMULTIPATH\n\n");
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

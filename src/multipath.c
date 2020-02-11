#include "lemin.h"

/*
** how_much_road :
** calcul nb of road in the roadset
*/

static int		how_much_road(t_roadset *roads)
{
	int		nb;

	nb = 0;
	while (roads[nb].t)
		nb++;
	return (nb + 1);
}

/*
** fill_remaining_ant :
** fill int *remaining_ant with the number of ant in each road
*/

static int		fill_remaining_ants(t_roadset *roads, int *remaining_ants, int nb_road)
{
	int		count;

	count = 0;
	if (!(remaining_ants = malloc(sizeof(int) * nb_road)))
		return (1);
	while (roads[count].t)
	{
		remaining_ants[count] = roads[count].nb_ant;
		count++;
	}
	return (0);
}

/*
** total_ant :
** calcul total ant in int *remaining_ants
*/

static int		total_ant(int *remaining_ants)
{
	int		count;
	int		ret;

	count = 0;
	ret = 0;
	while (remaining_ants[count])
	{
		ret += remaining_ants[count];
		count++;
	}
	return (ret);
}

/*
** wish_ant :
** return index of the last ant in the road_index-1 room()
*/

static int	which_ant(int *remaining_ants, int road_index)
{
	int		count;
	int		ret;

	ret = 0;
	count = 0;
	while (count < road_index)
	{
		ret += remaining_ants[count];
		count++;
	}
	return (ret);
}

/*
** is_starting :
** return start
** start = 1 if 1st cycle (all ant in start room)
** start = 0 if ant(s) is/are out start room
** if start == 1, move 1st ant out start room
*/

static int	is_starting(t_roadset *roads, int index, int *remaining_ants, t_anthill *anthill)
{
	int		count;
	int		start;

	count = 0;
	start = 1;
	while (count < roads[index].len)
	{
		if (roads[index].t[count].ant_index != 0)
			start = 0;
		count++;
	}
	if (start == 1)
	{
	    roads[index].t[1].ant_index = which_ant(remaining_ants, index) + 1;
		print_path(roads[index].t[1].ant_index, anthill->room_data[roads[index].t[1].ant_index].name);
	}
	return (start);
}

/*
** update_roads_rooms :
** browse all room in a road, move ants and print step;
*/

static void	update_roads_rooms( t_anthill *anthill, t_roadset *roads, int *remaining_ants, int index)
{
	int		count;

	count = 0;
	if (is_starting(roads, index, remaining_ants, anthill) == 1)
		return;
	while (count < roads[index].len)
	{
		if (roads[index].t[count].ant_index != 0)
		{
			roads[index].t[count].ant_index++;
			print_path(roads[index].t[count].ant_index, anthill->room_data[roads[index].t[count].ant_index].name);
			if (roads[index].t[count].ant_index != which_ant(remaining_ants, count + 1) && index != how_much_road(roads) - 1)
				ft_putchar(' ');
			if (roads[index].t[count].ant_index == 2 && roads[index].t[count + 1].ant_index == 0)
			{
				roads[index].t[count + 1].ant_index = 1;
				break;
			}
		}
		count++;
	}
	if (roads[index].t[roads[index].len - 1].ant_index == which_ant(remaining_ants, count + 1))
		roads[index].nb_ant = 0;
}

int			multi_path(t_anthill *anthill, t_roadset *roads)
{
	int		count;
	int		nb_road;
	int		*remaining_ants;

	count = 0;
	nb_road = how_much_road(roads);
	if (fill_remaining_ants(roads, remaining_ants, nb_road) == 1)
		return (1);
	while (total_ant(remaining_ants) > 0)
	{
		count = 0;
		while (count < nb_road)
		{
			if (roads[count].nb_ant != 0)
				update_roads_rooms(anthill, roads, remaining_ants, count);
			count++;
		}
		ft_putchar('\n');
	}
	free((void*)&remaining_ants);
	return (0);
}

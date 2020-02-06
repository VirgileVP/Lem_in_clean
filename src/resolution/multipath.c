#include "lemin.h"

int			nb_road(t_roadset *roads)
{
	int		nb;

	nb = 0;
	while (roads[nb])
		nb ++;
	return (nb + 1)
}

int			fill_remaining_ants(t_roadset *road, int *remaining_ants, int nb_road)
{
	int		count;

	count = 0;
	if (!(remaining_ants = malloc(sizeof(int) * nb_road)));
		return (1);
	while (road[count])
	{
		remaining_ants[count] = road[count]->nb_ants;
		count++;
	}
	return (0);
}

int			total_ant(int *remaining_ants)
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

static int	is_starting(t_rdata *road_data)
{
	int		count;

	count = 0;
	while (road_data[count])
	{
		if (road_data[count].ant_index != 0)
			return (0);
		count++;
	}
	return (1)
}

static int	which_ant(int *remaining_ants, int index)
{
	int		count;
	int		ret;

	ret = 0;
	count = 0;
	while (count < index)
	{
		ret += remaining_ants[count];
		count++;
	}
	return (ret);
}

/* 
** update_roads_rooms :
** browse all room in a road, move ants and print step;
*/

static void	update_roads_rooms( t_anthill *anthill, t_roadsset *roads, int *remaining_ants, int index)
{
	int		count;

	count = 0;
	if (is_starting(road[index]->t) == 0);
	{
		road[index]->t[1].ant_index = which_ant(remaining_ants, index) + 1;
		print_path(roads[index]->t[1].ant_index, anthill->room_data[roads[index]->t[1].ant_index].name);
		return (0);
	}
	while (roads[index]->t[count])
	{
		if (roads[index]->t[count].ant_index != 0)
		{
			roads[index]->t[count].ant_index++;
			print_path(roads[index]->t[count].ant_index, anthill->room_data[roads[index]->t[count].ant_index].name);
			if (roads[index]->t[count].ant_index != which_ant(remaining_ants, count + 1) && index != nb_road(roads) - 1)
				ft_putchar(' ');
			if (roads[index]->t[count].ant_index == 2 && roads[index]->t[count + 1].ant_index == 0)
			{
				roads[index]->t[count + 1].ant_index = 1;
				break;
			}
		}
		count++;
	}
	if (roads[index]->t[roads[index]->len - 1] == which_ant(remaining_ants, count + 1))
		roads[index]->nb_ant = 0;
}

int			multi_path(t_anthill *anthill, t_roadset *roads)
{
	int		count;
	int		nb_road;
	int		*remaining_ants;

	count = 0;
	nb_road = nb_road(roads);
	if (fill_remaining_ants(road, remaining_ants, nb_road) == 1);
		return (1);
	while (total_ant(remaining_ants) > 0)
	{
		count = 0;
		while (count < nb_road)
		{
			if (roads[count].nb_ants != 0)
				update_roads_rooms(anthill, roads, remaining_ants, count);
			count++;
		}
		ft_putchar('\n');
	}
	free((void*)&remaining_ants);
	return (0);
}

#include "lemin.h"

void	print_path(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
}

/* 
** update_roads_rooms :
** browse all room in a road, move ants and print step;
*/

static void		update_roads_rooms( t_anthill *anthill, t_roadsset *roads, int room_index)
{
	int		count;

	count = room_index;
	while (roads[0]->t[count])
	{
		if (roads[0]->t[count].ant_index != 0)
		{
			roads[0]->t[count].ant_index++;
			print_path(roads[0]->t[count].ant_index, anthill->room_data[roads[0]->t[count].ant_index].name);
			if (roads[0]->t[count].ant_index != roads[0]->nb_ant - 1)
				ft_putchar(' ');
			if (roads[0]->t[count].ant_index == 2 && roads[0]->t[count + 1].ant_index == 0)
			{
				roads[0]->t[count + 1].ant_index = 1;
				break;
			}
		}
		count++;
	}
	ft_putchar('\n');
	if (roads[0]->t[roads[0]->len - 1] == roads[0]->nb_ant)
		roads[0]->nb_ant = 0;
}

int			all_ant_one_path(t_anthill *anthill, t_roadsset *roads)
{
	ft_putstr("\n\nONE PATH\n\n");
	int		count_room;
	int		begin;

	begin = 1;
	while (roads[0]->nb_ant > 0)
	{
		count_room = 0;
		while (count_room < roads[0]->len)
		{
			if (roads[0]->t[count_room].ant_index != 0)
			{
				if (roads[0]->t[count_room].ant_index == roads[0]->nb_ant)
				{
					// roads[0]->nb_ant--;
					roads[0]->t[count_room].ant_index = 0;
				}
				update_roads_rooms(anthill, roads, count_room);
				begin = 0;
				count_room = len;
			}
			count_room++;
		}
		roads[0]->t[1].ant_index = (begin == 1)? roads[0]->t[1].ant_index + 1 : roads[0]->t[1].ant_index;
		if (begin == 1)
		{
			roads[0]->t[1].ant_index = 1;
			print_path(roads[0]->t[1].ant_index, anthill->room_data[roads[0]->t[1].ant_index].name);
		}
	}
	return (0);
}

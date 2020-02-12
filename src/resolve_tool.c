#include "lemin.h"

void	print_path(int ant, char *room)
{
	int	count;

	count = 0;
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	while(room[count] != ' ')
		count++;
	write(1, room, count);
}

/*
** how_much_road :
** calcul nb of road in the roadset
*/

int		how_much_road(t_roadset *roads)
{
	int		nb;

	nb = 0;
	while (roads[nb].t)
		nb++;
	//printf("\nRoadset contain %d roads\n", nb);
	return (nb + 1);
}

/*
** which_resolution :
** select multipath or unipath
*/

int		which_resolution(t_anthill *anthill, t_roadset *roads)
{
	if (how_much_road(roads) > 1)
	{
		if (multi_path(anthill, roads) == -1)
			return (-1);
	}
	else
	{
		if (all_ant_one_path(anthill, roads) == -1)
			return (-1);
	}
	return (0);
}
#include "lemin.h"

void	print_path(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
}

/*
** how_much_road :
** calcul nb of road in the roadset
*/

int		how_much_road(t_roadset *roads)
{
	int		nb;

	nb = 0;
	//printf("|%d|\n", roads[nb].t[0].n);
	while (roads[nb].t)
		nb++;
	//printf("\nhow_much_road = %d\n", nb);
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
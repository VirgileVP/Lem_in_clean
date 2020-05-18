/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveyrat- <vveyrat-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:42:26 by vveyrat-          #+#    #+#             */
/*   Updated: 2020/03/10 11:42:28 by vveyrat-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "resolve_print.h"
#include "print.h"

void	print_path(int ant, char *room)
{
	int	count;

	count = 0;
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	while (room[count] != ' ')
	{
		ft_putchar(room[count]);
		count++;
	}
}

int		empty_road(t_roadset *roads, int road_index)
{
	size_t	count;

	count = 0;
	while (count < roads[road_index].len)
	{
		if (roads[road_index].t[count].ant_index != 0)
			return (0);
		count++;
	}
	return (1);
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
	return (nb);
}

/*
** which_resolution :
** select multipath or unipath
*/

int		which_resolution(t_anthill *anthill, t_roadset *roads)
{
	int	nb_road;

	nb_road = how_much_road(roads);
	if (nb_road > 1)
	{
		if (multi_path(anthill, roads) == -1)
			return (-1);
	}
	else if (all_ant_one_path(anthill, roads) == -1)
		return (-1);
	return (0);
}

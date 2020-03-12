/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveyrat- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:41:16 by vveyrat-          #+#    #+#             */
/*   Updated: 2020/03/10 11:41:20 by vveyrat-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

int		empty_road(t_roadset *roads, int road_index)
{
	int	count;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveyrat- <vveyrat-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:42:26 by vveyrat-          #+#    #+#             */
/*   Updated: 2020/03/10 11:42:28 by vveyrat-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "check_error.h"
#include "misc.h"

/*
** first_line:
**
** By-pass comments and no-valid instructions
** Check if the first line is the ants number
*/

int						first_line(char **room, t_read_room *pars)
{
	int					index;

	index = 0;
	while (room[index] && room[index][0] == '#'
	&& (ft_strcmp(room[index], "##start") != 0
	&& ft_strcmp(room[index], "##end") != 0))
		index++;
	if (room[index][0] == ' ' || room[index][0] == 'L')
		return (-1);
	if (ft_is_strdigit(room[index]) != 1)
		return (-1);
	pars->decla_nb_ant = 1;
	index++;
	return (index);
}

/*
** check_command:
**
** check is start or end definitions are correct
*/

void					check_command(t_read_room *pars,
int index, t_check_bad_order *order)
{
	if (order->start == 0 && pars->room[index][2] == 's'
	&& pars->room[index][7] == '\0')
		order->start = 1;
	if (order->end == 0 && pars->room[index][2] == 'e'
	&& pars->room[index][5] == '\0')
		order->end = 1;
}

/*
** check_sharp:
**
** check lines begining with sharp
*/

int						check_sharp(t_read_room *pars,
int index, t_check_bad_order *order)
{
	if (ft_strcmp(pars->room[index], "##start") == 0 ||
	ft_strcmp(pars->room[index], "##end") == 0)
	{
		if ((ft_strcmp(pars->room[index], "##start") == 0 && order->start == 1)
		|| (ft_strcmp(pars->room[index], "##end") == 0 && order->end == 1)
		|| ft_strcmp(pars->room[index + 1], "##start") == 0
		|| ft_strcmp(pars->room[index + 1], "##end") == 0)
			return (-1);
		check_command(pars, index, order);
		if (pars->room[++index][0] != '#')
		{
			if (nmatch(pars->room[index], "* * *") == 1)
			{
				if (check_room(pars->room[index], order->tube_pars) == -1)
					return (-1);
				pars->nb_room++;
			}
			else
				return (-1);
		}
	}
	return (0);
}

/*
** check_error:
**
** check if errors are present in the file
*/

int						check_error(t_read_room *pars)
{
	t_check_bad_order	order;
	int					index;

	order.tube_pars = 0;
	order.start = 0;
	order.end = 0;
	index = first_line(pars->room, pars);
	if (index == -1)
		return (-1);
	while (index < pars->nb_line)
	{
		if (ft_is_strdigit(pars->room[index]) == 1 && pars->decla_nb_ant == 1)
			return (-1);
		if (ft_isspace(pars->room[index][0]) == 1 || pars->room[index][0] == 'L')
			return (-1);
		if (pars->room[index][0] == '#'
		&& check_sharp(pars, index, &order) == -1)
			return (-1);
		else if (ft_stroccurence(pars->room[index], '-') > 1
		|| check_definition(pars, &order, index) == -1)
			return (-1);
		index++;
	}
	if (order.start == 0 || order.end == 0)
		return (-1);
	return (0);
}

/*
** read_error:
**
** Read the file and check if errors are presents
** Stock lines in string and split it in pars->room
*/

int						read_error(t_read_room *pars)
{
	char				*temp;
	char				*line;
	int					ret;

	if (!(temp = ft_strnew(0)))
		return (-1);
	ret = 0;
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isspace(line[0]) == 0 && line[0] != '\n' && line[0] != 0)
		{
			ret = (ft_strcmp(line, "\0") == 0) ? 0 : 1;
			temp = ft_strjoin(temp, line);
			temp = ft_strjoin(temp, "\n");
			pars->nb_line++;
		}
		ft_strdel(&line);		
	}
	if (ret == 0)
		return (-1);
	if (!(pars->room = ft_strsplit(temp, '\n')) || check_error(pars) == -1)
		return (-1);
	ft_strdel(&temp);
	return (1);
}

#include "lem_in.h"
#include "check_error.h"

/*
** check_spaces:
**
** Return count of space in a string
*/

int			check_space(char *line)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	while (line[index])
	{
		if (line[index] == ' ')
			count++;
		index++;
	}
	return (count);
}

/*
** check_room:
**
** Check if a room definition is valid
*/

int			check_room(char *line, int tube_pars)
{
	int		count;
	char	**split;

	count = 0;
	if (check_space(line) != 2 && ft_count_words(line, ' ') != 3 && tube_pars == 0)
		return (-1);
	if (!(split = ft_strsplit(line, ' ')))
		return (-1);
	while (split[count])
		count++;
	if (count != 3)
		return (-1);
	if (ft_is_strdigit(split[1]) != 1 || ft_is_strdigit(split[2]) != 1)
		return (-1);
	free(split);
	return (1);
}

/*
** check_tubes:
**
** Check if a tube definition is valid
*/

int			check_tubes(char *line)
{
	int		index;

	index = 0;
	while (line[index] && line[index] != '-')
	{
		if (ft_isspace(line[index]))
			return (-1);
		index++;
	}
	if (line[index] != '-')
		return (-1);
	index++;
	while (line[index])
	{
		if (ft_isspace(line[index]))
			return (-1);
		index++;
	}
	return (1);
}

/*
** first_line:
**
** By-pass comments and no-valid instructions
** Check if the first line is the ants number
*/

int		first_line(char **room)
{
	int	index;

	index = 0;
	while (room[index] && room[index][0] == '#' && (ft_strcmp(room[index], "##start") != 0
	&& ft_strcmp(room[index], "##end") != 0))
		index++;
	if (room[index][0] == ' ' || room[index][0] == 'L')
		return (-1);
	if (ft_is_strdigit(room[index]) != 1)
		return (-1);
	index++;
	return (index);
}

/*
** check_sharp:
**
** check lines begining with sharp
*/

int		check_sharp(char **room, int index, t_check_bad_order *order)
{
	if (ft_strcmp(pars->room[index], "##start") == 0 || ft_strcmp(pars->room[index], "##end") == 0)
	{
		if ((ft_strcmp(pars->room[index], "##start") == 0 &&
		order->start == 1) || (ft_strcmp(pars->room[index], "##end") == 0 &&
		order->end == 1) || ft_strcmp(pars->room[index + 1], "##start") == 0 ||
		ft_strcmp(pars->room[index + 1], "##end") == 0)
			return (-1);
		order->start = (ft_strcmp(pars->room[index], "##start") == 0) ? 1 : 0;
		order->end = (ft_strcmp(pars->room[index], "##end") == 0) ? 1 : 0;
		index++;
		if (pars->room[index][0] != '#')
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
}

/*
** check_definition:
**
** run check_room and check_tubes
*/

int		check_definition(t_read_room *pars, t_check_bad_order *order, int index)
{
	if (nmatch(pars->room[index], "* * *") == 1)
	{
		if (check_room(pars->room[index], order->tube_pars) == -1)
			return (-1);
		pars->nb_room++;
	}
	else if (nmatch(pars->room[index], "*-*") == 1)
	{
		if (check_tubes(pars->room[index]) == -1)
			return (-1);
	}
}

/*
** check_error:
**
** check if errors are present in the file
*/

int		check_error(t_read_room *pars)
{
	t_check_bad_order	*order;
	int					index;

	if (!(ft_bzero(&order, sizeof(t_check_bad_order))))
		return (-1);
	order->tube_pars = 0;
	order->start = 0;
	order->end = 0;
	index = first_line(pars->room);
	if (index == -1)
		return (-1);
	while (pars->room[index])
	{
		if (pars->room[index][0] == ' ' || pars->room[index][0] == 'L')
			return (-1);
		if (pars->room[index][0] == '#')
			if (check_sharp(pars->room, index, order) == -1)
				return (-1);
		else if (check_definition(pars, order, index) == -1)
			return (-1);
		else
			return (-1);
		index++;
	}
	if (order->start == 0 || order->end == 0)
		return (-1);
	return (0);
}

/*
** read_line:
**
** get a line and put it in "char **line"
*/

int			read_line(int fd, char **line)
{
	int		ret;
	char	buff[2];
	char	*temp;
	char	*cpy;

	if (!(cpy = ft_strnew(0)))
		return (-1);
	while ((ret = read(fd, buff, 1)) > 0)	
	{
		buff[1] = 0;
		if (!ft_strcmp(buff, "\n"))
		{
			temp = cpy;
			if (!(cpy = ft_strjoin(cpy, buff)))
				return (-1);
			ft_strdel(&temp);
			break ;
		}
		temp = cpy;
		if (!(cpy = ft_strjoin(cpy, buff)))
			return (-1);
		ft_strdel(&temp);
	}
	if (!(*line = ft_strdup(cpy)))
		return (-1);
	ft_strdel(&cpy);
	return (ret);
}

/*
** read_error:
**
** Read the file and check if errors are presents
** Stock lines in string and split it in pars->room
*/

int			read_error(t_read_room *pars)
{
	char	*temp;
	char	*line;

	if (!(temp = ft_strnew(0)))
		return (-1);
	line = NULL;
	while (read_line(0, &line) > 0)
	{
		if (line[0] == '#')
		{
			if (ft_strcmp(line, "##start\n") == 0 || ft_strcmp(line, "##end\n") == 0)
				if (!(temp = ft_strjoin(temp, line))
					return (-1);
		}
		else
			if (!(temp = ft_strjoin(temp, line))
				return (-1);
		ft_strdel(&line);
	}
	if (!(pars->room = ft_strsplit(temp, '\n')))
		return (-1);
	if (check_error(pars) == -1)
		return (-1);
	return (0);
}

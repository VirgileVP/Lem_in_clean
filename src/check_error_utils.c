#include "lemin.h"
#include "check_error.h"

int		    free_temp_line(char *temp, char * line, int ret)
{
	ft_strdel(&temp);
	ft_strdel(&line);
	return (ret);
}

/*
** count_space:
**
** Return count of space in a string
*/

int			count_space(char *line)
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
** check_definition:
**
** run check_room and check_tubes
*/

int		    check_definition
(t_read_room *pars, t_check_bad_order *order, int index)
{
	if (nmatch(pars->room[index], "* * *") == 1)
	{
		if (check_room(pars->room[index], order->tube_pars) == -1)
			return (-1);
		pars->nb_room++;
	}
	else if (nmatch(pars->room[index], "*-*") == 1
    && check_tubes(pars->room[index]) == -1)
		return (-1);
	return (0);
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
	if (count_space(line) != 2 && ft_count_words(line, ' ') != 3
    && tube_pars == 0)
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
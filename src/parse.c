/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:02:10 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 14:49:20 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parse.h"
#include "lem_in.h"

static void			tabtok(char **entry)
{
	size_t				y;
	size_t				x;

	y = 0;
	while (entry[y] != NULL)
	{
		x = 0;
		while (entry[y][x] != '\0')
		{
			if (entry[y][x] == ' ' || entry[y][x] == '-')
				entry[y][x] = -1;
			x += 1;
		}
		y += 1;
	}
}

static char			*ntoken(char *chain, size_t n)
{
	char				*p;

	p = chain;
	if (p == NULL || *p == '\0')
		return (NULL);
	while (n > 0)
	{
		p = ft_strchr(p, -1);
		if (p == NULL)
			return (NULL);
		p += 1;
		n -= 1;
	}
	return (p);
}

static enum flags	parse_room(char *entry,
		t_anthill *ah,
		t_room *rdata,
		int **matrix __attribute__ ((unused)))
{
	static int			flag = 0;
	static int			prev = 0;
	int					i;

	i = 0;
	if (entry[0] == '#')
	{
		if (entry[2] == 's')
			flag = START;
		else if (entry[2] == 'e')
			flag = END;
		return (PROCEED);
	}
	if (flag == 0)
		i = prev + 1;
	else if (flag == START)
		i = 0;
	else if (flag == END)
		i = 1;
	flag = 0;
	if (!(rdata[i].name = ft_strdup(ntoken(entry, 0))))
		return (MALLOC_ERROR);
	rdata[i].x = ft_atoi(ntoken(entry, 1));
	rdata[i].y = ft_atoi(ntoken(entry, 2));
	return (room_dup(rdata, i, ah));
}

static enum flags		parse_tunnel(char *entry,
		t_anthill *ah,
		t_room *rdata,
		int **matrix)
{
	int					x;
	int					y;

	if ((x = room_seek(ntoken(entry, 0), rdata)) == -1 ||
			(y = room_seek(ntoken(entry, 1), rdata)) == -1)
		return (STOP);
	matrix[x][y] = 0;
	matrix[y][x] = 0;
	return (PROCEED);
}

enum flags				(*const parse_fct[])(char *, t_anthill *, t_room *, int **) = {
	&parse_room,
	&parse_tunnel
};

int						parse(char **entry, t_anthill *ah, t_room *rdata, int **matrix)
{
	enum status 			status;
	enum flags				ret;
	int						i;

	status = ROOM;
	i = 0;
	tabtok(entry);
	while ((ret = parse_fct[status](entry[i], ah, rdata, matrix)) == PROCEED)
	{
		i += 1;
		if (ret == MALLOC_ERROR || ret == DUP_ERROR)
			return (-1);
		if (status == ROOM && ntoken(entry[i], 2) == NULL)
			status = TUNNEL;
	}
	return (1);
}

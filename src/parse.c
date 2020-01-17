/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:02:10 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 10:03:56 by zseignon    ###    #+. /#+    ###.fr     */
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
	i = prev + 1;
	if (!(rdata[i].name = ft_strdup(ntoken(entry, 0))))
		return (MALLOC_ERROR);
	rdata[i].x = ft_atoi(ntoken(entry, 1));
	rdata[i].y = ft_atoi(ntoken(entry, 2));
	if (flag != 0)
	{
		if (flag == START)
			ah->start = i;
		else if (flag == END)
			ah->end = i;
		flag = 0;
	}
	return (room_dup(rdata, i));
}

static enum flags		parse_tunnel(char *entry,
		t_anthill *ah,
		t_room *rdata,
		t_ul **matrix)
{
	int					x;
	int					xn;
	int					y;
	int					yn;
	t_ul				cccc;

	if ((x = room_seek(ntoken(entry, 0), rdata, ah)) == -1 ||
			(y = room_seek(ntoken(entry, 1), rdata, ah)) == -1)
		return (STOP);
	cccc = BZERO >> (x % (sizeof(t_ul) * 8));
	xn = x / (sizeof(t_ul) * 8);
	yn = y / (sizeof(t_ul) * 8);
	matrix[y][xn] |= cccc;
	cccc = BZERO >> (y % (sizeof(t_ul) * 8));
	matrix[x][yn] |= cccc; 
	return (PROCEED);
}

enum flags				(*const parse_fct[])(char *, t_anthill *, t_room *, int **) = {
	&parse_room,
	&parse_tunnel
};

int						parse(char **entry, t_anthill *ah, t_room *rdata)
{
	enum status 			status;
	enum flags				ret;
	int						i;

	status = ROOM;
	i = 0;
	tabtok(entry);
	while ((ret = parse_fct[status](entry[i], ah, rdata, ah->matrix)) != STOP)
	{
		i += 1;
		if (ret == MALLOC_ERROR || ret == DUP_ERROR)
			return (-1);
		if (status == ROOM && ntoken(entry[i], 2) == NULL)
			status = TUNNEL;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:14:47 by zseignon          #+#    #+#             */
/*   Updated: 2020/05/01 17:14:24 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

const char			g_white_space[256] = {
	1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0
};

static void			parse_tok(char **entry, t_prs *prs, size_t y)
{
	size_t			x;

	x = 0;
	prs->n = 0;
	while (entry[y][x] != '\0' && prs->n < 3)
	{
		if (g_white_space[(int)entry[y][x]] == 0)
		{
			prs->p[prs->n] = &entry[y][x];
			prs->len[prs->n] = 0;
			while (g_white_space[(int)entry[y][x]] == 0)
			{
				prs->len[prs->n] += 1;
				x += 1;
			}
			prs->n += 1;
		}
		else
			x += 1;
	}
}

static void			connect_set(t_anthill *ah, int n1, int n2)
{
	t_node			*node;
	t_connect		connect;

	connect.state = CONNECT_POSITIVE;
	node = (t_node *)vect(&ah->farm, n1);
	connect.dst = n2;
	vect_add(&node->connect, &connect);
	node = (t_node *)vect(&ah->farm, n2);
	connect.dst = n1;
	vect_add(&node->connect, &connect);
}

static enum e_flag	parse_tunnel(t_anthill *ah, char **entry, size_t y,
		t_prs *prs)
{
	int				i;
	int				j;

	if (prs->p[0][0] == '#')
	{
		if (entry[y] == NULL)
			return (STOP);
		parse_tok(entry, prs, y);
		return (TUNNEL);
	}
	if ((i = rseek(ah, ah->room_data, prs->p[0])) < 0 ||
			(j = rseek(ah, ah->room_data, prs->p[1])) < 0)
		return (STOP);
	if ((i == ah->start && j == ah->end) ||
			(i == ah->end && j == ah->start))
		return (START_END_CONNECTED);
	connect_set(ah, i, j);
	if (entry[y] == NULL)
		return (STOP);
	parse_tok(entry, prs, y);
	if (prs->n == 2)
		return (TUNNEL);
	else
		return (STOP);
}

static enum e_flag	parse_room(t_anthill *ah, char **entry, size_t y,
		t_prs *prs)
{
	static size_t	n = 0;

	if (entry[y][0] == '#')
	{
		if (ft_strcmp(entry[y], "##start") == 0)
			ah->start = n;
		else if (ft_strcmp(entry[y], "##end") == 0)
			ah->end = n;
	}
	else
	{
		parse_tok(entry, prs, y);
		if (prs->n == 2 && (ah->start == -1 || ah->end == -1))
			return (START_END_UNDEFINIED);
		else if (prs->n == 2)
			return (TUNNEL);
		ah->room_data[n].name = prs->p[0];
		ah->room_data[n].x = ft_atoi(prs->p[1]);
		ah->room_data[n].y = ft_atoi(prs->p[2]);
		if (rdup_check(ah->room_data, n) == DUPLICATE)
			return (DUPLICATE);
		n += 1;
	}
	return (ROOM);
}

enum e_flag		(*const parse_fct[])(t_anthill *, char **, size_t, t_prs *) = {
	&parse_room,
	&parse_tunnel
};

int					parse_map(t_anthill *ah, char **entry)
{
	enum e_flag		ret;
	t_prs			prs;
	size_t			y;

	ret = ROOM;
	y = 0;
	while (ret >= ROOM && ret <= TUNNEL)
	{
		ret = parse_fct[ret](ah, entry, y, &prs);
		y += 1;
	}
	if (ret < STOP)
		return (-1);
	else if (ret == START_END_CONNECTED)
		return (2);
	return (1);
}

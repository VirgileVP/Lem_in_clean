/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 09:38:06 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 13:20:47 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parse.h"

const char			g_white_space[256] = {
	1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
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
		if (g_white_space[entry[y][x]] == 0)
		{
			prs->p[prs->n] = &entry[y][x];
			prs->len[prs->n] = 0;
			while (g_white_space[entry[y][x]] == 0)
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

static enum e_flag	parse_tunnel(t_anthill *ah, char **entry, size_t y,
		t_prs *prs)
{
	size_t			x;
	size_t			y;

	if ((x = rseek(ah->rdata, prs->p[0])) < 0 ||
			(y = rseek(ah->rdata, prs->p[1])) < 0)
		return (STOP);
	if ((x == ah->start && y == ah->end) ||
			(x == ah->end && y == ah->start))
		return (START_END_CONNECTED);
	ah->matrix[x][y / 64] |= BINIT >> (y % 64);
	ah->matrix[y][x / 64] |= BINIT >> (x % 64);
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
		ah->rdata[n].name = prs->p[0];
		ah->rdata[n].x = ft_atoi(prs->p[1]);
		ah->rdata[n].y = ft_atoi(prs->p[2]);
		if (rdup_check(ah->rdata, n) == DUPLICATE)
			return (DUPLICATE);
		n += 1;
	}
	return (ROOM);
}

int					parse_map(t_anthill *ah, char **entry)
{
	enum e_flag		ret;
	t_prs			*prs;
	size_t			y;

	ret = ROOM;
	y = 0;
	while (ret >= ROOM && ret <= TUNNEL)
	{
		ret = parse_fct[ret](ah, entry, y, &prs);
		y += 1;
	}
	if (ret < STOP)
		return (ret);
}

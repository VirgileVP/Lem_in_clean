/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:26:43 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 12:40:49 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int		namecmp(const char *s1, const char *s2)
{
	size_t			ss1;
	size_t			ss2;

	ss1 = (size_t)((t_ul)ft_strchr(s1, ' ') - (t_ul)s1);
	ss2 = (size_t)((t_ul)ft_strchr(s2, ' ') - (t_ul)s2);
	if (ss1 == ss2)
		return (ft_memcmp(s1, s2, ss1));
	else
		return (-1);
}

static int		tunnelcmp(const char *s1, const char *s2)
{
	size_t			ss1;
	size_t			ss2;

	ss1 = 0;
	ss2 = 0;
	while (g_white_space[(int)s1[ss1]] == 0)
		ss1 += 1;
	while (g_white_space[(int)s2[ss2]] == 0)
		ss2 += 1;
	if (ss1 == ss2)
		return (ft_memcmp(s1, s2, ss1));
	else
		return (-1);
}

int				rseek(t_anthill *ah, t_room *rdata, char *p)
{
	size_t			n;

	n = 0;
	while (n < (size_t)ah->nb_room)
	{
		if (tunnelcmp(rdata[n].name, p) == 0)
			return ((int)n);
		n += 1;
	}
	return (-1);
}

enum e_flag		rdup_check(t_room *rdata, size_t n)
{
	size_t			y;

	y = 0;
	while (y < n)
	{
		if (namecmp(rdata[y].name, rdata[n].name) == 0 ||
				(rdata[y].x == rdata[n].x && rdata[y].y == rdata[n].y))
			return (DUPLICATE);
		y += 1;
	}
	return (ROOM);
}

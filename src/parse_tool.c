/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_tool.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 09:41:11 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 08:05:39 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parsing.h"

static int		namecmp(const char *s1, const char *s2)
{
	size_t			ss1;
	size_t			ss2;

	ss1 = (size_t)((t_ul)ft_strchr(s1, ' ') -  (t_ul)s1);
	ss2 = (size_t)((t_ul)ft_strchr(s2, ' ') -  (t_ul)s2);
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
	while (g_white_space[s1[ss1]] == 0)
		ss1 += 1;
	while (g_white_space[s2[ss2]] == 0)
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
//	printf("nb_room = %zu\n", ah->nb_room);
	while (n < ah->nb_room)
	{
//		printf("rdata[%zu].name  = %s\n%s\n", n, rdata[n].name, p);
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
//	printf("name[n] = \"%s\" | %d | %d\n", rdata[n].name, rdata[n].x, rdata[n].y);
	while (y < n)
	{
//		printf("name[y] = \"%s\" | %d | %d\n", rdata[y].name, rdata[y].x, rdata[y].y);
		if (namecmp(rdata[y].name, rdata[n].name) == 0 ||
				(rdata[y].x == rdata[n].x && rdata[y].y == rdata[n].y))
			return (DUPLICATE);
		y += 1;
	}
	return (ROOM);
}

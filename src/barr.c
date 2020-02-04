/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   barr.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/31 11:10:04 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 13:11:10 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

int				barr_cmp(t_ul *t1, t_ul *t2, size_t len)
{
	size_t			n;

	n = 0;
	while (n < len)
	{
		if ((t1[n] & t2[n]) != 0)
			return (0);
		n += 1;
	}
	return (1);
}

void			barr_add(t_ul *dst, t_ul *src, size_t len)
{
	size_t			n;

	n = 0;
	while (n < len)
	{
		dst[n] |= src[n];
		n += 1;
	}
}

void			barr_remove(t_ul *dst, t_ul *src, size_t len)
{
	size_t			n;

	n = 0;
	while (n < len)
	{
		dst[n] ^= src[n];
		n += 1;
	}
}

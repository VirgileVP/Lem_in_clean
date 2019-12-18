/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   barr_new.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 11:36:50 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 11:57:02 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

static void		barr_compress(t_barr *b, char *t, size_t len, t_ul cccc)
{
	t_ul			cccc;
	size_t			xn;
	size_t			n;

	xn = 0;
	n = 0;
	while (xn < (*b)->xlen)
	{
		cccc = 0x8000000000000000UL;
		while (cccc != 0 && n < len)
		{
			if (t[n] == 1)
				(*b)->t[xn] |= cccc;
			cccc >>= 1;
			n += 1;
		}
		xn += 1;
	}
}

int				barr_new(t_barr **b, char *t, size_t len)
{
	if ((*b = (t_barr *)malloc(sizeof(t_barr))) == NULL)
		return (-1);
	(*b)->xlen = len / 64;
	if (len % 64 > 0)
		(*b)->xlen += 1;
	if (((*b)->t = (t_ul *)ft_memmalloc(sizeof(t_ul) * (*b)->xlen)) == NULL)
		return (-1);
	barr_compress(*b, t, len);
	return (1);
}

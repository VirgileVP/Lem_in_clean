/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 10:53:03 by zdebugs           #+#    #+#             */
/*   Updated: 2020/03/17 11:44:26 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(void *p1, void *p2)
{
	void		*tmp;

	tmp = p1;
	p1 = p2;
	p2 = tmp;
}

static int	part(
	void *restrict mem,
	int left,
	int right,
	int (*cmp)(const void *, const void *)
	)
{
	int      i;
	int      j;

	i = left;
	j = left;
	while (j < right)
	{
		if (cmp(&((char *)mem)[i], &((char *)mem)[right]) < 0)
		{
			ft_swap(&((char *)mem)[i], &((char *)mem)[j]);
			i++;
		}
		j++;
	}
	ft_swap(&((char *)mem)[i], &((char *)mem)[right]);
	return (i);
}

void		ft_qsort(
	void *restrict mem,
	int left,
	int right,
	int (*cmp)(const void *, const void *)
)
{
	int		mid;

	if (left < right)
	{
		mid = part(mem, left, right, cmp);
		ft_qsort(mem, left, mid - 1, cmp);
		ft_qsort(mem, mid + 1, right, cmp);
	}
}
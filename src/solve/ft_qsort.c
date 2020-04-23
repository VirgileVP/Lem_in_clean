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
#include "way.h"

int			part(t_way *restrict way, int start, int end)
{
	int		i;
	int		j;
	t_way	tmp;

	i = start;
	j = start;
	while (j < end)
	{
		if (way[j].len < way[end].len)
		{
			ft_memcpy(&tmp, &way[i], sizeof(t_way));
			ft_memcpy(&way[i], &way[j], sizeof(t_way));
			ft_memcpy(&way[j], &tmp, sizeof(t_way));
			i++;
		}
		j++;
	}
		ft_memcpy(&tmp, &way[i], sizeof(t_way));
		ft_memcpy(&way[i], &way[end], sizeof(t_way));
		ft_memcpy(&way[end], &tmp, sizeof(t_way));
		return (i);
}

void		ft_qsort(t_way *restrict way, int start, int end)
{
	int			mid;

	if (start < end)
	{
		mid = part(way, start, end);
		ft_qsort(way, start, mid - 1);
		ft_qsort(way, mid + 1, end);
	}
}
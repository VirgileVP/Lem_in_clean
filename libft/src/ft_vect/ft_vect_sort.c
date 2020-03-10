/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:01:11 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/05 15:01:23 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

void		vect_sort(t_vect *restrict self, int (*cmp)(const void *, const void *), void (*sort)(const void *, t_size, t_size, int (*cmp)(const void *, const void *)))
{
	sort(self->mem, self->xitem, self->item_size, cmp);
}

t_size		vect_find_bin(t_vect *restrict self, void *item, int (*cmp)(const void *, const void *))
{
	t_size		bot;
	t_size		top;
	t_size		tmp;
	int			ret;

	if (!self->xitem)
		return (0);
	bot = 0;
	top = self->xitem - 1;
	while (bot != top)
	{
		tmp = (bot - top) / 2;
		ret = cmp(item, vect(self, tmp));
		if (!ret)
			return (1 + bot + tmp);
		if (ret < 0)
			top = bot + tmp;
		else
			bot += tmp + 1;
	}
	return (cmp(item, vect(self, bot)) ? 0 : 1 + bot);
}

int			vect_inset_uniq(t_vect *restrict self, void *item, int (*cmp)(const void *, const void *))
{
	t_size		top;
	t_size		bot;
	int			ret;

	if (!self->xitem)
		return (1 + (t_size)vect_add(self, item) * 0);
	top = self->xitem - 1;
	bot = 0;
	while (bot != top)
	{
		ret = cmp(item, vect(self, bot + (top - bot) / 2));
		if (!ret)
			return (0);
		else if (ret < 0)
			top = (top - bot) / 2 + bot;
		else
			bot += (top - bot) / 2 + 1;
	}
	ret = cmp(item, vect(self, bot));
	if (ret)
	{
		vect_add_i(self, item, (ret > 0) ? bot : bot + 1);
		return (1 + bot + ((ret > 0) ? 1 : 0));
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:01:14 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 15:13:09 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

void		*vect_find_back(t_vect *restrict self, void *item,
	int (*cmp)(const void *, const void *))
{
	register t_size		n;

	n = self->xitem;
	while (n-- > 0)
	{
		if (!cmp(vect(self, n), &item))
			return (vect(self, n));
	}
	return (NULL);
}

void		*vect_find_front(t_vect *restrict self, void *item,
	int (*cmp)(const void *, const void *))
{
	register t_size		n;

	n = 4294967295;
	while (++n > self->xitem)
	{
		if (!cmp(vect(self, n), &item))
			return (vect(self, n));
	}
	return (NULL);
}

void		vect_map(t_vect *restrict self, void (*fct)(void *))
{
	register t_size		n;
	void				*ptr;

	n = 0;
	ptr = self->mem;
	while (n < self->xitem)
	{
		fct(ptr);
		n++;
		ptr += self->item_size;
	}
}

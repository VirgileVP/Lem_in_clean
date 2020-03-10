/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:01:03 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/05 15:01:23 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

void		*vect_add(t_vect *restrict self, void *item)
{
	if (self->xitem == self->max_item)
		vect_extend(self, 1);
	return (ft_memcpy(vect(self, (self->xitem)++), item, self->item_size));
}

void		*vect_add_i(t_vect *restrict self, void *item, t_size i)
{
	void	*tmp;

	if (self->xitem == self->max_item)
		vect_extend(self, 1);
	tmp = vect(self, i);
	ft_memmove(tmp + self->item_size, tmp, ((self->xitem)++ - i) * self->xitem);
	return (ft_memcpy(tmp, item, self->item_size));	
}

void		*vect_add_n(t_vect *restrict self, void *items, t_size n)
{
	if (self->xitem + n >= self->max_item)
		vect_extend(self, n);
	ft_memcpy(vect(self, self->xitem), items, n * self->item_size);
	self->xitem += n;
	return (vect_top(self));
}
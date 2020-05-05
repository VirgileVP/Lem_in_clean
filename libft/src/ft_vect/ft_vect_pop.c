/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:01:09 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/05 15:01:23 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

void		*vect_pop(t_vect *restrict self)
{
	return (vect(self, --(self->xitem)));
}

void		*vect_pop_i(t_vect *restrict self, t_size i)
{
	register void	*ptr;
	char			tmp[self->item_size];

	ptr = vect(self, i);
	ft_memcpy(tmp, ptr, self->item_size);
	ft_memmove(ptr, ptr + self->item_size,
		self->item_size * (self->xitem - i - 1));
	return (ft_memcpy(vect(self, --(self->xitem)), tmp, self->item_size));
}

void		*vect_pop_p(t_vect *restrict self, void *item)
{
	register void	*ptr;
	char			tmp[self->item_size];
	t_size			i;

	i = vect_i(self, item);
	ptr = vect(self, i);
	ft_memcpy(tmp, ptr, self->item_size);
	ft_memmove(ptr, ptr + self->item_size,
		self->item_size * (self->xitem - i - 1));
	return (ft_memcpy(vect(self, --(self->xitem)), tmp, self->item_size));
}

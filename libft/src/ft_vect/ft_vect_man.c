/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:00:09 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 09:38:03 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

void		vect_init(t_vect *restrict self, t_size item_size, t_size init_len)
{
	if (!self || !item_size || !init_len)
		ft_error_free_exit(ERR_VECT_MSG, MEMERR_CODE);
	self->mem = ft_malloc(item_size * init_len);
	self->item_size = item_size;
	self->xitem = 0;
	self->max_item = init_len;
}

void		vect_del(t_vect *restrict self)
{
	ft_free(self);
	ft_bzero(self, sizeof(t_vect));
}

void		vect_clean(t_vect *self)
{
	ft_bzero(self->mem, self->item_size * self->xitem);
	self->xitem = 0;
}

void		vect_extend(t_vect *restrict self, t_size n)
{
	t_size		old_size;

	old_size = self->max_item;
	while (self->xitem + n > self->max_item)
	{
		self->max_item <<= 1;
	}
	self->mem = ft_re_alloc_n(self->mem, old_size * self->item_size, self->max_item * self->item_size);
}

void		vect_shrink(t_vect *restrict self, t_size reserve)
{
	self->mem = ft_re_alloc_n(self->mem, self->item_size * self->max_item, (self->xitem + reserve) * self->item_size);
	self->max_item = (self->xitem + reserve);
}
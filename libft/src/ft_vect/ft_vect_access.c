/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:01:01 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/05 15:01:23 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

void		*vect(t_vect *restrict self, t_size i)
{
	return(self->mem + (self->item_size * i));
}

t_size		vect_i(t_vect *restrict self, void *item)
{
	return ((item - self->mem) / self->item_size);
}

void		*vect_top(t_vect *restrict self)
{
	return (self->mem + (((self->xitem - 1) * self->item_size)));
}
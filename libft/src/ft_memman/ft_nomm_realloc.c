/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nomm_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:37:03 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 14:44:29 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memman.h"
#include "libc.h"
#include <stdlib.h>

void		*ft_nomm_realloc(void *ptr, t_size oldsize, t_size newsize)
{
	void *newptr;

	if (newsize == oldsize)
		return (ptr);
	if (!(newptr = malloc(newsize)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(newptr, ptr, (oldsize < newsize) ? oldsize : newsize);
		free(ptr);
	}
	return (newptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:00:14 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 09:29:02 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memman.h"
#include "libft.h"

void		*ft_malloc(t_size size)
{
	return (ft_memman_malloc(size));
}

void		*ft_realloc(void *restrict ptr, t_size size)
{
	return (ft_memman_realloc(ptr, size));
}

void		*ft_re_alloc(void *restrict ptr, t_size size)
{
	void	*tmp;

	if (!(tmp = malloc(size)))
		ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	ft_memcpy(tmp, ptr, size);
	free(ptr);
	return (tmp);
}

void		*ft_re_alloc_n(void *restrict ptr, t_size oldsize, t_size newsize)
{
	void	*tmp;

	if (!(tmp = malloc(newsize)))
		ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	ft_memcpy(tmp, ptr, oldsize < newsize ? oldsize : newsize);
	free(ptr);
	return (tmp);
}

void		ft_free(void *restrict ptr)
{
	ft_memman_free(ptr);
}
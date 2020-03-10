/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:00:11 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 09:36:58 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memman.h"
#include "libft.h"

static t_vect		g_mem_manager;

void		ft_memman_init(void)
{
	if (!(g_mem_manager.mem = malloc(MM_INIT_SIZE * sizeof(void *))))
		ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	g_mem_manager.item_size = sizeof(void *);
	g_mem_manager.max_item = MM_INIT_SIZE;
	g_mem_manager.xitem = 0;
}

void		*ft_memman_malloc(t_size size)
{
	void	*tmp;
	t_size	oldsize;

	if (g_mem_manager.xitem == g_mem_manager.max_item)
	{
		oldsize = g_mem_manager.max_item;
		g_mem_manager.max_item += g_mem_manager.max_item < MM_MAX_INDENT ? g_mem_manager.max_item : MM_MAX_INDENT;
		if (!(g_mem_manager.mem = ft_re_alloc_n(g_mem_manager.mem, oldsize * PTR_SIZE, g_mem_manager.max_item * PTR_SIZE)))
			ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	}
	if (!(tmp = malloc(size)))
		ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	vect_add(&g_mem_manager, &tmp);
	return (tmp);
}

void		*ft_memman_realloc(void *ptr, t_size size)
{
	void	*tmp;

	if ((tmp = vect_find_back(&g_mem_manager, ptr, ft_pcmp)))
		vect_pop_p(&g_mem_manager, ptr);
	if (!(tmp = ft_re_alloc(ptr, size)))
	{
		ft_memdel(&ptr);
		ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
	}
	vect_add(&g_mem_manager, tmp);
	return (tmp);
}

void		ft_memman_free(void *restrict ptr)
{
	void	*tmp;

	if (!(tmp = vect_find_back(&g_mem_manager, ptr, ft_pcmp)))
	{
		ft_error_print(ERR_MEMFREE_MSG);
		return ;
	}
	(tmp == vect_top(&g_mem_manager)) ? vect_pop(&g_mem_manager) : vect_pop_p(&g_mem_manager, tmp);
	free(tmp);
	if (g_mem_manager.max_item > MM_INIT_SIZE && g_mem_manager.xitem < (g_mem_manager.max_item >> 1) - MM_MAX_INDENT)
	{
		if (!(tmp = ft_re_alloc_n(g_mem_manager.mem, g_mem_manager.xitem * PTR_SIZE, (g_mem_manager.max_item >> 1) - MM_MAX_INDENT)))
			ft_error_free_exit(ERR_MEMALLOC_MSG, MEMERR_CODE);
		g_mem_manager.mem = tmp;
		g_mem_manager.max_item >>= 1;
	}
}

void		ft_memman_clean(void)
{
	while (g_mem_manager.xitem > 0)
		vect_pop(&g_mem_manager);
	free(g_mem_manager.mem);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memman.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:00:46 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 09:27:26 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMMAN_H
# define FT_MEMMAN_H

# include "typedef.h"

# define MM_INIT_SIZE	128
# define MM_MAX_INDENT	1024

/*
**	ft_memory_manager.c
*/

void			ft_memman_init(void);
void			*ft_memman_malloc(t_size size);
void			*ft_memman_realloc(void *ptr, t_size size);
void			ft_memman_free(void *restrict ptr);
void			ft_memman_clean(void);

/*
**	ft_alloc.c
*/

void			*ft_malloc(t_size size);
void			*ft_realloc(void *restrict ptr, t_size size);
void			*ft_re_alloc(void *restrict ptr, t_size size);
void			*ft_re_alloc_n(void *restrict ptr, t_size oldsize, t_size newsize);
void			ft_free(void *restrict ptr);

#endif
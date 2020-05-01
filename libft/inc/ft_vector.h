/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:59:49 by zseignon          #+#    #+#             */
/*   Updated: 2020/05/01 17:09:58 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "typedef.h"

typedef struct		s_vect
{
	void *restrict	mem;
	t_size			item_size;
	t_size			xitem;
	t_size			max_item;
}					t_vect;

/*
**	ft_vect_man.c
*/

void				vect_init(t_vect *restrict self, t_size item_size,
	t_size init_size);
void				vect_del(t_vect *restrict self);
void				vect_clean(t_vect *self);
void				vect_extend(t_vect *restrict self, t_size n);
void				vect_shrink(t_vect *restrict self, t_size reserve);

/*
**	ft_vect_acces.c
*/

void				*vect(t_vect *restrict self, t_size i);
t_size				vect_i(t_vect *restrict self, void *item);
void				*vect_top(t_vect *restrict self);

/*
**	ft_vect_add.c
*/

void				*vect_add(t_vect *restrict self, void *item);
void				*vect_add_i(t_vect *restrict self, void *item, t_size i);
void				*vect_add_n(t_vect *restrict self, void *item, t_size n);

/*
**	ft_vect_pop.c
*/

void				*vect_pop(t_vect *restrict self);
void				*vect_pop_i(t_vect *restrict self, t_size i);
void				*vect_pop_p(t_vect *restrict self, void *item);

/*
**	ft_vect_utils.c
*/

void				*vect_find_back(t_vect *restrict self, void *item,
	int (*cmp)(const void *, const void *));
void				*vect_find_front(t_vect *restrict self, void *item,
	int (*cmp)(const void *, const void *));
void				vect_map(t_vect *restrict self, void (*fct)(void *));

/*
**	ft_vect_sort.c
*/

void				vect_sort(t_vect *restrict self,
	int (*cmp)(const void *, const void *),
	void (*sort)(const void *, t_size, t_size,
	int (*cmp)(const void *, const void *)));
t_size				vect_find_bin(t_vect *restrict self, void *item,
	int (*cmp)(const void *, const void *));
int					vect_insert_uniq(t_vect *restrict self, void *item,
	int (*cmp)(const void *, const void *));

#endif

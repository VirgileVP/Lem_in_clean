/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:35:40 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 09:39:44 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static t_connect		*iter_next_all(t_iter *restrict iter)
{
	return (iter->n != iter->connect->xitem ?
			vect(iter->connect, (iter->n)++) : NULL);
}

static t_connect		*iter_next_allowed(t_iter *restrict iter)
{
	t_connect		*connect;

	while ((connect = iter_next_all(iter)) && 
			connect->state == CONNECT_FORBIDDEN)
		continue ;
	return (connect);
}

static t_connect		*iter_next_negative(t_iter *restrict iter)
{
	t_connect		*connect;

	while ((connect = iter_next_all(iter)) && 
			connect->state != CONNECT_NEGATIVE)
		continue ;
	return (connect);
}

static t_connect		*iter_next_forbidden(t_iter *restrict iter)
{
	t_connect		*connect;

	while ((connect = iter_next_all(iter)) && 
			connect->state != CONNECT_FORBIDDEN)
		continue ;
	return (connect);
}

static t_connect		*iter_next_positive(t_iter *restrict iter)
{
	t_connect		*connect;

	while ((connect = iter_next_all(iter)) && 
			connect->state != CONNECT_POSITIVE)
		continue ;
	return (connect);
}

static t_connect		*(*g_iter_func[])(t_iter *restrict iter) = {
	iter_next_all,
	iter_next_allowed,
	iter_next_negative,
	iter_next_forbidden,
	iter_next_positive
};

t_connect		*iter_next(t_iter *restrict iter)
{
	return (g_iter_func[iter->fct](iter));
}

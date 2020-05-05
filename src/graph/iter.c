/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:35:40 by zseignon          #+#    #+#             */
/*   Updated: 2020/05/05 11:04:59 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_connect		*iter_next_all(t_iter *restrict iter)
{
	return (iter->n != iter->connect->xitem ?
			vect(iter->connect, (iter->n)++) : NULL);
}

t_connect		*iter_next_allowed(t_iter *restrict iter)
{
	t_connect		*connect;

	while ((connect = iter_next_all(iter)) &&
			connect->state == CONNECT_FORBIDDEN)
		continue ;
	return (connect);
}

t_connect		*iter_next_negative(t_iter *restrict iter)
{
	t_connect		*connect;

	while ((connect = iter_next_all(iter)) &&
			connect->state != CONNECT_NEGATIVE)
		continue ;
	return (connect);
}

t_connect		*iter_next_forbidden(t_iter *restrict iter)
{
	t_connect		*connect;

	while ((connect = iter_next_all(iter)) &&
			connect->state != CONNECT_FORBIDDEN)
		continue ;
	return (connect);
}

t_connect		*iter_next_positive(t_iter *restrict iter)
{
	t_connect		*connect;

	while ((connect = iter_next_all(iter)) &&
			connect->state != CONNECT_POSITIVE)
		continue ;
	return (connect);
}

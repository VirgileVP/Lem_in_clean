/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 11:01:54 by user42            #+#    #+#             */
/*   Updated: 2020/05/05 11:05:34 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static t_connect	*(*g_iter_func[])(t_iter *restrict iter) = {
	iter_next_all,
	iter_next_allowed,
	iter_next_negative,
	iter_next_forbidden,
	iter_next_positive
};

t_connect			*iter_next(t_iter *restrict iter)
{
	return (g_iter_func[iter->fct](iter));
}

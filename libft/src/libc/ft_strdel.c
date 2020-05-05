/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 09:57:12 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:24:55 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "typedef.h"
#include "libc.h"

void	ft_strdel(char **as)
{
	if (!(as))
		return ;
	ft_free(*as);
	*as = NULL;
}

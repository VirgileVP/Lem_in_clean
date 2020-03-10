/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:27:49 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:33:09 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

int		ft_isalnum(int c)
{
	if (ft_isalpha(c) + ft_isdigit(c) != 0)
		return (1);
	return (0);
}

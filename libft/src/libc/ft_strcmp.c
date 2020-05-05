/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:05:51 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:35:43 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	ss1;
	size_t	ss2;

	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	return (ft_memcmp(s1, s2, ss1 <= ss2 ? ss1 : ss2));
}

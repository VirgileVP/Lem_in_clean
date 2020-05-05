/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 12:00:47 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:37:09 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!(s1) || !(s2))
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2) && n != 0)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

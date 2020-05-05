/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 12:15:22 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:37:40 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!(str = ft_strnew(len)) || !(s))
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}

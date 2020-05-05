/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:53:52 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:36:54 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(s1);
	j = 0;
	if (n > i)
	{
		while (s2[j] && n--)
			s1[i++] = s2[j++];
		s1[i] = '\0';
	}
	else
	{
		while (s2[j] && n--)
			s1[i++] = s2[j++];
		while (s1[i])
			s1[i++] = '\0';
	}
	return (s1);
}

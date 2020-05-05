/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:34:33 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:37:43 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	needle_len;

	if (needle[0] == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (1)
	{
		if ((haystack = ft_strchr(haystack, needle[0])) == NULL)
			break ;
		if (needle_len == 1 || ft_memcmp(haystack, needle, needle_len) == 0)
			return ((char*)haystack);
	}
	return (NULL);
}

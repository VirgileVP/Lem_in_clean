/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:34:45 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:35:29 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

char		*ft_strchr(const char *s, int c)
{
	size_t		len;

	len = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[len]);
	return ((char *)ft_memchr(s, c, len));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:50:30 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:25:04 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "typedef.h"
#include "libc.h"

char	*ft_strdup(const char *s1)
{
	char		*ret;
	size_t		len;

	len = ft_strlen(s1);
	if (!(ret = (char *)ft_malloc(sizeof(t_byte) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	return (ft_memcpy(ret, (void *)s1, len));
}

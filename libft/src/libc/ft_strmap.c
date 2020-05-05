/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:14:11 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:36:43 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!(s) || !(*f))
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}

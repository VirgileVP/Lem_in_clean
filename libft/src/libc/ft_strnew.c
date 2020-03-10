/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 09:18:48 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:25:35 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "typedef.h"
#include "libc.h"

char	*ft_strnew(size_t size)
{
	void	*str;

	str = ft_malloc(sizeof(unsigned char) * (size + 1));
	if (!(str))
		return (NULL);
	ft_bzero(str, (size + 1));
	return ((char *)str);
}

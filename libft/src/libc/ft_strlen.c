/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:47:52 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:36:30 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

size_t		ft_strlen(const char *str)
{
	size_t		n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

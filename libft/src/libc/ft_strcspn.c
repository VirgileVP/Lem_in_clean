/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:24:57 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:35:53 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "typedef.h"
#include "libc.h"

size_t			ft_strcspn(const char *s, const char *charset)
{
	char			tab[256];
	size_t			n;

	ft_bzero(tab, 256);
	n = 0;
	while (charset[n] != '\0')
	{
		tab[(int)charset[n]] = 1;
		n += 1;
	}
	n = 0;
	while (s[n] != '\0' && tab[(int)s[n]] == 0)
		n += 1;
	return (n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:19:09 by vveyrat-          #+#    #+#             */
/*   Updated: 2020/05/05 11:51:13 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_count_words(char *s, char c)
{
	size_t	nb;
	size_t	counter;

	nb = 0;
	counter = 0;
	if (!s || !c)
		return (0);
	if (*s != c && *s != '\0')
		nb++;
	while (s[counter] != '\0')
	{
		if (s[counter] == c && s[counter + 1] != c && s[counter + 1] != '\0')
			nb++;
		counter++;
	}
	return (nb);
}

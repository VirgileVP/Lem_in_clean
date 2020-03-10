/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:19:05 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:26:14 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "typedef.h"
#include "libc.h"

static unsigned	int	ft_words_nb(char const *s, char c)
{
	unsigned int		words;
	size_t				i;
	unsigned int		instring;

	words = 0;
	i = 0;
	instring = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && instring == 1)
			instring = 0;
		if (s[i] != c && instring == 0)
		{
			instring = 1;
			words++;
		}
		i++;
	}
	return (words);
}

static size_t		ft_word_size(char const *s, char c, size_t i)
{
	size_t	wsize;

	wsize = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		wsize++;
	}
	return (wsize);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	y;
	unsigned int	words;

	i = 0;
	y = 0;
	if (!(s))
		return (NULL);
	words = ft_words_nb(s, c);
	tab = (char**)ft_malloc(sizeof(char*) * (words + 1));
	if (!(tab))
		return (NULL);
	while (y < words)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		tab[y] = ft_strsub(s, i, ft_word_size(s, c, i));
		while (s[i] != c && s[i] != '\0')
			i++;
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

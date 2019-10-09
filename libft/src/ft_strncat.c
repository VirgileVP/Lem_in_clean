/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:53:52 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 14:51:56 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

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

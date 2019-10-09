/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 13:51:21 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 17:26:43 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			n;
	char			*str;

	i = 0;
	if (!(s))
		return (NULL);
	n = (ft_strlen(s) - 1);
	str = NULL;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if ((i - 1) == n)
	{
		if (!(str = ft_strsub(s, 0, 0)))
			return (NULL);
		return (str);
	}
	while (s[n] == ' ' || s[n] == '\t' || s[n] == '\n')
		n--;
	n++;
	if (!(str = ft_strsub(s, i, (n - i))))
		return (NULL);
	str[n - i] = '\0';
	return (str);
}

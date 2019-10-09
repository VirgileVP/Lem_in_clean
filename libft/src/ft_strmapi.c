/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 11:22:34 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 17:23:51 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}

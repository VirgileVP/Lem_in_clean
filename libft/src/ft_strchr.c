/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 11:34:45 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 08:43:48 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t		len;

	len = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[len]);
	return ((char *)ft_memchr(s, c, len));
}

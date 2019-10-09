/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:42:50 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 13:45:14 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	n = ft_strlen(needle);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack && len-- >= n)
	{
		if (ft_memcmp(haystack, needle, n) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}

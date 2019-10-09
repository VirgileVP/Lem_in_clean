/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 13:34:33 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 10:28:59 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	needle_len;

	if (needle[0] == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (1)
	{
		if ((haystack = ft_strchr(haystack, needle[0])) == NULL)
			break ;
		if (needle_len == 1 || ft_memcmp(haystack, needle, needle_len) == 0)
			return ((char*)haystack);
	}
	return (NULL);
}

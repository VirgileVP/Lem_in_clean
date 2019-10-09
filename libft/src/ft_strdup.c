/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:50:30 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/24 09:14:50 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*ret;
	size_t		len;

	len = ft_strlen(s1);
	if (!(ret = (char *)malloc(sizeof(t_byte) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	return (ft_memcpy(ret, (void *)s1, len));
}

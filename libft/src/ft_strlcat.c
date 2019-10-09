/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 10:10:28 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 10:14:23 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t			dst_len;
	size_t			src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (len <= dst_len)
		return (src_len + len);
	ft_memcpy(&dst[dst_len], src, src_len + 1);
	return (dst_len + src_len);
}

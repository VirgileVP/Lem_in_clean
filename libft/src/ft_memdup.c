/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/24 09:12:29 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/24 09:22:56 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memdup(const void *src, size_t len)
{
	void		*dst;

	if (!(dst = malloc(sizeof(t_byte) * len)))
		return (NULL);
	ft_memcpy(dst, src, len);
	return (dst);
}

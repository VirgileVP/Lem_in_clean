/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 12:58:56 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 13:22:55 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memjoin(const void *p1, size_t len1,
		const void *p2, size_t len2)
{
	t_ul				ret;

	if (!(ret = (t_ul)malloc(sizeof(t_byte) * (len1 + len2))))
		return (NULL);
	ft_memcpy((void *)ret, p1, len1);
	ft_memcpy((void *)(ret + len1), p2, len2);
	return ((void *)ret);
}

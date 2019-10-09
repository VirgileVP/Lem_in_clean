/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 09:09:40 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/05 10:52:45 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t len)
{
	void	*p;

	if (!(p = malloc(sizeof(t_byte) * len)))
		return (NULL);
	ft_bzero(p, len);
	return (p);
}

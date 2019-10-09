/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 09:18:48 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 14:30:47 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void	*str;

	str = malloc(sizeof(unsigned char) * (size + 1));
	if (!(str))
		return (NULL);
	ft_bzero(str, (size + 1));
	return ((char *)str);
}

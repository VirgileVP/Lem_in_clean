/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   data_alloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/13 11:03:15 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 16:28:21 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_data			*ft_data_alloc(size_t len)
{
	t_data			*ret;

	if ((ret = (t_data *)malloc(sizeof(t_data))) == NULL ||
			(ret->data = malloc(sizeof(t_byte) * len)) == NULL)
		return (NULL);
	ret->len = 0;
	return (ret);
}

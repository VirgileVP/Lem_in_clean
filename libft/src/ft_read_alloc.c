/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_alloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/13 11:02:27 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 09:46:51 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_read		*ft_read_alloc(size_t len)
{
	t_read		*ret;

	if ((ret = (t_read *)malloc(sizeof(t_read))) == NULL ||
			(ret->data = ft_data_alloc(len)) == NULL)
		return (NULL);
	ret->next = NULL;
	return (ret);
}

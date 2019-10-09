/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   data_cat.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/13 11:03:47 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 16:27:25 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_data		*ft_data_cat(t_read *begin)
{
	t_data		*ret;
	t_read		*tmp;
	size_t		len;
	void		*p;

	tmp = begin;
	len = 1;
	while (tmp != NULL)
	{
		len += tmp->data->len;
		tmp = tmp->next;
	}
	tmp = begin;
	if ((ret = ft_data_alloc(len)) == NULL)
		return (NULL);
	ret->len = len;
	p = ret->data;
	while (tmp != NULL)
	{
		ft_memcpy(p, tmp->data->data, tmp->data->len);
		p += tmp->data->len;
		tmp = tmp->next;
	}
	((char *)p)[0] = '\0';
	return (ret);
}

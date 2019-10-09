/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_free.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/13 11:05:22 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 12:23:34 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				ft_read_free(t_read **begin)
{
	t_read		*tmp1;
	t_read		*tmp2;

	tmp1 = *begin;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		ft_data_free(&tmp1->data);
		free(tmp1);
		tmp1 = tmp2;
	}
	*begin = NULL;
}

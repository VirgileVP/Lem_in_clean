/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colony_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 14:58:34 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 10:23:56 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "colony.h"

int				colony_init(t_colony **c, t_anthill *ah, size_t n)
{
	t_colony		src;

	if (((*c) = (t_colony *)malloc(sizeof(t_colony))) == NULL)
		return (-1);
	if (n > 0)
	{
		ft_memset(&src, 0, sizeof(t_colony));
		if (ant_spawn(src, ah, n) < 0)
			return (-1);
		while (n-- > 0)
			colony_push(*c, &src);
	}
	else
		ft_memset(*c, 0, sizeof(t_colony));
	return (1);
}

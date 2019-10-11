/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pathfinding.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 14:30:52 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 15:45:27 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "pathfinding.h"

void				calc_dstart(t_cost *tab, int **matrix)
{
	int					*used;
	size_t				pos;

	if (!(used = ft_memalloc(sizeof(int) * len)))
		return (-1);
	pos = 0;

}

t_roadset			*pathfinding(t_anthill *ah, int **matrix)
{
	t_cost				*tab;

	if (!(tab = (t_cost *)malloc(sizeof(t_cost) * ah->nb_room)))
		return (-1);
	ft_bzero(tab, sizeof(t_cost) * ah->nb_room);
	calc_dstart(tab, matrix);
	calc_dend(tab, matrix);
	calc_total(tab);
}i

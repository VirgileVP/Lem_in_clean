/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant_spawn.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:26:41 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 13:55:00 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "colony.h"

int				ant_spawn(t_colony *c, t_anthill *ah, size_t n)
{
	t_colony		tmp;
	t_ant			*new;

	while (n > 0)
	{
		if ((new = (t_ant *)malloc(sizeof(t_ant))) == NULL ||
				(new->used = (char *)ft_memalloc(ah->nb_room)) == NULL ||
				(roadmap_init(new, ah->start)) < 0)
			return (-1);
		new->p = new->begin;
		new->rlen = 1;
		new->next = new;
		new->prev = new;
		tmp.ant = new;
		tmp.len = 1;
		colony_push(c, &tmp);
		n -= 1;
	}
	return (1);
}

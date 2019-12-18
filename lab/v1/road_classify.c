/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   road_classify.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 12:25:26 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 12:33:33 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int				road_classify(t_colony *c, t_rclass *rc, t_anthill *ah)
{
	t_barr			*barr;

	while (c->len > 0)
	{
		if (barr_new(&barr, c->ant->used, ah->nb_room) < 0)
			return (-1);
		while (barr_cmp(barr, rc->matrix) < 0)
		{
			rc = ;
		}

	}
}

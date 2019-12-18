/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tube_count.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 11:23:14 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 12:23:37 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int				tube_count(int room, t_anthill *ah)
{
	size_t			n;
	int				ret;

	n = 0;
	ret = 0;
	while (n < ah->nb_room)
	{
		if (ah->matrix[room][n] == 1 && room != n)
			ret += 1;
		n += 1;
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   room_dup.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 11:36:20 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 08:51:13 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parse.h"

enum flags		room_dup(t_room *rdata, int i)
{
	int				n;

	n = 0;
	while (n < i)
	{
		if (ft_strcmp(rdata[i].name, rdata[n].name) == 0 ||
			rdata[i].x == rdata[n].x ||
			rdata[i].y == rdata[n].y)
		return (DUP_ERROR);
		n += 1;
	}
	return (PROCEED);
}

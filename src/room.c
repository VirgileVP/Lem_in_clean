/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   room.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 14:38:02 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 14:49:20 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parse.h"

int			room_seek(char *name, t_room *rdata, t_anthill *ah)
{
	int			y;

	y = 0;
	while (y < ah->nb)
	{
		if (ft_strcmp(rdata[y].name) == 0)
			return (x);
	}
	return (-1);
}

int			room_dup(t_room *rdata, int i, t_anthill *ah)
{
	int			y;

	y = 0;
	while (y < 
}

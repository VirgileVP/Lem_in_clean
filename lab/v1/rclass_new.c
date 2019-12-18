/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rclass_new.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 09:54:34 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 10:21:20 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int				rclass_new(t_rclass **new, t_anthill *ah)
{
	if ((*new = ft_memalloc(sizeof(t_rclass))) == NULL)
		return (-1);
	return (1);
}

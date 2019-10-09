/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:47:52 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 09:02:08 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	t_ul		strp;
	t_ul		k;

	strp = (t_ul)str;
	while (strp & 7)
	{
		if (((t_byte *)strp)[0] == '\0')
			return (strp - (t_ul)str);
		strp += 1;
	}
	while (1)
	{
		k = ((t_ul *)strp)[0];
		if (((k - LOMAGIC) & ~k & HIMAGIC) != 0)
		{
			while (((t_byte *)strp)[0] != '\0')
				strp += 1;
			break ;
		}
		strp += 8;
	}
	return ((size_t)(strp - (t_ul)str));
}

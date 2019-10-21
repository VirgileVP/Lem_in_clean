/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrix.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 13:08:03 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 13:40:26 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "matrix.h"


void			m_set(int **matrix, int x, int y, char c)
{
	char			px;
	char			py;

	px = 0x08 >> (x % sizeof(long));
	py = y % sizeof(long);
	x /= sizeof(long);
	y /= sizeof(long);
}

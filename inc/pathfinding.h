/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pathfinding.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 14:30:42 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 14:35:27 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PATHFINDING_H
# define PATHFINDING_H

typedef struct			s_cost
{
	int					d_start;
	int					d_end;
	int					total;
}						t_cost;

#endif

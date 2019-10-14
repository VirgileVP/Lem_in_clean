/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pathfinding.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 14:30:42 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 15:44:55 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PATHFINDING_H
# define PATHFINDING_H

typedef struct			s_ant
{
	int					*used;
	int					*roadmap;
	int					pos;
}						t_ant;

typedef struct			s_colony
{
	struct s_ant		**ant;
	size_t				nb;
}						t_colony;

t_colony				ant_spawn

#endif

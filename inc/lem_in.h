/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 13:51:45 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 13:58:12 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct			s_anthill
{
	size_t				nb_room;
	size_t				nb_ant;
}						t_anthill;

typedef struct			s_room
{
	char				name;
	int					x;
	int					y;
	size_t				nb_ant;
}						t_room;

typedef struct			s_roadset
{
	int					**roadmap;
	size_t				nb_road;
}						t_roadset;

#endif

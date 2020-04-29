/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveyrat- <vveyrat-@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 08:46:44 by vveyrat-          #+#    #+#             */
/*   Updated: 2020/03/12 12:57:25 by vveyrat-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "lemin.h"
# include "graph.h"
# include "way.h"
# include "queue.h"

int	    	multi_path(t_anthill *anthill, t_roadset *roads);
int		    all_ant_one_path(t_anthill *anthill, t_roadset *roads);
void		oneshot(t_anthill *anthill);
int	        is_starting(t_roadset *roads, int road_index, t_anthill *anthill);
int         which_ant(t_roadset *roads, int road_index);
int		    total_ant(int *remaining_ants, int nb_road);
void		fill_remaining_ants(t_roadset *roads, int *remaining_ants, int nb_road);
void		print_step(t_anthill *anthill, t_roadset *roads, int road_index);


#endif

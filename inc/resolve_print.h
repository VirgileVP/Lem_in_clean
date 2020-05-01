/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_print.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 08:46:44 by vveyrat-          #+#    #+#             */
/*   Updated: 2020/05/01 17:32:22 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVE_PRINT_H
# define RESOLVE_PRINT_H

# include "lemin.h"
# include "graph.h"
# include "way.h"
# include "queue.h"

void		print_path(int ant, char *room);
int			how_much_road(t_roadset *roads);
int			which_resolution(t_anthill *anthill, t_roadset *roads);

#endif

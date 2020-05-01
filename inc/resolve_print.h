/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_print.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveyrat- <vveyrat-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:42:26 by vveyrat-          #+#    #+#             */
/*   Updated: 2020/03/10 11:42:28 by vveyrat-         ###   ########lyon.fr   */
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

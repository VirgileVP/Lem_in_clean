/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:54:16 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 12:56:26 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ERROR_H
# define CHECK_ERROR_H

typedef struct		s_check_bad_order
{
	int				tube_pars;
	int				start;
	int				end;
}					t_check_bad_order;

int			read_error(t_read_room *pars);
int			free_temp_line(char *temp, char *line, int ret);
int			count_space(char *line);
int			check_definition(t_read_room *pars, t_check_bad_order *order, int index);
int			check_room(char *line, int tube_pars);
int			check_tubes(char *line);

#endif
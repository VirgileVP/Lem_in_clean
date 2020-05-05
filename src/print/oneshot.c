/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oneshot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vveyrat- <vveyrat-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:42:26 by vveyrat-          #+#    #+#             */
/*   Updated: 2020/03/10 11:42:28 by vveyrat-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "resolve_print.h"

void		oneshot(t_anthill *anthill)
{
	int		count;

	count = 1;
	while (count <= anthill->nb_ant)
	{
		print_path(count, anthill->room_data[anthill->end].name);
		if (count == anthill->nb_ant)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		count++;
	}
}

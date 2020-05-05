/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:14:10 by zseignon          #+#    #+#             */
/*   Updated: 2020/05/01 17:36:12 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "resolve_print.h"
#include "print.h"

static void		print_read(t_read_room *read)
{
	int				index;

	index = 0;
	while (read->room[index])
	{
		ft_putendl(read->room[index]);
		index++;
	}
	ft_putchar('\n');
}

static void		data_init(t_anthill *data, int nb_room, int nb_lemin)
{
	int				n;
	t_node			node;

	n = 0;
	vect_init(&data->farm, sizeof(t_node), nb_room);
	data->room_data = ft_malloc(sizeof(t_room) * nb_room);
	data->start = -1;
	data->end = -1;
	data->nb_ant = nb_lemin;
	data->nb_room = nb_room;
	ft_bzero(&node, sizeof(t_node));
	while (n < nb_room)
	{
		vect_init(&node.connect, sizeof(t_connect), 5);
		vect_add(&data->farm, &node);
		n++;
	}
}

static void		graph_init(t_graph *restrict graph, t_anthill *restrict ah)
{
	t_size		n;

	n = 0;
	graph->nodes = (t_node **)ft_malloc(sizeof(t_node *) * ah->nb_room);
	while (n < (t_size)ah->nb_room)
	{
		graph->nodes[n] = (t_node *)vect(&ah->farm, n);
		n++;
	}
	graph->size = ah->nb_room;
	graph->end = ah->end;
	graph->start = ah->start;
}

int				main(void)
{
	t_anthill		data;
	t_read_room		read;
	t_roadset		*roadset;
	int				ret;
	t_graph			graph;

	ft_memman_init();
	ft_memset(&data, 0, sizeof(t_anthill));
	ft_memset(&read, 0, sizeof(t_read_room));
	if (read_error(&read) == 1)
	{
		read.nb_room -= 2;
		data_init(&data, read.nb_room, ft_atoi(read.room[0]));
		ret = parse_map(&data, &read.room[1]);
		if (ret == 2)
		{
			print_read(&read);
			oneshot(&data);
		}
		else
		{
			graph_init(&graph, &data);
			if ((roadset = solve(&graph, data.nb_ant)) != NULL)
			{
				print_read(&read);
				which_resolution(&data, roadset);
			}
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}

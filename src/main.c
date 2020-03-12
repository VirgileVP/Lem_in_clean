/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:14:10 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 13:13:41 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
//----------------PRINT-FUNCTION-----------------------------------------------
/*
static void		print_roadset(t_roadset *rs, t_anthill *ah)
{
	size_t			y;
	size_t			x;

	y = 0;
	printf("ROADSET");
	while (rs[y].t != NULL)
	{
		x = 0;
		printf("PATH N'%zu [%zu]: |", rs[y].len, y);
		fflush(stdout);
		while (x < rs[y].len)
		{
			write(1, ah->room_data[rs[y].t[x].n].name, (t_ul)ft_strchr(ah->room_data[rs[y].t[x].n].name, ' ') - (t_ul)ah->room_data[rs[y].t[x].n].name);
			write(1, "|", 1);
			x += 1;
		}
		y += 1;
		printf("\n");
	}
}
*/
//-----------------------------------------------------------------------------

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
	graph->nodes = (t_node **)ft_malloc(sizeof(t_node *));
	while (n < (t_size)ah->nb_ant)
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
			if ((roadset = solve(&graph, data.nb_ant)))
				which_resolution(&data, roadset);
		}
	}
	else
		write(1, "Error\n", 6);
	ft_memman_clean();
	return (0);
}

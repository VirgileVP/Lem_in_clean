/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:14:10 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/30 12:27:26 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
//----------------PRINT-FUNCTION-----------------------------------------------

__attribute__ ((unused))static void		print_roadset(t_roadset *rs, t_anthill *ah)
{
	size_t			y;
	size_t			x;

	y = 0;
	printf("ROADSET\n");
	while (rs[y].t != NULL)
	{
		x = 0;
		printf("PATH[%zu][%zu]: |", y, rs[y].len);
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

static void		graph_init(
	t_graph *restrict graph,
	t_anthill *restrict ah
	)
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

__attribute__ ((unused))static void		graph_test(t_graph *restrict graph)
{
	t_size		n;
	t_size		x;

	n = 0;
	while (n < graph->size)
	{
		x = 0;
		printf(
			"node[%ld]:\n\
			in_new_way = %d\n\
			in_queue = %d\n\
			marked = %d\n\
			parent = %d\n\
			sep_type = %d\n\
			separate = %d\n\
			weight = %d\n\
			xconnect = %ld\n",
			n,
			graph->nodes[n]->in_new_way,
			graph->nodes[n]->in_queue,
			graph->nodes[n]->marked,
			graph->nodes[n]->parent,
			graph->nodes[n]->sep_type,
			graph->nodes[n]->separate,
			graph->nodes[n]->weight,
			graph->nodes[n]->connect.xitem
		);
		while (x < graph->nodes[n]->connect.xitem)
		{
			printf(
				"\t\t\t\t->%d\n",
				((t_connect *)vect(&(graph->nodes[n]->connect), x))->dst
			);
			x++;
		}
		n++;
	}
}

int				main(void)
{
	t_anthill		data;
	t_read_room		read;
	t_roadset		*roadset __attribute__ ((unused));
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
//			graph_test(&graph);
//			printf("end = %s | %ld\n", data.room_data[graph.end].name, graph.nodes[graph.end]->connect.xitem);
			if ((roadset = solve(&graph, data.nb_ant)) != NULL)
			{
				print_roadset(roadset, &data);
				ft_putstr("\n\n\n");
				which_resolution(&data, roadset);
			}
		}
	}
	else
		write(1, "Error\n", 6);
	ft_memman_clean();
	return (0);
}

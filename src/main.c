/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 13:58:22 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 14:36:42 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

/*
** print_read:
**
** print the map
*/

void			print_read(t_read_room *read)
{
	int			index;

	index = 0;
	while (read->room[index])
	{
		ft_putendl(read->room[index]);
		ft_putchar('\n');
		index++;
	}
}

int		data_init(t_anthill *data, int nb_room, int nb_lemin)
{
	int			count;

	count = 0;
	if (!(data->room_data = (t_room *)malloc(sizeof(t_room) * nb_room)))
		return(-1);
	ft_bzero(data->room_data, sizeof(t_room) * nb_room);
	data->room_data[0].nb_ant = nb_lemin;
	data->nb_ant = nb_lemin;
	if (!(data->matrix = (t_ul **)malloc(sizeof(t_ul *) * nb_room)))
		return(-1);
	while (count < nb_room)
	{
		data->xlen = nb_room / 64;
		if (nb_room % 64 != 0)
			data->xlen += 1;
		if(!(data->matrix[count] =
			(t_ul *)ft_memalloc(sizeof(t_ul) * data->xlen)))
			return(-1);
		count += 1;
	}
	data->nb_room = nb_room;
	return (1);
}

/*
** main_free:
**
** free allocated struc in main function
** reason == 1 -> free because error
** reason == 0 -> free because end program
*/

void			main_free(t_anthill *data, t_read_room *read, int reason)
{
	ft_memdel((void**)&data);
	ft_memdel((void**)&read);
	if (reason == 1)
		ft_putendl("ERROR");
	exit (1);
}

int				main(int argc __attribute__ ((unused)),
					char *argv[] __attribute__ ((unused)))
{
	t_anthill	data;
	t_read_room	read;
	t_roadset	*roadset;
	int			parse_ret;

	parse_ret = 0;
	ft_bzero(&read, sizeof(t_read_room));
	ft_bzero(&data, sizeof(t_anthill));
	if (read_error(&read) == -1)
		main_free(&data, &read, 1);
	print_read(&read);
	ft_putstr("after print_read\n");
	if (data_init(&data, read.nb_room, ft_atoi(read.room[0])) == -1)
		main_free(&data, &read, 0);
	parse_ret = parse_map(&data, read.room);
	if (parse_ret == -1)
		main_free(&data, &read, 1);
	else if (parse_ret == 2)
	{
		oneshot(&data);
		main_free(&data, &read, 0);
	}
	if (pathfinding(&data, &roadset) != 1)
		main_free(&data, &read, 0);
	which_resolution(&data, roadset);
	main_free(&data, &read, 0);
	return (0);
}

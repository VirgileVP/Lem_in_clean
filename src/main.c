/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 13:58:22 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 13:28:24 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

/*
 ** print_read:
 **
 ** print the map
 */

static void		print_data(t_anthill *ah)
{
	for (size_t n = 0; n < ah->nb_room; n++)
	{
		t_ul			cccc = 0x8000000000000000UL;
		size_t		x = 0;
		size_t		xn = 0;

		printf("rdata[%zu] = %s\t|", n, ah->room_data[n].name);
		for (size_t x = 0; x < ah->nb_room; x += 1)
		{

			if (ah->matrix[n][xn] & cccc)
				printf("1|");
			else
				printf("0|");
			cccc >>= 1;
			if (cccc == 0)
			{
				cccc = 0x8000000000000000UL;
				xn += 1;
			}
		}
		printf("\n");
	}

}

void			print_read(t_read_room *read)
{
	int			index;

	index = 0;
	while (read->room[index])
	{
		ft_putendl(read->room[index]);
		index++;
	}
}

int		data_init(t_anthill *data, int nb_room, int nb_lemin)
{
	int			count;

	count = 0;
	if (!(data->room_data = (t_room *)ft_memalloc(sizeof(t_room) * nb_room)))
		return(-1);
	data->nb_ant = nb_lemin;
	if (!(data->matrix = (t_ul **)ft_memalloc(sizeof(t_ul *) * nb_room)))
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
	data->start = -1;
	data->end = -1;
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
	size_t			y;

	y = 0;
	if (data->room_data)
		free(data->room_data);
	if (data->matrix)
	{
		while (y < data->nb_room)
		{
			free(data->matrix[y]);
			y += 1;
		}
		free(data->matrix);
	}
	if (reason == 1)
		ft_putendl("ERROR");
	exit(1);
}

int				main(int argc __attribute__ ((unused)),
		char *argv[] __attribute__ ((unused)))
{
	t_anthill	data;
	t_read_room	read;
	t_roadset	*roadset;
	int			parse_ret;

	parse_ret = 0;
	ft_memset(&read, 0, sizeof(t_read_room));
	ft_memset(&data, 0, sizeof(t_anthill));
	if (read_error(&read) == -1)
		main_free(&data, &read, 1);
	print_read(&read);
<<<<<<< HEAD
	//	ft_putstr("after print_read\n");
=======
>>>>>>> f5674e6541461c59b107166e4f0fe662d0448746
	if (data_init(&data, read.nb_room, ft_atoi(read.room[0])) == -1)
		main_free(&data, &read, 0);
	parse_ret = parse_map(&data, &read.room[1]);
	if (parse_ret == -1)
	{
		main_free(&data, &read, 1);
	}
	else if (parse_ret == 2)
	{
		oneshot(&data);
		main_free(&data, &read, 0);
	}
//	print_data(&data);
	if (pathfinding(&data, &roadset) != 1)
	{
		printf("pathfinding failed\n");
		main_free(&data, &read, 0);
<<<<<<< HEAD
	}
//	printf("ok\n");
=======
	ft_putstr("TESTING\n");
>>>>>>> f5674e6541461c59b107166e4f0fe662d0448746
	which_resolution(&data, roadset);
//	main_free(&data, &read, 0);
	return (0);
}

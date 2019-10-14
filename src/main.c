/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 13:58:22 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 14:00:05 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

/*
** print_read:
**
** print the map
*/

void			print_read(t_read_room *read)
{
	int			index;

	index = 0;
	while (index < read->room[index])
	{
		ft_putendl(read->room[index])
		index++;
	}
	ft_putchar('\n');
}

int		data_init(t_data *data, int nb_room, int nb_lemin)
{
	int			count;

	count = 0;
	if (!(data->room_data = (t_room_data *)malloc(sizeof(t_room_data) * nb_room)))
		return(-1);
	ft_bzero(data->room_data, sizeof(t_room_data) * nb_room);
	data->room_data[0].nb_lemin = nb_lemin;
	data->nb_ants = nb_lemin;
	if (!(data->matrice = (int **)malloc(sizeof(int *) * nb_room)))
		return(-1);
	while (count < nb_room)
	{
		if(!(data->matrice[count] = (int *)malloc(sizeof(int) * nb_room)))
			return(-1);
		ft_bzero(data->matrice[count], sizeof(int) * nb_room);
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

void			main_free(t_data *data, t_read_room *read, int reason)
{
	ft_memdel(data);
	ft_memdel(read);
	if (reason == 1)
		ft_putendl("ERROR");
}

int				main(int argc __attribute__ ((unused)),char *argv[] __attribute__ ((unused)))
{
	t_data		data;
	t_read_room	read;

	ft_bzero(&read, sizeof(t_read));
	ft_bzero(&data, sizeof(t_data));
	if (read_error(&read) == -1)
	{
		main_free(&data, &read, 1);
		ft_putstr("ERROR\n");
		return (-1);
	}
	printf_read(&read);
	if (data_init(&data, read.nb_room, ft_atoi(read.room[0])) == -1)
	{
		main_free(&data, &read, 0);
		return (-1);
	}
	if (parse(&read.room[1] , &data) == -1)
	{
		main_free(&data, &read, 1);
		ft_putstr("ERROR\n");
	}
	/*CALL PATH_FINDING FUNCTION*/
	select_strategy(&data, /*SEND ROAD_MAP HERE*/);
	main_free(&data, &read);
	return (0);
}

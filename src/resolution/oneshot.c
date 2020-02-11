#include "lemin.h"

void		one_shot(t_anthill *anthill)
{
	int		count;

	count = 1;
	while(count <= anthill->nb_ant)
	{
		print_path(count, anthill->room_data[end].name);
		if (count == anthill->nb_ant)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		count ++;
	}
}
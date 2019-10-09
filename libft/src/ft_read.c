/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/13 10:30:48 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 16:26:09 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_data		*ft_read_input(t_read **entry, size_t read_size)
{
	char		*buf;
	t_read		*tmp;
	int			ret;

	buf = (char *)malloc(sizeof(t_byte) * read_size);
	tmp = *entry;
	while ((ret = read(0, buf, read_size)) > 0)
	{
		if (ret + tmp->data->len > BUFF_SIZE)
		{
			if ((tmp->next = ft_read_alloc(BUFF_SIZE)) == NULL)
				return (NULL);
			tmp = tmp->next;
		}
		ft_memcpy(&((char *)tmp->data->data)[tmp->data->len], buf, ret);
		tmp->data->len += ret;
		if ((size_t)ret == read_size)
		{
			ft_strdel(&buf);
			read_size *= 2;
			buf = (char *)malloc(sizeof(t_byte) * read_size);
		}
	}
	ft_strdel(&buf);
	return (ft_data_cat(*entry));
}

static t_data		*ft_read_file(int fd, t_read **entry)
{
	t_read		*tmp;

	tmp = *entry;
	while ((tmp->data->len = read(fd, tmp->data->data, BUFF_SIZE)) == BUFF_SIZE)
	{
		if ((tmp->next = ft_read_alloc(BUFF_SIZE)) == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	return (ft_data_cat(*entry));
}

t_data				*ft_read(char *file_name, int fd)
{
	t_data		*data;
	t_read		*entry;

	if ((entry = ft_read_alloc(BUFF_SIZE)) == NULL)
		return (NULL);
	if (file_name == NULL && fd == 0)
		data = ft_read_input(&entry, 2048);
	else
	{
		if (file_name != NULL && fd == 0)
			fd = open(file_name, O_RDONLY);
		data = ft_read_file(fd, &entry);
		close(fd);
	}
	ft_read_free(&entry);
	return (data);
}

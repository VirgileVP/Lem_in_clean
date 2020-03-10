/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_strdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:13:48 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 11:15:42 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

static int		isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int				ft_is_strdigit(char *str)
{
	int count;

	count = 0;
	if (str)
	{
		while (str[count])
		{
			if (isdigit(str[count]) == 0)
				return (0);
			count++;
		}
		return (1);
	}
	return (0);
}
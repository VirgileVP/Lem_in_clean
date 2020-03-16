/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_strdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:13:48 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/16 10:25:31 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

static int		ft_isdigit(char c)
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
			if (ft_isdigit(str[count]) == 0)
				return (0);
			count++;
		}
		return (1);
	}
	return (0);
}
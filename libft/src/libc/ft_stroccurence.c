/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stroccurence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:42:50 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:23:30 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int			ft_stroccurence(char *str, char c)
{
	int		index;
	int		ret;

	index = 0;
	ret = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			ret++;
		index++;
	}
	return (ret);
}
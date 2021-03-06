/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:56:55 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:22:34 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!(s) || !(*f))
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

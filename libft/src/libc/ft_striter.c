/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:10:48 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 08:22:30 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int	i;

	i = 0;
	if (!(s) || !(*f))
		return ;
	while (s[i])
	{
		(*f)(&s[i]);
		i++;
	}
}
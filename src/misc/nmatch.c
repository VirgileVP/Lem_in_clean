/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:23:03 by zseignon          #+#    #+#             */
/*   Updated: 2020/05/05 11:51:09 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		nmatch(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s2 == '*' && *s1 == '\0')
		return (nmatch(s1, s2 + 1));
	else if (*s2 == '*')
		return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
	else if (*s1 == *s2)
		return (nmatch(s1 + 1, s2 + 1));
	return (0);
}

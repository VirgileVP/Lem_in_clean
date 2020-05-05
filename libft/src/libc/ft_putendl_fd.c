/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:03:27 by zseignon          #+#    #+#             */
/*   Updated: 2020/05/01 17:46:31 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

int			ft_putendl_fd(char const *s, int fd)
{
	return (ft_putstr_fd(s, fd) + ft_putchar_fd('\n', fd));
}

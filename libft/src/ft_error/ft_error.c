/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:01:43 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 09:37:48 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_error.h"

void		ft_error_free_exit(const char *msg, int code)
{
	ft_memman_clean();
	write(FD_STDERR, msg, ft_strlen(msg));
	exit(code);
}

void		ft_error_exit(const char *msg, int code)
{
	write(FD_STDERR, msg, ft_strlen(msg));
	exit(code);
}

void		ft_error_print(const char *msg)
{
	write(FD_STDERR, msg, ft_strlen(msg));
}

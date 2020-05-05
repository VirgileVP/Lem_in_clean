/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:01:43 by zseignon          #+#    #+#             */
/*   Updated: 2020/05/01 17:53:04 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_error.h"

void		ft_error_free_exit(const char *msg, int code)
{
	int		ret;

	ft_memman_clean();
	ret = write(FD_STDERR, msg, ft_strlen(msg));
	exit(code + (ret & 0));
}

void		ft_error_exit(const char *msg, int code)
{
	int		ret;

	ret = write(FD_STDERR, msg, ft_strlen(msg));
	exit(code + (ret & 0));
}

int			ft_error_print(const char *msg)
{
	return (write(FD_STDERR, msg, ft_strlen(msg)));
}

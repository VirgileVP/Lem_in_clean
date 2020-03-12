/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:59:57 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/10 14:06:55 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define PTR_SIZE	8

# define FD_STDIN	0
# define FD_STROUT	1
# define FD_STDERR	2

# define INT_MIN	-2147483648
# define INT_MAX	2147483647	
# define UINT_MIN	0
# define UINT_MAX	4294967296

# include "ft_vector.h"
# include "typedef.h"
# include "ft_error.h"
# include "ft_memman.h"
# include "ft_cmp.h"
# include "libc.h"

#endif
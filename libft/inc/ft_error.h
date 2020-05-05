/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:59:02 by zseignon          #+#    #+#             */
/*   Updated: 2020/05/01 17:53:08 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include <unistd.h>

# define ERR_VECT_MSG		"[error] vect bard arguments.\naborting process.\n"
# define ERR_MEMALLOC_MSG	"[error] mallocation failed.\naborting process.\n"
# define ERR_MEMFREE_MSG	"[error] trying to free non allocated memory.\n"

# define MEMERR_CODE		0

void		ft_error_free_exit(const char *msg, int code);
void		ft_error_exit(const char *msg, int code);
int			ft_error_print(const char *msg);

#endif

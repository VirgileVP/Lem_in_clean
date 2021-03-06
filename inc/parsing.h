/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:26:36 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/12 12:57:15 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "lemin.h"

# define BINIT			0x8000000000000000UL

extern const char		g_white_space[256];

typedef struct			s_prs
{
	char				*p[3];
	size_t				len[3];
	size_t				n;
}						t_prs;

enum					e_flag
{
	DUPLICATE = -4,
	START_END_UNDEFINIED = -3,
	MALLOC_ERROR = -2,
	STOP = -1,
	ROOM = 0,
	TUNNEL = 1,
	START_END_CONNECTED = 2
};

enum e_flag				rdup_check(t_room *rdata, size_t n);
int						rseek(t_anthill *ah, t_room *rdata, char *p);

#endif

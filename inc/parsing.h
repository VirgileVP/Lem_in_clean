/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 09:37:39 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 13:30:37 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "lem_in.h"

# define BINIT				0x8000000000000000UL

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

#endif
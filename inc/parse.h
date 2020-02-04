/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <zseignon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:02:37 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 08:54:46 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "lem_in.h"

# define START				0x01
# define END				0x02
# define BZERO				0x8000000000000000UL

enum					status
{
	ROOM,
	TUNNEL
};

enum					flags
{
	PROCEED,
	STOP,
	DUP_ERROR,
	MALLOC_ERROR
};

int						room_seek(char *name, t_room *rdata, t_anthill *ah);
enum flags				room_dup(t_room *rdata, int i);

#endif

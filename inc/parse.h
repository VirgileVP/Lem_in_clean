/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:02:37 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 14:43:46 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "lem_in.h"

# define				START	0x01
# define				END		0x02

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

int						room_seek(char *name, t_root *rdata, t_anthill *ah);

#endif

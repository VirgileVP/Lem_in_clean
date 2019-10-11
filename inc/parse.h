/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:02:37 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 14:28:41 by zseignon    ###    #+. /#+    ###.fr     */
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

int						parse(char **entry, t_anthill *ah, t_room *rdata, int **matrix)

#endif

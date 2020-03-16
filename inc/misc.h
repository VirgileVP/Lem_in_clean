/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:09:21 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/16 13:49:09 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H

# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 300

typedef struct		s_gnl
{
	struct s_gnl	*next;
	char			*actual;
	char			*temp;
	int				current_fd;
}					t_gnl;

int			get_next_line(int fd, char **line);
size_t		ft_count_words(char *s, char c);
int			ft_is_strdigit(char *str);
int			ft_isspace(int c);
int			nmatch(char *s1, char *s2);

#endif
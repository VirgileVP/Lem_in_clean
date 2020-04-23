/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdebugs <zdebugs@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 11:15:28 by zdebugs           #+#    #+#             */
/*   Updated: 2020/03/17 11:18:15 by zdebugs          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QSORT_H
# define FT_QSORT_H

# include "typedef.h"

void        ft_qsort(
    void *restrict mem,
    t_size left,
    t_size right
);

#endif
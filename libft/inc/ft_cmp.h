/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:00:42 by zseignon          #+#    #+#             */
/*   Updated: 2020/05/01 17:09:15 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CMP_H
# define FT_CMP_H

int			ft_icmp(const void *p1, const void *p2);
int			ft_ccmp(const void *p1, const void *p2);
int			ft_scmp(const void *p1, const void *p2);
int			ft_zcmp(const void *p1, const void *p2);
int			ft_pcmp(const void *p1, const void *p2);

#endif

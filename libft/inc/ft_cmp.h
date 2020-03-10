/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:00:42 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/05 15:01:23 by zseignon         ###   ########lyon.fr   */
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
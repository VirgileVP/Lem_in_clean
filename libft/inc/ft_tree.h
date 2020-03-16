/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 13:04:28 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/13 13:31:39 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_H
# define FT_TREE_H

typedef struct		s_item
{

}					t_item;

typedef struct		s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

#endif
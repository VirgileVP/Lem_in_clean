/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 13:35:38 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/13 08:52:48 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	ss1;
	size_t	ss2;

	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	if (!(ret = ft_strnew(ss1 + ss2)))
		return (NULL);
	ft_memcpy(ret, s1, ss1);
	ft_memcpy(&ret[ss1], s2, ss2);
	return (ret);
}

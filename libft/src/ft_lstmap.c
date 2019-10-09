/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 10:52:37 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 12:47:36 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*t;
	t_list	*new;

	t = (*f)(lst);
	if (!(new = ft_lstnew(t->content, t->content_size)))
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		t = (*f)(lst);
		if (!(new->next = ft_lstnew(t->content, t->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (start);
}

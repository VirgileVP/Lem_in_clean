/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colony.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 14:01:22 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 15:11:26 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

t_ant				*ant_new(int room, size_t xlen)
{
	t_ant				*a;

	if ((a = (t_ant *)malloc(sizeof(t_ant))) == NULL)
		return (NULL);
	a->root = rlink_new(room);
	a->p = root;
	a->rlen = 1;
	if ((a->used = (t_ul *)ft_memalloc(sizeof(t_ul) * xlen)) == NULL)
		return (NULL);
	a->next = NULL;
	return (a);
}

t_colony			*colony_new(size_t n)
{
	t_colony			*c;
	t_ant				*a;
	t_ant				*tmp;

	if ((c = (t_colony *)ft_memalloc(sizeof(t_colony))) == NULL)
		return (NULL);
	if (n > 0)
	{
		if ((c->p = ant_new(c, ah->start, ah->xmatrix, ah->xlen)) == NULL)
			return (NULL);
		c->len = 1;
		while (c->len < n)
		{
			if ((a = ant_new(ah->start, ah->xmatrix, ah->xlen)) == NULL)
				return (NULL);
			tmp = c->p->next;
		}
	}
	return (c);
}

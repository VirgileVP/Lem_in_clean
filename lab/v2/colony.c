/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colony.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 14:01:22 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 11:34:36 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

static int			iadd_ant(t_colony *c, int r, size_t len)
{
	t_ant				*a;
	t_ant				*next;

	if ((a = (t_ant *)malloc(sizeof(t_ant))) == NULL ||
			(a->used = (t_ul *)ft_memalloc(sizeof(t_ul) * len)) == NULL)
		return (-1);
	rlink_init(a, r);
	if (c->len == 0)
	{
		c->p = a;
		a->next = NULL;
	}
	else
	{
		next = c->p->next;
		a->next = next;
		c->p->next = a;
		c->p = c->p->next;
	}
	c->len += 1;
	return (1);
}

int					colony_init(t_pfinding *pf, t_anthill *ah)
{
	size_t				n;

	if ((pf->wander = (t_colony *)ft_memalloc(sizeof(t_colony))) == NULL ||
			(pf->end = (t_colony *)ft_memalloc(sizeof(t_colony))) == NULL)
		return (-1);
	n = nconnect(ah->matrix, ah->start, ah->len);
	while (n > 0)
	{
		if (iadd_ant(pf>wander, ah->start, ah->len) < 0)
			return (-1);
		n -= 1;
	}
	return (1);
}

static void		src_relink(t_colony *c)
{
	t_ant			*last;
	t_ant			*first;

	if (c->len == 1)
		c->p = NULL;
	else
	{
		last = c->p->prev;
		first = c->p->next;
		last->next = first;
		first->prev = last;
		c->p = first;
	}
}

static void		dst_relink(t_colony *c, t_ant *new)
{
	t_ant			*first;
	t_ant			*last;

	if (c->len == 0)
	{
		new->next = new;
		new->prev = new;
		c->p = new;
	}
	else
	{
		first = c->p;
		last = c->p->prev;
		new->next = first;
		new->prev = last;
		first->prev = new;
		last->next = new;
		c->p = new;
	}
}

int				colony_push(t_colony *dst, t_colony *src)
{
	t_ant			*tmp;

	if (src->len > 0)
	{
		tmp = src->p;
		src_relink(src);
		dst_relink(dst, tmp);
		src->len -= 1;
		dst->len += 1;
		return (1);
	}
	return (0);
}









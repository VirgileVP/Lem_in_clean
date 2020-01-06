/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 10:21:21 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 11:37:13 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int				bchr(t_bindex *p, t_pfinding *pf, int y)
{
	while (b->xn < pf->len)
	{
		if (pf->xmatrix[y][b->xn] != 0)
		{
			if (b->cccc == 0)
				b->cccc = BZERO;
			while ((pf->xmatrix[y][b->xn] & b->cccc) != 0)
			{
				b->cccc >>= 1;
				b->x += 1;
			}
			return (1);
		}
		b->xn += 1;
		b->x += 64;
	}
	return (-1);
}

int				ant_scout(t_pfinding *pf)
{
	t_bindex		p;
	t_bindex		next;

	ft_memset(&p, 0, sizeof(t_bindex));
	bchr(&p, pf, c->p->n);
	next = p;
	next.cccc >>= 1;
	next.x += 1;
	while (bchr(&next, pf, c->p->n) == 1)
	{
		ant_dup(c, pf->len);
		rlink_addnew(c->p, x);
		c->p->used[p.xn] |= p.cccc;
		c->p = c->p->next;
		p = next;
		next.cccc >>= 1;
	}
	ant_dup(c, pf->len);
	rlink_addnew(c->p, x);
	c->p->used[p.xn] |= p.cccc;
	return (1);
}

int			ant_dup(t_colony *c, t_pfinding *pf)
{
	t_ant		*a;
	t_rlink		*tmp;

	if ((a = (t_ant *)ft_memalloc(sizeof(t_ant))) == NULL ||
			(a->used = (t_ul *)ft_memdup(c->p->used, sizeof(t_ul) * pf->len)) == NULL)
		return (-1);
	tmp = c->p->root;
	while (a->rlen < c->p->rlen)
	{
		rlink_add(a, tmp->n);
		tmp = tmp->next;
	}
	a->next = c->p->next;
	a->prev = c->p;
	c->p->next = a;
	c->p = c->p->next;
	return (1);
}

int		ant_ndup(t_colony *c, t_pfinding *pf, size_t n)
{
	while (n > 0)
	{
		if (ant_dup(c, pf) < 0)
			return (-1);
		n -= 1;
	}
	return (1);
}

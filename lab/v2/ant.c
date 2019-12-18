/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ant.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 10:21:21 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 12:42:14 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int				bchr()
{
	while (b->xn < pf->xlen)
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
	bchr(&p, pf, c->ant->p->n);
	next = p;
	next.cccc >>= 1;
	next.x += 1;
	while (bchr(&next, pf, c->ant->p->n) == 1)
	{
		ant_dup(c, pf->xlen);
		rlink_addnew(c, x);
		c->ant->used[p.xn] |= p.cccc;
		c->ant = c->ant->next;
		p = next;
		next.cccc >>= 1;
	}
	ant_dup(c, pf->xlen);
	rlink_addnew(c, x);
	c->ant->used[p.xn] |= p.cccc;
	return (1);
}

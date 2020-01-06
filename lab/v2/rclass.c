/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rclass.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 12:08:50 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 08:23:03 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int				rclass_init(t_pfinding *pf)
{
	if ((pf->root = rclass_new(pf)) == NULL)
		return (-1);
	pf->c = pf->root;
	pf->bext = NULL;
	return (1);
}

t_rclass		*rclass_chr(t_pfinding *pf, t_ant *ant)
{
	t_rclass		*tmp;
	size_t			n;
	char			check;

	tmp = pf->root;
	check = 1;
	while (tmp != NULL)
	{
		n = 0;
		while (n < pf->xlen)
		{
			if ((tmp->barr[n] & ant->used[n]) != 0)
			{
				check = 0;
				break ;
			}
			n += 1;
		}
		if (check)
			return (tmp);
		else
			tmp = tmp->next;
	}
	return (NULL);
}

t_rclass		*rclass_new(t_pfinding *pf)
{
	t_rclass		*r;

	if ((r = (t_rclass *)malloc(sizeof(t_rclass))) == NULL)
		return (NULL);
	r->rtab = NULL;
	r->t = NULL;
	if ((r->barr = (t_ul)ft_memalloc(sizeof(t_ul) * pf->len)) == NULL)
		return (NULL);
	r->next = NULL;
	return (r);
}

int				rclass_add_ant(t_rclass *r, t_ant *ant, t_pfinding *pf)
{
	t_rmap			*map;
	size_t			n;

	if ((map = (t_rmap *)malloc(sizeof(t_rmap))) == NULL)
		return (-1);
	map->p = ant->root;
	map->len = ant->rlen;
	map->next = NULL;
	if (r->rmap == NULL)
	{
		r->rmap = map;
		r->m = map;
	}
	else
	{
		r->m->next = map;
		r->m = r->m->next;
	}
	n = 0;
	while (n < pf->xlen)
	{
		r->barr[n] |= ant->used[n];
		n += 1;
	}
	return (1);
}

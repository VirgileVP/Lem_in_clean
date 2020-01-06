/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   roadset.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 11:43:15 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 12:54:21 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int				roadset_set(t_roadset **rs, t_rclass *rc)
{
	t_roadset		*rs;
	t_rmap			*rmap;
	t_rlink			*tmp;
	size_t			y;
	size_t			n;

	if ((*rs = (t_roadset *)malloc(sizeof(t_roadset))) == NULL ||
			((*rs)->roadmap = (int **)malloc(sizeof(int *) * rc->rlen)) == NULL)
		return (-1);
	y = 0;
	tmp = rc->rmap;
	while (y < rc->rlen)
	{
		if (((*rs)->roadmap[y] = (int *)malloc(sizeof(int) * rmap->len)) == NULL)
			return (-1);
		tmp = rmap->p;
		n = 0;
		while (n < rmap->len)
		{
			(*rs)->roadmap[y][n] = tmp->n;
			tmp = tmp->next;
			n += 1;
		}
		rmap = rmap->next;
		y += 1;
	}
	return (1);
}

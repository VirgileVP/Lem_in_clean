/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pathfinding.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 11:33:46 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 07:06:09 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int				pfinding_init(t_pfinding **pf, t_anthill *ah)
{
	if (((*pf) = (t_pfinding *)malloc(sizeof(t_pfinding))) == NULL)
		return (-1);
	colony_init(*pf, ah);
	rclass_init(*pf);
	(*pf)->matrix = ah->matrix;
	(*pf)->len = ah->len;
	return (1);
}

int				eval()
{

}

int				ant_loop(t_pfinding *pfinding, t_anthill *ah)
{
	int				ret;

	while (pfinding->wander->len > 0)
	{
		if ((ret = ant_scout(pfinding->wander, ah)) == END)
		{
			colony_push(pfinding->end, pfinding->wander);
			return (1);
		}
		pfinding->wander->p = pfinding->wander->p->next;
	}
	return (-1);
}

int				pathfinding(t_anthill *ah, t_roadset **rs)
{
	t_pfinding		*pfinding;
	int				ret;

	pfinding_init(&pfinding, ah);
	while (eval(pfinding, ah) == -1)
	{
		ret = ant_loop(pfinding, ah);
		if (ret == 1)
			rclass_add(rclass, end);
		else
			break ;
	}
	roadset_set(pfinding, rs);
	pfinding_free(&pfinding);
	return (1);
}

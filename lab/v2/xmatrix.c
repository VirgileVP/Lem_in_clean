/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   xmatrix.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 08:37:49 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 10:21:30 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


static int		xmatrix_convert(int **matrix, size_t len, t_pfinding *pf)
{
	size_t			y;
	size_t			x;
	size_t			xlen;

	y = 0;
	while (y < len)
	{
		if ((pf->xmatrix[y] = (t_ul *)malloc(sizeof(t_ul) * pf->xlen)) == NULL)
			return (-1);
		x = 0;
		while (x < len)
		{
			xlen = 0;
			while (x % 64 != 0 && x < len)
			{
				pf->xmatrix[y][xlen] <<= 1;
				if (matrix[x][y] == 1)
					pf->xmatrix[y][xlen] |= 1;
				x += 1;
			}
			xlen += 1;
		}
		y += 1;
	}
	return (1);
}

int				xmatrix_new(int **matrix, size_t len, t_pfinding *pf)
{
	if ((pf->xmatrix = (t_ul **)malloc(sizeof(t_ul *) * len)) == NULL)
		return (-1);
	if (len % 64 != 0)
		pf->xlen = 1;
	pf->xlen += len / 64;
	pf->len = len;
	xmatrix_convert(matrix, len, pf);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zseignon <zseignon@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:00:07 by zseignon          #+#    #+#             */
/*   Updated: 2020/03/05 15:00:28 by zseignon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int			main(void)
{
	void		*p1;
	void		*p2;

	p1 = malloc(17);
	p2 = malloc(16);
	printf("%ld - %ld = ", (unsigned long)p1, (unsigned long)p2);
	printf("%ld\n", (unsigned long)p1 - (unsigned long)p2);
	return (0);
}
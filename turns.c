/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:52:26 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/05/20 19:42:48 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		turn_left(t_base *base)
{
	int		q;
	double	degree;
	t_map	*map;
	int		sum;

	sum = base->size_map[0] * base->size_map[1];
	printf("%d\n", sum);
	degree = 53.27;
	map = base->map;
	q = 0;

	while (q < sum - 1)
	{
		printf("%d\n", q);
		map[q].y = map[q].y * cos(degree) + (map[q].z * sin(degree));
		map[q].z = map[q].y * sin(degree) + (map[q].z * cos(degree));
		q++;
	}
//	standart_output(base->img_ptr, base->map, base->size_map);
}
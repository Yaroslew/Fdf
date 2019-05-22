/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:52:26 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/05/22 19:48:34 by pcorlys-         ###   ########.fr       */
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
	degree = 53.27;
	map = base->map;
	q = 0;

	while (q < sum)
	{
		map[q].y = map[q].y * cos(degree) + (map[q].z * sin(degree));
		map[q].z = (map[q].y * -1) * sin(degree) + (map[q].z * cos(degree));
		q++;
		if (map[q - 1].y < 0)
			map[q-1].y *= -1;
		if (map[q-1].z < 0)
			map[q-1].z *= -1;

	}
	base->flag = 1;
	output(base);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 10:48:44 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/06/01 17:13:03 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdfHeader.h"

void			slantingR(t_base *base, int flag)
{
	int			q;

	q = 0;
	if (flag)
		base->angleSlantingR += base->angle;
	else
		base->angleSlantingR -= base->angle;
	freeImage(base);
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapDraw[q].x = (base->map[q].x + base->map[q].y) * cos(base->angle);
		base->mapDraw[q].y = (base->map[q].x - base->map[q].y) * sin(base->angle) - base->map[q].z;
		q++;
	}
	draw_map(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}

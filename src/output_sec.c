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

void		scale(t_base *base, int flag)
{
	int 		q;
	double		scale;

	if (flag % 2 == 0)
		scale = 1.25;
	else
		scale = 0.75;
	q = 0;
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapFl[q].x *= scale;
		base->mapFl[q].y *= scale;
		base->mapFl[q].z *= scale;
		q++;
	}
	pre_draw(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}

void	color_draw(t_base *base, int flag)
{
	int	q;

	q = 0;
	while (q < base->size_map[0] * base->size_map[1])
	{
		if (base->map[q].z > 0)
			base->mapDraw[q].color = 0xFF0000;
		q++;
	}
	pre_draw(base);
}
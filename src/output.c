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

void			stdOutput(t_base *base)
{
	int			q;

	q = 0;
	base->lineDraw->posCenterHor = (base->win_hor - (base->size_map[0] * base->scale)) / 2;
	base->lineDraw->posCenterVer = (base->win_ver - (base->size_map[1] * base->scale)) / 2;
	if (!(base->mapDraw = malloc(sizeof(t_map) * (base->size_map[0] * base->size_map[1]))))
			mess_err(0);
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapDraw[q].x = base->map[q].x;
		base->mapDraw[q].y = base->map[q].y;
		base->mapDraw[q].z = base->map[q].z;
		base->mapDraw[q].color = base->map[q].color;
		q++;
	}
	draw_map(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}

void			turnX(t_base *base, int flag)
{
	int			q;

	q = 0;
	if (flag)
		base->angleX += base->angle;
	else
		base->angleX -= base->angle;
	freeImage(base);
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapDraw[q].x = base->map[q].x;
		base->mapDraw[q].y = (base->map[q].y * cos(base->angleX)) + (base->map[q].z * sin(base->angleX));
		base->mapDraw[q].z = (base->map[q].y * sin(base->angleX)) + (base->map[q].z * cos(base->angleX));
		q++;
	}
	draw_map(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}

void			turnY(t_base *base, int flag)
{
	int			q;

	q = 0;
	if (flag)
		base->angleY += base->angle;
	else
		base->angleY -= base->angle;
	freeImage(base);
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapDraw[q].y = base->map[q].y;
		base->mapDraw[q].x = (base->map[q].x * cos(base->angleY)) + (base->map[q].z * sin(base->angleY));
		base->mapDraw[q].z = (base->map[q].x * sin(base->angleY)) + (base->map[q].z * cos(base->angleY));
		q++;
	}
	draw_map(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}

void			turnZ(t_base *base, int flag)
{
	int			q;

	q = 0;
	if (flag)
		base->angleZ += base->angle;
	else
		base->angleZ -= base->angle;
	freeImage(base);
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapDraw[q].z = base->map[q].z;
		base->mapDraw[q].x = (base->map[q].x * cos(base->angleZ)) - (base->map[q].y * sin(base->angleZ));
		base->mapDraw[q].y = (base->map[q].x * sin(base->angleZ)) + (base->map[q].y * cos(base->angleZ));
		q++;
	}
	draw_map(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}

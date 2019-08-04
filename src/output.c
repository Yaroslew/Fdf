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
	base->flagParrProj = 0;
	base->lineDraw->posCenterHor = (base->win_hor - (base->size_map[0] * base->scale)) / 2;
	base->lineDraw->posCenterVer = (base->win_ver - (base->size_map[1] * base->scale)) / 2;
	if (!(base->mapDraw = malloc(sizeof(t_map) * (base->size_map[0] * base->size_map[1]))))
			mess_err(0);
	if (!(base->mapFl = malloc(sizeof(t_mapFl) * (base->size_map[0] * base->size_map[1]))))
		mess_err(0);
	while(q < base->size_map[0] * base->size_map[1])
	{
		base->mapFl[q].x =(base->map[q].x - base->map[q].y) * cos(0.523599);
		base->mapFl[q].y = (base->map[q].x + base->map[q].y) * sin(0.523599) - base->map[q].z;
		base->mapFl[q].z = base->map[q].z;
		q++;
	}
	pre_draw(base);
}

void			parrProjection(t_base *base, int flag)
{
	int			q;

	q = 0;
	if (base->flagParrProj)
	{
		stdOutput(base);
		return;
	}
	freeImage(base);
	base->flagParrProj = 1;
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
	double		temp;
	double		angle;

	if (base->flagParrProj)
		return;
	q = 0;
	angle = base->angle;
	if (flag % 2 > 0)
		angle *= -1;
	freeImage(base);
	while (q < base->size_map[0] * base->size_map[1])
	{
		temp = base->mapFl[q].y;
		base->mapFl[q].y = base->mapFl[q].y * cos(angle) + base->mapFl[q].z * sin(angle);
		base->mapFl[q].z = -temp * sin(angle) + base->mapFl[q].z * cos(angle);
		q++;
	}
	pre_draw(base);
}

void			turnY(t_base *base, int flag)
{
	int			q;
	double		temp;
	double		angle;

	if (base->flagParrProj)
		return;
	q = 0;
	angle = base->angle;
	if (flag % 2 > 0)
		angle *= -1;
	while (q < base->size_map[0] * base->size_map[1])
	{
		temp = base->mapFl[q].x;
		base->mapFl[q].x = base->mapFl[q].x * cos(angle) + base->mapFl[q].z * sin(angle);
		base->mapFl[q].z = -temp * sin(angle) + base->mapFl[q].z * cos(angle);
		q++;
	}
	pre_draw(base);
}

void			turnZ(t_base *base, int flag)
{
	int			q;
	double		temp;
	double		angle;

	if (base->flagParrProj)
		return;
	q = 0;
	angle = base->angle;
	if (flag % 2 > 0)
		angle *= -1;
	while (q < base->size_map[0] * base->size_map[1])
	{
		temp = base->mapFl[q].x;
		base->mapFl[q].x = base->mapFl[q].x * cos(angle) - base->mapFl[q].y * sin(angle);
		base->mapFl[q].y = temp * sin(angle) + base->mapFl[q].y * cos(angle);
		q++;
	}
	pre_draw(base);
}

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

#include "../includes/fdfheader.h"

void			stdoutput(t_base *base)
{
	int			q;

	q = 0;
	base->flagparrproj = 0;
	base->linedraw->poscenterhor = (base->win_hor -
			(base->size_map[0] * base->scale)) / 2;
	base->linedraw->poscenterver = (base->win_ver -
			(base->size_map[1] * base->scale)) / 2;
	if (!(base->mapdraw = malloc(sizeof(t_map) * (base->size_map[0] *
			base->size_map[1]))))
		mess_err(0);
	if (!(base->mapfl = malloc(sizeof(t_mapfl) * (base->size_map[0] *
			base->size_map[1]))))
		mess_err(0);
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapfl[q].x = (base->map[q].x - base->map[q].y) * cos(0.523599);
		base->mapfl[q].y = (base->map[q].x + base->map[q].y) *
		sin(0.523599) - base->map[q].z;
		base->mapfl[q].z = base->map[q].z;
		base->mapdraw[q].color = base->map[q].color;
		q++;
	}
	pre_draw(base);
}

void			parrprojection(t_base *base, int flag)
{
	int			q;

	q = 0;
	if (base->flagparrproj)
	{
		stdoutput(base);
		return ;
	}
	freeimage(base);
	base->flagparrproj = 1;
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapdraw[q].x = base->map[q].x;
		base->mapdraw[q].y = base->map[q].y;
		base->mapdraw[q].z = base->map[q].z;
		base->mapdraw[q].color = base->map[q].color;
		q++;
	}
	draw_map(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}

void			turnx(t_base *base, int flag)
{
	int			q;
	double		temp;
	double		angle;

	if (base->flagparrproj)
		return ;
	q = 0;
	angle = base->angle;
	if (flag % 2 > 0)
		angle *= -1;
	while (q < base->size_map[0] * base->size_map[1])
	{
		temp = base->mapfl[q].y;
		base->mapfl[q].y = base->mapfl[q].y * cos(angle) +
				base->mapfl[q].z * sin(angle);
		base->mapfl[q].z = -temp * sin(angle) + base->mapfl[q].z * cos(angle);
		q++;
	}
	pre_draw(base);
}

void			turny(t_base *base, int flag)
{
	int			q;
	double		temp;
	double		angle;

	if (base->flagparrproj)
		return ;
	q = 0;
	angle = base->angle;
	if (flag % 2 == 0)
		angle *= -1;
	while (q < base->size_map[0] * base->size_map[1])
	{
		temp = base->mapfl[q].x;
		base->mapfl[q].x = base->mapfl[q].x * cos(angle) +
		base->mapfl[q].z * sin(angle);
		base->mapfl[q].z = -temp * sin(angle) + base->mapfl[q].z * cos(angle);
		q++;
	}
	pre_draw(base);
}

void			turnz(t_base *base, int flag)
{
	int			q;
	double		temp;
	double		angle;

	if (base->flagparrproj)
		return ;
	q = 0;
	angle = base->angle;
	if (flag % 2 > 0)
		angle *= -1;
	while (q < base->size_map[0] * base->size_map[1])
	{
		temp = base->mapfl[q].x;
		base->mapfl[q].x = base->mapfl[q].x * cos(angle) -
		base->mapfl[q].y * sin(angle);
		base->mapfl[q].y = temp * sin(angle) + base->mapfl[q].y * cos(angle);
		q++;
	}
	pre_draw(base);
}

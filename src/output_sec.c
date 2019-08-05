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

void			scale(t_base *base, int flag)
{
	int			q;
	double		scale;

	if (base->flagparrproj)
		return ;
	if (flag % 2 == 0)
		scale = 1.25;
	else
		scale = 0.75;
	q = 0;
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapfl[q].x *= scale;
		base->mapfl[q].y *= scale;
		base->mapfl[q].z *= scale;
		q++;
	}
	pre_draw(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}

static void		color_draw_sec(t_base *base)
{
	int			q;

	q = 0;
	while (q < base->size_map[0] * base->size_map[1])
	{
		if (base->map[q].z > 0)
			base->mapdraw[q].color = base->map[q].color;
		q++;
	}
	base->flagcolor = 0;
}

void			color_draw(t_base *base, int flag)
{
	int			q;

	q = 0;
	if (base->flagparrproj)
		return ;
	if (!base->flagcolor)
	{
		while (q < base->size_map[0] * base->size_map[1])
		{
			if (base->map[q].z > 0)
			{
				if (flag == 18)
					base->mapdraw[q].color = 0xFF0000;
				if (flag == 19)
					base->mapdraw[q].color = 0x00FF00;
				if (flag == 20)
					base->mapdraw[q].color = 0x0000FF;
			}
			q++;
		}
		base->flagcolor = 1;
	}
	else
		color_draw_sec(base);
	pre_draw(base);
}

void			movex(t_base *base, int flag)
{
	int			q;
	int			step;

	q = 0;
	step = 5;
	if (base->flagparrproj)
		return ;
	if (flag == 0)
		step = -5;
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapfl[q].x += step;
		q++;
	}
	pre_draw(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}

void			movey(t_base *base, int flag)
{
	int			q;
	int			step;

	q = 0;
	step = 5;
	if (base->flagparrproj)
		return ;
	if (flag == 13)
		step = -5;
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapfl[q].y += step;
		q++;
	}
	pre_draw(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}

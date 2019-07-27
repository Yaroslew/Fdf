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

#include "fdfHeader.h"

static void	init_steps(t_base *base, int flag)
{
	if (base->lineDraw->deltaY < 0)
		base->lineDraw->deltaY *= -1;
	if (base->lineDraw->deltaX < 0)
		base->lineDraw->deltaX *= -1;
	if (flag)
	{
		if (base->lineDraw->one.x < base->lineDraw->two.x)
			base->lineDraw->diry = 1;
		else
			base->lineDraw->diry = -1;
		base->lineDraw->stepErr = base->lineDraw->deltaY / base->lineDraw->deltaX;
	}
	else
	{
		if (base->lineDraw->one.y < base->lineDraw->two.y)
			base->lineDraw->diry = 1;
		else
			base->lineDraw->diry = -1;
		base->lineDraw->stepErr = base->lineDraw->deltaX / base->lineDraw->deltaY;
	}
}

static void	stepX(t_base *base)
{
	float	error;
	int 	pos;
	t_map	one;
	t_map	two;

	one = base->lineDraw->one;
	two = base->lineDraw->two;
	error = 0;
	init_steps(base, 1);
	while (one.x != two.x)
	{
		pos = (base->win_ver * base->lineDraw->posCenterVer) +
			  (base->win_ver * one.y + one.x + base->lineDraw->posCenterHor);
		if (pos > 0 && pos < base->win_ver * base->win_hor)
			base->data_img[pos] = get_color(one, base->lineDraw->start, two, 1);
		error += base->lineDraw->stepErr;
		if (error > 0.5)
		{
			one.y < two.y ? one.y++ : one.y--;
			error -= 0.5;
		}
		one.x += base->lineDraw->diry;
	}
}

static void	stepY(t_base *base)
{
	float	error;
	int 	pos;
	t_map	one;
	t_map	two;

	one = base->lineDraw->one;
	two = base->lineDraw->two;
	error = 0;
	init_steps(base, 0);
	while (one.y != two.y)
	{
		pos = (base->win_ver * base->lineDraw->posCenterVer) +
			  (base->win_ver * one.y + one.x + base->lineDraw->posCenterHor);
		if (pos > 0 && pos < base->win_ver * base->win_hor)
			base->data_img[pos] = get_color(one, base->lineDraw->start, two, 1);
		error += base->lineDraw->stepErr;
		if (error > 0.5)
		{
			one.x <two.x ? one.x++ : one.x--;
			error -= 0.5;
		}
		one.y += base->lineDraw->diry;
	}
}

static void	draw_line(t_base *base, t_map one, t_map two)
{
	base->lineDraw->one = one;
	base->lineDraw->start = one;
	base->lineDraw->two = two;
	one.x > two.x ? (base->lineDraw->deltaX = one.x - two.x) : 0;
	one.x < two.x ? (base->lineDraw->deltaX = two.x - one.x) : 0;
	one.y > two.y ? (base->lineDraw->deltaY = one.y - two.y) : 0;
	one.y < two.y ? (base->lineDraw->deltaY = two.y - one.y) : 0;

	if (base->lineDraw->deltaX > base->lineDraw->deltaY)
		stepX(base);
	else
		stepY(base);
}

void		draw_map(t_base *base)
{
	int		q;
	int 	lenLine;

	q = 0;
	lenLine = base->size_map[0];
	while (q < base->size_map[0] * base->size_map[1])
	{
		while (q < lenLine)
		{
			draw_line(base, base->mapDraw[q], base->mapDraw[q + 1]);
			if (q < base->size_map[0] * (base->size_map[1] - 1))
				draw_line(base, base->mapDraw[q], base->mapDraw[q +
																base->size_map[0]]);
			q++;
		}
		lenLine += base->size_map[0];
		q++;
	}
}
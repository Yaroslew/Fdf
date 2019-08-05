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

static void	init_steps(t_base *base, int flag)
{
	if (base->linedraw->deltay < 0)
		base->linedraw->deltay *= -1;
	if (base->linedraw->deltax < 0)
		base->linedraw->deltax *= -1;
	base->linedraw->er = 0;
	if (flag)
	{
		if (base->linedraw->one.x < base->linedraw->two.x)
			base->linedraw->diry = 1;
		else
			base->linedraw->diry = -1;
		base->linedraw->steperr = base->linedraw->deltay;
	}
	else
	{
		if (base->linedraw->one.y < base->linedraw->two.y)
			base->linedraw->diry = 1;
		else
			base->linedraw->diry = -1;
		base->linedraw->steperr = base->linedraw->deltax;
	}
}

static void	stepx(t_base *base)
{
	int		pos;
	t_map	one;
	t_map	two;

	one = base->linedraw->one;
	two = base->linedraw->two;
	init_steps(base, 1);
	while (one.x != two.x)
	{
		pos = (base->win_ver * base->linedraw->poscenterver) +
				(base->win_ver * one.y + one.x + base->linedraw->poscenterhor);
		if ((pos > 0 && (pos < base->win_ver * base->win_hor)) &&
		(one.x + base->linedraw->poscenterhor < base->win_hor &&
		one.x + base->linedraw->poscenterhor > 0))
			base->data_img[pos] = get_color(one, base->linedraw->start, two, 1);
		base->linedraw->er += base->linedraw->steperr;
		if (2 * base->linedraw->er >= base->linedraw->deltax)
		{
			if (one.y != two.y)
				one.y < two.y ? one.y++ : one.y--;
			base->linedraw->er -= base->linedraw->deltax;
		}
		one.x += base->linedraw->diry;
	}
}

static void	stepy(t_base *base)
{
	int		pos;
	t_map	one;
	t_map	two;

	one = base->linedraw->one;
	two = base->linedraw->two;
	init_steps(base, 0);
	while (one.y != two.y)
	{
		pos = (base->win_ver * base->linedraw->poscenterver) +
				(base->win_ver * one.y + one.x + base->linedraw->poscenterhor);
		if ((pos > 0 && (pos < base->win_ver * base->win_hor))
		&& (one.x + base->linedraw->poscenterhor < base->win_hor
		&& one.x + base->linedraw->poscenterhor > 0))
			base->data_img[pos] = get_color(one, base->linedraw->start, two, 1);
		base->linedraw->er += base->linedraw->steperr;
		if (2 * base->linedraw->er >= base->linedraw->deltay)
		{
			if (one.x != two.x)
				one.x < two.x ? one.x++ : one.x--;
			base->linedraw->er -= base->linedraw->deltay;
		}
		one.y += base->linedraw->diry;
	}
}

static void	draw_line(t_base *base, t_map one, t_map two)
{
	int flag;

	flag = 0;
	base->linedraw->one = one;
	base->linedraw->start = one;
	base->linedraw->two = two;
	base->linedraw->deltax = 0;
	base->linedraw->deltay = 0;
	one.x > two.x ? (base->linedraw->deltax = one.x - two.x) : 0;
	one.x < two.x ? (base->linedraw->deltax = two.x - one.x) : 0;
	one.y > two.y ? (base->linedraw->deltay = one.y - two.y) : 0;
	one.y < two.y ? (base->linedraw->deltay = two.y - one.y) : 0;
	if (base->linedraw->deltax > base->linedraw->deltay)
		stepx(base);
	else
		stepy(base);
}

void		draw_map(t_base *base)
{
	int		q;
	int		lenline;

	q = 0;
	lenline = base->size_map[0];
	while (q < base->size_map[0] * base->size_map[1] - 1)
	{
		while (q < lenline)
		{
			if (q < lenline - 1)
				draw_line(base, base->mapdraw[q], base->mapdraw[q + 1]);
			if (q < (base->size_map[0] *
				(base->size_map[1]) - base->size_map[0]))
				draw_line(base, base->mapdraw[q],
				base->mapdraw[q + base->size_map[0]]);
			q++;
		}
		lenline += base->size_map[0];
	}
}

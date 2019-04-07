/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:17:26 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/04/07 17:01:14 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		dir(int diry)
{
	if (diry > 0)
		diry = -1;
	if (diry < 0)
		diry = 1;
	return (diry);
}

static void		step_x(t_map one, t_map two, int delta_y, int *img_data)
{
	int			diry;
	int			delta_err;
	int			error;
	int			delta_x;

	error = 0;
	one.x > two.x ? (delta_x = one.x - two.x) : 0;
	one.x <= two.x ? (delta_x = two.x - one.x) : 0;
	diry = one.y - two.y;
	delta_y == 0 ? (delta_err = 0) : 0;
	delta_y != 0 ? (delta_err = ((float)delta_y / (float)delta_x) * 100) : 0;
	diry = dir(diry);
	while (one.x != two.x)
	{
		img_data[one.y * 1000 + one.x] = 0xffffff;
		one.x > two.x ? (one.x--) : (one.x++);
		error += delta_err;
		if (error > 50)
		{
			one.y += diry;
			error -= 100;
		}
	}
}

static void		step_y(t_map one, t_map two, int delta_y, int *img_data)
{
	int			diry;
	int			delta_err;
	int			error;
	int			delta_x;

	error = 0;
	one.x > two.x ? (delta_x = one.x - two.x) : 0;
	one.x <= two.x ? (delta_x = two.x - one.x) : 0;
	diry = one.x - two.x;
	delta_x == 0 ? (delta_err = 0) : 0;
	delta_x != 0 ? (delta_err = ((float)delta_x / (float)delta_y) * 100) : 0;
	diry = dir(diry);
	while (one.y != two.y)
	{
		img_data[one.y * 1000 + one.x] = 0xffffff;
		one.y > two.y ? (one.y--) : (one.y++);
		error += delta_err;
		if (error > 50)
		{
			one.x += diry;
			error -= 100;
		}
	}
}

void			draw_line(int *img_data, t_map one, t_map two)
{
	int			delta_y;
	int			delta_x;

	if (one.x >= two.x)
		delta_x = one.x - two.x;
	else
		delta_x = two.x - one.x;
	if (one.y >= two.y)
		delta_y = one.y - two.y;
	else
		delta_y = two.y - one.y;
	printf("dx=%d dy=%d \n", delta_x, delta_y);
	if (delta_x > delta_y)
		step_x(one, two, delta_y, img_data);
	else
		step_y(one, two, delta_y, img_data);
}

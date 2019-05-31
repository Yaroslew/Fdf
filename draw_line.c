/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 08:40:40 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/05/29 19:36:07 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void step_y(float del_err, t_map one, t_map two, t_base *base)
{
	int diry;
	float error;
	int pos_x;
	int pos_y;
	int flag;

	flag = 0;
	pos_x = (base->hor_win - (base->size_map[0] * 10)) / 2;
	pos_y = (base->ver_win - (base->size_map[1] * 10)) / 2;
//	printf("%d %d\n", pos_x, pos_y);
	diry = 1;
	error = 0;
	one.x - two.x > 0 ? (diry = -1) : 0;
	while (base->c_map->y != two.y)
	{
		base->position = (base->ver_win * pos_y) +
						 (base->ver_win * base->c_map->y + base->c_map->x + pos_x);
		base->data_img[base->position] = get_color(base->c_map[0], one, two, flag);
		error += del_err;
		if (error >  0.5)
		{
			base->c_map->x += diry;
			error -= 1.0;
		}
		one.y > two.y ? (base->c_map->y--) : base->c_map->y++;
	}
}

static void step_x(float del_err, t_map one, t_map two, t_base *base)
{
	int diry;
	float error;
	int pos_x;
	int pos_y;
	int flag;

	flag = 1;
	pos_x = (base->hor_win - (base->size_map[0] * 10)) / 2;
	pos_y = (base->ver_win - (base->size_map[1] * 10)) / 2;
//	printf("%d %d\n", pos_x, pos_y);
	diry = 1;
	error = 0;
	one.y - two.y > 0 ? (diry = -1) : 0;
	while (base->c_map->x  != two.x)
	{

		base->position = (base->ver_win * pos_y) +
						 (base->ver_win * base->c_map->y + base->c_map->x + pos_x);
		base->data_img[base->position] = get_color(base->c_map[0], one, two, flag);
		error += del_err;
		if (error >  0.5)
		{
			base->c_map->y += diry;
			error -= 1.0;
		}
		one.x > two.x ? (base->c_map->x--) : base->c_map->x++;
	}
}

void	draw_line(t_map one, t_map two, t_base *base)
{
	int	delta_x;
	int delta_y;
	float delta_err;
	one.x > two.x ? (delta_x = one.x - two.x) : 0;
	one.x > two.x ? 0 : (delta_x = two.x - one.x);
	one.y > two.y ? (delta_y = one.y - two.y) : 0;
	one.y > two.y ? 0 : (delta_y = two.y - one.y);
	delta_x > delta_y ? (delta_err = (float)delta_y / (float)delta_x) : 0;
	delta_x > delta_y ? 0 : (delta_err = (float)delta_x / (float)delta_x);
	base->c_map = malloc(sizeof(t_map));
	base->c_map->x = one.x;
	base->c_map->y = one.y;
	base->c_map->z = one.z;
	base->c_map->color = one.color;
	if (delta_x > delta_y)
		step_x(delta_err, one, two, base);
	else
		step_y(delta_err, one, two, base);
}

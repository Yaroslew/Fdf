/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:17:26 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/04/02 20:09:06 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		step_x(t_map one, t_map two, int delta_y, int *img_data)
{
	int			diry;
	int 		delta_err;
	int 		error;
	int 		delta_x;

	error = 0;
	one.x > two.x ? (delta_x = one.x - two.x) : (delta_x = two.x - one.x);
	diry = one.y - two.y;
	delta_y == 0 ? (delta_err = 0) : (delta_err = (delta_x / delta_y));
	printf("delta_x=%d delta_y=%d delta_err=%d\n", delta_x, delta_y, delta_err);
	diry < 0 ? (diry = 1) : (diry = -1);
	while(one.x != two.x)
	{
//		printf("one.x =%d two.x=%d one.y=%d two.y=%d\n", one.x, two.x, one.y, two.y);
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
	int 		delta_err;
	int 		error;
	int 		delta_x;
	int 		x;

	one.x > two.x ? (delta_x = one.x - two.x) : (delta_x = two.x - one.x);
	printf("!!!\n");
	error = 0;

}

void			draw_line(int *img_data, t_map one, t_map two)
{
	int 		delta_y;
	int 		delta_x;

	one.x > two.x ? (delta_x = one.x - two.x) : (delta_x = two.x - one.x);
	one.y > two.y ? (delta_y = one.y - two.y) : (delta_y = two.y - one.y);
	if (delta_x > delta_y)
		step_x(one, two, delta_y, img_data);
	else
		step_y(one, two, delta_y, img_data);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:16:49 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/06/01 15:50:09 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	output(t_base *base)
{
	int	q;
	t_map	*map;
	int side;
	int sum;

	q = 0;
	sum = base->size_map[0] * base->size_map[1];
	clean_img(base);
	side = base->size_map[0] - 1;
	map = base->map;
	while (q < sum)
	{
		if (map[q].color == 0)
			map[q].color = base->standart_color;
		if (map[q + 1].color == 0)
			map[q + 1].color = base->standart_color;
		if (map[q + base->size_map[0]].color == 0)
			map[q + base->size_map[0]].color = base->standart_color;
		if (q != side)
			draw_line(map[q], map[q + 1], base);
		if (q == side)
			side += base->size_map[0];
		if (q < base->size_map[0] * base->size_map[1] - base->size_map[0])
			draw_line(map[q], map[q + base->size_map[0]], base);
		q++;
	}
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}
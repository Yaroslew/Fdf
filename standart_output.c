/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:16:49 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/05/22 19:41:34 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		standart_output(void *img_ptr, t_map *map, int *size_map)
{
	int 	*data_img;
	int 	q;
	int 	edge;

	q = 0;
	edge = size_map[0];
	data_img = create_img_data(img_ptr);

	while (q < size_map[0] * size_map[1])
	{
		if (q == edge - 1)
		{
			edge += size_map[0];
			if (q < size_map[0] * size_map[1] - size_map[0])
				draw_line(data_img, map[q], map[q + size_map[0]]);
			q++;
		}
		draw_line(data_img, map[q], map[q + 1]);
	if (q < size_map[0] * size_map[1] - size_map[0])
			draw_line(data_img, map[q], map[q + size_map[0]]);
		q++;
	}
}

void	output(t_base *base)
{
	int	q;
	t_map	*map;

	q = 0;
	clean_img(base);
	map = base->map;

	while (q < base->size_map[0] * base->size_map[1])
	{
//		if (base->flag == 1)
//			printf("%d\n", map[q].y + map[q].x);
		base->data_img[base->ver_win * map[q].y + map[q].x] = 0xffffff;
		q++;
	}
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 10, 10);
}
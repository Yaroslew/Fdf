/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:16:49 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/04/07 17:55:35 by pcorlys-         ###   ########.fr       */
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
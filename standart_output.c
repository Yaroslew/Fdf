/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:16:49 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/04/07 17:05:50 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			standart_output(void *img_ptr, t_map *map, int *size_map)
{
	int 	*data_img;

	data_img = create_img_data(img_ptr);
	draw_line(data_img, map[0], map[27* 30 + 1]);
}
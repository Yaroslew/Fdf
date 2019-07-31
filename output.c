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

void			stdOutput(t_base *base)
{
	int			q;

	q = 0;
	if (base->mapDraw = malloc(sizeof(t_map) * (base->size_map[0] * base->size_map[1])))
			mess_err();
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapDraw[q].x = base->map[q].x;
		base->mapDraw[q].y = base->map[q].y;
		base->mapDraw[q].z = base->map[q].z;
		base->mapDraw[q].color = base->map[q].color;
		q++;
	}
	draw_map(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}
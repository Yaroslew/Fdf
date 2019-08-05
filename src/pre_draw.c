/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonard <sleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:59:08 by sleonard          #+#    #+#             */
/*   Updated: 2019/05/11 00:01:12 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdfheader.h"

void	pre_draw(t_base *base)
{
	int q;

	freeimage(base);
	q = 0;
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapdraw[q].x = (int)(base->mapfl[q].x + 0.5);
		base->mapdraw[q].y = (int)(base->mapfl[q].y + 0.5);
		base->mapdraw[q].z = (int)(base->mapfl[q].z + 0.5);
		q++;
	}
	draw_map(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}

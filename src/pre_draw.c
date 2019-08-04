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

#include "../includes/fdfHeader.h"

void	pre_draw(t_base *base)
{
	int q;

	freeImage(base);
	q = 0;
	while (q < base->size_map[0] * base->size_map[1])
	{
		base->mapDraw[q].x = (int)(base->mapFl[q].x + 0.5);
		base->mapDraw[q].y = (int)(base->mapFl[q].y + 0.5);
		base->mapDraw[q].z = (int)(base->mapFl[q].z + 0.5);
		q++;
	}
	draw_map(base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}
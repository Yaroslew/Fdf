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

#include "../includes/fdfHeader.h"

typedef void	(*dispatch)(t_base *base, int key);

static	dispatch const r_dispatch[269] =
		{
			[53] = exitMy,
			[126] = turnX,
			[125] = turnX,
			[27] = scale,
			[24] = scale,
			[6] = turnZ,
			[7] = turnZ,
			[123] = turnY,
			[124] = turnY,
			[48] = parrProjection,
			[18] = color_draw,
			[19] = color_draw,
			[20] = color_draw,
			[0] = moveX,
			[2] = moveX,
			[13] = moveY,
			[1] = moveY,
		};

int de_key(int key, t_base *base)
{
	if (key == 53 || key == 126 || key == 125 || key == 6 || key == 7 ||
	key == 123 || key == 124 || key == 12 || key == 13 || key == 48 ||
	key == 4 || key == 5 || key == 27 || key == 24 || key == 2 ||
	key == 0 || key == 1 || key == 18 || key == 19 || key == 20)
		r_dispatch[key](base, key);
	return (key);
}

void	exitMy(t_base *base, int flag)
{
	exit(0);
}
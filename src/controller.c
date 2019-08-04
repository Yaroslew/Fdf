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
			[12] = slantingR,
			[13] = slantingR,
			[48] = parrProjection,
			[18] = color_draw,
		};

int de_key(int key, t_base *base)
{
	if (key == 53 || key == 126 || key == 125 || key == 6 || key == 7 ||
	key == 123 || key == 124 || key == 12 || key == 13 || key == 48 ||
	key == 4 || key == 5 || key == 27 || key == 24)
		r_dispatch[key](base, key);
	return (key);
}

void	exitMy(t_base *base, int flag)
{
	exit(0);
}
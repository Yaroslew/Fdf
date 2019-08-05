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

#include "../includes/fdfheader.h"

typedef void	(*t_dispatch)(t_base *base, int key);

static			t_dispatch const g_dispatch[269] =
{
	[53] = exitmy,
	[126] = turnx,
	[125] = turnx,
	[27] = scale,
	[24] = scale,
	[6] = turnz,
	[7] = turnz,
	[123] = turny,
	[124] = turny,
	[48] = parrprojection,
	[18] = color_draw,
	[19] = color_draw,
	[20] = color_draw,
	[0] = movex,
	[2] = movex,
	[13] = movey,
	[1] = movey,
};

int				de_key(int key, t_base *base)
{
	if (key == 53 || key == 126 || key == 125 || key == 6 || key == 7 ||
	key == 123 || key == 124 || key == 12 || key == 13 || key == 48 ||
	key == 4 || key == 5 || key == 27 || key == 24 || key == 2 ||
	key == 0 || key == 1 || key == 18 || key == 19 || key == 20)
		g_dispatch[key](base, key);
	return (key);
}

void			exitmy(t_base *base, int flag)
{
	ft_printf("Выход\n");
	exit(0);
}

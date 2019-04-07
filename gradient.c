/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:58:47 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/03/09 09:39:40 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static double	percent(int start, int end, int current)
{
	double		placement;
	double		distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static double			percentage(t_coord *crd, t_coord one, t_coord two)
{
	double		percentage;

	if ((two.x - crd[5].x ) > (two.y - crd[5].y ))
		percentage = percent(one.x, two.x, crd[5].x);
	else
		percentage = percent(one.y, two.y, crd[5].y);
	return (percentage);
}

static int 		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			color_gradient(t_coord *crd, t_coord one, t_coord two)
{
	int 		red;
	int 		green;
	int 		blue;
	double 		per;

	per = percentage(crd, one, two);
	red = get_light((one.color >> 16) & 0xFF, (two.color >> 16) & 0xFF, per);
	green = get_light((one.color >> 8) & 0xFF, (two.color >> 8) & 0xFF, per);
	blue = get_light(one.color & 0xFF, two.color & 0xFF, per);
	return ((red << 16) | (green << 8) | blue);
}
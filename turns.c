/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:52:26 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/06/01 20:02:38 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void degree_xyz(t_base *base, int flag, int xyz)
{
	if (flag)
	{
		if (xyz == 0)
			base->degree_x += base->degree_std;
		if (xyz == 1)
			base->degree_y += base->degree_std;
		if (xyz == 2)
			base->degree_z += base->degree_std;
	}
	else
	{
		if (xyz == 0)
			base->degree_x -= base->degree_std;
		if (xyz == 1)
			base->degree_y -= base->degree_std;
		if (xyz == 2)
			base->degree_z -= base->degree_std;
	}
}

void		turn_x(t_base *base, int flag)
{
	int		q;
	t_map	*map;
	t_map	*copy;
	int		sum;
	double	degree;

	sum = base->size_map[0] * base->size_map[1];
	copy = base->copy_map;
	map = base->map;
	q = 0;
	degree_xyz(base, flag, 0);
	degree = base->degree_x;
	while (q < sum)
	{
		map[q].y = (double)copy[q].y * cos(degree) + ((double)copy[q].z * sin(degree));
		map[q].z = (-(double)copy[q].y * sin(degree)) + ((double)copy[q].z * cos(degree));
		q++;
	}
	output(base);
}

void		turn_y(t_base *base, int flag)
{
	int		q;
	t_map	*map;
	t_map	*copy;
	int		sum;
	double	degree;

	sum = base->size_map[0] * base->size_map[1];
	map = base->map;
	copy = base->copy_map;
	q = 0;
	degree_xyz(base, flag, 1);
	degree = base->degree_y;
	while (q < sum)
	{
		map[q].x = (double)copy[q].x * cos(degree) + ((double)copy[q].z * sin(degree));
		map[q].z = (-(double)copy[q].x) * sin(degree) + ((double)copy[q].z * cos(degree));
		q++;
	}

	output(base);
}


void		turn_z(t_base *base, int flag)
{
	int		q;
	t_map	*map;
	t_map	*copy;
	int		sum;
	double	degree;

	sum = base->size_map[0] * base->size_map[1];
	map = base->map;
	copy = base->copy_map;
	q = 0;
	degree_xyz(base, flag, 2);
	degree = base->degree_z;
	while (q < sum)
	{
		map[q].x = (double)copy[q].x * cos(degree) - sin(degree) * (double)copy[q].y;
		map[q].y = (double)copy[q].x * sin(degree) + cos(degree) * (double)copy[q].y;
		q++;
	}
	output(base);
}

void	std_out(t_base *base)
{
	int		q;
	t_map	*map;
	int		sum;

	sum = base->size_map[0] * base->size_map[1];
	map = base->map;
	q = 0;
	while (q < sum)
	{
		map[q].x = base->copy_map[q].x;
		map[q].y = base->copy_map[q].y;
		map[q].z = base->copy_map[q].z;
		map[q].color = base->copy_map[q].color;
		q++;
	}
	base->degree_x = base->degree_std;
	base->degree_y = base->degree_std;
	base->degree_z = base->degree_std;
	output(base);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:16:43 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/06/01 17:10:32 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void not_malloc(void)
{
	write(1, "Error - not malloc\n", 19);
	exit(0);
}

static int de_key(int key, t_base *base)
{
	if (key == 53)
		exit(0);
	if (key == 125)
		turn_x(base, 1);
	if (key == 126)
		turn_x(base, 0);
	if (key == 123)
		turn_y(base, 1);
	if (key == 124)
		turn_y(base, 0);
	if (key == 36)
		std_out(base);
	if (key == 6)
		turn_z(base, 0);
	if (key == 7)
		turn_z(base, 1);

	return (key);
}

static void test_map(t_base *base)
{
	int q = 0;
	t_map *map;

	map = base->map;
	while (q < base->size_map[0] * base->size_map[1])
	{
		printf("x=%d y=%d z=%d \n", map[q].x, map[q].y, map[q].z);
		q++;
	}
}

int main(int argc, char **argv)
{
	t_base	*base;

	if (!(base = malloc(sizeof(t_base) * 1)))
		not_malloc();
	valid(argc, argv[1], base->size_map);
	base->hor_win = 1000;
	base->ver_win = 1000;
	base->scale = 10;
	base->degree_std = 0.174533;
	base->standart_color = 0xff;
	base->map = record_map(argv[1], base->size_map, base);
	base->copy_map = record_map(argv[1], base->size_map, base);
//	test_map(base);
	base->mlx_ptr = mlx_init();
	base->win_ptr = mlx_new_window(base->mlx_ptr, base->ver_win, base->hor_win, "Fdf");
	base->img_ptr = create_img(base);
	base->data_img = (int*)create_img_data(base->img_ptr);
	output(base);

	mlx_key_hook(base->win_ptr, de_key, (t_base*)base);


	mlx_loop(base->mlx_ptr);
	return (0);
}
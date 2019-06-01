/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:16:43 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/06/01 19:38:20 by pcorlys-         ###   ########.fr       */
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

static void test(t_base *base)
{
	base->map = malloc(sizeof(t_map) * 3);
	base->map[0].x = 50;
	base->map[0].y = 50 ;
	base->map[0].z = 0;
	base->map[0].color =0xffffff ;

	base->map[1].x = 25;
	base->map[1].y = 25 ;
	base->map[1].z = 0;
	base->map[1].color =0xffffff ;

	base->map[2].x = 25;
	base->map[2].y = 75 ;
	base->map[2].z = 0;
	base->map[2].color =0xffffff ;



	base->copy_map = malloc(sizeof(t_map) * 3);
	base->copy_map[0].x = 50;
	base->copy_map[0].y = 50 ;
	base->copy_map[0].z = 0;
	base->copy_map[0].color =0xffffff ;

	base->copy_map[1].x = 25;
	base->copy_map[1].y = 25;
	base->copy_map[1].z = 0;
	base->copy_map[1].color =0xffffff ;

	base->copy_map[2].x = 25;
	base->copy_map[2].y = 75 ;
	base->copy_map[2].z = 0;
	base->copy_map[2].color =0xffffff ;

	draw_line(base->map[0], base->map[1], base);
	draw_line(base->map[0], base->map[2], base);
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);

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
	base->mlx_ptr = mlx_init();
	base->win_ptr = mlx_new_window(base->mlx_ptr, base->ver_win, base->hor_win, "Fdf");
	base->img_ptr = create_img(base);
	base->data_img = (int*)create_img_data(base->img_ptr);
//	test(base);
	output(base);

	mlx_key_hook(base->win_ptr, de_key, (t_base*)base);


	mlx_loop(base->mlx_ptr);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:16:43 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/05/20 19:38:22 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int de_key(int key, t_base *base)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		turn_left(base);


	return (key);
}

int main(int argc, char **argv)
{
	t_map 	*map;
	t_base	*base;

	base = malloc(sizeof(t_base) * 1);
	valid(argc, argv[1], base->size_map);
	map = record_map(argv[1], base->size_map, 10);
	base->mlx_ptr = mlx_init();
	base->win_ptr = mlx_new_window(base->mlx_ptr, 1000, 1000, "Fdf");
	base->img_ptr = create_img(base->mlx_ptr);


	standart_output(base->img_ptr, map, base->size_map);
	mlx_key_hook(base->win_ptr, de_key, (t_base*)base);

	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
	mlx_loop(base->mlx_ptr);
	return 0;
}
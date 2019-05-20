/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:16:43 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/05/20 16:17:21 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv)
{
	int 	size_map[2];
	t_map 	*map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	valid(argc, argv[1], size_map);

	map = record_map(argv[1], size_map, 10);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Fdf");
	img_ptr = create_img(mlx_ptr);

	standart_output(img_ptr, map, size_map);

	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return 0;
}
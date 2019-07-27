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

#include "fdfHeader.h"

static void init_base(t_base *base)
{
	if (!(base = malloc(sizeof(t_base) * 1)))
		mess_err(0);
	if (!(base->size_map = malloc(sizeof(int) * 2)))
		mess_err(0);
	base->size_map[0] = 0;
	base->size_map[1] = 0;
	base->scale = 10;
	base->standart_color = 0xffffff;

	if(!(base->lineDraw = malloc(sizeof(t_line))))
		mess_err(0);
	base->lineDraw->posCenterHor = (base->win_hor - (base->size_map[0] *
	base->scale)) / 2;
	base->lineDraw->posCenterHor = (base->win_ver - (base->size_map[0] *
	base->scale)) / 2;
}

static void init_mlx_win(t_base *base)
{
	int		endian;
	int		depth;
	int		size_line;

	base->win_hor = 1000;
	base->win_ver = 1000;
	base->mlx_ptr = mlx_init();
	base->win_ptr = mlx_new_window(base->mlx_ptr, base->win_hor, base->win_ver, "Fdf");
	base->img_ptr = mlx_new_image(base->mlx_ptr, base->win_hor, base->win_ver);
	base->data_img = (int *)mlx_get_data_addr(base->img_ptr, &depth, &size_line, &endian);
}

static int de_key(int key, t_base *base)
{
	if (key == 53)
			exit(0);

	return (key);
}

int main(int ar, char **av)
{
	t_base	base;

	init_base(&base);
	init_mlx_win(&base);
	valid(ar, av[1], base.size_map);
	record_map(av[1], &base);

	mlx_key_hook(base.win_ptr, de_key, (t_base*)(&base));
	mlx_loop(base.mlx_ptr);
}


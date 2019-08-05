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

static t_base *init_base(void)
{
	t_base *base;

	if (!(base = malloc(sizeof(t_base) * 1)))
		mess_err(0);
	base->size_map[0] = 0;
	base->size_map[1] = 0;
	base->scale = 10;
	base->standart_color = 0xffffff;
	base->angle = M_PI / 18.0;
	base->angleSlantingR = 0;
	base->flagColor = 0;

	if(!(base->lineDraw = malloc(sizeof(t_line))))
		mess_err(0);
	return (base);
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

int main(int ar, char **av)
{
	t_base	*base;

	base = init_base();
	valid(ar, av[1], base);
	record_map(av[1], base);
	init_mlx_win(base);
	stdOutput(base);
	mlx_hook(base->win_ptr, 2, 0, de_key, base);
	mlx_loop(base->mlx_ptr);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_and_imgdata.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:39:06 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/03/30 10:26:54 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		*create_img(void *mlx_ptr)
{
	void	*img_ptr;

	return (mlx_new_image(mlx_ptr, 1000, 1000));
}

int 		*create_img_data(void *img_ptr)
{
	int		endian;
	int		depth;
	int		size_line;

	return ((int *)mlx_get_data_addr(img_ptr, &depth, &size_line, &endian));
}

void		delete_img(void *img_ptr, void *mlx_ptr)
{
	mlx_destroy_image(mlx_ptr, img_ptr);
}
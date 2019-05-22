/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_and_imgdata.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:39:06 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/05/22 20:04:43 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		*create_img(t_base *base)
{
	void	*img_ptr;

	return (mlx_new_image(base->mlx_ptr, base->hor_win, base->ver_win));
}

int 	*create_img_data(void *img_ptr)
{
	int		endian;
	int		depth;
	int		size_line;

	return ((int *)mlx_get_data_addr(img_ptr, &depth, &size_line, &endian));
}

void		clean_img(t_base *base)
{
	int 	q;
	int *data;

	q = 0;
	data = base->data_img;
	while (q < base->hor_win * base->ver_win)
	{
		data[q] = 0;
		q++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:17:56 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/04/01 15:30:43 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
#define FDF_HEADER_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_map
{
	int 		x;
	int 		y;
	int 		z;
	int 		color;
}				t_map;

int				*valid(int argc, char *argv);
t_map			*record_map(char *argv, int *size_map, int scale);
void			standart_output(void *img_ptr, t_map *map, int *size_map);
int 			*create_img_data(void *img_ptr);
void			*create_img(void *mlx_ptr);
void			delete_img(void *img_ptr, void *mlx_ptr);
void			draw_line(int *img_data, t_map one, t_map two);

#endif

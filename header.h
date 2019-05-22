/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:17:56 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/05/22 19:34:57 by pcorlys-         ###   ########.fr       */
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

typedef struct	s_base
{
	int			size_map[2];
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_map		*map;
	int 		*data_img;
	int 		ver_win;
	int 		hor_win;
	int 		flag;

}				t_base;

void			valid(int argc, char *argv, int *size_map);
t_map			*record_map(char *argv, int *size_map, int scale);
void			standart_output(void *img_ptr, t_map *map, int *size_map);
int 			*create_img_data(void *img_ptr);
void			*create_img(t_base *base);
void			delete_img(void *img_ptr, void *mlx_ptr);
void			draw_line(int *img_data, t_map one, t_map two);
void			clean_img(t_base *base);
void			turn_left(t_base *base);
void			output(t_base *base);

#endif

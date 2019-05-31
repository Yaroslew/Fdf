/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:17:56 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/05/31 17:10:21 by pcorlys-         ###   ########.fr       */
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
	t_map		*copy_map;
	t_map		*c_map;
	int 		*data_img;
	int 		ver_win;
	int 		hor_win;
	int			position;
	double		degree_x;
	double		degree_y;
	double 		degree_z;
	double 		degree_std;
	int 		standart_color;
	int			scale;


}				t_base;

void			valid(int argc, char *argv, int *size_map);
t_map			*record_map(char *argv, int *size_map, t_base *base);
int 			*create_img_data(void *img_ptr);
void			*create_img(t_base *base);
void			clean_img(t_base *base);
void			turn_x(t_base *base, int flag);
void			output(t_base *base);
void			draw_line(t_map one, t_map two, t_base *base);
int				get_color(t_map current, t_map start, t_map end, int flag);
void			turn_y(t_base *base, int flag);
void			std_out(t_base *base);

#endif

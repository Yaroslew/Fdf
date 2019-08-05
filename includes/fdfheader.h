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

#ifndef FDF_FDFHEADER_H
# define FDF_FDFHEADER_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct	s_map
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_map;

typedef struct	s_mapfl
{
	double			x;
	double			y;
	double			z;
}				t_mapfl;

typedef struct	s_line
{
	t_map		one;
	t_map		two;
	t_map		start;
	int			poscenterver;
	int			poscenterhor;
	int			deltax;
	int			deltay;
	int			diry;
	float		steperr;
	float		er;
}				t_line;

typedef struct	s_base
{
	int			size_map[2];
	int			scale;
	double		angle;
	int			standart_color;
	t_map		*map;
	t_map		*mapdraw;
	t_mapfl		*mapfl;

	int			flagparrproj;
	int			flagcolor;

	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			win_hor;
	int			win_ver;
	int			*data_img;

	t_line		*linedraw;
}				t_base;

void			mess_err(int a);
void			valid(int ac, char *av, t_base *base);
void			record_map(char *argv, t_base *base);
int				get_color(t_map current, t_map start, t_map end, int flag);
void			draw_map(t_base *base);
void			stdoutput(t_base *base);
void			turnx(t_base *base, int flag);
void			turny(t_base *base, int flag);
void			turnz(t_base *base, int flag);
void			freeimage(t_base *base);
void			pre_draw(t_base *base);
void			parrprojection(t_base *base, int flag);
void			exitmy(t_base *base, int flag);
int				de_key(int key, t_base *base);
void			scale(t_base *base, int flag);
void			color_draw(t_base *base, int flag);
void			movex(t_base *base, int flag);
void			movey(t_base *base, int flag);
void			free_arr(char ***arr);

#endif

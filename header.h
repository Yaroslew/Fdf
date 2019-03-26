/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:17:56 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/03/26 19:56:08 by pcorlys-         ###   ########.fr       */
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
t_map			*record_map(char *argv, int *size_map);
#endif

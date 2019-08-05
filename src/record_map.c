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

#include "../includes/fdfheader.h"

static int	symbol(int flag, char base)
{
	char	a;
	char	ab;
	int		res;

	res = 10;
	a = 'A';
	ab = 'a';
	if (flag)
	{
		while (ab != base)
		{
			res++;
			ab++;
		}
	}
	else
	{
		while (a != base)
		{
			res++;
			a++;
		}
	}
	return (res);
}

static int	write_color(char *arr)
{
	int		q;
	int		r;
	int		res;
	int		temp;

	r = 0;
	q = 2;
	res = 0;
	while (arr[q])
	{
		if (arr[q] > 64 && arr[q] < 71)
			temp = symbol(0, arr[q]);
		if (arr[q] > 96 && arr[q] < 103)
			temp = symbol(1, arr[q]);
		if (arr[q] > 47 && arr[q] < 58)
			temp = arr[q] - 48;
		res += temp * (pow(16, r));
		q++;
		r++;
	}
	return (res);
}

static void	write_color_z(char *split, t_map *map, int ind, t_base *base)
{
	int		q;
	char	**arr;

	q = 0;
	while (split[q])
	{
		if (split[q] == ',')
		{
			arr = ft_strsplit(split, ',');
			map[ind].z = ft_atoi(arr[0]) * base->scale;
			map[ind].color = write_color(arr[1]);
			free_arr(&arr);
			return ;
		}
		q++;
	}
	map[ind].z = ft_atoi(split) * base->scale;
	map[ind].color = base->standart_color;
}

static void	write_line(t_map *map, int fd, int *size_map, t_base *base)
{
	char	**split;
	char	*line;
	int		q;
	int		r;
	int		ind;

	q = 0;
	r = 0;
	ind = 0;
	while (get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ' ');
		while (split[q])
		{
			map[ind].x = q * base->scale;
			map[ind].y = r * base->scale;
			write_color_z(split[q], map, ind, base);
			q++;
			ind++;
		}
		r++;
		q = 0;
		free_arr(&split);
	}
}

void		record_map(char *argv, t_base *base)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 3)
		mess_err(2);
	if (!(base->map = malloc(sizeof(t_map) *
		(base->size_map[0] * base->size_map[1]))))
		mess_err(0);
	write_line(base->map, fd, base->size_map, base);
	close(fd);
}

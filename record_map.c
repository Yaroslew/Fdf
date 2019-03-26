/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 10:48:44 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/03/26 20:35:48 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	write_color(char *arr)
{
	int 	res;
	int 	q;
	int		temp;
	int 	r;

	res = 0;
	q = 2;
	r = 0;
	while(arr[q])
	{
		if (arr[q] > 47 && arr[q] < 58)
			arr[q] -= 48;
		else if (arr[q] > 64 && arr[q] < 71)
			arr[q] -= 55;
		else if (arr[q] > 96 && arr[q] < 103)
			arr[q] -= 87;
		q++;
	}
	q--;
	while(q > 1)
	{
		temp += arr[q] * pow(16, r);
		q--;
		r++;
	}
	return (temp);
}

static void write_color_z(char *split, t_map *map, int ind)
{
	int 	q;
	char 	**arr;

	q = 0;
	while(split[q])
	{
		if (split[q] == ',')
		{
			arr = ft_strsplit(split, ',');
			map[ind].z = ft_atoi(arr[0]);
			map[ind].color = write_color(arr[1]);
			return ;
		}
		q++;
	}
	map[ind].z = ft_atoi(split);
	map[ind].color = 0;
}

static void	write_line(t_map *map, int fd, int *size_map)
{
	char 	**split;
	char 	*line;
	int 	q;
	int 	r;
	int 	ind;

	q = 0;
	r = 0;
	ind = 0;
	while(get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ' ');
		while(split[q])
		{
			map[ind].x = q;
			map[ind].y = r;
			printf("x=%d y=%d r=%d\n", map[q].x, map[q].y, r);
//			write_color_z(split[q], map, ind);

			q++;
			ind++;
		}
		r++;
		q = 0;
	}
}

t_map			*record_map(char *argv, int *size_map)
{
	int 	fd;
	t_map 	*map;

	fd = open(argv, O_RDONLY);
	map = malloc(sizeof(t_map) * (size_map[0] * size_map[1]));
	write_line(map, fd, size_map);

	close(fd);
	return (map);
}
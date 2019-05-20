/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 10:48:44 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/04/07 17:17:23 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	free_arr(char ***arr)
{
	int		q;
	char	**temp;

	temp = *arr;
	q = 0;
	while (temp[q])
	{
		free(temp[q]);
		q++;
	}
	**arr = NULL;
}

static int	write_color(char *arr)
{
	int		q;
	int		temp;
	int		r;

	q = 2;
	r = 0;
	while (arr[q])
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
	while (q > 1)
	{
		temp += arr[q] * pow(16, r);
		q--;
		r++;
	}
	return (temp);
}

static void	write_color_z(char *split, t_map *map, int ind)
{
	int		q;
	char	**arr;

	q = 0;
	while (split[q])
	{
		if (split[q] == ',')
		{
			arr = ft_strsplit(split, ',');
			map[ind].z = ft_atoi(arr[0]);
			map[ind].color = write_color(arr[1]);
			free_arr(&arr);
			return ;
		}
		q++;
	}
	map[ind].z = ft_atoi(split);
	map[ind].color = 0;
}

static void	write_line(t_map *map, int fd, int *size_map, int scale)
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
			map[ind].x = q * scale;
			map[ind].y = r * scale;
			write_color_z(split[q], map, ind);
			q++;
			ind++;
		}
		r++;
		q = 0;
		free_arr(&split);
	}
}

t_map		*record_map(char *argv, int *size_map, int scale)
{
	int		fd;
	t_map	*map;

	fd = open(argv, O_RDONLY);
	if (fd < 3)
	{
		write(1, "File not open\n", 14);
		exit(0);
	}
	map = malloc(sizeof(t_map) * (size_map[0] * size_map[1]));
	write_line(map, fd, size_map, scale);
	close(fd);
	return (map);
}

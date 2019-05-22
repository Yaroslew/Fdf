/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:35:17 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/05/22 18:20:29 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int check_color(int q, char *line)
{
	int count;

	count = 0;
	if (line[q + 1] != '0' && line[q + 2] != 'x')
	{
		write(1, "Error - not true prefix code-color\n", 35);
		exit(0);
	}
	q += 3;
	while (line[q] != ' ' && line[q] != '\0' && line[q] != '\t')
	{
		if ((line[q] > 47 && line[q] < 58) || (line[q] > 64 &&
		line[q] < 71) || (line[q] > 96 && line[q] < 103))
		{
			q++;
			count++;
		}
		else
		{
			write(1, "Error - not true code color\n", 40);
			exit(0);
		}
		if (count > 8)
		{
			write(1, "Error - more tnan 8 symbols in color code\n", 50);
			exit(0);
		}
	}
	return (q);
}

static int check_ver(int ver, int *size_map)
{
	if (size_map[0] == 0)
	{
		size_map[0] = ver;
		return (0);
	}
	else if (size_map[0] != ver)
	{
		write(1, "Error - strings dont same\n", 27);
		exit(0);
	}
	return (0);
}

static void check_str(int fd, int *size_map)
{
	char	*line;
	int		q;
	int		ver;

	ver = 0;
	while (get_next_line(fd, &line))
	{
		size_map[1]++;
		q = 0;
		while(line[q])
		{
			if ((line[q] < '0' || line[q] > '9') && line[q] != ' ' &&
				line[q] != '\t' && line[q] != '-' && line[q] != ',')
			{
				write(1, "Error - not true symbol\n", 24);
				exit(0);
			}
			if ((line[q] > 47 && line[q] < 58) && (line[q + 1] == ' ' ||
			line[q + 1] == '\t' || line[q + 1] == ',' || line[q + 1] == '\0'))
				ver++;
			if (line[q] == ',')
				q = check_color(q, line);
			q++;
		}
		ver = check_ver(ver, size_map);
	}
}

void valid(int ac, char *av, int *size_map)
{
	int fd;
	size_map[0] = 0;
	size_map[1] = 0;

	if (ac != 2)
	{
		write(1, "Error - you have more than one argument\n", 40);
		exit(0);
	}
	if (!(fd = open(av, O_RDONLY)))
	{
		write(1, "Error - not open file\n", 22);
		exit(0);
	}
	check_str(fd, size_map);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:35:17 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/03/24 12:30:35 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		errors_valid(int err)
{
	if (err == 1)
		write(1, "Error! Not true a color\n", 24);
	if (err == 2)
		write(1, "Error! not true a code color!\n", 30);
	if (err == 3)
		write(1, "Usage: ./fdf <filename> \n", 32);
	if (err == 4)
		write(1, "Error! Not same strings\n", 24);
	if (err == 5)
		write(1, "Error! Not open file\n", 21);
	if (err == 6)
		write(1, "Error! Much digit in color\n", 27);
	if (err == 7)
		write(1, "Error! Not valid a digit\n", 25);
	exit(0);
}

static int		check_color(char *line, int q)
{
	int			cost_num_in_color;

	cost_num_in_color = 0;
	if (line[q + 1] != '0' && line[q + 2] != 'x')
		errors_valid(1);
	q += 3;
	while (line[q] != 32 && line[q] != '\t')
	{
		if ((line[q] >= 48 && line[q] <= 57)
		|| (line[q] >= 65 && line[q] <= 70)
		|| (line[q] >= 97 && line[q] <= 102))
			q++;
		else
			errors_valid(2);
		cost_num_in_color++;
		if (cost_num_in_color > 8)
			errors_valid(6);
	}
	return (q - 1);
}

static int		*valid_line(int fd, int q, int old, int *size)
{
	int			new;
	char		*line;
	int			ver;

	new = 0;
	ver = 0;
	while (get_next_line(fd, &line))
	{
		while (line[q])
		{
			if ((line[q] >= '0' && line[q] <= '9') || line[q] == ',')
			{
				new++;
				while (line[q] >= '0' && line[q] <= '9')
					q++;
			}
			if (line[q] == ',')
				q = check_color(line, q);
			if (line[q] != ' ' && line[q] != '\t' && line[q])
				errors_valid(7);
			q++;
		}
		if (old != new && (old != 0 || new != 0))
			errors_valid(2);
		(old == new) ? (size[0] = new) : 0;
		old = new;
		new = 0;
		q = 0;
		ver++;
	}
	size[1] = ver;
	return (size);
}

void			valid(int argc, char *argv)
{
	int			fd;
	int			q;
	int			old;
	int			*size;

	size = malloc(sizeof(int) * 2);
	q = 0;
	old = 0;
	if (argc != 2)
		errors_valid(2);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		errors_valid(5);
	size = valid_line(fd, q, old, size);
	printf("x=%d y= %d\n", size[0], size[1]);
	close(fd);
}

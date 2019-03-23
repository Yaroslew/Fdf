/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:35:17 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/03/23 13:11:05 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	errors_valid(int err)
{
	if (err == 1)
		write(1, "Error! Not true a color\n", 24);
	if (err == 2)
		write(1, "Error! not true a code color!\n", 30);
	if (err == 3)
		write(1, "Usage: ./fdf <filename> \n", 32);
	if (err == 4)
		write(1, "Error! Not same strings\n", 24);
	exit(0);

}

static int 	check_color(char *line, int q)
{
	if (line[q + 1] != '0' && line[q + 2] != 'x')
		errors_valid(1);
	q += 3;
	while (line[q] != ' ' || line[q] != '\t')
	{
		if ((line[q] >= 48 && line[q] <= 57)
		|| (line[q] >= 65 && line[q] <= 70)
		|| (line[q] >= 97 && line[q] <= 102))
			q++;
		else
			errors_valid(2);
	}
	return (q - 1);
}

void		valid(int argc, char *argv)
{
	char	*line;
	int 	fd;
	int		old;
	int 	q;
	int		new;

	q = 0;
	new = 0;
	old = 0;
	if (argc != 2)
		errors_valid(2);
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		while (line[q])
		{
			if ((line[q] != ' ' || line[q] != '\t')
			&& (line[q] >= 0 && line[q] <= 9))
				new++;
			if (line[q] == ',')
				q = check_color(line, q);
			q++;
		}
		if (old != new && (old != 0 || new != 0 ))
			errors_valid(2);
		old = new;
		new = 0;
	}
}

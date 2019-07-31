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

#include "fdfHeader.h"

static int check_color(int q, char *line)
{
	int count;

	count = 0;
	if (line[q + 1] != '0' && line[q + 2] != 'x')
		mess_err(5);
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
			mess_err(6);
		if (count > 8)
			mess_err(7);
	}
	return (q);
}

static int check_ver(int ver, t_base *base)
{
	if (base->size_map[0] == 0)
	{
		base->size_map[0] = ver;
		return (0);
	}
	else if (base->size_map[0] != ver)
		mess_err(4);
	return (0);
}

static void check_str(int fd, t_base *base)
{
	char	*line;
	int		q;
	int		ver;

	while (get_next_line(fd, &line))
	{
		ver = 0;
		base->size_map[1]++;
		q = 0;
		while(line[q])
		{
			if ((line[q] < '0' || line[q] > '9') && line[q] != ' ' &&
				line[q] != '\t' && line[q] != '-' && line[q] != ',')
				mess_err(3);
			if ((line[q] > 47 && line[q] < 58) && (line[q + 1] == ' ' ||
			line[q + 1] == '\t' || line[q + 1] == ',' || line[q + 1] == '\0'))
				ver++;
			if (line[q] == ',')
				q = check_color(q, line);
			q++;
		}
		ver = check_ver(ver, base);
	}
}

void valid(int ac, char *av, t_base *base)
{
	int fd;


	if (ac != 2)
		mess_err(1);
	if (!(fd = open(av, O_RDONLY)))
		mess_err(2);
	check_str(fd, base);
}


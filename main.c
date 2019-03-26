/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:16:43 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/03/26 19:52:12 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv)
{
	int 	*size_map;
	t_map 	*map;

	size_map = valid(argc, argv[1]);
	map = record_map(argv[1], size_map);

	int q = 0;
	while(q < size_map[0] * size_map[1])
	{
//		printf("x=%d y=%d z=%d color=%d\n", map[q].x, map[q].y, map[q].z, map[q].color);
		q++;
	}
	return 0;
}
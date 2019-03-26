/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:16:43 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/03/26 16:53:48 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv)
{
	int 	*size_map;
	int 	*map;

	size_map = valid(argc, argv[1]);
	map = record_map(argv[1], size_map);

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 11:35:17 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/03/26 16:29:40 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				*valid(int argc, char *argv)
{
	int			*size_map = malloc(sizeof(int) * 2);
	size_map[0] = 27;
	size_map[1] = 34;
	return (size_map);
}


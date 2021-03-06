/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:33:40 by uvarly            #+#    #+#             */
/*   Updated: 2019/03/23 10:18:37 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcat(char *dst, const char *app)
{
	char		*c_dst;
	const char	*c_app;

	c_dst = (char *)dst + ft_strlen(dst);
	c_app = (const char *)app;
	while (*c_app)
	{
		*c_dst = *c_app;
		c_dst++;
		c_app++;
	}
	*c_dst = 0;
	return (dst);
}

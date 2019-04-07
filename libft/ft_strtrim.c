/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:00:36 by uvarly            #+#    #+#             */
/*   Updated: 2019/03/23 10:18:37 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	start;
	unsigned int	end;

	if (!s)
		return (0);
	str = (char *)s;
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	if (!*str)
		return (ft_strnew(0));
	start = str - s;
	while (*str)
		str++;
	str--;
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str--;
	end = str - s;
	return (ft_strsub(s, start, end - start + 1));
}

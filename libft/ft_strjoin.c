/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:48:07 by uvarly            #+#    #+#             */
/*   Updated: 2019/03/23 10:18:37 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (0);
	str = ft_strcat(ft_strcat(str, (char *)s1), (char *)s2);
	return (str);
}

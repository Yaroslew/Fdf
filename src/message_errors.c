/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 10:48:44 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/06/01 17:13:03 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdfHeader.h"

void	mess_err(int a)
{
	if (a == 0)
		ft_printf("Не получилось выделить память для массива. Чекай маллок\n");
	if (a == 1)
		ft_printf("Неправильный аргумент. Вы должны использовать только один файл\n");
	if (a == 2)
		ft_printf("Файл не был открыт. Проверьте файл или указанный путь\n");
	if (a == 3)
		ft_printf("Невалидный файл. Неправильный символ\n");
	if (a == 4)
		ft_printf("Невалидный файл. Строки имеют разную длину\n");
	if (a == 5)
		ft_printf("Невалидный файл. Неправильный префикс при указании цветового кода\n");
	if (a == 6)
		ft_printf("Невалидный файл. Неправильно написан цветовой код\n");
	if (a == 7)
		ft_printf("Невалидный файл. Цветовой код содержит слишком много символов\n");
	exit(0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 08:00:32 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 08:03:00 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libclr.h"

static	int		ft_bar_red(int where, int size)
{
	where = (where % size + size) % size;
	if (where < size / 6 * 1)
		return (255);
	if (where < size / 6 * 2)
		return ((-255000 / (size / 6)) * (where % (size / 6)) / 1000 + 255);
	if (where < size / 6 * 4)
		return (0);
	if (where < size / 6 * 5)
		return ((255000 / (size / 6)) * (where % (size / 6)) / 1000);
	return (255);
}

static	int		ft_bar_green(int where, int size)
{
	where = (where % size + size) % size;
	if (where < size / 6 * 1)
		return ((255000 / (size / 6)) * (where % (size / 6)) / 1000);
	if (where < size / 6 * 3)
		return (255);
	if (where < size / 6 * 4)
		return ((-255000 / (size / 6)) * (where % (size / 6)) / 1000 + 255);
	return (0);
}

static	int		ft_bar_blue(int where, int size)
{
	where = (where % size + size) % size;
	if (where < size / 6 * 2)
		return (0);
	if (where < size / 6 * 3)
		return ((255000 / (size / 6)) * (where % (size / 6)) / 1000);
	if (where < size / 6 * 5)
		return (255);
	if (where < size / 6 * 6)
		return ((-255000 / (size / 6)) * (where % (size / 6)) / 1000 + 255);
	return (0);
}

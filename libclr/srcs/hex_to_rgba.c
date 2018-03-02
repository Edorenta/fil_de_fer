/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_rgba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 22:05:24 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/02 22:05:58 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libclr.h"

int		hex_r(long clr, int mode)
{
	if (mode == MODE_RGB || mode == MODE_ARGB)
		return (clr >> 16 & 0xFF);
	if (mode == MODE_RGBA)
		return (clr >> 24 & 0xFF);
	return (0);
}

int		hex_g(long clr, int mode)
{
	if (mode == MODE_RGB || mode == MODE_ARGB)
		return (clr >> 8 & 0xFF);
	if (mode == MODE_RGBA)
		return (clr >> 16 & 0xFF);
	return (0);
}

int		hex_b(long clr, int mode)
{
	if (mode == MODE_RGB || mode == MODE_ARGB)
		return (clr & 0xFF);
	if (mode == MODE_RGBA)
		return (clr >> 8 & 0xFF);
	return (0);
}

int		hex_a(long clr, int mode)
{
	if (mode == MODE_ARGB)
		return (clr >> 24 & 0xFF);
	if (mode == MODE_RGBA)
		return (clr & 0xFF);
	return (0);
}

int		*hex_rgba(long clr, int mode, int *ptr)
{
	if (mode == MODE_RGB || mode == MODE_ARGB)
	{
		ptr[0] = clr >> 16 & 0xFF;
		ptr[1] = clr >> 8 & 0xFF;
		ptr[2] = clr & 0xFF;
		ptr[3] = (mode == MODE_RGB ? 0x00 : (clr >> 24 & 0xFF));
	}
	else if (mode == MODE_RGBA)
	{
		ptr[0] = clr >> 24 & 0xFF;
		ptr[1] = clr >> 16 & 0xFF;
		ptr[2] = clr >> 6 & 0xFF;
		ptr[3] = clr & 0xFF;
	}
	return (ptr);
}

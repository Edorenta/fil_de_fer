/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 22:03:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/02 22:05:11 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libclr.h"

int		shade_color(int clr, int pct)
{
	int r[2];
	int g[2];
	int b[2];
	int tmp;

	r[0] = hex_r(clr, MODE_RGB);
	g[0] = hex_g(clr, MODE_RGB);
	b[0] = hex_b(clr, MODE_RGB);
	tmp = pct < 0 ? 0 : 255;
	pct = pct < 0 ? pct * -1 : pct;
	r[1] = (((tmp - r[0]) * pct) / 100) + r[0];
	g[1] = (((tmp - g[0]) * pct) / 100) + g[0];
	b[1] = (((tmp - b[0]) * pct) / 100) + b[0];
	return (rgb_to_hex(r[1], g[1], b[1]));
}

int		shade_opacity(int clr, int pct, int mode)
{
	int a;
	int tmp;

	a = hex_a(clr, mode);
	tmp = pct < 0 ? 0 : 255;
	pct = pct < 0 ? pct * -1 : pct;
	a = (((tmp - a) * pct) / 100) + a;
	clr = (clr | 0xFF000000) ^ 0xFF000000;
	return (clr | a << 24);
}

int		set_opacity(int clr, int lvl)
{
	static int	alpha[22] = {ALPHA_0, ALPHA_5, ALPHA_10, ALPHA_15, ALPHA_20,
		ALPHA_25, ALPHA_30, ALPHA_35, ALPHA_40, ALPHA_45,
		ALPHA_50, ALPHA_55, ALPHA_60, ALPHA_65, ALPHA_70,
		ALPHA_75, ALPHA_80, ALPHA_85, ALPHA_90, ALPHA_95,
		ALPHA_100};

	lvl = lvl > 21 ? (lvl % 21) : lvl;
	clr = (clr | 0xFF000000) ^ 0xFF000000;
	return (clr | (alpha[lvl] << 24));
}

int		blend_color(int clr1, int clr2, int pct)
{
	int r[3];
	int g[3];
	int b[3];

	r[0] = DMIN(hex_r(clr1, MODE_RGB), hex_r(clr2, MODE_RGB));
	g[0] = DMIN(hex_g(clr1, MODE_RGB), hex_g(clr2, MODE_RGB));
	b[0] = DMIN(hex_b(clr1, MODE_RGB), hex_b(clr2, MODE_RGB));
	r[1] = DMAX(hex_r(clr1, MODE_RGB), hex_r(clr2, MODE_RGB));
	g[1] = DMAX(hex_g(clr1, MODE_RGB), hex_g(clr2, MODE_RGB));
	b[1] = DMAX(hex_b(clr1, MODE_RGB), hex_b(clr2, MODE_RGB));
	r[2] = ((r[1] - r[0]) * pct) / 100 + r[0];
	g[2] = ((g[1] - g[0]) * pct) / 100 + g[0];
	b[2] = ((b[1] - b[0]) * pct) / 100 + b[0];
	return (rgb_to_hex(r[2], g[2], b[2]));
}

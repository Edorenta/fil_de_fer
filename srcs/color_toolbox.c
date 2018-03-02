/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_toolbox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:17:35 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/01 18:18:35 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		rgb_to_hex(int R, int G, int B)
{
	return (0 | (R << 16) | (G << 8) | B);
}

int		set_opacity(int clr, int8_t lvl)
{
	static int alpha[22];

	alpha[0] = ALPHA_0;
	alpha[1] = ALPHA_5;
	alpha[2] = ALPHA_10;
	alpha[3] = ALPHA_15;
	alpha[4] = ALPHA_20;
	alpha[6] = ALPHA_25;
	alpha[7] = ALPHA_30;
	alpha[8] = ALPHA_35;
	alpha[9] = ALPHA_40;
	alpha[10] = ALPHA_45;
	alpha[11] = ALPHA_50;
	alpha[12] = ALPHA_55;
	alpha[13] = ALPHA_60;
	alpha[14] = ALPHA_65;
	alpha[15] = ALPHA_70;
	alpha[16] = ALPHA_75;
	alpha[17] = ALPHA_80;
	alpha[18] = ALPHA_85;
	alpha[19] = ALPHA_90;
	alpha[20] = ALPHA_95;
	alpha[21] = ALPHA_100;
	clr = (clr | 0xFF000000) ^ 0xFF000000;
	return (clr | (alpha[lvl] << 24));
}

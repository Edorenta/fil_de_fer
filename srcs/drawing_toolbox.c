/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_toolbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:18:36 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 19:39:00 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void			draw_line(t_env *env, t_point a, t_point b)
{
	int x[3];
	int y[3];
	int err[2];

	x[0] = abs(b.x - a.x);
	y[0] = abs(b.y - a.y);
	x[1] = (b.x > a.x ? 1 : -1);
	y[1] = (b.y > a.y ? 1 : -1);
	x[2] = a.x;
	y[2] = a.y;
	err[0] = x[0] - y[0];
	while (!((b.x == x[2]) && (b.y == y[2])))
	{
		ppixel(env, x[2], y[2], gradient(env, vectorize(&a, &b), y[2]));
		err[1] = err[0];
		if (err[1] > -x[0])
		{
			err[0] -= y[0];
			x[2] += x[1];
		}
		if (err[1] <= y[0])
		{
			err[0] += x[0];
			y[2] += y[1];
		}
	}
}

static	void	draw_eight_sym(t_env *env, t_point mid, int pos_x, int pos_y)
{
	ppixel(env, mid.x + pos_x, mid.y + pos_y, mid.clr);
	ppixel(env, mid.x + pos_y, mid.y + pos_x, mid.clr);
	ppixel(env, mid.x - pos_y, mid.y + pos_x, mid.clr);
	ppixel(env, mid.x - pos_x, mid.y + pos_y, mid.clr);
	ppixel(env, mid.x - pos_x, mid.y - pos_y, mid.clr);
	ppixel(env, mid.x - pos_y, mid.y - pos_x, mid.clr);
	ppixel(env, mid.x + pos_y, mid.y - pos_x, mid.clr);
	ppixel(env, mid.x + pos_x, mid.y - pos_y, mid.clr);
}

void			draw_circle(t_env *env, t_point mid, float radius)
{
	int pos_xy[2];
	int dxy[2];
	int err;

	dxy[0] = 1;
	dxy[1] = 1;
	radius *= ((float)env->width) / 100;
	pos_xy[0] = radius - 1;
	pos_xy[1] = 0;
	err = dxy[0] - ((int)radius << 1);
	while (pos_xy[0] >= pos_xy[1])
	{
		draw_eight_sym(env, mid, pos_xy[0], pos_xy[1]);
		if (err <= 0 && (pos_xy[1]++))
		{
			err += dxy[1];
			dxy[1] += 2;
		}
		if (err > 0 && (pos_xy[0]--))
		{
			dxy[0] += 2;
			err += dxy[0] - ((int)radius << 1);
		}
	}
}

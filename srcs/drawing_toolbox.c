/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_toolbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:18:36 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 18:15:51 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		draw_line(t_env *env, t_point a, t_point b)
{
	int x[2];
	int y[2];
	int err[2];

	x[0] = abs(b.x - a.x);
	y[0] = abs(b.y - a.y);
	x[1] = (b.x > a.x ? 1 : -1);
	y[1] = (b.y > a.y ? 1 : -1);
	err[0] = x[0] - y[0];	
	while (!((b.x == a.x) && (b.y == a.y)))
	{
		ppixel(env, a.x, a.y, gradient(env, vectorize(&a, &b), a.y));
		err[1] = err;
		if (err[1] > -x[0])
		{
			err[0] -= y[0];
			a.x += x[1];
		}
		if (err[1] <= y[0])
		{
			err[0] += x[0];
			a.y += y[1];
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

void			draw_circle(t_env *env, t_point mid, float pct_radius)
{
	int radius = (int)((float)env->width * pct_radius) / 100;
	int pos_x = radius-1;
	int pos_y = 0;
	int dx = 1;
	int dy = 1;
	int err[0] = dx - (radius << 1);

	while (pos_x >= pos_y)
	{
		draw_eight_sym(env, mid, pos_x, pos_y);
		if (err[0] <= 0)
		{
			pos_y++;
			err[0] += dy;
			dy += 2;
		}
		if (err[0] > 0)
		{
			pos_x--;
			dx += 2;
			err[0] += dx - (radius << 1);
		}
	}
}


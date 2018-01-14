/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_toolbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:18:36 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/14 15:05:53 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void			draw_vector(t_env *env, t_point *a, t_point *b,
				int clr1, int clr2)
{

	int dx, dy, p, x, y;

	dx = b->x - a->x;
	dy = b->y - a->y;
	x = a->x;
	y = a->y;
	p = 2 * dy - dx;
	while(x < b->x)
	{
		if(p >= 0)
		{
			ppixel(env, x, y, clr1);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			ppixel(env, x, y, clr1);
			p = p + 2 * dy;
		}
		x++;
	}
}

static	void	draw_eight_sym(t_env *env, t_point *mid, int x, int y, int clr)
{
	ppixel(env, mid->x + x, mid->y + y, clr);
	ppixel(env, mid->x + y, mid->y + x, clr);
	ppixel(env, mid->x - y, mid->y + x, clr);
	ppixel(env, mid->x - x, mid->y + y, clr);
	ppixel(env, mid->x - x, mid->y - y, clr);
	ppixel(env, mid->x - y, mid->y - x, clr);
	ppixel(env, mid->x + y, mid->y - x, clr);
	ppixel(env, mid->x + x, mid->y - y, clr);
}

void			draw_circle(t_env *env, t_point *mid, float pct_radius, int clr)
{
	int radius = (int)((float)env->width * pct_radius) / 100;
	int x = radius-1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1);

	while (x >= y)
	{
		draw_eight_sym(env, mid, x, y, clr);
		if (err <= 0)
		{
			y++;
			err += dy;
			dy += 2;
		}
		if (err > 0)
		{
			x--;
			dx += 2;
			err += dx - (radius << 1);
		}
	}
}


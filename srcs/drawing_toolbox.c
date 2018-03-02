/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_toolbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:18:36 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/01 10:13:52 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		draw_line(t_env *env, t_point *a, t_point *b)
{
	int x[4];
	int y[4];

	x[0] = a->x;
	x[1] = b->x;
	x[2] = abs(x[1] - x[0]);
	y[0] = a->y;
	y[1] = b->y;
	y[2] = abs(y[1] - y[0]);
	x[3] = (x[1] > x[0] ? 1 : -1);
	y[3] = (y[1] > y[0] ? 1 : -1);
	int err = x[2] - y[2];
	int	err2;

	while (!((x[1] == x[0]) && (y[1] == y[0])))
	{
		ppixel(env, env->imgtab, x[0], y[0], gradient(env, a, b, y[0], x[0]));
		err2 = err;
		if (err2 > -x[2])
		{
			err -= y[2];
			x[0] += x[3];
		}
		if (err2 <= y[2])
		{
			err += x[2];
			y[0] += y[3];
		}
	}
}
static	void	draw_eight_sym(t_env *env, t_point *mid, int pos_x, int pos_y)
{
	ppixel(env, env->imgtab, mid->x + pos_x, mid->y + pos_y, mid->clr);
	ppixel(env, env->imgtab, mid->x + pos_y, mid->y + pos_x, mid->clr);
	ppixel(env, env->imgtab, mid->x - pos_y, mid->y + pos_x, mid->clr);
	ppixel(env, env->imgtab, mid->x - pos_x, mid->y + pos_y, mid->clr);
	ppixel(env, env->imgtab, mid->x - pos_x, mid->y - pos_y, mid->clr);
	ppixel(env, env->imgtab, mid->x - pos_y, mid->y - pos_x, mid->clr);
	ppixel(env, env->imgtab, mid->x + pos_y, mid->y - pos_x, mid->clr);
	ppixel(env, env->imgtab, mid->x + pos_x, mid->y - pos_y, mid->clr);
}

void			draw_circle(t_env *env, t_point *mid, float pct_radius)
{
	int radius = (int)((float)env->width * pct_radius) / 100;
	int pos_x = radius-1;
	int pos_y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1);

	while (pos_x >= pos_y)
	{
		draw_eight_sym(env, mid, pos_x, pos_y);
		if (err <= 0)
		{
			pos_y++;
			err += dy;
			dy += 2;
		}
		if (err > 0)
		{
			pos_x--;
			dx += 2;
			err += dx - (radius << 1);
		}
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:12:21 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 18:15:20 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	int		get_color(t_env *env, double height)
{
	int		r;
	int		g;
	int		b;
	double	step;

	if (env->grid.min == env->grid.max)
		return (blend_color(env->clr1, env->clr2, 50));
	step = (height - env->grid.min) /
		(double)(env->grid.max - env->grid.min);
	r = (((double)1 - step) * ((env->clr1 & RED) >> 16)
			+ step * ((env->clr2 & RED) >> 16));
	g = (((double)1 - step) * ((env->clr1 & GREEN) >> 8)
			+ step * ((env->clr2 & GREEN) >> 8));
	b = (((double)1 - step) * (env->clr1 & BLUE) + step * (env->clr2 & BLUE));
	return (rgb_to_hex(r, g, b));
}

int				x_gradient(t_env *env, t_vect v, int x)
{
	if (v.a.d != v.b.d)
	{
		if (v.a.d > v.b.d)
		{
			if (v.a.x > v.b.x)
				return (get_color(env, (((((double)(x - v.b.x)) / (double)(v.a.x
					- v.b.x)) * (double)(v.a.d - v.b.d)) + (double)v.b.d)));
				if (v.b.x > v.a.x)
				return (get_color(env, (((((double)(v.b.x - x)) / (double)(v.b.x
					- v.a.x)) * (double)(v.a.d - v.b.d)) + (double)v.b.d)));
		}
		else
		{
			if (v.b.x > v.a.x)
				return (get_color(env, (((((double)(x - v.a.x)) / (double)(v.b.x
					- v.a.x)) * (double)(v.b.d - v.a.d)) + (double)v.a.d)));
			else if (v.a.x > v.b.x)
				return (get_color(env, (((((double)(v.a.x - x)) / (double)(v.a.x
					- v.b.x)) * (double)(v.b.d - v.a.d)) + (double)v.a.d)));
		}
	}
	return (get_color(env, (double)v.a.d));
}

int				y_gradient(t_env *env, t_vect v, int y)
{
	if (v.a.d != v.b.d)
	{
		if (v.a.d > v.b.d)
		{
			if (v.a.y > v.b.y)
				return (get_color(env, (((((double)(y - v.b.y)) / (double)(v.a.y
					- v.b.y)) * (double)(v.a.d - v.b.d)) + (double)v.b.d)));
				if (v.b.y > v.a.y)
				return (get_color(env, (((((double)(v.b.y - y)) / (double)(v.b.y
					- v.a.y)) * (double)(v.a.d - v.b.d)) + (double)v.b.d)));
		}
		else
		{
			if (v.b.y > v.a.y)
				return (get_color(env, (((((double)(y - v.a.y)) / (double)(v.b.y
					- v.a.y)) * (double)(v.b.d - v.a.d)) + (double)v.a.d)));
			else if (v.a.y > v.b.y)
				return (get_color(env, (((((double)(v.a.y - y)) / (double)(v.a.y
					- v.b.y)) * (double)(v.b.d - v.a.d)) + (double)v.a.d)));
		}
	}
	return (get_color(env, (double)v.a.d));
}

int				change_back_color(t_env *env)
{
	static	int	back_clr[10] = {BLACK, DARK_GREY, DARK_GREEN, DARK_RED,
		DARK_CYAN, DARK_BLUE, DARK_SAND, BROWN, DARK_PINK, DARK_GREY};
	int			picker;

	picker = rand() / (RAND_MAX / 9);
	env->view.background = set_opacity(back_clr[picker], env->view.trail_lvl);
	return (1);
}

int				change_front_color(t_env *env)
{
	static	int	wire_clr[10] = {LIGHT_GREY, ORANGE, RED, DARK_FUN, CYAN,
		MAGENTA, SAND, YELLOW, SKY_BLUE, GREEN};
	int			picker;

	picker = rand() / (RAND_MAX / 9);
	env->clr1 = wire_clr[9 - picker];
	env->clr2 = wire_clr[picker];
	return (1);
}

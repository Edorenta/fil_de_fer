/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:12:21 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 08:19:22 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	int		get_color(t_env *env, double height)
{
	int		r;
	int		g;
	int		b;
	double	step;

	step = (height - env->grid->min) /
		(double)(env->grid->max - env->grid->min);
	r = ((1 - step) * ((env->clr1 & RED) >> 16)
			+ step * ((env->clr2 & RED) >> 16));
	g = ((1 - step) * ((env->clr1 & GREEN) >> 8)
			+ step * ((env->clr2 & GREEN) >> 8));
	b = ((1 - step) * (env->clr1 & BLUE) + step * (env->clr2 & BLUE));
	return (rgb_to_hex(r, g, b));
}

int				gradient(t_env *env, t_vect v, int y)
{
	if (v.a.d != v.b.d)
	{
		if (v.a.d > v.b.d)
		{
			if (v.a.y > v.b.y)
				return (get_color(env, (((((double)(y - v.b.y)) / (v.a.y
					- v.b.y)) * (double)(v.a.d - v.b.d)) + (double)v.b.d)));
			if (v.b.y > v.a.y)
				return (get_color(env, (((((double)(v.b.y - y)) / (v.b.y
					- v.a.y)) * (double)(v.a.d - v.b.d)) + (double)v.b.d)));
		} 
		else
		{
			if (v.b.y > v.a.y)
				return (get_color(env, (((((double)(y - v.a.y)) / (v.b.y
					- v.a.y)) * (double)(v.b.d - v.a.d)) + (double)v.a.d)));
			else if (v.a.y > v.b.y)
				return (get_color(env, (((((double)(v.a.y - y)) / (v.a.y
					- v.b.y)) * (double)(v.b.d - v.a.d)) + (double)v.a.d)));
		}
	}
	return (get_color(env, (double)v.a.d));
}

int				change_back_color(t_env *env)
{
	static  int	back_clr[10] = {BLACK, DARK_GREY, DARK_GREEN, DARK_RED,
		DARK_CYAN, DARK_BLUE, DARK_SAND, BROWN, DARK_PINK, DARK_GREY};
	int         picker;

	picker = rand()/(RAND_MAX / 9);
	env->view->background = set_opacity(back_clr[picker], env->view->trail_lvl);
	return (1);
}

int				change_front_color(t_env *env)
{
	static  int	wire_clr[10] = {LIGHT_GREY, ORANGE, RED, DARK_FUN, CYAN,
		MAGENTA, SAND, YELLOW, SKY_BLUE, GREEN};
	int         picker;

	picker = rand()/(RAND_MAX / 9);
	env->clr1 = wire_clr[9 - picker];
	env->clr2 = wire_clr[picker];
	return (1);
}

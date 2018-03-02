/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:12:21 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/02 19:15:30 by pde-rent         ###   ########.fr       */
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
	return (rgb_to_hex(R, G, B));
}

int				gradient(t_env *env, t_vect *v, int y, int x)
{
	if (a->d != b->d)
	{
		if (a->d > b->d)
		{
			if (a->y > b->y)
				return (get_color(env, (((((double)(y - b->y)) / (a->y - b->y))
									* (double)(a->d - b->d)) + (double)b->d)));
			if (b->y > a->y)
				return (get_color(env, (((((double)(b->y - y)) / (b->y - a->y))
									* (double)(a->d - b->d)) + (double)b->d)));
		} 
		else
		{
			if (b->y > a->y)
				return (get_color(env, (((((double)(y - a->y)) / (b->y - a->y))
									* (double)(b->d - a->d)) + (double)a->d)));
			else if (a->y > b->y)
				return (get_color(env, (((((double)(a->y - y)) / (a->y - b->y))
									* (double)(b->d - a->d)) + (double)a->d)));
		}
	}
	return (get_color(env, (double)a->d));
}

int				change_back_color(t_env *env)
{
	static  int	back_clr[10] = {BLACK, DARK_GREY, DARK_FUN, DARK_RED,
		DARK_CYAN, DARK_BLUE, DARK_SAND,
		BROWN, DARK_PINK, DARK_GREEN};
	int         picker;

	picker = rand()/(RAND_MAX / 10) - 1;
	env->view->background = set_opacity(back_clr[picker], env->view->trail_lvl);
	return (1);
}

int				change_front_color(t_env *env)
{
	static  int	wire_clr[10] = {WHITE, LIGHT_GREY, ORANGE, RED, CYAN,
		SKY_BLUE, SAND, YELLOW, MAGENTA, GREEN};
	int         picker;

	picker = rand()/(RAND_MAX / 10) - 1;
	env->clr1 = wire_clr[picker];
	env->clr2 = wire_clr[picker];
	return (1);
}

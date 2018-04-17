/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:46:28 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 19:03:36 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	int g_prev_x = 0;
static	int g_prev_y = 0;
static	int g_in_motion = 0;

int			mouse_scroll(int key_code, int pos_x, int pos_y, t_env *env)
{
	if (key_code == SCROLL_UP)
		inc_depth(env);
	else if (key_code == SCROLL_DOWN)
		dec_depth(env);
	(void)pos_x;
	(void)pos_y;
	sketch(env);
	return (1);
}

int			mouse_press(int key_code, int pos_x, int pos_y, t_env *env)
{
	key_code ? env->clicked = 1 : 0;
	g_prev_x = pos_x;
	g_prev_y = pos_y;
	g_in_motion = 0;
	(void)pos_x;
	(void)pos_y;
	sketch(env);
	return (0);
}

int			mouse_release(int key_code, int pos_x, int pos_y, t_env *env)
{
	g_prev_x = pos_x;
	g_prev_y = pos_y;
	(void)pos_x;
	(void)pos_y;
	key_code ? env->clicked = 0 : 1;
	sketch(env);
	return (0);
}

static int	set_g_in_motion(int x, int y, t_env *env)
{
	if (x - (g_prev_x + 50) > 0)
	{
		rot_y(env, 1);
		g_in_motion = 1;
	}
	else if (x - (g_prev_x - 50) < 0)
	{
		rot_y(env, 2);
		g_in_motion = 1;
	}
	if (y - (g_prev_y + 50) > 0)
	{
		rot_x(env, 2);
		g_in_motion = 1;
	}
	else if (y - (g_prev_y - 50) < 0)
	{
		rot_x(env, 1);
		g_in_motion = 1;
	}
	return (0);
}

int			mouse_move(int pos_x, int pos_y, t_env *env)
{
	static int x = 0;
	static int y = 0;

	if (env->clicked && !g_in_motion)
	{
		x = pos_x;
		y = pos_y;
		set_g_in_motion(pos_x, pos_y, env);
	}
	else if (env->clicked && g_in_motion)
		set_g_in_motion(x, y, env);
	(void)pos_x;
	(void)pos_y;
	sketch(env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:46:28 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 19:03:36 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int				mouse_recognition(int key_code, int pos_x, int pos_y,
		t_env *env)
{
	if (key_code == SCROLL_UP)
		inc_depth(env);
	else if (key_code == SCROLL_DOWN)
		dec_depth(env);
	sketch(env);
	(void)pos_x;
	(void)pos_y;
	return (1);
}

static	int		key_rec_1(t_env *env, int key_code)
{
	if (key_code == KEY_UP)
		move_up(env);
	else if (key_code == KEY_DOWN)
		move_down(env);
	else if (key_code == KEY_LEFT)
		move_left(env);
	else if (key_code == KEY_RIGHT)
		move_right(env);
	else if (key_code == KEY_ADD)
		zoom_in(env);
	else if (key_code == KEY_SUBTRACT)
		zoom_out(env);
	else if (key_code == KEY_NUM8)
		rot_x(env, 1);
	else if (key_code == KEY_NUM2)
		rot_x(env, 2);
	else if (key_code == KEY_NUM6)
		rot_y(env, 1);
	else if (key_code == KEY_NUM4)
		rot_y(env, 2);
	else if (key_code == KEY_NUM1)
		rot_z(env, 1);
	else if (key_code == KEY_NUM3)
		rot_z(env, 2);
	return (1);
}

static	int		key_rec_2(t_env *env, int key_code)
{
	if (key_code == KEY_C)
		change_front_color(env);
	if (key_code == KEY_B)
		change_back_color(env);
	if (key_code == KEY_H)
		env->view.hori = env->view.hori ? 0 : 1;
	if (key_code == KEY_V)
		env->view.verti = env->view.verti ? 0 : 1;
	if (key_code == KEY_T)
	{
		env->trail = env->trail ? 0 : 1;
		if (!(env->trail))
			env->view.trail_lvl = 0;
	}
	if (key_code == KEY_G && env->trail)
	{
		env->view.trail_lvl = env->view.trail_lvl > 21 ? 0
			: env->view.trail_lvl + 1;
		env->view.background =
			set_opacity(env->view.background, env->view.trail_lvl);
	}
	return (1);
}

int				key_recognition(int key_code, t_env *env)
{
	if (key_code == 53)
	{
		deinit(env);
		exit(0);
	}
	else if (key_code == KEY_RETURN)
		reinit(env);
	else if (key_code == KEY_TAB)
		env->display_ui = env->display_ui ? 0 : 1;
	else if (key_code == KEY_SHIFT)
		env->display_state = env->display_state ? 0 : 1;
	key_rec_1(env, key_code);
	key_rec_2(env, key_code);
	sketch(env);
	return (0);
}

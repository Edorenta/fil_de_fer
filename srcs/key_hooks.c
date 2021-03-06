/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:46:28 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 19:03:36 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

inline static void		switch_view(t_env *env, int key_code)
{
	static int	i = 0;

	if (key_code == KEY_D)
	{
		i++;
		SWITCH_DIAG1;
		if (i > 1)
			SWITCH_DIAG2;
		if (i % 3)
			SWITCH_DIAG1;
	}
	else if (key_code == KEY_H)
		SWITCH_HORI;
	else if (key_code == KEY_V)
		SWITCH_VERTI;
}

static	int				key_rec_1(t_env *env, int key_code)
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

static	int				key_rec_2(t_env *env, int key_code)
{
	if (key_code == KEY_P)
	{
		env->view.projection = env->view.projection ? 0 : 1;
		if (!(env->view.projection))
			env->view.persp_coef = 1;
	}
	else if (key_code == KEY_O && env->view.projection == P_PERSPECTIVE)
		env->view.persp_coef = env->view.persp_coef > MAX_PERSP ? 0
			: env->view.persp_coef + 1;
	else if (key_code == KEY_T)
	{
		env->trail = env->trail ? 0 : 1;
		if (!(env->trail) && (env->view.background = 0))
			env->view.trail_lvl = 0;
	}
	else if (key_code == KEY_G && env->trail)
	{
		env->view.trail_lvl = env->view.trail_lvl > 21 ? 0
			: env->view.trail_lvl + 1;
		env->view.background =
			set_opacity(env->view.background, env->view.trail_lvl);
	}
	return (1);
}

int						key_recognition(int key_code, t_env *env)
{
	if (key_code == 53)
		deinit(env);
	else if (key_code == KEY_RETURN)
		reinit(env);
	else if (key_code == KEY_TAB)
		env->display_ui = env->display_ui ? 0 : 1;
	else if (key_code == KEY_SHIFT)
		env->display_state = env->display_state ? 0 : 1;
	else if (key_code == KEY_F)
		env->view.speed++;
	else if (key_code == KEY_S)
		env->view.speed--;
	else if (key_code == KEY_C)
		change_front_color(env);
	else if (key_code == KEY_B)
		change_back_color(env);
	else if (key_code == KEY_D || key_code == KEY_V || key_code == KEY_H)
		switch_view(env, key_code);
	key_rec_1(env, key_code);
	key_rec_2(env, key_code);
	sketch(env);
	return (0);
}

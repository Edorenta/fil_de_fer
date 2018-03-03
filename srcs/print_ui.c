/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:28:13 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 19:29:13 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	void		print_state2(t_env *env)
{
	put_ui(env, 28, 1, WHITE, "Highest:       (pixels)\0");
	put_ui(env, 28, 2, WHITE, ft_itoa(
		fmax(env->grid.max * env->grid.z_mult,
		env->grid.min * env->grid.z_mult) / 10000));
	put_ui(env, 29, 1, WHITE, "Lowest:        (pixels)\0");
	put_ui(env, 29, 2, WHITE, ft_itoa(
		fmin(env->grid.max * env->grid.z_mult,
		env->grid.min * env->grid.z_mult) / 10000));
	put_ui(env, 30, 1, env->clr1, "Highs Color\0");
	put_ui(env, 31, 1, env->clr2, "Lows Color\0");
	put_ui(env, 32, 1, WHITE, "Trail:");
	put_ui(env, 32, 2, WHITE, (!env->trail ? "OFF\0" : "ON: lvl\0"));
	put_ui(env, 32, 3, WHITE, (!env->trail ? ""
		: ft_itoa(env->view.trail_lvl)));
}

static	void		print_state(t_env *env)
{
	put_ui(env, 19, 1, env->clr1, "      .--------------.\0");
	put_ui(env, 20, 1, env->clr1, "      |    STATES    |\0");
	put_ui(env, 21, 1, env->clr1, "      '--------------'\0");
	put_ui(env, 22, 1, WHITE, "Pos x:         (pixels)\0");
	put_ui(env, 22, 2, WHITE, ft_itoa(env->view.pos_x));
	put_ui(env, 23, 1, WHITE, "Pos y:         (pixels)\0");
	put_ui(env, 23, 2, WHITE, ft_itoa(env->view.pos_y));
	put_ui(env, 24, 1, WHITE, "Rot x:         (degrees)\0");
	put_ui(env, 24, 2, WHITE, ft_itoa(env->view.rot_x));
	put_ui(env, 25, 1, WHITE, "Rot y:         (degrees)\0");
	put_ui(env, 25, 2, WHITE, ft_itoa(env->view.rot_y));
	put_ui(env, 26, 1, WHITE, "Rot z:         (degrees)\0");
	put_ui(env, 26, 2, WHITE, ft_itoa(env->view.rot_z));
	put_ui(env, 27, 1, WHITE, "Zoom:      x 1.15 ^\0");
	put_ui(env, 27, 3, WHITE, ft_itoa(env->view.zoom));
	print_state2(env);
	mlx_string_put(env->mlx, env->win, 300, 2, GREY,
		"Press SHIFT to hide STATES\0");
}

static	void		print_controls(t_env *env)
{
	put_ui(env, 1, 1, env->clr1, "      .--------------.\0");
	put_ui(env, 2, 1, env->clr1, "      |   CONTROLS   |\0");
	put_ui(env, 3, 1, env->clr1, "      '--------------'\0");
	put_ui(env, 4, 1, env->clr2, "---------- ARROWS ----------\0");
	put_ui(env, 5, 1, WHITE, "<left,right> : X Translation\0");
	put_ui(env, 6, 1, WHITE, "   <up,down> : Y Translation\0");
	put_ui(env, 7, 1, env->clr2, "---------- NUMPAD ----------\0");
	put_ui(env, 8, 1, WHITE, "       <1,3> : Z Rotation\0");
	put_ui(env, 9, 1, WHITE, "       <4,6> : Y Rotation\0");
	put_ui(env, 10, 1, WHITE, "       <8,2> : X Rotation\0");
	put_ui(env, 11, 1, WHITE, "       <+,-> : Zoom +/-\0");
	put_ui(env, 12, 1, WHITE, "       <*,/> : Depth +/-\0");
	put_ui(env, 13, 1, env->clr2, "---------- OTHERS ----------\0");
	put_ui(env, 14, 1, WHITE, "         <T> : Enable Trail\0");
	put_ui(env, 15, 1, WHITE, "         <C> : Shake Colors\0");
	put_ui(env, 16, 1, WHITE, "     <ENTER> : Reset Map\0");
	put_ui(env, 17, 1, WHITE, "       <ESC> : Exit Program\0");
	mlx_string_put(env->mlx, env->win, 10, 2, GREY,
		"Press TAB to hide CONTROLS |\0");
}

void				print_ui(t_env *env)
{
	if (env->display_ui)
		print_controls(env);
	else
		mlx_string_put(env->mlx, env->win, 10, 2, GREY,
			"Press TAB to show CONTROLS |\0");
	if (env->display_state)
		print_state(env);
	else
		mlx_string_put(env->mlx, env->win, 300, 2, GREY,
			"Press SHIFT to show STATES\0");
}

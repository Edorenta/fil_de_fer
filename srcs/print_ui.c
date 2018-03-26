/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:28:13 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 19:31:36 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int row;
int col;

static	void		print_state2(t_env *env)
{
	put_ui(env, DIM(row, ++col), WHITE,		"Highest:       (pixels)\0");
	put_ui(env, DIM(row + 1, col), WHITE, ft_itoa(
		fmax(env->grid.max * env->grid.z_mult,
		env->grid.min * env->grid.z_mult) / 10000));
	put_ui(env, DIM(row, ++col), WHITE,		"Lowest:        (pixels)\0");
	put_ui(env, DIM(2, col), WHITE, ft_itoa(
		fmin(env->grid.max * env->grid.z_mult,
		env->grid.min * env->grid.z_mult) / 10000));
	put_ui(env, DIM(row, ++col), env->clr1, "Highs Color\0");
	put_ui(env, DIM(row, ++col), env->clr2, "Lows Color\0");
	put_ui(env, DIM(row, ++col), WHITE,		"Trail:");
	put_ui(env, DIM(row + 1, col), WHITE, (!env->trail ? "OFF" : "ON: lvl"));
	put_ui(env, DIM(row + 2, col), WHITE, (!env->trail ? ""
		: ft_itoa(env->view.trail_lvl)));
	put_ui(env, DIM(row, ++col), WHITE,		"Speed:");
	put_ui(env, DIM(row + 1, col), WHITE, (ft_itoa(env->view.speed)));
}

static	void		print_state(t_env *env)
{
	put_ui(env, DIM(row, ++col), env->clr1, "      .--------------.\0");
	put_ui(env, DIM(row, ++col), env->clr1, "      |    STATES    |\0");
	put_ui(env, DIM(row, ++col), env->clr1, "      '--------------'\0");
	put_ui(env, DIM(row, ++col), WHITE,		"Pos x:         (pixels)\0");
	put_ui(env, DIM(row + 1, col), WHITE, ft_itoa(env->view.pos_x));
	put_ui(env, DIM(row, ++col), WHITE,		"Pos y:         (pixels)\0");
	put_ui(env, DIM(row + 1, col), WHITE, ft_itoa(env->view.pos_y));
	put_ui(env, DIM(row, ++col), WHITE,		"Rot x:         (degrees)\0");
	put_ui(env, DIM(row + 1, col), WHITE, ft_itoa(env->view.rot_x));
	put_ui(env, DIM(row, ++col), WHITE,		"Rot y:         (degrees)\0");
	put_ui(env, DIM(row + 1, col), WHITE, ft_itoa(env->view.rot_y));
	put_ui(env, DIM(row, ++col), WHITE,		"Rot z:         (degrees)\0");
	put_ui(env, DIM(row + 1, col), WHITE, ft_itoa(env->view.rot_z));
	put_ui(env, DIM(row, ++col), WHITE,		"Zoom:      x 1.15 ^\0");
	put_ui(env, DIM(row + 2, col), WHITE, ft_itoa(env->view.zoom));
	print_state2(env);
	mlx_string_put(env->mlx, env->win, 300, 2, GREY,
		"Press SHIFT to hide STATES\0");
}

static	void		print_controls(t_env *env)
{
	put_ui(env, DIM(row, ++col), env->clr1, "      .--------------.\0");
	put_ui(env, DIM(row, ++col), env->clr1, "      |   CONTROLS   |\0");
	put_ui(env, DIM(row, ++col), env->clr1, "      '--------------'\0");
	put_ui(env, DIM(row, ++col), env->clr2, "---------- ARROWS ----------\0");
	put_ui(env, DIM(row, ++col), WHITE,		"  <L,R> : X Translation\0");
	put_ui(env, DIM(row, ++col), WHITE,		"  <U,D> : Y Translation\0");
	put_ui(env, DIM(row, ++col), env->clr2, "---------- NUMPAD ----------\0");
	put_ui(env, DIM(row, ++col), WHITE,		"  <1,3> : Z Rotation\0");
	put_ui(env, DIM(row, ++col), WHITE,		"  <4,6> : Y Rotation\0");
	put_ui(env, DIM(row, ++col), WHITE,		"  <8,2> : X Rotation\0");
	put_ui(env, DIM(row, ++col), WHITE,		"  <+,-> : Zoom +/-\0");
	put_ui(env, DIM(row, ++col), WHITE,		"  <*,/> : Depth +/-\0");
	put_ui(env, DIM(row, ++col), env->clr2, "---------- OTHERS ----------\0");
	put_ui(env, DIM(row, ++col), WHITE,		"    <T> : Enable Trail\0");
	put_ui(env, DIM(row, ++col), WHITE,		"    <C> : Shuffle Front Colors\0");
	put_ui(env, DIM(row, ++col), WHITE,		"    <F> : Faster Movements\0");
	put_ui(env, DIM(row, ++col), WHITE,		"    <S> : Slower Movements\0");
	put_ui(env, DIM(row, ++col), WHITE,		"    <B> : Background Color\0");
	put_ui(env, DIM(row, ++col), WHITE,		"<ENTER> : Reset Map\0");
	put_ui(env, DIM(row, ++col), WHITE,		"  <ESC> : Exit Program\0");
	mlx_string_put(env->mlx, env->win, 10, 2, GREY,
		"Press TAB to hide CONTROLS |\0");
}

void				print_ui(t_env *env)
{
	row = 1;
	col = 0;
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

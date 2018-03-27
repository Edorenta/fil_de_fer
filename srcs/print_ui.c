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

static int		g_r;
static int		g_c;

static void		print_state2(t_env *env)
{
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Highest:       (pixels)\0");
	put_ui(env, DIM(g_r + 1, g_c), WHITE, ft_itoa(
		fmax(env->grid.max * env->grid.z_mult,
		env->grid.min * env->grid.z_mult) / 10000));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Lowest:        (pixels)\0");
	put_ui(env, DIM(2, g_c), WHITE, ft_itoa(
		fmin(env->grid.max * env->grid.z_mult,
		env->grid.min * env->grid.z_mult) / 10000));
	put_ui(env, DIM(g_r, ++g_c), env->clr1, "Highs color\0");
	put_ui(env, DIM(g_r, ++g_c), env->clr2, "Lows color\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Trail:");
	put_ui(env, DIM(g_r + 1, g_c), WHITE, (!env->trail ? "OFF" : "ON: lvl"));
	put_ui(env, DIM(g_r + 2, g_c), WHITE, (!env->trail ? ""
		: ft_itoa(env->view.trail_lvl)));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Speed:");
	put_ui(env, DIM(g_r + 1, g_c), WHITE, (ft_itoa(env->view.speed)));
}

static void		print_state(t_env *env)
{
	put_ui(env, DIM(g_r, ++g_c), env->clr1, "      .--------------.\0");
	put_ui(env, DIM(g_r, ++g_c), env->clr1, "      |    STATES    |\0");
	put_ui(env, DIM(g_r, ++g_c), env->clr1, "      '--------------'\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Pos x:         (pixels)\0");
	put_ui(env, DIM(g_r + 1, g_c), WHITE, ft_itoa(env->view.pos_x));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Pos y:         (pixels)\0");
	put_ui(env, DIM(g_r + 1, g_c), WHITE, ft_itoa(env->view.pos_y));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Rot x:         (degrees)\0");
	put_ui(env, DIM(g_r + 1, g_c), WHITE, ft_itoa(env->view.rot_x));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Rot y:         (degrees)\0");
	put_ui(env, DIM(g_r + 1, g_c), WHITE, ft_itoa(env->view.rot_y));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Rot z:         (degrees)\0");
	put_ui(env, DIM(g_r + 1, g_c), WHITE, ft_itoa(env->view.rot_z));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Zoom:      x 1.15 ^\0");
	put_ui(env, DIM(g_r + 2, g_c), WHITE, ft_itoa(env->view.zoom));
	print_state2(env);
	mlx_string_put(env->mlx, env->win, 300, 2, GREY,
		"Press SHIFT to hide STATES\0");
}

static void		print_controls(t_env *env)
{
	put_ui(env, DIM(g_r, ++g_c), env->clr1, "      .--------------.\0");
	put_ui(env, DIM(g_r, ++g_c), env->clr1, "      |   CONTROLS   |\0");
	put_ui(env, DIM(g_r, ++g_c), env->clr1, "      '--------------'\0");
	put_ui(env, DIM(g_r, ++g_c), env->clr2, "---------- ARg_rS ----------\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "  <L,R> : X Translation\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "  <U,D> : Y Translation\0");
	put_ui(env, DIM(g_r, ++g_c), env->clr2, "---------- NUMPAD ----------\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "  <1,3> : Z Rotation\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "  <4,6> : Y Rotation\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "  <8,2> : X Rotation\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "  <+,-> : Zoom +/-\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "  <*,/> : Depth +/-\0");
	put_ui(env, DIM(g_r, ++g_c), env->clr2, "---------- OTHERS ----------\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "    <T> : Enable Trail\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "    <C> : Shuffle Front g_cors\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "    <F> : Faster Movements\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "    <S> : Slower Movements\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "    <B> : Background g_cor\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "<ENTER> : Reset Map\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "  <ESC> : Exit Program\0");
	mlx_string_put(env->mlx, env->win, 10, 2, GREY,
		"Press TAB to hide CONTROLS |\0");
}

void			print_ui(t_env *env)
{
	g_r = 1;
	g_c = 0;
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

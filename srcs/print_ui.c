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
	put_ui(env, DIM(g_r, ++g_c), env->clr1, "Highs color\0");
	put_ui(env, DIM(g_r, ++g_c), env->clr2, "Lows color\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Horizontal wires:");
	put_ui(env, DIM(g_r + 2, g_c), WHITE, (!IS_SET_HORI ? "OFF" : "ON"));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Vertical wires:");
	put_ui(env, DIM(g_r + 2, g_c), WHITE, (!IS_SET_VERTI ? "OFF" : "ON"));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Diagonal LR:");
	put_ui(env, DIM(g_r + 2, g_c), WHITE, (!IS_SET_DIAG1 ? "OFF" : "ON"));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Diagonal RL:");
	put_ui(env, DIM(g_r + 2, g_c), WHITE, (!IS_SET_DIAG2 ? "OFF" : "ON"));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Trail:");
	put_ui(env, DIM(g_r + 1, g_c), WHITE, (!env->trail ? "OFF" : "ON: lvl"));
	put_ui(env, DIM(g_r + 2, g_c), WHITE, (!env->trail ? ""
		: ft_itoa(env->view.trail_lvl)));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "View:");
	put_ui(env, DIM(g_r + 1, g_c), WHITE, (env->view.projection == 0 ?
	"ISOMETRIC" : "PERPECTIVE        %"));
	if (env->view.projection == 1)
		put_ui(env, DIM(g_r + 2, g_c), WHITE, (ft_itoa(env->view.persp_coef)));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Commands Speed:");
	put_ui(env, DIM(g_r + 2, g_c), WHITE, (ft_itoa(env->view.speed)));
	mlx_string_put(env->mlx, env->win, 300, 2, GREY,
		"Press SHIFT to hide STATES\0");
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
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Highest:       (pixels)\0");
	put_ui(env, DIM(g_r + 1, g_c), WHITE, ft_itoa(
		fmax(env->grid.max * env->grid.z_mult,
		env->grid.min * env->grid.z_mult) / 10000));
	put_ui(env, DIM(g_r, ++g_c), WHITE, "Lowest:        (pixels)\0");
	put_ui(env, DIM(2, g_c), WHITE, ft_itoa(
		fmin(env->grid.max * env->grid.z_mult,
		env->grid.min * env->grid.z_mult) / 10000));
	print_state2(env);
}

static void		print_controls(t_env *env)
{
	put_ui(env, DIM(g_r, ++g_c), env->clr1, "      .--------------.\0");
	put_ui(env, DIM(g_r, ++g_c), env->clr1, "      |   CONTROLS   |\0");
	put_ui(env, DIM(g_r, ++g_c), env->clr1, "      '--------------'\0");
	put_ui(env, DIM(g_r, ++g_c), env->clr2, "---------- ARROWS ----------\0");
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
	put_ui(env, DIM(g_r, ++g_c), WHITE, "    <C> : Shuffle Front colors\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "    <B> : Background color\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "  <H,V> : Show/Hide main wires\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "    <D> : Show/Hide cross wires\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "  <F,S> : Move Speed +/-\0");
	put_ui(env, DIM(g_r, ++g_c), WHITE, "    <P> : Switch view\0");
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

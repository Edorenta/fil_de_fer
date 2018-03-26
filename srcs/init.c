/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:28:41 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 18:59:54 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			grid_init(t_env *env)
{
	int		shorter;
	int		abs_max;

	shorter = 15;
	env->grid.zx_spacing = 10000 * ((env->width
			* (100 - (2 * shorter))) / (400 * (env->grid.nb_x - 1)));
	env->grid.x_spacing = 10000 * (
			((env->width * (100 - (2 * shorter)) / 100)
			- ((env->grid.nb_y - 1) * (env->grid.zx_spacing / 10000)))
			/ ((env->grid.nb_x - 1)));
	env->grid.zy_spacing = 10000 * ((env->height
			* (100 - (2 * shorter))) / (900 * (env->grid.nb_y - 1)));
	env->grid.y_spacing = 10000 * (
			((env->height * (100 - (2 * shorter)) / 100)
			- ((env->grid.nb_x - 1) * (env->grid.zy_spacing / 10000)))
			/ ((env->grid.nb_y - 1)));
	X_OFFSET = ((env->width * shorter) / 100) * 10000;
	Y_OFFSET = (((env->height * shorter) / 100)
			+ ((env->grid.zy_spacing / 10000) * env->grid.nb_x)) * 10000;
	env->grid.max = ft_arraymax(env->grid.matrix, env->grid.nb_tot - 1);
	env->grid.min = ft_arraymin(env->grid.matrix, env->grid.nb_tot - 1);
	abs_max = (abs(env->grid.max) > abs(env->grid.min) ?
			abs(env->grid.max) : abs(env->grid.min));
	env->grid.z_mult = 10000 * ((env->height / 8) / (abs_max + 1));
	return (1);
}

int			view_init(t_view *view)
{
	view->hori = 1;
	view->verti = 1;
	view->pos_x = 0;
	view->pos_y = 0;
	view->depth = 0;
	view->zoom = 0;
	view->rot_x = 0;
	view->rot_y = 0;
	view->rot_z = 0;
	view->trail_lvl = 0;
	view->last_dir = 0;
	view->speed = 1;
	return (1);
}

t_env		*env_init(void)
{
	t_env	*env;

	srand(time(NULL));
	env = (t_env *)malloc(sizeof(t_env));
	env->trail = 0;
	env->win_title = ft_strdup("Wireframe");
	env->pct_scale = 80;
	env->width = (SCREEN_WIDTH * env->pct_scale) / 100;
	env->height = (SCREEN_HEIGHT * env->pct_scale) / 100;
	view_init(&(env->view));
	env->view.mid_x = env->width / 2;
	env->view.mid_y = env->height / 2;
	env->view.clr1 = CYAN;
	env->view.clr2 = MAGENTA;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->width, env->height,
			env->win_title);
	env->display_ui = 0;
	env->display_state = 0;
	env->view.background = BLACK;
	env->img = mlx_new_image(env->mlx, env->width, env->height);
	env->imgtab = (int *)mlx_get_data_addr(env->img,
			&(env->bpp), &(env->sl), &(env->endian));
	return (env);
}

int		deinit(t_env *env)
{
	/*
	** mlx_destroy_image(env->mlx, env->img);
	** mlx_clear_window(env->mlx, env->win);
	** mlx_destroy_window(env->mlx, env->win);
	** free(env->view);
	** free(env->grid.matrix);
	** free(env->win_title);
	** free(env->file_name);
	** free(env->imgtab);
	*/
	free(env);
	return (1);
}

int		reinit(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	ft_bzero(env->imgtab, env->width * env->height * sizeof(int));
	env->clr1 = env->view.clr1;
	env->clr2 = env->view.clr2;
	env->clr3 = env->view.background;
	env->trail = 0;
	view_init(&(env->view));
	tab_init(env, raw_str(env->file_name));
	sketch(env);
	return (1);
}

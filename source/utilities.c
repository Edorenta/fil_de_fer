/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:29:34 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/14 16:27:54 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	win_refresh(void *thread)
{
	mlx_loop(thread);
}

void	ppixel(t_env *env, int x, int y, int clr)
{
	mlx_pixel_put(env->mlx, env->win, x, y, clr);
}

int		dyna_key_hook(t_env *env)
{
	return (mlx_key_hook(env->win, key_recognition, env));
}

t_env	*env_init(void)
{
    t_env       *env;

    env = (t_env *)malloc(sizeof(t_env));
	env->index = 0;
	env->win_title = ft_strdup("Wireframe");
    env->pct_scale = 60;
    env->width = (SCREEN_WIDTH * env->pct_scale) / 100;
    env->height = (SCREEN_HEIGHT * env->pct_scale) / 100;
    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, env->width, env->height, env->win_title);
    return (env);	
}

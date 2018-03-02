/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sketch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:56:46 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/01 17:28:04 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	void	filltab(int *tab, int clr, int size, int i)
{
	while (++i < size)
		tab[i] = clr;
}

static	int		display_imgtab(t_env *env)
{
	static	int		i;

	i = -1;
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	filltab(env->imgtab, env->view->background, env->width * env->height, i);
	print_ui(env);
	return (1);
}
int     sketch(t_env *env)
{
	map_matrix(env);
	display_imgtab(env);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:29:34 by pde-rent          #+#    #+#             */
/*   Updated: 2018/02/28 19:39:52 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	win_refresh(t_env *env)
{
	mlx_loop(env->mlx);
}

void	ppixel(t_env *env, int *tab, int x, int y, int clr)
{
//	mlx_pixel_put(env->mlx, env->win, x, y, clr);
	if (x > 0 && y > 0)
		if (y < env->height && x < env->width)
			tab[y * env->width + x] = clr;
}

void	put_ui(t_env *env, int row, int col, int clr, char *str)
{
	mlx_string_put(env->mlx, env->win, -90 + 100 * col,
	22 * row, clr, str);
}

//void	ppoint(t_env *env, t_point *pt)
//{
//	mlx_pixel_put(env->mlx, env->win, pt->x, pt->y, pt->clr);
//}

int		dyna_key_hook(t_env *env)
{
	mlx_hook(env->win, 2, 2, key_recognition, env);
	mlx_mouse_hook(env->win, mouse_recognition, env);
	return (1);
}

t_vect	*vectorize(t_point *a, t_point *b)
{
	t_vect	*vect;

	vect = (t_vect *)malloc(sizeof(t_vect));
	vect->a = a;
	vect->b = b;
	return (vect);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:42:54 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/02 17:07:16 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	int			wire_points(t_env *env, t_point **pt, int n)
{
	int i = n;
	while(i--)
	{
		if ((i < (n - 1)) && ((i + 1)% env->grid->nb_x))
			draw_line(env, pt[i], pt[i + 1]);
		if (i < (n - env->grid->nb_x))
			draw_line(env, pt[i], pt[i + env->grid->nb_x]);
	}
	return (1);
}
static	void		set_coordinates(t_point *pt, int ref_x, int ref_y,
		int *x, int *y, int *z)
{
	*x = pt->x - ref_x;
	*y = pt->y - ref_y;
	*z = pt->z;
}

static	void		rotate_xyz(t_env *env, t_point **pt, int n)
{
	int		x;
	int		y;
	int		z;
	int		i;
	double	teta[3];

	i = -1;
	teta[2] = ROT_Z * M_PI / 180;
	teta[1] = ROT_Y * M_PI / 180;
	teta[0] = ROT_X * M_PI / 180;
	while(++i < n)
	{
		set_coordinates(pt[i], env->view->mid_x, env->view->mid_y, &x, &y, &z);
		pt[i]->x += (int)((x * cos(teta[2])) + (y * sin(teta[2]))) - x;
		pt[i]->y += (int)(-(x * sin(teta[2])) + (y * cos(teta[2]))) - y;
		set_coordinates(pt[i], env->view->mid_x, env->view->mid_y, &x, &y, &z);
		pt[i]->x += (int)((x * cos(teta[1])) - (z * sin(teta[1]))) - x;
		pt[i]->z = (int)((x * sin(teta[1])) + (z * cos(teta[1])));
		set_coordinates(pt[i], env->view->mid_x, env->view->mid_y, &x, &y, &z);
		pt[i]->y += (int)((y * cos(teta[0])) + (z * sin(teta[0]))) - y;
		pt[i]->z = (int)(-(y * sin(teta[0])) + (z * cos(teta[0])));
	}
}

static	void		init_coordinates(t_env *env, t_point **pt)
{
	int		n_x;
	int		n_y;
	int		i;

	i = 0;
	n_y = -1;
	while (++n_y < (env->grid->nb_y))
	{
		n_x = -1;
		while (++n_x < env->grid->nb_x)
		{
			pt[i]->x = ((X_OFFSET / 10000) + ((env->grid->x_spacing / 10000)
						* n_x) + ((env->grid->zx_spacing / 10000) * n_y));
			pt[i]->y = ((Y_OFFSET / 10000) + ((env->grid->y_spacing / 10000)
						* n_y) - ((env->grid->zy_spacing / 10000) * n_x));
			pt[i]->d = MX[n_y][n_x];
			pt[i]->z = pt[i]->d * env->grid->z_mult / 10000;
			//printf("z: %d ", pt[i]->z);
			i++;
		}
	}
}

int					map_matrix(t_env *env)
{
	int		n;
	int		i;
	t_point	**pt;

	i = -1;
	n = env->grid->nb_x * env->grid->nb_y;
	pt = (t_point **)malloc(sizeof(t_point *) * n);
	while (++i < n)
		pt[i] = (t_point *)malloc(sizeof(t_point));
	init_coordinates(env, pt);
	rotate_xyz(env, pt, n);
	i = -1;
	while(++i < n)
	{
		pt[i]->y -= pt[i]->z;
		printf("z: %d ", pt[i]->z);
	}
	wire_points(env, pt, n);
	return (1);
}

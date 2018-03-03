/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:42:54 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 19:21:01 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	void		wire_points(t_env *env, t_point *pt, int n)
{
	int		i;
	/*
	** int		corners;
	** t_point *pt2;
	** corners = 4;
	** pt2 = (t_point *)malloc(sizeof(t_point) * corners);
	*/
	i = n;
	while (i--)
	{
		if (env->view.hori)
			if ((i < (n - 1)) && ((i + 1) % env->grid.nb_x))
				draw_line(env, pt[i], pt[i + 1]);
		if (env->view.verti)
			if (i < (n - env->grid.nb_x))
				draw_line(env, pt[i], pt[i + env->grid.nb_x]);
	}
	/*
	** i = n;
	** while (i-- > (env->grid.nb_x + 1))
	** {
	** pt2[0] = pt[i];
	** pt2[1] = pt[i - 1];
	** pt2[2] = pt[i - env->grid.nb_x];
	** pt2[3] = pt[i - env->grid.nb_x + 1];
	** if ((i + 1)% env->grid.nb_x)
	** polygon_fill(env, pt2, corners, env->width * env->height);
	** }
	*/
}

static	void		rotate_xyz(t_env *env, t_point *pt, int n)
{
	int				rx;
	int				ry;
	int				z;
	int				i;
	static	double	t = M_PI / 180;

	i = -1;
	while (++i < n)
	{
		rx = (pt[i].x) - env->view.mid_x;
		ry = (pt[i].y) - env->view.mid_y;
		z = (pt[i].z);
		pt[i].x += (int)((rx * cos(t * ROT_Z)) + (ry * sin(t * ROT_Z))) - rx;
		pt[i].y += (int)(-(rx * sin(t * ROT_Z)) + (ry * cos(t * ROT_Z))) - ry;
		rx = (pt[i].x) - env->view.mid_x;
		ry = (pt[i].y) - env->view.mid_y;
		z = (pt[i].z);
		pt[i].x += (int)((rx * cos(t * ROT_Y)) - (z * sin(t * ROT_Y))) - rx;
		pt[i].z = (int)((rx * sin(t * ROT_Y)) + (z * cos(t * ROT_Y)));
		rx = (pt[i].x) - env->view.mid_x;
		ry = (pt[i].y) - env->view.mid_y;
		z = (pt[i].z);
		pt[i].y += (int)((ry * cos(t * ROT_X)) + (z * sin(t * ROT_X))) - ry;
		pt[i].z = (int)(-(ry * sin(t * ROT_X)) + (z * cos(t * ROT_X)));
	}
}

static	void		init_coordinates(t_env *env, t_point *pt)
{
	int		n_x;
	int		n_y;
	int		i;

	i = 0;
	n_y = -1;
	while (++n_y < (env->grid.nb_y))
	{
		n_x = -1;
		while (++n_x < env->grid.nb_x)
		{
			pt[i].x = ((X_OFFSET / 10000) + ((env->grid.x_spacing / 10000)
						* n_x) + ((env->grid.zx_spacing / 10000) * n_y));
			pt[i].y = ((Y_OFFSET / 10000) + ((env->grid.y_spacing / 10000)
						* n_y) - ((env->grid.zy_spacing / 10000) * n_x));
			pt[i].d = env->grid.matrix[i + n_y];
			pt[i].z = (pt[i].d * env->grid.z_mult) / 10000;
			i++;
		}
	}
}

int					map_matrix(t_env *env)
{
	int		n;
	int		i;
	t_point	*pt;

	i = -1;
	n = env->grid.nb_x * env->grid.nb_y;
	pt = (t_point *)malloc(sizeof(t_point) * n);
	init_coordinates(env, pt);
	rotate_xyz(env, pt, n);
	while (++i < n)
		pt[i].y -= pt[i].z;
	wire_points(env, pt, n);
	return (1);
}

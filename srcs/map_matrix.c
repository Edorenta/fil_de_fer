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

/*
** int		corners;
** t_point *pt2;
** corners = 4;
** pt2 = (t_point *)malloc(sizeof(t_point) * corners);
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

static	void		wire_points(t_env *env, t_point *pt, int n)
{
	int		i;

	i = n;
	while (i--)
	{
		if (IS_SET_HORI)
			if ((i < (n - 1)) && ((i + 1) % env->grid.nb_x))
				draw_line(env, pt[i], pt[i + 1]);
		if (IS_SET_VERTI)
			if (i < (n - env->grid.nb_x))
				draw_line(env, pt[i], pt[i + env->grid.nb_x]);
		if (IS_SET_DIAG1)
			if (i < (n - env->grid.nb_x) && ((i + 1) % env->grid.nb_x))
				draw_line(env, pt[i], pt[i + env->grid.nb_x + 1]);
		if (IS_SET_DIAG2)
			if ((i - 1) && i < (n - env->grid.nb_x)
			&& ((i) % env->grid.nb_x))
				draw_line(env, pt[i], pt[i + env->grid.nb_x - 1]);
	}
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
		rx = (pt[i].x) - MID_X;
		ry = (pt[i].y) - MID_Y;
		z = (pt[i].z);
		pt[i].x += ((rx * ft_cos(t * ROT_Z)) + (ry * ft_sin(t * ROT_Z))) - rx;
		pt[i].y += (-(rx * ft_sin(t * ROT_Z)) + (ry * ft_cos(t * ROT_Z))) - ry;
		rx = (pt[i].x) - MID_X;
		ry = (pt[i].y) - MID_Y;
		z = (pt[i].z);
		pt[i].x += ((rx * ft_cos(t * ROT_Y)) - (z * ft_sin(t * ROT_Y))) - rx;
		pt[i].z = ((rx * ft_sin(t * ROT_Y)) + (z * ft_cos(t * ROT_Y)));
		rx = (pt[i].x) - MID_X;
		ry = (pt[i].y) - MID_Y;
		z = (pt[i].z);
		pt[i].y += ((ry * ft_cos(t * ROT_X)) + (z * ft_sin(t * ROT_X))) - ry;
		pt[i].z = (-(ry * ft_sin(t * ROT_X)) + (z * ft_cos(t * ROT_X)));
	}
}

static	void		add_perspective(t_env *env, t_point *pt, int n)
{
	int			i;
	int			rx[3];
	int			ry[3];
	int			sign;

	i = -1;
	while (++i < n)
	{
		Y_MAX = pt[i].y > Y_MAX ? pt[i].y : Y_MAX;
		Y_MIN = pt[i].y < Y_MIN ? pt[i].y : Y_MIN;
		X_MAX = pt[i].x > X_MAX ? pt[i].x : X_MAX;
		X_MIN = pt[i].x < X_MIN ? pt[i].x : X_MIN;
	}
	i = -1;
	while (++i < n)
	{
		rx[1] = ft_iabs((pt[i].x) - MID_X);
		ry[1] = ft_iabs((pt[i].y) - MID_Y);
		sign = (pt[i].x) > MID_X ? 1 : -1;
		pt[i].y = pt[i].y * (PERSP_Y / (MAX_PERSP / MAX_PERSP - PERSP * 2))
		+ env->height / 5;
		pt[i].x += ((int)(PERSP_Y * 10000) * sign * rx[1] / 10000)
		* (MAX_PERSP / (MAX_PERSP - PERSP * 2));
	}
}

static	void		init_coordinates(t_env *env, t_point *pt)
{
	int		n_x;
	int		n_y;
	int		i;

	Y_MAX = 0;
	Y_MIN = env->height;
	X_MAX = 0;
	X_MIN = env->width;
	i = 0;
	n_y = -1;
	while (++n_y < (env->grid.nb_y) && (n_x = -1))
		while (++n_x < env->grid.nb_x)
		{
			pt[i].x = ((X_OFFSET / 10000) + ((env->grid.x_spacing / 10000)
						* n_x) + ((env->grid.zx_spacing / 10000) * n_y));
			pt[i].y = ((Y_OFFSET / 10000) + ((env->grid.y_spacing / 10000)
						* n_y) - ((env->grid.zy_spacing / 10000) * n_x));
			pt[i].d = env->grid.matrix[i];
			pt[i].z = (pt[i].d * env->grid.z_mult) / 10000;
			i++;
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
	if (env->view.projection)
		add_perspective(env, pt, n);
	while (++i < n)
		pt[i].y -= pt[i].z;
	wire_points(env, pt, n);
	free(pt);
	return (1);
}

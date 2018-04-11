/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:28:13 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 19:31:36 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rot_z(t_env *env, int dir)
{
	if (dir == 1)
	{
		ROT_Z -= (1 * SPEED);
		if (ROT_Z <= -360)
			ROT_Z = 0;
	}
	else if (dir == 2)
	{
		ROT_Z += (1 * SPEED);
		if (ROT_Z >= 360)
			ROT_Z = 0;
	}
	env->view.last_dir = 3;
}

void	rot_y(t_env *env, int dir)
{
	if (dir == 1)
	{
		ROT_Y -= (1 * SPEED);
		if (ROT_Y <= -360)
			ROT_Y = 0;
	}
	else if (dir == 2)
	{
		ROT_Y += (1 * SPEED);
		if (ROT_Y >= 360)
			ROT_Y = 0;
	}
	env->view.last_dir = 2;
}

void	rot_x(t_env *env, int dir)
{
	if (dir == 1)
	{
		ROT_X -= (1 * SPEED);
		if (ROT_X <= -360)
			ROT_X = 0;
	}
	else if (dir == 2)
	{
		ROT_X += (1 * SPEED);
		if (ROT_X >= 360)
			ROT_X = 0;
	}
	env->view.last_dir = 1;
}

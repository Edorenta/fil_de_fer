/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:51:58 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 02:17:15 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		move_up(t_env *env)
{
	if (POS_Y >= env->height)
	{
		POS_Y -= env->height;
		Y_OFFSET += (env->height * 10000);
	}
	POS_Y += (env->height / 50);
	Y_OFFSET -= ((env->height / 50) * 10000);
	return (1);
}

int		move_down(t_env *env)
{
	if (POS_Y <= -env->height)
	{
		POS_Y += env->height;
		Y_OFFSET -= (env->height * 10000);
	}
	POS_Y -= (env->height / 50);
	Y_OFFSET += ((env->height / 50) * 10000);
	return (1);
}

int		move_left(t_env *env)
{
	if (POS_X <= -env->width)
	{
		POS_X += env->width;
		X_OFFSET += (env->width * 10000);
	}
	POS_X -= (env->width / 50);
	X_OFFSET -= ((env->width / 50) * 10000);
	return (1);
}

int		move_right(t_env *env)
{
	if (POS_X >= env->width)
	{
		POS_X -= env->width;
		X_OFFSET -= ((env->width * 10000) * 10000);
	}
	POS_X += (env->width / 50);
	X_OFFSET += ((env->width / 50) * 10000);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:51:58 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 19:37:15 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		zoom_in(t_env *env)
{
	env->view.zoom += 1;
	env->grid.x_spacing *= 1.15;
	env->grid.y_spacing *= 1.15;
	env->grid.zy_spacing *= 1.15;
	env->grid.zx_spacing *= 1.15;
	env->grid.z_mult *= 1.15;
	env->grid.y_offset -= env->grid.zy_spacing * env->grid.nb_y / 4;
	env->grid.x_offset -= env->grid.zx_spacing * env->grid.nb_x / 4;
}

void		zoom_out(t_env *env)
{
	env->view.zoom -= 1;
	env->grid.x_spacing /= 1.15;
	env->grid.y_spacing /= 1.15;
	env->grid.zy_spacing /= 1.15;
	env->grid.zx_spacing /= 1.15;
	env->grid.z_mult /= 1.15;
	env->grid.y_offset += env->grid.zy_spacing * env->grid.nb_y / 3.5;
	env->grid.x_offset += env->grid.zx_spacing * env->grid.nb_x / 3.5;
}

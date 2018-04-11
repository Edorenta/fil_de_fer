/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 11:53:42 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 19:37:38 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		inc_depth(t_env *env)
{
	env->view.depth++;
	(env->grid.z_mult += 10000);
}

void		dec_depth(t_env *env)
{
	env->view.depth--;
	(env->grid.z_mult -= 10000);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sketch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:56:46 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/16 13:57:36 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int     sketch(t_env *env)
{
	ft_putstr("sketch started\n");
	env->ptest->x = env->width / 2;
	env->ptest->y = env->height / 2;
	env->ptest->clr = WHITE;
	draw_circle(env, env->ptest, env->index);
	ft_putstr("sketch succeeded\n");
	return (0);
}

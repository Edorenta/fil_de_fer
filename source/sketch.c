/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sketch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:56:46 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/14 16:03:00 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int     sketch(t_env *env)
{
	t_point	*pt[2];
	int i;

	i = -1;
	while (++i < 2)
		pt[i] = (t_point *)malloc(sizeof(t_point));	
	pt[0]->x = env->width / 4;
	pt[0]->y = env->height / 4;
	pt[1]->x = env->width / 2;
	pt[1]->y = env->height / 2;
	draw_circle(env, pt[1], env->index, WHITE);
	i = -1;
	while (++i < 2)
		free(pt[i]);
	printf("%d\n",env->index);
	return (0);
}

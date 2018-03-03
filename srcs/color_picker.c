/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 00:55:27 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 02:16:53 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	polygon_fill(t_env *env, t_point **pt, int corners, int size)
{
	int		i;
	t_point	j;
	int		k = corners - 1;
	int8_t	inside;

	j.d = -1;
	while (++(j.d) < size)
	{
		inside = 0;
		i = -1;
		j.y = j.d / env->width;
		j.x = j.d - (j.y * env->width);
		while (++i < corners)
		{
	    	if (((pt[i]->y < j.y && pt[k]->y >= j.y)
			|| (pt[k]->y < j.y && pt[i]->y >= j.y))
			    &&  (pt[i]->x <= j.x || pt[k]->x <= j.x))
			{
		      inside ^= (pt[i]->x + (j.y - pt[i]->y)
					  /(pt[k]->y - pt[i]->y) * (pt[k]->x - pt[i]->x) < j.x);
			}
	    	k = i;
		}
		if (inside)
		   ppixel(env, j.x, j.y, WHITE);	
	}
}

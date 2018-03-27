/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:59:21 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/16 18:58:26 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_op.h"

/*
** double	ft_cos(double x)
** {
** 	double	y;
** 	double	s;
** 	int		i;
**
** 	y = 1.0;
** 	s = -1.0;
** 	i = 2;
** 	while (i < 100)
** 	{
** 		y += s * (ft_dpow(x, i) / ft_dfact(i));
** 		s *= -1;
** 		i += 2;
** 	}
** 	return (y);
** }
*/

double	ft_cos(double x)
{
	double ret;

	if (x < -M_PI)
		x += M_2PI;
	x += M_PI_2;
	if (x > M_PI)
		x -= M_2PI;
	if (x < 0)
	{
		ret = 1.27323954 * x + 0.405284735 * x * x;
		if (ret < 0)
			ret = 0.225 * (ret * (-ret) - ret) + ret;
		else
			ret = 0.225 * (ret * ret - ret) + ret;
	}
	else
	{
		ret = 1.27323954 * x - 0.405284735 * x * x;
		if (ret < 0)
			ret = 0.225 * (ret * (-ret) - ret) + ret;
		else
			ret = 0.225 * (ret * ret - ret) + ret;
	}
	return (ret);
}

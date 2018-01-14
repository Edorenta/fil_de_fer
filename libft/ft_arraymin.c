/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraymin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:30:04 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:36:38 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arraymin(int *tab, unsigned long n)
{
	int				i;
	unsigned long	min;

	if (!tab)
		return (0);
	i = -1;
	min = tab[i];
	while (++i <= (int)n)
		if ((unsigned long)tab[i] < min)
			min = (unsigned long)tab[i];
	return (min);
}

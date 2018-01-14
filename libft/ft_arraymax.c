/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraymax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:29:50 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:36:47 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arraymax(int *tab, unsigned long n)
{
	int				i;
	unsigned long	max;

	if (!tab)
		return (0);
	i = -1;
	max = tab[i];
	while (++i <= (int)n)
		if ((unsigned long)tab[i] > max)
			max = (unsigned long)tab[i];
	return (max);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraymean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:29:56 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:35:53 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arraymean(int *tab, unsigned long n)
{
	int				i;
	unsigned long	sum;

	if (!tab)
		return (0);
	i = -1;
	sum = tab[i];
	while (++i <= (int)n)
		sum += (unsigned long)tab[i];
	return (sum / n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmedian.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:09:25 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/23 18:17:28 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_tabmedian(int **tab, unsigned long x, unsigned long y)
{
	int	i;
	int j;
	int k;
	int *tmp;

	if (!tab)
		return (0);
	tmp = (int *)malloc(sizeof(int) * (x * y));
	i = -1;
	k = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			tmp[++k] = tab[i][j];
	}
	return (ft_arraymedian(tmp, x * y));
}

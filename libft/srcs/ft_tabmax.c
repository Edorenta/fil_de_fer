/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:01:12 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/23 18:16:59 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_tabmax(int **tab, unsigned long x, unsigned long y)
{
	int i;
	int j;
	int max;

	if (!tab)
		return (0);
	i = -1;
	max = tab[0][0];
	while (++i < (int)y)
	{
		j = -1;
		while (++j < (int)x)
			if (tab[i][j] > max)
				max = tab[i][j];
	}
	return (max);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:05:24 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/23 18:16:52 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_tabmean(int **tab, unsigned long x, unsigned long y)
{
	int i;
	int j;
	int sum;

	if (!tab)
		return (0);
	i = -1;
	sum = 0;
	while (++i < (int)y)
	{
		j = -1;
		while (++j < (int)x)
			sum += tab[i][j];
	}
	return (sum / (x * y));
}

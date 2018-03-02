/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraymin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:30:04 by pde-rent          #+#    #+#             */
/*   Updated: 2018/01/23 18:08:30 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_arraymin(int *tab, unsigned long n)
{
	int i;
	int min;

	if (!tab)
		return (0);
	i = -1;
	min = tab[0];
	while (++i < (int)n)
		if (tab[i] < min)
			min = tab[i];
	return (min);
}

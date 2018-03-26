/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayrev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:30:12 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:50:32 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_arrayrev(int *tab, int left, int right)
{
	int tmp;

	if (tab)
		while (left < right)
		{
			tmp = tab[left];
			tab[left++] = tab[right];
			tab[right--] = tmp;
		}
}

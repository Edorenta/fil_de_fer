/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:30:08 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:37:50 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrayprint(int *tab, unsigned long n, char sep)
{
	int i;

	i = -1;
	if (tab && n)
		while (++i <= (int)n)
		{
			ft_putnbr(tab[i]);
			if (i < (int)n)
				ft_putchar(sep);
		}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:31:11 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:31:09 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long int nb, uint8_t base)
{
	long	tmp;
	uint8_t	dec;

	dec = 1;
	if (base < 2 || base > 16)
		return ;
	if (nb < 0 && (nb *= -1))
		ft_putchar('-');
	tmp = nb;
	while ((tmp /= (long)base) > 0)
		dec++;
	while (dec-- > 0)
	{
		tmp = nb / ft_pow((int)base, (int)dec);
		ft_putchar((tmp > 9) ? (tmp + 'A' - 10) : (tmp + '0'));
		tmp *= ft_pow((int)base, (int)dec);
		nb -= tmp;
	}
}

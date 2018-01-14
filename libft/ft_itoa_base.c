/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:29:55 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:26:01 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long int nb, uint8_t base)
{
	uint8_t	dec;
	long	tmp;
	int		i;
	char	*str;

	i = -1;
	dec = 1;
	if (base < 2 || base > 16)
		return (NULL);
	tmp = ((nb < 0) ? -nb : nb);
	while ((tmp /= (long)base) > 0)
		dec++;
	if (!(str = malloc(sizeof(char) * (dec) + 2)))
		return (NULL);
	if (nb < 0 && (nb *= -1))
		str[++i] = '-';
	while (dec-- > 0)
	{
		tmp = nb / ft_pow((int)base, (int)dec);
		str[++i] = ((tmp > 9) ? (tmp + 'A' - 10) : (tmp + '0'));
		tmp *= ft_pow((int)base, (int)dec);
		nb -= tmp;
	}
	str[++i] = '\0';
	return (str);
}

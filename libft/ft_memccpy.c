/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:33:52 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:26:29 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*src2;
	unsigned char	*dst2;

	i = 0;
	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	while (i < len)
	{
		dst2[i] = src2[i];
		if (src2[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

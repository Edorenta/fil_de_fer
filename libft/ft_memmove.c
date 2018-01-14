/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:34:02 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:26:44 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)malloc(sizeof(*tmp) * n);
	if (tmp)
	{
		ft_memcpy(tmp, src, n);
		ft_memcpy(dst, tmp, n);
		free(tmp);
	}
	return (dst);
}

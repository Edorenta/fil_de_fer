/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:33:43 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:26:42 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	void	*mem;

	if (!src)
		return (NULL);
	mem = (void *)malloc(n);
	if (!mem)
		return (NULL);
	mem = ft_memcpy(mem, src, n);
	return (mem);
}

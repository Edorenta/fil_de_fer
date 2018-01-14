/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:33:55 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:26:31 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		if (((unsigned char*)str)[i] == (unsigned char)c)
			return ((void*)(str + i));
	return (NULL);
}

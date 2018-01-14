/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:41:20 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/27 14:32:09 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	c2;
	char			*tmp;

	tmp = NULL;
	c2 = (unsigned char)c;
	while (*str)
	{
		if (*str == c2)
			tmp = (char *)str;
		str++;
	}
	if (*str == c2)
		return ((char *)str);
	return (tmp);
}

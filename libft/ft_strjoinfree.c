/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:05:07 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/30 19:10:16 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, char **addr)
{
	char	*cat;
	size_t	n;

	if (!s1 || !s2)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((cat = ft_strnew(n)) == 0)
		return (NULL);
	cat = ft_strcpy(cat, (char*)s1);
	cat = ft_strcat(cat, s2);
	if (addr)
		free(*addr);
	return (cat);
}

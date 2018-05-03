/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 00:07:38 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 02:40:37 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libclr.h"

long			parse_long(char *str)
{
	long	res;

	res = 0;
	while (*str)
		res = res * 10 + (*str++ - '0');
	return (res);
}

static	double	floating_part(char *str)
{
	int		n;
	double	f;

	n = 0;
	f = 0.0;
	while (*str >= '0' && *str <= '9')
	{
		f = (f * 10.0) + (*str - '0');
		++str;
		++n;
	}
	return (f / pow(10.0, n));
}

double			parse_double(char *str)
{
	double	res;
	int8_t	neg;

	neg = 0;
	res = 0.0;
	if (*str == '-')
	{
		neg = 1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10.0) + (*str - '0');
		++str;
	}
	if (*str == '.')
	{
		str++;
		res += floating_part(str);
	}
	return (neg ? -res : res);
}

int				parse_rgb(char *str)
{
	int		i;
	int		j;
	int		k;
	int		rgb[3];
	char	tmp[10];

	i = -1;
	k = 0;
	while (str[++i])
		if (str[i] >= '0' && str[i] <= '9')
		{
			j = -1;
			while (str[i] && str[i] >= '0' && str[i] <= '9' && j < 3)
			{
				tmp[++j] = str[i];
				i++;
			}
			tmp[++j] = '\0';
			rgb[k] = parse_long(tmp);
			++k;
		}
	if (str[0] == '(' && str[i - 1] == ')' && (rgb[0] >= 0 && rgb[0] < 256)
		&& (rgb[1] >= 0 && rgb[1] < 256) && (rgb[2] >= 0 && rgb[2] < 256))
		return (rgb_to_hex(rgb[0], rgb[1], rgb[2]));
	return (-1);
}

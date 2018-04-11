/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:53:36 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 18:47:12 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	int	color_test(int clr)
{
	int rgb[3];

	rgb[0] = hex_r(clr, MODE_RGB);
	rgb[1] = hex_g(clr, MODE_RGB);
	rgb[2] = hex_b(clr, MODE_RGB);
	if (rgb[0] > 255 || rgb[0] < 0
		|| rgb[1] > 255 || rgb[1] < 0
		|| rgb[2] > 255 || rgb[2] < 0)
		return (0);
	return (1);
}

int			put_err(int errno)
{
	if (errno == 1)
		ft_putstr("Usage:\n"
				"\t\t./fdf \"map filename\" << map to load\n"
				"\t\t\"(R,G,B)\" << default map highs color (optional)\n"
				"\t\t\"(R,G,B)\" << default map lows color (optional)\n"
				"\t\t\"(R,G,B)\" << default background color (optional)\n"
				"\t\t RGB colors will be given on an 8 bit basis (0 -> 255)\n");
	else if (errno == 2)
		ft_putstr("error: invalid RGB color parameter\n");
	else if (errno == 3)
		ft_putstr("error: invalid file\n");
	else if (errno == 4)
		ft_putstr("error: map (x,y) format not compliant\n");
	return (errno);
}

int			check_av(int ac, char **av)
{
	int errno;

	errno = 0;
	if (ac < 2 || ac > 4)
		errno = 1;
	else if ((ac == 3 && !color_test(parse_rgb(av[2]))) || (ac == 4 &&
		(!color_test(parse_rgb(av[2])) || !color_test(parse_rgb(av[3])))))
		errno = 2;
	else if (!check_map(raw_str(av[1])))
		errno = 3;
	else if (check_map(raw_str(av[1])) == -1)
		errno = 4;
	return (errno);
}

int			check_map(char *str)
{
	long	i;
	int		n_x;
	int		n_y;

	i = -1;
	n_x = 0;
	n_y = 0;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != 32
			&& str[i] != '\n' && (str[i] == '-' && !ft_isdigit(str[i + 1])))
			return (0);
		if (ft_isdigit(str[i]) && !ft_isdigit(str[i + 1]))
			n_x++;
		if (str[i] == '\n' || (!str[i + 1] && str[i] != '\n'))
			n_y++;
	}
	if (n_x % n_y)
		return (-1);
	return (1);
}

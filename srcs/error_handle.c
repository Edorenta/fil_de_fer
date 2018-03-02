/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:53:36 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 00:03:49 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	int	parse_color(char *str)
{
	int		i;
	int		j;
	int		k;
	int		rgb[3];
	char	*tmp;

	i = 0;
	k = 0;
	tmp = (char *)malloc(sizeof(char) * 3);
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
		{
			j = -1;
			while (ft_isdigit(str[i]))
			{
				tmp[++j] = str[i];
				i++;
			}
			rgb[k] = ft_atoi(tmp);
			++k;	
		}
	}
	free(tmp);
	return (rgb_to_hex(rgb[0], rgb[1], rgb[2]));
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
	if ((ac == 3 && !color_test(av[2])) || (ac == 4
		&& (!color_test(av[2]) || !color_test(av[3]))))
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
	while(str[++i])
	{
		//printf("%c", str[i]);
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
	return 1;
}

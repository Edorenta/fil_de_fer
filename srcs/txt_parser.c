/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:20:22 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 15:24:59 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char			*raw_str(char *file_name)
{
	int		fd;
	int		file_size;
	char	buf;
	char	*tmp;

	file_size = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	while (read(fd, &buf, 1) > 0)
	{
		if (!ft_isspace(buf) && !ft_isdigit(buf) && buf != '-')
			return (NULL);
		++file_size;
	}
	if (!(file_size))
		return (NULL);
	close(fd);
	IS_CHAR((tmp = (char *)malloc(sizeof(char) * ((file_size + 1)))));
	fd = open(file_name, O_RDONLY);
	read(fd, tmp, file_size);
	tmp[file_size] = '\0';
	close(fd);
	return (tmp);
}

static int		getsign(char c, int sign)
{
	if (c == '-')
		return (-1);
	else if (ft_isdigit(c))
		return (sign);
	return (1);
}

static int		map_str_tab(t_env *env, char *str)
{
	int		i;
	int		j;
	int		index;
	int		sign;
	char	tmp[10];

	i = -1;
	sign = 1;
	index = -1;
	while (str[++i])
	{
		sign = getsign(str[i], sign);
		if (ft_isdigit(str[i]))
		{
			j = -1;
			while (ft_isdigit(str[i]) && (tmp[++j] = str[i]))
				i++;
			tmp[++j] = '\0';
			env->grid.matrix[++index] = parse_long(tmp) * sign;
		}
	}
	free(str);
	grid_init(env);
	return (1);
}

static int		dim_tab(t_env *env, char *str)
{
	int		i;

	i = 0;
	env->grid.nb_x = 0;
	env->grid.nb_tot = 0;
	while (str[i])
	{
		while (str[i] && !ft_isdigit(str[i]))
			i++;
		while (str[i] && ft_isdigit(str[i]))
			i++;
		while (str[i] && ft_isspace(str[i]) && str[i] != 10)
			i++;
		env->grid.nb_tot++;
		if (!(env->grid.nb_x) && str[i] == '\n')
			env->grid.nb_x = env->grid.nb_tot;
	}
	env->grid.nb_y = env->grid.nb_tot / env->grid.nb_x;
	env->grid.nb_tot = env->grid.nb_x * env->grid.nb_y;
	IS_INT((env->grid.matrix = (int *)malloc(sizeof(int)
			* (env->grid.nb_tot))));
	return (map_str_tab(env, str));
}

int				tab_init(t_env *env, char *str)
{
	return (dim_tab(env, str));
}

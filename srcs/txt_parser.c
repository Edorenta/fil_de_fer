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

char    		*raw_str(char *file_name)
{
	int     fd;
	int     i;
	int		file_size;
	char    buf;
	char    *tmp;
	
	file_size = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	while ((read(fd, &buf, 1) > 0))
			++file_size;
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

static	int		map_str_tab(t_env *env, char *str)
{
	int		i;
	int		j;
	int		index;
	int		sign;
	char	*tmp;

	i = -1;
	sign = 1;
	index = -1;
	tmp = (char *)malloc(sizeof(char) * 10);
	printf("%s\n",str);
	while(str[++i])
	{
		sign = (str[i] == '-' ? -1 : ft_isdigit(str[i]) ? sign : 1);
		if (ft_isdigit(str[i]))
		{
			j = -1;
			while (ft_isdigit(str[i]))
			{
				tmp[++j] = str[i];
				i++;
			}
			tmp[++j] = '\0';
			env->grid.matrix[++index] = parse_long(tmp) * sign;
			//printf("%d ", env->grid.matrix[index]);
		}
	}
	free(tmp);
	free(str);
	grid_init(env);
	return (1);
}

static	int		dim_tab(t_env *env, char *str)
{
	int		i;

	i = 0;
	env->grid.nb_x = 0;
	env->grid.nb_tot = 0;
	while(str[i])
	{
		while (str[i] && !ft_isdigit(str[i]))
			i++;
		while (str[i] && ft_isdigit(str[i]))
			i++;
		if (!(env->grid.nb_x) && str[i] == '\n')
			env->grid.nb_x = env->grid.nb_tot;
	    env->grid.nb_tot++;
	}
	env->grid.nb_y = env->grid.nb_tot / env->grid.nb_x;
	/*
	ft_putstr("ok\n");
	ft_putstr(" nx: ");
	ft_putnbr(env->grid.nb_x);
	ft_putstr(" ny: ");
	ft_putnbr(env->grid.nb_y);
	ft_putchar('\n');
	*/
	i = -1;
	IS_INT((env->grid.matrix = (int *)malloc(sizeof(int) * (env->grid.nb_tot))));
	return (map_str_tab(env, str));
}

int		tab_init(t_env *env, char *str)
{
	return (dim_tab(env, str));
}

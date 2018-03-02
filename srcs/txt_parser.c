/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:20:22 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/02 16:26:05 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//convert the raw file to a string
char    		*raw_str(char *file_name)
{
	int     fd;
	int     i;
	int     handle;
	char    buf[BUFF_SIZE];
	char    *tmp;

	i = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	while ((handle = read(fd, buf, BUFF_SIZE)))
		i++;
	close(fd);
	IS_CHAR((tmp = (char *)malloc(sizeof(char) * (i * BUFF_SIZE + 1))));
	fd = open(file_name, O_RDONLY);
	handle = read(fd, tmp, (BUFF_SIZE * i + 1));
	i = BUFF_SIZE * (i - 1) - 1;
	while (tmp[++i])
		if (tmp[i] == '\n')
			if(!ft_isdigit(tmp[i + 1]) && !ft_isoperator(tmp[i + 1]))
				while(tmp[++i])
					tmp[i] = '\0';
	return (tmp);
}

//convert the char** tab to a matrix of point levels (size nb_x * nb_y)
static	int		tab_convert(t_env *env, char **tab)
{
	int		i;
	int		j;

	i = -1;
	IS_INT((MX = (int **)malloc(sizeof(int *) * env->grid->nb_y)));
    while (++i < env->grid->nb_y)
		IS_INT((MX[i] = (int *)malloc(sizeof(int) * env->grid->nb_x)));
	i = -1;
	while (++i < env->grid->nb_y)
	{
		j = -1;
		while (++j < env->grid->nb_x)
			MX[i][j] = ft_atoi(tab[(env->grid->nb_x * i) + j]);
	}
	i = -1;
	while (++i < env->grid->nb_y)
		free(tab[i]);
	free(tab);
	grid_init(env);
	return (1);
}

//convert the unique string to a char **table
static	int		map_str_tab(t_env *env, char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = -1;
	j = -1;
	k = 0;
	IS_INT((tab = (char **)malloc(sizeof(char *)
				* env->grid->nb_y * env->grid->nb_x + 10)));
	while (++i < (env->grid->nb_y * env->grid->nb_x))
		IS_INT((tab[i] = (char *)malloc(sizeof(char) * 10)))	
	i = -1;
	while (str[++i])
		if (str[i] > 32)
		{
			while (str[i] && (ft_isoperator(str[i]) || ft_isdigit(str[i])))
			{
				tab[k][++j] = str[i];
				i++;
			}
			while (tab[k][++j])
				tab[k][j] = '\0';
			j = -1;
			k++;
		}
	free(str);
	return (tab_convert(env, tab));
}

//convert each lines of the initial file into a tab of char* matching wireframe
static	int		dim_tab(t_env *env, char *str)
{
	int i;
	int j;

	i = -1;
	j = ((ft_isdigit(str[0]) || ft_isoperator(str[0])) ? 1 : 0);

	while(str[++i] != '\n')
	{
		if (str[i] == 32)
			if (ft_isdigit(str[i + 1]) || ft_isoperator(str[i + 1]))
				j++;
		if (str[i] == '\n')
			if (ft_isdigit(str[i + 1]) || ft_isoperator(str[i + 1]))
				j++;
	}
	env->grid->nb_x = j;
	return (map_str_tab(env, str));
}

//find the theoretical size of the wireframe counting \n and pass the data
int		tab_init(t_env *env, char *str)
{
	int		i;
	int		j;
	char	**tab;
	
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == '\n')
			j++;
	if (str[i-1] != '\n' && !str[i])
		j++;
	env->grid->nb_y = j;
	return (dim_tab(env, str));
}

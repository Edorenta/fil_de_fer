/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:42:20 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/02 15:11:56 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		main(int ac, char **av)
{
	t_env	*env;
	
	if (check_av(ac, av))
		return (put_err(check_av(ac, av)));
	env = env_init();
	env->file_name = ft_strdup(av[1]);
	tab_init(env, raw_str(env->file_name));
	sketch(env);
	dyna_key_hook(env);
	win_refresh(env);
	return (0);
}

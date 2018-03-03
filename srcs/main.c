/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:42:20 by pde-rent          #+#    #+#             */
/*   Updated: 2018/03/03 08:45:40 by pde-rent         ###   ########.fr       */
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
	if (ac > 2)
	{
		env->view.clr1 = parse_rgb(av[2]);
		if (ac > 3)
		{
			env->view.clr2 = parse_rgb(av[3]);
			if (ac == 5)
				env->view.background = parse_rgb(av[4]);
		}
	}
	env->clr1 = env->view.clr1;
	env->clr2 = env->view.clr2;
	env->clr3 = env->view.background;
	tab_init(env, raw_str(env->file_name));
	sketch(env);
	dyna_key_hook(env);
	win_refresh(env);
	return (0);
}

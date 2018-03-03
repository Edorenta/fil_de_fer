#include "../include/fdf.h"

int		zoom_in(t_env *env)
{
	env->view.zoom += 1;
	env->grid.x_spacing *= 1.15;
	env->grid.y_spacing *= 1.15;
	env->grid.zy_spacing *= 1.15;
	env->grid.zx_spacing *= 1.15;
	env->grid.z_mult *= 1.15;
	//env->view.pos_y /= 1.15;
	env->grid.y_offset -= env->grid.zy_spacing * env->grid.nb_y / 4;
	//env->view.pos_x /= 1.15;
	env->grid.x_offset -= env->grid.zx_spacing * env->grid.nb_x / 4;
	return (1);
}

int		zoom_out(t_env *env)
{
	env->view.zoom -= 1;
	env->grid.x_spacing /= 1.15;
	env->grid.y_spacing /= 1.15;
	env->grid.zy_spacing /= 1.15;
	env->grid.zx_spacing /= 1.15;
	env->grid.z_mult /= 1.15;
 	//env->view.pos_y *= 1.15;
	env->grid.y_offset += env->grid.zy_spacing * env->grid.nb_y / 3.5;
	//env->view.pos_x *= 1.15;
	env->grid.x_offset += env->grid.zx_spacing * env->grid.nb_x / 3.5;
	return (1);
}

#include "../include/fdf.h"

int     rot_z(t_env *env, int dir)
{
	if (dir == 1) //rotate z left
	{
		env->view->rot_z -= (1);
		if (env->view->rot_z <= -360)
			env->view->rot_z = 0;
	}
	else if (dir == 2)
	{
		env->view->rot_z += (1);
		if (env->view->rot_z >= 360)
			env->view->rot_z = 0;
	}
	env->view->last_dir = 3;
	return (1);
}

int     rot_y(t_env *env, int dir)
{
	if (dir == 1) //rotate z left
	{
		env->view->rot_y -= (1);
		if (env->view->rot_y <= -360)
			env->view->rot_y = 0;
	}
	else if (dir == 2)
	{
		env->view->rot_y += (1);
		if (env->view->rot_y >= 360)
			env->view->rot_y = 0;
	}
	env->view->last_dir = 2;
	return (1);
}

int     rot_x(t_env *env, int dir)
{
	if (dir == 1) //rotate z left
	{
		env->view->rot_x -= (1);
		if (env->view->rot_x <= -360)
			env->view->rot_x = 0;
	}
	else if (dir == 2)
	{
		env->view->rot_x += (1);
		if (env->view->rot_x >= 360)
			env->view->rot_x = 0;
	}
	env->view->last_dir = 1;
	return (1);
}

/*
   int     rot_y(t_env *env, int dir)
   {
   if (dir == 1) //rotate z left
   env->view->rot_y -= (1);
   else if (dir == 2)
   env->view->rot_y += (1);
   if (env->view->rot_y < 10)
   env->view->shift_y = (1 / (10 - (double)env->view->rot_y));
   else if (env->view->rot_y < 20 && env->view->rot_y >= 10)
   env->view->shift_y = (1 + (1 / (10 - ((double)env->view->rot_y - 10))));
   else if (env->view->rot_y < 30 && env->view->rot_y >= 20)
   env->view->shift_y = (2 - (1 / (10 - ((double)env->view->rot_y - 20))));
   else if (env->view->rot_y < 40 && env->view->rot_y >= 30)
   env->view->shift_y = (1 / ((double)env->view->rot_y - 30));
   else if (env->view->rot_y == 40)
   {
   env->view->rot_y = 0;
   env->view->shift_y = 0;
   }
   return (1);
   }

   int     rot_x(t_env *env, int dir)
   {
   if (dir == 1) //rotate z left
   env->view->rot_x -= (1);
   else if (dir == 2)
   env->view->rot_x += (1);
   if (env->view->rot_x < 10)
   env->view->shift_x = (1 / (10 - (double)env->view->rot_x));
   else if (env->view->rot_x < 20 && env->view->rot_x >= 10)
   env->view->shift_x = (1 + (1 / (10 - ((double)env->view->rot_x - 10))));
   else if (env->view->rot_x < 30 && env->view->rot_x >= 20)
   env->view->shift_x = (2 - (1 / (10 - ((double)env->view->rot_x - 20))));
   else if (env->view->rot_x < 40 && env->view->rot_x >= 30)
   env->view->shift_x = (1 / ((double)env->view->rot_x - 30));
   else if (env->view->rot_x == 40)
   {
   env->view->rot_x = 0;
   env->view->shift_x = 0;
   }
   return (1);
   }
   */


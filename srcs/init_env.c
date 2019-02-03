/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:52:59 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/16 14:53:03 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		*new_env(void)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	env->name = NULL;
	env->p = NULL;
	return (env);
}

t_env		*init_env(char *av1)
{
	t_env	*env;

	if (!(env = new_env()))
		return (NULL);
	env->name = av1;
	env->mlx = mlx_init();
	if (!env->mlx)
		return (NULL);
	if (!(env->win = mlx_new_window(env->mlx, X_SIZE + 200, Y_SIZE, \
			"ghaas's Fract'ol")))
		return (NULL);
	env->img = init_img(env);
	if (!ft_strcmp(env->name, "mandelbrot") || !ft_strcmp(env->name, "bship") \
		|| !ft_strcmp(env->name, "tricorn") || !ft_strcmp(env->name, "celtic"))
		env->p = init_mandelbrot();
	else if (!ft_strcmp(env->name, "julia") || !ft_strcmp(env->name, "tst") \
		|| !ft_strcmp(env->name, "sword") || !ft_strcmp(env->name, "chameleon"))
		env->p = init_julia();
	return (env);
}

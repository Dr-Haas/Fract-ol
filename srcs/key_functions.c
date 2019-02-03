/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:53:34 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/16 14:53:43 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		iter(int keycode, t_env *env)
{
	if (keycode == MORE_ITER)
		env->p->iter++;
	if (keycode == LESS_ITER && env->p->iter > 2)
		env->p->iter--;
}

void		theme(int keycode, t_env *env)
{
	if (keycode == T1)
		env->p->color = RGB(255, 255, 255);
	if (keycode == T2)
		env->p->color = RGB(211, 38, 53);
	if (keycode == T3)
		env->p->color = RGB(103, 248, 140);
	if (keycode == T4)
		env->p->color = RGB(57, 211, 108);
	if (keycode == T5)
		env->p->color = RGB(165, 129, 255);
}

void		color(int keycode, t_env *env)
{
	if (keycode == MORE_COLOR && env->p->color < INT_MAX - 2000)
		env->p->color += 2000;
	if (keycode == LESS_COLOR && env->p->color > 256)
		env->p->color -= 2000;
}

void		origin(int keycode, t_env *env)
{
	if (keycode == ORIGIN)
	{
		if (!ft_strcmp(env->name, "julia") || \
			!ft_strcmp(env->name, "chameleon") || \
			!ft_strcmp(env->name, "sword") || \
			!ft_strcmp(env->name, "tst"))
			env->p = init_julia();
		else
			env->p = init_mandelbrot();
	}
}

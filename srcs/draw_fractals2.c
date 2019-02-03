/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:52:28 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/16 14:52:33 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_julia(t_env *e)
{
	while (e->p->x < X_SIZE)
	{
		e->p->y = 0;
		while (e->p->y < Y_SIZE)
		{
			e->p->z_r = e->p->x / e->p->zoom + e->p->x1;
			e->p->z_i = e->p->y / e->p->zoom + e->p->y1;
			e->p->i = 0;
			while ((e->p->z_r * e->p->z_r + e->p->z_i * e->p->z_i) < 4 && \
				(e->p->i < e->p->iter))
			{
				e->p->tmp = e->p->z_r;
				e->p->z_r = (e->p->z_r * e->p->z_r) - (e->p->z_i * e->p->z_i) \
					+ e->p->c_r;
				e->p->z_i = 2 * e->p->z_i * e->p->tmp + e->p->c_i;
				e->p->i++;
			}
			set_pixel_to_image(e);
			e->p->y++;
		}
		e->p->x++;
	}
	e->p->x = 0;
}

void		draw_chameleon(t_env *e)
{
	while (e->p->x < X_SIZE)
	{
		e->p->y = 0;
		while (e->p->y < Y_SIZE)
		{
			e->p->z_r = e->p->x / e->p->zoom + e->p->x1;
			e->p->z_i = e->p->y / e->p->zoom + e->p->y1;
			e->p->i = 0;
			while ((e->p->z_r * e->p->z_r) + (e->p->z_i * e->p->z_i) < 4 && \
				(e->p->i < e->p->iter))
			{
				e->p->tmp = e->p->z_r;
				e->p->z_r = ((e->p->z_r * e->p->z_r) - (e->p->z_i * \
					e->p->z_i) + e->p->c_r);
				e->p->z_i = -2 * e->p->z_i * e->p->tmp + e->p->c_i;
				e->p->i++;
			}
			set_pixel_to_image(e);
			e->p->y++;
		}
		e->p->x++;
	}
	e->p->x = 0;
}

void		draw_sword(t_env *e)
{
	while (e->p->x < X_SIZE)
	{
		e->p->y = 0;
		while (e->p->y < Y_SIZE)
		{
			e->p->z_r = e->p->x / e->p->zoom + e->p->x1;
			e->p->z_i = e->p->y / e->p->zoom + e->p->y1;
			e->p->i = 0;
			while ((e->p->z_r * e->p->z_r) + (e->p->z_i * e->p->z_i) < 4 && \
				(e->p->i < e->p->iter))
			{
				e->p->tmp = e->p->z_r;
				e->p->z_r = fabs((e->p->z_r * e->p->z_r) - (e->p->z_i * \
					e->p->z_i) + e->p->c_r);
				e->p->z_i = fabs(2 * e->p->z_i * e->p->tmp + e->p->c_i);
				e->p->i++;
			}
			set_pixel_to_image(e);
			e->p->y++;
		}
		e->p->x++;
	}
	e->p->x = 0;
}

void		draw_tst(t_env *e)
{
	while (e->p->x < X_SIZE)
	{
		e->p->y = 0;
		while (e->p->y < Y_SIZE)
		{
			e->p->z_r = e->p->x / e->p->zoom + e->p->x1;
			e->p->z_i = e->p->y / e->p->zoom + e->p->y1;
			e->p->i = 0;
			while ((e->p->z_r * e->p->z_r) + (e->p->z_i * e->p->z_i) < 4 && \
				e->p->i < e->p->iter)
			{
				e->p->tmp = e->p->z_r;
				e->p->z_r = fabs((e->p->z_r * e->p->z_r) - (e->p->z_i * \
					e->p->z_i)) + e->p->c_r;
				e->p->z_i = 2 * e->p->z_i * e->p->tmp + e->p->c_i;
				e->p->i++;
			}
			set_pixel_to_image(e);
			e->p->y++;
		}
		e->p->x++;
	}
	e->p->x = 0;
}

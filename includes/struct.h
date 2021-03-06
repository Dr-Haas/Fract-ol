/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:51:52 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/16 14:51:55 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef	struct			s_img
{
	void				*img;
	char				*data;
	int					sizeline;
	int					endian;
	int					bpp;
}						t_img;

typedef	struct			s_param
{
	int					iter;
	int					x;
	int					y;
	int					i;
	int					motion;
	int					color;
	long double			zoom;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				c_r;
	double				z_i;
	double				c_i;
	double				z_r;
	double				tmp;
}						t_param;

typedef	struct			s_env
{
	char				*name;
	void				*mlx;
	void				*win;
	t_img				*img;
	t_param				*p;

}						t_env;

#endif

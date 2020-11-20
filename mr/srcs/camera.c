/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:37:54 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/17 13:43:40 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_point3		set_camera(int n, t_rendered rd, t_minilibx mlx)
{
	double		img_aspect_ratio;
	double		fov;
	double		x_offset;
	double		y_offset;
	t_point3	p;

	x_offset = ((n % 3) * 0.5);
	y_offset = ((n / 3) * 0.5);
	img_aspect_ratio = (double)rd.xres / (double)rd.yres;
	fov = tan((mlx.cam->fov * M_PI / 180) / 2);
	p.x = ((2 * ((rd.i + x_offset) / rd.xres)) - 1) * img_aspect_ratio * fov;
	p.x *= -1;
	p.y = (1 - (2 * ((rd.j + y_offset) / rd.yres))) * fov;
	p.z = 1;
	p = normalize(p);
	return (p);
}

static t_vector		look_at(t_vector d, t_vector cam_nv)
{
	t_vector	x_axis;
	t_vector	y_axis;
	t_vector	z_axis;
	t_vector	rotated;
	t_vector	vup;

	vup = new_vector(0, 1, 0);
	z_axis = cam_nv;
	if (cam_nv.y == 1 || cam_nv.y == -1)
		x_axis = cam_nv.y == 1 ? (t_vector) {1, 0, 0} : (t_vector) {-1, 0, 0};
	else
		x_axis = normalize(cross_product(vup, z_axis));
	y_axis = normalize(cross_product(z_axis, x_axis));
	rotated.x = d.x * x_axis.x + d.y * y_axis.x + d.z * z_axis.x;
	rotated.y = d.x * x_axis.y + d.y * y_axis.y + d.z * z_axis.y;
	rotated.z = d.x * x_axis.z + d.y * y_axis.z + d.z * z_axis.z;
	rotated = normalize(rotated);
	return (rotated);
}

int					calc_ray(int n, t_rendered rd, t_wrapper *w)
{
	t_vector	d;
	int			color;

	d = set_camera(n, rd, w->mlx);
	d = look_at(d, w->mlx.cam->nv);
	color = trace_ray(w->mlx.cam->o, d, w);
	return (color);
}

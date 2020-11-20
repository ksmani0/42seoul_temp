/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:52:50 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/18 17:52:37 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		trace_ray(t_point3 o, t_vector d, t_wrapper *w)
{
	t_ray		ray;
	t_figures	cl_fig;
	t_inter		inter;
	double		closest_inter;

	ray.o = o;
	ray.d = d;
	closest_inter = INFINITY;
	cl_fig.flag = -1;
	all_intersections(ray, w->lst, &cl_fig, &closest_inter);
	inter.p = vector_add(o, multiply_scalar(d, closest_inter));
	inter.normal = calc_normal(inter.p, d, &cl_fig);
	inter.color = cl_fig.flag == -1 ? w->data.bgr : cl_fig.color;
	compute_light(&inter, w->data, w->lst);
	return (inter.color);
}

void	all_intersections(t_ray r, t_figures *lst,
					t_figures *closest_fig, double *closest_inter)
{
	double dist;

	while (lst)
	{
		if (lst->flag == SP)
			dist = sphere_intersection(r.o, r.d, lst);
		else if (lst->flag == CY)
			dist = cylinder_intersection(r.o, r.d, lst);
		else if (lst->flag == SQ)
			dist = square_intersection(r.o, r.d, lst);
		else if (lst->flag == TR)
			dist = triangle_intersection(r.o, r.d, lst);
		else if (lst->flag == PL)
			dist = plane_intersection(r.o, r.d, lst);
		if (dist > EPSILON && dist < *closest_inter)
		{
			*closest_inter = dist;
			*closest_fig = *lst;
		}
		lst = lst->next;
	}
}

int		calc_pixel_color(t_wrapper *w)
{
	t_rendered	rd;
	int			color;

	rd.limit = 3;
	rd.xres = w->data.xres;
	rd.yres = w->data.yres;
	rd.i = w->i;
	rd.j = w->j;
	w->data.bgr = 0x000000;
	color = calc_ray(0, rd, w);
	return (color);
}

void	render_scene(t_wrapper *w)
{
	int		color;
	int		n;
	int		pad;

	n = w->data.yres;
	w->j = n * w->tid;
	pad = w->mlx.cam->pad;
	while (w->j < (n * (w->tid + 1)))
	{
		w->i = 0;
		while (w->i < w->data.xres)
		{
			color = calc_pixel_color(w);
			w->mlx.cam->px_img[w->j * (pad + w->data.xres) + w->i] = color;
			w->i++;
		}
		if (w->tid == 0)
			ft_printf("\rRendering scene... (cam %d/%d) [%d%%]",
				w->mlx.cam->idx, w->data.cam_nb, 100 * (w->j % n) / n);
		w->j++;
	}
	if (w->tid == 0)
		ft_printf("\rRendering scene... (cam %d/%d) [100%%]\n",
			w->mlx.cam->idx, w->data.cam_nb);
}

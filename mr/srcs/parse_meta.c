/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:49:05 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/16 20:15:14 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_res(t_scene *data, char **str)
{
	if (data->res_init > 0)
		scene_error("Resoultion (R) can be declared only once.");
	else
		data->res_init = 1;
	skip_space(str);
	data->xres = ft_stoi(str);
	check_range(data->xres, 1, INFINITY, "Resolution");
	data->yres = ft_stoi(str);
	check_range(data->yres, 1, INFINITY, "Resolution");
}

void	parse_ambient_lightning(t_scene *data, char **str)
{
	if (data->al_init > 0)
		scene_error("Ambient lightning (A) can be declared only once.");
	else
		data->al_init = 1;
	skip_space(str);
	data->ambient_light = ft_stof(str);
	check_range(data->ambient_light, 0, 1, "Ambient lightning");
	data->al_color = parse_color(str);
}

void	parse_camera(t_minilibx *mlx, t_scene *data, char **str)
{
	t_camera	*elem;
	t_camera	*list;
	int			prev_idx;

	list = mlx->cam;
	prev_idx = 0;
	if (!(elem = malloc(sizeof(t_camera))))
		fatal_error("in malloc");
	elem->next = NULL;
	if (list)
	{
		while (list->next)
			list = list->next;
		prev_idx = list->idx;
		list->next = elem;
	}
	else
		mlx->cam = elem;
	skip_space(str);
	elem->idx = prev_idx + 1;
	data->cam_nb = elem->idx;
	elem->o = parse_point3(str);
	elem->nv = normalize(parse_point3(str));
	elem->fov = ft_stoi(str);
	check_range(elem->fov, 0, 180, "camera fov");
}

void	parse_light(t_scene *data, char **str)
{
	t_light	*elem;
	t_light	*list;

	list = data->l;
	if (!(elem = malloc(sizeof(t_light))))
		fatal_error("in malloc");
	elem->next = NULL;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elem;
	}
	else
		data->l = elem;
	skip_space(str);
	elem->o = parse_point3(str);
	elem->br = ft_stof(str);
	check_range(elem->br, 0, 1, "light");
	elem->color = parse_color(str);
}

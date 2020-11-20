/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:42:54 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/18 17:52:55 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		init_mlx(t_minilibx *mlx, t_scene *data)
{
	t_camera	*cur_cam;
	int			sizex;
	int			sizey;

	mlx->mlx = mlx_init();
	mlx_get_screen_size(mlx->mlx, &sizex, &sizey);
	if (data->xres > sizex)
		data->xres = sizex;
	if (data->yres > sizey)
		data->yres = sizey;
	mlx->begin = mlx->cam;
	cur_cam = mlx->cam;
	while (cur_cam)
	{
		cur_cam->img = mlx_new_image(mlx->mlx, data->xres, data->yres);
		cur_cam->px_img = (int *)mlx_get_data_addr(cur_cam->img,
			&cur_cam->bits_per_pixel, &cur_cam->size_line, &cur_cam->endian);
		cur_cam->pad = (cur_cam->size_line -
			data->xres * (mlx->cam->bits_per_pixel / 8)) / 4;
		cur_cam = cur_cam->next;
	}
}

void		print_message(int argc)
{
	int		t;

	t = 1;
	if (argc == 2)
	{
		ft_printf("\nScene successfully rendered with %d thread, ", t);
		ft_printf("press ESC at any moment to close the program.\n");
		ft_printf("If the scene has more than 1 camera, ");
		ft_printf("press space to change between them\n\n");
	}
	else
	{
		ft_printf("\nScene successfully saved to BMP\n");
		ft_printf("The file has been saved into the current directory\n\n");
		exit(EXIT_SUCCESS);
	}
}

int			close_program(void *param)
{
	t_minilibx	mlx;
	t_camera	*cur_cam;

	mlx = *(t_minilibx *)param;
	cur_cam = mlx.cam;
	while (cur_cam)
	{
		mlx_destroy_image(mlx.mlx, cur_cam->img);
		cur_cam = cur_cam->next;
	}
	mlx_destroy_window(mlx.mlx, mlx.win);
	exit(EXIT_SUCCESS);
	return (1);
}

int			next_cam(int keycode, t_minilibx *mlx)
{
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode != SP_KEY)
		return (0);
	if (mlx->cam->next)
	{
		mlx->cam = mlx->cam->next;
		mlx_put_image_to_window(
				mlx->mlx, mlx->win, mlx->cam->img, 0, 0);
	}
	else
	{
		mlx->cam = mlx->begin;
		mlx_put_image_to_window(
				mlx->mlx, mlx->win, mlx->cam->img, 0, 0);
	}
	return (1);
}

void		graphic_loop(t_minilibx mlx, t_scene data)
{
	mlx.win = mlx_new_window(mlx.mlx, data.xres, data.yres, "miniRT");
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.cam->img, 0, 0);
	mlx_hook(mlx.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK,
			close_program, (void *)&mlx);
	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, next_cam, &mlx);
	mlx_loop(mlx.mlx);
}

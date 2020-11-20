/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:34:11 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/17 17:33:37 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mlx.h for MinilibX in
**
** Made by Charlie Root
** Login   <ol@42.fr>
**
** Started on  Mon Jul 31 16:37:50 2000 Charlie Root
** Last update Tue Oct 14 16:23:28 2019 Olivier Crouzet
*/

/*
**   MinilibX -  Please report bugs
*/

/*
** This library is a simple framework to help 42 students
** create simple graphical apps.
** It only provides the minimum functions, it's students' job
** to create the missing pieces for their own project :)
**
** The MinilibX can load XPM and PNG images.
** Please note that both image loaders are incomplete, some
** image may not load.
**
** For historical reasons, the alpha byte represent transparency
** instead of opacity.
** Also, for compatibility reasons, prototypes may show inconsistant
** types.
**
** Only the dynamic library is available. It must be placed
** in an appropriate path.
** ./ is one of them. You can also use DYLD_LIBRARY_PATH
*/

#ifndef MLX_H

# define MLX_H

void			*mlx_init();

void			*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
					char *title);

int				mlx_clear_window(void *mlx_ptr, void *win_ptr);
int				mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y,
					int color);

void			*mlx_new_image(void *mlx_ptr, int width, int height);

char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
					int *size_line, int *endian);

int				mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
					void *img_ptr, int x, int y);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);

int				mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(),
					void *param);
int				mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_expose_hook (void *win_ptr, int (*funct_ptr)(),
					void *param);

int				mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int				mlx_loop (void *mlx_ptr);

int				mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y,
					int color, char *string);
void			*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
					int *width, int *height);
void			*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
					int *width, int *height);
void			*mlx_png_file_to_image(void *mlx_ptr, char *file, int *width,
					int *height);
int				mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int				mlx_destroy_image(void *mlx_ptr, void *img_ptr);

int				mlx_hook(void *win_ptr, int x_event, int x_mask,
					int (*funct)(), void *param);

int				mlx_mouse_hide();
int				mlx_mouse_show();
int				mlx_mouse_move(void *win_ptr, int x, int y);
int				mlx_mouse_get_pos(void *win_ptr, int *x, int *y);

int				mlx_do_key_autorepeatoff(void *mlx_ptr);
int				mlx_do_key_autorepeaton(void *mlx_ptr);
int				mlx_do_sync(void *mlx_ptr);

# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3

int				mlx_sync(int cmd, void *param);
int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

#endif

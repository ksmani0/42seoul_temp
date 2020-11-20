/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:44:13 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/18 18:16:04 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "ft_printf.h"
# include "libft.h"
# include "libvector.h"
# include "figures.h"
# include "mlx.h"
# include "mlx_keycode.h"
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

# define BUFSIZE 64
# define SP 0
# define PL 1
# define SQ 2
# define TR 3
# define CY 4

# define EPSILON 0.0000001

typedef struct			s_ray
{
	t_point3			o;
	t_vector			d;
}						t_ray;

typedef struct			s_camera
{
	int					init;
	int					idx;
	t_vector			o;
	t_vector			nv;
	int					fov;
	void				*img;
	int					*px_img;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					pad;
	struct s_camera		*next;
}						t_camera;

typedef struct			s_minilibx
{
	void				*mlx;
	void				*win;
	t_camera			*cam;
	t_camera			*begin;
}						t_minilibx;

typedef	struct			s_light
{
	t_point3			o;
	double				br;
	int					color;
	struct s_light		*next;
}						t_light;

typedef	struct			s_scene
{
	int					res_init;
	int					xres;
	int					yres;
	int					cam_nb;
	t_light				*l;
	int					al_init;
	double				ambient_light;
	int					al_color;
	int					bgr;
}						t_scene;

typedef	struct			s_figures
{
	int					flag;
	union u_figures		fig;
	int					color;
	int					texture;
	t_vector			normal;
	struct s_figures	*next;
}						t_figures;

typedef struct			s_wrapper
{
	t_minilibx			mlx;
	t_scene				data;
	t_figures			*lst;
	int					tid;
	int					i;
	int					j;
}						t_wrapper;

typedef	struct			s_rendered
{
	int					limit;
	int					xres;
	int					yres;
	int					i;
	int					j;
}						t_rendered;

typedef	struct			s_inter
{
	int					color;
	t_vector			normal;
	t_point3			p;
}						t_inter;

typedef struct			s_sq
{
	t_vector			u;
	t_vector			v;
	t_vector			c_to_ip;
}						t_sq;

typedef struct			s_bmp_header
{
	char				type[2];
	unsigned int		size;
	unsigned int		reserved;
	unsigned int		offset;
}						t_bmp_header;

typedef struct			s_dib_header
{
	unsigned int		size;
	int					width;
	int					height;
	unsigned short		colplanes;
	unsigned short		bpp;
	unsigned int		compression;
	unsigned int		img_size;
	int					x_ppm;
	int					y_ppm;
	unsigned int		color_number;
	unsigned int		important_color;
}						t_dib_header;

void					parse_res(t_scene *data, char **str);
void					parse_ambient_lightning(t_scene *data, char **str);
void					parse_camera(t_minilibx *mlx, t_scene *data,
							char **str);
void					parse_light(t_scene *data, char **str);
void					parse_sphere(t_figures **lst, char **str);
void					parse_plane(t_figures **lst, char **str);
void					parse_square(t_figures **lst, char **str);
void					parse_triangle(t_figures **lst, char **str);
void					parse_cylinder(t_figures **lst, char **str);
void					parse_scene(t_minilibx *mlx, t_scene *data,
							t_figures **lst, char **argv);
void					usage(char *prog_name);
void					fatal_error(char *message);
void					scene_error(char *message);

void					check_range(double n, double min, double max,
							char *function);
char					*readfile(char *str, int fd);
void					skip_space(char **str);
int						ft_stoi(char **str);
double					ft_stof(char **str);
int						parse_color(char **str);
t_point3				parse_point3(char **str);
void					ft_figure_add_back(t_figures **lst, t_figures *new);

t_vector				reflect_ray(t_vector ray, t_vector normal);
t_vector				calc_normal(t_point3 p, t_vector d, t_figures *l);
double					sphere_intersection(t_point3 o, t_point3 d,
							t_figures *lst);
double					cylinder_intersection(t_point3 o, t_vector d,
							t_figures *lst);
double					triangle_intersection(t_point3 o, t_vector d,
							t_figures *lst);
double					square_intersection(t_point3 o, t_vector d,
							t_figures *lst);
double					plane_intersection(t_point3 o, t_vector d,
							t_figures *lst);
double					plane_root(t_point3 o, t_vector d, t_point3 pl_p,
							t_vector pl_nv);
void					all_intersections(t_ray r, t_figures *lst,
							t_figures *closest_fig, double *closest_inter);
void					compute_light(t_inter *inter, t_scene data,
							t_figures *lst);
int						color_add(int color1, int color2);
int						color_product(int color, double coef);
int						color_difference(int color1, int color2);
int						color_x_light(int color, double l_rgb[3]);
int						calc_ray(int n, t_rendered rd, t_wrapper *w);
int						trace_ray(t_point3 o, t_vector d, t_wrapper *w);
void					wrap_data(t_minilibx mlx, t_scene data, t_figures *lst,
							t_wrapper *wrapper);
void					multithread_render(t_wrapper *wrapper);
void					init_mlx(t_minilibx *mlx, t_scene *data);
void					print_message(int argc);
void					graphic_loop(t_minilibx mlx, t_scene data);
int						is_hit(t_point3 o, t_vector d, t_figures *lst);
void					render_scene(t_wrapper *w);
void					save_bmp(t_minilibx mlx, t_scene data, char *name);
void					*render_thread(void *wrapper);
void					rotation(t_vector *v, t_vector angle);
void					rotate_cylinder(t_figures *lst, t_vector angle);
void					rotate_plane(t_figures *lst, t_vector angle);
void					rotate_square(t_figures *lst, t_vector angle);
void					rotate_camera(t_camera *cam, t_vector angle);
void					trans_sphere(t_figures *lst, t_vector t);
void					trans_triangle(t_figures *lst, t_vector t);
void					trans_square(t_figures *lst, t_vector t);
void					trans_cylinder(t_figures *lst, t_vector t);
void					trans_plane(t_figures *lst, t_vector t);

#endif

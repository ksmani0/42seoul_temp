#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <float.h>
# include <errno.h>
# include "geometry.h"
# include "event.h"
# include "library/libft/libft.h"//ing
# include "library/gnl/get_next_line.h"//ing

# define R_SIZE 64

typedef union		u_dble
{
	double			value;
	struct
	{
		size_t		m : 52;
		size_t		e : 11;
		size_t		s : 1;
	}				s_int;
}					t_dble;

/*
**size:54 + 4 * x * y | reserved_1 ~_2:0 | offset:54
*/
typedef struct		s_bmp_fh
{
	t_uchar			type_1;//'B'
	t_uchar			type_2;//'M'
	t_uint			size;
	t_usint			reserved_1;
	t_usint			reserved_2;
	t_uint			offset;
}					t_bmp_fh;

/*
**size:40 | y:image is reversed when negative | plane:1
**bit_cnt:bit per pixel, 32 | compr:compression, 0
**img_size:4 * x * y | meter_x:x | meter_y:y
**clr_used:color used, 0xffffff | clr_imprt:0
*/
typedef struct		s_bmp_ih
{
	t_uint			size;
	int				x;
	int				y;
	t_usint			plane;
	t_usint			bit_cnt;
	t_uint			compr;
	t_uint			img_size;
	t_uint			meter_x;
	t_uint			meter_y;
	t_uint			clr_used;
	t_uint			clr_imprt;
}					t_bmp_ih;

typedef struct		s_bmp_h
{
	t_bmp_fh		file;
	t_bmp_ih		info;
}					t_bmp_h;

/*
**p:intersection point
*/
typedef struct		s_obj_clr
{
	t_vec3			p;
	t_vec3			center;
	t_vec3			normal;
	t_vec3			light;
	t_vec3			ray;
	t_rgb			rgb;
	//t_bonus		bonus;
}					t_obj_clr;

/*
**addr:해상도 크기만한 이미지 정보(버퍼로 봐도 될 듯) 주소 받음. 여기에 색상 입힘 
**id:image address | b_pix:bit_pixel | alias:aliasing
*/
typedef struct		s_image
{
	void			*i_adr;
	int				*addr;
	char			*alias;
	int				len;
	int				b_pix;
	int				end;
}					t_image;

/*
**MAIN OPTION INDEX:
**0:save | 1:help | 2:sepia filter | 3:antialiasing 
**4:no-specular | 5:reference-axis
*
**idx:scene index == idx_rec(records)
**0:scene resolution | 1:ambient | 2:camera | 3:light
**4:sphere | 5:plane | 6:square
**7:cylinder | 8:triangle
*
**opt:scene option index
**0:LIGHT | 1:parallel light -parallel ok!
**2:PLANE | 3:TRIANGLE | 4:SQUARE
**5:bonus:1 = normal disruption - normal-disruption
**6:bonus:2 = checkered pattern -checkered
**7:bonus:3 = bumpmap texture -bumpmap
**8:bonus:4 = plane texture - skybox:textures/skybox.png
**9:SPHERE
**10:bonus:5 = color disruption -rainbow
**11:bonus:6 = sphere texture - uv-map:texture/earth.png
**12:CYLINDER
**13:bonus:5 = color disruption -rainbow
*/
typedef struct		s_scene
{
	char			idx[9];
	char			idx_rec[9];
	//int				opt[14];
	int				x;//해상도 x
	int				y;//해상도 y
	short			n_cams;
	short			i_cam;
	short			i_light;
	t_axis			axis;
	t_window		win;
	t_image			img;
	t_ambient		ambient;
	t_camera		**camera;
	t_light			**light;
	t_sphere		**sphere;
	t_plane			**plane;
	t_square		**square;
	t_cylinder		**cylinder;
	t_triangle		**triangle;
} t_scene;

/***src - mian.c***/
void				free_each_obj(t_scene *s, int i);
void				free_scene(t_scene *s);
void				check_error_exit(t_scene *scene, int error);
void				guide_output(t_scene *scene);
int					main(int ac, char **av);//ing

/***src - parse_scene.c***/
int					count_scene_obj(t_scene *scene, char *line);
void				malloc_scene_obj(t_scene *s);
void				fill_each_obj(t_scene *scene, char **line);
void				fill_scene(char *file, t_scene *scene);
void				read_rt(char *file, t_scene *scene);

/***src - parse_scene2.c***/
void				free_parsing_buf(char **buf, char **line);
void				parse_resolution(t_scene *scene, char **line);
void				parse_ambient(t_scene *s, char **line);
void				parse_camera(t_scene *s, char **line);
void				parse_light(t_scene *s, char **line);

/***src - parse_scene3.c***/
void				parse_sphere(t_scene *s, char **line);
void				parse_plane(t_scene *s, char **line);
void				parse_square(t_scene *s, char **line);
void				parse_cylinder(t_scene *s, char **line);
void				parse_triangle(t_scene *s, char **line);

/***src - coord_n_rgb.c***/
t_vec3				parse_coord(t_scene *s, char *buf, char **line);
t_rgb				parse_rgb(t_scene *s, char *buf, char **line);
void				get_triangle_edges(t_triangle *t);//ing
void				resize_resolution(t_scene *s);//ing

/***src - light_n_shadow.c***/
int					between_light_n_obj(t_vec3 light, t_vec3 point, t_vec3 origin);
int					is_obj_shaded(t_scene s, t_ray *r);//ing
void				obj_disruption_for_shading(t_light *l, t_obj_clr *obj);
t_vec3				parse_parallel(char *s, t_scene *scene, char **line);
int					check_parallel(char *s);

/***src - bmp.c***/
void				write_bmp_header(t_scene *s, int fd);
void				write_bmp_image(t_scene *s, int fd);
void				save_bmp(t_scene *s, int fd);

/***src - render.c***/
void			    draw_obj_on_canvas(t_scene s, t_ray *r);//ing
void				render_pixel(t_scene *s, t_ray *r, double x, double y);
t_vec3				render_scene(t_scene *s);//ing

/***src - camera.c***/
t_vec3				get_local_camera_coord(t_scene *s, double pix_x, double pix_y);
void				make_camera_to_world_matrix(t_scene *s);

/***src - color.c***/
t_rgb				get_mix_color(t_rgb c0, t_rgb c1);
t_rgb				get_spot_light(t_scene *s, t_obj_clr *obj, int i);
t_rgb				get_ambient_color(t_scene *s, t_obj_clr *obj);
int					obj_color_to_canvas(t_scene s, t_obj_clr obj);

/***src - shpere.c***/
int					is_ray_intersect_sphere(t_scene *s, t_ray *r, int i);
int					is_shadow_in_sphere(t_scene s, t_ray *r, int i);
void				draw_sphere_on_canvas(t_scene s, t_ray *r, int i);

/***src - plane.c***/
void				draw_plane_on_canvas(t_scene s, t_ray *r, int i);
int					get_intersection_of_plane(t_scene *s, t_ray *r, t_sub_plane *pl);
int					is_shadow_in_plane(t_scene s, t_ray *r, int i);
int					is_ray_intersect_plane(t_scene *s, t_ray *r, t_sub_plane *pl);

/***src - square.c***/
int					is_intersect_inside_square(t_scene s, t_sub_plane *pl, int i);
int					is_shadow_in_square(t_scene s, t_ray *r, int i);
void				draw_square_on_canvas(t_scene s, t_ray *r, int i);

/***src - triangle.c***/
double				get_p_parameter(t_triangle *trngl, t_vec3 p0, int i);
double				get_q_parameter(t_triangle *trngl, t_vec3 p0, int i);
int					is_intersect_inside_triangle(t_scene s, int i, t_sub_plane *pl);
int					is_ray_intersect_triagle(t_scene *s, t_ray *r, int i, t_sub_plane *pl);
int					is_shadow_in_triangle(t_scene s, t_ray *r, int i);
void				draw_triangle_on_canvas(t_scene s, t_ray *r, int i);

/***src - cylinder.c***/
void				get_cylinder_surface(t_scene *s, t_ray *r, int i);
int					is_ray_intersect_cylinder(t_scene *s, t_ray *r, int i);
void				get_cylinder_color(t_scene s, t_ray *r, int i);
void				draw_cylinder_on_canvas(t_scene s, t_ray *r, int i);

/***src - cylinder2.c***/
int					is_shadow_in_cap(t_scene s, t_ray *shad_r, int i);
int					is_shadow_in_cylinder(t_scene s, t_ray *shad_r, int i);
t_vec3				get_nearest_cap(t_scene s, int i);
int					is_ray_intersect_cap(t_scene *s, t_ray *r, int i, t_sub_plane *pl);
void				draw_cylinder_cap(t_scene s, t_ray *r, int i);


#endif
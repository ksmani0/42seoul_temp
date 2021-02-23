#ifndef GEOMETRY_H
# define GEOMETRY_H

typedef struct s_vec3
{
	double x;
	double y;
	double z;
} t_vec3;

typedef struct	s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

/*
**mlx_p:mlx_ptr | win_p:win_ptr
*/
typedef struct	s_window
{
	void		*mlx_p;//mlx instance address
	void		*win_p;
	int			key;
}				t_window;

/*
**inten:intensity
*/
typedef struct	s_ambient
{
	double		inten;
	t_rgb		rgb;
}				t_ambient;

typedef struct	s_matrix
{
	t_vec3	vx;
	t_vec3	vy;
	t_vec3	vz;
}				t_matrix;

/*
**pos:position | n:normal
**base:camera to world matrix
*/
typedef struct	s_camera
{
	t_vec3		pos;
	t_vec3		n;
	t_matrix	base;
	double		fov;
}				t_camera;

/*
**p_shad:pos_shadow | inten:intensity
*/
typedef struct	s_light
{
	t_vec3	pos;
	t_vec3	p_shad;
	double	inten;
	t_rgb	rgb;
	t_vec3	parallel;
}				t_light;

/*
**p_x:pixel_x | p_y:pixel_y
*/
typedef struct	s_ray {
	int			p_x;
	int			p_y;
	t_vec3		local;
	t_vec3		global;
	t_vec3		origin;
	int			color;
	double		t;
}				t_ray;

typedef struct	s_axis {
	t_vec3	x;
	t_vec3	y;
	t_vec3	z;
}				t_axis;

typedef struct	s_axis_ref {
	int			x;
	int			y;
	int			l_x;
	int			l_y;
	int			px;
	int			py;
	int			color;
}				t_ax_ref;

/*
**p_oc:Intersection of ray and sphere
**oc:vector that sphere center minus origin
*/
typedef struct	s_sphere
{
	t_vec3	center;
	double	radius;
	t_rgb	rgb;
	double	p_oc;
	double	d;
	t_vec3	p;
	t_vec3	oc;
	t_vec3	n;
	//t_bonus		bonus;
}				t_sphere;

typedef struct	s_plane {
	t_vec3	point;
	t_vec3	n;
	t_rgb	rgb;
	//t_bonus		bonus;
}				t_plane;

typedef struct	s_sub_palne
{
	t_vec3	point;
	t_vec3	n;
	double	den;//평면 방향 벡터와 픽셀마다 관통(P')하는 광선 방향을 내적해 얻는 분모
	double	num;
	t_vec3	l;
	t_vec3	p;
	t_vec3	po;//광원 좌표에서 평면 좌표 빼서 방향 벡터 po
}				t_sub_plane;


typedef struct	s_square
{
	t_vec3	center;
	t_vec3	n;
	double	side;
	t_rgb	rgb;
	t_vec3	dx;
	t_vec3	dy;
	//t_bonus		bonus;
}				t_square;

/*
**delta:in other words discriminant
*/
typedef struct	s_cylinder
{
	t_vec3	point;
	t_vec3	n;
	t_rgb	rgb;
	double	radius;
	double	height;
	double	a;
	double	b;
	double	c;
	double	x1;
	double	x2;
	double	m;
	double	delta;
	t_vec3	oc;
	t_vec3	p;
	t_vec3	center;
	t_vec3	n_surface;
	//t_bonus	bonus;
}				t_cylinder;

/*
**det:determinant | equa:equation | e0:b-a
**e1:c-a | e2: a-c | p0:ray intersection
*/
typedef struct	s_triangle {
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;
	t_rgb	rgb;
	double	det;
	char	equa;
	t_vec3	e0;
	t_vec3	e1;
	t_vec3	e2;
	t_vec3	p0;
	//t_bonus	bonus;
}				t_triangle;

/***src - vec3_utils.c***/
t_vec3				vec3_add_vec3(t_vec3 v0, t_vec3 v1);
t_vec3				vec3_subtraction(t_vec3 v0, t_vec3 v1);
t_vec3				vec3_multiply_vec3(t_vec3 v0, t_vec3 v1);
t_vec3				scalar_multiply_vec3(double k, t_vec3 v);
double				vec3_dot_product(t_vec3 v0, t_vec3 v1);

/***src - vec3_utils2.c***/
double				vec3_self_dot_sqrt(t_vec3 v);
t_vec3				vec3_cross_product(t_vec3 v0, t_vec3 v1);
void				normalize_vec3(t_vec3 *v);
t_vec3				matrix_multiply_vec3(t_vec3 r, t_matrix m);
int					is_vec3_void(t_vec3 v);

/***src - vec3_utils3.c***/
int					is_n_valid(t_vec3 v3);
t_vec3				get_axis(char c);
t_vec3				get_horizon_axis(t_scene *s);

#endif

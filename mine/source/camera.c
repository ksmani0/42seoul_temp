#include "minirt.h"

/*
**To calculate the location of a point at the center of a pixel in raster space,
**you need to convert this pixel coordinate to world coordinates.
**The ray origin and direction must also be in the same space to calculate
**the ray intersection with the object (expressed in world coordinates).
**So we need to find the relationship between the pixel coordinates in
**raster space and the coordinates that are the same as this pixel
**but expressed in world space.
**The process is raster space(x,y)->NDC(0~1)->screen space(-1~1)->world space
**(camera-to-world transformation 4*4 matrix applied) transformation.
*/
t_vec3    get_local_camera_coord(t_scene *s, double pix_x, double pix_y)
{
	t_vec3 local;
	double s_x;
	double s_y;

	s_x = (double)s->x;
	s_y = (double)s->y;
	local.x = (2 * ((pix_x + 0.5) / s_x) - 1) * (s_x / s_y) *
			s->camera[s->i_cam]->fov;
	local.y = (1 - 2 * ((pix_y + 0.5) / s_y)) *
			s->camera[s->i_cam]->fov;
	local.z = -1;
	return (local);
}

/*
**The ray origin(camera origin, O) and ray direction vector(normalized)
**can be used to calculate the ray for this pixel (P).
**If it is the camera position and is set to the world origin (0,0,0),
**P-O in this state to find the ray direction OP.
**If the camera is at different positions, multiply P and O by
**the camera-to-world space transformation matrix to get P', O',
**and P'-O' to get the ray direction O'P'.
**P', O', O'P' are expressed in all world spaces.
**Another way is to compute the ray direction while
**the camera is in its default position (vector OP) and
**apply the camera-world matrix to this vector (I'm this way)
*/
void    make_camera_to_world_matrix(t_scene *s)
{
	t_matrix c_to_w;

	c_to_w.vx = get_horizon_axis(s);
	c_to_w.vy = vec3_cross_product(c_to_w.vx, s->camera[s->i_cam]->n);
	c_to_w.vz = scalar_multiply_vec3(-1, s->camera[s->i_cam]->n);
	normalize_vec3(&c_to_w.vx);
	normalize_vec3(&c_to_w.vy);
	normalize_vec3(&c_to_w.vz);
	s->camera[s->i_cam]->base = c_to_w;
}

void    apply_rgb_filter(char c, t_rgb *color)
{
	if (c == 'r')
	{
		color->g = 0;
		color->b = 0;
	}
	else if (c == 'g')
	{
		color->r = 0;
		color->b = 0;
	}
	else if (c == 'b')
	{
		color->r = 0;
		color->g = 0;
	}
}

void    apply_rainbow_pattern(t_obj_clr *obj)
{
	obj->rgb.r = ft_double_abs(obj->normal.x) * 255;
	obj->rgb.g = ft_double_abs(obj->normal.y) * 255;
	obj->rgb.b = ft_double_abs(obj->normal.z) * 255;
	obj->rgb.r = obj->rgb.r > 255 ? 255 : obj->rgb.r;
	obj->rgb.g = obj->rgb.g > 255 ? 255 : obj->rgb.g;
	obj->rgb.b = obj->rgb.b > 255 ? 255 : obj->rgb.b;
}

void    apply_checkerboard(t_obj_clr *obj)
{
	int		colored;
	int		white;
	int		result;
	t_vec3	tmp;

	colored = ((int)obj->rgb.r << 16) + ((int)obj->rgb.g << 8) +
				(int)obj->rgb.b;
	white = 0x00ffffff;
	tmp.x = abs((int)floor(obj->p.x)) % 2;
	tmp.y = abs((int)floor(obj->p.y)) % 2;
	tmp.z = abs((int)floor(obj->p.z)) % 2;
	result = ((int)tmp.x ^ (int)tmp.y) ^ (int)tmp.z;
	if (result == 0)
	{
		obj->rgb.r = 255;
		obj->rgb.g = 255;
		obj->rgb.b = 255;
	}
}
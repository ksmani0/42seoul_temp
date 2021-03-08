#include "minirt.h"

/*
**Reducing Computational Expense of Ray-Tracing Using Surface Oriented
**Pre-Computation(1991)
**r has P, P'(normalized), camera-world matrix
*/
int		is_ray_intersect_plane(t_scene *s, t_ray *r, t_sub_plane *pl)
{
	if ((is_vec3_void(r->origin)) != 0)
		pl->po = vec3_subtraction(r->origin, pl->point);
	else
		pl->po = vec3_subtraction(s->camera[s->i_cam]->pos, pl->point);
	pl->den = vec3_dot_product(pl->n, r->global);
	if (pl->den != 0)
	{
		pl->num = vec3_dot_product(pl->n, pl->po);
		if (pl->den * pl->num < 0)
			return (1);
	}
	return (0);
}

/*
**r->global is the normalization of converting canvas coordinate P
**to world coordinate P'
*/
int		get_intersection_of_plane(t_scene *s, t_ray *r, t_sub_plane *pl)
{
	double t;

	t = pl->num / pl->den * -1;
	if (t > r->t && is_vec3_void(r->origin) == 0)
		return (0);
	r->t = t + FLT_EPSILON;
	if (is_vec3_void(r->origin) != 0)
		pl->p = vec3_add_vec3(r->origin,
			scalar_multiply_vec3(r->t, r->global));
	else
		pl->p = vec3_add_vec3(s->camera[s->i_cam]->pos,
			scalar_multiply_vec3(r->t, r->global));
	return (1);
}

int		is_shadow_in_plane(t_scene s, t_ray *r, int i)
{
	t_sub_plane sub_pl;

	sub_pl.point = s.plane[i]->point;
	sub_pl.n = s.plane[i]->n;
	if ((is_ray_intersect_plane(&s, r, &sub_pl)) == 0)
		return (0);
	if ((get_intersection_of_plane(&s, r, &sub_pl)) == 0)
		return (0);
	if ((between_light_n_obj(s.light[s.i_light]->pos, sub_pl.p,
		r->origin)) == 0)
		return (0);
	return (1);
}

void	draw_plane_on_canvas(t_scene s, t_ray *r, int i)
{
	t_sub_plane	sub_pl;
	t_obj_clr	obj;

	g_now_obj = s.plane[i]->effect == 'k' ? 'p' : 0;
	sub_pl.point = s.plane[i]->point;
	sub_pl.n = s.plane[i]->n;
	if ((is_ray_intersect_plane(&s, r, &sub_pl)) == 0)
		return ;
	if ((get_intersection_of_plane(&s, r, &sub_pl)) == 0)
		return ;
	if (sub_pl.den > 0)
		sub_pl.n = scalar_multiply_vec3(-1, sub_pl.n);
	obj.p = sub_pl.p;
	obj.center = sub_pl.point;
	obj.normal = sub_pl.n;
	obj.rgb = s.plane[i]->rgb;
	r->color = obj_color_to_canvas(s, obj);
}

#include "minirt.h"

int     is_intersect_inside_square(t_scene s, t_sub_plane *pl, int i)
{
    t_square    *tmp;
    double      x;
    double      y;

    tmp = s.square[i];
    tmp->dx = get_axis('x');//교차점이 x축에서 떨어진 거리
    tmp->dy = vec3_cross_product(pl->n, tmp->dx);//교차점이 y축에서 떨어진 거리. 외적으로 y축 벡터 방향 확보
    if ((is_vec3_void(tmp->dy)) == 0)//y축 방향 벡터가 0,0,0이면 다시 설정
    {
        tmp->dx = get_axis('y');
        tmp->dy = vec3_cross_product(pl->n, tmp->dx);
    }
    normalize_vec3(&tmp->dx);
    normalize_vec3(&tmp->dy);
    x = vec3_dot_product(tmp->dx, vec3_subtraction(pl->p, tmp->center));//교차점 P에서 상자 중심 빼서 CP 벡터 확보한 후
    y = vec3_dot_product(tmp->dy, vec3_subtraction(pl->p, tmp->center));
    if ((ft_double_abs(x)) > tmp->side || (ft_double_abs(y)) > tmp->side)
        return (0);//교차점이 축에서 떨어진 거리가 상자 너비보다 크면 상자 밖에 있는 것
    return (1);
}

int     is_shadow_in_square(t_scene s, t_ray *r, int i)
{
    t_sub_plane sub_pl;

	sub_pl.point = s.square[i]->center;
	sub_pl.n = s.square[i]->n;
	if ((is_ray_intersect_plane(&s, r, &sub_pl)) == 0)
		return (0);
	if ((get_intersection_of_plane(&s, r, &sub_pl)) == 0)
		return (0);
    if ((is_intersect_inside_square(s, r, &sub_pl)) == 0)
		return (0);//교차점이 상자 안인지 밖인지 검사
	if ((between_light_n_obj(s.light[s.i_light]->pos, sub_pl.p,
		r->origin)) == 0)//음영 처리할 지점이 있는지 없는지 검사. 광원과 물체 사이에 방향 벡터 있는지 검사
		return (0);
	return (1);
}

void    draw_square_on_canvas(t_scene s, t_ray *r, int i)
{
    double      last_t;
    t_sub_plane sub_pl;
    t_obj_clr   obj;

    last_t = r->t;
    sub_pl.point = s.square[i]->center;
	sub_pl.n = s.plane[i]->n;
    if ((is_ray_intersect_plane(&s, r, &sub_pl)) == 0)//교차하는지 확인. 현재 P, P'(정규화), 카메라-세계 행렬 있음
        return ;
	if ((get_intersection_of_plane(&s, r, &sub_pl)) == 0)//상자 교차점 앞에 다른 도형 있으면 처리 안 해도 되니 검사해야 함
		return ;
	if ((is_intersect_inside_square(s, &sub_pl, i)) == 0)//교차점이 상자 안에 있는지 검사
		return ;
    if (sub_pl.den > 0)
        sub_pl.n = scalar_multiply_vec3(-1, sub_pl.n);
    obj.p = sub_pl.p;//교차점 전달
    obj.normal = sub_pl.n;
    obj.rgb = s.square[i]->rgb;
    r->color = obj_color_to_canvas(s, obj);
    r->t = last_t;
}

#include "minirt.h"

/*
Reducing Computational Expense of Ray-Tracing Using Surface Oriented Pre-Computation(1991) 논문 참고
*/

int		is_ray_intersect_plane(t_scene *s, t_ray *r, t_sub_plane *pl)
{//r에 P, P'(정규화), 카메라-세계 행렬 있음
	if ((is_vec3_void(r->origin)) != 0)//0, 0, 0
		pl->po = vec3_subtraction(r->origin, pl->point);//광원 좌표에서 평면 좌표 빼서 방향 벡터 po 확보
	else
		pl->po = vec3_subtraction(s->camera[s->i_cam]->pos, pl->point);//카메라 좌표에서 평면 좌표 빼서 po 확보
	pl->den = vec3_dot_product(pl->n, r->global);//평면 방향 벡터와 픽셀마다 관통(P')하는 광선 방향을 내적해 denominator 확보
	if (pl->den != 0)
	{
		pl->num = vec3_dot_product(pl->n, pl->po);//평면의 인덱스 번호 얻음
		if (pl->den * pl->num < 0)//나누기로 해도 되지만 나누기 연산이 더 성능에 안 좋아서 곱셈으로 대체
			return (1);//음수 나오면 광선 뒤에 있는 것
	}
	return (0);//입사각이 0(법선과 광선이 평행)이거나 두 값의 곱셈 결과가 0 이상이면 교차점 없음
}

int		get_intersection_of_plane(t_scene *s, t_ray *r, t_sub_plane *pl)
{//r->global은 캔버스 좌표 P를 세계 좌표 P'로 바꾼 것을 정규화한 것
	double t;

	t = pl->num / pl->den * -1;//교차점까지의 거리 계산
	if (t > r->t && is_vec3_void(r->origin) == 0)
		return (0);//이미 앞에 처리할 도형이 있음
	r->t = t;//굳이 + FLT_EPSILON을 해줘야 할까
	if (is_vec3_void(r->origin) != 0)//0, 0, 0이 아니라면
		pl->p = vec3_add_vec3(r->origin,
			scalar_multiply_vec3(r->t, r->global));//세계 원점에, P'에서 t만큼 움직인 지점 더해 교차점 P 찾음
	else
		pl->p = vec3_add_vec3(s->camera[s->i_cam]->pos,
			scalar_multiply_vec3(r->t, r->global));//카메라 위치와, t와 세계 좌표 P'를 곱한 걸 더해 교차점 P 찾음
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
		r->origin)) == 0)//음영 처리할 지점이 있는지 없는지 검사. 광원과 물체 사이에 방향 벡터 있는지 검사
		return (0);
	return (1);
}

void    draw_plane_on_canvas(t_scene s, t_ray *r, int i)
{
    t_sub_plane sub_pl;
	t_obj_clr   obj;

    sub_pl.point = s.plane[i]->point;
	sub_pl.n = s.plane[i]->n;
    if ((is_ray_intersect_plane(&s, r, &sub_pl)) == 0)//교차점 있는지 확인. 현재 P, P'(정규화), 카메라-세계 행렬 있음
        return ;
	if ((get_intersection_of_plane(&s, r, &sub_pl)) == 0)
		return ;
	if (sub_pl.den > 0)//분모가 양수면 -1을 곱해 방향 조정
		sub_pl.n = scalar_multiply_vec3(-1, sub_pl.n);
	obj.p = sub_pl.p;//캔버스에 그림 그릴 위치 확보
	obj.center = sub_pl.point;
	obj.normal = sub_pl.n;
	obj.rgb = s.plane[i]->rgb;
	r->color = obj_color_to_canvas(s, obj);
}

#include "minirt.h"

int     is_intersect_inside_triangle(t_scene s, int i, t_sub_plane *pl)
{
    double p;
    double q;//스크래차픽셀의 P를 미러링한 점인 P'라고 보면 됨
    t_vec3 p0;

    p0 = vec3_subtraction(pl->p, s.triangle[i]->a);//교차점에서 정점 빼서 ap 벡터 확보
    p = get_p_parameter(s.triangle[i], p0, i);//@
    q = get_q_parameter(s.triangle[i], p0, i);
    if (p >= 0 && p <= 1 && q >= 0 && q <= 1 && p + q >= 0 && p + q <= 1)
        return (1);//교차점이 삼각형 내부에 있다
    return (0);
}

int     is_ray_intersect_triagle(t_scene *s, t_ray *r, int i,
                                t_sub_plane *pl)
{
    double t;

    t = r->t;
    if ((is_ray_intersect_plane(s, r, pl)) == 0 ||//삼각형의 한 점, 법선으로 평면 따져서 광선과 교차하는지 검사
    (get_intersection_of_plane(s, r, pl)) == 0 ||//pl->p에 교차점 얻어옴
    (is_intersect_inside_triangle(*s, i, pl)) == 0)
    {
        r->t = t;
		return (0);
    }
    if (pl->den > 0)//삼각형이 좌표 그대로 보이도록 법선 방향을 뒤집기
        pl->n = scalar_multiply_vec3(-1, pl->n);
    return (1);
}

int     is_shadow_in_triangle(t_scene s, t_ray *r, int i)
{
    t_sub_plane sub_pl;

    sub_pl.point = s.triangle[i]->a;
    sub_pl.n = vec3_cross_product(s.triangle[i]->e1, s.triangle[i]->e0);
    if ((is_ray_intersect_triagle(&s, r, i, &sub_pl)) == 0)
        return (0);
    if (between_light_n_obj(s.light[s.i_light]->pos, sub_pl.p,
        r->origin) == 0)//음영 처리할 지점이 있는지 없는지 검사. 광원과 물체 사이에 방향 벡터 있는지 검사
        return (0);
    return (1);
}

void    draw_triangle_on_canvas(t_scene s, t_ray *r, int i)
{
    t_sub_plane sub_pl;
    t_obj_clr   obj;

    sub_pl.point = s.triangle[i]->a;//정점 하나를 평면 점으로 대입
    sub_pl.n = vec3_cross_product(s.triangle[i]->e1, s.triangle[i]->e0);
    if ((is_ray_intersect_triagle(&s, r, i, &sub_pl)) == 0)
        return ;//광선과의 교차점이 삼각형 내부인지 아닌지 검사
    obj.p = sub_pl.p;//확보한 삼각형 내부 교차점 전달
    obj.normal = sub_pl.n;
    obj.rgb = s.triangle[i]->rgb;
    r->color = obj_color_to_canvas(s, obj);
}

void	    get_triangle_edges(t_triangle *t)
{
	t->e0 = vec3_subtraction(t->b, t->a);//모서리 확보
	t->e1 = vec3_subtraction(t->c, t->a);
	t->det = t->e0.x * t->e1.y - t->e0.y * t->e1.x;//외적한 벡터, 법선의 방향 구하는 식
	t->equa = 0;//법선 방향 뽑아낸 식 알려주는 변수
	if (!t->det)
	{//방향==0면 광선 방향과 비교(평행, 교차 여부)할 수 없으니 다른 모서리로 검사
		t->det = t->e0.y * t->e1.z - t->e1.y * t->e0.z;
		t->equa = 1;
	}
	if (!t->det)
	{//3개 모서리 점은 같은 평면에 있기 때문에 
		t->det = t->e0.x * t->e1.z - t->e0.z * t->e1.x;
		t->equa = 2;
	}
}

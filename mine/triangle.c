#include "minirt.h"

double  get_p_parameter(t_triangle *trngl, t_vec3 p0, int i)
{//드디어 삼각형 행렬식 뽑아낸 방정식에 따라 교차점 p(삼각형 내외부에 있는지 판단하는 매개변수) 확보
    double p;

    if (trngl->equa == 0)
        p = (trngl->e1.y * p0.x - trngl->e1.x * p0.y) / trngl->det;
    else if (trngl->equa == 1)
        p = (trngl->e1.z * p0.y - trngl->e1.y * p0.z) / trngl->det;
    else
        p = (trngl->e1.z * p0.x - trngl->e1.x * p0.z) / trngl->det;
    return (p);
}

double  get_q_parameter(t_triangle *trngl, t_vec3 p0, int i)
{//삼각형 행렬식(determinant) 뽑아낸 방정식 따라 교차점 q(삼각형 내외부에 있는지 판단하는 매개변수) 확보
    double q;

    if (trngl->equa == 0)
        q = (trngl->e1.x * p0.y - trngl->e1.y * p0.x) / trngl->det;
    else if (trngl->equa == 1)
        q = (trngl->e1.y * p0.z - trngl->e1.z * p0.y) / trngl->det;
    else
        q = (trngl->e1.x * p0.z - trngl->e1.z * p0.x) / trngl->det;
    return (q);
}

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
#include "minirt.h"

int     is_ray_intersect_sphere(t_scene *s, t_ray *r, int i)
{//r에 P, P'(정규화), 카메라-세계 행렬 있음
    t_sphere    *tmp;

    tmp = s->sphere[i];
    if (is_vec3_void(r->origin) != 0)//0,0,0 상태가 아니라면
        tmp->oc = vec3_subtraction(tmp->center, r->origin);//구 중심에서 원점 빼서 벡터 구함
    else//구 중심에서 카메라 좌표 빼서 벡터 구함
    {
        tmp->oc = vec3_subtraction(tmp->center,
        s->camera[s->i_cam]->pos);
    }
    tmp->p_oc = vec3_dot_product(tmp->oc, r->global);//r->global는 픽셀마다 관통하는 광선 방향(세계 좌표, 정규화됨). p_oc == tca
    if (tmp->p_oc < 0)//음수면 tmp->oc와 r->global가 반대 방향 보는 것
        return (0);
    tmp->d = sqrt(vec3_dot_product(tmp->oc, tmp->oc) -
            tmp->p_oc * tmp->p_oc);//구 중심에서 교차점 직선으로 직각 되게 선 그렸을 때 그 선 길이
    if (tmp->d > tmp->radius)//d가 반지름보다 길면 교차 안 함
        return (0);
    return (1);
}

int     is_shadow_in_sphere(t_scene s, t_ray *r, int i)
{//r == shadow
    t_sphere *tmp;

    tmp = s.sphere[i];
    if ((is_ray_intersect_sphere(&s, r, i)) != 0)
    {
        r->t = tmp->p_oc - sqrt(tmp->radius * tmp->radius
            - tmp->d * tmp->d);//tca에서 '반지름 제곱 - d 제곱' 빼면 광원과 교차점까지의 거리 나옴
        tmp->p = vec3_add_vec3(r->origin,
            scalar_multiply_vec3(r->t, r->global));//세계 원점에, t와 세계 좌표 P'를 곱한 걸 더해 음영 처리할 좌표 확보
        if (between_light_n_obj(s.light[s.i_light]->p_shad,
            tmp->p, r->origin) != 0)//음영 처리할 지점이 있는지 없는지 검사. 광원과 물체 사이에 방향 벡터 있는지 검사
            return (1);
    }
    return (0);
}

void    draw_sphere_on_canvas(t_scene s, t_ray *r, int i)
{
    double      t;
    t_obj_clr   obj;
    t_sphere     *tmp;

    if ((is_ray_intersect_sphere(&s, r, i)) == 0)//교차점 있는지 확인. 현재 P, P'(정규화), 카메라-세계 행렬 있음
        return ;
    tmp = s.sphere[i];
    t = sqrt(tmp->radius * tmp->radius - tmp->d * tmp->d);
    if (t > r->t)//현재 구한 t가 r->t보다 크면 뒤에 있다는 말이니 표시 안 해도 됨
        return ;
    r->t = t;
    obj.p = vec3_add_vec3(s.camera[s.i_cam]->pos,
            scalar_multiply_vec3(r->t, r->global));//카메라 위치와, 광선 방향(P', 정규화)에서 t만큼 움직인 지점 더해 그림 그릴 위치 표시
    obj.normal = vec3_subtraction(obj.p, tmp->center);//그림 그릴 위치 P'에서 원 중심 C 빼서 벡터 확보
    obj.rgb = tmp->rgb;//구 색깔 전달
    obj.center = tmp->center;//구 중심 전달
    //obj.bonus = tmp->bonus;
    r->color = obj_color_to_canvas(s, obj);//광선이 관통하는 픽셀 P'의 색깔 구하기
}

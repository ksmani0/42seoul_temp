#include "minirt.h"

/*
래스터 공간의 픽셀 중심에 있는 점 위치를 계산하려면 이 픽셀 좌표를 세계 좌표로 바꿔야 함.
물체(세계 좌표로 표시)와 광선 교차점 계산하려면 광선 원점과 방향도 같은 공간에 있어야 함.
그래서 래스터 공간의 픽셀 좌표와, 이 픽셀과 동일하지만 세계 공간으로 표현된 좌표 관계를 찾아야 함.
그 과정이 래스터 공간(x, y)->NDC(0~1)->스크린 공간(-1~1)->세계 공간(카메라-to-세계 변환 4*4 행렬 적용) 변환임
*/
t_vec3    get_local_camera_coord(t_scene *s, double pix_x, double pix_y)
{//래스터->ndc->스크린(카메라) 좌표로 변환함. 여기서 뽑는 좌표로 카메라가 광선 쏨
    t_vec3 local;
    double s_x;
    double s_y;

    s_x = (double)s->x;
    s_y = (double)s->y;
    local.x = (2 * ((pix_x + 0.5) / s_x) - 1) * (s_x / s_y) *
            s->camera[s->i_cam]->fov;//픽셀 중앙에 쏘기 때문에 0.5 곱하기. 보통 가로가 넓은 이미지가 들어오니 x좌표에 종횡비도 곱하기
    local.y = (1 - 2 * ((pix_y + 0.5) / s_y)) *
            s->camera[s->i_cam]->fov;
    local.z = -1;//항상 카메라는 z축 음수쪽을 본다
    return (local);//이렇게 나온 것이 현재 광선이 중심을 뚫은 픽셀의 스크린에서의 최종 좌표 P
}

/*
광선 원점(카메라의 원점, O)과 광선 방향 벡터(정규화됨)을 이용해 이 픽셀(P)에 대한 광선을 계산 가능.
만약 카메라 위치라 세계 원점(0,0,0)에 맞춰져 있으면 이 상태로 P-O 해서 광선 방향 OP를 구함.
카메라가 다른 위치면 P, O에 카메라 대 세계 공간 변환 행렬을 곱해 P', O'를 구하고 P'-O' 해서 광선 방향 O'P' 구함
P', O', O'P'는 모드 세계 공간에서 표현된 것
또 다른 방법은 카메라가 기본 위치(벡터 OP)에 있는 동안 광선 방향을 계산하고 이 벡터에 카메라-세계 행렬 적용(내가 이 방법)
*/
void    make_camera_to_world_matrix(t_scene *s)
{
    t_matrix c_to_w;//카메라 공간 좌표를 세계 공간 좌표로 바꾸는 행렬. 크기 변환 등을 하지 않으니 3*3

    c_to_w.vx = get_horizon_axis(s);//행렬의 x축 변환 행을 s->cam[s->i_cam]->n에서 가져옴
    c_to_w.vy = vec3_cross_product(c_to_w.vx, s->camera[s->i_cam]->n);//x축 벡터와 카메라의 방향 벡터 외적
    c_to_w.vz = scalar_multiply_vec3(-1, s->camera[s->i_cam]->n);//카메라는 항상 음수 쪽으로 보니까 -1 곱
    normalize_vec3(&c_to_w.vx);//졍규화
    normalize_vec3(&c_to_w.vy);
    normalize_vec3(&c_to_w.vz);
    s->camera[s->i_cam]->base = c_to_w;//카메라 base에 이 행렬 대입
}

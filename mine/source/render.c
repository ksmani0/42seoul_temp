#include "minirt.h"

void	draw_obj_on_canvas(t_scene s, t_ray *r)
{
	int i;

	i = -1;
	while (s.sphere[++i] != 0)
		draw_sphere_on_canvas(s, r, i);
	i = -1;
	while (s.plane[++i] != 0)
		draw_plane_on_canvas(s, r, i);
	i = -1;
	while (s.square[++i] != 0)
		draw_square_on_canvas(s, r, i);
	i = -1;
	while (s.cylinder[++i] != 0)
		draw_cylinder_on_canvas(s, r, i);
	i = -1;
	while (s.triangle[++i] != 0)
		draw_triangle_on_canvas(s, r, i);//도형들 돌면서 y에 그리다 보니 맨 앞에 있는 도형 색만 얻을 수 있음 
}

void	render_pixel(t_scene *s, t_ray *r, double x, double y)
{
	r->local = get_local_camera_coord(s, x, y);//현재 카메라 광선이 중심을 뚫은 픽셀의 스크린에서의 최종 좌표 P@
	r->global = matrix_multiply_vec3(s->camera[s->i_cam]->base, r->local);//캔버스 좌표 P를 카메라-세계 행렬을 곱해 세계 좌표 P'로 바꿈
	r->t = DBL_MAX;//카메라와 물체 사이 거리를 일단 최대로 초기화
	r->color = 0;
	r->origin = (t_vec3){ 0, 0, 0 };//세계 좌표 원점으로 초기화
	normalize_vec3(&r->global);//r->global는 픽셀마다 관통(P')하는 광선 방향
	draw_obj_on_canvas(*s, r);//광선 원점(카메라의 원점, O)과 광선 방향 벡터(정규화됨)을 이용해 이 픽셀에 대한 광선을 계산
}

void	render_scene(t_scene *s)
{
	int		pix_x;
	int		pix_y;
	t_ray	ray;
	char	*data;
	int xxx;

	pix_y = 0;
	make_camera_to_world_matrix(s);//카메라 위치!=0,0,0일 때 P', O' 구할 때 쓸 카메라-세계 공간 변환 행렬을 s->camera[i_cam]->base에 대입
	while (pix_y < s->y)//x, y 순서 바꿈@
	{//왼쪽 위 모서리가 0,0인 래스터 공간의 픽셀을 하나씩 돌면서 카메라 캔버스에 색깔 칠하기
		pix_x = 0;
		while (pix_x < s->x)
		{
			if (pix_x == 338 && pix_y == 30)
				xxx = 0;
			if (s->effect == 'a')
				render_with_antialiasing(s, &ray, (double)pix_x, (double)pix_y);
			else
				render_pixel(s, &ray, (double)pix_x, (double)pix_y);//픽셀 돌아가며 도형들 r->color에 그림
			data = s->img.addr + (pix_y * s->img.len + pix_x * (s->img.b_pix / 8));
			*(t_uint*)data = ray.color;//img에 구한 색상 칠함@
			pix_x++;
		}
		pix_y++;
	}
}

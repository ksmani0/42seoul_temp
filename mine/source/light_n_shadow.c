#include "minirt.h"

int		between_light_n_obj(t_vec3 light, t_vec3 point, t_vec3 origin)
{//light(s.light[s.i_light]->p_shad)는 음영 처리 지점, point(s.sphere[i]->p)는 원 위치, origin(r->origin)은 세계 원점
	t_vec3 shad_ray;
	t_vec3 light_ray;
	double sqrt_global;
	double sqrt_shad;

	shad_ray = vec3_subtraction(point, origin);//도형 위치서 세계 원점 위치 빼서 방향 벡터 구함
	light_ray = vec3_subtraction(light, origin);//음영 처리할 광원 지점에서 세계 원점 위치 빼서 벡터 구함
	sqrt_shad = vec3_self_dot_sqrt(shad_ray);
	sqrt_global = vec3_self_dot_sqrt(light_ray);
	if (sqrt_shad > 0.0001 && sqrt_shad < sqrt_global)//0.0을 쓰면 부산물이 생겨 0.0001을 써야 함
		return (1);
	return (0);
}

int		is_obj_shaded(t_scene s, t_ray *shad_r)
{//r == shadow
	int i;

	i = -1;
	while (s.sphere[++i] != 0)
		if ((is_shadow_in_sphere(s, shad_r, i)) != 0)
			return (1);
	i = -1;
	while (s.plane[++i] != 0)
		if ((is_shadow_in_plane(s, shad_r, i)) != 0)
			return (1);
	i = -1;
	while (s.square[++i] != 0)
		if ((is_shadow_in_square(s, shad_r, i)) != 0)
			return (1);
	i = -1;
	while (s.cylinder[++i] != 0)
		if ((is_shadow_in_cylinder(s, shad_r, i)) != 0)
			return (1);
	i = -1;
	while (s.triangle[++i] != 0)
		if ((is_shadow_in_triangle(s, shad_r, i)) != 0)
			return (1);//도형들 돌면서 음영 처리할 지점 있는지 검사
	return (0);
}

void	obj_disruption_for_shading(t_light *l, t_obj_clr *obj)
{//.rt에 parallel이 있으면 광원 위치는 무시하고 무조건 parallel 방향으로 모든 빛이 평행하게 옴. 모든 s->light가 이 함수 거침
	t_vec3	light_dir;//광원 방향
	t_vec3	lp;

	lp = vec3_subtraction(l->pos, obj->p);//광원 위치에서 캔버스의 그림 그릴 위치 빼서 음영 벡터 방향 구함
	if (s_now_obj == 's' || s_now_obj == 'c')//구나 원통이면 굴곡이 생기니 무지개 효과를 적용할 수 있음
		apply_rainbow_pattern(obj);
	if (s_now_obj == 'p')
		apply_checkerboard(obj);
	if (is_vec3_void(l->parallel) != 0)//parallel != 0,0,0면 parallel 방향 대입
	{
		light_dir = l->parallel;//원래 광원 방향은 무시하고 parallel 방향으로 빛이 향하는 방향 대입
		light_dir = scalar_multiply_vec3(-1, light_dir);//오브젝트 쪽으로 향하도록 변환
		normalize_vec3(&light_dir);//방향 벡터니까 정규화
		l->p_shad = scalar_multiply_vec3(vec3_dot_product(light_dir, lp), light_dir);//음영 처리할 좌표?
	}//광원 벡터를, 광원 방향과 음영 벡터를 내적한 것과 곱했을 때 그게 음영 주는 광원 지점일까? 에서 지점이었다
	else
	{
		light_dir = lp;//광원 좌표-캔버스의 그림 그릴 좌표로 구한 음영 벡터 방향 그대로 대입
		l->p_shad = l->pos;//광원 위치를 음영 주는 광원 지점으로 대입?
		normalize_vec3(&light_dir);
	}
	obj->light = light_dir;//패레럴, 정규화된 광원 방향 벡터
}

t_vec3	parse_parallel(t_scene *s, char **buf, int i, char **line)
{//.rt에 parallel이 있으면 광원 위치는 무시하고 무조건 parallel 방향으로 모든 빛이 평행하게 옴. 모든 s->light가 이 함수 거침
	char	**comma;
	t_vec3	result;
	char	*tmp;

	tmp = buf[i];
	while (*tmp != ':' && *tmp != 0)
		tmp++;
	comma = 0;
	if (*tmp != ':' || !(comma = ft_split(++tmp, ',')))
	{
		free_parsing_buf(buf, line);
		check_error_exit(s, 5);
	}
	result.x = ft_atoi(comma[0]);
	result.y = ft_atoi(comma[1]);
	result.z = ft_atoi(comma[2]);
	i = 0;
	while (comma[i] != 0)
		free(comma[i++]);
	free(comma[i]);
	free(comma);
	normalize_vec3(&result);
	return (result);
}

int		check_parallel(char *s)
{
	if (s == 0 || ft_strncmp(s, "parallel", 8) == 0)
		return (1);
	return (0);
}
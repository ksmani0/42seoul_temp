#include "minirt.h"

t_vec3    parse_coord(t_scene *s, char *buf, char **line)
{
    t_vec3  result;
    char    **com;

    if (!(com = ft_split(buf, ',')))
    {
        free_parsing_buf(buf, line);
		check_error_exit(s, 5);
    }
    result.x = ft_atof(com[0], com[0]);
    result.y = ft_atof(com[1], com[1]);
    result.z = ft_atof(com[2], com[2]);
    free_parsing_buf(buf, line);
    return (result);
}

t_rgb      parse_rgb(t_scene *s, char *buf, char **line)
{
    t_rgb   result;
    char    **comma;

    if (!(comma = ft_split(buf, ',')))
    {
        free_parsing_buf(buf, line);
		check_error_exit(s, 5);
    }
    result.r = ft_atoi(comma[0]);
    result.g = ft_atoi(comma[1]);
    result.b = ft_atoi(comma[2]);
    free_parsing_buf(buf, line);
    return (result);
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

void        resize_resolution(t_scene *s)
{
    int *x;
    int *y;

    mlx_get_screen_size(s->win.mlx_p, x, y);
    if (s->x > x)
        s-> x = x;
    if (s->y > y)
        s->y = y;
}
#include "minirt.h"

int     is_n_valid(t_vec3 v3)
{
    if (v3.x == 0 && v3.y == 0 && (v3.z == 1 || v3.z == -1))
        return (1);
    else if (v3.y == 0 && v3.z == 0 && (v3.x == 1 || v3.x == -1))
        return (1);
    else if (v3.z == 0 && v3.x == 0 && (v3.y == 1 || v3.y == -1))
        return (1);
    return (-1);
}

t_vec3	get_axis(char c)
{
    t_vec3 result;

    result.x = 0;
    result.y = 0;
    result.z = 0;
    if (c == 'x')
        result.x = 1;
    else if (c == 'y')
        result.y = 1;
    else if (c == 'z')
        result.z = 1;
    return (result);
}

t_vec3  get_horizon_axis(t_scene *s)
{
    t_vec3 conversion_x;

    conversion_x.z = 0;
    if (s->camera[s->i_cam]->n.x == 0 && s->camera[s->i_cam]->n.y == 0)
    {//카메라 방향 벡터의 x, y 좌표가 둘 다 0일 때
        conversion_x.y = 0;
        if (s->camera[s->i_cam]->n.z > 0)//z==1면 -(1)로 나눠서 -1
            conversion_x.x = -1;
        else if (s->camera[s->i_cam]->n.z < 0)//z==-1면 -(-1)로 나눠서 1
            conversion_x.x = 1;
        else if (s->camera[s->i_cam]->n.z == 0)//0이면 방향 벡터가 잘못 들어온 것
            check_error_exit(s, 9);
    }
    else
    {
        conversion_x.x = s->camera[s->i_cam]->n.y;
        conversion_x.y = s->camera[s->i_cam]->n.x * -1.0;
    }
    return (conversion_x);
}
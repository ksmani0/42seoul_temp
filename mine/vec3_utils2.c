#include "minirt.h"

double  vec3_self_dot_sqrt(t_vec3 v)
{
    return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3 vec3_cross_product(t_vec3 v0, t_vec3 v1)
{
    t_vec3 result;

    result.x = v0.y * v1.z - v0.z * v1.y;
    result.y = v0.z * v1.x - v0.x * v1.z;
    result.z = v0.x * v1.y - v0.y * v1.x;
    return (result);
}

void    normalize_vec3(t_vec3 *v)
{
    double denominator;

    denominator = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
    v->x = v->x / denominator;
    v->y = v->y / denominator;
    v->z = v->z / denominator;
}

t_vec3  matrix_multiply_vec3(t_vec3 v, t_matrix m)
{
    t_vec3 result;

    result.x = m.vx.x * v.x + m.vx.x * v.y + m.vx.x * v.z;
    result.y = v.x * m.vx.y + v.y * m.vy.y + v.z * m.vz.y;
    result.z = v.x * m.vx.z + v.y * m.vy.z + v.z * m.vz.z;
    return (result);
}

int     is_vec3_void(t_vec3 v)
{
    return (v.x == 0 && v.y == 0 && v.z == 0 ? 0 : 1);
}
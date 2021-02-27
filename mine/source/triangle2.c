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


#include "../include/minirt.h"

t_rgb   get_mix_color(t_rgb c0, t_rgb c1)
{
    t_rgb clr;

    clr.r = c0.r + c1.r > 255 ? 255 : c0.r + c1.r;
    clr.g = c0.g + c1.g > 255 ? 255 : c0.g + c1.g;
    clr.b = c0.b + c1.b > 255 ? 255 : c0.b + c1.b;
    return (clr);
}

/*
주변 조명(ambient), 확산 조명(diffuse), 정반사 조명(specular)으로 색상 처리하는 phong 모델 채택
물체 교차점의 법선 벡터와 광원 벡터간 각도가 작을수록 내적 값이 1에 가까워지면서 교차점 색상이 흰색에 가까워짐. 각도가 크면 어두워짐
주변 조명은 get_ambient_color()에서 확보
확산 조명은 광원 벡터와 교차점 법선 벡터(둘 다 정규화됨)간 내적을 구한 후 색상과 곱함
kd:표면 확산 반사율
*/
t_rgb   get_spot_light(t_scene *s, t_obj_clr *obj, int i)
{
    t_rgb   clr;
    double  diffuse;
    double  specular;
    double  kd;

    diffuse = vec3_dot_product(obj->light, obj->normal);//패레럴, 정규화된 광원 방향 벡터와 정규화된 벡터 CP'를 내적한 게 광선 분사 계수
    kd = diffuse < 0 ? 0 : s->light[i]->inten;//두 벡터간 각도가 90도 이상이면 내적 결과가 음수. 음수 색상 광원은 존재하지 않으니 0으로 설정해야 함
    specular = pow(fmax(diffuse, 0.0), 50);//50은 하이라이트 광택값. 광택값이 크면 빛을 전체적으로 산란해서 spotlight 느낌이 사라짐
    clr.r = kd * s->light[i]->rgb.r * (obj->rgb.r * diffuse / 255 + specular);
    clr.r = kd * s->light[i]->rgb.b * (obj->rgb.g * diffuse / 255 + specular);
    clr.r = kd * s->light[i]->rgb.g * (obj->rgb.b * diffuse / 255 + specular);
    return (clr);
}

t_rgb   get_ambient_color(t_scene *s, t_obj_clr *obj)
{//여기서 ambient 색상 확보. ambient 색상과 채도, 물체 색상과 곱해서 구함
    t_rgb color;

    color.r = s->ambient.inten * s->ambient.rgb.r * obj->rgb.r / 255;
    color.g = s->ambient.inten * s->ambient.rgb.g * obj->rgb.g / 255;
    color.b = s->ambient.inten * s->ambient.rgb.b * obj->rgb.b / 255;
    return (color);
}

t_rgb  apply_sepia_filter(char c, t_rgb color)
{
    t_rgb result;

    result.r = color.r * 0.393 + color.g * 0.769 + color.b * 0.189;
	result.g = color.r * 0.349 + color.g * 0.686 + color.b * 0.168;
	result.b = color.r * 0.272 + color.g * 0.534 + color.b * 0.131;
    result.r = result.r > 255 ? 255 : result.r;
    result.g = result.g > 255 ? 255 : result.g;
    result.b = result.b > 255 ? 255 : result.b;
    return (result);
}

int     obj_color_to_canvas(t_scene s, t_obj_clr obj)
{
    t_rgb color;
    t_rgb sub_color;
    t_ray shadow;

    color = (t_rgb){ 0, 0, 0 };
    s.i_light = -1;
    while (s.light[++s.i_light] != 0)//광원 돌면서 음영 처리
    {
        normalize_vec3(&obj.normal);//그림 그릴 위치에서 원 중심 빼서 확보한 벡터 CP' 정규화
        obj_disruption_for_shading(s.light[s.i_light], &obj);//모든 s->light 요소가 이 함수 거치면서 광원 방향 벡터(obj.light), light.p_shad(음영 지점?) 확보
        shadow.global = obj.light;//패레럴, 정규화된 광원 방향 벡터 대입
        shadow.origin = obj.p;//캔버스에 그림 그릴 위치 대입
        sub_color = get_ambient_color(&s, &obj);//배경색 적용한 색상 확보
        if (is_obj_shaded(s, &shadow) != 0)//음영, 색상 처리
            sub_color = get_mix_color(sub_color, get_spot_light(&s, &obj, s.i_light));//s.i_light 매개변수로 추가@
        color = get_mix_color(color, sub_color);
    }
    if (s.light[s.i_light] == 0)//광원이 없으면 배경색으로 칠함
        color = get_ambient_color(&s, &obj);
    if (s.filter == 's')
        color = apply_sepia_filter(s.filter, color);
    else if (s.filter == 'r' || s.filter == 'g' || s.filter == 'b')
        apply_color_filter(s.filter, &color);
    return (((int)color.r << 16) + ((int)color.g << 8) + (int)color.b);//rgb 색상 맞춰 값 반환
}

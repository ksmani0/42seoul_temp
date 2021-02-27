#include "minirt.h"

void    update_obj_position(t_scene *s, int i, t_vec3 new)
{
    if (i == 4)
        s->sphere[0]->center =
        vec3_add_vec3(s->sphere[0]->center, new);
    else if (i == 5)
        s->plane[0]->point =
        vec3_add_vec3(s->plane[0]->point, new);
    else if (i == 6)
        s->square[0]->center =
        vec3_add_vec3(s->square[0]->center, new);
    else if (i == 7)
        s->cylinder[0]->point =
        vec3_add_vec3(s->cylinder[0]->point, new);
    else if (i == 8)
    {
        s->triangle[0]->a =
        vec3_add_vec3(s->triangle[0]->a, new);
        s->triangle[0]->b =
        vec3_add_vec3(s->triangle[0]->b, new);
        s->triangle[0]->c =
        vec3_add_vec3(s->triangle[0]->c, new);
    }
}

void    obj_axis_translation(int key, t_scene *s, int i)
{
    t_vec3  new_pos;

    if (key == KEY_Z)//move left
        new_pos = (t_vec3){ -1, 0, 0 };
    else if (key == KEY_X)//move right
        new_pos = (t_vec3){ 1, 0, 0 };
    else if (key == KEY_C)//move up
        new_pos = (t_vec3){ 0, 1, 0 };
    else if (key == KEY_V)//move down
        new_pos = (t_vec3){ 0, -1, 0 };
    while (s->idx_rec[i] == 0 && i < 8)
        i++;//도형 구, 평면, 정사각형, 원통, 삼각형
    update_obj_position(s, i, new_pos);
    render_scene(&s);//여기서 이벤트 내용 적용해서 다시 이미지 렌더링
    mlx_put_image_to_window(s->win.mlx_p, s->win.win_p, s->img.inst, 0, 0);//이미지 정보를 모았다가 한번에 그림. 새로운 mlx 호환 이미지를 생성
}

void    change_camera_with_key(int key, t_scene *s)
{
    if (key == ARROW_LEFT)
    {//후반에 파싱한 카메라로 이동
        if (s->i_cam > 0)
            s->i_cam--;
    }
    else if (key == ARROW_RIGHT)
    {//초반에 파싱한 카메라로 이동
        if (s->i_cam < s->idx_rec[2] - 1)
            s->i_cam++;
    }
    render_scene(&s);//여기서 이벤트 내용 적용해서 다시 이미지 렌더링
    mlx_put_image_to_window(s->win.mlx_p, s->win.win_p, s->img.inst, 0, 0);//이미지 정보를 모았다가 한번에 그림. 새로운 mlx 호환 이미지를 생성
}
